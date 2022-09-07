pub mod controller;
pub mod ze00;
pub mod ze30;
pub mod ze60;

pub enum Controller<'a> {
    Ze00(ze00::Controller<'a>),
    Ze30(ze30::Controller<'a>),
    Ze60(ze60::Controller<'a>),
    Default(controller::Controller<'a>),
}

#[derive(Debug, thiserror::Error)]
pub enum ControlError {
    #[error("Expected zenith angle 0, 30 or 60 found {0}")]
    ZenithAngle(i32),
}

type Result<T> = std::result::Result<T, ControlError>;

impl<'a> Controller<'a> {
    /// Returns a default mount controller
    pub fn new() -> Self {
        Controller::Default(controller::Controller::new())
    }
    /// Returns a mount controller for the given zenith angle
    ///
    /// The zenith angle is either 0, 30 or 60 degrees
    pub fn at_zenith_angle(ze: i32) -> Result<Self> {
        println!("Mount controller zenith angle: {ze}");
        match ze {
            ze if ze == 0 => Ok(Self::Ze00(ze00::Controller::new())),
            ze if ze == 30 => Ok(Self::Ze30(ze30::Controller::new())),
            ze if ze == 60 => Ok(Self::Ze60(ze60::Controller::new())),
            _ => Err(ControlError::ZenithAngle(ze)),
        }
    }
    /// Returns a mount controller for the given elevation
    ///
    /// The elevation is either 90, 60 or 30 degrees
    pub fn at_elevation(el: i32) -> Result<Self> {
        Self::at_zenith_angle(90 - el)
    }
    pub fn mount_fb(&mut self) -> Option<&mut [f64; 14]> {
        match self {
            Controller::Ze00(controller) => {
                if let ze00::U::MountFB(val) = &mut controller.mount_fb {
                    Some(val)
                } else {
                    None
                }
            }
            Controller::Ze30(controller) => {
                if let ze30::U::MountFB(val) = &mut controller.mount_fb {
                    Some(val)
                } else {
                    None
                }
            }
            Controller::Ze60(controller) => {
                if let ze60::U::MountFB(val) = &mut controller.mount_fb {
                    Some(val)
                } else {
                    None
                }
            }
            Controller::Default(controller) => {
                if let controller::U::MountFB(val) = &mut controller.mount_fb {
                    Some(val)
                } else {
                    None
                }
            }
        }
    }
    pub fn mount_sp(&mut self) -> Option<&mut [f64; 3]> {
        match self {
            Controller::Ze00(controller) => {
                if let ze00::U::MountSP(val) = &mut controller.mount_sp {
                    Some(val)
                } else {
                    None
                }
            }
            Controller::Ze30(controller) => {
                if let ze30::U::MountSP(val) = &mut controller.mount_sp {
                    Some(val)
                } else {
                    None
                }
            }
            Controller::Ze60(controller) => {
                if let ze60::U::MountSP(val) = &mut controller.mount_sp {
                    Some(val)
                } else {
                    None
                }
            }
            Controller::Default(controller) => {
                if let controller::U::MountSP(val) = &mut controller.mount_sp {
                    Some(val)
                } else {
                    None
                }
            }
        }
    }
    pub fn mount_cmd(&mut self) -> Option<&[f64; 3]> {
        match self {
            Controller::Ze00(controller) => {
                let ze00::Y::Mountcmd(val) = &controller.mount_cmd;
                Some(val)
            }
            Controller::Ze30(controller) => {
                let ze30::Y::Mountcmd(val) = &controller.mount_cmd;
                Some(val)
            }
            Controller::Ze60(controller) => {
                let ze60::Y::Mountcmd(val) = &controller.mount_cmd;
                Some(val)
            }
            Controller::Default(controller) => {
                let controller::Y::Mountcmd(val) = &controller.mount_cmd;
                Some(val)
            }
        }
    }
}

impl<'a> Iterator for Controller<'a> {
    type Item = ();

    fn next(&mut self) -> Option<Self::Item> {
        match self {
            Controller::Ze00(control) => control.next(),
            Controller::Ze30(control) => control.next(),
            Controller::Ze60(control) => control.next(),
            Controller::Default(control) => control.next(),
        }
    }
}
