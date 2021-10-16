cmake_minimum_required(VERSION 3.15)
project(EX_8 C)

set(CMAKE_C_STANDARD 11)

add_executable(EX_8 main.c dan_math.c dan_math.h)

FIND_PACKAGE(PkgConfig REQUIRED)
FIND_PACKAGE(GSL REQUIRED)
FIND_PACKAGE(BLAS REQUIRED)

PKG_CHECK_MODULES(PLPLOT REQUIRED plplot)

# Use BLAS from Apple instead of GNU cBLAS
message(${GSL_LIBRARY})
message(${BLAS_LIBRARIES})
message(${PLPLOT_LIBRARIES})


# Optimise the release build only, show all build steps when debug
set(CMAKE_C_FLAGS_DEBUG  "-Og -v -g3 -Wall -Werror -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_C_FLAGS_RELEASE "-O3")

target_link_libraries(EX_8 ${GSL_LIBRARY} ${BLAS_LIBRARIES} ${PLPLOT_LINK_LIBRARIES})
target_include_directories(EX_8 PUBLIC ${GSL_INCLUDE_DIRS} ${PLPLOT_INCLUDE_DIRS})