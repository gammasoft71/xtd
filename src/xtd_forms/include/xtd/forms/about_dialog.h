#pragma once
#include <xtd/drawing/icon.h>
#include "dialog_style.h"
#include "common_dialog.h"
#include "layout/arranged_element_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays about box.
    /// @par Example
    /// The following code example demonstrate the use of about_dialog dialog.
    /// @include about_dialog.cpp
    class about_dialog {
    public:
      using creators_collection = xtd::forms::layout::arranged_element_collection<std::string>;
      using designers_collection = xtd::forms::layout::arranged_element_collection<std::string>;
      using doc_writers_collection = xtd::forms::layout::arranged_element_collection<std::string>;
      using translators_collection = xtd::forms::layout::arranged_element_collection<std::string>;

      /// @brief Initializes a new instance of the about_dialog class.
      about_dialog() = default;
      
      xtd::forms::dialog_style dialog_style() const {return dialog_style_;}
      about_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        dialog_style_ = dialog_style;
        return *this;
      }
      
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
      /// @param description The product description.
      /// @return Current about_box instance.
      about_dialog& description(const std::string& description) {
        description_ = description;
        return *this;
      }
      
      /// @brief Gets the product icon.
      /// @return The product icon.
      xtd::drawing::icon icon() const {return xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(this->icon_));}
      /// @brief Sets the product icon.
      /// @param icon The product icon.
      /// @return Current about_box instance.
      about_dialog& icon(const xtd::drawing::icon& icon) {
        icon_ = icon.to_bitmap();
        return *this;
      }
      /// @brief Sets the product icon.
      /// @param image The product icon.
      /// @return Current about_box instance.
      about_dialog& icon(const xtd::drawing::image& image) {
        icon_ = image;
        return *this;
      }
      /// @brief Sets the product icon.
      /// @param bitmap The product icon.
      /// @return Current about_box instance.
      about_dialog& icon(const xtd::drawing::bitmap& bitmap) {
        icon_ = bitmap;
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
      
      /// @brief Gets the product website.
      /// @return The website.
      std::string website() const {return this->website_;}
      /// @brief Sets the product website.
      /// @param website The  product website.
      /// @return Current about_box instance.
      about_dialog& website(const std::string& website) {
        website_ = website;
        return *this;
      }
      
      /// @brief Gets the product website label.
      /// @return The product website label.
      std::string website_label() const {return this->website_label_;}
      /// @brief Sets the product website label.
      /// @param website_label The product website label.
      /// @return Current about_box instance.
      about_dialog& website_label(const std::string& website_label) {
        website_label_ = website_label;
        return *this;
      }
      
      /// @brief Gets the creators array.
      /// @return The creator array.
      const creators_collection& creators() const {return creators_;}
      /// @brief Gets the creators array.
      /// @return The creator array.
      creators_collection& creators() {return creators_;}
      /// @brief Sets the creators array.
      /// @param creators The creators array.
      /// @return Current about_box instance.
      about_dialog& creators(const creators_collection& creators) {
        creators_ = creators;
        return *this;
      }
      
      /// @brief Gets the designers array.
      /// @return The designers array.
      const designers_collection& designers() const {return designers_;}
      /// @brief Gets the designers array.
      /// @return The designers array.
      designers_collection& designers() {return designers_;}
      /// @brief Sets the designers array.
      /// @param designers The designers array.
      /// @return Current about_box instance.
      about_dialog& designers(const designers_collection& designers) {
        designers_ = designers;
        return *this;
      }
      
      /// @brief Gets the documentation writers array.
      /// @return The documentation writers array.
      const doc_writers_collection& doc_writers() const {return doc_writers_;}
      /// @brief Gets the documentation writers array.
      /// @return The designers array.
      doc_writers_collection& doc_writers() {return doc_writers_;}
      /// @brief Sets the documentation writers array.
      /// @param doc_writers The documentation writers array.
      /// @return Current about_box instance.
      about_dialog& doc_writers(const doc_writers_collection& doc_writers) {
        doc_writers_ = doc_writers;
        return *this;
      }
      
      /// @brief Gets the translators array.
      /// @return The translators array.
      const translators_collection& translators() const {return translators_;}
      /// @brief Gets the translators array.
      /// @return The translators array.
      translators_collection& translators() {return translators_;}
      /// @brief Sets the translators array.
      /// @param translators The translators array.
      /// @return Current about_box instance.
      about_dialog& translators(const translators_collection& translators) {
        translators_ = translators;
        return *this;
      }

      /// @brief Gets the product license.
      /// @return The product license.
      std::string license() const {return this->license_;}
      /// @brief Sets the product license.
      /// @param name The product license.
      /// @return Current about_box instance.
      about_dialog& license(const std::string& license) {
        license_ = license;
        return *this;
      }

      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs about dialog box.
      void show();
      /// @brief Runs about dialog box.
      void show(const iwin32_window& owner);

    protected:
      xtd::forms::dialog_style dialog_style_ = xtd::forms::dialog_style::standard;
      xtd::drawing::image icon_;
      std::string name_;
      std::string version_;
      std::string long_version_;
      std::string description_;
      std::string copyright_;
      std::string website_;
      std::string website_label_;
      creators_collection creators_;
      doc_writers_collection doc_writers_;
      translators_collection translators_;
      designers_collection designers_;
      std::string license_;
    };
  }
}
