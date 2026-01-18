/// @file
/// @brief Contains xtd::io::binary_writer class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "../array.hpp"
#include "../fixed_array.hpp"
#include "../object.hpp"
#include "../optional.hpp"
#include "../read_only_span"
#include "../string.hpp"
#include <fstream>
#include <array>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Writes primitive types in binary to a stream and supports writing strings.
    /// ```cpp
    /// class core_export_ binary_writer : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::io::binary_writer
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/binary_writer>
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
    /// @remarks The xtd::io::binary_writer class provides methods that simplify writing primitive data types to a stream. For example, you can use the Write method to write a Boolean value to the stream as a one-byte value. The class includes write methods that support different data types.
    /// @remarks When you create a new instance of the xtd::io::binary_writer class, you provide the stream to write to.
    /// @note xtd xtd::io::binary_reader and xtd::io::binary_writer are fully compatible with .NET [BinaryReader](https://learn.microsoft.com/en-us/dotnet/api/system.io.binaryreader)/[BinaryWriter](https://learn.microsoft.com/en-us/dotnet/api/system.io.binarywriter).
    /// @note Files written with xtd can be read directly in C# and vice versa, following the same binary format conventions (7-bit encoded string lengths, little-endian integers, etc.).
    class core_export_ binary_writer : public xtd::object {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the binary_writer class for the specified file name.
      /// @param path The complete file path to be read.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened
      explicit binary_writer(const xtd::string& path);
      /// @brief Initializes a new instance of the binary_writer class for the specified stream.
      /// @param stream The stream to be read.
      explicit binary_writer(std::ostream& stream);
      /// @}
      /// @cond
      binary_writer(const binary_writer&) = delete;
      binary_writer& operator =(const binary_writer&) = delete;
      ~binary_writer();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      [[nodiscard]] auto base_stream() const -> std::optional<xtd::ref<std::ostream>>;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Closes the xtd::io::binary_writer object and the underlying stream, and releases any system resources associated with the reader.
      virtual auto close() -> void;
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      virtual auto flush() -> void;
      
      /// @brief Sets the position within the current stream.
      /// @param ofsset A byte offset relative to origin.
      /// @param origin A field of std::ios::seekdir indicating the reference point from which the new position is to be obtained.
      /// @return The position with the current stream.
      /// @exception xtd::io::io_exception The file pointer was moved to an invalid location.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto seek(xtd::size offset, std::ios::seekdir origin) -> xtd::size;
      
      /// @brief Tell the current seek position of the readers stream;
      /// @return The current seek position
      [[nodiscard]] virtual auto tell() -> std::streampos;

      /// @brief Writes a one-byte boolean value to the current stream, with 0 representing `false` and 1 representing `true`.
      /// @param value The boolean value to write (0 or 1).
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(bool value) -> void;
      
      /// @brief Writes an unsigned byte to the current stream and advances the stream position by one byte.
      /// @param value The unsigned byte to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(xtd::byte value) -> void;
      
      /// @brief Writes a character to the current stream and advances the current position by one byte.
      /// @param value The character to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(char value) -> void;
      
      /// @brief Writes a byte array to the underlying stream.
      /// @param buffer A byte array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      template<xtd::size size>
      auto write(const std::array<xtd::byte, size>& buffer) -> void {
        for (auto b : buffer)
          write(b);
      }
      
      /// @brief Writes a character array to the underlying stream.
      /// @param buffer A character array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      template<xtd::size size>
      auto write(const std::array<char, size>& buffer) -> void {
        for (auto c : buffer)
          write(c);
      }
      
      /// @brief Writes a byte array to the underlying stream.
      /// @param buffer A byte array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(const xtd::read_only_span<xtd::byte>& buffer) -> void;
      
      /// @brief Writes a region of a byte array to the current stream.
      /// @param buffer A byte array containing the data to write.
      /// @param index The index of the first byte to read from buffer and to write to the stream.
      /// @param count The number of bytes to read from buffer and to write to the stream.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(const xtd::array<xtd::byte>& buffer, xtd::size index, xtd::size count) -> void;
      
      /// @brief Writes a character array to the underlying stream.
      /// @param buffer A character array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(const xtd::read_only_span<char>& buffer) -> void;
      
      /// @brief Writes a region of a character array to the current stream.
      /// @param buffer A character array containing the data to write.
      /// @param index The index of the first byte to read from buffer and to write to the stream.
      /// @param count The number of bytes to read from buffer and to write to the stream.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(const xtd::array<char>& buffer, xtd::size index, xtd::size count) -> void;
      
      /// @brief Writes an eight-byte floating-point value to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte floating-point value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(double value) -> void;
      
      /// @brief Writes a two-byte signed integer to the current stream and advances the stream position by two bytes.
      /// @param value The two-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(int16 value) -> void;
      
      /// @brief Writes a four-byte signed integer to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(xtd::int32 value) -> void;
      
      /// @brief Writes a eight-byte signed integer to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(xtd::int64 value) -> void;
      
      /// @brief Writes an signed byte to the current stream and advances the stream position by one byte.
      /// @param value The signed byte to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(xtd::sbyte value) -> void;
      
      /// @brief Writes an four-byte floating-point value to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte floating-point value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(float value) -> void;
      
      /// @brief Writes a length-prefixed string to this stream, and advances the current position of the stream and the specific characters being written to the stream.
      /// @param value The value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(const xtd::string& value) -> void;
      /// @cond
      virtual auto write(const std::string& value) -> void;
      virtual auto write(const std::u8string& value) -> void;
      virtual auto write(const std::u16string& value) -> void;
      virtual auto write(const std::u32string& value) -> void;
      virtual auto write(const std::wstring& value) -> void;
      virtual auto write(const char* value) -> void;
      virtual auto write(const xtd::char8* value) -> void;
      virtual auto write(const xtd::char16* value) -> void;
      virtual auto write(const xtd::char32* value) -> void;
      virtual auto write(const xtd::wchar* value) -> void;
      /// @endcond
      
      /// @brief Writes a two-byte unsigned integer to the current stream and advances the stream position by two bytes.
      /// @param value The two-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(xtd::uint16 value) -> void;
      
      /// @brief Writes a four-byte unsigned integer to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(xtd::uint32 value) -> void;
      
      /// @brief Writes a eight-byte unsigned integer to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Common%20I%3AO%20tasks).
      virtual auto write(xtd::uint64 value) -> void;
      
      /// @cond
      virtual auto write(xtd::slong value) -> void;
      virtual auto write(xtd::ulong value) -> void;
      /// @endcond
      
      /// @}
      
      /// @cond
      auto operator <<(bool value) -> binary_writer& {write(value); return *this;}
      auto operator <<(byte value) -> binary_writer& {write(value); return *this;}
      auto operator <<(char value) -> binary_writer& {write(value); return *this;}
      template<xtd::size size>
      auto operator <<(const xtd::fixed_array<xtd::byte, size>& value) -> binary_writer& {write(value); return *this;}
      template<xtd::size size>
      auto operator <<(const xtd::fixed_array<char, size>& value) -> binary_writer& {write(value); return *this;}
      auto operator <<(const xtd::array<xtd::byte>& value) -> binary_writer& {write(value, 0, value.length()); return *this;}
      auto operator <<(const xtd::array<char>& value) -> binary_writer& {write(value, 0, value.length()); return *this;}
      auto operator <<(double value) -> binary_writer& {write(value); return *this;}
      auto operator <<(int16 value) -> binary_writer& {write(value); return *this;}
      auto operator <<(int32 value) -> binary_writer& {write(value); return *this;}
      auto operator <<(int64 value) -> binary_writer& {write(value); return *this;}
      auto operator <<(sbyte value) -> binary_writer& {write(value); return *this;}
      auto operator <<(float value) -> binary_writer& {write(value); return *this;}
      auto operator <<(const string& value) -> binary_writer& {write(value); return *this;}
      auto operator <<(const char* value) -> binary_writer& {write(value); return *this;}
      auto operator <<(const char8* value) -> binary_writer& {write(value); return *this;}
      auto operator <<(const char16* value) -> binary_writer& {write(value); return *this;}
      auto operator <<(const char32* value) -> binary_writer& {write(value); return *this;}
      auto operator <<(const wchar* value) -> binary_writer& {write(value); return *this;}
      auto operator <<(uint16 value) -> binary_writer& {write(value); return *this;}
      auto operator <<(uint32 value) -> binary_writer& {write(value); return *this;}
      auto operator <<(uint64 value) -> binary_writer& {write(value); return *this;}
      /// @endcond
      
    private:
      auto write_7bit_encoded_int(int32 value) -> void;
      std::ostream* stream_ = nullptr;
      bool delete_when_destroy_ = false;
    };
  }
}
