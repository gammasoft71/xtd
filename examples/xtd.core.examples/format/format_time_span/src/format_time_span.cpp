#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

enum class cap {title, middle, end};

auto print_time_span(const string& text, const time_span& value, cap c) {
  if (c == cap::title)
    console::out << "┌──────────────────────────────────────────┬────────────┬──────────────────────────────────────────┐" << environment::new_line
    << "│  time_span                               │   format   │      representation                      │" << environment::new_line
    << "├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤" << environment::new_line;
  
  console::out <<  "│ " << text.pad_right(40) << " │ {}         │ " << string::format("{}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:c}       │ " << string::format("{:c}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:d}       │ " << string::format("{:d}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:D}       │ " << string::format("{:D}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:f}       │ " << string::format("{:f}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:F}       │ " << string::format("{:F}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:g}       │ " << string::format("{:g}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:G}       │ " << string::format("{:G}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:h}       │ " << string::format("{:h}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:H}       │ " << string::format("{:H}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:m}       │ " << string::format("{:m}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:M}       │ " << string::format("{:M}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:n}       │ " << string::format("{:n}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:N}       │ " << string::format("{:N}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:s}       │ " << string::format("{:s}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:S}       │ " << string::format("{:S}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:t}       │ " << string::format("{:t}", value).pad_right(40) << " |" << environment::new_line;
  console::out <<  "│ " << text.pad_right(40) << " │ {:T}       │ " << string::format("{:T}", value).pad_right(40) << " |" << environment::new_line;
  
  if (c != cap::end)
    console::out << "├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└──────────────────────────────────────────┴────────────┴──────────────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  print_time_span("{}", time_span {}, cap::title);
  print_time_span("6_h + 3_min + 8_s", 6_h + 3_min + 8_s, cap::middle);
  print_time_span("52_h + 3_min + 32_s", 52_h + 3_min + 2_s, cap::middle);
  print_time_span("24_ms + 543_ns", 24_ms + 543_ns, cap::middle);
  print_time_span("52_h + 3_min + 2_s + 24_ms + 543_ns", 52_h + 3_min + 2_s + 24_ms + 543_ns, cap::middle);
  print_time_span("time_span::min_value", time_span::min_value, cap::middle);
  print_time_span("time_span::max_value", time_span::max_value, cap::end);
}

// This code produces the following output :
//
// ┌──────────────────────────────────────────┬────────────┬──────────────────────────────────────────┐
// │  time_span                               │   format   │      representation                      │
// ├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ {}                                       │ {}         │ 00:00:00                                 |
// │ {}                                       │ {:c}       │ 00:00:00                                 |
// │ {}                                       │ {:d}       │ 0                                        |
// │ {}                                       │ {:D}       │ 00                                       |
// │ {}                                       │ {:f}       │ 0.0:00:00.0000000                        |
// │ {}                                       │ {:F}       │ 0.00:00:00.0000000                       |
// │ {}                                       │ {:g}       │ 0:00:00                                  |
// │ {}                                       │ {:G}       │ 00:00:00                                 |
// │ {}                                       │ {:h}       │ 0                                        |
// │ {}                                       │ {:H}       │ 00                                       |
// │ {}                                       │ {:m}       │ 0                                        |
// │ {}                                       │ {:M}       │ 00                                       |
// │ {}                                       │ {:n}       │ 0                                        |
// │ {}                                       │ {:N}       │ 000000000                                |
// │ {}                                       │ {:s}       │ 0                                        |
// │ {}                                       │ {:S}       │ 00                                       |
// │ {}                                       │ {:t}       │ 0                                        |
// │ {}                                       │ {:T}       │ 0000000                                  |
// ├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ 6_h + 3_min + 8_s                        │ {}         │ 06:03:08                                 |
// │ 6_h + 3_min + 8_s                        │ {:c}       │ 06:03:08                                 |
// │ 6_h + 3_min + 8_s                        │ {:d}       │ 0                                        |
// │ 6_h + 3_min + 8_s                        │ {:D}       │ 00                                       |
// │ 6_h + 3_min + 8_s                        │ {:f}       │ 0.6:03:08.0000000                        |
// │ 6_h + 3_min + 8_s                        │ {:F}       │ 0.06:03:08.0000000                       |
// │ 6_h + 3_min + 8_s                        │ {:g}       │ 6:03:08                                  |
// │ 6_h + 3_min + 8_s                        │ {:G}       │ 06:03:08                                 |
// │ 6_h + 3_min + 8_s                        │ {:h}       │ 6                                        |
// │ 6_h + 3_min + 8_s                        │ {:H}       │ 06                                       |
// │ 6_h + 3_min + 8_s                        │ {:m}       │ 3                                        |
// │ 6_h + 3_min + 8_s                        │ {:M}       │ 03                                       |
// │ 6_h + 3_min + 8_s                        │ {:n}       │ 0                                        |
// │ 6_h + 3_min + 8_s                        │ {:N}       │ 000000000                                |
// │ 6_h + 3_min + 8_s                        │ {:s}       │ 8                                        |
// │ 6_h + 3_min + 8_s                        │ {:S}       │ 08                                       |
// │ 6_h + 3_min + 8_s                        │ {:t}       │ 0                                        |
// │ 6_h + 3_min + 8_s                        │ {:T}       │ 0000000                                  |
// ├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ 52_h + 3_min + 32_s                      │ {}         │ 2.04:03:02                               |
// │ 52_h + 3_min + 32_s                      │ {:c}       │ 2.04:03:02                               |
// │ 52_h + 3_min + 32_s                      │ {:d}       │ 2                                        |
// │ 52_h + 3_min + 32_s                      │ {:D}       │ 02                                       |
// │ 52_h + 3_min + 32_s                      │ {:f}       │ 2.4:03:02.0000000                        |
// │ 52_h + 3_min + 32_s                      │ {:F}       │ 2.04:03:02.0000000                       |
// │ 52_h + 3_min + 32_s                      │ {:g}       │ 2.4:03:02                                |
// │ 52_h + 3_min + 32_s                      │ {:G}       │ 2.04:03:02                               |
// │ 52_h + 3_min + 32_s                      │ {:h}       │ 4                                        |
// │ 52_h + 3_min + 32_s                      │ {:H}       │ 04                                       |
// │ 52_h + 3_min + 32_s                      │ {:m}       │ 3                                        |
// │ 52_h + 3_min + 32_s                      │ {:M}       │ 03                                       |
// │ 52_h + 3_min + 32_s                      │ {:n}       │ 0                                        |
// │ 52_h + 3_min + 32_s                      │ {:N}       │ 000000000                                |
// │ 52_h + 3_min + 32_s                      │ {:s}       │ 2                                        |
// │ 52_h + 3_min + 32_s                      │ {:S}       │ 02                                       |
// │ 52_h + 3_min + 32_s                      │ {:t}       │ 0                                        |
// │ 52_h + 3_min + 32_s                      │ {:T}       │ 0000000                                  |
// ├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ 24_ms + 543_ns                           │ {}         │ 00:00:00.0240005                         |
// │ 24_ms + 543_ns                           │ {:c}       │ 00:00:00.0240005                         |
// │ 24_ms + 543_ns                           │ {:d}       │ 0                                        |
// │ 24_ms + 543_ns                           │ {:D}       │ 00                                       |
// │ 24_ms + 543_ns                           │ {:f}       │ 0.0:00:00.0240005                        |
// │ 24_ms + 543_ns                           │ {:F}       │ 0.00:00:00.0240005                       |
// │ 24_ms + 543_ns                           │ {:g}       │ 0:00:00.0240005                          |
// │ 24_ms + 543_ns                           │ {:G}       │ 00:00:00.0240005                         |
// │ 24_ms + 543_ns                           │ {:h}       │ 0                                        |
// │ 24_ms + 543_ns                           │ {:H}       │ 00                                       |
// │ 24_ms + 543_ns                           │ {:m}       │ 0                                        |
// │ 24_ms + 543_ns                           │ {:M}       │ 00                                       |
// │ 24_ms + 543_ns                           │ {:n}       │ 24000500                                 |
// │ 24_ms + 543_ns                           │ {:N}       │ 024000500                                |
// │ 24_ms + 543_ns                           │ {:s}       │ 0                                        |
// │ 24_ms + 543_ns                           │ {:S}       │ 00                                       |
// │ 24_ms + 543_ns                           │ {:t}       │ 240005                                   |
// │ 24_ms + 543_ns                           │ {:T}       │ 0240005                                  |
// ├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {}         │ 2.04:03:02.0240005                       |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:c}       │ 2.04:03:02.0240005                       |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:d}       │ 2                                        |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:D}       │ 02                                       |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:f}       │ 2.4:03:02.0240005                        |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:F}       │ 2.04:03:02.0240005                       |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:g}       │ 2.4:03:02.0240005                        |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:G}       │ 2.04:03:02.0240005                       |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:h}       │ 4                                        |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:H}       │ 04                                       |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:m}       │ 3                                        |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:M}       │ 03                                       |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:n}       │ 24000500                                 |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:N}       │ 024000500                                |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:s}       │ 2                                        |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:S}       │ 02                                       |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:t}       │ 240005                                   |
// │ 52_h + 3_min + 2_s + 24_ms + 543_ns      │ {:T}       │ 0240005                                  |
// ├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ time_span::min_value                     │ {}         │ -10675199.02:48:05.4775808               |
// │ time_span::min_value                     │ {:c}       │ -10675199.02:48:05.4775808               |
// │ time_span::min_value                     │ {:d}       │ 10675199                                 |
// │ time_span::min_value                     │ {:D}       │ 10675199                                 |
// │ time_span::min_value                     │ {:f}       │ -10675199.2:48:05.4775808                |
// │ time_span::min_value                     │ {:F}       │ -10675199.02:48:05.4775808               |
// │ time_span::min_value                     │ {:g}       │ -10675199.2:48:05.4775808                |
// │ time_span::min_value                     │ {:G}       │ -10675199.02:48:05.4775808               |
// │ time_span::min_value                     │ {:h}       │ 2                                        |
// │ time_span::min_value                     │ {:H}       │ 02                                       |
// │ time_span::min_value                     │ {:m}       │ 48                                       |
// │ time_span::min_value                     │ {:M}       │ 48                                       |
// │ time_span::min_value                     │ {:n}       │ 477580800                                |
// │ time_span::min_value                     │ {:N}       │ 477580800                                |
// │ time_span::min_value                     │ {:s}       │ 5                                        |
// │ time_span::min_value                     │ {:S}       │ 05                                       |
// │ time_span::min_value                     │ {:t}       │ 4775808                                  |
// │ time_span::min_value                     │ {:T}       │ 4775808                                  |
// ├──────────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ time_span::max_value                     │ {}         │ 10675199.02:48:05.4775807                |
// │ time_span::max_value                     │ {:c}       │ 10675199.02:48:05.4775807                |
// │ time_span::max_value                     │ {:d}       │ 10675199                                 |
// │ time_span::max_value                     │ {:D}       │ 10675199                                 |
// │ time_span::max_value                     │ {:f}       │ 10675199.2:48:05.4775807                 |
// │ time_span::max_value                     │ {:F}       │ 10675199.02:48:05.4775807                |
// │ time_span::max_value                     │ {:g}       │ 10675199.2:48:05.4775807                 |
// │ time_span::max_value                     │ {:G}       │ 10675199.02:48:05.4775807                |
// │ time_span::max_value                     │ {:h}       │ 2                                        |
// │ time_span::max_value                     │ {:H}       │ 02                                       |
// │ time_span::max_value                     │ {:m}       │ 48                                       |
// │ time_span::max_value                     │ {:M}       │ 48                                       |
// │ time_span::max_value                     │ {:n}       │ 477580700                                |
// │ time_span::max_value                     │ {:N}       │ 477580700                                |
// │ time_span::max_value                     │ {:s}       │ 5                                        |
// │ time_span::max_value                     │ {:S}       │ 05                                       |
// │ time_span::max_value                     │ {:t}       │ 4775807                                  |
// │ time_span::max_value                     │ {:T}       │ 4775807                                  |
// └──────────────────────────────────────────┴────────────┴──────────────────────────────────────────┘
