use dosio::{
    io::{jar, Tags},
    DOSIOSError, Dos, IOTags, IO,
};
use simulink_rs::*;

import_simulink!(MountDrives, U : (Mount_cmd,3,Mount_pos,20), Y : (Mount_F,20));
build_inputs!(
    CMD,
    3,
    0,
    OssAzDrive,
    20,
    0,
    OssElDrive,
    20,
    8,
    OssGirDrive,
    20,
    16
);
build_outputs!(
    OssAzDrive,
    20,
    8,
    0,
    OssElDrive,
    20,
    8,
    8,
    OssGirDrive,
    20,
    4,
    16
);
build_controller!(MountDrives,
                  U : (Mount_cmd -> (CMD,cmd) ,
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
            jar::OSSAzDriveF::io(),
            jar::OSSElDriveF::io(),
            jar::OSSGIRDriveF::io(),
        ]
    }
    fn inputs_tags(&self) -> Vec<Tags> {
        vec![
            jar::MountCmd::io(),
            jar::OSSAzDriveD::io(),
            jar::OSSElDriveD::io(),
            jar::OSSGIRDriveD::io(),
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
                        IO::OSSAzDriveD { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_az_drive_d[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSElDriveD { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_el_drive_d[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSGIRDriveD { data: Some(values) } => {
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
                    Err(DOSIOSError::Inputs("Either mount drive controller CMD, OSSAzDriveD, OSSElDriveD or OSSGIRDriveD not found".into()))
                }
            }
            None => Err(DOSIOSError::Inputs(
                "None data passed to mount drive".into(),
            )),
        }
    }
    fn outputs(&mut self) -> Option<Vec<IO<Self::Output>>> {
        Some(vec![
            IO::OSSAzDriveF {
                data: Some(Vec::<f64>::from(&self.oss_az_drive_f)),
            },
            IO::OSSElDriveF {
                data: Some(Vec::<f64>::from(&self.oss_el_drive_f)),
            },
            IO::OSSGIRDriveF {
                data: Some(Vec::<f64>::from(&self.oss_gir_drive_f)),
            },
        ])
    }
}
