#ifndef CONTROLLER__CONTROLLER_HPP_
#define CONTROLLER__CONTROLLER_HPP_

#include "controller_interface.hpp"

#include <PS3BT.h>

namespace controller
{
class Controller : public ControllerInterface
{
public:
  Controller();
  void init();
  void update();
  bool is_connected() override;
  uint8_t get_analog_hat(AnalogHatEnum hat) override;
  uint8_t get_analog_button(ButtonEnum button) override;
  bool get_button_click(ButtonEnum button) override;
  bool get_button_press(ButtonEnum button) override;

private:
  USB usb_;
  BTD btd_;
  PS3BT ps3bt_;
};  // class Controller

}  // namespace controller

#endif  // CONTROLLER__CONTROLLER_HPP_
