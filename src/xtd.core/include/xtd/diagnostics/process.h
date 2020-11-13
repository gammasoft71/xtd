/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include "process_start_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class process final {
    public:
      process() = default;
      process(const process&) = default;
      process& operator=(const process&) = default;

      intptr_t handle() const {return data_->handle_;}
      
      process_start_info start_info() const {return data_->start_info_;}
      process& start_info(process_start_info value) {
        data_->start_info_ = value;
        return *this;
      }

      process&  kill();

      static process start(const process_start_info& start_info);
      static process start(const std::string& file_name) {return start(process_start_info(file_name));}
      static process start(const std::string& file_name, const std::string& arguments) {return start(process_start_info(file_name, arguments));}

      process& wait_for_exit();
      
    private:
      struct data {
        intptr_t handle_ = 0;
        process_start_info start_info_;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
