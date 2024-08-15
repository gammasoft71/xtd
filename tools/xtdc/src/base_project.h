#pragma once
#include <map>
#include <xtd/bit_converter>
#include <xtd/environment>
#include <xtd/object>
#include <xtd/string>
#include <xtd/io/directory>
#include <xtd/io/file>
#include <xtd/io/path>

namespace xtdc_command {
  class base_project : public xtd::object {
    class change_current_directory {
    public:
      change_current_directory(const xtd::string& current_directory) {
        if (!xtd::io::directory::exists(current_directory)) xtd::io::directory::create_directory(current_directory);
        xtd::environment::current_directory(current_directory);
      }
      ~change_current_directory() {xtd::environment::current_directory(previous_current_directoy_);}
      
    private:
      xtd::string previous_current_directoy_ = xtd::environment::current_directory();
    };
    
  public:
    base_project() = delete;
    explicit base_project(const xtd::string& path) : current_path_(path) {}
    
    virtual void create(const xtd::string& name, bool create_solution) const = 0;
    
    const xtd::string& current_path() const noexcept {return current_path_;}
    
  protected:
    static std::tuple<std::vector<xtd::string>, std::vector<xtd::string>> get_c_sources(const xtd::string& current_path, const xtd::string& path) {
      std::vector<xtd::string> headers;
      std::vector<xtd::string> sources;
      for (auto file : xtd::io::directory::get_files(path, "*.h"))
        headers.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
      for (auto file : xtd::io::directory::get_files(path, "*.c"))
        sources.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
        
      for (auto sub_path : xtd::io::directory::get_directories(path)) {
        auto [sub_headers, sub_sources] = get_c_sources(current_path, sub_path);
        for (auto file : sub_headers)
          headers.push_back(file);
        for (auto file : sub_sources)
          sources.push_back(file);
      }
      
      return std::make_tuple(headers, sources);
    }
    
    static std::tuple<std::vector<xtd::string>, std::vector<xtd::string>> get_cpp_sources(const xtd::string& current_path, const xtd::string& path) {
      std::vector<xtd::string> headers;
      std::vector<xtd::string> sources;
      for (auto file : xtd::io::directory::get_files(path, "*.h"))
        headers.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
      for (auto file : xtd::io::directory::get_files(path, "*.cpp"))
        sources.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
        
      for (auto sub_path : xtd::io::directory::get_directories(path)) {
        auto [sub_headers, sub_sources] = get_cpp_sources(current_path, sub_path);
        for (auto file : sub_headers)
          headers.push_back(file);
        for (auto file : sub_sources)
          sources.push_back(file);
      }
      
      return std::make_tuple(headers, sources);
    }
    
    static std::tuple<std::vector<xtd::string>, std::vector<xtd::string>, std::vector<xtd::string>> get_csharp_sources(const xtd::string& current_path, const xtd::string& path) {
      std::vector<xtd::string> sources;
      std::vector<xtd::string> configs;
      std::vector<xtd::string> xamls;
      for (auto file : xtd::io::directory::get_files(path, "*.cs"))
        sources.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
      for (auto file : xtd::io::directory::get_files(path, "*.config"))
        configs.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
      for (auto file : xtd::io::directory::get_files(path, "*.xaml"))
        xamls.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
        
      for (auto sub_path : xtd::io::directory::get_directories(path)) {
        auto [sub_sources, sub_configs, sub_xamls] = get_csharp_sources(current_path, sub_path);
        for (auto file : sub_sources)
          sources.push_back(file);
        for (auto file : sub_configs)
          configs.push_back(file);
        for (auto file : sub_xamls)
          xamls.push_back(file);
      }
      
      return std::make_tuple(sources, configs, xamls);
    }
    
    static std::tuple<std::vector<xtd::string>, std::vector<xtd::string>> get_objectivec_sources(const xtd::string& current_path, const xtd::string& path) {
      std::vector<xtd::string> headers;
      std::vector<xtd::string> sources;
      for (auto file : xtd::io::directory::get_files(path, "*.h"))
        headers.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
      for (auto file : xtd::io::directory::get_files(path, "*.m"))
        sources.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), xtd::string::empty_string));
        
      for (auto sub_path : xtd::io::directory::get_directories(path)) {
        auto [sub_headers, sub_sources] = get_objectivec_sources(current_path, sub_path);
        for (auto file : sub_headers)
          headers.push_back(file);
        for (auto file : sub_sources)
          sources.push_back(file);
      }
      
      return std::make_tuple(headers, sources);
    }
    
  private:
    xtd::string current_path_ = xtd::environment::current_directory();
  };
}
