#include <iostream>
#include <cmath>
#include <ros/ros.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include "sensor/gaussian.h"
#include "msg_file/Sensor_TF.h"

class Lidar{
public:
    Lidar(int n_channel, int n_point);
    
    void SetPitchAngle(double angle);
    void SetGaussianRandom(double mean, double stddev);
    void SetTF(std::string frame_id, std::string child_frame_id, 
                double p_x, double p_y, double p_z, double o_r, double o_p, double o_y);
    void GenPCL();
    void PubTF();
    void PubPCL();

private:
    int n_channel_, n_point_, n_chpoint;
    double pitch, dp;
    double dth;

    std::string frame_id_, child_frame_id_, pcl_topic_id_;
    double p_x_, p_y_, p_z_, o_r_, o_p_, o_y_;

    Gaussian normal_random;

    ros::NodeHandle nh;
    ros::Publisher pcl_pub;
    ros::Publisher sensor_pub;
    msg_file::Sensor_TF sensor_tf;
    
    pcl::PointCloud<pcl::PointXYZ> cloud_init0;
};
