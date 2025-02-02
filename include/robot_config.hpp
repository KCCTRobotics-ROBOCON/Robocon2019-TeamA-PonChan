#ifndef ROBOT_CONFIG_HPP_
#define ROBOT_CONFIG_HPP_

#include "module/module_config.hpp"

struct RobotConfig
{
  RobotConfig(module::ModuleConfig module_config) : module_config(module_config) {}
  module::ModuleConfig module_config;
};

#endif  // ROBOT_CONFIG_HPP_
