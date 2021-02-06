{
    depfiles_gcc = "build/.objs/viewer/linux/x86_64/release/src/Viewer_World_Manager/Interactor_GlobalInfo.c.o:  src/Viewer_World_Manager/Interactor_GlobalInfo.c  include/Viewer_World_Manager/Interactor_GlobalInfo.h  thirdpart/cstructures/include/tools_node.h\
",
    files = {
        "src/Viewer_World_Manager/Interactor_GlobalInfo.c"
    },
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