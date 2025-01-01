/// @file
/// @brief Contains xtd::event_args event args.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "core_export.hpp"
#include "object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the base class for classes that contain event data, and provides a value to use for events that do not include event data.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  /// @remarks This class serves as the base class for all classes that represent event data. For example, the xtd::forms::form_closing_event_args class derives from event_args and is used to hold information when form closing. To create a custom event data class, create a class that derives from the event_args class and provide the properties to store the necessary data. The name of your custom event data class should end with _event_args.
  /// @remarks To pass an object that does not contain any data, use the empty field.
  class core_export_ event_args : public object {
  public:
    /// @name Public Fields
    
    /// @{
    /// @brief Provides a value to use with events that do not have event data.
    /// @remarks Pass this value to event handlers that are associated with events that do not have data.
    static const event_args empty;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the event_args class.
    /// @remarks To pass an object that does not contain any data, use the empty field.
    event_args() = default;
    /// @}
  };
}
