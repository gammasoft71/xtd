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
      /// @exception xtd::argument_exception path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened
      stream_writer(const xtd::ustring& path);
      /// @brief Initializes a new instance of the stream_writer class for the specified stream.
      /// @param stream The stream to be read.
      stream_writer(std::ostream& stream);
      /// @brief Initializes a new instance of the System::IO::StreamWriter class for the specified file on the specified path, using the default encoding and buffer size. If the file exists, it can be either overwritten or appended to. If the file does not exist, this constructor creates a new file.
      /// @param path The complete file path to write to.
      /// @param append Determines whether data is to be appended to the file. If the file exists and append is false, the file is overwritten. If the file exists and append is true, the data is appended to the file. Otherwise, a new file is created.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened
      stream_writer(const xtd::ustring& path, bool append);
      /// @brief Initializes a new instance of the stream_writer class for the specified stream.
      /// @param stream The stream to be read.
      stream_writer(std::ostream& stream, bool append);
      /// @cond
      ~stream_writer();
      /// @endcond
      
      bool auto_flush() const;
      void auto_flush(bool auto_flush);

      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      std::optional<std::reference_wrapper<std::ostream>> base_stream() const;
      
      /// @brief Closes the stream_writer object and the underlying stream, and releases any system resources associated with the reader.
      void close() override;
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      void flush() override;
 
      using text_writer::write;
      /// @brief Writes the specified string value to the text stream.
      /// @param value The value to write
      /// @exception io::io_exception An I/O error occurs.
      void write(const xtd::ustring& value) override;

    private:
      std::ostream* stream_ = nullptr;
      bool auto_flush_ = false;
      bool delete_when_destroy_ = false;
    };
  }
}
