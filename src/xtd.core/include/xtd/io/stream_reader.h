/// @file
/// @brief Contains xtd::io::stream_reader class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <fstream>
#include <optional>
#include "text_reader.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Represents a reader that can read a sequential series of characters.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class stream_reader : public xtd::io::text_reader {
    public:
      /// @brief Initializes a new instance of the stream_reader class for the specified file name.
      /// @param path The complete file path to be read.
      stream_reader(const std::string& path) : stream_(new std::ifstream(path)), delete_when_destroy_(true) {}
      /// @brief Initializes a new instance of the stream_reader class for the specified stream.
      /// @param stream The stream to be read.
      stream_reader(std::istream& stream) : stream_(&stream) {}
      /// @cond
      ~stream_reader() {
        if (delete_when_destroy_ && stream_) delete stream_;
      }
      /// @endcond
      
      /// @brief Returns the underlying stream.
      /// @return The underlying stream.
      std::optional<std::reference_wrapper<std::istream>> base_stream() const {return stream_ ? std::optional<std::reference_wrapper<std::istream>>(*stream_) : std::optional<std::reference_wrapper<std::istream>>();}
      
      /// @brief Closes the stream_reader object and the underlying stream, and releases any system resources associated with the reader.
      void close() override {
        if (stream_ && dynamic_cast<std::ifstream*>(stream_)) static_cast<std::ifstream*>(stream_)->close();
        if (delete_when_destroy_ && stream_) delete stream_;
        stream_ = nullptr;
      }

      /// @brief Reads the next character without changing the state of the reader or the character source. Returns the next available character without actually reading it from the input stream.
      /// @return An integer representing the next character to be read, or EOF if no more characters are available or the stream does not support seeking.
      int32_t peek() const override {
        if (!stream_) return EOF;
        int value = stream_->peek();
        return value;
      }
      
      /// @brief Reads the next character from the input stream and advances the character position by one character.
      /// @return The next character from the input stream, or EOF if no more characters are available.
      int32_t read() override {
        if (!stream_) return EOF;
        int value = stream_->get();
        return value;
      }
      
    private:
      std::istream* stream_ = nullptr;
      bool delete_when_destroy_ = false;
    };
  }
}
