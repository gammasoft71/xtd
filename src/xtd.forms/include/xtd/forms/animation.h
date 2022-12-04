/// @file
/// @brief Contains xtd::forms::animation control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/diagnostics/stopwatch.h>
#include "animation_update_event_handler.h"
#include "control.h"
#include "timer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents an animation control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of animation control.
    /// @include animation.cpp
    class animation : public xtd::forms::control {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of animation class.
      animation();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the elapsed time for the current frame, in milliseconds.
      /// @return A long integer representing the elapsed time for the current frame, in milliseconds.
      virtual int64_t elapsed_milliseconds() const noexcept;
      
      /// @brief Gets the current frame counter value.
      /// @return The current frame counter value.
      virtual int32_t frame_counter() const noexcept;
      
      /// @brief Gets the number of frame per second.
      /// @return The number if frame per seconds. The default is 10.
      virtual int32_t frames_per_second() const noexcept;
      /// @brief Sets the number of frame per second.
      /// @para value The number if frame per seconds. The default is 10.
      virtual animation& frames_per_second(int32_t value);
      
      
      /// @brief Gets a valiue that indicates if the animation is started.
      /// @return true if the animation is running; otherwise false.
      virtual bool running() const noexcept;
      
      /// @brief Gets a valiue that indicates if the animation is started.
      /// @param value true if the animation is running; otherwise false.
      virtual animation& running(bool value);
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Starts animation of the animation control.
      void start();
      
      /// @brief Stops animation of the animation control.
      void stop();
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the specified interval specified by xtd::animation::frames_per_seconds has elapsed and the animation is started.
      /// @ingroup events
      /// @remarks You can use this event to do things like advancing animation parameters, checking the mouse position, etc.
      /// @remarks For more information about handling events, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/guide_handle_and_raise_events.md">Handling and Raising Events</a>.
      xtd::event<animation, animation_updated_event_handler> updated;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      drawing::size default_size() const noexcept override;
      /// @}

      /// @name Protected methods
      
      /// @{
      /// @brief Raises the updated event.
      /// @param e An event_args that contains the event data. This is always xtd::event_args::empty.
      virtual void on_updated(const xtd::forms::animation_updated_event_args& e);
      /// @}
      
    private:
      void on_frames_timer_tick(object& timer, const xtd::event_args& e);
      
      struct data {
        int32_t frame_counter = 0;
        int32_t frames_per_second = 10;
        xtd::diagnostics::stopwatch stopwatch;
        xtd::forms::timer frames_timer;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
