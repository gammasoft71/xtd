/// @file
/// @brief Contains process API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstdint>
#include <memory>
#include <string>
#include <tuple>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace diagnostics {
    class process;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains process native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ process final {
      friend xtd::diagnostics::process;
    protected:
      /// @brief Contains the created process hande and created standard streams :
      /// * [0] : The created process handle.
      /// * [1] : The created process id.
      /// * [2] : The created ostream for the standard input.
      /// * [3] : The created istream for the standard output.
      /// * [4] : The created istream for the standard error.
      using started_process = std::tuple<intptr_t, int32_t, std::unique_ptr<std::ostream>, std::unique_ptr<std::istream>, std::unique_ptr<std::istream>>;
      /// @brief Gets the base priority xof the associated process.
      /// @param priority The process handle.
      /// @return The base priority, which is computed from the process priority class of the associated process. (see prioritty_classs.h file).
      /// @remarks The following table shows the relationship between the base priority and process priority class values.
      /// | Windows base_priority | macOS base_priority                        | linux base_priority                        | priority_class              |
      /// |-----------------------|--------------------------------------------|--------------------------------------------|-----------------------------|
      /// | 4                     | PRIO_MIN                             (-20) | PRIO_MIN                             (-20) | IDLE_PRIORITY_CLASS         |
      /// | 6                     | PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4 (-10) | PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4 (-10) | BELOW_NORMAL_PRIORITY_CLASS |
      /// | 8                     | PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2     (0) | PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2     (0) | NORMAL_PRIORITY_CLASS       |
      /// | 10                    | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4  (10) | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4  (10) | ABOVE_NORMAL_PRIORITY_CLASS |
      /// | 13                    | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8  (15) | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8  (15) | HIGH_PRIORITY_CLASS         |
      /// | 24                    | PRIO_MAX                              (20) | PRIO_MAX                              (20) | REALTIME_PRIORITY_CLASS     |
      static int32_t base_priority(int32_t priority);
      /// @brief Kill process.
      /// @param process The process handle to kill.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool kill(intptr_t process);
      /// @brief Sets the overall priority category for the associated process.
      /// @param process The process handle to set priority class.
      /// @param priority The priority category for the associated process, from which the base_priority of the process is calculated. (see prioritty_classs.h file).
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool priority_class(intptr_t process, int32_t priority);
      /// @brief Creates a process with specified file name, specified arguments, specified working directory, specified process creation flags, and specified process window style.
      /// @param file_name the name of the application file to run in process launched by the shell execute.
      /// @param arguments Command-line arguments to pass when startinhg the process.
      /// @param mworking_directory The fully qualified name of the directory that contains the process to be started. The default is an empty string ("").
      /// @param process_window_style One of the values that indicates whether the process is started in a window that is maximized, minimized, normal (neither maximized nor minimized), or not visible. The default is Normal. (see process_window_window_style.h file).
      /// @return The created process handle.
      /// @warning Internal use only
      static intptr_t shell_execute(const std::string& verb, const std::string& file_name, const std::string& arguments, const std::string& working_directory, int32_t process_window_style);
      /// @brief Starts a process with specified file name, specified arguments, specified working directory, specified process window style, specified process creation flags, and specified boolean tuples that represent redirect standard streams.
      /// @param file_name the name of the application file to run in the process.
      /// @param arguments Command-line arguments to pass when startinhg the process.
      /// @param mworking_directory The working directory for the process to be started. The default is an empty string ("").
      /// @param process_window_style One of the values that indicates whether the process is started in a window that is maximized, minimized, normal (neither maximized nor minimized), or not visible. The default is Normal. (see process_window_window_style.h file).
      /// @param process_creation_flags One of the values that indicates whether the process is created. (see process_creation_flags.h file).
      /// @param redirect_standard_streams Tuple for redirect standard streams :
      /// * [0] : true if input should be read from standard_input; otherwise, false. The default is false.
      /// * [1] : true if input should be written to standard_output; otherwise, false. The default is false.
      /// * [2] : true if input should be written to standard_error; otherwise, false. The default is false.
      /// @return A process::started_process that contains the created process hande, id and created standard streams.
      /// @warning Internal use only
      static started_process start(const std::string& file_name, const std::string& arguments, const std::string& working_directory, int32_t process_window_style, int32_t process_creation_flags, std::tuple<bool, bool, bool> redirect_standard_streams);
      /// @brief Wait process and close handles.
      /// @param process The process handle to wait.
      /// @param exit Receives the process exit code.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool wait_process(intptr_t process, int32_t& exit_code);
      /// @brief Wait shell process and close handles.
      /// @param process The process handle to wait.
      /// @param exit Receives the process exit code.
      /// @return true if succeed; otherwise false.
      /// @warning Internal use only
      static bool wait_shell_execute(intptr_t process);
    };
  }
}
