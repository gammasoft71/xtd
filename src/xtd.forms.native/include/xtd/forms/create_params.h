#pragma once
#include <cstdint>
#include <iostream>
#include <string>
#include <xtd/drawing/point.h>
#include <xtd/drawing/size.h>
#include <xtd/strings.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class create_params {
    public:
      create_params() = default;
      
      /// @cond
      create_params(const create_params&) = default;
      create_params& operator=(create_params&) = default;
      /// @endcond
      
      const std::string& caption() const {return caption_;}
      
      create_params& caption(const std::string& caption) {
        caption_ = caption;
        return *this;
      }
      
      const std::string& class_name() const {return class_name_;}
      
      create_params& class_name(const std::string& class_name) {
        class_name_ = class_name;
        return *this;
      }

      size_t class_style() const {return class_style_;}
      
      create_params& class_style(size_t class_style) {
        class_style_ = class_style;
        return *this;
      }

      size_t ex_style() const {return ex_style_;}
      
      create_params& ex_style(size_t ex_style) {
        ex_style_ = ex_style;
        return *this;
      }

      int32_t height() const {return size_.height();}
      
      create_params& height(int32_t height) {
        size_.height(height);
        return *this;
      }

      drawing::point location() const {return location_;}
      
      create_params& location(const drawing::point location) {
        location_ = location;
        return *this;
      }

      intptr_t param() const {return param_;}
      
      create_params& param(intptr_t param) {
        param_ = param;
        return *this;
      }

      intptr_t parent() const {return parent_;}
      
      create_params& parent(intptr_t parent) {
        parent_ = parent;
        return *this;
      }

      size_t style() const {return style_;}
      
      create_params& style(size_t style) {
        style_ = style;
        return *this;
      }

      drawing::size size() const {return size_;}
      
      create_params& size(const drawing::size size) {
        size_ = size;
        return *this;
      }

      int32_t width() const {return size_.width();}
      
      create_params& width(int32_t width) {
        size_.width(width);
        return *this;
      }

      int32_t x() const {return location_.x();}
      
      create_params& x(int32_t x) {
        location_.x(x);
        return *this;
      }
      
      int32_t y() const {return location_.y();}
      
      create_params& y(int32_t y) {
        location_.y(y);
        return *this;
      }

      std::string to_string() const {return strings::format("create_params {{'{}' , '{}', 0x{:X}, 0x{:X}, {{{}, {}, {}, {}}}}}", class_name_, caption_, style_, ex_style_, location_.x(), location_.y(), size_.width(), size_.height());}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const create_params& create_params) noexcept {return os << create_params.to_string();}
      /// @endcond

    private:
      std::string caption_;
      std::string class_name_;
      size_t class_style_ = 0;
      size_t ex_style_ = 0;
      drawing::point location_ = {-1, -1};
      intptr_t param_ = 0;
      intptr_t parent_ = 0;
      size_t style_ = 0;
      drawing::size size_ = {-1, -1};
    };
  }
}
