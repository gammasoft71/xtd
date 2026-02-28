#include <xtd/serialization/yaml>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::serialization;
using namespace xtd::tunit;

namespace xtd::serialization::tests {
  class test_class_(yaml_tests) {
    auto test_method_(nodes_collection) {
      assert::are_equal(typeof_<xtd::collections::generic::dictionary<string, any_object>>(), typeof_<yaml::nodes_collection>());
    }
    
    auto test_method_(yaml_with_null) {
      auto v = yaml {
        yaml::nodes_collection {
          {"null", null},
          {"not null", 42}
        }
      };
      assert::is_true(v["null"] == nullptr);
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto r = as<bool>(v["null"]);});
      
      assert::is_false(v["not null"] == nullptr);
    }
    
    auto test_method_(yaml_with_bool) {
      auto v = yaml {
        yaml::nodes_collection {
          {"bool", true},
          {"not bool", 42}
        }
      };
      assert::is_true(is<bool>(v["bool"]));
      assert::is_true(as<bool>(v["bool"]));
      
      assert::is_false(is<bool>(v["not bool"]));
      assert::throws<invalid_cast_exception>([&] {[[maybe_unused]] auto r = as<bool>(v["not bool"]);});
    }
    
    auto test_method_(yaml_with_integer) {
      auto v = yaml {
        yaml::nodes_collection {
          {"integer", 42_s64},
          {"not integer", false}
        }
      };
      assert::is_true(is<int64>(v["integer"]));
      assert::is_true(as<int64>(v["integer"]));

      assert::is_false(is<int64>(v["not integer"]));
      assert::throws<invalid_cast_exception>([&] {[[maybe_unused]] auto r = as<int64>(v["not integer"]);});
    }
  };
}

