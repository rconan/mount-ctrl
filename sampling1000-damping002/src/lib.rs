pub mod controller;
pub mod drives;

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn drives() {
        let mut val = [0f64; 3];
        let _ = drives::U::Mountcmd(&mut val);
    }
    #[test]
    fn controller() {
        let mut val = [0f64; 14];
        let _ = controller::U::MountFB(&mut val);
    }
}
