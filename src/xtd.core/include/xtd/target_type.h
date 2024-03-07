/// @file
/// @brief Contains xtd::target_type class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "object.h"
#include "target_id.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about target type, such as the target identifier. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks This class is used by xtd::environment::target_type method.
  class target_type : public object {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialise a new xtd::target_type class.
    /// @param target_id One of xtd::target_id values.
    target_type(xtd::target_id target_id);
    /// @}
    
    /// @cond
    target_type() = default;
    target_type(const target_type&) = default;
    target_type& operator =(const target_type&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets target id is console application.
    /// @return true if target id is console application; otherwise false.
    bool is_console_application() const noexcept;
    
    /// @brief Gets target id is gui application.
    /// @return true if target id is gui application; otherwise false.
    bool is_guid_application() const noexcept;
    
    /// @brief Gets target id is test application.
    /// @return true if target id is test application; otherwise false.
    bool is_test_application() const noexcept;
    
    /// @brief Gets target id is shared library.
    /// @return true if target id is shared library; otherwise false.
    bool is_shared_library() const noexcept;
    
    /// @brief Gets target id is static library.
    /// @return true if target id is static library; otherwise false.
    bool is_static_library() const noexcept;
    
    /// @brief Gets target id name.
    /// @return The target id name.
    ustring name() const noexcept;
    
    /// @brief Gets target id value.
    /// @return One of xtd::target_id values.
    xtd::target_id target_id() const noexcept;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    ustring to_string() const noexcept override;
    /// @}
    
  private:
    xtd::target_id target_id_ = xtd::target_id::unknown;
  };
}
