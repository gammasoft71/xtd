#pragma once
#include <any>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <xtd/drawing/color.hpp>
#include <xtd/drawing/font.hpp>
#include <xtd/drawing/point.hpp>
#include <xtd/drawing/rectangle.hpp>
#include <xtd/drawing/size.hpp>
#include <xtd/forms/create_params.hpp>

#include "layout/arranged_element_collection.hpp"
#include "auto_size_mode.hpp"
#include "bounds_specified.hpp"
#include "control_event_handler.hpp"
#include "key_event_handler.hpp"
#include "key_press_event_handler.hpp"
#include "mouse_event_handler.hpp"
#include "paint_event_handler.hpp"
#include "message.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class application;
    class screen;
    /// @endcond
    
    /// @brief Defines the base class for controls, which are components with visual representation.
    /// @remarks To create your own control class, inherit from the user_control, control classes, or from the other Windows Forms provided controls. For more information about authoring custom controls, see Developing Custom Windows Forms Controls with xtd.
    /// @remarks The control class implements very basic functionality required by classes that display information to the user. It handles user input through the keyboard and pointing devices. It handles message routing and security. It defines the bounds of a control (its position and size), although it does not implement painting. It provides a window handle (hWnd).
    /// @remarks Windows Forms controls use ambient properties so child controls can appear like their surrounding environment. An ambient property is a control property that, if not set, is retrieved from the parent control. If the control does not have a parent, and the property is not set, the control attempts to determine the value of the ambient property through the site property. If the control is not sited, if the site does not support ambient properties, or if the property is not set on the ambient_properties, the control uses its own default values. Typically, an ambient property represents a characteristic of a control, such as back_color, that is communicated to a child control. For example, a button will have the same back_color as its parent form by default. Ambient properties provided by the control class include: cursor, font, back_color, fore_color, and right_to_left.
    /// @remarks The majority of the controls in the xtd::forms namespace use the underlying Windows common control as a base to build on.
    class control {
    private:
      enum class state {
        empty = 0,
        double_click_fired = 0b1,
        mouse_entered = 0x10,
      };
      
    public:
      /// @brief @member types
      /// @{
      using ref_control = std::reference_wrapper<control>;
      using control_collection = layout::arranged_element_collection<ref_control>;
      /// @}
      
      /// @brief Represent a null control. This field is const.
      /// @remarks Use this field if you want remove control from parent.
      /// @code
      /// // remove button from form
      /// button.parent(control::null);
      /// @endcode
      static const control null;
      
      /// @brief Initializes a new instance of the Control class with default settings.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      control();
      /// @brief Initializes a new instance of the control class with specific text.
      /// @param text The text displayed by the control.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the control constructor sets the initial text property value to the text parameter value.
      explicit control(const std::string& text) : control() {
        this->text(text);
      }
      /// @brief nitializes a new instance of the control class as a child control, with specific text.
      /// @param parent The control to be the parent of the control.
      /// @param text The text displayed by the control.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the control constructor sets the initial text property value to the text parameter value. The constructor also adds the control to the parent control's control::control_collection.
      explicit control(const control& parent, const std::string& text) : control() {
        this->parent(parent);
        this->text(text);
      }
      /// @brief Initializes a new instance of the control class with specific text, size, and location.
      /// @param text The text displayed by the control.
      /// @param left The x position of the control, in pixels, from the left edge of the control's container. The value is assigned to the left property.
      /// @param top The y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the top property.
      /// @param width The width of the control, in pixels. The value is assigned to the width property.
      /// @param height The height of the control, in pixels. The value is assigned to the height property.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the control constructor sets the initial text property value to the text parameter value. The initial size and location of the control are determined by the left, top, width and height parameter values.
      explicit control(const std::string& text, int32_t left, int32_t top, int32_t width, int32_t height) : control() {
        this->text(text);
        this->left(left);
        this->top(top);
        this->width(width);
        this->height(height);
      }
      /// @brief Initializes a new instance of the control class as a child control, with specific text, size, and location.
      /// @param parent The control to be the parent of the control.
      /// @param text The text displayed by the control.
      /// @param left The x position of the control, in pixels, from the left edge of the control's container. The value is assigned to the left property.
      /// @param top The y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the top property.
      /// @param width The width of the control, in pixels. The value is assigned to the width property.
      /// @param height The height of the control, in pixels. The value is assigned to the height property.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the control constructor sets the initial text property value to the text parameter value. The constructor also adds the control to the parent control's control::control_collection. The initial size and location of the control are determined by the left, top, width and height parameter values.
      explicit control(const control& parent, const std::string& text, int32_t left, int32_t top, int32_t width, int32_t height) : control() {
        this->parent(parent);
        this->text(text);
        this->left(left);
        this->top(top);
        this->width(width);
        this->height(height);
      }
      
      /// @private
      /// @{
      control(const control& value) {*this = value;}
      control& operator=(const control& value);
      virtual ~control();
      /// @}
      
      /// @brief Gets a value that indicates whether the control resizes based on its contents.
      /// @return true if enabled; otherwise, false.
      /// @remarks This property is not relevant for this class.
      bool auto_size() const {return this->data_->auto_size_;}
      /// @brief Sets a value that indicates whether the control resizes based on its contents.
      /// @param auto_size true if enabled; otherwise, false.
      /// @return This control.
      /// @remarks This property is not relevant for this class.
      control& auto_size(bool auto_size);

      /// @brief Gets the background color for the control.
      /// @return A xtd::drawing::color that represents the background color of the control. The default is the value of the default_back_color property.
      /// @remarks The back_color property does not support transparent colors unless the supports_transparent_back_color value of xtd::forms::control_styles is set to true.
      /// @remarks The back_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a button will have the same back_color as its parent form by default.
      virtual drawing::color back_color() const {return this->data_->back_color_.value_or(this->data_->parent_ ? this->parent().back_color() : default_back_color());}
      /// @brief Sets the background color for the control.
      /// @param color A xtd::drawing::color that represents the background color of the control. The default is the value of the default_back_color property.
      /// @return This control.
      /// @remarks The back_color property does not support transparent colors unless the supports_transparent_back_color value of xtd::forms::control_styles is set to true.
      /// @remarks The back_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a button will have the same back_color as its parent form by default.
      /// @par Notes to Inheritors
      /// When overriding the back_color property in a derived class, use the base class's back_color property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the back_color property; you can override only one if needed.
      virtual control& back_color(const drawing::color& color);
      
      /// @brief Gets the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      /// @return An int32_t representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      /// @remarks The value of this property is equal to the sum of the top property value, and the height property value.
      /// @remarks The bottom property is a read-only property. You can manipulate this property value by changing the value of the top or height properties or calling the set_bounds, set_bounds_core, update_bounds, or set_client_size_core methods.
      virtual int32_t bottom() const {return this->top() + this->height();}
      
      /// @brief Gets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
      /// @return A rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
      /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus.
      virtual drawing::rectangle bounds() const {return {this->data_->location_, this->data_->size_};}
      /// @brief Sets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
      /// @param A rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
      /// @return This control.
      /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus. The Set_bounds_core method is called to set the bounds property. The bounds property is not always changed through its set method so you should override the set_bounds_core method to ensure that your code is executed when the bounds property is set.
      virtual control& bounds(const drawing::rectangle& bounds) {
        this->set_bounds_core(bounds.x(), bounds.y(), bounds.width(), bounds.height(), bounds_specified::all);
        return *this;
      }

      /// @brief Gets the rectangle that represents the client area of the control.
      /// @return A rectangle that represents the client area of the control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
      /// @remarks Because client coordinates are relative to the upper-left corner of the client area of the control, the coordinates of the upper-left corner of the rectangle returned by this property are (0,0). You can use this property to obtain the size and coordinates of the client area of the control for tasks such as drawing on the surface of the control.
      virtual const drawing::rectangle& client_rectangle() const {return this->data_->client_rectangle_;}

      /// @brief Gets  the height and width of the client area of the control.
      /// @return A size that represents the dimensions of the client area of the control.
      virtual const drawing::size& client_size() const {return this->data_->client_size_;}
      /// @brief Sets the height and width of the client area of the control.
      /// @param A size that represents the dimensions of the client area of the control.
      virtual control& client_size(const drawing::size& size);
      
      virtual control_collection& controls() {return this->data_->controls_;}
      
      virtual const control_collection& controls() const {return this->data_->controls_;}

      virtual drawing::color default_back_color() const;

      virtual drawing::color default_fore_color() const;
      
      virtual drawing::font default_font() const;
      
      virtual drawing::size default_size() const {return{0, 0};}
      
      virtual bool enabled() const {return this->data_->enabled_;}
      virtual control& enabled(bool enabled);

      virtual drawing::color fore_color() const {return this->data_->fore_color_.value_or(this->data_->parent_ ? this->parent().fore_color() : default_fore_color());}
      virtual control& fore_color(const drawing::color& color);
      
      virtual drawing::font font() const {return this->data_->font_.value_or(this->data_->parent_ ? this->parent().font() : default_font());}
      virtual control& font(const drawing::font& font);
      
      virtual intptr_t handle() const;
      
      virtual int32_t height() const {return this->data_->size_.height();}
      virtual control& height(int32_t height) {
        this->size({this->data_->size_.width() == -1 ? 0 : this->data_->size_.width(), height});
        return *this;
      }
      
      virtual int32_t left() const {return this->data_->location_.x();}
      virtual control& left(int32_t left) {
        this->size({left, this->data_->location_.y() == -1 ? 0 : this->data_->location_.y()});
        return *this;
      }

      virtual drawing::point location() const {return this->data_->location_;}
      virtual control& location(const drawing::point& location);

      virtual const std::string& name() const {return this->data_->name_;}
      virtual control& name(const std::string& name) {
        this->data_->name_ = name;
        return*this;
      }
      
      virtual control& parent() const {return from_handle(this->data_->parent_);}
      virtual control& parent(const control& parent);

      virtual int32_t right() const {return this->left() + this->width();}

      virtual drawing::size size() const {return this->data_->size_;}
      virtual control& size(const drawing::size& size);
      
      /// @brief Gets the object that contains data about the control.
      /// @return A std::any that contains data about the control. The default is empty.
      virtual std::any tag() const {return this->data_->tag_;}
      
      /// @brief Sets the object that contains data about the control.
      /// @param tag A std::any that contains data about the control. The default is empty.
      virtual control& tag(std::any tag) {
        this->data_->tag_ = tag;
        return*this;
      }
      
      virtual const std::string& text() const {return this->data_->text_;}
      virtual control& text(const std::string& text);
      
      virtual int32_t top() const {return this->data_->location_.y();}
      virtual control& top(int32_t top) {
        this->size({this->data_->location_.x() == -1 ? 0 : this->data_->location_.x(), top});
        return *this;
      }
      
      virtual bool visible() const {return this->data_->visible_;}
      virtual control& visible(bool visible);

      virtual int32_t width() const {return this->data_->size_.width();}
      virtual control& width(int32_t width) {
        this->size({width, this->data_->size_.height() == -1 ? 0 : this->data_->size_.height()});
        return *this;
      }
      
      friend control& operator<<(control& parent, control& child) {
        child.parent(parent);
        return parent;
      }

      template<typename control_t>
      static control_t create(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}) {
        control_t item;
        if (location != drawing::point {-1, -1}) item.location(location);
        if (size != drawing::size {-1, -1}) item.size(size);
        return item;
      }
      
      template<typename control_t>
      static control_t create(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}) {
        control_t item;
        item.parent(parent);
        if (location != drawing::point {-1, -1}) item.location(location);
        if (size != drawing::size {-1, -1}) item.size(size);
        return item;
      }
      
      template<typename control_t>
      static control_t create(const std::string& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}) {
        control_t item;
        item.text(text);
        if (location != drawing::point {-1, -1}) item.location(location);
        if (size != drawing::size {-1, -1}) item.size(size);
        return item;
      }
      
      template<typename control_t>
      static control_t create(const control& parent, const std::string& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}) {
        control_t item;
        item.parent(parent);
        item.text(text);
        if (location != drawing::point {-1, -1}) item.location(location);
        if (size != drawing::size {-1, -1}) item.size(size);
        return item;
      }

      void create_control();
      
      void destroy_control();
      
      virtual void hide() {this->visible(false);}

      virtual void create_handle();
      
      drawing::graphics create_graphics() const;

      virtual void destroy_handle();
      
      static control& from_child_handle(intptr_t handle);

      static control& from_handle(intptr_t handle);
      
      bool is_handle_created() const;
      
      bool is_null() const;
      
      virtual void refresh() const;
      
      intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam);
      
      void set_auto_size_mode(auto_size_mode auto_size_mode);
      
      void set_bounds(int32_t x, int32_t y, int32_t width, int32_t height) {this->set_bounds(x, y, width, height, bounds_specified::all);}

      void set_bounds(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {this->set_bounds_core(x, y, width, height, specified);}

      virtual void show() {this->visible(true);}
      
      virtual std::string to_string() const;
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::control& control) noexcept {
        return os << control.to_string();
      }
      /// @endcond
      
      virtual void wnd_proc(message& message);

      event<control, event_handler<control>> auto_size_changed;

      event<control, event_handler<control>> back_color_changed;
      
      event<control, event_handler<control>> click;
      
      event<control, event_handler<control>> client_size_changed;
      
      event<control, control_event_handler<control>> control_added;
      
      event<control, control_event_handler<control>> control_removed;
      
      event<control, event_handler<control>> double_click;

      event<control, event_handler<control>> got_focus;
      
      event<control, event_handler<control>> handle_created;
      
      event<control, event_handler<control>> handle_destroyed;
      
      event<control, event_handler<control>> enabled_changed;

      event<control, event_handler<control>> fore_color_changed;
      
      event<control, event_handler<control>> font_changed;
      
      event<control, key_event_handler<control>> key_down;
      
      event<control, key_press_event_handler<control>> key_press;
      
      event<control, key_event_handler<control>> key_up;
      
      event<control, event_handler<control>> location_changed;
      
      event<control, event_handler<control>> lost_focus;
      
      event<control, mouse_event_handler<control>> mouse_click;
      
      event<control, mouse_event_handler<control>> mouse_double_click;
      
      event<control, mouse_event_handler<control>> mouse_down;
      
      event<control, event_handler<control>> mouse_enter;
      
      event<control, mouse_event_handler<control>> mouse_horizontal_wheel;
      
      event<control, event_handler<control>> mouse_leave;
      
      event<control, mouse_event_handler<control>> mouse_move;
      
      event<control, mouse_event_handler<control>> mouse_up;
      
      event<control, mouse_event_handler<control>> mouse_wheel;
      
      event<control, paint_event_handler<control>> paint;
      
      event<control, event_handler<control>> parent_changed;
      
      event<control, event_handler<control>> size_changed;
      
      event<control, event_handler<control>> text_changed;
      
      event<control, event_handler<control>> visible_changed;

    protected:
      friend class application;
      friend class screen;
      virtual forms::create_params create_params() const;
      
      virtual void def_wnd_proc(message& message);

      template<typename control_t>
      void make_control(const control_t& value) {controls_[value.control::data_.get()] = std::make_shared<control_t>(value);}
    
      /// @brief Measure this control.
      /// @return THe Drawing::Size size of this control.
      /// @remarks This metod is not relevant for this class.
      virtual drawing::size measure_control() const;
      
      drawing::size measure_text() const;
      
      virtual void on_auto_size_changed(const event_args& e);
      
      virtual void on_back_color_changed(const event_args& e);
      
      virtual void on_click(const event_args& e);
      
      virtual void on_client_size_changed(const event_args& e);
      
      virtual void on_control_added(const control_event_args& e);
      
      virtual void on_control_removed(const control_event_args& e);
      
      virtual void on_create_control();
      
      virtual void on_double_click(const event_args& e);
      
      virtual void on_enabled_changed(const event_args& e);
      
      virtual void on_fore_color_changed(const event_args& e);
      
      virtual void on_font_changed(const event_args& e);
      
      virtual void on_got_focus(const event_args& e);
      
      virtual void on_handle_created(const event_args& e);
      
      virtual void on_handle_destroyed(const event_args& e);
      
      virtual void on_key_down(key_event_args& e);
      
      virtual void on_key_press(key_press_event_args& e);
      
      virtual void on_key_up(key_event_args& e);
      
      virtual void on_location_changed(const event_args& e);
      
      virtual void on_lost_focus(const event_args& e);
      
      virtual void on_mouse_click(const mouse_event_args& e);
      
      virtual void on_mouse_double_click(const mouse_event_args& e);
      
      virtual void on_mouse_down(const mouse_event_args& e);
      
      virtual void on_mouse_enter(const event_args& e);
      
      virtual void on_mouse_horizontal_wheel(const mouse_event_args& e);
      
      virtual void on_mouse_leave(const event_args& e);
      
      virtual void on_mouse_move(const mouse_event_args& e);
      
      virtual void on_mouse_up(const mouse_event_args& e);
      
      virtual void on_mouse_wheel(const mouse_event_args& e);
      
      virtual void on_paint(paint_event_args& e);
      
      virtual void on_parent_back_color_changed(const event_args& e);
      
      virtual void on_parent_changed(const event_args& e);
      
      virtual void on_parent_fore_color_changed(const event_args& e);
      
      virtual void on_parent_font_changed(const event_args& e);
      
      virtual void on_size_changed(const event_args& e);
      
      virtual void on_text_changed(const event_args& e);
      
      virtual void on_visible_changed(const event_args& e);

      void recreate_handle();
 
      virtual void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {
        if ((specified & bounds_specified::x) == bounds_specified::x) this->left(x);
        if ((specified & bounds_specified::y) == bounds_specified::y) this->top(y);
        if ((specified & bounds_specified::width) == bounds_specified::width) this->width(width);
        if ((specified & bounds_specified::height) == bounds_specified::height) this->height(height);
      }
      
      virtual void set_client_size_core(int32_t width, int32_t height) {this->size({width, height});}

      ///@private
      /// @{
      struct data {
        bool auto_size_ = false;
        auto_size_mode auto_size_mode_ = auto_size_mode::grow_and_shrink;
        std::optional<drawing::color> back_color_;
        drawing::rectangle client_rectangle_;
        drawing::size client_size_ {-1, -1};
        control_collection controls_;
        bool enabled_ = true;
        std::optional<drawing::color> fore_color_;
        std::optional<drawing::font> font_;
        intptr_t handle_ = 0;
        drawing::point location_ {-1, -1};
        std::string name_;
        intptr_t parent_ = 0;
        drawing::size size_ {-1, -1};
        control::state state_ = state::empty;
        std::any tag_;
        std::string text_;
        bool visible_ = true;
       };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
      static std::map<intptr_t, control*> handles_;
      static control_collection top_level_controls_;
      static std::map<control::data*, std::shared_ptr<control>> controls_;
      /// @}
      
    private:
      void internal_destroy_handle(intptr_t);
      void set_auto_size_size();
      control(const std::string& name, bool) {this->data_->name_ = name;}
      bool get_state(control::state flag) const {return ((int32_t)this->data_->state_ & (int32_t)flag) == (int32_t)flag;}
      void set_state(control::state flag, bool value) { this->data_->state_ = value ? (control::state)((int32_t)this->data_->state_ | (int32_t)flag) : (control::state)((int32_t)this->data_->state_ & ~(int32_t)flag); }
      intptr_t wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle);
      void wm_child_activate(message& message);
      void wm_command(message& message);
      void wm_key_char(message& message);
      void wm_kill_focus(message& message);
      void wm_mouse_down(message& message);
      void wm_mouse_double_click(message& message);
      void wm_mouse_enter(message& message);
      void wm_mouse_leave(message& message);
      void wm_mouse_up(message& message);
      void wm_mouse_move(message& message);
      void wm_move(message& message);
      void wm_mouse_wheel(message& message);
      void wm_paint(message& message);
      void wm_set_focus(message& message);
      void wm_set_text(message& message);
      void wm_size(message& message);
    };
  }
}
