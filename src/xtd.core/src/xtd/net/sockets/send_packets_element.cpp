#include "../../../../include/xtd/net/sockets/send_packets_element.hpp"

using namespace xtd;
using namespace xtd::net::sockets;

send_packets_element::send_packets_element(const xtd::array<xtd::byte>& buffer) : buffer_(buffer) {
}

send_packets_element::send_packets_element(const xtd::string& file_path, xtd::usize offset, xtd::usize count, bool end_of_packet) : count_(count), end_of_packet_(end_of_packet), file_path_(file_path), offset_(offset) {
}

send_packets_element::send_packets_element(const xtd::array<xtd::byte>& buffer, xtd::usize offset, xtd::usize count, bool end_of_packet) : buffer_(buffer), count_(count), end_of_packet_(end_of_packet), offset_(offset) {
}

send_packets_element::send_packets_element(const xtd::string& file_path, xtd::usize offset, xtd::usize count) : count_(count), file_path_(file_path), offset_(offset) {
}

send_packets_element::send_packets_element(std::ifstream& file_stream, xtd::usize offset, xtd::usize count, bool end_of_packet) : count_(count), end_of_packet_(end_of_packet), file_stream_(&file_stream), offset_(offset), delete_file_stream_when_destroy_(true) {
}

send_packets_element::send_packets_element(const xtd::array<xtd::byte>& buffer, xtd::usize offset, xtd::usize count) : buffer_(buffer), count_(count), offset_(offset) {
}

send_packets_element::send_packets_element(const xtd::string& file_path) : file_path_(file_path) {
}

send_packets_element::send_packets_element(std::ifstream& file_stream) : file_stream_(&file_stream), delete_file_stream_when_destroy_(true) {
}

send_packets_element::~send_packets_element() {
  if (delete_file_stream_when_destroy_) delete file_stream_;
}

xtd::array<xtd::byte> send_packets_element::buffer() const noexcept {
  return buffer_;
}

xtd::usize send_packets_element::count() const noexcept {
  return count_;
}

bool send_packets_element::end_of_packet() const noexcept {
  return end_of_packet_;
}

const string& send_packets_element::file_path() const noexcept {
  return file_path_;
}

std::optional<send_packets_element::ifstream_ref> send_packets_element::file_stream() const noexcept {
  return file_stream_ ? std::optional<ifstream_ref>(*file_stream_) : std::nullopt;
}

xtd::usize send_packets_element::offset() const noexcept {
  return offset_;
}
