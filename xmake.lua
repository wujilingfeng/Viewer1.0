add_rules("mode.debug","mode.release")
option("configure")
    set_default(false)
    set_showmenu(true)
option("demo")
    set_default(true)
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
            add_files("Demo/*.cpp","Demo/*.c")
            add_includedirs("include","Demo/include","thirdpart/cstructures/include","thirdpart/glad/include","thirdpart/glfw/include","thirdpart/freetype/include")
            add_links("cstructures","glfw3","opengl32","freetype","viewer","gdi32","comdlg32","advapi32","Z")
            add_linkdirs("lib","temp_libs")
            add_ldflags("-no-pie -Wl,--start-group ") 
    end
end


-- if not has_config("kind") then
--     target("viewer_matrix4x4")
--         set_kind("static")
--         set_targetdir("temp_libs")
--         add_files("src/Math/*.c")
--         add_includedirs("include")
-- end
-- if not has_config("kind") then


--     target("main")
--         add_deps("viewer")
--         set_targetdir("bin")
--         set_kind("binary")
--         add_files("Demo/*.cpp","Demo/*.c")
--         add_includedirs("include","Demo/include","thirdpart/cstructures/include","thirdpart/glad/include","thirdpart/glfw/include","thirdpart/freetype/include")
--         add_links("cstructures","glfw3","opengl32","freetype","viewer","gdi32","comdlg32","advapi32","Z")
--         add_linkdirs("lib","temp_libs")
--         add_ldflags("-no-pie -Wl,--start-group ")
-- end

-- target("main")
--     set_targetdir("bin")
--     set_kind("binary")
--     add_files("Demo/*.cpp","Demo/*.c")
--     add_includedirs("include","Demo/include","thirdpart/cstructures/include","thirdpart/glad/include","thirdpart/glfw/include","thirdpart/freetype/include")
--     add_links("cstructures","glfw3","opengl32","freetype","viewer","gdi32","comdlg32","advapi32","Z")
--     add_linkdirs("lib","temp_libs")
--     add_ldflags("-no-pie -Wl,--start-group ")
    ---add_ldflags("-Wl,--start-group  -lglfw3 -lfreetype -lviewer -lcstructures -lZ -Wl,--end-group",{force=true}) 
