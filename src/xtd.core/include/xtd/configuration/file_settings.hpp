/// @file
/// @brief Contains xtd::configuration::file_settings class
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.hpp"
#include "../collections/generic/sorted_dictionary.hpp"
#include "../collections/specialized/string_collection.hpp"
#include "../io/directory.hpp"
#include "../io/file.hpp"
#include "../io/path.hpp"
#include "../iequatable.hpp"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains the types that provide the programming model for handling configuration data.
  namespace configuration {
    /// @brief Represents an object for storing and retrieving configuration information using text files in [INI format](https://en.wikipedia.org/wiki/INI_file).
    /// @par Header
    /// ```cpp
    /// #include <xtd/configuration/file_settings>
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core configuration
    /// @remarks An [INI file](https://en.wikipedia.org/wiki/INI_file) is a configuration file that consists of a text-based content with a structure and syntax comprising key–value pairs for properties, and sections that organize the properties.
    /// @par Examples
    /// The following code example demonstrates the use of xtd::configuration::file_settings class.
    /// @include file_settings.cpp
    class core_export_ file_settings : public object, public iequatable<file_settings> {
    public:
      /// @name Public Aliass
      
      /// @{
      /// @brief Represents a xtd::collections::generic::sorted_dictionary with the key and the value strongly typed to be strings.
      using string_dictionary = std::map<xtd::string, xtd::string>;

      /// @brief Represents a collection of strings.
      using string_collection = xtd::collections::specialized::string_collection;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize an xtd::configuration::file_settings without loading a file.
      /// @remarks The xtd::configuration::file_settings::save method has no effect.
      /// @remarks This is equivalent to using the xtd::configuration::file_settings constructor with an empty string as the file path.
      file_settings() noexcept = default;
      /// @brief Initialize an xtd::configuration::file_settings with file path to load and save.
      /// @param file_path the file path to load and save.
      /// @remarks If the xtd::configuration::file_settings::auto_save is `true` the xtd::configuration::file_settings::save is called on the xtd::configuration::file_settings destructor; otherwise not, The xtd::configuration::file_settings::save method must be called manually.
      /// @remarks xtd::configuration::file_settings::auto_save is `false` by default.
      /// @remarks If the file path is empty, this is equivalent to using the xtd::configuration::file_settings constructor with no parameters.
      explicit file_settings(const xtd::string& file_path);
      /// @brief Initialize an xtd::configuration::file_settings with a stream to load and save.
      /// @param stream the stream to load and save.
      /// @remarks If the xtd::configuration::file_settings::auto_save is `true` the xtd::configuration::file_settings::save is called on the xtd::configuration::file_settings destructor; otherwise not, The xtd::configuration::file_settings::save method must be called manually.
      /// @remarks xtd::configuration::file_settings::auto_save is `false` by default.
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
      /// @return `true` if xtd::configuration::file_settings::save is called on the xtd::configuration::file_settings destructor; otherwise, `false`.
      /// @remarks The default is `false`.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::auto_save property, xtd::configuration::file_settings::write methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.auto_save(true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      bool auto_save() const noexcept;
      /// @brief Sets whether save should be called on the xtd::configuration::file_settings destructor.
      /// @param value `true` if xtd::configuration::file_settings::save is called on the xtd::configuration::file_settings destructor; otherwise, `false`.
      /// @remarks The default is `false`.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::auto_save property, xtd::configuration::file_settings::write methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.auto_save(true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
     void auto_save(bool value) noexcept;

      /// @brief Gets bottom file comment text.
      /// @return Bottom file comment text.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::bottom_file_comment property, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save_as methods.
      /// ```cpp
      /// auto file = file_settings {};
      /// file.bottom_file_comment("Modifications must be made with care, as they may result in incorrect behavior.");
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save_as("my_app.ini")
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      ///
      /// # Modifications must be made with care, as they may result in incorrect behavior.
      /// ```
      xtd::string bottom_file_comment() const noexcept;
      /// @brief Sets bottom file comment text.
      /// @param value Bottom file comment text.
      /// @return This current instance.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::bottom_file_comment property, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save_as methods.
      /// ```cpp
      /// auto file = file_settings {};
      /// file.bottom_file_comment("Modifications must be made with care, as they may result in incorrect behavior.");
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save_as("my_app.ini");
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      ///
      /// # Modifications must be made with care, as they may result in incorrect behavior.
      /// ```
      file_settings& bottom_file_comment(const xtd::string& value) noexcept;

      /// @brief Gets the file path of the current instance.
      /// @return The file path of the current instance.
      /// @remarks If no file the property can be return xtd::string::empty_string.
      /// @warning Don't manipulate the file yourself, otherwise the expected result may be undefined.
      const xtd::string& file_path() const noexcept;

      /// @brief Gets all key-value pairs from global section.
      /// @return The key-value pairs map.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::key_values (const xtd::string& section) with xtd::string::empty_string paramreter.
      string_dictionary key_values() const noexcept;
      /// @brief Gets all key-value pairs from a specified section.
      /// @param section The section to get key-value pairs.
      /// @return The key-value pairs map from the specified section.
      /// @remarks Use xtd::string::empty_string paramreter to get key-value pairs of the global section.
      string_dictionary key_values(const xtd::string& section) const noexcept;
      
      /// @brief Gets all keys from global section.
      /// @return The keys colection.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::keys (const xtd::string& section) with xtd::string::empty_string paramreter.
      string_collection keys() const noexcept;
      /// @brief Gets all keys from a specified section.
      /// @param section The section to get keys.
      /// @return The keys collection from the specified section.
      /// @remarks Use xtd::string::empty_string paramreter to get keys of the global section.
      string_collection keys(const xtd::string& section) const noexcept;

      /// @brief Gets all sections.
      /// @return The sections colection.
      string_collection sections() const noexcept;
      
      /// @brief Gets the stream of the current instance.
      /// @return The stream of the current instance.
      /// @warning Don't manipulate the stream yourself, otherwise the expected result may be undefined.
      std::optional<std::reference_wrapper<std::iostream>> stream() const noexcept;

      /// @brief Gets top file comment text.
      /// @return Top file comment textr.
      /// @remarks Generally used to read descriptions of the xtd::configuration::file_settings : authors, copyright, version, etc.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::top_file_comment property, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save_as methods.
      /// ```cpp
      /// auto file = file_settings {};
      /// file.top_file_comment("Contains settings for my_app application.\nCopyright, (c) 2025 MyCompany. All rights reserved.");
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save_as("my_app.ini");
      /// ```
      /// my_app.ini:
      /// ```ini
      /// # Contains settings for my_app application.
      /// # Copyright, (c) 2025 MyCompany. All rights reserved.
      ///
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      xtd::string top_file_comment() const noexcept;
      /// @brief Sets top file comment text.
      /// @param value Top file comment textr.
      /// @return This current instance.
      /// @remarks Generally used to write descriptions of the xtd::configuration::file_settings : authors, copyright, version, etc.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::top_file_comment property, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save_as methods.
      /// ```cpp
      /// auto file = file_settings {};
      /// file.top_file_comment("Contains settings for my_app application.\nCopyright, (c) 2025 MyCompany. All rights reserved.");
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save_as("my_app.ini");
      /// ```
      /// my_app.ini:
      /// ```ini
      /// # Contains settings for my_app application.
      /// # Copyright, (c) 2025 MyCompany. All rights reserved.
      ///
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      file_settings& top_file_comment(const xtd::string& value) noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Indicates whether the current object is equal to another object of the same type.
      /// @param obj An object to compare with this object.
      /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
      bool equals(const xtd::object& obj) const noexcept override;
      /// @brief Indicates whether the current object is equal to another object of the same type.
      /// @param other An object to compare with this object.
      /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
      bool equals(const file_settings& other) const noexcept override;
      
      /// @brief Sets the current settings with parsing the xtd::string in [INI format](https://en.wikipedia.org/wiki/INI_file).
      /// @param text A text to set the current setting.
      /// @par Notes to inheritors
      /// To create your own file_settings with another format, you just need to override the xtd::configuration::file_settings::from_string and xtd::configuration::file_settings::to_string methods.
      virtual void from_string(const xtd::string& text);

      /// @brief Loads settings from specified file.
      /// @param file_path The file path to load settings.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::load, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save_as methods.
      /// ```cpp
      /// auto file = file_settings {};
      /// file.load("my_app.ini");
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save_as("my_app.ini");
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void load(const xtd::string& file_path);
      /// @brief Loads settings from specified stream.
      /// @param stream The stream to load settings.
      void load(std::istream& stream);

      /// @brief Reads a value for specified key in the global section. If not found default value is used.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      /// @remarks Use xtd::string::empty_string for section paramreter to read keys of the global section.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::read (const xtd::string& section, const xtd::string& key, const xtd::string& default_value) with xtd::string::empty_string paramreter as section parameter.
      xtd::string read(const xtd::string& key, const xtd::string& default_value) noexcept;
      /// @brief Reads a value for specified key in the global section. If not found default value is used.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      /// @remarks Use xtd::string::empty_string for section paramreter to read keys of the global section.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::read (const xtd::string& section, const xtd::string& key, const xtd::string& default_value) with xtd::string::empty_string paramreter as section parameter.
      template<class type_t>
      type_t read(const xtd::string& key, const type_t& default_value) {
        return xtd::parse<type_t>(read_string(xtd::string::empty_string, key, xtd::string::format("{}", default_value)));
      }
      /// @brief Reads a value for specified key in the specified section. If not found default value is used.
      /// @param section The section where the key is read.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      /// @remarks Use xtd::string::empty_string for section paramreter to read keys of the global section.
      xtd::string read(const xtd::string& section, const xtd::string& key, const xtd::string& default_value) noexcept;
      /// @brief Reads a value for specified key in the specified section. If not found default value is used.
      /// @param section The section where the key is read.
      /// @param key The key used to read a value.
      /// @param default_value A string used if value not found.
      /// @return A string that represent the value associate to the key.
      /// @remarks Use xtd::string::empty_string for section paramreter to read keys of the global section.
      template<class type_t>
      type_t read(const xtd::string& section, const xtd::string& key, const type_t& default_value) {
        return xtd::parse<type_t>(read_string(section, key, xtd::string::format("{}", default_value)));
      }

      /// @brief Removes the specified key from the global section.
      /// @param key The key to remove from the global section.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::remove (const xtd::string& section) with xtd::string::empty_string paramreter.
      /// @brief Removes the specified key from the specified section.
      /// @param section The section where the key is removed.
      /// @param key The key to remove from the specified section.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks Use xtd::string::empty_string paramreter to remove key of the global section.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write, xtd::configuration::file_settings::remove and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write(quit_application_on_main_form_closed", true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.remove("quit_application_on_main_form_closed");
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void remove(const xtd::string& key) noexcept;
      /// @brief Removes the specified key from the specified section.
      /// @param section The section where the key is removed.
      /// @param key The key to remove from the specified section.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks Use xtd::string::empty_string paramreter to remove key of the global section.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write, xtd::configuration::file_settings::remove and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("main", "quit_application_on_main_form_closed", true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.remove("main", "quit_application_on_main_form_closed");
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void remove(const xtd::string& section, const xtd::string& key) noexcept;
      
      /// @brief Removes all keys from the global section.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks This method is equivalent to call xtd::configuration::file_settings::remove_all_keys (const xtd::string& section) with xtd::string::empty_string paramreter.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write, xtd::configuration::file_settings::remove_all_keys and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("main", "quit_application_on_main_form_closed", true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.remove_all_keys();
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void remove_all_keys() noexcept;
      /// @brief Removes all key from the specified section.
      /// @param section The section where all keys are removed.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @remarks Use xtd::string::empty_string paramreter to remove all keys of the global section.
      /// @remarks Use xtd::string::empty_string paramreter to remove key of the global section.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write, xtd::configuration::file_settings::remove_all_keys and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("main", "quit_application_on_main_form_closed", true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.remove_all_keys("pictures \"Menu\"");
      /// file.save()
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [main]
      /// quit_application_on_main_form_closed = true
      /// ```
      void remove_all_keys(const xtd::string& section) noexcept;
      
      /// @brief Reset current settings.
      /// @remarks The settings are cleared and the settings file is removed.
      /// @remarks To write permanently use the xtd::configuration::settings::save method.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("main", "quit_application_on_main_form_closed", true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [main]
      /// quit_application_on_main_form_closed = true
      ///
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void reset();
      
      /// @brief Save current settings.
      /// @remarks The settings are saved in the settings file.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("main", "quit_application_on_main_form_closed", true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [main]
      /// quit_application_on_main_form_closed = true
      ///
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void save();
      
      /// @brief Save current settings in the specified file path.
      /// @param file_path The file to save the current settings.
      /// @remarks The settings are saved in the specified settings file.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::write and xtd::configuration::file_settings::save_as methods.
      /// ```cpp
      /// auto file = file_settings {};
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save_as("my_app.ini")
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void save_as(const xtd::string& file_path);
      /// @brief Save current settings in the specified stream.
      /// @param stream The stream to save the current settings.
      /// @remarks The settings are saved in the specified settings stream.
      void save_as(std::ostream& stream);

      /// @brief Returns a xtd::string that represents the current setting in [INI format](https://en.wikipedia.org/wiki/INI_file).
      /// @return A string that represents the current setting.
      /// @par Notes to inheritors
      /// To create your own file_settings with another format, you just need to override the xtd::configuration::file_settings::from_string and xtd::configuration::file_settings::to_string methods.
      xtd::string to_string() const noexcept override;
      
      /// @brief Writes a specified value for specified key in the global section.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("quit_application_on_main_form_closed", "true");
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// quit_application_on_main_form_closed = true
      ///
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void write(const xtd::string& key, const xtd::string& value) noexcept;
      /// @brief Writes a specified value for specified key in the global section.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("quit_application_on_main_form_closed", true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// quit_application_on_main_form_closed = true
      ///
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      template<class type_t>
      void write(const xtd::string& key, type_t&& value) {
        write_string(xtd::string::empty_string, key, xtd::string::format("{}", value));
      }
      /// @brief Writes a specified value for specified key in the specified section.
      /// @param section The section where the key is write.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("quit_application_on_main_form_closed", "true");
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png");
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// quit_application_on_main_form_closed = true
      ///
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      void write(const xtd::string& section, const xtd::string& key, const xtd::string& value) noexcept;
      /// @brief Writes a specified value for specified key in the specified section.
      /// @param section The section where the key is write.
      /// @param key The key used to write a value.
      /// @param value A string to write.
      /// @remarks To write permanently use the xtd::configuration::file_settings::save method.
      /// @par Examples
      /// The following example shows how to create xtd::configuration::file_settings and use xtd::configuration::file_settings::reset, xtd::configuration::file_settings::write and xtd::configuration::file_settings::save methods.
      /// ```cpp
      /// auto file = file_settings {"my_app.ini"};
      /// file.reset();
      /// file.write("main", "quit_application_on_main_form_closed", true);
      /// file.write("pictures \"Menu\"", "file_open", "resources/symbolic_open.png")
      /// file.write("pictures \"Menu\"", "file_save", "resources/symbolic_save.png");
      /// file.save();
      /// ```
      /// my_app.ini:
      /// ```ini
      /// [main]
      /// quit_application_on_main_form_closed = true
      ///
      /// [pictures "Menu"]
      /// file_open = resources/symbolic_open.png
      /// file_save = resources/symbolic_save.png
      /// ```
      template<class type_t>
      void write(const xtd::string& section, const xtd::string& key, type_t&& value) {
        write_string(section, key, xtd::string::format("{}", value));
      }
      /// @}
      
      /// @name Public Operators
      
      /// @{
      /// @brief Gets key-value pairs of the specified section.
      /// @param secion The section to get the key-value pairs
      /// @return The key-value pairs of the section.
      /// @par Examples
      /// Use this operator to read value from section like xtd::configuration::file_settings::read method.
      /// ```cpp
      /// auto fs = file_settings {"my_file.ini"};
      /// auto v1 = fs["section1"]["key1"]; 
      /// // Is equivalent to call :
      /// // auto v1 = fs.read("section1", "key1", string::empty_string);
      /// ```
      const string_dictionary& operator [](const xtd::string& section) const noexcept;
      /// @brief Gets key-value pairs of the specified section.
      /// @param secion The section to get the key-value pairs
      /// @return The key-value pairs of the section.
      /// @par Examples
      /// Use this operator to write value to section like xtd::configuration::file_settings::write method.
      /// ```cpp
      /// auto fs = file_settings {"my_file.ini"};
      /// fs["section1"]["key1"] = "value1";
      /// // Is equivalent to call :
      /// // fs.write("section1", "key1", "value1");
      /// ```
      string_dictionary& operator [](const xtd::string& section) noexcept;
      /// @}
      
    protected:
      virtual xtd::string convert_comment_to_text(const xtd::string& text) const noexcept;
      virtual xtd::string convert_text_to_comment(const xtd::string& text) const noexcept;

    private:
      xtd::string read_string(const xtd::string& section, const xtd::string& key, const xtd::string& default_value) noexcept;
      void write_string(const xtd::string& section, const xtd::string& key, const xtd::string& value) noexcept;

      bool auto_save_ = false;
      std::map<xtd::string, string_dictionary> after_key_value_comment_;
      std::map<xtd::string, xtd::string> after_section_comment_;
      std::map<xtd::string, string_dictionary> before_key_value_comment_;
      std::map<xtd::string, xtd::string> before_section_comment_;
      xtd::string bottom_file_comment_;
      xtd::string file_path_;
      std::map<xtd::string, string_dictionary> key_value_comment_;
      std::map<xtd::string, xtd::string> section_comment_;
      std::map<xtd::string, string_dictionary> section_key_values_;
      std::iostream* stream_ = nullptr;
      xtd::string top_file_comment_;
    };
  }
}
