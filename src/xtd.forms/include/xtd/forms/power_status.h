/// @file
/// @brief Contains xtd::forms::power_status class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export"
#include "battery_charge_status"
#include "power_line_status"
#include <xtd/object>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class system_information;
    /// @endcond
    
    /// @brief Indicates current system power status information.
    /// @par Header
    /// @code #include <xtd/forms/power_status> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The xtd::forms::power_status class represents information about the current AC line power status, battery charging status, and battery charge status.
    /// @remarks This class is used by the xtd::forms::system_information::power_status property of the xtd::forms::system_information class to indicate current system power information.
    class forms_export_ power_status : public object {
    public:
      /// @cond
      power_status() = default;
      power_status(const power_status&) = default;
      power_status& operator =(const power_status&) = default;
      /// @endcond
      
      /// @name Peorperties
      
      /// @{
      /// @brief Gets the current battery charge status.
      /// @return One of the xtd::forms::battery_charge_status values indicating the current battery charge level or charging status.
      /// @remarks This property indicates the current battery charge level or battery charging status.
      xtd::forms::battery_charge_status battery_charge_status() const noexcept;
      
      /// @brief Gets the reported full charge lifetime of the primary battery power source in seconds.
      /// @return The reported number of seconds of battery life available when the battery is fully charged, or -1 if the battery life is unknown.
      int32 battery_full_life_time() const noexcept;
      
      /// @brief Gets the approximate amount of full battery charge remaining.
      /// @return The approximate amount, from 0.0 to 1.0, of full battery charge remaining.
      float battery_life_percent() const noexcept;
      
      /// @brief Gets the approximate number of seconds of battery time remaining.
      /// @return The approximate number of seconds of battery life remaining, or -1 if the approximate remaining battery life is unknown.
      int32 battery_life_remaining() const noexcept;
      
      /// @brief Gets the current system power status.
      /// @return One of the xtd::forms::power_line_status values indicating the current system power status.
      /// @remarks This property indicates whether the system power is online, or that the system power status is unknown.
      xtd::forms::power_line_status power_line_status() const noexcept;
      /// @}
      
    private:
      friend class system_information;
      power_status(xtd::forms::battery_charge_status battery_charge_status, int32 battery_full_life_time, float battery_life_percent, int32 battery_life_remaining, xtd::forms::power_line_status power_line_status);
      xtd::forms::battery_charge_status battery_charge_status_ = xtd::forms::battery_charge_status::unknown;
      int32 battery_full_life_time_ = -1;
      float battery_life_percent_ = 1.0f;
      int32 battery_life_remaining_ = -1;
      xtd::forms::power_line_status power_line_status_ = xtd::forms::power_line_status::unknown;
    };
  }
}
