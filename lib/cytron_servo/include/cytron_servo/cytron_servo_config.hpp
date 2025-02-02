#ifndef CYTRON_SERVO__CYTRON_SERVO_CONFIG_HPP_
#define CYTRON_SERVO__CYTRON_SERVO_CONFIG_HPP_

#include <cytron_motor_driver_lib/motor_config.hpp>
#include <simple_pid_lib/pid_config.hpp>

namespace cytron_servo
{
struct CytronServoConfig
{
  CytronServoConfig(
    int potentiometer_pin, cytron_motor_driver_lib::MotorConfig cytron_motor_config,
    simple_pid_lib::PIDConfig pid_config)
  : potentiometer_pin(potentiometer_pin),
    cytron_motor_config(cytron_motor_config),
    pid_config(pid_config)
  {
  }

  int potentiometer_pin;
  cytron_motor_driver_lib::MotorConfig cytron_motor_config;
  simple_pid_lib::PIDConfig pid_config;
};
}  // namespace cytron_servo

#endif  // CYTRON_SERVO__CYTRON_SERVO_CONFIG_HPP_
