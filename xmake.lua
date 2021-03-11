add_rules("mode.debug","mode.release")

option("configure")
    set_default(true)
    set_showmenu(true)
option("demo")
    set_default(true)
    set_showmenu(true)
option("demo_path")
    set_showmenu(true)




if has_config("configure") 
then
    target("configure1")
        on_load(function ( target )
            import("core.project.config")
            str=path.absolute(config.buildir())
            str1=string.gsub(str,"\\","/")
            str2="#define MESH_VIEWER_PATH \""..str1.."/..\""
            io.writefile("include/config.h",str2)
        end)
    includes("src/*.lua")
    if has_config("demo") 
    then
        target("main")
            add_deps("viewer")
            set_targetdir("bin")
            set_kind("binary")
            add_files("$(demo_path)/*.cpp","$(demo_path)/*.c")
            ---print("fdsfsdfd")
            add_includedirs("include","$(demo_path)/include","thirdpart/cstructures/include","thirdpart/glad/include","thirdpart/glfw/include","thirdpart/freetype/include")
            if is_plat("windows","mingw") then
               --- print("windwos")
                add_links("cstructures","glfw3","opengl32","freetype","viewer","gdi32","comdlg32","advapi32","Z")
            end
            if is_plat("linux") then
                add_links("cstructures","glfw3", "GL", "Xrandr", "Xi", "X11", "Xxf86vm", "pthread", "Xinerama", "Xcursor", "dl", "freetype", "png", "z", "harfbuzz")
            end
            add_linkdirs("lib","temp_libs")
            add_ldflags("-no-pie ") 
    end
end

-- target("viewer_matrix4x4")
--     set_kind("static")
--     set_targetdir("temp_libs")
--     add_files("src/Math/*.c")
--     add_includedirs("include")
-- add_ldflags(-static-libstdc++ -static-libgcc)
-- add_links(glfw3 Gl Xrandr Xi X11 Xxf86vm pthread Xinerama Xcursor m dl freetype png z harf buzz)
-- target("main")
--     set_kind("binary")
--     add_files("Demo/*.cpp","Demo/*.c")
--     add_includedirs("include","Demo/include","thirdpart/cstructures/include","thirdpart/glad/include","thirdpart/glfw/include","thirdpart/freetype/incldue")

