#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/io/file_not_found_exception.hpp"
#include "../../../include/xtd/io/file.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/io/stream_reader.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::io;

stream_reader::stream_reader(const string& path) : stream_(new std::ifstream(path)), delete_when_destroy_(true) {
  if (path.trim(' ').length() == 0 || path.index_of_any(io::path::get_invalid_path_chars()) != string::npos) throw_helper::throws(exception_case::argument);
  if (!file::exists(path)) throw_helper::throws(exception_case::file_not_found);
}

stream_reader::stream_reader(std::istream& stream) : stream_(&stream) {
}

stream_reader::~stream_reader() {
  if (delete_when_destroy_ && stream_) {
    if (dynamic_cast<std::ifstream*>(stream_)) static_cast<std::ifstream*>(stream_)->close();
    delete stream_;
  }
}

auto stream_reader::base_stream() const -> std::optional<ref<std::istream>> {
  return stream_ ? std::optional<ref<std::istream>>(*stream_) : std::nullopt;
}

auto stream_reader::end_of_stream() const -> bool {
  return peek() == EOF;
}

auto stream_reader::close() -> void {
  if (stream_ && dynamic_cast<std::ifstream*>(stream_)) static_cast<std::ifstream*>(stream_)->close();
  if (delete_when_destroy_) delete stream_;
  stream_ = nullptr;
}

auto stream_reader::peek() const -> int32 {
  if (!stream_) return EOF;
  int32 value = stream_->peek();
  return value;
}

auto stream_reader::read() -> int32 {
  if (!stream_) return EOF;
  int32 value = stream_->get();
  return value;
}
