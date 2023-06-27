#include "data_logger.hpp"
#include <rtt/Component.hpp>
#include <iostream>
#include <fstream>

Data_logger::Data_logger(std::string const& name) : TaskContext(name), _new_x(false), _new_y(false){
  std::cout << "Data_logger constructed !" <<std::endl;
  ports()->addEventPort("x", _x).doc("Coordinate x");
  ports()->addPort("y", _y).doc("Coordinate y");
  std::ofstream file;
  file.open ("data.dat");
  file<<"";
  file.close();
}

bool Data_logger::configureHook(){
  std::cout << "Data_logger configured !" <<std::endl;
  return true;
}

bool Data_logger::startHook(){
  std::cout << "Data_logger started !" <<std::endl;
  return true;
}

void Data_logger::updateHook(){
  std::cout << "Data_logger executes updateHook !" <<std::endl;
  if(_x.read(_x_mem) == RTT::NewData){_new_x = true;};
  if(_y.read(_y_mem) == RTT::NewData){_new_y = true;};
  if(_new_x && _new_y){
    std::ofstream file;
    file.open ("data.dat",std::ios_base::app);
    std::cout<<"x"<<_x_mem.data<<" "<<"y"<<_y_mem.data<<std::endl;
    file<<_x_mem.data<<" "<<_y_mem.data<<std::endl;
    file.close();
    _new_x = false;
    _new_y = false;
  }
  
}

void Data_logger::stopHook() {
  std::cout << "Data_logger executes stopping !" <<std::endl;
}

void Data_logger::cleanupHook() {
  std::cout << "Data_logger cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(ToFile)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(Data_logger)
