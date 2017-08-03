#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/qtros/qnode.hpp"

namespace qtros {


QNode::QNode(int argc, char** argv, const std::string &name ) :
    init_argc(argc),
    init_argv(argv),
    node_name(name)
{}



QNode::~QNode() {
    shutdown();
}

void QNode::shutdown(){
    if(ros::isStarted()) {
        ros::shutdown(); // explicitly needed since we use ros::start();
        ros::waitForShutdown();
    }
    wait();
}

bool QNode::init() {
    ros::init(init_argc,init_argv,"qtros");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros_comms_init();
    start();

    //Initial parameters from here
    right_angle=0;
    left_angle=0;

    return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
    std::map<std::string,std::string> remappings;
    remappings["__master"] = master_url;
    remappings["__hostname"] = host_url;
    ros::init(remappings,"qtros");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros_comms_init();
    start();
    return true;
}

void QNode::setRightAngle(float angle){
    right_angle=angle;
}

void QNode::setLeftAngle(float angle){
    left_angle=angle;
}

float QNode::getRightAngle(void){
    return right_angle;
}

float QNode::getLeftAngle(void){
    return left_angle;
}


}  // namespace qtros
