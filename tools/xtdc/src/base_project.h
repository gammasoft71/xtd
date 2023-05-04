#pragma once
#include <map>
#include <xtd/bit_converter.h>
#include <xtd/environment.h>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include <xtd/io/directory.h>
#include <xtd/io/file.h>
#include <xtd/io/path.h>

namespace xtdc_command {
  class base_project : public xtd::object {
    class change_current_directory {
    public:
      change_current_directory(const xtd::ustring& current_directory) {
        if (!xtd::io::directory::exists(current_directory)) xtd::io::directory::create_directory(current_directory);
        xtd::environment::current_directory(current_directory);
      }
      ~change_current_directory() {xtd::environment::current_directory(previous_current_directoy_);}
      
    private:
      xtd::ustring previous_current_directoy_ = xtd::environment::current_directory();
    };
    
  public:
    base_project() = delete;
    explicit base_project(const xtd::ustring& path) : current_path_(path) {}
    
    virtual void create(const xtd::ustring& name, bool create_solution) const = 0;
    
    const xtd::ustring& current_path() const noexcept {return current_path_;}
    
  protected:
    static std::tuple<std::vector<xtd::ustring>, std::vector<xtd::ustring>> get_sources(const xtd::ustring& current_path, const xtd::ustring& path) {
      std::vector<xtd::ustring> headers;
      std::vector<xtd::ustring> sources;
      for (auto file : xtd::io::directory::get_files(path, "*.h"))
        headers.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), ""));
      for (auto file : xtd::io::directory::get_files(path, "*.cpp"))
        sources.push_back(file.replace(current_path + xtd::io::path::directory_separator_char(), ""));
      
      for (auto sub_path : xtd::io::directory::get_directories(path)) {
        auto [sub_headers, sub_sources] = get_sources(current_path, sub_path);
        for (auto file : sub_headers)
          headers.push_back(file);
        for (auto file : sub_sources)
          sources.push_back(file);
      }
      
      return std::make_tuple(headers, sources);
    }
    
  private:
    xtd::ustring current_path_ = xtd::environment::current_directory();
  };
}
