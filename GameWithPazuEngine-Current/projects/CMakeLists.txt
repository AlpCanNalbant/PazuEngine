cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
cmake_policy(VERSION 3.22)
project(GameWithPazuEngine LANGUAGES CXX)

math(EXPR BITS "8 * ${CMAKE_SIZEOF_VOID_P}" OUTPUT_FORMAT DECIMAL)
if(${BITS} EQUAL 64)
	set(PROCESSOR_ARCH "x64")
else()
	set(PROCESSOR_ARCH "x86")
endif()
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/.." CACHE PATH "..." FORCE)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(SDL_MAIN_HANDLED "" OFF)

if(MINGW)
	set(COMPILER_NAME "mingw")
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
	set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
	set(THREADS_PREFER_PTHREAD_FLAG TRUE)
	find_package(Threads REQUIRED)

	if(${CMAKE_BUILD_TYPE} STREQUAL Release)
		add_compile_options(-m${BITS})
	else()
		add_compile_options(-m${BITS} -Wall -Wextra -Wformat=2 -Wunused -Wpedantic -std=c++20) #-Wshadow; #-Wfatal-errors ilk hatada durma ayari
	endif()
elseif(MSVC)
	set(COMPILER_NAME "msvc")
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
	set(CMAKE_VS_WINDOWS_TARGET_PLATFORM_VERSION_MAXIMUM 10.0.19041.0)
	option(BUILD_TEST_TEMPLATE "Ignore warnings related to TODOs" OFF)
	option(ENABLE_CODE_ANALYSIS "Use Static Code Analysis on build" OFF)

	# Maximum uyari ayari seviyesini kullan
	string(REPLACE "/W4 " "/Wall " CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
	string(REPLACE "/W4 " "/Wall " CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
	string(REPLACE "/W4 " "/Wall " CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})

	set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT SpatyomGame)
endif()

set(DEPS_HOME "${CMAKE_SOURCE_DIR}/../deps")
set(DEPS_INC_HOME "${DEPS_HOME}/include/${COMPILER_NAME}")
set(DEPS_LIB_HOME "${DEPS_HOME}/lib/${COMPILER_NAME}/${PROCESSOR_ARCH}/${CMAKE_BUILD_TYPE}")
set(INSTALL_BIN_HOME "publish/${COMPILER_NAME}/${PROCESSOR_ARCH}/${CMAKE_BUILD_TYPE}")

add_subdirectory("PazuEngine")
add_subdirectory("SpatyomGame")
