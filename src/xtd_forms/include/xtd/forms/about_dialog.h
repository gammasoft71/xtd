#pragma once
#include "common_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays about box.
    /// @par Example
    /// The following code example demonstrate the use of about_dialog dialog.
    /// @include about_dialog.cpp
    class about_dialog : public common_dialog {
    public:
      /// @brief Initializes a new instance of the about_dialog class.
      about_dialog() = default;
      
      /// @brief Gets the product copyright.
      /// @return The product copyright.
      std::string copyright() const {return this->copyright_;}
      /// @brief Sets the product description.
      /// @param copyright The description copyright.
      /// @return Current about_box instance.
      about_dialog& copyright(const std::string& copyright) {
        copyright_ = copyright;
        return *this;
      }
      
      /// @brief Gets the product description.
      /// @return The product description.
      std::string description() const {return this->description_;}
      /// @brief Sets the product description.
      /// @param description The description description.
      /// @return Current about_box instance.
      about_dialog& description(const std::string& description) {
        description_ = description;
        return *this;
      }
      
      /// @brief Gets the product long version.
      /// @return The product long version.
      std::string long_version() const {return this->long_version_;}
      /// @brief Sets the product long version.
      /// @param version The version version.
      /// @return Current about_box instance.
      about_dialog& long_version(const std::string& long_version) {
        long_version_ = long_version;
        return *this;
      }

      /// @brief Gets the product name.
      /// @return The product name.
      std::string name() const {return this->name_;}
      /// @brief Sets the product name.
      /// @param name The product name.
      /// @return Current about_box instance.
      about_dialog& name(const std::string& name) {
        name_ = name;
        return *this;
      }
      
      /// @brief Gets the product version.
      /// @return The product version.
      std::string version() const {return this->version_;}
      /// @brief Sets the product version.
      /// @param version The version version.
      /// @return Current about_box instance.
      about_dialog& version(const std::string& version) {
        version_ = version;
        return *this;
      }

      /// @brief Resets all properties to empty string.
      void reset() override;
      
      /// @brief Runs about dialog box.
      void show()  {run_dialog(0);}
      
    protected:
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      bool run_dialog(intptr_t owner) override;

      dialog_result show_dialog();
      dialog_result show_dialog(const iwin32_window& owner);
      std::string copyright_;
      std::string description_;
      std::string name_;
      std::string long_version_;
      std::string version_;
    };
  }
}
