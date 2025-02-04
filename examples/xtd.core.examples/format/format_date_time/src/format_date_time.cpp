#include <xtd/console>
#include <xtd/date_time>
#include <xtd/environment>
#include <xtd/format>

using namespace xtd;

enum class cap {title, middle, end};

auto print_date_time(const string& text, const date_time& value, cap c) {
  if (c == cap::title)
    console::out
    << "┌───────────────────────────────────────┬────────────┬──────────────────────────────────────────┐" << environment::new_line
    << "│  date_time                            │   format   │      representation                      │" << environment::new_line
    << "├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤" << environment::new_line;
  
  console::out <<  "│ " << text.pad_right(37) << " │ {}         │ " << format("{}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:a}       │ " << format("{:a}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:b}       │ " << format("{:b}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:B}       │ " << format("{:B}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:c}       │ " << format("{:c}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:C}       │ " << format("{:C}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:d}       │ " << format("{:d}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:D}       │ " << format("{:D}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:e}       │ " << format("{:e}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:E}       │ " << format("{:E}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:f}       │ " << format("{:f}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:F}       │ " << format("{:F}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:g}       │ " << format("{:g}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:G}       │ " << format("{:G}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:h}       │ " << format("{:h}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:H}       │ " << format("{:H}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:i}       │ " << format("{:i}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:I}       │ " << format("{:I}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:j}       │ " << format("{:j}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:J}       │ " << format("{:J}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:k}       │ " << format("{:k}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:K}       │ " << format("{:K}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:l}       │ " << format("{:l}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:L}       │ " << format("{:L}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:m}       │ " << format("{:m}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:M}       │ " << format("{:M}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:n}       │ " << format("{:n}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:n}       │ " << format("{:N}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:o}       │ " << format("{:o}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:O}       │ " << format("{:O}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:p}       │ " << format("{:p}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:P}       │ " << format("{:P}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:s}       │ " << format("{:s}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:S}       │ " << format("{:S}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:t}       │ " << format("{:t}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:T}       │ " << format("{:T}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:u}       │ " << format("{:u}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:U}       │ " << format("{:U}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:v}       │ " << format("{:v}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:V}       │ " << format("{:V}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:w}       │ " << format("{:w}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:W}       │ " << format("{:W}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:x}       │ " << format("{:x}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:X}       │ " << format("{:X}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:y}       │ " << format("{:y}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:Y}       │ " << format("{:Y}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:z}       │ " << format("{:z}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:Z}       │ " << format("{:Z}", value).pad_right(40) << " │" << environment::new_line;

  if (c != cap::end)
    console::out << "├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└───────────────────────────────────────┴────────────┴──────────────────────────────────────────┘" << environment::new_line;
}

auto main() -> int {
  print_date_time("date_time {}", date_time {}, cap::title);
  print_date_time("date_time {123456789123456789}", date_time {123456789123456789}, cap::middle);
  print_date_time("date_time {1971, 1, 5}", date_time {1971, 1, 5}, cap::middle);
  print_date_time("date_time {1971, 1, 5, 21, 30, 3}", date_time {1971, 1, 5, 21, 30, 3}, cap::middle);
  print_date_time("date_time {1971, 1, 5, 21, 30, 3, 42}", date_time {1971, 1, 5, 21, 30, 3, 42}, cap::middle);
  print_date_time("date_time::now()", date_time::now(), cap::middle);
  print_date_time("date_time::utc_now()", date_time::utc_now(), cap::middle);
  print_date_time("date_time::min_value", date_time::min_value, cap::middle);
  print_date_time("date_time::max_value", date_time::max_value, cap::end);
}

// This code can be produce the following output :
//
// ┌───────────────────────────────────────┬────────────┬──────────────────────────────────────────┐
// │  date_time                            │   format   │      representation                      │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time {}                          │ {}         │ Mon Jan  1 00:00:00 0001                 │
// │ date_time {}                          │ {:a}       │ AM                                       │
// │ date_time {}                          │ {:b}       │ 000                                      │
// │ date_time {}                          │ {:B}       │ 0                                        │
// │ date_time {}                          │ {:c}       │ 0000000                                  │
// │ date_time {}                          │ {:C}       │ 0                                        │
// │ date_time {}                          │ {:d}       │ 01/01/1                                  │
// │ date_time {}                          │ {:D}       │ 1/01/1                                   │
// │ date_time {}                          │ {:e}       │ 00                                       │
// │ date_time {}                          │ {:E}       │ 0                                        │
// │ date_time {}                          │ {:f}       │ Mon Jan  1 00:00:00 0001                 │
// │ date_time {}                          │ {:F}       │ Mon Jan  1 00:00:00 0001                 │
// │ date_time {}                          │ {:g}       │ Mon Jan  1 00:00:00 0001                 │
// │ date_time {}                          │ {:G}       │ 1-01-01 00:00:00                         │
// │ date_time {}                          │ {:h}       │ Mon                                      │
// │ date_time {}                          │ {:H}       │ Monday                                   │
// │ date_time {}                          │ {:i}       │ 01                                       │
// │ date_time {}                          │ {:I}       │ 1                                        │
// │ date_time {}                          │ {:j}       │ Jan                                      │
// │ date_time {}                          │ {:J}       │ January                                  │
// │ date_time {}                          │ {:k}       │ 01                                       │
// │ date_time {}                          │ {:K}       │ 1                                        │
// │ date_time {}                          │ {:l}       │ 01                                       │
// │ date_time {}                          │ {:L}       │ 0001                                     │
// │ date_time {}                          │ {:m}       │ 1                                        │
// │ date_time {}                          │ {:M}       │ January 1                                │
// │ date_time {}                          │ {:n}       │ Monday, 1 January 1                      │
// │ date_time {}                          │ {:n}       │ Monday, 1 January 1 0:00:00              │
// │ date_time {}                          │ {:o}       │ 1 January 1                              │
// │ date_time {}                          │ {:O}       │ 1 January 1                              │
// │ date_time {}                          │ {:p}       │ 00                                       │
// │ date_time {}                          │ {:P}       │ 0                                        │
// │ date_time {}                          │ {:s}       │ 0001-01-01T00:00:00.0000000              │
// │ date_time {}                          │ {:S}       │ 0001-01-01T00:00:00.000                  │
// │ date_time {}                          │ {:t}       │ 00:00:00                                 │
// │ date_time {}                          │ {:T}       │ 0:00:00                                  │
// │ date_time {}                          │ {:u}       │ 1-01-01 00:00:00                         │
// │ date_time {}                          │ {:U}       │ Monday, 1 January 1 0:00:00              │
// │ date_time {}                          │ {:v}       │ 00:00                                    │
// │ date_time {}                          │ {:V}       │ 0:00                                     │
// │ date_time {}                          │ {:w}       │ 00                                       │
// │ date_time {}                          │ {:W}       │ 0                                        │
// │ date_time {}                          │ {:x}       │ 00                                       │
// │ date_time {}                          │ {:X}       │ 0                                        │
// │ date_time {}                          │ {:y}       │ January 1                                │
// │ date_time {}                          │ {:Y}       │ January 1                                │
// │ date_time {}                          │ {:z}       │ UTC                                      │
// │ date_time {}                          │ {:Z}       │ UTC                                      │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time {123456789123456789}        │ {}         │ Sat Mar 21 19:15:12 0392                 │
// │ date_time {123456789123456789}        │ {:a}       │ PM                                       │
// │ date_time {123456789123456789}        │ {:b}       │ 345                                      │
// │ date_time {123456789123456789}        │ {:B}       │ 345                                      │
// │ date_time {123456789123456789}        │ {:c}       │ 0006789                                  │
// │ date_time {123456789123456789}        │ {:C}       │ 6789                                     │
// │ date_time {123456789123456789}        │ {:d}       │ 03/21/392                                │
// │ date_time {123456789123456789}        │ {:D}       │ 3/21/392                                 │
// │ date_time {123456789123456789}        │ {:e}       │ 12                                       │
// │ date_time {123456789123456789}        │ {:E}       │ 12                                       │
// │ date_time {123456789123456789}        │ {:f}       │ Sat Mar 21 19:15:12 0392                 │
// │ date_time {123456789123456789}        │ {:F}       │ Sat Mar 21 19:15:12 0392                 │
// │ date_time {123456789123456789}        │ {:g}       │ Sat Mar 21 19:15:12 0392                 │
// │ date_time {123456789123456789}        │ {:G}       │ 392-03-21 19:15:12                       │
// │ date_time {123456789123456789}        │ {:h}       │ Sat                                      │
// │ date_time {123456789123456789}        │ {:H}       │ Saturday                                 │
// │ date_time {123456789123456789}        │ {:i}       │ 21                                       │
// │ date_time {123456789123456789}        │ {:I}       │ 21                                       │
// │ date_time {123456789123456789}        │ {:j}       │ Mar                                      │
// │ date_time {123456789123456789}        │ {:J}       │ March                                    │
// │ date_time {123456789123456789}        │ {:k}       │ 03                                       │
// │ date_time {123456789123456789}        │ {:K}       │ 3                                        │
// │ date_time {123456789123456789}        │ {:l}       │ 92                                       │
// │ date_time {123456789123456789}        │ {:L}       │ 0392                                     │
// │ date_time {123456789123456789}        │ {:m}       │ 392                                      │
// │ date_time {123456789123456789}        │ {:M}       │ March 21                                 │
// │ date_time {123456789123456789}        │ {:n}       │ Saturday, 21 March 392                   │
// │ date_time {123456789123456789}        │ {:n}       │ Saturday, 21 March 392 19:15:12          │
// │ date_time {123456789123456789}        │ {:o}       │ 21 March 392                             │
// │ date_time {123456789123456789}        │ {:O}       │ 21 March 392                             │
// │ date_time {123456789123456789}        │ {:p}       │ 15                                       │
// │ date_time {123456789123456789}        │ {:P}       │ 15                                       │
// │ date_time {123456789123456789}        │ {:s}       │ 0392-03-21T19:15:12.3456789              │
// │ date_time {123456789123456789}        │ {:S}       │ 0392-03-21T19:15:12.345                  │
// │ date_time {123456789123456789}        │ {:t}       │ 19:15:12                                 │
// │ date_time {123456789123456789}        │ {:T}       │ 19:15:12                                 │
// │ date_time {123456789123456789}        │ {:u}       │ 392-03-21 19:15:12                       │
// │ date_time {123456789123456789}        │ {:U}       │ Saturday, 21 March 392 19:15:12          │
// │ date_time {123456789123456789}        │ {:v}       │ 19:15                                    │
// │ date_time {123456789123456789}        │ {:V}       │ 19:15                                    │
// │ date_time {123456789123456789}        │ {:w}       │ 19                                       │
// │ date_time {123456789123456789}        │ {:W}       │ 19                                       │
// │ date_time {123456789123456789}        │ {:x}       │ 07                                       │
// │ date_time {123456789123456789}        │ {:X}       │ 7                                        │
// │ date_time {123456789123456789}        │ {:y}       │ March 92                                 │
// │ date_time {123456789123456789}        │ {:Y}       │ March 392                                │
// │ date_time {123456789123456789}        │ {:z}       │ UTC                                      │
// │ date_time {123456789123456789}        │ {:Z}       │ UTC                                      │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time {1971, 1, 5}                │ {}         │ Tue Jan  5 00:00:00 1971                 │
// │ date_time {1971, 1, 5}                │ {:a}       │ AM                                       │
// │ date_time {1971, 1, 5}                │ {:b}       │ 000                                      │
// │ date_time {1971, 1, 5}                │ {:B}       │ 0                                        │
// │ date_time {1971, 1, 5}                │ {:c}       │ 0000000                                  │
// │ date_time {1971, 1, 5}                │ {:C}       │ 0                                        │
// │ date_time {1971, 1, 5}                │ {:d}       │ 01/05/1971                               │
// │ date_time {1971, 1, 5}                │ {:D}       │ 1/05/1971                                │
// │ date_time {1971, 1, 5}                │ {:e}       │ 00                                       │
// │ date_time {1971, 1, 5}                │ {:E}       │ 0                                        │
// │ date_time {1971, 1, 5}                │ {:f}       │ Tue Jan  5 00:00:00 1971                 │
// │ date_time {1971, 1, 5}                │ {:F}       │ Tue Jan  5 00:00:00 1971                 │
// │ date_time {1971, 1, 5}                │ {:g}       │ Tue Jan  5 00:00:00 1971                 │
// │ date_time {1971, 1, 5}                │ {:G}       │ 1971-01-05 00:00:00                      │
// │ date_time {1971, 1, 5}                │ {:h}       │ Tue                                      │
// │ date_time {1971, 1, 5}                │ {:H}       │ Tuesday                                  │
// │ date_time {1971, 1, 5}                │ {:i}       │ 05                                       │
// │ date_time {1971, 1, 5}                │ {:I}       │ 5                                        │
// │ date_time {1971, 1, 5}                │ {:j}       │ Jan                                      │
// │ date_time {1971, 1, 5}                │ {:J}       │ January                                  │
// │ date_time {1971, 1, 5}                │ {:k}       │ 01                                       │
// │ date_time {1971, 1, 5}                │ {:K}       │ 1                                        │
// │ date_time {1971, 1, 5}                │ {:l}       │ 71                                       │
// │ date_time {1971, 1, 5}                │ {:L}       │ 1971                                     │
// │ date_time {1971, 1, 5}                │ {:m}       │ 1971                                     │
// │ date_time {1971, 1, 5}                │ {:M}       │ January 5                                │
// │ date_time {1971, 1, 5}                │ {:n}       │ Tuesday, 5 January 1971                  │
// │ date_time {1971, 1, 5}                │ {:n}       │ Tuesday, 5 January 1971 0:00:00          │
// │ date_time {1971, 1, 5}                │ {:o}       │ 5 January 1971                           │
// │ date_time {1971, 1, 5}                │ {:O}       │ 5 January 1971                           │
// │ date_time {1971, 1, 5}                │ {:p}       │ 00                                       │
// │ date_time {1971, 1, 5}                │ {:P}       │ 0                                        │
// │ date_time {1971, 1, 5}                │ {:s}       │ 1971-01-05T00:00:00.0000000              │
// │ date_time {1971, 1, 5}                │ {:S}       │ 1971-01-05T00:00:00.000                  │
// │ date_time {1971, 1, 5}                │ {:t}       │ 00:00:00                                 │
// │ date_time {1971, 1, 5}                │ {:T}       │ 0:00:00                                  │
// │ date_time {1971, 1, 5}                │ {:u}       │ 1971-01-05 00:00:00                      │
// │ date_time {1971, 1, 5}                │ {:U}       │ Tuesday, 5 January 1971 0:00:00          │
// │ date_time {1971, 1, 5}                │ {:v}       │ 00:00                                    │
// │ date_time {1971, 1, 5}                │ {:V}       │ 0:00                                     │
// │ date_time {1971, 1, 5}                │ {:w}       │ 00                                       │
// │ date_time {1971, 1, 5}                │ {:W}       │ 0                                        │
// │ date_time {1971, 1, 5}                │ {:x}       │ 00                                       │
// │ date_time {1971, 1, 5}                │ {:X}       │ 0                                        │
// │ date_time {1971, 1, 5}                │ {:y}       │ January 71                               │
// │ date_time {1971, 1, 5}                │ {:Y}       │ January 1971                             │
// │ date_time {1971, 1, 5}                │ {:z}       │ UTC                                      │
// │ date_time {1971, 1, 5}                │ {:Z}       │ UTC                                      │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {}         │ Tue Jan  5 21:30:03 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:a}       │ PM                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:b}       │ 000                                      │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:B}       │ 0                                        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:c}       │ 0000000                                  │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:C}       │ 0                                        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:d}       │ 01/05/1971                               │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:D}       │ 1/05/1971                                │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:e}       │ 03                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:E}       │ 3                                        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:f}       │ Tue Jan  5 21:30:03 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:F}       │ Tue Jan  5 21:30:03 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:g}       │ Tue Jan  5 21:30:03 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:G}       │ 1971-01-05 21:30:03                      │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:h}       │ Tue                                      │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:H}       │ Tuesday                                  │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:i}       │ 05                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:I}       │ 5                                        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:j}       │ Jan                                      │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:J}       │ January                                  │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:k}       │ 01                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:K}       │ 1                                        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:l}       │ 71                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:L}       │ 1971                                     │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:m}       │ 1971                                     │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:M}       │ January 5                                │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:n}       │ Tuesday, 5 January 1971                  │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:n}       │ Tuesday, 5 January 1971 21:30:03         │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:o}       │ 5 January 1971                           │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:O}       │ 5 January 1971                           │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:p}       │ 30                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:P}       │ 30                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:s}       │ 1971-01-05T21:30:03.0000000              │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:S}       │ 1971-01-05T21:30:03.000                  │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:t}       │ 21:30:03                                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:T}       │ 21:30:03                                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:u}       │ 1971-01-05 21:30:03                      │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:U}       │ Tuesday, 5 January 1971 21:30:03         │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:v}       │ 21:30                                    │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:V}       │ 21:30                                    │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:w}       │ 21                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:W}       │ 21                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:x}       │ 09                                       │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:X}       │ 9                                        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:y}       │ January 71                               │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:Y}       │ January 1971                             │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:z}       │ UTC                                      │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:Z}       │ UTC                                      │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {}         │ Tue Jan  5 21:30:03 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:a}       │ PM                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:b}       │ 042                                      │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:B}       │ 42                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:c}       │ 0000000                                  │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:C}       │ 0                                        │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:d}       │ 01/05/1971                               │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:D}       │ 1/05/1971                                │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:e}       │ 03                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:E}       │ 3                                        │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:f}       │ Tue Jan  5 21:30:03 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:F}       │ Tue Jan  5 21:30:03 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:g}       │ Tue Jan  5 21:30:03 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:G}       │ 1971-01-05 21:30:03                      │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:h}       │ Tue                                      │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:H}       │ Tuesday                                  │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:i}       │ 05                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:I}       │ 5                                        │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:j}       │ Jan                                      │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:J}       │ January                                  │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:k}       │ 01                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:K}       │ 1                                        │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:l}       │ 71                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:L}       │ 1971                                     │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:m}       │ 1971                                     │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:M}       │ January 5                                │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:n}       │ Tuesday, 5 January 1971                  │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:n}       │ Tuesday, 5 January 1971 21:30:03         │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:o}       │ 5 January 1971                           │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:O}       │ 5 January 1971                           │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:p}       │ 30                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:P}       │ 30                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:s}       │ 1971-01-05T21:30:03.0420000              │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:S}       │ 1971-01-05T21:30:03.042                  │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:t}       │ 21:30:03                                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:T}       │ 21:30:03                                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:u}       │ 1971-01-05 21:30:03                      │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:U}       │ Tuesday, 5 January 1971 21:30:03         │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:v}       │ 21:30                                    │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:V}       │ 21:30                                    │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:w}       │ 21                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:W}       │ 21                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:x}       │ 09                                       │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:X}       │ 9                                        │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:y}       │ January 71                               │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:Y}       │ January 1971                             │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:z}       │ UTC                                      │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:Z}       │ UTC                                      │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time::now()                      │ {}         │ Wed Dec 18 20:10:41 2024                 │
// │ date_time::now()                      │ {:a}       │ PM                                       │
// │ date_time::now()                      │ {:b}       │ 825                                      │
// │ date_time::now()                      │ {:B}       │ 825                                      │
// │ date_time::now()                      │ {:c}       │ 0002420                                  │
// │ date_time::now()                      │ {:C}       │ 2420                                     │
// │ date_time::now()                      │ {:d}       │ 12/18/2024                               │
// │ date_time::now()                      │ {:D}       │ 12/18/2024                               │
// │ date_time::now()                      │ {:e}       │ 41                                       │
// │ date_time::now()                      │ {:E}       │ 41                                       │
// │ date_time::now()                      │ {:f}       │ Wed Dec 18 20:10:41 2024                 │
// │ date_time::now()                      │ {:F}       │ Wed Dec 18 20:10:41 2024                 │
// │ date_time::now()                      │ {:g}       │ Wed Dec 18 20:10:41 2024                 │
// │ date_time::now()                      │ {:G}       │ 2024-12-18 20:10:41                      │
// │ date_time::now()                      │ {:h}       │ Wed                                      │
// │ date_time::now()                      │ {:H}       │ Wednesday                                │
// │ date_time::now()                      │ {:i}       │ 18                                       │
// │ date_time::now()                      │ {:I}       │ 18                                       │
// │ date_time::now()                      │ {:j}       │ Dec                                      │
// │ date_time::now()                      │ {:J}       │ December                                 │
// │ date_time::now()                      │ {:k}       │ 12                                       │
// │ date_time::now()                      │ {:K}       │ 12                                       │
// │ date_time::now()                      │ {:l}       │ 24                                       │
// │ date_time::now()                      │ {:L}       │ 2024                                     │
// │ date_time::now()                      │ {:m}       │ 2024                                     │
// │ date_time::now()                      │ {:M}       │ December 18                              │
// │ date_time::now()                      │ {:n}       │ Wednesday, 18 December 2024              │
// │ date_time::now()                      │ {:n}       │ Wednesday, 18 December 2024 20:10:41     │
// │ date_time::now()                      │ {:o}       │ 18 December 2024                         │
// │ date_time::now()                      │ {:O}       │ 18 December 2024                         │
// │ date_time::now()                      │ {:p}       │ 10                                       │
// │ date_time::now()                      │ {:P}       │ 10                                       │
// │ date_time::now()                      │ {:s}       │ 2024-12-18T20:10:41.8252420              │
// │ date_time::now()                      │ {:S}       │ 2024-12-18T20:10:41.825                  │
// │ date_time::now()                      │ {:t}       │ 20:10:41                                 │
// │ date_time::now()                      │ {:T}       │ 20:10:41                                 │
// │ date_time::now()                      │ {:u}       │ 2024-12-18 20:10:41                      │
// │ date_time::now()                      │ {:U}       │ Wednesday, 18 December 2024 20:10:41     │
// │ date_time::now()                      │ {:v}       │ 20:10                                    │
// │ date_time::now()                      │ {:V}       │ 20:10                                    │
// │ date_time::now()                      │ {:w}       │ 20                                       │
// │ date_time::now()                      │ {:W}       │ 20                                       │
// │ date_time::now()                      │ {:x}       │ 08                                       │
// │ date_time::now()                      │ {:X}       │ 8                                        │
// │ date_time::now()                      │ {:y}       │ December 24                              │
// │ date_time::now()                      │ {:Y}       │ December 2024                            │
// │ date_time::now()                      │ {:z}       │                                          │
// │ date_time::now()                      │ {:Z}       │                                          │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time::utc_now()                  │ {}         │ Wed Dec 18 19:10:41 2024                 │
// │ date_time::utc_now()                  │ {:a}       │ PM                                       │
// │ date_time::utc_now()                  │ {:b}       │ 827                                      │
// │ date_time::utc_now()                  │ {:B}       │ 827                                      │
// │ date_time::utc_now()                  │ {:c}       │ 0005120                                  │
// │ date_time::utc_now()                  │ {:C}       │ 5120                                     │
// │ date_time::utc_now()                  │ {:d}       │ 12/18/2024                               │
// │ date_time::utc_now()                  │ {:D}       │ 12/18/2024                               │
// │ date_time::utc_now()                  │ {:e}       │ 41                                       │
// │ date_time::utc_now()                  │ {:E}       │ 41                                       │
// │ date_time::utc_now()                  │ {:f}       │ Wed Dec 18 19:10:41 2024                 │
// │ date_time::utc_now()                  │ {:F}       │ Wed Dec 18 19:10:41 2024                 │
// │ date_time::utc_now()                  │ {:g}       │ Wed Dec 18 19:10:41 2024                 │
// │ date_time::utc_now()                  │ {:G}       │ 2024-12-18 19:10:41                      │
// │ date_time::utc_now()                  │ {:h}       │ Wed                                      │
// │ date_time::utc_now()                  │ {:H}       │ Wednesday                                │
// │ date_time::utc_now()                  │ {:i}       │ 18                                       │
// │ date_time::utc_now()                  │ {:I}       │ 18                                       │
// │ date_time::utc_now()                  │ {:j}       │ Dec                                      │
// │ date_time::utc_now()                  │ {:J}       │ December                                 │
// │ date_time::utc_now()                  │ {:k}       │ 12                                       │
// │ date_time::utc_now()                  │ {:K}       │ 12                                       │
// │ date_time::utc_now()                  │ {:l}       │ 24                                       │
// │ date_time::utc_now()                  │ {:L}       │ 2024                                     │
// │ date_time::utc_now()                  │ {:m}       │ 2024                                     │
// │ date_time::utc_now()                  │ {:M}       │ December 18                              │
// │ date_time::utc_now()                  │ {:n}       │ Wednesday, 18 December 2024              │
// │ date_time::utc_now()                  │ {:n}       │ Wednesday, 18 December 2024 19:10:41     │
// │ date_time::utc_now()                  │ {:o}       │ 18 December 2024                         │
// │ date_time::utc_now()                  │ {:O}       │ 18 December 2024                         │
// │ date_time::utc_now()                  │ {:p}       │ 10                                       │
// │ date_time::utc_now()                  │ {:P}       │ 10                                       │
// │ date_time::utc_now()                  │ {:s}       │ 2024-12-18T19:10:41.8275120              │
// │ date_time::utc_now()                  │ {:S}       │ 2024-12-18T19:10:41.827                  │
// │ date_time::utc_now()                  │ {:t}       │ 19:10:41                                 │
// │ date_time::utc_now()                  │ {:T}       │ 19:10:41                                 │
// │ date_time::utc_now()                  │ {:u}       │ 2024-12-18 19:10:41                      │
// │ date_time::utc_now()                  │ {:U}       │ Wednesday, 18 December 2024 19:10:41     │
// │ date_time::utc_now()                  │ {:v}       │ 19:10                                    │
// │ date_time::utc_now()                  │ {:V}       │ 19:10                                    │
// │ date_time::utc_now()                  │ {:w}       │ 19                                       │
// │ date_time::utc_now()                  │ {:W}       │ 19                                       │
// │ date_time::utc_now()                  │ {:x}       │ 07                                       │
// │ date_time::utc_now()                  │ {:X}       │ 7                                        │
// │ date_time::utc_now()                  │ {:y}       │ December 24                              │
// │ date_time::utc_now()                  │ {:Y}       │ December 2024                            │
// │ date_time::utc_now()                  │ {:z}       │ UTC                                      │
// │ date_time::utc_now()                  │ {:Z}       │ UTC                                      │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time::min_value                  │ {}         │ Mon Jan  1 00:00:00 0001                 │
// │ date_time::min_value                  │ {:a}       │ AM                                       │
// │ date_time::min_value                  │ {:b}       │ 000                                      │
// │ date_time::min_value                  │ {:B}       │ 0                                        │
// │ date_time::min_value                  │ {:c}       │ 0000000                                  │
// │ date_time::min_value                  │ {:C}       │ 0                                        │
// │ date_time::min_value                  │ {:d}       │ 01/01/1                                  │
// │ date_time::min_value                  │ {:D}       │ 1/01/1                                   │
// │ date_time::min_value                  │ {:e}       │ 00                                       │
// │ date_time::min_value                  │ {:E}       │ 0                                        │
// │ date_time::min_value                  │ {:f}       │ Mon Jan  1 00:00:00 0001                 │
// │ date_time::min_value                  │ {:F}       │ Mon Jan  1 00:00:00 0001                 │
// │ date_time::min_value                  │ {:g}       │ Mon Jan  1 00:00:00 0001                 │
// │ date_time::min_value                  │ {:G}       │ 1-01-01 00:00:00                         │
// │ date_time::min_value                  │ {:h}       │ Mon                                      │
// │ date_time::min_value                  │ {:H}       │ Monday                                   │
// │ date_time::min_value                  │ {:i}       │ 01                                       │
// │ date_time::min_value                  │ {:I}       │ 1                                        │
// │ date_time::min_value                  │ {:j}       │ Jan                                      │
// │ date_time::min_value                  │ {:J}       │ January                                  │
// │ date_time::min_value                  │ {:k}       │ 01                                       │
// │ date_time::min_value                  │ {:K}       │ 1                                        │
// │ date_time::min_value                  │ {:l}       │ 01                                       │
// │ date_time::min_value                  │ {:L}       │ 0001                                     │
// │ date_time::min_value                  │ {:m}       │ 1                                        │
// │ date_time::min_value                  │ {:M}       │ January 1                                │
// │ date_time::min_value                  │ {:n}       │ Monday, 1 January 1                      │
// │ date_time::min_value                  │ {:n}       │ Monday, 1 January 1 0:00:00              │
// │ date_time::min_value                  │ {:o}       │ 1 January 1                              │
// │ date_time::min_value                  │ {:O}       │ 1 January 1                              │
// │ date_time::min_value                  │ {:p}       │ 00                                       │
// │ date_time::min_value                  │ {:P}       │ 0                                        │
// │ date_time::min_value                  │ {:s}       │ 0001-01-01T00:00:00.0000000              │
// │ date_time::min_value                  │ {:S}       │ 0001-01-01T00:00:00.000                  │
// │ date_time::min_value                  │ {:t}       │ 00:00:00                                 │
// │ date_time::min_value                  │ {:T}       │ 0:00:00                                  │
// │ date_time::min_value                  │ {:u}       │ 1-01-01 00:00:00                         │
// │ date_time::min_value                  │ {:U}       │ Monday, 1 January 1 0:00:00              │
// │ date_time::min_value                  │ {:v}       │ 00:00                                    │
// │ date_time::min_value                  │ {:V}       │ 0:00                                     │
// │ date_time::min_value                  │ {:w}       │ 00                                       │
// │ date_time::min_value                  │ {:W}       │ 0                                        │
// │ date_time::min_value                  │ {:x}       │ 00                                       │
// │ date_time::min_value                  │ {:X}       │ 0                                        │
// │ date_time::min_value                  │ {:y}       │ January 1                                │
// │ date_time::min_value                  │ {:Y}       │ January 1                                │
// │ date_time::min_value                  │ {:z}       │ UTC                                      │
// │ date_time::min_value                  │ {:Z}       │ UTC                                      │
// ├───────────────────────────────────────┼────────────┼──────────────────────────────────────────┤
// │ date_time::max_value                  │ {}         │ Fri Dec 31 23:59:59 9999                 │
// │ date_time::max_value                  │ {:a}       │ PM                                       │
// │ date_time::max_value                  │ {:b}       │ 999                                      │
// │ date_time::max_value                  │ {:B}       │ 999                                      │
// │ date_time::max_value                  │ {:c}       │ 0009999                                  │
// │ date_time::max_value                  │ {:C}       │ 9999                                     │
// │ date_time::max_value                  │ {:d}       │ 12/31/9999                               │
// │ date_time::max_value                  │ {:D}       │ 12/31/9999                               │
// │ date_time::max_value                  │ {:e}       │ 59                                       │
// │ date_time::max_value                  │ {:E}       │ 59                                       │
// │ date_time::max_value                  │ {:f}       │ Fri Dec 31 23:59:59 9999                 │
// │ date_time::max_value                  │ {:F}       │ Fri Dec 31 23:59:59 9999                 │
// │ date_time::max_value                  │ {:g}       │ Fri Dec 31 23:59:59 9999                 │
// │ date_time::max_value                  │ {:G}       │ 9999-12-31 23:59:59                      │
// │ date_time::max_value                  │ {:h}       │ Fri                                      │
// │ date_time::max_value                  │ {:H}       │ Friday                                   │
// │ date_time::max_value                  │ {:i}       │ 31                                       │
// │ date_time::max_value                  │ {:I}       │ 31                                       │
// │ date_time::max_value                  │ {:j}       │ Dec                                      │
// │ date_time::max_value                  │ {:J}       │ December                                 │
// │ date_time::max_value                  │ {:k}       │ 12                                       │
// │ date_time::max_value                  │ {:K}       │ 12                                       │
// │ date_time::max_value                  │ {:l}       │ 99                                       │
// │ date_time::max_value                  │ {:L}       │ 9999                                     │
// │ date_time::max_value                  │ {:m}       │ 9999                                     │
// │ date_time::max_value                  │ {:M}       │ December 31                              │
// │ date_time::max_value                  │ {:n}       │ Friday, 31 December 9999                 │
// │ date_time::max_value                  │ {:n}       │ Friday, 31 December 9999 23:59:59        │
// │ date_time::max_value                  │ {:o}       │ 31 December 9999                         │
// │ date_time::max_value                  │ {:O}       │ 31 December 9999                         │
// │ date_time::max_value                  │ {:p}       │ 59                                       │
// │ date_time::max_value                  │ {:P}       │ 59                                       │
// │ date_time::max_value                  │ {:s}       │ 9999-12-31T23:59:59.9999999              │
// │ date_time::max_value                  │ {:S}       │ 9999-12-31T23:59:59.999                  │
// │ date_time::max_value                  │ {:t}       │ 23:59:59                                 │
// │ date_time::max_value                  │ {:T}       │ 23:59:59                                 │
// │ date_time::max_value                  │ {:u}       │ 9999-12-31 23:59:59                      │
// │ date_time::max_value                  │ {:U}       │ Friday, 31 December 9999 23:59:59        │
// │ date_time::max_value                  │ {:v}       │ 23:59                                    │
// │ date_time::max_value                  │ {:V}       │ 23:59                                    │
// │ date_time::max_value                  │ {:w}       │ 23                                       │
// │ date_time::max_value                  │ {:W}       │ 23                                       │
// │ date_time::max_value                  │ {:x}       │ 11                                       │
// │ date_time::max_value                  │ {:X}       │ 11                                       │
// │ date_time::max_value                  │ {:y}       │ December 99                              │
// │ date_time::max_value                  │ {:Y}       │ December 9999                            │
// │ date_time::max_value                  │ {:z}       │ UTC                                      │
// │ date_time::max_value                  │ {:Z}       │ UTC                                      │
// └───────────────────────────────────────┴────────────┴──────────────────────────────────────────┘
