/// @file
/// @brief Contains xtd::diagnostics::stack_frame class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

/// @cond
// Like Windows.h, some includes define max as a macro and this causes compilation errors.
#undef max
/// @endcond

#include <cstdint>
#include <limits>
#include "../iequatable.h"
#include "../object.h"
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @cond
    class stack_trace;
    /// @endcond
    
    /// @brief Provides information about a xtd::diagnostics::stack_frame, which represents a function call on the call stack for the current thread.
    /// @code
    /// class core_export_ stack_frame : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::diagnostics::stack_frame
    /// @par Header
    /// @code #include <xtd/diagnostics/stack_frame> @endcode
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    /// @remarks A xtd::diagnostics::stack_frame is created and pushed on the call stack for every function call made during the execution of a thread. The stack frame always includes method information, and optionally includes file name, line number, and column number information.
    /// @remarks xtd::diagnostics::stack_frame information will be most informative with Debug build configurations. By default, Debug builds include debug symbols, while Release builds do not. The debug symbols contain most of the file, method name, line number, and column information used in constructing xtd::diagnostics::stack_frame objects.
    /// @par Examples
    /// The following example demonstrates the use of the xtd::diagnostics::stack_frame class to provide the stack frame information for a stack trace.
    /// @include stack_frame.cpp
    class core_export_ stack_frame : public xtd::object, public xtd::iequatable<stack_frame> {
    public:
    
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class.
      stack_frame();
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class that corresponds to a frame above the current stack frame.
      /// @param skip_frame The number of frames up the stack to skip.
      explicit stack_frame(size_t skip_frame);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class, optionally capturing source information.
      /// @param need_file_info true to capture the file name, line number, and column number of the stack frame; otherwise, false.
      explicit stack_frame(bool need_file_info);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class that corresponds to a frame above the current stack frame, optionally capturing source information.
      /// @param skip_frame The number of frames up the stack to skip.
      /// @param need_file_info true to capture the file name, line number, and column number of the stack frame; otherwise, false.
      stack_frame(size_t skip_frame, bool need_file_info);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class that contains only the given file name, and line number.
      /// @param file_name The file name.
      /// @param line_number The line number in the specified file.
      stack_frame(const xtd::ustring& file_name, uint32 line_number);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class that contains only the given file name, line number, and method name.
      /// @param file_name The file name.
      /// @param line_number The line number in the specified file.
      /// @param method_name The method name.
      stack_frame(const xtd::ustring& file_name, uint32 line_number, const xtd::ustring& method_name);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class that contains only the given file name, line number, and column number.
      /// @param file_name The file name.
      /// @param line_number The line number in the specified file.
      /// @param method_name The method name.
      /// @param offset The offset from the code for the method that is being executed.
      stack_frame(const xtd::ustring& file_name, uint32 line_number, const xtd::ustring& method_name, uint32 column_number);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class that contains only the given file name, line number, and column number.
      /// @param file_name The file name.
      /// @param line_number The line number in the specified file.
      /// @param method_name The method name.
      /// @param column_number The column number in the specified file.
      stack_frame(const xtd::ustring& file_name, uint32 line_number, uint32 column_number);
      /// @brief Initializes a new instance of the xtd::diagnostics::stack_frame class that contains only the given file name, line number, column number, method name, and offset.
      /// @param file_name The file name.
      /// @param line_number The line number in the specified file.
      /// @param method_name The method name.
      /// @param offset The offset from the code for the method that is being executed.
      stack_frame(const xtd::ustring& file_name, uint32 line_number, const xtd::ustring& method_name, uint32 column_number, uint32 offset);
      /// @cond
      stack_frame(const stack_frame&) = default;
      stack_frame(stack_frame&&) = default;
      stack_frame& operator =(const stack_frame&) = default;
      /// @endcond
      /// @}
      
      /// @name Public Fields
      
      /// @{
      /// @brief Return an empty stack frame.
      /// @return Empty stack frame.
      static stack_frame empty() noexcept;
      
      /// @brief Defines the value that is returned from the get_offset() method when the offset is unknown. This field is constant.
      /// @remarks The value of this constant is std::numeric_limit<uint32>::max().
      static constexpr uint32 OFFSET_UNKNOWN = std::numeric_limits<uint32>::max();
      /// @}
      
      /// @name Public Methods
      
      /// @{
      bool equals(const stack_frame& sf) const noexcept override;
      
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
      virtual uint32 get_file_column_number() const noexcept;
      
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
      virtual uint32 get_file_line_number() const noexcept;
      
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
      virtual const xtd::ustring& get_file_name() const noexcept;
      
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
      virtual const xtd::ustring& get_method() const noexcept;
      
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
      virtual uint32 get_offset() const noexcept;
      
      /// @brief Builds a readable representation of the stack trace.
      /// @return A readable representation of the stack trace.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      friend class stack_trace;
      static std::vector<stack_frame> get_stack_frames(const xtd::ustring& str, size_t skip_frames, bool need_file_info) noexcept;
      
      xtd::ustring file_name_;
      uint32 file_line_number_ = 0;
      xtd::ustring method_name_;
      uint32 file_column_number_ = 0;
      uint32 offset_ = OFFSET_UNKNOWN;
    };
  }
}

#include "current_stack_frame.h"
