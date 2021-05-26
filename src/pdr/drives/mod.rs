use dosio::{
    io::{jar, Tags},
    DOSIOSError, Dos, IOTags, IO,
};
use simulink_rs::*;

import_simulink!(Mount_Drv_PDR2021, U : (Mount_cmd,3,Mount_pos,14), Y : (Mount_F,20));
build_inputs!(
    MountCmd,
    3,
    0,
    OssAzDrive,
    14,
    0,
    OssElDrive,
    14,
    6,
    OssGirDrive,
    14,
    10
);
build_outputs!(
    OssAzDrive,
    20,
    12,
    0,
    OssElDrive,
    20,
    4,
    12,
    OssGirDrive,
    20,
    4,
    16
);
build_controller!(Mount_Drv_PDR2021,
                  U : (Mount_cmd -> (MountCmd,cmd) ,
                       Mount_pos -> (OssAzDrive,oss_az_drive_d),
                       Mount_pos -> (OssElDrive,oss_el_drive_d),
                       Mount_pos -> (OssGirDrive,oss_gir_drive_d)),
                  Y : (Mount_F -> (OssAzDrive,oss_az_drive_f),
                       Mount_F -> (OssElDrive,oss_el_drive_f),
                       Mount_F -> (OssGirDrive,oss_gir_drive_f))
);

// Mount
impl<'a> IOTags for Controller<'a> {
    fn outputs_tags(&self) -> Vec<Tags> {
        vec![
            jar::OSSAzDriveTorque::io(),
            jar::OSSElDriveTorque::io(),
            jar::OSSRotDriveTorque::io(),
        ]
    }
    fn inputs_tags(&self) -> Vec<Tags> {
        vec![
            jar::MountCmd::io(),
            jar::OSSAzEncoderAngle::io(),
            jar::OSSElEncoderAngle::io(),
            jar::OSSRotEncoderAngle::io(),
        ]
    }
}
impl<'a> Dos for Controller<'a> {
    type Input = Vec<f64>;
    type Output = Vec<f64>;
    fn inputs(&mut self, data: Option<Vec<IO<Self::Input>>>) -> Result<&mut Self, DOSIOSError> {
        match data {
            Some(data) => {
                if data.into_iter().fold(4, |mut a, io| {
                    match io {
                        IO::MountCmd { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.cmd[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSAzEncoderAngle { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_az_drive_d[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSElEncoderAngle { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_el_drive_d[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSRotEncoderAngle { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_gir_drive_d[k] = v;
                            }
                            a -= 1;
                        }
                        _ => (),
                    }
                    if a == 0 {
                        return a;
                    }
                    a
                }) == 0
                {
                    Ok(self)
                } else {
                    Err(DOSIOSError::Inputs("Either mount drive controller MountCmd, OSSAzEncoderAngle, OSSElEncoderAngle or OSSRotEncoderAngle not found".into()))
                }
            }
            None => Err(DOSIOSError::Inputs(
                "None data passed to mount drive".into(),
            )),
        }
    }
    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        Some(vec![
            IO::OSSAzDriveTorque {
                data: Some(Vec::<f64>::from(&self.oss_az_drive_f)),
            },
            IO::OSSElDriveTorque {
                data: Some(Vec::<f64>::from(&self.oss_el_drive_f)),
            },
            IO::OSSRotDriveTorque {
                data: Some(Vec::<f64>::from(&self.oss_gir_drive_f)),
            },
        ])
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn pdr_mount_drive_zeros() {
        let mut mnt_drives = Controller::new();
        for _ in 0..5 {
            let u = vec![
                jar::MountCmd::io_with(vec![0f64; 3]),
                jar::OSSAzEncoderAngle::io_with(vec![0f64; 6]),
                jar::OSSElEncoderAngle::io_with(vec![0f64; 4]),
                jar::OSSRotEncoderAngle::io_with(vec![0f64; 4]),
            ];
            let y = mnt_drives.in_step_out(Some(u)).unwrap();
            println!("PDR MOUNT DRIVE ZEROS TEST: {:#?}", y);
        }
    }

    #[test]
    fn pdr_mount_drive_ones() {
        let mut mnt_drives = Controller::new();
        for _ in 0..5 {
            let u = vec![
                jar::MountCmd::io_with(vec![1f64; 3]),
                jar::OSSAzEncoderAngle::io_with(vec![1f64; 6]),
                jar::OSSElEncoderAngle::io_with(vec![1f64; 4]),
                jar::OSSRotEncoderAngle::io_with(vec![1f64; 4]),
            ];
            let y = mnt_drives.in_step_out(Some(u)).unwrap();
            println!("PDR MOUNT DRIVE ONES TEST: {:#?}", y);
        }
    }
}
