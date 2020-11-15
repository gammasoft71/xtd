/// @file
/// @brief Contains xtd::diagnostics::trace class.
#pragma once
#include <vector>
#include "stack_frame.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class stack_trace {
    public:
      using frame_collection = std::vector<xtd::diagnostics::stack_frame>;
      
      stack_trace() : stack_trace(1) {}
      stack_trace(size_t skip_frames);
      /// @cond
      stack_trace(const stack_trace&) = default;
      stack_trace& operator=(const stack_trace&) = default;
      ~stack_trace();
      /// @endcond
      
      const frame_collection& frames() const {return frames_;}

    private:
      void get_frames(size_t skip_frames);
      frame_collection frames_;
      intptr_t handle_;
    };
  }
}
