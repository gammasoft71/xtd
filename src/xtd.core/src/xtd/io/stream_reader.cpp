#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/stream_reader.h"

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::io;

stream_reader::stream_reader(const string& path) : stream_(new ifstream(path)), delete_when_destroy_(true) {
  if (strings::trim(path, ' ').length() == 0 || ustring(path).index_of_any(path::get_invalid_path_chars()) != string::npos) throw argument_exception(csf_);
  if (!exists(path)) throw file_not_found_exception(csf_);
}

stream_reader::stream_reader(istream& stream) : stream_(&stream) {
}

stream_reader::~stream_reader() {
  if (delete_when_destroy_ && stream_) delete stream_;
}

optional<reference_wrapper<istream>> stream_reader::base_stream() const {
  return stream_ ? optional<reference_wrapper<istream>>(*stream_) : optional<reference_wrapper<istream>>();
}

bool stream_reader::end_of_stream() const {
  return peek() == EOF;
}

void stream_reader::close() {
  if (stream_ && dynamic_cast<ifstream*>(stream_)) static_cast<ifstream*>(stream_)->close();
  if (delete_when_destroy_ && stream_) delete stream_;
  stream_ = nullptr;
}

int32_t stream_reader::peek() const {
  if (!stream_) return EOF;
  int value = stream_->peek();
  return value;
}

int32_t stream_reader::read() {
  if (!stream_) return EOF;
  int value = stream_->get();
  return value;
}
