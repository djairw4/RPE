cmake_minimum_required(VERSION 3.0.2)
project(cosine)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

# Generate messages in the 'msg' folder
add_message_files(
  FILES
  Cos.msg
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

add_executable(cos src/cos.cpp)
target_link_libraries(cos ${catkin_LIBRARIES})
add_dependencies(cos cosine_generate_messages_cpp)