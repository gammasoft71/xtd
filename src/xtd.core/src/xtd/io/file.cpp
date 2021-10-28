#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/diagnostics/stack_frame.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/path.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
#include <xtd/native/file_system.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

ofstream file::append_text(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (!exists(string(path))) throw file_not_found_exception(csf_);
  return ofstream(path, ios::out|ios::app);
}

void file::copy(const ustring& src, const ustring& dest) {
  return copy(src, dest, true);
}

void file::copy(const ustring& src, const ustring& dest, bool overwrite) {
  if (src.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (dest.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (!exists(string(src))) throw file_not_found_exception(csf_);
  if (exists(dest) && overwrite == false) throw argument_exception(csf_);
  ifstream file_src(src, ios::binary);
  ofstream file_dest(dest, ios::binary);
  file_dest << file_src.rdbuf();
}

ofstream file::create(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  return ofstream(path, ios::binary | ios::out);
}

ofstream file::create_text(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  return ofstream(path);
}

bool file::exists(const ustring& path) noexcept {
  try {
    int32_t attributes = 0;
    return native::file_system::get_attributes(path, attributes) == 0 && (static_cast<file_attributes>(attributes) & file_attributes::directory) != file_attributes::directory;
  } catch(...) {
    return false;
  }
}

file_attributes file::get_attributes(const ustring& src) {
  int32_t attributes = 0;
  if (native::file_system::get_attributes(src, attributes) != 0) throw file_not_found_exception(csf_);
  return static_cast<file_attributes>(attributes);
}

void file::move(const ustring& src, const ustring& dest) {
  if (exists(dest)) throw argument_exception(csf_);
  if (::rename(src.c_str(), dest.c_str()) != 0) throw io_exception(csf_);
}

fstream file::open(const ustring& path, ios::openmode mode) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if ((mode & ios::in) == ios::in && !exists(string(path))) throw file_not_found_exception(csf_);
  return fstream(path, mode);
}

ifstream file::open_read(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (!exists(string(path))) throw file_not_found_exception(csf_);
  return ifstream(path, ios::binary | ios::in);
}

ifstream file::open_text(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (!exists(string(path))) throw file_not_found_exception(csf_);
  return ifstream(path);
}

ofstream file::open_write(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  return ofstream(path, ios::binary | ios::out);
}

vector<uint8_t> file::read_all_bytes(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  if (!exists(string(path))) throw file_not_found_exception(csf_);
  ifstream file(path, ios::binary);
  return vector<uint8_t> {istreambuf_iterator<char>(file), istreambuf_iterator<char>()};
}

vector<ustring> file::read_all_lines(const ustring& path) {
  vector<ustring> contents;
  stream_reader sr(path);
  while (!sr.end_of_stream())
    contents.push_back(sr.read_line());
  return contents;
}

ustring file::read_all_text(const ustring& path) {
  vector<ustring> contents;
  stream_reader sr(path);
  return sr.read_to_end();
}

void file::remove(const ustring& path) {
  if (::remove(path.c_str()) != 0) throw io_exception(csf_);
}

void file::replace(const ustring& source_file_name, const ustring& destination_file_name, const ustring& destination_backup_file_name) {
  if (!exists(source_file_name) || !exists(destination_file_name)) throw file_not_found_exception(csf_);
  copy(destination_file_name, destination_backup_file_name);
  remove(destination_file_name);
  move(source_file_name, destination_file_name);
}

ofstream file::write_text(const ustring& path) {
  if (path.index_of_any(xtd::io::path::get_invalid_path_chars()) != ustring::npos) throw argument_exception(csf_);
  return ofstream(path);
}
