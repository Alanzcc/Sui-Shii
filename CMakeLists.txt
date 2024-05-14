cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME Sui-Shii)
project(${PROJECT_NAME} VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set(LIBS_DIR libs)
# set(LIBS XXXXX)

set(SOURCE_DIR src)
set(SOURCE ${SOURCE_DIR}/run.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})
