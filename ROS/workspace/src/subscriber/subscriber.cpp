#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <iomanip>

// The callback function
void poseMessageReceived(const turtlesim::Pose& msg) {
    ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "position=(" << msg.x << "," << msg.y <<")" <<" direction=" << msg.theta);
}

int main(int argc, char **argv) {
    // Initialize the ROS system and make a node
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;
    
    // Create subscriber object
    ros::Subscriber sub=nh.subscribe("turtle1/pose", 1000, &poseMessageReceived);
    
    // Let ROS take over
    ros::spin();
}
