/**
 * @file /qtalker/talker.hpp
 *
 * @brief Ros communication central!
 *
 * @date August 2017
 **/


#ifndef TALKER_NODE_HPP_
#define TALKER_NODE_HPP_


#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include "../include/qtros/qnode.hpp"
#endif
#include <sstream>
#include <std_msgs/String.h>
#include <string>
#include <sensor_msgs/JointState.h>

namespace qtros {
class Talker : public QNode{
    //Q_OBJECT
public:
    Talker(int argc, char** argv):
        QNode(argc, argv,"qtros"){}
    virtual ~Talker() {}
    void run(){
        ros::NodeHandle n;
        ros::Publisher robotMsg=n.advertise<sensor_msgs::JointState>("ddrobotJointState",1000);

        sensor_msgs::JointState jointstate;
        jointstate.name.resize(2);
        jointstate.position.resize(2);
        jointstate.name[0]="joint_right_wheel";
        jointstate.name[1]="joint_left_wheel";

        ros::Rate loop_rate(10);

        while ( ros::ok() ) {
            jointstate.header.stamp=ros::Time::now();
            jointstate.position[0]=right_angle;
            jointstate.position[1]=left_angle;
            robotMsg.publish(jointstate);

            std_msgs::String msg;
            std::stringstream ss;
            ss << "right angle " <<right_angle<<" left angle: "<<left_angle;
            msg.data = ss.str();
            ROS_INFO("%s", msg.data.c_str());

            chatter_publisher.publish(msg);
            ros::spinOnce();
            loop_rate.sleep();
        }

    }

    void ros_comms_init(){
        ros::NodeHandle n;
        chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    }

private:
    ros::Publisher chatter_publisher;
};
}

#endif /* TALKER_NODE_HPP_ */
