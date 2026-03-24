/// @file
/// @brief Contains xtd::io::text_writer class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.hpp"
#include "../object.hpp"
#include "../string.hpp"
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
    /// ```cpp
    /// class core_export_ text_writer : public xtd::object
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
    class core_export_ text_writer : public xtd::object {
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Provides a text_writer with no backing store that can be written to, but not read from.
      /// @remarks Use null to redirect output to a stream that will not consume any operating system resources.
      /// @remarks When the text_writer::write methods are invoked on null, the call simply returns, and no data is actually written to any backing store.
      [[nodiscard]] static auto null() noexcept -> null_text_writer&;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the line terminator string used by the current text_writer.
      [[nodiscard]] auto new_line() const noexcept -> const xtd::string&;
      /// @brief Sets the line terminator string used by the current text_writer.
      auto new_line(const xtd::string& new_line) noexcept -> void;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Closes the xtd::io::text_reader and releases any system resources associated with the text_reader
      virtual auto close() -> void;
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      virtual auto flush() -> void;
      
      /// @brief Writes the specified string value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      virtual auto write(const xtd::string& value) -> void;
      
      /// @brief Writes the specified bool value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(bool value) -> void;
      
      /// @brief Writes the specified double value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(double value) -> void;
      
      /// @brief Writes the specified float value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(float value) -> void;
      
      /// @brief Writes the specified sbyte value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(sbyte value) -> void;
      
      /// @brief Writes the specified int16 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(int16 value) -> void;
      
      /// @brief Writes the specified int32 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(int32 value) -> void;
      
      /// @brief Writes the specified int64 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(int64 value) -> void;
      
      /// @brief Writes the specified xtd::byte value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(xtd::byte value) -> void;
      
      /// @brief Writes the specified uint16 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(uint16 value) -> void;
      
      /// @brief Writes the specified uint32 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(uint32 value) -> void;
      
      /// @brief Writes the specified uint64 value to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write(uint64 value) -> void;
      
      /// @brief Writes the specified value_t value to the text stream.
      /// @tparam value_t The type of value to write.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      template<typename value_t>
      auto write(value_t value) -> void {write(xtd::string::format("{}", value));}
      
      /// @brief Writes the specified arguments with specified format to the text stream.
      /// @param format The arguments format to write.
      /// @param args The arguments to write with format
      /// @exception io::io_exception An I/O error occurs.
      template<typename ...args_t>
      auto write(const xtd::string& fmt, args_t&& ... args) noexcept -> void {write(xtd::string::format(fmt, std::forward<args_t>(args)...));}
      
      /// @brief Writes new line to the text stream.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line() -> void;
      
      /// @brief Writes the specified string value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(const xtd::string& value) -> void;
      
      /// @brief Writes the specified bool value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(bool value) -> void;
      
      /// @brief Writes the specified double value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(double value) -> void;
      
      /// @brief Writes the specified float value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(float value) -> void;
      
      /// @brief Writes the specified sbyte value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(sbyte value) -> void;
      
      /// @brief Writes the specified int16 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(int16 value) -> void;
      
      /// @brief Writes the specified int32 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(int32 value) -> void;
      
      /// @brief Writes the specified int64 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(int64 value) -> void;
      
      /// @brief Writes the specified xtd::byte value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(xtd::byte value) -> void;
      
      /// @brief Writes the specified uint16 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(uint16 value) -> void;
      
      /// @brief Writes the specified uint32 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(uint32 value) -> void;
      
      /// @brief Writes the specified uint64 value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      auto write_line(uint64 value) -> void;
      
      /// @brief Writes the specified value_t value and new line to the text stream.
      /// @tparam value_t The type of value to write.
      /// @param value The value to write.
      /// @exception io::io_exception An I/O error occurs.
      template<typename value_t>
      auto write_line(value_t value) -> void {write_line(xtd::string::format("{}", value));}
      
      /// @brief Writes the specified arguments with specified format to the text stream.
      /// @param format The arguments format to write.
      /// @param args The arguments to write with format.
      /// @exception io::io_exception An I/O error occurs.
      template<typename ...args_t>
      auto write_line(const xtd::string& fmt, args_t&& ... args) noexcept -> void {write_line(xtd::string::format(fmt, std::forward<args_t>(args)...));}
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates a thread-safe (synchronized) wrapper around the specified text_writer object.
      /// @param reader The TextReader object to synchronize.
      /// @return text_writer A thread-safe text_writer object.
      [[nodiscard]] static auto synchronised(text_writer& writer) noexcept -> synchronized_text_writer;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::io::text_writer class.
      text_writer() = default;
      /// @}
      
    private:
      xtd::string new_line_ = "\n";
    };
    
    /// @brief Represents a null text writer.
    /// ```cpp
    /// class core_export_ null_text_writer : public xtd::io::text_writer
    /// ```
    /// @par Inheritance
    /// xtd::io::text_writer → xtd::io::null_text_writer
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ null_text_writer : public xtd::io::text_writer {
    public:
      auto write(const xtd::string&) -> void override;
    };
    
    /// @brief Represents a synchronized text writer.
    /// ```cpp
    /// class core_export_ synchronized_text_writer : public xtd::io::text_writer
    /// ```
    /// @par Inheritance
    /// xtd::io::text_writer → xtd::io::synchronized_text_writer
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ synchronized_text_writer : public xtd::io::text_writer {
    public:
      auto write(const xtd::string& value) -> void override ;
      
    private:
      friend class text_writer;
      explicit synchronized_text_writer(xtd::io::text_writer& writer);
      synchronized_text_writer() = delete;
      xtd::io::text_writer& writer_;
    };
  }
}
