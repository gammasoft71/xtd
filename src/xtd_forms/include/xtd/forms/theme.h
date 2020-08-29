#pragma once
#include "theme_style.h"
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class theme {
    public:
      theme() = default;
      theme(const std::string& name) : name_(name) {}
      theme(const std::string& name, xtd::forms::theme_style theme_style) : name_(name), theme_style_(theme_style) {}
      /// @cond
      theme(const theme&) = default;
      theme& operator=(const theme&) = default;
      bool operator==(const theme& value) {return name_ == value.name_ && theme_style_ == value.theme_style_ && is_default_ == value.is_default();}
      bool operator!=(const theme& value) {return !operator==(value);}
      virtual ~theme() = default;
      /// @endcond
      
      virtual const std::string& name() const {return name_;}
      theme& name(const std::string& name) {
        name_ = name;
        return *this;
      }
      
      xtd::forms::theme_style theme_style() const {return theme_style_;}
      theme& theme_style(xtd::forms::theme_style theme_style) {
        theme_style_ = theme_style;
        return *this;
      }
      
      bool is_default() const {return is_default_;}
      
      static const theme empty;
      
    protected:
      theme(const std::string& name, xtd::forms::theme_style theme_style, bool is_default) : name_(name), theme_style_(theme_style), is_default_(is_default) {}
      
      theme& is_default(bool is_default) {
        is_default_ = is_default;
        return *this;
      }
      
    private:
      std::string name_;
      xtd::forms::theme_style theme_style_;
      bool is_default_ = false;
    };
  }
}
