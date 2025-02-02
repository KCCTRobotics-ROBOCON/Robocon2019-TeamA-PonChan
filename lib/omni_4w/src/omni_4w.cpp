#include "omni_4w/omni_4w.hpp"

#include <algorithm>
#include <cmath>

namespace omni_4w
{
Omni4W::Omni4W(Omni4WConfig config)
: config_(config),
  motor_fl_(config.motor_fl_config),
  motor_fr_(config.motor_fr_config),
  motor_bl_(config.motor_bl_config),
  motor_br_(config.motor_br_config)
{
  {
    double max_linear_power = config_.max_linear_power;
    max_linear_power = std::clamp<double>(max_linear_power, -1.0, 1.0);
    config_.max_linear_power = max_linear_power;
  }
  {
    double max_angular_power = config_.max_angular_power;
    max_angular_power = std::clamp<double>(max_angular_power, -1.0, 1.0);
    config_.max_angular_power = max_angular_power;
  }
}

void Omni4W::drive(double linear_power, const double direction_angle_rad, double angular_power)
{
  linear_power = std::clamp(linear_power, -config_.max_linear_power, config_.max_linear_power);
  angular_power = std::clamp(angular_power, -config_.max_angular_power, config_.max_angular_power);
  double max_linear_power =
    (1.0 - std::abs(angular_power)) /
    (std::abs(std::cos(direction_angle_rad)) + std::abs(std::sin(direction_angle_rad)));
  double longitudinal_power = max_linear_power * linear_power * std::cos(direction_angle_rad);
  double lateral_power = max_linear_power * linear_power * std::sin(direction_angle_rad);

  motor_fl_.drive(-longitudinal_power + lateral_power + angular_power);
  motor_bl_.drive(-longitudinal_power - lateral_power + angular_power);
  motor_br_.drive(+longitudinal_power - lateral_power + angular_power);
  motor_fr_.drive(+longitudinal_power + lateral_power + angular_power);
}

void Omni4W::stop()
{
  motor_fl_.stop();
  motor_fr_.stop();
  motor_bl_.stop();
  motor_br_.stop();
}
}  // namespace omni_4w
