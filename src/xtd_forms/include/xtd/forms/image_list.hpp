#pragma once
#include <any>
#include <xtd/drawing/image.hpp>
#include "component.hpp"
#include "layout/arranged_element_collection.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class image_list final : public component {
    public:
      using image_collection = layout::arranged_element_collection<drawing::image>;

      image_list();
      ~image_list();

      intptr_t handle() const {return handle_;}
      
      bool handle_created() const {return handle_ != 0;}
      
      image_collection& images() {return images_;}
      const image_collection& images() const {return images_;}
      
      const drawing::size image_size() const {return image_size_;}
      void image_size(const drawing::size& value);
      
      std::any tag() const {return tag_;}
      void tag(std::any& tag) {tag_ = tag;}

    private:
      intptr_t handle_ = 0;
      image_collection images_;
      drawing::size image_size_ {16, 16};
      std::any tag_;
    };
  }
}
