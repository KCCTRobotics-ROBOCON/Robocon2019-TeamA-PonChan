#include "module/side_arm/side_arm.hpp"

#include <Arduino.h>

namespace module::side_arm
{
SideArm::SideArm(SideArmConfig config) : config_(config), servo_(config.cytron_servo_config)
{
  pinMode(config.hand_solenoid_pin, OUTPUT);
}

void SideArm::update()
{
  update_arm();
  update_hand();
}

void SideArm::update_arm()
{
  if (input_ == nullptr || !input_->is_connected()) {
    servo_.stop();
    return;
  }
  servo_.restart();

  if (input_->get_button_press(config_.arm_button)) {
    servo_.set_target_value(config_.extended_value);
  } else {
    servo_.set_target_value(config_.retracted_value);
  }
  servo_.update();
}

void SideArm::update_hand()
{
  if (input_ == nullptr || !input_->is_connected()) return;
  bool hand_state = input_->get_button_press(config_.hand_button);
  if (!hand_state && input_->get_button_press(config_.arm_button)) {
    int arm_value = servo_.get_current_value();
    if (config_.hand_open_min_value < arm_value && arm_value < config_.hand_open_max_value) {
      hand_state = true;
    }
  }
  digitalWrite(config_.hand_solenoid_pin, hand_state);
}

}  // namespace module::side_arm
