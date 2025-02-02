#ifndef OMNI_4W__OMNI_4W_CONFIG_HPP_
#define OMNI_4W__OMNI_4W_CONFIG_HPP_

#include <cytron_motor_driver_lib/motor_config.hpp>

namespace omni_4w
{
struct Omni4WConfig
{
  Omni4WConfig(
    cytron_motor_driver_lib::MotorConfig motor_fl_config,
    cytron_motor_driver_lib::MotorConfig motor_fr_config,
    cytron_motor_driver_lib::MotorConfig motor_bl_config,
    cytron_motor_driver_lib::MotorConfig motor_br_config, double max_linear_power,
    double max_angular_power)
  : motor_fl_config(motor_fl_config),
    motor_fr_config(motor_fr_config),
    motor_bl_config(motor_bl_config),
    motor_br_config(motor_br_config),
    max_linear_power(max_linear_power),
    max_angular_power(max_angular_power)
  {
  }

  cytron_motor_driver_lib::MotorConfig motor_fl_config;
  cytron_motor_driver_lib::MotorConfig motor_fr_config;
  cytron_motor_driver_lib::MotorConfig motor_bl_config;
  cytron_motor_driver_lib::MotorConfig motor_br_config;
  double max_linear_power;
  double max_angular_power;
};
}  // namespace omni_4w

#endif  // OMNI_4W__OMNI_4W_CONFIG_HPP_
