#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class list_control : public control {
    public:      
      class item {
      public:
        item() = default;
        item(const std::string& value) : value_(value) {}
        item(const std::string& value, const std::any& tag) : value_(value), tag_(tag) {}
        /// @cond
        item(const char* value) : value_(value) {}
        item(const item& value) = default;
        virtual ~item() = default;
        bool operator==(const item& value) const {return this->value_ == value.value_;}
        bool operator!=(const item& value) const {return !this->operator==(value);}
        bool operator<(const item& value) const {return this->value_ < value.value_;}
        bool operator<=(const item& value) const {return this->value_ <= value.value_;}
        bool operator>(const item& value) const {return this->value_ > value.value_;}
        bool operator>=(const item& value) const {return this->value_ >= value.value_;}
        /// @endcond
        
        virtual std::string value() const {return this->value_;}
        virtual void value(const std::string& value) {this->value_ = value;}
        
        virtual std::any tag() const {return this->tag_;}
        virtual void tag(const std::any& tag) {this->tag_ = tag;}
        
      private:
        std::string value_;
        std::any tag_;
      };
      
      using item_collection = layout::arranged_element_collection<item>;
      
    protected:
      list_control() = default;
  
      /// @brief Gets a value indicating whether the list enables selection of list items.
      /// @return true if the list enables list item selection; otherwise, false. The default is true.
      virtual bool allow_selection() {return true;}
    };
  }
}
