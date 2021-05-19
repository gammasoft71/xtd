#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

std::function<bool(int32_t)> user_cancel_callback;

void register_user_cancel_callback(std::function<bool(int32_t)> user_cancel_callback) {
  ::user_cancel_callback = user_cancel_callback;
}

int main() {
  console::write_line("Hello, Wolrd!");
  register_user_cancel_callback([](int v) {return v == 42;});
  console::write_line(user_cancel_callback ? user_cancel_callback(24) : false);
}
