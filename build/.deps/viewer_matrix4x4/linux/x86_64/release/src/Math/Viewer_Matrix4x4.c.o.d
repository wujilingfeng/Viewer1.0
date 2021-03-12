{
    depfiles_gcc = "build/.objs/viewer_matrix4x4/linux/x86_64/release/src/Math/Viewer_Matrix4x4.c.o:  src/Math/Viewer_Matrix4x4.c include/Math/Viewer_Matrix4x4.h  include/Math/LB_Math.h\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-O3",
            "-Iinclude",
            "-DNDEBUG"
        }
    },
    files = {
        "src/Math/Viewer_Matrix4x4.c"
    }
}