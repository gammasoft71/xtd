/// @file
/// @brief Contains xtd::forms::application_informations class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/object.h>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the application informations.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms application
    /// @par Examples
    /// The following code example demonstrate the use of application_informations class.
    /// @include application_informations.cpp
    /// @par Windows
    /// @image html application_informations_w.png
    /// <br>
    /// @image html application_informations_wd.png
    /// @par macOS
    /// @image html application_informations_m.png
    /// <br>
    /// @image html application_informations_md.png
    /// @par Gnome
    /// @image html application_informations_g.png
    /// <br>
    /// @image html application_informations_gd.png
    class application_informations : public object {
    public:
      /// @brief Gets the company name associated with the application.
      /// @return The company name.
      static const xtd::ustring& company_name() {return instance().company_name_;}
      /// @brief Sets the company name associated with the application.
      /// @param company_name The company name.
      static void company_name(const xtd::ustring& company_name) {instance().company_name_ = company_name;}
      
      /// @brief Gets the product description associated with the application.
      /// @return The product description.
      static xtd::ustring product_description() {return instance().product_description_;}
      /// @brief Sets the product description associated with the application.
      /// @param product_name The product description.
      static void product_description(const xtd::ustring& product_description) {instance().product_description_ = product_description;}
      
      /// @brief Gets the product name associated with the application.
      /// @return The product name.
      static xtd::ustring product_name() {return instance().product_name_;}
      /// @brief Sets the product name associated with the application.
      /// @param product_name The product name.
      static void product_name(const xtd::ustring& product_name) {instance().product_name_ = product_name;}

      /// @brief Gets the product version associated with the application.
      /// @return The product version.
      static xtd::ustring product_version() {return instance().product_version_;}
      /// @brief Sets the product version associated with the application.
      /// @param product_version The product version.
      static void product_version(const xtd::ustring& product_version) {instance().product_version_ = product_version;}

    private:
      static application_informations& instance() {
        static application_informations application_informations;
        return application_informations;
      }
      application_informations() = default;
      xtd::ustring company_name_;
      xtd::ustring product_description_;
      xtd::ustring product_name_;
      xtd::ustring product_version_;
    };
  }
}
