# Install script for directory: /Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/inst")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/inst/a3")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/inst" TYPE EXECUTABLE FILES "/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/build/src/a3")
  if(EXISTS "$ENV{DESTDIR}/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/inst/a3" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/inst/a3")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/lib"
      "$ENV{DESTDIR}/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/inst/a3")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}/Users/nayeonk/Documents/MIT/Courses/Senior/6.837/starter3/inst/a3")
    endif()
  endif()
endif()

