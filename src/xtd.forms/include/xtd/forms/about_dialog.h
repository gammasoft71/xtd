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
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// <table align="center" border="0" cellpadding="10" cellspacing="0" style="width:100%">
    ///   <tr>
    ///     <th style="width:100px"></th>
    ///     <th><b>Windows</b></th>
    ///     <th><b>macOS</b></th>
    ///     <th><b>Gnome</b></th>
    ///   </tr>
    ///   <tr>
    ///     <th>Light</th>
    ///     <td>@image html dialog_about_dialog_w.png</td>
    ///     <td>@image html dialog_about_dialog_m.png</td>
    ///     <td>@image html dialog_about_dialog_g.png</td>
    ///   </tr>
    ///   <tr>
    ///     <th>Dark</th>
    ///     <td>@image html dialog_about_dialog_wd.png</td>
    ///     <td>@image html dialog_about_dialog_md.png</td>
    ///     <td>@image html dialog_about_dialog_gd.png</td>
    ///   </tr>
    /// </table>
    /// @par Examples
    /// The following code example demonstrate the use of about_dialog dialog.
    /// @include about_dialog.cpp
    /// @par Examples
    /// The following code example demonstrates the use of about_dialog dialog with dialog_styledialog_style to system.
    /// @include about_dialog_system.cpp
    class forms_export_ about_dialog final : public component {
    public:
      /// @name Alias
      
      /// @{
      /// @brief Represents a author collection.
      using author_collection = xtd::forms::layout::arranged_element_collection<xtd::ustring>;
      /// @brief Represents a artist collection.
      using artist_collection = xtd::forms::layout::arranged_element_collection<xtd::ustring>;
      /// @brief Represents a documenter collection.
      using documenter_collection = xtd::forms::layout::arranged_element_collection<xtd::ustring>;
      /// @brief Represents a translator collection.
      using translator_collection = xtd::forms::layout::arranged_element_collection<xtd::ustring>;
      /// @}

      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the about_dialog class.
      about_dialog() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the artists array.
      /// @return The artists array.
      const artist_collection& artists() const {return data_->artists;}
      /// @brief Gets the artists array.
      /// @return The artists array.
      artist_collection& artists() {return data_->artists;}
      /// @brief Sets the artists array.
      /// @param artists The artists array.
      /// @return Current about_dialog instance.
      about_dialog& artists(const artist_collection& artists) {
        data_->artists = artists;
        return *this;
      }

      /// @brief Gets the authors array.
      /// @return The author array.
      const author_collection& authors() const {return data_->authors;}
      /// @brief Gets the authors array.
      /// @return The authors array.
      author_collection& authors() {return data_->authors;}
      /// @brief Sets the authors array.
      /// @param authors The authors array.
      /// @return Current about_dialog instance.
      about_dialog& authors(const author_collection& authors) {
        data_->authors = authors;
        return *this;
      }
      
      /// @brief Gets the product copyright.
      /// @return The product copyright.
      xtd::ustring copyright() const {return data_->copyright;}
      /// @brief Sets the product description.
      /// @param copyright The description copyright.
      /// @return Current about_dialog instance.
      about_dialog& copyright(const xtd::ustring& copyright) {
        data_->copyright = copyright;
        return *this;
      }

      /// @brief Gets the product description.
      /// @return The product description.
      xtd::ustring description() const {return data_->description;}
      /// @brief Sets the product description.
      /// @param description The product description.
      /// @return Current about_dialog instance.
      about_dialog& description(const xtd::ustring& description) {
        data_->description = description;
        return *this;
      }

      /// @brief Gets the documentation writers array.
      /// @return The documentation writers array.
      const documenter_collection& documenters() const {return data_->documenters;}
      /// @brief Gets the artists array.
      /// @return The artists array.
      documenter_collection& documenters() {return data_->documenters;}
      /// @brief Sets the documenters array.
      /// @param documenters The documenters array.
      /// @return Current about_dialog instance.
      about_dialog& documenters(const documenter_collection& documenters) {
        data_->documenters = documenters;
        return *this;
      }

      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const {return data_->dialog_style;}
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current about_dialog instance.
      about_dialog& dialog_style(xtd::forms::dialog_style dialog_style) {
        data_->dialog_style = dialog_style;
        return *this;
      }

      /// @brief Gets the product icon.
      /// @return The product icon.
      xtd::drawing::icon icon() const {return xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon));}
      /// @brief Sets the product icon.
      /// @param icon The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::icon& icon) {
        data_->icon = icon.to_bitmap();
        return *this;
      }
      /// @brief Sets the product icon.
      /// @param image The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::image& image) {
        data_->icon = image;
        return *this;
      }
      /// @brief Sets the product icon.
      /// @param bitmap The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::bitmap& bitmap) {
        data_->icon = bitmap;
        return *this;
      }

      /// @brief Gets the product license.
      /// @return The product license.
      xtd::ustring license() const {return data_->license;}
      /// @brief Sets the product license.
      /// @param name The product license.
      /// @return Current about_dialog instance.
      about_dialog& license(const xtd::ustring& license) {
        data_->license = license;
        return *this;
      }

      /// @brief Gets the product long version.
      /// @return The product long version.
      xtd::ustring long_version() const {return data_->long_version;}
      /// @brief Sets the product long version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      about_dialog& long_version(const xtd::ustring& long_version) {
        data_->long_version = long_version;
        return *this;
      }

      /// @brief Gets the product name.
      /// @return The product name.
      xtd::ustring name() const {return data_->name;}
      /// @brief Sets the product name.
      /// @param name The product name.
      /// @return Current about_dialog instance.
      about_dialog& name(const xtd::ustring& name) {
        data_->name = name;
        return *this;
      }
      
      /// @brief Gets the translators array.
      /// @return The translators array.
      const translator_collection& translators() const {return data_->translators;}
      /// @brief Gets the translators array.
      /// @return The translators array.
      translator_collection& translators() {return data_->translators;}
      /// @brief Sets the translators array.
      /// @param translators The translators array.
      /// @return Current about_dialog instance.
      about_dialog& translators(const translator_collection& translators) {
        data_->translators = translators;
        return *this;
      }

      /// @brief Gets the product version.
      /// @return The product version.
      xtd::ustring version() const {return data_->version;}
      /// @brief Sets the product version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      about_dialog& version(const xtd::ustring& version) {
        data_->version = version;
        return *this;
      }
      
      /// @brief Gets the product website.
      /// @return The website.
      xtd::ustring website() const {return data_->website;}
      /// @brief Sets the product website.
      /// @param website The  product website.
      /// @return Current about_dialog instance.
      about_dialog& website(const xtd::ustring& website) {
        data_->website = website;
        return *this;
      }
      
      /// @brief Gets the product website label.
      /// @return The product website label.
      xtd::ustring website_label() const {return data_->website_label;}
      /// @brief Sets the product website label.
      /// @param website_label The product website label.
      /// @return Current about_dialog instance.
      about_dialog& website_label(const xtd::ustring& website_label) {
        data_->website_label = website_label;
        return *this;
      }
      /// @}

      /// @name Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset();
      
      /// @brief Runs about dialog box.
      void show();
      /// @brief Runs about dialog box.
      void show(const iwin32_window& owner);
      /// @}

    private:
      struct data {
        xtd::forms::dialog_style dialog_style = xtd::forms::dialog_style::standard;
        xtd::drawing::image icon;
        xtd::ustring name;
        xtd::ustring version;
        xtd::ustring long_version;
        xtd::ustring description;
        xtd::ustring copyright;
        xtd::ustring website;
        xtd::ustring website_label;
        author_collection authors;
        documenter_collection documenters;
        translator_collection translators;
        artist_collection artists;
        xtd::ustring license;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
