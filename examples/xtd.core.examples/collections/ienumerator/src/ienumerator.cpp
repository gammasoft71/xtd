#include <xtd/xtd>

class program {
public:
  // Simple business object.
  struct person : public object, public iequatable<person>, public icomparable<person> {
  public:
    person(const string& first_name, const string last_name) : first_name {first_name}, last_name {last_name} {}
    
    string first_name;
    string last_name;
    
    auto compare_to(const person& o) const noexcept -> int32 override {
      if (first_name == o.first_name && last_name == o.last_name) return 0;
      if (first_name > o.first_name || (first_name == o.first_name && last_name > o.last_name)) return 1;
      return -1;
    }
    auto equals(const object& o) const noexcept -> bool override {return is<person>(o) && equals(as<person>(o));}
    auto equals(const person& o) const noexcept -> bool  override {return compare_to(o) == 0;}
    auto to_string() const noexcept -> string override {return string::format("{} {}", first_name, last_name);}
  };
  
  class people_enumerator : public collections::ienumerator {
  private:
    const collections::array_list& people_;
    
    // Enumerators are positioned before the first element until the first xtd::collections::ienumerator::move_next() call.
    size position = collections::array_list::npos;
    
  public:
    people_enumerator(const collections::array_list& list) : people_(list) {}
    
    auto move_next() -> bool override {return ++position < people_.count();}
    
    auto reset() -> void override {position = collections::array_list::npos;}
    
    auto current() const -> const any_object& override {
      if (position >= people_.count()) throw invalid_operation_exception {};
      return people_[position];
    }
  };
  
  static auto main() -> void {
    auto people_array = collections::array_list {
      person {"John", "Smith"},
      person {"Jim", "Johnson"},
      person {"Sue", "Rabon"},
    };
    
    auto enumerator = people_enumerator {people_array};
    while (enumerator.move_next())
      console::write_line(enumerator.current());
  }
};

startup_(program::main);


// This code produces the following output :
//
// John Smith
// Jim Johnson
// Sue Rabon
