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
      /// @brief Initializes a new instance of the tab_control class.
      tab_control();

      /// @brief Gets the area of the control (for example, along the top) where the tabs are aligned.
      /// @return One of the xtd::forms::tab_alignment values. The default is top.
      virtual tab_alignment alignment() const {return alignment_;}
      /// @brief Sets the area of the control (for example, along the top) where the tabs are aligned.
      /// @param alignment One of the xtd::forms::tab_alignment values. The default is top.
      /// @return Current tab_control instance.
      virtual tab_control& alignment(tab_alignment alignment);
      
      drawing::size default_size() const override {return {200, 100};}
      
      /// @brief Gets the images to display on the control's tabs.
      /// @return An xtd::forms::image_list that specifies the images to display on the tabs.
      /// @remarks To display an image on a tab, set the image_index property of that xtd::forms::tab_page. The image_index acts as the index into the image_list.
      virtual const forms::image_list& image_list() const {return image_list_;}
      /*
      /// @brief Gets the images to display on the control's tabs.
      /// @return An xtd::forms::image_list that specifies the images to display on the tabs.
      /// @remarks To display an image on a tab, set the image_index property of that xtd::forms::tab_page. The image_index acts as the index into the image_list.
      virtual forms::image_list& image_list() {return image_list_;}
       */
      /// @brief Sets the images to display on the control's tabs.
      /// @param value An xtd::forms::image_list that specifies the images to display on the tabs.
      /// @return Current tab_control instance.
      /// @remarks To display an image on a tab, set the image_index property of that xtd::forms::tab_page. The image_index acts as the index into the image_list.
      virtual tab_control& image_list(const forms::image_list& value);
      
      /// @brief Gets the index of the currently selected tab page.
      /// @return The zero-based index of the currently selected tab page. The default is -1, which is also the value if no tab page is selected.
      virtual size_t selected_index() const {return selected_index_;}
      /// @brief Sets the index of the currently selected tab page.
      /// @param selected_index The zero-based index of the currently selected tab page. The default is -1, which is also the value if no tab page is selected.
      /// @return Current tab_control instance.
      virtual tab_control& selected_index(size_t selected_index);
      
      /// @brief Gets the collection of tab pages in this tab control.
      /// @return A control_collection that contains the control objects in this tab_control.
      /// @remarks The order of tab pages in this collection reflects the order the tabs appear in the control.
      virtual control_collection& tab_pages() {return controls();}
      /// @brief Gets the collection of tab pages in this tab control.
      /// @return A control_collection that contains the control objects in this tab_control.
      /// @remarks The order of tab pages in this collection reflects the order the tabs appear in the control.
      virtual const control_collection& tab_pages() const {return controls();}

      /// @brief Occurs when the selected_index property has changed.
      /// @ingroup events
      event<tab_control, event_handler> selected_index_changed;

      /// @brief This is a special value equal to the maximum value representable by the type size_t.
      static const size_t npos = std::numeric_limits<size_t>::max();
      
    protected:
      forms::create_params create_params() const override;

      drawing::size measure_control() const override;

      void on_control_added(const control_event_args& e) override;
      
      void on_control_removed(const control_event_args& e) override;

      void on_handle_created(const event_args& e) override;

      /// @brief Raises the tab_control::selected_index_changed event.
      /// @param An xtd::event_args that contains the event data.
      virtual void on_selected_index_changed(const event_args& e) {selected_index_changed(*this, e);}
      
      void recreate_handle() override;

      void wnd_proc(message& message) override;
      
      /// @cond
      virtual void wm_reflect_command(message& message);
      
      friend class tab_page;
      size_t get_child_index(intptr_t page) {
        for (size_t index = 0;index < controls().size(); ++index)
          if (controls()[index].get().handle() == page) return index;
        return npos;
      }
      tab_alignment alignment_ = tab_alignment::top;
      forms::image_list image_list_;
      size_t selected_index_ = npos;
      /// @endcond
    };
  }
}
