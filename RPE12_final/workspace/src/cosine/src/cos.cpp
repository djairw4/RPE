#include "ros/ros.h"
#include "std_msgs/Float64.h"

class Cosine{
  ros::NodeHandle n; 
  ros::Publisher cosphi_pub;
  ros::Subscriber sub_phi_c;
public:
  Cosine()
  {
    cosphi_pub = n.advertise<std_msgs::Float64>("cos_phi", 1000);
    sub_phi_c = n.subscribe("phi", 1000, &Cosine::phiCallback,this);
  }

  void phiCallback(const std_msgs::Float64 & msg){
    std_msgs::Float64 cosphi;
    cosphi.data=cos(msg.data);
    cosphi_pub.publish(cosphi);
    ROS_INFO("cos(phi): [%f]", cosphi.data);
  }
};


int main(int argc, char **argv)
{
  ros::init(argc, argv, "cosine");
  Cosine cos;
  ros::spin();
  return 0;
}