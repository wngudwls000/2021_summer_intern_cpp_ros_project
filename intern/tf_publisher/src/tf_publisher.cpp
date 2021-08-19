#include "tf_publisher/tf_publisher.h"
// Tf_publisher::Tf_publisher()
// {
//     tfBroadcaster = new tf2_ros::TransformBroadcaster();
// }

Tf_publisher::Tf_publisher(std::string pose_topic_id, std::string global_frame_id, std::string base_frame_id, std::string lidar_frame_id)
{
    pose_topic_id_ = pose_topic_id;
    global_frame_id_ = global_frame_id;
    base_frame_id_ = base_frame_id;
    lidar_frame_id_ = lidar_frame_id;
    tfBroadcaster = new tf2_ros::TransformBroadcaster();
    tfBuffer = new tf2_ros::Buffer();
    tfListener = new tf2_ros::TransformListener(*tfBuffer);
    // filter_sub_ = new message_filters::Subscriber<geometry_msgs::TransformStamped>(nh, pose_topic_id_, 10);
    // filter_ = new tf2_ros::MessageFilter<geometry_msgs::TransformStamped>(*filter_sub_, *tfBuffer, global_frame_id_, 10, nh);
    // filter_->registerCallback(boost::bind(&Tf_publisher::update, this, _1));
    pose_sub = nh.subscribe(pose_topic_id_, 100, &Tf_publisher::TfCallback, this);
    sensor_sub = nh.subscribe(lidar_frame_id_, 100, &Tf_publisher::SensorCallback, this);
}

Tf_publisher::~Tf_publisher()
{
    if (tfBroadcaster)
        delete tfBroadcaster; 
    if (tfListener)
        delete tfListener;
    if (tfBuffer)
        delete tfBuffer;
}
void Tf_publisher::TfCallback(const geometry_msgs::TransformStamped msg)
{
    tf_publish(msg);
}
void Tf_publisher::SensorCallback(msg_file::Sensor_TF sensor_msg)
{
    static_tf_broadcast(sensor_msg.frame_id, sensor_msg.child_frame_id, sensor_msg.p_x, sensor_msg.p_y, sensor_msg.p_z, sensor_msg.o_r, sensor_msg.o_p, sensor_msg.o_y);
}
void Tf_publisher::tf_publish(geometry_msgs::TransformStamped pose_msg)
{
    tfBroadcaster->sendTransform(pose_msg);
}
void Tf_publisher::static_tf_broadcast(std::string frame_id, std::string chile_frame_id, double p_x, double p_y, double p_z, double o_r, double o_p, double o_y)
{
    geometry_msgs::TransformStamped trans;
    trans.header.stamp = ros::Time::now();
    trans.header.frame_id = frame_id;
    trans.child_frame_id = chile_frame_id;

    tf2::Quaternion q;
    q.setRPY(o_r, o_p, o_y);

    tf2::Transform tf;
    tf = tf2::Transform(q, tf2::Vector3(p_x, p_y, p_z));

    tf2::convert(tf, trans.transform);
    tfBroadcaster->sendTransform(trans);
}

// void Tf_publisher::update(const geometry_msgs::TransformStampedConstPtr& message){
//   std::cout << "test3" <<std::endl;
//   tf2::Transform txi;
//   tf2::convert(message->transform, txi);

//   geometry_msgs::TransformStamped trans;
//   trans = *message;
//   trans.header.stamp = message->header.stamp;
//   trans.header.frame_id = global_frame_id_;
//   trans.child_frame_id = base_frame_id_;

//   tfBroadcaster->sendTransform(trans);
// };