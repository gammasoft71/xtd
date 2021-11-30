/// @file
/// @brief Contains xtd::io::binary_reader class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <fstream>
#include <optional>
#include "../object.h"
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Reads primitive data types as binary values in a specific encoding.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class binary_reader : public object {
    public:
      /// @brief Initializes a new instance of the xtd::io::binary_reader class for the specified file name.
      /// @param path The complete file path to be read.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters as defined by xtd::io::path::invalid_path_chars.
      binary_reader(const xtd::ustring& path);
      /// @brief Initializes a new instance of the xtd::io::binary_reader class for the specified stream.
      /// @param stream The stream to be read.
      binary_reader(std::istream& stream);
      /// @cond
      ~binary_reader();
      /// @endcond

      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      std::optional<std::reference_wrapper<std::istream>> base_stream() const;
      
      /// @brief Gets a value that indicates whether the current stream position is at the end of the stream.
      /// @return true if the current stream position is at the end of the stream; otherwise false.
      bool end_of_stream() const;
      
      /// @brief Closes the xtd::io::binary_reader object and the underlying stream, and releases any system resources associated with the reader.
      void close();

      /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
      /// @return An integer representing the next character to be read, or EOF if no more characters are available or the stream does not support seeking.
      int32_t peek_char() const;
      
      virtual int32_t read();
      
      virtual size_t read(std::vector<byte_t>& buffer, size_t index, size_t count);
      
      virtual size_t read(std::vector<char>& buffer, size_t index, size_t count);

      virtual bool read_boolean();
      
      virtual byte_t read_byte();
      
      virtual std::vector<byte_t> read_bytes(size_t count);
      
      virtual char read_char();
      
      virtual std::vector<char> read_chars(size_t count);

      virtual double read_double();
      
      virtual int16_t read_int16();
      
      virtual int32_t read_int32();
      
      virtual int64_t read_int64();
      
      virtual sbyte_t read_sbyte();

      virtual float read_single();

      virtual uint16_t read_uint16();
      
      virtual uint32_t read_uint32();
      
      virtual uint64_t read_uint64();
      
    private:
      std::istream* stream_ = nullptr;
      bool delete_when_destroy_ = false;
    };
  }
}
