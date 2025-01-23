/// @file
/// @brief Contains xtd::io::stream class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "seek_origin.hpp"
#include "../threading/manual_reset_event.hpp"
#include "../array.hpp"
#include "../async_callback.hpp"
#include "../core_export.hpp"
#include "../iasync_result.hpp"
#include "../abstract_object.hpp"
#include "../string.hpp"
#include <cstdio>
#include <sstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class null_stream;
    /// @endcond

    /// @brief Provides a generic view of a sequence of bytes. This is an abstract class.
    /// ```cpp
    /// class core_export_ stream :  public xtd::abstract_object, public std::iostream;
    /// ```
    /// @par Inheritance
    /// xtd::object → abstract_object → xtd::io::text_writer
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/stream>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ stream :  public xtd::abstract_object, public std::iostream {
      class async_result_stream : public xtd::object, public xtd::iasync_result {
      public:
        explicit async_result_stream(std::any async_state) : async_state_(async_state) {}
        std::any async_state() const noexcept override {return async_state_;}
        xtd::threading::wait_handle& async_wait_handle() noexcept override {return async_event_;}
        bool completed_synchronously() const noexcept override {return false;}
        bool is_completed() const noexcept override {return is_completed_;};
        
        std::any async_state_;
        bool is_completed_ = false;
        xtd::threading::manual_reset_event async_event_;
        std::exception_ptr exception_;
      };

      class streambuf : public std::streambuf {
      public:
        explicit streambuf(stream& owner);
        
        int_type underflow() override;
        int_type overflow(int_type value) override;
        
      private:
        stream& owner_;
        xtd::byte value_ = 0;
        char_type* value_ptr_ = reinterpret_cast<char_type*>(&value_);
      };
      
    public:
      /// @name Public Aliases
      
      /// @{
      /// @}

      /// @name Public Fields
      
      /// @{
      /// @brief A Stream with no backing store.
      /// @remarks Use xtd::io::stream::null_stream to redirect output to a stream that will not consume any operating system resources. When the methods of xtd::io::stream that provide writing are invoked on xtd::io::stream::null_stream, the call simply returns, and no data is written. xtd::io::stream::null_stream also implements a xtd::io::stream::stream::read method that returns zero without reading data.
      static xtd::io::null_stream null_stream;
      
      /// @brief Represnets an eof value.
      /// @remarks Returns a value not equivalent to any valid value of stream type ([EOF](https://en.cppreference.com/w/cpp/header/cstdio) (-1)).
      inline static constexpr int32 eof = EOF;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief When overridden in a derived class, gets a value indicating whether the current stream supports reading.
      /// @return `true` if the stream supports reading; otherwise, `false`.
      virtual bool can_read() const noexcept = 0;

      /// @brief When overridden in a derived class, gets a value indicating whether the current stream supports seeking.
      /// @return `true` if the stream supports seeking; otherwise, `false`.
      virtual bool can_seek() const noexcept = 0;

      /// @brief Gets a value that determines whether the current stream can time out.
      /// @return A value that determines whether the current stream can time out.
      /// @remarks The xtd::io::stream::can_timeout property always returns false. Some stream implementations require different behavior, such as xtd::net::sockets::network_stream, which times out if network connectivity is interrupted or lost. If you are implementing a stream that must be able to time out, this property should be overridden to return true.
      virtual bool can_timeout() const noexcept;

      /// @brief Gets a value indicating whether the current stream supports writing.
      /// @return `true` if the stream supports writing; otherwise, `false`.
      virtual bool can_write() const noexcept = 0;

      /// @brief Indicates if the stream is closed
      /// @return true if the stream is closed, false otherwise
      virtual bool is_closed() const noexcept;

      /// @brief When overridden in a derived class, gets the length in bytes of the stream.
      /// @return The length of the stream in bytes.
      /// @exception xtd::not_supported_exception A class derived from xtd::io::stream does not support seeking and the length is unknown.
      virtual xtd::size length() const = 0;

      /// @brief When overridden in a derived class, gets the position within the current stream.
      /// @return The current position within the stream.
      /// @exception xtd::not_supported_exception The stream does not support seeking.
      /// @remarks The stream must support seeking to get or set the position. Use the xtd::io::stream::can_seek property to determine whether the stream supports seeking.
      /// @remarks Seeking to any location beyond the length of the stream is supported.
      virtual xtd::size position() const = 0;
      /// @brief When overridden in a derived class, sets the position within the current stream.
      /// @param value The current position within the stream.
      /// @exception xtd::not_supported_exception The stream does not support seeking.
      /// @remarks The stream must support seeking to get or set the position. Use the xtd::io::stream::can_seek property to determine whether the stream supports seeking.
      /// @remarks Seeking to any location beyond the length of the stream is supported.
      virtual void position(xtd::size value) = 0;
      
      /// @brief Gets a value, in milliseconds, that determines how long the stream will attempt to read before timing out.
      /// @return A value, in milliseconds, that determines how long the stream will attempt to read before timing out.
      /// @exception xtd::invalid_operation_exception The xtd::io::stream::read_timeout method always throws an xtd::invalid_operation_exception.
      /// @par Notes to Inheritors
      /// The xtd::io::stream::read_timeout property should be overridden to provide the appropriate behavior for the stream. If the stream does not support timing out, this property should raise an xtd::invalid_operation_exception.
      virtual int32 read_timeout() const;
      /// @brief Sets a value, in milliseconds, that determines how long the stream will attempt to read before timing out.
      /// @param value A value, in milliseconds, that determines how long the stream will attempt to read before timing out.
      /// @exception xtd::invalid_operation_exception The xtd::io::stream::read_timeout method always throws an xtd::invalid_operation_exception.
      /// @par Notes to Inheritors
      /// The xtd::io::stream::read_timeout property should be overridden to provide the appropriate behavior for the stream. If the stream does not support timing out, this property should raise an xtd::invalid_operation_exception.
      virtual void read_timeout(int32 value);

      /// @brief Gets a value, in milliseconds, that determines how long the stream will attempt to write before timing out.
      /// @return A value, in milliseconds, that determines how long the stream will attempt to write before timing out.
      /// @exception xtd::invalid_operation_exception The xtd::io::stream::write_timeout method always throws an xtd::invalid_operation_exception.
      /// @par Notes to Inheritors
      /// The xtd::io::stream::write_timeout property should be overridden to provide the appropriate behavior for the stream. If the stream does not support timing out, this property should raise an xtd::invalid_operation_exception.
      virtual int32 write_timeout() const;

      /// @brief Sets a value, in milliseconds, that determines how long the stream will attempt to write before timing out.
      /// @param value A value, in milliseconds, that determines how long the stream will attempt to write before timing out.
      /// @exception xtd::invalid_operation_exception The xtd::io::stream::write_timeout method always throws an xtd::invalid_operation_exception.
      /// @par Notes to Inheritors
      /// The xtd::io::stream::write_timeout property should be overridden to provide the appropriate behavior for the stream. If the stream does not support timing out, this property should raise an xtd::invalid_operation_exception.
      virtual void write_timeout(int32 value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Reads the bytes from the current memory stream and writes them to another stream.
      /// @param destination The stream to which the contents of the current memory stream will be copied.
      void copy_to(std::ostream& destination);
      
      /// @brief Reads the bytes from the current memory stream and writes them to another stream, using a specified buffer size.
      /// @param destination The stream to which the contents of the current memory stream will be copied.
      /// @param buffer_size The size of the buffer. This value must be greater than zero. The default size is 81920.
      void copy_to(std::ostream& destination, xtd::size buffer_size);
      
      using std::iostream::read;
      virtual xtd::size read(xtd::array<xtd::byte>& buffer);
      virtual xtd::size read(xtd::array<xtd::byte>& buffer, xtd::size offset, xtd::size count) = 0;

      virtual int32 read_byte();
      
      virtual void set_length(xtd::size value) = 0;
      
      using std::iostream::write;
      virtual void write(const xtd::array<xtd::byte>& buffer);
      virtual void write(const xtd::array<xtd::byte>& buffer, xtd::size offset, xtd::size count) = 0;

      virtual void write_byte(xtd::byte value);
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::io::stream class.
      /// @remarks xtd::io::stream is the abstract base class of all streams.
      /// @remarks Some of the more commonly used streams that inherit from xtd:io::stream are xtd:io::file_stream, and xtd:io::memory_stream.
      /// @remarks This constructor exposes the underlying stream, which xtd::io::stream::get_buffer returns.
      stream();
      /// @}
      
    private:
      streambuf streambuf_ {*this};
      bool closed_ = false;
    };
  }
}
