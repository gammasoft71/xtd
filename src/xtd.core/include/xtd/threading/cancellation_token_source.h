/// @file
/// @brief Contains xtd::threading::cancellation_token_source class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../core_export.h"
#include "../object.h"
#include "../types.h"
#include "cancellation_token.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing cancellation_token_source activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::cancellation_token_source class that allows you to use a pool of system-supplied threads, and a xtd::threading::cancellation_token_source class that executes callback methods on cancellation_token_source pool threads.
  namespace threading {
    /// @brief Propagates notification that operations should be canceled.
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
    /// xtd.core threading
    /// @ingroup xtd_core threading
    class core_export_ cancellation_token_source : public object {
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      cancellation_token_source(int32 milliseconds_delay);
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
