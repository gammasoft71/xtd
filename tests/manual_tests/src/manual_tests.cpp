#include <xtd/console>

using namespace std;
using namespace xtd;

// The main entry point for the application.
int main() {
  console_key_info cki;
  console::out << "cki = " << (int)cki.key() << endl;
}
