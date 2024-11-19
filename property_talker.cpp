#include "ros/ros.h"
#include "homework/my_property.h"

int main(int argc,char * argv[]){
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"property_talker");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<homework::my_property>("property",1000);

    homework::my_property p;
    p.name = "Student";
    p.Class = 2023;

    ros::Rate r(1);
    while(ros::ok()){
        pub.publish(p);
        ROS_INFO("Published:name=%s,class=%d",p.name.c_str(),p.Class);
        r.sleep();
        ros::spinOnce();
    }

    return 0;
}