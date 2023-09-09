#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/stream_reader.h"

using namespace std;
using namespace xtd;
using namespace xtd::io;

stream_reader::stream_reader(const ustring& path) : stream_(new ifstream(path)), delete_when_destroy_(true) {
  if (path.trim(' ').length() == 0 || path.index_of_any(io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception {csf_};
  if (!file::exists(path)) throw file_not_found_exception {csf_};
}

stream_reader::stream_reader(istream& stream) : stream_(&stream) {
}

stream_reader::~stream_reader() {
  if (delete_when_destroy_ && stream_) {
    if (dynamic_cast<ifstream*>(stream_)) static_cast<ifstream*>(stream_)->close();
    delete stream_;
  }
}

optional<reference_wrapper<istream>> stream_reader::base_stream() const {
  return stream_ ? optional<reference_wrapper<istream>>(*stream_) : optional<reference_wrapper<istream>>();
}

bool stream_reader::end_of_stream() const {
  return peek() == EOF;
}

void stream_reader::close() {
  if (stream_ && dynamic_cast<ifstream*>(stream_)) static_cast<ifstream*>(stream_)->close();
  if (delete_when_destroy_) delete stream_;
  stream_ = nullptr;
}

int32 stream_reader::peek() const {
  if (!stream_) return EOF;
  int32 value = stream_->peek();
  return value;
}

int32 stream_reader::read() {
  if (!stream_) return EOF;
  int32 value = stream_->get();
  return value;
}
