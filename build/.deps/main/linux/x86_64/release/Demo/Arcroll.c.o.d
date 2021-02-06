{
    depfiles_gcc = "build/.objs/main/linux/x86_64/release/Demo/Arcroll.c.o: Demo/Arcroll.c  Demo/include/Arcroll.h  include/Viewer_World_Manager/Viewer_World_Manager.h  include/Viewer_World_Manager/Viewer_Base_Species.h  include/Math/Viewer_Matrix4x4.h include/Math/LB_Math.h  thirdpart/cstructures/include/tools_node.h  include/Viewer_World_Manager/Interactor_GlobalInfo.h  thirdpart/cstructures/include/tools_rbtree.h\
",
    files = {
        "Demo/Arcroll.c"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-O3",
            "-Iinclude",
            "-I/home/libo/Documents/c++/viewer/Demo/include",
            "-Ithirdpart/cstructures/include",
            "-Ithirdpart/glad/include",
            "-Ithirdpart/glfw/include",
            "-Ithirdpart/freetype/include",
            "-DNDEBUG"
        }
    }
}