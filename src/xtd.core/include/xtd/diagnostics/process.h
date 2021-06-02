/// @file
/// @brief Contains xtd::diagnostics::process class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../event.h"
#include "../event_handler.h"
#include "process_start_info.h"
#include <chrono>
#include <thread>

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
      struct data {
        intptr_t handle_ = 0;
        process_start_info start_info_;
        std::thread thread_;
        std::chrono::system_clock::time_point start_time_;
        std::chrono::system_clock::time_point exit_time_;
        int32_t exit_code_ = 0;
        event_handler<process> exit_callback_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
      
    public:
      class event_process : protected event_handler<process> {
        friend process;
        event_process(data* data) : event_handler<process>(), data_(data) {}
        void set_data(data* data) {data_ = data;}

      public:        
        bool is_empty() const noexcept { return event_handler<process>::is_empty(); }
        
        event_handler<process>& operator+=(const event_handler<process>& handler) noexcept {
          data_->exit_callback_+=(handler);
         return event_handler<process>::operator+=(handler);
        }
        
        event_handler<process>& operator +=(const typename event_handler<process>::function_t& function) noexcept {
          data_->exit_callback_+=(function);
          return event_handler<process>::operator+=(function);
        }
        
        template<typename fn_t>
        event_handler<process>& operator +=(fn_t function) noexcept {
          data_->exit_callback_+=(function);
          return event_handler<process>::operator+=(function);
        }
        
        event_handler<process>& operator -=(const event_handler<process>& handler) noexcept {
          data_->exit_callback_-=(handler);
         return event_handler<process>::operator-=(handler);
        }
        
        event_handler<process>& operator -=(const typename event_handler<process>::function_t& function) noexcept {
          data_->exit_callback_-=(function);
          return event_handler<process>::operator-=(function);
        }
        
        template<typename fn_t>
        event_handler<process>& operator -=(fn_t function) noexcept {
          data_->exit_callback_-=(function);
          return event_handler<process>::operator-=(function);
        }
      private:
        data* data_ = nullptr;
      };

      /// @brief Initializes a new instance of the xtd::diagnostics::process class.
      /// @remarks If you do not specify the machine_name property, the default is the local computer, (".").
      /// @remarks You have two options for associating a new xtd::diagnostics::process component with a process on the computer. The first option is to use the constructor to create the xtd::diagnostics::process component, set the appropriate members of the xtd::diagnostics::proces::start_info property and call xtd::diagnostics::proces::start to associate the xtd::diagnostics::process with a new system process. The second option is to associate the xtd::diagnostics::process with a running system process by using xtd::diagnostics::process:get_process_by_id or one of the xtd::diagnostics::process::get_processes return values.
      /// @remarks If you use a static overload of the xtd::diagnostics::processs::start method to start a new system process, the method creates a new xtd::diagnostics::process component and associates it with the process.
      /// @remarks When the xtd::diagnostics::process_start_info::use_shell_execute property is set to its default value, true, you can start applications and documents in a way that is similar to using the Run dialog box of the Windows Start menu. When xtd::diagnostics::process_start_info::use_shell_execute is false, you can start only executables.
      /// @remarks Any executable file that you can call from the command line can be started in one of two ways: by setting the appropriate members of the xtd::diagnostics::process:start_info property and calling the xtd::diagnostics::process::start method with no parameters, or by passing the appropriate parameter to the static_start member.
      /// @remarks You can create a xtd::diagnostics::processs component by using the constructor, one of the static xtd::diagnostics::processs::start overloads, or any of the xtd::diagnostics::processs::get_process_by_id, xtd::diagnostics::processs::get_processes, or xtd::diagnostics::processs::get_processes_by_name methods. After you have done so, you have a view into the associated process. This is not a dynamic view that updates itself automatically when the process properties have changed in memory. Instead, you must call xtd::diagnostics::processs::refresh for the component to update the xtd::diagnostics::processs property information in your application.
      process() = default;
      /// @cond
      process(const process&) = default;
      process& operator=(const process& value);
      ~process();
      /// @endcond

      int32_t exit_code() const;
      std::chrono::system_clock::time_point exit_time() const;

      /// @brief Gets the native handle of the associated process.
      /// @return The handle that the operating system assigned to the associated process when the process was started. The system uses this handle to keep track of process attributes.
      /// @exception xtd::invalid_operation_exception The process has not been started or has exited. The xtd::diagnostics::processs::handle property cannot be read because there is no process associated with this xtd::diagnostics::processs instance. -or- The xtd::diagnostics::processs instance has been attached to a running process but you do not have the necessary permissions to get a handle with full access rights.
      /// @exception xtd::not_supported_exception You are trying to access the xtd::diagnostics::processs::handle property for a process that is running on a remote computer. This property is available only for processes that are running on the local computer.
      /// @remarks An application can obtain a handle to a process that can be used as a parameter to many process-information and control functions. You can use this handle to initialize a xtd::diagnostics::wait_handle or to call native methods with platform invoke.
      intptr_t handle() const;

      /// @brief Gets the name of the computer the associated process is running on.
      /// @return The name of the computer that the associated process is running on.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      std::string machine_name() const;
      
      process_start_info start_info() const;
      process& start_info(process_start_info value);

      std::chrono::system_clock::time_point start_time() const;

      process&  kill();

      static process start(const process_start_info& start_info);
      static process start(const std::string& file_name);
      static process start(const std::string& file_name, const std::string& arguments);

      process& wait_for_exit();
      
      event_process exited {data_.get()};
      //void register_exited(xtd::delegate<void()> exited);

    protected:
      virtual void on_exited();
    };
  }
}
