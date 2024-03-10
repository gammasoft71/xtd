/// @file
/// @brief Contains xtd::io::binary_writer class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../optional.h"
#include "../object.h"
#include "../ustring.h"
#include <fstream>
#include <array>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Writes primitive types in binary to a stream and supports writing strings.
    /// @code
    /// class core_export_ binary_writer : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::io::binary_writer
    /// @par Header
    /// @code #include <xtd/io/binary_writer> @endcode
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
    class core_export_ binary_writer : public xtd::object {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the binary_writer class for the specified file name.
      /// @param path The complete file path to be read.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened
      explicit binary_writer(const xtd::ustring& path);
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
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      std::optional<std::reference_wrapper<std::ostream>> base_stream() const;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Closes the xtd::io::binary_writer object and the underlying stream, and releases any system resources associated with the reader.
      virtual void close();
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      virtual void flush();
      
      /// @brief Sets the position within the current stream.
      /// @param ofsset A byte offset relative to origin.
      /// @param origin A field of std::ios::seekdir indicating the reference point from which the new position is to be obtained.
      /// @return The position with the current stream.
      /// @exception xtd::io::io_exception The file pointer was moved to an invalid location.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual size_t seek(size_t offset, std::ios::seekdir origin);
      
      /// @brief Writes a one-byte boolean value to the current stream, with 0 representing false and 1 representing true.
      /// @param value The boolean value to write (0 or 1).
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(bool value);
      
      /// @brief Writes an unsigned byte to the current stream and advances the stream position by one byte.
      /// @param value The unsigned byte to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(xtd::byte value);
      
      /// @brief Writes a character to the current stream and advances the current position by one byte.
      /// @param value The character to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(char value);
      
      /// @brief Writes a byte array to the underlying stream.
      /// @param buffer A byte array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      template<size_t size>
      void write(const std::array<xtd::byte, size>& buffer) {
        for (auto b : buffer)
          write(b);
      }
      
      /// @brief Writes a character array to the underlying stream.
      /// @param buffer A character array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      template<size_t size>
      void write(const std::array<char, size>& buffer) {
        for (auto c : buffer)
          write(c);
      }
      
      /// @brief Writes a byte array to the underlying stream.
      /// @param buffer A byte array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(const std::vector<xtd::byte>& buffer);
      
      /// @brief Writes a region of a byte array to the current stream.
      /// @param buffer A byte array containing the data to write.
      /// @param index The index of the first byte to read from buffer and to write to the stream.
      /// @param count The number of bytes to read from buffer and to write to the stream.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(const std::vector<xtd::byte>& buffer, size_t index, size_t count);
      
      /// @brief Writes a character array to the underlying stream.
      /// @param buffer A character array containing the data to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(const std::vector<char>& buffer);
      
      /// @brief Writes a region of a character array to the current stream.
      /// @param buffer A character array containing the data to write.
      /// @param index The index of the first byte to read from buffer and to write to the stream.
      /// @param count The number of bytes to read from buffer and to write to the stream.
      /// @exception xtd::argument_exception The buffer length minus index is less than count.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(const std::vector<char>& buffer, size_t index, size_t count);
      
      /// @brief Writes an eight-byte floating-point value to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte floating-point value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(double value);
      
      /// @brief Writes a two-byte signed integer to the current stream and advances the stream position by two bytes.
      /// @param value The two-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(int16 value);
      
      /// @brief Writes a four-byte signed integer to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(int32 value);
      
      /// @brief Writes a eight-byte signed integer to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte signed integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(int64 value);
      
      /// @brief Writes an signed byte to the current stream and advances the stream position by one byte.
      /// @param value The signed byte to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(sbyte value);
      
      /// @brief Writes an four-byte floating-point value to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte floating-point value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(float value);
      
      /// @brief Writes a length-prefixed string to this stream, and advances the current position of the stream and the specific characters being written to the stream.
      /// @param value The value to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(const ustring& value);
      /// @cond
      virtual void write(const std::string& value);
#if defined(__cpp_lib_char8_t)
      virtual void write(const std::u8string& value);
#endif
      virtual void write(const std::u16string& value);
      virtual void write(const std::u32string& value);
      virtual void write(const std::wstring& value);
      virtual void write(const char* value);
#if defined(__cpp_lib_char8_t)
      virtual void write(const char8* value);
#endif
      virtual void write(const char16* value);
      virtual void write(const char32* value);
      virtual void write(const wchar* value);
      /// @endcond
      
      /// @brief Writes a two-byte unsigned integer to the current stream and advances the stream position by two bytes.
      /// @param value The two-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(uint16 value);
      
      /// @brief Writes a four-byte unsigned integer to the current stream and advances the stream position by four bytes.
      /// @param value The four-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(uint32 value);
      
      /// @brief Writes a eight-byte unsigned integer to the current stream and advances the stream position by eight bytes.
      /// @param value The eight-byte unsigned integer to write.
      /// @exception xtd::io::io_exception An I/O error occurs.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      virtual void write(uint64 value);
      /// @}
      
      /// @cond
      binary_writer& operator <<(bool value) {write(value); return *this;}
      binary_writer& operator <<(byte value) {write(value); return *this;}
      binary_writer& operator <<(char value) {write(value); return *this;}
      template<size_t size>
      binary_writer& operator <<(const std::array<xtd::byte, size>& value) {write(value); return *this;}
      template<size_t size>
      binary_writer& operator <<(const std::array<char, size>& value) {write(value); return *this;}
      binary_writer& operator <<(const std::vector<xtd::byte>& value) {write(value); return *this;}
      binary_writer& operator <<(const std::vector<char>& value) {write(value); return *this;}
      binary_writer& operator <<(double value) {write(value); return *this;}
      binary_writer& operator <<(int16 value) {write(value); return *this;}
      binary_writer& operator <<(int32 value) {write(value); return *this;}
      binary_writer& operator <<(int64 value) {write(value); return *this;}
      binary_writer& operator <<(sbyte value) {write(value); return *this;}
      binary_writer& operator <<(float value) {write(value); return *this;}
      binary_writer& operator <<(const ustring& value) {write(value); return *this;}
      binary_writer& operator <<(const std::string& value) {write(value); return *this;}
#if defined(__cpp_lib_char8_t)
      binary_writer& operator <<(const std::u8string& value) {write(value); return *this;}
#endif
      binary_writer& operator <<(const std::u16string& value) {write(value); return *this;}
      binary_writer& operator <<(const std::u32string& value) {write(value); return *this;}
      binary_writer& operator <<(const std::wstring& value) {write(value); return *this;}
      binary_writer& operator <<(const char* value) {write(value); return *this;}
#if defined(__cpp_lib_char8_t)
      binary_writer& operator <<(const char8* value) {write(value); return *this;}
#endif
      binary_writer& operator <<(const char16* value) {write(value); return *this;}
      binary_writer& operator <<(const char32* value) {write(value); return *this;}
      binary_writer& operator <<(const wchar* value) {write(value); return *this;}
      binary_writer& operator <<(uint16 value) {write(value); return *this;}
      binary_writer& operator <<(uint32 value) {write(value); return *this;}
      binary_writer& operator <<(uint64 value) {write(value); return *this;}
      /// @endcond
      
    private:
      std::ostream* stream_ = nullptr;
      bool delete_when_destroy_ = false;
    };
  }
}
