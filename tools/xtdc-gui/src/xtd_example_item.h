/// @file
/// @brief Contains main_form class.
#pragma once
#include <string>
#include <filesystem>
#include <xtd/drawing/image.h>
#include <xtd/forms/application.h>
#include <xtd/environment.h>
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
    xtd_example_item(const std::string& name, const std::string& description, const std::filesystem::path& path) : name_(name), description_(description), path_(path) {}

    xtd::drawing::image picture() const {
      auto picture_file_name = get_base_path()/"share"/"xtd"/"resources"/"pictures/examples"/"xtd_forms"/(path_.stem().string() + "_" + get_os_potfix() + get_theme_postfix() +".png");
      if (std::filesystem::exists(picture_file_name))
        return xtd::drawing::bitmap(picture_file_name.string());
      return xtd::drawing::bitmap(noimage_picture);
    }
    const std::string& name() const {return name_;}
    const std::string& description() const {return description_;}
    const std::filesystem::path& path() const {return path_;}

  private:
#if defined(__XTD_FORMS_RESOURCES_PATH__)
    static std::filesystem::path get_base_path() noexcept {return {__XTD_FORMS_RESOURCES_PATH__};}
#else
    static std::filesystem::path get_base_path() noexcept {return {};}
#endif
    static std::string get_os_potfix() noexcept {return xtd::environment::os_version().is_windows_platform() ? "w" : xtd::environment::os_version().is_linux_platform() ? "g" : "m";}
    static std::string get_theme_postfix() noexcept {return xtd::forms::application::dark_mode_enabled() ? "d" : "";}
    std::string name_;
    std::string description_;
    std::filesystem::path path_;
  };
}
