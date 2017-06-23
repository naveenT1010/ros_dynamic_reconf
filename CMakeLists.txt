cmake_minimum_required(VERSION 2.8.3)
project(ros_dynamic_reconf)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  dynamic_reconfigure
)

generate_dynamic_reconfigure_options(
   cfg/config_file.cfg
)


catkin_package(

)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(config_ex_node src/config_ex_node.cpp)
add_dependencies(config_ex_node ${PROJECT_NAME}_gencfg)
target_link_libraries(config_ex_node ${catkin_LIBRARIES})
