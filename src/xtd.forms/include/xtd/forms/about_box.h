/// @file
/// @brief Contains xtd::forms::about_box dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "about_dialog.h"
#include <xtd/literals.h>
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a dialog box that displays about box.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Examples
    /// The following code example demonstrate the use of about_box dialog.
    /// @include about_box.cpp
    /// @par Windows
    /// @image html about_box_w.png
    /// <br>
    /// @image html about_box_wd.png
    /// @par macOS
    /// @image html about_box_m.png
    /// <br>
    /// @image html about_box_md.png
    /// @par Gnome
    /// @image html about_box_g.png
    /// <br>
    /// @image html about_box_gd.png
    class forms_export_ about_box final static_ {
    public:
      /// @brief Reprresents a creators collection.
      using creators_collection = xtd::forms::about_dialog::creators_collection;
      /// @brief Reprresents a designers collection.
      using designers_collection = xtd::forms::about_dialog::designers_collection;
      /// @brief Reprresents a documentt writers collection.
      using doc_writers_collection = xtd::forms::about_dialog::doc_writers_collection;
      /// @brief Reprresents a translators collection.
      using translators_collection = xtd::forms::about_dialog::translators_collection;

      /// @brief Displays an about box in front of the specified window.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      static void show(const iwin32_window& owner) {show_about_dialog<xtd::drawing::icon>(&owner);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      static void show(const iwin32_window& owner, const std::string& text) {show_about_dialog<xtd::drawing::icon>(&owner, text);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message and title bar caption.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption) {show_about_dialog<xtd::drawing::icon>(&owner, text, caption);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption and icon.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon) {show_about_dialog(&owner, text, caption, icon);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon and version.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version) {show_about_dialog(&owner, text, caption, icon, version);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version and long version.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version) {show_about_dialog(&owner, text, caption, icon, version, long_version);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version and copyright.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright) {show_about_dialog(&owner, text, caption, icon, version, long_version, copyright);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright and website.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website) {show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright and website with label.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label) {show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label and creators.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators) {show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, creators);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators and documentation writers.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers) {show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers and translators.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators) {show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers, translators and designers.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param designers A designers_collection that specifies the gesigners collection.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators, const designers_collection& designers) {show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators, designers);}

      /// @brief Displays an about box in front of the specified window. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers, translators, designers and license.
      /// @param owner A iwin32_window that represents the owner window of the busy box.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param designers A designers_collection that specifies the gesigners collection.
      /// @param license A string that specifies the license text to display.
      static void show(const iwin32_window& owner, const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators, const designers_collection& designers, const std::string& license) {show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators, designers, license);}

      /// @brief Displays a about box.
      static void show() {show_about_dialog<xtd::drawing::icon>(nullptr);}
      
      /// @brief Displays a about box. The about box displays a message.
      /// @param text A string that specifies the text to display.
      static void show(const std::string& text) {show_about_dialog<xtd::drawing::icon>(nullptr, text);}

      /// @brief Displays a about box. The about box displays a message and title bar caption.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      static void show(const std::string& text, const std::string& caption) {show_about_dialog<xtd::drawing::icon>(nullptr, text, caption);}

      /// @brief Displays a about box. The about box displays a message, title bar caption and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon) {show_about_dialog(nullptr, text, caption, icon);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon and version.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version) {show_about_dialog(nullptr, text, caption, icon, version);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version and long version.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version) {show_about_dialog(nullptr, text, caption, icon, version, long_version);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version and copyright.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright and website.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright and website with label.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label and creators.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators and documentation writers.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers and translators.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers, translators and designers.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param designers A designers_collection that specifies the gesigners collection.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators, const designers_collection& designers) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators, designers);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers, translators, designers and license.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param designers A designers_collection that specifies the gesigners collection.
      /// @param license A string that specifies the license text to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::icon& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators, const designers_collection& designers, const std::string& license) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators, designers, license);}

      /// @brief Displays a about box. The about box displays a message, title bar caption and icon.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon) {show_about_dialog(nullptr, text, caption, icon);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon and version.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version) {show_about_dialog(nullptr, text, caption, icon, version);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version and long version.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version) {show_about_dialog(nullptr, text, caption, icon, version, long_version);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version and copyright.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version, const std::string& copyright) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright and website.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright and website with label.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label and creators.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators and documentation writers.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers and translators.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers, translators and designers.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param designers A designers_collection that specifies the gesigners collection.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators, const designers_collection& designers) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators, designers);}
      
      /// @brief Displays a about box. The about box displays a message, title bar caption, icon, version, long version, copyright, website with label, creators, documentation writers, translators, designers and license.
      /// @param text A string that specifies the text to display.
      /// @param caption A string that specifies the title bar caption to display.
      /// @param icon An icon value that specifies the icon to display.
      /// @param version A string that specifies the version to display.
      /// @param long_version A string that specifies the long version to display.
      /// @param copyright A string that specifies the copyright to display.
      /// @param website A string that specifies the website url.
      /// @param website_label A string that specifies the website label to display.
      /// @param creators A creators_collection that specifies the creators collection.
      /// @param doc_writers A doc_writers_collection that specifies the documentation writers collection.
      /// @param translators A translators_collection that specifies the translators collection.
      /// @param designers A designers_collection that specifies the gesigners collection.
      /// @param license A string that specifies the license text to display.
      static void show(const std::string& text, const std::string& caption, const xtd::drawing::bitmap& icon, const std::string& version, const std::string& long_version, const std::string& copyright, const std::string& website, const std::string& website_label, const creators_collection& creators, const doc_writers_collection& doc_writers, const translators_collection translators, const designers_collection& designers, const std::string& license) {show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, creators, doc_writers, translators, designers, license);}

    private:
      template<typename icon_t>
      static void show_about_dialog(const iwin32_window* owner, const std::string& text = "About box..."_t, const std::string& caption = "", const icon_t& icon = icon_t::empty, const std::string& version = "", const std::string& long_version = "", const std::string& copyright = "", const std::string& website = "", const std::string& website_label = "", const creators_collection& creators = creators_collection {}, const doc_writers_collection& doc_writers = doc_writers_collection {}, const translators_collection translators = translators_collection {}, const designers_collection& designers = designers_collection {}, const std::string& license = "") {
        about_dialog dialog;
        dialog.description(text);
        dialog.name(caption);
        dialog.icon(icon);
        dialog.version(version);
        dialog.long_version(long_version);
        dialog.copyright(copyright);
        dialog.website(website);
        dialog.website_label(website_label);
        dialog.creators(creators);
        dialog.doc_writers(doc_writers);
        dialog.translators(translators);
        dialog.designers(designers);
        dialog.license(license);
        owner ? dialog.show(*owner) : dialog.show();
      }
    };
  }
}
