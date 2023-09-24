/// @file
/// @brief Contains xtd::program_exit_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "event_args"
#include "exit_mode"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides data for the environment program exit event. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  class program_exit_event_args final : public xtd::event_args {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the program_exit_event_args class.
    program_exit_event_args() = default;
    
    /// @brief Initializes a new instance of the program_exit_event_args class.
    /// @param signal One of the enumeration values that specifies the key combination that interrupted the current process. There is no default value..
    explicit program_exit_event_args(xtd::exit_mode exit_mode) : exit_mode_(exit_mode) {}
    /// @}
    
    /// @cond
    program_exit_event_args(const program_exit_event_args&) = default;
    program_exit_event_args& operator =(const program_exit_event_args&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets the exit mode.
    /// @return One of the xtd::exit_mode enumeration values.
    xtd::exit_mode exit_mode() const noexcept {return exit_mode_;}
    /// @}
    
  private:
    xtd::exit_mode exit_mode_ = xtd::exit_mode::normal;
  };
}
