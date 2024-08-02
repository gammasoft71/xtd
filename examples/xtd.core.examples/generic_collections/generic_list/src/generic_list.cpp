#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

// Simple business object. A part_id is used to identify a part
// but the part name be different for the same Id.
class part : public object, public iequatable<part> {
public:
  ustring part_name;
  int part_id = 0;
  
  part() = default;
  part(const ustring& name, int id) : part_name {name}, part_id {id} {}
  
  ustring to_string() const noexcept override {return ustring::format("ID: {}   Name: {}", part_id, part_name);}

  bool equals(const object& obj) const noexcept override {return is<part>(obj) && equals(as<part>(obj));}
  bool equals(const part& other) const noexcept override {return part_id == other.part_id;}
  
  size get_hash_code() const noexcept override {return object::get_hash_code();}

  // Should also override == and != operators.
};

class example {
public:
  static auto main() -> void {
    auto parts = list<part> {};
    
    console::write_line("\ncapacity: {0}", parts.capacity());
    
    parts.add(part {"crank arm", 1234});
    parts.add(part {"chain ring", 1334});
    parts.add(part {"seat", 1434});
    parts.add(part {"cassette", 1534});
    parts.add(part {"shift lever", 1634});
    
    console::write_line();
    for (auto part : parts)
      console::write_line(part);

    console::write_line("\ncapacity: {0}", parts.capacity());
    console::write_line("count: {0}", parts.count());
    
    parts.trim_excess();
    console::write_line("\ntrim_excess()");
    console::write_line("capacity: {0}", parts.capacity());
    console::write_line("count: {0}", parts.count());
    
    parts.clear();
    console::write_line("\nclear()");
    console::write_line("capacity: {0}", parts.capacity());
    console::write_line("count: {0}", parts.count());
  }
};

startup_(example::main);

// This code can produces the following output :
//
// capacity: 0
//
// ID: 1234   Name: crank arm
// ID: 1334   Name: chain ring
// ID: 1434   Name: seat
// ID: 1534   Name: cassette
// ID: 1634   Name: shift lever
//
// capacity: 8
// count: 5
//
// trim_excess()
// capacity: 5
// count: 5
//
// clear()
// capacity: 5
// count: 0
