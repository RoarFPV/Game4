
rootOut = "%{wks.location}/" --"%{wks.location}/out/"
projectFiles = rootOut -- "prj/"

-- Libraries directory
libsDir = "libs/"
libsPrjDir = projectFiles .. libsDir

-- Applications directory
appsDir = "apps/"
appsPrjDir = projectFiles .. appsDir

outputdir = "%{cfg.bluildcfg}-%{cfg.system}-%{cfg.architecture}"
targetOutputDir = rootOut .. "bin/" .. outputdir .. "/%{prj.name}"
objOutputDir = rootOut .. "build/" .. outputdir .. "/%{prj.name}"


workspace "Game4"
    architecture "x64"
    location "out/prj"
    namespace "G4"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }



cppType= "c++20"

-- group "libs"
--     include (libsDir .. "Engine")
-- group ""

group "apps"
    include "apps/Sandbox"
group ""
