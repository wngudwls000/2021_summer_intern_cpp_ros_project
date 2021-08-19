#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "msg_file/KeyCommand.h"

class Teleop{
public:
    Teleop();
    void loop_process();

    std::map<char, std::vector<float>> moveBindings;
    std::map<char, std::vector<float>> speedBindings;

    const char* msg = R"(
    Reading from the keyboard and Publishing to Twist!
    ---------------------------
    Moving around:
    u    i    o
    j    k    l
    m    ,    .
    For Holonomic mode (strafing), hold down the shift key:
    ---------------------------
    U    I    O
    J    K    L
    M    <    >
    t : up (+z)
    b : down (-z)
    anything else : stop
    q/z : increase/decrease max speeds by 10%
    w/x : increase/decrease only linear speed by 10%
    e/c : increase/decrease only angular speed by 10%
    CTRL-C to quit
    )";

private:
    ros::NodeHandle nh;
    ros::Publisher cmd_pub;
    geometry_msgs::Twist twist;
    msg_file::KeyCommand keycommand;
    std::string cmd_vel_id_;

    float linear_velocity;
    float angular_velocity;
    float x, y, z, th;
    char key;

    int getch();
};