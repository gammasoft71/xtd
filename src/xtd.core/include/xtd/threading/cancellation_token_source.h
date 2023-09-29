/// @file
/// @brief Contains xtd::threading::cancellation_token_source class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "cancellation_token.h"
#include "../core_export.h"
#include "../object.h"
#include "../types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Signals to a xtd::threading::cancellation_token that it should be canceled.
    /// @code
    /// class core_export_ cancellation_token_source : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::threading::cancellation_token_source
    /// @par Header
    /// @code #include <xtd/threading/cancellation_token_source> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks The xtd uses a unified model for cooperative cancellation of asynchronous or long-running synchronous operations that involves two objects:
    /// * A xtd::threading::cancellation_token_source object, which provides a cancellation token through its xtd::threading::cancellation_token_source::token property and sends a cancellation message by calling its xtd::threading::cancellation_token_source::cancel or xtd::threading::cancellation_token_sourcecancel_after method.
    /// * A xtd::threading::cancellation_token object, which indicates whether cancellation is requested.
    /// @remarks The general pattern for implementing the cooperative cancellation model is:
    /// * Instantiate a xtd::threading::cancellation_token_source object, which manages and sends cancellation notification to the individual cancellation tokens.
    /// * Pass the token returned by the xtd::threading::cancellation_token_source::token property to each task or thread that listens for cancellation.
    /// * Call the xtd::threading::cancellation_token::is_cancellation_requested method from operations that receive the cancellation token. Provide a mechanism for each task or thread to respond to a cancellation request. Whether you choose to cancel an operation, and exactly how you do it, depends on your application logic.
    /// * Call the xtd::threading::cancellation_token_source::cancel method to provide notification of cancellation. This sets the xtd::threading::cancellation_token.is_cancellation_requested property on every copy of the cancellation token to true.
    /// * Call the xtd::threading::cancellation_token_source::close method when you are finished with the xtd::threading::cancellation_token_source object.
    class core_export_ cancellation_token_source : public object {
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      cancellation_token_source(int32 milliseconds_delay);
      cancellation_token_source(const time_span& delay);
      /// @}

      /// @cond
      cancellation_token_source();
      cancellation_token_source(const cancellation_token_source& cancellation_token_source);
      cancellation_token_source& operator=(const cancellation_token_source& cancellation_token_source);
      ~cancellation_token_source();
      /// @endcond
      
      /// @name Proeprties
      
      /// @{
      bool is_cancellation_requested() const noexcept;
      
      const cancellation_token& token() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @}

    private:
      bool can_be_canceled() const noexcept;
      threading::wait_handle& wait_handle() noexcept;

      friend class cancellation_token;
      std::shared_ptr<data> data_;
    };
  }
}
