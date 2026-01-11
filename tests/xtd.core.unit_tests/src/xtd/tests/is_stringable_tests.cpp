#include <xtd/is_stringable>
#include <xtd/fixed_array>
#include <xtd/collections/generic/linked_list>
#include <xtd/collections/generic/hash_set>
#include <xtd/collections/generic/queue>
#include <xtd/collections/generic/stack>
#include <xtd/globalization/translator>
#include <xtd/ranges/views/select.hpp>
#include <xtd/tunit/constraints/assert_that>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#if defined(__xtd__cpp_lib_ranges)
#include <ranges>
#endif

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(is_stringable_tests) {
    auto test_method_(is_stringable_with_object) {
      struct my_object_test : public object {};
      assert_that(is_stringable<my_object_test>).is().true_();
      assert_that(is_stringable < my_object_test && >).is().true_();
      assert_that(is_stringable<my_object_test&>).is().true_();
      assert_that(is_stringable<const my_object_test&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_istringable) {
      struct my_istringable_test : public istringable {
        auto to_string() const noexcept -> string override {return "";}
      };
      assert_that(is_stringable<my_istringable_test>).is().true_();
      assert_that(is_stringable < my_istringable_test && >).is().true_();
      assert_that(is_stringable<my_istringable_test&>).is().true_();
      assert_that(is_stringable<const my_istringable_test&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_iformatable) {
      struct my_iformatable_test : public iformatable {
        auto to_string(const string&, const globalization::culture_info&) const noexcept -> string override {return "";}
      };
      assert_that(is_stringable<my_iformatable_test>).is().true_();
      assert_that(is_stringable < my_iformatable_test && >).is().true_();
      assert_that(is_stringable<my_iformatable_test&>).is().true_();
      assert_that(is_stringable<const my_iformatable_test&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_exception) {
      assert_that(is_stringable<argument_exception>).is().true_();
      assert_that(is_stringable < argument_exception && >).is().true_();
      assert_that(is_stringable<argument_exception&>).is().true_();
      assert_that(is_stringable<const argument_exception&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_enum) {
      enum my_enum_test {};
      assert_that(is_stringable<my_enum_test>).is().true_();
      assert_that(is_stringable < my_enum_test && >).is().true_();
      assert_that(is_stringable<my_enum_test&>).is().true_();
      assert_that(is_stringable<const my_enum_test&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_enum_class) {
      enum class my_enum_class_test {};
      assert_that(is_stringable<my_enum_class_test>).is().true_();
      assert_that(is_stringable < my_enum_class_test && >).is().true_();
      assert_that(is_stringable<my_enum_class_test&>).is().true_();
      assert_that(is_stringable<const my_enum_class_test&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_enum_struct) {
      enum struct my_enum_struct_test {};
      assert_that(is_stringable<my_enum_struct_test>).is().true_();
      assert_that(is_stringable < my_enum_struct_test && >).is().true_();
      assert_that(is_stringable<my_enum_struct_test&>).is().true_();
      assert_that(is_stringable<const my_enum_struct_test&>).is().true_();
    }
    
    #if defined(__xtd__cpp_lib_ranges)
    auto test_method_(is_stringable_with_std_ranges) {
      auto items = array {1, 2, 3, 4, 5} | std::views::transform(delegate_(auto v) {return v * v * v;});
      assert_that(is_stringable<decltype(items)>).is().true_();
      assert_that(is_stringable < decltype(items) && >).is().true_();
      assert_that(is_stringable<decltype(items)&>).is().true_();
      assert_that(is_stringable<const decltype(items)&>).is().true_();
    }
    #endif
    
    auto test_method_(is_stringable_with_xtd_ranges) {
      auto items = array {1, 2, 3, 4, 5} | select(delegate_(auto v) {return v * v * v;});
      assert_that(is_stringable<decltype(items)>).is().true_();
      assert_that(is_stringable < decltype(items) && >).is().true_();
      assert_that(is_stringable<decltype(items)&>).is().true_();
      assert_that(is_stringable<const decltype(items)&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_link) {
      auto items = array {1, 2, 3, 4, 5}.select(delegate_(auto v) {return v * v * v;});
      assert_that(is_stringable<decltype(items)>).is().true_();
      assert_that(is_stringable < decltype(items) && >).is().true_();
      assert_that(is_stringable<decltype(items)&>).is().true_();
      assert_that(is_stringable<const decltype(items)&>).is().true_();
    }
    
    struct my_streamable_test {
      friend auto operator <<(std::ostream& os, const my_streamable_test&) noexcept -> std::ostream& {return os;}
    };
    
    auto test_method_(is_stringable_with_streamble) {
      assert_that(is_stringable<my_streamable_test>).is().true_();
      assert_that(is_stringable < my_streamable_test && >).is().true_();
      assert_that(is_stringable<my_streamable_test&>).is().true_();
      assert_that(is_stringable<const my_streamable_test&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_somes_integrals) {
      assert_that(is_stringable<sbyte>).is().true_();
      assert_that(is_stringable < sbyte && >).is().true_();
      assert_that(is_stringable<sbyte&>).is().true_();
      assert_that(is_stringable<const sbyte&>).is().true_();
      
      assert_that(is_stringable<int16>).is().true_();
      assert_that(is_stringable < int16 && >).is().true_();
      assert_that(is_stringable<int16&>).is().true_();
      assert_that(is_stringable<const int16&>).is().true_();
      
      assert_that(is_stringable<int32>).is().true_();
      assert_that(is_stringable < int32 && >).is().true_();
      assert_that(is_stringable<int32&>).is().true_();
      assert_that(is_stringable<const int32&>).is().true_();
      
      assert_that(is_stringable<int64>).is().true_();
      assert_that(is_stringable < int64 && >).is().true_();
      assert_that(is_stringable<int64&>).is().true_();
      assert_that(is_stringable<const int64&>).is().true_();
      
      assert_that(is_stringable<intptr>).is().true_();
      assert_that(is_stringable < intptr && >).is().true_();
      assert_that(is_stringable<intptr&>).is().true_();
      assert_that(is_stringable<const intptr&>).is().true_();
      
      assert_that(is_stringable<byte>).is().true_();
      assert_that(is_stringable < byte && >).is().true_();
      assert_that(is_stringable<byte&>).is().true_();
      assert_that(is_stringable<const byte&>).is().true_();
      
      assert_that(is_stringable<uint16>).is().true_();
      assert_that(is_stringable < uint16 && >).is().true_();
      assert_that(is_stringable<uint16&>).is().true_();
      assert_that(is_stringable<const uint16&>).is().true_();
      
      assert_that(is_stringable<uint32>).is().true_();
      assert_that(is_stringable < uint32 && >).is().true_();
      assert_that(is_stringable<uint32&>).is().true_();
      assert_that(is_stringable<const uint32&>).is().true_();
      
      assert_that(is_stringable<uint64>).is().true_();
      assert_that(is_stringable < uint64 && >).is().true_();
      assert_that(is_stringable<uint64&>).is().true_();
      assert_that(is_stringable<const uint64&>).is().true_();
      
      assert_that(is_stringable<uintptr>).is().true_();
      assert_that(is_stringable < uintptr && >).is().true_();
      assert_that(is_stringable<uintptr&>).is().true_();
      assert_that(is_stringable<const uintptr&>).is().true_();
      
      assert_that(is_stringable<float>).is().true_();
      assert_that(is_stringable < float&& >).is().true_();
      assert_that(is_stringable<float&>).is().true_();
      assert_that(is_stringable<const float&>).is().true_();
      
      assert_that(is_stringable<double>).is().true_();
      assert_that(is_stringable < double&& >).is().true_();
      assert_that(is_stringable<double&>).is().true_();
      assert_that(is_stringable<const double&>).is().true_();
      
      assert_that(is_stringable<decimal>).is().true_();
      assert_that(is_stringable < decimal && >).is().true_();
      assert_that(is_stringable<decimal&>).is().true_();
      assert_that(is_stringable<const decimal&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_xtd_collections) {
      assert_that(is_stringable<fixed_array<int, 5>>).is().true_();
      assert_that(is_stringable < fixed_array<int, 5>&& >).is().true_();
      assert_that(is_stringable<fixed_array<int, 5>&>).is().true_();
      assert_that(is_stringable<const fixed_array<int, 5>&>).is().true_();
      
      assert_that(is_stringable<array<date_time>>).is().true_();
      assert_that(is_stringable < array<date_time>&& >).is().true_();
      assert_that(is_stringable<array<date_time>&>).is().true_();
      assert_that(is_stringable<const array<date_time>&>).is().true_();
      
      assert_that(is_stringable<list<string>>).is().true_();
      assert_that(is_stringable < list<string>&& >).is().true_();
      assert_that(is_stringable<list<string>&>).is().true_();
      assert_that(is_stringable<const list<string>&>).is().true_();
      
      assert_that(is_stringable<linked_list<double>>).is().true_();
      assert_that(is_stringable < linked_list<double>&& >).is().true_();
      assert_that(is_stringable<linked_list<double>&>).is().true_();
      assert_that(is_stringable<const linked_list<double>&>).is().true_();
      
      assert_that(is_stringable<hash_set<float>>).is().true_();
      assert_that(is_stringable < hash_set<float>&& >).is().true_();
      assert_that(is_stringable<hash_set<float>&>).is().true_();
      assert_that(is_stringable<const hash_set<float>&>).is().true_();
      
      assert_that(is_stringable<queue<intptr>>).is().true_();
      assert_that(is_stringable < queue<intptr>&& >).is().true_();
      assert_that(is_stringable<queue<intptr>&>).is().true_();
      assert_that(is_stringable<const queue<intptr>&>).is().true_();
      
      assert_that(is_stringable<stack<uint64>>).is().true_();
      assert_that(is_stringable < stack<uint64>&& >).is().true_();
      assert_that(is_stringable<stack<uint64>&>).is().true_();
      assert_that(is_stringable<const stack<uint64>&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_std_collections) {
      assert_that(is_stringable<std::initializer_list<std::string>>).is().true_();
      assert_that(is_stringable < std::initializer_list<std::string>&& >).is().true_();
      assert_that(is_stringable<std::initializer_list<std::string>&>).is().true_();
      assert_that(is_stringable<const std::initializer_list<std::string>&>).is().true_();
      
      assert_that(is_stringable<std::array<int, 5>>).is().true_();
      assert_that(is_stringable < std::array<int, 5>&& >).is().true_();
      assert_that(is_stringable<std::array<int, 5>&>).is().true_();
      assert_that(is_stringable<const std::array<int, 5>&>).is().true_();
      
      assert_that(is_stringable<std::vector<std::chrono::system_clock::duration>>).is().true_();
      assert_that(is_stringable < std::vector<std::chrono::system_clock::duration>&& >).is().true_();
      assert_that(is_stringable<std::vector<std::chrono::system_clock::duration>&>).is().true_();
      assert_that(is_stringable<const std::vector<std::chrono::system_clock::duration>&>).is().true_();
      
      assert_that(is_stringable<std::list<double>>).is().true_();
      assert_that(is_stringable < std::list<double>&& >).is().true_();
      assert_that(is_stringable<std::list<double>&>).is().true_();
      assert_that(is_stringable<const std::list<double>&>).is().true_();
      
      assert_that(is_stringable<std::unordered_set<float>>).is().true_();
      assert_that(is_stringable < std::unordered_set<float>&& >).is().true_();
      assert_that(is_stringable<std::unordered_set<float>&>).is().true_();
      assert_that(is_stringable<const std::unordered_set<float>&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_somes_std_objects) {
      assert_that(is_stringable<std::chrono::system_clock::duration>).is().true_();
      assert_that(is_stringable < std::chrono::system_clock::duration && >).is().true_();
      assert_that(is_stringable<std::chrono::system_clock::duration&>).is().true_();
      assert_that(is_stringable<const std::chrono::system_clock::duration&>).is().true_();
      
      assert_that(is_stringable<std::string>).is().true_();
      assert_that(is_stringable < std::string && >).is().true_();
      assert_that(is_stringable<std::string&>).is().true_();
      assert_that(is_stringable<const std::string&>).is().true_();
      
      assert_that(is_stringable<std::runtime_error>).is().true_();
      assert_that(is_stringable < std::runtime_error && >).is().true_();
      assert_that(is_stringable<std::runtime_error&>).is().true_();
      assert_that(is_stringable<const std::runtime_error&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_somes_xtd_objects) {
      assert_that(is_stringable<date_time>).is().true_();
      assert_that(is_stringable < date_time && >).is().true_();
      assert_that(is_stringable<date_time&>).is().true_();
      assert_that(is_stringable<const date_time&>).is().true_();
      
      assert_that(is_stringable<string>).is().true_();
      assert_that(is_stringable < string && >).is().true_();
      assert_that(is_stringable<string&>).is().true_();
      assert_that(is_stringable<const string&>).is().true_();
      
      assert_that(is_stringable<time_span>).is().true_();
      assert_that(is_stringable < time_span && >).is().true_();
      assert_that(is_stringable<time_span&>).is().true_();
      assert_that(is_stringable<const time_span&>).is().true_();
      
      assert_that(is_stringable<version>).is().true_();
      assert_that(is_stringable < version && >).is().true_();
      assert_that(is_stringable<version&>).is().true_();
      assert_that(is_stringable<const version&>).is().true_();
    }
    
    auto test_method_(is_stringable_with_invalid_type) {
      struct my_struct_test {};
      assert_that(is_stringable<my_struct_test>).is().false_();
      assert_that(is_stringable < my_struct_test && >).is().false_();
      assert_that(is_stringable<my_struct_test&>).is().false_();
      assert_that(is_stringable<const my_struct_test&>).is().false_();
    }
  };
}
