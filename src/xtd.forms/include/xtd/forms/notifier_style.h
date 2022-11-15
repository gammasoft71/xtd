#pragma once
#include <xtd/enum.h>
//TODO: Documentation

namespace xtd {
  namespace forms {
    enum class notifier_style {
      standard = 0,
      system = 1,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::notifier_style> {
  void operator()(xtd::enum_collection<xtd::forms::notifier_style>& values) {values = {{xtd::forms::notifier_style::standard, "standard"}, {xtd::forms::notifier_style::system, "system"}};}
};
/// @endcond
