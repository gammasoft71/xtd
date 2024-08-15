/// @file
/// @brief Contains xtd::reflection::assembly class.
#pragma once
#include "../object.h"
#include "../string.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Represents an assembly, which is a reusable, versionable, and self-describing building block of an application.
    /// ```cpp
    /// class assembly : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::reflection::assembly
    /// @par Header
    /// ```cpp
    /// #include <xtd/reflection/assembly>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    class core_export_ assembly : public xtd::object {
    public:
      /// @cond
      assembly(const assembly&) = default;
      assembly(assembly&&) = default;
      assembly& operator =(const assembly&) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets company name information.
      /// @return A string containing the company name.
      const string& company() const noexcept;
      
      /// @brief Gets assembly configuration information.
      /// @return A string containing the assembly configuration information.
      const string& configuration() const noexcept;
      
      /// @brief Initializes a new instance of the xtd::reflection::assembly_copyright_attribute class.
      /// @param copyright The copyright information.
      const string& copyright() const noexcept;
      
      /// @brief Gets culture information.
      /// @return A string containing the culture information.
      const string& culture() const noexcept;
      
      /// @brief Gets decription information.
      /// @return A string containing the decription information.
      const string& description() const noexcept;
      
      /// @brief Gets file version information.
      /// @return A string containing the file version information.
      const string& file_version() const noexcept;
      
      /// @brief Gets guid information.
      /// @return A string containing the guid information.
      const string& guid() const noexcept;
      
      /// @brief Gets identifier information.
      /// @return A string containing the identifier information.
      const string& identifier() const noexcept;
      
      /// @brief Gets the location of the executable file.
      /// @return A string containing the location_of the executable file.
      string location() const noexcept;
      
      /// @brief Gets name information.
      /// @return A string containing the name information.
      const string& name() const noexcept;
      
      /// @brief Gets product information.
      /// @return A string containing the product information.
      const string& product() const noexcept;

      /// @brief Gets the path for the executable file that started the application, not including the executable name.
      /// @return The path for the executable file that started the application.
      string location_path() const noexcept;

      /// @brief Gets title information.
      /// @return A string containing the title information.
      const string& title() const noexcept;
      
      /// @brief Gets trademark information.
      /// @return A string containing the trademark information.
      const string& trademarks() const noexcept;
      
      /// @brief Gets version information.
      /// @return A string containing the version information.
      const string& version() const noexcept;
      /// @}
      
      /// @name Static ethods
      
      /// @{
      /// @brief Gets the assembly that contains the code that is currently executing.
      /// @return The assembly that contains the code that is currently executing.
      static const assembly& get_executing_assembly() noexcept;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::reflection::assembly class.
      /// @remarks This constructor is invoked by derived classes during the construction of xtd::reflection::assembly objects.
      assembly() = default;
      /// @}
      
    private:
      string company_;
      string configuration_;
      string copyright_;
      string culture_;
      string description_;
      string file_version_;
      string guid_;
      string identifier_;
      string name_;
      string product_;
      string title_;
      string trademarks_;
      string version_;
    };
  }
}
