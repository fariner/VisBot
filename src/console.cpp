#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"


void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{	
  //ROS_INFO("I heard lineal: [%f]", msg->twist.twist.linear.x);
  //ROS_INFO("I heard angular: [%f]", msg->twist.twist.angular.z);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Linear Velocity: [%f]\n", msg->twist.twist.linear.x);
    printf("Angular Velocity: [%f]\n", msg->twist.twist.angular.z);
    fflush(stdout);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "console");

  
  ros::NodeHandle n;
 
  
  ros::Subscriber sub = n.subscribe("odom", 10, odomCallback);

  
  ros::spin();

  return 0;
}
