{
    depfiles_gcc = "build/.objs/viewer/linux/x86_64/release/src/Viewer_Interpreter/glfw_callback.c.o:  src/Viewer_Interpreter/glfw_callback.c  include/Viewer_Interpreter/glfw_callback.h  include/Viewer_Interpreter/Viewer_OpenglAlg.h  thirdpart/glad/include/glad/glad.h  thirdpart/glad/include/KHR/khrplatform.h  include/Viewer_World_Manager/Viewer_World_Manager.h  include/Viewer_World_Manager/Viewer_Base_Species.h  include/Math/Viewer_Matrix4x4.h include/Math/LB_Math.h  thirdpart/cstructures/include/tools_node.h  include/Viewer_World_Manager/Interactor_GlobalInfo.h  thirdpart/cstructures/include/tools_rbtree.h  thirdpart/glfw/include/GLFW/glfw3.h\
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
        "src/Viewer_Interpreter/glfw_callback.c"
    }
}