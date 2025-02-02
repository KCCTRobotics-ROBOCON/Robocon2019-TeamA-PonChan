#include "module/chassis/chassis.hpp"

namespace module::chassis
{
Chassis::Chassis(ChassisConfig config) : config_(config), omni_(config.omni_config)
{
}

void Chassis::init(controller::ControllerInterface * controller)
{
  input_ = controller;
}

void Chassis::update()
{
  if (input_ == nullptr || !input_->is_connected()) {
    omni_.stop();
    return;
  }
  uint8_t longitudinal_input = input_->get_analog_hat(config_.longitudinal_axis);
  uint8_t lateral_input = input_->get_analog_hat(config_.lateral_axis);
  uint8_t angular_input = input_->get_analog_hat(config_.angular_axis);

  double linear_power = 0.0;
  double direction_angle_rad = 0.0;
  {
    double longitudinal_power = map(longitudinal_input, 0, 255, -1.0, 1.0);
    double lateral_power = map(lateral_input, 0, 255, -1.0, 1.0);
    linear_power =
      std::sqrt(longitudinal_power * longitudinal_power + lateral_power * lateral_power);
    direction_angle_rad = std::atan2(lateral_power, longitudinal_power);
  }
  double angular_power = map(
    angular_input, 0, 255, -config_.omni_config.max_angular_power,
    config_.omni_config.max_angular_power);

  omni_.drive(linear_power, direction_angle_rad, angular_power);
}
}  // namespace module::chassis
