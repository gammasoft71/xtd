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

#if defined(__cpp_lib_filesystem)
ofstream file::append_text(const filesystem::path& path) noexcept {
  try {
    return ofstream(path, ios::app);
  } catch(...) {
    return ofstream();
  }
}
#endif

bool file::copy(const ustring& src, const ustring& dest) {
  return copy(src, dest, true);
}

#if defined(__cpp_lib_filesystem)
bool file::copy(const filesystem::path& src, const filesystem::path& dest) {
  return copy(src, dest, true);
}
#endif

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

#if defined(__cpp_lib_filesystem)
bool file::copy(const filesystem::path& src, const filesystem::path& dest, bool overwrite) {
  try {
    if (filesystem::exists(dest) && overwrite == false) return false;
    ifstream file_src(src, ios::binary);
    ofstream file_dest(dest, ios::binary);
    file_dest << file_src.rdbuf();
    return true;
  } catch(...) {
    return false;
  }
}
#endif

ofstream file::create(const ustring& path) noexcept {
  try {
    return ofstream(path, ios::binary | ios::out);
  } catch(...) {
    return ofstream();
  }
}

#if defined(__cpp_lib_filesystem)
ofstream file::create(const filesystem::path& path) noexcept {
  try {
    return ofstream(path, ios::binary | ios::out);
  } catch(...) {
    return ofstream();
  }
}
#endif

ofstream file::create_text(const ustring& path) noexcept {
  try {
    return ofstream(path);
  } catch(...) {
    return ofstream();
  }
}

#if defined(__cpp_lib_filesystem)
ofstream file::create_text(const filesystem::path& path) noexcept {
  try {
    return ofstream(path);
  } catch(...) {
    return ofstream();
  }
}
#endif

bool file::exists(const ustring& path) noexcept {
  try {
    return ifstream(string(path)).good();
  } catch(...) {
    return false;
  }
}

#if defined(__cpp_lib_filesystem)
bool file::exists(const filesystem::path& path) noexcept {
  try {
    return ifstream(path).good();
  } catch(...) {
    return false;
  }
}
#endif

file_attributes file::get_attributes(const ustring& src) noexcept {
  return (file_attributes) native::file::get_attributes(src.c_str());
}

#if defined(__cpp_lib_filesystem)
file_attributes file::get_attributes(const filesystem::path& src) noexcept {
  return get_attributes(ustring(src.string()));
}
#endif

bool file::move(const ustring& src, const ustring& dest) noexcept {
  return move(string(src).c_str(), string(dest).c_str());
}

#if defined(__cpp_lib_filesystem)
bool file::move(const filesystem::path& src, const filesystem::path& dest) noexcept {
  return move(src.string().c_str(), dest.string().c_str());
}
#endif

fstream file::open(const ustring& path, ios::openmode mode) noexcept {
  try {
    return fstream(path, mode);
  } catch(...) {
    return fstream();
  }
}

#if defined(__cpp_lib_filesystem)
fstream file::open(const filesystem::path& path, ios::openmode mode) noexcept {
  try {
    return fstream(path, mode);
  } catch(...) {
    return fstream();
  }
}
#endif

ifstream file::open_read(const ustring& path) noexcept {
  try {
    return ifstream(path, ios::binary | ios::in);
  } catch(...) {
    return ifstream();
  }
}

#if defined(__cpp_lib_filesystem)
ifstream file::open_read(const filesystem::path& path) noexcept {
  try {
    return ifstream(path, ios::binary | ios::in);
  } catch(...) {
    return ifstream();
  }
}
#endif

ifstream file::open_text(const ustring& path) noexcept {
  try {
    return ifstream(path);
  } catch(...) {
    return ifstream();
  }
}

#if defined(__cpp_lib_filesystem)
ifstream file::open_text(const filesystem::path& path) noexcept {
  try {
    return ifstream(path);
  } catch(...) {
    return ifstream();
  }
}
#endif

ofstream file::open_write(const ustring& path) noexcept {
  try {
    return ofstream(path, ios::binary | ios::out);
  } catch(...) {
    return ofstream();
  }
}

#if defined(__cpp_lib_filesystem)
ofstream file::open_write(const filesystem::path& path) noexcept {
  try {
    return ofstream(path, ios::binary | ios::out);
  } catch(...) {
    return ofstream();
  }
}
#endif

vector<uint8_t> file::read_all_bytes(const ustring& path) noexcept {
  try {
    ifstream file(path, ios::binary);
    return vector<uint8_t> {istreambuf_iterator<char>(file), istreambuf_iterator<char>()};
  } catch(...) {
    return {};
  }
}

#if defined(__cpp_lib_filesystem)
vector<uint8_t> file::read_all_bytes(const filesystem::path& path) noexcept {
  try {
    ifstream file(path, ios::binary);
    return vector<uint8_t> {istreambuf_iterator<char>(file), istreambuf_iterator<char>()};
  } catch(...) {
    return {};
  }
}
#endif

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

#if defined(__cpp_lib_filesystem)
vector<ustring> file::read_all_lines(const filesystem::path& path) noexcept {
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
#endif

ustring file::read_all_text(const ustring& path) noexcept {
  try {
    ifstream file(path);
    return ustring(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
  } catch(...) {
    return {};
  }
}

#if defined(__cpp_lib_filesystem)
string file::read_all_text(const filesystem::path& path) noexcept {
  try {
    ifstream file(path);
    return string {istreambuf_iterator<char>(file), istreambuf_iterator<char>()};
  } catch(...) {
    return {};
  }
}
#endif

bool file::remove(const ustring& path) noexcept {
  return remove(string(path).c_str());
}

#if defined(__cpp_lib_filesystem)
bool file::remove(const filesystem::path& path) noexcept {
  return remove(ustring(path.string()));
}
#endif

bool file::replace(const ustring& source_file_name, const ustring& destination_file_name, const ustring& destination_backup_file_name) noexcept {
  if (!exists(source_file_name) || !exists(destination_file_name)) return false;
  if (!copy(destination_file_name, destination_backup_file_name)) return false;
  if (!remove(destination_file_name)) return false;
  return move(source_file_name, destination_file_name);
}

#if defined(__cpp_lib_filesystem)
bool file::replace(const filesystem::path& source_file_name, const filesystem::path destination_file_name, const filesystem::path& destination_backup_file_name) noexcept {
  if (!filesystem::exists(source_file_name) || !filesystem::exists(destination_file_name)) return false;
  if (!copy(destination_file_name, destination_backup_file_name)) return false;
  if (!remove(destination_file_name)) return false;
  return move(source_file_name, destination_file_name);
}
#endif

ofstream file::write_text(const ustring& path) noexcept {
  try {
    return ofstream(path);
  } catch(...) {
    return ofstream();
  }
}

#if defined(__cpp_lib_filesystem)
ofstream file::write_text(const filesystem::path& path) noexcept {
  try {
    return ofstream(path);
  } catch(...) {
    return ofstream();
  }
}
#endif
