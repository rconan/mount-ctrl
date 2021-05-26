use dosio::{
    io::{jar, Tags},
    DOSIOSError, Dos, IOTags, IO,
};
use simulink_rs::*;

import_simulink!(MountControl0, U : (Mount_SP,3,Mount_FB,20), Y : (Mount_cmd,3));
build_inputs!(
    SP,
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
build_outputs!(CMD, 3);
build_controller!(MountControl0,
                  U : (Mount_FB -> (OssAzDrive,oss_az_drive),
                       Mount_FB -> (OssElDrive,oss_el_drive),
                       Mount_FB -> (OssGirDrive,oss_gir_drive)),
                  Y : (Mount_cmd -> (CMD,cmd))
);

impl<'a> IOTags for Controller<'a> {
    fn outputs_tags(&self) -> Vec<Tags> {
        vec![jar::MountCmd::io()]
    }
    fn inputs_tags(&self) -> Vec<Tags> {
        vec![
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
                if data.into_iter().fold(3, |mut a, io| {
                    match io {
                        IO::OSSAzDriveD { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_az_drive[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSElDriveD { data: Some(values) } => {
                            for (k, v) in values.into_iter().enumerate() {
                                self.oss_el_drive[k] = v;
                            }
                            a -= 1;
                        }
                        IO::OSSGIRDriveD { data: Some(values) } => {
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
            }
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
