#pragma once
#include "theme_style.h"
#include <xtd/environment.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class theme_base {
    public:
      /// @cond
      theme_base(const theme_base&) = default;
      theme_base& operator=(const theme_base&) = default;
      bool operator==(const theme_base& value) const {return name_ == value.name_ && theme_style_ == value.theme_style_ && is_default_ == value.is_default();}
      bool operator!=(const theme_base& value) const {return !operator==(value);}
      virtual ~theme_base() = default;
      /// @endcond
      
      using theme_name_collection = std::vector<std::string>;

      virtual const std::string& name() const {return name_;}
      theme_base& name(const std::string& name) {
        name_ = name;
        return *this;
      }
      
      xtd::forms::theme_style theme_style() const {return theme_style_;}
      theme_base& theme_style(xtd::forms::theme_style theme_style) {
        theme_style_ = theme_style;
        return *this;
      }
      
      bool is_default() const {return is_default_;}
      
      static std::string default_theme_name() {return xtd::environment::os_version().desktop_environment() == "" ? "symbolic" :  xtd::environment::os_version().desktop_environment();}
      
      static const theme_name_collection& theme_names() {return theme_names_;}
      
      static const theme_base empty;
      
    protected:
      theme_base() = default;
      explicit theme_base(const std::string& name) : name_(name) {}
      theme_base(const std::string& name, xtd::forms::theme_style theme_style) : name_(name), theme_style_(theme_style) {}
      theme_base(const std::string& name, xtd::forms::theme_style theme_style, bool is_default) : name_(name), theme_style_(theme_style), is_default_(is_default) {}
      
      theme_base& is_default(bool is_default) {
        is_default_ = is_default;
        return *this;
      }
      

    private:
      std::string name_;
      xtd::forms::theme_style theme_style_ = xtd::forms::theme_style::undefined;
      bool is_default_ = false;
      static theme_name_collection theme_names_;
    };
  }
}
