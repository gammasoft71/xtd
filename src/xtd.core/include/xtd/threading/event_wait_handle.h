/// @file
/// @brief Contains xtd::threading::event_wait_handle exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "event_reset_mode.h"
#include "wait_handle.h"
#include "../icomparable.h"
#include "../iequatable.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents a thread synchronization event.
    /// @code
    /// class event_wait_handle : public xtd::threading::wait_handle, public xtd::icomparable < xtd::threading::event_wait_handle >, public xtd::iequatable<xtd::threading::event_wait_handle>
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/event_wait_handle> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks The xtd::threading::event_wait_handle class allows threads to communicate with each other by signaling. Typically, one or more threads block on an xtd::threading::event_wait_handle until an unblocked thread calls the xtd::threading::event_wait_handle::set method, releasing one or more of the blocked threads. A thread can signal an xtd::threading::event_wait_handle and then block on it, by calling the static xtd::threading::wait_handle::signal_and_wait method.
    /// @note The xtd::threading::event_wait_handle class provides access to named system synchronization events.
    /// @remarks The behavior of an xtd::threading::event_wait_handle that has been signaled depends on its reset mode. An xtd::threading::event_wait_handle created with the xtd::threading::event_reset_mode::auto_reset flag resets automatically when signaled, after releasing a single waiting thread. An xtd::threading::event_wait_handle created with the xtd::threading::event_reset_mode::manual_reset flag remains signaled until its Reset method is called.
    /// @remarks Automatic reset events provide exclusive access to a resource. If an automatic reset event is signaled when no threads are waiting, it remains signaled until a thread attempts to wait on it. The event releases the thread and immediately resets, blocking subsequent threads.
    /// @remarks Manual reset events are like gates. When the event is not signaled, threads that wait on it will block. When the event is signaled, all waiting threads are released, and the event remains signaled (that is, subsequent waits do not block) until its xtd::threading::event_wait_handle::reset method is called. Manual reset events are useful when one thread must complete an activity before other threads can proceed.
    /// @remarks xtd::threading::event_wait_handle objects can be used with the static xtd::threading::wait_handle::wWait_all and xtd::threading::wait_handle::wait_any methods.
    /// @par Examples
    /// The following code example uses the xtd::threading::wait_handle::signal_and_wait(xtd::threading::wait_handle&, xtd::threading::wait_handle&) method overload to allow the main thread to signal a blocked thread and then wait until the thread finishes a task.<br><br>
    /// The example starts five threads and allows them to block on an xtd::threading::event_wait_handle created with the xtd::threading::event_reset_mode::auto_reset flag, then releases one thread each time the user presses the Enter key. The example then queues another five threads and releases them all using an xtd::threading::event_wait_handle created with the xtd::threading::event_reset_mode::manual_reset flag.
    /// @include event_wait_handle.cpp
    class core_export_ event_wait_handle : public wait_handle, public icomparable<event_wait_handle>, public iequatable<event_wait_handle> {
      class event_wait_handle_base;
      class named_event_wait_handle;
      class unnamed_event_wait_handle;
      struct data;
    
    public:
      /// @name Public Constructors
      
      /// @{
      event_wait_handle();
      /// @brief Initializes a new instance of the xtd::threading::event_wait_handle class, specifying whether the wait handle is initially signaled.
      /// @param initial_state true to set the initial state to signaled; false to set it to nonsignaled.
      /// @remarks The mode is set to xtd::threading::event_reset_mode::auto_reset and the name is empty string ("").
      explicit event_wait_handle(bool initial_state);
      /// @brief Initializes a new instance of the xtd::threading::event_wait_handle class, specifying the name.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @remarks The initial state is false and the mode is set to xtd::threading::event_reset_mode::auto_reset.
      explicit event_wait_handle(const ustring& name);
      /// @brief Initializes a new instance of the xtd::threading::event_wait_handle class, specifying whether the wait handle is initially signaled if created as a result of this call, whether it resets automatically or manually, the name of a system synchronization event, and a bool variable whose value after the call indicates whether the named system event was created.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @param created_new When this method returns, contains true if a local event was created (that is, if name is null or an empty string) or if the specified named system event was created; false if the specified named system event already existed. This parameter is passed uninitialized.
      event_wait_handle(const ustring& name, bool& created_new);
      /// @brief Initializes a new instance of the xtd::threading::event_wait_handle class, specifying whether the wait handle is initially signaled if created as a result of this call, and the name of a system synchronization event.
      /// @param initial_state true to set the initial state to signaled; false to set it to nonsignaled.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      event_wait_handle(bool initial_state, const ustring& name);
      /// @brief Initializes a new instance of the xtd::threading::event_wait_handle class, specifying whether the wait handle is initially signaled if created as a result of this call, the name of a system synchronization event, and a bool variable whose value after the call indicates whether the named system event was created.
      /// @param initial_state true to set the initial state to signaled; false to set it to nonsignaled.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @param created_new When this method returns, contains true if a local event was created (that is, if name is null or an empty string) or if the specified named system event was created; false if the specified named system event already existed. This parameter is passed uninitialized.
      event_wait_handle(bool initial_state, const ustring& name, bool& created_new);
      /// @brief Initializes a new instance of the xtd::threading::event_wait_handle class, specifying whether the wait handle is initially signaled, and whether it resets automatically or manually.
      /// @param initial_state true to set the initial state to signaled; false to set it to nonsignaled.
      /// @param mode One of the xtd::threading::event_reset_mode values that determines whether the event resets automatically or manually.
      /// @remarks If the initial state of the event is nonsignaled, threads that wait on the event will block. If the initial state is signaled, and the xtd::threading::event_reset_mode::manual_reset flag is specified for mode, threads that wait on the event will not block. If the initial state is signaled, and mode is xtd::threading::event_reset_mode::auto_reset, the first thread that waits on the event will be released immediately, after which the event will reset, and subsequent threads will block.
      /// @exception xtd::argument_excpetion The mode enum value was out of legal range.
      event_wait_handle(bool initial_state, event_reset_mode mode);
      /// @brief Initializes a new instance of the xtd::threading::event_wait_handle class, specifying whether the wait handle is initially signaled if created as a result of this call, whether it resets automatically or manually, and the name of a system synchronization event.
      /// @param initial_state true to set the initial state to signaled; false to set it to nonsignaled.
      /// @param mode One of the xtd::threading::event_reset_mode values that determines whether the event resets automatically or manually.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @exception xtd::argument_excpetion The mode enum value was out of legal range.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @exception xtd::io::path_to_long_exception The name is too long. Length restrictions may depend on the operating system or configuration.
      /// @remarks The name may be prefixed with Global\ or Local\ to specify a namespace. When the Global namespace is specified, the synchronization object may be shared with any processes on the system. When the Local namespace is specified, which is also the default when no namespace is specified, the synchronization object may be shared with processes in the same session. On Windows, a session is a login session, and services typically run in a different non-interactive session. On Unix-like operating systems, each shell has its own session. Session-local synchronization objects may be appropriate for synchronizing between processes with a parent/child relationship where they all run in the same session.
      /// @remarks If a name is provided and a synchronization object of the requested type already exists in the namespace, the existing synchronization object is opened. If a synchronization object of a different type already exists in the namespace, a xtd::threading::wait_handle_cannot_be_opened_exception is thrown. Otherwise, a new synchronization object is created.
      /// @remarks If a system event with the name specified for the name parameter already exists, the initialState parameter is ignored.
      /// @warning When using this constructor for named system events, specify false for initial_state. This constructor provides no way to determine whether a named system event was created, so you cannot make any assumptions about the state of the named event. To determine whether a named event was created, use the xtd::threading::event_wait_handle(bool, xtd::threading::event_reset_mode, xtd::utring, bool) constructor or the xtd::threading::event_wait_handle(bool, xtd::threading::event__reset_mode, xtd:string, bool) constructor.
      /// @remarks If the initial state of the event is nonsignaled, threads that wait on the event will block. If the initial state is signaled, and the xtd::threading::event_reset_mode::manual_reset flag is specified for mode, threads that wait on the event will not block. If the initial state is signaled, and mode is xtd::threading::event_reset_mode::auto_reset, the first thread that waits on the event will be released immediately, after which the event will reset, and subsequent threads will block.
      event_wait_handle(bool initial_state, event_reset_mode mode, const ustring& name);
      /// @brief Initializes a new instance of the xtd::threading::event_wait_handle class, specifying whether the wait handle is initially signaled if created as a result of this call, whether it resets automatically or manually, the name of a system synchronization event, and a bool variable whose value after the call indicates whether the named system event was created.
      /// @param initial_state true to set the initial state to signaled; false to set it to nonsignaled.
      /// @param mode One of the xtd::threading::event_reset_mode values that determines whether the event resets automatically or manually.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @param created_new When this method returns, contains true if a local event was created (that is, if name is null or an empty string) or if the specified named system event was created; false if the specified named system event already existed. This parameter is passed uninitialized.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @exception xtd::io::path_too_long_exception The name is too long. Length restrictions may depend on the operating system or configuration.
      /// @exception xtd::threading::wait_handle_cannot_be_opened_exception A synchronization object with the provided name cannot be created. A synchronization object of a different type might have the same name.
      /// @exception xtd::argument_exception The mode enum value was out of legal range.
      /// @remarks The name may be prefixed with Global\ or Local\ to specify a namespace. When the Global namespace is specified, the synchronization object may be shared with any processes on the system. When the Local namespace is specified, which is also the default when no namespace is specified, the synchronization object may be shared with processes in the same session. On Windows, a session is a login session, and services typically run in a different non-interactive session. On Unix-like operating systems, each shell has its own session. Session-local synchronization objects may be appropriate for synchronizing between processes with a parent/child relationship where they all run in the same session
      /// @remarks If a name is provided and a synchronization object of the requested type already exists in the namespace, the existing synchronization object is opened. If a synchronization object of a different type already exists in the namespace, a WaitHandleCannotBeOpenedException is thrown. Otherwise, a new synchronization object is created.
      /// @remarks If a system event with the name specified for the name parameter already exists, the initialState parameter is ignored. After calling this constructor, use the value in the variable specified for the ref parameter (ByRef parameter in Visual Basic)createdNew to determine whether the named system event already existed or was created.
      /// @remarks If the initial state of the event is nonsignaled, threads that wait on the event will block. If the initial state is signaled, and the xtd::threading::event_reset_mode::manual_reset flag is specified for mode, threads that wait on the event will not block. If the initial state is signaled, and mode is xtd::threading::event_reset_mode::auto_reset, the first thread that waits on the event will be released immediately, after which the event will reset, and subsequent threads will block.
      event_wait_handle(bool initial_state, event_reset_mode mode, const ustring& name, bool& created_new);
      /// @}

      /// @cond
      template <typename char_t>
      explicit event_wait_handle(const char_t* name) : event_wait_handle(ustring(name)) {}
      ~event_wait_handle();
      /// @endcond

      /// @name Public Properties
      
      /// @{
      intptr handle() const noexcept override;
      void handle(intptr value) override;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      void close() override;
      
      int32 compare_to(const event_wait_handle& value) const noexcept override;
      
      bool equals(const event_wait_handle& value) const noexcept override;

      /// @brief Sets the state of the event to nonsignaled, causing threads to block.
      /// @return true if the operation succeeds; otherwise, false.
      /// @exception xtd::object_closed_exception The xtd::threading::wait_handle::close() method was previously called on this xtd::threading::event_wait_handle.
      bool reset();
      
      /// @brief Sets the state of the event to signaled, allowing one or more waiting threads to proceed.
      /// @return true if the operation succeeds; otherwise, false.
      /// @exception xtd::object_closed_exception The xtd::threading::wait_handle::close() method was previously called on this xtd::threading::event_wait_handle.
      /// @remarks For an xtd::threading::event_wait_handle with xtd::threading::event_reset_mode::auto_reset (including xtd::threading:::auto_reset_event), the xtd::threading::event_wait_handle::set method releases a single thread. If there are no waiting threads, the wait handle remains signaled until a thread attempts to wait on it, or until its xtd::threading::event_wait_handle::reset method is called.
      /// @warning There is no guarantee that every call to the xtd::threading::auto_reset_event::set method will release a thread. If two calls are too close together, so that the second call occurs before a thread has been released, only one thread is released. It's as if the second call did not happen. Also, if xtd::threading::auto_reset_event::set is called when there are no threads waiting and the xtd::threading::auto_reset_event is already signaled, the call has no effect.
      /// @remarks For an xtd::threading::event_wait_handle with xtd::threading::event_reset_mode::manual_reset (including xtd::threading:::manual_reset_event), calling the Set method leaves the wait handle in a signaled state until its xtd::threading::event_wait_handle::reset method is called.
      bool set();
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @brief Opens the specified named synchronization event, if it already exists.
      /// @param name The name of the synchronization object to be opened and shared with other processes. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @return An object that represents the named system event.
      /// @exception xtd::threading::wait_handle_cannot_be_opened_exception A synchronization object with the provided name cannot be opened. It may not exist, or a synchronization object of a different type might have the same name. In some cases, this exception may be thrown for invalid names.
      /// @exception xtd::argument_exception name is an empty string.
      /// @exception xtd::io_io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @exception xtd::io::path_too_long_exception The name is too long. Length restrictions may depend on the operating system or configuration.
      /// @remarks The name may be prefixed with Global\ or Local\ to specify a namespace. When the Global namespace is specified, the synchronization object may be shared with any processes on the system. When the Local namespace is specified, which is also the default when no namespace is specified, the synchronization object may be shared with processes in the same session. On Windows, a session is a login session, and services typically run in a different non-interactive session. On Unix-like operating systems, each shell has its own session. Session-local synchronization objects may be appropriate for synchronizing between processes with a parent/child relationship where they all run in the same session.
      /// @remarks If a synchronization object of the requested type exists in the namespace, the existing synchronization object is opened. If a synchronization object does not exist in the namespace, or a synchronization object of a different type exists in the namespace, a xtd::threading::wait_handle_cannot_be_opened_exception is thrown
      /// @remarks The xtd::threading::event_wait_handle::open_existing method tries to open the specified named system event. To create the system event when it does not already exist, use one of the xtd::threading::event_wait_handle constructors that has a name parameter.
      /// @remarks Multiple calls to this method that use the same value for name do not necessarily return the same xtd::threading::event_wait_handle object, even though the objects that are returned represent the same named system event.
      static event_wait_handle open_existing(const ustring& name);

      /// @brief Opens the specified named synchronization event, if it already exists, and returns a value that indicates whether the operation succeeded.
      /// @param name The name of the synchronization object to be opened and shared with other processes. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @param result When this method returns, contains a The xtd::threading::event_wait_handle object that represents the named synchronization event if the call succeeded, or null if the call failed. This parameter is treated as uninitialized.
      /// @return true if the named synchronization event was opened successfully; otherwise, false. In some cases, false may be returned for invalid names.
      /// @exception xtd::argument_exception name is an empty string.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive. For some invalid names, the method may return false instead.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @exception xtd::io::path_too_long_exception The name is too long. Length restrictions may depend on the operating system or configuration.
      /// @remarks The name may be prefixed with Global\ or Local\ to specify a namespace. When the Global namespace is specified, the synchronization object may be shared with any processes on the system. When the Local namespace is specified, which is also the default when no namespace is specified, the synchronization object may be shared with processes in the same session. On Windows, a session is a login session, and services typically run in a different non-interactive session. On Unix-like operating systems, each shell has its own session. Session-local synchronization objects may be appropriate for synchronizing between processes with a parent/child relationship where they all run in the same session.
      /// @remarks If a synchronization object of the requested type exists in the namespace, the existing synchronization object is opened. If a synchronization object does not exist in the namespace, or a synchronization object of a different type exists in the namespace, false is returned.
      /// @remarks To create the system event when it does not already exist, use one of the xtd::threading::event_wait_handle constructors that has a name parameter.
      /// @remarks If you are uncertain whether a named synchronization event exists, use this method overload instead of the xtd::threading::event_xait_handle::open_existing(xtd::uttring) method overload, which throws an exception if the synchronization event does not exist.
      /// @remarks Multiple calls to this method that use the same value for name do not necessarily return the same xtd::threading::event_wait_handle object, even though the objects that are returned represent the same named system event.
      static bool try_open_existing(const ustring& name, event_wait_handle& result) noexcept;
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      bool signal() override;

      bool wait(int32 milliseconds_timeout) override;
      /// @}

    private:
      void create(bool initial_state, bool& created_new);
      
      std::shared_ptr<data> data_;
    };
  }
}
