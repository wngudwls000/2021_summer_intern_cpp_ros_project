#include "car/car.h"

Car::Car(std::string cmd_vel_id, std::string pose_topic_id, std::string child_frame_id, std::string frame_id)
        : cmd_vel_id_(cmd_vel_id), pose_topic_id_(pose_topic_id), child_frame_id_(child_frame_id), frame_id_(frame_id)
{
    tfstamped.header.frame_id = frame_id_;
    tfstamped.child_frame_id = child_frame_id_;
    cmd_vel_sub = nh.subscribe(cmd_vel_id_, 100, &Car::CmdCallback, this);
    car_pose_pub = nh.advertise<geometry_msgs::TransformStamped>(pose_topic_id_, 1, true);
    current_time = last_time = ros::Time::now();
    tf.setIdentity();
}

void Car::CmdCallback(const msg_file::KeyCommand::ConstPtr& msg)
{
    keycommand = *msg;
}

void Car::PosePub(geometry_msgs::TransformStamped msg)
{
    car_pose_pub.publish(msg);
}

void Car::CarControl()
{
    current_time = last_time = ros::Time::now();
    ros::Rate loop_rate(30);
    while (ros::ok())
    {
        tf2::Transform dtf;
        tf2::Quaternion q;

        current_time = ros::Time::now();
        durantion = current_time - last_time;
        last_time = current_time;

        dt = durantion.toNSec();

        double delta_yaw_ = keycommand.turn * dt / 1000000000;

        q.setRPY(0.0, 0.0, delta_yaw_);

        double delta_x = keycommand.go * dt / 1000000000;
        dtf = tf2::Transform(q, tf2::Vector3(delta_x, 0, 0));
        tf = tf * dtf;

        tfstamped.header.stamp = ros::Time::now();
        tf2::convert(tf, tfstamped.transform);
        PosePub(tfstamped);
        loop_rate.sleep();
        ros::spinOnce();
    }
}