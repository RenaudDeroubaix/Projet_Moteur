# CMake entry point
cmake_minimum_required (VERSION 3.1)
project (Tutorials)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# TP3
add_executable(TP
    main.cpp
    common/utils.hpp
    common/stb_image.hpp
	common/shader.cpp
	common/shader.hpp
	common/texture.cpp
	common/texture.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp
	common/quaternion_utils.cpp
    common/quaternion_utils.hpp

	common/Renderer.cpp
	common/Renderer.hpp
	
	common/Graph.cpp
	common/Graph.hpp
	
	common/Scene.cpp
	common/Scene.hpp
	
	common/GameObject.cpp
	common/GameObject.cpp
	
	common/Plan.hpp
	common/Plan.cpp
	
	common/Mur.hpp
	common/Mur.cpp
	
	common/Mesh.hpp
	common/Mesh.cpp
	
    common/Camera.cpp
	common/Camera.hpp
	
	common/InputManager.cpp
	common/InputManager.hpp

	common/CubeInit.hpp
	common/CubeInit.cpp
	
	common/Room.hpp
	
	common/GOInfo.hpp
	
	common/Physics.hpp
	common/Physics.cpp

    common/Helper.cpp
    common/Helper.hpp
    
    common/SceneManager.hpp
    
    common/Event.hpp
    common/Event.cpp
    
    common/SceneInit.hpp
    
     common/lumiere.hpp
     common/lumiere.cpp
	
	
)
target_link_libraries(TP
	${ALL_LIBS}
	
)

# Xcode and Visual working directories
set_target_properties(TP PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
create_target_launcher(TP WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/")

if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
add_custom_command(
   TARGET TP POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}"
)
elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -gstabs")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gstabs")
endif()
