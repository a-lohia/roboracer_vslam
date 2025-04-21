cmake_minimum_required(VERSION 3.5)
project(roboracer_vslam)
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

# Find Packages
foreach(PACKAGE 
  rclcpp
  nav_msgs
  sensor_msgs
  geometry_msgs
  visualization_msgs
  Eigen3
  tf2_ros)

  find_package(${PACKAGE} REQUIRED)

endforeach()

# Include CPP Headers
include_directories(include/${PROJECT_NAME})
include_directories(
  ${EIGEN3_INCLUDE_DIRS}
)

# Create Executable
add_executable(vslam_node src/vslam_node.cpp)
ament_target_dependencies(
    vslam_node rclcpp sensor_msgs nav_msgs visualization_msgs geometry_msgs Eigen3 tf2_ros
)

# Install Targets
install(TARGETS
    vslam_node
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()