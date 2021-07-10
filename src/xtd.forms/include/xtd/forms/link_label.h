/// @file
/// @brief Contains xtd::forms::link_label class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <tuple>
#include <xtd/drawing/system_colors.h>
#include "cursors.h"
#include "label.h"
#include "link.h"
#include "link_label_clicked_event_handler.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows label control that can display hyperlinks.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks
    class link_label : public label {
    public:
      /// @brief Represents a link within a link_label control.
      /// @remarks The xtd::forms::link_label::link class defines the properties of a link within a xtd::forms::link_label control. You can use these properties to provide data to the xtd::forms::link_label::link_clicked event of the xtd::forms::link_label control to perform tasks when the link is clicked in the control. The xtd::forms::link_label::link_data property enables you to define information that the xtd::forms::link_label::link_clicked event can use to display a URL within your web browser or to open a file.
      /// @remarks In addition to information related to the link, the properties of the xtd::forms::link_label::link class also help define the text of thextd::forms::link_label::lLink and its display state. The xtd::forms::link_label::start and xtd::forms::link_label::length properties define the location and length of text from the text of the xtd::forms::link_label control to display as a link. The xtd::forms::link_label::enabled property allows you to display the link as a disabled link, and the xtd::forms::link_label::visited property can alert the user that they already visited the specified link in the current instance of the xtd::forms::link_label.
      /// @remarks You can display multiple links in a single xtd::forms::link_label control. Each xtd::forms::link_label::link is added into the xtd::forms::link_label::link_collection associated with the xtd::forms::link_label control. To obtain the collection of links defined in a xtd::forms::link_label control, use the xtd::forms::link_label::links property.
      using link = xtd::forms::link;
      
      /// @brief Represents a collection of controls.
      class link_collection : public xtd::forms::layout::arranged_element_collection<xtd::forms::link_label::link> {
      public:
        /// @brief Represents the base type of the collection.
        using base = xtd::forms::layout::arranged_element_collection<xtd::forms::link_label::link>;
        
        /// @brief Creates a new object xtd::forms::control::control_collection with specified alllocator (optional).
        /// @param allocator The allocator associate to the collection (optional).
        /// @remarks If allocator not specified, the std::allocator<value_type> is used.
        explicit link_collection(const allocator_type& allocator = allocator_type());
        /// @cond
        link_collection(const base& collection);
        link_collection(const link_collection& collection);
        link_collection& operator=(const link_collection& collection);
        link_collection(link_collection&&) = default;
        /// @endcond
        
        using base::operator[];
        /// @brief Gets the first xtd::forms::control::control_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator[] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator[] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        const_reference operator[](const std::string& name) const;
        /// @brief Gets the first xtd::forms::control::control_collection in the list with the specified name.
        /// @param name The name of the xtd::forms::control to get from the list.
        /// @return The first xtd::forms::control in the list with the given Name. This item returns optional with no value if no xtd::forms::control with the given name can be found.
        /// @remarks The operator[] property is case-sensitive when searching for names. That is, if two controls exist with the names "Lname" and "lname", operator[] property will find only the xtd::forms::control with the xtd::forms::control::name() that you specify, not both.
        reference operator[](const std::string& name);

      private:
       inline static value_type empty_;
      };

      link_label();

      const link_collection& links() const;
      link_collection& links();
      
      event<link_label, link_label_clicked_event_handler<control&>> link_clicked;

    protected:
      void on_cursor_changed(const xtd::event_args& e) override;
      void on_mouse_click(const xtd::forms::mouse_event_args& e) override;
      void on_mouse_down(const xtd::forms::mouse_event_args& e) override;
      void on_mouse_up(const xtd::forms::mouse_event_args& e) override;
      void on_mouse_move(const xtd::forms::mouse_event_args& e) override;
      void on_paint(xtd::forms::paint_event_args& e) override;
      void on_text_align_changed(const xtd::event_args& e) override;
      void on_text_changed(const xtd::event_args& e) override;
      
      link_label::link& point_in_link(const xtd::drawing::point& point);

    private:
      xtd::drawing::point get_text_location(size_t line) const;
      std::vector<std::tuple<xtd::drawing::rectangle, bool>> generate_text_rects() const;
      xtd::drawing::font link_font() const;
      bool mouse_hover_ = false;
      xtd::drawing::color active_link_color_;
      xtd::drawing::color disable_link_color_;
      xtd::drawing::color link_color_;
      link_collection links_;
      xtd::forms::cursor original_cursor_;
      xtd::forms::cursor override_cursor_;
      xtd::drawing::color visited_link_color_;
      inline static link link_empty_;
    };
  }
}

