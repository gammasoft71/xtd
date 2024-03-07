/// @file
/// @brief Contains xtd::threading::barrier exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
    /// @code
    /// class barrier : public xtd::object
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/barrier> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// @include barrier.cpp
    /// @remarks A group of tasks cooperate by moving through a series of phases, where each in the group signals it has arrived at the xtd::threading::barrier in a given phase and implicitly waits for all others to arrive. The same xtd::threading::barrier can be used for multiple phases.
    class core_export_ barrier : public object {
      struct data;
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the xtd::threading::barrier::post_phase_action delegate.
      using post_phase_action = action<barrier&>;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::barrier class.
      /// @param participant_count The number of participating threads.
      /// @exception xtd::argument_out_of_range_exception participant_count is less than 0 or greater than 32,767.
      explicit barrier(int32 participant_count);
      /// @brief Initializes a new instance of the xtd::threading::barrier class.
      /// @param participant_count The number of participating threads.
      /// @param post_phase_action The xtd::action< barrier& > to be executed after each phase. Empty may be passed to indicate no action is taken.
      /// @exception xtd::argument_out_of_range_exception participant_count is less than 0 or greater than 32,767.
      /// @remarks The post_phase_action delegate will be executed after all participants have arrived at the barrier in one phase. The participants will not be released to the next phase until the post_phase_action delegate has completed execution.
      barrier(int32 participant_count, barrier::post_phase_action post_phase_action);
      /// @}

      ///@cond
      template <typename post_phase_action_t>
      barrier(int32 participant_count, post_phase_action_t post_phase_action) : barrier(participant_count, barrier::post_phase_action {post_phase_action}) {}
      barrier();
      barrier(barrier&&) = default;
      barrier(const barrier&) = default;
      barrier& operator =(const barrier& other);
      ~barrier();
      ///@endcond

      /// @name Public Properties
      
      /// @{
      /// @brief Gets the number of the barrier's current phase.
      /// @return Returns the number of the barrier's current phase.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      int32 current_phase_number() const;

      /// @brief Gets the total number of participants in the barrier.
      /// @return Returns the total number of participants in the barrier.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      int32 participant_count() const;

      /// @brief Gets the number of participants in the barrier that haven't yet signaled in the current phase.
      /// @return Returns the number of participants in the barrier that haven't yet signaled in the current phase.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @remarks This could be 0 during a post-phase action delegate execution or if the participant_count is 0.
      int32 participants_remaining() const;
      /// @}

      /// @name Public Methods
      
      /// @{
      /// @brief Notifies the xtd::threading::barrier that there will be an additional participant.
      /// @return The phase number of the barrier in which the new participants will first participate.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::argument_out_of_range_exception Adding a participant would cause the barrier's participant count to exceed 32,767.
      /// @remarks If the barrier is currently executing a post phase action, this call is blocked until the post phase action completes and the barrier has moved on to the next phase.
      int32 add_participant();

      /// @brief Notifies the xtd::threading::barrier that there will be additional participants.
      /// @param participant_count The number of additional participants to add to the barrier.
      /// @return The phase number of the barrier in which the new participants will first participate.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::argument_out_of_range_exception participant_count is less than 0 <br>-or-<br> Adding participant_count participants would cause the barrier's participant count to exceed 32,767..
      /// @remarks If the barrier is currently executing a post phase action, this call is blocked until the post phase action completes and the barrier has moved on to the next phase.
      int32 add_participants(int32 participant_count);
      
      /// @brief Close the current instance of the xtd::threading::barrier  class.
      void close();

      /// @brief Notifies the Barrier that there will be one less participant.
      /// @return The phase number of the barrier in which the new participants will first participate.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::argument_out_of_range_exception The barrier already has 0 participants.
      int32 remove_participant();
      
      /// @brief Notifies the Barrier that there will be fewer participants.
      /// @param participant_count The number of additional participants to remove from the barrier.
      /// @return The phase number of the barrier in which the new participants will first participate.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::argument_out_of_range_exception participant_count is less than 0 <br>-or-<br> The total participant count is less than the specified participant_count
      int32 remove_participants(int32 participant_count);

      /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier as well.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::threading::barrier_post_phase_exception If an exception is thrown from the post phase action of a xtd::threading::barrier after all participating threads have called xtd::threading::barrier::signal_and_wait, the exception will be wrapped in a xtd::threading::barrier_post_phase_exception and be thrown on all participating threads.
      void signal_and_wait();
      /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier as well, using a 32-bit signed integer to measure the timeout.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite(-1) to wait indefinitely.
      /// @return true if all participants reached the barrier within the specified time; otherwise false.
      /// @exception xtd::argument_out_of_range_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::threading::barrier_post_phase_exception If an exception is thrown from the post phase action of a xtd::threading::barrier after all participating threads have called xtd::threading::barrier::signal_and_wait, the exception will be wrapped in a xtd::threading::barrier_post_phase_exception and be thrown on all participating threads.
      bool signal_and_wait(int32 milliseconds_timeout);
      /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier, while observing a cancellation token.
      /// @param cancellation_token The xtd::threading::cancellation_token to observe.
      /// @return true if all participants reached the barrier within the specified time; otherwise false.
      /// @exceptkon xtd::operation_canceled_exception cancellation_token has been canceled.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::threading::barrier_post_phase_exception If an exception is thrown from the post phase action of a xtd::threading::barrier after all participating threads have called xtd::threading::barrier::signal_and_wait, the exception will be wrapped in a xtd::threading::barrier_post_phase_exception and be thrown on all participating threads.
      bool signal_and_wait(const cancellation_token& cancellation_token);
      /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier as well, using a xtd::time_span object to measure the time interval.
      /// @param timout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds to wait indefinitely.
      /// @return true if all participants reached the barrier within the specified time; otherwise false.
      /// @exception xtd::argument_out_of_range_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::threading::barrier_post_phase_exception If an exception is thrown from the post phase action of a xtd::threading::barrier after all participating threads have called xtd::threading::barrier::signal_and_wait, the exception will be wrapped in a xtd::threading::barrier_post_phase_exception and be thrown on all participating threads.
      bool signal_and_wait(const time_span& timeout);
      /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier as well, using a 32-bit signed integer to measure the timeout, while observing a cancellation token.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite(-1) to wait indefinitely.
      /// @param cancellation_token The xtd::threading::cancellation_token to observe.
      /// @return true if all participants reached the barrier within the specified time; otherwise false.
      /// @exception xtd::argument_out_of_range_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      /// @exceptkon xtd::operation_canceled_exception cancellation_token has been canceled.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::threading::barrier_post_phase_exception If an exception is thrown from the post phase action of a xtd::threading::barrier after all participating threads have called xtd::threading::barrier::signal_and_wait, the exception will be wrapped in a xtd::threading::barrier_post_phase_exception and be thrown on all participating threads.
      bool signal_and_wait(int32 milliseconds_timeout, const cancellation_token& cancellation_token);
      /// @brief Signals that a participant has reached the barrier and waits for all other participants to reach the barrier as well, using a xtd::time_span object to measure the time interval, while observing a cancellation token.
      /// @param timout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds to wait indefinitely.
      /// @param cancellation_token The xtd::threading::cancellation_token to observe.
      /// @return true if all participants reached the barrier within the specified time; otherwise false.
      /// @exception xtd::argument_out_of_range_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      /// @exceptkon xtd::operation_canceled_exception cancellation_token has been canceled.
      /// @exception xtd::object_closed_exception The current instance has already been disposed.
      /// @exception xtd::threading::barrier_post_phase_exception If an exception is thrown from the post phase action of a xtd::threading::barrier after all participating threads have called xtd::threading::barrier::signal_and_wait, the exception will be wrapped in a xtd::threading::barrier_post_phase_exception and be thrown on all participating threads.
      bool signal_and_wait(const time_span& timeout, const cancellation_token& cancellation_token);
      /// @}

    private:
      bool wait_wtih_cancellation_token();
      bool wait_wtih_cancellation_token(int32 milliseconds_timeout);

      std::shared_ptr<data> data_;
    };
  }
}
