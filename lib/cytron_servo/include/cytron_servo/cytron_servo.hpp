#ifndef CYTRON_SERVO__CYTRON_SERVO_HPP_
#define CYTRON_SERVO__CYTRON_SERVO_HPP_

#include "cytron_servo/cytron_servo_config.hpp"

#include <cytron_motor_driver_lib/motor.hpp>
#include <simple_pid_lib/pid.hpp>

namespace cytron_servo
{
class CytronServo
{
public:
  CytronServo(CytronServoConfig config);
  void update();
  void stop();
  void restart();
  void set_target_value(int target_value);
  int get_current_value();

private:
  CytronServoConfig config_;

  cytron_motor_driver_lib::Motor motor_;
  simple_pid_lib::PID pid_;

  bool is_stopped_;

  int target_value_;
  int current_value_;
};  // class CytronServo
}  // namespace cytron_servo

#endif  // CYTRON_SERVO__CYTRON_SERVO_HPP_
