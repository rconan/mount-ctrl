pub mod controller;
pub mod drives;
pub mod ze00;
pub mod ze30;
pub mod ze60;

pub enum Controller<'a> {
    Ze00(ze00::Controller<'a>),
    Ze30(ze30::Controller<'a>),
    Ze60(ze60::Controller<'a>),
    Default(controller::Controller<'a>),
}

impl<'a> Controller<'a> {
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
