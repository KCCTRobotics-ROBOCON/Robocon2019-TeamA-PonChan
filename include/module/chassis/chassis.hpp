#ifndef MODULE__CHASSIS__CHASSIS_HPP_
#define MODULE__CHASSIS__CHASSIS_HPP_

#include "chassis_config.hpp"
#include "controller/controller_interface.hpp"

#include <omni_4w/omni_4w.hpp>

namespace module::chassis
{
class Chassis
{
  using Omni = omni_4w::Omni4W;

public:
  Chassis(ChassisConfig config);
  void init(controller::ControllerInterface * controller);
  void update();

private:
  ChassisConfig config_;
  controller::ControllerInterface * input_;
  Omni omni_;
};  // class Chassis
}  // namespace module::chassis

#endif  // CHASSIS__CHASSIS_HPP_
