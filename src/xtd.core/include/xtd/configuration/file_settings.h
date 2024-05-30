/// @file
/// @brief Contains xtd::configuration::file_settings class
/// .
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../collections/specialized/string_map.h"
#include "../collections/specialized/string_vector.h"
#include "../io/directory.h"
#include "../io/file.h"
#include "../io/path.h"
#include "../iequatable.h"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains the types that provide the programming model for handling configuration data.
  namespace configuration {
    /// @brief Represents an object for storing and retrieving configuration information using text files in [INI format](https://en.wikipedia.org/wiki/INI_file).
    /// @par Header
    /// @code #include <xtd/settings> @endcode
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core system
    /// @remarks An [INI file](https://en.wikipedia.org/wiki/INI_file) is a configuration file that consists of a text-based content with a structure and syntax comprising key–value pairs for properties, and sections that organize the properties.
    class core_export_ file_settings : public object, public iequatable<file_settings> {
    public:
      /// @brief Implements a std::map with the key and the value strongly typed to be strings.
      using string_map = xtd::collections::specialized::string_map;

      /// @brief Represents a collection of strings.
      using string_vector = xtd::collections::specialized::string_vector;
      
      /// @brief Initialize an xtd::configuration::file_settings without loading a file.
      /// @remarks The xtd::configuration::file_settings::save method has no effect.
      /// @remarks This is equivalent to using the xtd::configuration::file_settings constructor with an empty string as the file path.
      file_settings() noexcept = default;
      /// @brief Initialize an xtd::configuration::file_settings with file path to load.
      /// @param file_path the file path to load.
      /// @remarks When the xtd::configuration::file_settings file is destroyed, the backup is not automatically called up. The backup must be made manually.
      /// @remarks If the file path is empty, this is equivalent to using the xtd::configuration::file_settings constructor with no parameters.
      explicit file_settings(const xtd::ustring& file_path);
      
      /// @cond
      file_settings(file_settings&&) noexcept = default;
      file_settings(const file_settings&) noexcept = default;
      file_settings& operator =(const file_settings&) noexcept = default;
      /// @endcond
      
      string_map key_values() const noexcept;
      
      string_map key_values(const xtd::ustring& section) const noexcept;
      
      string_vector keys() const noexcept;
      
      string_vector keys(const xtd::ustring& section) const noexcept;
      
      bool equals(const file_settings&) const noexcept override;
      
      void load(const xtd::ustring& file_path);

      string_vector sections() const noexcept;
      
      xtd::ustring read(const xtd::ustring& key, const xtd::ustring& default_value) noexcept;
      
      xtd::ustring read(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) noexcept;
      
      void remove(const xtd::ustring& key) noexcept;
      
      void remove(const xtd::ustring& section, const xtd::ustring& key) noexcept;
      
      void remove_all_keys() noexcept;
      
      void remove_all_keys(const xtd::ustring& section) noexcept;
      
      void reset();
      
      void save();
      
      void save_as(const xtd::ustring& file_path);

      virtual void from_string(const xtd::ustring& text);
      
      xtd::ustring to_string() const noexcept override;
      
      void write(const xtd::ustring& key, const xtd::ustring& value) noexcept;
      
      void write(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& value) noexcept;
      
      const string_map& operator [](const xtd::ustring& section) const noexcept;
      
      string_map& operator [](const xtd::ustring& section) noexcept;
      
    private:
      std::map<xtd::ustring, string_map> section_key_values_;
      xtd::ustring file_path_;
    };
  }
}
