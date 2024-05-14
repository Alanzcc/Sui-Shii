cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME Sui-Shii)
project(${PROJECT_NAME} VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set(LIBS_DIR libs)
# set(LIBS ~/usr/share/mongo-cxx-driver)

set(SOURCE_DIR src)
set(SOURCE ${SOURCE_DIR}/run.cpp)

find_package(mongocxx CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME}
  PRIVATE mongo::mongocxx_shared
)

get_target_property(LIBMONGOCXX_DEFINITIONS mongo::mongocxx_shared INTERFACE_COMPILE_DEFINITIONS)
list(FIND LIBMONGOCXX_DEFINITIONS "BSONCXX_STATIC" LIST_IDX)
if (${LIST_IDX} GREATER -1)
    message(FATAL_ERROR "Expected BSONCXX_STATIC to not be defined")
endif()
list(FIND LIBMONGOCXX_DEFINITIONS "MONGOCXX_STATIC" LIST_IDX)
if (${LIST_IDX} GREATER -1)
    message(FATAL_ERROR "Expected MONGOCXX_STATIC to not be defined")
endif()

