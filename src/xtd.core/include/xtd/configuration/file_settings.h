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
    /// @code #include <xtd/configuration/file_settings> @endcode
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core configuration
    /// @remarks An [INI file](https://en.wikipedia.org/wiki/INI_file) is a configuration file that consists of a text-based content with a structure and syntax comprising key–value pairs for properties, and sections that organize the properties.
    class core_export_ file_settings : public object, public iequatable<file_settings> {
    public:
      /// @name Public Aliass
      
      /// @{
      /// @brief Represents a std::map with the key and the value strongly typed to be strings.
      using string_map = xtd::collections::specialized::string_map;

      /// @brief Represents a collection of strings.
      using string_vector = xtd::collections::specialized::string_vector;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize an xtd::configuration::file_settings without loading a file.
      /// @remarks The xtd::configuration::file_settings::save method has no effect.
      /// @remarks This is equivalent to using the xtd::configuration::file_settings constructor with an empty string as the file path.
      file_settings() noexcept = default;
      /// @brief Initialize an xtd::configuration::file_settings with file path to load and save.
      /// @param file_path the file path to load and save.
      /// @remarks If the xtd::configuration::file_settings::auto_save is true the xtd::configuration::file_settings::save is called on the xtd::configuration::file_settings destructor; otherwise not, The xtd::configuration::file_settings::save method must be called manually.
      /// @remarks xtd::configuration::file_settings::auto_save is false by default.
      /// @remarks If the file path is empty, this is equivalent to using the xtd::configuration::file_settings constructor with no parameters.
      explicit file_settings(const xtd::ustring& file_path);
      /// @brief Initialize an xtd::configuration::file_settings with a stream to load and save.
      /// @param stream the stream to load and save.
      /// @remarks If the xtd::configuration::file_settings::auto_save is true the xtd::configuration::file_settings::save is called on the xtd::configuration::file_settings destructor; otherwise not, The xtd::configuration::file_settings::save method must be called manually.
      /// @remarks xtd::configuration::file_settings::auto_save is false by default.
      /// @remarks If the stream is empty, this is equivalent to using the xtd::configuration::file_settings constructor with no parameters.
      explicit file_settings(std::iostream& stream);
      /// @}
      
      /// @cond
      file_settings(file_settings&&) noexcept = default;
      file_settings(const file_settings&) noexcept = default;
      file_settings& operator =(const file_settings&) noexcept = default;
      ~file_settings();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets whether save should be called on the xtd::configuration::file_settings destructor.
      /// @return true if xtd::configuration::file_settings::save is called on the xtd::configuration::file_settings destructor; otherwise, false.
      /// @remarks The default is false.
      bool auto_save() const noexcept;
      /// @brief Sets whether save should be called on the xtd::configuration::file_settings destructor.
      /// @param value true if xtd::configuration::file_settings::save is called on the xtd::configuration::file_settings destructor; otherwise, false.
      /// @remarks The default is false.
      void auto_save(bool value) noexcept;

      /// @brief Gets the file path of the current instance.
      /// @return The file path of the current instance.
      /// @remarks If no file the property can be return xtd::ustring::empty_string.
      /// @warning Don't manipulate the file yourself, otherwise the expected result may be undefined.
      const xtd::ustring& file_path() const noexcept;

      /// @brief Gets all key-value pairs from global section.
      /// @return The key-value pairs map.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::key_values (const xtd::ustring& section) with xtd::ustring::empty_string paramreter.
      string_map key_values() const noexcept;
      /// @brief Gets all key-value pairs from a specified section.
      /// @param section The section to get key-value pairs.
      /// @return The key-value pairs map from the specified section.
      /// @remarks Use xtd::ustring::empty_string paramreter to get key-value pairs of the global section.
      string_map key_values(const xtd::ustring& section) const noexcept;
      
      /// @brief Gets all keys from global section.
      /// @return The keys vector.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::keys (const xtd::ustring& section) with xtd::ustring::empty_string paramreter.
      string_vector keys() const noexcept;
      /// @brief Gets all keys from a specified section.
      /// @param section The section to get keys.
      /// @return The keys vector from the specified section.
      /// @remarks Use xtd::ustring::empty_string paramreter to get keys of the global section.
      string_vector keys(const xtd::ustring& section) const noexcept;

      /// @brief Gets all sections.
      /// @return The sections vector.
      string_vector sections() const noexcept;
      
      /// @brief Gets the stream of the current instance.
      /// @return The stream of the current instance.
      /// @warning Don't manipulate the stream yourself, otherwise the expected result may be undefined.
      std::optional<std::reference_wrapper<std::iostream>> stream() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Indicates whether the current object is equal to another object of the same type.
      /// @param obj An object to compare with this object.
      /// @return true if the current object is equal to the other parameter; otherwise, false.
      bool equals(const file_settings& obj) const noexcept override;
      
      /// @brief Sets the current settings with parsing the xtd::ustring in [INI format](https://en.wikipedia.org/wiki/INI_file).
      /// @param text A text to set the current setting.
      /// @par Notes to inheritors
      /// To create your own file_settings with another format, you just need to override the xtd::configuration::file_settings::from_string and xtd::configuration::file_settings::to_string methods.
      virtual void from_string(const xtd::ustring& text);

      /// @brief Loads settings from specified file.
      /// @param file_path The file path to load settings.
      void load(const xtd::ustring& file_path);
      /// @brief Loads settings from specified stream.
      /// @param stream The stream to load settings.
      void load(std::istream& stream);

      /// @brief Reads a value for specified key in the global section. If not found default value is used.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      /// @remarks Use xtd::ustring::empty_string for section paramreter to read keys of the global section.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::read (const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) with xtd::ustring::empty_string paramreter as section parameter.
      xtd::ustring read(const xtd::ustring& key, const xtd::ustring& default_value) noexcept;
      /// @brief Reads a value for specified key in the global section. If not found default value is used.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      /// @remarks Use xtd::ustring::empty_string for section paramreter to read keys of the global section.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::read (const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) with xtd::ustring::empty_string paramreter as section parameter.
      template<typename type_t>
      type_t read(const xtd::ustring& key, const type_t& default_value) {
        return xtd::parse<type_t>(read_string(xtd::ustring::empty_string, key, xtd::ustring::format("{}", default_value)));
      }
      /// @brief Reads a value for specified key in the specified section. If not found default value is used.
      /// @param section The section where the key is read.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      /// @remarks Use xtd::ustring::empty_string for section paramreter to read keys of the global section.
      xtd::ustring read(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) noexcept;
      /// @brief Reads a value for specified key in the specified section. If not found default value is used.
      /// @param section The section where the key is read.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      /// @remarks Use xtd::ustring::empty_string for section paramreter to read keys of the global section.
      template<typename type_t>
      type_t read(const xtd::ustring& section, const xtd::ustring& key, const type_t& default_value) {
        return xtd::parse<type_t>(read_string(section, key, xtd::ustring::format("{}", default_value)));
      }

      /// @brief Removes the specified key from the global section.
      /// @param key The key to remove from the global section.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::remove (const xtd::ustring& section) with xtd::ustring::empty_string paramreter.
      void remove(const xtd::ustring& key) noexcept;
      /// @brief Removes the specified key from the specified section.
      /// @param section The section where the key is removed.
      /// @param key The key to remove from the specified section.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks Use xtd::ustring::empty_string paramreter to remove key of the global section.
      void remove(const xtd::ustring& section, const xtd::ustring& key) noexcept;
      
      /// @brief Removes all keys from the global section.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::remove_all_keys (const xtd::ustring& section) with xtd::ustring::empty_string paramreter.
      void remove_all_keys() noexcept;
      /// @brief Removes all key from the specified section.
      /// @param section The section where all keys are removed.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks Use xtd::ustring::empty_string paramreter to remove all keys of the global section.
      void remove_all_keys(const xtd::ustring& section) noexcept;
      
      /// @brief Reset current settings.
      /// @remarks The settings are cleared and the settings file is removed.
      /// @remarks To write permanently use the xtd::configuration::settings::save method.
      void reset();
      
      /// @brief Save current settings.
      /// @remarks The settings are saved in the settings file.
      void save();
      
      /// @brief Save current settings in the specified file path.
      /// @param file_path The file to save the current settings.
      /// @remarks The settings are saved in the specified settings file.
      void save_as(const xtd::ustring& file_path);
      /// @brief Save current settings in the specified stream.
      /// @param stream The stream to save the current settings.
      /// @remarks The settings are saved in the specified settings stream.
      void save_as(std::ostream& stream);

      /// @brief Returns a xtd::ustring that represents the current setting in [INI format](https://en.wikipedia.org/wiki/INI_file).
      /// @return A string that represents the current setting.
      /// @par Notes to inheritors
      /// To create your own file_settings with another format, you just need to override the xtd::configuration::file_settings::from_string and xtd::configuration::file_settings::to_string methods.
      xtd::ustring to_string() const noexcept override;
      
      /// @brief Writes a specified value for specified key in the global section.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      void write(const xtd::ustring& key, const xtd::ustring& value) noexcept;
      /// @brief Writes a specified value for specified key in the global section.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      template<typename type_t>
      void write(const xtd::ustring& key, type_t&& value) {
        write_string(xtd::ustring::empty_string, key, xtd::ustring::format("{}", value));
      }
      /// @brief Writes a specified value for specified key in the specified section.
      /// @param section The section where the key is write.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      void write(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& value) noexcept;
      /// @brief Writes a specified value for specified key in the specified section.
      /// @param section The section where the key is write.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      template<typename type_t>
      void write(const xtd::ustring& section, const xtd::ustring& key, type_t&& value) {
        write_string(section, key, xtd::ustring::format("{}", value));
      }
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Gets key-value pairs of the specified section.
      /// @param secion The section to get the key-value pairs
      /// @return The key-value pairs of the section.
      /// @par Examples
      /// Use this operator to read value from section like xtd::configuration::file_settings::read method.
      /// @code
      /// auto fs = file_settings {"my_file.ini"};
      /// auto v1 = fs["section1"]["key1"]; 
      /// // Is equivalent to call :
      /// // auto v1 = fs.read("section1", "key1", ustring::empty_string);
      /// @endcode
      const string_map& operator [](const xtd::ustring& section) const noexcept;
      /// @brief Gets key-value pairs of the specified section.
      /// @param secion The section to get the key-value pairs
      /// @return The key-value pairs of the section.
      /// @par Examples
      /// Use this operator to write value to section like xtd::configuration::file_settings::write method.
      /// @code
      /// auto fs = file_settings {"my_file.ini"};
      /// fs["section1"]["key1"] = "value1";
      /// // Is equivalent to call :
      /// // fs.write("section1", "key1", "value1");
      /// @endcode
      string_map& operator [](const xtd::ustring& section) noexcept;
      /// @}
      
    private:
      xtd::ustring read_string(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) noexcept;
      void write_string(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& value) noexcept;

      bool auto_save_ = false;
      xtd::ustring file_path_;
      std::map<xtd::ustring, string_map> section_key_values_;
      std::iostream* stream_ = nullptr;
    };
  }
}
