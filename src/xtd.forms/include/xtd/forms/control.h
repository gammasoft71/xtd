/// @file
/// @brief Contains xtd::forms::control control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <condition_variable>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <thread>
#include <vector>
#include <xtd/iasync_result.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/point.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/drawing/size.h>
#include <xtd/forms/create_params.h>

#include "../forms_export.h"
#include "layout/arranged_element_collection.h"
#include "anchor_styles.h"
#include "auto_size_mode.h"
#include "bounds_specified.h"
#include "component.h"
#include "control_event_handler.h"
#include "control_ref.h"
#include "control_styles.h"
#include "cursors.h"
#include "dock_style.h"
#include "image_layout.h"
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
    /// @endcond
    
    /// @brief Defines the base class for controls, which are components with visual representation.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks To create your own control class, inherit from the xtd::forms::user_control, control classes, or from the other Windows Forms provided controls.
    /// @remarks The control class implements very basic functionality required by classes that display information to the user. It handles user input through the keyboard and pointing devices. It handles message routing and security. It defines the bounds of a control (its position and size), although it does not implement painting. It provides a window handle (hWnd).
    /// @remarks Windows Forms controls use ambient properties so child controls can appear like their surrounding environment. An ambient property is a control property that, if not set, is retrieved from the parent control. If the control does not have a parent, and the property is not set, the control attempts to determine the value of the ambient property through the site property. If the control is not sited, if the site does not support ambient properties, or if the property is not set on the ambient_properties, the control uses its own default values. Typically, an ambient property represents a characteristic of a control, such as back_color, that is communicated to a child control. For example, a button will have the same back_color as its parent form by default. Ambient properties provided by the control class include: cursor, font, back_color, fore_color, and right_to_left.
    /// @remarks The majority of the controls in the xtd::forms namespace use the underlying Windows common control as a base to build on.
    /// @par Examples
    /// The following code example demonstrate the use of control control.
    /// @include control.cpp
    class forms_export_ control : public component, public iwin32_window {
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
      
      class async_result_invoke : public xtd::iasync_result {
      public:
        async_result_invoke(std::any async_state) : async_state_(async_state) {}
        std::any async_state() const noexcept override {return async_state_;}
        std::shared_mutex& async_mutex() override {return *async_mutex_;}
        bool completed_synchronously() const noexcept override {return false;}
        bool is_completed() const noexcept override {return *is_completed_;};
        
        std::any async_state_;
        std::shared_ptr<bool> is_completed_ = std::make_shared<bool>(false);
        std::shared_ptr<std::shared_mutex> async_mutex_ = std::make_shared<std::shared_mutex>();
      };
      
    public:
      /// @brief Represents a collection of controls.
      class control_collection : public xtd::forms::layout::arranged_element_collection<control_ref> {
      public:
        /// @brief Represents the base type of the collection.
        using base = xtd::forms::layout::arranged_element_collection<control_ref>;
        
        /// @brief Creates a new object xtd::forms::control::control_collection with specified allocator (optional).
        /// @param allocator The allocator associate to the collection (optional).
        /// @remarks If allocator not specified, the std::allocator<value_type> is used.
        explicit control_collection(const allocator_type& allocator = allocator_type());
        /// @cond
        control_collection(const base& collection);
        control_collection(const control_collection& collection);
        control_collection& operator=(const control_collection& collection);
        control_collection(control_collection&&) = default;
        /// @endcond
        
        using base::operator[];
        /// @brief Gets the first xtd::forms::control::control_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator[] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator[] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        std::optional<value_type> operator[](const xtd::ustring& name) const;
        /// @brief Gets the first xtd::forms::control::control_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator[] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator[] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        std::optional<value_type> operator[](const xtd::ustring& name);
      };
      
      /// @brief Initializes a new instance of the control class with default settings.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      control();
      /// @brief Initializes a new instance of the control class with specific text.
      /// @param text The text displayed by the control.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the control constructor sets the initial text property value to the text parameter value.
      explicit control(const xtd::ustring& text) : control() {
        this->text(text);
      }
      /// @brief Initializes a new instance of the control class as a child control, with specific text.
      /// @param parent The control to be the parent of the control.
      /// @param text The text displayed by the control.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the control constructor sets the initial text property value to the text parameter value. The constructor also adds the control to the parent control's control::control_collection.
      explicit control(const control& parent, const xtd::ustring& text) : control() {
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
      explicit control(const xtd::ustring& text, int32_t left, int32_t top, int32_t width, int32_t height) : control() {
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
      explicit control(const control& parent, const xtd::ustring& text, int32_t left, int32_t top, int32_t width, int32_t height) : control() {
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
      /// @par Notes to Inheritors
      /// When overriding the anchor property in a derived class, use the base class's anchor property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the anchor property; you can override only one if needed.
      virtual anchor_styles anchor() const {return anchor_;}
      /// @brief Gets the edges of the container to which a control is bound and determines how a control is resized with its parent.
      /// @param anchor A bitwise combination of the anchor_styles values. The default is top and left.
      /// @return Current control.
      /// @remarks Use the anchor property to define how a control is automatically resized as its parent control is resized. Anchoring a control to its parent control ensures that the anchored edges remain in the same position relative to the edges of the parent control when the parent control is resized.
      /// @remarks You can anchor a control to one or more edges of its container. For example, if you have a form with a button whose anchor property value is set to top and bottom, the button is stretched to maintain the anchored distance to the top and bottom edges of the form as the height of the form is increased.
      /// @note The anchor and dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
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
      /// @return Current control.
      /// @remarks This property is not relevant for this class.
      virtual control& auto_size(bool auto_size);

      /// @brief Gets the background color for the control.
      /// @return A xtd::drawing::color that represents the background color of the control. The default is the value of the default_back_color property.
      /// @remarks The back_color property does not support transparent colors unless the supports_transparent_back_color value of xtd::forms::control_styles is set to true.
      /// @remarks The back_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a button will have the same back_color as its parent form by default.
      virtual drawing::color back_color() const;
      /// @brief Sets the background color for the control.
      /// @param color A xtd::drawing::color that represents the background color of the control. The default is the value of the default_back_color property.
      /// @return Current control.
      /// @remarks The back_color property does not support transparent colors unless the supports_transparent_back_color value of xtd::forms::control_styles is set to true.
      /// @remarks The back_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a button will have the same back_color as its parent form by default.
      /// @par Notes to Inheritors
      /// When overriding the back_color property in a derived class, use the base class's back_color property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the back_color property; you can override only one if needed.
      virtual control& back_color(const drawing::color& color);
      /// @cond
      virtual control& back_color(nullptr_t);
      /// @endcond

      /// @brief Gets the background image displayed in the control.
      /// @return An xtd::drawing::image that represents the image to display in the background of the control.
      /// @remarks Use the background_image property to place a graphic image onto a control.
      virtual const xtd::drawing::image& background_image() const {return background_image_;}
      /// @brief Sets the background image displayed in the control.
      /// @param background_image An xtd::drawing::image that represents the image to display in the background of the control.
      /// @return Current control.
      /// @remarks Use the background_image property to place a graphic image onto a control.
      virtual control& background_image(const xtd::drawing::image& background_image);
      
      /// @brief Gets the background image layout as defined in the xtd::forms::image_layout enumeration.
      /// @return One of the values of xtd::forms::image_layout (center , none, stretch, tile, or zoom). tile is the default value.
      /// @remarks Use the background_image_layout property to specify the position and behavior of an image you have placed onto a control. background_image_layout takes effect only if the background_image property is set.
      /// @remarks You can increase performance for large images if you set background_image_layout to something other than tile.
      virtual xtd::forms::image_layout background_image_layout() const {return background_image_layout_;}
      
      /// @brief Sets the background image layout as defined in the xtd::forms::image_layout enumeration.
      /// @param background_image_layout One of the values of xtd::forms::image_layout (center , none, stretch, tile, or zoom). tile is the default value.
      /// @return Current control.
      /// @remarks Use the background_image_layout property to specify the position and behavior of an image you have placed onto a control. background_image_layout takes effect only if the background_image property is set.
      /// @remarks You can increase performance for large images if you set background_image_layout to something other than tile.
      virtual control& background_image_layout(xtd::forms::image_layout background_image_layout);
      
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
      /// @param bounds A rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
      /// @return Current control.
      /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus. The Set_bounds_core method is called to set the bounds property. The bounds property is not always changed through its set method so you should override the set_bounds_core method to ensure that your code is executed when the bounds property is set.
      virtual control& bounds(const drawing::rectangle& bounds) {
        set_bounds_core(bounds.x(), bounds.y(), bounds.width(), bounds.height(), bounds_specified::all);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the control can receive focus.
      /// @return true if the control can receive focus; otherwise, false.
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
      /// @return true if the control can raise events; otherwise, false.
      bool can_raise_events() const override {return can_raise_events_;}

      /// @brief Gets the rectangle that represents the client area of the control.
      /// @return A rectangle that represents the client area of the control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
      /// @remarks Because client coordinates are relative to the upper-left corner of the client area of the control, the coordinates of the upper-left corner of the rectangle returned by this property are (0,0). You can use this property to obtain the size and coordinates of the client area of the control for tasks such as drawing on the surface of the control.
      virtual const drawing::rectangle& client_rectangle() const {return client_rectangle_;}

      /// @brief Gets the height and width of the client area of the control.
      /// @return A size that represents the dimensions of the client area of the control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
      virtual const drawing::size& client_size() const {return client_size_;}
      /// @brief Sets the height and width of the client area of the control.
      /// @param client_size A size that represents the dimensions of the client area of the control.
      /// @return Current control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus. The set_client_size_core method is called to set the client_size property. The client_size property is not always changed through its set method so you should override the set_client_size_core method to ensure that your code is executed when the client_size property is set.
      virtual control& client_size(const drawing::size& client_size) {
        if (!get_state(state::client_size_setted) || client_size_ != client_size) {
          set_state(state::client_size_setted, true);
          set_client_size_core(client_size.width(), client_size.height());
        }
        return *this;
      }
      
      /// @brief Gets the name of the company or creator of the application containing the control.
      /// @return The company name or creator of the application containing the control.
      virtual xtd::ustring company_name() const {return "Gammasoft";}
      
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
      
      /// @brief Gets the cursor that is displayed when the mouse pointer is over the control.
      /// @return A xtd::forms::cursor that represents the cursor to display when the mouse pointer is over the control.
      virtual forms::cursor cursor() const;
      /// @brief Sets the cursor that is displayed when the mouse pointer is over the control.
      /// @param cursor A xtd::forms::cursor that represents the cursor to display when the mouse pointer is over the control.
      /// @return Current control.
      virtual control& cursor(const forms::cursor& cursor);
      /// @cond
      virtual control& cursor(nullptr_t);
      /// @endcond

      /// @brief Gets the default background color of the control.
      /// @return The default background color of the control. The default is control.
      /// @remarks This is the default back_color property value of a generic top-level control. Derived classes can have different defaults.
      virtual drawing::color default_back_color() const {return xtd::forms::theme_colors::current_theme().control();}

      /// @brief Gets the default cursor for the control.
      /// @return An object of type xtd::forms::cursor representing the current default cursor.
      virtual forms::cursor default_cursor() const {return cursors::default_cursor();}

      /// @brief Gets the default font of the control.
      /// @return The default font of the control. The value returned will vary depending on the user's operating system the local culture setting of their system.
      virtual drawing::font default_font() const;

      /// @brief Gets the default foreground color of the control.
      /// @return The default foreground color of the control. The default is control_text.
      virtual drawing::color default_fore_color() const {return xtd::forms::theme_colors::current_theme().control_text();}
      
      /// @brief Gets the default size of the control.
      /// @return The default size of the control.
      virtual drawing::size default_size() const {return {0, 0};}
      
      /// @brief Gets the rectangle that represents the display area of the control.
      /// @return A rectangle that represents the display area of the control.
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
      /// @brief Sets or sets which control borders are docked to its parent control and determines how a control is resized with its parent.
      /// @param dock One of the dock_style values. The default is none.
      /// @return Current control.
      /// @remarks Use the dock property to define how a control is automatically resized as its parent control is resized. For example, setting dock to dock_style::left causes the control to align itself with the left edges of its parent control and to resize as the parent control is resized. Controls are docked in their Z-order, which is the visual layering of controls on a form along the form's Z-axis (depth).
      /// @remarks A control can be docked to one edge of its parent container or can be docked to all edges and fill the parent container.
      /// @remarks Setting the margin property on a docked control has no effect on the distance of the control from the edges of its container.
      /// @note The anchor and dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the dock property in a derived class, use the base class's dock property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set methods of the dock property; you can override only one if needed.
      virtual control& dock(dock_style dock);

      /// @brief Gets a value indicating whether this control should redraw its surface using a secondary buffer to reduce or prevent flicker.
      /// @return true if the surface of the control should be drawn using double buffering; otherwise, false.
      virtual bool double_buffered() const {return get_state(state::double_buffered);}
      /// @brief Sets a value indicating whether this control should redraw its surface using a secondary buffer to reduce or prevent flicker.
      /// @param double_buffered true if the surface of the control should be drawn using double buffering; otherwise, false.
      /// @return Current control.
      virtual control& double_buffered(bool double_buffered) {
        set_state(state::double_buffered, double_buffered);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the control can respond to user interaction.
      /// @return true if the control can respond to user interaction; otherwise, false. The default is true.
      virtual bool enabled() const {return get_state(state::enabled);}
      /// @brief Sets a value indicating whether the control can respond to user interaction.
      /// @param enabled true if the control can respond to user interaction; otherwise, false. The default is true.
      /// @return Current control.
      virtual control& enabled(bool enabled);

      /// @brief Gets a value indicating whether the control has input focus.
      /// @return true if the control has focus; otherwise, false.
      virtual bool focused() const {return focused_;}

      /// @brief Gets the foreground color of the control.
      /// @return The foreground color of the control. The default is the value of the default_fore_color property.
      virtual drawing::color fore_color() const;
      /// @brief Sets the foreground color of the control.
      /// @param color The foreground color of the control. The default is the value of the default_fore_color property.
      /// @return Current control.
      virtual control& fore_color(const drawing::color& color);
      /// @cond
      virtual control& fore_color(nullptr_t);
      /// @endcond

      /// @brief Gets the font of the text displayed by the control.
      /// @return The font to apply to the text displayed by the control. The default is the value of the default_font property.
      virtual drawing::font font() const;
      /// @brief Sets the font of the text displayed by the control.
      /// @param font The font to apply to the text displayed by the control. The default is the value of the default_font property.
      /// @return Current control.
      virtual control& font(const drawing::font& font);
      /// @cond
      virtual control& font(nullptr_t);
      /// @endcond

      /// @brief Gets the window handle that the control is bound to.
      /// @return An intptr_t that contains the window handle (HWND) of the control.
      intptr_t handle() const override;
      
      /// @brief Gets the height of the control.
      /// @return The height of the control in pixels.
      virtual int32_t height() const {return size_.height();}
      /// @brief Sets the height of the control.
      /// @param height The height of the control in pixels.
      /// @return Current control.
      virtual control& height(int32_t height) {
        if (size_.height() != height)
          set_bounds_core(0, 0, 0, height, bounds_specified::height);
        return *this;
      }
      
      /// @brief Gets a value indicating whether the control has a handle associated with it.
      /// @return true if a handle has been assigned to the control; otherwise, false.
      /// @remarks Use the is_handle_created property to determine whether create_handle has been called.
      bool is_handle_created() const;
      
      /// @brief Gets the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
      /// @return An int32_t representing the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
      virtual int32_t left() const {return location_.x();}
      /// @brief Sets the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
      /// @param left An int32_t representing the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
      /// @return Current control.
      virtual control& left(int32_t left) {
        if (location_.x() != left)
          set_bounds_core(left, 0, 0, 0, bounds_specified::x);
        return *this;
      }

      /// @brief Gets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
      /// @return The point that represents the upper-left corner of the control relative to the upper-left corner of its container.
      virtual drawing::point location() const {return location_;}
      /// @brief Sets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
      /// @param location The point that represents the upper-left corner of the control relative to the upper-left corner of its container.
      /// @return Current control.
      virtual control& location(const drawing::point& location) {
        if (location_ != location)
          set_bounds_core(location.x(), location.y(), 0, 0, bounds_specified::location);
        return *this;
      }
      
      /// @brief Gets the space between controls.
      /// @return A padding representing the space between controls.
      virtual forms::padding margin() const {return margin_;}
      /// @brief Sets the space between controls.
      /// @param margin A padding representing the space between controls.
      /// @return Current control.
      virtual control& margin(const forms::padding& margin) {
        if (margin_ != margin)
          margin_ = margin;
        return *this;
      }

      /// @brief Gets the size that is the upper limit that xtd::forms::control::get_preferred_size can specify.
      /// @return An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual const drawing::size& maximum_size() const;
      /// @brief Sets the size that is the upper limit that xtd::forms::control::get_preferred_size can specify.
      /// @param size An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual control& maximum_size(const drawing::size& size);
      
      /// @brief Gets the size that is the lower limit that xtd::forms::control::get_preferred_size can specify.
      /// @return An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual const drawing::size& minimum_size() const;
      /// @brief Sets the size that is the lower limit that xtd::forms::control::get_preferred_size can specify.
      /// @param size An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual control& minimum_size(const drawing::size& size);
      
      /// @brief Gets a value indicating which of the modifier keys (SHIFT, CTRL, and ALT) is in a pressed state.
      /// @return A bitwise combination of the keys values. The default is none.
      static forms::keys modifier_keys() {return modifier_keys_;}
      
      /// @brief Gets a value indicating which of the mouse buttons is in a pressed state.
      /// @return A bitwise combination of the mouse_buttons enumeration values. The default is none.
      static forms::mouse_buttons mouse_buttons() {return mouse_buttons_;}
      
      /// @brief Gets the name of the control.
      /// @return The name of the control. The default is an empty string ("").
      virtual const xtd::ustring& name() const {return name_;}
      /// @brief Sets the name of the control.
      /// @param name The name of the control. The default is an empty string ("").
      /// @return Current control.
      virtual control& name(const xtd::ustring& name) {
        name_ = name;
        return*this;
      }
      
      /// @brief Gets padding within the control.
      /// @return A padding representing the control's internal spacing characteristics.
      virtual forms::padding padding() const {return padding_;}
      /// @brief Sets padding within the control.
      /// @param padding A padding representing the control's internal spacing characteristics.
      /// @return Current control.
      virtual control& padding(const forms::padding& padding) {
        if (padding_ != padding)
          padding_ = padding;
        return *this;
      }
      
      /// @brief Gets the parent container of the control.
      /// @return A control that represents the parent or container control of the control.
      virtual std::optional<control_ref> parent() const {return from_handle(parent_);}
      /// @brief Sets the parent container of the control.
      /// @param parent A control that represents the parent or container control of the control  or nullptr for none.
      /// @return Current control.
      virtual control& parent(const control& parent);
      /// @brief Resets the parent container of the control.
      /// @param nullptr.
      /// @return Current control.
      virtual control& parent(std::nullptr_t);

      /// @brief Gets the product name of the assembly containing the control.
      /// @return The product name of the assembly containing the control.
      virtual xtd::ustring product_name() const {return "xtd";}
      
      /// @brief Gets a value indicating whether the control is currently re-creating its handle.
      /// @return true if the control is currently re-creating its handle; otherwise, false.
      bool recreating_handle() const {return get_state(state::recreate);}
      
      /// @brief Gets the distance, in pixels, between the right edge of the control and the left edge of its container's client area.
      /// @return An int32_t representing the distance, in pixels, between the right edge of the control and the left edge of its container's client area.
      virtual int32_t right() const {return left() + width();}

      /// @brief Gets the height and width of the control.
      /// @return The size that represents the height and width of the control in pixels.
      virtual const drawing::size& size() const {return size_;}
      /// @brief Sets the height and width of the control.
      /// @param size The size that represents the height and width of the control in pixels.
      /// @return Current control.
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
      /// @return Current control.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      virtual control& tag(std::any tag) {
        tag_ = tag;
        return*this;
      }
      
      /// @brief Gets the text associated with this control.
      /// @return The text associated with this control.
      virtual const xtd::ustring& text() const {return text_;}
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      /// @return Current control.
      virtual control& text(const xtd::ustring& text);

      /// @brief Gets the distance, in pixels, between the top edge of the control and the top edge of its container's client area.
      /// @return An Int32_t representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      virtual int32_t top() const {return location_.y();}
      /// @brief Sets the distance, in pixels, between the top edge of the control and the top edge of its container's client area.
      /// @param top An Int32_t representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      /// @return Current control.
      virtual control& top(int32_t top) {
        if (location_.y() != top)
          set_bounds_core(0, top, 0, 0, bounds_specified::y);
        return *this;
      }
      
      /// @brief Gets the parent control that is not parented by another Windows Forms control. Typically, this is the outermost Form that the control is contained in.
      /// @return The control that represents the top-level control that contains the current control.
      virtual std::optional<control_ref> top_level_control() const;

      /// @brief Gets a value indicating whether the control and all its child controls are displayed.
      /// @return true if the control and all its child controls are displayed; otherwise, false. The default is true.
      virtual bool visible() const {return get_state(state::visible);}
      /// @brief Sets a value indicating whether the control and all its child controls are displayed.
      /// @param visible true if the control and all its child controls are displayed; otherwise, false. The default is true.
      /// @return Current control.
      virtual control& visible(bool visible);

      /// @brief Gets the width of the control.
      /// @return The width of the control in pixels.
      virtual int32_t width() const {return size_.width();}
      /// @brief Sets the width of the control.
      /// @param width The width of the control in pixels.
      /// @return Current control.
      virtual control& width(int32_t width) {
        if (size_.width() != width)
          set_bounds_core(0, 0, width, 0, bounds_specified::width);
        return *this;
      }
      
      /// @brief Add child control.
      /// @param parent A control that represents the parent or container control of the control.
      /// @param child A control to add to parent.
      /// @return Current control.
      friend control& operator<<(control& parent, control& child) {
        child.parent(parent);
        return parent;
      }
      
      /// @brief Remove child control.
      /// @param parent A control that represents the parent or container control of the control.
      /// @param child A control to remove to parent.
      /// @return Current control.
      friend control& operator>>(control& parent, control& child) {
        if (child.parent().has_value() && &child.parent().value().get() == &parent)
          child.parent(nullptr);
        return parent;
      }

      /// @brief Executes the specified delegate asynchronously on the thread that the control's underlying handle was created on.
      /// @param value A delegate to a method that takes no parameters.
      /// @return An async_result_invoke that represents the result of the begin_invoke(delegate) operation.
      std::shared_ptr<xtd::iasync_result> begin_invoke(delegate<void()> value) {return begin_invoke(delegate<void(std::vector<std::any>)>(value), {});}
      
      /// @brief Executes the specified delegate asynchronously with the specified arguments, on the thread that the control's underlying handle was created on.
      /// @param value A delegate to a method that takes parameters of the same number and type that are contained in the args parameter.
      /// @param args An array of objects to pass as arguments to the given method. This can be empty if no arguments are needed.
      /// @return An async_result_invoke that represents the result of the begin_invoke(delegate) operation.
      std::shared_ptr<xtd::iasync_result> begin_invoke(delegate<void(std::vector<std::any>)> value, const std::vector<std::any>& args);
      
      /// @cond
      template<typename delegate_t>
      std::shared_ptr<xtd::iasync_result> begin_invoke(delegate_t value, const std::vector<std::any>& args) {return begin_invoke(delegate<void(std::vector<std::any>)>(value), args);}
      
      template<typename delegate_t>
      std::shared_ptr<xtd::iasync_result> begin_invoke(delegate_t value) {return begin_invoke(delegate<void(std::vector<std::any>)>(value), {});}
      /// @endcond

      /// @brief Brings the control to the front of the z-order.
      /// @remarks The control is moved to the front of the z-order. If the control is a child of another control, the child control is moved to the front of the z-order. bring_to_front does not make a control a top-level control, and it does not raise the paint event.
      virtual void bring_to_front();

      /// @brief A factory to create a specified control with specified location ,size back_color and fore_color.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param back_color A xtd::drawing::color that represent background color of the control.
      /// @param fore_color A xtd::drawing::color that represent foreground color of the control.
      /// @return New control created.
      template<typename control_t>
      static std::unique_ptr<control_t> create(const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        if (location != drawing::point {-1, -1}) item->location(location);
        if (size != drawing::size {-1, -1}) item->size(size);
        if (back_color != drawing::color::empty) item->back_color(back_color);
        if (fore_color != drawing::color::empty) item->fore_color(fore_color);
        return item;
      }
      
      /// @brief A factory to create a specified control with specified parent, location ,size back_color and fore_color.
      /// @param parent The parent that contains the new created control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param back_color A xtd::drawing::color that represent background color of the control.
      /// @param fore_color A xtd::drawing::color that represent foreground color of the control.
      /// @return New control created.
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
      
      /// @brief A factory to create a specified control with specified text, location ,size back_color and fore_color.
      /// @param text A string that represent text of the control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param back_color A xtd::drawing::color that represent background color of the control.
      /// @param fore_color A xtd::drawing::color that represent foreground color of the control.
      /// @return New control created.
      template<typename control_t>
      static std::unique_ptr<control_t> create(const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->text(text);
        if (location != drawing::point {-1, -1}) item->location(location);
        if (size != drawing::size {-1, -1}) item->size(size);
        if (back_color != drawing::color::empty) item->back_color(back_color);
        if (fore_color != drawing::color::empty) item->fore_color(fore_color);
        return item;
      }
      
      /// @brief A factory to create a specified control with specified parent, text, location ,size back_color and fore_color.
      /// @param parent The parent that contains the new created control.
      /// @param text A string that represent text of the control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param back_color A xtd::drawing::color that represent background color of the control.
      /// @param fore_color A xtd::drawing::color that represent foreground color of the control.
      /// @return New control created.
      template<typename control_t>
      static std::unique_ptr<control_t> create(const control& parent, const xtd::ustring& text, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const drawing::color& back_color = drawing::color::empty, const drawing::color& fore_color = drawing::color::empty) {
        std::unique_ptr<control_t> item = std::make_unique<control_t>();
        item->parent(parent);
        item->text(text);
        if (location != drawing::point {-1, -1}) item->location(location);
        if (size != drawing::size {-1, -1}) item->size(size);
        if (back_color != drawing::color::empty) item->back_color(back_color);
        if (fore_color != drawing::color::empty) item->fore_color(fore_color);
        return item;
      }

      /// @brief Forces the creation of the visible control, including the creation of the handle and any visible child controls.
      /// @remarks The create_control method forces a handle to be created for the control and its child controls. This method is used when you need a handle immediately for manipulation of the control or its children; simply calling a control's constructor does not create the Handle.
      /// @remarks create_control does not create a control handle if the control's visible property is false. You can either call the create_control method or access the handle property to create the control's handle regardless of the control's visibility, but in this case, no window handles are created for the control's children.
      void create_control();
      
      /// @brief Creates the xtd::drawing::graphics for the control.
      /// @return A xtd::drawing::graphics for the control.
      /// @ingroup drawing
      /// @remarks The graphics object that you retrieve through the create_graphics method should not normally be retained after the current Windows message has been processed, because anything painted with that object will be erased with the next WM_PAINT message. Therefore you cannot cache the graphics object for reuse, except to use non-visual methods like xtd::drawing::graphics::measure_string. Instead, you must call create_graphics every time that you want to use the graphics object.
      drawing::graphics create_graphics() const;
      
      /// @brief Creates a handle for the control.
      /// @remarks You typically should not call the create_handle method directly. The preferred method is to call the create_control method, which forces a handle to be created for the control and its child controls when the control is created.
      /// @par Notes to Inheritors
      /// When overriding create_handle() in a derived class, be sure to call the base class's create_handle() method to ensure that the handle is created.
      virtual void create_handle();

      /// @brief Forces the destruction of the visible control, including the destruction of the handle and any visible child controls.
      /// @remarks The destroy_control method forces a handle to be destroyed for the control and its child controls.
      /// @par Notes to Inheritors
      /// When overriding destroy_control() in a derived class, be sure to call the base class's destroy_control() method to ensure that the handle is destroyed.
      virtual void destroy_control();

      /// @brief Destroys the handle associated with the control.
      /// @par Notes to Inheritors
      /// When overriding destroy_handle() in a derived class, be sure to call the base class's destroy_handle() method to ensure that the handle is destroyed.
      virtual void destroy_handle();

      /// @brief Retrieves the return value of the asynchronous operation represented by the async_result_invoke passed.
      /// @param async The async_result_invoke that represents a specific invoke asynchronous operation, returned when calling begin_invoke(delegate).
      void end_invoke(std::shared_ptr<xtd::iasync_result> async);

      /// @brief Sets input focus to the control.
      /// @return true if the input focus request was successful; otherwise, false.
      /// @remarks The focus method returns true if the control successfully received input focus. The control can have the input focus while not displaying any visual cues of having the focus. This behavior is primarily observed by the unselectable controls listed below, or any controls derived from them.
      bool focus();
      
      /// @brief Retrieves the control that contains the specified handle.
      /// @param handle The window handle (HWND) to search for.
      /// @return The control that represents the control associated with the specified handle; returns null if no control with the specified handle is found.
      /// @remarks This method searches up the window handle parent chain until it finds a handle that is associated with a control. This method is more reliable than the from_handle method, because it correctly returns controls that own more than one handle.
      static std::optional<control_ref> from_child_handle(intptr_t handle);

      /// @brief Returns the control that is currently associated with the specified handle.
      /// @param handle The window handle (HWND) to search for.
      /// @return A control that represents the control associated with the specified handle; returns null if no control with the specified handle is found.
      static std::optional<control_ref> from_handle(intptr_t handle);

      /// @brief Retrieves the index of a control within the control collection.
      /// @param child The control to search for in the control collection.
      /// @return A zero-based index value that represents the location of the specified child control within the control collection.
      /// @exception xtd::argument_exception The child control is not in the control::control_collection.
      size_t get_child_index(intptr_t child) const {
        for (size_t index = 0;index < controls().size(); ++index)
        if (controls()[index].get().handle() == child) return index;
        throw xtd::argument_exception(current_stack_frame_);
      }

      /// @brief Retrieves the index of the specified child control within the control collection, and optionally raises an exception if the specified control is not within the control collection.
      /// @param child The control to search for in the control collection.
      /// @@param throw_exception true to throw an exception if the control specified in the child parameter is not a control in the control::control_collection; otherwise, false.
      size_t get_child_index(intptr_t child, bool& throw_exception) const {
        throw_exception = false;
        try {
          return get_child_index(child);
        } catch(...) {
          throw_exception = true;
          return control_collection::npos;
        }
      }

      /// @brief Conceals the control from the user.
      /// @remarks Hiding the control is equivalent to setting the visible property to false. After the hide method is called, the visible property returns a value of false until the show method is called.
      virtual void hide() {visible(false);}
      
      /// @brief Invalidates the entire surface of the control and causes the control to be redrawn.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate() const {invalidate({{0, 0}, client_size()}, false);}

      /// @brief Invalidates a specific region of the control and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
      /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(bool invalidate_children) const {invalidate({{0, 0}, client_size()}, invalidate_children);}

      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control.
      /// @param rect A xtd::drawing::rectangle that represents the region to invalidate.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(const drawing::rectangle& rect) const {invalidate(rect, false);}
      
      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
      /// @param rect A xtd::drawing::rectangle that represents the region to invalidate.
      /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(const drawing::rectangle& rect, bool invalidate_children) const;

      /// @brief Executes the specified delegate on the thread that owns the control's underlying window handle.
      /// @param value A delegate that contains a method to be called in the control's thread context.
      void invoke(delegate<void()> value) {invoke(delegate<void(std::vector<std::any>)>(value), {});}
      
      /// @brief Executes the specified delegate, on the thread that owns the control's underlying window handle, with the specified list of arguments.
      /// @param value A delegate to a method that takes parameters of the same number and type that are contained in the args parameter.
      /// @param args An array of objects to pass as arguments to the specified method. This parameter can be null if the method takes no arguments.
      void invoke(delegate<void(std::vector<std::any>)> value, const std::vector<std::any>& args) {end_invoke(begin_invoke(value, args));}
      
      /// @cond
      template<typename delegate_t>
      void invoke(delegate_t value, const std::vector<std::any>& args) {invoke(delegate<void(std::vector<std::any>)>(value), args);}
      
      template<typename delegate_t>
      void invoke(delegate_t value) {invoke(delegate<void(std::vector<std::any>)>(value), {});}
      /// @endcond

      /// @brief Forces the control to apply layout logic to all its child controls.
      /// @remarks If the suspend_layout method was called before calling the perform_layout method, the layout event is suppressed.
      void perform_layout();
      
      /// @brief Computes the location of the specified screen point into client coordinates.
      /// @param p The screen coordinate xtd::drawing::point to convert.
      /// @return A xtd::drawing::point that represents the converted xtd::drawing::point, p, in client coordinates.
      xtd::drawing::point point_to_client(const xtd::drawing::point& p);
      
      /// @brief Computes the location of the specified client point into screen coordinates.
      /// @param p The client coordinate  xtd::drawing::point to convert.
      /// @return A xtd::drawing::point that represents the converted  xtd::drawing::point, p, in screen coordinates.
      xtd::drawing::point point_to_screen(const xtd::drawing::point& p);
      
      /// @brief Preprocesses keyboard or input messages within the message loop before they are dispatched.
      /// @param message A xtd::forms::message, passed by reference, that represents the message to process. The possible values are WM_KEYDOWN, WM_SYSKEYDOWN, WM_CHAR, and WM_SYSCHAR.
      /// @return true if the message was processed by the control; otherwise, false.
      /// @remarks pre_process_message is called by the application's message loop to preprocess input messages before they are dispatched. Possible values for the msg parameter are WM_KEYDOWN, WM_SYSKEYDOWN, WM_CHAR, and WM_SYSCHAR.
      virtual bool pre_process_message(xtd::forms::message& message);

      /// @brief Forces the control to invalidate its client area and immediately redraw itself and any child controls.
      /// @par Notes to Inheritors
      /// When overriding refresh() in a derived class, be sure to call the base class's refresh() method so the control and its child controls are invalidated and redrawn.
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
      
      /// @brief Send a message with specified hwnd, message, wparam and lparam.
      /// @param hwnd The window handle of the message.
      /// @param msg The ID number for the message.
      /// @param wparam The WParam field of the message.
      /// @param lparam The LParam field of the message.
      /// @return The return value of the message.
      intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) const;
      
      /// @brief Sets a value indicating how a control will behave when its auto_size property is enabled.
      /// @param auto_size_mode One of the xtd::forms::auto_size_mode values.
      void set_auto_size_mode(auto_size_mode auto_size_mode);
      
      /// @brief Sets the bounds of the control to the specified location and size.
      /// @param x The new left property value of the control.
      /// @param y The new top property value of the control.
      /// @param width The new width property value of the control.
      /// @param height The new height property value of the control.
      void set_bounds(int32_t x, int32_t y, int32_t width, int32_t height) {set_bounds(x, y, width, height, bounds_specified::all);}

      /// @brief Sets the specified bounds of the control to the specified location and size.
      /// @param x The new left property value of the control.
      /// @param y The new top property value of the control.
      /// @param width The new width property value of the control.
      /// @param height The new height property value of the control.
      /// @param specified A bitwise combination of the xtd::forms::bounds_specified values. For any parameter not specified, the current value will be used.
      void set_bounds(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) {set_bounds_core(x, y, width, height, specified);}

      /// @brief Displays the control to the user.
      /// @remarks Showing the control is equivalent to setting the visible property to true. After the show method is called, the visible property returns a value of true until the hide method is called.
      virtual void show() {visible(true);}
      
      /// @brief Temporarily suspends the layout logic for the control.
      /// @remarks The layout logic of the control is suspended until the resume_layout method is called.
      /// @remarks The suspend_layout and resume_layout methods are used in tandem to suppress multiple layout events while you adjust multiple attributes of the control. For example, you would typically call the suspend_layout method, then set the size, location, anchor, or dock properties of the control, and then call the resume_layout method to enable the changes to take effect.
      /// @remarks There must be no pending calls to suspend_layout for resume_layout to be successfully called.
      /// @note When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. This will increase the performance of applications with many controls.
      void suspend_layout() {
        set_state(state::layout_deferred, true);
      }
      
      /// @brief Returns a string containing the name of the control, if any.
      /// @return A string containing the name of the control, if any, or class name if the control is unnamed.
      xtd::ustring to_string() const noexcept override;
      
      /// @brief Causes the control to redraw the invalidated regions within its client area.
      /// @remarks Executes any pending requests for painting.
      /// @remarks There are two ways to repaint a form and its contents:
      /// * You can use one of the overloads of the invalidate method with the update method.
      /// * You can call the refresh method, which forces the control to redraw itself and all its children. This is equivalent to setting the invalidate method to true and using it with update.
      /// @remarks The invalidate method governs what gets painted or repainted. The update method governs when the painting or repainting occurs. If you use the invalidate and update methods together rather than calling refresh, what gets repainted depends on which overload of invalidate you use. The update method just forces the control to be painted immediately, but the invalidate method governs what gets painted when you call the update method.
      virtual void update() const;
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::control& control) noexcept {
        return os << control.to_string();
      }
      
      bool operator==(const control& value) const {return this == &value;}
      bool operator!=(const control& value) const {return !operator==(value);}
      bool operator<(const control& value) const {return this < &value;}
      /// @endcond

      /// @brief Occurs when the value of the auto_size property changes.
      /// @ingroup events
      /// @remarks This event is raised if the auto_size property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> auto_size_changed;

      /// @brief Occurs when the value of the back_color property changes.
      /// @ingroup events
      /// @remarks This event is raised if the back_color property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> back_color_changed;

      /// @brief Occurs when the value of the background_image property changes.
      /// @ingroup events
      /// @remarks This event is raised if the background_image property is changed by either a programmatic modification or user interaction
      event<control, event_handler> background_image_changed;
      
      /// @brief Occurs when the value of the background_image_layout property changes.
      /// @ingroup events
      /// @remarks This event is raised if the background_image_layout property is changed by either a programmatic modification or user interaction
      event<control, event_handler> background_image_layout_changed;
      
      /// @brief Occurs when the control is clicked.
      /// @ingroup events
      /// @remarks The click event passes an xtd::event_args to its event handler, so it only indicates that a click has occurred. If you need more specific mouse information (button, number of clicks, wheel rotation, or location), use the mouse_click event. However, the mouse_click event will not be raised if the click is caused by action other than that of the mouse, such as pressing the ENTER key.
      /// @remarks A double-click is determined by the mouse settings of the user's operating system. The user can set the time between clicks of a mouse button that should be considered a double-click rather than two clicks. The click event is raised every time a control is double-clicked. For example, if you have event handlers for the click and double_click events of a xtd::forms::form, the click and double_click events are raised when the form is double-clicked and both methods are called. If a control is double-clicked and that control does not support the double_click event, the click event might be raised twice.
      /// @remarks You must set the standard_click value of xtd::forms::control_styles to true for this event to be raised.
      /// @note The following events are not raised for the xtd::forms::tab_control class unless there is at least one xtd::forms::tab_page in the xtd::forms::tab_control. xtd::forms::tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one xtd::forms::tab_page in the collection, and the user interacts with the tab control's header (where the xtd::forms::tab_page names appear), the xtd::forms::tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the xtd::forms::tab_page raises the appropriate event.
      /// @par Notes to Inheritors
      /// Inheriting from a standard Windows Forms control and changing the standard_click or standard_double_click values of xtd::forms::control_styles to true can cause unexpected behavior or have no effect at all if the control does not support the click or double_click events.
      /// @remarks The following table lists Windows Forms controls and which event (click or double_click) is raised in response to the mouse action specified.
      /// | Control                                                                                                                                                                                                                                                                                                                                                                                                                                                                     | Left Mouse Click | Left Mouse Double Click | Right Mouse Click | Right Mouse Click   | Middle Mouse Click | Middle Mouse Double Click | XButton1 Mouse Click | XButton1 Mouse Double-Click | XButton2 Mouse Click | XButton2 Mouse Double-Click |
      /// |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------|-------------------------|-------------------|---------------------|--------------------|---------------------------|----------------------|-----------------------------|----------------------|-----------------------------|
      /// | xtd::forms::month_calendar, xtd::forms::date_time_picker, xtd::forms::h_scroll_bar, xtd::forms::v_scroll_bar                                                                                                                                                                                                                                                                                                                                                                | none             | none                    | none              | none                | none               | none                      | none                 | none                        | none                 | none                        |
      /// | xtd::forms::button, xtd::forms::check_box, xtd::forms::color_picker, xtd::forms::command_link_button, xtd::forms::font_picker, xtd::forms::rich_text_box, xtd::forms::radio_button, xtd::forms::switch_button, xtd::forms::toggle_button                                                                                                                                                                                                                                    | click            | click, click            | none              | none                | none               | none                      | none                 | none                        | none                 | none                        |
      /// | xtd::forms::list_box, xtd::forms::checked_list_box, xtd::forms::choice, xtd::forms::combo_box                                                                                                                                                                                                                                                                                                                                                                               | click            | click, double_click     | none              | none                | none               | none                      | none                 | none                        | none                 | none                        |
      /// | xtd::forms::text_box, xtd::forms::domain_up_down, xtd::forms::numeric_up_down                                                                                                                                                                                                                                                                                                                                                                                               | click            | click, double_click     | none              | none                | none               | none                      | none                 | none                        | none                 | none                        |
      /// | * xtd::forms::tree_view, * xtd::forms::list_view                                                                                                                                                                                                                                                                                                                                                                                                                            | click            | click, double_click     | click             | click, double_click | none               | none                      | none                 | none                        | none                 | none                        |
      /// | xtd::forms::progress_bar, xtd::forms::track_bar                                                                                                                                                                                                                                                                                                                                                                                                                             | click            | click, click            | click             | click, click        | click              | click, click              | click                | click, click                | click                | click, click                |
      /// | xtd::forms::form, xtd::forms::collapsible_panel, xtd::forms::data_grid, xtd::forms::dot_matrix_display, xtd::forms::label, xtd::forms::lcd_label, xtd::forms::link_label, xtd::forms::nine_segment_display, xtd::forms::seven_segment_display, xtd::forms::sixteen_segment_display, xtd::forms::panel, xtd::forms::group_box, xtd::forms::picture_box, xtd::forms::splitter, xtd::forms::status_bar, xtd::forms::tool_bar, xtd::forms::tab_page, ** xtd::forms::tab_control | click            | click, double_click     | click             | click, double_click | click              | click, double_click       | click                | click, double_click         | click                | click, double_click         |
      /// <br>* The mouse pointer must be over a child object (xtd::forms::tree_node or xtd::forms::list_view_item).
      /// <br>** The xtd::forms::tab_control must have at least one xtd::forms::tab_page in its xtd::forms::tab_pages collection.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, event_handler> click;
      
      /// @brief Occurs when the value of the client_size property changes.
      /// @ingroup events
      /// @remarks This event is raised if the client_size property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> client_size_changed;
        
      /// @brief Occurs when the value of the cursor property changes.
      /// @ingroup events
      /// @remarks This event is raised if the cursor property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> cursor_changed;

      /// @brief Occurs when a new control is added to the control::control_collection.
      /// @ingroup events
      event<control, control_event_handler> control_added;
      
      /// @brief Occurs when a new control is removed to the control::control_collection.
      /// @ingroup events
      event<control, control_event_handler> control_removed;
      
      /// @brief Occurs when the value of the dock property changes.
      /// @ingroup events
      /// @remarks This event is raised if the dock property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> dock_changed;
        
      /// @brief Occurs when the control is double-clicked.
      /// @ingroup events
      /// @remarks A double-click is determined by the mouse settings of the user's operating system. The user can set the time between clicks of a mouse button that should be considered a double-click rather than two clicks. The click event is raised every time a control is double-clicked. For example, if you have event handlers for the click and double_click events of a xtd::forms::form, the click and double_click events are raised when the form is double-clicked and both methods are called. If a control is double-clicked and that control does not support the double_click event, the click event might be raised twice.
      /// @remarks You must set the standard_double_click and standard_click value of xtd::forms::control_styles to true for this event to be raised.
      /// @note The following events are not raised for the xtd::forms::tab_control class unless there is at least one xtd::forms::tab_page in the xtd::forms::tab_control. xtd::forms::tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one xtd::forms::tab_page in the collection, and the user interacts with the tab control's header (where the xtd::forms::tab_page names appear), the xtd::forms::tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the xtd::forms::tab_page raises the appropriate event.
      /// @par Notes to Inheritors
      /// Inheriting from a standard Windows Forms control and changing the standard_click or standard_double_click values of xtd::forms::control_styles to true can cause unexpected behavior or have no effect at all if the control does not support the click or double_click events.
      /// @remarks The following table lists Windows Forms controls and which event (click or double_click) is raised in response to the mouse action specified.
      /// | Control                                                                                                                                                                                                                                                                                                                                                                                                                                                                     | Left Mouse Click | Left Mouse Double Click | Right Mouse Click | Right Mouse Click   | Middle Mouse Click | Middle Mouse Double Click | XButton1 Mouse Click | XButton1 Mouse Double-Click | XButton2 Mouse Click | XButton2 Mouse Double-Click |
      /// |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------|-------------------------|-------------------|---------------------|--------------------|---------------------------|----------------------|-----------------------------|----------------------|-----------------------------|
      /// | xtd::forms::month_calendar, xtd::forms::date_time_picker, xtd::forms::h_scroll_bar, xtd::forms::v_scroll_bar                                                                                                                                                                                                                                                                                                                                                                | none             | none                    | none              | none                | none               | none                      | none                 | none                        | none                 | none                        |
      /// | xtd::forms::button, xtd::forms::check_box, xtd::forms::color_picker, xtd::forms::command_link_button, xtd::forms::font_picker, xtd::forms::rich_text_box, xtd::forms::radio_button, xtd::forms::switch_button, xtd::forms::toggle_button                                                                                                                                                                                                                                    | click            | click, click            | none              | none                | none               | none                      | none                 | none                        | none                 | none                        |
      /// | xtd::forms::list_box, xtd::forms::checked_list_box, xtd::forms::choice, xtd::forms::combo_box                                                                                                                                                                                                                                                                                                                                                                               | click            | click, double_click     | none              | none                | none               | none                      | none                 | none                        | none                 | none                        |
      /// | xtd::forms::text_box, xtd::forms::domain_up_down, xtd::forms::numeric_up_down                                                                                                                                                                                                                                                                                                                                                                                               | click            | click, double_click     | none              | none                | none               | none                      | none                 | none                        | none                 | none                        |
      /// | * xtd::forms::tree_view, * xtd::forms::list_view                                                                                                                                                                                                                                                                                                                                                                                                                            | click            | click, double_click     | click             | click, double_click | none               | none                      | none                 | none                        | none                 | none                        |
      /// | xtd::forms::progress_bar, xtd::forms::track_bar                                                                                                                                                                                                                                                                                                                                                                                                                             | click            | click, click            | click             | click, click        | click              | click, click              | click                | click, click                | click                | click, click                |
      /// | xtd::forms::form, xtd::forms::collapsible_panel, xtd::forms::data_grid, xtd::forms::dot_matrix_display, xtd::forms::label, xtd::forms::lcd_label, xtd::forms::link_label, xtd::forms::nine_segment_display, xtd::forms::seven_segment_display, xtd::forms::sixteen_segment_display, xtd::forms::panel, xtd::forms::group_box, xtd::forms::picture_box, xtd::forms::splitter, xtd::forms::status_bar, xtd::forms::tool_bar, xtd::forms::tab_page, ** xtd::forms::tab_control | click            | click, double_click     | click             | click, double_click | click              | click, double_click       | click                | click, double_click         | click                | click, double_click         |
      /// <br>* The mouse pointer must be over a child object (xtd::forms::tree_node or xtd::forms::list_view_item).
      /// <br>** The xtd::forms::tab_control must have at least one xtd::forms::tab_page in its xtd::forms::tab_pages collection.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, event_handler> double_click;

      /// @brief Occurs when the control receives focus.
      /// @ingroup events
      /// @remarks When you change the focus by using the keyboard (TAB, SHIFT+TAB, and so on), by calling the select or select_next_control methods, or by setting the container_control::active_control property to the current form, focus events occur in the following order:
      /// 1. xtd::forms::control::enter event
      /// 2. xtd::forms::control::got_focus event
      /// 3. xtd::forms::control::leave event
      /// 4. xtd::forms::control::validating event
      /// 5. xtd::forms::control::validated event
      /// 6. xtd::forms::control::lost_focus event
      /// @remarks When you change the focus by using the mouse or by calling the focus method, focus events occur in the following order:
      /// 1. xtd::forms::control::enter event
      /// 2. xtd::forms::control::got_focus event
      /// 3. xtd::forms::control::lost_focus event
      /// 4. xtd::forms::control::leave event
      /// 5. xtd::forms::control::validating event
      /// 6. xtd::forms::control::validated event
      /// @remarks If the causes_validation property is set to false, the xtd::forms::control::validating and xtd::forms::control::validated events are suppressed.
      /// @remarks Note The got_focus and lost_focus events are low-level focus events that are tied to the WM_KILLFOCUS and WM_SETFOCUS Windows messages. Typically, the got_focus and lost_focus events are only used when updating when writing custom controls. Instead the enter and leave events should be used for all controls except the xtd::forms::form class, which uses the activated and deactivate events.
      /// @warning Do not attempt to set focus from within the enter, got_focus, leave, lost_focus, validating, or validated event handlers. Doing so can cause your application or the operating system to stop responding.
      event<control, event_handler> got_focus;
      
      /// @brief Occurs when a handle is created for the control.
      /// @ingroup events
      /// @remarks A handle is created when the xtd::forms::control is displayed for the first time. For example, if a xtd::forms::control is created that has visible set to false, the handle_created event will not be raised until visible is set to true.
      event<control, event_handler> handle_created;
      
      /// @brief Occurs when the control's handle is in the process of being destroyed.
      /// @ingroup events
      /// @remarks During the handle_destroyed event, the control is still a valid Windows control and the handle can be recreated by calling the recreate_handle method.
      event<control, event_handler> handle_destroyed;
      
      /// @brief Occurs when the value of the enabled property changes.
      /// @ingroup events
      /// @remarks This event is raised if the enabled property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> enabled_changed;

      /// @brief Occurs when the value of the fore_color property changes.
      /// @ingroup events
      /// @remarks This event is raised if the fore_color property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> fore_color_changed;
      
      /// @brief Occurs when the value of the font property changes.
      /// @ingroup events
      /// @remarks This event is raised if the font property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> font_changed;
      
      /// @brief Occurs when a key is pressed while the control has focus.
      /// @ingroup events
      /// @remarks Key events occur in the following order:
      /// 1. xtd::forms::control::key_down event
      /// 1. xtd::forms::control::key_press event
      /// 1. xtd::forms::control::key_up event
      /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the key_press_event_args::handled property in your form's key_press event-handling method to true. Certain keys, such as the TAB, RETURN, ESC, and arrow keys are handled by controls automatically. To have these keys raise the key_down event, you must override the is_input_key method in each control on your form. The code for the override of the is_input_key would need to determine if one of the special keys is pressed and return a value of true. Instead of overriding the is_input_key method, you can handle the preview_key_down event and set the is_input_key property to true.
      /// @par Examples
      /// The following code example demonstrate the use of control keyboard events.
      /// @include key_events.cpp
      event<control, key_event_handler> key_down;
      
      /// @brief Occurs when a character. space or backspace key is pressed while the control has focus.
      /// @ingroup events
      /// @remarks Key events occur in the following order:
      /// 1. xtd::forms::control::key_down event
      /// 1. xtd::forms::control::key_press event
      /// 1. xtd::forms::control::key_up event
      /// @remarks The key_press event is not raised by non-character keys other than space and backspace; however, the non-character keys do raise the key_down and key_up events.
      /// @remarks Use the xtd::forms::key_press_event_args::key_char property to sample keystrokes at run time and to consume or modify a subset of common keystrokes.
      /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the key_press_event_args::handled property in your form's key_press event-handling method to true.
      /// @par Examples
      /// The following code example demonstrate the use of control keyboard events.
      /// @include key_events.cpp
      event<control, key_press_event_handler> key_press;
      
      /// @brief Occurs when a key is released while the control has focus.
      /// @ingroup events
      /// @remarks Key events occur in the following order:
      /// 1. xtd::forms::control::key_down event
      /// 1. xtd::forms::control::key_press event
      /// 1. xtd::forms::control::key_up event
      /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the key_press_event_args::handled property in your form's key_press event-handling method to true. Certain keys, such as the TAB, RETURN, ESC, and arrow keys are handled by controls automatically. To have these keys raise the key_down event, you must override the is_input_key method in each control on your form. The code for the override of the is_input_key would need to determine if one of the special keys is pressed and return a value of true. Instead of overriding the is_input_key method, you can handle the preview_key_down event and set the is_input_key property to true.
      /// @par Examples
      /// The following code example demonstrate the use of control keyboard events.
      /// @include key_events.cpp
      event<control, key_event_handler> key_up;
      
      /// @brief Occurs when a control should reposition its child controls.
      /// @ingroup events
      /// @remarks The layout event occurs when child controls are added or removed, when the bounds of the control changes, and when other changes occur that can affect the layout of the control. The layout event can be suppressed using the suspend_layout and resume_layout methods. Suspending layout enables you to perform multiple actions on a control without having to perform a layout for each change. For example, if you resize and move a control, each operation would raise a layout event.
      event<control, event_handler> layout;
      
      /// @brief Occurs when the value of the location property changes.
      /// @ingroup events
      /// @remarks This event is raised if the location property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> location_changed;
      
      /// @brief Occurs when the control loses focus.
      /// @ingroup events
      /// @remarks When you change the focus by using the keyboard (TAB, SHIFT+TAB, and so on), by calling the select or select_next_control methods, or by setting the container_control::active_control property to the current form, focus events occur in the following order:
      /// 1. xtd::forms::control::enter event
      /// 2. xtd::forms::control::got_focus event
      /// 3. xtd::forms::control::leave event
      /// 4. xtd::forms::control::validating event
      /// 5. xtd::forms::control::validated event
      /// 6. xtd::forms::control::lost_focus event
      /// @remarks When you change the focus by using the mouse or by calling the focus method, focus events occur in the following order:
      /// 1. xtd::forms::control::enter event
      /// 2. xtd::forms::control::got_focus event
      /// 3. xtd::forms::control::lost_focus event
      /// 4. xtd::forms::control::leave event
      /// 5. xtd::forms::control::validating event
      /// 6. xtd::forms::control::validated event
      /// @remarks If the causes_validation property is set to false, the xtd::forms::control::validating and xtd::forms::control::validated events are suppressed.
      /// @remarks If the cancel property of the xtd::forms::cancel_event_args is set to true in the validating event delegate, all events that would usually occur after the validating event are suppressed.
      /// @remarks Note The got_focus and lost_focus events are low-level focus events that are tied to the WM_KILLFOCUS and WM_SETFOCUS Windows messages. Typically, the got_focus and lost_focus events are only used when updating when writing custom controls. Instead the enter and leave events should be used for all controls except the xtd::forms::form class, which uses the activated and deactivate events.
      /// @warning Do not attempt to set focus from within the enter, got_focus, leave, lost_focus, validating, or validated event handlers. Doing so can cause your application or the operating system to stop responding.
      event<control, event_handler> lost_focus;
      
      /// @brief Occurs when the control is clicked by the mouse.
      /// @ingroup events
      /// @remarks Depressing a mouse button when the cursor is over a control typically raises the following series of events from the control:
      /// 1. xtd::forms::control::mouse_down event
      /// 2. xtd::forms::control::click event
      /// 3. xtd::forms::control::mouse_click event
      /// 4. xtd::forms::control::mouse_up event
      /// @remarks For this to occur, the various events cannot be disabled in the control's class.
      /// @remarks Two single clicks that occur close enough in time, as determined by the mouse settings of the user's operating system, will generate a mouse_double_click event instead of the second mouse_click event.
      /// @par important
      /// click events are logically higher-level events of a control. They are often raised by other actions, such as pressing the ENTER key when the control has focus.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, mouse_event_handler> mouse_click;
      
      /// @brief Occurs when the control is double clicked by the mouse.
      /// @ingroup events
      /// @remarks The mouse_double_click event occurs when the user depresses a mouse button twice in quick succession when the cursor is over the control. The time interval that separates two single clicks from a double-click is determined by the mouse settings of the user's operating system.
      /// @remarks The following series of events is raised by the control when such a user action takes place:
      /// 1. xtd::forms::control::mouse_down event
      /// 2. xtd::forms::control::click event
      /// 3. xtd::forms::control::mouse_click event
      /// 4. xtd::forms::control::mouse_up event
      /// 5. xtd::forms::control::mouse_down event
      /// 6. xtd::forms::control::double_click event
      /// 7. xtd::forms::control::mouse_click event
      /// 8. xtd::forms::control::mouse_up event
      /// @remarks For this to occur, the various events cannot be disabled in the control's class.
      /// @par important
      /// double_click events are logically higher-level events of a control. They may be raised by other user actions, such as shortcut key combinations.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, mouse_event_handler> mouse_double_click;
      
      /// @brief Occurs when the mouse pointer is over the control and a mouse button is pressed.
      /// @ingroup events
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, mouse_event_handler> mouse_down;
      
      /// @brief Occurs when the mouse pointer enters the control.
      /// @ingroup events
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, event_handler> mouse_enter;
      
      /// @brief Occurs when the mouse horizontal wheel moves while the control has focus.
      /// @ingroup events
      /// @remarks When handling the mouse_horizontal_wheel event it is important to follow the user interface (UI) standards associated with the mouse wheel. The mouse_event_args::delta property value indicates the amount the mouse wheel has been moved.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, mouse_event_handler> mouse_horizontal_wheel;
      
      /// @brief Occurs when the mouse pointer leaves the control.
      /// @ingroup events
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, event_handler> mouse_leave;
      
      /// @brief Occurs when the mouse pointer is moved over the control.
      /// @ingroup events
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, mouse_event_handler> mouse_move;
      
      /// @brief Occurs when the mouse pointer is over the control and a mouse button is released.
      /// @ingroup events
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, mouse_event_handler> mouse_up;
      
      /// @brief Occurs when the mouse wheel moves while the control has focus.
      /// @ingroup events
      /// @remarks When handling the mouse_wheel event it is important to follow the user interface (UI) standards associated with the mouse wheel. The mouse_event_args::delta property value indicates the amount the mouse wheel has been moved. The UI should scroll when the accumulated delta is plus or minus 120. The UI should scroll the number of logical lines returned by the system_information::mouse_wheel_scroll_lines property for every delta value reached. You can also scroll more smoothly in smaller that 120 unit increments, however the ratio should remain constant, that is system_information::mouse_wheel_scroll_lines lines scrolled per 120 delta units of wheel movement.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: click, double_click, mouse_down, mouse_up, mouse_hover, mouse_enter, mouse_leave and mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrate the use of control mouse events.
      /// @include mouse_events.cpp
      event<control, mouse_event_handler> mouse_wheel;
      
      /// @brief Occurs when the control is redrawn.
      /// @ingroup events
      /// @remarks The paint event is raised when the control is redrawn. It passes an instance of paint_event_args to the method(s) that handles the paint event. The paint event is raised when the control is redrawn. It passes an instance of paint_event_args to the method(s) that handles the paint event.
      /// @remarks When creating a new custom control or an inherited control with a different visual appearance, you must provide code to render the control by overriding the on_paint method.
      /// @par Examples
      /// The following code example demonstrate the use of control paint events.
      /// @include form_paint.cpp
      event<control, paint_event_handler> paint;
      
      /// @brief Occurs when the value of the parent property changes.
      /// @ingroup events
      /// @remarks This event is raised if the parent property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> parent_changed;
      
      /// @brief Occurs when the control is resized.
      /// @ingroup events
      /// @remarks To determine the size of the resized control, you can cast the sender parameter of the registered control_event_handler method to a control and get its size property (or height and width properties individually).
      /// @remarks To handle custom layouts, use the layout event instead of the resize event. The layout event is raised in response to a resize event, but also in response to other changes that affect the layout of the control.
      /// @par Examples
      /// The following code example demonstrate the use of control resize event.
      /// @include dot_matrix_display.cpp
      event<control, event_handler> resize;
        
      /// @brief Occurs when the value of the size property changes.
      /// @ingroup events
      /// @remarks This event is raised if the size property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> size_changed;

      /// @brief Occurs when the value of the text property changes.
      /// @ingroup events
      /// @remarks This event is raised if the text property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> text_changed;
      
      /// @brief Occurs when the value of the visible property changes.
      /// @ingroup events
      /// @remarks This event is raised if the visible property is changed by either a programmatic modification or user interaction.
      event<control, event_handler> visible_changed;

    protected:
      friend class application;
      friend class paint_event_args;
      friend class screen;
      
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      /// @remarks The create_params property should not be overridden and used to adjust the properties of your derived control. Properties such as the create_params::caption, create_params::width, and create_params::height should be set by the corresponding properties in your control such as control::text, control::width and control::height. The create_params should only be extended when you are wrapping a standard Windows control class or to set styles not provided by the forms namespace.
      /// @par Notes for inheritors
      /// When overriding the create_params property in a derived class, use the base class's create_params property to extend the base implementation. Otherwise, you must provide all the implementation.
      virtual forms::create_params create_params() const;
      
      /// @brief Sends the specified message to the default window procedure.
      /// @param message The Windows Message to process.
      virtual void def_wnd_proc(message& message);

      /// @brief Retrieves the value of the specified control style bit for the control.
      /// @param flag The control_styles bit to return the value from.
      /// @return true if the specified control style bit is set to true; otherwise, false.
      /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the set_style method and passing in the appropriate control_styles bit and the bool value to set the bit to. To determine the value assigned to a specified control_styles bit, use the get_style method and pass in the control_styles member to evaluate.
      bool get_style(control_styles flag) const {return ((int32_t)style_ & (int32_t)flag) == (int32_t)flag;}

      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      virtual drawing::size measure_control() const;
      
      /// @brief Measure this control text.
      /// @return The drawing::size size of this control text.
      drawing::size measure_text() const;
      
      /// @brief Raises the control::auto_size_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_auto_size_changed(const event_args& e);
      
      /// @brief Raises the control::back_color_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_back_color_changed(const event_args& e);
      
      /// @brief Raises the control::background_image_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_background_image_changed(const event_args& e);
      
      /// @brief Raises the control::background_image_layout_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_background_image_layout_changed(const event_args& e);
      
      /// @brief Raises the control::click event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_click(const event_args& e);
      
      /// @brief Raises the control::client_size_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_client_size_changed(const event_args& e);
      
      /// @brief Raises the control::control_added event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_control_added(const control_event_args& e);
      
      /// @brief Raises the control::control_removed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_control_removed(const control_event_args& e);
      
      /// @brief Raises the control::create_control event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_create_control();
      
      /// @brief Raises the control::cursor_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_cursor_changed(const event_args& e);

      /// @brief Raises the control::dock_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_dock_changed(const event_args& e);
        
      /// @brief Raises the double_click event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_double_click(const event_args& e);

      /// @brief Raises the control::enabled_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_enabled_changed(const event_args& e);
      
      /// @brief Raises the control::fore_color_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_fore_color_changed(const event_args& e);
      
      /// @brief Raises the control::font_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_font_changed(const event_args& e);
      
      /// @brief Raises the control::got_focus event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_got_focus(const event_args& e);
      
      /// @brief Raises the control::handle_created event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_handle_created(const event_args& e);
      
      /// @brief Raises the control::handle_destroyed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_handle_destroyed(const event_args& e);
      
      /// @brief Raises the control::key_down event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_key_down(key_event_args& e);
      
      /// @brief Raises the control::key_press event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_key_press(key_press_event_args& e);
      
      /// @brief Raises the control::key_up event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_key_up(key_event_args& e);

      /// @brief Raises the control::layout event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_layout(const event_args& e);

      /// @brief Raises the control::location_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_location_changed(const event_args& e);
      
      /// @brief Raises the control::lost_focus event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_lost_focus(const event_args& e);
      
      /// @brief Raises the control::mouse_click event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_click(const mouse_event_args& e);
      
      /// @brief Raises the control::mouse_double_click event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_double_click(const mouse_event_args& e);
      
      /// @brief Raises the control::mouse_down event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_down(const mouse_event_args& e);
      
      /// @brief Raises the control::mouse_enter event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_enter(const event_args& e);
      
      /// @brief Raises the control::mouse_horizontal_wheel event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_horizontal_wheel(const mouse_event_args& e);
      
      /// @brief Raises the control::mouse_leave event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_leave(const event_args& e);
      
      /// @brief Raises the control::mouse_move event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_move(const mouse_event_args& e);
      
      /// @brief Raises the control::mouse_up event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_up(const mouse_event_args& e);
      
      /// @brief Raises the control::mouse_wheel event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_mouse_wheel(const mouse_event_args& e);
      
      /// @brief Raises the control::paint event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_paint(paint_event_args& e);
      
      /// @brief Raises the control::parent_back_color_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_parent_back_color_changed(const event_args& e);
        
      /// @brief Raises the control::parent_cursor_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_parent_cursor_changed(const event_args& e);

      /// @brief Raises the control::parent_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_parent_changed(const event_args& e);
      
      /// @brief Raises the xtd::control::enabled_changed event when the xtd::control::enabled property value of the control's container changes..
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_parent_enabled_changed(const event_args& e);
      
      /// @brief Raises the control::parent_fore_color_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_parent_fore_color_changed(const event_args& e);

      /// @brief Raises the control::parent_font_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_parent_font_changed(const event_args& e);
      
      /// @brief Raises the control::resize event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_resize(const event_args& e);
        
      /// @brief Raises the control::size_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_size_changed(const event_args& e);

      /// @brief Raises the control::text_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_text_changed(const event_args& e);
      
      /// @brief Raises the control::visible_changed event.
      /// @param e An xtd::event_args that contains the event data.
      /// @ingroup events
      virtual void on_visible_changed(const event_args& e);

      /// @brief Forces the re-creation of the handle for the control.
      /// @remarks The recreate_handle method is called whenever parameters are needed for a new control, but using a call from update_styles to create_params is insufficient. This method also calls destroy_handle and create_handle and sets recreating_handle to true.
      virtual void recreate_handle();
 
      /// @brief Performs the work of setting the specified bounds of this control.
      /// @param x The new left property value of the control.
      /// @param y The new top property value of the control.
      /// @param width The new width property value of the control.
      /// @param height The new height property value of the control.
      /// @param specified A bitwise combination of the bounds_specified values.
      /// @remarks Typically, the parameters that correspond to the bounds not included in the specified parameter are passed in with their current values. For example, the height, width, or the y or y properties of the location property can be passed in with a reference to the current instance of the control. However all values passed in are honored and applied to the control.
      /// @remarks The specified parameter represents the elements of the controls Bounds changed by your application. For example, if you change the size of the control, the specified parameter value is the size value of bounds_specified. However, if the size is adjusted in response to the dock property being set, the specified parameter value is the none value of bounds_specified.
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
      xtd::drawing::image background_image_ = xtd::drawing::image::empty;
      xtd::forms::image_layout background_image_layout_ = xtd::forms::image_layout::tile;
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
      drawing::size maximum_size_;
      drawing::size minimum_size_;
      forms::padding padding_;
      static forms::keys modifier_keys_;
      static forms::mouse_buttons mouse_buttons_;
      bool mouse_in_ = false;
      xtd::ustring name_;
      intptr_t parent_ = 0;
      drawing::size parent_size_;
      drawing::size size_;
      control::state state_ = state::empty;
      control_styles style_ = control_styles::none;
      std::any tag_;
      xtd::ustring text_;
      static std::map<intptr_t, control*> handles_;
      static control_collection top_level_controls_;
      /// @endcond
      
    private:
      void on_parent_size_changed(object& sender, const event_args& e);
      void do_layout_children_with_dock_style();
      void do_layout_with_auto_size_mode();
      void do_layout_with_anchor_styles();
      control(const xtd::ustring& name, bool) {name_ = name;}
      intptr_t wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle);
      void wm_child_activate(message& message);
      void wm_create(message& message);
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
