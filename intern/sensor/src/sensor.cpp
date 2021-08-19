#include "sensor/sensor.h"

Lidar::Lidar(int n_channel, int n_point) : n_channel_(n_channel), n_point_(n_point), pitch(60), normal_random(15, 1){
    dth = n_channel_*360.0/n_point_;
    n_chpoint = n_point_/n_channel_;
    cloud_init0.resize(n_point_);

    if(n_channel_>1){
        dp = pitch/(n_channel_ - 1);
    }
    else{
        dp = 0;
    }
    pcl_topic_id_ = "pcl";
    pcl_pub = nh.advertise<sensor_msgs::PointCloud2>(pcl_topic_id_,1,true);
    sensor_pub = nh.advertise<msg_file::Sensor_TF>("sensor", 1);
}
void Lidar::SetGaussianRandom(double mean, double stddev){
    normal_random.SetGaussian(mean, stddev);
}
void Lidar::SetPitchAngle(double angle){
    pitch = angle;

    if(n_channel_>1){
        dp = pitch/(n_channel_ - 1);
    }
    else{
        dp = 0;
    }
}
void Lidar::GenPCL(){
    cloud_init0.clear();
    for(int i = 0; i < n_channel_; i++){
        for(int j = 0; j < n_chpoint; j++){
            double d = normal_random.GetGaussianRandom();
            double th_pitch = (-pitch/2 + dp*i) / 180 * M_PI;
            double th_yaw = dth * j / 180 * M_PI;
            double x = d*cos(th_pitch)*cos(th_yaw);
            double y = d*cos(th_pitch)*sin(th_yaw);
            double z = d*sin(th_pitch);
            cloud_init0.push_back(pcl::PointXYZ(x, y, z));
        }
    }
}

void Lidar::SetTF(std::string frame_id, std::string child_frame_id, double p_x, double p_y, double p_z, double o_r, double o_p, double o_y){
    sensor_tf.frame_id = frame_id;
    sensor_tf.child_frame_id = child_frame_id;
    child_frame_id_ = child_frame_id;
    sensor_tf.p_x = p_x;
    sensor_tf.p_y = p_y;
    sensor_tf.p_z = p_z;
    sensor_tf.o_r = o_r;
    sensor_tf.o_p = o_p;
    sensor_tf.o_y = o_y;
}

void Lidar::PubTF(){
    sensor_pub.publish(sensor_tf);
}

void Lidar::PubPCL(){
    pcl::PCLPointCloud2 cloud_p;
    pcl::toPCLPointCloud2(cloud_init0, cloud_p);
    sensor_msgs::PointCloud2 pcl_msg;
    pcl_conversions::fromPCL(cloud_p, pcl_msg);
    pcl_msg.header.stamp = ros::Time::now();
    pcl_msg.header.frame_id = child_frame_id_;
    pcl_pub.publish(pcl_msg);
}