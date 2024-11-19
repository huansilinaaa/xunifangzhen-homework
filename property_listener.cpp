#include "ros/ros.h"
#include "homework/my_property.h"

void doProperty(const homework::my_property::ConstPtr& p){
    ROS_INFO("Received message:%s,%d",p->name.c_str(),p->Class);
}

int main(int argc,char * argv[]){
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"property_listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<homework::my_property>("property",10,doProperty);
    ros::spin();
    return 0;
}