/// @file
/// @brief Contains xtd::threading::cancellation_token class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.hpp"
#include "../iequatable.hpp"
#include "../object.hpp"
#include "../types.hpp"
#include "wait_handle.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @cond
    class cancellation_token_source;
    /// @endcond
    
    /// @brief Propagates notification that operations should be canceled.
    /// ```cpp
    /// class core_export_ cancellation_token : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::threading::cancellation_token
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/cancellation_token>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example uses a random number generator to emulate a data collection application that reads 10 integral values from eleven different instruments. A value of zero indicates that the measurement has failed for one instrument, in which case the operation should be cancelled and no overall mean should be computed.
    /// To handle the possible cancellation of the operation, the example instantiates a xtd::threading::cancellation_token_source object that generates a cancellation token that's passed to a xtd::threading::tasks::task_factory object. In turn, the xtd::threading::tasks::task_factory object passes the cancellation token to each of the tasks responsible for collecting readings for a particular instrument. The xtd::threading::tasks::task_factory::continue_when_all<antecedent_result_t,result_t>(xtd::array<xtd::threading::tasks::task<antecedent_result_t>>, xtd::func<xtd::array<xtd::threading::tasks::task<antecedent_tesult_t>>,TResult>, cancellation_token) method is called to ensure that the mean is computed only after all readings have been gathered successfully. If a task has not completed because it was cancelled, the xtd::threading::tasks::task_factory::continue_when_all method throws an exception.
    /// @include cancellation_token.cpp
    /// @remarks A xtd::threading::cancellation_token enables cooperative cancellation between threads, thread pool work items, or xtd::threading::taks::task objects. You create a cancellation token by instantiating a xtd::threading::cancellation_token_source object, which manages cancellation tokens retrieved from its xtd::threading::cancellation_token_source::token property. You then pass the cancellation token to any number of threads, tasks, or operations that should receive notice of cancellation. The token cannot be used to initiate cancellation. When the owning object calls xtd::threading::cancellation_token_source.cancel, the xtd::threading::cancellation_token::is_cancellation_requested property on every copy of the cancellation token is set to `true`. The objects that receive the notification can respond in whatever manner is appropriate.
    class core_export_ cancellation_token : public object, public iequatable<cancellation_token> {
      struct data;
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Represents an empty xtd::threading::cancellation_token value.
      /// @remarks The cancellation token returned by this property cannot be canceled; that is, its xtd::cancellation_token::can_be_canceled property is `false`.
      /// @remarks Two empty cancellation tokens are always equal.
      static cancellation_token none;
      /// @}

      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes the xtd::threading::cancellation_token.
      /// @param canceled The canceled state for the token.
      /// @remarks Tokens created with this constructor will remain in the canceled state specified by the canceled parameter. If canceled is `false`, both xtd::threading::cancellation_token::can_be_canceled and xtd::threading::cancellation_token::is_cancellation_requested will be `false`.
      /// @remarks If canceled is `true`, both xtd::threading::cancellation_token::can_be_canceled and xtd::threading::cancellation_token::is_cancellation_requested will be `true`.
      cancellation_token(bool canceled);
      /// @}

      /// @cond
      cancellation_token();
      cancellation_token(const cancellation_token& cancellation_token) = default;
      cancellation_token& operator=(const cancellation_token& cancellation_token) = default;
      ~cancellation_token();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets whether this token is capable of being in the canceled state.
      /// @return `true` if this token is capable of being in the canceled state; otherwise, `false`.
      bool can_be_canceled() const noexcept;

      /// @brief Gets whether cancellation has been requested for this token.
      /// @return `true` if cancellation has been requested for this token; otherwise, `false`.
      /// @remarks This property indicates whether cancellation has been requested for this token, either through the token initially being constructed in a canceled state, or through calling xtd::threading::cancellation_token_source::cancel on the token's associated xtd::threading::cancellation_token_source.
      /// @remarks If this property is `true`, it only guarantees that cancellation has been requested. It does not guarantee that every registered handler has finished executing, nor that cancellation requests have finished propagating to all registered handlers. Additional synchronization may be required, particularly in situations where related objects are being canceled concurrently.
      bool is_cancellation_requested() const noexcept;
      
      /// @brief Gets a xtd::threading::wait_handle that is signaled when the token is canceled.
      /// @remarks Accessing this property causes a xtd::threading::wait_handle to be instantiated. It is preferable to only use this property when necessary, and to then dispose the associated xtd::threading::cancellation_token_source instance at the earliest opportunity (disposing the source will dispose of this allocated handle). The handle should not be closed directly.
      threading::wait_handle& wait_handle() noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const object& obj) const noexcept override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const cancellation_token& other) const noexcept override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      xtd::size get_hash_code() const noexcept override;

      /// @brief Throws a xtd::operation_canceled_exception if this token has had cancellation requested.
      /// @exception xtd::operation_canceled_exception The token has had cancellation requested.
      /// @remarks This method provides functionality equivalent to:
      /// ```cpp
      /// if (tpken.is_cancellation_requested())
      ///   throw xtd::operation_canceled_exception {};
      /// ```
      void throw_if_cancellation_requested() const;
      /// @}

    private:
      friend class cancellation_token_source;
      explicit cancellation_token(cancellation_token_source& token_source);

      bool canceled_ = false;
      cancellation_token_source* token_source_ = nullptr;
      xtd::sptr<threading::wait_handle> wait_handle_;
    };
  }
}
