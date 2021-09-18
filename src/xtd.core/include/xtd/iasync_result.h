/// @file
/// @brief Contains xtd::iasync_result interface.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <shared_mutex>
#include "interface.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the status of an asynchronous operation.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core interfaces
  /// @remarks The xtd::iasync_result interface is implemented by classes containing methods that can operate asynchronously. It is the return type of methods that initiate an asynchronous operation, such as xtd::io::file_stream.begin_read, and it is passed to methods that conclude an asynchronous operation, such as xtd::ioo::file_stream::end_read. xtd::iasync_result objects are also passed to methods invoked by xtd::async_callback delegates when an asynchronous operation completes.
  /// @remarks An object that supports the xtd::iasync_result interface stores state information for an asynchronous operation and provides a synchronization object to allow threads to be signaled when the operation completes.
  /// @note The async_result class is the implementation of xtd::iasync_result that is returned by the begin_invoke method when you use a delegate to call a method asynchronously.
  class iasync_result interface_ {
  public:
    /// @brief Gets a user-defined object that qualifies or contains information about an asynchronous operation.
    /// @return A user-defined object that qualifies or contains information about an asynchronous operation.
    /// @remarks This property returns the object that is the last parameter of the method that initiates an asynchronous operation.
    /// @par Notes to Implementers
    /// Implement this property to allow the caller of an asynchronous operation to obtain an application-defined object specified at the start of the operation.
    /// @par Notes to Callers
    /// This object can be used to pass state information for the asynchronous operation to an AsyncCallback that you provide.
    virtual std::any async_state() const noexcept = 0;
    
    /// @brief Gets a std::mutex that is used to wait for an asynchronous operation to complete.
    /// @return A std::mutex that is used to wait for an asynchronous operation to complete.
    /// @remarks The return value allows the client to wait for an asynchronous operation to complete instead of polling xtd::iasync_result::is_completed until the operation concludes. The return value can be used to perform a wait operation.
    /// @par Notes to Implementers
    /// The object that implements xtd::iasync_result does not need to create the std::mutex until the xtd::iasync_result::async_mutex property is read. It is the choice of the xtd::iasync_result implementer. However, if the implementer creates xtd::iasync_result::async_mutex, it is the responsibility of the implementer to signal the std::mutex that will terminate the wait at the appropriate time. Once created, xtd::iasync_result xtd::iasync_result::async_mutex should be kept alive until the user calls the method that concludes the asynchronous operation. At that time the object behind xtd::iasync_result::async_mutex can be discarded.
    /// @par Notes to Callers
    /// Clients that wait for the operation to complete (as opposed to polling) use this property to obtain a synchronization object to wait on.
    /// @par Notes to Implementers
    virtual std::shared_mutex& async_mutex() = 0;
    
    /// @brief Gets a value that indicates whether the asynchronous operation completed synchronously.
    /// @return true if the asynchronous operation completed synchronously; otherwise, false.
    /// @remarks If the synchronous completion of the call is detected in the xtd::async_callback delegate, it is probable that the thread that initiated the asynchronous operation is the current thread.
    /// @par Notes to Callers
    /// Use this property to determine if the asynchronous operation completed synchronously. For example, this property can return true for an asynchronous I/O operation if the I/O request was small.
    virtual bool completed_synchronously() const noexcept = 0;

    /// @brief Gets a value that indicates whether the asynchronous operation has completed.
    /// @return true if the operation is complete; otherwise, false.
    /// @remarks When this property is true, you can assume it is safe to discard any resources you allocate for use by the asynchronous operation.
    /// @par Notes to Implementers
    /// Implementers will typically return the value of a private field or internal test as the value of this property.
    /// @par Notes to Callers
    /// Clients that poll for operation status (as opposed to waiting on a synchronization object) use this property to determine the status of the operation.
    virtual bool is_completed() const noexcept = 0;
  };
}
