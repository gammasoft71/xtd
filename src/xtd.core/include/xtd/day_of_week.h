/// @file
/// @brief Contains xtd::day_of_week enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  enum class day_of_week {
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday
  };

  inline std::ostream& operator<<(std::ostream& os, const day_of_week value) {return os << to_string(value, { {day_of_week::sunday, "sunday,"}, {day_of_week::monday, "monday,"}, {day_of_week::tuesday, "tuesday,"}, {day_of_week::wednesday, "wednesday,"}, {day_of_week::thursday, "thursday,"}, {day_of_week::friday, "friday,"}, {day_of_week::saturday, "saturday"}});}
  inline std::wostream& operator<<(std::wostream& os, const day_of_week value) {return os << to_string(value, { {day_of_week::sunday, L"sunday,"}, {day_of_week::monday, L"monday,"}, {day_of_week::tuesday, L"tuesday,"}, {day_of_week::wednesday, L"wednesday,"}, {day_of_week::thursday, L"thursday,"}, {day_of_week::friday, L"friday,"}, {day_of_week::saturday, L"saturday"}});}
}
