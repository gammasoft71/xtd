#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/unauthorized_access_exception.h"
#include "../../../include/xtd/io/io_exception.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/path.h"
#include "../../../include/xtd/io/binary_writer.h"

using namespace std;
using namespace xtd;
using namespace xtd::io;

binary_writer::binary_writer(const ustring& path) : stream_(new ofstream(path, ios::out|ios::binary|ios_base::trunc)), delete_when_destroy_(true) {
  if (path.index_of_any(path::get_invalid_path_chars()) != string::npos) throw argument_exception(csf_);
  if (path.empty() || path.trim(' ').empty()) throw argument_exception(csf_);
  if (!file::exists(path)) throw file_not_found_exception(csf_);
  if ((file::get_attributes(path) & file_attributes::read_only) == file_attributes::read_only) throw unauthorized_access_exception(csf_);
  if (!dynamic_cast<ofstream*>(stream_)->is_open() || !stream_->good()) throw io_exception(csf_);
}

binary_writer::binary_writer(ostream& stream) {
  if (!stream_->good()) throw io_exception(csf_);
  stream_->flush();
}

binary_writer::~binary_writer() {
  if (delete_when_destroy_ && stream_) {
    flush();
    if (stream_ && dynamic_cast<ofstream*>(stream_)) static_cast<ofstream*>(stream_)->close();
    delete stream_;
  }
}

optional<reference_wrapper<ostream>> binary_writer::base_stream() const {
  return stream_ ? optional<reference_wrapper<ostream>>(*stream_) : optional<reference_wrapper<ostream>>();
}

void binary_writer::close() {
  flush();
  if (stream_ && dynamic_cast<ofstream*>(stream_)) static_cast<ofstream*>(stream_)->close();
  if (delete_when_destroy_ && stream_) delete stream_;
  stream_ = nullptr;
}

void binary_writer::flush() {
  if (stream_) stream_->flush();
}

size_t binary_writer::seek(size_t offset, std::ios::seekdir origin) {
  if (!stream_) throw io_exception(csf_);
  stream_->seekp(offset, origin);
  return stream_->tellp();
}
