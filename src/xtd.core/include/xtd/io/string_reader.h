/// @file
/// @brief Contains xtd::io::string_reader class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <sstream>
#include "text_reader.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Represents a reader that can read a sequential series of characters.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class string_reader : public xtd::io::text_reader {
    public:
      /// @brief Initializes a new instance of the stream_reader class for the specified file name.
      /// @param path The complete file path to be read.
      string_reader(const std::string& input) : stream_(input) {}
      
      /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
      /// @return An integer representing the next character to be read, or EOF if no more characters are available or the stream does not support seeking.
      int32_t peek() const override {return stream_.peek();}
      
      /// @brief Reads the next character from the input stream and advances the character position by one character.
      /// @return The next character from the input stream, or EOF if no more characters are available.
      int32_t read() override {return stream_.get();}
      
    private:
      mutable std::stringstream stream_;
    };
  }
}
