/// @file
/// @brief Contains main_form class.
#pragma once
#include <string>
#include <xtd/iequatable>
#include <xtd/drawing/image>
#include "project_language.hpp"
#include "project_platform.hpp"
#include "project_sdk.hpp"
#include "project_type.hpp"

namespace xtdc_gui {
  /// @brief Represents the project_type_item class
  class project_type_item : public xtd::iequatable<project_type_item> {
  public:
    /// @brief Initializes a new instance of the project_type_item class.
    project_type_item() = default;
    project_type_item(const project_type_item&) = default;
    project_type_item& operator =(const project_type_item&) = default;
    
    /// @brief Initializes a new instance of the project_type_item class.
    project_type_item(const xtd::drawing::image& icon, const xtd::string& name, const xtd::string& description, xtdc_gui::project_language project_language, xtdc_gui::project_sdk project_sdk, xtdc_gui::project_platform project_platform, xtdc_gui::project_type project_type) : icon_(icon), name_(name), description_(description), project_language_(project_language), project_platform_(project_platform), project_sdk_(project_sdk), project_type_(project_type) {}
    
    const xtd::drawing::image& icon() const {return icon_;}
    const xtd::string& name() const {return name_;}
    const xtd::string& description() const {return description_;}
    xtdc_gui::project_language project_language() const {return project_language_;}
    xtdc_gui::project_platform project_platform() const {return project_platform_;}
    xtdc_gui::project_sdk project_sdk() const {return project_sdk_;}
    xtdc_gui::project_type project_type() const {return project_type_;}
    
    bool equals(const project_type_item& value) const noexcept override {return icon_ == value.icon_ && name_ == value.name_ && description_ == value.description_ && project_language_ == value.project_language_ && project_platform_ == value.project_platform_ && project_sdk_ == value.project_sdk_ && project_type_ == value.project_type_;}
    
  private:
    xtd::drawing::image icon_ = xtd::drawing::image::empty;
    xtd::string name_;
    xtd::string description_;
    xtdc_gui::project_language project_language_ = xtdc_gui::project_language::all;
    xtdc_gui::project_platform project_platform_ = xtdc_gui::project_platform::all;
    xtdc_gui::project_sdk project_sdk_ = xtdc_gui::project_sdk::none;
    xtdc_gui::project_type project_type_ = xtdc_gui::project_type::all;
  };
}
