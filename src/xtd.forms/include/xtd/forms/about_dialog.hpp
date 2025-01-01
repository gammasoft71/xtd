/// @file
/// @brief Contains xtd::forms::about_dialog dialog.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.hpp"
#include "component.hpp"
#include "dialog_appearance.hpp"
#include "iwin32_window.hpp"
#include "tab_control.hpp"
#include <xtd/drawing/icon>
#include <xtd/reflection/assembly>
#include <xtd/delegate>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays about dialog.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/about_dialog>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html dialog_about_dialog_w.png   |  @image html dialog_about_dialog_m.png   |  @image html dialog_about_dialog_g.png   |
    /// | Dark  |  @image html dialog_about_dialog_wd.png  |  @image html dialog_about_dialog_md.png  |  @image html dialog_about_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of about_dialog dialog.
    /// @include about_dialog.cpp
    /// @par Examples
    /// The following code example demonstrates the use of about_dialog dialog with dialog_styledialog_style to system.
    /// @include about_dialog_system.cpp
    class forms_export_ about_dialog final : public component {
      struct data;
      
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents an author collection.
      using author_collection = xtd::forms::layout::arranged_element_collection<xtd::string>;
      /// @brief Represents an artist collection.
      using artist_collection = xtd::forms::layout::arranged_element_collection<xtd::string>;
      /// @brief Represents a documenter collection.
      using documenter_collection = xtd::forms::layout::arranged_element_collection<xtd::string>;
      /// @brief Represents a translator collection.
      using translator_collection = xtd::forms::layout::arranged_element_collection<xtd::string>;
      /// @brief Represents user tab page collection.
      using user_tab_page_collection = tab_control::tab_page_collection;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the about_dialog class.
      about_dialog();
      /// @}
      
      /// @cond
      ~about_dialog();
      /// @endcond
      
      /// @name Public Properties
      
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
      xtd::string copyright() const noexcept;
      /// @brief Sets the product description.
      /// @param copyright The description copyright.
      /// @return Current about_dialog instance.
      about_dialog& copyright(const xtd::string& copyright);
      
      /// @brief Gets the product description.
      /// @return The product description.
      xtd::string description() const noexcept;
      /// @brief Sets the product description.
      /// @param description The product description.
      /// @return Current about_dialog instance.
      about_dialog& description(const xtd::string& description);
      
      /// @brief Gets the documentation writers array.
      /// @return The documentation writers array.
      const documenter_collection& documenters() const noexcept;
      /// @brief Gets the documentation writers array.
      /// @return The documentation writers array.
      documenter_collection& documenters() noexcept;
      /// @brief Sets the documentation writers array.
      /// @param documenters The documentation writers array.
      /// @return Current about_dialog instance.
      about_dialog& documenters(const documenter_collection& documenters);
      
      /// @brief Gets the dialog appearance.
      /// @return One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      xtd::forms::dialog_appearance dialog_appearance() const noexcept;
      /// @brief Sets the dialog appearance.
      /// @param dialog_appearance One of the xtd::forms::dialog_appearance values. The default value is xtd::forms::dialog_appearance::standard.
      /// @return Current about_dialog instance.
      about_dialog& dialog_appearance(xtd::forms::dialog_appearance dialog_appearance);
      
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
      xtd::string license() const noexcept;
      /// @brief Sets the product license.
      /// @param name The product license.
      /// @return Current about_dialog instance.
      about_dialog& license(const xtd::string& license);
      
      /// @brief Gets the product long version.
      /// @return The product long version.
      xtd::string long_version() const noexcept;
      /// @brief Sets the product long version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      about_dialog& long_version(const xtd::string& long_version);
      
      /// @brief Gets the product name.
      /// @return The product name.
      xtd::string name() const noexcept;
      /// @brief Sets the product name.
      /// @param name The product name.
      /// @return Current about_dialog instance.
      about_dialog& name(const xtd::string& name);
      
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
      
      /// @brief Gets the collection of user tab pages in this about box.
      /// @return A xtd::forms::about_dialog::user_tab_page_collection that contains the control objects in this about box.
      /// @remarks This property is used to add user tab pages in this about dialog.
      user_tab_page_collection& user_tab_pages() noexcept;
      /// @brief Gets the collection of user tab pages in this about box.
      /// @return A xtd::forms::about_dialog::user_tab_page_collection that contains the control objects in this about box.
      /// @remarks This property is used to add user tab pages in this about dialog.
      const user_tab_page_collection& user_tab_pages() const noexcept;

      /// @brief Gets the product version.
      /// @return The product version.
      xtd::string version() const noexcept;
      /// @brief Sets the product version.
      /// @param version The version version.
      /// @return Current about_dialog instance.
      about_dialog& version(const xtd::string& version);
      
      /// @brief Gets the product website.
      /// @return The website.
      xtd::string website() const noexcept;
      /// @brief Sets the product website.
      /// @param website The  product website.
      /// @return Current about_dialog instance.
      about_dialog& website(const xtd::string& website);
      
      /// @brief Gets the product website label.
      /// @return The product website label.
      xtd::string website_label() const noexcept;
      /// @brief Sets the product website label.
      /// @param website_label The product website label.
      /// @return Current about_dialog instance.
      about_dialog& website_label(const xtd::string& website_label);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Resets all properties to empty string.
      void reset() noexcept;
      
      /// @brief Runs about dialog box.
      void show();
      /// @brief Runs about dialog box with specified owner.
      /// @param owner The owner of the about box dialog.
      void show(const iwin32_window& owner);
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @brief Create a new xtd::forms::about_dialog from specified assembly.
      /// @param assembly The xtd::reflection::assembly object containing the information for filling in the dialog.
      /// @return New xtd::forms::about_dialog with xtd::reflection::assembly informations.
      static about_dialog from_assembly(const xtd::reflection::assembly& assembly);
      /// @brief Create a new xtd::forms::about_dialog from executing xtd::reflection::assembly informations.
      /// @return New xtd::forms::about_dialog with executing xtd::reflection::assembly informations.
      static about_dialog from_executing_assembly_informations();
      /// @}

    private:
      xtd::sptr<data> data_;
    };
  }
}
