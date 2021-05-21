/// @file
/// @brief Contains xtd::forms::native::cursors API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class cursors;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains cursors native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ cursors final static_ {
        friend xtd::forms::cursors;
      protected:
        /// @brief Gets the cursor that appears when an application starts.
        /// @return The cursor that represents the cursor that appears when an application starts.
        /// @warning Internal use only
        static intptr_t app_starting();
        /// @brief Gets the arrow cursor.
        /// @return The cursor that represents the arrow cursor.
        /// @warning Internal use only
        static intptr_t arrow();
        /// @brief Gets the closed hand cursor.
        /// @return The cursor that represents the close hand cursor.
        /// @warning Internal use only
        static intptr_t closed_hand();
        /// @brief Gets the contextual menu cursor.
        /// @return The cursor that represents the contextual menu cursor.
        /// @warning Internal use only
        static intptr_t contextual_menu();
        /// @brief Gets the cell cursor.
        /// @return The cursor that represents the cell cursor.
        /// @warning Internal use only
        static intptr_t cell();
        /// @brief Gets the crosshair cursor.
        /// @return The cursor that represents the crosshair cursor.
        /// @warning Internal use only
        static intptr_t cross();
        /// @brief Gets the default cursor, which is usually an arrow cursor.
        /// @return The cursor that represents the default cursor.
        /// @warning Internal use only
        static intptr_t default_cursor();
        /// @brief Gets the disappearing item cursor.
        /// @return The cursor that represents the disappearing item cursor.
        /// @warning Internal use only
        static intptr_t disappearing_item();
        /// @brief Gets the drag copy cursor.
        /// @return The cursor that represents the drag copy cursor.
        /// @warning Internal use only
        static intptr_t drag_copy();
        /// @brief Gets the drag link cursor.
        /// @return The cursor that represents the drag link cursor.
        /// @warning Internal use only
        static intptr_t drag_link();
        /// @brief Gets the hand cursor, typically used when hovering over a Web link.
        /// @return The cursor that represents the hand cursor.
        /// @warning Internal use only
        static intptr_t hand();
        /// @brief Gets the Help cursor, which is a combination of an arrow and a question mark.
        /// @return The cursor that represents the Help cursor.
        /// @warning Internal use only
        static intptr_t help();
        /// @brief Gets the cursor that appears when the mouse is positioned over a horizontal splitter bar.
        /// @return The cursor that represents the cursor that appears when the mouse is positioned over a horizontal splitter bar.
        /// @warning Internal use only
        static intptr_t hsplit();
        /// @brief Gets the I-beam cursor, which is used to show where the text cursor appears when the mouse is clicked.
        /// @return The cursor that represents the I-beam cursor.
        /// @warning Internal use only
        static intptr_t ibeam();
        /// @brief Gets the cursor that indicates that a particular region is invalid for the current operation.
        /// @return The cursor that represents the cursor that indicates that a particular region is invalid for the current operation.
        /// @warning Internal use only
        static intptr_t no();
        /// @brief Gets the cursor that indicates that a particular region is invalid for the current drag & drop operation.
        /// @return The cursor that represents the cursor that indicates that a particular region is invalid for the curren drag & dropt operation.
        /// @warning Internal use only
        static intptr_t no_drag();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in both a horizontal and vertical direction.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
        /// @warning Internal use only
        static intptr_t no_move_2d();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in a horizontal direction.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
        /// @warning Internal use only
        static intptr_t no_move_horiz();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is not moving, but the window can be scrolled in a vertical direction.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is not moving.
        /// @warning Internal use only
        static intptr_t no_move_vert();
        /// @brief Gets the open hand cursor.
        /// @return The cursor that represents the open hand cursor.
        /// @warning Internal use only
        static intptr_t open_hand();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the right.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the right.
        /// @warning Internal use only
        static intptr_t pan_east();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the right.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the right.
        /// @warning Internal use only
        static intptr_t pan_ne();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in an upward direction.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in an upward direction.
        /// @warning Internal use only
        static intptr_t pan_north();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the left.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically upward and to the left.
        /// @warning Internal use only
        static intptr_t pan_nw();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the right.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the right.
        /// @warning Internal use only
        static intptr_t pan_se();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in a downward direction.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling vertically in a downward direction.
        /// @warning Internal use only
        static intptr_t pan_south();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the left.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally and vertically downward and to the left.
        /// @warning Internal use only
        static intptr_t pan_sw();
        /// @brief Gets the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the left.
        /// @return The cursor that represents the cursor that appears during wheel operations when the mouse is moving and the window is scrolling horizontally to the left.
        /// @warning Internal use only
        static intptr_t pan_west();
        /// @brief Gets the four-headed sizing cursor, which consists of four joined arrows that point north, south, east, and west.
        /// @return The cursor that represents the four-headed sizing cursor.
        /// @warning Internal use only
        static intptr_t size_all();
        /// @brief Gets the two-headed diagonal (northeast/southwest) sizing cursor.
        /// @return The cursor that represents two-headed diagonal (northeast/southwest) sizing cursor.
        /// @warning Internal use only
        static intptr_t size_nesw();
        /// @brief Gets the two-headed vertical (north/south) sizing cursor.
        /// @return The cursor that represents the two-headed vertical (north/south) sizing cursor.
        /// @warning Internal use only
        /// @warning Internal use only
        static intptr_t size_ns();
        /// @brief Gets the two-headed diagonal (northwest/southeast) sizing cursor.
        /// @return The cursor that represents the two-headed diagonal (northwest/southeast) sizing cursor.
        /// @warning Internal use only
        static intptr_t size_nwse();
        /// @brief Gets the two-headed diagonal (northwest/southeast) sizing cursor.
        /// @return The cursor that represents the two-headed diagonal (northwest/southeast) sizing cursor.
        /// @warning Internal use only
        static intptr_t size_we();
        /// @brief Gets the up arrow cursor, typically used to identify an insertion point.
        /// @return The cursor that represents the up arrow cursor.
        /// @warning Internal use only
        static intptr_t up_arrow();
        /// @brief Gets the vertical I-beam cursor, which is used to show where the text cursor appears when the mouse is clicked for vertical layout.
        /// @return The cursor that represents the vertical I-beam cursor.
        /// @warning Internal use only
        static intptr_t vibeam();
        /// @brief Gets the cursor that appears when the mouse is positioned over a vertical splitter bar.
        /// @return The cursor that represents the cursor that appears when the mouse is positioned over a vertical splitter bar.
        /// @warning Internal use only
        /// @warning Internal use only
        static intptr_t vsplit();
        /// @brief Gets the wait cursor, typically an hourglass shape.
        /// @return The cursor that represents the wait cursor.
        /// @warning Internal use only
        static intptr_t wait_cursor();
        /// @brief Gets the zoom int cursor, typically to zoom in an object.
        /// @return The cursor that represents the zoom in cursor.
        /// @warning Internal use only
        static intptr_t zoom_in();
        /// @brief Gets the zoom out cursor, typically to zoom out an object.
        /// @return The cursor that represents the zoom out cursor.
        /// @warning Internal use only
        static intptr_t zoom_out();
      };
    }
  }
}
