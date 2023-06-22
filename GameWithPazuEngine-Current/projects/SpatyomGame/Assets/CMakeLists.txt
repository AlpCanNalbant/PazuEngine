project(SpatyomGameAssets LANGUAGES CXX)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../../../deps/projects/ResourceManager" "${CMAKE_CURRENT_BINARY_DIR}/../ResourceManager")
rm_embed_resources(RESOURCES
	"Sprites/Characters/Character.DDS" "Sprites/Characters/Character2.DDS" "Sprites/Characters/Character3.DDS"
	"Sprites/Characters/Hand.DDS"	"Sprites/Armors/Ribbon.DDS" "Sprites/Weapons/Bow.DDS"	"Sprites/Weapons/Quiver.DDS"
  "Models/Environment/FlyingRock.fbx"	"Models/Environment/FlyingRockDiff.DDS" "Models/Characters/Dude.fbx"
	"Models/Characters/DudeSkinned.fbx" "Models/Characters/DarkGrass.DDS" "Models/Characters/Dirt.DDS"
	"Textures/Nature/DarkGrass.DDS" "Textures/Nature/Dirt.DDS" "Textures/Environment/Crate.DDS"
	"Textures/Environment/CrateSpec.DDS" "Textures/Environment/CrateLow.DDS" "Textures/HeightMaps/HeightMap.DDS"
	"Textures/Nature/Grass.DDS"	"Textures/Nature/GrassSpec.DDS"	"Textures/Testing/Tile.DDS"	"Textures/Testing/TileSpec.DDS"
	"Shaders/OpenGL/Model/default.shader" "Shaders/OpenGL/Model/diffuse.shader"	"Shaders/Direct3D/Model/default.shader"
	"Shaders/Direct3D/Model/defaultSource.shader"	"Shaders/Direct3D/Model/defaultVS.shader" "Shaders/Direct3D/Model/defaultPS.shader"
	"Shaders/Direct3D/Model/Animated/defaultVS.shader" "Shaders/Direct3D/Model/Animated/defaultPS.shader"
	"Shaders/Direct3D/Model/Animated/default.shader" "Shaders/Model/default.shader" "Shaders/Model/Animated/default.shader")

add_library(${PROJECT_NAME} STATIC ${RESOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${DEPS_INC_HOME})
