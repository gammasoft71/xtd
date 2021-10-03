/// @file
/// @brief Contains xtd::forms::cursors factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "cursor.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of xtd::forms::cursor objects for use by a Windows Forms application.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @par Examples
    /// The following code example demonstrate the use of cursors component.
    /// @include cursors.cpp
    class forms_export_ cursors final static_ {
    public:
      /// @brief Gets the cursor that appears when an application starts.
      /// @return The cursor that represents the cursor that appears when an application starts.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html app_starting_w.png</td>
      ///     <td>@image html app_starting_m.png</td>
      ///     <td>@image html app_starting_g.png</td>
      ///   </tr>
      /// </table>
      static cursor app_starting();

      /// @brief Gets the arrow cursor.
      /// @return The cursor that represents the arrow cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html arrow_w.png</td>
      ///     <td>@image html arrow_m.png</td>
      ///     <td>@image html arrow_g.png</td>
      ///   </tr>
      /// </table>
      static cursor arrow();

      /// @brief Gets the closed hand cursor.
      /// @return The cursor that represents the close hand cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html closed_hand_w.png</td>
      ///     <td>@image html closed_hand_m.png</td>
      ///     <td>@image html closed_hand_g.png</td>
      ///   </tr>
      /// </table>
      static cursor closed_hand();

      /// @brief Gets the contextual menu cursor.
      /// @return The cursor that represents the contextual menu cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html contextual_menu_w.png</td>
      ///     <td>@image html contextual_menu_m.png</td>
      ///     <td>@image html contextual_menu_g.png</td>
      ///   </tr>
      /// </table>
      static cursor contextual_menu();

      /// @brief Gets the cell cursor.
      /// @return The cursor that represents the cell cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html cell_w.png</td>
      ///     <td>@image html cell_m.png</td>
      ///     <td>@image html cell_g.png</td>
      ///   </tr>
      /// </table>
      static cursor cell();
      
      /// @brief Gets the crosshair cursor.
      /// @return The cursor that represents the crosshair cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html cross_w.png</td>
      ///     <td>@image html cross_m.png</td>
      ///     <td>@image html cross_g.png</td>
      ///   </tr>
      /// </table>
      static cursor cross();
      
      /// @brief Gets the default cursor, which is usually an arrow cursor.
      /// @return The cursor that represents the default cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html default_cursor_w.png</td>
      ///     <td>@image html default_cursor_m.png</td>
      ///     <td>@image html default_cursor_g.png</td>
      ///   </tr>
      /// </table>
      static cursor default_cursor();

      /// @brief Gets the disappearing item cursor.
      /// @return The cursor that represents the disappearing item cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html disappearing_item_w.png</td>
      ///     <td>@image html disappearing_item_m.png</td>
      ///     <td>@image html disappearing_item_g.png</td>
      ///   </tr>
      /// </table>
      static cursor disappearing_item();

      /// @brief Gets the drag copy cursor.
      /// @return The cursor that represents the drag copy cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html drag_copy_w.png</td>
      ///     <td>@image html drag_copy_m.png</td>
      ///     <td>@image html drag_copy_g.png</td>
      ///   </tr>
      /// </table>
      static cursor drag_copy();

      /// @brief Gets the drag link cursor.
      /// @return The cursor that represents the drag link cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html drag_link_w.png</td>
      ///     <td>@image html drag_link_m.png</td>
      ///     <td>@image html drag_link_g.png</td>
      ///   </tr>
      /// </table>
      static cursor drag_link();

      /// @brief Gets the hand cursor, typically used when hovering over a Web link.
      /// @return The cursor that represents the hand cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html hand_w.png</td>
      ///     <td>@image html hand_m.png</td>
      ///     <td>@image html hand_g.png</td>
      ///   </tr>
      /// </table>
      static cursor hand();

      /// @brief Gets the Help cursor, which is a combination of an arrow and a question mark.
      /// @return The cursor that represents the Help cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html help_w.png</td>
      ///     <td>@image html help_m.png</td>
      ///     <td>@image html help_g.png</td>
      ///   </tr>
      /// </table>
      static cursor help();

      /// @brief Gets the cursor that appears when the mouse is positioned over a horizontal splitter bar.
      /// @return The cursor that represents the cursor that appears when the mouse is positioned over a horizontal splitter bar.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html hsplit_w.png</td>
      ///     <td>@image html hsplit_m.png</td>
      ///     <td>@image html hsplit_g.png</td>
      ///   </tr>
      /// </table>
      static cursor hsplit();

      /// @brief Gets the I-beam cursor, which is used to show where the text cursor appears when the mouse is clicked.
      /// @return The cursor that represents the I-beam cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html ibeam_w.png</td>
      ///     <td>@image html ibeam_m.png</td>
      ///     <td>@image html ibeam_g.png</td>
      ///   </tr>
      /// </table>
      static cursor ibeam();

      /// @brief Gets the cursor that indicates that a particular region is invalid for the current operation.
      /// @return The cursor that represents the cursor that indicates that a particular region is invalid for the current operation.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html no_w.png</td>
      ///     <td>@image html no_m.png</td>
      ///     <td>@image html no_g.png</td>
      ///   </tr>
      /// </table>
      static cursor no();
      
      /// @brief Gets the cursor that indicates that a particular region is invalid for the current drag & drop operation.
      /// @return The cursor that represents the cursor that indicates that a particular region is invalid for the curren drag & drop operation.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html no_drag_w.png</td>
      ///     <td>@image html no_drag_m.png</td>
      ///     <td>@image html no_drag_g.png</td>
      ///   </tr>
      /// </table>
      static cursor no_drag();
      
      /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in both a horizontal and vertical direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html no_move_2d_w.png</td>
      ///     <td>@image html no_move_2d_m.png</td>
      ///     <td>@image html no_move_2d_g.png</td>
      ///   </tr>
      /// </table>
      static cursor no_move_2d();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in a horizontal direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html no_move_horiz_w.png</td>
      ///     <td>@image html no_move_horiz_m.png</td>
      ///     <td>@image html no_move_horiz_g.png</td>
      ///   </tr>
      /// </table>
      static cursor no_move_horiz();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in a vertical direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html no_move_vert_w.png</td>
      ///     <td>@image html no_move_vert_m.png</td>
      ///     <td>@image html no_move_vert_g.png</td>
      ///   </tr>
      /// </table>
      static cursor no_move_vert();

      /// @brief Gets the open hand cursor.
      /// @return The cursor that represents the open hand cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html open_hand_w.png</td>
      ///     <td>@image html open_hand_m.png</td>
      ///     <td>@image html open_hand_g.png</td>
      ///   </tr>
      /// </table>
      static cursor open_hand();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the right.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the right.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html pan_east_w.png</td>
      ///     <td>@image html pan_east_m.png</td>
      ///     <td>@image html pan_east_g.png</td>
      ///   </tr>
      /// </table>
      static cursor pan_east();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the right.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the right.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html pan_ne_w.png</td>
      ///     <td>@image html pan_ne_m.png</td>
      ///     <td>@image html pan_ne_g.png</td>
      ///   </tr>
      /// </table>
      static cursor pan_ne();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in an upward direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in an upward direction.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html pan_north_w.png</td>
      ///     <td>@image html pan_north_m.png</td>
      ///     <td>@image html pan_north_g.png</td>
      ///   </tr>
      /// </table>
      static cursor pan_north();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the left.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the left.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html pan_nw_w.png</td>
      ///     <td>@image html pan_nw_m.png</td>
      ///     <td>@image html pan_nw_g.png</td>
      ///   </tr>
      /// </table>
      static cursor pan_nw();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the right.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the right.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html pan_se_w.png</td>
      ///     <td>@image html pan_se_m.png</td>
      ///     <td>@image html pan_se_g.png</td>
      ///   </tr>
      /// </table>
      static cursor pan_se();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in a downward direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in a downward direction.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html pan_south_w.png</td>
      ///     <td>@image html pan_south_m.png</td>
      ///     <td>@image html pan_south_g.png</td>
      ///   </tr>
      /// </table>
      static cursor pan_south();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the left.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the left.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html pan_sw_w.png</td>
      ///     <td>@image html pan_sw_m.png</td>
      ///     <td>@image html pan_sw_g.png</td>
      ///   </tr>
      /// </table>
      static cursor pan_sw();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the left.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the left.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html pan_west_w.png</td>
      ///     <td>@image html pan_west_m.png</td>
      ///     <td>@image html pan_west_g.png</td>
      ///   </tr>
      /// </table>
      static cursor pan_west();

      /// @brief Gets the four-headed sizing cursor, which consists of four joined arrows that point north, south, east, and west.
      /// @return The cursor that represents the four-headed sizing cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html size_all_w.png</td>
      ///     <td>@image html size_all_m.png</td>
      ///     <td>@image html size_all_g.png</td>
      ///   </tr>
      /// </table>
      static cursor size_all();

      /// @brief Gets the two-headed diagonal (northeast/southwest) sizing cursor.
      /// @return The cursor that represents two-headed diagonal (northeast/southwest) sizing cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html size_nesw_w.png</td>
      ///     <td>@image html size_nesw_m.png</td>
      ///     <td>@image html size_nesw_g.png</td>
      ///   </tr>
      /// </table>
      static cursor size_nesw();

      /// @brief Gets the two-headed vertical (north/south) sizing cursor.
      /// @return The cursor that represents the two-headed vertical (north/south) sizing cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html size_ns_w.png</td>
      ///     <td>@image html size_ns_m.png</td>
      ///     <td>@image html size_ns_g.png</td>
      ///   </tr>
      /// </table>
      static cursor size_ns();

      /// @brief Gets the two-headed diagonal (northwest/southeast) sizing cursor.
      /// @return The cursor that represents the two-headed diagonal (northwest/southeast) sizing cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html size_nwse_w.png</td>
      ///     <td>@image html size_nwse_m.png</td>
      ///     <td>@image html size_nwse_g.png</td>
      ///   </tr>
      /// </table>
      static cursor size_nwse();

      /// @brief Gets the two-headed diagonal (northwest/southeast) sizing cursor.
      /// @return The cursor that represents the two-headed diagonal (northwest/southeast) sizing cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html size_we_w.png</td>
      ///     <td>@image html size_we_m.png</td>
      ///     <td>@image html size_we_g.png</td>
      ///   </tr>
      /// </table>
      static cursor size_we();

      /// @brief Gets the up arrow cursor, typically used to identify an insertion point.
      /// @return The cursor that represents the up arrow cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html up_arrow_w.png</td>
      ///     <td>@image html up_arrow_m.png</td>
      ///     <td>@image html up_arrow_g.png</td>
      ///   </tr>
      /// </table>
      static cursor up_arrow();

      /// @brief Gets the vertical I-beam cursor, which is used to show where the text cursor appears when the mouse is clicked for vertical layout.
      /// @return The cursor that represents the vertical I-beam cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html vibeam_w.png</td>
      ///     <td>@image html vibeam_m.png</td>
      ///     <td>@image html vibeam_g.png</td>
      ///   </tr>
      /// </table>
      static cursor vibeam();

      /// @brief Gets the cursor that appears when the mouse is positioned over a vertical splitter bar.
      /// @return The cursor that represents the cursor that appears when the mouse is positioned over a vertical splitter bar.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html vsplit_w.png</td>
      ///     <td>@image html vsplit_m.png</td>
      ///     <td>@image html vsplit_g.png</td>
      ///   </tr>
      /// </table>
      static cursor vsplit();

      /// @brief Gets the wait cursor, typically an hourglass shape.
      /// @return The cursor that represents the wait cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html wait_cursor_w.png</td>
      ///     <td>@image html wait_cursor_m.png</td>
      ///     <td>@image html wait_cursor_g.png</td>
      ///   </tr>
      /// </table>
      static cursor wait_cursor();

      /// @brief Gets the zoom int cursor, typically to zoom in an object.
      /// @return The cursor that represents the zoom in cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html zoom_in_w.png</td>
      ///     <td>@image html zoom_in_m.png</td>
      ///     <td>@image html zoom_in_g.png</td>
      ///   </tr>
      /// </table>
      static cursor zoom_in();

      /// @brief Gets the zoom out cursor, typically to zoom out an object.
      /// @return The cursor that represents the zoom out cursor.
      /// @par Appearance
      /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
      ///   <tr>
      ///     <th><b>Windows</b></th>
      ///     <th><b>macOS</b></th>
      ///     <th><b>Gnome</b></th>
      ///   </tr>
      ///   <tr>
      ///     <td>@image html zoom_out_w.png</td>
      ///     <td>@image html zoom_out_m.png</td>
      ///     <td>@image html zoom_out_g.png</td>
      ///   </tr>
      /// </table>
      static cursor zoom_out();

      static const std::vector<cursor>& get_cursors();
    };
  }
}
