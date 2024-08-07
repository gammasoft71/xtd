#include <xtd/collections/array_list>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::collections;

class program {
public:
  // Simple business object.
  struct person : public object, public iequatable<person>, public icomparable<person> {
  public:
    person(const ustring& first_name, const ustring last_name) : first_name {first_name}, last_name {last_name} {}
    
    ustring first_name;
    ustring last_name;

    int32 compare_to(const person& o) const noexcept override {
      if (first_name == o.first_name && last_name == o.last_name) return 0;
      if (first_name > o.first_name || (first_name == o.first_name && last_name > o.last_name)) return 1;
      return -1;
    }
    bool equals(const object& o) const noexcept override {return is<person>(o) && equals(as<person>(o));}
    bool equals(const person& o) const noexcept override {return compare_to(o) == 0;}
    ustring to_string() const noexcept override {return ustring::format("{} {}", first_name, last_name);}
  };
  
  // Collection of person objects. This class
  // implements IEnumerable so that it can be used
  // with ForEach syntax.
  class people : public ienumerable {
  private:
    array_list people_;
    
  public:
    people(const array<person>& p_array) {
      people_ = array_list(p_array.size());
      
      for (auto i = 0_z; i < p_array.size(); ++i)
        people_[i] = p_array[i];
    }
    
    // Implementation for the GetEnumerator method.
    enumerator get_enumerator() const noexcept override {
      return people_.get_enumerator();
    }
  };

  static auto main() -> void {
    auto people_array = xtd::array<person> {
      person {"John", "Smith"},
      person {"Jim", "Johnson"},
      person {"Sue", "Rabon"},
    };
    
    auto people_list = people {people_array};
    auto people_enum = people_list.get_enumerator();
    while (people_enum.move_next())
      console::write_line(people_enum.current());
  }
};

startup_(program::main);


// This code can produces the following output :
//
// John Smith
// Jim Johnson
// Sue Rabon
