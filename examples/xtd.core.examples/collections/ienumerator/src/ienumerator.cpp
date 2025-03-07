#include <xtd/collections/array_list>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;

class program {
public:
  // Simple business object.
  struct person : public object, public iequatable<person>, public icomparable<person> {
  public:
    person(const string& first_name, const string last_name) : first_name {first_name}, last_name {last_name} {}
    
    string first_name;
    string last_name;
    
    int32 compare_to(const person& o) const noexcept override {
      if (first_name == o.first_name && last_name == o.last_name) return 0;
      if (first_name > o.first_name || (first_name == o.first_name && last_name > o.last_name)) return 1;
      return -1;
    }
    bool equals(const object& o) const noexcept override {return is<person>(o) && equals(as<person>(o));}
    bool equals(const person& o) const noexcept override {return compare_to(o) == 0;}
    string to_string() const noexcept override {return string::format("{} {}", first_name, last_name);}
  };
  
  class people_enumerator : public collections::ienumerator {
  private:
    const collections::array_list& people_;
    
    // Enumerators are positioned before the first element until the first xtd::collections::ienumerator::move_next() call.
    size position = collections::array_list::npos;
    
  public:
    people_enumerator(const collections::array_list& list) : people_(list) {}
    
    bool move_next() override {return ++position < people_.count();}
    
    void reset() override {position = collections::array_list::npos;}
    
    const any_object& current() const override {
      if (position >= people_.size()) throw invalid_operation_exception {};
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
