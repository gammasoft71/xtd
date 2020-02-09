#pragma once
#include "emoticon.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class emoticons static_ {
    public:
      /// 00080-00FF Latin 1 Supplement
      
      /// @brief Gets a system-defined emoticon that has a string value of {0x000000A9, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon copyright_sign;
      /// @brief Gets a system-defined emoticon that has a string value of {0x000000AE, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon registered_sign;

      /// 2000-206F - General Punctuation
      
      /// @brief Gets a system-defined emoticon that has a string value of 0x0000200D. This field is constant.
      static const xtd::forms::emoticon zero_width_joiner;
      /// @brief Gets a system-defined emoticon that has a string value of {0x0000203C, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon double_exclamation_mark;
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002049, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon exclamation_question_mark;

      /// 2100-214F Letterlike Symbols
      
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002122, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon trade_mark_sign;
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002139, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon information_source;
      /// 2190-21FF Arrows
      
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002194, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon left_right_arrow;
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002195, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon up_down_arrow;
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002196, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon north_west_arrow;
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002197, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon north_east_arrow;
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002198, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon south_east_arrow;
      /// @brief Gets a system-defined emoticon that has a string value of {0x00002199, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon south_west_arrow;
      /// @brief Gets a system-defined emoticon that has a string value of {0x000021A9, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon leftwards_arrow_with_hook;
      /// @brief Gets a system-defined emoticon that has a string value of {0x000021AA, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon rightwards_arrow_with_hook;

      static const std::vector<xtd::forms::emoticon>& get_emoticons();
    };
  }
}
