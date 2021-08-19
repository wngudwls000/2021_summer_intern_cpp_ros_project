#include "sensor/sensor.h"


int main(int argc, char** argv){
    ros::init(argc, argv, "lidar_node");
    ros::NodeHandle private_nh("~");  

    std::string frame_id, child_frame_id;
    int n_channel, n_point;
    double angle, mean, stddev;
    double p_x, p_y, p_z, o_r, o_p, o_y;

    private_nh.param("frame_id", frame_id, std::string("/vehicle"));
    private_nh.param("child_frame_id", child_frame_id, std::string("/sensor"));
    private_nh.param("n_channel", n_channel, 5);   
    private_nh.param("n_point", n_point, 360);
    private_nh.param("mean", mean, 15.0);
    private_nh.param("stddev", stddev, 1.0);  
    private_nh.param("angle", angle, 60.0);
    private_nh.param("p_x", p_x, 5.0);
    private_nh.param("p_y", p_y, 0.0);
    private_nh.param("p_z", p_x, 0.0);
    private_nh.param("o_r", o_r, 0.0);
    private_nh.param("o_p", o_p, 0.0);
    private_nh.param("o_y", o_y, 0.0);
    

    Lidar lidar(n_channel, n_point);
    lidar.SetPitchAngle(angle);
    lidar.SetGaussianRandom(mean, stddev);
    lidar.SetTF(frame_id, child_frame_id, p_x, p_y, p_z, o_r, o_p, o_y);

    ros::Rate loop_rate(30);

    while(ros::ok()){
        lidar.GenPCL();
        lidar.PubTF();
        lidar.PubPCL();
        loop_rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
