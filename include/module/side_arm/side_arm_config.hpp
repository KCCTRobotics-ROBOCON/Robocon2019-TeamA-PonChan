#ifndef MODULE__SIDE_ARM__SIDE_ARM_CONFIG_HPP_
#define MODULE__SIDE_ARM__SIDE_ARM_CONFIG_HPP_

#include <cytron_servo/cytron_servo_config.hpp>

// clang-format off
#include <cstdint>
// clang-format on

#include <controllerEnums.h>

namespace module::side_arm
{
struct SideArmConfig
{
  SideArmConfig(
    cytron_servo::CytronServoConfig cytron_servo_config, int hand_solenoid_pin,
    ButtonEnum arm_button, ButtonEnum hand_button, int extended_value, int retracted_value,
    int hand_open_min_value, int hand_open_max_value)
  : cytron_servo_config(cytron_servo_config),
    hand_solenoid_pin(hand_solenoid_pin),
    arm_button(arm_button),
    hand_button(hand_button),
    extended_value(extended_value),
    retracted_value(retracted_value),
    hand_open_min_value(hand_open_min_value),
    hand_open_max_value(hand_open_max_value)
  {
  }

  cytron_servo::CytronServoConfig cytron_servo_config;
  int hand_solenoid_pin;

  ButtonEnum arm_button;
  ButtonEnum hand_button;

  int extended_value;
  int retracted_value;
  int hand_open_min_value;
  int hand_open_max_value;
};
}  // namespace module::side_arm

#endif  // MODULE__SIDE_ARM__SIDE_ARM_CONFIG_HPP_
