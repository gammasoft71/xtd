#pragma region xtd generated code
// This code was generated by CMake script.
//
// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.

#pragma once
#include <xtd/configuration/settings>

namespace settings_command::properties {
  /// @brief A strongly typed settings class, for storing user and system settings
  /// @details This class was auto-generated by CMake script. To add or remove a member, edit your CMakeList.txt or properties/settings.cmake file then rerun cmake tools.
  /// @remarks See [Settings](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/settings) for more informations.
  class settings : public xtd::object {
  public:
    /// @name Public Constructors

    /// @{
    /// @brief Initializes a new instance of the settings_command::properties::settings class.
    /// @remarks All properties are reloaded with the last saved value.
    settings() noexcept : settings {true} {}
    /// @brief Initializes a new instance of the settings_command::properties::settings class.
    /// @param load If `true` all properties are reloaded with the last saved values; otherwise none.
    explicit settings(bool load) noexcept {
      if (load) reload();
    }
    /// @}

    /// @cond
    settings(settings&&) noexcept = default;
    settings(const settings&) noexcept = default;
    settings& operator =(const settings&) noexcept = default;
    /// @endcond

    /// @name Public Properties

    /// @{
    /// @brief Gets the color user setting property.
    /// @return A xtd::drawing::color value.
    xtd::drawing::color color() const noexcept {return color_;}
    /// @brief Sets the color user setting property.
    /// @param value A xtd::drawing::color value.
    settings& color(xtd::drawing::color value) noexcept {
      color_ = value;
      return *this;
    }

    /// @}

    /// @name Public Methods

    /// @{
    /// @brief Reload all properties with the last saved values.
    /// @remarks See [Settings](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/settings) for more informations.
    void reload() noexcept {
      color_ = settings_.read("color", color_);
    }

    /// @brief Reset all properties to their default values.
    /// @remarks See [Settings](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/settings) for more informations.
    void reset() noexcept {
      settings_.reset();
      *this = settings {false};
    }

    /// @brief Save all properties.
    /// @remarks See [Settings](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/settings) for more informations.
    void save() noexcept {
      settings_.write("color", color_);
      settings_.save();
    }
    /// @}

    /// @name Public Static Properties

    /// @{
    /// @brief Gets the default instance of settings.
    /// @return The default instance.
    /// @remarks At the first call all properties are reloaded with the last saved values.
    static settings& default_settings() noexcept {
      static auto default_settings = settings {};
      return default_settings;
    }
    /// @}

  private:
    xtd::configuration::settings settings_;
    xtd::drawing::color color_ {xtd::drawing::color::red};
  };
}

#pragma endregion
