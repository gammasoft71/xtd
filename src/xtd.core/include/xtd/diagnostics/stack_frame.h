/// @file
/// @brief Contains xtd::diagnostics::trace class.
#pragma once
#include <cstdint>
#include "../strings.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @cond
    class stack_trace;
    /// @endcond
    
    class stack_frame {
    public:
      stack_frame() = default;
      /// @cond
      stack_frame(const stack_frame&) = default;
      stack_frame& operator=(const stack_frame&) = default;
      virtual ~stack_frame() {}
      /// @endcond

      virtual const std::string& file_path() const {return file_path_;}
      virtual stack_frame& file_path(const std::string& file_path) {
        file_path_ = file_path;
        return *this;
      }
      
      virtual size_t file_line() const {return file_line_;}
      virtual stack_frame& file_line(size_t file_line) {
        file_line_ = file_line;
        return *this;
      }
      
      virtual size_t file_column() const {return file_column_;}
      virtual stack_frame& file_column(size_t file_column) {
        file_column_ = file_column;
        return *this;
      }

      virtual const std::string& method_name() const {return method_name_;}
      virtual stack_frame& method_name(const std::string& method_name) {
        method_name_ = method_name;
        return *this;
      }
      
      virtual size_t offset() const {return offset_;}
      virtual stack_frame& offset(size_t offset) {
        offset_ = offset;
        return *this;
      }
      
      virtual std::string to_string() const {return xtd::strings::format("{} at {}  in file:line:column {} : {} : {}", method_name_.empty() ? "<unknown method>" : method_name_, file_path_.empty() ? "<unknown offset>" : std::to_string(offset_), file_path_.empty() ? "<filename unknown>" : file_path_, file_line_, file_column_);}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::diagnostics::stack_frame& stack_frame) noexcept {return os << stack_frame.to_string();}
      /// @endcond

    private:
      friend class stack_trace;
      stack_frame(const std::string& file_path, size_t file_line, size_t file_column, const std::string& method_name, size_t offset) : file_path_(file_path), file_line_(file_line), file_column_(file_column), method_name_(method_name), offset_(offset) {}
      stack_frame(const std::string& method_name, size_t offset) : method_name_(method_name), offset_(offset) {}

      std::string file_path_;
      size_t file_line_ = 0;
      size_t file_column_ = 0;
      std::string method_name_;
      size_t offset_ = 0;
    };
  }
}
