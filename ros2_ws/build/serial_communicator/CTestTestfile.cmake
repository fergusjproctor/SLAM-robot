# CMake generated Testfile for 
# Source directory: /Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator
# Build directory: /Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cppcheck "/opt/homebrew/Frameworks/Python.framework/Versions/3.12/bin/python3.12" "-u" "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_test/cmake/run_test.py" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/test_results/serial_communicator/cppcheck.xunit.xml" "--package-name" "serial_communicator" "--output-file" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_cppcheck/cppcheck.txt" "--command" "/Users/fergusproctor/miniforge3/envs/ros_env/bin/ament_cppcheck" "--xunit-file" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/test_results/serial_communicator/cppcheck.xunit.xml" "--include_dirs" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/include")
set_tests_properties(cppcheck PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator" _BACKTRACE_TRIPLES "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;66;ament_add_test;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;87;ament_cppcheck;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/CMakeLists.txt;56;ament_package;/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/CMakeLists.txt;0;")
add_test(lint_cmake "/opt/homebrew/Frameworks/Python.framework/Versions/3.12/bin/python3.12" "-u" "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_test/cmake/run_test.py" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/test_results/serial_communicator/lint_cmake.xunit.xml" "--package-name" "serial_communicator" "--output-file" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_lint_cmake/lint_cmake.txt" "--command" "/Users/fergusproctor/miniforge3/envs/ros_env/bin/ament_lint_cmake" "--xunit-file" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/test_results/serial_communicator/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator" _BACKTRACE_TRIPLES "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/CMakeLists.txt;56;ament_package;/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/CMakeLists.txt;0;")
add_test(uncrustify "/opt/homebrew/Frameworks/Python.framework/Versions/3.12/bin/python3.12" "-u" "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_test/cmake/run_test.py" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/test_results/serial_communicator/uncrustify.xunit.xml" "--package-name" "serial_communicator" "--output-file" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_uncrustify/uncrustify.txt" "--command" "/Users/fergusproctor/miniforge3/envs/ros_env/bin/ament_uncrustify" "--xunit-file" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/test_results/serial_communicator/uncrustify.xunit.xml")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator" _BACKTRACE_TRIPLES "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;70;ament_add_test;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;43;ament_uncrustify;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;0;;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/CMakeLists.txt;56;ament_package;/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/CMakeLists.txt;0;")
add_test(xmllint "/opt/homebrew/Frameworks/Python.framework/Versions/3.12/bin/python3.12" "-u" "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_test/cmake/run_test.py" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/test_results/serial_communicator/xmllint.xunit.xml" "--package-name" "serial_communicator" "--output-file" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/ament_xmllint/xmllint.txt" "--command" "/Users/fergusproctor/miniforge3/envs/ros_env/bin/ament_xmllint" "--xunit-file" "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/build/serial_communicator/test_results/serial_communicator/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator" _BACKTRACE_TRIPLES "/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/Users/fergusproctor/miniforge3/envs/ros_env/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/CMakeLists.txt;56;ament_package;/Users/fergusproctor/dev/SLAM-robot/ros2_ws/src/serial_communicator/CMakeLists.txt;0;")
