#pragma once
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the application informations.
    class application_informations {
    public:
      /// @brief Gets the company name associated with the application.
      /// @return The company name.
      static const std::string& company_name() {return instance().company_name_;}
      /// @brief Sets the company name associated with the application.
      /// @param company_name The company name.
      static void company_name(const std::string& company_name) {instance().company_name_ = company_name;}
      
      /// @brief Gets the product description associated with the application.
      /// @return The product description.
      static std::string product_description() {return instance().product_description_;}
      /// @brief Sets the product description associated with the application.
      /// @param product_name The product description.
      static void product_description(const std::string& product_description) {instance().product_description_ = product_description;}
      
      /// @brief Gets the product name associated with the application.
      /// @return The product name.
      static std::string product_name() {return instance().product_name_;}
      /// @brief Sets the product name associated with the application.
      /// @param product_name The product name.
      static void product_name(const std::string& product_name) {instance().product_name_ = product_name;}

      /// @brief Gets the product version associated with the application.
      /// @return The product version.
      static std::string product_version() {return instance().product_version_;}
      /// @brief Sets the product version associated with the application.
      /// @param product_version The product version.
      static void product_version(const std::string& product_version) {instance().product_version_ = product_version;}

    private:
      static application_informations& instance() {
        static application_informations application_informations;
        return application_informations;
      }
      application_informations() = default;
      std::string company_name_;
      std::string product_description_;
      std::string product_name_;
      std::string product_version_;
    };
  }
}
