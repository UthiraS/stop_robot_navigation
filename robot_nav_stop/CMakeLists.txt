cmake_minimum_required(VERSION 3.8)
project(robot_nav_stop)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)

# Add the executable target for the action client
add_executable(stop_robot src/stop_robot.cpp)
ament_target_dependencies(stop_robot rclcpp rclcpp_action nav2_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Install the executable
install(TARGETS
  stop_robot
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
