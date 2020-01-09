#include <xtd/xtd.delegates>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd;

//using printer = delegate<void()>;
using printer = function<void()>;

void print_hello_world() {
  cout << "Hello, world!" << endl;
}

printer&& create_delegate() {
  printer item = {print_hello_world};
  //return item;
  //return std::forward<printer>(item);
  return std::move(item);
}

int main() {
  printer d1 = create_delegate();
  d1();
}
