/// @file
/// @brief Contains xtd::io::stream_reader class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "text_reader.hpp"
#include "../optional.hpp"
#include <fstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Implements a xtd::io::text_reader that reads characters from a byte stream.
    /// ```cpp
    /// class core_export_ stream_reader : public xtd::io::text_reader
    /// ```
    /// @par Inheritance
    /// xtd::io::text_reader → xtd::io::stream_reader
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/stream_reader>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ stream_reader : public xtd::io::text_reader {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the stream_reader class for the specified file name.
      /// @param path The complete file path to be read.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters as defined by xtd::io::path::invalid_path_chars.
      explicit stream_reader(const xtd::string& path);
      /// @brief Initializes a new instance of the stream_reader class for the specified stream.
      /// @param stream The stream to be read.
      explicit stream_reader(std::istream& stream);
      /// @}
      /// @cond
      stream_reader(const stream_reader&) = delete;
      stream_reader& operator =(const stream_reader&) = delete;
      ~stream_reader();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      std::optional<std::reference_wrapper<std::istream>> base_stream() const;
      
      /// @brief Gets a value that indicates whether the current stream position is at the end of the stream.
      /// @return `true` if the current stream position is at the end of the stream; otherwise `false`.
      bool end_of_stream() const;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Closes the stream_reader object and the underlying stream, and releases any system resources associated with the reader.
      void close() override;
      
      /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
      /// @return An integer representing the next character to be read, or EOF if no more characters are available or the stream does not support seeking.
      int32 peek() const override;
      
      /// @brief Reads the next character from the input stream and advances the character position by one character.
      /// @return The next character from the input stream, or EOF if no more characters are available.
      int32 read() override;
      /// @}
      
    private:
      std::istream* stream_ = nullptr;
      bool delete_when_destroy_ = false;
    };
  }
}
