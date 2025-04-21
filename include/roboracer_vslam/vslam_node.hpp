#pragma once

// ROS2 Imports
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "nav_msgs/msg/odometry.hpp"

// Standard Imports
#include <memory>

class VSLAMNode : public rclcpp::Node {
    
    public:
        // Constructor Declaration
        VSLAMNode();

    private: 
        // ROS2 Pub/Sub
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr camera_sub_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;

        // Pose Pub
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pose_pub_;
        // Map Pub?

        // ROS Params

        // Methods
        void camera_callback(const sensor_msgs::msg::Image::SharedPtr msg);

        void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg);
};

