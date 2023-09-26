#include "../../../include/xtd/forms/power_status"

using namespace xtd;
using namespace xtd::forms;

xtd::forms::battery_charge_status power_status::battery_charge_status() const noexcept {
  return battery_charge_status_;
}

int32 power_status::battery_full_life_time() const noexcept {
  return battery_full_life_time_;
}

float power_status::battery_life_percent() const noexcept {
  return battery_life_percent_;
}

int32 power_status::battery_life_remaining() const noexcept {
  return battery_life_remaining_;
}

xtd::forms::power_line_status power_status::power_line_status() const noexcept {
  return power_line_status_;
}

power_status::power_status(xtd::forms::battery_charge_status battery_charge_status, int32 battery_full_life_time, float battery_life_percent, int32 battery_life_remaining, xtd::forms::power_line_status power_line_status) : battery_charge_status_(battery_charge_status), battery_full_life_time_(battery_full_life_time), battery_life_percent_(battery_life_percent), battery_life_remaining_(battery_life_remaining), power_line_status_(power_line_status) {
}
