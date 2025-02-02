#ifndef MODULE__CENTER_ARM__CENTER_ARM_HPP_
#define MODULE__CENTER_ARM__CENTER_ARM_HPP_

#include "center_arm_config.hpp"
#include "controller/controller_interface.hpp"

namespace module::center_arm
{
class CenterArm
{
public:
  CenterArm(CenterArmConfig config);
  void init(controller::ControllerInterface * controller);
  void update();

private:
  CenterArmConfig config_;
  controller::ControllerInterface * input_;
};
}  // namespace module::center_arm

#endif  // MODULE__CENTER_ARM__CENTER_ARM_HPP_
