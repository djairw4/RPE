#include "ros/ros.h"
#include "std_msgs/Float64.h"

static bool new_cosphi=false;
static bool new_sinphi=false;
static bool new_u1_x=false;
static bool new_u1_y=false;

class Product{
  ros::NodeHandle n; 
  ros::Publisher pub_xdot;
  ros::Publisher pub_ydot;
  ros::Subscriber sub_cosphi;
  ros::Subscriber sub_sinphi;
  ros::Subscriber sub_u1;
  double cosphi;
  double sinphi;
  double u1;

public:
  Product()
  {
    pub_xdot = n.advertise<std_msgs::Float64>("xdot", 1000);
    pub_ydot = n.advertise<std_msgs::Float64>("ydot", 1000);
    sub_cosphi = n.subscribe("cos_phi", 1000, &Product::cosphiCallback,this);
    sub_sinphi = n.subscribe("sin_phi", 1000, &Product::sinphiCallback,this);
    sub_u1 = n.subscribe("g2sint", 1000, &Product::u1Callback,this);
  }
  void u1Callback(const std_msgs::Float64 & msg){
    u1=msg.data;
    new_u1_x=true;
    new_u1_y=true;
    // ROS_INFO("u1: [%d]", new_u1_x);

  }
  void cosphiCallback(const std_msgs::Float64 & msg){
    cosphi=msg.data;
    new_cosphi=true;
    // ROS_INFO("cosphi: [%d]", new_cosphi);
  }
  void sinphiCallback(const std_msgs::Float64 & msg){
    sinphi=msg.data;
    new_sinphi=true;
    // ROS_INFO("sinphi: [%d]", new_sinphi);
  }
  void publish_xdot(){
    std_msgs::Float64 xdot;
    xdot.data=u1*cosphi;
    pub_xdot.publish(xdot);
    ROS_INFO("u1: [%f], cosphi: [%f], xdot: [%f]", u1, cosphi,xdot.data);    
  }
  void publish_ydot(){
    std_msgs::Float64 ydot;
    ydot.data=u1*sinphi;
    pub_ydot.publish(ydot);
    ROS_INFO("u1: [%f], sinphi: [%f], ydot: [%f]", u1, sinphi,ydot.data);    
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "product");
  Product p;
  while (ros::ok())
  { 
    if(new_cosphi && new_u1_x){
        // ROS_INFO("xdot");
        p.publish_xdot();
        new_cosphi=false;
        new_u1_x=false;
    }
    if(new_sinphi && new_u1_y){
        // ROS_INFO("ydot");
        p.publish_ydot();
        new_sinphi=false;
        new_u1_y=false;
    }
    ros::spinOnce();
  }
  return 0;
}