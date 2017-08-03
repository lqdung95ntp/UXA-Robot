
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"
#include <sstream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "ddrobot");
  ros::NodeHandle n;
  ros::Publisher robotMsg = n.advertise<sensor_msgs::JointState>("ddrobotJointState", 1000);
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  sensor_msgs::JointState jointstate;

  jointstate.name.resize(2);
  jointstate.position.resize(2);
  jointstate.name[0]="joint_right_wheel";
  jointstate.name[1]="joint_left_wheel";
  ros::Rate loop_rate(50);

  int count = 0;
  while (ros::ok())
  {
    jointstate.header.stamp=ros::Time::now();
// ` (int i=0; i<360;i++){
    float angle=count*2.0*3.14/360.0;
    jointstate.position[0]=angle;
    jointstate.position[1]=angle;
    robotMsg.publish(jointstate);

    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}