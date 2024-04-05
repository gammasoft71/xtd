/// @file
/// @brief Contains xtd::forms::control control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "layout/arranged_element_collection.h"
#include "anchor_styles.h"
#include "auto_size_mode.h"
#include "bounds_specified.h"
#include "component.h"
#include "const_control_ref.h"
#include "context_menu.h"
#include "control_appearance.h"
#include "control_event_handler.h"
#include "control_ref.h"
#include "control_styles.h"
#include "create_params.h"
#include "cursors.h"
#include "dock_style.h"
#include "help_event_handler.h"
#include "image_layout.h"
#include "iwin32_window.h"
#include "key_event_handler.h"
#include "key_press_event_handler.h"
#include "message.h"
#include "mouse_event_handler.h"
#include "padding.h"
#include "paint_event_handler.h"
#include "right_to_left.h"
#include "timer.h"
#include "style_sheets/style_sheet.h"
#include "visual_styles/control_state.h"
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/drawing/point>
#include <xtd/drawing/rectangle>
#include <xtd/drawing/size>
#include <xtd/any>
#include <xtd/async_result>
#include <xtd/optional>
#include <xtd/iclonable>
#include <xtd/iequatable>
#include <xtd/isynchronize_invoke>
#include <cstdint>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class application;
    class context_menu;
    class horizontal_layout_panel;
    class screen;
    class vertical_layout_panel;
    
    /// @endcond
    
    /// @brief Defines the base class for controls, which are components with visual representation.
    /// @par Header
    /// @code #include <xtd/forms/control> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks To create your own control class, inherit from the xtd::forms::user_control, xtd::forms::control classes, or from the other Windows Forms provided controls.
    /// @remarks The xtd::forms::control class implements very basic functionality required by classes that display information to the user. It handles user input through the keyboard and pointing devices. It handles message routing and security. It defines the bounds of a control (its position and size), although it does not implement painting. It provides a window handle (hWnd).
    /// @remarks Windows Forms controls use ambient properties so child controls can appear like their surrounding environment. An ambient property is a control property that, if not set, is retrieved from the xtd::forms::control::parent control. If the control does not have a parent, and the property is not set, the control attempts to determine the value of the ambient property through the site property. If the control is not sited, if the site does not support ambient properties, or if the property is not set on the ambient_properties, the control uses its own default values. Typically, an ambient property represents a characteristic of a control, such as xtd::forms::control::back_color, that is communicated to a child control. For example, a button will have the same xtd::forms::control::back_color as its parent form by default. Ambient properties provided by the control class include: xtd::forms::control::cursor, xtd::forms::control::font, xtd::forms::control::back_color, xtd::forms::control::fore_color, and xtd::forms::control::right_to_left.
    /// @remarks The majority of the controls in the xtd::forms namespace use the underlying Windows common control as a base to build on.
    /// @par Examples
    /// The following code example demonstrates the use of control control.
    /// @include control.cpp
    class forms_export_ control : public component, public iwin32_window, public iclonable, public icomparable<control>, public xtd::iequatable<control>, public xtd::isynchronize_invoke {
      struct data;
      
    protected:
      /// @cond
      enum class state : int64 {
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
        
        mouse_enter_pending = 0b100000000000000000000,
        tracking_mouse_event = 0b1000000000000000000000,
        mouse_pressed = 0b10000000000000000000000,
        use_wait_cursor = 0b100000000000000000000000,
        
        is_accessible = 0b1000000000000000000000000,
        no_zorder = 0b10000000000000000000000000,
        size_locked_by_os = 0b10000000000000000000000000,
        causes_validation = 0b100000000000000000000000000,
        own_ctl_brush = 0b1000000000000000000000000000,
        exception_while_painting = 0b10000000000000000000000000000,
        layout_sis_dirty = 0b100000000000000000000000000000,
        checked_host = 0b1000000000000000000000000000000,
        hosted_in_dialog = 0b10000000000000000000000000000000,
        validation_cancelled = 0b100000000000000000000000000000000,
        mirrored = 0b1000000000000000000000000000000000,
      };
      
      class async_result_invoke : public xtd::iasync_result {
        struct data;
      public:
        explicit async_result_invoke(std::any async_state);
        std::any async_state() const noexcept override;
        xtd::threading::wait_handle& async_wait_handle() noexcept override;
        bool completed_synchronously() const noexcept override;
        bool is_completed() const noexcept override;
        
        std::shared_ptr<data> data_;
      };
      /// @endcond
      
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represent an xtd::forms::context_menu reference.
      using context_menu_ref = std::reference_wrapper<xtd::forms::context_menu>;
      /// @}
      
      /// @brief Represents a collection of controls.
      class control_collection : public xtd::forms::layout::arranged_element_collection<control_ref> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the base type of the collection.
        using base = xtd::forms::layout::arranged_element_collection<control_ref>;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Creates a new object xtd::forms::control::control_collection with specified allocator (optional).
        /// @param allocator The allocator associate to the collection (optional).
        /// @remarks If allocator not specified, the std::allocator<value_type> is used.
        explicit control_collection(const allocator_type& allocator = allocator_type());
        /// @brief Creates a new object xtd::forms::control::control_collection with specified clone_and_keep_controls, and allocator (optional).
        /// @param clone_and_keep_controls If true the collection clone and keep controls; otherwise none.
        /// @param allocator The allocator associate to the collection (optional).
        /// @remarks If allocator not specified, the std::allocator<value_type> is used.
        /// @warning Internal use only
        explicit control_collection(bool clone_and_keep_controls, const allocator_type& allocator = allocator_type());
        /// @}
        
        /// @cond
        explicit control_collection(const base& collection);
        control_collection(const control_collection& collection);
        control_collection& operator =(const control_collection& collection);
        control_collection(control_collection&&) = default;
        /// @endcond
        
        /// @name Operators
        
        /// @{
        using base::operator [];
        /// @brief Gets the first xtd::forms::control::control_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        std::optional<value_type> operator [](const xtd::ustring& name) const;
        /// @brief Gets the first xtd::forms::control::control_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator [] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator [] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        std::optional<value_type> operator [](const xtd::ustring& name);
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Creates and inserts specified control at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the xtd::forms::control::control_collection::end iterator.
        /// @param args The arguments to forward to the create method of the control
        /// @return A reference to the created control.
        /// @remarks The control will be destroyed automatically when the control no longer has a parent.
        /// @remarks For creation and insertion, this method uses the xtd::forms::control::create methods of the various controls.
        /// @par Examples
        /// The folowing example demonstartes the use of xtd::forms::control::control_collection::emplace, xtd::forms::control::control_collection::emplace_at and xtd::forms::control::control_collection::emplace_back methods.
        /// @include emplace.cpp
        template<typename control_t, typename ... args_t>
        control_t& emplace(const_iterator pos, args_t&& ...args) {
          auto control_ptr = std::make_unique<control_t>(control_t::create(std::forward<args_t>(args)...));
          auto& control_ref = *control_ptr;
          controls_.push_back(std::move(control_ptr));
          base::insert(pos, control_ref);
          return control_ref;
        }
        
        /// @brief Creates and inserts specified control at specified position.
        /// @param index The index before which the content will be inserted.
        /// @param args The arguments to forward to the create method of the control
        /// @return A reference to the created control.
        /// @remarks The control will be destroyed automatically when the control no longer has a parent.
        /// @remarks For creation and insertion, this method uses the xtd::forms::control::create methods of the various controls.
        /// @par Examples
        /// The folowing example demonstartes the use of xtd::forms::control::control_collection::emplace, xtd::forms::control::control_collection::emplace_at and xtd::forms::control::control_collection::emplace_back methods.
        /// @include emplace.cpp
        template<typename control_t, typename ... args_t>
        control_t& emplace_at(size_t index, args_t&& ...args) {
          auto control_ptr = std::make_unique<control_t>(control_t::create(std::forward<args_t>(args)...));
          auto& control_ref = *control_ptr;
          controls_.push_back(std::move(control_ptr));
          base::insert_at(index, control_ref);
          return control_ref;
        }
        
        /// @brief Creates and adds a control to the end.
        /// @param args The arguments to forward to the create method of the control
        /// @return A reference to the created control.
        /// @remarks The control will be destroyed automatically when the control no longer has a parent.
        /// @remarks For creation and insertion, this method uses the xtd::forms::control::create methods of the various controls.
        /// @par Examples
        /// The folowing example demonstartes the use of xtd::forms::control::control_collection::emplace, xtd::forms::control::control_collection::emplace_at and xtd::forms::control::control_collection::emplace_back methods.
        /// @include emplace.cpp
        template<typename control_t, typename ... args_t>
        control_t& emplace_back(args_t&& ...args) {
          auto control_ptr = std::make_unique<control_t>(control_t::create(std::forward<args_t>(args)...));
          auto& control_ref = *control_ptr;
          controls_.push_back(std::move(control_ptr));
          base::push_back(control_ref);
          return control_ref;
        }
        
        iterator insert(const_iterator pos, const value_type& value) override;
        
        void insert_at(size_t index, const value_type& value) override;
        
        void push_back(const value_type& value) override;
        
        template<typename control_t>
        iterator insert(const_iterator pos, control_t& value) {
          for (auto it = begin(); it != end(); ++it)
            if (it->get() == value) return it;
          if (!clone_and_keep_controls_) return base::insert(pos, value);
          auto control_ptr = as<control>(as<iclonable>(value).clone());
          auto& control_ref = *control_ptr;
          controls_.push_back(std::move(control_ptr));
          return base::insert(pos, control_ref);
        }
        
        template<typename control_t>
        void insert_at(size_t index, control_t& value) {
          for (auto it = begin(); it != end(); ++it)
            if (it->get() == value) return;
          if (!clone_and_keep_controls_) base::insert_at(index, value);
          else {
            auto control_ptr = as<control>(as<iclonable>(value).clone());
            auto& control_ref = *control_ptr;
            controls_.push_back(std::move(control_ptr));
            base::insert_at(index, control_ref);
          }
        }
        
        template<typename control_t>
        void push_back(control_t& value) {
          for (auto it = begin(); it != end(); ++it)
            if (it->get() == value) return;
          if (!clone_and_keep_controls_) base::push_back(value);
          else {
            auto control_ptr = as<control>(as<iclonable>(value).clone());
            auto& control_ref = *control_ptr;
            controls_.push_back(std::move(control_ptr));
            base::push_back(control_ref);
          }
        }

        /// @}
        
      protected:
        /// @name Protected Methods
        
        /// @{
        void on_item_removed(size_t index, control_ref& item) override {
          xtd::forms::layout::arranged_element_collection<control_ref>::on_item_removed(index, item);
          for (auto iterator = controls_.begin(); iterator != controls_.end(); ++iterator) {
            if (iterator->get() != &item.get()) continue;
            controls_.erase(iterator);
            break;
          }
        }
        /// @}

      private:
        bool clone_and_keep_controls_ = false;
        static std::vector<std::unique_ptr<xtd::forms::control>> controls_;
      };
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::control class with default settings.
      /// @remarks The xtd::forms::control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      control();
      /// @brief Initializes a new instance of the xtd::forms::control class with specific text.
      /// @param text The text displayed by the control.
      /// @remarks The xtd::forms::control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the xtd::forms::control constructor sets the initial xtd::forms::control::text property value to the text parameter value.
      explicit control(const xtd::ustring& text);
      /// @brief Initializes a new instance of the xtd::forms::control class as a child control, with specific text.
      /// @param parent The control to be the parent of the control.
      /// @param text The text displayed by the control.
      /// @remarks The xtd::forms::control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the control constructor sets the initial xtd::forms::control::text property value to the text parameter value. The constructor also adds the control to the parent control's control::control_collection.
      control(const control& parent, const xtd::ustring& text);
      /// @brief Initializes a new instance of the control class with specific text, size, and location.
      /// @param text The text displayed by the control.
      /// @param left The x position of the control, in pixels, from the left edge of the control's container. The value is assigned to the left property.
      /// @param top The y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the top property.
      /// @param width The width of the control, in pixels. The value is assigned to the width property.
      /// @param height The height of the control, in pixels. The value is assigned to the height property.
      /// @remarks The control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the control constructor sets the initial xtd::forms::control::text property value to the text parameter value. The initial xtd::forms::control::size and xtd::forms::control::location of the control are determined by the left, top, width and height parameter values.
      control(const xtd::ustring& text, int32 left, int32 top, int32 width, int32 height);
      /// @brief Initializes a new instance of the xtd::forms::control class as a child control, with specific text, size, and location.
      /// @param parent The control to be the parent of the control.
      /// @param text The text displayed by the control.
      /// @param left The x position of the control, in pixels, from the left edge of the control's container. The value is assigned to the xtd::forms::control::left property.
      /// @param top The y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the xtd::forms::control::top property.
      /// @param width The width of the control, in pixels. The value is assigned to the xtd::forms::control::width property.
      /// @param height The height of the control, in pixels. The value is assigned to the xtd::forms::control::height property.
      /// @remarks The xtd::forms::control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
      /// @remarks This version of the xtd::forms::control constructor sets the initial xtd::forms::control::text property value to the text parameter value. The constructor also adds the control to the xtd::forms::control::parent control's control::control_collection. The initial xtd::forms::control::size and xtd::forms::control::location of the control are determined by the left, top, width and height parameter values.
      control(const control& parent, const xtd::ustring& text, int32 left, int32 top, int32 width, int32 height);
      /// @}
      
      /// @cond
      control(control&& rhs);
      control(const control&) = default;
      control& operator =(const control&) = default;
      ~control();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the edges of the container to which a control is bound and determines how a control is resized with its parent.
      /// @return A bitwise combination of the xtd::forms::anchor_styles values. The default is xtd::forms::anchor_styles::top and xtd::forms::anchor_styles::left.
      /// @remarks Use the xtd::forms::control::anchor property to define how a control is automatically resized as its parent control is resized. Anchoring a control to its parent control ensures that the anchored edges remain in the same position relative to the edges of the parent control when the parent control is resized.
      /// @remarks You can anchor a control to one or more edges of its container. For example, if you have a form with a button whose xtd::forms::control::anchor property value is set to xtd::forms::canchor_styles::top and xtd::forms::anchor_styles::bottom, the button is stretched to maintain the anchored distance to the top and bottom edges of the form as the height of the form is increased.
      /// @note The xtd::forms::control::anchor and xtd::forms::control::dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the xtd::forms::control::anchor property in a derived class, use the base class's xtd::forms::control::anchor property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the xtd::forms::control::anchor property; you can override only one if needed.
      virtual anchor_styles anchor() const noexcept;
      /// @brief Gets the edges of the container to which a control is bound and determines how a control is resized with its parent.
      /// @param anchor A bitwise combination of the xtd::forms::anchor_styles values. The default is xtd::forms::anchor_styles::top and xtd::forms::anchor_styles::left.
      /// @return Current control.
      /// @remarks Use the xtd::forms::control::anchor property to define how a control is automatically resized as its parent control is resized. Anchoring a control to its parent control ensures that the anchored edges remain in the same position relative to the edges of the parent control when the parent control is resized.
      /// @remarks You can anchor a control to one or more edges of its container. For example, if you have a form with a button whose xtd::forms::control::anchor property value is set to xtd::forms::anchor_styles::top and xtd::forms::anchor_styles::bottom, the button is stretched to maintain the anchored distance to the top and bottom edges of the form as the height of the form is increased.
      /// @note The xtd::forms::control::anchor and xtd::forms::control::dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @warning Set the xtd::forms::control::anchor property after setting the xtd::forms::control::location and xtd::forms::control::size.
      /// @par Notes to Inheritors
      /// When overriding the anchor property in a derived class, use the base class's anchor property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the anchor property; you can override only one if needed.
      virtual control& anchor(xtd::forms::anchor_styles anchor);
      
      /// @brief Gets where this control is scrolled to in scroll_control_into_view(control).
      /// @return A xtd::drawing::point specifying the scroll location. The default is the upper-left corner of the control.
      virtual drawing::point auto_scroll_point() const noexcept;
      
      /// @brief Gets a value that indicates whether the control resizes based on its contents.
      /// @return true if enabled; otherwise, false.
      /// @remarks This property is not relevant for this class.
      virtual bool auto_size() const noexcept;
      /// @brief Sets a value that indicates whether the control resizes based on its contents.
      /// @param auto_size true if enabled; otherwise, false.
      /// @return Current control.
      /// @remarks This property is not relevant for this class.
      virtual control& auto_size(bool auto_size);
      
      /// @brief Gets the background color for the control.
      /// @return A xtd::drawing::color that represents the background color of the control. The default is the value of the xtd::forms::control::default_back_color property.
      /// @remarks The xtd::forms::control::back_color property does not support transparent colors unless the xtd::forms::control_styles::supports_transparent_back_color value of xtd::forms::control_styles is set to true.
      /// @remarks The xtd::forms::control::back_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a button will have the same xtd::forms::control::back_color as its parent form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      virtual drawing::color back_color() const noexcept;
      /// @brief Sets the background color for the control.
      /// @param color A xtd::drawing::color that represents the background color of the control. The default is the value of the xtd::forms::control::default_back_color property.
      /// @return Current control.
      /// @remarks The xtd::forms::control::back_color property does not support transparent colors unless the xtd::forms::control_styles::supports_transparent_back_color value of xtd::forms::control_styles is set to true.
      /// @remarks The xtd::forms::control::back_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a button will have the same xtd::forms::control::back_color as its parent form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      /// @par Notes to Inheritors
      /// When overriding the xtd::forms::control::back_color property in a derived class, use the base class's xtd::forms::control::back_color property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the xtd::forms::control::back_color property; you can override only one if needed.
      virtual control& back_color(const xtd::drawing::color& color);
      /// @cond
      virtual control& back_color(std::nullptr_t);
      /// @endcond
      
      /// @brief Gets the background image displayed in the control.
      /// @return An xtd::drawing::image that represents the image to display in the background of the control.
      /// @remarks Use the background_image property to place a graphic image onto a control.
      virtual const xtd::drawing::image& background_image() const noexcept;
      /// @brief Sets the background image displayed in the control.
      /// @param background_image An xtd::drawing::image that represents the image to display in the background of the control.
      /// @return Current control.
      /// @remarks Use the background_image property to place a graphic image onto a control.
      virtual control& background_image(const xtd::drawing::image& background_image);
      
      /// @brief Gets the background image layout as defined in the xtd::forms::image_layout enumeration.
      /// @return One of the values of xtd::forms::image_layout (center , none, stretch, tile, or zoom). tile is the default value.
      /// @remarks Use the background_image_layout property to specify the position and behavior of an image you have placed onto a control. background_image_layout takes effect only if the background_image property is set.
      /// @remarks You can increase performance for large images if you set background_image_layout to something other than tile.
      virtual xtd::forms::image_layout background_image_layout() const noexcept;
      
      /// @brief Sets the background image layout as defined in the xtd::forms::image_layout enumeration.
      /// @param background_image_layout One of the values of xtd::forms::image_layout (center , none, stretch, tile, or zoom). tile is the default value.
      /// @return Current control.
      /// @remarks Use the background_image_layout property to specify the position and behavior of an image you have placed onto a control. background_image_layout takes effect only if the background_image property is set.
      /// @remarks You can increase performance for large images if you set background_image_layout to something other than tile.
      virtual control& background_image_layout(xtd::forms::image_layout background_image_layout);
      
      /// @brief Gets the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      /// @return An int32 representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      /// @remarks The value of this property is equal to the sum of the top property value, and the height property value.
      /// @remarks The bottom property is a read-only property. You can manipulate this property value by changing the value of the top or height properties or calling the set_bounds, set_bounds_core, update_bounds, or set_client_size_core methods.
      virtual int32 bottom() const noexcept;
      
      /// @brief Gets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
      /// @return A rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
      /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus.
      virtual drawing::rectangle bounds() const noexcept;
      /// @brief Sets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
      /// @param bounds A rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
      /// @return Current control.
      /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus. The Set_bounds_core method is called to set the bounds property. The bounds property is not always changed through its set method so you should override the set_bounds_core method to ensure that your code is executed when the bounds property is set.
      virtual control& bounds(const xtd::drawing::rectangle& bounds);
      
      /// @brief Gets a value indicating whether the control can receive focus.
      /// @return true if the control can receive focus; otherwise, false.
      /// @remarks In order for a control to receive input focus, the control must have a handle assigned to it, and the visible and enabled properties must both be set to true for both the control and all its parent controls, and the control must be a form or the control's outermost parent must be a form.
      virtual bool can_focus() const noexcept;
      
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
      virtual bool can_select() const noexcept;
      
      /// @brief Determines if events can be raised on the control.
      /// @return true if the control can raise events; otherwise, false.
      bool can_raise_events() const noexcept override;
      
      /// @brief Gets the rectangle that represents the client area of the control.
      /// @return A rectangle that represents the client area of the control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
      /// @remarks Because client coordinates are relative to the upper-left corner of the client area of the control, the coordinates of the upper-left corner of the rectangle returned by this property are (0,0). You can use this property to obtain the size and coordinates of the client area of the control for tasks such as drawing on the surface of the control.
      virtual const drawing::rectangle& client_rectangle() const noexcept;
      
      /// @brief Gets the height and width of the client area of the control.
      /// @return A size that represents the dimensions of the client area of the control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
      virtual const drawing::size& client_size() const noexcept;
      /// @brief Sets the height and width of the client area of the control.
      /// @param client_size A size that represents the dimensions of the client area of the control.
      /// @return Current control.
      /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus. The set_client_size_core method is called to set the client_size property. The client_size property is not always changed through its set method so you should override the set_client_size_core method to ensure that your code is executed when the client_size property is set.
      virtual control& client_size(const xtd::drawing::size& client_size);
      
      /// @brief Gets the name of the company or creator of the application containing the control.
      /// @return The company name or creator of the application containing the control.
      virtual xtd::ustring company_name() const noexcept;
      
      /// @brief Gets the xtd::forms::context_menu that is displayed in the control.
      /// @return A xtd::forms::context_menu that represents the context menu to display in the control.
      virtual std::optional<context_menu_ref> context_menu() const noexcept;
      /// @brief Sets the xtd::forms::context_menu that is displayed in the control.
      /// @param value A xtd::forms::context_menu that represents the context menu to display in the control.
      /// @return Current control.
      virtual control& context_menu(xtd::forms::context_menu& value);
      /// @brief Sets the xtd::forms::context_menu that is displayed in the control.
      /// @param value A xtd::forms::context_menu that represents the context menu to display in the control.
      /// @return Current control.
      virtual control& context_menu(std::nullptr_t);
      
      /// @brief Gets control appearance.
      /// @return One of xtd::forms::control_appearance values. THe default is xtd::forms::control_appearance::standard.
      /// @remarks The control appearance determine how the control is drawed :
      /// * xtd::control::control_appearance::standard : The appearance of the control is determined by current theme of xtd.
      /// * xtd::control::control_appearance::system : The appearance of the control is determined by the user's operating system.
      virtual forms::control_appearance control_appearance() const noexcept;
      /// @brief Sets control appearance.
      /// @param value One of xtd::forms::control_appearance values. THe default is xtd::forms::control_appearance::standard.
      /// @remarks The control appearance determine how the control is drawed :
      /// * xtd::control::control_appearance::standard : The appearance of the control is determined by current theme of xtd.
      /// * xtd::control::control_appearance::system : The appearance of the control is determined by the user's operating system.
      virtual control& control_appearance(xtd::forms::control_appearance value);
      
      /// @brief Gets the collection of controls contained within the control.
      /// @return A control::control_collection representing the collection of controls contained within the control.
      /// @remarks A control can act as a parent to a collection of controls. For example, when several controls are added to a form, each of the controls is a member of the control::control_collection assigned to the controls property of the form, which is derived from the control class.
      /// @remarks You can manipulate the controls in the control::control_collection assigned to the controls property by using the methods available in the control::control_collection class.
      /// @remarks When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. Doing so will increase the performance of applications with many controls.
      /// @remarks Use the controls property to iterate through all controls of a form, including nested controls. Use the get_next_control method to retrieve the previous or next child control in the tab order. Use the active_control property to get or set the active control of a container control.
      virtual control_collection& controls() noexcept;
      /// @brief Gets the collection of controls contained within the control.
      /// @return A control::control_collection representing the collection of controls contained within the control.
      /// @remarks A control can act as a parent to a collection of controls. For example, when several controls are added to a form, each of the controls is a member of the control::control_collection assigned to the controls property of the form, which is derived from the control class.
      /// @remarks You can manipulate the controls in the control::control_collection assigned to the controls property by using the methods available in the control::control_collection class.
      /// @remarks When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. Doing so will increase the performance of applications with many controls.
      /// @remarks Use the controls property to iterate through all controls of a form, including nested controls. Use the get_next_control method to retrieve the previous or next child control in the tab order. Use the active_control property to get or set the active control of a container control.
      virtual const control_collection& controls() const noexcept;
      
      /// @brief Gets a value indicating whether the control has been created.
      /// @return true if the control has been created; otherwise, false.
      /// @remarks The created property returns true if the control was successfully created even though the control's handle might not have been created or recreated yet.
      virtual bool created() const noexcept;
      
      /// @brief Gets the cursor that is displayed when the mouse pointer is over the control.
      /// @return A xtd::forms::cursor that represents the cursor to display when the mouse pointer is over the control.
      /// @remarks The xtd::forms::control::cursor property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a xtd::forms::button will have the same xtd::forms::control::back_color as its parent xtd::forms::form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      virtual forms::cursor cursor() const noexcept;
      /// @brief Sets the cursor that is displayed when the mouse pointer is over the control.
      /// @param cursor A xtd::forms::cursor that represents the cursor to display when the mouse pointer is over the control.
      /// @return Current control.
      /// @remarks The xtd::forms::control::cursor property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a xtd::forms::button will have the same xtd::forms::control::back_color as its parent xtd::forms::form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      virtual control& cursor(const xtd::forms::cursor& cursor);
      /// @cond
      virtual control& cursor(std::nullptr_t);
      /// @endcond
      
      /// @brief Gets the rectangle that represents the display area of the control.
      /// @return A rectangle that represents the display area of the control.
      virtual drawing::rectangle display_rectangle() const noexcept;
      
      /// @brief Gets which control borders are docked to its parent control and determines how a control is resized with its parent.
      /// @return One of the xtd::forms::dock_style values. The default is xtd::forms::dock_style::none.
      /// @remarks Use the xtd::forms::control::dock property to define how a control is automatically resized as its parent control is resized. For example, setting xtd::forms::control::dock to xtd::forms::dock_style::left causes the control to align itself with the left edges of its parent control and to resize as the parent control is resized. Controls are docked in their Z-order, which is the visual layering of controls on a form along the form's Z-axis (depth).
      /// @remarks A control can be docked to one edge of its parent container or can be docked to all edges and fill the parent container.
      /// @remarks Setting the xtd::forms::control::margin property on a docked control has no effect on the distance of the control from the edges of its container.
      /// @note The xtd::forms::control::anchor and xtd::forms::control::dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the xtd::forms::control::dock property in a derived class, use the base class's xtd::forms::control::dock property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set methods of the xtd::forms::control::dock property; you can override only one if needed.
      virtual dock_style dock() const noexcept;
      /// @brief Sets which control borders are docked to its parent control and determines how a control is resized with its parent.
      /// @param dock One of the xtd::forms::dock_style values. The default is xtd::forms::dock_style::none.
      /// @return Current control.
      /// @remarks Use the xtd::forms::control::dock property to define how a control is automatically resized as its parent control is resized. For example, setting xtd::forms::control::dock to xtd::forms::dock_style::left causes the control to align itself with the left edges of its parent control and to resize as the parent control is resized. Controls are docked in their Z-order, which is the visual layering of controls on a form along the form's Z-axis (depth).
      /// @remarks A control can be docked to one edge of its parent container or can be docked to all edges and fill the parent container.
      /// @remarks Setting the xtd::forms::control::margin property on a docked control has no effect on the distance of the control from the edges of its container.
      /// @note The xtd::forms::control::anchor and xtd::forms::control::dock properties are mutually exclusive. Only one can be set at a time, and the last one set takes precedence.
      /// @par Notes to Inheritors
      /// When overriding the xtd::forms::control::dock property in a derived class, use the base class's xtd::forms::control::dock property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set methods of the xtd::forms::control::dock property; you can override only one if needed.
      virtual control& dock(xtd::forms::dock_style dock);
      
      /// @brief Gets a value indicating whether this control should redraw its surface using a secondary buffer to reduce or prevent flicker.
      /// @return true if the surface of the control should be drawn using double buffering; otherwise, false.
      virtual bool double_buffered() const noexcept;
      /// @brief Sets a value indicating whether this control should redraw its surface using a secondary buffer to reduce or prevent flicker.
      /// @param double_buffered true if the surface of the control should be drawn using double buffering; otherwise, false.
      /// @return Current control.
      virtual control& double_buffered(bool double_buffered);
      
      /// @brief Gets a value indicating whether the control can respond to user interaction.
      /// @return true if the control can respond to user interaction; otherwise, false. The default is true.
      virtual bool enabled() const noexcept;
      /// @brief Sets a value indicating whether the control can respond to user interaction.
      /// @param enabled true if the control can respond to user interaction; otherwise, false. The default is true.
      /// @return Current control.
      virtual control& enabled(bool enabled);
      
      /// @brief Gets a value indicating whether the control has input focus.
      /// @return true if the control has focus; otherwise, false.
      virtual bool focused() const noexcept;
      
      /// @brief Gets the font of the text displayed by the control.
      /// @return The font to apply to the text displayed by the control. The default is the value of the default_font property.
      /// @remarks The xtd::forms::control::font property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a xtd::forms::button will have the same xtd::forms::control::back_color as its parent xtd::forms::form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      virtual drawing::font font() const noexcept;
      /// @brief Sets the font of the text displayed by the control.
      /// @param font The font to apply to the text displayed by the control. The default is the value of the default_font property.
      /// @return Current control.
      /// @remarks The xtd::forms::control::font property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a xtd::forms::button will have the same xtd::forms::control::back_color as its parent xtd::forms::form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      virtual control& font(const xtd::drawing::font& font);
      /// @cond
      virtual control& font(std::nullptr_t);
      /// @endcond
      
      /// @brief Gets the foreground color of the control.
      /// @return The foreground color of the control. The default is the value of the default_fore_color property.
      /// @remarks The xtd::forms::control::fore_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a xtd::forms::button will have the same xtd::forms::control::back_color as its parent xtd::forms::form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      virtual drawing::color fore_color() const noexcept;
      /// @brief Sets the foreground color of the control.
      /// @param color The foreground color of the control. The default is the value of the default_fore_color property.
      /// @return Current control.
      /// @remarks The xtd::forms::control::fore_color property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a xtd::forms::button will have the same xtd::forms::control::back_color as its parent xtd::forms::form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      virtual control& fore_color(const xtd::drawing::color& color);
      /// @cond
      virtual control& fore_color(std::nullptr_t);
      /// @endcond
      
      /// @brief Gets the window handle that the control is bound to.
      /// @return An intptr that contains the window handle (HWND) of the control.
      /// @remarks When the underlying toolkits is native, xtd::forms::control::handle and xtd::forms::control::native_handle are the same, But if the underlying toolkit is not native, the xtd::forms::control::handle matches the toolkit handle while xtd::forms::control::native_handle returns the true native handle.
      intptr handle() const override;
      
      /// @brief Gets the height of the control.
      /// @return The height of the control in pixels.
      virtual int32 height() const noexcept;
      /// @brief Sets the height of the control.
      /// @param height The height of the control in pixels.
      /// @return Current control.
      virtual control& height(int32 height);
      
      /// @brief Gets a value indicating whether the caller must call an invoke method when making method calls to the control because the caller is on a different thread than the one the control was created on.
      /// @return true if the control's xttd::forms::control::handle was created on a different thread than the calling thread (indicating that you must make calls to the control through an invoke method); otherwise, false.
      bool invoke_required() const noexcept override;
      
      /// @brief Gets a value indicating whether the control has a handle associated with it.
      /// @return true if a handle has been assigned to the control; otherwise, false.
      /// @remarks Use the is_handle_created property to determine whether create_handle has been called.
      bool is_handle_created() const noexcept;
      
      /// @brief Gets the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
      /// @return An int32 representing the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
      virtual int32 left() const noexcept;
      /// @brief Sets the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
      /// @param left An int32 representing the distance, in pixels, between the left edge of the control and the left edge of its container's client area.
      /// @return Current control.
      virtual control& left(int32 left);
      
      /// @brief Gets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
      /// @return The point that represents the upper-left corner of the control relative to the upper-left corner of its container.
      virtual drawing::point location() const noexcept;
      /// @brief Sets the coordinates of the upper-left corner of the control relative to the upper-left corner of its container.
      /// @param location The point that represents the upper-left corner of the control relative to the upper-left corner of its container.
      /// @return Current control.
      virtual control& location(const xtd::drawing::point& location);
      
      /// @brief Gets the space between controls.
      /// @return A padding representing the space between controls.
      virtual forms::padding margin() const noexcept;
      /// @brief Sets the space between controls.
      /// @param margin A padding representing the space between controls.
      /// @return Current control.
      virtual control& margin(const xtd::forms::padding& margin);
      
      /// @brief Gets the client size that is the upper limit that xtd::forms::control::get_preferred_size can specify.
      /// @return An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual const drawing::size& maximum_client_size() const noexcept;
      /// @brief Sets the client size that is the upper limit that xtd::forms::control::get_preferred_size can specify.
      /// @param size An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual control& maximum_client_size(const xtd::drawing::size& size);
      
      /// @brief Gets the size that is the upper limit that xtd::forms::control::get_preferred_size can specify.
      /// @return An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual const drawing::size& maximum_size() const noexcept;
      /// @brief Sets the size that is the upper limit that xtd::forms::control::get_preferred_size can specify.
      /// @param size An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual control& maximum_size(const xtd::drawing::size& size);
      
      /// @brief Gets the client size that is the lower limit that xtd::forms::control::get_preferred_size can specify.
      /// @return An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual const drawing::size& minimum_client_size() const noexcept;
      /// @brief Sets the client size that is the lower limit that xtd::forms::control::get_preferred_size can specify.
      /// @param size An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual control& minimum_client_size(const xtd::drawing::size& size);
      
      /// @brief Gets the size that is the lower limit that xtd::forms::control::get_preferred_size can specify.
      /// @return An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual const drawing::size& minimum_size() const noexcept;
      /// @brief Sets the size that is the lower limit that xtd::forms::control::get_preferred_size can specify.
      /// @param size An ordered pair of type xtd::drawing::size representing the width and height of a rectangle.
      /// @par Examples
      /// The following code shows how to set minimum size, set maximum size, move and resize a form.
      /// @include form_resize.cpp
      virtual control& minimum_size(const xtd::drawing::size& size);
      
      /// @brief Gets the native handle that the control is bound to.
      /// @return An intptr that contains the native handle (HWND) of the control.
      /// @remarks When the underlying toolkits is native, xtd::forms::control::handle and xtd::forms::control::native_handle are the same, But if the underlying toolkit is not native, the xtd::forms::control::handle matches the toolkit handle while xtd::forms::control::native_handle returns the true native handle.
      intptr native_handle() const noexcept;
      
      /// @brief Gets the name of the control.
      /// @return The name of the control. The default is an empty string ("").
      virtual const xtd::ustring& name() const noexcept;
      /// @brief Sets the name of the control.
      /// @param name The name of the control. The default is an empty string ("").
      /// @return Current control.
      virtual control& name(const xtd::ustring& name);
      
      /// @brief Gets padding within the control.
      /// @return A padding representing the control's internal spacing characteristics.
      virtual forms::padding padding() const noexcept;
      /// @brief Sets padding within the control.
      /// @param padding A padding representing the control's internal spacing characteristics.
      /// @return Current control.
      virtual control& padding(const xtd::forms::padding& padding);
      
      /// @brief Gets the parent container of the control.
      /// @return A control that represents the parent or container control of the control.
      virtual std::optional<control_ref> parent() const noexcept;
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
      virtual xtd::ustring product_name() const noexcept;
      
      /// @brief Gets a value indicating whether the control is currently re-creating its handle.
      /// @return true if the control is currently re-creating its handle; otherwise, false.
      bool recreating_handle() const noexcept;
      
      /// @brief Gets the window region associated with the control.
      /// @return The window xtd::drawing::region associated with the control.
      /// @remarks The window region is a collection of pixels within the window where the operating system permits drawing. The operating system does not display any portion of a window that lies outside of the window region. The coordinates of a control's region are relative to the upper-left corner of the control, not the client area of the control.
      /// @note The collection of pixels contained with the region can be noncontiguous.
      virtual const xtd::drawing::region& region() const noexcept;
      /// @brief Sets the window region associated with the control.
      /// @param value The window xtd::drawing::region associated with the control.
      /// @return Current control.
      /// @remarks The window region is a collection of pixels within the window where the operating system permits drawing. The operating system does not display any portion of a window that lies outside of the window region. The coordinates of a control's region are relative to the upper-left corner of the control, not the client area of the control.
      /// @note The collection of pixels contained with the region can be noncontiguous.
      virtual control& region(const xtd::drawing::region& value);
      
      /// @brief Gets the distance, in pixels, between the right edge of the control and the left edge of its container's client area.
      /// @return An int32 representing the distance, in pixels, between the right edge of the control and the left edge of its container's client area.
      virtual int32 right() const noexcept;
      
      /// @brief Gets a value indicating whether control's elements are aligned to support locales using right-to-left fonts.
      /// @return One of the xtd::forms::right_to_left values. The default is xtd::forms::right_to_left::inherit.
      /// @remarks The xtd::forms::control::right_to_left property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a xtd::forms::button will have the same xtd::forms::control::back_color as its parent xtd::forms::form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      /// @remarks The xtd::forms::control::right_to_left property is used for international applications where the language is written from right to left, such as Hebrew or Arabic. When this property is set to xtd::forms::right_to_left::yes, control elements that include text are displayed from right to left.
      /// @note If the value of the xtd::forms::control::right_to_left property is changed at run time, only raw text without formatting is preserved.
      /// @remarks The following are a few examples of how control elements are affected by the xtd::forms::control::right_to_left property value of xtd::forms::right_to_left::yes :
      /// * Vertical scroll bars are displayed on the left side rather than right side of scrollable controls (for example, xtd::forms::form, xtd::forms::panel, multiline xtd::forms::text_box, and xtd::forms::rich_text_box).
      /// * Horizontal scroll bars start with the scroll box (thumb) right-aligned.
      /// * The check box element alignment, controlled by the `check_align` property, is reversed for xtd::forms::check_box and xtd::forms::radio_button controls.
      /// * Items in list box, combo box, and up-down controls are right aligned.
      /// * Up and down buttons are left-aligned on xtd::forms::numeric_up_down and domain_up_down controls.
      /// * Menus (xtd::forms::main_menu, xtd::forms::menu_item, and xtd::forms::context_menu) are displayed right-aligned.
      /// * The alignment of toolbar buttons on a xtd::forms::tool_bar control or the alignment of text on a xtd::forms::tool_bar_button is not affected by the xtd::forms::control::right_to_left property.
      /// @par Notes to Inheritors
      /// When overriding the xtd::forms::control::right_to_left property in a derived class, use the base class's xtd::forms::control::right_to_left property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the xtd::forms::control::right_to_left property; you can override only one if needed.
      virtual xtd::forms::right_to_left right_to_left() const noexcept;
      /// @brief Sets a value indicating whether control's elements are aligned to support locales using right-to-left fonts.
      /// @param value One of the xtd::forms::right_to_left values. The default is xtd::forms::right_to_left::inherit.
      /// @return Current control.
      /// @remarks The xtd::forms::control::right_to_left property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a xtd::forms::button will have the same xtd::forms::control::back_color as its parent xtd::forms::form by default. For more information about ambient properties, see the [ambient_properties](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Overview/ambient_properties) guide.
      /// @remarks The xtd::forms::control::right_to_left property is used for international applications where the language is written from right to left, such as Hebrew or Arabic. When this property is set to xtd::forms::right_to_left::yes, control elements that include text are displayed from right to left.
      /// @note If the value of the xtd::forms::control::right_to_left property is changed at run time, only raw text without formatting is preserved.
      /// @remarks The following are a few examples of how control elements are affected by the xtd::forms::control::right_to_left property value of xtd::forms::right_to_left::yes :
      /// * Vertical scroll bars are displayed on the left side rather than right side of scrollable controls (for example, xtd::forms::form, xtd::forms::panel, multiline xtd::forms::text_box, and xtd::forms::rich_text_box).
      /// * Horizontal scroll bars start with the scroll box (thumb) right-aligned.
      /// * The check box element alignment, controlled by the `check_align` property, is reversed for xtd::forms::check_box and xtd::forms::radio_button controls.
      /// * Items in list box, combo box, and up-down controls are right aligned.
      /// * Up and down buttons are left-aligned on xtd::forms::numeric_up_down and domain_up_down controls.
      /// * Menus (xtd::forms::main_menu, xtd::forms::menu_item, and xtd::forms::context_menu) are displayed right-aligned.
      /// * The alignment of toolbar buttons on a xtd::forms::tool_bar control or the alignment of text on a xtd::forms::tool_bar_button is not affected by the xtd::forms::control::right_to_left property.
      /// @par Notes to Inheritors
      /// When overriding the xtd::forms::control::right_to_left property in a derived class, use the base class's xtd::forms::control::right_to_left property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the xtd::forms::control::right_to_left property; you can override only one if needed.
      virtual control& right_to_left(xtd::forms::right_to_left value);
      /// @cond
      virtual control& right_to_left(std::nullptr_t);
      /// @endcond

      /// @brief Gets the height and width of the control.
      /// @return The size that represents the height and width of the control in pixels.
      virtual drawing::size size() const noexcept;
      /// @brief Sets the height and width of the control.
      /// @param size The size that represents the height and width of the control in pixels.
      /// @return Current control.
      virtual control& size(const drawing::size& size);
      
      /// @brief Gets the contol style sheet.
      /// @return The xtd::forms::style_sheets::style-sheet style sheet associate to this current instance of xtd::forms::control.
      /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview).
      virtual style_sheets::style_sheet style_sheet() const noexcept;
      /// @brief Sets the contol style sheet.
      /// @param value The xtd::forms::style_sheets::style-sheet style sheet associate to this current instance of xtd::forms::control.
      /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview).
      virtual control& style_sheet(const style_sheets::style_sheet& value);
      /// @brief Sets the contol style sheet.
      /// @param value The xtd::forms::style_sheets::style-sheet style sheet associate to this current instance of xtd::forms::control.
      /// @return Current control.
      /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview).
      virtual control& style_sheet(const xtd::ustring& value);
      /// @brief Resets the contol style sheet.
      /// @param value The xtd::forms::style_sheets::style-sheet style sheet associate to this current instance of xtd::forms::control.
      /// @return Current control.
      /// @remarks For more information, see [Style sheets overview](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_overview).
      virtual control& style_sheet(std::nullptr_t);
      
      /// @brief Gets a value indicating whether the user can give the focus to this control using the TAB key.
      /// @return true if the user can give the focus to the control using the TAB key; otherwise, false. The default is true.
      /// @note Note: This property will always return true for an instance of the xtd::forms::form class.
      /// @remarks When the user presses the TAB key, the input focus is set to the next control in the tab order. Controls with the xtd::forms::control::tab_stop property value of false are not included in the collection of controls in the tab order. The tab order can be manipulated by setting the control's xtd::forms::control::tab_index property value.
      virtual bool tab_stop() const noexcept;
      /// @brief Sets a value indicating whether the user can give the focus to this control using the TAB key.
      /// @param value true if the user can give the focus to the control using the TAB key; otherwise, false. The default is true.
      /// @return Current control.
      /// @note Note: This property will always return true for an instance of the xtd::forms::form class.
      /// @remarks When the user presses the TAB key, the input focus is set to the next control in the tab order. Controls with the xtd::forms::control::tab_stop property value of false are not included in the collection of controls in the tab order. The tab order can be manipulated by setting the control's xtd::forms::control::tab_index property value.
      virtual control& tab_stop(bool value);
      
      /// @brief Gets the object that contains data about the control.
      /// @return A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      virtual std::any tag() const noexcept;
      /// @brief Sets the object that contains data about the control.
      /// @param tag A std::any that contains data about the control. The default is empty.
      /// @return Current control.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      virtual control& tag(std::any tag);
      
      /// @brief Gets the text associated with this control.
      /// @return The text associated with this control.
      virtual const xtd::ustring& text() const noexcept;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      /// @return Current control.
      virtual control& text(const xtd::ustring& text);
      
      /// @brief Gets the toolkit handle that the control is bound to.
      /// @return An intptr that contains the toolkit handle (HWND) of the control.
      /// @remarks When the underlying toolkits is native, xtd::forms::control::handle and xtd::forms::control::toolkit_handle are the same, But if the underlying toolkit is not native, the xtd::forms::control::handle matches the toolkit handle while xtd::forms::control::toolkit_handle returns the toolkit handle.
      intptr toolkit_handle() const noexcept;
      
      /// @brief Gets the distance, in pixels, between the top edge of the control and the top edge of its container's client area.
      /// @return An Int32_t representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      virtual int32 top() const noexcept;
      /// @brief Sets the distance, in pixels, between the top edge of the control and the top edge of its container's client area.
      /// @param top An Int32_t representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
      /// @return Current control.
      virtual control& top(int32 top);
      
      /// @brief Gets the parent control that is not parented by another Windows Forms control. Typically, this is the outermost Form that the control is contained in.
      /// @return The control that represents the top-level control that contains the current control.
      virtual std::optional<control_ref> top_level_control() const noexcept;
      
      /// @brief Gets a value indicating whether the control and all its child controls are displayed.
      /// @return true if the control and all its child controls are displayed; otherwise, false. The default is true.
      virtual bool visible() const noexcept;
      /// @brief Sets a value indicating whether the control and all its child controls are displayed.
      /// @param visible true if the control and all its child controls are displayed; otherwise, false. The default is true.
      /// @return Current control.
      virtual control& visible(bool visible);
      
      /// @brief Gets the width of the control.
      /// @return The width of the control in pixels.
      virtual int32 width() const noexcept;
      /// @brief Sets the width of the control.
      /// @param width The width of the control in pixels.
      /// @return Current control.
      virtual control& width(int32 width);
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets a value indicating whether to catch calls on the wrong thread that access a xtd::forms::contrtol::handle property when an application is being debugged.
      /// @return true if calls on the wrong thread are caught; otherwise, false.
      /// @remarks When a thread other than the creating thread of a control tries to access one of that control's methods or properties, it often leads to unpredictable results. A common invalid thread activity is a call on the wrong thread that accesses the xtd::forms::control::handle property. Set xtd::forms::control::check_for_illegal_cross_thread_calls to true to find and diagnose this thread activity more easily while debugging.
      /// @warning Be careful, some OS don't support cross-thread UI operations!
      static bool check_for_illegal_cross_thread_calls() noexcept;
      /// @brief Sets a value indicating whether to catch calls on the wrong thread that access a xtd::forms::contrtol::handle property when an application is being debugged.
      /// @param value true if calls on the wrong thread are caught; otherwise, false.
      /// @remarks When a thread other than the creating thread of a control tries to access one of that control's methods or properties, it often leads to unpredictable results. A common invalid thread activity is a call on the wrong thread that accesses the xtd::forms::control::handle property. Set xtd::forms::control::check_for_illegal_cross_thread_calls to true to find and diagnose this thread activity more easily while debugging.
      /// @warning Be careful, some OS don't support cross-thread UI operations!
      static void check_for_illegal_cross_thread_calls(bool value);
      
      /// @brief Gets a value indicating which of the modifier keys (SHIFT, CTRL, and ALT) is in a pressed state.
      /// @return A bitwise combination of the keys values. The default is none.
      static forms::keys modifier_keys() noexcept;
      
      /// @brief Gets a value indicating which of the mouse buttons is in a pressed state.
      /// @return A bitwise combination of the mouse_buttons enumeration values. The default is none.
      static forms::mouse_buttons mouse_buttons() noexcept;
      
      /// @brief Gets the position of the mouse cursor in screen coordinates.
      /// @return A xtd::drawing::point that contains the coordinates of the mouse cursor relative to the upper-left corner of the screen.
      /// @remarks The xtd::forms::control::mouse_position property returns a xtd::drawing::point that represents the mouse cursor position at the time the property was referenced. The coordinates indicate the position on the screen, not relative to the control, and are returned regardless of whether the cursor is positioned over the control. The coordinates of the upper-left corner of the screen are 0,0.
      /// @remarks The xtd::forms::control::mouse_position property is identical to the xtd::forms::cursor::position property.
      static xtd::drawing::point mouse_position() noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      using isynchronize_invoke::begin_invoke;
      /// @brief Executes the specified delegate asynchronously on the thread that the control's underlying handle was created on.
      /// @param method A delegate to a method that takes no parameters.
      /// @return An async_result_invoke that represents the result of the begin_invoke(delegate) operation.
      xtd::async_result begin_invoke(delegate<void()> method) override;
      
      /// @brief Executes the specified delegate asynchronously with the specified arguments, on the thread that the control's underlying handle was created on.
      /// @param method A delegate to a method that takes parameters of the same number and type that are contained in the args parameter.
      /// @param args An array of objects to pass as arguments to the given method. This can be empty if no arguments are needed.
      /// @return An async_result_invoke that represents the result of the begin_invoke(delegate) operation.
      xtd::async_result begin_invoke(delegate<void(std::vector<std::any>)> method, const std::vector<std::any>& args) override;
      
      /// @brief Brings the control to the front of the z-order.
      /// @remarks The control is moved to the front of the z-order. If the control is a child of another control, the child control is moved to the front of the z-order. bring_to_front does not make a control a top-level control, and it does not raise the xtd::forms::control::paint event.
      virtual void bring_to_front();
      
      int32 compare_to(const control& value) const noexcept override;

      /// @brief Forces the creation of the visible control, including the creation of the handle and any visible child controls.
      /// @remarks The create_control method forces a handle to be created for the control and its child controls. This method is used when you need a handle immediately for manipulation of the control or its children; simply calling a control's constructor does not create the Handle.
      /// @remarks create_control does not create a control handle if the control's visible property is false. You can either call the create_control method or access the handle property to create the control's handle regardless of the control's visibility, but in this case, no window handles are created for the control's children.
      void create_control();
      
      /// @brief Creates the xtd::drawing::graphics for the control.
      /// @return A xtd::drawing::graphics for the control.
      /// @remarks The graphics object that you retrieve through the create_graphics method should not normally be retained after the current Windows message has been processed, because anything painted with that object will be erased with the next WM_PAINT message. Therefore you cannot cache the graphics object for reuse, except to use non-visual methods like xtd::drawing::graphics::measure_string. Instead, you must call create_graphics every time that you want to use the graphics object.
      drawing::graphics create_graphics() const;
      
      /// @brief Forces the destruction of the visible control, including the destruction of the handle and any visible child controls.
      /// @remarks The destroy_control method forces a handle to be destroyed for the control and its child controls.
      /// @par Notes to Inheritors
      /// When overriding destroy_control() in a derived class, be sure to call the base class's destroy_control() method to ensure that the handle is destroyed.
      virtual void destroy_control();
      
      /// @brief Retrieves the return value of the asynchronous operation represented by the async_result_invoke passed.
      /// @param async The async_result_invoke that represents a specific invoke asynchronous operation, returned when calling begin_invoke(delegate).
      std::optional<object_ref> end_invoke(xtd::async_result async) override;
      
      bool equals(const control& value) const noexcept override;
      
      /// @brief Sets input focus to the control.
      /// @return true if the input focus request was successful; otherwise, false.
      /// @remarks The focus method returns true if the control successfully received input focus. The control can have the input focus while not displaying any visual cues of having the focus. This behavior is primarily observed by the unselectable controls listed below, or any controls derived from them.
      bool focus();
      
      /// @brief Gets a value indicating how a control will behave when its auto_size property is enabled.
      /// @return auto_size_mode One of the xtd::forms::auto_size_mode values.
      auto_size_mode get_auto_size_mode() const;
      
      /// @cond
      /// @todo Remove when render is done.
      std::optional<xtd::drawing::color> get_back_color() const noexcept;
      /// @endcond
      
      /// @cond
      /// @todo Remove when render is done.
      std::optional<xtd::drawing::font> get_font() const noexcept;
      /// @endcond
      
      /// @cond
      /// @todo Remove when render is done.
      std::optional<xtd::drawing::color> get_fore_color() const noexcept;
      /// @endcond
      
      /// @brief Retrieves the index of a control within the control collection.
      /// @param child The control to search for in the control collection.
      /// @return A zero-based index value that represents the location of the specified child control within the control collection.
      /// @exception xtd::argument_exception The child control is not in the control::control_collection.
      size_t get_child_index(intptr child) const;
      
      /// @brief Retrieves the index of the specified child control within the control collection, and optionally raises an exception if the specified control is not within the control collection.
      /// @param child The control to search for in the control collection.
      /// @param throw_exception true to throw an exception if the control specified in the child parameter is not a control in the control::control_collection; otherwise, false.
      size_t get_child_index(intptr child, bool& throw_exception) const;
      
      /// @brief Conceals the control from the user.
      /// @remarks Hiding the control is equivalent to setting the visible property to false. After the hide method is called, the visible property returns a value of false until the show method is called.
      virtual void hide();
      
      /// @brief Invalidates the entire surface of the control and causes the control to be redrawn.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate() const;
      
      /// @brief Invalidates a specific region of the control and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
      /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(bool invalidate_children) const;
      
      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control.
      /// @param rect A xtd::drawing::rectangle that represents the region to invalidate.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(const drawing::rectangle& rect) const;
      
      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
      /// @param rect A xtd::drawing::rectangle that represents the region to invalidate.
      /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(const drawing::rectangle& rect, bool invalidate_children) const;
      
      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control.
      /// @param region A xtd::drawing::region that represents the region to invalidate.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(const drawing::region& region) const;
      
      /// @brief Invalidates the specified region of the control (adds it to the control's update region, which is the area that will be repainted at the next paint operation), and causes a paint message to be sent to the control. Optionally, invalidates the child controls assigned to the control.
      /// @param region A xtd::drawing::region that represents the region to invalidate.
      /// @param invalidate_children true to invalidate the control's child controls; otherwise, false.
      /// @remarks Calling the invalidate method does not force a synchronous paint; to force a synchronous paint, call the update method after calling the Invalidate method. When this method is called with no parameters, the entire client area is added to the update region.
      virtual void invalidate(const drawing::region& region, bool invalidate_children) const;
      
      using isynchronize_invoke::invoke;
      /// @brief Executes the specified delegate on the thread that owns the control's underlying window handle.
      /// @param method A delegate that contains a method to be called in the control's thread context.
      std::optional<object_ref> invoke(delegate<void()> method) override;
      /// @brief Executes the specified delegate, on the thread that owns the control's underlying window handle, with the specified list of arguments.
      /// @param method A delegate to a method that takes parameters of the same number and type that are contained in the args parameter.
      /// @param args An array of objects to pass as arguments to the specified method. This parameter can be null if the method takes no arguments.
      std::optional<object_ref> invoke(delegate<void(std::vector<std::any>)> method, const std::vector<std::any>& args) override;
      /// @brief Executes the specified delegate, on the thread that owns the control's underlying window handle, with the specified list of arguments.
      /// @param method A delegate to a method that takes parameters of the same number and type that are contained in the args parameter.
      /// @param args An array of objects to pass as arguments to the specified method. This parameter can be null if the method takes no arguments.
      std::optional<object_ref> invoke(delegate<void(std::vector<std::any>)> method, std::any arg) override;
      
      /// @brief Forces the control to apply layout logic to all its child controls.
      /// @remarks If the suspend_layout method was called before calling the perform_layout method, the xtd::forms::control::layout event is suppressed.
      void perform_layout();
      
      /// @brief Computes the location of the specified screen point into client coordinates.
      /// @param p The screen coordinate xtd::drawing::point to convert.
      /// @return A xtd::drawing::point that represents the converted xtd::drawing::point, p, in client coordinates.
      xtd::drawing::point point_to_client(const xtd::drawing::point& p) const;
      
      /// @brief Computes the location of the specified client point into screen coordinates.
      /// @param p The client coordinate  xtd::drawing::point to convert.
      /// @return A xtd::drawing::point that represents the converted  xtd::drawing::point, p, in screen coordinates.
      xtd::drawing::point point_to_screen(const xtd::drawing::point& p) const;
      
      /// @brief Preprocesses keyboard or input messages within the message loop before they are dispatched.
      /// @param message A xtd::forms::message, passed by reference, that represents the message to process. The possible values are WM_KEYDOWN, WM_SYSKEYDOWN, WM_CHAR, and WM_SYSCHAR.
      /// @return true if the message was processed by the control; otherwise, false.
      /// @remarks pre_process_message is called by the application's message loop to preprocess input messages before they are dispatched. Possible values for the msg parameter are WM_KEYDOWN, WM_SYSKEYDOWN, WM_CHAR, and WM_SYSCHAR.
      virtual bool pre_process_message(const xtd::forms::message& message);
      
      /// @brief Forces the control to invalidate its client area and immediately redraw itself and any child controls.
      /// @par Notes to Inheritors
      /// When overriding refresh() in a derived class, be sure to call the base class's refresh() method so the control and its child controls are invalidated and redrawn.
      virtual void refresh() const;
      
      /// @brief Resumes usual layout logic.
      /// @remarks Calling the resume_layout method forces an immediate layout if there are any pending layout requests.
      /// @remarks The suspend_layout and resume_layout methods are used in tandem to suppress multiple layout events while you adjust multiple attributes of the control. For example, you would typically call the suspend_layout method, then set the size, location, anchor, or dock properties of the control, and then call the resume_layout method to enable the changes to take effect.
      /// @remarks There must be no pending calls to suspend_layout for resume_layout to be successfully called.
      void resume_layout();
      
      /// @brief Resumes usual layout logic, optionally forcing an immediate layout of pending layout requests.
      /// @param perform_layout true to execute pending layout requests; otherwise, false.
      /// @remarks Calling the resume_layout method forces an immediate layout if there are any pending layout requests. When the perform_layout parameter is set to true, an immediate layout occurs if there are any pending layout requests.
      /// @remarks The suspend_layout and resume_layout methods are used in tandem to suppress multiple xtd::forms::control::layout events while you adjust multiple attributes of the control. For example, you would typically call the suspend_layout method, then set the size, location, anchor, or dock properties of the control, and then call the resume_layout method to enable the changes to take effect.
      /// @remarks There must be no pending calls to suspend_layout for resume_layout to be successfully called.
      /// @note When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. This will increase the performance of applications with many controls.
      void resume_layout(bool perform_layout);
      
      /// @brief Send a message with specified hwnd, message, wparam and lparam.
      /// @param hwnd The window handle of the message.
      /// @param msg The ID number for the message.
      /// @param wparam The WParam field of the message.
      /// @param lparam The LParam field of the message.
      /// @return The return value of the message.
      intptr send_message(intptr hwnd, int32 msg, intptr wparam, intptr lparam) const;
      
      /// @brief Sets a value indicating how a control will behave when its auto_size property is enabled.
      /// @param auto_size_mode One of the xtd::forms::auto_size_mode values.
      void set_auto_size_mode(auto_size_mode auto_size_mode);
      
      /// @brief Sets the bounds of the control to the specified location and size.
      /// @param x The new left property value of the control.
      /// @param y The new top property value of the control.
      /// @param width The new width property value of the control.
      /// @param height The new height property value of the control.
      void set_bounds(int32 x, int32 y, int32 width, int32 height);
      
      /// @brief Sets the specified bounds of the control to the specified location and size.
      /// @param x The new left property value of the control.
      /// @param y The new top property value of the control.
      /// @param width The new width property value of the control.
      /// @param height The new height property value of the control.
      /// @param specified A bitwise combination of the xtd::forms::bounds_specified values. For any parameter not specified, the current value will be used.
      void set_bounds(int32 x, int32 y, int32 width, int32 height, bounds_specified specified);
      
      /// @brief Displays the control to the user.
      /// @remarks Showing the control is equivalent to setting the visible property to true. After the show method is called, the visible property returns a value of true until the hide method is called.
      virtual void show();
      
      /// @brief Temporarily suspends the layout logic for the control.
      /// @remarks The layout logic of the control is suspended until the resume_layout method is called.
      /// @remarks The suspend_layout and resume_layout methods are used in tandem to suppress multiple xtd::forms::control::layout events while you adjust multiple attributes of the control. For example, you would typically call the suspend_layout method, then set the size, location, anchor, or dock properties of the control, and then call the resume_layout method to enable the changes to take effect.
      /// @remarks There must be no pending calls to suspend_layout for resume_layout to be successfully called.
      /// @note When adding several controls to a parent control, it is recommended that you call the suspend_layout method before initializing the controls to be added. After adding the controls to the parent control, call the resume_layout method. This will increase the performance of applications with many controls.
      void suspend_layout();
      
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
      /// @}
      
      /// @name Operators
      
      /// @{
      /// @brief Add child control.
      /// @param parent A control that represents the parent or container control of the control.
      /// @param child A control to add to parent.
      /// @return Current control.
      control& operator <<(control& child);
      
      /// @brief Remove child control.
      /// @param parent A control that represents the parent or container control of the control.
      /// @param child A control to remove to parent.
      /// @return Current control.
      control& operator >>(control& child);
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create a specified control.
      /// @return New control created.
      static control create();
      /// @brief A factory to create a specified control with specified location.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @return New control created.
      static control create(const drawing::point& location);
      /// @brief A factory to create a specified control with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @return New control created.
      static control create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create a specified control with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param name The name of the control.
      /// @return New control created.
      static control create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create a specified control with specified parent.
      /// @param parent The parent that contains the new created control.
      /// @return New control created.
      static control create(const control& paren);
      /// @brief A factory to create a specified control with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param name The name of the control.
      /// @return New control created.
      static control create(const control& parent, const drawing::point& location);
      /// @brief A factory to create a specified control with specified parent, location, and size.
      /// @param parent The parent that contains the new created control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @return New control created.
      static control create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create a specified control with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param name The name of the control.
      /// @return New control created.
      static control create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create a specified control.
      /// @return New control created.
      template<typename control_t>
      static control_t create() {
        auto result = control_t {};
        return result;
      }
      /// @brief A factory to create a specified control with specified location.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const drawing::point& location) {
        auto result = control_t {};
        result.location(location);
        return result;
      }
      /// @brief A factory to create a specified control with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const drawing::point& location, const drawing::size& size) {
        auto result = control_t {};
        result.location(location);
        result.size(size);
        return result;
      }
      /// @brief A factory to create a specified control with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param name The name of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
        auto result = control_t {};
        result.location(location);
        result.size(size);
        result.name(name);
        return result;
      }
      /// @brief A factory to create a specified control with specified parent.
      /// @param parent The parent that contains the new created control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const control& parent) {
        auto result = control_t {};
        result.parent(parent);
        return result;
      }
      /// @brief A factory to create a specified control with specified parent, and location.
      /// @param parent The parent that contains the new created control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const control& parent, const drawing::point& location) {
        auto result = control_t {};
        result.parent(parent);
        result.location(location);
        return result;
      }
      /// @brief A factory to create a specified control with specified parent, location, and size.
      /// @param parent The parent that contains the new created control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const control& parent, const drawing::point& location, const drawing::size& size) {
        auto result = control_t {};
        result.parent(parent);
        result.location(location);
        result.size(size);
        return result;
      }
      /// @brief A factory to create a specified control with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param name The name of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
        auto result = control_t {};
        result.parent(parent);
        result.location(location);
        result.size(size);
        result.name(name);
        return result;
      }
      /// @brief A factory to create a specified control with specified text.
      /// @param text A string that represent text of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const xtd::ustring& text) {
        auto result = control_t {};
        result.text(text);
        return result;
      }
      /// @brief A factory to create a specified control with specified text, and location.
      /// @param text A string that represent text of the control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const xtd::ustring& text, const drawing::point& location) {
        auto result = control_t {};
        result.text(text);
        result.location(location);
        return result;
      }
      /// @brief A factory to create a specified control with specified text, location, and size.
      /// @param text A string that represent text of the control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
        auto result = control_t {};
        result.text(text);
        result.location(location);
        result.size(size);
        return result;
      }
      /// @brief A factory to create a specified control with specified text, location,size, and name.
      /// @param text A string that represent text of the control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param name The name of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
        auto result = control_t {};
        result.text(text);
        result.location(location);
        result.size(size);
        result.name(name);
        return result;
      }
      /// @brief A factory to create a specified control with specified parent, and text.
      /// @param parent The parent that contains the new created control.
      /// @param text A string that represent text of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const control& parent, const xtd::ustring& text) {
        auto result = control_t {};
        result.parent(parent);
        result.text(text);
        return result;
      }
      /// @brief A factory to create a specified control with specified parent, text, and location.
      /// @param parent The parent that contains the new created control.
      /// @param text A string that represent text of the control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const control& parent, const xtd::ustring& text, const drawing::point& location) {
        auto result = control_t {};
        result.parent(parent);
        result.text(text);
        result.location(location);
        return result;
      }
      /// @brief A factory to create a specified control with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created control.
      /// @param text A string that represent text of the control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size) {
        auto result = control_t {};
        result.parent(parent);
        result.text(text);
        result.location(location);
        result.size(size);
        return result;
      }
      /// @brief A factory to create a specified control with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created control.
      /// @param text A string that represent text of the control.
      /// @param location A xtd::drawing::point that represent location of the control.
      /// @param size A xtd::drawing::size that represent size of the control.
      /// @param name The name of the control.
      /// @return New control created.
      template<typename control_t>
      static control_t create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name) {
        auto result = control_t {};
        result.parent(parent);
        result.text(text);
        result.location(location);
        result.size(size);
        result.name(name);
        return result;
      }
      
      /// @brief Retrieves the control that contains the specified handle.
      /// @param handle The window handle (HWND) to search for.
      /// @return The control that represents the control associated with the specified handle; returns null if no control with the specified handle is found.
      /// @remarks This method searches up the window handle parent chain until it finds a handle that is associated with a control. This method is more reliable than the from_handle method, because it correctly returns controls that own more than one handle.
      static std::optional<control_ref> from_child_handle(intptr handle);
      
      /// @brief Returns the control that is currently associated with the specified handle.
      /// @param handle The window handle (HWND) to search for.
      /// @return A control that represents the control associated with the specified handle; returns null if no control with the specified handle is found.
      static std::optional<control_ref> from_handle(intptr handle);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the value of the xtd::forms::control::auto_size property changes.
      /// @remarks This event is raised if the xtd::forms::control::auto_size property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> auto_size_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::back_color property changes.
      /// @remarks This event is raised if the xtd::forms::control::back_color property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> back_color_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::background_image property changes.
      /// @remarks This event is raised if the xtd::forms::control::background_image property is changed by either a programmatic modification or user interaction
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> background_image_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::background_image_layout property changes.
      /// @remarks This event is raised if the xtd::forms::control::background_image_layout property is changed by either a programmatic modification or user interaction
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> background_image_layout_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::control_appearance property changes.
      /// @remarks This event is raised if the control_appearance property is changed by either a programmatic modification or user interaction
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> control_appearance_changed;
      
      /// @brief Occurs when the xtd::forms::control is clicked.
      /// @remarks The xtd::forms::control::click event passes an xtd::event_args to its event handler, so it only indicates that a click has occurred. If you need more specific mouse information (button, number of clicks, wheel rotation, or location), use the xtd::forms::control::mouse_click event. However, the xtd::forms::control::mouse_click event will not be raised if the click is caused by action other than that of the mouse, such as pressing the ENTER key.
      /// @remarks A double-click is determined by the mouse settings of the user's operating system. The user can set the time between clicks of a mouse button that should be considered a double-click rather than two clicks. The xtd::forms::control::click event is raised every time a control is double-clicked. For example, if you have event handlers for the xtd::forms::control::click and xtd::forms::control::double_click events of a xtd::forms::form, the xtd::forms::control::click and xtd::forms::control::double_click events are raised when the form is double-clicked and both methods are called. If a control is double-clicked and that control does not support the xtd::forms::control::double_click event, the xtd::forms::control::click event might be raised twice.
      /// @remarks You must set the standard_click value of xtd::forms::control_styles to true for this event to be raised.
      /// @note The following events are not raised for the xtd::forms::tab_control class unless there is at least one xtd::forms::tab_page in the xtd::forms::tab_control. xtd::forms::tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one xtd::forms::tab_page in the collection, and the user interacts with the tab control's header (where the xtd::forms::tab_page names appear), the xtd::forms::tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the xtd::forms::tab_page raises the appropriate event.
      /// @par Notes to Inheritors
      /// Inheriting from a standard Windows Forms control and changing the standard_click or standard_double_click values of xtd::forms::control_styles to true can cause unexpected behavior or have no effect at all if the control does not support the click or xtd::forms::control::double_click events.
      /// @remarks The following table lists Windows Forms controls and which event (xtd::forms::control::click or xtd::forms::control::double_click) is raised in response to the mouse action specified.
      /// | Control                                                                                                                                                                                                                                                                                                                                                                                                                                                                     | Left Mouse Click | Left Mouse Double Click | Right Mouse Click | Right Mouse Click   | Middle Mouse Click | Middle Mouse Double Click | XButton1 Mouse Click | XButton1 Mouse Double-Click | XButton2 Mouse Click | XButton2 Mouse Double-Click |
      /// | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------- | ----------------------- | ----------------- | ------------------- | ------------------ | ------------------------- | -------------------- | --------------------------- | -------------------- | --------------------------- |
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
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> click;
      
      /// @brief Occurs when the value of the xtd::forms::control::client_size property changes.
      /// @remarks This event is raised if the xtd::forms::control::client_size property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> client_size_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::cursor property changes.
      /// @remarks This event is raised if the xtd::forms::control::cursor property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> cursor_changed;
      
      /// @brief Occurs when a new xtd::forms::control::control is added to the xtd::forms::control::control_collection.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, control_event_handler> control_added;
      
      /// @brief Occurs when a new xtd::forms::control:: is removed to the xtd::forms::control::control_collection.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, control_event_handler> control_removed;
      
      /// @brief Occurs when the value of the xtd::forms::control::dock property changes.
      /// @remarks This event is raised if the xtd::forms::control::dock property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> dock_changed;
      
      /// @brief Occurs when the xtd::forms::control is double-clicked.
      /// @remarks A double-click is determined by the mouse settings of the user's operating system. The user can set the time between clicks of a mouse button that should be considered a double-click rather than two clicks. The click event is raised every time a control is double-clicked. For example, if you have event handlers for the xtd::forms::control::click and xtd::forms::control::double_click events of a xtd::forms::form, the xtd::forms::control::click and xtd::forms::control::double_click events are raised when the form is double-clicked and both methods are called. If a control is double-clicked and that control does not support the xtd::forms::control::double_click event, the click event might be raised twice.
      /// @remarks You must set the standard_double_click and standard_click value of xtd::forms::control_styles to true for this event to be raised.
      /// @note The following events are not raised for the xtd::forms::tab_control class unless there is at least one xtd::forms::tab_page in the xtd::forms::tab_control. xtd::forms::tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one xtd::forms::tab_page in the collection, and the user interacts with the tab control's header (where the xtd::forms::tab_page names appear), the xtd::forms::tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the xtd::forms::tab_page raises the appropriate event.
      /// @par Notes to Inheritors
      /// Inheriting from a standard Windows Forms control and changing the standard_click or standard_double_click values of xtd::forms::control_styles to true can cause unexpected behavior or have no effect at all if the control does not support the xtd::forms::control::click or xtd::forms::control::double_click events.
      /// @remarks The following table lists Windows Forms controls and which event (xtd::forms::control::click or xtd::forms::control::double_click) is raised in response to the mouse action specified.
      /// | Control                                                                                                                                                                                                                                                                                                                                                                                                                                                                     | Left Mouse Click | Left Mouse Double Click | Right Mouse Click | Right Mouse Click   | Middle Mouse Click | Middle Mouse Double Click | XButton1 Mouse Click | XButton1 Mouse Double-Click | XButton2 Mouse Click | XButton2 Mouse Double-Click |
      /// | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------- | ----------------------- | ----------------- | ------------------- | ------------------ | ------------------------- | -------------------- | --------------------------- | -------------------- | --------------------------- |
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
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> double_click;
      
      /// @brief Occurs when the xtd::forms::control receives focus.
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
      /// @remarks Note The xtd::forms::control::got_focus and xtd::forms::control::lost_focus events are low-level focus events that are tied to the WM_KILLFOCUS and WM_SETFOCUS Windows messages. Typically, the xtd::forms::control::got_focus and xtd::forms::control::lost_focus events are only used when updating when writing custom controls. Instead the enter and leave events should be used for all controls except the xtd::forms::form class, which uses the activated and deactivate events.
      /// @warning Do not attempt to set focus from within the xtd::forms::control::enter, xtd::forms::control::got_focus, xtd::forms::control::leave, xtd::forms::control::lost_focus, xtd::forms::control::validating, or xtd::forms::control::validated event handlers. Doing so can cause your application or the operating system to stop responding.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> got_focus;
      
      /// @brief Occurs when a handle is created for the xtd::forms::control.
      /// @remarks A handle is created when the xtd::forms::control is displayed for the first time. For example, if a xtd::forms::control is created that has visible set to false, the xtd::forms::control::handle_created event will not be raised until visible is set to true.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> handle_created;
      
      /// @brief Occurs when the control's handle is in the process of being destroyed.
      /// @remarks During the xtd::forms::control::handle_destroyed event, the control is still a valid Windows control and the handle can be recreated by calling the recreate_handle method.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> handle_destroyed;
      
      /// @brief Occurs when the value of the xtd::forms::control::enabled property changes.
      /// @remarks This event is raised if the xtd::forms::control::enabled property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> enabled_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::fore_color property changes.
      /// @remarks This event is raised if the xtd::forms::control::fore_color property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> fore_color_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::font property changes.
      /// @remarks This event is raised if the xtd::forms::control::font property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> font_changed;
      
      /// @brief Occurs when the user requests help for a xtd::forms::control.
      /// @remarks The xtd::forms::control::help_requested event is commonly raised when the user presses the F1 key or an associated context-sensitive help button is clicked.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, help_event_handler> help_requested;
      
      /// @brief Occurs when a key is pressed while the xtd::forms::control has focus.
      /// @remarks Key events occur in the following order:
      /// 1. xtd::forms::control::key_down event
      /// 1. xtd::forms::control::key_press event
      /// 1. xtd::forms::control::key_up event
      /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the xtd::forms::key_press_event_args::handled property in your form's xtd::forms::control::key_press event-handling method to true. Certain keys, such as the TAB, RETURN, ESC, and arrow keys are handled by controls automatically. To have these keys raise the xtd::forms::control::key_down event, you must override the is_input_key method in each control on your form. The code for the override of the is_input_key would need to determine if one of the special keys is pressed and return a value of true. Instead of overriding the is_input_key method, you can handle the preview_key_down event and set the is_input_key property to true.
      /// @par Examples
      /// The following code example demonstrates the use of control keyboard events.
      /// @include key_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, key_event_handler> key_down;
      
      /// @brief Occurs when a character. space or backspace key is pressed while the xtd::forms::control has focus.
      /// @remarks Key events occur in the following order:
      /// 1. xtd::forms::control::key_down event
      /// 1. xtd::forms::control::key_press event
      /// 1. xtd::forms::control::key_up event
      /// @remarks The xtd::forms::control::key_press event is not raised by non-character keys other than space and backspace; however, the non-character keys do raise the xtd::forms::control::key_down and xtd::forms::control::key_up events.
      /// @remarks Use the xtd::forms::key_press_event_args::key_char property to sample keystrokes at run time and to consume or modify a subset of common keystrokes.
      /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the xtd::forms::key_press_event_args::handled property in your form's xtd::forms::control::key_press event-handling method to true.
      /// @par Examples
      /// The following code example demonstrates the use of control keyboard events.
      /// @include key_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, key_press_event_handler> key_press;
      
      /// @brief Occurs when a key is released while the xtd::forms::control has focus.
      /// @remarks Key events occur in the following order:
      /// 1. xtd::forms::control::key_down event
      /// 1. xtd::forms::control::key_press event
      /// 1. xtd::forms::control::key_up event
      /// @remarks To handle keyboard events only at the form level and not enable other controls to receive keyboard events, set the xtd::forms::key_press_event_args::handled property in your form's xtd::forms::control::key_press event-handling method to true. Certain keys, such as the TAB, RETURN, ESC, and arrow keys are handled by controls automatically. To have these keys raise the xtd::forms::control::key_down event, you must override the is_input_key method in each control on your form. The code for the override of the is_input_key would need to determine if one of the special keys is pressed and return a value of true. Instead of overriding the is_input_key method, you can handle the preview_key_down event and set the is_input_key property to true.
      /// @par Examples
      /// The following code example demonstrates the use of control keyboard events.
      /// @include key_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, key_event_handler> key_up;
      
      /// @brief Occurs when a xtd::forms::control should reposition its child controls.
      /// @remarks The xtd::forms::control::layout event occurs when child controls are added or removed, when the bounds of the control changes, and when other changes occur that can affect the layout of the control. The xtd::forms::control::layout event can be suppressed using the suspend_layout and resume_layout methods. Suspending layout enables you to perform multiple actions on a control without having to perform a layout for each change. For example, if you resize and move a control, each operation would raise a xtd::forms::control::layout event.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> layout;
      
      /// @brief Occurs when the value of the xtd::forms::control::location property changes.
      /// @remarks This event is raised if the xtd::forms::control::location property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> location_changed;
      
      /// @brief Occurs when the xtd::forms::control loses focus.
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
      /// @remarks Note The xtd::forms::control::got_focus and xtd::forms::control::lost_focus events are low-level focus events that are tied to the WM_KILLFOCUS and WM_SETFOCUS Windows messages. Typically, the xtd::forms::control::got_focus and xtd::forms::control::lost_focus events are only used when updating when writing custom controls. Instead the enter and leave events should be used for all controls except the xtd::forms::form class, which uses the activated and deactivate events.
      /// @warning Do not attempt to set focus from within the xtd::forms::control::enter, xtd::forms::control::got_focus, xtd::forms::control::leave, xtd::forms::control::lost_focus, xtd::forms::control::validating, or xtd::forms::control::validated event handlers. Doing so can cause your application or the operating system to stop responding.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> lost_focus;
      
      /// @brief Occurs when the xtd::forms::control is clicked by the mouse.
      /// @remarks Depressing a mouse button when the cursor is over a control typically raises the following series of events from the control:
      /// 1. xtd::forms::control::mouse_down event
      /// 2. xtd::forms::control::click event
      /// 3. xtd::forms::control::mouse_click event
      /// 4. xtd::forms::control::mouse_up event
      /// @remarks For this to occur, the various events cannot be disabled in the control's class.
      /// @remarks Two single clicks that occur close enough in time, as determined by the mouse settings of the user's operating system, will generate a xtd::forms::control::mouse_double_click event instead of the second xtd::forms::control::mouse_click event.
      /// @par important
      /// click events are logically higher-level events of a control. They are often raised by other actions, such as pressing the ENTER key when the control has focus.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, mouse_event_handler> mouse_click;
      
      /// @brief Occurs when the xtd::forms::control is double clicked by the mouse.
      /// @remarks The xtd::forms::control::mouse_double_click event occurs when the user depresses a mouse button twice in quick succession when the cursor is over the control. The time interval that separates two single clicks from a double-click is determined by the mouse settings of the user's operating system.
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
      /// xtd::forms::control::double_click events are logically higher-level events of a control. They may be raised by other user actions, such as shortcut key combinations.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, mouse_event_handler> mouse_double_click;
      
      /// @brief Occurs when the mouse pointer is over the xtd::forms::control and a mouse button is pressed.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, mouse_event_handler> mouse_down;
      
      /// @brief Occurs when the mouse pointer enters the xtd::forms::control.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> mouse_enter;
      
      /// @brief Occurs when the mouse horizontal wheel moves while the xtd::forms::control has focus.
      /// @remarks When handling the xtd::forms::control::mouse_horizontal_wheel event it is important to follow the user interface (UI) standards associated with the mouse wheel. The mouse_event_args::delta property value indicates the amount the mouse wheel has been moved.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, mouse_event_handler> mouse_horizontal_wheel;
      
      /// @brief Occurs when the mouse pointer leaves the xtd::forms::control.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> mouse_leave;
      
      /// @brief Occurs when the mouse pointer is moved over the xtd::forms::control.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, mouse_event_handler> mouse_move;
      
      /// @brief Occurs when the mouse pointer is over the xtd::forms::control and a mouse button is released.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, mouse_event_handler> mouse_up;
      
      /// @brief Occurs when the mouse wheel moves while the xtd::forms::control has focus.
      /// @remarks When handling the xtd::forms::control::mouse_wheel event it is important to follow the user interface (UI) standards associated with the mouse wheel. The mouse_event_args::delta property value indicates the amount the mouse wheel has been moved. The UI should scroll when the accumulated delta is plus or minus 120. The UI should scroll the number of logical lines returned by the system_information::mouse_wheel_scroll_lines property for every delta value reached. You can also scroll more smoothly in smaller that 120 unit increments, however the ratio should remain constant, that is system_information::mouse_wheel_scroll_lines lines scrolled per 120 delta units of wheel movement.
      /// @remarks Mouse events occur in the following order:
      /// 1. xtd::forms::control::mouse_enter
      /// 2. xtd::forms::control::mouse_move
      /// 3. xtd::forms::control::mouse_hover / xtd::forms::control::mouse_down / xtd::forms::control::mouse_wheel / xtd::forms::control::mouse_horizontal_wheel
      /// 4. xtd::forms::control::mouse_up
      /// 5. xtd::forms::control::mouse_leave
      /// @note The following events are not raised for the tab_control class unless there is at least one tab_page in the tab_control::tab_pages collection: xtd::forms::control::click, xtd::forms::control::double_click, xtd::forms::control::mouse_down, xtd::forms::control::mouse_up, xtd::forms::control::mouse_hover, xtd::forms::control::mouse_enter, xtd::forms::control::mouse_leave and xtd::forms::control::mouse_move. If there is at least one tab_page in the collection, and the user interacts with the tab control's header (where the tab_page names appear), the tab_control raises the appropriate event. However, if the user interaction is within the client area of the tab page, the tab_page raises the appropriate event.
      /// @par Examples
      /// The following code example demonstrates the use of control mouse events.
      /// @include mouse_events.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, mouse_event_handler> mouse_wheel;
      
      /// @brief Occurs when the control is moved.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> move;
      
      /// @brief Occurs when the xtd::forms::control is redrawn.
      /// @remarks The xtd::forms::control::paint event is raised when the control is redrawn. It passes an instance of paint_event_args to the method(s) that handles the xtd::forms::control::paint event. The xtd::forms::control::paint event is raised when the control is redrawn. It passes an instance of paint_event_args to the method(s) that handles the xtd::forms::control::paint event.
      /// @remarks When creating a new custom control or an inherited control with a different visual appearance, you must provide code to render the control by overriding the on_paint method.
      /// @par Examples
      /// The following code example demonstrates the use of control paint events.
      /// @include form_paint.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, paint_event_handler> paint;
      
      /// @brief Occurs when the value of the xtd::forms::control::parent property changes.
      /// @remarks This event is raised if the xtd::forms::control::parent property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> parent_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::region property changes.
      /// @remarks This event is raised if the xtd::forms::control::region property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> region_changed;
      
      /// @brief Occurs when the xtd::forms::control is resized.
      /// @remarks To determine the size of the resized control, you can cast the sender parameter of the registered control_event_handler method to a control and get its size property (or height and width properties individually).
      /// @remarks To handle custom layouts, use the xtd::forms::control::layout event instead of the xtd::forms::control::resize event. The xtd::forms::control::layout event is raised in response to a xtd::forms::control::resize event, but also in response to other changes that affect the layout of the control.
      /// @par Examples
      /// The following code example demonstrates the use of control xtd::forms::control::resize event.
      /// @include dot_matrix_display.cpp
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> resize;
      
      /// @brief Occurs when the value of the xtd::forms::control::right_to_left property changes.
      /// @remarks This event is raised if the xtd::forms::control::right_to_left property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> right_to_left_changed;

      /// @brief Occurs when the value of the xtd::forms::control::size property changes.
      /// @remarks This event is raised if the xtd::forms::control::size property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> size_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::style_sheet property changes or when xtd::application::style_sheet property changes.
      /// @remarks This event is raised if the xtd::forms::control::style_sheet property is changed or when xtd::application::style_sheet property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> style_sheet_changed;
      
      /// @brief Occurs when the xtd::drwing::system_colors changes.
      /// @remarks This event is raised if the xtd::drawing::system_colors is changed. For example when automatic dark mode switching on macOS.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> system_colors_changed;

      /// @brief Occurs when the xtd::forms::control::tab_stop property value changes.
      /// @remarks This event is raised if the xtd::forms::control::tab_stop property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> tab_stop_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::text property changes.
      /// @remarks This event is raised if the xtd::forms::control::text property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> text_changed;
      
      /// @brief Occurs when the value of the xtd::forms::control::visible property changes.
      /// @remarks This event is raised if the xtd::forms::control::visible property is changed by either a programmatic modification or user interaction.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<control, event_handler> visible_changed;
      /// @}
      
    protected:
      friend class application;
      friend class context_menu;
      friend class horizontal_layout_panel;
      friend class paint_event_args;
      friend class screen;
      friend class vertical_layout_panel;
      friend class style_sheets::style_sheet;
      
      /// @name Protected Properties
      
      /// @{
      /// @brief Gets state.
      /// @return One of xtd::forms::visual_styles::control_state values.
      xtd::forms::visual_styles::control_state control_state() const noexcept;
      
      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      /// @remarks The create_params property should not be overridden and used to adjust the properties of your derived control. Properties such as the create_params::caption, create_params::width, and create_params::height should be set by the corresponding properties in your control such as control::text, control::width and control::height. The create_params should only be extended when you are wrapping a standard Windows control class or to set styles not provided by the forms namespace.
      /// @par Notes for inheritors
      /// When overriding the create_params property in a derived class, use the base class's create_params property to extend the base implementation. Otherwise, you must provide all the implementation.
      virtual forms::create_params create_params() const noexcept;
      
      /// @brief Gets the default background color of the control.
      /// @return The default background color of the control. The default is control.
      /// @remarks This is the default back_color property value of a generic top-level control. Derived classes can have different defaults.
      virtual drawing::color default_back_color() const noexcept;
      
      /// @brief Gets the default cursor for the control.
      /// @return An object of type xtd::forms::cursor representing the current default cursor.
      virtual forms::cursor default_cursor() const noexcept;
      
      /// @brief Gets the default font of the control.
      /// @return The default font of the control. The value returned will vary depending on the user's operating system the local culture setting of their system.
      virtual drawing::font default_font() const noexcept;
      
      /// @brief Gets the default foreground color of the control.
      /// @return The default foreground color of the control. The default is control_text.
      virtual drawing::color default_fore_color() const noexcept;
      
      /// @brief Gets the default size of the control.
      /// @return The default size of the control.
      virtual drawing::size default_size() const noexcept;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      std::unique_ptr<xtd::object> clone() const override;
      
      /// @brief Creates a handle for the control.
      /// @remarks You typically should not call the create_handle method directly. The preferred method is to call the create_control method, which forces a handle to be created for the control and its child controls when the control is created.
      /// @par Notes to Inheritors
      /// When overriding create_handle() in a derived class, be sure to call the base class's create_handle() method to ensure that the handle is created.
      virtual void create_handle();
      
      /// @brief Destroys the handle associated with the control.
      /// @par Notes to Inheritors
      /// When overriding destroy_handle() in a derived class, be sure to call the base class's destroy_handle() method to ensure that the handle is destroyed.
      virtual void destroy_handle();
      
      /// @brief Sends the specified message to the default window procedure.
      /// @param message The Windows Message to process.
      virtual void def_wnd_proc(message& message);
      
      /// @brief Retrieves the value of the specified control style bit for the control.
      /// @param flag The control_styles bit to return the value from.
      /// @return true if the specified control style bit is set to true; otherwise, false.
      /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the set_style method and passing in the appropriate control_styles bit and the bool value to set the bit to. To determine the value assigned to a specified control_styles bit, use the get_style method and pass in the control_styles member to evaluate.
      bool get_style(control_styles flag) const noexcept;
      
      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      virtual drawing::size measure_control() const noexcept;
      
      /// @brief Measure this control text.
      /// @return The drawing::size size of this control text.
      drawing::size measure_text() const noexcept;
      
      /// @brief Raises the xtd::forms::control::auto_size_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_auto_size_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::back_color_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_back_color_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::background_image_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_background_image_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::background_image_layout_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_background_image_layout_changed(const event_args& e);
      
      /// @brief Raises the control::control_appearance_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_control_appearance_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::click event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_click(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::client_size_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_client_size_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::control_added event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_control_added(const control_event_args& e);
      
      /// @brief Raises the xtd::forms::control::control_removed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_control_removed(const control_event_args& e);
      
      /// @brief Raises the xtd::forms::control::create_control event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_create_control();
      
      /// @brief Raises the xtd::forms::control::cursor_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_cursor_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::destroy_control event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_destroy_control();
      
      /// @brief Raises the xtd::forms::control::dock_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_dock_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::double_click event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_double_click(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::enabled_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_enabled_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::fore_color_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_fore_color_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::font_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_font_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::got_focus event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_got_focus(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::handle_created event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_handle_created(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::handle_destroyed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_handle_destroyed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::help_requested event.
      /// @param e A xtd::forms::help_event_args that contains the event data.
      virtual void on_help_requested(help_event_args& e);
      
      /// @brief Raises the xtd::forms::control::key_down event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_key_down(key_event_args& e);
      
      /// @brief Raises the xtd::forms::control::key_press event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_key_press(key_press_event_args& e);
      
      /// @brief Raises the xtd::forms::control::key_up event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_key_up(key_event_args& e);
      
      /// @brief Raises the xtd::forms::control::layout event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_layout(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::location_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_location_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::lost_focus event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_lost_focus(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_click event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_click(const mouse_event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_double_click event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_double_click(const mouse_event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_down event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_down(const mouse_event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_enter event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_enter(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_horizontal_wheel event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_horizontal_wheel(const mouse_event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_leave event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_leave(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_move event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_move(const mouse_event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_up event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_up(const mouse_event_args& e);
      
      /// @brief Raises the xtd::forms::control::mouse_wheel event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_mouse_wheel(const mouse_event_args& e);
      
      /// @brief Raises the xtd::forms::control::move event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_move(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::paint event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_paint(paint_event_args& e);
      
      /// @brief Paints the background of the xtd::forms::control.
      /// @param e An xtd::event_args that contains the event data.
      /// @remarks The xtd::forms::control::on_paint_background method enables derived classes to handle Windows background erase requests.
      virtual void on_paint_background(paint_event_args& e);
      
      /// @brief Raises the xtd::forms::control::parent_back_color_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_parent_back_color_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::parent_cursor_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_parent_cursor_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::parent_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_parent_changed(const event_args& e);
      
      /// @brief Raises the xtd::control::enabled_changed event when the xtd::control::enabled property value of the control's container changes..
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_parent_enabled_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::parent_fore_color_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_parent_fore_color_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::parent_font_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_parent_font_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::region event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_resize(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::region_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_region_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::right_to_left_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_right_to_left_changed(const event_args& e);

      /// @brief Raises the xtd::forms::control::size_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_size_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::style_sheet_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_style_sheet_changed(const event_args& e);
      
      /// @brief Raises the control::system_colors_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_system_colors_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::tab_stop_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_tab_stop_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::text_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_text_changed(const event_args& e);
      
      /// @brief Raises the xtd::forms::control::visible_changed event.
      /// @param e An xtd::event_args that contains the event data.
      virtual void on_visible_changed(const event_args& e);
      
      void post_recreate_handle() noexcept;
      
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
      /// When overriding set_bounds_core(int32, int32, int32, int32, bounds_specified) in a derived class, be sure to call the base class's set_bounds_core(int32, int32, int32, int32, bounds_specified) method to force the bounds of the control to change. Derived classes can add size restrictions to the set_bounds_core(int32, int32, int32, int32, bounds_specified) method.
      virtual void set_bounds_core(int32 x, int32 y, int32 width, int32 height, bounds_specified specified);
      
      /// @brief Sets a value indicating whether the control can receive focus.
      /// @param value true if the control can receive focus; otherwise, false.
      /// @remarks In order for a control to receive input focus, the control must have a handle assigned to it, and the visible and enabled properties must both be set to true for both the control and all its parent controls, and the control must be a form or the control's outermost parent must be a form.
      void set_can_focus(bool value);
      
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      /// @return Current control.
      virtual void set_text(const xtd::ustring& text);
      
      /// @brief Sets the size of the client area of the control.
      /// @param width The client area width, in pixels.
      /// @param height The client area height, in pixels.
      /// @remarks The client area starts at the (0, 0) location and extends to the (width, height) location.
      /// @remarks Typically, you should not set the client_size of the control.
      /// @par Notes to Inheritors
      /// When overriding set_client_size_core(int32, int32) in a derived class, be sure to call the base class's set_client_size_core(int32, int32) method so that the client_size property is adjusted.
      virtual void set_client_size_core(int32 width, int32 height);
            
      /// @brief Sets the parent handle of the control.
      /// @param handle The parent handle.
      void set_parent(intptr handle);
      
      /// @brief Sets a specified control_styles flag to either true or false.
      /// @param flag The control_styles bit to set.
      /// @param value true to apply the specified style to the control; otherwise, false.
      /// @remarks Control style bit flags are used to categorize supported behavior. A control can enable a style by calling the set_style method and passing in the appropriate control_styles bit (or bits) and the bool value to set the bit(s) to. To determine the value assigned to a specified control_styles bit, use the get_style method and pass in the control_styles member to evaluate.
      /// @warning Setting the control style bits can substantially change the behavior of the control. Review the control_styles enumeration documentation to understand the effects of changing the control style bits before calling the set_style method.
      void set_style(control_styles flag, bool value);
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      /// @par Notes to Inheritors
      /// Inheriting controls should call the base class's wnd_proc(message&) method to process any messages that they do not handle.
      virtual void wnd_proc(message& m);
      /// @}
      
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Sets a value indicating which of the mouse buttons is in a pressed state.
      /// @param value A bitwise combination of the mouse_buttons enumeration values. The default is none.
      static void set_mouse_buttons(forms::mouse_buttons value);
      /// @}
      
      /// @cond
      bool get_state(control::state flag) const noexcept;
      void set_state(control::state flag, bool value);
      bool on_context_menu_item_click(xtd::forms::context_menu& menu, intptr menu_id) const;
      /// @endcond
      
    private:
      void do_layout_children_with_dock_style();
      void do_layout_with_auto_size_mode();
      void do_layout_with_anchor_styles();
      static bool is_trace_form_or_control(const ustring& name);
      void on_controls_item_added(size_t, control_ref item);
      void on_controls_item_removed(size_t, control_ref item);
      void on_parent_size_changed(object& sender, const event_args& e);
      void show_context_menu(xtd::forms::context_menu& menu, const xtd::drawing::point& pos) const;
      void reflect_message(intptr handle, message& message);
      intptr wnd_proc_(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr handle);
      void wm_app_idle(message& message);
      void wm_child_activate(message& message);
      void wm_command(message& message);
      void wm_command_control(message& message);
      void wm_ctlcolor(message& message);
      void wm_ctlcolor_control(message& message);
      void wm_create(message& message);
      void wm_destroy(message& message);
      void wm_key_char(message& message);
      void wm_kill_focus(message& message);
      void wm_menu_command(message& message);
      void wm_mouse_down(message& message);
      void wm_mouse_double_click(message& message);
      void wm_mouse_enter(message& message);
      void wm_mouse_leave(message& message);
      void wm_mouse_up(message& message);
      void wm_mouse_move(message& message);
      void wm_move(message& message);
      void wm_mouse_wheel(message& message);
      void wm_notify(message& message);
      void wm_notify_control(message& message);
      void wm_paint(message& message);
      void wm_erase_background(message& message);
      void wm_help(message& message);
      void wm_scroll(message& message);
      void wm_scroll_control(message& message);
      void wm_set_focus(message& message);
      void wm_set_text(message& message);
      void wm_show(message& message);
      void wm_size(message& message);
      void wm_sizing(message& message);
      void wm_style_sheet_changed(message& message);
      
      static bool check_for_illegal_cross_thread_calls_;
      static forms::keys modifier_keys_;
      static forms::mouse_buttons mouse_buttons_;
      static std::map<intptr, control*> handles_;
      static control_collection top_level_controls_;
      
      std::shared_ptr<data> data_;
    };
  }
}
