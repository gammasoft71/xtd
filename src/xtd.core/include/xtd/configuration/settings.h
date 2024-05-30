/// @file
/// @brief Contains xtd::configuration::settings class
/// .
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../object"
#include "../ustring"
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains the types that provide the programming model for handling configuration data.
  namespace configuration {
    /// @brief Represent settings associate to the application.
    /// @par Header
    /// @code #include <xtd/settings> @endcode
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core system components
    /// @remarks On Windows settings are stored in "application_path/product_name.ini" file.
    /// @remarks On macos settings are stored in "~/Library/Preferences/company_name/product_name Preferences" file.
    /// @remarks On linux settings are stored in "~/.consig/company_name/product_name.conf" file.
    /// @par Examples
    /// The following code example demonstrates the use of settings class.
    /// @include settings_example.cpp
    class core_export_ settings : public object {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of settings class.
      settings();
      /// @}
      
      /// @cond
      ~settings();
      /// @endcond
      
      /// @name Public Methods
      
      /// @{
      /// @brief Reads a value for specified key. If not found default value is used.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      xtd::ustring read(const xtd::ustring& key, const xtd::ustring& default_value);
      /// @brief Reads a value for specified key. If not found default value is used.
      /// @tparam type_t The type of value to read.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A type_t that represent the value associate to the key.
      template<typename type_t>
      type_t read(const xtd::ustring& key, const type_t& default_value) {
        return xtd::parse<type_t>(read_string(key, xtd::ustring::format("{}", default_value)));
      }
      
      /// @brief Reset application settings.
      void reset();
      
      /// @brief Save application settings.
      void save();
      
      /// @brief Writes a specified value for specified key.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      void write(const xtd::ustring& key, const xtd::ustring& value);
      /// @brief Writes a specified value for specified key.
      /// @tparam type_t The type of value to write.
      /// @param key The key used to write a value.
      /// @param value A type_t to write.
      template<typename type_t>
      void write(const xtd::ustring& key, type_t&& value) {
        write_string(key, xtd::ustring::format("{}", value));
      }
      /// @}
      
    private:
      xtd::ustring read_string(const xtd::ustring& key, const xtd::ustring& default_value);
      void write_string(const xtd::ustring& key, const xtd::ustring& value);
      
      std::shared_ptr<data> data_;
    };
  }
}
