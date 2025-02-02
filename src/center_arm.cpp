#include "module/center_arm/center_arm.hpp"

#include <Arduino.h>

namespace module::center_arm
{
CenterArm::CenterArm(CenterArmConfig config) : config_(config)
{
  pinMode(config.raise_lower_solenoid_pin, OUTPUT);
  pinMode(config.extend_retract_solenoid_pin, OUTPUT);
}

void CenterArm::init(controller::ControllerInterface * controller)
{
  input_ = controller;
}

void CenterArm::update()
{
  if (input_ == nullptr || !input_->is_connected()) return;

  if (input_->get_button_click(config_.raise_button)) {
    digitalWrite(config_.raise_lower_solenoid_pin, HIGH);
  } else if (input_->get_button_click(config_.lower_button)) {
    digitalWrite(config_.raise_lower_solenoid_pin, LOW);
  }

  if (input_->get_button_click(config_.extend_button)) {
    digitalWrite(config_.extend_retract_solenoid_pin, HIGH);
  } else if (input_->get_button_click(config_.retract_button)) {
    digitalWrite(config_.extend_retract_solenoid_pin, LOW);
  }
}
}  // namespace module::center_arm
