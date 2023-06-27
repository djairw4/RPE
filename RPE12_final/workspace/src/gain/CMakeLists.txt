cmake_minimum_required(VERSION 3.0.2)
project(gain)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

# Generate messages in the 'msg' folder
add_message_files(
  FILES
  Gain.msg
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

add_executable(gain src/gain.cpp)
target_link_libraries(gain ${catkin_LIBRARIES})
add_dependencies(gain gain_generate_messages_cpp)
