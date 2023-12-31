/// @file
/// @brief Contains xtd::threading::semaphore exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "semaphore_full_exception.h"
#include "wait_handle.h"
#include "../icomparable.h"
#include "../iequatable.h"
#include "../int32_object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Limits the number of threads that can access a resource or pool of resources concurrently.
    /// @code
    /// class core_export_ semaphore : public xtd::threading::wait_handle, public xtd::icomparable<semaphore>, public xtd::iequatable<semaphore>
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/semaphore> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks Use the xtd::threading::semaphore class to control access to a pool of resources. Threads enter the semaphore by calling the xtd::threading::wait_handle::wait_one method, which is inherited from the xtd::threading::wait_handle class, and release the semaphore by calling the xtd::threading::semaphore::release method.
    /// @remarks The count on a semaphore is decremented each time a thread enters the semaphore, and incremented when a thread releases the semaphore. When the count is zero, subsequent requests block until other threads release the semaphore. When all threads have released the semaphore, the count is at the maximum value specified when the semaphore was created.
    /// @remarks There is no guaranteed order, such as FIFO or LIFO, in which blocked threads enter the semaphore.
    /// @remarks A thread can enter the semaphore multiple times, by calling the xtd::threading::wait_handle::wait_one method repeatedly. To release some or all of these entries, the thread can call the parameterless xtd::threading::semaphore::release() method overload multiple times, or it can call the xtd::threading::semaphore::release(int32) method overload that specifies the number of entries to be released.
    /// @remarks The xtd::threading::semaphore class does not enforce thread identity on calls to xtd::threading::wait_handle::wait_one or xtd::threading::semaphore::release. It is the programmer's responsibility to ensure that threads do not release the semaphore too many times. For example, suppose a semaphore has a maximum count of two, and that thread A and thread B both enter the semaphore. If a programming error in thread B causes it to call xtd::threading::semaphore::release twice, both calls succeed. The count on the semaphore is full, and when thread A eventually calls xtd::threading::semaphore::release, a xtd::threading::semaphore_full_exception is thrown.
    /// @remarks Semaphores are of two types: local semaphores and named system semaphores. If you create a xtd::threading::semaphore object using a constructor that accepts a name, it is associated with an operating-system semaphore of that name. Named system semaphores are visible throughout the operating system, and can be used to synchronize the activities of processes. You can create multiple xtd::threading::semaphore objects that represent the same named system semaphore, and you can use the xtd::threading::semaphore::open_existing method to open an existing named system semaphore.
    /// @remarks A local semaphore exists only within your process. It can be used by any thread in your process that has a reference to the local xtd::threading::semaphore object. Each xtd::threading::semaphore object is a separate local semaphore.
    /// @par Example
    /// The following code example creates a semaphore with a maximum count of three and an initial count of zero. The example starts five threads, which block waiting for the semaphore. The main thread uses the xtd::threading::semaphore::release(int32) method overload to increase the semaphore count to its maximum, allowing three threads to enter the semaphore. Each thread uses the xtd::threading::thread::sleep method to wait for one second, to simulate work, and then calls the xtd::threading::semaphore::release() method overload to release the semaphore. Each time the semaphore is released, the previous semaphore count is displayed. Console messages track semaphore use. The simulated work interval is increased slightly for each thread, to make the output easier to read.
    /// @include semaphore.cpp
    class core_export_ semaphore : public wait_handle, public icomparable<semaphore>, public iequatable<semaphore> {
      class semaphore_base;
      class named_semaphore;
      class unnamed_semaphore;
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::semaphore class.
      /// @remarks The initial count is set to 0 and the maximum count is set to xtd::int32_object::max_value.
      semaphore();
      /// @brief nitializes a new instance of the xtd::threading::semaphore class, specifying optionally specifying the name of a system semaphore object.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks This constructor initializes a xtd::threading::semaphore object that represents a named system semaphore. You can create multiple xtd::threading::semaphore objects that represent the same named system semaphore.
      /// @remarks The initial count is set to 0 and the maximum count is set to xtd::int32_object::max_value.
      /// @remarks If a name is provided and a synchronization object of the requested type already exists in the namespace, the existing synchronization object is used. Use createdNew to determine whether the system semaphore was created.
      /// @remarks If you specify an empty string ("") for name, a local semaphore is created, as if you had called the xtd::threading::semaphore(int32, int32) constructor overload.
      /// @remarks Because named semaphores are visible throughout the operating system, they can be used to coordinate resource use across process boundaries.
      /// @remarks If you want to find out whether a named system semaphore exists, use the xtd::threading::semaphore::open_existing method. The xtd::threading::semaphore::open_existing method attempts to open an existing named semaphore, and throws an exception if the system semaphore does not exist.
      explicit semaphore(const ustring& name);
      /// @brief nitializes a new instance of the xtd::threading::semaphore class, specifying optionally specifying the name of a system semaphore object, and specifying a variable that receives a value indicating whether a new system semaphore was created.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @param created_new When this method returns, contains true if a local semaphore was created (that is, if name is null or an empty string) or if the specified named system semaphore was created; false if the specified named system semaphore already existed. This parameter is passed uninitialized.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks This constructor initializes a xtd::threading::semaphore object that represents a named system semaphore. You can create multiple xtd::threading::semaphore objects that represent the same named system semaphore.
      /// @remarks The initial count is set to 0 and the maximum count is set to xtd::int32_object::max_value.
      /// @remarks If a name is provided and a synchronization object of the requested type already exists in the namespace, the existing synchronization object is used. Use createdNew to determine whether the system semaphore was created.
      /// @remarks If you specify an empty string ("") for name, a local semaphore is created, as if you had called the xtd::threading::semaphore(int32, int32) constructor overload.
      /// @remarks Because named semaphores are visible throughout the operating system, they can be used to coordinate resource use across process boundaries.
      /// @remarks If you want to find out whether a named system semaphore exists, use the xtd::threading::semaphore::open_existing method. The xtd::threading::semaphore::open_existing method attempts to open an existing named semaphore, and throws an exception if the system semaphore does not exist.
      explicit semaphore(const ustring& name, bool& created_new);
      /// @brief Initializes a new instance of the xtd::threading::semaphore class, specifying the initial number of entries.
      /// @param initial_count The initial number of requests for the semaphore that can be granted concurrently.
      /// @exception xtd::argument_out_of_range_exception initial_count is less than 0.
      /// @remarks This constructor initializes an unnamed semaphore. All threads that use an instance of such a semaphore must have references to the instance.
      /// @remarks The maximum count is set to xtd::int32_object::max_value.
      explicit semaphore(int32 initial_count);
      /// @brief nitializes a new instance of the xtd::threading::semaphore class, specifying the initial number of entries and the maximum number of concurrent entries, optionally specifying the name of a system semaphore object.
      /// @param initial_count The initial number of requests for the semaphore that can be granted concurrently.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @exception xtd::argument_out_of_range_exception initial_count is less than 0.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks This constructor initializes a xtd::threading::semaphore object that represents a named system semaphore. You can create multiple xtd::threading::semaphore objects that represent the same named system semaphore.
      /// @remarks If a name is provided and a synchronization object of the requested type already exists in the namespace, the existing synchronization object is used. Use createdNew to determine whether the system semaphore was created.
      /// @remarks The maximum count is set to xtd::int32_object::max_value.
      /// @remarks If you specify an empty string ("") for name, a local semaphore is created, as if you had called the xtd::threading::semaphore(int32, int32) constructor overload.
      /// @remarks Because named semaphores are visible throughout the operating system, they can be used to coordinate resource use across process boundaries.
      /// @remarks If you want to find out whether a named system semaphore exists, use the xtd::threading::semaphore::open_existing method. The xtd::threading::semaphore::open_existing method attempts to open an existing named semaphore, and throws an exception if the system semaphore does not exist.
      semaphore(int32 initial_count, const ustring& name);
      /// @brief nitializes a new instance of the xtd::threading::semaphore class, specifying the initial number of entries and the maximum number of concurrent entries, optionally specifying the name of a system semaphore object, and specifying a variable that receives a value indicating whether a new system semaphore was created.
      /// @param initial_count The initial number of requests for the semaphore that can be granted concurrently.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @param created_new When this method returns, contains true if a local semaphore was created (that is, if name is null or an empty string) or if the specified named system semaphore was created; false if the specified named system semaphore already existed. This parameter is passed uninitialized.
      /// @exception xtd::argument_out_of_range_exception initial_count is less than 0.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks This constructor initializes a xtd::threading::semaphore object that represents a named system semaphore. You can create multiple xtd::threading::semaphore objects that represent the same named system semaphore.
      /// @remarks If a name is provided and a synchronization object of the requested type already exists in the namespace, the existing synchronization object is used. Use createdNew to determine whether the system semaphore was created.
      /// @remarks The maximum count is set to xtd::int32_object::max_value.
      /// @remarks If you specify an empty string ("") for name, a local semaphore is created, as if you had called the xtd::threading::semaphore(int32, int32) constructor overload.
      /// @remarks Because named semaphores are visible throughout the operating system, they can be used to coordinate resource use across process boundaries.
      /// @remarks If you want to find out whether a named system semaphore exists, use the xtd::threading::semaphore::open_existing method. The xtd::threading::semaphore::open_existing method attempts to open an existing named semaphore, and throws an exception if the system semaphore does not exist.
      semaphore(int32 initial_count, const ustring& name, bool& created_new);
      /// @brief Initializes a new instance of the xtd::threading::semaphore class, specifying the initial number of entries and the maximum number of concurrent entries.
      /// @param initial_count The initial number of requests for the semaphore that can be granted concurrently.
      /// @param maximum_count The maximum number of requests for the semaphore that can be granted concurrently.
      /// @exception xtd::argument_exception initial_count is greater than maximum_count.
      /// @exception xtd::argument_out_of_range_exception maximum_count is less than 1.<br>-or-<br>initial_count is less than 0.
      /// @remarks This constructor initializes an unnamed semaphore. All threads that use an instance of such a semaphore must have references to the instance.
      /// @remarks If initial_count is less than maximum_count, the effect is the same as if the current thread had called xtd::threading::wait_handle::wait_one (maximum_count minus initial_count) times. If you do not want to reserve any entries for the thread that creates the semaphore, use the same number for maximum_count and initial_count.
      semaphore(int32 initial_count, int32 maximum_count);
      /// @brief Initializes a new instance of the xtd::threading::semaphore class, specifying the initial number of entries and the maximum number of concurrent entries, and optionally specifying the name of a system semaphore object.
      /// @param initial_count The initial number of requests for the semaphore that can be granted concurrently.
      /// @param maximum_count The maximum number of requests for the semaphore that can be granted concurrently.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @exception xtd::argument_exception initial_count is greater than maximum_count.
      /// @exception xtd::argument_out_of_range_exception maximum_count is less than 1.<br>-or-<br>initial_count is less than 0.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks This constructor initializes a xtd::threading::semaphore object that represents a named system semaphore. You can create multiple xtd::threading::semaphore objects that represent the same named system semaphore.
      /// @remarks If a name is provided and a synchronization object of the requested type already exists in the namespace, the existing synchronization object is used.
      /// @remarks If initial_count is less than maximum_count, the effect is the same as if the current thread had called xtd::threading::wait_handle::wait_one (maximum_count minus initial_count) times. If you do not want to reserve any entries for the thread that creates the semaphore, use the same number for maximum_count and initial_count.
      /// @warning When you use this constructor overload, the recommended practice is to specify the same number for initial_count and maximum_count. If initial_count is less than maximum_count, and a named system semaphore is created, the effect is the same as if the current thread had called xtd::threading::wait_handle::wait_one (maximum_count minus initial_count) times. However, with this constructor overload there is no way to determine whether a named system semaphore was created.
      /// @remarks If you specify an empty string ("") for name, a local semaphore is created, as if you had called the xtd::threading::semaphore(int32, int32) constructor overload.
      /// @remarks Because named semaphores are visible throughout the operating system, they can be used to coordinate resource use across process boundaries.
      /// @remarks If you want to find out whether a named system semaphore exists, use the xtd::threading::semaphore::open_existing method. The xtd::threading::semaphore::open_existing method attempts to open an existing named semaphore, and throws an exception if the system semaphore does not exist.
      semaphore(int32 initial_count, int32 maximum_count, const ustring& name);
      /// @brief nitializes a new instance of the xtd::threading::semaphore class, specifying the initial number of entries and the maximum number of concurrent entries, optionally specifying the name of a system semaphore object, and specifying a variable that receives a value indicating whether a new system semaphore was created.
      /// @param initial_count The initial number of requests for the semaphore that can be granted concurrently.
      /// @param maximum_count The maximum number of requests for the semaphore that can be granted concurrently.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, null or an empty string. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @param created_new When this method returns, contains true if a local semaphore was created (that is, if name is null or an empty string) or if the specified named system semaphore was created; false if the specified named system semaphore already existed. This parameter is passed uninitialized.
      /// @exception xtd::argument_exception initial_count is greater than maximum_count.
      /// @exception xtd::argument_out_of_range_exception maximum_count is less than 1.<br>-or-<br>initial_count is less than 0.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks This constructor initializes a xtd::threading::semaphore object that represents a named system semaphore. You can create multiple xtd::threading::semaphore objects that represent the same named system semaphore.
      /// @remarks If a name is provided and a synchronization object of the requested type already exists in the namespace, the existing synchronization object is used. Use createdNew to determine whether the system semaphore was created.
      /// @remarks If initial_count is less than maximum_count, the effect is the same as if the current thread had called xtd::threading::wait_handle::wait_one (maximum_count minus initial_count) times. If you do not want to reserve any entries for the thread that creates the semaphore, use the same number for maximum_count and initial_count.
      /// @remarks If you specify an empty string ("") for name, a local semaphore is created, as if you had called the xtd::threading::semaphore(int32, int32) constructor overload.
      /// @remarks Because named semaphores are visible throughout the operating system, they can be used to coordinate resource use across process boundaries.
      /// @remarks If you want to find out whether a named system semaphore exists, use the xtd::threading::semaphore::open_existing method. The xtd::threading::semaphore::open_existing method attempts to open an existing named semaphore, and throws an exception if the system semaphore does not exist.
      semaphore(int32 initial_count, int32 maximum_count, const ustring& name, bool& created_new);
      /// @}

      /// @cond
      template <typename char_t>
      explicit semaphore(const char_t* name) : semaphore(ustring(name)) {}
      ~semaphore();
      /// @endcond

      /// @name Properties
      
      /// @{
      intptr handle() const noexcept override;
      void handle(intptr value) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      void close() override;
      
      int32 compare_to(const semaphore& value) const noexcept override;
      
      bool equals(const semaphore& value) const noexcept override;
      
      /// @brief Opens the specified named semaphore, if it already exists.
      /// @param name The name of the synchronization object to be shared with other processes. The name is case-sensitive.
      /// @return An object that represents the named system semaphore.
      /// @exception xtd::argument_exception name is an empty string.
      /// @exception xtd::io::io_exception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks If a synchronization object of the requested type exists in the namespace, the existing synchronization object is opened.
      /// @remarks The xtd::threading::semaphore::open_existing method tries to open the specified named semaphore. To create the system semaphore when it does not already exist, use one of the xtd::threading::semaphore constructors that has a name parameter.
      /// @remarks Multiple calls to this method that use the same value for name do not necessarily return the same xtd::threading::semaphore object, even though the objects that are returned represent the same named system semaphore.
      static semaphore open_existing(const ustring& name);

      /// @brief Exits the semaphore and returns the previous count.
      /// @return The count on the semaphore before the xtd::threading::semaphore::release method was called.
      /// @exception xtd::threading::semaphore_full_exception The semaphore count is already at the maximum value.
      /// @exception xtd::io::io_exception A Win32 or pthred error occurred with a named semaphore.
      /// @remarks Threads typically use the xtd::threading::wait_handle::wait_one method to enter the semaphore, and they typically use this method overload to exit.
      /// @remarks If a xtd::threading::semaphore_full_exception is thrown by the xtd::threading::release method, it does not necessarily indicate a problem with the calling thread. A programming error in another thread might have caused that thread to exit the semaphore more times than it entered.
      int32 release();
      /// @brief Exits the semaphore a specified number of times and returns the previous count.
      /// @param release_count The number of times to exit the semaphore.
      /// @return The count on the semaphore before the xtd::threading::semaphore::release method was called.
      /// @exception xtd::argument_out_of_range_exception releaseCount is less than 1.
      /// @exception xtd::threading::semaphore_full_exception The semaphore count is already at the maximum value.
      /// @remarks Threads typically use the xtd::threading::wait_handle::wait_one method to enter the semaphore, and they typically use this method overload to exit.
      /// @remarks If a xtd::threading::semaphore_full_exception is thrown by the xtd::threading::release method, it does not necessarily indicate a problem with the calling thread. A programming error in another thread might have caused that thread to exit the semaphore more times than it entered.
      int32 release(int32 release_count);

      /// @brief Opens the specified named semaphore, if it already exists, and returns a value that indicates whether the operation succeeded.
      /// @param name The name of the synchronization object to be shared with other processes. The name is case-sensitive. The backslash character (\) is reserved and may only be used to specify a namespace. For more information on namespaces, see the remarks section. There may be further restrictions on the name depending on the operating system. For example, on Unix-based operating systems, the name after excluding the namespace must be a valid file name.
      /// @param result When this method returns, contains a xtd::threading::semaphore object that represents the named semaphore if the call succeeded.
      /// @return true if the named semaphore was opened successfully; otherwise, false. In some cases, false may be returned for invalid names.
      /// @remarks If a synchronization object of the requested type exists in the namespace, the existing synchronization object is opened.
      /// @remarks The xtd::threading::semaphore::open_existing method tries to open the specified named semaphore. To create the system semaphore when it does not already exist, use one of the xtd::threading::semaphore constructors that has a name parameter.
      /// @remarks Multiple calls to this method that use the same value for name do not necessarily return the same xtd::threading::semaphore object, even though the objects that are returned represent the same named system semaphore.
      static bool try_open_existing(const ustring& name, semaphore& result) noexcept;
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      bool signal() override;

      bool wait(int32 milliseconds_timeout) override;
      /// @}

    private:
      void create(int32 initial_count, int32 maximum_count, bool& created_new);
      std::shared_ptr<semaphore_base> semaphore_;
      std::shared_ptr<data> data_;
    };
  }
}
