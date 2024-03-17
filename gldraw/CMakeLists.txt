cmake_minimum_required(VERSION 3.28.1)
project("OpenGlDraw")
set(CMAKE_CXX_STANDARD 17)
#项目中添加一个预编译的宏
add_definitions(-DDEBUG)

include_directories("./include")
link_directories("./lib")
file(GLOB_RECURSE src_dir "./src/*.cpp" "./src/*.c" "./src/*.h")
add_subdirectory("./include/wrapper")
add_subdirectory("./include/app")
add_executable(${PROJECT_NAME} ${src_dir})
target_link_libraries(${PROJECT_NAME}
app
glfw3
openGL32
wrapper
)