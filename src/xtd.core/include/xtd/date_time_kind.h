/// @file
/// @brief Contains xtd::date_time_kind enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  enum class date_time_kind {
    unspecified,
    utc,
    local,
  };

  inline std::ostream& operator<<(std::ostream& os, const date_time_kind value) {return os << to_string(value, { {date_time_kind::unspecified, "unspecified,"}, {date_time_kind::utc, "utc,"}, {date_time_kind::local, "local,"}});}
  inline std::wostream& operator<<(std::wostream& os, const date_time_kind value) {return os << to_string(value, { {date_time_kind::unspecified, L"unspecified,"}, {date_time_kind::utc, L"utc,"}, {date_time_kind::local, L"local,"}});}
}
