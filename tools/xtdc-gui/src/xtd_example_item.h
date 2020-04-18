/// @file
/// @brief Contains main_form class.
#pragma once
#include <string>
#include <xtd/drawing/image.h>
#include "../resources/noimage.xpm"

namespace xtdc_gui {
  /// @brief Represents the project_type_item class
  class xtd_example_item {
  public:
    /// @brief Initializes a new instance of the project_type_item class.
    xtd_example_item() = default;
    xtd_example_item(const xtd_example_item&) = default;
    bool operator==(const xtd_example_item& value) const {return name_ == value.name_ && description_ == value.description_ && path_ == value.path_;}
    bool operator!=(const xtd_example_item& value) const {return !operator==(value);}

    /// @brief Initializes a new instance of the project_type_item class.
    xtd_example_item(const std::string& name, const std::string& description, const std::string& path) : name_(name), description_(description), path_(path) {}

    xtd::drawing::image picture() const {return xtd::drawing::bitmap(noimage_picture);}
    const std::string& name() const {return name_;}
    const std::string& description() const {return description_;}
    const std::string& path() const {return path_;}

  private:
    std::string name_;
    std::string description_;
    std::string path_;
  };
}
