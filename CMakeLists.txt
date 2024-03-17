cmake_minimum_required(VERSION 3.16)
project(Survival LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


set(PROJECT_HEADERS 

    include/game.h
    include/protagonista.h
    include/enemy.h
    include/enemyVillain.h
    include/enemySuperVillain.h
    include/enemyManager.h
    include/plataforma.h
    include/position.h
    include/screenSize.h
    include/map.h
    include/gameManager.h
    include/shoot.h
    include/ObjectPooler.h
    include/effects.h
    include/initScene.h
    include/UIManager.h
    include/life.h
    include/music.h


)

set(PROJECT_SOURCES 
    src/game.cpp
    src/main.cpp
    src/protagonista.cpp
    src/enemy.cpp
    src/enemyVillain.cpp
    src/enemySuperVillain.cpp
    src/enemyManager.cpp
    src/plataforma.cpp
    src/map.cpp
    src/gameManager.cpp
    src/shoot.cpp
    src/ObjectPooler.cpp
    src/effects.cpp
    src/InitScene.cpp
    src/UIManager.cpp
    src/life.cpp
    src/music.cpp
)

set(PROJECT_FILES 
  ${PROJECT_HEADERS} 
  ${PROJECT_SOURCES}
)

include_directories(${PROJECT_NAME} PRIVATE include)

add_executable(${PROJECT_NAME} ${PROJECT_FILES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})