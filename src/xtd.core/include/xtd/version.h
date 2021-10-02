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
  /// @include version_os.cpp
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
  /// You can use the xtd::version::compare_to method to determine whether one xtd::version object is earlier than, the same as, or later than a second xtd::version object. The following example indicates that xtd::version 2.1 is later than xtd::version 2.0.
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
  /// For two versions to be equal, the major, minor, build, and revision numbers of the first xtd::version object must be identical to those of the second xtd::version object. If the build or revision number of a xtd::version object is undefined, that xtd::version object is considered to be earlier than a xtd::vVersion object whose build or revision number is equal to zero. The following example illustrates this by comparing three xtd::version objects that have undefined version components.
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
    /// @remarks This constructor creates a xtd::version object with the following property values.
    /// | Property               | Value |
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
    version(const xtd::ustring& version);
    /// @brief Initializes a new instance of the xtd::version class using the specified major and minor values.
    /// @param major The major version number.
    /// @param minor The minor version number.
    /// @exception xtd::out_of_range_exception major or minor is less than zero.
    /// @remarks This constructor creates a xtd::version object with the following property values.
    /// | Property               | Value          |
    /// |------------------------|----------------|
    /// | xtd::version::major    | major          |
    /// | xtd::version::minor    | minor          |
    /// | xtd::version::build    | undefined (-1) |
    /// | xtd::version::revision | undefined (-1) |
    version(int32_t major, int32_t minor);
    /// @brief Initializes a new instance of the xtd::version class using the specified major, minor and build values.
    /// @param major The major version number.
    /// @param minor The minor version number.
    /// @param build The build version number.
    /// @exception xtd::out_of_range_exception major, minor or build is less than zero.
    /// @remarks This constructor creates a xtd::version object with the following property values.
    /// | Property               | Value          |
    /// |------------------------|----------------|
    /// | xtd::version::major    | major          |
    /// | xtd::version::minor    | minor          |
    /// | xtd::version::build    | build          |
    /// | xtd::version::revision | undefined (-1) |
    version(int32_t major, int32_t minor, int32_t build);
    /// @brief Initializes a new instance of the xtd::version class using the specified major, minor, build and revision values.
    /// @param major The major version number.
    /// @param minor The minor version number.
    /// @param build The build version number.
    /// @param revision The revision version number.
    /// @exception xtd::out_of_range_exception major, minor, build or revision is less than zero.
    /// @remarks This constructor creates a xtd::version object with the following property values.
    /// | Property               | Value    |
    /// |------------------------|----------|
    /// | xtd::version::major    | major    |
    /// | xtd::version::minor    | minor    |
    /// | xtd::version::build    | build    |
    /// | xtd::version::revision | revision |
    /// @par Examples
    /// The following code example demonstrates the xtd::version constructor, and xtd::version::major, xtd::version::minor, xtd::version::build, xtd::version::revision, xtd::version::major_revision, and xtd::version::minor_revision properties.
    /// @include version.cpp
    version(int32_t major, int32_t minor, int32_t build, int32_t revision);

    /// @cond
    version(const version&) noexcept = default;
    version& operator=(const version&) noexcept = default;
    
    bool operator==(const version& v) const noexcept;
    bool operator!=(const version& v) const noexcept;
    /// @endcond

    /// @brief Gets the value of the build component of the version number for the current xtd::version object.
    /// @return The build number, or -1 if the build number is undefined.
    /// @remarks For example, if the version number is 6.2.1.3, the build number is 1. If the version number is 6.2, the build number is undefined.
    int32_t build() const noexcept;
    
    /// @brief Gets the value of the major component of the version number for the current xtd::version object.
    /// @return The major version number.
    /// @remarks For example, if the version number is 6.2, the major version is 6.
    int32_t major() const noexcept;
    
    /// @brief Gets the high 16 bits of the revision number.
    /// @return A 16-bit signed integer.
    /// @remarks Suppose you release an interim version of your application to temporarily correct a problem until you can release a permanent solution. The temporary version does not warrant a new revision number, but it does need to be identified as a different version. In this case, encode the identification information in the high and low 16-bit portions of the 32-bit revision number. Use the xtd::version::revision property to obtain the entire revision number, use the xtd::version::major_revision property to obtain the high 16 bits, and use the xtd::version::minor_revision property to obtain the low 16 bits.
    int16_t major_revision() const noexcept;
    
    /// @brief Gets the value of the minor component of the version number for the current xtd::version object.
    /// @return The minor version number.
    /// @remarks For example, if the version number is 6.2, the minor version is 2.
    int32_t minor() const noexcept;
    
    /// @brief Gets the low 16 bits of the revision number.
    /// @return A 16-bit signed integer.
    /// @remarks Suppose you release an interim version of your application to temporarily correct a problem until you can release a permanent solution. The temporary version does not warrant a new revision number, but it does need to be identified as a different version. In this case, encode the identification information in the high and low 16-bit portions of the 32-bit revision number. Use the xtd::version::revision property to obtain the entire revision number, use the xtd::version::major_revision property to obtain the high 16 bits, and use the xtd::version::minor_revision property to obtain the low 16 bits.
    int16_t minor_revision() const noexcept;
    
    /// @brief Gets the value of the revision component of the version number for the current xtd::version object.
    /// @return The revision number, or -1 if the revision number is undefined.
    /// @remarks For example, if the version number is 6.2.1.3, the revision number is 3. If the version number is 6.2, the revision number is undefined.
    int32_t revision() const noexcept;

    /// @brief Compares the current xtd::version object to a specified object and returns an indication of their relative values.
    /// @param version An object to compare.
    /// @return A signed integer that indicates the relative values of the two objects, as shown in the following table.
    /// | Return value      | Meaning                                                                                                       |
    /// |-------------------|---------------------------------------------------------------------------------------------------------------|
    /// | Less than zero    | The current xtd::version object is a version before version.                                                  |
    /// | Zero              | The current xtd::version object is the same version as version.                                               |
    /// | Greater than zero | The current xtd::version object is a version subsequent to version or version is not ta xtd::version object. |
    /// @remarks The components of Version in decreasing order of importance are: major, minor, build, and revision. An unknown component is assumed to be older than any known component.
    /// For example:
    /// * xtd::version 1.1 is older than version 1.1.0
    /// * xtd::version 1.1 is older than version 1.1.1
    /// * xtd::version 1.1 is older than version 1.1.2.3
    /// * xtd::version 1.1.2 is older than version 1.1.2.4
    /// * xtd::version 1.2.5 is newer than version 1.2.3.4
    int32_t compare_to(const object& version) const noexcept override;
    /// @brief Compares the current xtd::version object to a specified object and returns an indication of their relative values.
    /// @param version An object to compare.
    /// @return A signed integer that indicates the relative values of the two objects, as shown in the following table.
    /// | Return value      | Meaning                                                              |
    /// |-------------------|----------------------------------------------------------------------|
    /// | Less than zero    | The current xtd::version object is a version before version.         |
    /// | Zero              | The current xtd::version object is the same version as version.      |
    /// | Greater than zero | The current xtd::version object is a version subsequent to version. |
    /// @remarks The components of Version in decreasing order of importance are: major, minor, build, and revision. An unknown component is assumed to be older than any known component.
    /// For example:
    /// * xtd::version 1.1 is older than version 1.1.0
    /// * xtd::version 1.1 is older than version 1.1.1
    /// * xtd::version 1.1 is older than version 1.1.2.3
    /// * xtd::version 1.1.2 is older than version 1.1.2.4
    /// * xtd::version 1.2.5 is newer than version 1.2.3.4
    int32_t compare_to(const version& version) const noexcept override;

    /// @brief Converts the string representation of a version number to an equivalent Version object.
    /// @param input A string that contains a version number to convert.
    /// @return An object that is equivalent to the version number specified in the input parameter.
    /// @exception xtd::argument_out_of_range_exception A major, minor, build, or revision component is less than zero.
    /// @exception xtd::format_exception At least one component of input does not parse to an integer.
    /// @exception xtd::overflow_exception At least one component of input represents a number greater than std::numeric_limits<int32_t>::max().
    /// @remarks The input parameter must have the following format:
    /// @verbatim major.minor[.build[.revision]] @endverbatim
    /// @remarks where major, minor, build, and revision are the string representations of the version number's four components: major version number, minor version number, build number, and revision number, respectively. Optional components are shown in square brackets ([ and ]). The components must appear in the specified order and must be separated by periods
    /// @warning Because the string representation of a version number must conform to a recognized pattern, applications should always use exception handling when calling the xtd::version::parse method to parse user input. Alternatively, you can call the xtd::version::try_parse method to parse the string representation of a version number and return a value that indicates whether the parse operation succeeded.
    /// @remarks The xtd::version::parse method is a convenience method; it is equivalent to calling the xtd::version(const ustring&) constructor.
    static version parse(const xtd::ustring& input);
    
    /// @brief Converts the value of the current xtd::version object to its equivalent xtd::ustring representation.
    /// @return The xtd::ustring representation of the values of the major, minor, build, and revision components of the current xtd::version object, as depicted in the following format. Each component is separated by a period character ('.'). Square brackets ('[' and ']') indicate a component that will not appear in the return value if the component is not defined:
    /// @verbatim major.minor[.build[.revision]] @endverbatim
    /// For example, if you create a xtd::version object using the constructor xtd::version(1, 1), the returned string is "1.1". If you create a xtd::version object using the constructor xtd::version(1, 3, 4, 2), the returned string is "1.3.4.2".
    xtd::ustring to_string() const noexcept override;
    /// @brief Converts the value of the current xtd::version object to its equivalent xtd::ustring representation. A specified count indicates the number of components to return.
    /// @param field_count The number of components to return. The field_count ranges from 0 to 4.
    /// @return The xtd::ustring representation of the values of the major, minor, build, and revision components of the current xtd::version object, each separated by a period character ('.'). The field_count parameter determines how many components are returned.
    /// | field_count | Return Value               |
    /// |-------------|----------------------------|
    /// | 0           | An empty string ("").      |
    /// | 1           | major                      |
    /// | 2           | major.minor                |
    /// | 3           | major.minor.build          |
    /// | 4           | major.minor.build.revision |
    /// For example, if you create xtd::version object using the constructor xtd::version(1,3,5), xtd::version::to_string(2) returns "1.3" and xtd::version::to_string(4) throws an exception.
    /// @exception xtd::argument_exception field_count is more than 4 -or- field_count is more than the number of components defined in the current xtd::version object.
    xtd::ustring to_string(size_t field_count) const;
    
    /// @brief Tries to convert the string representation of a version number to an equivalent xtd::version object, and returns a value that indicates whether the conversion succeeded.
    /// @param input A string that contains a version number to convert.
    /// @param result When this method returns, contains the xtd::version equivalent of the number that is contained in input, if the conversion succeeded. If input is empty, or if the conversion fails, result is empty when the method returns.
    /// @return true if the input parameter was converted successfully; otherwise, false.
    /// @remarks The xtd::version::try_parse method is similar to the xtd::version::parse method, except that it doesn't throw an exception if the conversion fails. Instead, it returns false if input is null, has fewer than two or more than four components, has at least one component that is not an integer, has at least one component that is less than zero, or has at least one component that is greater than std::numeric_limits<int32_t>::max().
    /// For the parse operation to succeed, the input parameter must be in the following format:
    /// @verbatim major.minor[.build[.revision]] @endverbatim
    /// where major, minor, build, and revision are the string representations of the version number's four components: major version number, minor version number, build number, and revision number, respectively. Optional components are shown in square brackets ([ and ]). The components must appear in order and must be separated by periods.
    static bool try_parse(const xtd::ustring& input, version& result) noexcept;

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
