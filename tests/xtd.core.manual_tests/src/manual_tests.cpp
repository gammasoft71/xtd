#include <filesystem>
#include <xtd/xtd.core>

using namespace xtd;

class xtd_core_manual_test {
public:
  static size_t multi_byte_to_wide_char(const char* multi_byte_str, uint32_t nb_wide_char, wchar_t* wide_char_ctr, const char* local_str) {
    size_t result = static_cast<size_t>(-1);
    bool ok = true;

    if (multi_byte_str) {
      if (local_str) ok = local_str[0] ? setlocale(LC_ALL, local_str) != nullptr : setlocale(LC_ALL, "C") != nullptr;
      if (ok) result = std::mbstowcs(wide_char_ctr, multi_byte_str, nb_wide_char);
      if (local_str) std::locale::global(std::locale());
    }
    
    return result;
  }
  
  size_t wide_char_to_multi_byte(const wchar_t* wide_char_ctr, uint32_t nb_multibyte_char, char* multi_byte_str, const char* local_str) {
    size_t result = static_cast<size_t> (-1);
    bool ok = true;
    
    if (wide_char_ctr) {
      if (local_str) ok = local_str[0] ? setlocale(LC_ALL, local_str) != nullptr : setlocale(LC_ALL, "C") != nullptr;
      if (ok) result = std::wcstombs(multi_byte_str, wide_char_ctr, nb_multibyte_char);
      if (local_str) std::locale::global(std::locale::global(std::locale(local_str)));
    }
    
    return result;
  }

  static void main() {
    console::write_line("Hello, World!");
    console::write_line("temp = {}", io::path::get_temp_path());
    console::write_line("temp = {}", std::filesystem::temp_directory_path().string());
  }
};

startup_(xtd_core_manual_test);
