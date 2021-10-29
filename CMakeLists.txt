cmake_minimum_required(VERSION 3.22)
project("xcoreutils"
    LANGUAGES
        C
    VERSION
        0.1.0.1
    DESCRIPTION
        "A Windows-native re-implementation of the GNU Coreutils")

option(BUILD_CAT "Build the cat utility" ON)
if(${BUILD_CAT})
    add_subdirectory("cat")
    message(VERBOSE "Build cat: ${BUILD_CAT}")
endif()

option(BUILD_SEQ "Build the seq utility" ON)
if(${BUILD_SEQ})
    #add_subdirectory("seq")
    message(VERBOSE "Build seq: ${BUILD_SEQ}")
    message(WARNING "Building seq via CMake is not yet implemented.")
endif()

option(BUILD_WC "Build the wc utility" ON)
if(${BUILD_WC})
    #add_subdirectory("wc")
    message(VERBOSE "Build wc: ${BUILD_WC}")
    message(WARNING "Building wc via CMake is not yet implemented.")
endif()
