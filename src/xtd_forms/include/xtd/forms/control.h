#pragma once
#include <any>
#include <condition_variable>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <shared_mutex>
#include <optional>
#include <string>
#include <thread>
#include <vector>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/point.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/drawing/size.h>
#include <xtd/forms/create_params.h>

#include "layout/arranged_element_collection.h"
#include "anchor_styles.h"
#include "auto_size_mode.h"
#include "bounds_specified.h"
#include "component.h"
#include "control_event_handler.h"
#include "control_styles.h"
#include "cursors.h"
#include "dock_style.h"
#include "iwin32_window.h"
#include "key_event_handler.h"
#include "key_press_event_handler.h"
#include "mouse_event_handler.h"
#include "padding.h"
#include "paint_event_handler.h"
#include "message.h"
#include "theme_colors.h"
#include "timer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class application;
    class screen;
    class control;
    /// @endcond
    
    /// @brief Represents a control reference.
    using control_ref = std::reference_wrapper<control>;

    /// @brief Defines the base class for controls, which are components with visual representation.
    /// @remarks To create your own control class, inherit from the user_control, control classes, or from the other Windows Forms provided controls. For more information about authoring custom controls, see Developing Custom Windows Forms Controls with xtd.
    /// @remarks The control class implements very basic functionality required by classes that display information to the user. It handles user input through the keyboard and pointing devices. It handles message routing and security. It defines the bounds of a control (its position and size), although it does not implement painting. It provides a window handle (hWnd).
    /// @remarks Windows Forms controls use ambient properties so child controls can appear like their surrounding environment. An ambient property is a control property that, if not set, is retrieved from the parent control. If the control does not have a parent, and the property is not set, the control attempts to determine the value of the ambient property through the site property. If the control is not sited, if the site does not support ambient properties, or if the property is not set on the ambient_properties, the control uses its own default values. Typically, an ambient property represents a characteristic of a control, such as back_color, that is communicated to a child control. For example, a button will have the same back_color as its parent form by default. Ambient properties provided by the control class include: cursor, font, back_color, fore_color, and right_to_left.
    /// @remarks The majority of the controls in the xtd::forms namespace use the underlying Windows common control as a base to build on.
    /// @par Example
    /// The following code example demonstrate the use of control control.
    /// @include control.cpp
    class control : public component, public iwin32_window {
    protected:
      /// @cond
      enum class state {
        empty = 0,
        creating = 0b1,
        created = 0b10,
        destroying = 0b100,
        destroyed = 0b1000,
        creating_handle = 0b10000,
        recreate = 0b100000,
        parent_recreating = 0b1000000,

        client_size_setted = 0b10000000,
        modal = 0b100000000,
        top_level = 0b1000000000,
        visible = 0b10000000000,
        enabled = 0b100000000000,
        auto_size = 0b1000000000000,
        tab_stop = 0b10000000000000,
        allow_drop = 0b100000000000000,
        drop_target = 0b1000000000000000,

        layout_deferred = 0b10000000000000000,
        docked = 0b100000000000000000,

        double_click_fired = 0b1000000000000000000,
        double_buffered = 0b10000000000000000000,
        /*
        mouse_enter_pending = 0,
        tracking_mouse_event = 0,
        mouse_pressed = 0,
        use_wait_cursor = 0,
         */

         /*
        is_accessible = 0,
        no_zorder = 0,
        size_locked_by_os = 0,
        causes_validation = 0,
        thread_marshall_pending = 0,
        own_ctl_brush = 0,
        exception_while_painting = 0,
        layout_sis_dirty = 0,
        checked_host = 0,
        hosted_in_dialog = 0,
        validation_cancelled = 0,
        mirrored = 0,
         */
      };
      /// @endcond
      
    public:
      class async_result_invoke {
      public:
        async_result_invoke(const async_result_invoke&) = default;
        async_result_invoke(async_result_invoke&&) = default;
        
        std::shared_mutex& async_mutex() {return *async_mutex_;}
        
      private:
        async_result_invoke() = default;
        friend class control;
        std::shared_ptr<std::shared_mutex> async_mutex_ = std::make_shared<std::shared_mutex>();
      };
      
      /// @brief Represents a collection of controls.
      using control_collection = layout::arranged_element_collection<control_ref>;
      
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
      
      /// @cond
      control(control&&) = delete;
      control(const control&) = delete;
      ~control();
      /// @endcond
      
      /// @brief Gets the edges of the container to which a control is bound and determines how a control is resized with its parent.
      /// @return A bitwise combination of the anchor_styles values. The default is top and left.
      /// @remarks Use the anchor property to define how a control is automatically resized as its parent control is resized. Anchoring a control to its parent control ensures that the anchored edges remain in the same position relative to the edges of the parent control when the parent control is resized.
      /// @remarks You can anchor a control to one or more edges of its container. For example, if you have a form with a button whose anchor property value is set to top and bottom, the button is stretched to maintain the anchored distance to the top and bottom edges of the form as the height of the form is increased.
      /// @note The anchor and dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Ineritors
      /// When overriding the anchor property in a derived class, use the base class's anchor property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the anchor property; you can override only one if needed.
      virtual anchor_styles anchor() const {return anchor_;}
      /// @brief Gets the edges of the container to which a control is bound and determines how a control is resized with its parent.
      /// @param anchor A bitwise combination of the anchor_styles values. The default is top and left.
      /// @remarks Use the anchor property to define how a control is automatically resized as its parent control is resized. Anchoring a control to its parent control ensures that the anchored edges remain in the same position relative to the edges of the parent control when the parent control is resized.
      /// @remarks You can anchor a control to one or more edges of its container. For example, if you have a form with a button whose anchor property value is set to top and bottom, the button is stretched to maintain the anchored distance to the top and bottom edges of the form as the height of the form is increased.
      /// @note The anchor and dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Ineritors
      /// When overriding the anchor property in a derived class, use the base class's anchor property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the anchor property; you can override only one if needed.
      virtual control& anchor(anchor_styles anchor);
      
      /// @brief Gets where this control is scrolled to in scroll_control_into_view(control).
      /// @return A point specifying the scroll location. The default is the upper-left corner of the control.
      virtual drawing::point auto_scroll_point() const {return auto_scroll_point_;}
      
      /// @brief Gets a value that indicates whether the control resizes based on its contents.
      /// @return true if enabled; otherwise, false.
      /// @remarks This property is not relevant for this class.
      virtual bool auto_size() const {return get_state(state::auto_size);}
      /// @brief Sets a value that indicates whether the control resizes based on its contents.
      /// @param auto_size true if enabled; otherwise, false.
      /// @return This control.
      /// @remarks This property is not relevant for this class.
      virtual control& auto_size(bool auto_size);

      /// @brief Gets the background color for the control.
      /// @return A xtd::drawing::color that represents the background color of the control. The default is the value of the default_back_color property.
      /// @remarks The back_color property does not support transparent colors unless the supports_transparent_back_color value of xtd::forms::control_styles is set to true.
      /// @remarks The back_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a button will have the same back_color as its parent form by default.
      virtual drawing::color back_color() const;
      /// @brief Sets the background color for the control.
      /// @param color A xtd::drawing::color that represents the background color of the control. The default is the value of the default_back_color property.
      /// @return This control.
      /// @remarks The back_color property does not support transparent colors unless the supports_transparent_back_color value of xtd::forms::control_styles is set to true.
      /// @remarks The back_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a button will have the same back_color as its parent form by default.
      /// @par Notes to Inheritors
      /// When overriding the back_color property in a derived class, use the base class's back_color property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the back_color property; you can override only one if needed.
      virtual control& back_color(const drawing::color& color);
      /// @cond
      virtual control& back_color(nullptr_t);
      /// @endcond

      /// @brief Gets the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      /// @return An int32_t representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      /// @remarks The value of this property is equal to the sum of the top property value, and the height property value.
      /// @remarks The bottom property is a read-only property. You can manipulate this property value by changing the value of the top or height properties or calling the set_bounds, set_bounds_core, update_bounds, or set_client_size_core methods.
      virtual int32_t bottom() const {return top() + height();}
      
      /// @brief Gets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
      /// @return A rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
      /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus.
      virtual drawing::rectangle bounds() const {return {location_, size_};}
      /// @brief Sets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
      /// @param A rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
      /// @return This control.
      /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus. The Set_bounds_core method is called to set the bounds property. The bounds property is not always changed through its set method so you should override the set_bounds_core method to ensure that your code is executed when the bounds property is set.
      virtual control& bounds(const drawing::rectangle& bounds) {
        set_bounds_core(bounds.x(), bounds.y(), bounds.width(), bounds.height(), bounds_specified::all);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the control can receive focus.
      /// @brief true if the control can receive focus; otherwise, false.
      /// @remarks In order for a control to receive input focus, the control must have a handle assigned to it, and the visible and enabled properties must both be set to true for both the control and all its parent controls, and the control must be a form or the control's outermost parent must be a form.
      virtual bool can_focus() const;
      
      /// @brief Gets a value indicating whether the control can be selected.
      /// @return true if the control can be selected; otherwise, false.s
      /// @remarks This property returns true if the electable value of control_styles is set to true, is contained in another control, the control itself is visible and enabled, and all its parent controls are visible and enabled.
      /// @remarks The Windows Forms controls in the following list are not selectable and will return a value of false for the can_select property. controls derived from these controls are also not selectable.
      /// * panel
      /// * group_box
      /// * picture_box
      /// * progress_bar
      /// * splitter
      /// * label
      /// * link_label (when there is no link present in the control)
      virtual bool can_select() const {return enabled() &&  visible() && get_style(control_styles::selectable);}
      
      /// @brief Determines if events can be raised on the control.
      /// @return true if the control ican raise events; otherwise, false.
      bool can_raise_events() const override {return can_raise_events_;}

      /// @brief Gets the rectangle that represents the client area of the control.
      /// @return A rectangle that represents the client area of the control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
      /// @remarks Because client coordinates are relative to the upper-left corner of the client area of the control, the coordinates of the upper-left corner of the rectangle returned by this property are (0,0). You can use this property to obtain the size and coordinates of the client area of the control for tasks such as drawing on the surface of the control.
      virtual const drawing::rectangle& client_rectangle() const {return client_rectangle_;}

      /// @brief Gets  the height and width of the client area of the control.
      /// @return A size that represents the dimensions of the client area of the control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
      virtual const drawing::size& client_size() const {return client_size_;}
      /// @brief Sets the height and width of the client area of the control.
      /// @param A size that represents the dimensions of the client area of the control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus. The set_client_size_core method is called to set the client_size property. The client_size property is not always changed through its set method so you should override the set_client_sizeCore method to ensure that your code is executed when the client_size property is set.
      virtual control& client_size(const drawing::size& client_size) {
        if (!get_state(state::client_size_setted) || client_size_ != client_size) {
          set_state(state::client_size_setted, true);
          set_client_size_core(client_size.width(), client_size.height());
        }
        return *this;
      }
      
      /// @brief Gets the name of the company or creator of the application containing the control.
      /// @return The company name or creator of the application containing the control.
      virtual std::string compagny_name() const {return "Gammasoft";}
      
      /// @brief Gets the collection of controls contained within the control.
      /// @return A control::control_collection representing the collection of controls contained within the control.
      /// @remarks A control can act as a parent to a collection of controls. For example, when several controls are added to a form, each of the controls is a member of the control::control_collection assigned to the controls property of the form, which is derived from the control class.
      /// @remarks You can manipulate the controls in the control::control_collection assigned to the controls property by using the methods available in the control::control_collection class.
      /// @remarks When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. Doing so will increase the performance of applications with many controls.
      /// @remarks Use the controls property to iterate through all controls of a form, including nested controls. Use the get_next_control method to retrieve the previous or next child control in the tab order. Use the active_control property to get or set the active control of a container control.
      virtual control_collection& controls() {return controls_;}
      /// @brief Gets the collection of controls contained within the control.
      /// @return A control::control_collection representing the collection of controls contained within the control.
      /// @remarks A control can act as a parent to a collection of controls. For example, when several controls are added to a form, each of the controls is a member of the control::control_collection assigned to the controls property of the form, which is derived from the control class.
      /// @remarks You can manipulate the controls in the control::control_collection assigned to the controls property by using the methods available in the control::control_collection class.
      /// @remarks When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. Doing so will increase the performance of applications with many controls.
      /// @remarks Use the controls property to iterate through all controls of a form, including nested controls. Use the get_next_control method to retrieve the previous or next child control in the tab order. Use the active_control property to get or set the active control of a container control.
      virtual const control_collection& controls() const {return controls_;}

      /// @brief Gets a value indicating whether the control has been created.
      /// @return true if the control has been created; otherwise, false.
      /// @remarks The created property returns true if the control was successfully created even though the control's handle might not have been created or recreated yet.
      virtual bool created() {return get_state(state::created);}
      
      virtual forms::cursor cursor() const;
      virtual control& cursor(const forms::cursor& cursor);
      /// @cond
      virtual control& cursor(nullptr_t);
      /// @endcond

      /// @brief Gets the default background color of the control.
      /// @return The default background color of the control. The default is control.
      /// @remarks This is the default back_color property value of a generic top-level control. Derived classes can have different defaults.
      virtual drawing::color default_back_color() const {return xtd::forms::theme_colors::current_theme().control();}

      virtual forms::cursor default_cursor() const {return cursors::default_cursor();}

      virtual drawing::color default_fore_color() const {return xtd::forms::theme_colors::current_theme().control_text();}
      
      virtual drawing::font default_font() const;
      
      virtual drawing::size default_size() const {return {0, 0};}
      
      virtual drawing::rectangle display_rectangle() const {return client_rectangle_;}
      
      /// @brief Gets or sets which control borders are docked to its parent control and determines how a control is resized with its parent.
      /// @return One of the dock_style values. The default is none.
      /// @remarks Use the dock property to define how a control is automatically resized as its parent control is resized. For example, setting dock to dock_style::left causes the control to align itself with the left edges of its parent control and to resize as the parent control is resized. Controls are docked in their Z-order, which is the visual layering of controls on a form along the form's Z-axis (depth).
      /// @remarks A control can be docked to one edge of its parent container or can be docked to all edges and fill the parent container.
      /// @remarks Setting the margin property on a docked control has no effect on the distance of the control from the edges of its container.
      /// @note The anchor and dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the dock property in a derived class, use the base class's dock property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set methods of the dock property; you can override only one if needed.
      virtual dock_style dock() const {return dock_;}
      virtual control& dock(dock_style dock);

      virtual bool double_buffered() const {return get_state(state::double_buffered);}
      virtual control& double_buffered(bool double_buffered) {
        set_state(state::double_buffered, double_buffered);
        return *this;
      }
      
      virtual bool enabled() const {return get_state(state::enabled);}
      virtual control& enabled(bool enabled);

      virtual bool focused() const {return focused_;}
      virtual drawing::color fore_color() const;
      virtual control& fore_color(const drawing::color& color);
      /// @cond
      virtual control& fore_color(nullptr_t);
      /// @endcond

      virtual drawing::font font() const;
      virtual control& font(const drawing::font& font);
      /// @cond
      virtual control& font(nullptr_t);
      /// @endcond

      intptr_t handle() const override;
      
      virtual int32_t height() const {return size_.height();}
      virtual control& height(int32_t height) {
        if (size_.height() != height)
          set_bounds_core(0, 0, 0, height, bounds_specified::height);
        return *this;
      }
      
      virtual int32_t left() const {return location_.x();}
      virtual control& left(int32_t left) {
        if (location_.x() != left)
          set_bounds_core(left, 0, 0, 0, bounds_specified::x);
        return *this;
      }

      virtual drawing::point location() const {return location_;}
      virtual control& location(const drawing::point& location) {
        if (location_ != location)
          set_bounds_core(location.x(), location.y(), 0, 0, bounds_specified::location);
        return *this;
      }
      
      virtual forms::padding margin() const {return margin_;}
      virtual control& margin(const forms::padding& margin) {
        if (margin_ != margin)
          margin_ = margin;
        return *this;
      }

      static forms::keys modifier_keys() {return modifier_keys_;}
      
      static forms::mouse_buttons mouse_buttons() {return mouse_buttons_;}
      
      virtual const std::string& name() const {return name_;}
      virtual control& name(const std::string& name) {
        name_ = name;
        return*this;
      }
      
      virtual forms::padding padding() const {return padding_;}
      virtual control& padding(const forms::padding& padding) {
        if (padding_ != padding)
          padding_ = padding;
        return *this;
      }
      
      virtual std::optional<control_ref> parent() const {return from_handle(parent_);}
      virtual control& parent(const control& parent);
      virtual control& parent(std::nullptr_t);

      virtual std::string product_name() const {return "xtd";}
      
      bool recreating_handle() const {return get_state(state::recreate);}
      
      virtual int32_t right() const {return left() + width();}

      virtual drawing::size size() const {return size_;}
      virtual control& size(const drawing::size& size) {
        if (get_state(state::client_size_setted) || size_ != size) {
          set_state(state::client_size_setted, false);
          set_bounds_core(0, 0, size.width(), size.height(), bounds_specified::size);
        }
        return *this;
      }
      
      /// @brief Gets the object that contains data about the control.
      /// @return A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      virtual std::any tag() const {return tag_;}
      
      /// @brief Sets the object that contains data about the control.
      /// @param tag A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      virtual control& tag(std::any tag) {
        tag_ = tag;
        return*this;
      }
      
      virtual const std::string& text() const {return text_;}
      virtual control& text(const std::string& text);

      virtual int32_t top() const {return location_.y();}
      virtual control& top(int32_t top) {
        if (location_.y() != top)
          set_bounds_core(0, top, 0, 0, bounds_specified::y);
        return *this;
      }
      
      virtual std::optional<control_ref> top_level_control() const;

      virtual bool visible() const {return get_state(state::visible);}
      virtual control& visible(bool visible);

      virtual int32_t width() const {return size_.width();}
      virtual control& width(int32_t width) {
        if (size_.width() != width)
          set_bounds_core(0, 0, width, 0, bounds_specified::width);
        return *this;
      }
      
      friend control& operator<<(control& parent, control& child) {
        child.parent(parent);
        return parent;
      }
      
      virtual void bring_to_front();

      template<typename control_t>
      static std::unique_ptr<control_t> create(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        if (location != drawing::point {-1, -1}) item->location(location);
        if (size != drawing::size {-1, -1}) item->size(size);
        if (back_color != drawing::color::empty) item->back_color(back_color);
        if (fore_color != drawing::color::empty) item->fore_color(fore_color);
        return item;
      }
      
      template<typename control_t>
      static std::unique_ptr<control_t> create(const control& parent, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->parent(parent);
        if (location != drawing::point {-1, -1}) item->location(location);
        if (size != drawing::size {-1, -1}) item->size(size);
        if (back_color != drawing::color::empty) item->back_color(back_color);
        if (fore_color != drawing::color::empty) item->fore_color(fore_color);
        return item;
      }
      
      template<typename control_t>
      static std::unique_ptr<control_t> create(const std::string& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->text(text);
        if (location != drawing::point {-1, -1}) item->location(location);
        if (size != drawing::size {-1, -1}) item->size(size);
        if (back_color != drawing::color::empty) item->back_color(back_color);
        if (fore_color != drawing::color::empty) item->fore_color(fore_color);
        return item;
      }
      
      template<typename control_t>
      static std::unique_ptr<control_t> create(const control& parent, const std::string& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->parent(parent);
        item->text(text);
        if (location != drawing::point {-1, -1}) item->location(location);
        if (size != drawing::size {-1, -1}) item->size(size);
        if (back_color != drawing::color::empty) item->back_color(back_color);
        if (fore_color != drawing::color::empty) item->fore_color(fore_color);
        return item;
      }

      void create_control();
      
      void destroy_control();
      
      virtual void create_handle();
      
      drawing::graphics create_graphics() const;

      virtual void destroy_handle();
      
      bool focus();
      
      static std::optional<control_ref> from_child_handle(intptr_t handle);

      static std::optional<control_ref> from_handle(intptr_t handle);
      
      virtual void hide() {visible(false);}
      
      virtual void invalidate() const {invalidate({{0, 0}, client_size()}, true);}

      virtual void invalidate(bool invalidate_children) const {invalidate({{0, 0}, client_size()}, invalidate_children);}

      virtual void invalidate(const drawing::rectangle& rect) const {invalidate(rect, true);}
      
      virtual void invalidate(const drawing::rectangle& rect, bool invalidate_children) const;

      async_result_invoke begin_invoke(delegate<void(std::vector<std::any>)> value, const std::vector<std::any>& args);
      
      async_result_invoke begin_invoke(delegate<void()> value) {return begin_invoke(delegate<void(std::vector<std::any>)>(value), {});}
      
      void end_invoke(async_result_invoke async);
      
      /// @cond
      template<typename delegate_t>
      async_result_invoke begin_invoke(delegate_t value, const std::vector<std::any>& args) {return begin_invoke(delegate<void(std::vector<std::any>)>(value), args);}
      
      template<typename delegate_t>
      async_result_invoke begin_invoke(delegate_t value) {return begin_invoke(delegate<void(std::vector<std::any>)>(value), {});}
      /// @endcond

      void invoke(delegate<void(std::vector<std::any>)> value, const std::vector<std::any>& args) {end_invoke(begin_invoke(value, args));}
      
      void invoke(delegate<void()> value) {invoke(delegate<void(std::vector<std::any>)>(value), {});}

      /// @cond
      template<typename delegate_t>
      void invoke(delegate_t value, const std::vector<std::any>& args) {invoke(delegate<void(std::vector<std::any>)>(value), args);}
      
      template<typename delegate_t>
      void invoke(delegate_t value) {invoke(delegate<void(std::vector<std::any>)>(value), {});}
      /// @endcond

      bool is_handle_created() const;

      /// @brief Forces the control to apply layout logic to all its child controls.
      /// @remarks If the suspend_layout method was called before calling the perform_layout method, the layout event is suppressed.
      void perform_layout() {on_layout(event_args::empty);}
      
      xtd::drawing::point point_to_client(const xtd::drawing::point& p);
      
      xtd::drawing::point point_to_screen(const xtd::drawing::point& p);

      virtual void refresh() const;
      
      /// @brief Resumes usual layout logic.
      /// @remarks Calling the resume_layout method forces an immediate layout if there are any pending layout requests.
      /// @remarks The suspend_layout and resume_layout methods are used in tandem to suppress multiple layout events while you adjust multiple attributes of the control. For example, you would typically call the suspend_layout method, then set the size, location, anchor, or dock properties of the control, and then call the resume_layout method to enable the changes to take effect.
      /// @remarks There must be no pending calls to suspend_layout for resume_layout to be successfully called.
      void resume_layout() {resume_layout(true);}
      
      /// @brief Resumes usual layout logic, optionally forcing an immediate layout of pending layout requests.
      /// @param perform_layout true to execute pending layout requests; otherwise, false.
      /// @remarks Calling the resume_layout method forces an immediate layout if there are any pending layout requests. When the perform_layout parameter is set to true, an immediate layout occurs if there are any pending layout requests.
      /// @remarks The suspend_layout and resume_layout methods are used in tandem to suppress multiple layout events while you adjust multiple attributes of the control. For example, you would typically call the suspend_layout method, then set the size, location, anchor, or dock properties of the control, and then call the resume_layout method to enable the changes to take effect.
      /// @remarks There must be no pending calls to suspend_layout for resume_layout to be successfully called.
      /// @note When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. This will increase the performance of applications with many controls.
      void resume_layout(bool perform_layout) {
        set_state(state::layout_deferred, false);
        if (perform_layout) this->perform_layout();
      }
      
      intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) const;
      
      void set_auto_size_mode(auto_size_mode auto_size_mode);
      
      void set_bounds(int32_t x, int32_t y, int32_t width, int32_t height) {set_bounds(x, y, width, height, bounds_specified::all);}

      void set_bounds(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {set_bounds_core(x, y, width, height, specified);}

      virtual void show() {visible(true);}
      
      /// @brief Temporarily suspends the layout logic for the control.
      /// @remarks The layout logic of the control is suspended until the resume_layout method is called.
      /// @remarks The suspend_layout and resume_layout methods are used in tandem to suppress multiple layout events while you adjust multiple attributes of the control. For example, you would typically call the suspend_layout method, then set the size, location, anchor, or dock properties of the control, and then call the resume_layout method to enable the changes to take effect.
      /// @remarks There must be no pending calls to suspend_layout for resume_layout to be successfully called.
      /// @note When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. This will increase the performance of applications with many controls.
      void suspend_layout() {
        set_state(state::layout_deferred, true);
      }
      
      virtual std::string to_string() const;
      
      virtual void update() const;
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::control& control) noexcept {
        return os << control.to_string();
      }
      
      bool operator==(const control& value) const {return this == &value;}
      bool operator!=(const control& value) const {return !operator==(value);}
      /// @endcond

      event<control, event_handler<control&>> auto_size_changed;

      event<control, event_handler<control&>> back_color_changed;
      
      event<control, event_handler<control&>> click;
      
      event<control, event_handler<control&>> client_size_changed;
        
      event<control, event_handler<control&>> cursor_changed;

      event<control, control_event_handler<control&>> control_added;
      
      event<control, control_event_handler<control&>> control_removed;
      
      event<control, event_handler<control&>> dock_changed;
        
      event<control, event_handler<control&>> double_click;

      event<control, event_handler<control&>> got_focus;
      
      event<control, event_handler<control&>> handle_created;
      
      event<control, event_handler<control&>> handle_destroyed;
      
      event<control, event_handler<control&>> enabled_changed;

      event<control, event_handler<control&>> fore_color_changed;
      
      event<control, event_handler<control&>> font_changed;
      
      event<control, key_event_handler<control&>> key_down;
      
      event<control, key_press_event_handler<control&>> key_press;
      
      event<control, key_event_handler<control&>> key_up;
      
      /// @brief Occurs when a control should reposition its child controls.
      /// @remarks The layout event occurs when child controls are added or removed, when the bounds of the control changes, and when other changes occur that can affect the layout of the control. The layout event can be suppressed using the suspend_layout and resume_layout methods. Suspending layout enables you to perform multiple actions on a control without having to perform a layout for each change. For example, if you resize and move a control, each operation would raise a layout event.
      event<control, event_handler<control&>> layout;
      
      event<control, event_handler<control&>> location_changed;
      
      event<control, event_handler<control&>> lost_focus;
      
      event<control, mouse_event_handler<control&>> mouse_click;
      
      event<control, mouse_event_handler<control&>> mouse_double_click;
      
      event<control, mouse_event_handler<control&>> mouse_down;
      
      event<control, event_handler<control&>> mouse_enter;
      
      event<control, mouse_event_handler<control&>> mouse_horizontal_wheel;
      
      event<control, event_handler<control&>> mouse_leave;
      
      event<control, mouse_event_handler<control&>> mouse_move;
      
      event<control, mouse_event_handler<control&>> mouse_up;
      
      event<control, mouse_event_handler<control&>> mouse_wheel;
      
      event<control, paint_event_handler<control&>> paint;
      
      event<control, event_handler<control&>> parent_changed;
      
      event<control, event_handler<control&>> resize;
        
      event<control, event_handler<control&>> size_changed;

      event<control, event_handler<control&>> text_changed;
      
      event<control, event_handler<control&>> visible_changed;

    protected:
      friend class application;
      friend class screen;
      
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      /// @remarks The create_params property should not be overridden and used to adjust the properties of your derived control. Properties such as the create_params::caption, create_params::width, and create_params::height should be set by the corresponding properties in your control such as control::text, control::width and control::height. The create_params should only be extended when you are wrapping a standard Windows control class or to set styles not provided by the forms namespace.
      /// @par Notes for inheritors
      /// When overriding the create_params property in a derived class, use the base class's create_params property to extend the base implementation. Otherwise, you must provide all the implementation.
      virtual forms::create_params create_params() const;
      
      virtual void def_wnd_proc(message& message);

      /// @brief Retrieves the value of the specified control style bit for the control.
      /// @param flag The control_styles bit to return the value from.
      /// @return true if the specified control style bit is set to true; otherwise, false.
      /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the set_style method and passing in the appropriate control_styles bit and the bool value to set the bit to. To determine the value assigned to a specified control_styles bit, use the get_style method and pass in the control_styles member to evaluate.
      bool get_style(control_styles flag) const {return ((int32_t)style_ & (int32_t)flag) == (int32_t)flag;}

      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
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
      
      virtual void on_cursor_changed(const event_args& e);

      virtual void on_dock_changed(const event_args& e);
        
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

      virtual void on_layout(const event_args& e);

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
        
      virtual void on_parent_cursor_changed(const event_args& e);

      virtual void on_parent_changed(const event_args& e);
      
      virtual void on_parent_fore_color_changed(const event_args& e);
      
      virtual void on_parent_font_changed(const event_args& e);
      
      virtual void on_resize(const event_args& e);
        
      virtual void on_size_changed(const event_args& e);

      virtual void on_text_changed(const event_args& e);
      
      virtual void on_visible_changed(const event_args& e);

      virtual void recreate_handle();
 
      /// @brief Performs the work of setting the specified bounds of this control.
      /// @param x The new left property value of the control.
      /// @param y The new top property value of the control.
      /// @param width The new width property value of the control.
      /// @param height The new height property value of the control.
      /// @param specified A bitwise combination of the bounds_specified values.
      /// @remarks Typically, the parameters that correspond to the bounds not included in the specified parameter are passed in with their current values. For example, the height, width, or the y or y properties of the location property can be passed in with a reference to the current instance of the control. However all values passed in are honored and applied to the control.
      /// @remarks The specified parameter represents the elements of the controls Bounds changed by your application. For example, if you change the size of the control, the specified parameter value is the size value of bounds_specified. However, if the size is adjusted in response to the dock property being set, the pecified parameter value is the none value of bounds_specified.
      /// @par Notes to Inheritors
      /// When overriding set_bounds_core(int32_t, int32_t, int32_t, int32_t, bounds_specified) in a derived class, be sure to call the base class's set_bounds_core(int32_t, int32_t, int32_t, int32_t, bounds_specified) method to force the bounds of the control to change. Derived classes can add size restrictions to the set_bounds_core(int32_t, int32_t, int32_t, int32_t, bounds_specified) method.
      virtual void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified);
      
      /// @brief Sets the size of the client area of the control.
      /// @param width The client area width, in pixels.
      /// @param height The client area height, in pixels.
      /// @remarks The client area starts at the (0, 0) location and extends to the (width, height) location.
      /// @remarks Typically, you should not set the client_size of the control.
      /// @par Notes to Inheritors
      /// When overriding set_client_size_core(int32_t, int32_t) in a derived class, be sure to call the base class's set_client_size_core(int32_t, int32_t) method so that the client_size property is adjusted.
      virtual void set_client_size_core(int32_t width, int32_t height);
        
      /// @brief Sets a specified control_styles flag to either true or false.
      /// @param flag The control_styles bit to set.
      /// @param value true to apply the specified style to the control; otherwise, false.
      /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the set_style method and passing in the appropriate control_styles bit (or bits) and the bool value to set the bit(s) to. To determine the value assigned to a specified control_styles bit, use the get_style method and pass in the control_styles member to evaluate.
      /// @warning Setting the control style bits can substantially change the behavior of the control. Review the control_styles enumeration documentation to understand the effects of changing the control style bits before calling the set_style method.
      void set_style(control_styles flag, bool value) {style_ = value ? (control_styles)((int32_t)style_ | (int32_t)flag) : (control_styles)((int32_t)style_ & ~(int32_t)flag);}

      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      /// @par Notes to Inheritors
      /// Inheriting controls should call the base class's wnd_proc(message&) method to process any messages that they do not handle.
      virtual void wnd_proc(message& m);

      /// @cond
      bool get_state(control::state flag) const {return ((int32_t)state_ & (int32_t)flag) == (int32_t)flag;}
      void set_state(control::state flag, bool value) { state_ = value ? (control::state)((int32_t)state_ | (int32_t)flag) : (control::state)((int32_t)state_ & ~(int32_t)flag); }

      anchor_styles anchor_ = anchor_styles::top | anchor_styles::left;
      drawing::point auto_scroll_point_;
      auto_size_mode auto_size_mode_ = auto_size_mode::grow_and_shrink;
      std::optional<drawing::color> back_color_;
      bool can_focus_ = true;
      bool can_raise_events_ = true;
      drawing::rectangle client_rectangle_;
      drawing::size client_size_;
      control_collection controls_;
      std::optional<forms::cursor> cursor_;
      dock_style dock_ = dock_style::none;
      bool focused_ = false;
      std::optional<drawing::color> fore_color_;
      std::optional<drawing::font> font_;
      intptr_t handle_ = 0;
      drawing::point location_;
      forms::padding margin_ {3};
      forms::padding padding_;
      static forms::keys modifier_keys_;
      static forms::mouse_buttons mouse_buttons_;
      bool mouse_left_down_ = false;
      std::string name_;
      intptr_t parent_ = 0;
      drawing::size parent_size_;
      drawing::size size_;
      control::state state_ = state::empty;
      control_styles style_ = control_styles::none;
      std::any tag_;
      std::string text_;
      static std::map<intptr_t, control*> handles_;
      static control_collection top_level_controls_;
      /// @endcond
      
    private:
      void on_parent_size_changed(const control& sender, const event_args& e);
      void do_layout_childs_with_dock_style();
      void do_layout_with_auto_size_mode();
      void do_layout_with_anchor_styles();
      control(const std::string& name, bool) {name_ = name;}
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
      void wm_scroll(message& message);
      void wm_set_focus(message& message);
      void wm_set_text(message& message);
      void wm_size(message& message);
    };
  }
}
