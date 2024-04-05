/// @file
/// @brief Contains xtd::forms::animation control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "animation_update_event_handler.h"
#include "control.h"
#include "timer.h"
#include <xtd/diagnostics/stopwatch>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents an animation control.
    /// @par Header
    /// @code #include <xtd/forms/animation> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of animation control.
    /// @include animation.cpp
    class animation : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new instance of xtd::forms::animation class.
      animation();
      /// @}
      
      /// @cond
      animation(animation&& rhs);
      animation(const animation&) = default;
      animation& operator =(const animation&) = default;
      /// @endcond

      /// @name Public Properties
      
      /// @{
      /// @brief Gets the elapsed time for the current frame, in nanoseconds.
      /// @return A std::chrono::nanoseconds representing the elapsed time for the current frame, in nanoseconds.
      virtual time_span elapsed() const noexcept;
      
      /// @brief Gets the elapsed time for the current frame, in milliseconds.
      /// @return A long integer representing the elapsed time for the current frame, in milliseconds.
      virtual int64 elapsed_milliseconds() const noexcept;
      
      /// @brief Gets the elapsed time for the current frame, in nanoseconds.
      /// @return A long integer representing the elapsed time for the current frame, in nanoseconds.
      virtual int64 elapsed_nanoseconds() const noexcept;
      
      /// @brief Gets the elapsed time for the current frame, in ticks.
      /// @return A long integer representing the elapsed time for the current frame, in ticks.
      virtual int64 elapsed_ticks() const noexcept;
      
      /// @brief Gets the current frame counter value.
      /// @return The current frame counter value.
      virtual uint32 frame_counter() const noexcept;
      
      /// @brief Gets the number of frame per second.
      /// @return The number of frame per seconds. The default is 10.
      virtual uint32 frames_per_second() const noexcept;
      /// @brief Sets the number of frame per second.
      /// @param value The number of frame per seconds. The default is 10.
      virtual animation& frames_per_second(uint32 value);
      
      /// @brief Gets a valiue that indicates if the animation is running.
      /// @return true if the animation is running; otherwise false.
      virtual bool running() const noexcept;
      
      /// @brief Gets a valiue that indicates if the animation is running.
      /// @param value true if the animation is running; otherwise false.
      virtual animation& running(bool value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Starts animation of the animation control.
      void start();
      
      /// @brief Stops animation of the animation control.
      void stop();
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create();
      /// @brief A factory to create an xtd::forms::animation with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::animation with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::animation with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @param name The name of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::animation with specified the number of frame per seconds.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(uint32 frames_per_second);
      /// @brief A factory to create an xtd::forms::animation with specified the number of frame per second, and location.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(uint32 frames_per_second, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::animation with specified the number of frame per second, location, and size.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(uint32 frames_per_second, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::animation with specified the number of frame per second, location, size, and name.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @param name The name of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(uint32 frames_per_second, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::animation with specified parent.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const control& parent);
      /// @brief A factory to create an xtd::forms::animation with specified parent, and location.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::animation with specified parent, location, and size.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::animation with specified parent, location, size, and name.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @param name The name of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::animation with specified parent, and the number of frame per second.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const control& parent, uint32 frames_per_second);
      /// @brief A factory to create an xtd::forms::animation with specified parent, the number of frame per second, and location.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const control& parent, uint32 frames_per_second, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::animation with specified parent, the number of frame per second, location, and size.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const control& parent, uint32 frames_per_second, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::animation with specified parent, the number of frame per second, location, size, and name.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @param name The name of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      static animation create(const control& parent, uint32 frames_per_second, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the specified interval specified by xtd::forms::animation::frames_per_second has elapsed and the animation is started.
      /// @remarks You can use this event to do things like advancing animation parameters, checking the mouse position, etc.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      xtd::event<animation, animation_updated_event_handler> updated;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      drawing::size default_size() const noexcept override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      std::unique_ptr<xtd::object> clone() const override;
      
      /// @brief Raises the updated event.
      /// @param e An event_args that contains the event data. This is always xtd::event_args::empty.
      virtual void on_updated(const xtd::forms::animation_updated_event_args& e);
      /// @}
      
    private:
      void on_frames_timer_tick(object& timer, const xtd::event_args& e);
      
      std::shared_ptr<data> data_;
    };
  }
}
