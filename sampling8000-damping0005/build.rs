use cc;
use std::path::Path;

fn main() {
    let path = Path::new("src/controller");
    for controller in ["ze30"] {
        let compile = format!("mount_{controller}");
        cc::Build::new()
            .file(path.join(controller).join("Mount_Control.c"))
            .file(path.join(controller).join("Mount_Control_data.c"))
            .compile(compile.as_str());
    }
    cc::Build::new()
        .file("src/drives/Mount_Drv_PDR2021_linear.c")
        .compile("mount_drives");
    /*
    cc::Build::new()
        .file("src/drives/nl_mnt_drv/Mount_Drv_PDR2021.c")
        .file("src/drives/nl_mnt_drv/Mount_Drv_PDR2021_data.c")
        .file("src/drives/nl_mnt_drv/rtGetInf.c")
        .file("src/drives/nl_mnt_drv/rtGetNaN.c")
        .file("src/drives/nl_mnt_drv/rt_nonfinite.c")
        .compile("mount_pdr_drives");
    */
}
