#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc,char * argv[]){

    setlocale(LC_ALL,"");
    ros::init(argc,argv,"talker");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("hello_ros_topic",10);
    std_msgs::String msg;

    std::string msg_front = "Hello,ROS!";
    int count=0;

    ros::Rate r(10);

    while(ros::ok()){

        std::stringstream ss;
        ss<<msg_front<<count;
        msg.data = ss.str();

        pub.publish(msg);

        ROS_INFO("Sent message:%s",msg.data.c_str());

        r.sleep();
        count++;
        ros::spinOnce();
    }



    return 0;
}