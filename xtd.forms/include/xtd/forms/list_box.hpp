#pragma once
#include "layout/arranged_element_collection.hpp"
#include "control.hpp"
#include "selection_mode.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class list_box : public control {
    public:
      using string_collection = layout::arranged_element_collection<std::string>;
      
      list_box();

      drawing::color default_back_color() const override;
      
      drawing::color default_fore_color() const override;
      
      drawing::size default_size() const override {return{120, 96};}
      
      string_collection& items() {return this->items_;}

      const string_collection& items() const {return this->items_;}
      
      const list_box& items(const string_collection& items) {
        this->items_ = items;
        return *this;
      }
      
      virtual size_t selected_index() const {return this->selected_index_;}
      
      virtual list_box& selected_index(size_t selected_index);
      
      virtual const std::string& selected_item() const {return this->selected_item_;}
      
      virtual list_box& selected_item(const std::string& selected_item);
      
      virtual forms::selection_mode selection_mode() const {return this->selection_mode_;}
      virtual list_box& selection_mode(forms::selection_mode selection_mode);

      virtual bool sorted() const {return this->sorted_;}
      virtual list_box& sorted(bool sorted);
      
      using control::text;
      control& text(const std::string& text) override {return this->selected_item(text);}

      void create_handle() override;
      
      event<list_box, event_handler<control>> selected_index_changed;
      
    protected:
      void on_selected_index_changed(const event_args& e) {this->selected_index_changed(*this, e);}

      void on_selected_value_changed(const event_args& e) {this->control::text(this->selected_item_);}

      void wnd_proc(message& message) override;
      
    private:
      void wm_reflect_command(message& message);
      
      string_collection items_;
      size_t selected_index_ = -1;
      std::vector<size_t> selected_indices;
      std::string selected_item_;
      std::vector<std::string> selected_items_;
      forms::selection_mode selection_mode_ = forms::selection_mode::one;
      bool sorted_ = false;
    };
  }
}
