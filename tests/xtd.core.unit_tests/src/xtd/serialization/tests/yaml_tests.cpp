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
      assert::is_true(is<null_ptr>(v["null"]));
      assert::is_true(v.is<null_ptr>("null"));
      assert::is_true(v.is_null("null"));
      assert::throws<invalid_operation_exception>([&] {[[maybe_unused]] auto r = as<int>(v["null"]);});
      
      assert::is_false(is<null_ptr>(v["not null"]));
      assert::is_false(v.is<null_ptr>("not null"));
      assert::is_false(v.is_null("not null"));
      assert::does_not_throw([&] {[[maybe_unused]] auto r = as<int>(v["not null"]);});
    }
    
    auto test_method_(yaml_with_boolean) {
      auto v = yaml {
        yaml::nodes_collection {
          {"boolean", true},
          {"not boolean", 42}
        }
      };
      assert::is_true(is<boolean>(v["boolean"]));
      assert::is_true(v.is<boolean>("boolean"));
      assert::is_true(v.is_boolean("boolean"));
      assert::is_true(as<boolean>(v["boolean"]));
      
      assert::is_false(is<boolean>(v["not boolean"]));
      assert::is_false(v.is<boolean>("not boolean"));
      assert::is_false(v.is_boolean("not boolean"));
      assert::throws<invalid_cast_exception>([&] {[[maybe_unused]] auto r = as<boolean>(v["not boolean"]);});
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

