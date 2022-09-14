use cc;
use std::path::Path;

fn main() {
    let path = Path::new("src").join("controller");
    cc::Build::new()
        .file(path.join("Mount_Control.c"))
        .file(path.join("Mount_Control_data.c"))
        .compile("mount_controller");
}
