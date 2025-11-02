/// @file
/// @brief Contains xtd::threading::jthread class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "thread.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Creates and controls an automatically rejoins on destruction thread, sets its priority, and gets its status.
    /// ```cpp
    /// class core_export_ jthread final : public xtd::threading::thread
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::threading::jthread
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/jthread>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example shows how to use xtd::threading::jthread.
    /// @include jthread.cpp
    /// @remarks When a process starts, the system automatically creates a single foreground thread to execute application code. Along with this main foreground thread, a process can create one or more threads to execute a portion of the program code associated with the process. These threads can execute either in the foreground or in the background. In addition, you can use the xtd::threading::thread_pool class to execute code on worker threads that are managed by the framework xrd.
    /// @remarks An xtd::threading::jthread object is identical to an xtd::threading::thread whose xtd::threading::thread::auto_join property is set to `true`.
    class core_export_ jthread final : public xtd::threading::thread {
    public:
      /// @name Cosntructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::jthread class, specifying a delegate that allows an object to be passed to the thread when the thread is started.
      /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
      /// @exception xtd::argument_exception The start parameter is empty.
      /// @remarks A thread does not begin executing when it is created. To schedule the thread for execution, call the xtd::threading::jthread::start method. To pass a data object to the thread, use the xtd::threading::jthread::start(const xtd::any_object&) method overload.
      explicit jthread(const xtd::threading::parameterized_thread_start& start);
      /// @brief Initializes a new instance of the xtd::threading::jthread class, specifying a delegate that allows an object to be passed to the thread when the thread is started and specifying the maximum stack size for the thread.
      /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
      /// @param max_stack_size The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.<br>Important For partially trusted code, max_stack_size is ignored if it is greater than the default stack size. No exception is thrown.
      /// @exception xtd::argument_exception The start parameter is empty.
      /// @remarks A thread does not begin executing when it is created. To schedule the thread for execution, call the xtd::threading::jthread::start method. To pass a data object to the thread, use the xtd::threading::jthread::start(const xtd::any_object&) method overload.
      jthread(const xtd::threading::parameterized_thread_start& start, int32 max_stack_size);
      /// @brief Initializes a new instance of the xtd::threading::jthread class.
      /// @param start A xtd::threading::thread_start delegate that represents the methods to be invoked when this thread begins executing.
      /// @param max_stack_size The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.<br>Important For partially trusted code, max_stack_size is ignored if it is greater than the default stack size. No exception is thrown.
      /// @exception xtd::argument_exception The start parameter is empty.
      /// @remarks A thread does not begin executing when it is created. To schedule the thread for execution, call the xtd::threading::jthread::start method.
      explicit jthread(const xtd::threading::thread_start& start);
      /// @brief Initializes a new instance of the xtd::threading::jthread class, specifying the maximum stack size for the thread.
      /// @param start A xtd::threading::thread_start delegate that represents the methods to be invoked when this thread begins executing.
      /// @param max_stack_size The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.<br>Important For partially trusted code, max_stack_size is ignored if it is greater than the default stack size. No exception is thrown.
      /// @exception xtd::argument_exception The start parameter is empty.
      /// @remarks A thread does not begin executing when it is created. To schedule the thread for execution, call the xtd::threading::jthread::start method.
      jthread(const xtd::threading::thread_start& start, int32 max_stack_size);
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Create and immedialtely start a xtd::threading::jthread with specified method.
      /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
      /// @exception xtd::argument_exception The start parameter is empty.
      static jthread start_new(const xtd::threading::thread_start& start);
      /// @brief Create and immedialtely start a xtd::threading::jthread with specified method.
      /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
      /// @param obj An object that contains data to be used by the method the thread executes.
      /// @exception xtd::argument_exception The start parameter is empty.
      static jthread start_new(const xtd::threading::parameterized_thread_start& start, const xtd::any_object& obj);
      /// @}
      
      /// @cond
      jthread();
      template<class start_t>
      jthread(start_t start) : jthread(parameterized_thread_start {start}) {}
      template<class start_t>
      jthread(start_t start, int32 max_stack_size) : jthread(parameterized_thread_start {start}, max_stack_size) {}
      jthread(jthread&&) = default;
      jthread(const jthread&) = default;
      jthread& operator=(const jthread&) = default;
      template<class start_t>
      
      static jthread start_new(start_t start) {return start_new(thread_start {start});}
      template<class start_t>
      inline static jthread start_new(start_t start, const xtd::any_object& obj) {return start_new(parameterized_thread_start {start}, obj);}
      /// @endcond
      
    private:
      using thread::auto_join;
    };
  }
}
