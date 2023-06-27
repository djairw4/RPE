cmake_minimum_required(VERSION 3.0.2)
project(sine)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

# Generate messages in the 'msg' folder
add_message_files(
  FILES
  Sin.msg
)

# Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)


catkin_package(
 CATKIN_DEPENDS message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(sin src/sin.cpp)
target_link_libraries(sin ${catkin_LIBRARIES})
add_dependencies(sin sine_generate_messages_cpp)