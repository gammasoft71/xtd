/// @file
/// @brief Contains xtd::diagnostics::stack_trace class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <exception>
#include <memory>
#include <vector>
#include "../core_export.h"
#include "stack_frame.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class system_exception;
  /// @endcond
  
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Represents a stack trace, which is an ordered collection of one or more stack frames.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    /// @par Examples
    /// The following console application demonstrates how to create a simple xtd::diagnostics::stack_trace and iterate through its frames to obtain debugging and diagnostic information.
    /// @include stack_trace_simple.cpp
    /// @remarks xtd::diagnostics::stack_trace information will be most informative with Debug build configurations. By default, Debug builds include debug symbols, while Release builds do not. The debug symbols contain most of the file, method name, line number, and column information used in constructing xtd::diagnostics::stack_frame and xtd::diagnostics::stack_trace objects.
    /// @remarks xtd::diagnostics::stack_trace might not report as many method calls as expected, due to code transformations that occur during optimization.
    class core_export_ stack_trace {
    public:
      /// @brief Represents a stack_frame collection.
      using stack_frame_collection = std::vector<xtd::diagnostics::stack_frame>;
      
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_trace class from the caller's frame.
      /// @par Examples
      /// The following code example displays the first and last function calls in a stack trace.
      /// @code
      /// void Level_5_method() {
      ///   try {
      ///     class_level_6 nested_class;
      ///     nested_class.level_6_method();
      ///   } catch (const system_exception& e) {
      ///     console::write_line(" Level_5_method exception handler");
      ///
      ///     stack_trace st;
      ///
      ///     // Display the most recent function call.
      ///     stack_frame sf = st.get_frame(0);
      ///     console::write_line();
      ///     console::write_line("  Exception in method: ");
      ///     console::write_line("      {}", sf.get_method());
      ///
      ///     if (st.frame_count() >1) {
      ///       // Display the highest-level function call
      ///       // in the trace.
      ///       sf = st.get_frame(st.frame_count() - 1);
      ///       console::write_line("  Original function call at top of call stack):");
      ///       console::write_line("      {}", sf.get_method());
      ///     }
      ///
      ///     console::write_line();
      ///     console::write_line("   ... throwing exception to next level ...");
      ///     console::write_line("-------------------------------------------------\n");
      ///     throw e;
      ///   }
      /// }
      /// @endcode
      /// @remarks The xtd::diagnostics::stack_trace is created with the caller's current thread, and does not contain file name, line number, or column information.
      /// @remarks Use this parameterless constructor when you want a complete trace with only summary method information about the call stack.
      stack_trace();
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_trace class from the caller's frame, optionally capturing source information.
      /// @param need_file_info true to capture the file name, line number, and column number; otherwise, false.
      /// @par Examples
      /// The following code example displays the first and last function calls in a stack trace.
      /// @code
      /// void Level_5_method() {
      ///   try {
      ///     class_level_6 nested_class;
      ///     nested_class.level_6_method();
      ///   } catch (const system_exception& e) {
      ///     console::write_line(" Level_5_method exception handler");
      ///
      ///     stack_trace st;
      ///
      ///     // Display the most recent function call.
      ///     stack_frame sf = st.get_frame(0);
      ///     console::write_line();
      ///     console::write_line("  Exception in method: ");
      ///     console::write_line("      {}", sf.get_method());
      ///
      ///     if (st.frame_count() >1) {
      ///       // Display the highest-level function call
      ///       // in the trace.
      ///       sf = st.get_frame(st.frame_count() - 1);
      ///       console::write_line("  Original function call at top of call stack):");
      ///       console::write_line("      {}", sf.get_method());
      ///     }
      ///
      ///     console::write_line();
      ///     console::write_line("   ... throwing exception to next level ...");
      ///     console::write_line("-------------------------------------------------\n");
      ///     throw e;
      ///   }
      /// }
      /// @endcode
      /// @remarks The xtd::diagnostics::stack_trace is created with the caller's current thread.
      explicit stack_trace(bool need_file_info);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_trace class that contains a single frame.
      /// @param frame The frame that the xtd::diagnostics::stack_trace object should contain.
      /// @par Examples
      /// The following code example writes stack trace information to an event log entry.
      /// @code
      /// stack_frame fr(1, true);
      /// stack_trace st(fr);
      /// debug::write_line(strings::format("{}\n{}", fr.get_method(), st.to_string());
      /// @endcode
      /// @remarks Use this constructor when you do not want the overhead of a full stack trace.
      explicit stack_trace(const xtd::diagnostics::stack_frame& frame);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_trace class using the provided exception object.
      /// @param exception The exception object from which to construct the stack trace.
      /// @remarks The xtd::diagnostics::stack_trace is created with the caller's current thread, and does not contain file name, line number, or column information.
      /// @remarks The resulting stack trace describes the stack at the time of the exception.
      stack_trace(const std::exception& exception);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_trace class from the caller's frame, skipping the specified number of frames.
      /// @param skip_frames The number of frames up the stack from which to start the trace.
      /// @remarks The xtd::diagnostics::stack_trace is created with the caller's current thread, and does not contain file name, line number, or column information.
      /// @remarks If the number of frames to skip is greater than or equal to the total number of frames on the call stack at the time the instance is created, the xtd::diagnostics::stack_trace will contain no frames.
      explicit stack_trace(size_t skip_frames);
      /// @brief Initializes a new instance of the StackTrace class using the provided exception object and skipping the specified number of frames.
      /// @param exception The exception object from which to construct the stack trace.
      /// @param skip_framed The number of frames up the stack from which to start the trace.
      /// @remarks The xtd::diagnostics::stack_trace does not contain file name, line number, or column information.
      /// @remarks The resulting stack trace describes the stack at the time of the exception.
      /// @remarks If the number of frames to skip is greater than or equal to the total number of frames on the call stack at the time the instance is created, the xtd::diagnostics::stack_trace will contain no frames.
      stack_trace(const std::exception& exception, size_t skip_frames);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_trace class from the caller's frame, skipping the specified number of frames and optionally capturing source information.
      /// @param skip_frames The number of frames up the stack from which to start the trace.
      /// @param need_file_info true to capture the file name, line number, and column number; otherwise, false.
      /// @par Examples
      /// The following code example displays the first and last function calls in a stack trace.
      /// @code
      /// void Level_5_method() {
      ///   try {
      ///     class_level_6 nested_class;
      ///     nested_class.level_6_method();
      ///   } catch (const system_exception& e) {
      ///     console::write_line(" Level_5_method exception handler");
      ///
      ///     stack_trace st;
      ///
      ///     // Display the most recent function call.
      ///     stack_frame sf = st.get_frame(0);
      ///     console::write_line();
      ///     console::write_line("  Exception in method: ");
      ///     console::write_line("      {}", sf.get_method());
      ///
      ///     if (st.frame_count() >1) {
      ///       // Display the highest-level function call
      ///       // in the trace.
      ///       sf = st.get_frame(st.frame_count() - 1);
      ///       console::write_line("  Original function call at top of call stack):");
      ///       console::write_line("      {}", sf.get_method());
      ///     }
      ///
      ///     console::write_line();
      ///     console::write_line("   ... throwing exception to next level ...");
      ///     console::write_line("-------------------------------------------------\n");
      ///     throw e;
      ///   }
      /// }
      /// @endcode
      /// @remarks If the number of frames to skip is greater than or equal to the total number of frames on the call stack at the time the instance is created, the xtd::diagnostics::stack_trace will contain no frames.
      stack_trace(size_t skip_frames, bool need_file_info);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_trace class using the provided exception object, skipping the specified number of frames and optionally capturing source information.
      /// @param exception The exception object from which to construct the stack trace.
      /// @param skip_frames The number of frames up the stack from which to start the trace.
      /// @param need_file_info true to capture the file name, line number, and column number; otherwise, false.
      /// @remarks The resulting stack trace describes the stack at the time of the exception.
      /// @remarks If the number of frames to skip is greater than or equal to the total number of frames on the call stack at the time the instance is created, the xtd::diagnostics::stack_trace will contain no frames.
      stack_trace(const std::exception& exception, size_t skip_frames, bool need_file_info);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_trace class, using the provided exception object and optionally capturing source information.
      /// @param exception The exception object from which to construct the stack trace.
      /// @param need_file_info true to capture the file name, line number, and column number; otherwise, false.
      /// @remarks The resulting stack trace describes the stack at the time of the exception.
      stack_trace(const std::exception& exception, bool need_file_info);
      /// @cond
      stack_trace(const stack_trace&) = default;
      stack_trace& operator=(const stack_trace&) = default;
      /// @endcond
      
      /// @brief Gets the number of frames in the stack trace.
      /// @return The number of frames in the stack trace.
      /// @par Examples
      /// The following code example displays the first and last function calls in a stack trace.
      /// @code
      /// void Level_5_method() {
      ///   try {
      ///     class_level_6 nested_class;
      ///     nested_class.level_6_method();
      ///   } catch (const system_exception& e) {
      ///     console::write_line(" Level_5_method exception handler");
      ///
      ///     stack_trace st;
      ///
      ///     // Display the most recent function call.
      ///     stack_frame sf = st.get_frame(0);
      ///     console::write_line();
      ///     console::write_line("  Exception in method: ");
      ///     console::write_line("      {}", sf.get_method());
      ///
      ///     if (st.frame_count() >1) {
      ///       // Display the highest-level function call
      ///       // in the trace.
      ///       sf = st.get_frame(st.frame_count() - 1);
      ///       console::write_line("  Original function call at top of call stack):");
      ///       console::write_line("      {}", sf.get_method());
      ///     }
      ///
      ///     console::write_line();
      ///     console::write_line("   ... throwing exception to next level ...");
      ///     console::write_line("-------------------------------------------------\n");
      ///     throw e;
      ///   }
      /// }
      /// @endcode
      size_t frame_count() const;
      
      /// @brief Gets the specified stack frame.
      /// @param index The index of the stack frame requested.
      /// @return The specified stack frame.
      /// @par Examples
      /// The following code example displays the first and last function calls in a stack trace.
      /// @code
      /// void Level_5_method() {
      ///   try {
      ///     class_level_6 nested_class;
      ///     nested_class.level_6_method();
      ///   } catch (const system_exception& e) {
      ///     console::write_line(" Level_5_method exception handler");
      ///
      ///     stack_trace st;
      ///
      ///     // Display the most recent function call.
      ///     stack_frame sf = st.get_frame(0);
      ///     console::write_line();
      ///     console::write_line("  Exception in method: ");
      ///     console::write_line("      {}", sf.get_method());
      ///
      ///     if (st.frame_count() >1) {
      ///       // Display the highest-level function call
      ///       // in the trace.
      ///       sf = st.get_frame(st.frame_count() - 1);
      ///       console::write_line("  Original function call at top of call stack):");
      ///       console::write_line("      {}", sf.get_method());
      ///     }
      ///
      ///     console::write_line();
      ///     console::write_line("   ... throwing exception to next level ...");
      ///     console::write_line("-------------------------------------------------\n");
      ///     throw e;
      ///   }
      /// }
      /// @endcode
      /// @remarks Stack frames are numbered starting at 0, which is the last stack frame pushed.
      const xtd::diagnostics::stack_frame& get_frame(size_t index);
            
      /// @brief Returns a copy of all stack frames in the current stack trace.
      /// @return An array of type xtd::diagnostics::stack_frame representing the function calls in the stack trace.
      /// @par Examples
      /// The following code example demonstrates enumerating the frames in a xtd::diagnostics::stack_trace.
      /// @code
      /// stack_trace st(1, true);
      /// stack_trace::stack_frame_collection st_frames = st.get_frames();
      ///
      /// for(const stack_frame& sf : st_frames) {
      ///   console::write_line("Method: {}", sf.get_method());
      /// }
      /// @endcode
      /// @remarks Use the returned xtd::diagnostics::stack_frame array to enumerate and examine function calls in the xtd::diagnostics::stack_trace. The size of the returned array is equal to the frame_count() property value.
      /// @remarks The xtd::diagnostics::stack_frame array elements are in reverse chronological order. The xtd::diagnostics::stack_frame at array index 0 represents the most recent function call in the stack trace and the last frame pushed onto the call stack. The xtd::diagnostics::stack_frame at array index frame_count() minus 1 represents the oldest function call in the stack trace and the first frame pushed onto the call stack.
      /// @remarks Use the get_frames() method to obtain all stack frames in a stack trace; use the get_frame(size_t) method to obtain a specific stack frame in a stack trace. The xtd::diagnostics::stack_frame indexes are ordered alike by the two methods. For example, the xtd::diagnostics::stack_frame at index 0 in the array returned by get_frames() is equivalent to the xtd::diagnostics::stack_frame returned by get_frame(size_t) with an input index of 0.
      const stack_frame_collection& get_frames() const;
      
      /// @brief Builds a readable representation of the stack trace.
      /// @return A readable representation of the stack trace.
      /// @par Examples
      /// The following code example writes stack trace information to an event log entry.
      /// @code
      /// stack_frame fr(1, true);
      /// stack_trace st(fr);
      /// debug::write_line(strings::format("{}\n{}", fr.get_method(), st.to_string());
      /// @endcode
      std::string to_string() const;

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::diagnostics::stack_trace& stack_trace) noexcept {return os << stack_trace.to_string();}
      /// @endcond

      /// @brief Defines the default for the number of methods to omit from the stack trace. This field is constant.
      /// @remarks The default value for the number of methods to skip at the beginning of the stack trace. The value of this constant is 0.
      static constexpr size_t METHODS_TO_SKIP = 0;
      
    private:
      friend class xtd::system_exception;
      stack_trace(const std::string& str, size_t skip_frames, bool need_file_info);
      std::string to_string(size_t skip_frames, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) const;
      
      stack_frame_collection frames_;
    };
  }
}
