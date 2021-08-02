#include "../../../include/xtd/argument_exception.h"
#include "../../../include/xtd/diagnostics/stack_frame.h"
#include "../../../include/xtd/io/file.h"
#include "../../../include/xtd/io/file_not_found_exception.h"
#include "../../../include/xtd/io/path.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
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
    return native::file::get_attributes(path) != -1;
  } catch(...) {
    return false;
  }
}

file_attributes file::get_attributes(const ustring& src) {
  if (!exists(string(src))) throw file_not_found_exception(csf_);
  return (file_attributes) native::file::get_attributes(src.c_str());
}

bool file::move(const ustring& src, const ustring& dest) noexcept {
  try {
    if (exists(dest)) return false;
    return ::rename(src.c_str(), dest.c_str()) == 0;
  } catch(...) {
    return false;
  }
}

fstream file::open(const ustring& path, ios::openmode mode) noexcept {
  try {
    return fstream(path, mode);
  } catch(...) {
    return fstream();
  }
}

ifstream file::open_read(const ustring& path) noexcept {
  try {
    return ifstream(path, ios::binary | ios::in);
  } catch(...) {
    return ifstream();
  }
}

ifstream file::open_text(const ustring& path) noexcept {
  try {
    return ifstream(path);
  } catch(...) {
    return ifstream();
  }
}

ofstream file::open_write(const ustring& path) noexcept {
  try {
    return ofstream(path, ios::binary | ios::out);
  } catch(...) {
    return ofstream();
  }
}

vector<uint8_t> file::read_all_bytes(const ustring& path) noexcept {
  try {
    ifstream file(path, ios::binary);
    return vector<uint8_t> {istreambuf_iterator<char>(file), istreambuf_iterator<char>()};
  } catch(...) {
    return {};
  }
}

vector<ustring> file::read_all_lines(const ustring& path) noexcept {
  try {
    vector<ustring> contents;
    ifstream file(path);
    string line;
    while(getline(file, line))
      contents.push_back(line);
    return contents;
  } catch(...) {
    return {};
  }
}

ustring file::read_all_text(const ustring& path) noexcept {
  try {
    ifstream file(path);
    return ustring(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
  } catch(...) {
    return {};
  }
}

bool file::remove(const ustring& path) noexcept {
  return ::remove(path.c_str()) == 0;
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
