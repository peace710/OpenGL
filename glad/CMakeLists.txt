cmake_minimum_required(VERSION 3.28.1)
project("OpenGlGlad")
include_directories("./include")
link_directories("./lib")
file(GLOB_RECURSE src_dir "./src/*.cpp" "./src/*.c" "./src/*.h")
add_executable(${PROJECT_NAME} ${src_dir})
target_link_libraries(${PROJECT_NAME}
glfw3
openGL32
)