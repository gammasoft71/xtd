/// @file
/// @brief Contains xtd::version class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "icomparable.h"
#include "ustring.h"

/// @cond
#undef major
#undef minor
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the version number of an assembly, operating system, or the xtd. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to use xtd::version to get the version of the Operating System.
  /// @include version.cpp
  /// @remarks xtd::version numbers consist of two to four components: major, minor, build, and revision. The major and minor components are required; the build and revision components are optional, but the build component is required if the revision component is defined. All defined components must be integers greater than or equal to 0. The format of the version number is as follows (optional components are shown in square brackets ([ and ]):
  /// @verbatim major.minor[.build[.revision]] @endverbatim
  /// @remarks The components are used by convention as follows:
  /// * major: Assemblies with the same name but different major versions are not interchangeable. A higher version number might indicate a major rewrite of a product where backward compatibility cannot be assumed.
  /// * minor: If the name and major version number on two assemblies are the same, but the minor version number is different, this indicates significant enhancement with the intention of backward compatibility. This higher minor version number might indicate a point release of a product or a fully backward-compatible new version of a product.
  /// * build: A difference in build number represents a recompilation of the same source. Different build numbers might be used when the processor, platform, or compiler changes.
  /// * revision: Assemblies with the same name, major, and minor version numbers but different revisions are intended to be fully interchangeable. A higher revision number might be used in a build that fixes a security hole in a previously released assembly.
  /// @remarks Subsequent versions of an assembly that differ only by build or revision numbers are considered to be Hotfix updates of the prior version.
  /// @warning The value of xtd::version properties that have not been explicitly assigned a value is undefined (-1).
  /// @par Retrieving Version Information
  /// xtd::version objects are most frequently used to store version information about some system or application component (such as the operating system), the common language runtime, the current application's executable, or a particular assembly. The following examples illustrate some of the most common scenarios:
  /// * Retrieving the operating system version. The following example uses the xtd::operating_system::version property to retrieve the version number of the operating system.
  /// @code
  /// // Get the operating system version.
  /// operating_system os = environment::os_version();
  /// version ver = os.version();
  /// console::write_line("Operating System: {0} ({1})", os.version_string(), ver.to_string());
  /// @endcode
  /// * Retrieving the version of xtd. The following example uses the xtd::environment::version property to retrieve version information about xtd.
  /// @code
  /// // Get the xtd version.
  /// version ver = environment::version();
  /// console::write_line("xtd version {0}", ver.to_string());
  /// @endcode
  /// @par Comparing xtd::version objects
  /// You can use the xtd::version::compare_to method to determine whether one xtd::version object is earlier than, the same as, or later than a secondxtd::version object. The following example indicates that xtd::version 2.1 is later than xtd::version 2.0.
  /// @code
  /// version v1(2, 0);
  /// version v2("2.1");
  /// console::write("version {0} is ", v1);
  /// switch(v1.compare_to(v2)) {
  ///   case 0: console::write("the same as"); break;
  ///   case 1: console::write("later than"); break;
  ///   case -1: console::write("earlier than"); break;
  /// }
  /// console::write_line(" version {0}.", v2);
  /// // The example displays the following output:
  /// //       version 2.0 is earlier than version 2.1.
  /// @endcode
  /// For two versions to be equal, the major, minor, build, and revision numbers of the first xttd::version object must be identical to those of the second xtd::version object. If the build or revision number of a xtd::version object is undefined, that Vxtd::version object is considered to be earlier than a xttd::vVersion object whose build or revision number is equal to zero. The following example illustrates this by comparing three xtd::version objects that have undefined version components.
  /// @code
  ///
  /// using namespace xtd;
  ///
  /// enum class version_time {earlier = -1, same = 0, later = 1 };
  ///
  /// std::ostream& operator<<(std::ostream& os, version_time value) {return os << to_string(value, {{version_time::earlier, "earlier"}, {version_time::same, "same"}, {version_time::later, "later"}});}
  ///
  /// class example {
  /// public:
  ///   static void main() {
  ///     version v1(1, 1);
  ///     version v1a("1.1.0");
  ///     show_relationship(v1, v1a);
  ///
  ///     version v1b(1, 1, 0, 0);
  ///     show_relationship(v1b, v1a);
  ///   }
  /// private:
  ///   static void show_relationship(const version& v1, const version& v2) {
  ///     console::write_line("Relationship of {0} to {1}: {2}", v1, v2, as<version_time>(v1.compare_to(v2)));
  ///   }
  /// };
  ///
  /// startup_(example);
  /// // The example displays the following output:
  /// //       Relationship of 1.1 to 1.1.0: earlier
  /// //       Relationship of 1.1.0.0 to 1.1.0: later
  /// @endcode
  class version final : public object, public icomparable<version> {
  public:
    /// @brief Initializes a new instance of the xtd::version class.
    /// @remarks This constructor creates a xttd::ersion object with the following property values.
    /// | Properrty              | Value |
    /// |------------------------|-------|
    /// | xtd::version::major    | 0     |
    /// | xtd::version::minor    | 0     |
    /// | xtd::version::build    | -1    |
    /// | xtd::version::revision | -1    |
    version() noexcept = default;
    /// @brief Initializes a new instance of the xtd::version class using the specified string.
    /// @param version A string containing the major, minor, build, and revision numbers, where each number is delimited with a period character ('.').
    /// @exception xtd::argument_exception version has fewer than two components or more than four components.
    /// @exception xtd::argument_out_of_range_exception A major, minor, build, or revision component is less than zero.
    /// @exception xtd::format_exception At least one component of version does not parse to an integer.
    /// @exception xtd::overflow_exception At least one component of version represents a number greater than std::numeric_limits<int32_t>::max().
    /// @remarks The version parameter can contain only the components major, minor, build, and revision, in that order, and all separated by periods. There must be at least two components, and at most four. The first two components are assumed to be major and minor. The value of unspecified components is undefined.
    /// @remarks The format of the version number is as follows. Optional components are shown in square brackets ('[' and ']'):
    /// @verbatim major.minor[.build[.revision]] @endverbatim
    /// @remarks All defined components must be integers greater than or equal to 0. For example, if the major number is 6, the minor number is 2, the build number is 1, and the revision number is 3, then version should be "6.2.1.3".
    version(const xtd::ustring& verion);
    version(int32_t major, int32_t minor);
    version(int32_t major, int32_t minor, int32_t build);
    version(int32_t major, int32_t minor, int32_t build, int32_t revision);

    /// @cond
    version(const version&) noexcept = default;
    version& operator=(const version&) noexcept = default;
    
    bool operator==(const version& v) const noexcept;
    bool operator!=(const version& v) const noexcept;
    /// @endcond

    int32_t build() const noexcept;
    
    int32_t major() const noexcept;
    
    int16_t major_revision() const noexcept;
    
    int32_t minor() const noexcept;
    
    int16_t mainor_revision() const noexcept;
    
    int32_t revision() const noexcept;

    int32_t compare_to(const object& obj) const noexcept override;
    
    int32_t compare_to(const version& value) const noexcept override;

    static version parse(const xtd::ustring& ver);
    
    static bool try_parse(const xtd::ustring& ver, version& result) noexcept;
    
    xtd::ustring to_string() const noexcept override;
    
    xtd::ustring to_string(size_t field_count) const;
    
  private:
    int32_t major_ = 0;
    int32_t minor_ = 0;
    int32_t build_ = -1;
    int32_t revision_ = -1;
  };

  /// @cond
  std::ostream& operator <<(std::ostream& os, const version& ver) noexcept;
  /// @endcond
}
