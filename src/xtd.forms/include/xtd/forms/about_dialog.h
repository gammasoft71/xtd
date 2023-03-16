/// @file
/// @brief Contains xtd::forms::about_dialog dialog.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
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
    /// The following code example demonstrates the use of about_dialog dialog.
    /// @include about_dialog.cpp
    /// @par Examples
    /// The following code example demonstrates the use of about_dialog dialog with dialog_styledialog_style to system.
    /// @include about_dialog_system.cpp
    class forms_export_ about_dialog final : public component {
      struct data;
      
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
      about_dialog();
      /// @}

      /// @cond
      ~about_dialog();
      /// @endcond

      /// @name Properties
      
      /// @{
      /// @brief Gets the artists array.
      /// @return The artists array.
      const artist_collection& artists() const noexcept;
      /// @brief Gets the artists array.
      /// @return The artists array.
      artist_collection& artists() noexcept;
      /// @brief Sets the artists array.
      /// @param artists The artists array.
      /// @return Current about_dialog instance.
      about_dialog& artists(const artist_collection& artists);
      
      /// @brief Gets the authors array.
      /// @return The author array.
      const author_collection& authors() const noexcept;
      /// @brief Gets the authors array.
      /// @return The authors array.
      author_collection& authors() noexcept;
      /// @brief Sets the authors array.
      /// @param authors The authors array.
      /// @return Current about_dialog instance.
      about_dialog& authors(const author_collection& authors);
      
      /// @brief Gets the product copyright.
      /// @return The product copyright.
      xtd::ustring copyright() const noexcept;
      /// @brief Sets the product description.
      /// @param copyright The description copyright.
      /// @return Current about_dialog instance.
      about_dialog& copyright(const xtd::ustring& copyright);
      
      /// @brief Gets the product description.
      /// @return The product description.
      xtd::ustring description() const noexcept;
      /// @brief Sets the product description.
      /// @param description The product description.
      /// @return Current about_dialog instance.
      about_dialog& description(const xtd::ustring& description);
      
      /// @brief Gets the documentation writers array.
      /// @return The documentation writers array.
      const documenter_collection& documenters() const noexcept;
      /// @brief Gets the artists array.
      /// @return The artists array.
      documenter_collection& documenters() noexcept;
      /// @brief Sets the documenters array.
      /// @param documenters The documenters array.
      /// @return Current about_dialog instance.
      about_dialog& documenters(const documenter_collection& documenters);
      
      /// @brief Gets the dialog style.
      /// @return One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      xtd::forms::dialog_style dialog_style() const noexcept;
      /// @brief Sets the dialog style.
      /// @param dialog_style One of the xtd::forms::dialog_style values. The default value is xtd::forms::dialog_style::standard.
      /// @return Current about_dialog instance.
      about_dialog& dialog_style(xtd::forms::dialog_style dialog_style);
      
      /// @brief Gets the product icon.
      /// @return The product icon.
      xtd::drawing::icon icon() const noexcept;
      /// @brief Sets the product icon.
      /// @param icon The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::icon& icon);
      /// @brief Sets the product icon.
      /// @param image The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::image& image);
      /// @brief Sets the product icon.
      /// @param bitmap The product icon.
      /// @return Current about_dialog instance.
      about_dialog& icon(const xtd::drawing::bitmap& bitmap);
      
      /// @brief Gets the product license.
      /// @return The product license.
      xtd::ustring license() const noexcept;
      /// @brief Sets the product license.
      /// @param name The product license.
      /// @return Current about_dialog instance.
      about_dialog& license(const xtd::ustring& license);
      
      /// @brief Gets the product long version.
      /// @return The product long version.
      xtd::ustring long_version() const noexcept;
      /// @brief Sets the product long version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      about_dialog& long_version(const xtd::ustring& long_version);
      
      /// @brief Gets the product name.
      /// @return The product name.
      xtd::ustring name() const noexcept;
      /// @brief Sets the product name.
      /// @param name The product name.
      /// @return Current about_dialog instance.
      about_dialog& name(const xtd::ustring& name);
      
      /// @brief Gets the translators array.
      /// @return The translators array.
      const translator_collection& translators() const noexcept;
      /// @brief Gets the translators array.
      /// @return The translators array.
      translator_collection& translators() noexcept;
      /// @brief Sets the translators array.
      /// @param translators The translators array.
      /// @return Current about_dialog instance.
      about_dialog& translators(const translator_collection& translators);
      
      /// @brief Gets the product version.
      /// @return The product version.
      xtd::ustring version() const noexcept;
      /// @brief Sets the product version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      about_dialog& version(const xtd::ustring& version);
      
      /// @brief Gets the product website.
      /// @return The website.
      xtd::ustring website() const noexcept;
      /// @brief Sets the product website.
      /// @param website The  product website.
      /// @return Current about_dialog instance.
      about_dialog& website(const xtd::ustring& website);
      
      /// @brief Gets the product website label.
      /// @return The product website label.
      xtd::ustring website_label() const noexcept;
      /// @brief Sets the product website label.
      /// @param website_label The product website label.
      /// @return Current about_dialog instance.
      about_dialog& website_label(const xtd::ustring& website_label);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset() noexcept;
      
      /// @brief Runs about dialog box.
      void show();
      /// @brief Runs about dialog box.
      void show(const iwin32_window& owner);
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
