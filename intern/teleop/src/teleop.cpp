#include "teleop/teleop.h"

Teleop::Teleop()
{
    ros::NodeHandle private_nh("~");
    private_nh.param("cmd_vel_id", cmd_vel_id_, std::string("cmd_vel"));

    linear_velocity = 0.5;
    angular_velocity = 1.0;
    x = y = z = th = 0;
    key = ' ';

    cmd_pub = nh.advertise<msg_file::KeyCommand>("cmd_vel", 1);
    std::cout << msg;
    std::cout << "\rLinear_velocity : " << linear_velocity << "\tAngular_velocity : " << angular_velocity << " | Awaiting command... \r";
    
    moveBindings = 
    {
    {'i', {1, 0, 0, 0}},
    {'o', {1, 0, 0, -1}},
    {'j', {0, 0, 0, 1}},
    {'l', {0, 0, 0, -1}},
    {'u', {1, 0, 0, 1}},
    {',', {-1, 0, 0, 0}},
    {'.', {-1, 0, 0, 1}},
    {'m', {-1, 0, 0, -1}},
    {'O', {1, -1, 0, 0}},
    {'I', {1, 0, 0, 0}},
    {'J', {0, 1, 0, 0}},
    {'L', {0, -1, 0, 0}},
    {'U', {1, 1, 0, 0}},
    {'<', {-1, 0, 0, 0}},
    {'>', {-1, -1, 0, 0}},
    {'M', {-1, 1, 0, 0}},
    {'t', {0, 0, 1, 0}},
    {'b', {0, 0, -1, 0}},
    {'k', {0, 0, 0, 0}},
    {'K', {0, 0, 0, 0}}
    };

    speedBindings =
    {
    {'q', {1.1, 1.1}},
    {'z', {0.9, 0.9}},
    {'w', {1.1, 1}},
    {'x', {0.9, 1}},
    {'e', {1, 1.1}},
    {'c', {1, 0.9}}
    };
}

int Teleop::getch()
{
    int ch;
    struct termios oldt;
    struct termios newt;

    // Store old settings, and copy to new settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Make required changes and apply the settings
    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_iflag |= IGNBRK;
    newt.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF);
    newt.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | ISIG | IEXTEN);
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &newt);

    // Get the current character
    ch = getchar();

    // Reapply old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void Teleop::loop_process()
{
    while(true)
    {
        key = getch();

        if (moveBindings.count(key) == 1)
        {
            x = moveBindings[key][0];
            y = moveBindings[key][1];
            z = moveBindings[key][2];
            th = moveBindings[key][3];

            std::cout << "\nLinear_velocity : " << linear_velocity << "\tAngular_velocity : " << angular_velocity << " | Last command : " << key;
        }
        else if (speedBindings.count(key) == 1)
        {
            linear_velocity = linear_velocity * speedBindings[key][0];
            angular_velocity = angular_velocity * speedBindings[key][1];

            std::cout << "\nLinear_velocity : " << linear_velocity << "\tAngular_velocity : " << angular_velocity << " | Last command : " << key;
        }
        else
        {
            x = 0;
            y = 0;
            z = 0;
            th = 0;
            if(key == '\x03')
            {
                printf("\n\n                 .     .\n              .  |\\-^-/|  .    \n             /| } O.=.O { |\\\n\n                 CHREERS\n\n");
                break;
            }
            std::cout << "\nLinear_velocity : " << linear_velocity << "\tAngular_velocity : " << angular_velocity << " | Last command : " << key;

        }
        twist.linear.x = x * linear_velocity;
        twist.linear.y = y * linear_velocity;
        twist.linear.z = z * linear_velocity;

        twist.angular.x = 0;
        twist.angular.y = 0;
        twist.angular.z = th * angular_velocity;

        keycommand.go = twist.linear.x;
        keycommand.turn = twist.angular.z;

        cmd_pub.publish(keycommand);
        ros::spinOnce;
    }
}