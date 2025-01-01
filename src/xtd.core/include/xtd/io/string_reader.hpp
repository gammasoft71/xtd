/// @file
/// @brief Contains xtd::io::string_reader class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "text_reader.hpp"
#include <sstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Implements a xtd::io::text_reader that reads from a string.
    /// ```cpp
    /// class core_export_ string_reader : public xtd::io::text_reader
    /// ```
    /// @par Inheritance
    /// xtd::io::text_reader → xtd::io::string_reader
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/string_reader>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ string_reader : public xtd::io::text_reader {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the stream_reader class for the specified file name.
      /// @param path The complete file path to be read.
      explicit string_reader(const xtd::string& input);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
      /// @return An integer representing the next character to be read, or EOF if no more characters are available or the stream does not support seeking.
      int32 peek() const override;
      
      /// @brief Reads the next character from the input stream and advances the character position by one character.
      /// @return The next character from the input stream, or EOF if no more characters are available.
      int32 read() override;
      /// @}
      
    private:
      mutable std::stringstream stream_;
    };
  }
}
