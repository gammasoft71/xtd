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
    
  private:
    xtd::ustring current_path_ = xtd::environment::current_directory();
  };
}
