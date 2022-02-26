use cc;

fn main() {
    cc::Build::new()
        .file("src/controller/Mount_Control.c")
        .file("src/controller/Mount_Control_data.c")
        .compile("mount_pdr_controller");
    cc::Build::new()
        .file("src/drives/Mount_Drv_PDR2021.c")
        .file("src/drives/Mount_Drv_PDR2021_data.c")
        .file("src/drives/rtGetInf.c")
        .file("src/drives/rtGetNaN.c")
        .file("src/drives/rt_nonfinite.c")
        .compile("mount_pdr_drives");
}
