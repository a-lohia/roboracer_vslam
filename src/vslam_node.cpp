#include "vslam_node.hpp"

// Standard Imports
#include <stdio.h>


VSLAMNode::VSLAMNode() : Node("vslam_node") {

    // ROS2 Objects
    camera_sub_ = create_subscription<sensor_msgs::msg::Image>(
        "/camera/camera/color/image_raw", 10,
        [this](const sensor_msgs::msg::Image::SharedPtr msg) {camera_callback(msg);}
    );
    imu_sub_ = create_subscription<sensor_msgs::msg::Imu>(
        "/camera/camera/imu", 10,
        [this](const sensor_msgs::msg::Imu::SharedPtr msg) {imu_callback(msg);}
    );

    pose_pub_ = create_publisher<nav_msgs::msg::Odometry>("/vslam/pose", 10);

    RCLCPP_INFO(get_logger(), "VSLAM STARTED!");
}

void VSLAMNode::camera_callback(const sensor_msgs::msg::Image::SharedPtr msg) {
    (void)msg;
    return;
}

void VSLAMNode::imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg) {
    (void)msg;
    return;
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VSLAMNode>());
    rclcpp::shutdown();
    return 0;
}