#include "robot.hpp"

Robot::Robot(RobotConfig config)
: center_arm_(config.module_config.center_arm_config),
  chassis_(config.module_config.chassis_config),
  left_side_arm_(config.module_config.left_side_arm_config),
  right_side_arm_(config.module_config.right_side_arm_config),
  t_shirt_holder_(config.module_config.t_shirt_holder_config)
{
}

void Robot::init()
{
  controller_.init();
  center_arm_.init(&controller_);
  chassis_.init(&controller_);
  left_side_arm_.init(&controller_);
  right_side_arm_.init(&controller_);
  t_shirt_holder_.init(&controller_);
}

void Robot::update()
{
  controller_.update();
  center_arm_.update();
  chassis_.update();
  left_side_arm_.update();
  right_side_arm_.update();
  t_shirt_holder_.update();
}
