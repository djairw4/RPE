#include "ros/ros.h"
#include "std_msgs/Float64.h"

class Integral{
  ros::NodeHandle n; 
  ros::Publisher pub_x;
  ros::Publisher pub_y;
  ros::Publisher pub_phi;
  ros::Subscriber sub_u2;
  ros::Subscriber sub_xdot;
  ros::Subscriber sub_ydot;
  std_msgs::Float64 x;
  std_msgs::Float64 y;
  std_msgs::Float64 phi;
  double dt;

public:
  Integral():dt(0.01)
  {
    pub_phi = n.advertise<std_msgs::Float64>("phi", 1000);
    pub_x = n.advertise<std_msgs::Float64>("x", 1000);
    pub_y = n.advertise<std_msgs::Float64>("y", 1000);
    sub_u2 = n.subscribe("g05t", 1000, &Integral::u2Callback,this);
    sub_xdot = n.subscribe("xdot", 1000, &Integral::xdotCallback,this);
    sub_ydot = n.subscribe("ydot", 1000, &Integral::ydotCallback,this);
  }
  void u2Callback(const std_msgs::Float64 & msg){
    phi.data+=msg.data*dt;
    pub_phi.publish(phi);
    ROS_INFO("phi: [%f]", phi.data);
  }
  void xdotCallback(const std_msgs::Float64 & msg){
    x.data+=msg.data*dt;
    pub_x.publish(x);
    ROS_INFO("x: [%f]", x.data);
  }
  void ydotCallback(const std_msgs::Float64 & msg){
    y.data+=msg.data*dt;
    pub_y.publish(y);
    ROS_INFO("y: [%f]", y.data);
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "integral");
  Integral i;
  ros::spin();

  return 0;
}