/// @file
/// @brief Contains xtd::forms::cursor class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/drawing/bitmap>
#include <xtd/drawing/point>
#include <xtd/drawing/size>
#include <xtd/any>
#include <xtd/iequatable>
#include <xtd/object>
#include <cstdint>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class cursors;
    /// @endcond
    
    /// @brief Represents the image used to paint the mouse pointer.
    /// @par Header
    /// @code #include <xtd/forms/cursor> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @remarks A cursor is a small picture whose location on the screen is controlled by a pointing device, such as a mouse, pen, or trackball. When the user moves the pointing device, the operating system moves the cursor accordingly.
    /// @remarks Different cursor shapes are used to inform the user what operation the mouse will have. For example, when editing or selecting text, a cursors::ibeam cursor is typically displayed. A wait cursor is commonly used to inform the user that a process is currently running. Examples of processes you might have the user wait for are opening a file, saving a file, or filling a control such as a data_grid, list_box or tree_view with a large amount of data.
    /// @remarks All controls that derive from the Control class have a Cursor property. To change the cursor displayed by the mouse pointer when it is within the bounds of the control, assign a Cursor to the Cursor property of the control. Alternatively, you can display cursors at the application level by assigning a Cursor to the Current property. For example, if the purpose of your application is to edit a text file, you might set the Current property to Cursors.WaitCursor to display a wait cursor over the application while the file loads or saves to prevent any mouse events from being processed. When the process is complete, set the Current property to Cursors.Default for the application to display the appropriate cursor over each control type.
    /// @see xtd::forms::cursors
    /// @par Examples
    /// The following code example demonstrates the use of cursor component.
    /// @include cursors.cpp
    class forms_export_ cursor : public object, public xtd::iequatable<cursor> {
      struct data;
      
    public:
      /// @name Fields
      
      /// @{
      /// @brief Represent none cursor.
      static cursor none;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the cursor class.
      cursor();
      /// @brief Initializes a new instance of the Cursor class from the specified Windows handle.
      /// @param handle An IntPtr that represents the Windows handle of the cursor to create.
      /// @remarks You must free the cursor handle when you are done with it.
      explicit cursor(intptr handle);
      /// @}
      
      /// @cond
      cursor(const cursor& value) = default;
      cursor& operator =(const cursor& value) = default;
      ~cursor();
      /// @endcond
      
      /// @brief Gets a cursor object that represents the mouse cursor.
      /// @return A cursor that represents the mouse cursor. The default is cursor::none.
      /// @remarks Setting the current property changes the cursor currently displayed. The application may or may not continue to listen for mouse events. To signal that the application should not respond to mouse events during a long-running operation, use the application::use_wait_cursor property. In most cases, however, it's better to use a background thread to manage a long-running operation, and leave your user interface accessible to the user.
      static xtd::forms::cursor current();
      /// @brief Sets a cursor object that represents the mouse cursor.
      /// @param cursor A cursor that represents the mouse cursor. The default is cursor::none.
      /// @remarks Setting the current property changes the cursor currently displayed. The application may or may not continue to listen for mouse events. To signal that the application should not respond to mouse events during a long-running operation, use the application::use_wait_cursor property. In most cases, however, it's better to use a background thread to manage a long-running operation, and leave your user interface accessible to the user.
      static void current(const xtd::forms::cursor& cursor);
      
      /// @brief Gets the handle of the cursor.
      /// @return An intptr that represents the cursor's handle.
      /// @remarks This is not a copy of the handle; do not destroy it.
      intptr handle() const noexcept;
      
      /// @brief Gets the cursor hot spot.
      /// @return A point representing the cursor hot spot.
      /// @remarks The hot_spot is the point in the cursor that interacts with other elements on the screen.
      drawing::point hot_spot() const noexcept;
      
      /// @brief Gets the cursor's position.
      /// @return A point that represents the cursor's position in screen coordinates.
      /// @remarks The position property is identical to the control::mouse_position property.
      static drawing::point position();
      /// @brief Sets the cursor's position.
      /// @param position A point that represents the cursor's position in screen coordinates.
      /// @remarks The position property is identical to the control::mouse_position property.
      static void position(const drawing::point& position);
      
      /// @brief Gets the size of the cursor object.
      /// @return A size that represents the width and height of the cursor.
      drawing::size size() const noexcept;
      
      /// @brief Gets the object that contains data about the control.
      /// @return A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      std::any tag() const noexcept;
      
      /// @brief Sets the object that contains data about the control.
      /// @param tag A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      void tag(std::any tag);
      /// @}
      
      /// @name Methodds
      
      /// @{
      /// @brief Copies the handle of this cursor.
      /// @return An intptr that represents the cursor's handle.
      /// @remarks The handle created as a result of calling this method must be deleted of when you are done with it.
      intptr copy_handle() const;
      
      bool equals(const cursor& value) const noexcept override;
      
      /// @brief Create a cursor form a specified bitmap with specified hot spot.
      /// @param bitmap A xtd::drawing::bitmap image will be use by cursor.
      /// @param hot_spot A xtd::drawing::point hot spot location.
      /// @return A new cursor instance.
      static cursor from_bitmap(const xtd::drawing::bitmap& bitmap, const xtd::drawing::point& hot_spot);
      /// @brief Create a cursor form a specified bitmap.
      /// @param bitmap A xtd::drawing::bitmap image will be use by cursor.
      /// @return A new cursor instance.
      /// @remarks The hot spot location is top left (0, 0).
      static cursor from_bitmap(const xtd::drawing::bitmap& bitmap);
      
      /// @brief Hides the cursor.
      /// @brief The show and hide method calls must be balanced. For every call to the hide method there must be a corresponding call to the show method.
      static void hide();
      
      /// @brief Displays the cursor.
      /// @brief The show and hide method calls must be balanced. For every call to the hide method there must be a corresponding call to the show method.
      static void show();
      
      /// @brief Returns a string containing the name of the cursor.
      /// @return A string containing the name of the cursor.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      friend class xtd::forms::cursors;
      cursor(const xtd::drawing::bitmap& bitmap, const xtd::drawing::point& hot_spot);
      cursor(intptr handle, bool destroyable, const xtd::ustring& name);
      
      std::shared_ptr<data> data_;
    };
  }
}
