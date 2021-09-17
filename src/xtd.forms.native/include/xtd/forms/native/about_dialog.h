/// @file
/// @brief Contains xtd::forms::native::about_dialog API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing/icon.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class about_dialog;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains about dialog native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ about_dialog final static_ {
        friend xtd::forms::about_dialog;
      protected:
        /// @brief Shows about dialog.
        /// @param hwnd Window handle.
        /// @param icon An icon value that specifies the icon to display.
        /// @param name A string that specifies the title bar caption to display.
        /// @param decription A string that specifies the text to display.
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
        /// @warning Internal use only
        static void show(intptr_t hwnd, const xtd::drawing::icon& icon, const xtd::ustring& name, const xtd::ustring& description, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const std::vector<xtd::ustring>& creators, const std::vector<xtd::ustring>& designers, const std::vector<xtd::ustring>& doc_writers, const std::vector<xtd::ustring>& translators, const xtd::ustring& license);
      };
    }
  }
}
