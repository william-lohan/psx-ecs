
cmake_minimum_required(VERSION 3.20)

project(
	psx-ecs
	LANGUAGES    C CXX ASM
	VERSION      1.0.0
	DESCRIPTION  "ECS for PSX"
	HOMEPAGE_URL "https://github.com/william-lohan/psx-ecs"
)

file(GLOB _sources *.c)
psn00bsdk_add_executable(psx-ecs STATIC ${_sources})

psn00bsdk_add_cd_image(
	iso      # Target name
	psx-ecs # Output file name (= psx-ecs.bin + psx-ecs.cue)
	iso.xml  # Path to config file
	DEPENDS psx-ecs
)

install(FILES ${PROJECT_BINARY_DIR}/psx-ecs.bin ${PROJECT_BINARY_DIR}/psx-ecs.cue TYPE BIN)
