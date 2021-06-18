/// @file
/// @brief Contains xtd::diagnostics::process class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../event.h"
#include "../event_handler.h"
#include "data_received_event_handler.h"
#include "process_priority_class.h"
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
    /// The following example populates a StartInfo with the file to execute, the action performed on it and whether it should displays a user interface. For additional examples, refer to the reference pages for properties of the ProcessStartInfo class.
    /// @include process.cpp
    /// @remarks A xtd::diagnostics::process component provides access to a process that is running on a computer. A process, in the simplest terms, is a running app. A thread is the basic unit to which the operating system allocates processor time. A thread can execute any part of the code of the process, including parts currently being executed by another thread.
    /// @remarks The xtd::diagnostics::process component is a useful tool for starting, stopping, controlling, and monitoring apps. You can use the xtd::diagnostics::process component, to obtain a list of the processes that are running, or you can start a new process. A Process component is used to access system processes. After a xtd::diagnostics::process component has been initialized, it can be used to obtain information about the running process. Such information includes the set of threads, the loaded modules (.dll and .exe files), and performance information such as the amount of memory the process is using.
    /// @note 32-bit processes cannot access the modules of a 64-bit process. If you try to get information about a 64-bit process from a 32-bit process, you will get a Win32Exception exception. A 64-bit process, on the other hand, can access the modules of a 32-bit process.
    /// @remarks The xtd::diagnostics::process component obtains information about a group of properties all at once. After the xtd::diagnostics::process component has obtained information about one member of any group, it will cache the values for the other properties in that group and not obtain new information about the other members of the group until you call the xtd::diagnostics::process::refresh method. Therefore, a property value is not guaranteed to be any newer than the last call to the xtd::diagnostics::process::refresh method. The group breakdowns are operating-system dependent.
    /// @remarks If you have a path variable declared in your system using quotes, you must fully qualify that path when starting any process found in that location. Otherwise, the system will not find the path. For example, if c:\mypath is not in your path, and you add it using quotation marks: path = %path%;"c:\mypath", you must fully qualify any process in c:\mypath when starting it.
    /// @remarks A system process is uniquely identified on the system by its process identifier. Like many Windows resources, a process is also identified by its handle, which might not be unique on the computer. A handle is the generic term for an identifier of a resource. The operating system persists the process handle, which is accessed through the Handle property of the Process component, even when the process has exited. Thus, you can get the process's administrative information, such as the xtd::diagnostics::process::exit_code (usually either zero for success or a nonzero error code) and the xtd::diagnostics::process::exit_time. xtd::diagnostics::process::handles are an extremely valuable resource, so leaking handles is more virulent than leaking memory.
    class core_export_ process final {
      struct data;
      
    public:
      /// @brief Represents a process error data received event.
      /// @par Library
      /// xtd.core
      /// @remarks Used by xtd::diagnostics::process::exited, xtd::diagnostics::process::error_data_recaived and xtd::diagnostics::process::output_data_received events.
      /// @ingroup xtd_core events
      class error_data_received_event : protected xtd::diagnostics::data_received_event_handler<process&> {
        friend process;
        void set_data(data* data) {data_ = data;}
      public:
        /// @brief Gets a value indicate if the event is empty.
        /// @return true if evcent does not contains functions; otherwise false.
        bool is_empty() const noexcept;
        
        /// @brief Adds an handler to the event.
        /// @param handler Handler to add.
        /// @return The current event instance.
        xtd::diagnostics::data_received_event_handler<process&>& operator+=(const xtd::diagnostics::data_received_event_handler<process&>& handler) noexcept;
        
        /// @brief Adds a function to the event.
        /// @param function Function to add.
        /// @return The current event instance.
        xtd::diagnostics::data_received_event_handler<process&>& operator+=(const typename xtd::diagnostics::data_received_event_handler<process&>::function_t& function) noexcept;
        
        /// @brief Adds a function to the event.
        /// @param function Function to add.
        /// @return The current event instance.
        template<typename fn_t>
        xtd::diagnostics::data_received_event_handler<process&>& operator+=(fn_t function) noexcept {
          data_->error_data_received_callback_+=(function);
          return xtd::diagnostics::data_received_event_handler<process&>::operator+=(function);
        }
        
        /// @brief Removes an handler to the event.
        /// @param handler Handler to remove.
        /// @return The current event instance.
        xtd::diagnostics::data_received_event_handler<process&>& operator-=(const xtd::diagnostics::data_received_event_handler<process&>& handler) noexcept;
        
        /// @brief Removes a function to the event.
        /// @param function Function to remove.
        /// @return The current event instance.
        xtd::diagnostics::data_received_event_handler<process&>& operator-=(const typename xtd::diagnostics::data_received_event_handler<process&>::function_t& function) noexcept;
        
        /// @brief Removes a function to the event.
        /// @param function Function to remove.
        /// @return The current event instance.
        template<typename fn_t>
        xtd::diagnostics::data_received_event_handler<process&>& operator -=(fn_t function) noexcept {
          data_->error_data_received_callback_-=(function);
          return data_received_event_handler<process&>::operator-=(function);
        }
        
      private:
        data* data_ = nullptr;
      };

      /// @brief Represents a process exit event.
      /// @par Library
      /// xtd.core
      /// @remarks Used by xtd::diagnostics::process::exited event.
      /// @ingroup xtd_core events
      class exit_event : protected xtd::event_handler<process&> {
        friend process;
        void set_data(data* data) {data_ = data;}
      public:
        /// @brief Gets a value indicate if the event is empty.
        /// @return true if evcent does not contains functions; otherwise false.
        bool is_empty() const noexcept;
        
        /// @brief Adds an handler to the event.
        /// @param handler Handler to add.
        /// @return The current event instance.
        xtd::event_handler<process&>& operator+=(const xtd::event_handler<process&>& handler) noexcept;
        
        /// @brief Adds a function to the event.
        /// @param function Function to add.
        /// @return The current event instance.
        xtd::event_handler<process&>& operator+=(const typename xtd::event_handler<process&>::function_t& function) noexcept;
        
        /// @brief Adds a function to the event.
        /// @param function Function to add.
        /// @return The current event instance.
        template<typename fn_t>
        xtd::event_handler<process&>& operator+=(fn_t function) noexcept {
          data_->exit_callback_+=(function);
          return xtd::event_handler<process&>::operator+=(function);
        }
        
        /// @brief Removes an handler to the event.
        /// @param handler Handler to remove.
        /// @return The current event instance.
        xtd::event_handler<process&>& operator-=(const xtd::event_handler<process&>& handler) noexcept;
        
        /// @brief Removes a function to the event.
        /// @param function Function to remove.
        /// @return The current event instance.
        xtd::event_handler<process&>& operator-=(const typename xtd::event_handler<process&>::function_t& function) noexcept;
        
        /// @brief Removes a function to the event.
        /// @param function Function to remove.
        /// @return The current event instance.
        template<typename fn_t>
        xtd::event_handler<process&>& operator -=(fn_t function) noexcept {
          data_->exit_callback_-=(function);
          return xtd::event_handler<process&>::operator-=(function);
        }
        
      private:
        data* data_ = nullptr;
      };
      
      /// @brief Represents a process output data received event.
      /// @par Library
      /// xtd.core
      /// @remarks Used by xtd::diagnostics::process::exited, xtd::diagnostics::process::error_data_recaived and xtd::diagnostics::process::output_data_received events.
      /// @ingroup xtd_core events
      class output_data_received_event : protected xtd::diagnostics::data_received_event_handler<process&> {
        friend process;
        void set_data(data* data) {data_ = data;}
      public:
        /// @brief Gets a value indicate if the event is empty.
        /// @return true if evcent does not contains functions; otherwise false.
        bool is_empty() const noexcept;
        
        /// @brief Adds an handler to the event.
        /// @param handler Handler to add.
        /// @return The current event instance.
        xtd::diagnostics::data_received_event_handler<process&>& operator+=(const xtd::diagnostics::data_received_event_handler<process&>& handler) noexcept;
        
        /// @brief Adds a function to the event.
        /// @param function Function to add.
        /// @return The current event instance.
        xtd::diagnostics::data_received_event_handler<process&>& operator+=(const typename xtd::diagnostics::data_received_event_handler<process&>::function_t& function) noexcept;
        
        /// @brief Adds a function to the event.
        /// @param function Function to add.
        /// @return The current event instance.
        template<typename fn_t>
        xtd::diagnostics::data_received_event_handler<process&>& operator+=(fn_t function) noexcept {
          data_->output_data_received_callback_+=(function);
          return xtd::diagnostics::data_received_event_handler<process&>::operator+=(function);
        }
        
        /// @brief Removes an handler to the event.
        /// @param handler Handler to remove.
        /// @return The current event instance.
        xtd::diagnostics::data_received_event_handler<process&>& operator-=(const xtd::diagnostics::data_received_event_handler<process&>& handler) noexcept;
        
        /// @brief Removes a function to the event.
        /// @param function Function to remove.
        /// @return The current event instance.
        xtd::diagnostics::data_received_event_handler<process&>& operator-=(const typename xtd::diagnostics::data_received_event_handler<process&>::function_t& function) noexcept;
        
        /// @brief Removes a function to the event.
        /// @param function Function to remove.
        /// @return The current event instance.
        template<typename fn_t>
        xtd::diagnostics::data_received_event_handler<process&>& operator -=(fn_t function) noexcept {
          data_->output_data_received_callback_-=(function);
          return xtd::diagnostics::data_received_event_handler<process&>::operator-=(function);
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
      
      /// @brief Gets the base priority xof the associated process.
      /// @return The base priority, which is computed from the xtd::diagnostics::processs::priority_class of the associated process.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks The value returned by this property represents the most recently refreshed base priority of the process. To get the most up to date base priority, you need to call xtd::diagnostics::processs::refresh() method first.
      /// @remarks The xtd::diagnostics::processs::base_priority of the process is the starting priority for threads created within the associated process. You can view information about the base priority through the System Monitor's Priority Base counter.
      /// @remarks Based on the time elapsed or other boosts, the operating system can change the base priority when a process should be placed ahead of others.
      /// @remarks The xtd::diagnostics::processs::base_priority property lets you view the starting priority assigned to a process. However, because it is read-only, you cannot use the xtd::diagnostics::processs::base_priority to set the priority of the process. To change the priority, use the xtd::diagnostics::processs::priority_class property. The xtd::diagnostics::processs::base_priority is viewable using the System Monitor, while the xtd::diagnostics::processs::priority_class is not. Both the xtd::diagnostics::processs::base_priority and the xtd::diagnostics::processs::priority_class can be viewed programmatically. The following table shows the relationship between xtd::diagnostics::processs::base_priority values and xtd::diagnostics::processs::priority_class values.
      /// | Windows base_priority | macOS base_priority                        | linux base_priority                        | priority_class                                         |
      /// |-----------------------|--------------------------------------------|--------------------------------------------|--------------------------------------------------------|
      /// | 4                     | PRIO_MIN                             (-20) | PRIO_MIN                             (-20) | xtd::diagnostics::process_priority_class::idle         |
      /// | 6                     | PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4 (-10) | PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4 (-10) | xtd::diagnostics::process_priority_class::below_normal |
      /// | 8                     | PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2     (0) | PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2     (0) | xtd::diagnostics::process_priority_class::normal       |
      /// | 10                    | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4  (10) | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4  (10) | xtd::diagnostics::process_priority_class::above_normal |
      /// | 13                    | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8  (15) | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8  (15) | xtd::diagnostics::process_priority_class::high         |
      /// | 24                    | PRIO_MAX                              (20) | PRIO_MAX                              (20) | xtd::diagnostics::process_priority_class::real_time    |
      int32_t base_priority() const;
      
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
      process& enable_raising_events(bool value);

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
      /// @exception xtd::invalid_operation_exception The process's Id property has not been set.
      /// @remarks The process xtd::diagnostics::process::id is not valid if the associated process is not running. Therefore, you should ensure that the process is running before attempting to retrieve the xtd::diagnostics::process::id property. Until the process terminates, the process identifier uniquely identifies the process throughout the system.
      /// @remarks You can connect a process that is running on a local or remote computer to a new xtd::diagnostics::process instance by passing the process identifier to the xtd::diagnostics::process::get_process_by_id method. xtd::diagnostics::process::get_process_by_id is a static method that creates a new component and sets the xtd::diagnostics::process::id property for the new xtd::diagnostics::process instance automatically.
      /// @remarks Process identifiers can be reused by the system. The xtd::diagnostics::process::id property value is unique only while the associated process is running. After the process has terminated, the system can reuse the xtd::diagnostics::process::id property value for an unrelated process.
      /// @remarks Because the identifier is unique on the system, you can pass it to other threads as an alternative to passing a xtd::diagnostics::process instance. This action can save system resources yet guarantee that the process is correctly identified.
      int32_t id() const;

      /// @brief Gets the name of the computer the associated process is running on.
      /// @return The name of the computer that the associated process is running on.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks You can view statistical data and process information for processes running on remote computers but you cannot call xtd::diagnostics::process::start, xtd::diagnostics::process::close_main_window, or xtd::diagnostics::process::kill on remote computers.
      /// @note When the associated process is executing on the local machine, this property returns a period (".") for the machine name. You should use the xtd::environment::machine_name property to get the correct machine name.
      std::string machine_name() const;

      /// @brief Gets the overall priority category for the associated process.
      /// @return The priority category for the associated process, from which the xtd::diagnostics::processs::base_priority of the process is calculated.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks The value returned by this property represents the most recently refreshed priority of the process. To get the most up to date priority, you need to call xtd::diagnostics::process::refresh() method first.
      /// @remarks A process priority class encompasses a range of thread priority levels. Threads with different priorities that are running in the process run relative to the priority class of the process. Win32 uses four priority classes with seven base priority levels per class. These process priority classes are captured in the xtd::diagnostics::process_priority_class enumeration, which lets you set the process priority to xtd::diagnostics::process_priority_class::idle, xtd::diagnostics::process_priority_class::normal, xtd::diagnostics::process_priority_class::high, xtd::diagnostics::process_priority_class::above_normal, xtd::diagnostics::process_priority_class::xtd::diagnostics::process_priority_class::below_normal, or xtd::diagnostics::process_priority_class::real_time. Based on the time elapsed or other boosts, the base priority level can be changed by the operating system when a process needs to be put ahead of others for access to the processor. In addition, you can set the xtd::diagnostics::process::priority_boost_enabled to temporarily boost the priority level of threads that have been taken out of the wait state. The priority is reset when the process returns to the wait state.
      /// @remarks The xtd::diagnostics::processs::base_priority property lets you view the starting priority that is assigned to a process. However, because it is read-only, you cannot use the xtd::diagnostics::processs::base_priority property to set the priority of a process. To change the priority, use the xtd::diagnostics::processs::priority_class property, which gets or sets the overall priority category for the process.
      /// @remarks The priority class cannot be viewed using System Monitor. The following table shows the relationship between the xtd::diagnostics::processs::base_priority and xtd::diagnostics::processs::priority_class values.
      /// | Windows base_priority | macOS base_priority                        | linux base_priority                        | priority_class                                         |
      /// |-----------------------|--------------------------------------------|--------------------------------------------|--------------------------------------------------------|
      /// | 4                     | PRIO_MIN                             (-20) | PRIO_MIN                             (-20) | xtd::diagnostics::process_priority_class::idle         |
      /// | 6                     | PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4 (-10) | PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4 (-10) | xtd::diagnostics::process_priority_class::below_normal |
      /// | 8                     | PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2     (0) | PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2     (0) | xtd::diagnostics::process_priority_class::normal       |
      /// | 10                    | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4  (10) | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4  (10) | xtd::diagnostics::process_priority_class::above_normal |
      /// | 13                    | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8  (15) | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8  (15) | xtd::diagnostics::process_priority_class::high         |
      /// | 24                    | PRIO_MAX                              (20) | PRIO_MAX                              (20) | xtd::diagnostics::process_priority_class::real_time    |
      xtd::diagnostics::process_priority_class priority_class() const;
      /// @brief Sets the overall priority category for the associated process.
      /// @param value The priority category for the associated process, from which the xtd::diagnostics::processs::base_priority of the process is calculated.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks The value returned by this property represents the most recently refreshed priority of the process. To get the most up to date priority, you need to call xtd::diagnostics::process::refresh() method first.
      /// @remarks A process priority class encompasses a range of thread priority levels. Threads with different priorities that are running in the process run relative to the priority class of the process. Win32 uses four priority classes with seven base priority levels per class. These process priority classes are captured in the xtd::diagnostics::process_priority_class enumeration, which lets you set the process priority to xtd::diagnostics::process_priority_class::idle, xtd::diagnostics::process_priority_class::normal, xtd::diagnostics::process_priority_class::high, xtd::diagnostics::process_priority_class::above_normal, xtd::diagnostics::process_priority_class::xtd::diagnostics::process_priority_class::below_normal, or xtd::diagnostics::process_priority_class::real_time. Based on the time elapsed or other boosts, the base priority level can be changed by the operating system when a process needs to be put ahead of others for access to the processor. In addition, you can set the xtd::diagnostics::process::priority_boost_enabled to temporarily boost the priority level of threads that have been taken out of the wait state. The priority is reset when the process returns to the wait state.
      /// @remarks The xtd::diagnostics::processs::base_priority property lets you view the starting priority that is assigned to a process. However, because it is read-only, you cannot use the xtd::diagnostics::processs::base_priority property to set the priority of a process. To change the priority, use the xtd::diagnostics::processs::priority_class property, which gets or sets the overall priority category for the process.
      /// @remarks The priority class cannot be viewed using System Monitor. The following table shows the relationship between the xtd::diagnostics::processs::base_priority and xtd::diagnostics::processs::priority_class values.
      /// | Windows base_priority | macOS base_priority                        | linux base_priority                        | priority_class                                         |
      /// |-----------------------|--------------------------------------------|--------------------------------------------|--------------------------------------------------------|
      /// | 4                     | PRIO_MIN                             (-20) | PRIO_MIN                             (-20) | xtd::diagnostics::process_priority_class::idle         |
      /// | 6                     | PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4 (-10) | PRIO_MIN + (PRIO_MAX - PRIO_MIN) / 4 (-10) | xtd::diagnostics::process_priority_class::below_normal |
      /// | 8                     | PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2     (0) | PRIO_MIN + (PRIO_MAX - PRIO_MIN)/2     (0) | xtd::diagnostics::process_priority_class::normal       |
      /// | 10                    | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4  (10) | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 4  (10) | xtd::diagnostics::process_priority_class::above_normal |
      /// | 13                    | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8  (15) | PRIO_MAX - (PRIO_MAX - PRIO_MIN) / 8  (15) | xtd::diagnostics::process_priority_class::high         |
      /// | 24                    | PRIO_MAX                              (20) | PRIO_MAX                              (20) | xtd::diagnostics::process_priority_class::real_time    |
      process& priority_class(xtd::diagnostics::process_priority_class value);
      
      /// @brief Gets the name of the process.
      /// @return The name that the system uses to identify the process to the user.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks The xtd::diagnostics::process::process_name property holds an executable file name, such as Outlook, that does not include the .exe extension or the path. It is helpful for getting and manipulating all the processes that are associated with the same executable file.
      /// @remarks You can call xtd::diagnostics::processs::get_processes_by_name, passing it an executable file name, to retrieve an array that contains every running instance on the specified computer. You can use this array, for example, to shut down all the running instances of the executable file.
      std::string process_name() const;

      /// @brief Gets a stream used to read the error output of the application.
      /// @return A std::istream that can be used to read the standard error stream of the application.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @par Examples
      /// The following example uses the net use command together with a user supplied argument to map a network resource. It then reads the standard error stream of the net command and writes it to console.
      /// @code
      /// using_(xtd::diagnostics::process my_process) {
      ///   xtd::diagnostics::process_start_info my_process_start_info("net ", "use " + args[0]);
      ///
      ///   my_process_start_info.use_shell_execute(false);
      ///   my_process_start_info.redirect_standard_error(true);
      ///   my_process.start_info(my_process_start_info);
      ///   my_process.start();
      ///
      ///   xtd::io::stream_reader my_stream_reader(my_process.standard_error());
      ///   // Read the standard error of net.exe and write it on to console.
      ///   xtd::console::write_line(my_stream_reader.read_line());
      /// }
      /// @endcode
      /// @remarks When a xtd::diagnostics::process writes text to its standard error stream, that text is normally displayed on the console. By redirecting the xtd::diagnostics::process::standard_error stream, you can manipulate or suppress the error output of a process. For example, you can filter the text, format it differently, or write the output to both the console and a designated log file.
      /// @note To use xtd::diagnostics::process::standard_error, you must set xtd::diagnostics::process_start_info::use_shell_execute to false, and you must set xtd::diagnostics::process_start_info::redirect_standard_error to true. Otherwise, reading from the xtd::diagnostics::process::standard_error stream throws an exception.
      /// @remarks The redirected xtd::diagnostics::process::standard_error stream can be read synchronously or asynchronously. Methods such as xtd::io::stream_reader::read, xtd::io::stream_reader::read_line, and xtd::io::stream_reader::read_to_end perform synchronous read operations on the error output stream of the process. These synchronous read operations do not complete until the associated xtd::diagnostics::process writes to its xtd::diagnostics::process::standard_error stream, or closes the stream.
      /// @remarks In contrast, xtd::diagnostics::process::begin_error_read_line starts asynchronous read operations on the xtd::diagnostics::process::standard_error stream. This method enables a designated event handler for the stream output and immediately returns to the caller, which can perform other work while the stream output is directed to the event handler.
      /// @remarks Synchronous read operations introduce a dependency between the caller reading from the xtd::diagnostics::process::standard_error stream and the child process writing to that stream. These dependencies can result in deadlock conditions. When the caller reads from the redirected stream of a child process, it is dependent on the child. The caller waits on the read operation until the child writes to the stream or closes the stream. When the child process writes enough data to fill its redirected stream, it is dependent on the parent. The child process waits on the next write operation until the parent reads from the full stream or closes the stream. The deadlock condition results when the caller and child process wait on each other to complete an operation, and neither can proceed. You can avoid deadlocks by evaluating dependencies between the caller and child process.
      /// @remarks The last two examples in this section use the xtd::diagnostics:process::start method to launch an executable named Write500Lines.exe. The following example contains its source code.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// int main() {
      ///   for (int ctr = 0; ctr < 500; ctr++)
      ///     console::write_line("Line {} of 500 written: {:P2}", ctr + 1, (ctr + 1)/500.0);
      ///
      ///   console::error << "\nSuccessfully wrote 500 lines.\n";
      /// }
      /// // The example displays the following output:
      /// //      The last 40 characters in the output stream are:
      /// //      ': 99.80%
      /// //      Line 500 of 500 written: 100.00%
      /// //      '
      /// //
      /// //      Successfully wrote 500 lines.
      /// @endcode
      /// @remarks The following example shows how to read from a redirected error stream and wait for the child process to exit. It avoids a deadlock condition by calling stream_reader(p.standard_error()).read_to_end() before p.wait_for_exit. A deadlock condition can result if the parent process calls p.wait_for_exit before stream_reader(p.standard_error()).read_to_end() and the child process writes enough text to fill the redirected stream. The parent process would wait indefinitely for the child process to exit. The child process would wait indefinitely for the parent to read from the full xtd::diagnostics::process::standard_error stream.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::diagnostics;
      /// using namespace xtd::io;
      ///
      /// int main() {
      ///   auto p = process();
      ///   p.start_info().use_shell_execute(false);
      ///   p.start_info().redirect_standard_error(true);
      ///   p.start_info().file_name("write_500_lines");
      ///   p.start();
      ///
      ///   // To avoid deadlocks, always read the output stream first and then wait.
      ///   string output = stream_reader(p.standard_error()).read_to_end();
      ///   p.wait_for_exit();
      ///
      ///   console::write_line("\nError stream: {}", output);
      /// }
      /// // The end of the output produced by the example includes the following:
      /// //      Error stream: Successfully wrote 500 lines.
      /// @endcode
      /// @remarks There is a similar issue when you read all text from both the standard output and standard error streams. The following example performs a read operation on both streams. It avoids the deadlock condition by performing asynchronous read operations on the xtd::diagnostics::process::standard_error stream. A deadlock condition results if the parent process calls stream_reader(p.standard_output()).read_to_end() followed by stream_reader(p.standard_error()).read_to_end() and the child process writes enough text to fill its error stream. The parent process would wait indefinitely for the child process to close its xtd::diagnostics::process::standard_output stream. The child process would wait indefinitely for the parent to read from the full xtd::diagnostics::process::standard_error stream.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::diagnostics;
      /// using namespace xtd::io;
      ///
      /// int main() {
      ///   auto p = process();
      ///   p.start_info().use_shell_execute(false);
      ///   p.start_info().redirect_standard_output(true);
      ///   string e_out;
      ///   p.start_info().redirect_standard_error(true);
      ///   p.error_data_recaived += [&](process& sender, const data_received_event_args& e) {
      ///     e_out += e.data();
      ///   };
      ///   p.start_info().file_name("write_500_lines");
      ///   p.start();
      ///
      ///   // To avoid deadlocks, always read the output stream first and then wait.
      ///   p.begin_error_read_line();
      ///   string output = stream_reader(p.standard_error()).read_to_end();
      ///   p.wait_for_exit();
      ///
      ///   console::write_line("\nError stream: {}", output);
      /// }
      /// // The example displays the following output:
      /// //      The last 40 characters in the output stream are:
      /// //      ': 99.80%
      /// //      Line 500 of 500 written: 100.00%
      /// //      '
      /// //
      /// //      Error stream: Successfully wrote 500 lines.
      /// @endcode
      /// @remarks You can use asynchronous read operations to avoid these dependencies and their deadlock potential. Alternately, you can avoid the deadlock condition by creating two threads and reading the output of each stream on a separate thread.
      /// @note You cannot mix asynchronous and synchronous read operations on a redirected stream. Once the redirected stream of a xtd::diagnostics::process is opened in either asynchronous or synchronous mode, all further read operations on that stream must be in the same mode. For example, do not follow xtd::diagnostics::process::begin_error_read_line with a call to xtd::ioo::stream_reader::read_line on the xtd::diagnostics::process::standard_error stream, or vice versa. However, you can read two different streams in different modes. For example, you can call xtd::diagnostics::process::begin_output_read_line and then call xtd::io::sstream_reader::read_line for the xtd::diagnostics::process::standard_error stream.
      std::istream& standard_error();

      /// @brief Gets a stream used to write the input of the application.
      /// @return A std::ostream that can be used to write the standard input stream of the application.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @par Examples
      /// The following example illustrates how to redirect the xtd::diagnostics::process::standard_input stream of a process. The example starts the sort command with redirected input. It then prompts the user for text, and passes that to the sort process by means of the redirected xtd::diagnostics::process::standard_input stream. The sort results are displayed to the user on the console.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::diagnostics;
      /// using namespace xtd::io;
      ///
      /// int main() {
      ///   console::write_line("Ready to sort one or more text lines...");
      ///
      ///   // Start the sort process with redirected input.
      ///   // Use the sort command to sort the input text.
      ///   using_(process my_process) {
      ///     my_process.start_info().file_name("sort");
      ///     my_process.start_info().use_shell_execute(false);
      ///     my_process.start_info().redirect_standard_input(true);
      ///
      ///     my_process.start();
      ///
      ///     stream_writer my_stream_writer(my_process.standard_input());
      ///
      ///     // Prompt the user for input text lines to sort.
      ///     // Write each line to the StandardInput stream of
      ///     // the sort command.
      ///     string input_text;
      ///     int num_lines = 0;
      ///     do {
      ///       console::write_line("Enter a line of text (or press the Enter key to stop):");
      ///
      ///       input_text = console::read_line();
      ///       if (input_text.size() > 0) {
      ///         num_lines++;
      ///         my_stream_writer.write_line(input_text);
      ///       }
      ///     } while (input_text.size() > 0);
      ///
      ///     // Write a report header to the console.
      ///     if (num_lines > 0) {
      ///       console::write_line(" {} sorted text line(s) ", num_lines);
      ///       console::write_line("------------------------");
      ///     } else {
      ///       console::write_line(" No input was sorted");
      ///     }
      ///
      ///     // End the input stream to the sort command.
      ///     // When the stream closes, the sort command
      ///     // writes the sorted text lines to the
      ///     // console.
      ///     my_stream_writer.close();
      ///
      ///     // Wait for the sort process to write the sorted text lines.
      ///     my_process.wait_for_exit();
      ///   }
      /// }
      /// @endcode
      /// @remarks A xtd::diagnostics::process can read input text from its standard input stream, typically the keyboard. By redirecting the xtd::diagnostics::process::standard_input stream, you can programmatically specify the input. For example, instead of using keyboard input, you can provide text from the contents of a designated file or output from another application.
      /// @note To use xtd::diagnostics::process::standard_input, you must set xtd::diagnostics::process_start_info::use_shell_execute to false, and you must set xtd::diagnostics::process_start_info::redirect_standard_input to true. Otherwise, writing to the xtd::diagnostics::process::standard_input stream throws an exception.
      std::ostream& standard_input();

      /// @brief Gets a stream used to read the textual output of the application.
      /// @return A std::istream that can be used to read the standard output stream of the application.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @par Examplles
      /// The following example runs the ipconfig.exe command and redirects its standard output to the example's console window.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::diagnostics;
      /// using namespace xtd::io;
      ///
      /// int main() {
      ///   using_(process process) {
      ///     process.start_info().file_name("ipconfig");
      ///     process.start_info().use_shell_execute(false);
      ///     process.start_info().redirect_standard_output(true);
      ///     process.start();
      ///
      ///     // Synchronously read the standard output of the spawned process.
      ///     stream_reader reader(process.standard_output());
      ///     string output = reader.read_to_end();
      ///
      ///     // Write the redirected output to this application's window.
      ///     console::write_line(output);
      ///
      ///     process.wait_for_exit();
      ///   }
      ///
      ///   console::write_line("\n\nPress any key to exit.");
      ///   console::read_line();
      /// }
      /// @endcode
      /// @remarks When a xtd::diagnostics::processs writes text to its standard stream, that text is normally displayed on the console. By redirecting the xtd::diagnostics::processs::standard_output stream, you can manipulate or suppress the output of a process. For example, you can filter the text, format it differently, or write the output to both the console and a designated log file.
      /// @note To use xtd::diagnostics::processs::standard_output, you must set xtd::diagnostics::process_start_info::use_shell_execute to false, and you must set xtd::diagnostics::process_start_info::redirect_standard_output to true. Otherwise, reading from the xtd::diagnostics::processs::standard_output stream throws an exception.
      /// @remarks The redirected xtd::diagnostics::processs::standard_output stream can be read synchronously or asynchronously. Methods such as xtd::io::stream_reader::read, xtd::io::stream_reader::read_line, and xtd::io::stream_reader::read_to_end perform synchronous read operations on the output stream of the process. These synchronous read operations do not complete until the associated Process writes to its xtd::diagnostics::processs::xtd::diagnostics::processs::standard_output stream, or closes the stream.
      /// @remarks In contrast, xtd::diagnostics::processs::begin_output_read_line starts asynchronous read operations on the xtd::diagnostics::processs::standard_output stream. This method enables a designated event handler for the stream output and immediately returns to the caller, which can perform other work while the stream output is directed to the event handler.
      /// @remarks Synchronous read operations introduce a dependency between the caller reading from the xtd::diagnostics::processs::standard_output stream and the child process writing to that stream. These dependencies can result in deadlock conditions. When the caller reads from the redirected stream of a child process, it is dependent on the child. The caller waits on the read operation until the child writes to the stream or closes the stream. When the child process writes enough data to fill its redirected stream, it is dependent on the parent. The child process waits on the next write operation until the parent reads from the full stream or closes the stream. The deadlock condition results when the caller and child process wait on each other to complete an operation, and neither can proceed. You can avoid deadlocks by evaluating dependencies between the caller and child process.
      /// @remarks The last two examples in this section use the xtd::diagnostics:process::start method to launch an executable named Write500Lines.exe. The following example contains its source code.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// int main() {
      ///   for (int ctr = 0; ctr < 500; ctr++)
      ///     console::write_line("Line {} of 500 written: {:P2}", ctr + 1, (ctr + 1)/500.0);
      ///
      ///   console::error << "\nSuccessfully wrote 500 lines.\n";
      /// }
      /// // The example displays the following output:
      /// //      The last 40 characters in the output stream are:
      /// //      ': 99.80%
      /// //      Line 500 of 500 written: 100.00%
      /// //      '
      /// //
      /// //      Successfully wrote 500 lines.
      /// @endcode
      /// @remarks The following example shows how to read from a redirected error stream and wait for the child process to exit. It avoids a deadlock condition by calling stream_reader(p.standard_error()).read_to_end() before p.wait_for_exit. A deadlock condition can result if the parent process calls p.wait_for_exit before stream_reader(p.standard_error()).read_to_end() and the child process writes enough text to fill the redirected stream. The parent process would wait indefinitely for the child process to exit. The child process would wait indefinitely for the parent to read from the full xtd::diagnostics::process::standard_error stream.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::diagnostics;
      /// using namespace xtd::io;
      ///
      /// int main() {
      ///   auto p = process();
      ///   p.start_info().use_shell_execute(false);
      ///   p.start_info().redirect_standard_error(true);
      ///   p.start_info().file_name("write_500_lines");
      ///   p.start();
      ///
      ///   // To avoid deadlocks, always read the output stream first and then wait.
      ///   string output = stream_reader(p.standard_error()).read_to_end();
      ///   p.wait_for_exit();
      ///
      ///   console::write_line("\nError stream: {}", output);
      /// }
      /// // The end of the output produced by the example includes the following:
      /// //      Error stream: Successfully wrote 500 lines.
      /// @endcode
      /// @remarks There is a similar issue when you read all text from both the standard output and standard error streams. The following example performs a read operation on both streams. It avoids the deadlock condition by performing asynchronous read operations on the xtd::diagnostics::process::standard_error stream. A deadlock condition results if the parent process calls stream_reader(p.standard_output()).read_to_end() followed by stream_reader(p.standard_error()).read_to_end() and the child process writes enough text to fill its error stream. The parent process would wait indefinitely for the child process to close its xtd::diagnostics::process::standard_output stream. The child process would wait indefinitely for the parent to read from the full xtd::diagnostics::process::standard_error stream.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::diagnostics;
      /// using namespace xtd::io;
      ///
      /// int main() {
      ///   auto p = process();
      ///   p.start_info().use_shell_execute(false);
      ///   p.start_info().redirect_standard_output(true);
      ///   string e_out;
      ///   p.start_info().redirect_standard_error(true);
      ///   p.error_data_recaived += [&](process& sender, const data_received_event_args& e) {
      ///     e_out += e.data();
      ///   };
      ///   p.start_info().file_name("write_500_lines");
      ///   p.start();
      ///
      ///   // To avoid deadlocks, always read the output stream first and then wait.
      ///   p.begin_error_read_line();
      ///   string output = stream_reader(p.standard_error()).read_to_end();
      ///   p.wait_for_exit();
      ///
      ///   console::write_line("\nError stream: {}", output);
      /// }
      /// // The example displays the following output:
      /// //      The last 40 characters in the output stream are:
      /// //      ': 99.80%
      /// //      Line 500 of 500 written: 100.00%
      /// //      '
      /// //
      /// //      Error stream: Successfully wrote 500 lines.
      /// @endcode
      /// @remarks You can use asynchronous read operations to avoid these dependencies and their deadlock potential. Alternately, you can avoid the deadlock condition by creating two threads and reading the output of each stream on a separate thread.
      /// @note You cannot mix asynchronous and synchronous read operations on a redirected stream. Once the redirected stream of a xtd::diagnostics::processs is opened in either asynchronous or synchronous mode, all further read operations on that stream must be in the same mode. For example, do not follow xtd::diagnostics::processs::begin_output_read_line with a call to xtd::io::stream_reader::read_line on the xtd::diagnostics::processs::standard_output stream, or vice versa. However, you can read two different streams in different modes. For example, you can call xtd::diagnostics::processs::begin_output_read_line and then call xtd::io::stream_reader::read_line for the xtd::diagnostics::processs::standard_error stream.
      std::istream& standard_output();

      /// @brief Gets the properties to pass to the xtd::diagnostics::process::start() method of the xtd::diagnostics::process.
      /// @return The xtd::diagnostics::process_start_info that represents the data with which to start the process. These arguments include the name of the executable file or document used to start the process.
      /// @par Examples
      /// The following example populates a StartInfo with the file to execute, the action performed on it and whether it should displays a user interface. For additional examples, refer to the reference pages for properties of the ProcessStartInfo class.
      /// @include process.cpp
      /// @remarks xtd::diagnostics::process_start_info represents the set of parameters to use to start a process. When xtd::diagnostics::process::start is called, the xtd::diagnostics::process::start_info is used to specify the process to start. The only necessary xtd::diagnostics::process::start_info member to set is the xtd::diagnostics::process_start_info::file_name property. Starting a process by specifying the xtd::diagnostics::process_start_info::file_name property is similar to typing the information in the Run dialog box of the Windows Start menu. Therefore, the xtd::diagnostics::process_start_info::file_name property does not need to represent an executable file. It can be of any file type for which the extension has been associated with an application installed on the system. For example the xtd::diagnostics::process_start_info::file_name can have a .txt extension if you have associated text files with an editor, such as Notepad, or it can have a .doc if you have associated .doc files with a word processing tool, such as Microsoft Word. Similarly, in the same way that the Run dialog box can accept an executable file name with or without the .exe extension, the .exe extension is optional in the xtd::diagnostics::process_start_info::file_name member. For example, you can set the xtd::diagnostics::process_start_info::file_name property to either "Notepad.exe" or "Notepad".
      /// @remarks If the file name involves a nonexecutable file, such as a .doc file, you can include a verb specifying what action to take on the file. For example, you could set the Verb to "Print" for a file ending in the .doc extension. The file name specified in the xtd::diagnostics::process::start_info::file_name property does not need to have an extension if you manually enter a value for the Verb property. However, if you use the Verbs property to determine what verbs are available, you must include the extension.
      /// @remarks You can change the parameters specified in the xtd::diagnostics::process::start_info property up to the time that you call the xtd::diagnostics::process::start method on the process. After you start the process, changing the xtd::diagnostics::process::start_info values does not affect or restart the associated process. If you call the xtd::diagnostics::process::start(xtd::diagnostics::process_start_info) method with the xtd::diagnostics::process_start_info. xtd::diagnostics::process::start_info::user_name and xtd::diagnostics::process::start_info::password properties set, the unmanaged CreateProcessWithLogonW function is called, which starts the process in a new window even if the xtd::diagnostics::process::start_info::create_no_window property value is true or the xtd::diagnostics::process::start_info::window_style property value is xtd::diagnostics::process_window_style::hidden.
      /// @remarks You should only access the xtd::diagnostics::process::start_info property on a xtd::diagnostics::process object returned by the Start method. For example, you should not access the xtd::diagnostics::process::start_info property on a xtd::diagnostics::process object returned by xtd::diagnostics::process::get_processes.
      const xtd::diagnostics::process_start_info& start_info() const;
      /// @brief Gets the properties to pass to the xtd::diagnostics::process::start() method of the xtd::diagnostics::process.
      /// @return The xtd::diagnostics::process_start_info that represents the data with which to start the process. These arguments include the name of the executable file or document used to start the process.
      /// @par Examples
      /// The following example populates a StartInfo with the file to execute, the action performed on it and whether it should displays a user interface. For additional examples, refer to the reference pages for properties of the ProcessStartInfo class.
      /// @include process.cpp
      /// @remarks xtd::diagnostics::process_start_info represents the set of parameters to use to start a process. When xtd::diagnostics::process::start is called, the xtd::diagnostics::process::start_info is used to specify the process to start. The only necessary xtd::diagnostics::process::start_info member to set is the xtd::diagnostics::process_start_info::file_name property. Starting a process by specifying the xtd::diagnostics::process_start_info::file_name property is similar to typing the information in the Run dialog box of the Windows Start menu. Therefore, the xtd::diagnostics::process_start_info::file_name property does not need to represent an executable file. It can be of any file type for which the extension has been associated with an application installed on the system. For example the xtd::diagnostics::process_start_info::file_name can have a .txt extension if you have associated text files with an editor, such as Notepad, or it can have a .doc if you have associated .doc files with a word processing tool, such as Microsoft Word. Similarly, in the same way that the Run dialog box can accept an executable file name with or without the .exe extension, the .exe extension is optional in the xtd::diagnostics::process_start_info::file_name member. For example, you can set the xtd::diagnostics::process_start_info::file_name property to either "Notepad.exe" or "Notepad".
      /// @remarks If the file name involves a nonexecutable file, such as a .doc file, you can include a verb specifying what action to take on the file. For example, you could set the Verb to "Print" for a file ending in the .doc extension. The file name specified in the xtd::diagnostics::process::start_info::file_name property does not need to have an extension if you manually enter a value for the Verb property. However, if you use the Verbs property to determine what verbs are available, you must include the extension.
      /// @remarks You can change the parameters specified in the xtd::diagnostics::process::start_info property up to the time that you call the xtd::diagnostics::process::start method on the process. After you start the process, changing the xtd::diagnostics::process::start_info values does not affect or restart the associated process. If you call the xtd::diagnostics::process::start(xtd::diagnostics::process_start_info) method with the xtd::diagnostics::process_start_info. xtd::diagnostics::process::start_info::user_name and xtd::diagnostics::process::start_info::password properties set, the unmanaged CreateProcessWithLogonW function is called, which starts the process in a new window even if the xtd::diagnostics::process::start_info::create_no_window property value is true or the xtd::diagnostics::process::start_info::window_style property value is xtd::diagnostics::process_window_style::hidden.
      /// @remarks You should only access the xtd::diagnostics::process::start_info property on a xtd::diagnostics::process object returned by the Start method. For example, you should not access the xtd::diagnostics::process::start_info property on a xtd::diagnostics::process object returned by xtd::diagnostics::process::get_processes.
      xtd::diagnostics::process_start_info& start_info();
      /// @brief SGets the properties to pass to the xtd::diagnostics::process::start() method of the xtd::diagnostics::process.
      /// @param value The xtd::diagnostics::process_start_info that represents the data with which to start the process. These arguments include the name of the executable file or document used to start the process.
      /// @par Examples
      /// The following example populates a StartInfo with the file to execute, the action performed on it and whether it should displays a user interface. For additional examples, refer to the reference pages for properties of the ProcessStartInfo class.
      /// @include process.cpp
      /// @remarks xtd::diagnostics::process_start_info represents the set of parameters to use to start a process. When xtd::diagnostics::process::start is called, the xtd::diagnostics::process::start_info is used to specify the process to start. The only necessary xtd::diagnostics::process::start_info member to set is the xtd::diagnostics::process_start_info::file_name property. Starting a process by specifying the xtd::diagnostics::process_start_info::file_name property is similar to typing the information in the Run dialog box of the Windows Start menu. Therefore, the xtd::diagnostics::process_start_info::file_name property does not need to represent an executable file. It can be of any file type for which the extension has been associated with an application installed on the system. For example the xtd::diagnostics::process_start_info::file_name can have a .txt extension if you have associated text files with an editor, such as Notepad, or it can have a .doc if you have associated .doc files with a word processing tool, such as Microsoft Word. Similarly, in the same way that the Run dialog box can accept an executable file name with or without the .exe extension, the .exe extension is optional in the xtd::diagnostics::process_start_info::file_name member. For example, you can set the xtd::diagnostics::process_start_info::file_name property to either "Notepad.exe" or "Notepad".
      /// @remarks If the file name involves a nonexecutable file, such as a .doc file, you can include a verb specifying what action to take on the file. For example, you could set the Verb to "Print" for a file ending in the .doc extension. The file name specified in the xtd::diagnostics::process::start_info::file_name property does not need to have an extension if you manually enter a value for the Verb property. However, if you use the Verbs property to determine what verbs are available, you must include the extension.
      /// @remarks You can change the parameters specified in the xtd::diagnostics::process::start_info property up to the time that you call the xtd::diagnostics::process::start method on the process. After you start the process, changing the xtd::diagnostics::process::start_info values does not affect or restart the associated process. If you call the xtd::diagnostics::process::start(xtd::diagnostics::process_start_info) method with the xtd::diagnostics::process_start_info. xtd::diagnostics::process::start_info::user_name and xtd::diagnostics::process::start_info::password properties set, the unmanaged CreateProcessWithLogonW function is called, which starts the process in a new window even if the xtd::diagnostics::process::start_info::create_no_window property value is true or the xtd::diagnostics::process::start_info::window_style property value is xtd::diagnostics::process_window_style::hidden.
      /// @remarks You should only access the xtd::diagnostics::process::start_info property on a xtd::diagnostics::process object returned by the Start method. For example, you should not access the xtd::diagnostics::process::start_info property on a xtd::diagnostics::process object returned by xtd::diagnostics::process::get_processes.
      process& start_info(const xtd::diagnostics::process_start_info& value);

      /// @brief Gets the time that the associated process was started.
      /// @return An object that indicates when the process started. An exception is thrown if the process is not running.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      time_point start_time() const;

      /// @brief Frees all the resources that are associated with this component.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks The xtd::diagnostics::process::close method causes the process to stop waiting for exit if it was waiting, closes the process handle, and clears process-specific properties. Close does not close the standard output, input, and error readers and writers in case they are being referenced externally.
      void close();
      
      /// @brief Immediately stops the associated process.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks The xtd::diagnostics::process::kill method forces a termination of the process, while xtd::diagnostics::process::close_main_window only requests a termination. When a process with a graphical interface is executing, its message loop is in a wait state. The message loop executes every time a Windows message is sent to the process by the operating system. Calling xtd::diagnostics::process::close_main_window sends a request to close the main window, which, in a well-formed application, closes child windows and revokes all running message loops for the application. The request to exit the process by calling xtd::diagnostics::process::close_main_window does not force the application to quit. The application can ask for user verification before quitting, or it can refuse to quit. To force the application to quit, use the xtd::diagnostics::process::kill method.
      /// @remarks The behavior of xtd::diagnostics::process::xtd::diagnostics::process::close_main_window is identical to that of a user closing an application's main window using the system menu. Therefore, the request to exit the process by closing the main window does not force the application to quit immediately.
      /// @note The xtd::diagnostics::process::kill method executes asynchronously. After calling the xtd::diagnostics::process::kill method, call the xtd::diagnostics::process::xtd::diagnostics::process::wait_for_exit method to wait for the process to exit, or check the xtd::diagnostics::process::has_exited property to determine if the process has exited.
      /// @note The xtd::diagnostics::process::wait_for_exit method and the xtd::diagnostics::process::has_exited property do not reflect the status of descendant processes. When xtd::diagnostics::process::kill(entireProcessTree: true) is used, xtd::diagnostics::process::wait_for_exit and xtd::diagnostics::process::has_exited will indicate that exiting has completed after the given process exits, even if all descendants have not yet exited.
      /// @remarks Data edited by the process or resources allocated to the process can be lost if you call xtd::diagnostics::process::kill. xtd::diagnostics::process::kill causes an abnormal process termination and should be used only when necessary. xtd::diagnostics::process::close_main_window enables an orderly termination of the process and closes all windows, so it is preferable for applications with an interface. If xtd::diagnostics::process::close_main_window fails, you can use xtd::diagnostics::process::kill to terminate the process. xtd::diagnostics::process::kill is the only way to terminate processes that do not have graphical interfaces.
      /// @remarks You can call xtd::diagnostics::process::kill and xtd::diagnostics::process::close_main_window only for processes that are running on the local computer. You cannot cause processes on remote computers to exit. You can only view information for processes running on remote computers.
      void kill();

      /// @brief Starts (or reuses) the process resource that is specified by the xtd::diagnostics::process::start_info property of this Process component and associates it with the component.
      /// @return true if a process resource is started; false if no new process resource is started (for example, if an existing process is reused).
      /// @exception xtd::invalid_operation_exception No file name was specified in the xtd::diagnostics::process component's xtd::diagnostics::process::start_info.
      /// @par Examples
      /// The following example populates a StartInfo with the file to execute, the action performed on it and whether it should displays a user interface. For additional examples, refer to the reference pages for properties of the ProcessStartInfo class.
      /// @include process.cpp
      bool start();
      /// @brief Starts the process resource that is specified by the parameter containing process start information (for example, the file name of the process to start) and associates the resource with a new xtd::diagnostics::process component.
      /// @param The xtd::diagnostics::process_start_ifo that contains the information that is used to start the process, including the file name and any command-line arguments.
      /// @return A new xtd::diagnostics::process that is associated with the process resource. Note that a new process that's started alongside already running instances of the same process will be independent from the others. In addition, Start may return a xtd::diagnostics::process with its xtd::diagnostics::process::has_exited property already set to true. In this case, the started process may have activated an existing instance of itself and then exited.
      /// @exception xtd::invalid_operation_exception No file name was specified in the startInfo parameter's xtd::diagnostics::process_start_info::file_name property.
      /// @par Examples
      /// Shows how to launch process.
      /// @include process_form.cpp
      /// @remarks Use this overload to start a process resource by specifying a xtd::diagnostics::process_start_info instance. The overload associates the resource with a new xtd::diagnostics::process object.
      /// @remarks This overload lets you start a process without first creating a new xtd::diagnostics::process instance. Using this overload with a xtd::diagnostics::processxtd::diagnostics::process_start_info parameter is an alternative to the explicit steps of creating a new xtd::diagnostics::process instance, setting its xtd::diagnostics::process::start_info properties, and calling Start for the xtd::diagnostics::process instance.
      /// @remarks Using a xtd::diagnostics::process_start_info instance as the parameter lets you call xtd::diagnostics::process::start with the most control over what is passed into the call to start the process. If you need to pass only a file name or a file name and arguments, it is not necessary to create a new xtd::diagnostics::process_start_info instance, although that is an option. The only xtd::diagnostics::process::start_info property that must be set is the xtd::diagnostics::process_start_info::file_name property. The xtd::diagnostics::process_start_info::file_name property does not need to represent an executable file. It can be of any file type for which the extension has been associated with an application that is installed on the system. For example, the xtd::diagnostics::process_start_info::file_name property can have a .txt extension if you have associated text files with an editor, such as Notepad, or it can have a .doc extension if you have associated .doc files with a word processing tool, such as Microsoft Word.
      /// @remarks Unlike the other overloads, the overload of td::diagnostics::process::start that has no parameters is not a static member. Use that overload when you have already created a td::diagnostics::process instance and specified start information (including the file name), and you want to start a process resource and associate it with the existing Process instance. Use one of the static overloads when you want to create a new Process component rather than start a process for an existing component. Both this overload and the overload that has no parameters allow you to specify the start information for the process resource by using a td::diagnostics::process_start_info instance.
      /// @remarks If you have a path variable declared in your system using quotes, you must fully qualify that path when starting any process found in that location. Otherwise, the system will not find the path. For example, if c:\mypath is not in your path, and you add it using quotation marks: path = %path%;"c:\mypath", you must fully qualify any process in c:\mypath when starting it.
      /// @remarks Whenever you use xtd::diagnostics::process::start to start a process, you might need to close it or you risk losing system resources. Close processes using xtd::diagnostics::process::close_main_window or xtd::diagnostics::process::kill. You can check whether a process has already been closed by using its xtd::diagnostics::process::has_exited property.
      static process start(const xtd::diagnostics::process_start_info& start_info);
      /// @brief Starts a process resource by specifying the name of a document or application file and associates the resource with a new Process component.
      /// @param fille_name The name of a document or application file to run in the process.
      /// @return A new xtd::diagnostics::process that is associated with the process resource. Note that a new process that's started alongside already running instances of the same process will be independent from the others. In addition, Start may return a xtd::diagnostics::process with its xtd::diagnostics::process::has_exited property already set to true. In this case, the started process may have activated an existing instance of itself and then exited.
      /// @exception xtd::invalid_operation_exception No file name was specified in the filen_ame parameter's xtd::diagnostics::process_start_info::file_name property.
      /// @remarks Use this overload to start a process resource by specifying its file name. The overload associates the resource with a new xtd::diagnostics::process object.
      /// @remarks This overload lets you start a process without first creating a new xtd::diagnostics::process instance. The overload is an alternative to the explicit steps of creating a new xtd::diagnostics::process instance, setting the xtd::diagnostics::process_start_info::file_name member of the xtd::diagnostics::process::start_info property, and calling xtd::diagnostics::process::start for the xtd::diagnostics::process instance.
      /// @remarks Starting a process by specifying its file name is similar to typing the information in the Run dialog box of the Windows Start menu. Therefore, the file name does not need to represent an executable file. It can be of any file type for which the extension has been associated with an application installed on the system. For example the file name can have a .txt extension if you have associated text files with an editor, such as Notepad, or it can have a .doc if you have associated .doc files with a word processing tool, such as Microsoft Word. Similarly, in the same way that the Run dialog box can accept an executable file name with or without the .exe extension, the .exe extension is optional in the fileName parameter. For example, you can set the fileName parameter to either "Notepad.exe" or "Notepad".
      /// @remarks This overload does not allow command-line arguments for the process. If you need to specify one or more command-line arguments for the process, use the xtd::diagnostics::process::start(xtd::diagnostics::process_start_info) or xtd::diagnostics::process::start(std::string, std::string) overloads.
      /// @remarks Unlike the other overloads, the overload of xtd::diagnostics::process::start that has no parameters is not a static member. Use that overload when you have already created a Process instance and specified start information (including the file name), and you want to start a process resource and associate it with the existing Process instance. Use one of the static overloads when you want to create a new xtd::diagnostics::process component rather than start a process for an existing component. Both this overload and the overload that has no parameters allow you to specify the file name of the process resource to start.
      /// @remarks If you have a path variable declared in your system using quotes, you must fully qualify that path when starting any process found in that location. Otherwise, the system will not find the path. For example, if c:\mypath is not in your path, and you add it using quotation marks: path = %path%;"c:\mypath", you must fully qualify any process in c:\mypath when starting it.
      /// @remarks Whenever you use xtd::diagnostics::process::start to start a process, you might need to close it or you risk losing system resources. Close processes using xtd::diagnostics::process::close_main_window or xtd::diagnostics::process::kill. You can check whether a process has already been closed by using its xtd::diagnostics::process::has_exited property.
      static process start(const std::string& file_name);
      /// @brief Starts a process resource by specifying the name of an application and a set of command-line arguments, and associates the resource with a new xtd::diagnostics::process component.
      /// @param fille_name The name of a document or application file to run in the process.
      /// @param arguments Command-line arguments to pass when starting the process.
      /// @return A new xtd::diagnostics::process that is associated with the process resource. Note that a new process that's started alongside already running instances of the same process will be independent from the others. In addition, Start may return a xtd::diagnostics::process with its xtd::diagnostics::process::has_exited property already set to true. In this case, the started process may have activated an existing instance of itself and then exited.
      /// @exception xtd::invalid_operation_exception No file name was specified in the filen_ame parameter's xtd::diagnostics::process_start_info::file_name property.
      /// @remarks Use this overload to start a process resource by specifying its file name and command-line arguments. The overload associates the resource with a new xtd::diagnostics::process object.
      /// @remarks This overload lets you start a process without first creating a new xtd::diagnostics::process instance. The overload is an alternative to the explicit steps of creating a new xtd::diagnostics::process instance, setting the file_name and arguments members of the xtd::diagnostics::process_start_info property, and calling xtd::diagnostics::process::start for the xtd::diagnostics::process instance.
      /// @remarks Starting a process by specifying its file name and arguments is similar to typing the file name and command-line arguments in the Run dialog box of the Windows Start menu. Therefore, the file name does not need to represent an executable file. It can be of any file type for which the extension has been associated with an application installed on the system. For example the file name can have a .txt extension if you have associated text files with an editor, such as Notepad, or it can have a .doc if you have associated .doc files with a word processing tool, such as Microsoft Word. Similarly, in the same way that the Run dialog box can accept an executable file name with or without the .exe extension, the .exe extension is optional in the file_name parameter. For example, you can set the file_name parameter to either "Notepad.exe" or "Notepad". If the file_name parameter represents an executable file, the arguments parameter might represent a file to act upon, such as the text file in Notepad.exe myfile.txt. If the file_name parameter represents a command (.cmd) file, the arguments parameter must include either a "/c" or "/k" argument to specify whether the command window exits or remains after completion.
      /// @remarks Unlike the other overloads, the overload of xtd::diagnostics::process::start that has no parameters is not a static member. Use that overload when you have already created a xtd::diagnostics::process instance and specified start information (including the file name), and you want to start a process resource and associate it with the existing Process instance. Use one of the static overloads when you want to create a new Process component rather than start a process for an existing component. Both this overload and the overload that has no parameters allow you to specify the file name of the process resource to start and command-line arguments to pass.
      /// @remarks If you have a path variable declared in your system using quotes, you must fully qualify that path when starting any process found in that location. Otherwise, the system will not find the path. For example, if c:\mypath is not in your path, and you add it using quotation marks: path = %path%;"c:\mypath", you must fully qualify any process in c:\mypath when starting it.
      /// @remarks Whenever you use xtd::diagnostics::process::start to start a process, you might need to close it or you risk losing system resources. Close processes using xtd::diagnostics::process::close_main_window or Kill. You can check whether a process has already been closed by using its xtd::diagnostics::process::has_exited property.
      static process start(const std::string& file_name, const std::string& arguments);

      /// @brief Instructs the xtd::diagnostics::process component to wait indefinitely for the associated process to exit.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks xtd::diagnostics::process::wait_for_exit() makes the current thread wait until the associated process terminates. It should be called after all other methods are called on the process. To avoid blocking the current thread, use the xtd::diagnostics::process::exited event.
      /// @remarks This method instructs the xtd::diagnostics::process component to wait an infinite amount of time for the process and event handlers to exit. This can cause an application to stop responding. For example, if you call td::diagnostics::process::close_main_window for a process that has a user interface, the request to the operating system to terminate the associated process might not be handled if the process is written to never enter its message loop.
      /// @remarks This overload ensures that all processing has been completed, including the handling of asynchronous events for redirected standard output. You should use this overload after a call to the xtd::diagnostics::process::wait_for_exit(int32_t) overload when standard output has been redirected to asynchronous event handlers.
      /// @remarks When an associated process exits (that is, when it is shut down by the operation system through a normal or abnormal termination), the system stores administrative information about the process and returns to the component that had called xtd::diagnostics::process::wait_for_exit(). The xtd::diagnostics::process component can then access the information, which includes the xtd::diagnostics::process::exit_time, by using the xtd::diagnostics::process::handle to the exited process.
      /// @remarks Because the associated process has exited, the Handle property of the component no longer points to an existing process resource. Instead, the handle can be used only to access the operating system's information about the process resource. The system is aware of handles to exited processes that have not been released by xtd::diagnostics::process components, so it keeps the xtd::diagnostics::process::exit_time and xtd::diagnostics::process::handle information in memory until the xtd::diagnostics::process component specifically frees the resources. For this reason, any time you call xtd::diagnostics::process::start for a xtd::diagnostics::process instance, call xtd::diagnostics::process::close when the associated process has terminated and you no longer need any administrative information about it. xtd::diagnostics::process::close frees the memory allocated to the exited process.
      process& wait_for_exit();
      
      /// @brief Instructs the Process component to wait the specified number of milliseconds for the associated process to exit.
      /// @param milliseconds The amount of time, in milliseconds, to wait for the associated process to exit. A value of 0 specifies an immediate return, and a value of -1 specifies an infinite wait.The amount of time, in milliseconds, to wait for the associated process to exit. A value of 0 specifies an immediate return, and a value of -1 specifies an infinite wait.
      /// @exception xtd::invalid_operation_exception There is no process associated with this xtd::diagnostics::processs object.
      /// @remarks xtd::diagnostics::process::wait_for_exit() makes the current thread wait until the associated process terminates. It should be called after all other methods are called on the process. To avoid blocking the current thread, use the xtd::diagnostics::process::exited event.
      /// @remarks This method instructs the xtd::diagnostics::process component to wait an infinite amount of time for the process and event handlers to exit. This can cause an application to stop responding. For example, if you call td::diagnostics::process::close_main_window for a process that has a user interface, the request to the operating system to terminate the associated process might not be handled if the process is written to never enter its message loop.
      /// @remarks This overload ensures that all processing has been completed, including the handling of asynchronous events for redirected standard output. You should use this overload after a call to the xtd::diagnostics::process::wait_for_exit(int32_t) overload when standard output has been redirected to asynchronous event handlers.
      /// @remarks When an associated process exits (that is, when it is shut down by the operation system through a normal or abnormal termination), the system stores administrative information about the process and returns to the component that had called xtd::diagnostics::process::wait_for_exit(). The xtd::diagnostics::process component can then access the information, which includes the xtd::diagnostics::process::exit_time, by using the xtd::diagnostics::process::handle to the exited process.
      /// @remarks Because the associated process has exited, the Handle property of the component no longer points to an existing process resource. Instead, the handle can be used only to access the operating system's information about the process resource. The system is aware of handles to exited processes that have not been released by xtd::diagnostics::process components, so it keeps the xtd::diagnostics::process::exit_time and xtd::diagnostics::process::handle information in memory until the xtd::diagnostics::process component specifically frees the resources. For this reason, any time you call xtd::diagnostics::process::start for a xtd::diagnostics::process instance, call xtd::diagnostics::process::close when the associated process has terminated and you no longer need any administrative information about it. xtd::diagnostics::process::close frees the memory allocated to the exited process.
      process& wait_for_exit(int32_t milliseconds);
      
      /// @brief Occurs when an application writes to its redirected xtd::diagnostics::process::standard_error stream.
      /// @remarks The xtd::diagnostics::process::error_data_received event indicates that the associated xtd::diagnostics::process has written a line that's terminated with a newline (carriage return (CR), line feed (LF), or CR+LF) to its redirected xtd::diagnostics::process::standard_error stream.
      /// @remarks The event only occurs during asynchronous read operations on xtd::diagnostics::process::standard_error. To start asynchronous read operations, you must redirect the xtd::diagnostics::process::standard_error stream of a xtd::diagnostics::process, add your event handler to the xtd::diagnostics::process::error_data_received event, and call xtd::diagnostics::process::begin_error_read_line. Thereafter, the xtd::diagnostics::process::error_data_received event signals each time the process writes a line to the redirected xtd::diagnostics::process::standard_error stream, until the process exits or calls xtd::diagnostics::process::cancel_error_read.
      /// @note The application that is processing the asynchronous output should call the xtd::diagnostics::process::wait_forE_exit() method to ensure that the output buffer has been flushed. Note that specifying a timeout by using the xtd::diagnostics::process::wait_for_exit(int32_t) overload does not ensure the output buffer has been flushed.
      error_data_received_event error_data_recaived;
      
      /// @brief Occurs when a process exits.
      /// @remarks The exited event indicates that the associated process exited. This occurrence means either that the process terminated (aborted) or successfully closed. This event can occur only if the value of the EnableRaisingEvents property is true.
      /// @remarks There are two ways of being notified when the associated process exits: synchronously and asynchronously. Synchronous notification means calling the xtd::diagnostics::process::wait_for_exit method to block the current thread until the process exits. Asynchronous notification uses the xtd::diagnostics::process::exited event, which allows the calling thread to continue execution in the meantime. In the latter case, xtd::diagnostics::process::enable_raising_events must be set to true for the calling application to receive the xtd::diagnostics::process::exited event.
      /// @remarks When the operating system shuts down a process, it notifies all other processes that have registered handlers for the xtd::diagnostics::process::exited event. At this time, the handle of the process that just exited can be used to access some properties such as xtd::diagnostics::process::exit_time and xtd::diagnostics::process::has_exited that the operating system maintains until it releases that handle completely.
      /// @note Even if you have a handle to an exited process, you cannot call xtd::diagnostics::process::start again to reconnect to the same process. Calling xtd::diagnostics::process::start automatically releases the associated process and connects to a process with the same file but an entirely new xtd::diagnostics::process::handle.
      exit_event exited;
      
      /// @brief Occurs each time an application writes a line to its redirected xtd::diagnostics::process::standard_output stream.
      /// @remarks The xtd::diagnostics::process::output_data_received event indicates that the associatedxtd::diagnostics::process has written a line that's terminated with a newline (carriage return (CR), line feed (LF), or CR+LF) to its redirected xtd::diagnostics::process::standard_output stream.
      /// @remarks The event is enabled during asynchronous read operations on xtd::diagnostics::process::standard_output. To start asynchronous read operations, you must redirect the standard_output stream of a xtd::diagnostics::process, add your event handler to the xtd::diagnostics::process::Output_data_received event, and call xtd::diagnostics::process::begin_output_read_line. Thereafter, the xtd::diagnostics::process::output_dData_rReceived event signals each time the process writes a line to the redirected xtd::diagnostics::process::standard_output stream, until the process exits or calls xtd::diagnostics::process::cancel_output_read.
      /// @note The application that is processing the asynchronous output should call the WaitForExit method to ensure that the output buffer has been flushed.
      output_data_received_event output_data_recaived;
      
    protected:
      /// @brief Raises the xtd::diagnostics::process::exited event.
      /// @remarks xtd::diagnostics::process::on_exited is the API method that raises the xtd::diagnostics::process::exited event. Calling xtd::diagnostics::process::on_exited causes the xtd::diagnostics::process::exited event to occur and is the only way to raise the event using the Process component. xtd::diagnostics::process::on_exited is primarily used when deriving classes from the component.
      /// @remarks As an alternative to xtd::diagnostics::process::xtd::diagnostics::process::on_eExited, you can write your own event handler. You create your own event handler delegate and your own event-handling method.
      virtual void on_exited();
      
    private:
      struct data {
        xtd::diagnostics::process_start_info start_info_;
        std::optional<intptr_t> handle_ = 0;
        int32_t id_ = 0;
        std::string machine_name_;
        xtd::diagnostics::process_priority_class priority_class_ = xtd::diagnostics::process_priority_class::normal;
        std::unique_ptr<std::ostream> standard_input_;
        std::unique_ptr<std::istream> standard_output_;
        std::unique_ptr<std::istream> standard_error_;
        std::thread thread_;
        process::time_point start_time_;
        process::time_point exit_time_;
        bool enable_raising_events_ = false;
        std::optional<int32_t> exit_code_;
        event_handler<process&> exit_callback_;
        data_received_event_handler<process&> error_data_received_callback_;
        data_received_event_handler<process&> output_data_received_callback_;
        std::exception_ptr exception_pointer_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
      friend __init_process_message_box_message__;
      inline static xtd::delegate<void(const std::string&)> message_box_message_;
    };
  }
}
