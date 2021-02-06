{
    depfiles_gcc = "build/.objs/viewer/linux/x86_64/release/src/Viewer_World_Manager/Viewer_Base_Species.c.o:  src/Viewer_World_Manager/Viewer_Base_Species.c  include/Viewer_World_Manager/Viewer_Base_Species.h  include/Math/Viewer_Matrix4x4.h include/Math/LB_Math.h  thirdpart/cstructures/include/tools_node.h\
",
    files = {
        "src/Viewer_World_Manager/Viewer_Base_Species.c"
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