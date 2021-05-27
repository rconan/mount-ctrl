use dosio::{
    io::{jar, Tags},
    DOSIOSError, Dos, IOTags, IO,
};
use simulink_rs::*;

import_simulink!(Mount_Control, U : (Mount_SP,3,Mount_FB,14), Y : (Mount_cmd,3));
build_inputs!(
    SP,
    3,
    0,
    OssAzDrive,
    14,
    0,
    OssElDrive,
    14,
    4,
    OssGirDrive,
    14,
    10
);
build_outputs!(MountCmd, 3);
build_controller!(Mount_Control,
                  U : (Mount_FB -> (OssAzDrive,oss_az_drive),
                       Mount_FB -> (OssElDrive,oss_el_drive),
                       Mount_FB -> (OssGirDrive,oss_gir_drive)),
                  Y : (Mount_cmd -> (MountCmd,cmd))
);

impl<'a> IOTags for Controller<'a> {
    fn outputs_tags(&self) -> Vec<Tags> {
        vec![jar::MountCmd::io()]
    }
    fn inputs_tags(&self) -> Vec<Tags> {
        vec![
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
                if data.into_iter().fold(3, |mut a, io| {
                    match io {
                        IO::OSSAzEncoderAngle { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_az_drive[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSElEncoderAngle { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_el_drive[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSRotEncoderAngle { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_gir_drive[k] = v;
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
                    Err(DOSIOSError::Inputs("Either mount controller controller OSSAzDriveD, OSSElDriveD or OSSGIRDriveD not found".into()))
                }
            },
            None => Err(DOSIOSError::Inputs(
                "None data passed to mount controller".into(),
            )),
        }
    }
    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        Some(vec![IO::MountCmd {
            data: Some(Vec::<f64>::from(&self.cmd)),
        }])
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn pdr_mount_control_zeros_test() {
        let mut mnt_ctrl = Controller::new();
        let u = vec![
            jar::OSSAzEncoderAngle::io_with(vec![0f64; 8]),
            jar::OSSElEncoderAngle::io_with(vec![0f64; 8]),
            jar::OSSRotEncoderAngle::io_with(vec![0f64; 4]),
        ];
        let y = mnt_ctrl.in_step_out(Some(u)).unwrap();
        println!("PDR MOUNT CONTROL ZEROS TEST: {:#?}", y);
    }

    #[test]
    fn pdr_mount_control_ones_test() {
        let mut mnt_ctrl = Controller::new();
        for k in 0..5 {
            let u = vec![
                jar::OSSAzEncoderAngle::io_with(vec![1f64; 8]),
                jar::OSSElEncoderAngle::io_with(vec![1f64; 8]),
                jar::OSSRotEncoderAngle::io_with(vec![1f64; 4]),
            ];
            let y = mnt_ctrl.in_step_out(Some(u)).unwrap();
            println!("PDR MOUNT CONTROL ONES TEST: {:#?}", y);
        }
    }
}
