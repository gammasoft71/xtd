/// @file
/// @brief Contains xtd::io::text_writer class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <cstdio>
#include <istream>
#include <mutex>
#include <string>
#include "../core_export.h"
#include "../strings.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class null_text_writer;
    class synchronized_text_writer;
    /// @endcond

    /// @brief Represents a writer that can write a sequential series of characters.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ text_writer {
    public:
      /// @cond
      virtual ~text_writer() {}
      /// @endcond
      
      /// @brief Gets the line terminator string used by the current text_writer.
      const std::string& new_line() const {return new_line_;}
      /// @brief Sets the line terminator string used by the current text_writer.
      void new_line(const std::string& new_line) {new_line_ = new_line;}

      /// @brief Provides a text_writer with no backing store that can be written to, but not read from.
      /// @remarks Use null to redirect output to a stream that will not consume any operating system resources.
      /// @remarks When the text_writer::write methods are invoked on null, the call simply returns, and no data is actually written to any backing store.
      static null_text_writer& null();
      
      /// @brief Closes the xtd::io::text_reader and releases any system resources associated with the text_reader
      virtual void close() {}
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      virtual void flush() {}
      
      /// @brief Creates a thread-safe (synchronized) wrapper around the specified text_writer object.
      /// @param reader The TextReader object to synchronize.
      /// @return text_writer A thread-safe text_writer object.
      static synchronized_text_writer synchronised(text_writer& writer);

      /// @brief Writes the specified string value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      virtual void write(const std::string& value) {}
      
      /// @brief Writes the specified bool value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(bool value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified double value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(double value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified float value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(float value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified int8_t value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(int8_t value) {write(xtd::strings::format("{}", value));}

      /// @brief Writes the specified int16_t value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(int16_t value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified int32_t value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(int32_t value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified int64_t value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(int64_t value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified uint8_t value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(uint8_t value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified uint16_t value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(uint16_t value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified uint32_t value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(uint32_t value) {write(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified uint64_t value to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write(uint64_t value) {write(xtd::strings::format("{}", value));}

      /// @brief Writes the specified value_t value to the text stream.
      /// @tparam value_t The type of value to write.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      template<typename value_t>
      void write(value_t value) {write(xtd::strings::format("{}", value));}

      /// @brief Writes the specified arguments with specified format to the text stream.
      /// @param format The arguments format to write.
      /// @param args The arguments to write witth format
      /// @exception io::ioexception An I/O error occurs.
      template<typename ... args_t>
      void write(const std::string& fmt, args_t&& ... args) noexcept {write(xtd::strings::format(fmt, std::forward<args_t>(args)...));}
      
      /// @brief Writes new line to the text stream.
      /// @exception io::ioexception An I/O error occurs.
      void write_line() {write(new_line_);}
      
      /// @brief Writes the specified string value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(const std::string& value) {
        write(value);
        write_line();
      }
      
      /// @brief Writes the specified bool value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(bool value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified double value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(double value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified float value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(float value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified int8_t value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(int8_t value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified int16_t value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(int16_t value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified int32_t value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(int32_t value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified int64_t value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(int64_t value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified uint8_t value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(uint8_t value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified uint16_t value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(uint16_t value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified uint32_t value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(uint32_t value) {write_line(xtd::strings::format("{}", value));}
      
      /// @brief Writes the specified uint64_t value and new line to the text stream.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      void write_line(uint64_t value) {write_line(xtd::strings::format("{}", value));}

      /// @brief Writes the specified value_t value and new line to the text stream.
      /// @tparam value_t The type of value to write.
      /// @param value The value to write.
      /// @exception io::ioexception An I/O error occurs.
      template<typename value_t>
      void write_line(value_t value) {write_line(xtd::strings::format("{}", value));}

      /// @brief Writes the specified arguments with specified format to the text stream.
      /// @param format The arguments format to write.
      /// @param args The arguments to write witth format.
      /// @exception io::ioexception An I/O error occurs.
      template<typename ... args_t>
      void write_line(const std::string& fmt, args_t&& ... args) noexcept {write_line(xtd::strings::format(fmt, std::forward<args_t>(args)...));}

    protected:
      /// @brief Initializes a new instance of the xtd::io::text_writer class.
      text_writer() = default;
      std::string new_line_ = "\n";
    };
    
    class null_text_writer : public text_writer {
    public:
      void write(const std::string&) override {}
    };
    
    class synchronized_text_writer : public text_writer {
    public:
      void write(const std::string& value) override {
        std::lock_guard<std::mutex> lock(mutex_);
        writer_.write(value);
      }
      
    private:
      friend class text_writer;
      explicit synchronized_text_writer(xtd::io::text_writer& writer) : writer_(writer) {}
      synchronized_text_writer() = delete;
      xtd::io::text_writer& writer_;
      std::mutex mutex_;
    };
  }
}
