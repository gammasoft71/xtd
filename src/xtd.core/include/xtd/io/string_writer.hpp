/// @file
/// @brief Contains xtd::io::string_writer class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "text_writer.hpp"
#include <sstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Implements a xtd::io::text_writer for writing characters to a string.
    /// ```cpp
    /// class core_export_ string_writer : public xtd::io::text_writer
    /// ```
    /// @par Inheritance
    /// xtd::io::text_writer → xtd::io::string_writer
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/string_writer>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ string_writer : public xtd::io::text_writer {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the stream_writer class .
      string_writer() = default;
      /// @brief Initializes a new instance of the stream_writer class for the specified string.
      /// @param str base string.
      explicit string_writer(const xtd::string& str);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      const std::ostream& base_stream() const noexcept;
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      std::ostream& base_stream() noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      void flush() override;
      
      xtd::string to_string() const noexcept override;
      
      /// @brief Writes the specified string value to the text stream.
      /// @param value The value to write
      /// @exception io::io_exception An I/O error occurs.
      void write(const xtd::string& value) override;
      /// @}
      
    private:
      std::stringstream stream_;
    };
  }
}
