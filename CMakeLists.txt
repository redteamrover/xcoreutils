cmake_minimum_required(VERSION 3.22)
project("xcoreutils"
    LANGUAGES
        C
    VERSION
        0.1.0.1
    DESCRIPTION
        "A Windows-native re-implementation of the GNU Coreutils"
    HOMEPAGE_URL
        "https://github.com/redteamrover/xcoreutils")

option(BUILD_SHARED_LIBS "Build shared libraries instead of static-linking the runtime directly" ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_subdirectory("lib")

option(BUILD_CAT "Build the cat utility" ON)
if(${BUILD_CAT})
    add_subdirectory("cat")
    message(VERBOSE "Build cat: ${BUILD_CAT}")
endif()

option(BUILD_CP "Build the cp utility" ON)
if(${BUILD_CP})
    add_subdirectory("cp")
    message(VERBOSE "Build cp: ${BUILD_CP}")
endif()

option(BUILD_SEQ "Build the seq utility" ON)
if(${BUILD_SEQ})
    add_subdirectory("seq")
    message(VERBOSE "Build seq: ${BUILD_SEQ}")
endif()

option(BUILD_WC "Build the wc utility" ON)
if(${BUILD_WC})
    add_subdirectory("wc")
    message(VERBOSE "Build wc: ${BUILD_WC}")
endif()
