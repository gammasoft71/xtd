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
    /// @remarks A stopwatch instance can measure elapsed time for one interval, or the total of elapsed time across multiple intervals. In a typical stopwatch scenario, you call the start method, then eventually call the stop method, and then you check elapsed time using the Elapsed property.
    /// @remarks A stopwatch instance is either running or stopped; use IsRunning to determine the current state of a stopwatch. Use start to begin measuring elapsed time; use stop to stop measuring elapsed time. Query the elapsed time value through the properties Elapsed, ElapsedMilliseconds, or ElapsedTicks. You can query the elapsed time properties while the instance is running or stopped. The elapsed time properties steadily increase while the stopwatch is running; they remain constant when the instance is stopped.
    /// @remarks By default, the elapsed time value of a stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the reset method to clear the cumulative elapsed time in an existing stopwatch instance.
    /// @remarks The stopwatch measures elapsed time by counting timer ticks in the underlying timer mechanism. If the installed hardware and operating system support a high-resolution performance counter, then the stopwatch class uses that counter to measure elapsed time. Otherwise, the stopwatch class uses the system timer to measure elapsed time. Use the Frequency and IsHighResolution fields to determine the precision and resolution of the stopwatch timing implementation.
    /// @remarks The stopwatch class assists the manipulation of timing-related performance counters within managed code. Specifically, the Frequency field and get_timestamp method can be used in place of the unmanaged Win32 APIs QueryPerformanceFrequency and QueryPerformanceCounter.
    /// @par Examples
    /// The following example demonstrates how to use the stopwatch class to determine the execution time for an application.
    /// @include stopwatch.cpp
    class stopwatch {
    public:
      /// @brief Initializes a new instance of the stopwatch class.
      /// @remarks The returned stopwatch instance is stopped, and the elapsed time property of the instance is zero.
      /// @remarks Use the start method to begin measuring elapsed time with the new stopwatch instance. Use the start_new method to initialize a new stopwatch instance and immediately start it.
      stopwatch() = default;
      
      /// @cond
      stopwatch(const stopwatch&) = default;
      stopwatch& operator=(const stopwatch&) = default;
      /// @endcond
      
      /// @brief Gets the frequency of the timer as the number of nanoseconds per second. This field is read-only.
      /// @return The frequency of the timer as the number of nanoseconds per second.
      static int64_t frequency() {return std::nano::den;}
      
      /// @brief Indicates whether the timer is based on a high-resolution performance counter. This field is read-only.
      /// @return true if the timer is based on a high-resolution performance counte; otherwise, false.
      /// @remarks The timer used by the stopwatch class depends on the system hardware and operating system. is_high_resolution is true if the stopwatch timer is based on a high-resolution performance counter. Otherwise, is_high_resolution is false, which indicates that the stopwatch timer is based on the system timer.
      /// @remarks Returns always true
      static bool is_high_resolution() {return true;}
      
      /// @brief Gets the total elapsed time measured by the current instance.
      /// @return A  std::chrono::nanoseconds representing the total elapsed time measured by the current instance.
      /// @remarks In a typical stopwatch scenario, you call the start method, then eventually call the stop method, and then you check elapsed time using the elapsed property.
      /// @remarks Use the elapsed property to retrieve the elapsed time value using  std::chrono::nanoseconds methods and properties. For example, you can format the returned  std::chrono::nanoseconds instance into a text representation, or pass it to another class that requires a  std::chrono::duration parameter.
      /// @remarks You can query the properties elapsed, elapsed_milliseconds, elapsed_ticks, and elapsed_nanoseconds while the stopwatch instance is running or stopped. The elapsed time properties steadily increase while the stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the reset method to clear the cumulative elapsed time in an existing stopwatch instance.
      std::chrono::nanoseconds elapsed() const {return std::chrono::nanoseconds(elapsed_nanoseconds());}
      
      /// @brief Gets the total elapsed time measured by the current instance, in milliseconds.
      /// @return A long integer representing the total number of milliseconds measured by the current instance.
      /// @remarks This property represents elapsed time rounded down to the nearest whole millisecond value. For higher precision measurements, use the elapsed, elapsed_ticks or elapsed_nanoseconds properties.
      /// @remarks You can query the properties elapsed, elapsed_milliseconds, elapsed_ticks, and elapsed_nanoseconds while the stopwatch instance is running or stopped. The elapsed time properties steadily increase while the stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the reset method to clear the cumulative elapsed time in an existing stopwatch instance.
      int64_t elapsed_milliseconds() const {return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed()).count();}

      /// @brief Gets the total elapsed time measured by the current instance, in nanoseconds.
      /// @return A long integer representing the total number of nanoseconds measured by the current instance.
      /// @remarks This property represents elapsed time rounded down to the nearest whole nanoseconds value. For higher precision measurements, use the elapsed, elapsed_ticks or elapsed_nanoseconds properties.
      /// @remarks You can query the properties elapsed, elapsed_milliseconds, elapsed_ticks, and elapsed_nanoseconds while the stopwatch instance is running or stopped. The elapsed time properties steadily increase while the stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the reset method to clear the cumulative elapsed time in an existing stopwatch instance.
      int64_t elapsed_nanoseconds() const {
        if (running_) return get_timestamp() - start_;
        return stop_ - start_;
      }

      /// @brief Gets the total elapsed time measured by the current instance, in timer ticks.
      /// @return A long integer representing the total number of timer ticks measured by the current instance.
      /// @remarks This property represents the number of elapsed ticks in the underlying timer mechanism. A tick is the smallest unit of time that the stopwatch timer can measure. Use the Frequency field to convert the ElapsedTicks value into a number of seconds.
      /// @remarks You can query the properties elapsed, elapsed_milliseconds, elapsed_ticks, and elapsed_nanoseconds while the stopwatch instance is running or stopped. The elapsed time properties steadily increase while the stopwatch is running; they remain constant when the instance is stopped.
      /// @remarks By default, the elapsed time value of a stopwatch instance equals the total of all measured time intervals. Each call to start begins counting at the cumulative elapsed time; each call to stop ends the current interval measurement and freezes the cumulative elapsed time value. Use the reset method to clear the cumulative elapsed time in an existing stopwatch instance.
      int64_t elapsed_ticks() const {return std::chrono::duration_cast<ticks>(elapsed()).count();}
      
      /// @brief Gets a value indicating whether the stopwatch timer is running.
      /// @return true if the stopwatch instance is currently running and measuring elapsed time for an interval; otherwise, false.
      /// @remarks A stopwatch instance begins running with a call to start or start_new. The instance stops running with a call to stop or reset.
      bool is_running() const {return running_;}
      
      /// @brief Gets the current number of nanoseconds in the timer mechanism.
      /// @return A long integer representing the nanosecond counter value of the underlying timer mechanism.
      static int64_t get_timestamp() {return std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count();}
      
      /// @brief Stops time interval measurement and resets the elapsed time to zero.
      /// @remarks A stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset. Use stop to stop the current interval measurement and retain the cumulative elapsed time value. Use reset to stop any interval measurement in progress and clear the elapsed time value.
      void reset() {
        start_ = stop_ = 0;
        running_ = false;
      }
      
      /// @brief stops time interval measurement, resets the elapsed time to zero, and starts measuring elapsed time.
      /// @remarks A stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset or restarted. Use stop to stop the current interval measurement and retain the cumulative elapsed time value. Use reset to stop any interval measurement in progress and clear the elapsed time value. Use restart to stop current interval measurement and start a new interval measurement.
      void restart() {
        reset();
        start();
      }
      
      /// @brief Starts, or resumes, measuring elapsed time for an interval.
      /// @remarks In a typical stopwatch scenario, you call the start method, then eventually call the stop method, and then you check elapsed time using the Elapsed property.
      /// @remarks Once started, a stopwatch timer measures the current interval, in elapsed timer ticks, until the instance is stopped or reset. starting a stopwatch that is already running does not change the timer state or reset the elapsed time properties.
      /// @remarks When a stopwatch instance measures more than one interval, the start method resumes measuring time from the current elapsed time value. A stopwatch instance calculates and retains the cumulative elapsed time across multiple time intervals, until the instance is reset. Use the reset method before calling start to clear the cumulative elapsed time in a stopwatch instance. Use the restart method to reset and start the stopwatch with a single command.
      void start() {
        if (running_) return;
        start_ = get_timestamp() - (stop_ - start_);
        running_ = true;
      }
      
      /// @brief Initializes a new stopwatch instance, sets the elapsed time property to zero, and starts measuring elapsed time.
      /// @remarks This method is equivalent to calling the stopwatch constructor and then calling start on the new instance.
      static stopwatch start_new() {return stopwatch(true);}
      
      /// @brief Stops measuring elapsed time for an interval.
      /// @remarks In a typical stopwatch scenario, you call the start method, then eventually call the stop method, and then you check elapsed time using the Elapsed property.
      /// @remarks The stop method ends the current time interval measurement. stopping a stopwatch that is not running does not change the timer state or reset the elapsed time properties.
      /// @remarks When a stopwatch instance measures more than one interval, the stop method is equivalent to pausing the elapsed time measurement. A subsequent call to start resumes measuring time from the current elapsed time value. Use the reset method to clear the cumulative elapsed time in a stopwatch instance.
      void stop() {
        if (!running_) return;
        stop_ = get_timestamp();
        running_ = false;
      }
      
    private:
      explicit stopwatch(bool start) {if (start) this->start();}
      bool running_ = false;
      int64_t start_ = 0;
      int64_t stop_ = 0;
    };
  }
}
