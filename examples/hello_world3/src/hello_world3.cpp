#include <console/console>

using namespace gammasoft;
using namespace std;

// The main entry point for the application.
int main() {
  cout << foreground_color(console_color::blue) << "Hello, World!" << reset_color() << endl;
}
