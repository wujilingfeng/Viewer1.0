
target("viewer_matrix4x4")
    set_kind("static")
    set_targetdir("../temp_libs")
    add_files("Math/*.c")
---set_toolset("cc","gcc")
    add_includedirs("../include")

target("viewer")
    set_kind("static")
    set_targetdir("../temp_libs")
    add_files("Math/*.c","Viewer_Interpreter/OpenGL/*.c","Viewer_Interpreter/*.c","Viewer_World_Manager/*.c","../thirdpart/glad/src/*.c")
    add_includedirs("../include","../thirdpart/cstructures/include","../thirdpart/glad/include","../thirdpart/glfw/include","../thirdpart/freetype/include")
    add_linkdirs("../temp_libs","../lib")

