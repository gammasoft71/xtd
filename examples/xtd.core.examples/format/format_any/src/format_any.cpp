#include <xtd/xtd>

using namespace std;
using namespace xtd;

class character {
public:
  character(const ustring& name, const ustring& rank) noexcept : name_(name), rank_(rank) {}

  const ustring& name() const noexcept {return name_;}
  const ustring& rank() const noexcept {return rank_;}
  
  ustring to_string() const noexcept {return name_ + " (" + rank_ + ")";}
  
private:
  ustring name_;
  ustring rank_;
};

int main() {
  any value = make_any<int>(42);
  cout << ustring::format("{}", value) << endl;

  value = make_any<ustring>("Star Trek: The Next Generation");
  cout << ustring::format("{}", value) << endl;

  value = character("Jean-Luc Picard", "Captain");
  cout << ustring::format("{}", value) << endl;

  register_any_stringer<character>([](character value) {return value.to_string();});
  cout << ustring::format("{}", value) << endl;
}

// This code produces the following output :
//
