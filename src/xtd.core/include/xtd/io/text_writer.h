/// @file
/// @brief Contains xtd::io::text_writer class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
    class null_text_writer;
    class synchronized_text_writer;
    /// @endcond
    
    /// @brief Represents a writer that can write a sequential series of characters.
    /// @code
    /// class core_export_ text_writer : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::io::text_writer
    /// @par Header
    /// @code #include <xtd/io/text_writer> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ text_writer : public xtd::object {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Provides a text_writer with no backing store that can be written to, but not read from.
      /// @remarks Use null to redirect output to a stream that will not consume any operating system resources.
      /// @remarks When the text_writer::write methods are invoked on null, the call simply returns, and no data is actually written to any backing store.
      static null_text_writer& null() noexcept;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the line terminator string used by the current text_writer.
      const xtd::ustring& new_line() const noexcept;
      /// @brief Sets the line terminator string used by the current text_writer.
      void new_line(const xtd::ustring& new_line) noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Closes the xtd::io::text_reader and releases any system resources associated with the text_reader
      virtual void close();
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      virtual void flush();
      
      /// @brief Creates a thread-safe (synchronized) wrapper around the specified text_writer object.
      /// @param reader The TextReader object to synchronize.
      /// @return text_writer A thread-safe text_writer object.
      static synchronized_text_writer synchronised(text_writer& writer) noexcept;
      
      /// @brief Writes the specified string value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      virtual void write(const xtd::ustring& value);
      
      /// @brief Writes the specified bool value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(bool value);
      
      /// @brief Writes the specified double value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(double value);
      
      /// @brief Writes the specified float value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(float value);
      
      /// @brief Writes the specified sbyte value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(sbyte value);
      
      /// @brief Writes the specified int16 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(int16 value);
      
      /// @brief Writes the specified int32 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(int32 value);
      
      /// @brief Writes the specified int64 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(int64 value);
      
      /// @brief Writes the specified xtd::byte value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(xtd::byte value);
      
      /// @brief Writes the specified uint16 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(uint16 value);
      
      /// @brief Writes the specified uint32 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(uint32 value);
      
      /// @brief Writes the specified uint64 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write(uint64 value);
      
      /// @brief Writes the specified value_t value to the text stream.
      /// @tparam value_t The type of value to write.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      template<typename value_t>
      void write(value_t value) {write(xtd::ustring::format("{}", value));}
      
      /// @brief Writes the specified arguments with specified format to the text stream.
      /// @param format The arguments format to write.
      /// @param args The arguments to write with format
      /// @exception io::io_exception An I/O error occurs.
      template<typename ... args_t>
      void write(const xtd::ustring& fmt, args_t&& ... args) noexcept {write(xtd::ustring::format(fmt, std::forward<args_t>(args)...));}
      
      /// @brief Writes new line to the text stream.
      /// @exception io::io_exception An I/O error occurs.
      void write_line();
      
      /// @brief Writes the specified string value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(const xtd::ustring& value);
      
      /// @brief Writes the specified bool value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(bool value);
      
      /// @brief Writes the specified double value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(double value);
      
      /// @brief Writes the specified float value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(float value);
      
      /// @brief Writes the specified sbyte value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(sbyte value);
      
      /// @brief Writes the specified int16 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(int16 value);
      
      /// @brief Writes the specified int32 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(int32 value);
      
      /// @brief Writes the specified int64 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(int64 value);
      
      /// @brief Writes the specified xtd::byte value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(xtd::byte value);
      
      /// @brief Writes the specified uint16 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(uint16 value);
      
      /// @brief Writes the specified uint32 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(uint32 value);
      
      /// @brief Writes the specified uint64 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      void write_line(uint64 value);
      
      /// @brief Writes the specified value_t value and new line to the text stream.
      /// @tparam value_t The type of value to write.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      template<typename value_t>
      void write_line(value_t value) {write_line(xtd::ustring::format("{}", value));}
      
      /// @brief Writes the specified arguments with specified format to the text stream.
      /// @param format The arguments format to write.
      /// @param args The arguments to write with format.
      /// @exception io::io_exception An I/O error occurs.
      template<typename ... args_t>
      void write_line(const xtd::ustring& fmt, args_t&& ... args) noexcept {write_line(xtd::ustring::format(fmt, std::forward<args_t>(args)...));}
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::io::text_writer class.
      text_writer() = default;
      /// @}
      
    private:
      xtd::ustring new_line_ = "\n";
    };
    
    /// @brief Represents a null text writer.
    /// @code
    /// class core_export_ null_text_writer : public xtd::io::text_writer
    /// @endcode
    /// @par Inheritance
    /// xtd::io::text_writer → xtd::io::null_text_writer
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ null_text_writer : public xtd::io::text_writer {
    public:
      void write(const xtd::ustring&) override;
    };
    
    /// @brief Represents a synchronized text writer.
    /// @code
    /// class core_export_ synchronized_text_writer : public xtd::io::text_writer
    /// @endcode
    /// @par Inheritance
    /// xtd::io::text_writer → xtd::io::synchronized_text_writer
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ synchronized_text_writer : public xtd::io::text_writer {
    public:
      void write(const xtd::ustring& value) override ;
      
    private:
      friend class text_writer;
      explicit synchronized_text_writer(xtd::io::text_writer& writer);
      synchronized_text_writer() = delete;
      xtd::io::text_writer& writer_;
    };
  }
}
