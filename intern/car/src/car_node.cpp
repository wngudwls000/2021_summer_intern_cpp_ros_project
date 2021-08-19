#include "car/car.h"
 
int main(int argc, char** argv)
{
    ros::init(argc, argv, "car_node");
    ros::NodeHandle private_nh("~");

    std::string cmd_vel_id_;
    std::string pose_topic_id_;
    std::string child_frame_id_;
    std::string frame_id_;

    private_nh.param("cmd_vel_id", cmd_vel_id_, std::string("/cmd_vel"));
    private_nh.param("pose_topic_id", pose_topic_id_, std::string("/vehicle_pose"));
    private_nh.param("child_frame_id", child_frame_id_, std::string("/vehicle"));
    private_nh.param("frame_id", frame_id_, std::string("/map"));

    Car car(cmd_vel_id_, pose_topic_id_, child_frame_id_, frame_id_);
    car.CarControl();

    return 0;
}