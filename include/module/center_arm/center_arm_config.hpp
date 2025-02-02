#ifndef MODULE__CENTER_ARM__CENTER_ARM_CONFIG_HPP_
#define MODULE__CENTER_ARM__CENTER_ARM_CONFIG_HPP_

// clang-format off
#include <cstdint>
// clang-format on

#include <controllerEnums.h>

namespace module::center_arm
{
struct CenterArmConfig
{
  CenterArmConfig(
    int raise_lower_solenoid_pin, int extend_retract_solenoid_pin, ButtonEnum raise_button,
    ButtonEnum lower_button, ButtonEnum extend_button, ButtonEnum retract_button)
  : raise_lower_solenoid_pin(raise_lower_solenoid_pin),
    extend_retract_solenoid_pin(extend_retract_solenoid_pin),
    raise_button(raise_button),
    lower_button(lower_button),
    extend_button(extend_button),
    retract_button(retract_button)
  {
  }

  int raise_lower_solenoid_pin;
  int extend_retract_solenoid_pin;

  ButtonEnum raise_button;
  ButtonEnum lower_button;
  ButtonEnum extend_button;
  ButtonEnum retract_button;
};
}  // namespace module::center_arm

#endif  // MODULE__CENTER_ARM__CENTER_ARM_CONFIG_HPP_
