#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  auto date_time = std::chrono::system_clock::now();
  // Instead previous line you can use following lines :
  // auto t = std::time(nullptr);
  // auto date_time = *std::localtime(&t);

  cout << strings::format("{}", date_time) << endl;
  cout << strings::format("{:d}", date_time) << endl;
  cout << strings::format("{:D}", date_time) << endl;
  cout << strings::format("{:t}", date_time) << endl;
  cout << strings::format("{:T}", date_time) << endl;
  cout << strings::format("{:f}", date_time) << endl;
  cout << strings::format("{:F}", date_time) << endl;
  cout << strings::format("{:g}", date_time) << endl;
  cout << strings::format("{:G}", date_time) << endl;
  //cout << strings::format("{0:h} {0:i} {0:j} {0:l}", date_time) << endl;
  //cout << strings::format("{0:H} {0:I} {0:J} {0:L}", date_time) << endl;
  //cout << strings::format("{:i}/{0:k}/{0:l}", date_time) << endl;
  //cout << strings::format("{:I}/{0:K}/{0:L}", date_time) << endl;
  cout << strings::format("{:h}", date_time) << endl;
  cout << strings::format("{:H}", date_time) << endl;
  cout << strings::format("{:i}", date_time) << endl;
  cout << strings::format("{:I}", date_time) << endl;
  cout << strings::format("{:j}", date_time) << endl;
  cout << strings::format("{:J}", date_time) << endl;
  cout << strings::format("{:k}", date_time) << endl;
  cout << strings::format("{:K}", date_time) << endl;
  cout << strings::format("{:l}", date_time) << endl;
  cout << strings::format("{:L}", date_time) << endl;
  cout << strings::format("{:m}", date_time) << endl;
  cout << strings::format("{:M}", date_time) << endl;
  cout << strings::format("{:n}", date_time) << endl;
  cout << strings::format("{:n}", date_time) << endl;
  cout << strings::format("{:O}", date_time) << endl;
  cout << strings::format("{:s}", date_time) << endl;
  cout << strings::format("{:t}", date_time) << endl;
  cout << strings::format("{:T}", date_time) << endl;
  cout << strings::format("{:u}", date_time) << endl;
  cout << strings::format("{:U}", date_time) << endl;
  cout << strings::format("{:v}", date_time) << endl;
  cout << strings::format("{:V}", date_time) << endl;
  cout << strings::format("{:y}", date_time) << endl;
  cout << strings::format("{:Y}", date_time) << endl;
  cout << strings::format("{:z}", date_time) << endl;
  cout << strings::format("{:Z}", date_time) << endl;
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
