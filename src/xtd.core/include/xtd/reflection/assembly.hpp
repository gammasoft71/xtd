/// @file
/// @brief Contains xtd::reflection::assembly class.
#pragma once
#include "../iequatable.hpp"
#include "../object.hpp"
#include "../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::reflection namespace contains types that retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata. These types also can be used to manipulate instances of loaded types, for example to hook up events or to invoke methods. To dynamically create types, use the System.Reflection.Emit namespace.
  namespace reflection {
    /// @brief Represents an assembly, which is a reusable, versionable, and self-describing building block of an application.
    /// ```cpp
    /// class core_export_ assembly : public xtd::object, public xtd::iequatable<xtd::reflection::assembly>;
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
    class core_export_ assembly : public xtd::object, public xtd::iequatable<xtd::reflection::assembly> {
    public:
      /// @cond
      assembly(assembly&&) = default;
      assembly(const assembly&) = default;
      auto operator =(assembly&&) -> assembly& = default;
      auto operator =(const assembly&) -> assembly& = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets company name information.
      /// @return A string containing the company name.
      [[nodiscard]] auto company() const noexcept -> const xtd::string&;
      
      /// @brief Gets assembly configuration information.
      /// @return A string containing the assembly configuration information.
      [[nodiscard]] auto configuration() const noexcept -> const xtd::string&;
      
      /// @brief Initializes a new instance of the xtd::reflection::assembly_copyright_attribute class.
      /// @param copyright The copyright information.
      [[nodiscard]] auto copyright() const noexcept -> const xtd::string&;
      
      /// @brief Gets culture information.
      /// @return A string containing the culture information.
      [[nodiscard]] auto culture() const noexcept -> const xtd::string&;
      
      /// @brief Gets decription information.
      /// @return A string containing the decription information.
      [[nodiscard]] auto description() const noexcept -> const xtd::string&;
      
      /// @brief Gets file_name information.
      /// @return A string containing the file_name information.
      [[nodiscard]] auto file_name() const noexcept -> xtd::string;
      
      /// @brief Gets file version information.
      /// @return A string containing the file version information.
      [[nodiscard]] auto file_version() const noexcept -> const xtd::string&;
      
      /// @brief Gets guid information.
      /// @return A string containing the guid information.
      [[nodiscard]] auto guid() const noexcept -> const xtd::string&;
      
      /// @brief Gets identifier information.
      /// @return A string containing the identifier information.
      [[nodiscard]] auto identifier() const noexcept -> const xtd::string&;
      
      /// @brief Gets the location of the executable file.
      /// @return A string containing the location_of the executable file.
      [[nodiscard]] auto location() const noexcept -> xtd::string;
      
      /// @brief Gets the path for the executable file that started the application, not including the executable name.
      /// @return The path for the executable file that started the application.
      [[nodiscard]] auto location_path() const noexcept -> xtd::string;
      
      /// @brief Gets name information.
      /// @return A string containing the name information.
      [[nodiscard]] auto name() const noexcept -> const xtd::string&;
      
      /// @brief Gets name or file_name if empty information.
      /// @return A string containing the name or file_name if empty information.
      [[nodiscard]] auto name_or_file_name() const noexcept -> xtd::string;
      
      /// @brief Gets product information.
      /// @return A string containing the product information.
      [[nodiscard]] auto product() const noexcept -> const xtd::string&;
      
      /// @brief Gets title information.
      /// @return A string containing the title information.
      [[nodiscard]] auto title() const noexcept -> const xtd::string&;
      
      /// @brief Gets trademark information.
      /// @return A string containing the trademark information.
      [[nodiscard]] auto trademark() const noexcept -> const xtd::string&;
      
      /// @brief Gets version information.
      /// @return A string containing the version information.
      [[nodiscard]] auto version() const noexcept -> const xtd::string&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const assembly& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::size override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets the assembly that contains the code that is currently executing.
      /// @return The assembly that contains the code that is currently executing.
      [[nodiscard]] static auto get_executing_assembly() noexcept -> const assembly&;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::reflection::assembly class.
      /// @remarks This constructor is invoked by derived classes during the construction of xtd::reflection::assembly objects.
      assembly() = default;
      /// @}
      
    private:
      xtd::string company_;
      xtd::string configuration_;
      xtd::string copyright_;
      xtd::string culture_;
      xtd::string description_;
      xtd::string file_version_;
      xtd::string guid_;
      xtd::string identifier_;
      xtd::string name_;
      xtd::string product_;
      xtd::string title_;
      xtd::string trademarks_;
      xtd::string version_;
    };
  }
}
