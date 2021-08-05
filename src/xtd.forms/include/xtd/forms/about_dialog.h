/// @file
/// @brief Contains xtd::forms::about_dialog dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/delegate.h>
#include <xtd/ustring.h>
#include <xtd/drawing/icon.h>
#include "component.h"
#include "dialog_style.h"
#include "iwin32_window.h"
#include "layout/arranged_element_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays about dialog.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of about_dialog dialog.
    /// @include about_dialog.cpp
    /// @par Windows
    /// @image html about_dialog_w.png
    /// <br>
    /// @image html about_dialog_wd.png
    /// @par macOS
    /// @image html about_dialog_m.png
    /// <br>
    /// @image html about_dialog_md.png
    /// @par Gnome
    /// @image html about_dialog_g.png
    /// <br>
    /// @image html about_dialog_gd.png
    /// @par Examples
    /// The following code example demonstrate the use of about_dialog dialog with dialog_styledialog_style tooo system.
    /// @include about_dialog_system.cpp
    /// @par Windows
    /// @image html about_dialog_system_w.png
    /// <br>
    /// @image html about_dialog_system_wd.png
    /// @par macOS
    /// @image html about_dialog_system_m.png
    /// <br>
    /// @image html about_dialog_system_md.png
    /// @par Gnome
    /// @image html about_dialog_system_g.png
    /// <br>
    /// @image html about_dialog_system_gd.png
    class forms_export_ about_dialog final : public component {
    public:
      /// @brief Represents a author collection.
      using author_collection = xtd::forms::layout::arranged_element_collection<xtd::ustring>;
      /// @brief Represents a artist collection.
      using artist_collection = xtd::forms::layout::arranged_element_collection<xtd::ustring>;
      /// @brief Represents a documenter collection.
      using documenter_collection = xtd::forms::layout::arranged_element_collection<xtd::ustring>;
      /// @brief Represents a translator collection.
      using translator_collection = xtd::forms::layout::arranged_element_collection<xtd::ustring>;

      /// @brief Initializes a new instance of the about_dialog class.
      about_dialog() = default;
      
      /// @brief Gets the artists array.
      /// @return The artists array.
      const artist_collection& artists() const {return artists_;}
      /// @brief Gets the artists array.
      /// @return The artists array.
      artist_collection& artists() {return artists_;}
      /// @brief Sets the artists array.
      /// @param artists The artists array.
      /// @return Current about_dialog instance.
      about_dialog& artists(const artist_collection& artists) {
        artists_ = artists;
        return *this;
      }

      /// @brief Gets the authors array.
      /// @return The author array.
      const author_collection& authors() const {return authors_;}
      /// @brief Gets the authors array.
      /// @return The authors array.
      author_collection& authors() {return authors_;}
      /// @brief Sets the authors array.
      /// @param authors The authors array.
      /// @return Current about_dialog instance.
      about_dialog& authors(const author_collection& authors) {
        authors_ = authors;
        return *this;
      }
      
      /// @brief Gets the product copyright.
      /// @return The product copyright.
      std::string copyright() const {return copyright_;}
      /// @brief Sets the product description.
      /// @param copyright The description copyright.
      /// @return Current about_dialog instance.
      about_dialog& copyright(const std::string& copyright) {
        copyright_ = copyright;
        return *this;
      }

      /// @brief Gets the product description.
      /// @return The product description.
      std::string description() const {return description_;}
      /// @brief Sets the product description.
      /// @param description The product description.
      /// @return Current about_dialog instance.
      about_dialog& description(const std::string& description) {
        description_ = description;
        return *this;
      }

      /// @brief Gets the documentation writers array.
      /// @return The documentation writers array.
      const documenter_collection& documenters() const {return documenters_;}
      /// @brief Gets the artists array.
      /// @return The artists array.
      documenter_collection& documenters() {return documenters_;}
      /// @brief Sets the documenters array.
      /// @param documenters The documenters array.
      /// @return Current about_dialog instance.
      about_dialog& documenters(const documenter_collection& documenters) {
        documenters_ = documenters;
        return *this;
      }

      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const {return dialog_style_;}
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current about_dialog instance.
      about_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        dialog_style_ = dialog_style;
        return *this;
      }

      /// @brief Gets the product icon.
      /// @return The product icon.
      xtd::drawing::icon icon() const {return xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_));}
      /// @brief Sets the product icon.
      /// @param icon The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::icon& icon) {
        icon_ = icon.to_bitmap();
        return *this;
      }
      /// @brief Sets the product icon.
      /// @param image The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::image& image) {
        icon_ = image;
        return *this;
      }
      /// @brief Sets the product icon.
      /// @param bitmap The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::bitmap& bitmap) {
        icon_ = bitmap;
        return *this;
      }

      /// @brief Gets the product license.
      /// @return The product license.
      std::string license() const {return license_;}
      /// @brief Sets the product license.
      /// @param name The product license.
      /// @return Current about_dialog instance.
      about_dialog& license(const std::string& license) {
        license_ = license;
        return *this;
      }

      /// @brief Gets the product long version.
      /// @return The product long version.
      std::string long_version() const {return long_version_;}
      /// @brief Sets the product long version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      about_dialog& long_version(const std::string& long_version) {
        long_version_ = long_version;
        return *this;
      }

      /// @brief Gets the product name.
      /// @return The product name.
      std::string name() const {return name_;}
      /// @brief Sets the product name.
      /// @param name The product name.
      /// @return Current about_dialog instance.
      about_dialog& name(const std::string& name) {
        name_ = name;
        return *this;
      }
      
      /// @brief Gets the translators array.
      /// @return The translators array.
      const translator_collection& translators() const {return translators_;}
      /// @brief Gets the translators array.
      /// @return The translators array.
      translator_collection& translators() {return translators_;}
      /// @brief Sets the translators array.
      /// @param translators The translators array.
      /// @return Current about_dialog instance.
      about_dialog& translators(const translator_collection& translators) {
        translators_ = translators;
        return *this;
      }

      /// @brief Gets the product version.
      /// @return The product version.
      std::string version() const {return version_;}
      /// @brief Sets the product version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      about_dialog& version(const std::string& version) {
        version_ = version;
        return *this;
      }
      
      /// @brief Gets the product website.
      /// @return The website.
      std::string website() const {return website_;}
      /// @brief Sets the product website.
      /// @param website The  product website.
      /// @return Current about_dialog instance.
      about_dialog& website(const std::string& website) {
        website_ = website;
        return *this;
      }
      
      /// @brief Gets the product website label.
      /// @return The product website label.
      std::string website_label() const {return website_label_;}
      /// @brief Sets the product website label.
      /// @param website_label The product website label.
      /// @return Current about_dialog instance.
      about_dialog& website_label(const std::string& website_label) {
        website_label_ = website_label;
        return *this;
      }

      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs about dialog box.
      void show();
      /// @brief Runs about dialog box.
      void show(const iwin32_window& owner);

    private:
      xtd::forms::dialog_style dialog_style_ = xtd::forms::dialog_style::standard;
      xtd::drawing::image icon_;
      std::string name_;
      std::string version_;
      std::string long_version_;
      std::string description_;
      std::string copyright_;
      std::string website_;
      std::string website_label_;
      author_collection authors_;
      documenter_collection documenters_;
      translator_collection translators_;
      artist_collection artists_;
      std::string license_;
    };
  }
}
