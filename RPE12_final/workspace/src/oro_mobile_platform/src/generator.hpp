#ifndef OROCOS_GENERATOR_HPP
#define OROCOS_GENERATOR_HPP

#include <rtt/RTT.hpp>
#include <std_msgs/Float64.h>

class Generator : public RTT::TaskContext{
  public:
    Generator(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
  private:
    RTT::OutputPort<std_msgs::Float64> _outPort;
    double _step_sec;
    double _time;
};
#endif
