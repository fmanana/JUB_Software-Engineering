cmake_minimum_required(VERSION 3.10.2)
project(testPencil)

enable_testing()

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(TEST_SRC
    ../Pencil-Producer/wallet.cpp 
    ../Pencil-Producer/material_inventory.cpp 
    ../Pencil-Producer/wood_inventory.cpp 
    ../Pencil-Producer/graphite_inventory.cpp 
    ../Pencil-Producer/pencil_inventory.cpp 
    ../Pencil-Producer/apm2000_inventory.cpp
    )
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Test REQUIRED)

if(CMAKE_COMPILER_IS_GNUCC)
    add_definitions(-Wall -Werror)
endif(CMAKE_COMPILER_IS_GNUCC)
  
add_executable(testpencils tst_test.cpp ${TEST_SRC})
add_test(testpencils testpencils)

target_link_libraries(testpencils Qt5::Test)
