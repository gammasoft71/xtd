/// @file
/// @brief Contains xtd::background_color class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "basic_console.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent background color output manipulator class.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see xtd::basic_console<char_t>::background_color(console_color color) method.
  class background_color final : public object {
  public:
    explicit background_color(console_color color) : color(color) {}
    
    /// @cond
    template<typename char_t>
    friend std::basic_ostream<char_t>& operator <<(std::basic_ostream<char_t>& os, const background_color& color) {
      if (os.rdbuf() == __get_out_rdbuf<char_t>() || os.rdbuf() == __get_err_rdbuf<char_t>())
        basic_console<char_t>::background_color(color.color);
      return os;
    }
    /// @endcond

  private:
    console_color color ;
  };
}
