#ifndef OMNI_4W__OMNI_4W_HPP_
#define OMNI_4W__OMNI_4W_HPP_

#include "omni_4w_config.hpp"

#include <cytron_motor_driver_lib/motor.hpp>

namespace omni_4w
{
class Omni4W
{
  using Motor = cytron_motor_driver_lib::Motor;

public:
  Omni4W(Omni4WConfig config);
  void drive(const double longitudinal_power, const double lateral_power, double angular_power);
  void stop();

private:
  Omni4WConfig config_;

  Motor motor_fl_;
  Motor motor_fr_;
  Motor motor_bl_;
  Motor motor_br_;
};  // class Omni4W
}  // namespace omni_4w

#endif  // OMNI_4W__OMNI_4W_HPP_
