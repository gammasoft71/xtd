#include "../../../include/xtd/io/file.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/file.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

ofstream file::append_text(const ustring& path) noexcept {
  try {
    return ofstream(path, ios::app);
  } catch(...) {
    return ofstream();
  }
}

bool file::copy(const ustring& src, const ustring& dest) {
  return copy(src, dest, true);
}

bool file::copy(const ustring& src, const ustring& dest, bool overwrite) {
  try {
    if (exists(dest) && overwrite == false) return false;
#if defined(__cpp_lib_filesystem)
    filesystem::copy(filesystem::path(string(src)), filesystem::path(string(dest)), filesystem::copy_options::overwrite_existing);
    return true;
#else
    ifstream file_src(src, ios::binary);
    ofstream file_dest(dest, ios::binary);
    file_dest << file_src.rdbuf();
    return true;
#endif
  }
  catch (...) {
    return false;
  }
}

ofstream file::create(const ustring& path) noexcept {
  try {
    return ofstream(path, ios::binary | ios::out);
  } catch(...) {
    return ofstream();
  }
}

ofstream file::create_text(const ustring& path) noexcept {
  try {
    return ofstream(path);
  } catch(...) {
    return ofstream();
  }
}

bool file::exists(const ustring& path) noexcept {
  try {
    return ifstream(string(path)).good();
  } catch(...) {
    return false;
  }
}

file_attributes file::get_attributes(const ustring& src) noexcept {
  return (file_attributes) native::file::get_attributes(src.c_str());
}

bool file::move(const ustring& src, const ustring& dest) noexcept {
  return move(string(src).c_str(), string(dest).c_str());
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
  return remove(string(path).c_str());
}

bool file::replace(const ustring& source_file_name, const ustring& destination_file_name, const ustring& destination_backup_file_name) noexcept {
  if (!exists(source_file_name) || !exists(destination_file_name)) return false;
  if (!copy(destination_file_name, destination_backup_file_name)) return false;
  if (!remove(destination_file_name)) return false;
  return move(source_file_name, destination_file_name);
}

ofstream file::write_text(const ustring& path) noexcept {
  try {
    return ofstream(path);
  } catch(...) {
    return ofstream();
  }
}
