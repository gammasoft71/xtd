/// @file
/// @brief Contains xtd::diagnostics::process class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "process_start_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides access to local and remote processes and enables you to start and stop local system processes.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics
    /// @remarks A xtd::diagnostics::process component provides access to a process that is running on a computer. A process, in the simplest terms, is a running app. A thread is the basic unit to which the operating system allocates processor time. A thread can execute any part of the code of the process, including parts currently being executed by another thread.
    /// @remarks The xtd::diagnostics::process component is a useful tool for starting, stopping, controlling, and monitoring apps. You can use the xtd::diagnostics::process component, to obtain a list of the processes that are running, or you can start a new process. A Process component is used to access system processes. After a xtd::diagnostics::process component has been initialized, it can be used to obtain information about the running process. Such information includes the set of threads, the loaded modules (.dll and .exe files), and performance information such as the amount of memory the process is using.
    /// @note 32-bit processes cannot access the modules of a 64-bit process. If you try to get information about a 64-bit process from a 32-bit process, you will get a Win32Exception exception. A 64-bit process, on the other hand, can access the modules of a 32-bit process.
    /// @remarks The xtd::diagnostics::process component obtains information about a group of properties all at once. After the xtd::diagnostics::process component has obtained information about one member of any group, it will cache the values for the other properties in that group and not obtain new information about the other members of the group until you call the xtd::diagnostics::process::refresh method. Therefore, a property value is not guaranteed to be any newer than the last call to the xtd::diagnostics::process::refresh method. The group breakdowns are operating-system dependent.
    /// @remarks If you have a path variable declared in your system using quotes, you must fully qualify that path when starting any process found in that location. Otherwise, the system will not find the path. For example, if c:\mypath is not in your path, and you add it using quotation marks: path = %path%;"c:\mypath", you must fully qualify any process in c:\mypath when starting it.
    /// @remarks A system process is uniquely identified on the system by its process identifier. Like many Windows resources, a process is also identified by its handle, which might not be unique on the computer. A handle is the generic term for an identifier of a resource. The operating system persists the process handle, which is accessed through the Handle property of the Process component, even when the process has exited. Thus, you can get the process's administrative information, such as the xtd::diagnostics::process::exit_code (usually either zero for success or a nonzero error code) and the xtd::diagnostics::process::exit_time. xtd::diagnostics::process::handles are an extremely valuable resource, so leaking handles is more virulent than leaking memory.
    class core_export_ process final {
    public:
      process() = default;
      process(const process&) = default;
      process& operator=(const process&) = default;

      intptr_t handle() const {return data_->handle_;}
      
      process_start_info start_info() const {return data_->start_info_;}
      process& start_info(process_start_info value) {
        data_->start_info_ = value;
        return *this;
      }

      process&  kill();

      static process start(const process_start_info& start_info);
      static process start(const std::string& file_name) {return start(process_start_info(file_name));}
      static process start(const std::string& file_name, const std::string& arguments) {return start(process_start_info(file_name, arguments));}

      process& wait_for_exit();
      
    private:
      struct data {
        intptr_t handle_ = 0;
        process_start_info start_info_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
