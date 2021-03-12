{
    depfiles_gcc = "build/.objs/viewer/linux/x86_64/release/thirdpart/glad/src/glad.c.o:  thirdpart/glad/src/glad.c thirdpart/glad/include/glad/glad.h  thirdpart/glad/include/KHR/khrplatform.h\
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
        "thirdpart/glad/src/glad.c"
    }
}