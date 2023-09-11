/// @file
/// @brief Contains xtd::threading::barrier exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "barrier_post_phase_exception.h"
#include "cancellation_token.h"
#include "../action.h"
#include "../object.h"
#include "../time_span.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Enables multiple tasks to cooperatively work on an algorithm in parallel through multiple phases.
    /// @par Header
    /// @code #include <xtd/threading/barrier> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// @include barrier.cpp
    class core_export_ barrier : public object {
      struct data;
    public:
      /// @name Aliases
      
      /// @{
      using post_phase_action = action<barrier&>;
      /// @}
      
      /// @name Constructors
      
      /// @{
      explicit barrier(int32 participant_count);
      barrier(int32 participant_count, barrier::post_phase_action post_phase_action);
      /// @}

      ///@cond
      template <typename post_phase_action_t>
      barrier(int32 participant_count, post_phase_action_t post_phase_action) : barrier(participant_count, barrier::post_phase_action {post_phase_action}) {}
      barrier();
      barrier(barrier&&) = default;
      barrier(const barrier&) = default;
      barrier& operator =(const barrier& other);
      ///@endcond

      /// @name Properties
      
      /// @{
      int32 current_phase_number() const noexcept;

      int32 participant_count() const noexcept;

      int32 participants_remaining() const noexcept;
      /// @}

      /// @name Methods
      
      /// @{
      int32 add_participant();

      int32 add_participants(int32 participant_count);
      
      void close();

      int32 remove_participant();
      
      int32 remove_participants(int32 participant_count);
      
      void signal_and_wait();
      bool signal_and_wait(int32 milliseconds_timeout);
      bool signal_and_wait(const cancellation_token& cancellation_token);
      bool signal_and_wait(const time_span& timeout);
      bool signal_and_wait(int32 milliseconds_timeout, const cancellation_token& cancellation_token);
      bool signal_and_wait(const time_span& timeout, const cancellation_token& cancellation_token);
      /// @}

    private:
      std::shared_ptr<data> data_;
    };
  }
}
