/// @file
/// @brief Contains main_form class.
#pragma once
#include <string>
#include "project_language.h"
#include "project_platform.h"
#include "project_type.h"

namespace xtdc_gui {
  /// @brief Represents the project_type_item class
  class project_type_item {
  public:
    /// @brief Initializes a new instance of the project_type_item class.
    project_type_item() = default;
    project_type_item(const project_type_item&) = default;
    bool operator==(const project_type_item& value) const {return name_ == value.name_ && description_ == value.description_ && project_language_ == value.project_language_ && project_platform_ == value.project_platform_ && project_type_ == value.project_type_;}
    bool operator!=(const project_type_item& value) const {return !operator==(value);}

    /// @brief Initializes a new instance of the project_type_item class.
    project_type_item(const std::string& name, const std::string& description, xtdc_gui::project_language project_language, xtdc_gui::project_platform project_platform, xtdc_gui::project_type project_type) : name_(name), description_(description), project_language_(project_language), project_platform_(project_platform), project_type_(project_type) {}

    const std::string& name() const {return name_;}
    const std::string& description() const {return description_;}
    xtdc_gui::project_language project_language() const {return project_language_;}
    xtdc_gui::project_platform project_platform() const {return project_platform_;}
    xtdc_gui::project_type project_type() const {return project_type_;}

  private:
    std::string name_;
    std::string description_;
    xtdc_gui::project_language project_language_ = xtdc_gui::project_language::all;
    xtdc_gui::project_platform project_platform_ = xtdc_gui::project_platform::all;
    xtdc_gui::project_type project_type_ = xtdc_gui::project_type::all;
  };
}
