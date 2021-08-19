#include "../../../../include/xtd/net/sockets/send_packets_element.h"

using namespace std;
using namespace xtd;
using namespace xtd::net::sockets;

send_packets_element::~send_packets_element() {
  if (delete_file_stream_when_destroy_ && file_stream_) delete file_stream_;
}

vector<byte_t> send_packets_element::buffer() const noexcept {
  return buffer_;
}

size_t send_packets_element::count() const noexcept {
  return count_;
}

bool send_packets_element::end_of_packett() const noexcept {
  return end_of_packet_;
}

const ustring& send_packets_element::file_path() const noexcept {
  return file_path_;
}

optional<send_packets_element::ifstream_ref> send_packets_element::file_stream() const noexcept {
  return file_stream_ == nullptr ? optional<ifstream_ref>() : optional<ifstream_ref>(*file_stream_);
}

size_t send_packets_element::offset() const noexcept {
  return offset_;
}
