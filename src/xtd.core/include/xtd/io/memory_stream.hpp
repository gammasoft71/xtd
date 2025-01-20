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
      using std::stringstream::read;
      void read(xtd::array<xtd::byte>& bytes);
      void read(xtd::array<xtd::byte>& bytes, size offset, size count);
      
      xtd::int32 read_byte();
      
      xtd::size seek(xtd::size offset, seek_origin loc);

      using std::stringstream::write;
      void write(const xtd::array<xtd::byte>& bytes);
      void write(const xtd::array<xtd::byte>& bytes, size offset, size count);
      void write_byte(xtd::byte value);
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @}

    private:
    };
  }
}
