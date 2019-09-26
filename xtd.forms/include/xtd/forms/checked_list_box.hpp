#pragma once
#include "list_box.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class checked_list_box : public list_box {
    public:
      class item : public list_box::item {
      public:
        item() = default;
        item(const std::string& value) : list_box::item(value) {}
        item(const std::string& value, bool checked) : list_box::item(value), checked_(checked) {}
        template<typename object_t>
        item(const object_t& tag, bool checked) : list_box::item(tag), checked_(checked) {}
        item(const std::string& value, const std::any& tag) : list_box::item(value, tag) {}
        item(const std::string& value, bool checked, const std::any& tag) : list_box::item(value, tag), checked_(checked) {}
        /// @cond
        item(const char* value) : list_box::item(value) {}
        item(const item& value) = default;
        bool operator==(const item& value) const {return this->list_box::item::operator==(value);}
        bool operator!=(const item& value) const {return this->list_box::item::operator!=(value);}
        bool operator<(const item& value) const {return this->list_box::item::operator<(value);}
        bool operator<=(const item& value) const {return this->list_box::item::operator<=(value);}
        bool operator>(const item& value) const {return this->list_box::item::operator>(value);}
        bool operator>=(const item& value) const {return this->list_box::item::operator>=(value);}
        /// @endcond

        virtual bool checked() const {return this->checked_;}
        
        friend std::ostream& operator<<(std::ostream& os, const item& value) {return os << value.to_string();}

      private:
        bool checked_ = false;
      };
      
      using item_collection = layout::arranged_element_collection<item>;
      
      checked_list_box();
    
      item_collection& items() {return this->items_;}

      const item_collection& items() const {return this->items_;}
      
      const list_box& items(const item_collection& items) {
        this->items_ = items;
        return *this;
      }
      
      using list_box::selected_index;
      list_control& selected_index(size_t selected_index) override;
      
      std::vector<size_t> selected_indices() const override;
      
      const item& selected_item() const {return this->selected_item_;}
      
      list_box& selected_item(const item& selected_item);
      
      std::vector<item> selected_items() const;
      
      using list_box::text;
      control& text(const std::string& text) override {
        this->selected_item_ = {text};
        return *this;
      }
      
      bool get_item_checked(size_t index) const;

      const std::string& get_item_text(size_t index) const;

      void set_item_checked(size_t index, bool checked);

      void set_item_text(size_t index, const std::string& text);

    protected:
      bool allow_selection() override {return this->selection_mode_ != forms::selection_mode::none;}

      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;

      void on_selected_value_changed(const event_args& e) override;

      void wnd_proc(message& message) override;
      
      void wm_reflect_command(message& message) override;
      
      void wm_mouse_double_click(message& message) override;

      void wm_mouse_down(message& message) override;
      
      void wm_mouse_up(message& message) override;
      
      item_collection items_;
      item selected_item_;
    };
  }
}
