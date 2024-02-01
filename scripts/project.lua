function create_project(project_name, project_kind)
    project(project_name)
        kind(project_kind)
        language "C++"
        cppdialect "C++17"

        targetdir(binaries_path .. "/%{prj.name}")
        objdir(intermediate_path .. "/%{prj.name}")

        files {
            "**.cpp",
            "**.hpp",
            "**.c",
            "**.h",
        }
    
        includedirs {
            "%{prj.location}",
            "%{prj.location}/src"
        }

        -- Configurations
        filter { "configurations:Debug" }
            defines { "MEM_DEBUG" }
            runtime "Debug"
            symbols "on"
        filter { }
            
        filter { "configurations:Release" }
            runtime "Release"
            optimize "on"
            inlining "auto"
        filter { }

        conan_setup()       
end