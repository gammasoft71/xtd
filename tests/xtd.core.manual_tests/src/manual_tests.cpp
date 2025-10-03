#include <xtd/xtd>

auto main() -> int {  
  auto date_formats = array<std::tuple<string, string>> {
    {"2025-10-03T10:49:12.1234567Z", "O"},
    {"2025/10/03", "yyyy/MM/dd"},
    {"10:49:12", "HH:mm:ss"},
  };
  
  for (auto [date, format] : date_formats) {
    auto dt = date_time {};
    auto result = date_time::try_parse_exact(date, format, dt);
    if (result) println("'{}' -> {}", format, dt.to_string(format));
    else println("format '{}' invalid", format);
  }
}

// This code produces the following outputs :
//
// 'O' -> 2025-10-03T10:49:12.1234567Z
// 'yyyy/MM/dd' -> 2025/10/03
// 'HH:mm:ss' -> 10:49:12
