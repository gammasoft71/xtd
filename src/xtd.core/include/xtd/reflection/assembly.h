/// @file
/// @brief Contains xtd::reflection::assembly class.
#pragma once
#include "../object.h"
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Represents an assembly, which is a reusable, versionable, and self-describing building block of an application.
    /// @code
    /// class assembly : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::reflection::assembly
    /// @par Header
    /// @code #include <xtd/reflection/assembly> @endcode
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
      const ustring& company() const noexcept;
      
      /// @brief Gets assembly configuration information.
      /// @return A string containing the assembly configuration information.
      const ustring& configuration() const noexcept;
      
      /// @brief Initializes a new instance of the xtd::reflection::assembly_copyright_attribute class.
      /// @param copyright The copyright information.
      const ustring& copyright() const noexcept;
      
      /// @brief Gets culture information.
      /// @return A string containing the culture information.
      const ustring& culture() const noexcept;
      
      /// @brief Gets decription information.
      /// @return A string containing the decription information.
      const ustring& description() const noexcept;
      
      /// @brief Gets file version information.
      /// @return A string containing the file version information.
      const ustring& file_version() const noexcept;
      
      /// @brief Gets guid information.
      /// @return A string containing the guid information.
      const ustring& guid() const noexcept;
      
      /// @brief Gets identifier information.
      /// @return A string containing the identifier information.
      const ustring& identifier() const noexcept;
      
      /// @brief Gets name information.
      /// @return A string containing the name information.
      const ustring& name() const noexcept;
      
      /// @brief Gets product information.
      /// @return A string containing the product information.
      const ustring& product() const noexcept;
      
      /// @brief Gets title information.
      /// @return A string containing the title information.
      const ustring& title() const noexcept;
      
      /// @brief Gets trademark information.
      /// @return A string containing the trademark information.
      const ustring& trademarks() const noexcept;
      
      /// @brief Gets version information.
      /// @return A string containing the version information.
      const ustring& version() const noexcept;
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
      ustring company_;
      ustring configuration_;
      ustring copyright_;
      ustring culture_;
      ustring description_;
      ustring file_version_;
      ustring guid_;
      ustring identifier_;
      ustring name_;
      ustring product_;
      ustring title_;
      ustring trademarks_;
      ustring version_;
    };
  }
}
