use cc;
use std::path::Path;

fn main() {
    let path = Path::new("src/controller");
    for controller in ["controller", "ze00", "ze30", "ze60"] {
        let compile = format!("mount_{controller}");
        cc::Build::new()
            .file(path.join(controller).join("Mount_Control.c"))
            .file(path.join(controller).join("Mount_Control_data.c"))
            .compile(compile.as_str());
    }
    cc::Build::new()
        .file("src/drives/Mount_Drv_PDR2021.c")
        .compile("mount_drives");
}
