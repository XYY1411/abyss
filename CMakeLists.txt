cmake_minimum_required(VERSION 3.29)

set(PROJECT_NAME abyss)
set(PROJECT_VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(${PROJECT_NAME}  VERSION ${PROJECT_VERSION} LANGUAGES CXX)
add_subdirectory(random_generate)
add_subdirectory(dataclass)
add_executable(${PROJECT_NAME} main.cpp scan.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC random_generate)
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${PROJECT_SOURCE_DIR}/random_generate
                           )
target_link_libraries(${PROJECT_NAME} PUBLIC dataclass)
target_include_directories(${PROJECT_NAME} PUBLIC
                            ${PROJECT_BINARY_DIR}
                            ${PROJECT_SOURCE_DIR}/dataclass
                            )
add_compile_options("-Wall" "-Wextra" "-Wpedantic" "-Werror" "-O2" "-static")