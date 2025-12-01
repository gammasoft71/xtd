/// @file
/// @brief Contains main_form class.
#pragma once
#include <string>
#include <xtd/drawing/image>
#include <xtd/forms/application>
#include <xtd/forms/application>
#include <xtd/io/directory>
#include <xtd/io/file>
#include <xtd/io/path>
#include <xtd/icomparable>
#include <xtd/iequatable>
//#include "../resources/noimage.xpm"

namespace xtdc_gui {
  /// @brief Represents the project_type_item class
  class xtd_example_item : public xtd::object, public xtd::icomparable<xtd_example_item>, public xtd::iequatable<xtd_example_item> {
  public:
    xtd_example_item() = default;
    xtd_example_item(const xtd::string& name, const xtd::string& description, const xtd::string& path, const xtd::drawing::image& picture, const xtd::string& output) : name_(name), description_(description), path_(path), picture_(picture), output_(output) {}
    
    const xtd::string& name() const noexcept {return name_;};
    const xtd::string& description() const noexcept {return description_;}
    const xtd::string& path() const noexcept {return path_;}
    const xtd::drawing::image& picture() const noexcept {return picture_;}
    const xtd::string& output() const noexcept {return output_;}
    
    int32 compare_to(const xtd_example_item& value) const noexcept override {return name_.compare_to(value.name_);}
    
    bool equals(const object& obj) const noexcept override {return is<xtd_example_item>(obj) && equals(static_cast<const xtd_example_item&>(obj));}
    
    bool equals(const xtd_example_item& value) const noexcept override {return name_.equals(value.name_);}
    
    static const xtd::array<xtd_example_item>& get_cmake_examples() {
      static auto examples = xtd::array<xtd_example_item> {};
      if (examples.empty()) examples = xtd_example_item::get_examples(xtd::io::path::combine(xtd_share_path_, "examples", "xtd.cmake.examples"));
      return examples;
    }
    
    static const xtd::array<xtd_example_item>& get_core_examples() {
      static auto examples = xtd::array<xtd_example_item> {};
      if (examples.empty()) examples = xtd_example_item::get_examples(xtd::io::path::combine(xtd_share_path_, "examples", "xtd.core.examples"));
      return examples;
    }
    
    static const xtd::array<xtd_example_item>& get_drawing_examples() {
      static auto examples = xtd::array<xtd_example_item> {};
      if (examples.empty()) examples = xtd_example_item::get_examples(xtd::io::path::combine(xtd_share_path_, "examples", "xtd.drawing.examples"));
      return examples;
    }
    
    static const xtd::array<xtd_example_item>& get_forms_examples() {
      static auto examples = xtd::array<xtd_example_item> {};
      if (examples.empty()) examples = xtd_example_item::get_examples(xtd::io::path::combine(xtd_share_path_, "examples", "xtd.forms.examples"));
      return examples;
    }
    
    xtd::size get_hash_code() const noexcept override {return name_.get_hash_code();}
    
    static const xtd::array<xtd_example_item>& get_tunit_examples() {
      static auto examples = xtd::array<xtd_example_item> {};
      if (examples.empty()) examples = xtd_example_item::get_examples(xtd::io::path::combine(xtd_share_path_, "examples", "xtd.tunit.examples"));
      return examples;
    }
    
  private:
    static xtd::array<xtd_example_item> get_examples(const xtd::string& examples_path) {
      auto examples = xtd::collections::generic::list<xtd_example_item> {};
      for (auto group_item : xtd::io::directory::enumerate_directories(examples_path)) {
        for (auto item : xtd::io::directory::enumerate_directories(group_item)) {
          if (xtd::io::path::get_file_name(item) != "src") {
            examples.add({xtd::string::format("{} - {}", xtd::io::path::get_file_name(group_item), xtd::io::path::get_file_name(item)), get_description(xtd::io::path::combine(item, "README.md")), item, get_picture(xtd::io::path::get_file_name(item)), get_output(xtd::io::path::combine(item, "README.md")) });
          }
        }
      }
      std::sort(examples.items().begin(), examples.items().end(), [](auto a, auto b)->bool {return a.name() < b.name();});
      return examples.to_array();
    }
    
    static xtd::string get_description(const xtd::string& readme_md) {
      if (!xtd::io::file::exists(readme_md)) return "";
      auto content = xtd::io::file::read_all_lines(readme_md);
      if (content.length() < 2) return "";
      return content[2];
    }
    
    static xtd::string get_image_path(const xtd::string& name) {
      auto base_path = xtd::io::path::combine(xtd_share_path_, "resources", "pictures", "examples");
      return "";
    }
    
    static xtd::drawing::image get_picture(const xtd::string& name) {
      auto picture_file_name = xtd::io::path::combine({xtd_share_path_, "resources", "pictures", "examples", (name + "_" + get_os_postfix() + get_theme_postfix() + ".png")});
      if (xtd::io::file::exists(picture_file_name)) return xtd::drawing::bitmap(picture_file_name);
      picture_file_name = xtd::io::path::combine({xtd_share_path_, "resources", "pictures", "examples", (name + "_" + get_os_postfix() + ".png")});
      if (xtd::io::file::exists(picture_file_name)) return xtd::drawing::bitmap(picture_file_name);
      picture_file_name = xtd::io::path::combine({xtd_share_path_, "resources", "pictures", "examples", (name + ".png")});
      if (xtd::io::file::exists(picture_file_name)) return xtd::drawing::bitmap(picture_file_name);
      return xtd::drawing::image::empty;
    }
    
    static xtd::string get_output(const xtd::string& readme_md) {
      if (!xtd::io::file::exists(readme_md)) return "";
      const auto contents = xtd::io::file::read_all_lines(readme_md);
      bool found_output = false;
      xtd::string output = "";
      for (const xtd::string& line : contents) {
        if (xtd::string::is_empty(line)) continue;
        if (!found_output && line.to_lower().starts_with("# output")) {
          found_output = true;
          continue;
        } else if (found_output) {
          if (line.starts_with("#") || line.starts_with("```") || line.starts_with("![")) continue; // skip other # ``` sections and ![Screenshots]
          output += line + '\n';
        }
      }
      return output;
    }
    
    static xtd::string get_os_postfix() noexcept {return xtd::environment::os_version().is_windows_platform() ? "w" : xtd::environment::os_version().is_macos_platform() ? "m" : "g";}
    static xtd::string get_theme_postfix() noexcept {return xtd::forms::application::dark_mode() ? "d" : "";}
    
    inline static const xtd::string xtd_share_path_ = xtd::io::path::combine(xtd::environment::get_folder_path(xtd::environment::special_folder::xtd_install), "share", "xtd");
    
    xtd::string name_;
    xtd::string description_;
    xtd::string path_;
    xtd::drawing::image picture_;
    xtd::string output_;
  };
}
