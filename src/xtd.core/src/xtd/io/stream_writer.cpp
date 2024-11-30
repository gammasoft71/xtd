#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/unauthorized_access_exception.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/file_not_found_exception.hpp"
#include "../../../include/xtd/io/file.hpp"
#include "../../../include/xtd/io/path.hpp"
#include "../../../include/xtd/io/stream_writer.hpp"
#include "../../../include/xtd/diagnostics/debug.hpp"

using namespace xtd;
using namespace xtd::io;

stream_writer::stream_writer(const string& path) : stream_writer(path, false) {
}

stream_writer::stream_writer(std::ostream& stream) : stream_writer(stream, false) {
}

stream_writer::stream_writer(const string& path, bool append) : stream_(new std::ofstream(path, append ? std::ios::out | std::ios_base::app : std::ios::out | std::ios_base::trunc)), delete_when_destroy_(true) {
  if (path.index_of_any(path::get_invalid_path_chars()) != string::npos) throw argument_exception {};
  if (path.empty() || path.trim(' ').empty()) throw argument_exception {};
  if (!file::exists(path)) throw file_not_found_exception {};
  if ((file::get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw unauthorized_access_exception {};
  if (!dynamic_cast<std::ofstream*>(stream_)->is_open() || !stream_->good()) throw io_exception {};
}

stream_writer::stream_writer(std::ostream& stream, bool append) : stream_(&stream) {
  if (!stream_->good()) throw io_exception {};
  if (append) stream_->seekp(0, std::ios_base::end);
  stream_->flush();
}

stream_writer::~stream_writer() {
  if (delete_when_destroy_ && stream_) {
    flush();
    if (dynamic_cast<std::ofstream*>(stream_)) static_cast<std::ofstream*>(stream_)->close();
    delete stream_;
  }
}

bool stream_writer::auto_flush() const {
  return auto_flush_;
}

void stream_writer::auto_flush(bool auto_flush) {
  auto_flush_ = auto_flush;
  if (auto_flush_) flush();
}

std::optional<std::reference_wrapper<std::ostream>> stream_writer::base_stream() const {
  return stream_ ? std::optional<std::reference_wrapper<std::ostream>>(*stream_) : std::optional<std::reference_wrapper<std::ostream>>();
}

void stream_writer::close() {
  flush();
  if (stream_ && dynamic_cast<std::ofstream*>(stream_)) static_cast<std::ofstream*>(stream_)->close();
  if (delete_when_destroy_) delete stream_;
  stream_ = nullptr;
}

void stream_writer::flush() {
  if (stream_) stream_->flush();
}

void stream_writer::write(const string& value) {
  if (stream_) stream_->write(value.c_str(), value.length());
  if (auto_flush_) flush();
}
