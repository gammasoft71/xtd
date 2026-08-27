/// @file
/// @brief Contains xtd::exit_status enum class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "enum.hpp"
//#include <cstdlib>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies exit status for the xtd::environment::exit method.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks Each of the above values represents a constant, which represent different exit status of to the program.
  /// @remarks For more information about exit_status, see [EXIT_status](https://en.cppreference.com/w/cpp/utility/program/EXIT_status.html).
  enum class exit_status {
    /// @brief Successful execution of a program. Is equal to [EXIT_SUCCESS](https://en.cppreference.com/w/cpp/utility/program/EXIT_status.html).
    success = 0,
    /// @brief Unsuccessful execution of a program. Is equal to [EXIT_FAILURE](https://en.cppreference.com/w/cpp/utility/program/EXIT_status.html).
    failure = 1,
    /// @brief Command line usage error (e.g., wrong arguments).
    usage = 64,
    /// @brief< Input data was incorrect or malformed.
    data_err = 65,
    /// @brief Input file was not found or unreadable.
    no_input = 66,
    /// @brief Specified user or entity was not found.
    no_user = 67,
    /// @brief Specified host or server was not found.
    no_host = 68,
    /// @brief External service or resource is temporarily unavailable.
    unavailable = 69,
    /// @brief Internal software logic or runtime error.
    software = 70,
    /// @brief Operating system error (e.g., cannot fork or create thread).
    os_err = 71,
    /// @brief Missing or inaccessible critical system file.
    os_file = 72,
    /// @brief Cannot create the requested output file.
    cant_create = 73,
    /// @brief Input/Output (I/O) error during read/write.
    io_err = 74,
    /// @brief Temporary failure (invites the user to retry later).
    temp_fail = 75,
    /// @brief Network protocol or data exchange error.
    protocol = 76,
    /// @brief Permission denied for the requested operation.
    noperm = 77,
    /// @brief Configuration file is corrupted or invalid.
    config = 78,
    /// @brief Uncategorized critical error (upper safety bound).
    unknown_fatal = 125
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::exit_status> {
  static auto values() noexcept {return xtd::enum_collection<xtd::exit_status> {{xtd::exit_status::success, "success"}, {xtd::exit_status::failure, "failure"}, {xtd::exit_status::usage, "usage"}, {xtd::exit_status::data_err, "data_err"}, {xtd::exit_status::no_input, "no_input"}, {xtd::exit_status::no_user, "no_user"}, {xtd::exit_status::no_host, "no_host"}, {xtd::exit_status::unavailable, "unavailable"}, {xtd::exit_status::software, "software"}, {xtd::exit_status::os_err, "os_err"}, {xtd::exit_status::os_file, "os_file"}, {xtd::exit_status::cant_create, "cant_create"}, {xtd::exit_status::io_err, "io_err"}, {xtd::exit_status::temp_fail, "temp_fail"}, {xtd::exit_status::protocol, "protocol"}, {xtd::exit_status::noperm, "noperm"}, {xtd::exit_status::config, "config"}, {xtd::exit_status::unknown_fatal, "unknown_fatal"}};}
};
/// @endcond
