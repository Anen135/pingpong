cmake_minimum_required(VERSION 3.16)

project(PingPong LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

add_executable(PingPong ${SOURCES}
    include/terminal.h
    src/terminal.cpp)

target_include_directories(PingPong PRIVATE include)

# --- preprocess target ---
get_target_property(INC_DIRS PingPong INCLUDE_DIRECTORIES)

# превращаем include dirs в список аргументов
set(INCLUDE_ARGS "")
foreach(dir ${INC_DIRS})
    list(APPEND INCLUDE_ARGS /I "${dir}")
endforeach()

add_custom_target(preprocess
    COMMAND ${CMAKE_CXX_COMPILER}
        /P
        /TP
        /Fi"${CMAKE_BINARY_DIR}/main.i"
        ${INCLUDE_ARGS}
        "${CMAKE_SOURCE_DIR}/src/main.cpp"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating preprocessed file main.i"
)

if (WIN32)
    target_link_libraries(PingPong PRIVATE user32)
endif()