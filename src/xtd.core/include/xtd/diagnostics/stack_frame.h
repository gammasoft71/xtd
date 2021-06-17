/// @file
/// @brief Contains xtd::diagnostics::stack_frame class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
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
    
    /// @brief Provides information about a xtd::diagnostics::stack_frame, which represents a function call on the call stack for the current thread.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    /// @remarks A xtd::diagnostics::stack_frame is created and pushed on the call stack for every function call made during the execution of a thread. The stack frame always includes method information, and optionally includes file name, line number, and column number information.
    /// @remarks xtd::diagnostics::stack_frame information will be most informative with Debug build configurations. By default, Debug builds include debug symbols, while Release builds do not. The debug symbols contain most of the file, method name, line number, and column information used in constructing xtd::diagnostics::stack_frame objects.
    class stack_frame {
    public:
      stack_frame() = default;
      /// @cond
      stack_frame(const stack_frame&) = default;
      stack_frame& operator=(const stack_frame&) = default;
      virtual ~stack_frame();
      /// @endcond

      /// @brief Gets the column number in the file that contains the code that is executing. This information is typically extracted from the debugging symbols for the executable.
      /// @return The file column number, or 0 (zero) if the file column number cannot be determined.
      /// @par Examples
      /// The following example demonstrates the use of the get_file_column_number() method. This code example is part of a larger example provided for the xtd::diagnostics::stack_frame class.
      /// @code
      /// // Display the stack frame properties.
      /// stack_frame sf = st.get_frame(i);
      /// console::write_line(" File: {}", sf.get_file_name());
      /// console::write_line(" Line Number: {}", sf.get_file_line_number());
      /// // Note that the column number defaults to zero when not initialized.
      /// console::write_line(" Column Number: {}", sf.get_file_column_number());
      /// console::write_line(" Method: {}", sf.get_method());
      /// if (sf.get_offset() != stack_frame::OFFSET_UNKNOWN)
      ///   console::write_line(" Offset: {}", sf.get_offset());
      /// @endcode
      virtual size_t get_file_column_number() const;
      
      /// @brief Gets the line number in the file that contains the code that is executing. This information is typically extracted from the debugging symbols for the executable.
      /// @return The file line number, or 0 (zero) if the file line number cannot be determined.
      /// @par Examples
      /// The following example demonstrates the use of the get_file_line_number() method. This code example is part of a larger example provided for the xtd::diagnostics::stack_frame class.
      /// @code
      /// // Display the stack frame properties.
      /// stack_frame sf = st.get_frame(i);
      /// console::write_line(" File: {}", sf.get_file_name());
      /// console::write_line(" Line Number: {}", sf.get_file_line_number());
      /// // Note that the column number defaults to zero when not initialized.
      /// console::write_line(" Column Number: {}", sf.get_file_column_number());
      /// console::write_line(" Method: {}", sf.get_method());
      /// if (sf.get_offset() != stack_frame::OFFSET_UNKNOWN)
      ///   console::write_line(" Offset: {}", sf.get_offset());
      /// @endcode
      virtual size_t get_file_line_number() const;
      
      /// @brief Gets the file name that contains the code that is executing. This information is typically extracted from the debugging symbols for the executable.
      /// @return The file name, or empty ("") if the file name cannot be determined.
      /// @par Examples
      /// The following example demonstrates the use of the get_file_name() method. This code example is part of a larger example provided for the xtd::diagnostics::stack_frame class.
      /// @code
      /// // Display the stack frame properties.
      /// stack_frame sf = st.get_frame(i);
      /// console::write_line(" File: {}", sf.get_file_name());
      /// console::write_line(" Line Number: {}", sf.get_file_line_number());
      /// // Note that the column number defaults to zero when not initialized.
      /// console::write_line(" Column Number: {}", sf.get_file_column_number());
      /// console::write_line(" Method: {}", sf.get_method());
      /// if (sf.get_offset() != stack_frame::OFFSET_UNKNOWN)
      ///   console::write_line(" Offset: {}", sf.get_offset());
      /// @endcode
      virtual const std::string& get_file_name() const;
      
      /// @brief Gets the method in which the frame is executing.
      /// @return The method in which the frame is executing.
      /// @par Examples
      /// The following example demonstrates the use of the get_method() method. This code example is part of a larger example provided for the xtd::diagnostics::stack_frame class.
      /// @code
      /// // Display the stack frame properties.
      /// stack_frame sf = st.get_frame(i);
      /// console::write_line(" File: {}", sf.get_file_name());
      /// console::write_line(" Line Number: {}", sf.get_file_line_number());
      /// // Note that the column number defaults to zero when not initialized.
      /// console::write_line(" Column Number: {}", sf.get_file_column_number());
      /// console::write_line(" Method: {}", sf.get_method());
      /// if (sf.get_offset() != stack_frame::OFFSET_UNKNOWN)
      ///   console::write_line(" Offset: {}", sf.get_offset());
      /// @endcode
      virtual const std::string& get_method() const;
      
      /// @brief Gets the offset from the start of the code for the method that is being executed.
      /// @return The offset from the code for the method that is being executed.
      /// @par Examples
      /// The following example demonstrates the use of the get_offset() method. This code example is part of a larger example provided for the xtd::diagnostics::stack_frame class.
      /// @code
      /// // Display the stack frame properties.
      /// stack_frame sf = st.get_frame(i);
      /// console::write_line(" File: {}", sf.get_file_name());
      /// console::write_line(" Line Number: {}", sf.get_file_line_number());
      /// // Note that the column number defaults to zero when not initialized.
      /// console::write_line(" Column Number: {}", sf.get_file_column_number());
      /// console::write_line(" Method: {}", sf.get_method());
      /// if (sf.get_offset() != stack_frame::OFFSET_UNKNOWN)
      ///   console::write_line(" Offset: {}", sf.get_offset());
      /// @endcode
      virtual size_t get_offset() const;
      
      /// @brief Builds a readable representation of the stack trace.
      /// @return A readable representation of the stack trace.
      virtual std::string to_string() const;

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::diagnostics::stack_frame& stack_frame) noexcept {return os << stack_frame.to_string();}
      /// @endcond

      /// @brief Defines the value that is returned from the get_offset() method when the offset is unknown. This field is constant.
      /// @remarks The value of this constant is 0xFFFFFFFFFFFFFFFF.
      static constexpr const size_t npos = 0xFFFFFFFFFFFFFFFF;
      
      /// @brief Defines the value that is returned from the get_offset() method when the offset is unknown. This field is constant.
      /// @remarks The value of this constant is 0xFFFFFFFFFFFFFFFF.
      static constexpr const size_t OFFSET_UNKNOWN = npos;
      
    private:
      friend class stack_trace;
      stack_frame(const std::string& file_path, size_t file_line, size_t file_column, const std::string& method_name, size_t offset);
      stack_frame(const std::string& method_name, size_t offset);

      std::string file_path_;
      size_t file_line_ = 0;
      size_t file_column_ = 0;
      std::string method_name_;
      size_t offset_ = 0;
    };
  }
}
