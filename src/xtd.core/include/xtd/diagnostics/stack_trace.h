/// @file
/// @brief Contains xtd::diagnostics::trace class.
#pragma once
#include <exception>
#include <vector>
#include "stack_frame.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class stack_trace {
    public:
      using frame_collection = std::vector<xtd::diagnostics::stack_frame>;
      
      stack_trace() : stack_trace("", METHODS_TO_SKIP, false) {}
      explicit stack_trace(bool need_file_info) : stack_trace("", METHODS_TO_SKIP, need_file_info) {}
      explicit stack_trace(size_t skip_frames) : stack_trace("", skip_frames, false) {}
      stack_trace(size_t skip_frames, bool need_file_info) : stack_trace("", skip_frames, need_file_info) {}
      stack_trace(const std::exception& exception) : stack_trace(xtd::strings::full_class_name(exception), METHODS_TO_SKIP, false) {}
      stack_trace(const std::exception& exception, bool need_file_info) : stack_trace(xtd::strings::full_class_name(exception), METHODS_TO_SKIP, need_file_info) {}
      stack_trace(const std::exception& exception, size_t skip_frames) : stack_trace(xtd::strings::full_class_name(exception), skip_frames, false) {}
      stack_trace(const std::exception& exception, size_t skip_frames, bool need_file_info) : stack_trace(xtd::strings::full_class_name(exception), skip_frames, need_file_info) {}
      /// @cond
      stack_trace(const stack_trace&) = default;
      stack_trace& operator=(const stack_trace&) = default;
      ~stack_trace();
      /// @endcond
      
      const frame_collection& frames() const {return frames_;}
            
      std::string to_string() const;

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::diagnostics::stack_trace& stack_trace) noexcept {return os << stack_trace.to_string();}
      /// @endcond

      static constexpr size_t METHODS_TO_SKIP = 0;
      
    private:
      stack_trace(const std::string& str, size_t skip_frames, bool need_file_info);
      void get_frames(const std::string& str, size_t skip_frames, bool need_file_info);
      frame_collection frames_;
      intptr_t handle_;
    };
  }
}
