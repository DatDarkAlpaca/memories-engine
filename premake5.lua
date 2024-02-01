require "scripts/clear"
require "scripts/project"
include "dependencies/conandeps.premake5.lua"

output_path         = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
binaries_path       = "%{wks.location}/build/bin/" .. "%{output_path}"
intermediate_path   = "%{wks.location}/build/intermediate/" .. "%{output_path}"
dependencies_path   = "%{wks.location}/dependencies/"

workspace "memories-engine"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }

    startproject "memories-example"

include "memories-engine/engine.lua"
include "memories-example/example.lua"