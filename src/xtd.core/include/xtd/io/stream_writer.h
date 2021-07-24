/// @file
/// @brief Contains xtd::io::stream_writer class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <fstream>
#include <optional>
#include "text_writer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Represents a writer that can write a sequential series of characters.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class stream_writer : public xtd::io::text_writer {
    public:
      /// @brief Initializes a new instance of the stream_writer class for the specified file name.
      /// @param path The complete file path to be read.
      stream_writer(const std::string& path);
      /// @brief Initializes a new instance of the stream_writer class for the specified stream.
      /// @param stream The stream to be read.
      stream_writer(std::ostream& stream);
      /// @cond
      ~stream_writer();
      /// @endcond
      
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      std::optional<std::reference_wrapper<std::ostream>> base_stream() const;
      
      /// @brief Closes the stream_writer object and the underlying stream, and releases any system resources associated with the reader.
      void close() override;
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      void flush() override;
 
      /// @brief Writes the specified string value to the text stream.
      /// @param value The value to write
      /// @exception io::ioexception An I/O error occurs.
      void write(const std::string& value) override;

    private:
      std::ostream* stream_ = nullptr;
      bool delete_when_destroy_ = false;
    };
  }
}
