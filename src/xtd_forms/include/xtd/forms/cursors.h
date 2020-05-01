#pragma once
#include "cursor.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of Cursor objects for use by a Windows Forms application.
    class cursors static_ {
    public:
      /// @brief Gets the cursor that appears when an application starts.
      /// @return The cursor that represents the cursor that appears when an application starts.
      static cursor app_starting();

      /// @brief Gets the arrow cursor.
      /// @return The cursor that represents the arrow cursor.
      static cursor arrow();

      /// @brief Gets the closed hand cursor.
      /// @return The cursor that represents the close hand cursor.
      static cursor closed_hand();

      /// @brief Gets the contextual menu cursor.
      /// @return The cursor that represents the contextual menu cursor.
      static cursor contextual_menu();

      /// @brief Gets the crosshair cursor.
      /// @return The cursor that represents the crosshair cursor.
      static cursor cross();

      /// @brief Gets the default cursor, which is usually an arrow cursor.
      /// @return The cursor that represents the default cursor.
      static cursor default_cursor();

      /// @brief Gets the disappearing item cursor.
      /// @return The cursor that represents the disappearing item cursor.
      static cursor disappearing_item();

      /// @brief Gets the drag copy cursor.
      /// @return The cursor that represents the drag copy cursor.
      static cursor drag_copy();

      /// @brief Gets the drag link cursor.
      /// @return The cursor that represents the drag link cursor.
      static cursor drag_link();

      /// @brief Gets the hand cursor, typically used when hovering over a Web link.
      /// @return The cursor that represents the hand cursor.
      static cursor hand();

      /// @brief Gets the Help cursor, which is a combination of an arrow and a question mark.
      /// @return The cursor that represents the Help cursor.
      static cursor help();

      /// @brief Gets the cursor that appears when the mouse is positioned over a horizontal splitter bar.
      /// @return The cursor that represents the cursor that appears when the mouse is positioned over a horizontal splitter bar.
      static cursor hsplit();

      /// @brief Gets the I-beam cursor, which is used to show where the text cursor appears when the mouse is clicked.
      /// @return The cursor that represents the I-beam cursor.
      static cursor ibeam();

      /// @brief Gets the cursor that indicates that a particular region is invalid for the current operation.
      /// @return The cursor that represents the cursor that indicates that a particular region is invalid for the current operation.
      static cursor no();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in both a horizontal and vertical direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
      static cursor no_move_2d();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in a horizontal direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
      static cursor no_move_horiz();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in a vertical direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
      static cursor no_move_vert();

      /// @brief Gets the open hand cursor.
      /// @return The cursor that represents the open hand cursor.
      static cursor open_hand();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the right.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the right.
      static cursor pan_east();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the right.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the right.
      static cursor pan_ne();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in an upward direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in an upward direction.
      static cursor pan_north();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the left.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the left.
      static cursor pan_nw();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the right.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the right.
      static cursor pan_se();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in a downward direction.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in a downward direction.
      static cursor pan_south();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the left.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the left.
      static cursor pan_sw();

      /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the left.
      /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the left.
      static cursor pan_west();

      /// @brief Gets the four-headed sizing cursor, which consists of four joined arrows that point north, south, east, and west.
      /// @return The cursor that represents the four-headed sizing cursor.
      static cursor size_all();

      /// @brief Gets the two-headed diagonal (northeast/southwest) sizing cursor.
      /// @return The cursor that represents two-headed diagonal (northeast/southwest) sizing cursor.
      static cursor size_nesw();

      /// @brief Gets the two-headed vertical (north/south) sizing cursor.
      /// @return The cursor that represents the two-headed vertical (north/south) sizing cursor.
      static cursor size_ns();

      /// @brief Gets the two-headed diagonal (northwest/southeast) sizing cursor.
      /// @return The cursor that represents the two-headed diagonal (northwest/southeast) sizing cursor.
      static cursor size_nwse();

      /// @brief Gets the two-headed diagonal (northwest/southeast) sizing cursor.
      /// @return The cursor that represents the two-headed diagonal (northwest/southeast) sizing cursor.
      static cursor size_we();

      /// @brief Gets the up arrow cursor, typically used to identify an insertion point.
      /// @return The cursor that represents the up arrow cursor.
      static cursor up_arrow();

      /// @brief Gets the vertical I-beam cursor, which is used to show where the text cursor appears when the mouse is clicked for vertical layout.
      /// @return The cursor that represents the vertical I-beam cursor.
      static cursor vibeam();

      /// @brief Gets the cursor that appears when the mouse is positioned over a vertical splitter bar.
      /// @return The cursor that represents the cursor that appears when the mouse is positioned over a vertical splitter bar.
      static cursor vsplit();

      /// @brief Gets the wait cursor, typically an hourglass shape.
      /// @return The cursor that represents the wait cursor.
      static cursor wait_cursor();
    };
  }
}
