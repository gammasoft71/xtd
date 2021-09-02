/// @file
/// @brief Contains xtd::forms::emoticons factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "emoticon.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Countries for all known emoticons. This class cannot be inherited.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @par Examples
    /// The following code example demonstrate the use of emoticons class.
    /// @include emoticons.cpp
    /// @par Windows
    /// @image html emoticons_w.png
    /// <br>
    /// @image html emoticons_wd.png
    /// @par macOS
    /// @image html emoticons_m.png
    /// <br>
    /// @image html emoticons_md.png
    /// @par Gnome
    /// @image html emoticons_g.png
    /// <br>
    /// @image html emoticons_gd.png
    class forms_export_ emoticons final static_ {
    public:
      // 00080-00FF Latin 1 Supplement
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000000A9, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon copyright_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000000AE, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon registered_sign;

      // 2000-206F - General Punctuation
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000200D. This field is constant.
      static const xtd::forms::emoticon zero_width_joiner;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000203C, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon double_exclamation_mark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002049, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon exclamation_question_mark;

      // 2100-214F Letterlike Symbols
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002122, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon trade_mark_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002139, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon information_source;
      
      // 2190-21FF Arrows
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002194, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon left_right_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002195, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon up_down_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002196, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon north_west_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002197, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon north_east_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002198, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon south_east_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002199, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon south_west_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000021A9, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon leftwards_arrow_with_hook;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000021AA, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon rightwards_arrow_with_hook;

      // 2300-23FF Miscellaneous Technical
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000231A. This field is constant.
      static const xtd::forms::emoticon watch;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000231B. This field is constant.
      static const xtd::forms::emoticon hourglass;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002328, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon keyboard;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000023CF, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon eject_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023E9. This field is constant.
      static const xtd::forms::emoticon black_right_pointing_double_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023EA. This field is constant.
      static const xtd::forms::emoticon black_left_pointing_double_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023EB. This field is constant.
      static const xtd::forms::emoticon black_up_pointing_double_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023EC. This field is constant.
      static const xtd::forms::emoticon black_down_pointing_double_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023ED. This field is constant.
      static const xtd::forms::emoticon black_right_pointing_double_triangle_with_vertical_bar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023EE. This field is constant.
      static const xtd::forms::emoticon black_left_pointing_double_triangle_with_vertical_bar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023EF. This field is constant.
      static const xtd::forms::emoticon black_right_pointing_triangle_with_double_vertical_bar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023F0. This field is constant.
      static const xtd::forms::emoticon alarm_clock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023F1. This field is constant.
      static const xtd::forms::emoticon stopwatch;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023F2. This field is constant.
      static const xtd::forms::emoticon timer_clock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023F3. This field is constant.
      static const xtd::forms::emoticon hourglass_with_flowing_sand;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023F8. This field is constant.
      static const xtd::forms::emoticon double_vertical_bar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023F9. This field is constant.
      static const xtd::forms::emoticon black_square_for_stop;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000023FA. This field is constant.
      static const xtd::forms::emoticon black_circle_for_record;
      
      // 2460-24FF Enclosed Alphanumerics
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000024C2, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon circled_latin_capital_letter_m;

      /// 25A0 25FF Geometric Shapes
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000025AA, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_small_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000025AB, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon white_small_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000025B6, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_right_pointing_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000025C0, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_left_pointing_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000025FB, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon white_medium_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000025FC, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_medium_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000025FD. This field is constant.
      static const xtd::forms::emoticon white_medium_small_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000025FE. This field is constant.
      static const xtd::forms::emoticon black_medium_small_square;

      // 2600-26FF Miscellaneous Symbols
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002600, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_sun_with_rays;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002601, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon cloud;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002602, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon umbrella;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002603, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon snowman;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002604, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon comet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000260E, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_telephone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002611, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon ballot_box_with_check;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002614. This field is constant.
      static const xtd::forms::emoticon umbrella_with_rain_drops;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002615, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon hot_beverage;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002618, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon shamrock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000261D, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon white_up_pointing_index;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002620, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon skull_and_crossbones;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002622, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon radioactive_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002623, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon biohazard_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002626, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon orthodox_cross;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000262A, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon star_and_crescent;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000262E, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon peace_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000262F, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon yin_yang;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002638, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon wheel_of_dharma;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002639, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon white_frowning_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000263A, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon white_smiling_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002640, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon female_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002642, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon male_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002648. This field is constant.
      static const xtd::forms::emoticon aries;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002649. This field is constant.
      static const xtd::forms::emoticon taurus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000264A. This field is constant.
      static const xtd::forms::emoticon gemini;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000264B. This field is constant.
      static const xtd::forms::emoticon cancer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000264C. This field is constant.
      static const xtd::forms::emoticon leo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000264D. This field is constant.
      static const xtd::forms::emoticon virgo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000264E. This field is constant.
      static const xtd::forms::emoticon libra;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000264F. This field is constant.
      static const xtd::forms::emoticon scorpius;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002650. This field is constant.
      static const xtd::forms::emoticon sagittarius;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002651. This field is constant.
      static const xtd::forms::emoticon capricorn;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002652. This field is constant.
      static const xtd::forms::emoticon aquarius;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002653. This field is constant.
      static const xtd::forms::emoticon pisces;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000265F. This field is constant.
      static const xtd::forms::emoticon black_chess_pawn;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002660, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_spade_suit;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002663, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_club_suit;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002665, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_heart_suit;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002666, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_diamond_suit;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002668, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon hot_springs;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000267B, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_universal_recycling_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000267E, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon permanent_paper_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000267F. This field is constant.
      static const xtd::forms::emoticon wheelchair_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002692, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon hammer_and_pick;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002693. This field is constant.
      static const xtd::forms::emoticon anchor;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002694, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon crossed_swords;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002695, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon staff_of_aesculapius;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002696, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon scales;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002697, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon alembic;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002699, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon gear;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000269B, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon atom_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000269C, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon fleur_de_lis;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000026A0, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon warning_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026A1. This field is constant.
      static const xtd::forms::emoticon high_voltage_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026AA. This field is constant.
      static const xtd::forms::emoticon medium_white_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000026AB. This field is constant.
      static const xtd::forms::emoticon medium_black_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026B0, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon coffin;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000026B1, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon funeral_urn;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026BD. This field is constant.
      static const xtd::forms::emoticon soccer_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026BE. This field is constant.
      static const xtd::forms::emoticon baseball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026C4. This field is constant.
      static const xtd::forms::emoticon snowman_without_snow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026C5. This field is constant.
      static const xtd::forms::emoticon sun_behind_cloud;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026C8. This field is constant.
      static const xtd::forms::emoticon thunder_cloud_and_rain;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026CE. This field is constant.
      static const xtd::forms::emoticon ophiuchus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026CF. This field is constant.
      static const xtd::forms::emoticon pick;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026D1. This field is constant.
      static const xtd::forms::emoticon helmet_with_white_cross;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026D3. This field is constant.
      static const xtd::forms::emoticon chains;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026D4. This field is constant.
      static const xtd::forms::emoticon no_entry;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026E9. This field is constant.
      static const xtd::forms::emoticon shinto_shrine;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026EA. This field is constant.
      static const xtd::forms::emoticon church;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F0. This field is constant.
      static const xtd::forms::emoticon mountain;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F1. This field is constant.
      static const xtd::forms::emoticon umbrella_on_ground;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F2. This field is constant.
      static const xtd::forms::emoticon fountain;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F3. This field is constant.
      static const xtd::forms::emoticon flag_in_hole;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F4. This field is constant.
      static const xtd::forms::emoticon ferry;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F5. This field is constant.
      static const xtd::forms::emoticon sailboat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F7. This field is constant.
      static const xtd::forms::emoticon skier;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F8. This field is constant.
      static const xtd::forms::emoticon ice_skate;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026F9. This field is constant.
      static const xtd::forms::emoticon person_with_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026FA. This field is constant.
      static const xtd::forms::emoticon tent;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000026FD. This field is constant.
      static const xtd::forms::emoticon fuel_pump;

      // 2700-27BF Dingbats
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002702, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_scissors;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002705. This field is constant.
      static const xtd::forms::emoticon white_heavy_check_mark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002708., 0x0000FE0F} This field is constant.
      static const xtd::forms::emoticon airplane;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002709, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon envelope;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000270A. This field is constant.
      static const xtd::forms::emoticon raised_fist;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000270B. This field is constant.
      static const xtd::forms::emoticon raised_hand;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000270C, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon victory_hand;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000270D, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon writing_hand;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000270F, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon pencil;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002712, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_nib;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002714, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon heavy_check_mark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002716, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon heavy_multiplication_x;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000271D, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon latin_cross;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002721, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon star_of_david;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002728. This field is constant.
      static const xtd::forms::emoticon sparkles;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002733, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon eight_spoked_asterisk;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002734, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon eight_pointed_black_star;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002744, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon snowflake;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002747, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon sparkle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000274C. This field is constant.
      static const xtd::forms::emoticon cross_mark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000274E. This field is constant.
      static const xtd::forms::emoticon negative_squared_cross_mark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002753. This field is constant.
      static const xtd::forms::emoticon black_question_mark_ornament;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of{ 0x00002754, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon white_question_mark_ornament;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002755, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon white_exclamation_mark_ornament;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002757. This field is constant.
      static const xtd::forms::emoticon heavy_exclamation_mark_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002763, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon heavy_heart_exclamation_mark_ornament;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002764, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon black_heart_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002795. This field is constant.
      static const xtd::forms::emoticon heavy_plus_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002796. This field is constant.
      static const xtd::forms::emoticon heavy_minus_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002797. This field is constant.
      static const xtd::forms::emoticon heavy_division_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x000027A, 0x0000FE0F}1. This field is constant.
      static const xtd::forms::emoticon black_rightwards_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000027B0. This field is constant.
      static const xtd::forms::emoticon curly_loop;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x000027BF. This field is constant.
      static const xtd::forms::emoticon double_curly_loop;

      // 2900-297F Supplemental Arrows-B
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002934, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon arrow_pointing_rightwards_then_curving_upwards;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002935, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon arrow_pointing_rightwards_then_curving_downwards;

      /// 2B00-2BFF Miscellaneous Symbols And Arrows
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002B05, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon leftwards_black_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002B06, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon upwards_black_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00002B07, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon downwards_black_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002B1B. This field is constant.
      static const xtd::forms::emoticon black_large_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002B1C. This field is constant.
      static const xtd::forms::emoticon white_large_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002B50. This field is constant.
      static const xtd::forms::emoticon white_medium_star;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x00002B55. This field is constant.
      static const xtd::forms::emoticon heavy_large_circle;

      // 3000-303F CJK Symbols and Punctuation
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00003030, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon wavy_dash;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0000303D, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon part_alternation_mark;

      // 3200-32FF Enclosed CJK Letters and Months
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00003297, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon circled_ideograph_congratulation;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x00003299, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon circled_ideograph_secret;

      // FE00-FE0F Variation Selectors
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0000FE0F. This field is constant.
      static const xtd::forms::emoticon variation_selector_16;
      
      // 1F000-1F02F Mahjong Tiles
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F004. This field is constant.
      static const xtd::forms::emoticon mahjong_tile_red_dragon;

      // 1F0A0-1F0FF Playing Cards
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F0CF. This field is constant.
      static const xtd::forms::emoticon playing_card_black_joker;

      // 1F100-1F1FF Enclosed Alphanumeric Supplement
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0001F170, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon negative_squared_latin_capital_letter_a;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0001F171, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon negative_squared_latin_capital_letter_b;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0001F17E, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon negative_squared_latin_capital_letter_o;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0001F17F, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon negative_squared_latin_capital_letter_p;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F18E. This field is constant.
      static const xtd::forms::emoticon negative_squared_ab;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F191. This field is constant.
      static const xtd::forms::emoticon squared_cl;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F192. This field is constant.
      static const xtd::forms::emoticon squared_cool;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F193. This field is constant.
      static const xtd::forms::emoticon squared_free;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F194. This field is constant.
      static const xtd::forms::emoticon squared_id;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F195. This field is constant.
      static const xtd::forms::emoticon squared_new;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F196. This field is constant.
      static const xtd::forms::emoticon squared_ng;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F197. This field is constant.
      static const xtd::forms::emoticon squared_ok;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F198. This field is constant.
      static const xtd::forms::emoticon squared_sos;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F199. This field is constant.
      static const xtd::forms::emoticon squared_up_with_exclamation_mark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F19A. This field is constant.
      static const xtd::forms::emoticon squared_vs;
      
      // 1F200-1F2FF Enclosed Ideographic Supplement
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F201. This field is constant.
      static const xtd::forms::emoticon squared_katakana_koko;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0001F202, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon squared_katakana_sa;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F21A. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_7121;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F22F. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_6307;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F232. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_7981;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F233. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_7a7a;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F234. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_5408;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F235. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_6e80;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F236. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_6709;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of {0x0001F237, 0x0000FE0F}. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_6708;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F238. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_7533;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F239. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_5272;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F23A. This field is constant.
      static const xtd::forms::emoticon squared_cjk_unified_ideograph_55b6;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F250. This field is constant.
      static const xtd::forms::emoticon circled_ideograph_advantage;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F251. This field is constant.
      static const xtd::forms::emoticon circled_ideograph_accept;
      
      // 1F300-1F5FF symbols_and_pictographs
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F300. This field is constant.
      static const xtd::forms::emoticon cyclone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F301. This field is constant.
      static const xtd::forms::emoticon foggy;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F302. This field is constant.
      static const xtd::forms::emoticon closed_umbrella;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F303. This field is constant.
      static const xtd::forms::emoticon night_with_stars;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F304. This field is constant.
      static const xtd::forms::emoticon sunrise_over_mountains;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F305. This field is constant.
      static const xtd::forms::emoticon sunrise;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F306. This field is constant.
      static const xtd::forms::emoticon cityscape_at_dusk;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F307. This field is constant.
      static const xtd::forms::emoticon sunset_over_buildings;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F308. This field is constant.
      static const xtd::forms::emoticon rainbow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F309. This field is constant.
      static const xtd::forms::emoticon bridge_at_night;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F30A. This field is constant.
      static const xtd::forms::emoticon water_wave;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F30B. This field is constant.
      static const xtd::forms::emoticon volcano;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F30C. This field is constant.
      static const xtd::forms::emoticon milky_way;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F30D. This field is constant.
      static const xtd::forms::emoticon earth_globe_europe_africa;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F30E. This field is constant.
      static const xtd::forms::emoticon earth_globe_americas;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F30F. This field is constant.
      static const xtd::forms::emoticon earth_globe_asia_australia;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F310. This field is constant.
      static const xtd::forms::emoticon globe_with_meridians;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F311. This field is constant.
      static const xtd::forms::emoticon new_moon_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F312. This field is constant.
      static const xtd::forms::emoticon waxing_crescent_moon_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F313. This field is constant.
      static const xtd::forms::emoticon first_quarter_moon_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F314. This field is constant.
      static const xtd::forms::emoticon waxing_gibbous_moon_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F315. This field is constant.
      static const xtd::forms::emoticon full_moon_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F316. This field is constant.
      static const xtd::forms::emoticon waning_gibbous_moon_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F317. This field is constant.
      static const xtd::forms::emoticon last_quarter_moon_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F318. This field is constant.
      static const xtd::forms::emoticon waning_crescent_moon_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F319. This field is constant.
      static const xtd::forms::emoticon crescent_moon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F31A. This field is constant.
      static const xtd::forms::emoticon new_moon_with_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F31B. This field is constant.
      static const xtd::forms::emoticon first_quarter_moon_with_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F31C. This field is constant.
      static const xtd::forms::emoticon last_quarter_moon_with_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F31D. This field is constant.
      static const xtd::forms::emoticon full_moon_with_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F31E. This field is constant.
      static const xtd::forms::emoticon sun_with_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F31F. This field is constant.
      static const xtd::forms::emoticon glowing_star;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F320. This field is constant.
      static const xtd::forms::emoticon shooting_star;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F321. This field is constant.
      static const xtd::forms::emoticon thermometer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F324. This field is constant.
      static const xtd::forms::emoticon white_sun_with_small_cloud;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F325. This field is constant.
      static const xtd::forms::emoticon white_sun_behind_cloud;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F326. This field is constant.
      static const xtd::forms::emoticon white_sun_behind_cloud_with_rain;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F327. This field is constant.
      static const xtd::forms::emoticon cloud_with_rain;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F328. This field is constant.
      static const xtd::forms::emoticon cloud_with_snow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F329. This field is constant.
      static const xtd::forms::emoticon cloud_with_lightning;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F32A. This field is constant.
      static const xtd::forms::emoticon cloud_with_tornado;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F32B. This field is constant.
      static const xtd::forms::emoticon fog;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F32C. This field is constant.
      static const xtd::forms::emoticon wind_blowing_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F32D. This field is constant.
      static const xtd::forms::emoticon hot_dog;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F32E. This field is constant.
      static const xtd::forms::emoticon taco;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F32F. This field is constant.
      static const xtd::forms::emoticon burrito;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F330. This field is constant.
      static const xtd::forms::emoticon chestnut;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F331. This field is constant.
      static const xtd::forms::emoticon seedling;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F332. This field is constant.
      static const xtd::forms::emoticon evergreen_tree;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F333. This field is constant.
      static const xtd::forms::emoticon deciduous_tree;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F334. This field is constant.
      static const xtd::forms::emoticon palm_tree;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F335. This field is constant.
      static const xtd::forms::emoticon cactus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F336. This field is constant.
      static const xtd::forms::emoticon hot_pepper;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F337. This field is constant.
      static const xtd::forms::emoticon tulip;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F338. This field is constant.
      static const xtd::forms::emoticon cherry_blossom;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F339. This field is constant.
      static const xtd::forms::emoticon rose;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F33A. This field is constant.
      static const xtd::forms::emoticon hibiscus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F33B. This field is constant.
      static const xtd::forms::emoticon sunflower;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F33C. This field is constant.
      static const xtd::forms::emoticon blossom;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F33D. This field is constant.
      static const xtd::forms::emoticon ear_of_maize;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F33E. This field is constant.
      static const xtd::forms::emoticon ear_of_rice;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F33F. This field is constant.
      static const xtd::forms::emoticon herb;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F340. This field is constant.
      static const xtd::forms::emoticon four_leaf_clover;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F341. This field is constant.
      static const xtd::forms::emoticon maple_leaf;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F342. This field is constant.
      static const xtd::forms::emoticon fallen_leaf;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F343. This field is constant.
      static const xtd::forms::emoticon leaf_fluttering_in_wind;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F344. This field is constant.
      static const xtd::forms::emoticon mushroom;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F345. This field is constant.
      static const xtd::forms::emoticon tomato;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F346. This field is constant.
      static const xtd::forms::emoticon aubergine;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F347. This field is constant.
      static const xtd::forms::emoticon grapes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F348. This field is constant.
      static const xtd::forms::emoticon melon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F349. This field is constant.
      static const xtd::forms::emoticon watermelon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F34A. This field is constant.
      static const xtd::forms::emoticon tangerine;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F34B. This field is constant.
      static const xtd::forms::emoticon lemon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F34C. This field is constant.
      static const xtd::forms::emoticon banana;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F34D. This field is constant.
      static const xtd::forms::emoticon pineapple;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F34E. This field is constant.
      static const xtd::forms::emoticon red_apple;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F34F. This field is constant.
      static const xtd::forms::emoticon green_apple;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F350. This field is constant.
      static const xtd::forms::emoticon pear;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F351. This field is constant.
      static const xtd::forms::emoticon peach;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F352. This field is constant.
      static const xtd::forms::emoticon cherries;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F353. This field is constant.
      static const xtd::forms::emoticon strawberry;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F354. This field is constant.
      static const xtd::forms::emoticon hamburger;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F355. This field is constant.
      static const xtd::forms::emoticon slice_of_pizza;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F356. This field is constant.
      static const xtd::forms::emoticon meat_on_bone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F357. This field is constant.
      static const xtd::forms::emoticon poultry_leg;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F358. This field is constant.
      static const xtd::forms::emoticon rice_cracker;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F359. This field is constant.
      static const xtd::forms::emoticon rice_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F35A. This field is constant.
      static const xtd::forms::emoticon cooked_rice;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F35B. This field is constant.
      static const xtd::forms::emoticon curry_and_rice;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F35C. This field is constant.
      static const xtd::forms::emoticon steaming_bowl;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F35D. This field is constant.
      static const xtd::forms::emoticon spaghetti;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F35E. This field is constant.
      static const xtd::forms::emoticon bread;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F35F. This field is constant.
      static const xtd::forms::emoticon french_fries;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F360. This field is constant.
      static const xtd::forms::emoticon roasted_sweet_potato;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F361. This field is constant.
      static const xtd::forms::emoticon dango;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F362. This field is constant.
      static const xtd::forms::emoticon oden;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F363. This field is constant.
      static const xtd::forms::emoticon sushi;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F364. This field is constant.
      static const xtd::forms::emoticon fried_shrimp;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F365. This field is constant.
      static const xtd::forms::emoticon fish_cake_with_swirl_design;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F366. This field is constant.
      static const xtd::forms::emoticon soft_ice_cream;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F367. This field is constant.
      static const xtd::forms::emoticon shaved_ice;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F368. This field is constant.
      static const xtd::forms::emoticon ice_cream;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F369. This field is constant.
      static const xtd::forms::emoticon doughnut;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F36A. This field is constant.
      static const xtd::forms::emoticon cookie;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F36B. This field is constant.
      static const xtd::forms::emoticon chocolate_bar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F36C. This field is constant.
      static const xtd::forms::emoticon candy;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F36D. This field is constant.
      static const xtd::forms::emoticon lollipop;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F36E. This field is constant.
      static const xtd::forms::emoticon custard;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F36F. This field is constant.
      static const xtd::forms::emoticon honey_pot;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F370. This field is constant.
      static const xtd::forms::emoticon shortcake;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F371. This field is constant.
      static const xtd::forms::emoticon bento_box;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F372. This field is constant.
      static const xtd::forms::emoticon pot_of_food;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F373. This field is constant.
      static const xtd::forms::emoticon cooking;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F374. This field is constant.
      static const xtd::forms::emoticon fork_and_knife;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F375. This field is constant.
      static const xtd::forms::emoticon teacup_without_handle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F376. This field is constant.
      static const xtd::forms::emoticon sake_bottle_and_cup;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F377. This field is constant.
      static const xtd::forms::emoticon wine_glass;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F378. This field is constant.
      static const xtd::forms::emoticon cocktail_glass;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F379. This field is constant.
      static const xtd::forms::emoticon tropical_drink;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F37A. This field is constant.
      static const xtd::forms::emoticon beer_mug;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F37B. This field is constant.
      static const xtd::forms::emoticon clinking_beer_mugs;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F37C. This field is constant.
      static const xtd::forms::emoticon baby_bottle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F37D. This field is constant.
      static const xtd::forms::emoticon fork_and_knife_with_plate;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F37E. This field is constant.
      static const xtd::forms::emoticon bottle_with_popping_cork;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F37F. This field is constant.
      static const xtd::forms::emoticon popcorn;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F380. This field is constant.
      static const xtd::forms::emoticon ribbon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F381. This field is constant.
      static const xtd::forms::emoticon wrapped_present;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F382. This field is constant.
      static const xtd::forms::emoticon birthday_cake;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F383. This field is constant.
      static const xtd::forms::emoticon jack_o_lantern;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F384. This field is constant.
      static const xtd::forms::emoticon christmas_tree;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F385. This field is constant.
      static const xtd::forms::emoticon father_christmas;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F386. This field is constant.
      static const xtd::forms::emoticon fireworks;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F387. This field is constant.
      static const xtd::forms::emoticon firework_sparkler;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F388. This field is constant.
      static const xtd::forms::emoticon balloon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F389. This field is constant.
      static const xtd::forms::emoticon party_popper;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F38A. This field is constant.
      static const xtd::forms::emoticon confetti_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F38B. This field is constant.
      static const xtd::forms::emoticon tanabata_tree;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F38C. This field is constant.
      static const xtd::forms::emoticon crossed_flags;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F38D. This field is constant.
      static const xtd::forms::emoticon pine_decoration;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F38E. This field is constant.
      static const xtd::forms::emoticon japanese_dolls;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F38F. This field is constant.
      static const xtd::forms::emoticon carp_streamer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F390. This field is constant.
      static const xtd::forms::emoticon wind_chime;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F391. This field is constant.
      static const xtd::forms::emoticon moon_viewing_ceremony;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F392. This field is constant.
      static const xtd::forms::emoticon school_satchel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F393. This field is constant.
      static const xtd::forms::emoticon graduation_cap;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F396. This field is constant.
      static const xtd::forms::emoticon military_medal;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F397. This field is constant.
      static const xtd::forms::emoticon reminder_ribbon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F399. This field is constant.
      static const xtd::forms::emoticon studio_microphone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F39A. This field is constant.
      static const xtd::forms::emoticon level_slider;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F39B. This field is constant.
      static const xtd::forms::emoticon control_knobs;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F39E. This field is constant.
      static const xtd::forms::emoticon film_frames;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F39F. This field is constant.
      static const xtd::forms::emoticon admission_tickets;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A0. This field is constant.
      static const xtd::forms::emoticon carousel_horse;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A1. This field is constant.
      static const xtd::forms::emoticon ferris_wheel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A2. This field is constant.
      static const xtd::forms::emoticon roller_coaster;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A3. This field is constant.
      static const xtd::forms::emoticon fishing_pole_and_fish;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A4. This field is constant.
      static const xtd::forms::emoticon microphone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A5. This field is constant.
      static const xtd::forms::emoticon movie_camera;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A6. This field is constant.
      static const xtd::forms::emoticon cinema;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A7. This field is constant.
      static const xtd::forms::emoticon headphone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A8. This field is constant.
      static const xtd::forms::emoticon artist_palette;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3A9. This field is constant.
      static const xtd::forms::emoticon top_hat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3AA. This field is constant.
      static const xtd::forms::emoticon circus_tent;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3AB. This field is constant.
      static const xtd::forms::emoticon ticket;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3AC. This field is constant.
      static const xtd::forms::emoticon clapper_board;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3AD. This field is constant.
      static const xtd::forms::emoticon performing_arts;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3AE. This field is constant.
      static const xtd::forms::emoticon video_game;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3AF. This field is constant.
      static const xtd::forms::emoticon direct_hit;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B0. This field is constant.
      static const xtd::forms::emoticon slot_machine;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B1. This field is constant.
      static const xtd::forms::emoticon billiards;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B2. This field is constant.
      static const xtd::forms::emoticon game_die;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B3. This field is constant.
      static const xtd::forms::emoticon bowling;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B4. This field is constant.
      static const xtd::forms::emoticon flower_playing_cards;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B5. This field is constant.
      static const xtd::forms::emoticon musical_note;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B6. This field is constant.
      static const xtd::forms::emoticon multiple_musical_notes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B7. This field is constant.
      static const xtd::forms::emoticon saxophone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B8. This field is constant.
      static const xtd::forms::emoticon guitar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3B9. This field is constant.
      static const xtd::forms::emoticon musical_keyboard;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3BA. This field is constant.
      static const xtd::forms::emoticon trumpet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3BB. This field is constant.
      static const xtd::forms::emoticon violin;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3BC. This field is constant.
      static const xtd::forms::emoticon musical_score;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3BD. This field is constant.
      static const xtd::forms::emoticon running_shirt_with_sash;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3BE. This field is constant.
      static const xtd::forms::emoticon tennis_racquet_and_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3BF. This field is constant.
      static const xtd::forms::emoticon ski_and_ski_boot;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C0. This field is constant.
      static const xtd::forms::emoticon basketball_and_hoop;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C1. This field is constant.
      static const xtd::forms::emoticon chequered_flag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C2. This field is constant.
      static const xtd::forms::emoticon snowboarder;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C3. This field is constant.
      static const xtd::forms::emoticon runner;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C4. This field is constant.
      static const xtd::forms::emoticon surfer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C5. This field is constant.
      static const xtd::forms::emoticon sports_medal;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C6. This field is constant.
      static const xtd::forms::emoticon trophy;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C7. This field is constant.
      static const xtd::forms::emoticon horse_racing;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C8. This field is constant.
      static const xtd::forms::emoticon american_football;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3C9. This field is constant.
      static const xtd::forms::emoticon rugby_football;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3CA. This field is constant.
      static const xtd::forms::emoticon swimmer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3CB. This field is constant.
      static const xtd::forms::emoticon weight_lifter;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3CC. This field is constant.
      static const xtd::forms::emoticon golfer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3CD. This field is constant.
      static const xtd::forms::emoticon racing_motorcycle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3CE. This field is constant.
      static const xtd::forms::emoticon racing_car;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3CF. This field is constant.
      static const xtd::forms::emoticon cricket_bat_and_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D0. This field is constant.
      static const xtd::forms::emoticon volleyball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D1. This field is constant.
      static const xtd::forms::emoticon field_hockey_stick_and_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D2. This field is constant.
      static const xtd::forms::emoticon ice_hockey_stick_and_puck;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D3. This field is constant.
      static const xtd::forms::emoticon table_tennis_paddle_and_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D4. This field is constant.
      static const xtd::forms::emoticon snow_capped_mountain;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D5. This field is constant.
      static const xtd::forms::emoticon camping;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D6. This field is constant.
      static const xtd::forms::emoticon beach_with_umbrella;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D7. This field is constant.
      static const xtd::forms::emoticon building_construction;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D8. This field is constant.
      static const xtd::forms::emoticon house_buildings;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3D9. This field is constant.
      static const xtd::forms::emoticon cityscape;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3DA. This field is constant.
      static const xtd::forms::emoticon derelict_house_building;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3DB. This field is constant.
      static const xtd::forms::emoticon classical_building;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3DC. This field is constant.
      static const xtd::forms::emoticon desert;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3DD. This field is constant.
      static const xtd::forms::emoticon desert_island;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3DE. This field is constant.
      static const xtd::forms::emoticon national_park;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3DF. This field is constant.
      static const xtd::forms::emoticon stadium;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E0. This field is constant.
      static const xtd::forms::emoticon house_building;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E1. This field is constant.
      static const xtd::forms::emoticon house_with_garden;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E2. This field is constant.
      static const xtd::forms::emoticon office_building;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E3. This field is constant.
      static const xtd::forms::emoticon japanese_post_office;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E4. This field is constant.
      static const xtd::forms::emoticon european_post_office;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E5. This field is constant.
      static const xtd::forms::emoticon hospital;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E6. This field is constant.
      static const xtd::forms::emoticon bank;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E7. This field is constant.
      static const xtd::forms::emoticon automated_teller_machine;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E8. This field is constant.
      static const xtd::forms::emoticon hotel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3E9. This field is constant.
      static const xtd::forms::emoticon love_hotel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3EA. This field is constant.
      static const xtd::forms::emoticon convenience_store;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3EB. This field is constant.
      static const xtd::forms::emoticon school;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3EC. This field is constant.
      static const xtd::forms::emoticon department_store;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3ED. This field is constant.
      static const xtd::forms::emoticon factory;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3EE. This field is constant.
      static const xtd::forms::emoticon izakaya_lantern;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3EF. This field is constant.
      static const xtd::forms::emoticon japanese_castle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3F0. This field is constant.
      static const xtd::forms::emoticon european_castle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3F3. This field is constant.
      static const xtd::forms::emoticon waving_white_flag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3F4. This field is constant.
      static const xtd::forms::emoticon waving_black_flag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3F5. This field is constant.
      static const xtd::forms::emoticon rosette;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3F7. This field is constant.
      static const xtd::forms::emoticon label;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3F8. This field is constant.
      static const xtd::forms::emoticon badminton_racquet_and_shuttlecock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3F9. This field is constant.
      static const xtd::forms::emoticon bow_and_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3FA. This field is constant.
      static const xtd::forms::emoticon amphora;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3FB. This field is constant.
      static const xtd::forms::emoticon emoji_modifier_fitzpatrick_type_1_2;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3FC. This field is constant.
      static const xtd::forms::emoticon emoji_modifier_fitzpatrick_type_3;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3FD. This field is constant.
      static const xtd::forms::emoticon emoji_modifier_fitzpatrick_type_4;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3FE. This field is constant.
      static const xtd::forms::emoticon emoji_modifier_fitzpatrick_type_5;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F3FF. This field is constant.
      static const xtd::forms::emoticon emoji_modifier_fitzpatrick_type_6;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F400. This field is constant.
      static const xtd::forms::emoticon rat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F401. This field is constant.
      static const xtd::forms::emoticon mouse;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F402. This field is constant.
      static const xtd::forms::emoticon ox;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F403. This field is constant.
      static const xtd::forms::emoticon water_buffalo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F404. This field is constant.
      static const xtd::forms::emoticon cow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F405. This field is constant.
      static const xtd::forms::emoticon tiger;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F406. This field is constant.
      static const xtd::forms::emoticon leopard;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F407. This field is constant.
      static const xtd::forms::emoticon rabbit;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F408. This field is constant.
      static const xtd::forms::emoticon cat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F409. This field is constant.
      static const xtd::forms::emoticon dragon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F40A. This field is constant.
      static const xtd::forms::emoticon crocodile;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F40B. This field is constant.
      static const xtd::forms::emoticon whale;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F40C. This field is constant.
      static const xtd::forms::emoticon snail;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F40D. This field is constant.
      static const xtd::forms::emoticon snake;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F40E. This field is constant.
      static const xtd::forms::emoticon horse;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F40F. This field is constant.
      static const xtd::forms::emoticon ram;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F410. This field is constant.
      static const xtd::forms::emoticon goat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F411. This field is constant.
      static const xtd::forms::emoticon sheep;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F412. This field is constant.
      static const xtd::forms::emoticon monkey;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F413. This field is constant.
      static const xtd::forms::emoticon rooster;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F414. This field is constant.
      static const xtd::forms::emoticon chicken;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F415. This field is constant.
      static const xtd::forms::emoticon dog;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F416. This field is constant.
      static const xtd::forms::emoticon pig;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F417. This field is constant.
      static const xtd::forms::emoticon boar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F418. This field is constant.
      static const xtd::forms::emoticon elephant;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F419. This field is constant.
      static const xtd::forms::emoticon octopus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F41A. This field is constant.
      static const xtd::forms::emoticon spiral_shell;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F41B. This field is constant.
      static const xtd::forms::emoticon bug;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F41C. This field is constant.
      static const xtd::forms::emoticon ant;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F41D. This field is constant.
      static const xtd::forms::emoticon honeybee;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F41E. This field is constant.
      static const xtd::forms::emoticon lady_beetle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F41F. This field is constant.
      static const xtd::forms::emoticon fish;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F420. This field is constant.
      static const xtd::forms::emoticon tropical_fish;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F421. This field is constant.
      static const xtd::forms::emoticon blowfish;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F422. This field is constant.
      static const xtd::forms::emoticon turtle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F423. This field is constant.
      static const xtd::forms::emoticon hatching_chick;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F424. This field is constant.
      static const xtd::forms::emoticon baby_chick;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F425. This field is constant.
      static const xtd::forms::emoticon front_facing_baby_chick;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F426. This field is constant.
      static const xtd::forms::emoticon bird;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F427. This field is constant.
      static const xtd::forms::emoticon penguin;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F428. This field is constant.
      static const xtd::forms::emoticon koala;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F429. This field is constant.
      static const xtd::forms::emoticon poodle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F42A. This field is constant.
      static const xtd::forms::emoticon dromedary_camel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F42B. This field is constant.
      static const xtd::forms::emoticon bactrian_camel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F42C. This field is constant.
      static const xtd::forms::emoticon dolphin;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F42D. This field is constant.
      static const xtd::forms::emoticon mouse_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F42E. This field is constant.
      static const xtd::forms::emoticon cow_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F42F. This field is constant.
      static const xtd::forms::emoticon tiger_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F430. This field is constant.
      static const xtd::forms::emoticon rabbit_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F431. This field is constant.
      static const xtd::forms::emoticon cat_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F432. This field is constant.
      static const xtd::forms::emoticon dragon_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F433. This field is constant.
      static const xtd::forms::emoticon spouting_whale;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F434. This field is constant.
      static const xtd::forms::emoticon horse_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F435. This field is constant.
      static const xtd::forms::emoticon monkey_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F436. This field is constant.
      static const xtd::forms::emoticon dog_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F437. This field is constant.
      static const xtd::forms::emoticon pig_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F438. This field is constant.
      static const xtd::forms::emoticon frog_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F439. This field is constant.
      static const xtd::forms::emoticon hamster_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F43A. This field is constant.
      static const xtd::forms::emoticon wolf_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F43B. This field is constant.
      static const xtd::forms::emoticon bear_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F43C. This field is constant.
      static const xtd::forms::emoticon panda_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F43D. This field is constant.
      static const xtd::forms::emoticon pig_nose;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F43E. This field is constant.
      static const xtd::forms::emoticon paw_prints;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F43F. This field is constant.
      static const xtd::forms::emoticon chipmunk;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F440. This field is constant.
      static const xtd::forms::emoticon eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F441. This field is constant.
      static const xtd::forms::emoticon eye;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F442. This field is constant.
      static const xtd::forms::emoticon ear;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F443. This field is constant.
      static const xtd::forms::emoticon nose;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F444. This field is constant.
      static const xtd::forms::emoticon mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F445. This field is constant.
      static const xtd::forms::emoticon tongue;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F446. This field is constant.
      static const xtd::forms::emoticon white_up_pointing_backhand_index;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F447. This field is constant.
      static const xtd::forms::emoticon white_down_pointing_backhand_index;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F448. This field is constant.
      static const xtd::forms::emoticon white_left_pointing_backhand_index;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F449. This field is constant.
      static const xtd::forms::emoticon white_right_pointing_backhand_index;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F44A. This field is constant.
      static const xtd::forms::emoticon fisted_hand_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F44B. This field is constant.
      static const xtd::forms::emoticon waving_hand_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F44C. This field is constant.
      static const xtd::forms::emoticon ok_hand_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F44D. This field is constant.
      static const xtd::forms::emoticon thumbs_up_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F44E. This field is constant.
      static const xtd::forms::emoticon thumbs_down_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F44F. This field is constant.
      static const xtd::forms::emoticon clapping_hands_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F450. This field is constant.
      static const xtd::forms::emoticon open_hands_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F451. This field is constant.
      static const xtd::forms::emoticon crown;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F452. This field is constant.
      static const xtd::forms::emoticon womans_hat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F453. This field is constant.
      static const xtd::forms::emoticon eyeglasses;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F454. This field is constant.
      static const xtd::forms::emoticon necktie;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F455. This field is constant.
      static const xtd::forms::emoticon t_shirt;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F456. This field is constant.
      static const xtd::forms::emoticon jeans;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F457. This field is constant.
      static const xtd::forms::emoticon dress;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F458. This field is constant.
      static const xtd::forms::emoticon kimono;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F459. This field is constant.
      static const xtd::forms::emoticon bikini;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F45A. This field is constant.
      static const xtd::forms::emoticon womans_clothes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F45B. This field is constant.
      static const xtd::forms::emoticon purse;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F45C. This field is constant.
      static const xtd::forms::emoticon handbag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F45D. This field is constant.
      static const xtd::forms::emoticon pouch;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F45E. This field is constant.
      static const xtd::forms::emoticon mans_shoe;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F45F. This field is constant.
      static const xtd::forms::emoticon athletic_shoe;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F460. This field is constant.
      static const xtd::forms::emoticon high_heeled_shoe;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F461. This field is constant.
      static const xtd::forms::emoticon womans_sandal;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F462. This field is constant.
      static const xtd::forms::emoticon womans_boots;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F463. This field is constant.
      static const xtd::forms::emoticon footprints;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F464. This field is constant.
      static const xtd::forms::emoticon bust_in_silhouette;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F465. This field is constant.
      static const xtd::forms::emoticon busts_in_silhouette;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F466. This field is constant.
      static const xtd::forms::emoticon boy;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F467. This field is constant.
      static const xtd::forms::emoticon girl;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F468. This field is constant.
      static const xtd::forms::emoticon man;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F469. This field is constant.
      static const xtd::forms::emoticon woman;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F46A. This field is constant.
      static const xtd::forms::emoticon family;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F46B. This field is constant.
      static const xtd::forms::emoticon man_and_woman_holding_hands;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F46C. This field is constant.
      static const xtd::forms::emoticon two_men_holding_hands;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F46D. This field is constant.
      static const xtd::forms::emoticon two_women_holding_hands;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F46E. This field is constant.
      static const xtd::forms::emoticon police_officer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F46F. This field is constant.
      static const xtd::forms::emoticon woman_with_bunny_ears;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F470. This field is constant.
      static const xtd::forms::emoticon bride_with_veil;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F471. This field is constant.
      static const xtd::forms::emoticon person_with_blond_hair;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F472. This field is constant.
      static const xtd::forms::emoticon man_with_gua_pi_mao;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F473. This field is constant.
      static const xtd::forms::emoticon man_with_turban;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F474. This field is constant.
      static const xtd::forms::emoticon older_man;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F475. This field is constant.
      static const xtd::forms::emoticon older_woman;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F476. This field is constant.
      static const xtd::forms::emoticon baby;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F477. This field is constant.
      static const xtd::forms::emoticon construction_worker;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F478. This field is constant.
      static const xtd::forms::emoticon princess;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F479. This field is constant.
      static const xtd::forms::emoticon japanese_ogre;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F47A. This field is constant.
      static const xtd::forms::emoticon japanese_goblin;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F47B. This field is constant.
      static const xtd::forms::emoticon ghost;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F47C. This field is constant.
      static const xtd::forms::emoticon baby_angel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F47D. This field is constant.
      static const xtd::forms::emoticon extraterrestrial_alien;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F47E. This field is constant.
      static const xtd::forms::emoticon alien_monster;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F47F. This field is constant.
      static const xtd::forms::emoticon imp;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F480. This field is constant.
      static const xtd::forms::emoticon skull;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F481. This field is constant.
      static const xtd::forms::emoticon information_desk_person;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F482. This field is constant.
      static const xtd::forms::emoticon guardsman;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F483. This field is constant.
      static const xtd::forms::emoticon dancer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F484. This field is constant.
      static const xtd::forms::emoticon lipstick;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F485. This field is constant.
      static const xtd::forms::emoticon nail_polish;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F486. This field is constant.
      static const xtd::forms::emoticon face_massage;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F487. This field is constant.
      static const xtd::forms::emoticon haircut;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F488. This field is constant.
      static const xtd::forms::emoticon barber_pole;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F489. This field is constant.
      static const xtd::forms::emoticon syringe;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F48A. This field is constant.
      static const xtd::forms::emoticon pill;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F48B. This field is constant.
      static const xtd::forms::emoticon kiss_mark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F48C. This field is constant.
      static const xtd::forms::emoticon love_letter;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F48D. This field is constant.
      static const xtd::forms::emoticon ring;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F48E. This field is constant.
      static const xtd::forms::emoticon gem_stone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F48F. This field is constant.
      static const xtd::forms::emoticon kiss;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F490. This field is constant.
      static const xtd::forms::emoticon bouquet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F491. This field is constant.
      static const xtd::forms::emoticon couple_with_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F492. This field is constant.
      static const xtd::forms::emoticon wedding;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F493. This field is constant.
      static const xtd::forms::emoticon beating_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F494. This field is constant.
      static const xtd::forms::emoticon broken_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F495. This field is constant.
      static const xtd::forms::emoticon two_hearts;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F496. This field is constant.
      static const xtd::forms::emoticon sparkling_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F497. This field is constant.
      static const xtd::forms::emoticon growing_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F498. This field is constant.
      static const xtd::forms::emoticon heart_with_arrow;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F499. This field is constant.
      static const xtd::forms::emoticon blue_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F49A. This field is constant.
      static const xtd::forms::emoticon green_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F49B. This field is constant.
      static const xtd::forms::emoticon yellow_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F49C. This field is constant.
      static const xtd::forms::emoticon purple_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F49D. This field is constant.
      static const xtd::forms::emoticon heart_with_ribbon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F49E. This field is constant.
      static const xtd::forms::emoticon revolving_hearts;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F49F. This field is constant.
      static const xtd::forms::emoticon heart_decoration;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A0. This field is constant.
      static const xtd::forms::emoticon diamond_shape_with_a_dot_inside;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A1. This field is constant.
      static const xtd::forms::emoticon electric_light_bulb;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A2. This field is constant.
      static const xtd::forms::emoticon anger_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A3. This field is constant.
      static const xtd::forms::emoticon bomb;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A4. This field is constant.
      static const xtd::forms::emoticon sleeping_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A5. This field is constant.
      static const xtd::forms::emoticon collision_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A6. This field is constant.
      static const xtd::forms::emoticon splashing_sweat_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A7. This field is constant.
      static const xtd::forms::emoticon droplet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A8. This field is constant.
      static const xtd::forms::emoticon dash_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4A9. This field is constant.
      static const xtd::forms::emoticon pile_of_poo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4AA. This field is constant.
      static const xtd::forms::emoticon flexed_biceps;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4AB. This field is constant.
      static const xtd::forms::emoticon dizzy_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4AC. This field is constant.
      static const xtd::forms::emoticon speech_balloon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4AD. This field is constant.
      static const xtd::forms::emoticon thought_balloon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4AE. This field is constant.
      static const xtd::forms::emoticon white_flower;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4AF. This field is constant.
      static const xtd::forms::emoticon hundred_points_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B0. This field is constant.
      static const xtd::forms::emoticon money_bag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B1. This field is constant.
      static const xtd::forms::emoticon currency_exchange;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B2. This field is constant.
      static const xtd::forms::emoticon heavy_dollar_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B3. This field is constant.
      static const xtd::forms::emoticon credit_card;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B4. This field is constant.
      static const xtd::forms::emoticon banknote_with_yen_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B5. This field is constant.
      static const xtd::forms::emoticon banknote_with_dollar_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B6. This field is constant.
      static const xtd::forms::emoticon banknote_with_euro_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B7. This field is constant.
      static const xtd::forms::emoticon banknote_with_pound_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B8. This field is constant.
      static const xtd::forms::emoticon money_with_wings;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4B9. This field is constant.
      static const xtd::forms::emoticon chart_with_upwards_trend_and_yen_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4BA. This field is constant.
      static const xtd::forms::emoticon seat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4BB. This field is constant.
      static const xtd::forms::emoticon personal_computer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4BC. This field is constant.
      static const xtd::forms::emoticon briefcase;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4BD. This field is constant.
      static const xtd::forms::emoticon minidisc;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4BE. This field is constant.
      static const xtd::forms::emoticon floppy_disk;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4BF. This field is constant.
      static const xtd::forms::emoticon optical_disc;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C0. This field is constant.
      static const xtd::forms::emoticon dvd;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C1. This field is constant.
      static const xtd::forms::emoticon file_folder;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C2. This field is constant.
      static const xtd::forms::emoticon open_file_folder;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C3. This field is constant.
      static const xtd::forms::emoticon page_with_curl;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C4. This field is constant.
      static const xtd::forms::emoticon page_facing_up;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C5. This field is constant.
      static const xtd::forms::emoticon calendar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C6. This field is constant.
      static const xtd::forms::emoticon tear_off_calendar;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C7. This field is constant.
      static const xtd::forms::emoticon card_index;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C8. This field is constant.
      static const xtd::forms::emoticon chart_with_upwards_trend;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4C9. This field is constant.
      static const xtd::forms::emoticon chart_with_downwards_trend;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4CA. This field is constant.
      static const xtd::forms::emoticon bar_chart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4CB. This field is constant.
      static const xtd::forms::emoticon clipboard;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4CC. This field is constant.
      static const xtd::forms::emoticon pushpin;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4CD. This field is constant.
      static const xtd::forms::emoticon round_pushpin;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4CE. This field is constant.
      static const xtd::forms::emoticon paperclip;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4CF. This field is constant.
      static const xtd::forms::emoticon straight_ruler;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D0. This field is constant.
      static const xtd::forms::emoticon triangular_ruler;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D1. This field is constant.
      static const xtd::forms::emoticon bookmark_tabs;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D2. This field is constant.
      static const xtd::forms::emoticon ledger;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D3. This field is constant.
      static const xtd::forms::emoticon notebook;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D4. This field is constant.
      static const xtd::forms::emoticon notebook_with_decorative_cover;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D5. This field is constant.
      static const xtd::forms::emoticon closed_book;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D6. This field is constant.
      static const xtd::forms::emoticon open_book;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D7. This field is constant.
      static const xtd::forms::emoticon green_book;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D8. This field is constant.
      static const xtd::forms::emoticon blue_book;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4D9. This field is constant.
      static const xtd::forms::emoticon orange_book;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4DA. This field is constant.
      static const xtd::forms::emoticon books;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4DB. This field is constant.
      static const xtd::forms::emoticon name_badge;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4DC. This field is constant.
      static const xtd::forms::emoticon scroll;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4DD. This field is constant.
      static const xtd::forms::emoticon memo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4DE. This field is constant.
      static const xtd::forms::emoticon telephone_receiver;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4DF. This field is constant.
      static const xtd::forms::emoticon pager;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E0. This field is constant.
      static const xtd::forms::emoticon fax_machine;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E1. This field is constant.
      static const xtd::forms::emoticon satellite_antenna;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E2. This field is constant.
      static const xtd::forms::emoticon public_address_loudspeaker;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E3. This field is constant.
      static const xtd::forms::emoticon cheering_megaphone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E4. This field is constant.
      static const xtd::forms::emoticon outbox_tray;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E5. This field is constant.
      static const xtd::forms::emoticon inbox_tray;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E6. This field is constant.
      static const xtd::forms::emoticon package;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E7. This field is constant.
      static const xtd::forms::emoticon e_mail_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E8. This field is constant.
      static const xtd::forms::emoticon incoming_envelope;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4E9. This field is constant.
      static const xtd::forms::emoticon envelope_with_downwards_arrow_above;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4EA. This field is constant.
      static const xtd::forms::emoticon closed_mailbox_with_lowered_flag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4EB. This field is constant.
      static const xtd::forms::emoticon closed_mailbox_with_raised_flag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4EC. This field is constant.
      static const xtd::forms::emoticon open_mailbox_with_raised_flag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4ED. This field is constant.
      static const xtd::forms::emoticon open_mailbox_with_lowered_flag;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4EE. This field is constant.
      static const xtd::forms::emoticon postbox;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4EF. This field is constant.
      static const xtd::forms::emoticon postal_horn;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F0. This field is constant.
      static const xtd::forms::emoticon newspaper;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F1. This field is constant.
      static const xtd::forms::emoticon mobile_phone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F2. This field is constant.
      static const xtd::forms::emoticon mobile_phone_with_rightwards_arrow_at_left;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F3. This field is constant.
      static const xtd::forms::emoticon vibration_mode;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F4. This field is constant.
      static const xtd::forms::emoticon mobile_phone_off;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F5. This field is constant.
      static const xtd::forms::emoticon no_mobile_phones;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F6. This field is constant.
      static const xtd::forms::emoticon antenna_with_bars;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F7. This field is constant.
      static const xtd::forms::emoticon camera;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F8. This field is constant.
      static const xtd::forms::emoticon camera_with_flash;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4F9. This field is constant.
      static const xtd::forms::emoticon video_camera;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4FA. This field is constant.
      static const xtd::forms::emoticon television;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4FB. This field is constant.
      static const xtd::forms::emoticon radio;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4FC. This field is constant.
      static const xtd::forms::emoticon videocassette;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4FD. This field is constant.
      static const xtd::forms::emoticon film_projector;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F4FF. This field is constant.
      static const xtd::forms::emoticon prayer_beads;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F500. This field is constant.
      static const xtd::forms::emoticon twisted_rightwards_arrows;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F501. This field is constant.
      static const xtd::forms::emoticon clockwise_rightwards_and_leftwards_open_circle_arrows;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F502. This field is constant.
      static const xtd::forms::emoticon clockwise_rightwards_and_leftwards_open_circle_arrows_with_circled_one_overlay;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F503. This field is constant.
      static const xtd::forms::emoticon clockwise_downwards_and_upwards_open_circle_arrows;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F504. This field is constant.
      static const xtd::forms::emoticon anticlockwise_downwards_and_upwards_open_circle_arrows;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F505. This field is constant.
      static const xtd::forms::emoticon low_brightness_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F506. This field is constant.
      static const xtd::forms::emoticon high_brightness_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F507. This field is constant.
      static const xtd::forms::emoticon speaker_with_cancellation_stroke;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F508. This field is constant.
      static const xtd::forms::emoticon speaker;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F509. This field is constant.
      static const xtd::forms::emoticon speaker_with_one_sound_wave;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F50A. This field is constant.
      static const xtd::forms::emoticon speaker_with_three_sound_waves;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F50B. This field is constant.
      static const xtd::forms::emoticon battery;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F50C. This field is constant.
      static const xtd::forms::emoticon electric_plug;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F50D. This field is constant.
      static const xtd::forms::emoticon left_pointing_magnifying_glass;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F50E. This field is constant.
      static const xtd::forms::emoticon right_pointing_magnifying_glass;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F50F. This field is constant.
      static const xtd::forms::emoticon lock_with_ink_pen;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F510. This field is constant.
      static const xtd::forms::emoticon closed_lock_with_key;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F511. This field is constant.
      static const xtd::forms::emoticon key;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F512. This field is constant.
      static const xtd::forms::emoticon lock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F513. This field is constant.
      static const xtd::forms::emoticon open_lock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F514. This field is constant.
      static const xtd::forms::emoticon bell;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F515. This field is constant.
      static const xtd::forms::emoticon bell_with_cancellation_stroke;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F516. This field is constant.
      static const xtd::forms::emoticon bookmark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F517. This field is constant.
      static const xtd::forms::emoticon link_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F518. This field is constant.
      static const xtd::forms::emoticon radio_button;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F519. This field is constant.
      static const xtd::forms::emoticon back_with_leftwards_arrow_above;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F51A. This field is constant.
      static const xtd::forms::emoticon end_with_leftwards_arrow_above;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F51B. This field is constant.
      static const xtd::forms::emoticon on_with_exclamation_mark_with_left_right_arrow_above;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F51C. This field is constant.
      static const xtd::forms::emoticon soon_with_rightwards_arrow_above;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F51D. This field is constant.
      static const xtd::forms::emoticon top_with_upwards_arrow_above;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F51E. This field is constant.
      static const xtd::forms::emoticon no_one_under_eighteen_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F51F. This field is constant.
      static const xtd::forms::emoticon keycap_ten;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F520. This field is constant.
      static const xtd::forms::emoticon input_symbol_for_latin_capital_letters;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F521. This field is constant.
      static const xtd::forms::emoticon input_symbol_for_latin_small_letters;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F522. This field is constant.
      static const xtd::forms::emoticon input_symbol_for_numbers;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F523. This field is constant.
      static const xtd::forms::emoticon input_symbol_for_symbols;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F524. This field is constant.
      static const xtd::forms::emoticon input_symbol_for_latin_letters;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F525. This field is constant.
      static const xtd::forms::emoticon fire;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F526. This field is constant.
      static const xtd::forms::emoticon electric_torch;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F527. This field is constant.
      static const xtd::forms::emoticon wrench;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F528. This field is constant.
      static const xtd::forms::emoticon hammer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F529. This field is constant.
      static const xtd::forms::emoticon nut_and_bolt;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F52A. This field is constant.
      static const xtd::forms::emoticon hocho;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F52B. This field is constant.
      static const xtd::forms::emoticon pistol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F52C. This field is constant.
      static const xtd::forms::emoticon microscope;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F52D. This field is constant.
      static const xtd::forms::emoticon telescope;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F52E. This field is constant.
      static const xtd::forms::emoticon crystal_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F52F. This field is constant.
      static const xtd::forms::emoticon six_pointed_star_with_middle_dot;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F530. This field is constant.
      static const xtd::forms::emoticon japanese_symbol_for_beginner;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F531. This field is constant.
      static const xtd::forms::emoticon trident_emblem;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F532. This field is constant.
      static const xtd::forms::emoticon black_square_button;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F533. This field is constant.
      static const xtd::forms::emoticon white_square_button;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F534. This field is constant.
      static const xtd::forms::emoticon large_red_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F535. This field is constant.
      static const xtd::forms::emoticon large_blue_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F536. This field is constant.
      static const xtd::forms::emoticon large_orange_diamond;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F537. This field is constant.
      static const xtd::forms::emoticon large_blue_diamond;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F538. This field is constant.
      static const xtd::forms::emoticon small_orange_diamond;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F539. This field is constant.
      static const xtd::forms::emoticon small_blue_diamond;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F53A. This field is constant.
      static const xtd::forms::emoticon up_pointing_red_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F53B. This field is constant.
      static const xtd::forms::emoticon down_pointing_red_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F53C. This field is constant.
      static const xtd::forms::emoticon up_pointing_small_red_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F53D. This field is constant.
      static const xtd::forms::emoticon down_pointing_small_red_triangle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F549. This field is constant.
      static const xtd::forms::emoticon om_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F54A. This field is constant.
      static const xtd::forms::emoticon dove_of_peace;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F54B. This field is constant.
      static const xtd::forms::emoticon kaaba;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F54C. This field is constant.
      static const xtd::forms::emoticon mosque;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F54D. This field is constant.
      static const xtd::forms::emoticon synagogue;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F54E. This field is constant.
      static const xtd::forms::emoticon menorah_with_nine_branches;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F550. This field is constant.
      static const xtd::forms::emoticon clock_face_one_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F551. This field is constant.
      static const xtd::forms::emoticon clock_face_two_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F552. This field is constant.
      static const xtd::forms::emoticon clock_face_three_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F553. This field is constant.
      static const xtd::forms::emoticon clock_face_four_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F554. This field is constant.
      static const xtd::forms::emoticon clock_face_five_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F555. This field is constant.
      static const xtd::forms::emoticon clock_face_six_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F556. This field is constant.
      static const xtd::forms::emoticon clock_face_seven_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F557. This field is constant.
      static const xtd::forms::emoticon clock_face_eight_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F558. This field is constant.
      static const xtd::forms::emoticon clock_face_nine_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F559. This field is constant.
      static const xtd::forms::emoticon clock_face_ten_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F55A. This field is constant.
      static const xtd::forms::emoticon clock_face_eleven_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F55B. This field is constant.
      static const xtd::forms::emoticon clock_face_twelve_oclock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F55C. This field is constant.
      static const xtd::forms::emoticon clock_face_one_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F55D. This field is constant.
      static const xtd::forms::emoticon clock_face_two_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F55E. This field is constant.
      static const xtd::forms::emoticon clock_face_three_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F55F. This field is constant.
      static const xtd::forms::emoticon clock_face_four_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F560. This field is constant.
      static const xtd::forms::emoticon clock_face_five_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F561. This field is constant.
      static const xtd::forms::emoticon clock_face_six_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F562. This field is constant.
      static const xtd::forms::emoticon clock_face_seven_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F563. This field is constant.
      static const xtd::forms::emoticon clock_face_eight_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F564. This field is constant.
      static const xtd::forms::emoticon clock_face_nine_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F565. This field is constant.
      static const xtd::forms::emoticon clock_face_ten_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F566. This field is constant.
      static const xtd::forms::emoticon clock_face_eleven_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F567. This field is constant.
      static const xtd::forms::emoticon clock_face_twelve_thirty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F56F. This field is constant.
      static const xtd::forms::emoticon candle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F570. This field is constant.
      static const xtd::forms::emoticon mantelpiece_clock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F573. This field is constant.
      static const xtd::forms::emoticon hole;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F574. This field is constant.
      static const xtd::forms::emoticon man_in_business_suit_levitating;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F575. This field is constant.
      static const xtd::forms::emoticon sleuth_or_spy;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F576. This field is constant.
      static const xtd::forms::emoticon dark_sunglasses;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F577. This field is constant.
      static const xtd::forms::emoticon spider;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F578. This field is constant.
      static const xtd::forms::emoticon spider_web;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F579. This field is constant.
      static const xtd::forms::emoticon joystick;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F57A. This field is constant.
      static const xtd::forms::emoticon man_dancing;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F587. This field is constant.
      static const xtd::forms::emoticon linked_paperclips;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F58A. This field is constant.
      static const xtd::forms::emoticon lower_left_ballpoint_pen;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F58B. This field is constant.
      static const xtd::forms::emoticon lower_left_fountain_pen;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F58C. This field is constant.
      static const xtd::forms::emoticon lower_left_paintbrush;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F58D. This field is constant.
      static const xtd::forms::emoticon lower_left_crayon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F590. This field is constant.
      static const xtd::forms::emoticon raised_hand_with_fingers_splayed;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F595. This field is constant.
      static const xtd::forms::emoticon reversed_hand_with_middle_finger_extended;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F596. This field is constant.
      static const xtd::forms::emoticon raised_hand_with_part_between_middle_and_ring_fingers;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5A4. This field is constant.
      static const xtd::forms::emoticon black_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5A5. This field is constant.
      static const xtd::forms::emoticon desktop_computer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5A8. This field is constant.
      static const xtd::forms::emoticon printer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5B1. This field is constant.
      static const xtd::forms::emoticon three_button_mouse;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5B2. This field is constant.
      static const xtd::forms::emoticon trackball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5BC. This field is constant.
      static const xtd::forms::emoticon frame_with_picture;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5C2. This field is constant.
      static const xtd::forms::emoticon card_index_dividers;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5C3. This field is constant.
      static const xtd::forms::emoticon card_file_box;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5C4. This field is constant.
      static const xtd::forms::emoticon file_cabinet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5D1. This field is constant.
      static const xtd::forms::emoticon wastebasket;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5D2. This field is constant.
      static const xtd::forms::emoticon spiral_note_pad;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5D3. This field is constant.
      static const xtd::forms::emoticon spiral_calendar_pad;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5DC. This field is constant.
      static const xtd::forms::emoticon compression;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5DD. This field is constant.
      static const xtd::forms::emoticon old_key;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5DE. This field is constant.
      static const xtd::forms::emoticon rolled_up_newspaper;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5E1. This field is constant.
      static const xtd::forms::emoticon dagger_knife;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5E3. This field is constant.
      static const xtd::forms::emoticon speaking_head_in_silhouette;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5E8. This field is constant.
      static const xtd::forms::emoticon left_speech_bubble;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5EF. This field is constant.
      static const xtd::forms::emoticon right_anger_bubble;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5F3. This field is constant.
      static const xtd::forms::emoticon ballot_box_with_ballot;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5FA. This field is constant.
      static const xtd::forms::emoticon world_map;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5FB. This field is constant.
      static const xtd::forms::emoticon mount_fuji;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5FC. This field is constant.
      static const xtd::forms::emoticon tokyo_tower;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5FD. This field is constant.
      static const xtd::forms::emoticon statue_of_liberty;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5FE. This field is constant.
      static const xtd::forms::emoticon silhouette_of_japan;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F5FF. This field is constant.
      static const xtd::forms::emoticon moyai;
      
      /// 1F600-1F64F Emoticons (Emoji)
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F600. This field is constant.
      static const xtd::forms::emoticon grinning_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F601. This field is constant.
      static const xtd::forms::emoticon grinning_face_with_smiling_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F602. This field is constant.
      static const xtd::forms::emoticon face_with_tears_of_joy;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F603. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_open_mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F604. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_open_mouth_and_smiling_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F605. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_open_mouth_and_cold_sweat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F606. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_open_mouth_and_tightly_closed_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F607. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_halo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F608. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_horns;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F609. This field is constant.
      static const xtd::forms::emoticon winking_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F60A. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_smiling_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F60B. This field is constant.
      static const xtd::forms::emoticon face_savouring_delicious_food;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F60C. This field is constant.
      static const xtd::forms::emoticon relieved_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F60D. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_heart_shaped_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F60E. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_sunglasses;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F60F. This field is constant.
      static const xtd::forms::emoticon smirking_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F610. This field is constant.
      static const xtd::forms::emoticon neutral_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F611. This field is constant.
      static const xtd::forms::emoticon expressionless_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F612. This field is constant.
      static const xtd::forms::emoticon unamused_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F613. This field is constant.
      static const xtd::forms::emoticon face_with_cold_sweat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F614. This field is constant.
      static const xtd::forms::emoticon pensive_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F615. This field is constant.
      static const xtd::forms::emoticon confused_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F616. This field is constant.
      static const xtd::forms::emoticon confounded_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F617. This field is constant.
      static const xtd::forms::emoticon kissing_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F618. This field is constant.
      static const xtd::forms::emoticon face_throwing_a_kiss;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F619. This field is constant.
      static const xtd::forms::emoticon kissing_face_with_smiling_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F61A. This field is constant.
      static const xtd::forms::emoticon kissing_face_with_closed_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F61B. This field is constant.
      static const xtd::forms::emoticon face_with_stuck_out_tongue;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F61C. This field is constant.
      static const xtd::forms::emoticon face_with_stuck_out_tongue_and_winking_eye;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F61D. This field is constant.
      static const xtd::forms::emoticon face_with_stuck_out_tongue_and_tightly_closed_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F61E. This field is constant.
      static const xtd::forms::emoticon disappointed_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F61F. This field is constant.
      static const xtd::forms::emoticon worried_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F620. This field is constant.
      static const xtd::forms::emoticon angry_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F621. This field is constant.
      static const xtd::forms::emoticon pouting_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F622. This field is constant.
      static const xtd::forms::emoticon crying_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F623. This field is constant.
      static const xtd::forms::emoticon persevering_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F624. This field is constant.
      static const xtd::forms::emoticon face_with_look_of_triumph;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F625. This field is constant.
      static const xtd::forms::emoticon disappointed_but_relieved_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F626. This field is constant.
      static const xtd::forms::emoticon frowning_face_with_open_mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F627. This field is constant.
      static const xtd::forms::emoticon anguished_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F628. This field is constant.
      static const xtd::forms::emoticon fearful_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F629. This field is constant.
      static const xtd::forms::emoticon weary_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F62A. This field is constant.
      static const xtd::forms::emoticon sleepy_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F62B. This field is constant.
      static const xtd::forms::emoticon tired_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F62C. This field is constant.
      static const xtd::forms::emoticon grimacing_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F62D. This field is constant.
      static const xtd::forms::emoticon loudly_crying_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F62E. This field is constant.
      static const xtd::forms::emoticon face_with_open_mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F62F. This field is constant.
      static const xtd::forms::emoticon hushed_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F630. This field is constant.
      static const xtd::forms::emoticon face_with_open_mouth_and_cold_sweat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F631. This field is constant.
      static const xtd::forms::emoticon face_screaming_in_fear;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F632. This field is constant.
      static const xtd::forms::emoticon astonished_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F633. This field is constant.
      static const xtd::forms::emoticon flushed_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F634. This field is constant.
      static const xtd::forms::emoticon sleeping_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F635. This field is constant.
      static const xtd::forms::emoticon dizzy_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F636. This field is constant.
      static const xtd::forms::emoticon face_without_mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F637. This field is constant.
      static const xtd::forms::emoticon face_with_medical_mask;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F638. This field is constant.
      static const xtd::forms::emoticon grinning_cat_face_with_smiling_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F639. This field is constant.
      static const xtd::forms::emoticon cat_face_with_tears_of_joy;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F63A. This field is constant.
      static const xtd::forms::emoticon smiling_cat_face_with_open_mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F63B. This field is constant.
      static const xtd::forms::emoticon smiling_cat_face_with_heart_shaped_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F63C. This field is constant.
      static const xtd::forms::emoticon cat_face_with_wry_smile;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F63D. This field is constant.
      static const xtd::forms::emoticon kissing_cat_face_with_closed_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F63E. This field is constant.
      static const xtd::forms::emoticon pouting_cat_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F63F. This field is constant.
      static const xtd::forms::emoticon crying_cat_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F640. This field is constant.
      static const xtd::forms::emoticon weary_cat_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F641. This field is constant.
      static const xtd::forms::emoticon slightly_frowning_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F642. This field is constant.
      static const xtd::forms::emoticon slightly_smiling_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F643. This field is constant.
      static const xtd::forms::emoticon upside_down_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F644. This field is constant.
      static const xtd::forms::emoticon face_with_rolling_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F645. This field is constant.
      static const xtd::forms::emoticon face_with_no_good_gesture;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F646. This field is constant.
      static const xtd::forms::emoticon face_with_ok_gesture;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F647. This field is constant.
      static const xtd::forms::emoticon person_bowing_deeply;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F648. This field is constant.
      static const xtd::forms::emoticon see_no_evil_monkey;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F649. This field is constant.
      static const xtd::forms::emoticon hear_no_evil_monkey;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F64A. This field is constant.
      static const xtd::forms::emoticon speak_no_evil_monkey;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F64B. This field is constant.
      static const xtd::forms::emoticon happy_person_raising_one_hand;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F64C. This field is constant.
      static const xtd::forms::emoticon person_raising_both_hands_in_celebration;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F64D. This field is constant.
      static const xtd::forms::emoticon person_frowning;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F64E. This field is constant.
      static const xtd::forms::emoticon person_with_pouting_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F64F. This field is constant.
      static const xtd::forms::emoticon person_with_folded_hands;
      
      // 1F680-1F6FF Transport And Map Symbols
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F680. This field is constant.
      static const xtd::forms::emoticon rocket;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F681. This field is constant.
      static const xtd::forms::emoticon helicopter;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F682. This field is constant.
      static const xtd::forms::emoticon steam_locomotive;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F683. This field is constant.
      static const xtd::forms::emoticon railway_car;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F684. This field is constant.
      static const xtd::forms::emoticon high_speed_train;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F685. This field is constant.
      static const xtd::forms::emoticon high_speed_train_with_bullet_nose;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F686. This field is constant.
      static const xtd::forms::emoticon train;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F687. This field is constant.
      static const xtd::forms::emoticon metro;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F688. This field is constant.
      static const xtd::forms::emoticon light_rail;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F689. This field is constant.
      static const xtd::forms::emoticon station;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F68A. This field is constant.
      static const xtd::forms::emoticon tram;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F68B. This field is constant.
      static const xtd::forms::emoticon tram_car;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F68C. This field is constant.
      static const xtd::forms::emoticon bus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F68D. This field is constant.
      static const xtd::forms::emoticon oncoming_bus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F68E. This field is constant.
      static const xtd::forms::emoticon trolleybus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F68F. This field is constant.
      static const xtd::forms::emoticon bus_stop;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F690. This field is constant.
      static const xtd::forms::emoticon minibus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F691. This field is constant.
      static const xtd::forms::emoticon ambulance;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F692. This field is constant.
      static const xtd::forms::emoticon fire_engine;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F693. This field is constant.
      static const xtd::forms::emoticon police_car;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F694. This field is constant.
      static const xtd::forms::emoticon oncoming_police_car;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F695. This field is constant.
      static const xtd::forms::emoticon taxi;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F696. This field is constant.
      static const xtd::forms::emoticon oncoming_taxi;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F697. This field is constant.
      static const xtd::forms::emoticon automobile;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F698. This field is constant.
      static const xtd::forms::emoticon oncoming_automobile;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F699. This field is constant.
      static const xtd::forms::emoticon recreational_vehicle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F69A. This field is constant.
      static const xtd::forms::emoticon delivery_truck;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F69B. This field is constant.
      static const xtd::forms::emoticon articulated_lorry;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F69C. This field is constant.
      static const xtd::forms::emoticon tractor;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F69D. This field is constant.
      static const xtd::forms::emoticon monorail;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F69E. This field is constant.
      static const xtd::forms::emoticon mountain_railway;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F69F. This field is constant.
      static const xtd::forms::emoticon suspension_railway;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A0. This field is constant.
      static const xtd::forms::emoticon mountain_cableway;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A1. This field is constant.
      static const xtd::forms::emoticon aerial_tramway;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A2. This field is constant.
      static const xtd::forms::emoticon ship;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A3. This field is constant.
      static const xtd::forms::emoticon rowboat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A4. This field is constant.
      static const xtd::forms::emoticon speedboat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A5. This field is constant.
      static const xtd::forms::emoticon horizontal_traffic_light;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A6. This field is constant.
      static const xtd::forms::emoticon vertical_traffic_light;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A7. This field is constant.
      static const xtd::forms::emoticon construction_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A8. This field is constant.
      static const xtd::forms::emoticon police_cars_revolving_light;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6A9. This field is constant.
      static const xtd::forms::emoticon triangular_flag_on_post;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6AA. This field is constant.
      static const xtd::forms::emoticon door;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6AB. This field is constant.
      static const xtd::forms::emoticon no_entry_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6AC. This field is constant.
      static const xtd::forms::emoticon smoking_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6AD. This field is constant.
      static const xtd::forms::emoticon no_smoking_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6AE. This field is constant.
      static const xtd::forms::emoticon put_litter_in_its_place_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6AF. This field is constant.
      static const xtd::forms::emoticon do_not_litter_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B0. This field is constant.
      static const xtd::forms::emoticon potable_water_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B1. This field is constant.
      static const xtd::forms::emoticon non_potable_water_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B2. This field is constant.
      static const xtd::forms::emoticon bicycle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B3. This field is constant.
      static const xtd::forms::emoticon no_bicycles;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B4. This field is constant.
      static const xtd::forms::emoticon bicyclist;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B5. This field is constant.
      static const xtd::forms::emoticon mountain_bicyclist;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B6. This field is constant.
      static const xtd::forms::emoticon pedestrian;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B7. This field is constant.
      static const xtd::forms::emoticon no_pedestrians;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B8. This field is constant.
      static const xtd::forms::emoticon children_crossing;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6B9. This field is constant.
      static const xtd::forms::emoticon mens_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6BA. This field is constant.
      static const xtd::forms::emoticon womens_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6BB. This field is constant.
      static const xtd::forms::emoticon restroom;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6BC. This field is constant.
      static const xtd::forms::emoticon baby_symbol;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6BD. This field is constant.
      static const xtd::forms::emoticon toilet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6BE. This field is constant.
      static const xtd::forms::emoticon water_closet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6BF. This field is constant.
      static const xtd::forms::emoticon shower;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6C0. This field is constant.
      static const xtd::forms::emoticon bath;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6C1. This field is constant.
      static const xtd::forms::emoticon bathtub;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6C2. This field is constant.
      static const xtd::forms::emoticon passport_control;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6C3. This field is constant.
      static const xtd::forms::emoticon customs;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6C4. This field is constant.
      static const xtd::forms::emoticon baggage_claim;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6C5. This field is constant.
      static const xtd::forms::emoticon left_luggage;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6CB. This field is constant.
      static const xtd::forms::emoticon couch_and_lamp;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6CC. This field is constant.
      static const xtd::forms::emoticon sleeping_accommodation;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6CD. This field is constant.
      static const xtd::forms::emoticon shopping_bags;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6CE. This field is constant.
      static const xtd::forms::emoticon bellhop_bell;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6CF. This field is constant.
      static const xtd::forms::emoticon bed;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6D0. This field is constant.
      static const xtd::forms::emoticon place_of_worship;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6D1. This field is constant.
      static const xtd::forms::emoticon octagonal_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6D2. This field is constant.
      static const xtd::forms::emoticon shopping_trolley;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6E0. This field is constant.
      static const xtd::forms::emoticon hammer_and_wrench;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6E1. This field is constant.
      static const xtd::forms::emoticon shield;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6E2. This field is constant.
      static const xtd::forms::emoticon oil_drum;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6E3. This field is constant.
      static const xtd::forms::emoticon motorway;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6E4. This field is constant.
      static const xtd::forms::emoticon railway_track;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6E5. This field is constant.
      static const xtd::forms::emoticon motor_boat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6E9. This field is constant.
      static const xtd::forms::emoticon small_airplane;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6EB. This field is constant.
      static const xtd::forms::emoticon airplane_departure;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6EC. This field is constant.
      static const xtd::forms::emoticon airplane_arriving;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6F0. This field is constant.
      static const xtd::forms::emoticon satellite;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6F3. This field is constant.
      static const xtd::forms::emoticon passenger_ship;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6F4. This field is constant.
      static const xtd::forms::emoticon scooter;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6F5. This field is constant.
      static const xtd::forms::emoticon motor_scooter;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6F6. This field is constant.
      static const xtd::forms::emoticon canoe;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6F7. This field is constant.
      static const xtd::forms::emoticon sled;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6F8. This field is constant.
      static const xtd::forms::emoticon flying_saucer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6F9. This field is constant.
      static const xtd::forms::emoticon skateboard;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F6FA. This field is constant.
      static const xtd::forms::emoticon auto_rrickshaw;
      
      // 1F780-1F7FF Geometric Shapes Extended
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E0. This field is constant.
      static const xtd::forms::emoticon large_orange_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E1. This field is constant.
      static const xtd::forms::emoticon large_yellow_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E2. This field is constant.
      static const xtd::forms::emoticon large_green_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E3. This field is constant.
      static const xtd::forms::emoticon large_purple_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E4. This field is constant.
      static const xtd::forms::emoticon large_brown_circle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E5. This field is constant.
      static const xtd::forms::emoticon large_red_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E6. This field is constant.
      static const xtd::forms::emoticon large_blue_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E7. This field is constant.
      static const xtd::forms::emoticon large_orange_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E8. This field is constant.
      static const xtd::forms::emoticon large_yellow_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E9. This field is constant.
      static const xtd::forms::emoticon large_green_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7E1. This field is constant.
      static const xtd::forms::emoticon large_purple_square;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F7EB. This field is constant.
      static const xtd::forms::emoticon large_brown_square;
      
      // 1F900-1F9FF Supplemental Symbols and Pictographs
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F90D. This field is constant.
      static const xtd::forms::emoticon white_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F90E. This field is constant.
      static const xtd::forms::emoticon brown_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F90F. This field is constant.
      static const xtd::forms::emoticon pinching_hand;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F910. This field is constant.
      static const xtd::forms::emoticon zipper_mouth_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F911. This field is constant.
      static const xtd::forms::emoticon money_mouth_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F912. This field is constant.
      static const xtd::forms::emoticon face_with_thermometer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F913. This field is constant.
      static const xtd::forms::emoticon nerd_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F914. This field is constant.
      static const xtd::forms::emoticon thinking_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F915. This field is constant.
      static const xtd::forms::emoticon face_with_head_bandage;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F916. This field is constant.
      static const xtd::forms::emoticon robot_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F917. This field is constant.
      static const xtd::forms::emoticon hugging_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F918. This field is constant.
      static const xtd::forms::emoticon sign_of_the_horns;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F919. This field is constant.
      static const xtd::forms::emoticon call_me_hand;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F91A. This field is constant.
      static const xtd::forms::emoticon raised_back_of_hand;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F91B. This field is constant.
      static const xtd::forms::emoticon left_facing_fist;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F91C. This field is constant.
      static const xtd::forms::emoticon right_facing_fist;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F91D. This field is constant.
      static const xtd::forms::emoticon handshake;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F91E. This field is constant.
      static const xtd::forms::emoticon hand_with_index_and_middle_fingers_crossed;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F91F. This field is constant.
      static const xtd::forms::emoticon i_love_you_hand_sign;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F920. This field is constant.
      static const xtd::forms::emoticon face_with_cowboy_hat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F921. This field is constant.
      static const xtd::forms::emoticon clown_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F922. This field is constant.
      static const xtd::forms::emoticon nauseated_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F923. This field is constant.
      static const xtd::forms::emoticon rolling_on_the_floor_laughing;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F924. This field is constant.
      static const xtd::forms::emoticon drooling_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F925. This field is constant.
      static const xtd::forms::emoticon lying_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F926. This field is constant.
      static const xtd::forms::emoticon face_palm;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F927. This field is constant.
      static const xtd::forms::emoticon sneezing_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F928. This field is constant.
      static const xtd::forms::emoticon face_with_one_eyebrow_raised;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F929. This field is constant.
      static const xtd::forms::emoticon grinning_face_with_star_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F92A. This field is constant.
      static const xtd::forms::emoticon grinning_face_with_one_large_and_one_small_eye;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F92B. This field is constant.
      static const xtd::forms::emoticon face_with_finger_covering_closed_lips;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F92C. This field is constant.
      static const xtd::forms::emoticon serious_face_with_symbols_covering_mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F92D. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_smiling_eyes_and_hand_covering_mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F92E. This field is constant.
      static const xtd::forms::emoticon face_with_open_mouth_vomiting;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F92F. This field is constant.
      static const xtd::forms::emoticon shocked_face_with_exploding_head;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F930. This field is constant.
      static const xtd::forms::emoticon pregnant_woman;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F931. This field is constant.
      static const xtd::forms::emoticon breast_feeding;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F932. This field is constant.
      static const xtd::forms::emoticon palms_up_together;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F933. This field is constant.
      static const xtd::forms::emoticon selfie;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F934. This field is constant.
      static const xtd::forms::emoticon prince;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F935. This field is constant.
      static const xtd::forms::emoticon man_in_tuxedo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F936. This field is constant.
      static const xtd::forms::emoticon mother_christmas;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F937. This field is constant.
      static const xtd::forms::emoticon shrug;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F938. This field is constant.
      static const xtd::forms::emoticon person_doing_cartwheel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F939. This field is constant.
      static const xtd::forms::emoticon juggling;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F93A. This field is constant.
      static const xtd::forms::emoticon fencer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F93C. This field is constant.
      static const xtd::forms::emoticon wrestlers;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F93D. This field is constant.
      static const xtd::forms::emoticon water_polo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F93E. This field is constant.
      static const xtd::forms::emoticon handball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F940. This field is constant.
      static const xtd::forms::emoticon wilted_flower;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F941. This field is constant.
      static const xtd::forms::emoticon drum_with_drumsticks;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F942. This field is constant.
      static const xtd::forms::emoticon clinking_glasses;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F943. This field is constant.
      static const xtd::forms::emoticon tumbler_glass;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F944. This field is constant.
      static const xtd::forms::emoticon spoon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F945. This field is constant.
      static const xtd::forms::emoticon goal_net;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F947. This field is constant.
      static const xtd::forms::emoticon first_place_medal;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F948. This field is constant.
      static const xtd::forms::emoticon second_place_medal;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F949. This field is constant.
      static const xtd::forms::emoticon third_place_medal;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F94A. This field is constant.
      static const xtd::forms::emoticon boxing_glove;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F94B. This field is constant.
      static const xtd::forms::emoticon martial_arts_uniform;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F94C. This field is constant.
      static const xtd::forms::emoticon curling_stone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F94D. This field is constant.
      static const xtd::forms::emoticon lacrosse_stick_and_ball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F94E. This field is constant.
      static const xtd::forms::emoticon softball;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F94F. This field is constant.
      static const xtd::forms::emoticon flying_disc;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F950. This field is constant.
      static const xtd::forms::emoticon croissant;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F951. This field is constant.
      static const xtd::forms::emoticon avocado;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F952. This field is constant.
      static const xtd::forms::emoticon cucumber;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F953. This field is constant.
      static const xtd::forms::emoticon bacon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F954. This field is constant.
      static const xtd::forms::emoticon potato;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F955. This field is constant.
      static const xtd::forms::emoticon carrot;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F956. This field is constant.
      static const xtd::forms::emoticon baguette_bread;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F957. This field is constant.
      static const xtd::forms::emoticon green_salad;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F958. This field is constant.
      static const xtd::forms::emoticon shallow_pan_of_food;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F959. This field is constant.
      static const xtd::forms::emoticon stuffed_flatbread;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F95A. This field is constant.
      static const xtd::forms::emoticon egg;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F95B. This field is constant.
      static const xtd::forms::emoticon glass_of_milk;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F95C. This field is constant.
      static const xtd::forms::emoticon peanuts;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F95D. This field is constant.
      static const xtd::forms::emoticon kiwifruit;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F95E. This field is constant.
      static const xtd::forms::emoticon pancakes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F95F. This field is constant.
      static const xtd::forms::emoticon dumpling;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F960. This field is constant.
      static const xtd::forms::emoticon fortune_cookie;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F961. This field is constant.
      static const xtd::forms::emoticon takeout_box;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F962. This field is constant.
      static const xtd::forms::emoticon chopsticks;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F963. This field is constant.
      static const xtd::forms::emoticon bowl_with_spoon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F964. This field is constant.
      static const xtd::forms::emoticon cup_with_straw;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F965. This field is constant.
      static const xtd::forms::emoticon coconut;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F966. This field is constant.
      static const xtd::forms::emoticon broccoli;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F967. This field is constant.
      static const xtd::forms::emoticon pie;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F968. This field is constant.
      static const xtd::forms::emoticon pretzel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F969. This field is constant.
      static const xtd::forms::emoticon cut_of_meat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F96A. This field is constant.
      static const xtd::forms::emoticon sandwich;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F96B. This field is constant.
      static const xtd::forms::emoticon canned_food;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F96C. This field is constant.
      static const xtd::forms::emoticon leafy_green;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F96D. This field is constant.
      static const xtd::forms::emoticon mango;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F96E. This field is constant.
      static const xtd::forms::emoticon moon_cake;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F96F. This field is constant.
      static const xtd::forms::emoticon bagel;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F970. This field is constant.
      static const xtd::forms::emoticon smiling_face_with_smiling_eyes_and_three_hearts;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F973. This field is constant.
      static const xtd::forms::emoticon face_with_party_horn_and_party_hat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F974. This field is constant.
      static const xtd::forms::emoticon face_with_uneven_eyes_and_wavy_mouth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F975. This field is constant.
      static const xtd::forms::emoticon overheated_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F976. This field is constant.
      static const xtd::forms::emoticon freezing_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F97A. This field is constant.
      static const xtd::forms::emoticon face_with_pleading_eyes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F97C. This field is constant.
      static const xtd::forms::emoticon lab_coat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F97D. This field is constant.
      static const xtd::forms::emoticon goggles;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F97E. This field is constant.
      static const xtd::forms::emoticon hiking_boot;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F97F. This field is constant.
      static const xtd::forms::emoticon flat_shoe;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F980. This field is constant.
      static const xtd::forms::emoticon crab;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F981. This field is constant.
      static const xtd::forms::emoticon lion_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F982. This field is constant.
      static const xtd::forms::emoticon scorpion;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F983. This field is constant.
      static const xtd::forms::emoticon turkey;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F984. This field is constant.
      static const xtd::forms::emoticon unicorn_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F985. This field is constant.
      static const xtd::forms::emoticon eagle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F986. This field is constant.
      static const xtd::forms::emoticon duck;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F987. This field is constant.
      static const xtd::forms::emoticon bat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F988. This field is constant.
      static const xtd::forms::emoticon shark;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F989. This field is constant.
      static const xtd::forms::emoticon owl;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F98A. This field is constant.
      static const xtd::forms::emoticon fox_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F98B. This field is constant.
      static const xtd::forms::emoticon butterfly;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F98C. This field is constant.
      static const xtd::forms::emoticon deer;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F98D. This field is constant.
      static const xtd::forms::emoticon gorilla;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F98E. This field is constant.
      static const xtd::forms::emoticon lizard;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F98F. This field is constant.
      static const xtd::forms::emoticon rhinoceros;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F990. This field is constant.
      static const xtd::forms::emoticon shrimp;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F991. This field is constant.
      static const xtd::forms::emoticon squid;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F992. This field is constant.
      static const xtd::forms::emoticon giraffe_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F993. This field is constant.
      static const xtd::forms::emoticon zebra_face;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F994. This field is constant.
      static const xtd::forms::emoticon hedgehog;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F995. This field is constant.
      static const xtd::forms::emoticon sauropod;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F996. This field is constant.
      static const xtd::forms::emoticon t_rex;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F997. This field is constant.
      static const xtd::forms::emoticon cricket;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F998. This field is constant.
      static const xtd::forms::emoticon kangaroo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F999. This field is constant.
      static const xtd::forms::emoticon llama;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F99A. This field is constant.
      static const xtd::forms::emoticon peacock;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F99B. This field is constant.
      static const xtd::forms::emoticon hippopotamus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F99C. This field is constant.
      static const xtd::forms::emoticon parrot;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F99D. This field is constant.
      static const xtd::forms::emoticon raccoon;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F99E. This field is constant.
      static const xtd::forms::emoticon lobster;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F99F. This field is constant.
      static const xtd::forms::emoticon mosquito;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9A0. This field is constant.
      static const xtd::forms::emoticon microbe;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9A1. This field is constant.
      static const xtd::forms::emoticon badger;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9A2. This field is constant.
      static const xtd::forms::emoticon swan;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B0. This field is constant.
      static const xtd::forms::emoticon emoji_component_red_hair;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B1. This field is constant.
      static const xtd::forms::emoticon emoji_component_curly_hair;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B2. This field is constant.
      static const xtd::forms::emoticon emoji_component_bald;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B3. This field is constant.
      static const xtd::forms::emoticon emoji_component_white_hair;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B4. This field is constant.
      static const xtd::forms::emoticon bone;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B5. This field is constant.
      static const xtd::forms::emoticon leg;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B6. This field is constant.
      static const xtd::forms::emoticon foot;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B7. This field is constant.
      static const xtd::forms::emoticon tooth;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B8. This field is constant.
      static const xtd::forms::emoticon superhero;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9B9. This field is constant.
      static const xtd::forms::emoticon supervillain;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9C0. This field is constant.
      static const xtd::forms::emoticon cheese_wedge;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9C1. This field is constant.
      static const xtd::forms::emoticon cupcake;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9C2. This field is constant.
      static const xtd::forms::emoticon salt_shaker;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D0. This field is constant.
      static const xtd::forms::emoticon face_with_monocle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D1. This field is constant.
      static const xtd::forms::emoticon adult;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D2. This field is constant.
      static const xtd::forms::emoticon child;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D3. This field is constant.
      static const xtd::forms::emoticon older_adult;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D4. This field is constant.
      static const xtd::forms::emoticon bearded_person;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D5. This field is constant.
      static const xtd::forms::emoticon person_with_headscarf;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D6. This field is constant.
      static const xtd::forms::emoticon person_in_steamy_room;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D7. This field is constant.
      static const xtd::forms::emoticon person_climbing;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D8. This field is constant.
      static const xtd::forms::emoticon person_in_lotus_position;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9D9. This field is constant.
      static const xtd::forms::emoticon mage;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9DA. This field is constant.
      static const xtd::forms::emoticon fairy;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9DB. This field is constant.
      static const xtd::forms::emoticon vampire;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9DC. This field is constant.
      static const xtd::forms::emoticon merperson;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9DD. This field is constant.
      static const xtd::forms::emoticon elf;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9DE. This field is constant.
      static const xtd::forms::emoticon genie;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9DF. This field is constant.
      static const xtd::forms::emoticon zombie;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E0. This field is constant.
      static const xtd::forms::emoticon brain;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E1. This field is constant.
      static const xtd::forms::emoticon orange_heart;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E2. This field is constant.
      static const xtd::forms::emoticon billed_cap;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E3. This field is constant.
      static const xtd::forms::emoticon scarf;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E4. This field is constant.
      static const xtd::forms::emoticon gloves;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E5. This field is constant.
      static const xtd::forms::emoticon coat;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E6. This field is constant.
      static const xtd::forms::emoticon socks;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E7. This field is constant.
      static const xtd::forms::emoticon red_gift_envelope;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E8. This field is constant.
      static const xtd::forms::emoticon firecracker;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9E9. This field is constant.
      static const xtd::forms::emoticon jigsaw_puzzle_piece;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9EA. This field is constant.
      static const xtd::forms::emoticon test_tube;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9EB. This field is constant.
      static const xtd::forms::emoticon petri_dish;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9EC. This field is constant.
      static const xtd::forms::emoticon dna_double_helix;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9ED. This field is constant.
      static const xtd::forms::emoticon compass;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9EE. This field is constant.
      static const xtd::forms::emoticon abacus;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9EF. This field is constant.
      static const xtd::forms::emoticon fire_extinguisher;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F0. This field is constant.
      static const xtd::forms::emoticon toolbox;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F1. This field is constant.
      static const xtd::forms::emoticon brick;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F2. This field is constant.
      static const xtd::forms::emoticon magnet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F3. This field is constant.
      static const xtd::forms::emoticon luggage;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F4. This field is constant.
      static const xtd::forms::emoticon lotion_bottle;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F5. This field is constant.
      static const xtd::forms::emoticon spool_of_thread;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F6. This field is constant.
      static const xtd::forms::emoticon ball_of_yarn;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F7. This field is constant.
      static const xtd::forms::emoticon safety_pin;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F8. This field is constant.
      static const xtd::forms::emoticon teddy_bear;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9F9. This field is constant.
      static const xtd::forms::emoticon broom;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9FA. This field is constant.
      static const xtd::forms::emoticon basket;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9FB. This field is constant.
      static const xtd::forms::emoticon roll_of_paper;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9FC. This field is constant.
      static const xtd::forms::emoticon bar_of_soap;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9FD. This field is constant.
      static const xtd::forms::emoticon sponge;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9FE. This field is constant.
      static const xtd::forms::emoticon receipt;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001F9FF. This field is constant.
      static const xtd::forms::emoticon nazar_amulet;
      
      // 1FA70-1F7FF Symbols and Pictographs Extended-A
      
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA70. This field is constant.
      static const xtd::forms::emoticon ballet_shoes;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA71. This field is constant.
      static const xtd::forms::emoticon one_piece_swinsuit;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA72. This field is constant.
      static const xtd::forms::emoticon briefs;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA73. This field is constant.
      static const xtd::forms::emoticon shorts;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA78. This field is constant.
      static const xtd::forms::emoticon drop_of_blood;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA79. This field is constant.
      static const xtd::forms::emoticon adhesive_bandage;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA7A. This field is constant.
      static const xtd::forms::emoticon stethoscope;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA80. This field is constant.
      static const xtd::forms::emoticon yo_yo;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA81. This field is constant.
      static const xtd::forms::emoticon kite;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA82. This field is constant.
      static const xtd::forms::emoticon parachute;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA90. This field is constant.
      static const xtd::forms::emoticon ringed_planet;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA91. This field is constant.
      static const xtd::forms::emoticon chair;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA92. This field is constant.
      static const xtd::forms::emoticon razor;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA93. This field is constant.
      static const xtd::forms::emoticon axe;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA94. This field is constant.
      static const xtd::forms::emoticon diya_lamp;
      /// @brief Gets a system-defined xtd::forms::emoticon that has a string value of 0x0001FA95. This field is constant.
      static const xtd::forms::emoticon banjo;
      
      static const std::vector<xtd::forms::emoticon>& get_emoticons();
    };
  }
}
