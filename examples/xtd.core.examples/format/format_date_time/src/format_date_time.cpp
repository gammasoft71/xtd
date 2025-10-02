#include <xtd/xtd>

enum class cap {title, middle, end};

auto print_date_time(const string& text, const date_time& value, cap c) {
  if (c == cap::title)
    console::out
    << "┌───────────────────────────────────────┬─────────────────────┬──────────────────────────────────────────┐" << environment::new_line
    << "│  date_time                            │     format          │      representation                      │" << environment::new_line
    << "├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤" << environment::new_line;
  
  console::out <<  "│ " << text.pad_right(37) << " │ {}                  │ " << format("{}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:d}                │ " << format("{:d}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:D}                │ " << format("{:D}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:f}                │ " << format("{:f}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:F}                │ " << format("{:F}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:g}                │ " << format("{:g}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:G}                │ " << format("{:G}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:m}                │ " << format("{:m}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:M}                │ " << format("{:M}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:o}                │ " << format("{:o}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:O}                │ " << format("{:O}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:r}                │ " << format("{:r}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:R}                │ " << format("{:R}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:s}                │ " << format("{:s}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:t}                │ " << format("{:t}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:T}                │ " << format("{:T}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:u}                │ " << format("{:u}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:U}                │ " << format("{:U}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:y}                │ " << format("{:y}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:Y}                │ " << format("{:Y}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:h:mm:ss.ff t}     │ " << format("{:h:mm:ss.ff t}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:d MMM yyyy}       │ " << format("{:d MMM yyyy}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:HH:mm:ss.f}       │ " << format("{:HH:mm:ss.f}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:dd MMM HH:mm:ss}  │ " << format("{:dd MMM HH:mm:ss}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:\\Mon\\t\\h\\: M}     │ " << format("{:\\Mon\\t\\h\\: M}", value).pad_right(40) << " │" << environment::new_line;
  console::out <<  "│ " << text.pad_right(37) << " │ {:HH:mm:ss.ffffzzz} │ " << format("{:HH:mm:ss.ffffzzz}", value).pad_right(40) << " │" << environment::new_line;

  if (c != cap::end)
    console::out << "├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤" << environment::new_line;
  else
    console::out << "└───────────────────────────────────────┴─────────────────────┴──────────────────────────────────────────┘" << environment::new_line;
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
// ┌───────────────────────────────────────┬─────────────────────┬──────────────────────────────────────────┐
// │  date_time                            │     format          │      representation                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time {}                          │ {}                  │ 1/1/0001 00:00                           │
// │ date_time {}                          │ {:d}                │ 1/1/0001                                 │
// │ date_time {}                          │ {:D}                │ Monday, January 1, 0001                  │
// │ date_time {}                          │ {:f}                │ Monday, January 1, 0001 00:00            │
// │ date_time {}                          │ {:F}                │ Monday, January 1, 0001 00:00:00         │
// │ date_time {}                          │ {:g}                │ 1/1/0001 00:00                           │
// │ date_time {}                          │ {:G}                │ 1/1/0001 00:00:00                        │
// │ date_time {}                          │ {:m}                │ January 1                                │
// │ date_time {}                          │ {:M}                │ January 1                                │
// │ date_time {}                          │ {:o}                │ 0001-01-01T00:00:00.0000000Z             │
// │ date_time {}                          │ {:O}                │ 0001-01-01T00:00:00.0000000Z             │
// │ date_time {}                          │ {:r}                │ Mon, 01 Jan 0001 00:00:00 G1T            │
// │ date_time {}                          │ {:R}                │ Mon, 01 Jan 0001 00:00:00 G1T            │
// │ date_time {}                          │ {:s}                │ 0001-01-01T00:00:00                      │
// │ date_time {}                          │ {:t}                │ 00:00                                    │
// │ date_time {}                          │ {:T}                │ 00:00:00                                 │
// │ date_time {}                          │ {:u}                │ 0001-01-01 00:00:00Z                     │
// │ date_time {}                          │ {:U}                │ Monday, January 1, 0001 00:00:00         │
// │ date_time {}                          │ {:y}                │ January 0001                             │
// │ date_time {}                          │ {:Y}                │ January 0001                             │
// │ date_time {}                          │ {:h:mm:ss.ff t}     │ 0:00:00.00 A                             │
// │ date_time {}                          │ {:d MMM yyyy}       │ 1 Jan 0001                               │
// │ date_time {}                          │ {:HH:mm:ss.f}       │ 00:00:00.0                               │
// │ date_time {}                          │ {:dd MMM HH:mm:ss}  │ 01 Jan 00:00:00                          │
// │ date_time {}                          │ {:\Mon\t\h\: M}     │ Month: 1                                 │
// │ date_time {}                          │ {:HH:mm:ss.ffffzzz} │ 00:00:00.0000+00:17                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time {123456789123456789}        │ {}                  │ 3/21/0392 19:15                          │
// │ date_time {123456789123456789}        │ {:d}                │ 3/21/0392                                │
// │ date_time {123456789123456789}        │ {:D}                │ Saturday, March 21, 0392                 │
// │ date_time {123456789123456789}        │ {:f}                │ Saturday, March 21, 0392 19:15           │
// │ date_time {123456789123456789}        │ {:F}                │ Saturday, March 21, 0392 19:15:12        │
// │ date_time {123456789123456789}        │ {:g}                │ 3/21/0392 19:15                          │
// │ date_time {123456789123456789}        │ {:G}                │ 3/21/0392 19:15:12                       │
// │ date_time {123456789123456789}        │ {:m}                │ March 21                                 │
// │ date_time {123456789123456789}        │ {:M}                │ March 21                                 │
// │ date_time {123456789123456789}        │ {:o}                │ 0392-03-21T19:15:12.3456789Z             │
// │ date_time {123456789123456789}        │ {:O}                │ 0392-03-21T19:15:12.3456789Z             │
// │ date_time {123456789123456789}        │ {:r}                │ Sat, 21 Mar 0392 19:15:12 G3T            │
// │ date_time {123456789123456789}        │ {:R}                │ Sat, 21 Mar 0392 19:15:12 G3T            │
// │ date_time {123456789123456789}        │ {:s}                │ 0392-03-21T19:15:12                      │
// │ date_time {123456789123456789}        │ {:t}                │ 19:15                                    │
// │ date_time {123456789123456789}        │ {:T}                │ 19:15:12                                 │
// │ date_time {123456789123456789}        │ {:u}                │ 0392-03-21 19:15:12Z                     │
// │ date_time {123456789123456789}        │ {:U}                │ Saturday, March 21, 0392 19:15:12        │
// │ date_time {123456789123456789}        │ {:y}                │ March 0392                               │
// │ date_time {123456789123456789}        │ {:Y}                │ March 0392                               │
// │ date_time {123456789123456789}        │ {:h:mm:ss.ff t}     │ 7:15:12.34 P                             │
// │ date_time {123456789123456789}        │ {:d MMM yyyy}       │ 21 Mar 0392                              │
// │ date_time {123456789123456789}        │ {:HH:mm:ss.f}       │ 19:15:12.3                               │
// │ date_time {123456789123456789}        │ {:dd MMM HH:mm:ss}  │ 21 Mar 19:15:12                          │
// │ date_time {123456789123456789}        │ {:\Mon\t\h\: M}     │ Month: 3                                 │
// │ date_time {123456789123456789}        │ {:HH:mm:ss.ffffzzz} │ 19:15:12.3456+00:17                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time {1971, 1, 5}                │ {}                  │ 1/5/1971 00:00                           │
// │ date_time {1971, 1, 5}                │ {:d}                │ 1/5/1971                                 │
// │ date_time {1971, 1, 5}                │ {:D}                │ Tuesday, January 5, 1971                 │
// │ date_time {1971, 1, 5}                │ {:f}                │ Tuesday, January 5, 1971 00:00           │
// │ date_time {1971, 1, 5}                │ {:F}                │ Tuesday, January 5, 1971 00:00:00        │
// │ date_time {1971, 1, 5}                │ {:g}                │ 1/5/1971 00:00                           │
// │ date_time {1971, 1, 5}                │ {:G}                │ 1/5/1971 00:00:00                        │
// │ date_time {1971, 1, 5}                │ {:m}                │ January 5                                │
// │ date_time {1971, 1, 5}                │ {:M}                │ January 5                                │
// │ date_time {1971, 1, 5}                │ {:o}                │ 1971-01-05T00:00:00.0000000Z             │
// │ date_time {1971, 1, 5}                │ {:O}                │ 1971-01-05T00:00:00.0000000Z             │
// │ date_time {1971, 1, 5}                │ {:r}                │ Tue, 05 Jan 1971 00:00:00 G1T            │
// │ date_time {1971, 1, 5}                │ {:R}                │ Tue, 05 Jan 1971 00:00:00 G1T            │
// │ date_time {1971, 1, 5}                │ {:s}                │ 1971-01-05T00:00:00                      │
// │ date_time {1971, 1, 5}                │ {:t}                │ 00:00                                    │
// │ date_time {1971, 1, 5}                │ {:T}                │ 00:00:00                                 │
// │ date_time {1971, 1, 5}                │ {:u}                │ 1971-01-05 00:00:00Z                     │
// │ date_time {1971, 1, 5}                │ {:U}                │ Tuesday, January 5, 1971 00:00:00        │
// │ date_time {1971, 1, 5}                │ {:y}                │ January 1971                             │
// │ date_time {1971, 1, 5}                │ {:Y}                │ January 1971                             │
// │ date_time {1971, 1, 5}                │ {:h:mm:ss.ff t}     │ 0:00:00.00 A                             │
// │ date_time {1971, 1, 5}                │ {:d MMM yyyy}       │ 5 Jan 1971                               │
// │ date_time {1971, 1, 5}                │ {:HH:mm:ss.f}       │ 00:00:00.0                               │
// │ date_time {1971, 1, 5}                │ {:dd MMM HH:mm:ss}  │ 05 Jan 00:00:00                          │
// │ date_time {1971, 1, 5}                │ {:\Mon\t\h\: M}     │ Month: 1                                 │
// │ date_time {1971, 1, 5}                │ {:HH:mm:ss.ffffzzz} │ 00:00:00.0000+01:00                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {}                  │ 1/5/1971 21:30                           │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:d}                │ 1/5/1971                                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:D}                │ Tuesday, January 5, 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:f}                │ Tuesday, January 5, 1971 21:30           │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:F}                │ Tuesday, January 5, 1971 21:30:03        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:g}                │ 1/5/1971 21:30                           │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:G}                │ 1/5/1971 21:30:03                        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:m}                │ January 5                                │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:M}                │ January 5                                │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:o}                │ 1971-01-05T21:30:03.0000000Z             │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:O}                │ 1971-01-05T21:30:03.0000000Z             │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:r}                │ Tue, 05 Jan 1971 21:30:03 G1T            │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:R}                │ Tue, 05 Jan 1971 21:30:03 G1T            │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:s}                │ 1971-01-05T21:30:03                      │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:t}                │ 21:30                                    │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:T}                │ 21:30:03                                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:u}                │ 1971-01-05 21:30:03Z                     │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:U}                │ Tuesday, January 5, 1971 21:30:03        │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:y}                │ January 1971                             │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:Y}                │ January 1971                             │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:h:mm:ss.ff t}     │ 9:30:03.00 P                             │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:d MMM yyyy}       │ 5 Jan 1971                               │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:HH:mm:ss.f}       │ 21:30:03.0                               │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:dd MMM HH:mm:ss}  │ 05 Jan 21:30:03                          │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:\Mon\t\h\: M}     │ Month: 1                                 │
// │ date_time {1971, 1, 5, 21, 30, 3}     │ {:HH:mm:ss.ffffzzz} │ 21:30:03.0000+01:00                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {}                  │ 1/5/1971 21:30                           │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:d}                │ 1/5/1971                                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:D}                │ Tuesday, January 5, 1971                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:f}                │ Tuesday, January 5, 1971 21:30           │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:F}                │ Tuesday, January 5, 1971 21:30:03        │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:g}                │ 1/5/1971 21:30                           │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:G}                │ 1/5/1971 21:30:03                        │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:m}                │ January 5                                │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:M}                │ January 5                                │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:o}                │ 1971-01-05T21:30:03.0420000Z             │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:O}                │ 1971-01-05T21:30:03.0420000Z             │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:r}                │ Tue, 05 Jan 1971 21:30:03 G1T            │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:R}                │ Tue, 05 Jan 1971 21:30:03 G1T            │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:s}                │ 1971-01-05T21:30:03                      │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:t}                │ 21:30                                    │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:T}                │ 21:30:03                                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:u}                │ 1971-01-05 21:30:03Z                     │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:U}                │ Tuesday, January 5, 1971 21:30:03        │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:y}                │ January 1971                             │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:Y}                │ January 1971                             │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:h:mm:ss.ff t}     │ 9:30:03.04 P                             │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:d MMM yyyy}       │ 5 Jan 1971                               │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:HH:mm:ss.f}       │ 21:30:03.0                               │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:dd MMM HH:mm:ss}  │ 05 Jan 21:30:03                          │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:\Mon\t\h\: M}     │ Month: 1                                 │
// │ date_time {1971, 1, 5, 21, 30, 3, 42} │ {:HH:mm:ss.ffffzzz} │ 21:30:03.0420+01:00                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time::now()                      │ {}                  │ 10/2/2025 21:32                          │
// │ date_time::now()                      │ {:d}                │ 10/2/2025                                │
// │ date_time::now()                      │ {:D}                │ Thursday, October 2, 2025                │
// │ date_time::now()                      │ {:f}                │ Thursday, October 2, 2025 21:32          │
// │ date_time::now()                      │ {:F}                │ Thursday, October 2, 2025 21:32:14       │
// │ date_time::now()                      │ {:g}                │ 10/2/2025 21:32                          │
// │ date_time::now()                      │ {:G}                │ 10/2/2025 21:32:14                       │
// │ date_time::now()                      │ {:m}                │ October 2                                │
// │ date_time::now()                      │ {:M}                │ October 2                                │
// │ date_time::now()                      │ {:o}                │ 2025-10-02T21:32:14.6527690+02:00        │
// │ date_time::now()                      │ {:O}                │ 2025-10-02T21:32:14.6527690+02:00        │
// │ date_time::now()                      │ {:r}                │ Thu, 02 Oct 2025 21:32:14 G10T           │
// │ date_time::now()                      │ {:R}                │ Thu, 02 Oct 2025 21:32:14 G10T           │
// │ date_time::now()                      │ {:s}                │ 2025-10-02T21:32:14                      │
// │ date_time::now()                      │ {:t}                │ 21:32                                    │
// │ date_time::now()                      │ {:T}                │ 21:32:14                                 │
// │ date_time::now()                      │ {:u}                │ 2025-10-02 21:32:14Z                     │
// │ date_time::now()                      │ {:U}                │ Thursday, October 2, 2025 21:32:14       │
// │ date_time::now()                      │ {:y}                │ October 2025                             │
// │ date_time::now()                      │ {:Y}                │ October 2025                             │
// │ date_time::now()                      │ {:h:mm:ss.ff t}     │ 9:32:14.65 P                             │
// │ date_time::now()                      │ {:d MMM yyyy}       │ 2 Oct 2025                               │
// │ date_time::now()                      │ {:HH:mm:ss.f}       │ 21:32:14.6                               │
// │ date_time::now()                      │ {:dd MMM HH:mm:ss}  │ 02 Oct 21:32:14                          │
// │ date_time::now()                      │ {:\Mon\t\h\: M}     │ Month: 10                                │
// │ date_time::now()                      │ {:HH:mm:ss.ffffzzz} │ 21:32:14.6527+02:00                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time::utc_now()                  │ {}                  │ 10/2/2025 19:32                          │
// │ date_time::utc_now()                  │ {:d}                │ 10/2/2025                                │
// │ date_time::utc_now()                  │ {:D}                │ Thursday, October 2, 2025                │
// │ date_time::utc_now()                  │ {:f}                │ Thursday, October 2, 2025 19:32          │
// │ date_time::utc_now()                  │ {:F}                │ Thursday, October 2, 2025 19:32:14       │
// │ date_time::utc_now()                  │ {:g}                │ 10/2/2025 19:32                          │
// │ date_time::utc_now()                  │ {:G}                │ 10/2/2025 19:32:14                       │
// │ date_time::utc_now()                  │ {:m}                │ October 2                                │
// │ date_time::utc_now()                  │ {:M}                │ October 2                                │
// │ date_time::utc_now()                  │ {:o}                │ 2025-10-02T19:32:14.6541510Z             │
// │ date_time::utc_now()                  │ {:O}                │ 2025-10-02T19:32:14.6541510Z             │
// │ date_time::utc_now()                  │ {:r}                │ Thu, 02 Oct 2025 19:32:14 G10T           │
// │ date_time::utc_now()                  │ {:R}                │ Thu, 02 Oct 2025 19:32:14 G10T           │
// │ date_time::utc_now()                  │ {:s}                │ 2025-10-02T19:32:14                      │
// │ date_time::utc_now()                  │ {:t}                │ 19:32                                    │
// │ date_time::utc_now()                  │ {:T}                │ 19:32:14                                 │
// │ date_time::utc_now()                  │ {:u}                │ 2025-10-02 19:32:14Z                     │
// │ date_time::utc_now()                  │ {:U}                │ Thursday, October 2, 2025 19:32:14       │
// │ date_time::utc_now()                  │ {:y}                │ October 2025                             │
// │ date_time::utc_now()                  │ {:Y}                │ October 2025                             │
// │ date_time::utc_now()                  │ {:h:mm:ss.ff t}     │ 7:32:14.65 P                             │
// │ date_time::utc_now()                  │ {:d MMM yyyy}       │ 2 Oct 2025                               │
// │ date_time::utc_now()                  │ {:HH:mm:ss.f}       │ 19:32:14.6                               │
// │ date_time::utc_now()                  │ {:dd MMM HH:mm:ss}  │ 02 Oct 19:32:14                          │
// │ date_time::utc_now()                  │ {:\Mon\t\h\: M}     │ Month: 10                                │
// │ date_time::utc_now()                  │ {:HH:mm:ss.ffffzzz} │ 19:32:14.6541+00:00                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time::min_value                  │ {}                  │ 1/1/0001 00:00                           │
// │ date_time::min_value                  │ {:d}                │ 1/1/0001                                 │
// │ date_time::min_value                  │ {:D}                │ Monday, January 1, 0001                  │
// │ date_time::min_value                  │ {:f}                │ Monday, January 1, 0001 00:00            │
// │ date_time::min_value                  │ {:F}                │ Monday, January 1, 0001 00:00:00         │
// │ date_time::min_value                  │ {:g}                │ 1/1/0001 00:00                           │
// │ date_time::min_value                  │ {:G}                │ 1/1/0001 00:00:00                        │
// │ date_time::min_value                  │ {:m}                │ January 1                                │
// │ date_time::min_value                  │ {:M}                │ January 1                                │
// │ date_time::min_value                  │ {:o}                │ 0001-01-01T00:00:00.0000000Z             │
// │ date_time::min_value                  │ {:O}                │ 0001-01-01T00:00:00.0000000Z             │
// │ date_time::min_value                  │ {:r}                │ Mon, 01 Jan 0001 00:00:00 G1T            │
// │ date_time::min_value                  │ {:R}                │ Mon, 01 Jan 0001 00:00:00 G1T            │
// │ date_time::min_value                  │ {:s}                │ 0001-01-01T00:00:00                      │
// │ date_time::min_value                  │ {:t}                │ 00:00                                    │
// │ date_time::min_value                  │ {:T}                │ 00:00:00                                 │
// │ date_time::min_value                  │ {:u}                │ 0001-01-01 00:00:00Z                     │
// │ date_time::min_value                  │ {:U}                │ Monday, January 1, 0001 00:00:00         │
// │ date_time::min_value                  │ {:y}                │ January 0001                             │
// │ date_time::min_value                  │ {:Y}                │ January 0001                             │
// │ date_time::min_value                  │ {:h:mm:ss.ff t}     │ 0:00:00.00 A                             │
// │ date_time::min_value                  │ {:d MMM yyyy}       │ 1 Jan 0001                               │
// │ date_time::min_value                  │ {:HH:mm:ss.f}       │ 00:00:00.0                               │
// │ date_time::min_value                  │ {:dd MMM HH:mm:ss}  │ 01 Jan 00:00:00                          │
// │ date_time::min_value                  │ {:\Mon\t\h\: M}     │ Month: 1                                 │
// │ date_time::min_value                  │ {:HH:mm:ss.ffffzzz} │ 00:00:00.0000+00:17                      │
// ├───────────────────────────────────────┼─────────────────────┼──────────────────────────────────────────┤
// │ date_time::max_value                  │ {}                  │ 12/31/9999 23:59                         │
// │ date_time::max_value                  │ {:d}                │ 12/31/9999                               │
// │ date_time::max_value                  │ {:D}                │ Friday, December 31, 9999                │
// │ date_time::max_value                  │ {:f}                │ Friday, December 31, 9999 23:59          │
// │ date_time::max_value                  │ {:F}                │ Friday, December 31, 9999 23:59:59       │
// │ date_time::max_value                  │ {:g}                │ 12/31/9999 23:59                         │
// │ date_time::max_value                  │ {:G}                │ 12/31/9999 23:59:59                      │
// │ date_time::max_value                  │ {:m}                │ December 31                              │
// │ date_time::max_value                  │ {:M}                │ December 31                              │
// │ date_time::max_value                  │ {:o}                │ 9999-12-31T23:59:59.9999999Z             │
// │ date_time::max_value                  │ {:O}                │ 9999-12-31T23:59:59.9999999Z             │
// │ date_time::max_value                  │ {:r}                │ Fri, 31 Dec 9999 23:59:59 G12T           │
// │ date_time::max_value                  │ {:R}                │ Fri, 31 Dec 9999 23:59:59 G12T           │
// │ date_time::max_value                  │ {:s}                │ 9999-12-31T23:59:59                      │
// │ date_time::max_value                  │ {:t}                │ 23:59                                    │
// │ date_time::max_value                  │ {:T}                │ 23:59:59                                 │
// │ date_time::max_value                  │ {:u}                │ 9999-12-31 23:59:59Z                     │
// │ date_time::max_value                  │ {:U}                │ Friday, December 31, 9999 23:59:59       │
// │ date_time::max_value                  │ {:y}                │ December 9999                            │
// │ date_time::max_value                  │ {:Y}                │ December 9999                            │
// │ date_time::max_value                  │ {:h:mm:ss.ff t}     │ 11:59:59.99 P                            │
// │ date_time::max_value                  │ {:d MMM yyyy}       │ 31 Dec 9999                              │
// │ date_time::max_value                  │ {:HH:mm:ss.f}       │ 23:59:59.9                               │
// │ date_time::max_value                  │ {:dd MMM HH:mm:ss}  │ 31 Dec 23:59:59                          │
// │ date_time::max_value                  │ {:\Mon\t\h\: M}     │ Month: 12                                │
// │ date_time::max_value                  │ {:HH:mm:ss.ffffzzz} │ 23:59:59.9999+01:00                      │
// └───────────────────────────────────────┴─────────────────────┴──────────────────────────────────────────┘
