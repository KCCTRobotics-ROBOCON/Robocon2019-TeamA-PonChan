#ifndef CONFIG__INPUT_CONFIG_HPP_
#define CONFIG__INPUT_CONFIG_HPP_

// clang-format off
#include <cstdint>
// clang-format on

#include <controllerEnums.h>

// Center Arm
#define CENTER_ARM_RAISE_BUTTON ButtonEnum::SQUARE
#define CENTER_ARM_LOWER_BUTTON ButtonEnum::CROSS
#define CENTER_ARM_EXTEND_BUTTON ButtonEnum::TRIANGLE
#define CENTER_ARM_RETRACT_BUTTON ButtonEnum::CIRCLE

// Chassis
#define CHASSIS_LONGITUDINAL_AXIS AnalogHatEnum::LeftHatY
#define CHASSIS_LATERAL_AXIS AnalogHatEnum::LeftHatX
#define CHASSIS_ANGULAR_AXIS AnalogHatEnum::RightHatX

// Left Side Arm
#define LEFT_SIDE_ARM_ARM_BUTTON ButtonEnum::L1
#define LEFT_SIDE_ARM_HAND_BUTTON ButtonEnum::L2

// Right Side Arm
#define RIGHT_SIDE_ARM_ARM_BUTTON ButtonEnum::R1
#define RIGHT_SIDE_ARM_HAND_BUTTON ButtonEnum::R2

// T-Shirt Holder
#define T_SHIRT_HOLDER_EXTEND_BUTTON ButtonEnum::UP
#define T_SHIRT_HOLDER_RETRACT_BUTTON ButtonEnum::DOWN

#endif
