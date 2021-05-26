use cc;

fn main() {
    cc::Build::new()
        .file("src/cdr/controller/MountControl0.c")
        .file("src/cdr/controller/MountControl0_data.c")
        .compile("mount_controller");
    cc::Build::new()
        .file("src/pdr/controller/Mount_Control.c")
        .file("src/pdr/controller/Mount_Control_data.c")
        .compile("mount_pdr_controller");
    cc::Build::new()
        .file("src/cdr/drives/MountDrives.c")
        .file("src/cdr/drives/MountDrives_data.c")
        .compile("mount_drives");
    cc::Build::new()
        .file("src/pdr/drives/Mount_Drv_PDR2021.c")
        .file("src/pdr/drives/Mount_Drv_PDR2021_data.c")
        .file("src/pdr/drives/rtGetInf.c")
        .file("src/pdr/drives/rtGetNaN.c")
        .file("src/pdr/drives/rt_nonfinite.c")
        .compile("mount_pdr_drives");
}
