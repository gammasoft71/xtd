#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;
using namespace std::literals;

enum class cap {title, middle, end};

template <typename type_t, typename period_t = std::ratio<1>>
auto print_duration(const string& text, const std::chrono::duration<type_t, period_t>& value, cap c) {
  if (c == cap::title)
    console::out
    << "┌────────────────────────────────────────────────────┬────────────┬────────────────────────────┐" << environment::new_line
    << "│  time_span                                         │   format   │      representation        │" << environment::new_line
    << "├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤" << environment::new_line;
  
  console::out <<  "│ " << text.pad_right(50) << " │ {}         │ " << string::format("{}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:c}       │ " << string::format("{:c}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:d}       │ " << string::format("{:d}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:D}       │ " << string::format("{:D}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:f}       │ " << string::format("{:f}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:F}       │ " << string::format("{:F}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:g}       │ " << string::format("{:g}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:G}       │ " << string::format("{:G}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:h}       │ " << string::format("{:h}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:H}       │ " << string::format("{:H}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:m}       │ " << string::format("{:m}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:M}       │ " << string::format("{:M}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:n}       │ " << string::format("{:n}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:N}       │ " << string::format("{:N}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:s}       │ " << string::format("{:s}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:S}       │ " << string::format("{:S}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:t}       │ " << string::format("{:t}", value).pad_right(26) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(50) << " │ {:T}       │ " << string::format("{:T}", value).pad_right(26) << " |" << environment::new_line;
  
  if (c != cap::end)
    console::out << "├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤" << environment::new_line;
  else
    console::out << "└────────────────────────────────────────────────────┴────────────┴────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  print_duration("std::chrono::nanoseconds {}", std::chrono::nanoseconds {}, cap::title);
  print_duration("6h + 3min + 8s", 6h + 3min + 8s, cap::middle);
  print_duration("52h + 3min + 32s", 52h + 3min + 2s, cap::middle);
  print_duration("24ms + 543ns", 24ms + 543ns, cap::middle);
  print_duration("52h + 3min + 2s + 24ms + 543ns", 52h + 3min + 2s + 24ms + 543ns, cap::middle);
  print_duration("std::chrono::nanoseconds {int64_object::min_value}", std::chrono::nanoseconds {int64_object::min_value}, cap::middle);
  print_duration("std::chrono::nanoseconds {int64_object::max_value}", std::chrono::nanoseconds {int64_object::max_value}, cap::end);
}

// This code produces the following output :
//
// ┌────────────────────────────────────────────────────┬────────────┬────────────────────────────┐
// │  time_span                                         │   format   │      representation        │
// ├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
// │ std::chrono::nanoseconds {}                        │ {}         │ 00:00:00                   |
// │ std::chrono::nanoseconds {}                        │ {:c}       │ 00:00:00                   |
// │ std::chrono::nanoseconds {}                        │ {:d}       │ 0                          |
// │ std::chrono::nanoseconds {}                        │ {:D}       │ 00                         |
// │ std::chrono::nanoseconds {}                        │ {:f}       │ 0.0:00:00:000000000        |
// │ std::chrono::nanoseconds {}                        │ {:F}       │ 0.00:00:00:000000000       |
// │ std::chrono::nanoseconds {}                        │ {:g}       │ 0:00:00                    |
// │ std::chrono::nanoseconds {}                        │ {:G}       │ 00:00:00                   |
// │ std::chrono::nanoseconds {}                        │ {:h}       │ 0                          |
// │ std::chrono::nanoseconds {}                        │ {:H}       │ 00                         |
// │ std::chrono::nanoseconds {}                        │ {:m}       │ 0                          |
// │ std::chrono::nanoseconds {}                        │ {:M}       │ 00                         |
// │ std::chrono::nanoseconds {}                        │ {:n}       │ 0                          |
// │ std::chrono::nanoseconds {}                        │ {:N}       │ 000000000                  |
// │ std::chrono::nanoseconds {}                        │ {:s}       │ 0                          |
// │ std::chrono::nanoseconds {}                        │ {:S}       │ 00                         |
// │ std::chrono::nanoseconds {}                        │ {:t}       │ 0                          |
// │ std::chrono::nanoseconds {}                        │ {:T}       │ 0000000                    |
// ├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
// │ 6h + 3min + 8s                                     │ {}         │ 06:03:08                   |
// │ 6h + 3min + 8s                                     │ {:c}       │ 06:03:08                   |
// │ 6h + 3min + 8s                                     │ {:d}       │ 0                          |
// │ 6h + 3min + 8s                                     │ {:D}       │ 00                         |
// │ 6h + 3min + 8s                                     │ {:f}       │ 0.6:03:08:000000000        |
// │ 6h + 3min + 8s                                     │ {:F}       │ 0.06:03:08:000000000       |
// │ 6h + 3min + 8s                                     │ {:g}       │ 6:03:08                    |
// │ 6h + 3min + 8s                                     │ {:G}       │ 06:03:08                   |
// │ 6h + 3min + 8s                                     │ {:h}       │ 6                          |
// │ 6h + 3min + 8s                                     │ {:H}       │ 06                         |
// │ 6h + 3min + 8s                                     │ {:m}       │ 3                          |
// │ 6h + 3min + 8s                                     │ {:M}       │ 03                         |
// │ 6h + 3min + 8s                                     │ {:n}       │ 0                          |
// │ 6h + 3min + 8s                                     │ {:N}       │ 000000000                  |
// │ 6h + 3min + 8s                                     │ {:s}       │ 8                          |
// │ 6h + 3min + 8s                                     │ {:S}       │ 08                         |
// │ 6h + 3min + 8s                                     │ {:t}       │ 0                          |
// │ 6h + 3min + 8s                                     │ {:T}       │ 0000000                    |
// ├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
// │ 52h + 3min + 32s                                   │ {}         │ 2.04:03:02                 |
// │ 52h + 3min + 32s                                   │ {:c}       │ 2.04:03:02                 |
// │ 52h + 3min + 32s                                   │ {:d}       │ 2                          |
// │ 52h + 3min + 32s                                   │ {:D}       │ 02                         |
// │ 52h + 3min + 32s                                   │ {:f}       │ 2.4:03:02:000000000        |
// │ 52h + 3min + 32s                                   │ {:F}       │ 2.04:03:02:000000000       |
// │ 52h + 3min + 32s                                   │ {:g}       │ 2.4:03:02                  |
// │ 52h + 3min + 32s                                   │ {:G}       │ 2.04:03:02                 |
// │ 52h + 3min + 32s                                   │ {:h}       │ 4                          |
// │ 52h + 3min + 32s                                   │ {:H}       │ 04                         |
// │ 52h + 3min + 32s                                   │ {:m}       │ 3                          |
// │ 52h + 3min + 32s                                   │ {:M}       │ 03                         |
// │ 52h + 3min + 32s                                   │ {:n}       │ 0                          |
// │ 52h + 3min + 32s                                   │ {:N}       │ 000000000                  |
// │ 52h + 3min + 32s                                   │ {:s}       │ 2                          |
// │ 52h + 3min + 32s                                   │ {:S}       │ 02                         |
// │ 52h + 3min + 32s                                   │ {:t}       │ 0                          |
// │ 52h + 3min + 32s                                   │ {:T}       │ 0000000                    |
// ├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
// │ 24ms + 543ns                                       │ {}         │ 00:00:00:024000543         |
// │ 24ms + 543ns                                       │ {:c}       │ 00:00:00:024000543         |
// │ 24ms + 543ns                                       │ {:d}       │ 0                          |
// │ 24ms + 543ns                                       │ {:D}       │ 00                         |
// │ 24ms + 543ns                                       │ {:f}       │ 0.0:00:00:024000543        |
// │ 24ms + 543ns                                       │ {:F}       │ 0.00:00:00:024000543       |
// │ 24ms + 543ns                                       │ {:g}       │ 0:00:00:024000543          |
// │ 24ms + 543ns                                       │ {:G}       │ 00:00:00:024000543         |
// │ 24ms + 543ns                                       │ {:h}       │ 0                          |
// │ 24ms + 543ns                                       │ {:H}       │ 00                         |
// │ 24ms + 543ns                                       │ {:m}       │ 0                          |
// │ 24ms + 543ns                                       │ {:M}       │ 00                         |
// │ 24ms + 543ns                                       │ {:n}       │ 24000543                   |
// │ 24ms + 543ns                                       │ {:N}       │ 024000543                  |
// │ 24ms + 543ns                                       │ {:s}       │ 0                          |
// │ 24ms + 543ns                                       │ {:S}       │ 00                         |
// │ 24ms + 543ns                                       │ {:t}       │ 240005                     |
// │ 24ms + 543ns                                       │ {:T}       │ 0240005                    |
// ├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {}         │ 2.04:03:02:024000543       |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:c}       │ 2.04:03:02:024000543       |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:d}       │ 2                          |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:D}       │ 02                         |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:f}       │ 2.4:03:02:024000543        |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:F}       │ 2.04:03:02:024000543       |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:g}       │ 2.4:03:02:024000543        |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:G}       │ 2.04:03:02:024000543       |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:h}       │ 4                          |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:H}       │ 04                         |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:m}       │ 3                          |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:M}       │ 03                         |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:n}       │ 24000543                   |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:N}       │ 024000543                  |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:s}       │ 2                          |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:S}       │ 02                         |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:t}       │ 240005                     |
// │ 52h + 3min + 2s + 24ms + 543ns                     │ {:T}       │ 0240005                    |
// ├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
// │ std::chrono::nanoseconds {int64_object::min_value} │ {}         │ -106751.23:47:16:854775808 |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:c}       │ -106751.23:47:16:854775808 |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:d}       │ 106751                     |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:D}       │ 106751                     |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:f}       │ -106751.23:47:16:854775808 |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:F}       │ -106751.23:47:16:854775808 |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:g}       │ -106751.23:47:16:854775808 |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:G}       │ -106751.23:47:16:854775808 |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:h}       │ 23                         |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:H}       │ 23                         |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:m}       │ 47                         |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:M}       │ 47                         |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:n}       │ 854775808                  |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:N}       │ 854775808                  |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:s}       │ 16                         |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:S}       │ 16                         |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:t}       │ 8547758                    |
// │ std::chrono::nanoseconds {int64_object::min_value} │ {:T}       │ 8547758                    |
// ├────────────────────────────────────────────────────┼────────────┼────────────────────────────┤
// │ std::chrono::nanoseconds {int64_object::max_value} │ {}         │ 106751.23:47:16:854775807  |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:c}       │ 106751.23:47:16:854775807  |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:d}       │ 106751                     |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:D}       │ 106751                     |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:f}       │ 106751.23:47:16:854775807  |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:F}       │ 106751.23:47:16:854775807  |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:g}       │ 106751.23:47:16:854775807  |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:G}       │ 106751.23:47:16:854775807  |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:h}       │ 23                         |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:H}       │ 23                         |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:m}       │ 47                         |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:M}       │ 47                         |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:n}       │ 854775807                  |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:N}       │ 854775807                  |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:s}       │ 16                         |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:S}       │ 16                         |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:t}       │ 8547758                    |
// │ std::chrono::nanoseconds {int64_object::max_value} │ {:T}       │ 8547758                    |
// └────────────────────────────────────────────────────┴────────────┴────────────────────────────┘
