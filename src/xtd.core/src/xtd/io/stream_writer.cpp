#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/stream_writer.h"
#include "../../../include/xtd/diagnostics/debug.h"

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::io;

stream_writer::stream_writer(const ustring& path) : stream_writer(path, false) {
}

stream_writer::stream_writer(ostream& stream) : stream_writer(stream, false) {
}

stream_writer::stream_writer(const ustring& path, bool append) : stream_(new ofstream(path, append ? ios::out|ios_base::app : ios::out|ios_base::trunc)), delete_when_destroy_(true) {
  if (path.index_of_any(path::get_invalid_path_chars()) != string::npos) throw argument_exception(csf_);
  if (!exists(string(path))) throw file_not_found_exception(csf_);
  if (!dynamic_cast<ofstream*>(stream_)->is_open() || !stream_->good()) throw io_exception(csf_);
}

stream_writer::stream_writer(ostream& stream, bool append) : stream_(&stream) {
  if (!stream_->good()) throw io_exception(csf_);
  if (append) stream_->seekp(0, ios_base::end);
  stream_->flush();
}

stream_writer::~stream_writer() {
  if (delete_when_destroy_ && stream_) {
    flush();
    if (stream_ && dynamic_cast<ofstream*>(stream_)) static_cast<ofstream*>(stream_)->close();
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

optional<reference_wrapper<ostream>> stream_writer::base_stream() const {
  return stream_ ? optional<reference_wrapper<ostream>>(*stream_) : optional<reference_wrapper<ostream>>();
}

void stream_writer::close() {
  flush();
  if (stream_ && dynamic_cast<ofstream*>(stream_)) static_cast<ofstream*>(stream_)->close();
  if (delete_when_destroy_ && stream_) delete stream_;
  stream_ = nullptr;
}

void stream_writer::flush() {
  if (stream_) stream_->flush();
}

void stream_writer::write(const ustring& value) {
  if (stream_) stream_->write(value.c_str(), value.length());
  if (auto_flush_) flush();
}
