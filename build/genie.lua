-- GENIe solution to build the Wolfy2D Solution.
-- Julio Marcelo Picardo <juliomarcelopicardo@gmail.com>
-- 

PROJ_DIR = path.getabsolute("../")

solution "Wolfy2D_Solution"
  configurations {
    "Release",
    "Debug",
  }
  language "C++"
  platforms { "x32", "x64" }

  configuration "Debug"
    flags { "Symbols" }
  	targetsuffix "-d"
  	links {
      "opengl32",
  	}
    defines {
      "_DEBUG",
  	  "_GLFW_WIN32",
      "LUA_COMPAT_MODULE",
      "ENJINE_OPENGL",
      "GLEW_STATIC",
	  }

  configuration "Release"
    flags { "OptimizeSize" }
  	links {
      "opengl32",
  	}
    defines {
      "NDEBUG",
      "_GLFW_WIN32",
      "LUA_COMPAT_MODULE",
      "ENJINE_OPENGL",
      "GLEW_STATIC",
	  }

project "Wolfy2D"
  kind "staticlib"
  language "C++"

  includedirs {
    path.join(PROJ_DIR, "include/"),
    path.join(PROJ_DIR, "src/"),
    -- GLFW
    path.join(PROJ_DIR, "external/glfw3_2_1/include/"),
  	path.join(PROJ_DIR, "external/glfw3_2_1/src/"),
    -- GLEW
    path.join(PROJ_DIR, "external/glew/include/"),
    path.join(PROJ_DIR, "external/glew/src/"),
    -- LUA
    path.join(PROJ_DIR, "external/lua/include/"),
    path.join(PROJ_DIR, "external/lua/src/"),
    -- IMGUI
    path.join(PROJ_DIR, "external/imgui/include/"),
    path.join(PROJ_DIR, "external/imgui/src/"),
    -- GLM
    path.join(PROJ_DIR, "external/glm/include/"),
    path.join(PROJ_DIR, "external/glm/src/"),
    -- FontStash
    path.join(PROJ_DIR, "external/fontstash/include/"),
  }

  files {
    path.join(PROJ_DIR, "src/*.cc"),
    path.join(PROJ_DIR, "src/core/*.cc"),
    path.join(PROJ_DIR, "src/Wolfy2D/*.cc"),
    path.join(PROJ_DIR, "include/*.h"),
    path.join(PROJ_DIR, "include/core/*.h"),
    path.join(PROJ_DIR, "include/Wolfy2D/*.h"),
    path.join(PROJ_DIR, "data/geometries/*.*"),
    path.join(PROJ_DIR, "data/materials/*.*"),
    path.join(PROJ_DIR, "data/textures/*.*"),
    -- GLFW
    path.join(PROJ_DIR, "external/glfw3_2_1/src/*.c"),
    path.join(PROJ_DIR, "external/glfw3_2_1/src/*.h"),
    -- GLEW
    path.join(PROJ_DIR, "external/glew/src/*.c"),
    -- ImGui
	  path.join(PROJ_DIR, "external/imgui/*.cpp"),
	  path.join(PROJ_DIR, "external/imgui/*.h"),
    -- GLM
    path.join(PROJ_DIR, "external/glm/include/GLM/detail/*.*"),
    path.join(PROJ_DIR, "external/glm/include/GLM/gtc/*.*"),
    path.join(PROJ_DIR, "external/glm/include/GLM/gtx/*.*"),
    path.join(PROJ_DIR, "external/glm/include/GLM/simd/*.*"),
    path.join(PROJ_DIR, "external/glm/include/GLM/*.*"),
    path.join(PROJ_DIR, "external/glm/src/*.cpp"),
    -- FontStash
    path.join(PROJ_DIR, "external/fontstash/include/FONTSTASH/fontstash.h"),
    path.join(PROJ_DIR, "external/fontstash/include/FONTSTASH/glfontstash.h"),
    path.join(PROJ_DIR, "external/fontstash/include/FONTSTASH/stb_truetype.h"),
  }

  configuration "Debug"
    targetdir ("../bin/")
    links {
	    "opengl32",
	  }

  configuration "Release"
    targetdir ("../bin/")
  	links {
  	  "opengl32",
  	}

-- Function to generate the different mains or projects.
function GenerateProject(name)

  project(name)
	kind "ConsoleApp"

  includedirs {
	  path.join(PROJ_DIR, "include/"),
    path.join(PROJ_DIR, "external/glew/include/"),
    path.join(PROJ_DIR, "external/glfw3_2_1/include/"),
    path.join(PROJ_DIR, "external/lua/include/"),
    path.join(PROJ_DIR, "external/imgui/include/"),
    path.join(PROJ_DIR, "external/glm/include/"),
    path.join(PROJ_DIR, "external/fontstash/include/"),
  }

  files {
    path.join(PROJ_DIR, "data/"..name.."/*.*"),
    path.join(PROJ_DIR, "examples/"..name.."/*.*"),
  }

  configuration "Debug"
    targetdir ("../bin/")
    links {
      "opengl32",
      "Wolfy2D",
	  }

  configuration "Release"
    targetdir ("../bin/")
  	links {
      "opengl32",
      "Wolfy2D",
  	}

end

-- PROJECTS
GenerateProject("01_Testing")
