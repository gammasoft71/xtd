/// @file
/// @brief Contains xtd::io::text_reader class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "../object.h"
#include "../ustring.h"
#include <cstdio>
#include <istream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class null_text_reader;
    class synchronized_text_reader;
    /// @endcond
    
    /// @brief Represents a reader that can read a sequential series of characters.
    /// @code
    /// class core_export_ text_reader : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::io::text_reader
    /// @par Header
    /// @code #include <xtd/io/text_reader> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ text_reader : public xtd::object {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Provides a text_reader with no data to read from.
      /// @remarks Reading from the null text reader is similar to reading from the end of a stream:
      /// @remarks read and peek methods return EOF.
      /// @remarks read_block method returns zero.
      /// @remarks read_line and read_to_end methods return a string Empty.
      static null_text_reader& null() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Closes the xtd::io::text_reader and releases any system resources associated with the text_reader
      virtual void close();
      
      /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
      /// @return An integer representing the next character to be read, or EOF if no more characters are available or the stream does not support seeking.
      virtual int32 peek() const;
      
      /// @brief Reads the next character from the input stream and advances the character position by one character.
      /// @return The next character from the input stream, or EOF if no more characters are available.
      virtual int32 read();
      
      /// @brief Reads a specified maximum number of characters from the current text reader and writes the data to a buffer, beginning at the specified index.
      /// @param buffer When this method returns, this parameter contains the specified character array with the values between index and (index + count -1) replaced by the characters read from the current source.
      /// @param index The position in buffer at which to begin writing.
      /// @param count The maximum number of characters to read.
      /// @return The number of characters that have been read. The number will be less than or equal to count, depending on whether all input characters have been read.
      virtual size_t read(std::vector<char>& buffer, size_t index, size_t count);
      
      /// @brief Reads a specified maximum number of characters from the current text reader and writes the data to a buffer, beginning at the specified index.
      /// @param buffer When this method returns, this parameter contains the specified character array with the values between index and (index + count -1) replaced by the characters read from the current source.
      /// @param index The position in buffer at which to begin writing.
      /// @param count The maximum number of characters to read.
      /// @return The number of characters that have been read. The number will be less than or equal to count, depending on whether all input characters have been read.
      virtual size_t read_block(std::vector<char>& buffer, size_t index, size_t count);
      
      /// @brief Reads a line of characters from the current stream and returns the data as a string.
      /// @return The next line from the input stream, or the empty string if all characters have been read.
      virtual xtd::ustring read_line();
      
      /// @brief Reads all characters from the current position to the end of the text_reader and returns them as one string.
      /// @return A string containing all characters from the current position to the end of the text_reader.
      /// @exception io::io_exception An I/O error occurs.
      virtual xtd::ustring read_to_end();
      
      /// @brief Creates a thread-safe (synchronized) wrapper around the specified text_reader object.
      /// @param reader The text_reader object to synchronize.
      /// @return text_reader A thread-safe text_reader object.
      static synchronized_text_reader synchronised(text_reader& reader) noexcept;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::io::text_reader class.
      text_reader() = default;
      /// @}
    };
    
    /// @brief Represents a null text reader.
    /// @par Inheritance
    /// xtd::io::text_reader → xtd::io::null_text_reader
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @code
    /// class core_export_ null_text_reader : public xtd::io::text_reader
    /// @endcode
    class core_export_ null_text_reader : public xtd::io::text_reader {
    public:
      /// @name Methods
      
      /// @{
      int32 read() override;
      /// @}
    };
    
    /// @brief Represents a synchronized text reader.
    /// @code
    /// class core_export_ synchronized_text_reader : public xtd::io::text_reader
    /// @endcode
    /// @par Inheritance
    /// xtd::io::text_reader → xtd::io::synchronized_text_reader
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ synchronized_text_reader : public xtd::io::text_reader {
    public:
      /// @name Methods
      
      /// @{
      int32 read() override;
      /// @}
      
    private:
      friend class text_reader;
      explicit synchronized_text_reader(xtd::io::text_reader& reader);
      synchronized_text_reader() = delete;
      xtd::io::text_reader& reader_;
    };
  }
}
