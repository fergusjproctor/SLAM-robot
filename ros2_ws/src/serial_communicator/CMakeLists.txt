cmake_minimum_required(VERSION 3.8)
project(serial_communicator)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(geometry_msgs REQUIRED)


set(dependencies "geometry_msgs" "rclcpp" "std_msgs")

include_directories(
  include
  ${Boost_INCLUDE_DIRS}
)

add_executable(serial_node src/serial_node.cpp)
add_executable(simple_serial src/simple_serial.cpp)

ament_target_dependencies(serial_node ${dependencies}
)

target_link_libraries(serial_node ${Boost_LIBRARIES})
target_link_libraries(simple_serial ${Boost_LIBRARIES})

install(TARGETS
  serial_node
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  simple_serial
  DESTINATION lib/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
