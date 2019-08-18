#pragma once
#include <iostream>
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class create_params {
    public:
      create_params() = default;
      create_params(const create_params&) = default;
      create_params& operator=(create_params&) = default;
      
      const std::string& caption() const {return this->caption_;}
      
      create_params& caption(const std::string& caption) {
        this->caption_ = caption;
        return *this;
      }
      
      const std::string& class_name() const {return this->class_name_;}
      
      create_params& class_name(const std::string& class_name) {
        this->class_name_ = class_name;
        return *this;
      }

      size_t class_style() const {return this->class_style_;}
      
      create_params& class_style(size_t class_style) {
        this->class_style_ = class_style;
        return *this;
      }

      size_t ex_style() const {return this->ex_style_;}
      
      create_params& ex_style(size_t ex_style) {
        this->ex_style_ = ex_style;
        return *this;
      }

      size_t height() const {return this->height_;}
      
      create_params& height(size_t height) {
        this->height_ = height;
        return *this;
      }

      intptr_t param() const {return this->param_;}
      
      create_params& param(intptr_t param) {
        this->param_ = param;
        return *this;
      }

      intptr_t parent() const {return this->parent_;}
      
      create_params& parent(intptr_t parent) {
        this->parent_ = parent;
        return *this;
      }

      size_t style() const {return this->style_;}
      
      create_params& style(size_t style) {
        this->style_ = style;
        return *this;
      }

      size_t width() const {return this->width_;}
      
      create_params& width(size_t width) {
        this->width_ = width;
        return *this;
      }

      size_t x() const {return this->x_;}
      
      create_params& x(size_t x) {
        this->x_ = x;
        return *this;
      }
      
      size_t y() const {return this->y_;}
      
      create_params& y(size_t y) {
        this->y_ = y;
        return *this;
      }

      std::string to_string() const {return strings::format("create_params {{'{}' , '{}', 0x{:X}, 0x{:X}, {{{}, {}, {}, {}}}}}", this->class_name_, this->caption_, this->style_, this->ex_style_, this->x_, this->y_, this->width_, this->height_);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const create_params& create_params) noexcept {return os << create_params.to_string();}
      /// @endcond

    private:
      std::string caption_;
      std::string class_name_;
      size_t class_style_ = 0;
      size_t ex_style_ = 0;
      size_t height_ = -1;
      intptr_t param_ = 0;
      intptr_t parent_ = 0;
      size_t style_ = 0;
      size_t width_ = -1;
      size_t x_ = -1;
      size_t y_ = -1;
    };
  }
}
