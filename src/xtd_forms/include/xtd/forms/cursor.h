#pragma once
#include <any>
#include <cstdint>
#include <memory>
#include <xtd/drawing/bitmap.h>
#include <xtd/drawing/point.h>
#include <xtd/drawing/size.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class cursors;
    /// @endcond
    
    /// @brief Represents the image used to paint the mouse pointer.
    /// @remarks A cursor is a small picture whose location on the screen is controlled by a pointing device, such as a mouse, pen, or trackball. When the user moves the pointing device, the operating system moves the cursor accordingly.
    /// @remarks Different cursor shapes are used to inform the user what operation the mouse will have. For example, when editing or selecting text, a cursors::ibeam cursor is typically displayed. A wait cursor is commonly used to inform the user that a process is currently running. Examples of processes you might have the user wait for are opening a file, saving a file, or filling a control such as a data_grid, list_box or tree_view with a large amount of data.
    /// @remarks All controls that derive from the Control class have a Cursor property. To change the cursor displayed by the mouse pointer when it is within the bounds of the control, assign a Cursor to the Cursor property of the control. Alternatively, you can display cursors at the application level by assigning a Cursor to the Current property. For example, if the purpose of your application is to edit a text file, you might set the Current property to Cursors.WaitCursor to display a wait cursor over the application while the file loads or saves to prevent any mouse events from being processed. When the process is complete, set the Current property to Cursors.Default for the application to display the appropriate cursor over each control type.
    class cursor {
    public:
      /// @brief Initializes a new instance of the Cursor class.
      cursor();
      /// @brief Initializes a new instance of the Cursor class from the specified Windows handle.
      /// @param handle An IntPtr that represents the Windows handle of the cursor to create.
      /// @remarks You must free the cursor handle when you are done with it.
      explicit cursor(intptr_t handle) : cursor(handle, false, "") {}
      
      /// @cond
      cursor(const cursor& value) = default;
      ~cursor();
      /// @endcond
      
      /// @brief Gets the handle of the cursor.
      /// @return An intptr_t that represents the cursor's handle.
      /// @remarks This is not a copy of the handle; do not detroy it.
      intptr_t handle() const {return this->data_->handle_;}
      
      /// @brief Gets the cursor hot spot.
      /// @return A point representing the cursor hot spot.
      /// @remarks The hot_spot is the point in the cursor that interacts with other elements on the screen.
      drawing::point hot_spot() const {return this->data_->hot_spot_;}
      
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
      drawing::size size() const {return this->data_->size_;}
      
      /// @brief Gets the object that contains data about the control.
      /// @return A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      std::any tag() const {return this->data_->tag_;}
      
      /// @brief Sets the object that contains data about the control.
      /// @param tag A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      void tag(std::any tag) {this->data_->tag_ = tag;}
      
      /// @remarks Copies the handle of this cursor.
      /// @return An intptr_t that represents the cursor's handle.
      /// @remarks The handle created as a result of calling this method must be deleted of when you are done with it.
      intptr_t copy_handle() const;
      
      static cursor from_bitmap(const xtd::drawing::bitmap& bitmap, const xtd::drawing::point& hot_spot) {return cursor(bitmap, hot_spot);}
      static cursor from_bitmap(const xtd::drawing::bitmap& bitmap) {return from_bitmap(bitmap, {});}

      /// @brief Hides the cursor.
      /// @brief The show and hide method calls must be balanced. For every call to the hide method there must be a corresponding call to the show method.
      static void hide();
      
      /// @brief Displays the cursor.
      /// @brief The show and hide method calls must be balanced. For every call to the hide method there must be a corresponding call to the show method.
      static void show();
      
      std::string to_string() const;
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const cursor& value) noexcept {return os << value.to_string();}
      bool operator==(const cursor& value) const {return this->data_ == value.data_;}
      bool operator!=(const cursor& value) const {return !this->operator==(value);}
      /// @endcond

    private:
      friend class cursors;
      cursor(const xtd::drawing::bitmap& bitmap, const xtd::drawing::point& hot_spot);
      cursor(intptr_t handle, bool destroyable, const std::string& name);

      struct data {
        intptr_t handle_ = 0;
        bool destroyable_ = true;
        drawing::point hot_spot_;
        std::string name_;
        drawing::size size_;
        std::any tag_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
