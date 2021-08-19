#include "tf_publisher/tf_publisher.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "tf_publisher_node");
    ros::NodeHandle private_nh("~");  
    std::string base_frame_id_, global_frame_id_, pose_topic_id_, lidar_frame_id_;

    private_nh.param("global_frame_id", global_frame_id_, std::string("/map"));
    private_nh.param("base_frame_id", base_frame_id_, std::string("/vehicle"));
    private_nh.param("lidar_frame_id", lidar_frame_id_, std::string("/sensor"));
    private_nh.param("pose_topic_id", pose_topic_id_, std::string("/vehicle_pose"));

    Tf_publisher tf_publisher(pose_topic_id_, global_frame_id_, base_frame_id_, lidar_frame_id_);

    ros::spin();

    return 0;
}