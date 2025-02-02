#ifndef ROBOT_HPP_
#define ROBOT_HPP_
#include "controller/controller.hpp"
#include "module/center_arm/center_arm.hpp"
#include "module/chassis/chassis.hpp"
#include "module/side_arm/side_arm.hpp"
#include "module/t_shirt_holder/t_shirt_holder.hpp"
#include "robot_config.hpp"

class Robot
{
public:
  Robot(RobotConfig config);
  void init();
  void update();

private:
  // Controller
  controller::Controller controller_;
  // Modules
  module::center_arm::CenterArm center_arm_;
  module::chassis::Chassis chassis_;
  module::side_arm::SideArm left_side_arm_;
  module::side_arm::SideArm right_side_arm_;
  module::t_shirt_holder::TShirtHolder t_shirt_holder_;
};  // class Robot

#endif
