#ifndef MODULE__T_SHIRT_HOLDER__T_SHIRT_HOLDER_HPP_
#define MODULE__T_SHIRT_HOLDER__T_SHIRT_HOLDER_HPP_

#include "controller/controller_interface.hpp"
#include "t_shirt_holder_config.hpp"

namespace module::t_shirt_holder
{
class TShirtHolder
{
public:
  TShirtHolder(TShirtHolderConfig config);
  void init(controller::ControllerInterface * controller) { input_ = controller; }
  void update();

private:
  TShirtHolderConfig config_;
  controller::ControllerInterface * input_;
};  // class TShirtHolder
}  // namespace module::t_shirt_holder

#endif  // MODULE__T_SHIRT_HOLDER__T_SHIRT_HOLDER_HPP_
