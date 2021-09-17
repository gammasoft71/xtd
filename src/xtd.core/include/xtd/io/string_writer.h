/// @file
/// @brief Contains xtd::io::string_writer class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <sstream>
#include "text_writer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Represents a writer that can write a sequential series of characters.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class string_writer : public xtd::io::text_writer {
    public:
      /// @brief Initializes a new instance of the stream_writer class .
      string_writer() = default;
      /// @brief Initializes a new instance of the stream_writer class for the specified string.
      /// @param str base string.
      string_writer(const xtd::ustring& str);
      
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      const std::ostream& base_stream() const noexcept;
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      std::ostream& base_stream() noexcept;

      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      void flush() override;
 
      xtd::ustring to_string() const noexcept override;
      
      /// @brief Writes the specified string value to the text stream.
      /// @param value The value to write
      /// @exception io::io_exception An I/O error occurs.
      void write(const xtd::ustring& value) override;
    private:
      std::stringstream stream_;
    };
  }
}
