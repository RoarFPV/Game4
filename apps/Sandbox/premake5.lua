project "Sandbox"
    location (appsPrjDir .. "%{prj.name}")
    kind "ConsoleApp"
    language "C++" 

    targetdir (targetOutputDir)
    objdir (objOutputDir)
    compileas "Module"
    exceptionhandling "off"

    files
    {
        "src/**.h",
        "src/**.cpp",
        "src/**.ixx",
        "../../modules/**.cpp",
        "../../modules/Core/**.ixx",
        "../../modules/Engine/**.ixx",
        
        -- "$(VCToolsInstallDir)/modules/std.ixx"
    }
 
    includedirs 
    {
        "../../modules/",
        "../../external/tracy/public/tracy"
    }

    links
    {
        -- "Engine"    
    }

    filter "system:windows"
        cppdialect (cppType)
        staticruntime "on"
        systemversion "latest"
        defines { "WIN32"}
        links { "kernel32", "user32"}
        editandcontinue "off"
        -- postbuildcommands copy dll

    filter "configurations:Debug"
        defines {"G4_DEGUG", "_DEBUG", "TRACY_ENABLE", "TRACY_CALLSTACK=20" }
        symbols "On"
        files { 
            "../../external/tracy/public/TracyClient.cpp", 
            "../../modules/Tracy.ixx" 
        }
    
    filter "configurations:Release"
        defines {"G4_RELEASE", "TRACY_ENABLE", "TRACY_CALLSTACK=20" }
        optimize "On"
        files { 
            "../../external/tracy/public/TracyClient.cpp", 
            "../../modules/Tracy.ixx" 
        }
    filter "configurations:Dist"
        defines "G4_DIST"
        optimize "On" 
