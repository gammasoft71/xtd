#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  auto date_time = std::chrono::system_clock::now();
  // Instead previous line you can use following lines :
  // auto t = std::time(nullptr);
  // auto date_time = *std::localtime(&t);

  cout << ustring::format("{}", date_time) << endl;
  cout << ustring::format("{:d}", date_time) << endl;
  cout << ustring::format("{:D}", date_time) << endl;
  cout << ustring::format("{:t}", date_time) << endl;
  cout << ustring::format("{:T}", date_time) << endl;
  cout << ustring::format("{:f}", date_time) << endl;
  cout << ustring::format("{:F}", date_time) << endl;
  cout << ustring::format("{:g}", date_time) << endl;
  cout << ustring::format("{:G}", date_time) << endl;
  //cout << ustring::format("{0:h} {0:i} {0:j} {0:l}", date_time) << endl;
  //cout << ustring::format("{0:H} {0:I} {0:J} {0:L}", date_time) << endl;
  //cout << ustring::format("{:i}/{0:k}/{0:l}", date_time) << endl;
  //cout << ustring::format("{:I}/{0:K}/{0:L}", date_time) << endl;
  cout << ustring::format("{:h}", date_time) << endl;
  cout << ustring::format("{:H}", date_time) << endl;
  cout << ustring::format("{:i}", date_time) << endl;
  cout << ustring::format("{:I}", date_time) << endl;
  cout << ustring::format("{:j}", date_time) << endl;
  cout << ustring::format("{:J}", date_time) << endl;
  cout << ustring::format("{:k}", date_time) << endl;
  cout << ustring::format("{:K}", date_time) << endl;
  cout << ustring::format("{:l}", date_time) << endl;
  cout << ustring::format("{:L}", date_time) << endl;
  cout << ustring::format("{:m}", date_time) << endl;
  cout << ustring::format("{:M}", date_time) << endl;
  cout << ustring::format("{:n}", date_time) << endl;
  cout << ustring::format("{:n}", date_time) << endl;
  cout << ustring::format("{:O}", date_time) << endl;
  cout << ustring::format("{:s}", date_time) << endl;
  cout << ustring::format("{:t}", date_time) << endl;
  cout << ustring::format("{:T}", date_time) << endl;
  cout << ustring::format("{:u}", date_time) << endl;
  cout << ustring::format("{:U}", date_time) << endl;
  cout << ustring::format("{:v}", date_time) << endl;
  cout << ustring::format("{:V}", date_time) << endl;
  cout << ustring::format("{:y}", date_time) << endl;
  cout << ustring::format("{:Y}", date_time) << endl;
  cout << ustring::format("{:z}", date_time) << endl;
  cout << ustring::format("{:Z}", date_time) << endl;
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
