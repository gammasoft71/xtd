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
  
  // Collection of person objects. This class implements xtd::collections::ienumerable so that it can be used with for each syntax.
  class people : public ienumerable {
  private:
    array_list people_;
    
  public:
    people(const array<person>& p_array) {
      people_ = array_list(p_array.size());
      
      for (auto i = 0_z; i < p_array.size(); ++i)
        people_[i] = p_array[i];
    }
    
    // Implementation for the xtd::collections::ienumerable::get_enumerator method.
    enumerator get_enumerator() const noexcept override {
      return enumerator {new_ptr<people_enumerator>(people_)};
    }
  };
  
  // When you implement xtd::collections::ienumerable, you must also implement xtd::collections::ienumerator.
  class people_enumerator : public ienumerator {
  private:
    const array_list& people_;

    // Enumerators are positioned before the first element until the first xtd::collections::ienumerator::move_next() call.
    size position = array_list::npos;
    
  public:
    people_enumerator(const array_list& list) : people_(list) {}
    
    bool move_next() override {return ++position < people_.count();}
    
    void reset() override {position = array_list::npos;}
    
    const any_object& current() const override {
      if (position >= people_.size()) throw invalid_operation_exception {csf_};
      return people_[position];
    }
  };

  static auto main() -> void {
    auto people_array = xtd::array<person> {
      person {"John", "Smith"},
      person {"Jim", "Johnson"},
      person {"Sue", "Rabon"},
    };
    
    auto people_list = people {people_array};
    for (auto person : people_list)
      console::write_line(person);
  }
};

startup_(program::main);


// This code produces the following output :
//
// John Smith
// Jim Johnson
// Sue Rabon
