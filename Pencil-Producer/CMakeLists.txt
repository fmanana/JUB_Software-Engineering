cmake_minimum_required(VERSION 3.1.0)

project(Pencil-Producer)

# set Qt for MACOS
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.12.1/clang_64)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

# Populate a CMake variable with the sources
set(pencilproducer_SRCS
    pencilproducer.ui
    pencilproducer.cpp
    main.cpp
    wallet.cpp 
    material_inventory.cpp 
    wood_inventory.cpp 
    graphite_inventory.cpp 
    pencil_inventory.cpp 
    apm2000_inventory.cpp
)
# Tell CMake to create the pencilproducer executable
add_executable(pencilproducer ${pencilproducer_SRCS})
# Use the Widgets module from Qt 5
target_link_libraries(pencilproducer Qt5::Widgets)