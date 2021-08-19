#include "teleop/teleop.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "teleop_node");

    Teleop teleop;
    teleop.loop_process();

    return 0;
}