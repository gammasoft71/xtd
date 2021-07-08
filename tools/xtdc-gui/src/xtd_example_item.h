/// @file
/// @brief Contains main_form class.
#pragma once
#include <string>
#include <filesystem>
#include <xtd/drawing/image.h>
#include <xtd/forms/application.h>
#include <xtd/environment.h>
//#include "../resources/noimage.xpm"

namespace xtdc_gui {
  /// @brief Represents the project_type_item class
  class xtd_example_item {
  public:
    xtd_example_item() = default;
    xtd_example_item(const std::string& name, const std::string& description, const std::filesystem::path& path,  const xtd::drawing::image& picture) : name_(name), description_(description), path_(path), picture_(picture) {}
    
    const std::string& name() const noexcept {return name_;};
    const std::string& description() const noexcept {return description_;};
    const std::filesystem::path& path() const noexcept {return path_;};
    const xtd::drawing::image& picture() const noexcept {return picture_;};
    
    static std::vector<xtd_example_item> get_cmake_examples() {
      return xtd_example_item::get_examples(xtd_share_path_/"examples"/"xtd.cmake.examples");
    }
    
    static std::vector<xtd_example_item> get_core_examples() {
      return xtd_example_item::get_examples(xtd_share_path_/"examples"/"xtd.core.examples");
    }
    
    static std::vector<xtd_example_item> get_drawing_examples() {
      return xtd_example_item::get_examples(xtd_share_path_/"examples"/"xtd.drawing.examples");
    }
    
    static std::vector<xtd_example_item> get_forms_examples() {
      return xtd_example_item::get_examples(xtd_share_path_/"examples"/"xtd.forms.examples");
    }
    
    static std::vector<xtd_example_item> get_tunit_examples() {
      return xtd_example_item::get_examples(xtd_share_path_/"examples"/"xtd.tunit.examples");
    }
    
  private:
    static std::vector<xtd_example_item> get_examples(const std::filesystem::path& examples_path) {
      std::vector<xtd_example_item> examples;
      for (auto group_item : std::filesystem::directory_iterator(examples_path)) {
        if (group_item.is_directory()) {
          for (auto item : std::filesystem::directory_iterator(group_item)) {
            if (item.is_directory()) {
              examples.push_back({xtd::strings::format("{} - {}", group_item.path().filename().string(), item.path().filename().string()), get_description(item.path() / "README.md"), item.path().string(), get_picture(item.path().stem().string())});
            }
          }
        }
      }
      std::sort(examples.begin(), examples.end(), [](auto a, auto b)->bool {return a.name() < b.name();});
      return examples;
    }
    
    static std::string get_description(const std::filesystem::path& readme_md) {
      if (!std::filesystem::exists(readme_md)) return "";
      auto content = xtd::io::file::read_all_lines(readme_md);
      if (content.size() < 2) return "";
      return content[2];
    }
    
    static std::string get_image_path(const std::string& name) {
      auto base_path = std::filesystem::path(xtd_share_path_/"resources"/"pictures"/"examples");
      return "";
    }
    
    static xtd::drawing::image get_picture(const std::string& name) {
      auto picture_file_name = xtd_share_path_/"resources"/"pictures/examples"/(name + "_" + get_os_potfix() + get_theme_postfix() +".png");
      if (std::filesystem::exists(picture_file_name)) return xtd::drawing::bitmap(picture_file_name.string());
      picture_file_name = xtd_share_path_/"resources"/"pictures/examples"/(name + "_" + get_os_potfix() +".png");
      if (std::filesystem::exists(picture_file_name)) return xtd::drawing::bitmap(picture_file_name.string());
      //return xtd::drawing::bitmap(noimage_picture);
      return xtd::drawing::bitmap(400, 250);
    }
    
    static std::string get_os_potfix() noexcept {return xtd::environment::os_version().is_windows_platform() ? "w" : xtd::environment::os_version().is_linux_platform() ? "g" : "m";}
    static std::string get_theme_postfix() noexcept {return xtd::forms::application::dark_mode_enabled() ? "d" : "";}
    
    inline static const std::filesystem::path xtd_share_path_ = std::filesystem::path(__XTD_RESOURCES_PATH__)/"share"/"xtd";
    
    std::string name_;
    std::string description_;
    std::filesystem::path path_;
    xtd::drawing::image picture_;
  };
}
