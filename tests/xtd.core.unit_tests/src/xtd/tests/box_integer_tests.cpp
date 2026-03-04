#include <xtd/box_integer>
#include <xtd/tunit/assert>
#include <xtd/tunit/generic_test_class>
#include <xtd/tunit/test_method_attribute>

namespace xtd::tests {
  generic_test_class_(box_integer_typeests, char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long long, sbyte, int16, int32, int64, intptr, ptrdiff, size, byte, uint16, uint32, uint64, uintptr) {
    auto test_method_(box_type_type) {
      assert::is_instance_of<box<type_t>>(box_integer<type_t> {});
    }
    
    auto test_method_(value_type) {
      assert::are_equal(typeof_<type_t>(), typeof_<typename box_integer<type_t>::value_type>());
    }
    
    auto test_method_(reference) {
      assert::are_equal(typeof_<type_t&>(), typeof_<typename box_integer<type_t>::reference>());
    }
    
    auto test_method_(const_reference) {
      assert::are_equal(typeof_<const type_t&>(), typeof_<typename box_integer<type_t>::const_reference>());
    }
    
    auto test_method_(pointer) {
      assert::are_equal(typeof_<type_t*>(), typeof_<typename box_integer<type_t>::pointer>());
    }
    
    auto test_method_(const_pointer) {
      assert::are_equal(typeof_<const type_t*>(), typeof_<typename box_integer<type_t>::const_pointer>());
    }

    auto test_method_(default_constructor) {
      assert::are_equal(type_t {0}, box_integer<type_t> {}.value);
    }

    auto test_method_(constructor_with_type) {
      assert::are_equal(type_t {0}, box_integer<type_t> {0}.value);
      assert::are_equal(type_t {42}, box_integer<type_t> {42}.value);
    }

    auto test_method_(copy_constructor) {
      assert::are_equal(type_t {0}, box_integer<type_t> {box_integer<type_t> {0}}.value);
      assert::are_equal(type_t {42}, box_integer<type_t> {box_integer<type_t> {42}}.value);
    }
    
    auto test_method_(move_constructor) {
      auto o = box_integer<type_t> {42};
      assert::are_equal(type_t {42}, box_integer<type_t> {std::move(o)}.value);
    }

    auto test_method_(copy_operator) {
      auto o1 = box_integer<type_t> {42};
      auto o2 = box_integer<type_t> {};
      o2 = o1;
      assert::are_equal(type_t {42}, o2.value);
    }
    
    auto test_method_(move_operator) {
      auto o1 = box_integer<type_t> {42};
      auto o2 = box_integer<type_t> {};
      o2 = std::move(o1);
      assert::are_equal(type_t {42}, o2.value);
    }

    auto test_method_(max_value) {
      assert::are_equal(std::numeric_limits<type_t>::max(), box_integer<type_t>::max_value);
    }
    
    auto test_method_(min_value) {
      assert::are_equal(std::numeric_limits<type_t>::lowest(), box_integer<type_t>::min_value);
    }

    auto test_method_(value_get) {
      assert::are_equal(type_t {0}, box_integer<type_t> {}.value);
      assert::are_equal(type_t {0}, box_integer<type_t> {0}.value);
      assert::are_equal(type_t {42}, box_integer<type_t> {42}.value);
    }
    
    auto test_method_(value_set) {
      auto o = box_integer<type_t> {};
      assert::are_equal(type_t {0}, o.value);
      o.value = 42;
      assert::are_equal(type_t {42}, o.value);
      o.value = 120;
      assert::are_equal(type_t {120}, o.value);
    }

    auto test_method_(operator_value_type) {
      auto v = box_integer<type_t> {}.value;
      assert::are_equal(type_t {0}, v);
      v = box_integer<type_t> {42}.value;
      assert::are_equal(type_t {42}, v);
      v = box_integer<type_t> {120}.value;
      assert::are_equal(type_t {120}, v);
    }
    
    auto test_method_(compare_to) {
      assert::is_zero(box_integer<type_t> {5}.compare_to(box_integer<type_t> {5}));
      assert::is_negative(box_integer<type_t> {4}.compare_to(box_integer<type_t> {5}));
      assert::is_positive(box_integer<type_t> {5}.compare_to(box_integer<type_t> {4}));
    }
    
    auto test_method_(less_operator) {
      assert::is_false(box_integer<type_t> {5} < box_integer<type_t> {5});
      assert::is_true(box_integer<type_t> {4} < box_integer<type_t> {5});
      assert::is_false(box_integer<type_t> {5} < box_integer<type_t> {4});
    }
    
    auto test_method_(less_or_equal_operator) {
      assert::is_true(box_integer<type_t> {5} <= box_integer<type_t> {5});
      assert::is_true(box_integer<type_t> {4} <= box_integer<type_t> {5});
      assert::is_false(box_integer<type_t> {5} <= box_integer<type_t> {4});
    }
  };
}
