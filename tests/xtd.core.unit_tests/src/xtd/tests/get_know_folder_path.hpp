#pragma once
#include <cstdint>
#include <string>

#if defined(_WIN32)
#define NOMINMAX
#define UNICODE
#include <shlobj.h>
#include <Windows.h>
#undef interface
#include <xtd/convert_string>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

constexpr xtd::int32 __CSIDL_HOME__ = 0x0040;

inline xtd::string __get_environment_variable__(const xtd::string& variable) {
  DWORD environent_variable_size = 65535;
  std::wstring environment_variable(environent_variable_size, 0);
  environent_variable_size = GetEnvironmentVariable(xtd::convert_string::to_wstring(variable).data(), environment_variable.data(), environent_variable_size);
  if (!environent_variable_size) return "";
  return environment_variable.data();
}

inline xtd::string __get_know_folder_path__(xtd::int32 id) {
  if (id == __CSIDL_HOME__)
    return __get_environment_variable__("HOMEPATH");
  DWORD path_size = 65535;
  std::wstring path(path_size, 0);
  return SHGetFolderPath(nullptr, id, nullptr, SHGFP_TYPE_CURRENT, path.data()) == xtd::h_result::S_OK ? path.data() : L"";
}
#else
#include <xtd/string>

inline xtd::string __get_know_folder_path__(xtd::int32 id) {
  return "";
}
#endif
