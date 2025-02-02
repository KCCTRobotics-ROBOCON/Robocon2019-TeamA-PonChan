#ifndef MODULE__CHASSIS__CHASSIS_CONFIG_HPP_
#define MODULE__CHASSIS__CHASSIS_CONFIG_HPP_

#include <omni_4w/omni_4w_config.hpp>

// clang-format off
#include <cstdint>
// clang-format on

#include <controllerEnums.h>

namespace module::chassis
{
struct ChassisConfig
{
  ChassisConfig(
    omni_4w::Omni4WConfig omni_config, AnalogHatEnum longitudinal_axis, AnalogHatEnum lateral_axis,
    AnalogHatEnum angular_axis)
  : omni_config(omni_config),
    longitudinal_axis(longitudinal_axis),
    lateral_axis(lateral_axis),
    angular_axis(angular_axis)
  {
  }

  omni_4w::Omni4WConfig omni_config;

  AnalogHatEnum longitudinal_axis;
  AnalogHatEnum lateral_axis;
  AnalogHatEnum angular_axis;
};
}  // namespace module::chassis

#endif  // CHASSIS__CHASSIS_CONFIG_HPP_