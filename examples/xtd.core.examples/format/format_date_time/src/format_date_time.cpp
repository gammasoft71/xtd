#include <xtd/console>
#include <xtd/date_time>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  auto date_time = std::chrono::system_clock::now();
  // Instead previous line you can use following lines :
  // auto t = std::time(nullptr);
  // auto date_time = *std::localtime(&t);
  
  console::out << ustring::format("{}", date_time) << environment::new_line;
  console::out << ustring::format("{:d}", date_time) << environment::new_line;
  console::out << ustring::format("{:D}", date_time) << environment::new_line;
  console::out << ustring::format("{:t}", date_time) << environment::new_line;
  console::out << ustring::format("{:T}", date_time) << environment::new_line;
  console::out << ustring::format("{:f}", date_time) << environment::new_line;
  console::out << ustring::format("{:F}", date_time) << environment::new_line;
  console::out << ustring::format("{:g}", date_time) << environment::new_line;
  console::out << ustring::format("{:G}", date_time) << environment::new_line;
  //console::out << ustring::format("{0:h} {0:i} {0:j} {0:l}", date_time) << environment::new_line;
  //console::out << ustring::format("{0:H} {0:I} {0:J} {0:L}", date_time) << environment::new_line;
  //console::out << ustring::format("{:i}/{0:k}/{0:l}", date_time) << environment::new_line;
  //console::out << ustring::format("{:I}/{0:K}/{0:L}", date_time) << environment::new_line;
  console::out << ustring::format("{:h}", date_time) << environment::new_line;
  console::out << ustring::format("{:H}", date_time) << environment::new_line;
  console::out << ustring::format("{:i}", date_time) << environment::new_line;
  console::out << ustring::format("{:I}", date_time) << environment::new_line;
  console::out << ustring::format("{:j}", date_time) << environment::new_line;
  console::out << ustring::format("{:J}", date_time) << environment::new_line;
  console::out << ustring::format("{:k}", date_time) << environment::new_line;
  console::out << ustring::format("{:K}", date_time) << environment::new_line;
  console::out << ustring::format("{:l}", date_time) << environment::new_line;
  console::out << ustring::format("{:L}", date_time) << environment::new_line;
  console::out << ustring::format("{:m}", date_time) << environment::new_line;
  console::out << ustring::format("{:M}", date_time) << environment::new_line;
  console::out << ustring::format("{:n}", date_time) << environment::new_line;
  console::out << ustring::format("{:n}", date_time) << environment::new_line;
  console::out << ustring::format("{:O}", date_time) << environment::new_line;
  console::out << ustring::format("{:s}", date_time) << environment::new_line;
  console::out << ustring::format("{:t}", date_time) << environment::new_line;
  console::out << ustring::format("{:T}", date_time) << environment::new_line;
  console::out << ustring::format("{:u}", date_time) << environment::new_line;
  console::out << ustring::format("{:U}", date_time) << environment::new_line;
  console::out << ustring::format("{:v}", date_time) << environment::new_line;
  console::out << ustring::format("{:V}", date_time) << environment::new_line;
  console::out << ustring::format("{:y}", date_time) << environment::new_line;
  console::out << ustring::format("{:Y}", date_time) << environment::new_line;
  console::out << ustring::format("{:z}", date_time) << environment::new_line;
  console::out << ustring::format("{:Z}", date_time) << environment::new_line;
}

// This code can be produce the following output :
//
// Sat Jan  2 03:04:05 2021
// 01/02/2021
// 1/02/2021
// 03:04:05
// 3:04:05
// Sat Jan  2 03:04:05 2021
// Sat Jan  2 03:04:05 2021
// Sat Jan  2 03:04:05 2021
// Sat Jan  2 03:04:05 2021
// Sat
// Saturday
// 02
// 2
// Jan
// January
// 01
// 1
// 21
// 2021
// January 2
// January 2
// Saturday, 2 January 2021
// Saturday, 2 January 2021
// 2 January 2021
// 2021-01-02T03:04:05
// 03:04:05
// 3:04:05
// 2021-01-02 03:04:05
// Saturday, 2 January 2021 3:04:05
// 03:04
// 3:04
// January 21
// January 2021
// CET
// CET
