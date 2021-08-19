#include <ros/ros.h>
#include <ros/time.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/convert.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <iostream>
#include "msg_file/KeyCommand.h"

class Car{
public:
    Car(std::string cmd_vel_id, std::string pose_topic_id, std::string child_frame_id, std::string frame_id);
    void CarControl();
    void PosePub(geometry_msgs::TransformStamped msg);

private:
    void CmdCallback(const msg_file::KeyCommand::ConstPtr& msg);

    ros::NodeHandle nh;
    ros::Publisher car_pose_pub;
    ros::Subscriber cmd_vel_sub;
    ros::Time current_time, last_time;
    ros::Duration durantion;
    tf2::Transform tf;
    int64_t dt;

    geometry_msgs::TransformStamped tfstamped;
    geometry_msgs::Twist twist;
    msg_file::KeyCommand keycommand;

    std::string cmd_vel_id_;
    std::string pose_topic_id_;
    std::string child_frame_id_;
    std::string frame_id_;
};