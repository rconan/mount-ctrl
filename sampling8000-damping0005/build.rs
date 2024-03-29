use cc;
use std::path::Path;

fn main() {
    let path = Path::new("src").join("controller");
    cc::Build::new()
        .file(path.join("Mount_Control.c"))
        .file(path.join("Mount_Control_data.c"))
        .compile("mount_controller");
    let path = Path::new("src").join("drives");
    cc::Build::new()
        .file(path.join("Mount_Drv_PDR2021_linear.c"))
        .compile("mount_drives");
}
