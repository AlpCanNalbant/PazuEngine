set(PAZU_ENGINE_VERSION 0.1)
project(PazuEngine VERSION ${PAZU_ENGINE_VERSION} LANGUAGES CXX)

file(GLOB_RECURSE PAZU_ENGINE_HEADER "./Pazu/*.h")
file(GLOB_RECURSE PAZU_ENGINE_INLINE "./Pazu/*.inl")
file(GLOB_RECURSE PAZU_ENGINE_SOURCE "./Pazu/*.cpp")

add_library(${PROJECT_NAME} STATIC ${PAZU_ENGINE_HEADER} ${PAZU_ENGINE_INLINE} ${PAZU_ENGINE_SOURCE})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME Pazu)
target_include_directories(${PROJECT_NAME} PUBLIC ${DEPS_INC_HOME})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEPS_LIB_HOME})
target_precompile_headers(${PROJECT_NAME} PUBLIC Pazu/Precompiled.h)

target_compile_definitions(${PROJECT_NAME} PUBLIC "$<$<CONFIG:DEBUG>:_DEBUG>" "$<$<CONFIG:RELEASE>:NDEBUG>")
if(WIN32)
	target_compile_definitions(${PROJECT_NAME} PUBLIC _UNICODE UNICODE _WIN32_WINNT=0x0A00)
endif()
if(SDL_MAIN_HANDLED)
	target_compile_definitions(${PROJECT_NAME} PUBLIC SDL_MAIN_HANDLED)
endif()

if(MINGW)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

	target_link_libraries(${PROJECT_NAME} PUBLIC mingw32 d3d11 dxgi dxguid d3dcompiler uuid kernel32 user32 comdlg32 advapi32 shell32 ole32 oleaut32
		opengl32 SDL2main -lSDL2.dll Glad BulletDynamics BulletCollision LinearMath assimp zlibstatic IrrXML DDSTextureLoader SOIL2 -static-libgcc -static-libstdc++ -static Threads::Threads)
elseif(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")

	target_link_libraries(${PROJECT_NAME} PUBLIC d3d11 dxgi dxguid d3dcompiler uuid kernel32 user32 comdlg32 advapi32 shell32 ole32 oleaut32
		opengl32 SDL2main SDL2 Glad BulletDynamics BulletCollision LinearMath assimp zlibstatic IrrXML DDSTextureLoader SOIL2) # DirectXTK runtimeobject
	target_link_options(${PROJECT_NAME} PUBLIC /DYNAMICBASE /NXCOMPAT)
	target_compile_options(${PROJECT_NAME} PUBLIC /fp:fast)
	target_compile_options(${PROJECT_NAME} PUBLIC /permissive- /Zc:__cplusplus
		"/wd4061" "/wd4365" "/wd4514" "/wd4571" "/wd4668" "/wd4710" "/wd4820" "/wd5039" "/wd5045")
		# "/wd4265" "/wd4625" "/wd4626" "/wd4986" "/wd5204" "/wd5220")

	if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.26)
		target_compile_options(${PROJECT_NAME} PUBLIC /Zc:preprocessor /wd5105)
	endif()
	if(ENABLE_CODE_ANALYSIS)
		target_compile_options(${PROJECT_NAME} PUBLIC /analyze)
	endif()
	if(BUILD_TEST_TEMPLATE)
		target_compile_options(${PROJECT_NAME} PUBLIC "/wd4555")
	endif()
endif()
