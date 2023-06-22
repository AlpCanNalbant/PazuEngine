add_subdirectory("Assets")
set(SPATYOM_GAME_VERSION 0.1)
project(SpatyomGame VERSION ${SPATYOM_GAME_VERSION} LANGUAGES CXX)

file(GLOB_RECURSE SPATYOM_GAME_HEADER "./Spatyom/*.h")
file(GLOB_RECURSE SPATYOM_GAME_INLINE "./Spatyom/*.inl")
file(GLOB_RECURSE SPATYOM_GAME_SOURCE "./Spatyom/*.cpp")

add_executable(${PROJECT_NAME} ${SPATYOM_GAME_HEADER} ${SPATYOM_GAME_INLINE} ${SPATYOM_GAME_SOURCE}) # WIN32

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME Spatyom)
target_include_directories(${PROJECT_NAME} PRIVATE "../PazuEngine")
target_link_libraries(${PROJECT_NAME} PRIVATE PazuEngine SpatyomGameAssets)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${INSTALL_BIN_HOME})
