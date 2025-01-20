/// @file
/// @brief Contains xtd::io::memory_stream class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "seek_origin.hpp"
#include "../core_export.hpp"
#include "../array.hpp"
#include "../object.hpp"
#include "../string.hpp"
#include <cstdio>
#include <sstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    /// @brief Creates a stream whose backing store is memory.
    /// ```cpp
    /// class core_export_ memory_stream : public xtd::object, public std::stringstream
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::io::text_writer
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/text_writer>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ memory_stream :  public xtd::object, public std::stringstream {
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the underlying memory buffer type.
      using memory_buffer = std::stringbuf;
      /// @}

      /// @name Public constructors
      
      /// @{
      /// @brief Initializes a new instance of the MemoryStream class with an expandable capacity initialized to zero.
      /// @remarks The xtd::io::memory_stream::can_read, xtd::io::memory_stream::can_seek, and xtd::io::memory_stream::can_write properties are all set to true.
      /// @remarks The capacity of the current stream automatically increases when you use the xtd::io::memory_stream::set_length method to set the length to a value larger than the capacity of the current stream.
      /// @remarks This constructor exposes the underlying stream, which xtd::io::memory_stream::get_buffer returns.
      memory_stream();
      /// @brief Initializes a new instance of the MemoryStream class with an expandable capacity initialized as specified.
      /// @param capacity The initial size of the internal array in bytes.
      /// @remarks The xtd::io::memory_stream::can_read, xtd::io::memory_stream::can_seek, and xtd::io::memory_stream::can_write properties are all set to true.
      /// @remarks The capacity of the current stream automatically increases when you use the xtd::io::memory_stream::set_length method to set the length to a value larger than the capacity of the current stream.
      /// @remarks This constructor exposes the underlying stream, which xtd::io::memory_stream::get_buffer returns.
      memory_stream(xtd::size capacity);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the current stream supports reading.
      /// @return `true` if the stream supports reading; otherwise, `false`.
      bool can_read() const noexcept;
      /// @brief Gets a value indicating whether the current stream supports seeking.
      /// @return `true` if the stream supports seeking; otherwise, `false`.
      bool can_seek() const noexcept;
      /// @brief Gets a value indicating whether the current stream supports writing.
      /// @return `true` if the stream supports writing; otherwise, `false`.
      bool can_write() const noexcept;

      /// @brief Gets the number of bytes allocated for this stream.
      /// @return The length of the usable portion of the buffer for the stream.
      /// @exception xtd::argument_out_of_range_exception A capacity is less than the current length of the stream.
      /// @remarks `capacity` is the buffer length for system-provided byte arrays. `capacity` cannot be set to a value less than the current length of the stream.
      xtd::size capacity() const noexcept;
      /// @brief Sets the number of bytes allocated for this stream.
      /// @param value The length of the usable portion of the buffer for the stream.
      /// @return This current instance.
      /// @exception xtd::argument_out_of_range_exception A capacity is less than the current length of the stream.
      /// @remarks `capacity` is the buffer length for system-provided byte arrays. `capacity` cannot be set to a value less than the current length of the stream.
      memory_stream& capacity(xtd::size value);

      /// @brief Gets the length of the stream in bytes.
      /// @return The length of the stream in bytes.
      xtd::size length() const noexcept;

      /// @brief Gets the current position within the stream.
      /// @return The current position within the stream.
      xtd::size position() const noexcept;
      /// @brief Sets the current position within the stream.
      /// @param value The current position within the stream.
      /// @return This current instance.
      memory_stream& position(xtd::size value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Reads the bytes from the current memory stream and writes them to another stream, using a specified buffer size.
      /// @param destination The stream to which the contents of the current memory stream will be copied.
      /// @param buffer_size The size of the buffer. This value must be greater than zero. The default size is 81920.
      void copy_to(std::ostream& destination, xtd::size buffer_size) const;

      /// @brief Returns the array of unsigned bytes from which this stream was created.
      /// @return The byte array from which this stream was created, or the underlying array if a byte array was not provided to the xtd::memory_stream::memory_stream constructor during construction of the current instance.
      /// @remarks Note that the buffer contains allocated bytes which might be unused. For example, if the string "test" is written into the xtd::memory_stream object, the length of the buffer returned from xtd::memory_stream::get_buffer is 256, not 4, with 252 bytes unused. To obtain only the data in the buffer, use the xtd::memory_stream::to_array method; however, xtd::memory_stream::to_array creates a copy of the data in memory.
      /// @remarks To create a xtd::memory_stream instance with a publicly visible buffer, use xtd::memory_stream::memory_stream, xtd::memory_stream::memory_stream (const array<byte>&, xtd::zize, xtd::size, bool, bool), or xtd::memory_stream::memory_stream (xtd::size). If the current stream is resizable, two calls to this method do not return the same array if the underlying byte array is resized between calls. For additional information, see xtd::memory_stream::capacity.
      const memory_buffer& get_buffer() const;

      using std::stringstream::read;
      /// @brief Reads a sequence of bytes from the current memory stream and advances the position within the memory stream by the number of bytes read.
      /// @param buffer A region of memory. When this method returns, the contents of this span are replaced by the bytes read from the current memory stream source.
      /// @return The total number of bytes read into the buffer. This can be less than the number of bytes allocated in the buffer if that many bytes are not currently available, or zero (0) if the end of the memory stream has been reached.
      xtd::size read(xtd::array<xtd::byte>& buffer);
      /// @brief Reads a block of bytes from the current stream and writes the data to a buffer.
      /// @param buffer When this method returns, contains the specified byte array with the values between `offset` and (`offset` + `count` - 1) replaced by the characters read from the current stream.
      /// @param offset The zero-based byte offset in buffer at which to begin storing data from the current stream.
      /// @param count The maximum number of bytes to read.
      /// @return The total number of bytes written into the buffer. This can be less than the number of bytes requested if that number of bytes are not currently available, or zero if the end of the stream is reached before any bytes are read.
      /// @remarks The `offset` parameter gives the offset of the first byte in `buffer` to which data from the current stream is written. The `count` parameter gives the maximum number of bytes to read from the current stream. The returned value is the actual number of bytes read, or zero if the end of the stream is reached.
      /// @remarks If the read operation is successful, the current position within the stream advances by the number of bytes read. If an exception occurs, the current position within the stream remains unchanged.
      /// @remarks The `read` method will return zero only if the end of the stream is reached. In all other cases, `read` always reads at least one byte from the stream before returning. By definition, if no data is available from the stream upon a call to `read`, the `read` method returns zero (the end of the stream is reached automatically). An implementation is free to return fewer bytes than requested even if the end of the stream has not been reached.
      /// @remarks Use xtd::io::binary_reader for reading primitive data types.
      xtd::size read(xtd::array<xtd::byte>& buffer, size offset, size count);
      
      /// @brief Reads a byte from the current stream.
      /// @return The byte cast to a xtd::int32, or -1 if the end of the stream has been reached.
      /// @remarks If the read operation is successful, the current position within the stream is advanced by one byte. If an exception occurs, the current position within the stream is unchanged.
      /// @par Examples
      /// This code example is part of a larger example provided for the xtd::io::memory_stream class.
      /// ```cpp
      /// // Read the remaining bytes, byte by byte.
      /// while(count < mem_stream.length()) {
      ///   byte_array[count++] = as<byte>(mem_stream.read_byte());
      /// }
      /// ```
      xtd::int32 read_byte();
      
      /// @brief Sets the position within the current stream to the specified value.
      /// @param offset The new position within the stream. This is relative to the loc parameter, and can be positive or negative.
      /// @param loc A value of type xtd::io::seek_origin, which acts as the seek reference point.
      /// @return The new position within the stream, calculated by combining the initial reference point and the offset.
      xtd::size seek(std::streamoff offset, seek_origin loc);

      /// @brief Sets the length of the current stream to the specified value.
      /// @param value The value at which to set the length.
      /// @remarks If the specified value is less than the current length of the stream, the stream is truncated. If after the truncation the current position within the stream is past the end of the stream, the xtd::io::memery_stream::read_byte method returns -1, the xtd::io::memery_stream::read method reads zero bytes into the provided byte array, and xtd::io::memery_stream::write and xtd::io::memery_stream::write_byte methods append specified bytes at the end of the stream, increasing its length. If the specified value is larger than the current capacity and the stream is resizable, the capacity is increased, and the current position within the stream is unchanged. If the length is increased, the contents of the stream between the old and the new length are initialized to zeros.
      void set_length(xtd::size value);

      /// @brief Writes the stream contents to a byte array, regardless of the Position property.
      /// @return A new byte array.
      /// @remarks This method omits unused bytes in xtd::io::memory_stream from the array. To get the entire buffer, use the xtd::io::memory_stream::get_buffer method.
      /// @remarks This method returns a copy of the contents of the xtd::io::memory_stream as a byte array. If the current instance was constructed on a provided byte array, a copy of the section of the array to which this instance has access is returned. See the xtd::io::memory_stream constructor for details.
      xtd::array<xtd::byte> to_array() const;
      
      using std::stringstream::write;
      /// @brief Writes the sequence of bytes contained in `source` into the current memory stream and advances the current position within this memory stream by the number of bytes written.
      /// @param bytes A region of memory. This method copies the contents of this region to the current memory stream.
      void write(const xtd::array<xtd::byte>& bytes);
      /// @brief Writes a block of bytes to the current stream using data read from a buffer.
      /// @param bytes The buffer to write data from.
      /// @param offset The zero-based byte offset in buffer at which to begin copying bytes to the current stream.
      /// @param count The maximum number of bytes to write.
      /// @par Examples
      /// This code example is part of a larger example provided for the xtd::io::memory_stream class.
      /// ```cpp
      /// // Write the first string to the stream.
      /// mem_stream.write(first_string, 0 , first_string.length());
      /// ```
      /// @remarks The `offset` parameter gives the offset of the first byte in `buffer` to write from, and the `count` parameter gives the number of bytes to write. If the write operation is successful, the current position within the stream is advanced by the number of bytes written. If an exception occurs, the current position within the stream is unchanged.
      /// @remarks Except for a `memory_stream` constructed with a byte[] parameter, write operations at the end of a `memory_stream` expand the `memory_stream`.
      void write(const xtd::array<xtd::byte>& bytes, size offset, size count);
      /// @brief Writes a byte to the current stream at the current position.
      /// @param value The byte to write.
      /// @par Examples
      /// This code example is part of a larger example provided for the MemoryStream class.
      /// ```cpp
      /// // Write the second string to the stream, byte by byte.
      /// count = 0;
      /// while(count < second_string.Length) {
      ///   memStream.write_byte(second_string[count++]);
      /// }
      /// ```
      /// @remarks Except for a `memory_stream` constructed with a byte[] parameter, write operations at the end of a `memory_stream` expand the `memory_stream`.
      void write_byte(xtd::byte value);
      
      /// @brief Writes the entire contents of this memory stream to another stream.
      /// @param stream The stream to write this memory stream to.
      /// @exception xtd::bject_closed_exception The current or target stream is closed.
      /// @remarks When the current stream is open, this method is equivalent to calling [std::ostream::write](https://en.cppreference.com/w/cpp/io/basic_ostream/write) on the underlying buffer of this stream.
      void write_to(std::ostream& stream) const;
      /// @}
    };
  }
}
