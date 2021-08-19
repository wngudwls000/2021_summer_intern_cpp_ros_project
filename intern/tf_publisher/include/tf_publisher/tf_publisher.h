#include <ros/ros.h>
#include <ros/time.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/convert.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/message_filter.h>
#include "message_filters/subscriber.h"
#include <iostream>
#include "msg_file/Sensor_TF.h"

class Tf_publisher{
public:
    Tf_publisher();
    Tf_publisher(std::string pose_topic_id, std::string global_frame_id, std::string base_frame_id, std::string lidar_frame_id);
    ~Tf_publisher();
    void tf_publish(geometry_msgs::TransformStamped);
    void static_tf_broadcast(std::string frame_id, std::string chile_frame_id,
                            double p_x, double p_y, double p_z, double o_r, double o_p, double o_y);
    // void update(const geometry_msgs::TransformStampedConstPtr& msg);

private:
    void TfCallback(const geometry_msgs::TransformStamped msg);
    void SensorCallback(msg_file::Sensor_TF sensor_msg);

    ros::NodeHandle nh;
    // message_filters::Subscriber<geometry_msgs::TransformStamped>* filter_sub_;
    ros::Publisher pose_pub;
    ros::Subscriber pose_sub;
    ros::Subscriber sensor_sub;
    tf2_ros::TransformBroadcaster *tfBroadcaster;
    tf2_ros::TransformListener *tfListener;
    tf2_ros::Buffer *tfBuffer;
    // tf2_ros::MessageFilter<geometry_msgs::TransformStamped>* filter_;

    std::string lidar_frame_id_;
    std::string base_frame_id_;
    std::string global_frame_id_;
    std::string pose_topic_id_;
};