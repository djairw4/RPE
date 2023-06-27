#include "ros/ros.h"
#include "std_msgs/Float64.h"

class Gain{
  ros::NodeHandle n; 
  ros::Publisher _2sint_pub;
  ros::Publisher _05t_pub;
  ros::Subscriber sub_time;
  ros::Subscriber sub_sint;
public:
  Gain()
  {
    _05t_pub = n.advertise<std_msgs::Float64>("g05t", 1000);
    _2sint_pub = n.advertise<std_msgs::Float64>("g2sint", 1000);
    sub_time = n.subscribe("time", 1000, &Gain::timeCallback,this);
    sub_sint = n.subscribe("sin_t", 1000, &Gain::sintCallback,this);
  }
  void timeCallback(const std_msgs::Float64 & msg){
    std_msgs::Float64 _05t;
    _05t.data=0.5*msg.data;
    _05t_pub.publish(_05t);
    ROS_INFO("0.5t: [%f]", _05t.data);
  }
  void sintCallback(const std_msgs::Float64 & msg){
    std_msgs::Float64 _2sint;
    _2sint.data=2*msg.data;
    _2sint_pub.publish(_2sint);
    ROS_INFO("2sin(t): [%f]", _2sint.data);
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "gain");
  Gain g;
  ros::spin();

  return 0;
}