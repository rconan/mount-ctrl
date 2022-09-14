#![allow(unused_imports)]

#[cfg(feature = "sampling1000-damping002")]
pub use sampling1000_damping002::{controller, drives};
#[cfg(feature = "s8000d0005")]
pub use sampling8000_damping0005::{controller, drives};

pub trait DriveController {
    fn mount_cmd(&mut self) -> Option<&mut [f64; 3]>;
    fn mount_pos(&mut self) -> Option<&mut [f64; 14]>;
    fn mount_t(&self) -> Option<&[f64; 20]>;
}

impl<'a> DriveController for drives::Controller<'a> {
    fn mount_cmd(&mut self) -> Option<&mut [f64; 3]> {
        if let drives::U::Mountcmd(val) = &mut self.mount_cmd {
            Some(val)
        } else {
            None
        }
    }

    fn mount_pos(&mut self) -> Option<&mut [f64; 14]> {
        if let drives::U::Mountpos(val) = &mut self.mount_pos {
            Some(val)
        } else {
            None
        }
    }

    fn mount_t(&self) -> Option<&[f64; 20]> {
        let drives::Y::MountT(val) = &self.mount_t;
        Some(val)
    }
}

pub trait ControllerController {
    fn mount_fb(&mut self) -> Option<&mut [f64; 14]>;
    fn mount_sp(&mut self) -> Option<&mut [f64; 3]>;
    fn mount_cmd(&mut self) -> Option<&[f64; 3]>;
}
impl<'a> ControllerController for controller::Controller<'a> {
    fn mount_fb(&mut self) -> Option<&mut [f64; 14]> {
        if let controller::U::MountFB(val) = &mut self.mount_fb {
            Some(val)
        } else {
            None
        }
    }

    fn mount_sp(&mut self) -> Option<&mut [f64; 3]> {
        if let controller::U::MountSP(val) = &mut self.mount_sp {
            Some(val)
        } else {
            None
        }
    }

    fn mount_cmd(&mut self) -> Option<&[f64; 3]> {
        let controller::Y::Mountcmd(val) = &self.mount_cmd;
        Some(val)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn controller() {
        let mut ctrlr = controller::Controller::new();
        assert_eq!(ctrlr.mount_fb(), Some(&mut [0f64; 14]));
        assert_eq!(ctrlr.mount_sp(), Some(&mut [0f64; 3]));
        assert_eq!(ctrlr.mount_cmd(), Some(&[0f64; 3]));
    }
    #[test]
    fn driver() {
        let mut drvr = drives::Controller::new();
        assert_eq!(drvr.mount_cmd(), Some(&mut [0f64; 3]));
        assert_eq!(drvr.mount_pos(), Some(&mut [0f64; 14]));
        assert_eq!(drvr.mount_t(), Some(&[0f64; 20]));
    }
}
