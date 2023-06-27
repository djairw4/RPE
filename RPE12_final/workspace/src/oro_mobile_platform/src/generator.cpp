
#include "generator.hpp"
#include <rtt/Component.hpp>
#include <iostream>

Generator::Generator(std::string const& name) : TaskContext(name,PreOperational), _step_sec(0.01), _time(0){
  std::cout << "Generator constructed !" <<std::endl;
  addAttribute("time", _time);
  // Add output ports
  ports()->addPort("out", _outPort).doc("Output port");
}

bool Generator::configureHook(){
  std::cout << "Generator configured !" <<std::endl;
  //if(setActivity(new RTT::Activity(ORO_SCHED_RT,1,3,1,0,getName())) == false){
  
  if(setActivity(new RTT::Activity(ORO_SCHED_RT,1,_step_sec,1,0,getName())) == false){
    std::cout << "Unable to set activity!" << std::endl;
    return false;
  }
  return true;
}

bool Generator::startHook(){
  std::cout << "Generator started !" <<std::endl;
  return true;
}

void Generator::updateHook(){
  std::cout << "Generator executes updateHook !" <<std::endl;
  //double msg =rand()%5;
  //_outPort.write(msg);
  // if(_time<10){
    std_msgs::Float64 msg;
    _time += _step_sec;
    msg.data = _time;
    _outPort.write(msg);
  // }
  // else{setActivity(new RTT::Activity(ORO_SCHED_RT,1,0,1,0,getName()));}
}

void Generator::stopHook() {
  std::cout << "Generator executes stopping !" <<std::endl;
}

void Generator::cleanupHook() {
  std::cout << "Generator cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Generator)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Generator)