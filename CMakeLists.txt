cmake_minimum_required(VERSION 3.17)
project(udp_test)

set(CMAKE_CXX_STANDARD 17)

set(CONAN_CMAKE_VERSION 0.15)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v${CONAN_CMAKE_VERSION}/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake"
                 TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
        REQUIRES
        boost/1.74.0
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
)

add_executable(udp_test main.cpp)
target_link_libraries(udp_test
        CONAN_PKG::boost
        pthread)
