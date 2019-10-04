#pragma once
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class application_informations {
    public:
      static const ustring& company_name() {return instance().company_name_;}
      static void company_name(const ustring& company_name) {instance().company_name_ = company_name;}
      
      static ustring product_name() {return instance().product_name_;}
      static void product_name(const ustring& product_name) {instance().product_name_ = product_name;}
      
      static ustring product_version() {return instance().product_version_;}
      static void product_version(const ustring& product_version) {instance().product_version_ = product_version;}

    private:
      static application_informations& instance() {
        static application_informations application_informations;
        return application_informations;
      }
      application_informations() = default;
      ustring company_name_;
      ustring product_name_;
      ustring product_version_;
    };
  }
}
