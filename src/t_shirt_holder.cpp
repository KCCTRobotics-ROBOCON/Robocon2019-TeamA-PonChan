#include "module/t_shirt_holder/t_shirt_holder.hpp"

#include <Arduino.h>

namespace module::t_shirt_holder
{

TShirtHolder::TShirtHolder(TShirtHolderConfig config) : config_(config)
{
  pinMode(config.solenoid_pin, OUTPUT);
}

void TShirtHolder::update()
{
  if (input_ == nullptr || !input_->is_connected()) return;
  if (input_->get_button_press(config_.extend_button)) {
    digitalWrite(config_.solenoid_pin, HIGH);
  } else if (input_->get_button_press(config_.retract_button)) {
    digitalWrite(config_.solenoid_pin, LOW);
  }
}

}  // namespace module::t_shirt_holder