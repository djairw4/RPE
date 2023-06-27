#include "ros/ros.h"
#include "std_msgs/Float64.h"

class Sine{
  ros::NodeHandle n; 
  ros::Publisher sint_pub;
  ros::Publisher sinphi_pub;
  ros::Subscriber sub_time;
  ros::Subscriber sub_phi;
public:
  Sine()
  {
    sint_pub = n.advertise<std_msgs::Float64>("sin_t", 1000);
    sinphi_pub = n.advertise<std_msgs::Float64>("sin_phi", 1000);
    sub_time = n.subscribe("time", 1000, &Sine::timeCallback,this);
    sub_phi = n.subscribe("phi", 1000, &Sine::phiCallback,this);
  }

  void timeCallback(const std_msgs::Float64 & msg){
    std_msgs::Float64 sint;
    sint.data=sin(msg.data);
    sint_pub.publish(sint);
    ROS_INFO("sin(t): [%f]", sint.data);
  }
  void phiCallback(const std_msgs::Float64 & msg){
    std_msgs::Float64 sinphi;
    sinphi.data=sin(msg.data);
    sinphi_pub.publish(sinphi);
    ROS_INFO("sin(phi): [%f]", sinphi.data);
  }
};



int main(int argc, char **argv)
{
  ros::init(argc, argv, "sine");
  Sine sin;  
  ros::spin();

  return 0;
}