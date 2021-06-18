/// @file
/// @brief Contains xtd::diagnostics::stopwatch class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <string>
#include "../ticks.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a set of methods and properties that you can use to accurately measure elapsed time.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics
    /// @remarks A xtd::diagnostics::stopwatch instance can measure elapsed time for one interval, or the total of elapsed time across multiple intervals. In a typical xtd::diagnostics::stopwatch scenario, you call the xtd::diagnostics::stopwatch::start method, then eventually call the xtd::diagnostics::stopwatch::stop method, and then you check elapsed time using the xtd::diagnostics::stopwatch::elapsed property.
    /// @remarks A xtd::diagnostics::stopwatch instance is either running or stopped; use xtd::diagnostics::stopwatch::is_running to determine the current state of a xtd::diagnostics::stopwatch::. Use xtd::diagnostics::stopwatch::start to begin measuring elapsed time; use xtd::diagnostics::stopwatch::stop to stop measuring elapsed time. Query the elapsed time value through the properties xtd::diagnostics::stopwatch::elapsed, xtd::diagnostics::stopwatch::elapsed_milliseconds, or xtd::diagnostics::stopwatch::elapsed_ticks. You can query the elapsed time properties while the instance is running or stopped. The elapsed time properties steadily increase while the xtd::diagnostics::stopwatch is running; they remain constant when the instance is stopped.
    /// @remarks By default, the elapsed time value of a xtd::diagnostics::stopwatch:: instance equals the total of all measured time intervals. Each call to xtd::diagnostics::stopwatch::start begins counting at the cumulative elapsed time; each call to xtd::diagnostics::stopwatch::stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the xtd::diagnostics::stopwatch::reset method to clear the cumulative elapsed time in an existing xtd::diagnostics::stopwatch instance.
    /// @remarks The xtd::diagnostics::stopwatch measures elapsed time by counting timer ticks in the underlying timer mechanism. If the installed hardware and operating system support a high-resolution performance counter, then the xtd::diagnostics::stopwatch:: class uses that counter to measure elapsed time. Otherwise, the xtd::diagnostics::stopwatch class uses the system timer to measure elapsed time. Use the xtd::diagnostics::stopwatch::frequency and xtd::diagnostics::stopwatch::is_high_resolution fields to determine the precision and resolution of the xtd::diagnostics::stopwatch timing implementation.
    /// @remarks The xtd::diagnostics::stopwatch class assists the manipulation of timing-related performance counters. Specifically, the xtd::diagnostics::stopwatch::frequency field and xtd::diagnostics::stopwatch::get_timestamp method can be used in place of the Win32 APIs QueryPerformanceFrequency and QueryPerformanceCounter.
    /// @par Examples
    /// The following example demonstrates how to use the xtd::diagnostics::stopwatch class to determine the execution time for an application.
    /// @include stopwatch.cpp
    class stopwatch {
    public:
      /// @brief Initializes a new instance of the xtd::diagnostics::stopwatch class.
      /// @remarks The returned xtd::diagnostics::stopwatch instance is stopped, and the xtd::diagnostics::stopwatch::elapsed time property of the instance is zero.
      /// @remarks Use the xtd::diagnostics::stopwatch::start method to begin measuring elapsed time with the new xtd::diagnostics::stopwatch instance. Use the xtd::diagnostics::stopwatch::start_new method to initialize a new xtd::diagnostics::stopwatch instance and immediately start it.
      /// @par Examples
      /// The following example initializes a xtd::diagnostics::stopwatch instance by using a simple class constructor.
      /// @include stopwatch_constructor.cpp
      stopwatch() = default;
      
      /// @cond
      stopwatch(const stopwatch&) = default;
      stopwatch& operator=(const stopwatch&) = default;
      /// @endcond
      
      /// @brief Gets the frequency of the timer as the number of nanoseconds per second. This field is read-only.
      /// @return The frequency of the timer as the number of nanoseconds per second.
      static int64_t frequency();
      
      /// @brief Indicates whether the timer is based on a high-resolution performance counter. This field is read-only.
      /// @return true if the timer is based on a high-resolution performance counte; otherwise, false.
      /// @remarks The timer used by the xtd::diagnostics::stopwatch class depends on the system hardware and operating system. is_high_resolution is true if the stopwatch timer is based on a high-resolution performance counter. Otherwise, is_high_resolution is false, which indicates that the stopwatch timer is based on the system timer.
      /// @remarks Returns always true
      static bool is_high_resolution();
      
      /// @brief Gets the total elapsed time measured by the current instance.
      /// @return A std::chrono::nanoseconds representing the total elapsed time measured by the current instance.
      /// @remarks This property represents the number of elapsed nanoseconds in the underlying timer mechanism. A nanosecond is the smallest unit of time that the stopwatch timer can measure. Use the Frequency field to convert the ElapsedTicks value into a number of seconds.
      /// @remarks In a typical xtd::diagnostics::stopwatch scenario, you call the xtd::diagnostics::stopwatch::start method, then eventually call the xtd::diagnostics::stopwatch::stop method, and then you check elapsed time using the xtd::diagnostics::stopwatch::elapsed property.
      /// @remarks Use the xtd::diagnostics::stopwatch::elapsed property to retrieve the elapsed time value using std::chrono::nanoseconds methods and properties. For example, you can format the returned std::chrono::nanoseconds instance into a text representation, or pass it to another class that requires a std::chrono::duration parameter.
      /// @remarks You can query the properties xtd::diagnostics::stopwatch::elapsed, xtd::diagnostics::stopwatch::elapsed_milliseconds, xtd::diagnostics::stopwatch::elapsed_ticks, and xtd::diagnostics::stopwatch::elapsed_nanoseconds while the xtd::diagnostics::stopwatch instance is running or stopped. The elapsed time properties steadily increase while the xtd::diagnostics::stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a xtd::diagnostics::stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to xtd::diagnostics::stopwatch::stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the xtd::diagnostics::stopwatch::reset method to clear the cumulative elapsed time in an existing xtd::diagnostics::stopwatch instance.
      /// @par Examples
      /// The following example initializes a xtd::diagnostics::stopwatch instance by using a simple class constructor.
      /// @include stopwatch_constructor.cpp
      std::chrono::nanoseconds elapsed() const;
      
      /// @brief Gets the total elapsed time measured by the current instance, in milliseconds.
      /// @return A long integer representing the total number of milliseconds measured by the current instance.
      /// @remarks This property represents elapsed time rounded down to the nearest whole millisecond value. For higher precision measurements, use the xtd::diagnostics::stopwatch::elapsed, xtd::diagnostics::stopwatch::elapsed_ticks or xtd::diagnostics::stopwatch::elapsed_nanoseconds properties.
      /// @remarks You can query the properties xtd::diagnostics::stopwatch::elapsed, xtd::diagnostics::stopwatch::elapsed_milliseconds, xtd::diagnostics::stopwatch::elapsed_ticks, and xtd::diagnostics::stopwatch::elapsed_nanoseconds while the xtd::diagnostics::stopwatch instance is running or stopped. The elapsed time properties steadily increase while the xtd::diagnostics::stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a xtd::diagnostics::stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to xtd::diagnostics::stopwatch::stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the xtd::diagnostics::stopwatch::reset method to clear the cumulative elapsed time in an existing xtd::diagnostics::stopwatch instance.
      /// @par Examples
      /// The following example demonstrates how to use the xtd::diagnostics::stopwatch class to determine the execution time for an application.
      /// @include stopwatch.cpp
      int64_t elapsed_milliseconds() const;

      /// @brief Gets the total elapsed time measured by the current instance, in nanoseconds.
      /// @return A long integer representing the total number of nanoseconds measured by the current instance.
      /// @remarks This property represents the number of elapsed nanoseconds in the underlying timer mechanism. A nanosecond is the smallest unit of time that the stopwatch timer can measure. Use the Frequency field to convert the ElapsedTicks value into a number of seconds.
      /// @remarks You can query the properties xtd::diagnostics::stopwatch::elapsed, xtd::diagnostics::stopwatch::elapsed_milliseconds, xtd::diagnostics::stopwatch::elapsed_ticks, and xtd::diagnostics::stopwatch::elapsed_nanoseconds while the xtd::diagnostics::stopwatch instance is running or stopped. The elapsed time properties steadily increase while the xtd::diagnostics::stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a xtd::diagnostics::stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to xtd::diagnostics::stopwatch::stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the xtd::diagnostics::stopwatch::reset method to clear the cumulative elapsed time in an existing xtd::diagnostics::stopwatch instance.
      int64_t elapsed_nanoseconds() const;

      /// @brief Gets the total elapsed time measured by the current instance, in timer ticks.
      /// @return A long integer representing the total number of timer ticks measured by the current instance.
      /// @remarks This property represents elapsed time rounded down to the nearest whole nanoseconds value. For higher precision measurements, use the xtd::diagnostics::stopwatch::elapsed_nanoseconds property.
      /// @remarks You can query the properties xtd::diagnostics::stopwatch::elapsed, xtd::diagnostics::stopwatch::elapsed_milliseconds, xtd::diagnostics::stopwatch::elapsed_ticks, and xtd::diagnostics::stopwatch::elapsed_nanoseconds while the xtd::diagnostics::stopwatch instance is running or stopped. The elapsed time properties steadily increase while the xtd::diagnostics::stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a xtd::diagnostics::stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to xtd::diagnostics::stopwatch::stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the xtd::diagnostics::stopwatch::reset method to clear the cumulative elapsed time in an existing xtd::diagnostics::stopwatch instance.
      /// @par Examples
      /// The following example demonstrates how to use the xtd::diagnostics::stopwatch class to determine the execution time for an application.
      /// @include stopwatch.cpp
      int64_t elapsed_ticks() const;
      
      /// @brief Gets a value indicating whether the stopwatch timer is running.
      /// @return true if the stopwatch instance is currently running and measuring elapsed time for an interval; otherwise, false.
      /// @remarks A stopwatch instance begins running with a call to start or start_new. The instance stops running with a call to stop or reset.
      bool is_running() const;
      
      /// @brief Gets the current number of nanoseconds in the timer mechanism.
      /// @return A long integer representing the nanosecond counter value of the underlying timer mechanism.
      static int64_t get_timestamp();
      
      /// @brief Stops time interval measurement and resets the elapsed time to zero.
      /// @remarks A xtd::diagnostics::stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset. Use xtd::diagnostics::stopwatch::stop to stop the current interval measurement and retain the cumulative elapsed time value. Use xtd::diagnostics::stopwatch::reset to stop any interval measurement in progress and clear the elapsed time value.
      void reset();
      
      /// @brief stops time interval measurement, resets the elapsed time to zero, and starts measuring elapsed time.
      /// @remarks A xtd::diagnostics::stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset or restarted. Use xtd::diagnostics::stopwatch::stop to stop the current interval measurement and retain the cumulative elapsed time value. Use xtd::diagnostics::stopwatch::reset to stop any interval measurement in progress and clear the elapsed time value. Use xtd::diagnostics::stopwatch::restart to stop current interval measurement and start a new interval measurement.
      void restart();
      
      /// @brief Starts, or resumes, measuring elapsed time for an interval.
      /// @remarks In a typical xtd::diagnostics::stopwatch scenario, you call the xtd::diagnostics::stopwatch::start method, then eventually call the xtd::diagnostics::stopwatch::stop method, and then you check elapsed time using the xtd::diagnostics::stopwatch::elapsed property.
      /// @remarks Once started, a xtd::diagnostics::stopwatch timer measures the current interval, in elapsed timer ticks, until the instance is stopped or reset. starting a xtd::diagnostics::stopwatch that is already running does not change the timer state or reset the elapsed time properties.
      /// @remarks When a stopwatch instance measures more than one interval, the start method resumes measuring time from the current elapsed time value. A stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset. Use the reset method before calling start to clear the cumulative elapsed time in a stopwatch instance. Use the restart method to reset and start the stopwatch with a single command.
      /// @par Examples
      /// The following example initializes a xtd::diagnostics::stopwatch instance by using a simple class constructor.
      /// @include stopwatch_constructor.cpp
      void start();
      
      /// @brief Initializes a new xtd::diagnostics::stopwatch instance, sets the xtd::diagnostics::stopwatch::elapsed time property to zero, and starts measuring elapsed time.
      /// @remarks This method is equivalent to calling the xtd::diagnostics::stopwatch constructor and then calling xtd::diagnostics::stopwatch::start on the new instance.
      /// @par Examples
      /// The following example demonstrates how to use the xtd::diagnostics::stopwatch class to determine the execution time for an application.
      /// @include stopwatch.cpp
      static stopwatch start_new();
      
      /// @brief Stops measuring elapsed time for an interval.
      /// @remarks In a typical xtd::diagnostics::stopwatch scenario, you call the xtd::diagnostics::stopwatch::start method, then eventually call the xtd::diagnostics::stopwatch::stop method, and then you check elapsed time using the xtd::diagnostics::stopwatch::elapsed property.
      /// @remarks The xtd::diagnostics::stopwatch::stop method ends the current time interval measurement. stopping a xtd::diagnostics::stopwatch that is not running does not change the timer state or reset the elapsed time properties.
      /// @remarks When a xtd::diagnostics::stopwatch instance measures more than one interval, the xtd::diagnostics::stopwatch::stop method is equivalent to pausing the elapsed time measurement. A subsequent call to xtd::diagnostics::stopwatch::start resumes measuring time from the current elapsed time value. Use the xtd::diagnostics::stopwatch::reset method to clear the cumulative elapsed time in a xtd::diagnostics::stopwatch instance.
      /// @par Examples
      /// The following example initializes a xtd::diagnostics::stopwatch instance by using a simple class constructor.
      /// @include stopwatch_constructor.cpp
      void stop();
      
    private:
      explicit stopwatch(bool start);
      bool running_ = false;
      int64_t start_ = 0;
      int64_t stop_ = 0;
    };
  }
}
