/// @file
/// @brief Contains xtd::io::binary_writer class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <fstream>
#include <optional>
#include <array>
#include <vector>
#include "../object.h"
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Writes primitive types in binary to a stream and supports writing strings.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class binary_writer : public object {
    public:
      /// @brief Initializes a new instance of the binary_writer class for the specified file name.
      /// @param path The complete file path to be read.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters -or- The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened
      binary_writer(const xtd::ustring& path);
      /// @brief Initializes a new instance of the binary_writer class for the specified stream.
      /// @param stream The stream to be read.
      binary_writer(std::ostream& stream);
      /// @cond
      ~binary_writer();
      /// @endcond
      
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      std::optional<std::reference_wrapper<std::ostream>> base_stream() const;
      
      /// @brief Closes the binary_writer object and the underlying stream, and releases any system resources associated with the reader.
      virtual void close();
      
      /// @brief Clears all buffers for the current writer and causes any buffered data to be written to the underlying device.
      /// @remarks This default method does nothing, but derived classes can virtual the method to provide the appropriate functionality
      virtual void flush();
      
      virtual size_t seek(size_t offset, std::ios::seekdir origin);

      virtual void write(bool value);
      
      virtual void write(byte_t value);
      
      virtual void write(char value);
      
      template<size_t size>
      void write(const std::array<byte_t, size>& buffer) {
        for (auto b : buffer)
          write(b);
      }
      
      template<size_t size>
      void write(const std::array<char, size>& buffer) {
        for (auto c : buffer)
          write(c);
      }

      virtual void write(const std::vector<byte_t>& value);
      
      virtual void write(const std::vector<byte_t>& buffer, size_t index, size_t count);
      
      virtual void write(const std::vector<char>& value);

      virtual void write(const std::vector<char>& buffer, size_t index, size_t count);      
      
      virtual void write(double value);

      virtual void write(int16_t value);
      
      virtual void write(int32_t value);
      
      virtual void write(int64_t value);
      
      virtual void write(sbyte_t value);
      
      virtual void write(float value);
      
      virtual void write(const ustring& value);
      /// @cond
      virtual void write(const std::string& value);
      virtual void write(const std::u8string& value);
      virtual void write(const std::u16string& value);
      virtual void write(const std::u32string& value);
      virtual void write(const std::wstring& value);
      virtual void write(const char* value);
      virtual void write(const char8_t* value);
      virtual void write(const char16_t* value);
      virtual void write(const char32_t* value);
      virtual void write(const wchar_t* value);
      /// @endcond

      virtual void write(uint16_t value);
      
      virtual void write(uint32_t value);
      
      virtual void write(uint64_t value);

    private:
      std::ostream* stream_ = nullptr;
      bool delete_when_destroy_ = false;
    };
  }
}
