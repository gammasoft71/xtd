/// @file
/// @brief Contains xtd::io::binary_reader class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../array.hpp"
#include "../optional.hpp"
#include "../object.hpp"
#include "../string.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Reads primitive data types as binary values in a specific encoding.
    /// ```cpp
    /// class core_export_ binary_reader : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::io::binary_reader
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/binary_reader>
    /// ```
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
    /// @note xtd xtd::io::binary_reader and xtd::io::binary_writer are fully compatible with .NET [BinaryReader](https://learn.microsoft.com/en-us/dotnet/api/system.io.binaryreader)/[BinaryWriter](https://learn.microsoft.com/en-us/dotnet/api/system.io.binarywriter).
    /// @note Files written with xtd can be read directly in C# and vice versa, following the same binary format conventions (7-bit encoded string lengths, little-endian integers, etc.).
    class core_export_ binary_reader : public xtd::object {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::io::binary_reader class for the specified file name.
      /// @param path The complete file path to be read.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters as defined by xtd::io::path::invalid_path_chars.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      explicit binary_reader(const xtd::string& path);
      /// @brief Initializes a new instance of the xtd::io::binary_reader class for the specified stream.
      /// @param stream The stream to be read.
      /// @par Examples
      /// The following code example demonstrates how to store and retrieve application settings in a file.
      /// @include binary_reader.cpp
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      explicit binary_reader(std::istream& stream);
      /// @}
      /// @cond
      binary_reader(const binary_reader&) = delete;
      auto operator =(const binary_reader&) -> binary_reader& = delete;
      ~binary_reader();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      /// @warning Using the underlying stream while reading or while using the xtd::io::binary_reader can cause data loss and corruption. For example, the same bytes might be read more than once, bytes might be skipped, or character reading might become unpredictable.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] auto base_stream() const -> std::optional<xtd::ref<std::istream>>;
      
      /// @brief Gets a value that indicates whether the current stream position is at the end of the stream.
      /// @return `true` if the current stream position is at the end of the stream; otherwise `false`.
      [[nodiscard]] auto end_of_stream() const -> bool;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Closes the xtd::io::binary_reader object and the underlying stream, and releases any system resources associated with the reader.
      auto close() -> void;
      
      /// @brief Returns the next available character and does not advance the byte or character position.
      /// @return The next available character, or EOF if no more characters are available or the stream does not support seeking.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] auto peek_char() const -> xtd::int32;
      
      /// @brief Pop the current top position
      auto pop() -> std::streampos;
      
      /// @brief Push the current position
      /// @param pos The stream position to be push/saved relative to ios_base::beg direction
      auto push(std::streampos pos = 0) -> void;
      
      /// @brief Reads characters from the underlying stream and advances the current position of the stream in accordance with the Encoding used and the specific character being read from the stream.
      /// @return The next character from the input stream, or EOF if no characters are currently available.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read() -> xtd::int32;
      
      /// @brief Reads the specified number of bytes from the stream, starting from a specified point in the byte array.
      /// @param buffer The buffer to read data into.
      /// @param index The starting point in the buffer at which to begin reading into the buffer.
      /// @param count The number of bytes to read.
      /// @return The number of bytes read into buffer. This might be less than the number of bytes requested if that many bytes are not available, or it might be zero if the end of the stream is reached.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io_io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto read(xtd::array<xtd::byte>& buffer, xtd::usize index, xtd::usize count) -> xtd::usize;
      
      /// @brief Reads the specified number of characters from the stream, starting from a specified point in the character array.
      /// @param buffer The buffer to read data into.
      /// @param index The starting point in the buffer at which to begin reading into the buffer.
      /// @param count The number of characters to read.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io_io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto read(xtd::array<char>& buffer, xtd::usize index, xtd::usize count) -> xtd::usize;
      
      /// @brief Reads a boolean value from the current stream and advances the current position of the stream by one byte.
      /// @return `true` if the byte is nonzero; otherwise, `false`.
      /// @exception xtd::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_boolean() -> bool;
      
      /// @brief Reads the next byte from the current stream and advances the current position of the stream by one byte.
      /// @return The next byte read from the current stream.
      /// @exception xtd::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_byte() -> xtd::byte;
      
      /// @brief Reads the specified number of bytes from the current stream into a byte array and advances the current position by that number of bytes.
      /// @param count The number of bytes to read. This value must be 0 or a non-negative number or an exception will occur.
      /// @return A byte array containing data read from the underlying stream. This might be less than the number of bytes requested if the end of the stream is reached.
      /// @exception xtd::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_bytes(xtd::usize count) -> xtd::array<xtd::byte>;
      
      /// @brief Reads the next character from the current stream and advances the current position of the stream by one byte.
      /// @return A character read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_char() -> char;
      
      /// @brief Reads the specified number of characters from the current stream into a byte array and advances the current position by that number of bytes.
      /// @param count The number of characters to read. This value must be 0 or a non-negative number or an exception will occur.
      /// @return A character array containing data read from the underlying stream. This might be less than the number of bytes requested if the end of the stream is reached.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_chars(xtd::usize count) -> xtd::array<char>;
      
      /// @brief Reads an 8-byte floating point value from the current stream and advances the current position of the stream by eight bytes.
      /// @return An 8-byte floating point value read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_double() -> double;
      
      /// @brief Reads a 2-byte signed integer from the current stream and advances the current position of the stream by two bytes.
      /// @return A 2-byte signed integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_int16() -> xtd::int16;
      
      /// @brief Reads a 4-byte signed integer from the current stream and advances the current position of the stream by four bytes.
      /// @return A 4-byte signed integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_int32() -> xtd::int32;
      
      /// @brief Reads a 8-byte signed integer from the current stream and advances the current position of the stream by eight bytes.
      /// @return A 8-byte signed integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_int64() -> xtd::int64;
      
      /// @brief Reads the a signed byte from the current stream and advances the current position of the stream by one byte.
      /// @return A signed byte read from the current stream.
      /// @exception xtd::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_sbyte() -> xtd::sbyte;
      
      /// @brief Reads an 4-byte floating point value from the current stream and advances the current position of the stream by four bytes.
      /// @return An 4-byte floating point value read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_single() -> float;
      
      /// @brief Reads a xtd::usize from the current stream and advances the current position of the stream by eight bytes.
      /// @return A xtd::usize read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_size() -> xtd::usize;
      
      /// @brief Reads a string from the current stream. The string is prefixed with the length.
      /// @return The string being read.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_string() -> xtd::string;
      
      /// @brief Reads a 2-byte unsigned integer from the current stream and advances the current position of the stream by two bytes.
      /// @return A 2-byte unsigned integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_uint16() -> xtd::uint16;
      
      /// @brief Reads a 4-byte unsigned integer from the current stream and advances the current position of the stream by four bytes.
      /// @return A 4-byte unsigned integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_uint32() -> xtd::uint32;
      
      /// @brief Reads a 8-byte unsigned integer from the current stream and advances the current position of the stream by eight bytes.
      /// @return A 8-byte unsigned integer read from the current stream.
      /// @exception xtd::io::end_of_stream_exception The end of the stream is reached.
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @remarks xtd::io::binary_reader does not restore the file position after an unsuccessful read operation.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] virtual auto read_uint64() -> xtd::uint64;
      
      /// @brief Rewind stream
      auto rewind() -> void;
      
      /// @brief Change the position of the readers stream
      /// @param off The offset being added to the direction
      /// @param dir The seek direction. If ommited defaults to ios_base::cur
      virtual auto seek(std::streamoff off, std::ios_base::seekdir dir = std::ios_base::cur) -> void;
      
      /// @brief Tell the current seek position of the readers stream;
      /// @return The current seek position
      [[nodiscard]] auto tell() -> std::streampos;
      /// @}
      
      /// @cond
      auto operator >>(bool& value) -> binary_reader& {value = read_boolean(); return *this;}
      auto operator >>(xtd::byte& value) -> binary_reader& {value = read_byte(); return *this;}
      auto operator >>(char& value) -> binary_reader& {value = read_char(); return *this;}
      auto operator >>(double& value) -> binary_reader& {value = read_double(); return *this;}
      auto operator >>(int16& value) -> binary_reader& {value = read_int16(); return *this;}
      auto operator >>(int32& value) -> binary_reader& {value = read_int32(); return *this;}
      auto operator >>(int64& value) -> binary_reader& {value = read_int64(); return *this;}
      auto operator >>(sbyte& value) -> binary_reader& {value = read_sbyte(); return *this;}
      auto operator >>(float& value) -> binary_reader& {value = read_single(); return *this;}
      auto operator >>(string& value) -> binary_reader& {value = read_string(); return *this;}
      auto operator >>(uint16& value) -> binary_reader& {value = read_uint16(); return *this;}
      auto operator >>(uint32& value) -> binary_reader& {value = read_uint32(); return *this;}
      auto operator >>(uint64& value) -> binary_reader& {value = read_uint64(); return *this;}
      /// @endcond
      
    private:
      [[nodiscard]] auto read_7bit_encoded_int() -> int32;
      std::istream* stream_ = nullptr;
      std::stack<std::streampos> pos_stack_;
      bool delete_when_destroy_ = false;
    };
  }
}
