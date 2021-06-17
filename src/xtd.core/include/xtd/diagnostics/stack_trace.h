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
    /// @remarks xtd::diagnostics::stack_trace information will be most informative with Debug build configurations. By default, Debug builds include debug symbols, while Release builds do not. The debug symbols contain most of the file, method name, line number, and column information used in constructing xtd::diagnostics::stack_frame and xtd::diagnostics::stack_trace objects.
    class core_export_ stack_trace {
    public:
      using frame_collection = std::vector<xtd::diagnostics::stack_frame>;
      
      stack_trace() : stack_trace("", METHODS_TO_SKIP, false) {}
      explicit stack_trace(bool need_file_info) : stack_trace("", METHODS_TO_SKIP, need_file_info) {}
      explicit stack_trace(const xtd::diagnostics::stack_frame& frame);
      explicit stack_trace(size_t skip_frames) : stack_trace("", skip_frames, false) {}
      stack_trace(size_t skip_frames, bool need_file_info) : stack_trace("", skip_frames, need_file_info) {}
      stack_trace(const std::exception& exception) : stack_trace(xtd::strings::full_class_name(exception), METHODS_TO_SKIP, false) {}
      stack_trace(const std::exception& exception, bool need_file_info) : stack_trace(xtd::strings::full_class_name(exception), METHODS_TO_SKIP, need_file_info) {}
      stack_trace(const std::exception& exception, size_t skip_frames) : stack_trace(xtd::strings::full_class_name(exception), skip_frames, false) {}
      stack_trace(const std::exception& exception, size_t skip_frames, bool need_file_info) : stack_trace(xtd::strings::full_class_name(exception), skip_frames, need_file_info) {}
      /// @cond
      stack_trace(const stack_trace&) = default;
      stack_trace& operator=(const stack_trace&) = default;
      /// @endcond
      
      size_t frame_count() const {return frames_.size();}
      
      const xtd::diagnostics::stack_frame& get_frame(size_t index) {return frames_[index];}
            
      const frame_collection& get_frames() const {return frames_;}
      
      std::string to_string() const {return to_string(0);}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::diagnostics::stack_trace& stack_trace) noexcept {return os << stack_trace.to_string();}
      /// @endcond

      static constexpr size_t METHODS_TO_SKIP = 0;
      
    private:
      friend class xtd::system_exception;
      std::string to_string(size_t skip_frames, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) const;
      stack_trace(const std::string& str, size_t skip_frames, bool need_file_info);
      frame_collection frames_;
    };
  }
}
