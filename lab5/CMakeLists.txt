cmake_minimum_required(VERSION 3.8)

project(main)
include_directories(include)

add_library(lib1 SHARED src/lib1.c)
add_library(lib2 SHARED src/lib2.c)

add_executable(main1 src/main1.c include/lib.h)
add_executable(main2 src/main2.c include/lib.h)
target_link_libraries(main1 lib1)
target_link_libraries(main2 lib2)

if (NOT (DEFINED LIB_PRINT_TYPE))
	set(LIB_PRINT_TYPE EXTENDED)
endif ()

if (LIB_PRINT_TYPE STREQUAL EXTENDED)
	add_compile_definitions(SYSTEM="${CMAKE_SYSTEM}")
elseif (NOT (LIB_PRINT_TYPE STREQUAL DEFAULT))
	message(FATAL_ERROR "Unexpected LIB_PRINT_TYPE: ${LIB_PRINT_TYPE}")
endif ()

add_executable(main src/main2.c)
target_link_libraries(main ${CMAKE_DL_LIBS})
