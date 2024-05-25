/// @file
/// @brief Contains xtd::forms::shortcut enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "keys.h"
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies shortcut keys that can be used by menu items.
    /// @par Header
    /// @code #include <xtd/forms/shortcut> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks Use the members of this enumeration to set the value of the xtd::forms::menu_item::shortcut property of the xtd::forms::menu_item class.
    /// @remarks On Apple platforms, references to xtd::forms::keys::control_key and xtd::forms::keys::control correspond to the `command` keys on the Macintosh keyboard, and references to xtd::forms::keys::lwin, xtd::forms::keys::rwin and xtd::forms::keys::meta correspond to the `control` keys. In effect, developers can use the same shortcut descriptions across all platforms, and their applications will automatically work as expected on Apple platforms.
    enum class shortcut {
      /// @brief The shortcut keys ALT+0.
      alt_0 = 0x00040030,
      /// @brief The shortcut keys ALT+1.
      alt_1,
      /// @brief The shortcut keys ALT+2.
      alt_2,
      /// @brief The shortcut keys ALT+3.
      alt_3,
      /// @brief The shortcut keys ALT+4.
      alt_4,
      /// @brief The shortcut keys ALT+5.
      alt_5,
      /// @brief The shortcut keys ALT+6.
      alt_6,
      /// @brief The shortcut keys ALT+7.
      alt_7,
      /// @brief The shortcut keys ALT+8.
      alt_8,
      /// @brief The shortcut keys ALT+9.
      alt_9,
      /// @brief The shortcut keys ALT+BACKSPACE.
      alt_bksp = 0x00040008,
      /// @brief The shortcut keys ALT+DOWNARROW.
      alt_down_arrow = 0x00040028,
      /// @brief The shortcut keys ALT+F1.
      alt_f1 = 0x00040070,
      /// @brief The shortcut keys ALT+F10.
      alt_f10 = 0x00040079,
      /// @brief The shortcut keys ALT+F11.
      alt_f11,
      /// @brief The shortcut keys ALT+F12.
      alt_f12,
      /// @brief The shortcut keys ALT+F2.
      alt_f2 = 0x00040071,
      /// @brief The shortcut keys ALT+F3.
      alt_f3,
      /// @brief The shortcut keys ALT+F4.
      alt_f4,
      /// @brief The shortcut keys ALT+F5.
      alt_f5,
      /// @brief The shortcut keys ALT+F6.
      alt_f6,
      /// @brief The shortcut keys ALT+F7.
      alt_f7,
      /// @brief The shortcut keys ALT+F8.
      alt_f8,
      /// @brief The shortcut keys ALT+F9.
      alt_f9,
      /// @brief The shortcut keys ALT+LEFTARROW.
      alt_left_arrow = 0x00040025,
      /// @brief The shortcut keys ALT+RIGHTARROW.
      alt_right_arrow = 0x00040027,
      /// @brief The shortcut keys ALT+UPARROW.
      alt_up_arrow = 0x00040026,
      /// @brief The shortcut keys CTRL+0.
      ctrl_0 = 0x00020030,
      /// @brief The shortcut keys CTRL+1.
      ctrl_1,
      /// @brief The shortcut keys CTRL+2.
      ctrl_2,
      /// @brief The shortcut keys CTRL+3.
      ctrl_3,
      /// @brief The shortcut keys CTRL+4.
      ctrl_4,
      /// @brief The shortcut keys CTRL+5.
      ctrl_5,
      /// @brief The shortcut keys CTRL+6.
      ctrl_6,
      /// @brief The shortcut keys CTRL+7.
      ctrl_7,
      /// @brief The shortcut keys CTRL+8.
      ctrl_8,
      /// @brief The shortcut keys CTRL+9.
      ctrl_9,
      /// @brief The shortcut keys CTRL+A.
      ctrl_a = 0x00020041,
      /// @brief The shortcut keys CTRL+B.
      ctrl_b,
      /// @brief The shortcut keys CTRL+C.
      ctrl_c,
      /// @brief The shortcut keys CTRL+D.
      ctrl_d,
      /// @brief The shortcut keys CTRL+DELETE.
      ctrl_del = 0x0002002E,
      /// @brief The shortcut keys CTRL+E.
      ctrl_e = 0x00020045,
      /// @brief The shortcut keys CTRL+F.
      ctrl_f,
      /// @brief The shortcut keys CTRL+F1.
      ctrl_f1 = 0x00020070,
      /// @brief The shortcut keys CTRL+F10.
      ctrl_f10 = 0x00020079,
      /// @brief The shortcut keys CTRL+F11.
      ctrl_f11,
      /// @brief The shortcut keys CTRL+F12.
      ctrl_f12,
      /// @brief The shortcut keys CTRL+F2.
      ctrl_f2 = 0x00020071,
      /// @brief The shortcut keys CTRL+F3.
      ctrl_f3,
      /// @brief The shortcut keys CTRL+F4.
      ctrl_f4,
      /// @brief The shortcut keys CTRL+F5.
      ctrl_f5,
      /// @brief The shortcut keys CTRL+F6.
      ctrl_f6,
      /// @brief The shortcut keys CTRL+F7.
      ctrl_f7,
      /// @brief The shortcut keys CTRL+F8.
      ctrl_f8,
      /// @brief The shortcut keys CTRL+F9.
      ctrl_f9,
      /// @brief The shortcut keys CTRL+G.
      ctrl_g = 0x00020047,
      /// @brief The shortcut keys CTRL+H.
      ctrl_h,
      /// @brief The shortcut keys CTRL+I.
      ctrl_i,
      /// @brief The shortcut keys CTRL+INSERT.
      ctrl_ins = 0x0002002D,
      /// @brief The shortcut keys CTRL+J.
      ctrl_j = 0x0002004A,
      /// @brief The shortcut keys CTRL+K.
      ctrl_k,
      /// @brief The shortcut keys CTRL+L.
      ctrl_l,
      /// @brief The shortcut keys CTRL+M.
      ctrl_m,
      /// @brief The shortcut keys CTRL+N.
      ctrl_n,
      /// @brief The shortcut keys CTRL+O.
      ctrl_o,
      /// @brief The shortcut keys CTRL+P.
      ctrl_p,
      /// @brief The shortcut keys CTRL+Q.
      ctrl_q,
      /// @brief The shortcut keys CTRL+R.
      ctrl_r,
      /// @brief The shortcut keys CTRL+S.
      ctrl_s,
      /// @brief The shortcut keys CTRL+SHIFT+0.
      ctrl_shift_0 = 0x00030030,
      /// @brief The shortcut keys CTRL+SHIFT+1.
      ctrl_shift_1,
      /// @brief The shortcut keys CTRL+SHIFT+2.
      ctrl_shift_2,
      /// @brief The shortcut keys CTRL+SHIFT+3.
      ctrl_shift_3,
      /// @brief The shortcut keys CTRL+SHIFT+4.
      ctrl_shift_4,
      /// @brief The shortcut keys CTRL+SHIFT+5.
      ctrl_shift_5,
      /// @brief The shortcut keys CTRL+SHIFT+6.
      ctrl_shift_6,
      /// @brief The shortcut keys CTRL+SHIFT+7.
      ctrl_shift_7,
      /// @brief The shortcut keys CTRL+SHIFT+8.
      ctrl_shift_8,
      /// @brief The shortcut keys CTRL+SHIFT+9.
      ctrl_shift_9,
      /// @brief The shortcut keys CTRL+SHIFT+A.
      ctrl_shift_a = 0x00030041,
      /// @brief The shortcut keys CTRL+SHIFT+B.
      ctrl_shift_b,
      /// @brief The shortcut keys CTRL+SHIFT+C.
      ctrl_shift_c,
      /// @brief The shortcut keys CTRL+SHIFT+D.
      ctrl_shift_d,
      /// @brief The shortcut keys CTRL+SHIFT+E.
      ctrl_shift_e,
      /// @brief The shortcut keys CTRL+SHIFT+F.
      ctrl_shift_f,
      /// @brief The shortcut keys CTRL+SHIFT+F1.
      ctrl_shift_f1 = 0x00030070,
      /// @brief The shortcut keys CTRL+SHIFT+F10.
      ctrl_shift_f10 = 0x00030079,
      /// @brief The shortcut keys CTRL+SHIFT+F11.
      ctrl_shift_f11,
      /// @brief The shortcut keys CTRL+SHIFT+F12.
      ctrl_shift_f12,
      /// @brief The shortcut keys CTRL+SHIFT+F2.
      ctrl_shift_f2 = 0x00030071,
      /// @brief The shortcut keys CTRL+SHIFT+F3.
      ctrl_shift_f3,
      /// @brief The shortcut keys CTRL+SHIFT+F4.
      ctrl_shift_f4,
      /// @brief The shortcut keys CTRL+SHIFT+F5.
      ctrl_shift_f5,
      /// @brief The shortcut keys CTRL+SHIFT+F6.
      ctrl_shift_f6,
      /// @brief The shortcut keys CTRL+SHIFT+F7.
      ctrl_shift_f7,
      /// @brief The shortcut keys CTRL+SHIFT+F8.
      ctrl_shift_f8,
      /// @brief The shortcut keys CTRL+SHIFT+F9.
      ctrl_shift_f9,
      /// @brief The shortcut keys CTRL+SHIFT+G.
      ctrl_shift_g = 0x00030047,
      /// @brief The shortcut keys CTRL+SHIFT+H.
      ctrl_shift_h,
      /// @brief The shortcut keys CTRL+SHIFT+I.
      ctrl_shift_i,
      /// @brief The shortcut keys CTRL+SHIFT+J.
      ctrl_shift_j,
      /// @brief The shortcut keys CTRL+SHIFT+K.
      ctrl_shift_k,
      /// @brief The shortcut keys CTRL+SHIFT+L.
      ctrl_shift_l,
      /// @brief The shortcut keys CTRL+SHIFT+M.
      ctrl_shift_m,
      /// @brief The shortcut keys CTRL+SHIFT+N.
      ctrl_shift_n,
      /// @brief The shortcut keys CTRL+SHIFT+O.
      ctrl_shift_o,
      /// @brief The shortcut keys CTRL+SHIFT+P.
      ctrl_shift_p,
      /// @brief The shortcut keys CTRL+SHIFT+Q.
      ctrl_shift_q,
      /// @brief The shortcut keys CTRL+SHIFT+R.
      ctrl_shift_r,
      /// @brief The shortcut keys CTRL+SHIFT+S.
      ctrl_shift_s,
      /// @brief The shortcut keys CTRL+SHIFT+T.
      ctrl_shift_t,
      /// @brief The shortcut keys CTRL+SHIFT+U.
      ctrl_shift_u,
      /// @brief The shortcut keys CTRL+SHIFT+V.
      ctrl_shift_v,
      /// @brief The shortcut keys CTRL+SHIFT+W.
      ctrl_shift_w,
      /// @brief The shortcut keys CTRL+SHIFT+X.
      ctrl_shift_x,
      /// @brief The shortcut keys CTRL+SHIFT+Y.
      ctrl_shift_y,
      /// @brief The shortcut keys CTRL+SHIFT+Z.
      ctrl_shift_z,
      /// @brief The shortcut keys CTRL+T.
      ctrl_t = 0x00020054,
      /// @brief The shortcut keys CTRL+U.
      ctrl_u,
      /// @brief The shortcut keys CTRL+V.
      ctrl_v,
      /// @brief The shortcut keys CTRL+W.
      ctrl_w,
      /// @brief The shortcut keys CTRL+X.
      ctrl_x,
      /// @brief The shortcut keys CTRL+Y.
      ctrl_y,
      /// @brief The shortcut keys CTRL+Z.
      ctrl_z,
      /// @brief The shortcut keys DELETE.
      del = 0x0000002E,
      /// @brief The shortcut keys F1.
      f1 = 0x00000070,
      /// @brief The shortcut keys F10.
      f10 = 0x00000079,
      /// @brief The shortcut keys F11.
      f11,
      /// @brief The shortcut keys F12.
      f12,
      /// @brief The shortcut keys F2.
      f2 = 0x00000071,
      /// @brief The shortcut keys F3.
      f3,
      /// @brief The shortcut keys F4.
      f4,
      /// @brief The shortcut keys F5.
      f5,
      /// @brief The shortcut keys F6.
      f6,
      /// @brief The shortcut keys F7.
      f7,
      /// @brief The shortcut keys F8.
      f8,
      /// @brief The shortcut keys F9.
      f9,
      /// @brief The shortcut keys INSERT.
      ins = 0x0000002D,
      /// @brief No shortcut key is associated with the menu item.
      none = 0,
      /// @brief The shortcut keys SHIFT+DELETE.
      shift_del = 0x0001002E,
      /// @brief The shortcut keys SHIFT+F1.
      shift_f1 = 0x00010070,
      /// @brief The shortcut keys SHIFT+F10.
      shift_f10 = 0x00010079,
      /// @brief The shortcut keys SHIFT+11.
      shift_f11,
      /// @brief The shortcut keys SHIFT+F12.
      shift_f12,
      /// @brief The shortcut keys SHIFT+F2.
      shift_f2 = 0x00010071,
      /// @brief The shortcut keys SHIFT+F3.
      shift_f3,
      /// @brief The shortcut keys SHIFT+F4.
      shift_f4,
      /// @brief The shortcut keys SHIFT+F5.
      shift_f5,
      /// @brief The shortcut keys SHIFT+F6.
      shift_f6,
      /// @brief The shortcut keys SHIFT+F7.
      shift_f7,
      /// @brief The shortcut keys SHIFT+F8.
      shift_f8,
      /// @brief The shortcut keys SHIFT+F9.
      shift_f9,
      /// @brief The shortcut keys SHIFT+INSERT.
      shift_ins = 0x0001002D,
      /// @brief The shortcut keys CMD+0.
      cmd_0 = ctrl_0,
      /// @brief The shortcut keys CMD+1.
      cmd_1 = ctrl_1,
      /// @brief The shortcut keys CMD+2.
      cmd_2 = ctrl_2,
      /// @brief The shortcut keys CMD+3.
      cmd_3 = ctrl_3,
      /// @brief The shortcut keys CMD+4.
      cmd_4 = ctrl_4,
      /// @brief The shortcut keys CMD+5.
      cmd_5 = ctrl_5,
      /// @brief The shortcut keys CMD+6.
      cmd_6 = ctrl_6,
      /// @brief The shortcut keys CMD+7.
      cmd_7 = ctrl_7,
      /// @brief The shortcut keys CMD+8.
      cmd_8 = ctrl_8,
      /// @brief The shortcut keys CMD+9.
      cmd_9 = ctrl_9,
      /// @brief The shortcut keys CMD+A.
      cmd_a = ctrl_a,
      /// @brief The shortcut keys CMD+B.
      cmd_b = ctrl_b,
      /// @brief The shortcut keys CMD+C.
      cmd_c = ctrl_c,
      /// @brief The shortcut keys CMD+D.
      cmd_d = ctrl_d,
      /// @brief The shortcut keys CMD+DELETE.
      cmd_del = ctrl_del,
      /// @brief The shortcut keys CMD+E.
      cmd_e = ctrl_e,
      /// @brief The shortcut keys CMD+F.
      cmd_f = ctrl_f,
      /// @brief The shortcut keys CMD+F1.
      cmd_f1 = ctrl_f1,
      /// @brief The shortcut keys CMD+F10.
      cmd_f10 = ctrl_f10,
      /// @brief The shortcut keys CMD+F11.
      cmd_f11 = ctrl_f11,
      /// @brief The shortcut keys CMD+F12.
      cmd_f12 = ctrl_f12,
      /// @brief The shortcut keys CMD+F2.
      cmd_f2 = ctrl_f2,
      /// @brief The shortcut keys CMD+F3.
      cmd_f3 = ctrl_f3,
      /// @brief The shortcut keys CMD+F4.
      cmd_f4 = ctrl_f4,
      /// @brief The shortcut keys CMD+F5.
      cmd_f5 = ctrl_f4,
      /// @brief The shortcut keys CMD+F6.
      cmd_f6 = ctrl_f6,
      /// @brief The shortcut keys CMD+F7.
      cmd_f7 = ctrl_f7,
      /// @brief The shortcut keys CMD+F8.
      cmd_f8 = ctrl_f8,
      /// @brief The shortcut keys CMD+F9.
      cmd_f9 = ctrl_f9,
      /// @brief The shortcut keys CMD+G.
      cmd_g = ctrl_g,
      /// @brief The shortcut keys CMD+H.
      cmd_h = ctrl_h,
      /// @brief The shortcut keys CMD+I.
      cmd_i = ctrl_i,
      /// @brief The shortcut keys CMD+INSERT.
      cmd_ins = ctrl_ins,
      /// @brief The shortcut keys CMD+J.
      cmd_j = ctrl_j,
      /// @brief The shortcut keys CMD+K.
      cmd_k = ctrl_k,
      /// @brief The shortcut keys CMD+L.
      cmd_l = ctrl_l,
      /// @brief The shortcut keys CMD+M.
      cmd_m = ctrl_m,
      /// @brief The shortcut keys CMD+N.
      cmd_n = ctrl_n,
      /// @brief The shortcut keys CMD+O.
      cmd_o = ctrl_o,
      /// @brief The shortcut keys CMD+P.
      cmd_p = ctrl_p,
      /// @brief The shortcut keys CMD+Q.
      cmd_q = ctrl_q,
      /// @brief The shortcut keys CMD+R.
      cmd_r = ctrl_r,
      /// @brief The shortcut keys CMD+S.
      cmd_s = ctrl_s,
      /// @brief The shortcut keys CMD+SHIFT+0.
      cmd_shift_0 = ctrl_shift_0,
      /// @brief The shortcut keys CMD+SHIFT+1.
      cmd_shift_1 = ctrl_shift_1,
      /// @brief The shortcut keys CMD+SHIFT+2.
      cmd_shift_2 = ctrl_shift_2,
      /// @brief The shortcut keys CMD+SHIFT+3.
      cmd_shift_3 = ctrl_shift_3,
      /// @brief The shortcut keys CMD+SHIFT+4.
      cmd_shift_4 = ctrl_shift_4,
      /// @brief The shortcut keys CMD+SHIFT+5.
      cmd_shift_5 = ctrl_shift_5,
      /// @brief The shortcut keys CMD+SHIFT+6.
      cmd_shift_6 = ctrl_shift_6,
      /// @brief The shortcut keys CMD+SHIFT+7.
      cmd_shift_7 = ctrl_shift_7,
      /// @brief The shortcut keys CMD+SHIFT+8.
      cmd_shift_8 = ctrl_shift_8,
      /// @brief The shortcut keys CMD+SHIFT+9.
      cmd_shift_9 = ctrl_shift_9,
      /// @brief The shortcut keys CMD+SHIFT+A.
      cmd_shift_a = ctrl_shift_a,
      /// @brief The shortcut keys CMD+SHIFT+B.
      cmd_shift_b = ctrl_shift_b,
      /// @brief The shortcut keys CMD+SHIFT+C.
      cmd_shift_c = ctrl_shift_c,
      /// @brief The shortcut keys CMD+SHIFT+D.
      cmd_shift_d = ctrl_shift_d,
      /// @brief The shortcut keys CMD+SHIFT+E.
      cmd_shift_e = ctrl_shift_e,
      /// @brief The shortcut keys CMD+SHIFT+F.
      cmd_shift_f = ctrl_shift_f,
      /// @brief The shortcut keys CMD+SHIFT+F1.
      cmd_shift_f1 = ctrl_shift_f1,
      /// @brief The shortcut keys CMD+SHIFT+F10.
      cmd_shift_f10 = ctrl_shift_f10,
      /// @brief The shortcut keys CMD+SHIFT+F11.
      cmd_shift_f11 = ctrl_shift_f11,
      /// @brief The shortcut keys CMD+SHIFT+F12.
      cmd_shift_f12 = ctrl_shift_f12,
      /// @brief The shortcut keys CMD+SHIFT+F2.
      cmd_shift_f2 = ctrl_shift_f2,
      /// @brief The shortcut keys CMD+SHIFT+F3.
      cmd_shift_f3 = ctrl_shift_f3,
      /// @brief The shortcut keys CMD+SHIFT+F4.
      cmd_shift_f4 = ctrl_shift_f4,
      /// @brief The shortcut keys CMD+SHIFT+F5.
      cmd_shift_f5 = ctrl_shift_f5,
      /// @brief The shortcut keys CMD+SHIFT+F6.
      cmd_shift_f6 = ctrl_shift_f6,
      /// @brief The shortcut keys CMD+SHIFT+F7.
      cmd_shift_f7 = ctrl_shift_f7,
      /// @brief The shortcut keys CMD+SHIFT+F8.
      cmd_shift_f8 = ctrl_shift_f8,
      /// @brief The shortcut keys CMD+SHIFT+F9.
      cmd_shift_f9 = ctrl_shift_f9,
      /// @brief The shortcut keys CMD+SHIFT+G.
      cmd_shift_g = ctrl_shift_g,
      /// @brief The shortcut keys CMD+SHIFT+H.
      cmd_shift_h = ctrl_shift_h,
      /// @brief The shortcut keys CMD+SHIFT+I.
      cmd_shift_i = ctrl_shift_i,
      /// @brief The shortcut keys CMD+SHIFT+J.
      cmd_shift_j = ctrl_shift_j,
      /// @brief The shortcut keys CMD+SHIFT+K.
      cmd_shift_k = ctrl_shift_k,
      /// @brief The shortcut keys CMD+SHIFT+L.
      cmd_shift_l = ctrl_shift_l,
      /// @brief The shortcut keys CMD+SHIFT+M.
      cmd_shift_m = ctrl_shift_m,
      /// @brief The shortcut keys CMD+SHIFT+N.
      cmd_shift_n = ctrl_shift_n,
      /// @brief The shortcut keys CMD+SHIFT+O.
      cmd_shift_o = ctrl_shift_o,
      /// @brief The shortcut keys CMD+SHIFT+P.
      cmd_shift_p = ctrl_shift_p,
      /// @brief The shortcut keys CMD+SHIFT+Q.
      cmd_shift_q = ctrl_shift_q,
      /// @brief The shortcut keys CMD+SHIFT+R.
      cmd_shift_r = ctrl_shift_r,
      /// @brief The shortcut keys CMD+SHIFT+S.
      cmd_shift_s = ctrl_shift_s,
      /// @brief The shortcut keys CMD+SHIFT+T.
      cmd_shift_t = ctrl_shift_t,
      /// @brief The shortcut keys CMD+SHIFT+U.
      cmd_shift_u = ctrl_shift_u,
      /// @brief The shortcut keys CMD+SHIFT+V.
      cmd_shift_v = ctrl_shift_v,
      /// @brief The shortcut keys CMD+SHIFT+W.
      cmd_shift_w = ctrl_shift_w,
      /// @brief The shortcut keys CMD+SHIFT+X.
      cmd_shift_x = ctrl_shift_x,
      /// @brief The shortcut keys CMD+SHIFT+Y.
      cmd_shift_y = ctrl_shift_y,
      /// @brief The shortcut keys CMD+SHIFT+Z.
      cmd_shift_z = ctrl_shift_z,
      /// @brief The shortcut keys CMD+T.
      cmd_t = ctrl_t,
      /// @brief The shortcut keys CMD+U.
      cmd_u = ctrl_u,
      /// @brief The shortcut keys CMD+V.
      cmd_v = ctrl_v,
      /// @brief The shortcut keys CMD+W.
      cmd_w = ctrl_w,
      /// @brief The shortcut keys CMD+X.
      cmd_x = ctrl_x,
      /// @brief The shortcut keys CMD+Y.
      cmd_ = ctrl_y,
      /// @brief The shortcut keys CMD+Z.
      cmd_z = ctrl_z,
      /// @brief The shortcut keys ALT+0.
      opt_0 = alt_0,
      /// @brief The shortcut keys ALT+1.
      opt_1 = alt_1,
      /// @brief The shortcut keys ALT+2.
      opt_2 = alt_2,
      /// @brief The shortcut keys ALT+3.
      opt_3 = alt_3,
      /// @brief The shortcut keys ALT+4.
      opt_4 = alt_4,
      /// @brief The shortcut keys ALT+5.
      opt_5 = alt_5,
      /// @brief The shortcut keys ALT+6.
      opt_6 = alt_6,
      /// @brief The shortcut keys ALT+7.
      opt_7 = alt_7,
      /// @brief The shortcut keys ALT+8.
      opt_8 = alt_8,
      /// @brief The shortcut keys ALT+9.
      opt_9 = alt_9,
      /// @brief The shortcut keys ALT+BACKSPACE.
      opt_bksp = alt_bksp,
      /// @brief The shortcut keys ALT+DOWNARROW.
      opt_down_arrow = alt_down_arrow,
      /// @brief The shortcut keys ALT+F1.
      opt_f1 = alt_f1,
      /// @brief The shortcut keys ALT+F10.
      opt_f10 = alt_f10,
      /// @brief The shortcut keys ALT+F11.
      opt_f11 = alt_f11,
      /// @brief The shortcut keys ALT+F12.
      opt_f12 = alt_f12,
      /// @brief The shortcut keys ALT+F2.
      opt_f2 = alt_f2,
      /// @brief The shortcut keys ALT+F3.
      opt_f3 = alt_f3,
      /// @brief The shortcut keys ALT+F4.
      opt_f4 = alt_f4,
      /// @brief The shortcut keys ALT+F5.
      opt_f5 = alt_f5,
      /// @brief The shortcut keys ALT+F6.
      opt_f6 = alt_f6,
      /// @brief The shortcut keys ALT+F7.
      opt_f7 = alt_f7,
      /// @brief The shortcut keys ALT+F8.
      opt_f8 = alt_f8,
      /// @brief The shortcut keys ALT+F9.
      opt_f9 = alt_f9,
      /// @brief The shortcut keys ALT+LEFTARROW.
      opt_left_arrow = alt_left_arrow,
      /// @brief The shortcut keys ALT+RIGHTARROW.
      opt_right_arrow = alt_right_arrow,
      /// @brief The shortcut keys ALT+UPARROW.
      opt_up_arrow = alt_up_arrow,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::shortcut> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::shortcut> {{xtd::forms::shortcut::alt_0, "alt_0"}, {xtd::forms::shortcut::alt_1, "alt_1"}, {xtd::forms::shortcut::alt_2, "alt_2"}, {xtd::forms::shortcut::alt_3, "alt_3"}, {xtd::forms::shortcut::alt_4, "alt_4"}, {xtd::forms::shortcut::alt_5, "alt_5"}, {xtd::forms::shortcut::alt_6, "alt_6"}, {xtd::forms::shortcut::alt_7, "alt_7"}, {xtd::forms::shortcut::alt_8, "alt_8"}, {xtd::forms::shortcut::alt_9, "alt_9"}, {xtd::forms::shortcut::alt_bksp, "alt_bksp"}, {xtd::forms::shortcut::alt_down_arrow, "alt_down_arrow"}, {xtd::forms::shortcut::alt_f1, "alt_f1"}, {xtd::forms::shortcut::alt_f10, "alt_f10"}, {xtd::forms::shortcut::alt_f11, "alt_f11"}, {xtd::forms::shortcut::alt_f12, "alt_f12"}, {xtd::forms::shortcut::alt_f2, "alt_f2"}, {xtd::forms::shortcut::alt_f3, "alt_f3"}, {xtd::forms::shortcut::alt_f4, "alt_f4"}, {xtd::forms::shortcut::alt_f5, "alt_f5"}, {xtd::forms::shortcut::alt_f6, "alt_f6"}, {xtd::forms::shortcut::alt_f7, "alt_f7"}, {xtd::forms::shortcut::alt_f8, "alt_f8"}, {xtd::forms::shortcut::alt_f9, "alt_f9"}, {xtd::forms::shortcut::alt_left_arrow, "alt_left_arrow"}, {xtd::forms::shortcut::alt_right_arrow, "alt_right_arrow"}, {xtd::forms::shortcut::alt_up_arrow, "alt_up_arrow"}, {xtd::forms::shortcut::ctrl_0, "ctrl_0"}, {xtd::forms::shortcut::ctrl_1, "ctrl_1"}, {xtd::forms::shortcut::ctrl_2, "ctrl_2"}, {xtd::forms::shortcut::ctrl_3, "ctrl_3"}, {xtd::forms::shortcut::ctrl_4, "ctrl_4"}, {xtd::forms::shortcut::ctrl_5, "ctrl_5"}, {xtd::forms::shortcut::ctrl_6, "ctrl_6"}, {xtd::forms::shortcut::ctrl_7, "ctrl_7"}, {xtd::forms::shortcut::ctrl_8, "ctrl_8"}, {xtd::forms::shortcut::ctrl_9, "ctrl_9"}, {xtd::forms::shortcut::ctrl_a, "ctrl_a"}, {xtd::forms::shortcut::ctrl_b, "ctrl_b"}, {xtd::forms::shortcut::ctrl_c, "ctrl_c"}, {xtd::forms::shortcut::ctrl_d, "ctrl_d"}, {xtd::forms::shortcut::ctrl_del, "ctrl_del"}, {xtd::forms::shortcut::ctrl_e, "ctrl_e"}, {xtd::forms::shortcut::ctrl_f, "ctrl_f"}, {xtd::forms::shortcut::ctrl_f1, "ctrl_f1"}, {xtd::forms::shortcut::ctrl_f10, "ctrl_f10"}, {xtd::forms::shortcut::ctrl_f11, "ctrl_f11"}, {xtd::forms::shortcut::ctrl_f12, "ctrl_f12"}, {xtd::forms::shortcut::ctrl_f2, "ctrl_f2"}, {xtd::forms::shortcut::ctrl_f3, "ctrl_f3"}, {xtd::forms::shortcut::ctrl_f4, "ctrl_f4"}, {xtd::forms::shortcut::ctrl_f5, "ctrl_f5"}, {xtd::forms::shortcut::ctrl_f6, "ctrl_f6"}, {xtd::forms::shortcut::ctrl_f7, "ctrl_f7"}, {xtd::forms::shortcut::ctrl_f8, "ctrl_f8"}, {xtd::forms::shortcut::ctrl_f9, "ctrl_f9"}, {xtd::forms::shortcut::ctrl_g, "ctrl_g"}, {xtd::forms::shortcut::ctrl_h, "ctrl_h"}, {xtd::forms::shortcut::ctrl_i, "ctrl_i"}, {xtd::forms::shortcut::ctrl_ins, "ctrl_ins"}, {xtd::forms::shortcut::ctrl_j, "ctrl_j"}, {xtd::forms::shortcut::ctrl_k, "ctrl_k"}, {xtd::forms::shortcut::ctrl_l, "ctrl_l"}, {xtd::forms::shortcut::ctrl_m, "ctrl_m"}, {xtd::forms::shortcut::ctrl_n, "ctrl_n"}, {xtd::forms::shortcut::ctrl_o, "ctrl_o"}, {xtd::forms::shortcut::ctrl_p, "ctrl_p"}, {xtd::forms::shortcut::ctrl_q, "ctrl_q"}, {xtd::forms::shortcut::ctrl_r, "ctrl_r"}, {xtd::forms::shortcut::ctrl_s, "ctrl_s"}, {xtd::forms::shortcut::ctrl_shift_0, "ctrl_shift_0"}, {xtd::forms::shortcut::ctrl_shift_1, "ctrl_shift_1"}, {xtd::forms::shortcut::ctrl_shift_2, "ctrl_shift_2"}, {xtd::forms::shortcut::ctrl_shift_3, "ctrl_shift_3"}, {xtd::forms::shortcut::ctrl_shift_4, "ctrl_shift_4"}, {xtd::forms::shortcut::ctrl_shift_5, "ctrl_shift_5"}, {xtd::forms::shortcut::ctrl_shift_6, "ctrl_shift_6"}, {xtd::forms::shortcut::ctrl_shift_7, "ctrl_shift_7"}, {xtd::forms::shortcut::ctrl_shift_8, "ctrl_shift_8"}, {xtd::forms::shortcut::ctrl_shift_9, "ctrl_shift_9"}, {xtd::forms::shortcut::ctrl_shift_a, "ctrl_shift_a"}, {xtd::forms::shortcut::ctrl_shift_b, "ctrl_shift_b"}, {xtd::forms::shortcut::ctrl_shift_c, "ctrl_shift_c"}, {xtd::forms::shortcut::ctrl_shift_d, "ctrl_shift_d"}, {xtd::forms::shortcut::ctrl_shift_e, "ctrl_shift_e"}, {xtd::forms::shortcut::ctrl_shift_f, "ctrl_shift_f"}, {xtd::forms::shortcut::ctrl_shift_f1, "ctrl_shift_f1"}, {xtd::forms::shortcut::ctrl_shift_f10, "ctrl_shift_f10"}, {xtd::forms::shortcut::ctrl_shift_f11, "ctrl_shift_f11"}, {xtd::forms::shortcut::ctrl_shift_f12, "ctrl_shift_f12"}, {xtd::forms::shortcut::ctrl_shift_f2, "ctrl_shift_f2"}, {xtd::forms::shortcut::ctrl_shift_f3, "ctrl_shift_f3"}, {xtd::forms::shortcut::ctrl_shift_f4, "ctrl_shift_f4"}, {xtd::forms::shortcut::ctrl_shift_f5, "ctrl_shift_f5"}, {xtd::forms::shortcut::ctrl_shift_f6, "ctrl_shift_f6"}, {xtd::forms::shortcut::ctrl_shift_f7, "ctrl_shift_f7"}, {xtd::forms::shortcut::ctrl_shift_f8, "ctrl_shift_f8"}, {xtd::forms::shortcut::ctrl_shift_f9, "ctrl_shift_f9"}, {xtd::forms::shortcut::ctrl_shift_g, "ctrl_shift_g"}, {xtd::forms::shortcut::ctrl_shift_h, "ctrl_shift_h"}, {xtd::forms::shortcut::ctrl_shift_i, "ctrl_shift_i"}, {xtd::forms::shortcut::ctrl_shift_j, "ctrl_shift_j"}, {xtd::forms::shortcut::ctrl_shift_k, "ctrl_shift_k"}, {xtd::forms::shortcut::ctrl_shift_l, "ctrl_shift_l"}, {xtd::forms::shortcut::ctrl_shift_m, "ctrl_shift_m"}, {xtd::forms::shortcut::ctrl_shift_n, "ctrl_shift_n"}, {xtd::forms::shortcut::ctrl_shift_o, "ctrl_shift_o"}, {xtd::forms::shortcut::ctrl_shift_p, "ctrl_shift_p"}, {xtd::forms::shortcut::ctrl_shift_q, "ctrl_shift_q"}, {xtd::forms::shortcut::ctrl_shift_r, "ctrl_shift_r"}, {xtd::forms::shortcut::ctrl_shift_s, "ctrl_shift_s"}, {xtd::forms::shortcut::ctrl_shift_t, "ctrl_shift_t"}, {xtd::forms::shortcut::ctrl_shift_u, "ctrl_shift_u"}, {xtd::forms::shortcut::ctrl_shift_v, "ctrl_shift_v"}, {xtd::forms::shortcut::ctrl_shift_w, "ctrl_shift_w"}, {xtd::forms::shortcut::ctrl_shift_x, "ctrl_shift_x"}, {xtd::forms::shortcut::ctrl_shift_y, "ctrl_shift_y"}, {xtd::forms::shortcut::ctrl_shift_z, "ctrl_shift_z"}, {xtd::forms::shortcut::ctrl_t, "ctrl_t"}, {xtd::forms::shortcut::ctrl_u, "ctrl_u"}, {xtd::forms::shortcut::ctrl_v, "ctrl_v"}, {xtd::forms::shortcut::ctrl_w, "ctrl_w"}, {xtd::forms::shortcut::ctrl_x, "ctrl_x"}, {xtd::forms::shortcut::ctrl_y, "ctrl_y"}, {xtd::forms::shortcut::ctrl_z, "ctrl_z"}, {xtd::forms::shortcut::del, "del"}, {xtd::forms::shortcut::f1, "f1"}, {xtd::forms::shortcut::f10, "f10"}, {xtd::forms::shortcut::f11, "f11"}, {xtd::forms::shortcut::f12, "f12"}, {xtd::forms::shortcut::f2, "f2"}, {xtd::forms::shortcut::f3, "f3"}, {xtd::forms::shortcut::f4, "f4"}, {xtd::forms::shortcut::f5, "f5"}, {xtd::forms::shortcut::f6, "f6"}, {xtd::forms::shortcut::f7, "f7"}, {xtd::forms::shortcut::f8, "f8"}, {xtd::forms::shortcut::f9, "f9"}, {xtd::forms::shortcut::ins, "ins"}, {xtd::forms::shortcut::shift_del, "shift_del"}, {xtd::forms::shortcut::shift_f1, "shift_f1"}, {xtd::forms::shortcut::shift_f10, "shift_f10"}, {xtd::forms::shortcut::shift_f11, "shift_f11"}, {xtd::forms::shortcut::shift_f12, "shift_f12"}, {xtd::forms::shortcut::shift_f2, "shift_f2"}, {xtd::forms::shortcut::shift_f3, "shift_f3"}, {xtd::forms::shortcut::shift_f4, "shift_f4"}, {xtd::forms::shortcut::shift_f5, "shift_f5"}, {xtd::forms::shortcut::shift_f6, "shift_f6"}, {xtd::forms::shortcut::shift_f7, "shift_f7"}, {xtd::forms::shortcut::shift_f8, "shift_f8"}, {xtd::forms::shortcut::shift_f9, "shift_f9"}, {xtd::forms::shortcut::shift_ins, "shift_ins"}};}
};
/// @endcond
