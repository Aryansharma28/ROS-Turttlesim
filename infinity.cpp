#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>

using namespace std;
const double PI = 3.14159265359;

int main(int argc, char **argv)
{
        ros::init(argc, argv, "infinity");
        ros::NodeHandle n;


        ros::Publisher velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

        ros::Rate loop_rate(1);

        //      /turtle1/cmd_vel is the Topic name
        //      /geometry_msgs::Twist is the msg type 
        ROS_INFO("\n\n\n ********DEMO- Drawing Infinity Symbol*********\n");

        geometry_msgs::Twist vel_msg;

        vel_msg.linear.x =12;
        vel_msg.linear.y =0;
        vel_msg.linear.z =0;

        vel_msg.angular.x = 0;
        vel_msg.angular.y = 0;
        vel_msg.angular.z =2*PI;

        loop_rate.sleep();
        velocity_publisher.publish(vel_msg);
        ROS_INFO("\n\n\n ***** Completed One CIRCLE ****\n");
        vel_msg.angular.z =-2*PI;
        loop_rate.sleep();
        ROS_INFO("\n\n\n ***** Draw another CIRCLE ****\n");
        velocity_publisher.publish(vel_msg);

        ros::spin();
        return 0;
}
