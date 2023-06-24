add_subdirectory("Assets")
set(GAME_VERSION 0.1)
project(Sample VERSION ${GAME_VERSION} LANGUAGES CXX)

file(GLOB_RECURSE GAME_HEADER "./Game/*.h")
file(GLOB_RECURSE GAME_INLINE "./Game/*.inl")
file(GLOB_RECURSE GAME_SOURCE "./Game/*.cpp")

add_executable(${PROJECT_NAME} ${GAME_HEADER} ${GAME_INLINE} ${GAME_SOURCE}) # WIN32

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME GameWithPazuEngine)
target_include_directories(${PROJECT_NAME} PRIVATE "../PazuEngine")
target_link_libraries(${PROJECT_NAME} PRIVATE PazuEngine SampleAssets)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${INSTALL_BIN_HOME})
