#include <xtd/xtd>

struct order_order_line : public object, public iequatable<order_order_line> {
public:
  order_order_line() = default;
  order_order_line(int order_id, int order_line_id) : order_id_ {order_id}, order_line_id_ {order_line_id} {}
  
  auto order_id() const noexcept -> int {return order_id_;}
  auto order_line_id() const noexcept -> int {return order_line_id_;}
  
  auto equals(const object& obj) const noexcept -> bool override {return is<order_order_line>(obj) && equals(as<order_order_line>(obj));}
  auto equals(const order_order_line& other) const noexcept -> bool override {return order_id_ == other.order_id_ && order_line_id_ == other.order_line_id_;}
  
  auto get_hash_code() const noexcept -> usize override {return hash_code::combine(order_id_, order_line_id_);}
  
private:
  int order_id_ = 0;
  int order_line_id_ = 0;
};

auto main() -> int {
  auto set = hash_set<order_order_line> {
    order_order_line {1, 1},
    order_order_line {1, 1},
    order_order_line {1, 2}
  };
  
  console::write_line("Item count: {}.", set.count());
}

// This code produces the following output :
//
// Item count: 2.
