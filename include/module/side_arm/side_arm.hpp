#ifndef MODULE__SIDE_ARM__SIDE_ARM_HPP_
#define MODULE__SIDE_ARM__SIDE_ARM_HPP_

#include "controller/controller_interface.hpp"
#include "side_arm_config.hpp"

#include <cytron_servo/cytron_servo.hpp>

namespace module::side_arm
{
using CytronServo = cytron_servo::CytronServo;

class SideArm
{
public:
  SideArm(SideArmConfig config);
  void init(controller::ControllerInterface * controller) { input_ = controller; }
  void update();

private:
  void update_arm();
  void update_hand();

  SideArmConfig config_;
  controller::ControllerInterface * input_;
  CytronServo servo_;
};  // class SideArm
}  // namespace module::side_arm

#endif  // MODULE__SIDE_ARM__SIDE_ARM_HPP_
