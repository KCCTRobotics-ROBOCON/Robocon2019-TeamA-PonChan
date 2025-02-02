#ifndef MODULE__MODULE_CONFIG_HPP_
#define MODULE__MODULE_CONFIG_HPP_

#include "center_arm/center_arm_config.hpp"
#include "chassis/chassis_config.hpp"
#include "side_arm/side_arm_config.hpp"
#include "t_shirt_holder/t_shirt_holder_config.hpp"

namespace module
{
struct ModuleConfig
{
  ModuleConfig(
    center_arm::CenterArmConfig center_arm_config, chassis::ChassisConfig chassis_config,
    side_arm::SideArmConfig left_side_arm_config, side_arm::SideArmConfig right_side_arm_config,
    t_shirt_holder::TShirtHolderConfig t_shirt_holder_config)
  : center_arm_config(center_arm_config),
    chassis_config(chassis_config),
    left_side_arm_config(left_side_arm_config),
    right_side_arm_config(right_side_arm_config),
    t_shirt_holder_config(t_shirt_holder_config)
  {
  }
  center_arm::CenterArmConfig center_arm_config;
  chassis::ChassisConfig chassis_config;
  side_arm::SideArmConfig left_side_arm_config;
  side_arm::SideArmConfig right_side_arm_config;
  t_shirt_holder::TShirtHolderConfig t_shirt_holder_config;
};
}  // namespace module

#endif  // MODULE__MODULE_CONFIG_HPP_
