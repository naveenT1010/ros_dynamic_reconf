#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <ros_dynamic_reconf/config_fileConfig.h>

void callback(ros_dynamic_reconf::config_fileConfig &config, uint32_t level){
	ROS_INFO("The int param is %d and enum size is %d", config.int_param, config.enum_size);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "config_ex_node");

	dynamic_reconfigure::Server<ros_dynamic_reconf::config_fileConfig> server;
	dynamic_reconfigure::Server<ros_dynamic_reconf::config_fileConfig>::CallbackType cb;

	cb = boost::bind(&callback, _1, _2);
	server.setCallback(cb);

	ROS_INFO("Spin node");
	ros::spin();
	return 0;
}