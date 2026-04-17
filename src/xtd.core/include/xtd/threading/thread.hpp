/// @file
/// @brief Contains xtd::threading::thread class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "parameterized_thread_start.hpp"
#include "wait_handle.hpp"
#include "thread_priority.hpp"
#include "thread_start.hpp"
#include "thread_state.hpp"
#include "../as.hpp"
#include "../core_export.hpp"
//#include "../date_time.hpp"
#include "../intptr.hpp"
#include "../object.hpp"
#include "../time_span.hpp"
#include "../types.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class date_time;
  /// @endcond
  
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @cond
    class thread_pool;
    /// @endcond
    
    /// @brief Creates and controls a thread, sets its priority, and gets its status.
    /// ```cpp
    /// class core_export_ thread : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::threading::thread
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/thread>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example demonstrates simple threading functionality.
    /// @include thread.cpp
    /// @remarks When a process starts, the system automatically creates a single foreground thread to execute application code. Along with this main foreground thread, a process can create one or more threads to execute a portion of the program code associated with the process. These threads can execute either in the foreground or in the background. In addition, you can use the xtd::threading::thread_pool class to execute code on worker threads that are managed by the framework xrd.
    class core_export_ thread : public object {
      struct data;
      
      struct static_data;
      
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Represents an invalid native operating system handle. This field is read-only.
      /// @remarks Used internally to initialize the xtd::thread::wait_handle::handle property.
      static const intptr invalid_handle;
      
      /// @brief Represents an invalid native operating system thread id. This field is read-only.
      /// @remarks Used internally to initialize the xtd::threading::thread::thread_id property.
      static const intptr invalid_thread_id;
      /// @}
      
      /// @name Cosntructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::thread class, specifying a delegate that allows an object to be passed to the thread when the thread is started.
      /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
      /// @exception xtd::argument_exception The start parameter is empty.
      /// @remarks A thread does not begin executing when it is created. To schedule the thread for execution, call the xtd::threading::thread::start method. To pass a data object to the thread, use the xtd::threading::thread::start(const xtd::any_object&) method overload.
      explicit thread(const xtd::threading::parameterized_thread_start& start);
      /// @brief Initializes a new instance of the xtd::threading::thread class, specifying a delegate that allows an object to be passed to the thread when the thread is started and specifying the maximum stack size for the thread.
      /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
      /// @param max_stack_size The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.<br>Important For partially trusted code, max_stack_size is ignored if it is greater than the default stack size. No exception is thrown.
      /// @exception xtd::argument_exception The start parameter is empty.
      /// @remarks A thread does not begin executing when it is created. To schedule the thread for execution, call the xtd::threading::thread::start method. To pass a data object to the thread, use the xtd::threading::thread::start(const xtd::any_object&) method overload.
      thread(const xtd::threading::parameterized_thread_start& start, int32 max_stack_size);
      /// @brief Initializes a new instance of the xtd::threading::thread class.
      /// @param start A xtd::threading::thread_start delegate that represents the methods to be invoked when this thread begins executing.
      /// @param max_stack_size The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.<br>Important For partially trusted code, max_stack_size is ignored if it is greater than the default stack size. No exception is thrown.
      /// @exception xtd::argument_exception The start parameter is empty.
      /// @remarks A thread does not begin executing when it is created. To schedule the thread for execution, call the xtd::threading::thread::start method.
      explicit thread(const xtd::threading::thread_start& start);
      /// @brief Initializes a new instance of the xtd::threading::thread class, specifying the maximum stack size for the thread.
      /// @param start A xtd::threading::thread_start delegate that represents the methods to be invoked when this thread begins executing.
      /// @param max_stack_size The maximum stack size, in bytes, to be used by the thread, or 0 to use the default maximum stack size specified in the header for the executable.<br>Important For partially trusted code, max_stack_size is ignored if it is greater than the default stack size. No exception is thrown.
      /// @exception xtd::argument_exception The start parameter is empty.
      /// @remarks A thread does not begin executing when it is created. To schedule the thread for execution, call the xtd::threading::thread::start method.
      thread(const xtd::threading::thread_start& start, int32 max_stack_size);
      /// @}
      
      /// @cond
      thread();
      template<typename start_t>
      explicit thread(start_t start) : thread(parameterized_thread_start {start}) {}
      template<typename start_t>
      thread(start_t start, int32 max_stack_size) : thread(parameterized_thread_start {start}, max_stack_size) {}
      thread(thread&&) = default;
      thread(const thread&) = default;
      auto operator=(thread&&) -> thread& = default;
      auto operator=(const thread&) -> thread&;
      ~thread();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating the current thread wiil be joined when destroyed.
      /// @return `true` if this thread will be joined when destroyed; otherwise, `false`.
      [[nodiscard]] auto auto_join() const noexcept -> bool;
      /// @brief Sets a value indicating the current thread wiil be joined when destroyed.
      /// @param value `true` if this thread will be joined when destroyed; otherwise, `false`.
      /// @return The xtd::threading::thread current instance.
      auto auto_join(bool value) -> thread&;
      
      /// @brief Gets the native operating system handle.
      /// @return An intptr representing the native operating system handle.
      [[nodiscard]] auto handle() const noexcept -> intptr;
      
      /// @brief Gets a value indicating the execution status of the current thread.
      /// @return `true` if this thread has been started and has not terminated normally or aborted; otherwise, `false`.
      [[nodiscard]] auto is_alive() const noexcept -> bool;
      
      /// @brief Gets a value indicating whether or not a thread is a background thread.
      /// @return `true` if this thread is or is to become a background thread; otherwise, `false`.
      /// @exception xtd::threadng::thread_state_exception The thread is dead.
      /// @remarks A thread is either a background thread or a foreground thread. Background threads are identical to foreground threads, except that background threads do not prevent a process from terminating. Once all foreground threads belonging to a process have terminated, the system ends the process. Any remaining background threads are stopped and do not complete.
      /// @remarks By default, the following threads execute in the foreground (that is, their xtd::threading::thread::is_background property returns false):
      /// * The primary thread (or main application thread).
      /// * All threads created by calling a xtd::threading::thread class constructor.
      /// @remarks By default, the following threads execute in the background (that is, their xtd::threading::thread::is_background property returns `true`):
      /// * Thread pool threads, which are a pool of worker threads maintained by the runtime. You can configure the thread pool and schedule work on thread pool threads by using the xtd::threading::thread_pool class.
      /// * All threads create without xtd::threading::thread class (std::thread or threads create by oparating system API).
      [[nodiscard]] auto is_background() const noexcept -> bool;
      /// @brief Sets a value indicating whether or not a thread is a background thread.
      /// @param value `true` if this thread is or is to become a background thread; otherwise, `false`.
      /// @return The xtd::threading::thread current instance.
      /// @exception xtd::threadng::thread_state_exception The thread is dead.
      /// @remarks A thread is either a background thread or a foreground thread. Background threads are identical to foreground threads, except that background threads do not prevent a process from terminating. Once all foreground threads belonging to a process have terminated, the system ends the process. Any remaining background threads are stopped and do not complete.
      /// @remarks By default, the following threads execute in the foreground (that is, their xtd::threading::thread::is_background property returns `false`):
      /// * The primary thread (or main application thread).
      /// * All threads created by calling a xtd::threading::thread class constructor.
      /// @remarks By default, the following threads execute in the background (that is, their xtd::threading::thread::is_background property returns `true`):
      /// * Thread pool threads, which are a pool of worker threads maintained by the runtime. You can configure the thread pool and schedule work on thread pool threads by using the xtd::threading::thread_pool class.
      /// * All threads create without xtd::threading::thread class (std::thread or threads create by oparating system API).
      auto is_background(bool value) -> thread&;
      
      /// @brief Gets a value indicating the current thread is the main thread.
      /// @return `true` if this thread is the main thread; otherwise, `false`.
      [[nodiscard]] auto is_main_thread() const noexcept -> bool;
      
      /// @brief Gets a value indicating whether or not a thread belongs to the managed thread pool.
      /// @return `true` if this thread belongs to the managed thread pool; otherwise, `false`.
      /// @remarks For more information see xtd::threading::thread_pool.
      [[nodiscard]] auto is_thread_pool_thread() const noexcept -> bool;
      
      /// @brief Gets a value indicating the current thread is joinable.
      /// @return `true` if this thread is joinable; otherwise, `false`.
      /// @remarks A thread is joinable if it started, not stopped and if is not a background thread.
      /// @remarks if the thread is joinable you can call the xtd::threading::thread::join method.
      [[nodiscard]] auto joinable() const noexcept -> bool;
      
      /// @brief Gets a unique identifier for the current managed thread.
      /// @return An integer that represents a unique identifier for this managed thread.
      /// @remarks A thread's xtd::threading::thread::managed_thread_id property value serves to uniquely identify that thread within its process.
      /// @remarks The value of the xtd::threading::thread::managed_thread_id property does not vary over time
      [[nodiscard]] auto managed_thread_id() const noexcept -> int32;
      
      /// @brief Gets the name of the thread.
      /// @return A string containing the name of the thread, or empty ("") if no name was set.
      [[nodiscard]] auto name() const noexcept -> string;
      /// @brief Sets the name of the thread.
      /// @param value A string containing the name of the thread, or empty ("") if no name was set.
      /// @return The xtd::threading::thread current instance.
      auto name(const string& value) -> thread&;
      
      /// @brief Gets a value indicating the scheduling priority of a thread.
      /// @return One of the xtd::threading::thread_priority values. The default value is xtd::threading::thread_priority::normal.
      /// @exception xtd::threading::thread_state_exception The thread has reached a final state, such as Aborted.
      /// @exception xtd::argument_exception The value specified for a set operation is not a valid xtd::threading::thread_priority value.
      /// @remarks A thread can be assigned any one of the following priority xtd::threading::thread_priority values:
      /// * highest
      /// * above_normal
      /// * normal
      /// * below_normal
      /// * lowest
      [[nodiscard]] auto priority() const noexcept -> xtd::threading::thread_priority;
      /// @brief Sets a value indicating the scheduling priority of a thread.
      /// @param value One of the xtd::threading::thread_priority values. The default value is xtd::threading::thread_priority::normal.
      /// @exception xtd::threading::thread_state_exception The thread has reached a final state, such as Aborted.
      /// @exception xtd::argument_exception The value specified for a set operation is not a valid xtd::threading::thread_priority value.
      /// @remarks A thread can be assigned any one of the following priority xtd::threading::thread_priority values:
      /// * highest
      /// * above_normal
      /// * normal
      /// * below_normal
      /// * lowest
      auto priority(xtd::threading::thread_priority value) -> thread&;
      
      /// @brief Gets the processors on which the associated thread can run.
      /// @return An xtd::array<xtd::usize> that represents an array of processor numbers on which the thread can run.
      /// @exception xtd::threading::thread_state_exception The thread has reached a final state, such as Aborted.
      /// @remarks If the array is empty, no affinity is defined.
      /// @remarks Works only on Windows and Linux operating syetms, no effect on others.
      [[nodiscard]] auto processor_affinity() const noexcept -> const xtd::array<xtd::usize>&;
      /// @brief Sets the processors on which the associated thread can run.
      /// @param value An xtd::array<xtd::usize> that represents an array of processor numbers on which the thread can run.
      /// @exception xtd::threading::thread_state_exception The thread has reached a final state, such as Aborted.
      /// @remarks If the array is empty, no affinity is defined.
      /// @remarks Works only on Windows and Linux operating syetms, no effect on others.
      auto processor_affinity(const xtd::array<xtd::usize>& value) -> thread&;
      
      /// @brief Gets the native operating system thread id.
      /// @return An intptr representing the native operating thread id.
      /// @remarks if the thread is not started this method return xtd::threading::thread::invalid_thread_id.
      [[nodiscard]] auto thread_id() const noexcept -> intptr;
      
      /// @brief Gets a value containing the states of the current thread.
      /// @return One of the xtd::threading::thread_state values indicating the state of the current thread. The initial value is xtd::threading::thread_state::unstarted.
      /// @remarks The xtd::threading::thread::thread_state property provides more specific information than the xtd::threading::thread::is_alive property.
      /// @warning Thread state is only of interest in debugging scenarios. Your code should never use thread state to synchronize the activities of threads.
      [[nodiscard]] auto thread_state() const noexcept -> xtd::threading::thread_state;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets the currently running thread.
      /// @return A xtd::threading::thread that is the representation of the currently running thread.
      [[nodiscard]] static auto current_thread() noexcept -> thread&;
      
      /// @brief Gets the main thread.
      /// @return A xtd::threading::thread that is the representation of the main thread.
      /// @remarks if the thread is not started this method return xtd::threading::thread::invalid_handle.
      [[nodiscard]] static auto main_thread() -> thread&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Raises a xtd::threading::thread_aborted_exception in the thread on which it is invoked, to begin the process of terminating the thread. Calling this method usually terminates the thread.
      /// @exception xtd::threading::thread_aborted_exception The thread that is being aborted is currently suspended.
      auto abort() -> void;
      
      /// @brief Sets the thread background.
      /// @remarks This method is identical to the call to xtd::threading::thread::is_background(true).
      auto detach() -> void;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      /// @brief Interrupts a thread that is in the xtd::threading::thread_state::wait_sleep_join thread state.
      /// @remarks If this thread is not currently blocked in a thread_state::wait, thread_state::sleep, or thread_state::join state, it will be interrupted when it next begins to block.
      /// @remarks xtd::threading::thread_interrupted_exception is thrown in the interrupted thread, but not until the thread blocks. If the thread never blocks, the exception is never thrown, and thus the thread might complete without ever being interrupted.
      auto interrupt() -> void;
      
      /// @brief Blocks the calling thread until this thread object terminates, while continuing to perform standard COM and SendMessage pumping.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      auto join() -> void;
      
      /// @brief Blocks the calling thread until this thread object terminates or the specified time elapses, while continuing to perform standard COM and SendMessage pumping.
      /// @param milliseconds_timeout The number of milliseconds to wait for the thread to terminate.
      /// @return `true` if the thread has terminated; `false` if the thread has not terminated after the amount of time specified by the xtd::milliseconds_timeout parameter has elapsed.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      /// @exception xtd::argument_out_of_range_rxception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      auto join(int32 milliseconds_timeout) -> bool;
      
      /// @brief Blocks the calling thread until this thread object terminates or the specified time elapses, while continuing to perform standard COM and SendMessage pumping.
      /// @param timeout A xtd::time_span set to the amount of time to wait for the thread to terminate.
      /// @return `true` if the thread has terminated; `false` if the thread has not terminated after the amount of time specified by the xtd::milliseconds_timeout parameter has elapsed.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      /// @exception xtd::argument_exception timeout is a negative number other than -1 milliseconds, which represents <br>-or-<br> timeout is greater than xtd::int32_object::max_value.
      auto join(const time_span& timeout) -> bool;
      
      /// @brief Resumes a thread that has been suspended (Should not be used).
      /// @exception xtd::threading::thread_state_exception The thread has not been started, is dead, or is not in the suspended state.
      /// @remarks Works only on Windows operating syetm.
      /// @warning Do not use the xtd::threading::thread::suspend and xtd::threading::thread::resume methods to synchronize the activities of threads. You have no way of knowing what code a thread is executing when you suspend it. If you suspend a thread while it holds locks during a security permission evaluation, other threads in the application might be blocked. If you suspend a thread while it is executing a class constructor, other threads in the application that attempt to use that class are blocked. Deadlocks can occur very easily.
      auto resume() -> void;
      
      /// @brief Causes the operating system to change the state of the current instance to xtd::threading::thread_state::running.
      /// @exception xtd::threading::thread_state_exception The thread has already been started.
      auto start() -> void;
      
      /// @brief Causes the operating system to change the state of the current instance to xtd::threading::thread_state::running.
      /// @param obj An object that contains data to be used by the method the thread executes.
      /// @exception xtd::threading::thread_state_exception The thread has already been started.
      auto start(const xtd::any_object& obj) -> void;
      
      /// @brief Either suspends the thread, or if the thread is already suspended, has no effect (Should not be used).
      /// @exception xtd::threading::thread_state_exception The thread has not been started or is dead.
      /// @remarks Works only on Windows operating syetm, no effect on others.
      /// @warning Do not use the xtd::threading::thread::suspend and xtd::threading::thread::resume methods to synchronize the activities of threads. You have no way of knowing what code a thread is executing when you suspend it. If you suspend a thread while it holds locks during a security permission evaluation, other threads in the application might be blocked. If you suspend a thread while it is executing a class constructor, other threads in the application that attempt to use that class are blocked. Deadlocks can occur very easily.
      auto suspend() -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Create and immedialtely start a xtd::threading::thread with specified method.
      /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
      /// @exception xtd::argument_exception The start parameter is empty.
      static auto start_new(const xtd::threading::thread_start& start) -> thread;
      /// @brief Create and immedialtely start a xtd::threading::thread with specified method.
      /// @param start A delegate that represents the methods to be invoked when this thread begins executing.
      /// @param obj An object that contains data to be used by the method the thread executes.
      /// @exception xtd::argument_exception The start parameter is empty.
      static auto start_new(const xtd::threading::parameterized_thread_start& start, const xtd::any_object& obj) -> thread;
      
      /// @brief Blocks the calling thread until all joinable threads terminate.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      /// @remarks If one or more threads are not joinable, they will be skipped.
      /// @remarks The xtd::startup::run method and #startup_ keyword call the xtd::threading::thread::join_all method.
      /// @remarks Call xtd::threading::thread_pool::close method to join the end of running worker threads too.
      static auto join_all() -> void;
      /// @brief Blocks the calling thread until all joinable threads terminate or the specified time elapses, while continuing.
      /// @param milliseconds_timeout The number of milliseconds to wait for all threads to terminate.
      /// @return `true` if all threads have terminated; `false` if all threads have not terminated after the amount of time specified by the timeout parameter has elapsed.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      /// @remarks If one or more threads are not joinable, they will be skipped.
      /// @remarks Call xtd::threading::thread_pool::close method to join the end of running worker threads too.
      static auto join_all(int32 milliseconds_timeout) -> bool;
      /// @brief Blocks the calling thread until all joinable threads terminate or the specified time elapses, while continuing.
      /// @param timeout A xtd::time_span set to the amount of time to wait for all threads to terminate.
      /// @return `true` if all threads have terminated; `false` if all threads have not terminated after the amount of time specified by the timeout parameter has elapsed.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      /// @remarks If one or more threads are not joinable, they will be skipped.
      /// @remarks Call xtd::threading::thread_pool::close method to join the end of running worker threads too.
      static auto join_all(const time_span& timeout) -> bool;
      
      /// @brief Blocks the calling thread until all specified joinable threads collection terminate.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      /// @remarks If one or more threads are not joinable, they will be skipped.
      template<typename collection_t>
      static auto join_all(const collection_t& threads) -> void {join_all(threads, timeout::infinite);}
      /// @brief Blocks the calling thread until all specified joinable threads collection terminate or the specified time elapses, while continuing.
      /// @param milliseconds_timeout The number of milliseconds to wait for all threads to terminate.
      /// @return `true` if all threads have terminated; `false` if all threads have not terminated after the amount of time specified by the timeout parameter has elapsed.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      /// @remarks If one or more threads are not joinable, they will be skipped.
      template<typename collection_t>
      static auto join_all(const collection_t& threads, int32 milliseconds_timeout) -> bool {
        auto thread_pointers = xtd::array<thread*> {};
        for (auto& item : threads)
          thread_pointers.resize(thread_pointers.length() + 1, const_cast<thread*>(&item));
        return join_all_ptr(thread_pointers, milliseconds_timeout);
      }
      /// @brief Blocks the calling thread until all specified joinable threads collection terminate or the specified time elapses, while continuing.
      /// @param timeout A xtd::time_span set to the amount of time to wait for all threads to terminate.
      /// @return `true` if all threads have terminated; `false` if all threads have not terminated after the amount of time specified by the timeout parameter has elapsed.
      /// @exception xtd::threading::thread_state_exception The caller attempted to join a thread that is in the xtd::threading::thread_state::unstarted state.
      /// @remarks If one or more threads are not joinable, they will be skipped.
      template<typename collection_t>
      static auto join_all(const collection_t& threads, const time_span& timeout) -> bool {return join_all(threads, as<int32>(timeout.total_milliseconds_duration().count()));}
      
      /// @brief Suspends the current thread for a specified time.
      /// @param milliseconds_timeout The number of milliseconds for which the thread is blocked. Specify zero (0) to indicate that this thread should be suspended to allow other waiting threads to execute. Specify xtd::threading::Timeout.Infinite to block the thread indefinitely.
      /// @exception xtd::argument_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      static auto sleep(int32 milliseconds_timeout) -> void;
      
      /// @brief Suspends the current thread for a specified time.
      /// @param timeout A std::chrono::duration set to the amount of time for which the thread is blocked. Specify zero to indicate that this thread should be suspended to allow other waiting threads to execute. Specify xtd::threading::Timeout.Infinite to block the thread indefinitely.
      /// @exception xtd::argument_exception The value of timeout is negative and is not equal to xtd::threading::timeout::infinite in milliseconds, or is greater than xtd::Int32.MaxValue milliseconds.
      static auto sleep(const time_span& timeout) -> void;
      
      /// @brief Causes a thread to wait the number of times defined by the iterations parameter.
      /// @param iterations A 32-bit signed integer that defines how long a thread is to wait.
      /// @remarks The xtd::threading::thread::spin_wait method is useful for implementing locks. Classes in the xtd, such as xtd::threading::monitor and xtd::threading::reader_writer_lock, use this method internally. xtd::threading::thread::spin_wait essentially puts the processor into a very tight loop, with the loop count specified by the iterations parameter. The duration of the wait therefore depends on the speed of the processor.
      /// @remarks Contrast this with the xtd::threading::thread::sleep method. A thread that calls xtd::threading::thread::sleep yields the rest of its current slice of processor time, even if the specified interval is zero. Specifying a non-zero interval for xtd::threading::thread::sleep removes the thread from consideration by the thread scheduler until the time interval has elapsed.
      /// @remarks xtd::threading::thread::spin_wait is not generally useful for ordinary applications. In most cases, you should use the synchronization classes provided by the xtd Framework; for example, call xtd::threading::monitor::enter or a statement that wraps xtd::threading::thread::monitor::enter
      static auto spin_wait(int32 iterations) -> void;
      
      /// @brief Causes the calling thread to yield execution to another thread that is ready to run on the current processor. The operating system selects the thread to yield to.
      /// @return `true` if the operating system switched execution to another thread; otherwise, `false`.
      /// @remarks If this method succeeds, the rest of the thread's current time slice is yielded. The operating system schedules the calling thread for another time slice, according to its priority and the status of other threads that are available to run.
      /// @remarks yielding is limited to the processor that is executing the calling thread. The operating system will not switch execution to another processor, even if that processor is idle or is running a thread of lower priority. If there are no other threads that are ready to execute on the current processor, the operating system does not yield execution, and this method returns `false`.
      /// @remarks This method is equivalent to using platform invoke to call the native Win32 switch_to_thread function. You should call the xtd::threading::thread::yield method instead of using platform invoke, because platform invoke bypasses any custom threading behavior the host has requested.
      static auto yield() noexcept -> bool;
      /// @}
      
      /// @cond
      template<typename item_t>
      static auto join_all(const std::initializer_list<item_t>& threads) -> bool {return join_all(threads, timeout::infinite);}
      template<typename item_t>
      static auto join_all(const std::initializer_list<item_t>& threads, int32 milliseconds_timeout) -> bool {
        auto thread_pointers = xtd::array<thread*> {};
        for (auto& item : threads)
          thread_pointers.resize(thread_pointers.length() + 1, const_cast<thread*>(&item));
        return join_all_ptr(thread_pointers, milliseconds_timeout);
      }
      template<typename item_t>
      static auto join_all(const std::initializer_list<item_t>& threads, const time_span& timeout) -> bool {return join_all(threads, as<int32>(timeout.total_milliseconds_duration().count()));}
      static auto join_all(const std::initializer_list<xtd::sptr<thread>>& threads) -> bool;
      static auto join_all(const std::initializer_list<xtd::sptr<thread>>& threads, int32 milliseconds_timeout) -> bool;
      static auto join_all(const std::initializer_list<xtd::sptr<thread>>& threads, const time_span& timeout) -> bool;
      static auto join_all(const std::initializer_list<xtd::uptr<thread>>& threads) -> bool;
      static auto join_all(const std::initializer_list<xtd::uptr<thread>>& threads, int32 milliseconds_timeout) -> bool;
      static auto join_all(const std::initializer_list<xtd::uptr<thread>>& threads, const time_span& timeout) -> bool;
      static auto join_all(const xtd::array<xtd::sptr<thread>>& threads) -> bool;
      static auto join_all(const xtd::array<xtd::sptr<thread>>& threads, int32 milliseconds_timeout) -> bool;
      static auto join_all(const xtd::array<xtd::sptr<thread>>& threads, const time_span& timeout) -> bool;
      static auto join_all(const xtd::array<xtd::uptr<thread>>& threads) -> bool;
      static auto join_all(const xtd::array<xtd::uptr<thread>>& threads, int32 milliseconds_timeout) -> bool;
      static auto join_all(const xtd::array<xtd::uptr<thread>>& threads, const time_span& timeout) -> bool;
      template<typename start_t>
      static auto start_new(start_t start) -> thread {return start_new(thread_start {start});}
      template<typename start_t>
      static auto start_new(start_t start, const xtd::any_object& obj) -> thread {return start_new(parameterized_thread_start {start}, obj);}
      /// @endcond
      
    private:
      friend class thread_pool;
      friend class wait_handle;
      
      void close();
      static auto do_wait(wait_handle& wait_handle, int32 milliseconds_timeout) -> bool;
      [[nodiscard]] static auto generate_managed_thread_id() noexcept -> int32;
      [[nodiscard]] static auto get_current_thread_handle() -> intptr;
      [[nodiscard]] static auto get_current_thread_id() noexcept -> intptr;
      [[nodiscard]] static auto get_static_data() -> static_data&;
      [[nodiscard]] static auto get_thread(intptr thread_id) -> thread&;
      auto interrupt_internal() -> void;
      [[nodiscard]] auto is_aborted() const noexcept -> bool;
      [[nodiscard]] auto is_stopped() const noexcept -> bool;
      [[nodiscard]] auto is_suspended() const noexcept -> bool;
      auto is_thread_pool_thread(bool value) noexcept -> void;
      [[nodiscard]] auto is_unmanaged_thread() const noexcept -> bool;
      [[nodiscard]] auto is_unstarted() const noexcept -> bool;
      [[nodiscard]] auto is_wait_sleep_join() const noexcept -> bool;
      static auto join_all_ptr(const xtd::array<thread*>& threads, int32 milliseconds_timeout) -> bool;
      auto thread_proc() -> void;
      [[nodiscard]] static auto unmanaged_thread() -> thread&;
      
      static constexpr int32 main_managed_thread_id = 1;
      static constexpr int32 unmanaged_thread_id = 0;
      
      xtd::sptr<data> data_;
      static intptr main_thread_id_;
    };
  }
}

#include "this_thread.hpp"
