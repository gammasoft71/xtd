/// @file
/// @brief Contains xtd::forms::animation_updated_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/event_args>
#include <xtd/time_span>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the animation update event.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/animation_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class animation_updated_event_args : public event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      animation_updated_event_args(int32 frame_counter, int64 elapsed_nanoseconds) : frame_counter_(frame_counter), elapsed_nanoseconds_(elapsed_nanoseconds) {}
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets elepased time in nanoseconds.
      /// @return Elapsed time in nanoseconds
      time_span elapsed() const {return time_span {std::chrono::duration_cast<xtd::ticks>(std::chrono::nanoseconds {elapsed_nanoseconds_}).count()};}
      /// @brief Gets elepased time in milliseconds.
      /// @return Elapsed time in milliseconds
      int64 elapsed_milliseconds() const {return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::nanoseconds {elapsed_nanoseconds_}).count();}
      /// @brief Gets elepased time in nanoseconds.
      /// @return Elapsed time in nanoseconds
      int64 elapsed_nanoseconds() const {return elapsed_nanoseconds_;}
      
      /// @brief Gets frame counter.
      /// @return Frame counter.
      int32 frame_counter() const {return frame_counter_;}
      /// @}
      
    private:
      int32 frame_counter_ = 0;
      int64 elapsed_nanoseconds_ {0};
    };
  }
}
