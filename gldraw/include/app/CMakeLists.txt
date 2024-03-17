file(GLOB_RECURSE APP "./*.cpp" "./*.c" "./*.h")

add_library(app ${APP})