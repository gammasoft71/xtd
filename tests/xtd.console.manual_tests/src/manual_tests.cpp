#include <atomic>
#include <xtd/xtd.console>

using namespace std;
using namespace xtd;
using namespace std::string_literals;

// The main entry point for the application.
int main() {
  //cout << format("{}, {}!", "Hello", "World"s) << endl;
  double denominator = 1;
  double pi = 0;
  int counter = 1;

  while (!console::key_available()) {
    if (counter % 2) pi += 4.0 / denominator;
    else pi -= 4.0 / denominator;
    console::write_line("{:D} - pi = {:F20}", counter, pi);
    console::out.flush();
    denominator += 2;
    counter++;
  }
}
