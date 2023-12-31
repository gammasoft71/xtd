/// @file
/// @brief Contains xtd::io::binary_reader class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../optional.h"
#include "../object.h"
#include "../ustring.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Reads primitive data types as binary values in a specific encoding.
    /// @code
    /// class core_export_ binary_reader : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::io::binary_reader
    /// @par Header
    /// @code #include <xtd/io/binary_reader> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Examples
    /// The following code example demonstrates how to store and retrieve application settings in a file.
    /// @include binary_reader.cpp
    /// @par Examples
    /// The same example with stream operators.
    /// @include binary_reader2.cpp
    /// @remarks The xtd:io::binary_reader class provides methods that simplify reading primitive data types from a stream. For example, you can use the xtd:io::binary_reader::read_boolean method to read the next byte as a bool value and advance the current position in the stream by one byte. The class includes read methods that support different data types.
    /// @remarks When you create a new instance of the xtd:io::binary_reader and whether to leave the stream open after disposing the xtd:io::binary_reader object.
    class core_export_ binary_reader : public xtd::object {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::io::binary_reader class for the specified file name.
      /// @param path The complete file path to be read.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters as defined by xtd::io::path::invalid_path_chars.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      explicit binary_reader(const xtd::ustring& path);
      /// @brief Initializes a new instance of the xtd::io::binary_reader class for the specified stream.
      /// @param stream The stream to be read.
      /// @par Examples
      /// The following code example demonstrates how to store and retrieve application settings in a file.
      /// @include binary_reader.cpp
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      explicit binary_reader(std::istream& stream);
      /// @}
      /// @cond
      binary_reader(const binary_reader&) = delete;
      binary_reader& operator =(const binary_reader&) = delete;
      ~binary_reader();
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      /// @warning Using the underlying stream while reading or while using the xtd::io::binary_reader can cause data loss and corruption. For example, the same bytes might be read more than once, bytes might be skipped, or character reading might become unpredictable.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      std::optional<std::reference_wrapper<std::istream>> base_stream() const;
      
      /// @brief Gets a value that indicates whether the current stream position is at the end of the stream.
      /// @return true if the current stream position is at the end of the stream; otherwise false.
      bool end_of_stream() const;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Closes the xtd::io::binary_reader object and the underlying stream, and releases any system resources associated with the reader.
      void close();
      
      /// @brief Returns the next available character and does not advance the byte or character position.
      /// @return The next available character, or EOF if no more characters are available or the stream does not support seeking.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      int32 peek_char() const;
      
      /// @brief Pop the current top position
      std::streampos pop();
      
      /// @brief Push the current position
      /// @param pos The stream position to be push/saved relative to ios_base::beg direction
      void push(std::streampos pos = 0);
      
      /// @brief Reads characters from the underlying stream and advances the current position of the stream in accordance with the Encoding used and the specific character being read from the stream.
      /// @return The next character from the input stream, or EOF if no characters are currently available.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual int32 read();
      
      /// @brief Reads the specified number of bytes from the stream, starting from a specified point in the byte array.
      /// @param buffer The buffer to read data into.
      /// @param index The starting point in the buffer at which to begin reading into the buffer.
      /// @param count The number of bytes to read.
      /// @return The number of bytes read into buffer. This might be less than the number of bytes requested if that many bytes are not available, or it might be zero if the end of the stream is reached.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io_io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual size_t read(std::vector<xtd::byte>& buffer, size_t index, size_t count);
      
      /// @brief Reads the specified number of characters from the stream, starting from a specified point in the character array.
      /// @param buffer The buffer to read data into.
      /// @param index The starting point in the buffer at which to begin reading into the buffer.
      /// @param count The number of characters to read.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io_io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual size_t read(std::vector<char>& buffer, size_t index, size_t count);
      
      /// @brief Reads a boolean value from the current stream and advances the current position of the stream by one byte.
      /// @return true if the byte is nonzero; otherwise, false.
      /// @exception EndOfStreamException The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual bool read_boolean();
      
      /// @brief Reads the next byte from the current stream and advances the current position of the stream by one byte.
      /// @return The next byte read from the current stream.
      /// @exception EndOfStreamException The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual xtd::byte read_byte();
      
      /// @brief Reads the specified number of bytes from the current stream into a byte array and advances the current position by that number of bytes.
      /// @param count The number of bytes to read. This value must be 0 or a non-negative number or an exception will occur.
      /// @return A byte array containing data read from the underlying stream. This might be less than the number of bytes requested if the end of the stream is reached.
      /// @exception EndOfStreamException The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual std::vector<xtd::byte> read_bytes(size_t count);
      
      /// @brief Reads the next character from the current stream and advances the current position of the stream by one byte.
      /// @return A character read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual char read_char();
      
      /// @brief Reads the specified number of characters from the current stream into a byte array and advances the current position by that number of bytes.
      /// @param count The number of characters to read. This value must be 0 or a non-negative number or an exception will occur.
      /// @return A character array containing data read from the underlying stream. This might be less than the number of bytes requested if the end of the stream is reached.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual std::vector<char> read_chars(size_t count);
      
      /// @brief Reads an 8-byte floating point value from the current stream and advances the current position of the stream by eight bytes.
      /// @return An 8-byte floating point value read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual double read_double();
      
      /// @brief Reads a 2-byte signed integer from the current stream and advances the current position of the stream by two bytes.
      /// @return A 2-byte signed integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual int16 read_int16();
      
      /// @brief Reads a 4-byte signed integer from the current stream and advances the current position of the stream by four bytes.
      /// @return A 4-byte signed integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual int32 read_int32();
      
      /// @brief Reads a 8-byte signed integer from the current stream and advances the current position of the stream by eight bytes.
      /// @return A 8-byte signed integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual int64 read_int64();
      
      /// @brief Reads the a signed byte from the current stream and advances the current position of the stream by one byte.
      /// @return A signed byte read from the current stream.
      /// @exception EndOfStreamException The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual sbyte read_sbyte();
      
      /// @brief Reads an 4-byte floating point value from the current stream and advances the current position of the stream by four bytes.
      /// @return An 4-byte floating point value read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual float read_single();
      
      /// @brief Reads a string from the current stream. The string is prefixed with the length.
      /// @return The string being read.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual ustring read_string();
      
      /// @brief Reads a 2-byte unsigned integer from the current stream and advances the current position of the stream by two bytes.
      /// @return A 2-byte unsigned integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual uint16 read_uint16();
      
      /// @brief Reads a 4-byte unsigned integer from the current stream and advances the current position of the stream by four bytes.
      /// @return A 4-byte unsigned integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual uint32 read_uint32();
      
      /// @brief Reads a 8-byte unsigned integer from the current stream and advances the current position of the stream by eight bytes.
      /// @return A 8-byte unsigned integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      virtual uint64 read_uint64();
      
      /// @brief Rewind stream
      void rewind();
      
      /// @brief Change the position of the readers stream
      /// @param off The offset being added to the direction
      /// @param dir The seek direction. If ommited defaults to ios_base::cur
      void seekg(std::streamoff off, std::ios_base::seekdir dir = std::ios_base::cur);
      
      /// @brief Tell the current seek position of the readers stream;
      /// @return The current seek position
      std::streampos tellg();
      /// @}
      
      /// @cond
      binary_reader& operator >>(bool& value) {value = read_boolean(); return *this;}
      binary_reader& operator >>(xtd::byte& value) {value = read_byte(); return *this;}
      binary_reader& operator >>(char& value) {value = read_char(); return *this;}
      binary_reader& operator >>(double& value) {value = read_double(); return *this;}
      binary_reader& operator >>(int16& value) {value = read_int16(); return *this;}
      binary_reader& operator >>(int32& value) {value = read_int32(); return *this;}
      binary_reader& operator >>(int64& value) {value = read_int64(); return *this;}
      binary_reader& operator >>(sbyte& value) {value = read_sbyte(); return *this;}
      binary_reader& operator >>(float& value) {value = read_single(); return *this;}
      binary_reader& operator >>(ustring& value) {value = read_string(); return *this;}
      binary_reader& operator >>(uint16& value) {value = read_uint16(); return *this;}
      binary_reader& operator >>(uint32& value) {value = read_uint32(); return *this;}
      binary_reader& operator >>(uint64& value) {value = read_uint64(); return *this;}
      /// @endcond
      
    private:
      std::istream* stream_ = nullptr;
      std::stack<std::streampos> pos_stack_;
      bool delete_when_destroy_ = false;
    };
  }
}
