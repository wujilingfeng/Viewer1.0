{
    depfiles_gcc = "build/.objs/viewer/linux/x86_64/release/src/Math/LB_Math.c.o:  src/Math/LB_Math.c include/Math/LB_Math.h\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-O3",
            "-Iinclude",
            "-Ithirdpart/cstructures/include",
            "-Ithirdpart/glad/include",
            "-Ithirdpart/glfw/include",
            "-Ithirdpart/freetype/include",
            "-DNDEBUG"
        }
    },
    files = {
        "src/Math/LB_Math.c"
    }
}