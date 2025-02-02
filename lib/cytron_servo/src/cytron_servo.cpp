#include "cytron_servo/cytron_servo.hpp"

#include <Arduino.h>

namespace cytron_servo
{
CytronServo::CytronServo(CytronServoConfig config)
: config_(config), motor_(config.cytron_motor_config), pid_(config.pid_config), is_stopped_(true)
{
  motor_.stop();
  pid_.reset_integral();
}

void CytronServo::update()
{
  if (is_stopped_) {
    pid_.reset_integral();
    motor_.stop();
    return;
  }
  current_value_ = analogRead(config_.potentiometer_pin);
  int error = target_value_ - current_value_;
  pid_.update(error);
  motor_.drive(pid_.get_output());
}

void CytronServo::stop()
{
  pid_.reset_integral();
  motor_.stop();
  is_stopped_ = true;
}

void CytronServo::restart()
{
  is_stopped_ = false;
}

void CytronServo::set_target_value(int target_value)
{
  target_value_ = target_value;
  pid_.reset_integral();
}

int CytronServo::get_current_value()
{
  return current_value_;
}

}  // namespace cytron_servo