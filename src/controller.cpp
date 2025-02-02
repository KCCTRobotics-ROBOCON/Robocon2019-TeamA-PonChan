#include "controller/controller.hpp"

namespace controller
{
Controller::Controller() : usb_(), btd_(&usb_), ps3bt_(&btd_)
{
}

void Controller::init()
{
  if (usb_.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1);
  }
}

void Controller::update()
{
  usb_.Task();
  if (ps3bt_.getButtonClick(PS)) {
    ps3bt_.disconnect();
  }
}

bool Controller::is_connected()
{
  return ps3bt_.PS3Connected;
}

uint8_t Controller::get_analog_hat(AnalogHatEnum hat)
{
  if (!ps3bt_.PS3Connected) return 127;
  return ps3bt_.getAnalogHat(hat);
}

uint8_t Controller::get_analog_button(ButtonEnum button)
{
  if (!ps3bt_.PS3Connected) return 0;
  return ps3bt_.getAnalogButton(button);
}

bool Controller::get_button_click(ButtonEnum button)
{
  if (!ps3bt_.PS3Connected) return false;
  return ps3bt_.getButtonClick(button);
}

bool Controller::get_button_press(ButtonEnum button)
{
  if (!ps3bt_.PS3Connected) return false;
  return ps3bt_.getButtonPress(button);
}

}  // namespace controller