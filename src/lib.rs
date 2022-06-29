pub mod controller;
pub mod drives;

impl<'a> drives::Controller<'a> {
    pub fn mount_cmd(&mut self) -> Option<&mut [f64; 3]> {
        if let drives::U::Mountcmd(val) = &mut self.mount_cmd {
            Some(val)
        } else {
            None
        }
    }
    pub fn mount_pos(&mut self) -> Option<&mut [f64; 14]> {
        if let drives::U::Mountpos(val) = &mut self.mount_pos {
            Some(val)
        } else {
            None
        }
    }
    pub fn mount_t(&self) -> Option<&[f64; 20]> {
        let drives::Y::MountT(val) = &self.mount_t;
        Some(val)
    }
}
