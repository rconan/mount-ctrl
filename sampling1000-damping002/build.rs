use cc;
use std::path::Path;

fn main() {
    let path = Path::new("src").join("drives");
    cc::Build::new()
        .file(path.join("Mount_Drv_PDR2021.c"))
        .compile("mount_drives");
}
