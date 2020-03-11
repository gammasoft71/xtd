#pragma once
#include <optional>
#include "control.h"
#include "border_style.h"
#include "picture_box_size_mode.h"
#include <xtd/drawing/image.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class picture_box : public control {
    public:
      picture_box();

      virtual forms::border_style border_style() const {return this->border_style_;}
      virtual picture_box& border_style(forms::border_style border_style);

      drawing::size default_size() const override {return{100, 50};}
      
      const std::optional<drawing::image> image() const {return this->image_;}
      picture_box& image(const drawing::image& image);
      picture_box& image(std::nullptr_t);
      
      picture_box_size_mode size_mode() const {return this->size_mode_;}
      picture_box& size_mode(picture_box_size_mode size_mode);

    protected:
      forms::create_params create_params() const override;

      /// @brief Overrides the on_handle_created(const event_args&) method.
      /// @param e An event_args that contains the event data.
      void on_handle_created(const event_args& e) override;

      drawing::size measure_control() const override;

      forms::border_style border_style_ = forms::border_style::none;
      
      std::optional<drawing::image> image_;
      picture_box_size_mode size_mode_ = picture_box_size_mode::normal;
    };
  }
}
