cmake_minimum_required(VERSION 3.16)
project(firstProject)

set(SOURCE_FILES main.cpp)

#set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/Poco)

add_executable(firstProject main.cpp)

link_directories(src)

include_directories(src)

add_subdirectory(src)
add_subdirectory(thirdParty/poco)

#find_package(Poco REQUIRED Foundation)

#find_library(Poco_Lib Poco /usr/local/lib/cmake/Pogo)

target_link_libraries( ${PROJECT_NAME} 
    src 
    Net
)

#target_link_libraries(firstProject PRIVATE "${FOO_LIB}")
#add_subdirectory(thirdParty/curlpp-0.8.1)