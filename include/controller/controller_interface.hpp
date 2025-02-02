#ifndef CONTROLLER__CONTROLLER_INTERFACE_HPP_
#define CONTROLLER__CONTROLLER_INTERFACE_HPP_

#include <PS3BT.h>

namespace controller
{
class ControllerInterface
{
public:
  virtual bool is_connected() = 0;
  virtual uint8_t get_analog_hat(AnalogHatEnum hat) = 0;
  virtual uint8_t get_analog_button(ButtonEnum button) = 0;
  virtual bool get_button_click(ButtonEnum button) = 0;
  virtual bool get_button_press(ButtonEnum button) = 0;
};
}  // namespace controller

#endif  // CONTROLLER__CONTROLLER_INTERFACE_HPP_
