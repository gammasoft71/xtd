/// @file
/// @brief Contains xtd::forms::about_box dialog.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "about_dialog.hpp"
#include <xtd/static>
#include <xtd/string>
#include <xtd/globalization/translator>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays about box.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/about_box>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html dialog_about_dialog_w.png   |  @image html dialog_about_dialog_m.png   |  @image html dialog_about_dialog_g.png   |
    /// | Dark  |  @image html dialog_about_dialog_wd.png  |  @image html dialog_about_dialog_md.png  |  @image html dialog_about_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of about_box dialog.
    /// @include about_box.cpp
    class forms_export_ about_box final static_ {
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents an author collection.
      using author_collection = xtd::forms::about_dialog::author_collection;
      /// @brief Represents an artist collection.
      using artist_collection = xtd::forms::about_dialog::artist_collection;
      /// @brief Represents a documenter collection.
      using documenter_collection = xtd::forms::about_dialog::documenter_collection;
      /// @brief Represents a translator collection.
      using translator_collection = xtd::forms::about_dialog::translator_collection;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays an about box in front of the specified window.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      static auto show(const xtd::forms::iwin32_window& owner) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message and title bar caption.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption and icon.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon and version.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version and long version.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version and copyright.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright and website.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright and website with label.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label and authors.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors and documentation writers.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers and translators.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers, translators and artists.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param artists A artists_collection that specifies the designers collection.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists) -> void;
      
      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers, translators, artists and license.
      /// @param owner A xtd::forms::iwin32_window that represents the owner window of the about box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param artists A artists_collection that specifies the designers collection.
      /// @param license A string that specifies the license text to display.
      static auto show(const xtd::forms::iwin32_window& owner, const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists, const xtd::string& license) -> void;
      
      /// @brief Displays an about box.
      static auto show() -> void;
      
      /// @brief Displays an about box. The about box displays a message.
      /// @param text A string that specifies the text to display.
      static auto show(const xtd::string& text) -> void;
      
      /// @brief Displays an about box. The about box displays a message and title bar caption.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      static auto show(const xtd::string& text, const xtd::string& caption) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon and version.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version and long version.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version and copyright.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright and website.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright and website with label.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label and authors.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors and documentation writers.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers and translators.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers, translators and artists.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param artists A artists_collection that specifies the designers collection.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers, translators, artists and license.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param artists A artists_collection that specifies the designers collection.
      /// @param license A string that specifies the license text to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::icon& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists, const xtd::string& license) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon and version.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version and long version.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version and copyright.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright and website.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright and website with label.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label and authors.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors and documentation writers.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers and translators.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers, translators and artists.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param artists A artists_collection that specifies the designers collection.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists) -> void;
      
      /// @brief Displays an about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, authors, documentation writers, translators, artists and license.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param authors A authors_collection that specifies the authors collection.
      /// @param documenters A documenters_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param artists A artists_collection that specifies the designers collection.
      /// @param license A string that specifies the license text to display.
      static auto show(const xtd::string& text, const xtd::string& caption, const xtd::drawing::bitmap& icon, const xtd::string& version, const xtd::string& long_version, const xtd::string& copyright, const xtd::string& website, const xtd::string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists, const xtd::string& license) -> void;
      /// @}
      
    private:
      template<typename icon_t>
      static auto show_about_dialog(const xtd::forms::iwin32_window* owner, const xtd::string& text = "About box..."_t, const xtd::string& caption = xtd::string::empty_string, const icon_t& icon = icon_t::empty, const xtd::string& version = xtd::string::empty_string, const xtd::string& long_version = xtd::string::empty_string, const xtd::string& copyright = xtd::string::empty_string, const xtd::string& website = xtd::string::empty_string, const xtd::string& website_label = xtd::string::empty_string, const author_collection& authors = author_collection {}, const documenter_collection& documenters = documenter_collection {}, const translator_collection& translators = translator_collection {}, const artist_collection& artists = artist_collection {}, const xtd::string& license = "") -> void {
        static auto dialog = about_dialog {};
        dialog.description(text);
        dialog.name(caption);
        dialog.icon(icon);
        dialog.version(version);
        dialog.long_version(long_version);
        dialog.copyright(copyright);
        dialog.website(website);
        dialog.website_label(website_label);
        dialog.authors(authors);
        dialog.documenters(documenters);
        dialog.translators(translators);
        dialog.artists(artists);
        dialog.license(license);
        owner ? dialog.show(*owner) : dialog.show();
      }
    };
  }
}
