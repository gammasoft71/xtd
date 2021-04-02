/// @file
/// @brief Contains xtd::forms::tab_control container.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "image_list.h"
#include "tab_alignment.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class tab_page;
    /// @endcond
  
    /// @brief Manages a related set of tab pages.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Examples
    /// The following code example demonstrate the use of tab_control container.
    /// @include tab_control.cpp
    /// @par Windows
    /// @image html tab_control_w.png
    /// <br>
    /// @image html tab_control_wd.png
    /// @par macOS
    /// @image html tab_control_m.png
    /// <br>
    /// @image html tab_control_md.png
    /// @par Gnome
    /// @image html tab_control_g.png
    /// <br>
    /// @image html tab_control_gd.png
    class forms_export_ tab_control : public control {
    public:
      tab_control();

      virtual control_collection& pages() {return controls();}
      virtual const control_collection& pages() const {return controls();}

      virtual tab_alignment alignment() const {return alignment_;}
      virtual tab_control& alignment(tab_alignment alignment);
      
      drawing::size default_size() const override {return {200, 100};}
      
      virtual const forms::image_list& image_list() const {return image_list_;}
      virtual forms::image_list& image_list() {return image_list_;}
      virtual tab_control& image_list(const forms::image_list& value);
      
      virtual size_t selected_index() const {return selected_index_;}
      virtual tab_control& selected_index(size_t selected_index_);

      event<tab_control, event_handler<control&>> selected_index_changed;

      /// @brief This is a special value equal to the maximum value representable by the type size_t.
      static const size_t npos = std::numeric_limits<size_t>::max();
      
    protected:
      forms::create_params create_params() const override;

      drawing::size measure_control() const override;

      void on_control_added(const control_event_args& e) override;
      
      void on_control_removed(const control_event_args& e) override;
      
      virtual void on_selected_index_changed(const event_args& e) {selected_index_changed(*this, e);}
      
      void recreate_handle() override;

      void wnd_proc(message& message) override;
      
      virtual void wm_reflect_command(message& message);
      
      /// @cond
      friend class tab_page;
      tab_alignment alignment_ = tab_alignment::top;
      forms::image_list image_list_;
      size_t selected_index_ = npos;
      /// @endcond
    };
  }
}
