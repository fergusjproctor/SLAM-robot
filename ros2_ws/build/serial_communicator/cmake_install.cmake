# Install script for directory: /Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/install/serial_communicator")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Users/fergusproctor/miniforge3/envs/ros_env/bin/llvm-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/serial_communicator" TYPE EXECUTABLE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/serial_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/serial_communicator/serial_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/serial_communicator/serial_node")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/fergusproctor/miniforge3/envs/ros_env/bin/arm64-apple-darwin20.0.0-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/serial_communicator/serial_node")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/CMakeFiles/serial_node.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/serial_communicator" TYPE EXECUTABLE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/simple_serial")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/serial_communicator/simple_serial" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/serial_communicator/simple_serial")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Users/fergusproctor/miniforge3/envs/ros_env/bin/arm64-apple-darwin20.0.0-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/serial_communicator/simple_serial")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/CMakeFiles/simple_serial.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/serial_communicator")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/serial_communicator")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator/environment" TYPE FILE FILES "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator/environment" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator/environment" TYPE FILE FILES "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator/environment" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_index/share/ament_index/resource_index/packages/serial_communicator")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator/cmake" TYPE FILE FILES
    "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_core/serial_communicatorConfig.cmake"
    "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cmake_core/serial_communicatorConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/serial_communicator" TYPE FILE FILES "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
