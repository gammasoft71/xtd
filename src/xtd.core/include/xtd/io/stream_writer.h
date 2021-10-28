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
    /// @brief Implements a xtd::io::text_writer for writing characters to a stream.
    /// @par Namespace
    /// xtd::io
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
      /// @brief Initializes a new instance of the xtd::io::stream_writer class for the specified file on the specified path, using the default encoding and buffer size. If the file exists, it can be either overwritten or appended to. If the file does not exist, this constructor creates a new file.
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
      
      /// @brief Gets a value indicating whether the xtd::io::stream_writer will flush its buffer to the underlying stream after every call to xtd::io::text_writer::write(char).
      /// @return true to force xtd::io::stream_writer to flush its buffer; otherwise, false.
      /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call xtd::io::stream_writer::flush or xtd::io::stream_writer::close. Setting xtd::io::stream_writer::auto_flush to true means that data will be flushed from the buffer to the stream after each write operation, but the encoder state will not be flushed.
      /// @remarks When xtd::io::stream_writer::auto_flush is set to false, xtd::io::stream_writer will do a limited amount of buffering, both internally and potentially in the encoder from the encoding you passed in. You can get better performance by setting AutoFlush to false, assuming that you always call xtd::io::stream_writer::close (or at least Flush) when you're done writing with a xtd::io::stream_writer.
      /// @remarks For example, set xtd::io::stream_writer::auto_flush to true when you are writing to a device where the user expects immediate feedback. xtd::console::out is one of these cases: The xtd::io::stream_writer used internally for writing to xtd::console flushes all its internal state except the encoder state after every call to xtd::io::stream_writer::write.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      bool auto_flush() const;
      /// @brief Sets a value indicating whether the xtd::io::stream_writer will flush its buffer to the underlying stream after every call to xtd::io::text_writer::write(char).
      /// @param auto_flush true to force xtd::io::stream_writer to flush its buffer; otherwise, false.
      /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call xtd::io::stream_writer::flush or xtd::io::stream_writer::close. Setting xtd::io::stream_writer::auto_flush to true means that data will be flushed from the buffer to the stream after each write operation, but the encoder state will not be flushed.
      /// @remarks When xtd::io::stream_writer::auto_flush is set to false, xtd::io::stream_writer will do a limited amount of buffering, both internally and potentially in the encoder from the encoding you passed in. You can get better performance by setting AutoFlush to false, assuming that you always call xtd::io::stream_writer::close (or at least Flush) when you're done writing with a xtd::io::stream_writer.
      /// @remarks For example, set xtd::io::stream_writer::auto_flush to true when you are writing to a device where the user expects immediate feedback. xtd::console::out is one of these cases: The xtd::io::stream_writer used internally for writing to xtd::console flushes all its internal state except the encoder state after every call to xtd::io::stream_writer::write.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
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
