/// @file
/// @brief Contains xtd::io::memory_stream class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
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
      memory_stream() {}
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
      
      xtd::size capacity() const noexcept;
      memory_stream& capacity(xtd::size value);

      xtd::size length() const noexcept;
      
      xtd::size position() const noexcept;
      memory_stream& position(xtd::size value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      using std::stringstream::read;
      void read(xtd::array<xtd::byte>& bytes);
      void read(xtd::array<xtd::byte>& bytes, size offset, size count);
      
      xtd::int32 read_byte();

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
