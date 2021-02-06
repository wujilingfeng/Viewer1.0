{
    files = {
        "src/Viewer_Interpreter/OpenGL/Viewer_OpenglAlg.c"
    },
    depfiles_gcc = "build/.objs/viewer/linux/x86_64/release/src/Viewer_Interpreter/OpenGL/Viewer_OpenglAlg.c.o:  src/Viewer_Interpreter/OpenGL/Viewer_OpenglAlg.c  include/Viewer_Interpreter/Viewer_OpenglAlg.h  thirdpart/glad/include/glad/glad.h  thirdpart/glad/include/KHR/khrplatform.h  include/Viewer_Interpreter/stb_image.h  include/Viewer_Interpreter/stb_image_write.h\
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
    }
}