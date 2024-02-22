file(GLOB_RECURSE WRAPPER "./*.cpp" "./*.c" "./*.h")

add_library(wrapper ${WRAPPER})