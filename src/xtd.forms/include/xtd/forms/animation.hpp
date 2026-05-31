/// @file
/// @brief Contains xtd::forms::animation control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "animation_update_event_handler.hpp"
#include "control.hpp"
#include "timer.hpp"
#include <xtd/diagnostics/stopwatch>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents an animation control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/animation>
    /// ```
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
      [[nodiscard]] virtual auto elapsed() const noexcept -> xtd::time_span;
      
      /// @brief Gets the elapsed time for the current frame, in milliseconds.
      /// @return A long integer representing the elapsed time for the current frame, in milliseconds.
      [[nodiscard]] virtual auto elapsed_milliseconds() const noexcept -> xtd::int64;
      
      /// @brief Gets the elapsed time for the current frame, in nanoseconds.
      /// @return A long integer representing the elapsed time for the current frame, in nanoseconds.
      [[nodiscard]] virtual auto elapsed_nanoseconds() const noexcept -> xtd::int64;
      
      /// @brief Gets the elapsed time for the current frame, in ticks.
      /// @return A long integer representing the elapsed time for the current frame, in ticks.
      [[nodiscard]] virtual auto elapsed_ticks() const noexcept -> xtd::int64;
      
      /// @brief Gets the current frame counter value.
      /// @return The current frame counter value.
      [[nodiscard]] virtual auto frame_counter() const noexcept -> xtd::uint32;
      
      /// @brief Gets the number of frame per second.
      /// @return The number of frame per seconds. The default is 10.
      [[nodiscard]] virtual auto frames_per_second() const noexcept -> xtd::uint32;
      /// @brief Sets the number of frame per second.
      /// @param value The number of frame per seconds. The default is 10.
      virtual auto frames_per_second(uint32 value) -> animation&;
      
      /// @brief Gets a valiue that indicates if the animation is running.
      /// @return `true` if the animation is running; otherwise `false`.
      [[nodiscard]] virtual auto running() const noexcept -> bool;
      /// @brief Sets a valiue that indicates if the animation is running.
      /// @param value `true` if the animation is running; otherwise `false`.
      virtual auto running(bool value) -> animation&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Starts animation of the animation control.
      auto start() -> void;
      
      /// @brief Stops animation of the animation control.
      auto stop() -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create() -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const drawing::point& location) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const drawing::point& location, const drawing::size& size) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @param name The name of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified the number of frame per seconds.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(uint32 frames_per_second) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified the number of frame per second, and location.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(uint32 frames_per_second, const drawing::point& location) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified the number of frame per second, location, and size.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(uint32 frames_per_second, const drawing::point& location, const drawing::size& size) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified the number of frame per second, location, size, and name.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @param name The name of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(uint32 frames_per_second, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified parent.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const control& parent) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified parent, and location.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const control& parent, const drawing::point& location) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified parent, location, and size.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const control& parent, const drawing::point& location, const drawing::size& size) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified parent, location, size, and name.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @param name The name of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified parent, and the number of frame per second.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const control& parent, uint32 frames_per_second) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified parent, the number of frame per second, and location.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const control& parent, uint32 frames_per_second, const drawing::point& location) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified parent, the number of frame per second, location, and size.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const control& parent, uint32 frames_per_second, const drawing::point& location, const drawing::size& size) -> animation;
      /// @brief A factory to create an xtd::forms::animation with specified parent, the number of frame per second, location, size, and name.
      /// @param parent The number of frame per seconds of the xtd::forms::animation.
      /// @param frames_per_second The number of frame per seconds of the xtd::forms::animation.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::animation.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::animation.
      /// @param name The name of the xtd::forms::animation.
      /// @return New xtd::forms::animation created.
      [[nodiscard]] static auto create(const control& parent, uint32 frames_per_second, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> animation;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the specified interval specified by xtd::forms::animation::frames_per_second has elapsed and the animation is started.
      /// @remarks You can use this event to do things like advancing animation parameters, checking the mouse position, etc.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<animation, animation_updated_event_handler> updated;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto default_size() const noexcept -> xtd::drawing::size override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      [[nodiscard]] auto clone() const -> xtd::uptr<xtd::object> override;
      
      /// @brief Raises the updated event.
      /// @param e An event_args that contains the event data. This is always xtd::event_args::empty.
      virtual auto on_updated(const xtd::forms::animation_updated_event_args& e) -> void;
      /// @}
      
    private:
      auto on_frames_timer_tick(object& timer, const xtd::event_args& e) -> void;
      
      xtd::sptr<data> data_;
    };
  }
}
