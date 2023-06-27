#ifndef OROCOS_DATA_LOGGER_HPP
#define OROCOS_DATA_LOGGER_HPP

#include <rtt/RTT.hpp>
#include <std_msgs/Float64.h>

class Data_logger : public RTT::TaskContext{
  public:
    Data_logger(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::InputPort<std_msgs::Float64> _x;
    RTT::InputPort<std_msgs::Float64> _y;
    std_msgs::Float64 _x_mem;
    std_msgs::Float64 _y_mem;
    bool _new_x;
    bool _new_y;
};
#endif