#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

int main() {
  console::write_line("nameof=\"{}\", sizeof(int32)=\"{}\"", nameof_(int32), sizeof(int32));
  console::write_line("nameof=\"{}\", sizeof(int)=\"{}\"", nameof_(int), sizeof(int));
  console::write_line();
  console::write_line("nameof=\"{}\", sizeof(int64)=\"{}\"", nameof_(int64), sizeof(int64));
  console::write_line("nameof=\"{}\", sizeof(long long int)=\"{}\"", nameof_(long long int), sizeof(long long int));
  console::write_line();
  console::write_line("nameof=\"{}\", sizeof(slong)=\"{}\"", nameof_(slong), sizeof(slong));
  console::write_line("nameof=\"{}\", sizeof(long)=\"{}\"", nameof_(long), sizeof(long));
  console::write_line();
  console::write_line("nameof=\"{}\", sizeof(slong)=\"{}\"", nameof_(xtd::ulong), sizeof(xtd::ulong));
  console::write_line("nameof=\"{}\", sizeof(unsigned long)=\"{}\"", nameof_(unsigned long), sizeof(unsigned long));
}

// This code produces the following output for a consome application:
//
// target_type="console application"
// target_type="console application"
