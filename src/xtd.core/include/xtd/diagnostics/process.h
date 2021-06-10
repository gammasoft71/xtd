/// @file
/// @brief Contains xtd::diagnostics::process class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../event.h"
#include "../event_handler.h"
#include "process_start_info.h"
#include <chrono>
#include <functional>
#include <memory>
#include <optional>
#include <thread>

/// @cond
struct __init_process_message_box_message__;
/// @endcond

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
      struct data;
      
    public:
      /// @brief Represents a process event.
      /// @par Library
      /// xtd.core
      /// @remarks Used by xtd::diagnostics::process::exited, xtd::diagnostics::process::error_data_recaived and xtd::diagnostics::process::output_data_received events.
      /// @ingroup xtd_core diagnostics
      class process_event : protected event_handler<process> {
        friend process;
        process_event() : event_handler<process>() {}
        void set_data(data* data) {data_ = data;}

      public:
        /// @brief Gerts a value indicate if the event is empty.
        /// @return true if evcent does not contains functions; otherwise false.
        bool is_empty() const noexcept { return event_handler<process>::is_empty(); }
        
        /// @brief Adds an handler to the event.
        /// @param handler Handler to add.
        /// @return The current event instance.
        event_handler<process>& operator+=(const event_handler<process>& handler) noexcept {
          data_->exit_callback_+=(handler);
         return event_handler<process>::operator+=(handler);
        }
        
        /// @brief Adds a function to the event.
        /// @param handler Function to add.
        /// @return The current event instance.
        event_handler<process>& operator +=(const typename event_handler<process>::function_t& function) noexcept {
          data_->exit_callback_+=(function);
          return event_handler<process>::operator+=(function);
        }
        
        /// @brief Adds a function to the event.
        /// @param handler Function to add.
        /// @return The current event instance.
        template<typename fn_t>
        event_handler<process>& operator +=(fn_t function) noexcept {
          data_->exit_callback_+=(function);
          return event_handler<process>::operator+=(function);
        }
        
        /// @brief Removes an handler to the event.
        /// @param handler Handler to remove.
        /// @return The current event instance.
        event_handler<process>& operator -=(const event_handler<process>& handler) noexcept {
          data_->exit_callback_-=(handler);
         return event_handler<process>::operator-=(handler);
        }
        
        /// @brief Removes a function to the event.
        /// @param handler Function to remove.
        /// @return The current event instance.
        event_handler<process>& operator -=(const typename event_handler<process>::function_t& function) noexcept {
          data_->exit_callback_-=(function);
          return event_handler<process>::operator-=(function);
        }
        
        /// @brief Removes a function to the event.
        /// @param handler Function to remove.
        /// @return The current event instance.
        template<typename fn_t>
        event_handler<process>& operator -=(fn_t function) noexcept {
          data_->exit_callback_-=(function);
          return event_handler<process>::operator-=(function);
        }
        
      private:
        data* data_ = nullptr;
      };
      
      /// @brief Represents a point in time.
      using time_point = std::chrono::system_clock::time_point;

      /// @brief Initializes a new instance of the xtd::diagnostics::process class.
      /// @remarks If you do not specify the machine_name property, the default is the local computer, (".").
      /// @remarks You have two options for associating a new xtd::diagnostics::process component with a process on the computer. The first option is to use the constructor to create the xtd::diagnostics::process component, set the appropriate members of the xtd::diagnostics::proces::start_info property and call xtd::diagnostics::proces::start to associate the xtd::diagnostics::process with a new system process. The second option is to associate the xtd::diagnostics::process with a running system process by using xtd::diagnostics::process:get_process_by_id or one of the xtd::diagnostics::process::get_processes return values.
      /// @remarks If you use a static overload of the xtd::diagnostics::processs::start method to start a new system process, the method creates a new xtd::diagnostics::process component and associates it with the process.
      /// @remarks When the xtd::diagnostics::process_start_info::use_shell_execute property is set to its default value, true, you can start applications and documents in a way that is similar to using the Run dialog box of the Windows Start menu. When xtd::diagnostics::process_start_info::use_shell_execute is false, you can start only executables.
      /// @remarks Any executable file that you can call from the command line can be started in one of two ways: by setting the appropriate members of the xtd::diagnostics::process:start_info property and calling the xtd::diagnostics::process::start method with no parameters, or by passing the appropriate parameter to the static_start member.
      /// @remarks You can create a xtd::diagnostics::processs component by using the constructor, one of the static xtd::diagnostics::processs::start overloads, or any of the xtd::diagnostics::processs::get_process_by_id, xtd::diagnostics::processs::get_processes, or xtd::diagnostics::processs::get_processes_by_name methods. After you have done so, you have a view into the associated process. This is not a dynamic view that updates itself automatically when the process properties have changed in memory. Instead, you must call xtd::diagnostics::processs::refresh for the component to update the xtd::diagnostics::processs property information in your application.
      process();
      /// @cond
      process(const process&) = default;
      process& operator=(const process& value);
      ~process();
      /// @endcond
      
      /// @brief Gets whether the xtd::diagnostics::process::exited event should be raised when the process terminates.
      /// @return true if the xtd::diagnostics::process::exited event should be raised when the associated process is terminated (through either an exit or a call to xtd::diagnostics::process::kill()); otherwise, false. The default is false. Note that the xtd::diagnostics::process::exited event is raised even if the value of xtd::diagnostics::process::enable_raising_events is false when the process exits during or before the user performs a xtd::diagnostics::process::has_exited check.
      /// @remarks The xtd::diagnostics::process::enable_raising_events property suggests whether the component should be notified when the operating system has shut down a process. The xtd::diagnostics::process::enable_raising_events property is used in asynchronous processing to notify your application that a process has exited. To force your application to synchronously wait for an exit event (which interrupts processing of the application until the exit event has occurred), use the xtd::diagnostics::process::wait_for_exit method.
      /// @remarks If the component's xtd::diagnostics::process::enable_raising_events value is true, or when xtd::diagnostics::process::enable_raising_events is false and a xtd::diagnostics::process::has_exited check is invoked by the component, the component can access the administrative information for the associated process, which remains stored by the operating system. Such information includes the xtd::diagnostics::process::exit_time and the xtd::diagnostics::process::exit_code.
      /// @remarks After the associated process exits, the xtd::diagnostics::process::handle of the component no longer points to an existing process resource. Instead, it can only be used to access the operating system's information about the process resource. The operating system is aware that there are handles to exited processes that haven't been released by xtd::diagnostics::process components, so it keeps the xtd::diagnostics::process::exit_time and xtd::diagnostics::process::handle information in memory.
      /// @remarks There's a cost associated with watching for a process to exit. If xtd::diagnostics::process::enable_raising_events is true, the xtd::diagnostics::process::exited event is raised when the associated process terminates. Your procedures for the xtd::diagnostics::process::exited event run at that time.
      /// @remarks Sometimes, your application starts a process but doesn't require notification of its closure. For example, your application can start Notepad to allow the user to perform text editing but make no further use of the Notepad application. You can choose to avoid notification when the process exits because it's not relevant to the continued operation of your application. Setting xtd::diagnostics::process::enable_raising_events to false can save system resources.
      bool enable_raising_events() const;
      /// @brief Sets whether the xtd::diagnostics::process::exited event should be raised when the process terminates.
      /// @param value true if the xtd::diagnostics::process::exited event should be raised when the associated process is terminated (through either an exit or a call to xtd::diagnostics::process::kill()); otherwise, false. The default is false. Note that the xtd::diagnostics::process::exited event is raised even if the value of xtd::diagnostics::process::enable_raising_events is false when the process exits during or before the user performs a xtd::diagnostics::process::has_exited check.
      /// @remarks The xtd::diagnostics::process::enable_raising_events property suggests whether the component should be notified when the operating system has shut down a process. The xtd::diagnostics::process::enable_raising_events property is used in asynchronous processing to notify your application that a process has exited. To force your application to synchronously wait for an exit event (which interrupts processing of the application until the exit event has occurred), use the xtd::diagnostics::process::wait_for_exit method.
      /// @remarks If the component's xtd::diagnostics::process::enable_raising_events value is true, or when xtd::diagnostics::process::enable_raising_events is false and a xtd::diagnostics::process::has_exited check is invoked by the component, the component can access the administrative information for the associated process, which remains stored by the operating system. Such information includes the xtd::diagnostics::process::exit_time and the xtd::diagnostics::process::exit_code.
      /// @remarks After the associated process exits, the xtd::diagnostics::process::handle of the component no longer points to an existing process resource. Instead, it can only be used to access the operating system's information about the process resource. The operating system is aware that there are handles to exited processes that haven't been released by xtd::diagnostics::process components, so it keeps the xtd::diagnostics::process::exit_time and xtd::diagnostics::process::handle information in memory.
      /// @remarks There's a cost associated with watching for a process to exit. If xtd::diagnostics::process::enable_raising_events is true, the xtd::diagnostics::process::exited event is raised when the associated process terminates. Your procedures for the xtd::diagnostics::process::exited event run at that time.
      /// @remarks Sometimes, your application starts a process but doesn't require notification of its closure. For example, your application can start Notepad to allow the user to perform text editing but make no further use of the Notepad application. You can choose to avoid notification when the process exits because it's not relevant to the continued operation of your application. Setting xtd::diagnostics::process::enable_raising_events to false can save system resources.
      void enable_raising_events(bool value);

      /// @brief Gets the value that the associated process specified when it terminated.
      /// @return The code that the associated process specified when it terminated.
      /// @exception xtd::invalid_operation_exception The process has not exited. -or- The process xtd::diagnostics::process::handle is not valid.
      /// @exception xtd::not_supported_exception You are trying to access the xtd::diagnostics::process::exit_code property for a process that is running on a remote computer. This property is available only for processes that are running on the local computer.
      /// @remarks Use xtd::diagnostics::process::exit_code to get the status that the system process returned when it exited. You can use the exit code much like an integer return value from a main() procedure.
      /// @remarks The xtd::diagnostics::process::exit_code value for a process reflects the specific convention implemented by the application developer for that process. If you use the exit code value to make decisions in your code, be sure that you know the exit code convention used by the application process.
      /// @remarks Developers usually indicate a successful exit by an xtd::diagnostics::process::exit_code value of zero (EXIT_SUCCESS), and designate errors by nonzero values (EXIT_FAILURE) that the calling method can use to identify the cause of an abnormal process termination. It is not necessary to follow these guidelines, but they are the convention.
      /// @remarks If you try to get the xtd::diagnostics::process::exit_code before the process has exited, the attempt throws an exception. Examine the xtd::diagnostics::process::has_exited property first to verify whether the associated process has terminated.
      /// @note When standard output has been redirected to asynchronous event handlers, it is possible that output processing will not have completed when HasExited returns true. To ensure that asynchronous event handling has been completed, call the xtd::diagnostics::wait_for_exit() overload that takes no parameter before checking xtd::diagnostics::has_exited.
      /// @remarks You can use the xtd::diagnostics::process::close_main_window or the xtd::diagnostics::process::kill method to cause an associated process to exit.
      /// @remarks There are two ways of being notified when the associated process exits: synchronously and asynchronously. Synchronous notification relies on calling the xtd::diagnostics::process::wait_for_exit method to pause the processing of your application until the associated component exits. Asynchronous notification relies on the xtd::diagnostics::process::exited event. When using asynchronous notification, xtd::diagnostics::process::enable_raising_events must be set to true for the xtd::diagnostics::process component to receive notification that the process has exited.
      int32_t exit_code() const;

      /// @brief Gets the time that the associated process exited.
      /// @return A std::chrono::system_clock::time_point that indicates when the associated process was terminated.
      /// @exception xtd::not_supported_exception You are trying to access the xtd::diagnostics::process::exit_time property for a process that is running on a remote computer. This property is available only for processes that are running on the local computer.
      /// @remarks If the process has not terminated, attempting to retrieve the xtd::diagnostics::process::exit_time property throws an exception. Use xtd::diagnostics::process::has_exited before getting the xtd::diagnostics::process::exit_time property to determine whether the associated process has terminated.
      time_point exit_time() const;

      /// @brief Gets the native handle of the associated process.
      /// @return The handle that the operating system assigned to the associated process when the process was started. The system uses this handle to keep track of process attributes.
      /// @exception xtd::invalid_operation_exception The process has not been started or has exited. The xtd::diagnostics::processs::handle property cannot be read because there is no process associated with this xtd::diagnostics::processs instance. -or- The xtd::diagnostics::processs instance has been attached to a running process but you do not have the necessary permissions to get a handle with full access rights.
      /// @exception xtd::not_supported_exception You are trying to access the xtd::diagnostics::processs::handle property for a process that is running on a remote computer. This property is available only for processes that are running on the local computer.
      /// @remarks An application can obtain a handle to a process that can be used as a parameter to many process-information and control functions. You can use this handle to initialize a xtd::diagnostics::wait_handle or to call native methods with platform invoke.
      /// @remarks This process handle is private to an application--in other words, process handles cannot be shared. A process also has a process Id which, unlike the xtd::diagnostics::processs::handle, is unique and, therefore, valid throughout the system.
      /// @remarks Only processes started through a call to xtd::diagnostics::processs::start set the xtd::diagnostics::processs::handle property of the corresponding xtd::diagnostics::processs instances.
      intptr_t handle() const;
      
      /// @brief Gets a value indicating whether the associated process has been terminated.
      /// @return true if the operating system process referenced by the process component has terminated; otherwise, false.
      /// @exception xtd::invalid_operation_exception There is no process associated with the object.
      /// @exception xtd::not_supported_exception You are trying to access the xtd::diagnostics::process::has_exited property for a process that is running on a remote computer. This property is available only for processes that are running on the local computer.
      /// @remarks A value of true for xtd::diagnostics::process::has_exited indicates that the associated process has terminated, either normally or abnormally. You can request or force the associated process to exit by calling xtd::diagnostics::process::close_main_window or xtd::diagnostics::process::kill. If a handle is open to the process, the operating system releases the process memory when the process has exited, but retains administrative information about the process, such as the handle, exit code, and exit time. To get this information, you can use the xtd::diagnostics::process::exit_code and xtd::diagnostics::process::exit_time properties. These properties are populated automatically for processes that were started by this component. The administrative information is released when all the Process components that are associated with the system process are destroyed and hold no more handles to the exited process.
      /// @remarks A process can terminate independently of your code. If you started the process using this component, the system updates the value of xtd::diagnostics::process::has_exited automatically, even if the associated process exits independently.
      /// @note When standard output has been redirected to asynchronous event handlers, it is possible that output processing will not have completed when HasExited returns true. To ensure that asynchronous event handling has been completed, call the xtd::diagnostics::wait_for_exit() overload that takes no parameter before checking xtd::diagnostics::has_exited.
      bool has_exited() const;

      /// @brief Gets the unique identifier for the associated process.
      /// @return The system-generated unique identifier of the process that is referenced by this process instance.
      /// @exception xtd::invalid_operation The process's Id property has not been set.
      /// @remarks The process xtd::diagnostics::process::id is not valid if the associated process is not running. Therefore, you should ensure that the process is running before attempting to retrieve the xtd::diagnostics::process::id property. Until the process terminates, the process identifier uniquely identifies the process throughout the system.
      /// @remarks You can connect a process that is running on a local or remote computer to a new xtd::diagnostics::process instance by passing the process identifier to the xtd::diagnostics::process::get_process_by_id method. xtd::diagnostics::process::get_process_by_id is a static method that creates a new component and sets the xtd::diagnostics::process::id property for the new xtd::diagnostics::process instance automatically.
      /// @remarks Process identifiers can be reused by the system. The xtd::diagnostics::process::id property value is unique only while the associated process is running. After the process has terminated, the system can reuse the xtd::diagnostics::process::id property value for an unrelated process.
      /// @remarks Because the identifier is unique on the system, you can pass it to other threads as an alternative to passing a xtd::diagnostics::process instance. This action can save system resources yet guarantee that the process is correctly identified.
      int32_t id() const;

      /// @brief Gets the name of the computer the associated process is running on.
      /// @return The name of the computer that the associated process is running on.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      std::string machine_name() const;
      
      std::istream& standard_error();

      std::ostream& standard_input();

      std::istream& standard_output();

      const process_start_info& start_info() const;
      process_start_info& start_info();
      process& start_info(const process_start_info& value);

      time_point start_time() const;

      process& kill();

      bool start();
      static process start(const process_start_info& start_info);
      static process start(const std::string& file_name);
      static process start(const std::string& file_name, const std::string& arguments);

      process& wait_for_exit();
      
      process_event error_data_recaived;
      
      /// @brief Occurs when a process exits.
      /// @remarks The exited event indicates that the associated process exited. This occurrence means either that the process terminated (aborted) or successfully closed. This event can occur only if the value of the EnableRaisingEvents property is true.
      process_event exited;
      
      process_event output_data_recaived;
      
    protected:
      virtual void on_exited();
      
    private:
      struct data {
        process_start_info start_info_;
        intptr_t handle_ = 0;
        int32_t id_ = 0;
        std::unique_ptr<std::ostream> standard_input_;
        std::unique_ptr<std::istream> standard_output_;
        std::unique_ptr<std::istream> standard_error_;
        std::thread thread_;
        process::time_point start_time_;
        process::time_point exit_time_;
        bool enable_raising_events_ = false;
        std::optional<int32_t> exit_code_;
        event_handler<process> exit_callback_;
        std::exception_ptr exception_pointer_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    private:
      friend __init_process_message_box_message__;
      // This delehgate will be initialized by __init_process_message_box_message__ in xtd.forns/src/xtd/forms/appllication.cpp file.
      // This operation can be done only if xtd.forms lib is present.
      inline static xtd::delegate<void(const std::string&)> message_box_message_;
    };
  }
}
