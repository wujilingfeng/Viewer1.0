{
    depfiles_gcc = "build/.objs/main/linux/x86_64/release/Demo1/main.cpp.o: Demo1/main.cpp  include/Viewer_Interpreter/Viewer_OpenGL_Interpreter.h  thirdpart/freetype/include/ft2build.h  thirdpart/freetype/include/freetype/config/ftheader.h  thirdpart/freetype/include/freetype/freetype.h  thirdpart/freetype/include/freetype/config/ftconfig.h  thirdpart/freetype/include/freetype/config/ftoption.h  thirdpart/freetype/include/freetype/config/ftstdlib.h  thirdpart/freetype/include/freetype/fttypes.h  thirdpart/freetype/include/freetype/ftsystem.h  thirdpart/freetype/include/freetype/ftimage.h  thirdpart/freetype/include/freetype/fterrors.h  thirdpart/freetype/include/freetype/ftmoderr.h  thirdpart/freetype/include/freetype/fterrdef.h  include/Viewer_Interpreter/Viewer_OpenGL_Interpreter_Shader.h  include/Viewer_Interpreter/glfw_callback.h  include/Viewer_Interpreter/Viewer_OpenglAlg.h  thirdpart/glad/include/glad/glad.h  thirdpart/glad/include/KHR/khrplatform.h  include/Viewer_World_Manager/Viewer_World_Manager.h  include/Viewer_World_Manager/Viewer_Base_Species.h  include/Math/Viewer_Matrix4x4.h include/Math/LB_Math.h  thirdpart/cstructures/include/tools_node.h  include/Viewer_World_Manager/Interactor_GlobalInfo.h  thirdpart/cstructures/include/tools_rbtree.h  thirdpart/glfw/include/GLFW/glfw3.h include/config.h\
",
    files = {
        "Demo1/main.cpp"
    },
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-Iinclude",
            "-I/home/libo/Documents/c++/viewer/Demo1/include",
            "-Ithirdpart/cstructures/include",
            "-Ithirdpart/glad/include",
            "-Ithirdpart/glfw/include",
            "-Ithirdpart/freetype/include",
            "-DNDEBUG"
        }
    }
}