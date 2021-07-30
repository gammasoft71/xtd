#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/stream_writer.h"

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::io;

stream_writer::stream_writer(const string& path) : stream_(new ofstream(path)), delete_when_destroy_(true) {
  if (ustring(path).index_of_any(path::get_invalid_path_chars()) != string::npos) throw argument_exception(csf_);
  if (!exists(path)) throw file_not_found_exception(csf_);
}

stream_writer::stream_writer(ostream& stream) : stream_(&stream) {
}

stream_writer::~stream_writer() {
  if (delete_when_destroy_ && stream_) delete stream_;
}

optional<reference_wrapper<ostream>> stream_writer::base_stream() const {
  return stream_ ? optional<reference_wrapper<ostream>>(*stream_) : optional<reference_wrapper<ostream>>();
}

void stream_writer::close() {
  if (stream_ && dynamic_cast<ofstream*>(stream_)) static_cast<ofstream*>(stream_)->close();
  if (delete_when_destroy_ && stream_) delete stream_;
  stream_ = nullptr;
}

void stream_writer::flush() {
  if (stream_) stream_->flush();
}

void stream_writer::write(const std::string& value) {
  if (stream_) stream_->write(value.c_str(), value.length());
}
