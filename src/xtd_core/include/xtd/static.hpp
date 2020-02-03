#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a static class. A static class can't be instancied (constructors are deleted).
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// class foo : public static_class {
  /// public:
  ///   static std::string to_string() {return "foo";}
  /// };
  /// @endcode
  class static_class {
    static_class() = delete;
  };

  /// @brief This keyword is use to represent a static class. A static class can't be instancied (constructors are deleted).
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// class foo static_ {
  /// public:
  ///   static std::string to_string() {return "foo";}
  /// };
  /// @endcode
  /// @ingroup keywords
  #define static_ \
    final : xtd::static_class

  /// @brief This keyword is use to represent a static class. A static class can't be instancied (constructors are deleted).
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// class foo static_class_ {
  /// public:
  ///   static std::string to_string() {return "foo";}
  /// };
  /// @endcode
  /// @ingroup keywords
  #define static_class_ \
    final : xtd::static_class
}
