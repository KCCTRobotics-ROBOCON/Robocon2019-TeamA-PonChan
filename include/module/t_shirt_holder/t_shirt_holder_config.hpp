#ifndef MODULE__T_SHIRT_HOLDER__T_SHIRT_HOLDER_CONFIG_HPP_
#define MODULE__T_SHIRT_HOLDER__T_SHIRT_HOLDER_CONFIG_HPP_

#include <controllerEnums.h>

namespace module::t_shirt_holder
{
struct TShirtHolderConfig
{
  TShirtHolderConfig(int solenoid_pin, ButtonEnum extend_button, ButtonEnum retract_button)
  : solenoid_pin(solenoid_pin), extend_button(extend_button), retract_button(retract_button)
  {
  }

  int solenoid_pin;

  ButtonEnum extend_button;
  ButtonEnum retract_button;
};
}  // namespace module::t_shirt_holder

#endif  // MODULE__T_SHIRT_HOLDER__T_SHIRT_HOLDER_CONFIG_HPP_
