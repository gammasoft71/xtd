/// @file
/// @brief Contains xtd::forms::animation control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of animation control.
    /// @include animattion.cpp
    /// @par Windows
    /// @image html animation_w.png
    /// <br>
    /// @image html animation_wd.png
    /// @par macOS
    /// @image html animation_m.png
    /// <br>
    /// @image html animation_md.png
    /// @par Gnome
    /// @image html animation_g.png
    /// <br>
    /// @image html animation_gd.png
    class animation : public xtd::forms::control {
    public:
      /// @brief Initializee a new instance of animation class.
      animation();
      
      drawing::size default_size() const override {return {200, 100};}
      
      /// @brief Gets the elapsed time for the current frame, in milliseconds.
      /// @return A long integer representing the elapsed time for the current frame, in milliseconds.
      virtual int32_t elapsed_millliseconds() const;
      
      /// @brief Gets the current frame counter value.
      /// @return The current frame counter value.
      virtual int32_t frame_counter() const;
      
      /// @brief Gets the number of frame per second.
      /// @return The number if frame per seconds. The default is 10.
      virtual int32_t frames_per_second() const;
      /// @brief Sets the number of frame per second.
      /// @para mvalue The number if frame per seconds. The default is 10.
      virtual animation& frames_per_second(int32_t value);
      
      /// @brief Returns if the animation is started.
      /// @return true if the animation is running; otherwise false.
      virtual bool is_running() const;
      
      /// @brief Starts animation of the animation control.
      void start();
      
      /// @brief Stops animation of the animation control.
      void stop();

      /// @brief Occurs when the specified interval specified by xtd::animation::frames_per_seconds has elapsed and the animation is started.
      /// @remarks You can use this event to do things like advancing animation parameters, checking the mouse position, etc.
      /// @ingroup events
      xtd::event<animation, animation_updated_event_handler> updated;
      
    protected:
      /// @brief Raises the updated event.
      /// @param e An event_args that contains the event data. This is always xtd::event_args::empty.
      virtual void on_updated(const xtd::forms::animation_updated_event_args& e);
      
    private:
      void on_frames_timer_tick(object& timer, const xtd::event_args& e);
      
      int32_t frame_counter_ = 0;
      int32_t frames_per_second_ = 10;
      xtd::diagnostics::stopwatch stopwatch_;
      xtd::forms::timer frames_timer_;
    };
  }
}

