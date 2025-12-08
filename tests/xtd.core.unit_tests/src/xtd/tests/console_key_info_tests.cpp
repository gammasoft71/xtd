#include <xtd/as>
#include <xtd/console_key_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_key_info_tests) {
    auto test_method_(create_empty_console_key_info) {
      console_key_info cki;
      
      assert::is_zero(cki.key_char());
      assert::are_equal(0, as<int32>(cki.key()));
      assert::are_equal(0, as<int32>(cki.modifiers()));
    }
    
    auto test_method_(create_console_key_info_with_key_char_key) {
      console_key_info cki('a', console_key::a, false, false, false);
      
      assert::are_equal(U'a', cki.key_char());
      assert::are_equal(as<int32>(console_key::a), as<int32>(cki.key()));
      assert::are_equal(0, as<int32>(cki.modifiers()));
    }
    
    auto test_method_(create_console_key_info_with_key_char_key_and_shift) {
      console_key_info cki(' ', console_key::spacebar, true, false, false);
      
      assert::are_equal(U' ', cki.key_char());
      assert::are_equal(as<int32>(console_key::spacebar), as<int32>(cki.key()));
      assert::is_false((cki.modifiers() & console_modifiers::alt) == console_modifiers::alt);
      assert::is_true((cki.modifiers() & console_modifiers::shift) == console_modifiers::shift);
      assert::is_false((cki.modifiers() & console_modifiers::control) == console_modifiers::control);
    }
    
    auto test_method_(create_console_key_info_with_key_char_key_and_alt) {
      console_key_info cki('\0', console_key::up_arrow, false, true, false);
      
      assert::are_equal(U'\0', cki.key_char());
      assert::are_equal(as<int32>(console_key::up_arrow), as<int32>(cki.key()));
      assert::is_true((cki.modifiers() & console_modifiers::alt) == console_modifiers::alt);
      assert::is_false((cki.modifiers() & console_modifiers::shift) == console_modifiers::shift);
      assert::is_false((cki.modifiers() & console_modifiers::control) == console_modifiers::control);
    }
    
    auto test_method_(create_console_key_info_with_key_char_key_and_control) {
      console_key_info cki('\t', console_key::tab, false, false, true);
      
      assert::are_equal(U'\t', cki.key_char());
      assert::are_equal(as<int32>(console_key::tab), as<int32>(cki.key()));
      assert::is_false((cki.modifiers() & console_modifiers::alt) == console_modifiers::alt);
      assert::is_false((cki.modifiers() & console_modifiers::shift) == console_modifiers::shift);
      assert::is_true((cki.modifiers() & console_modifiers::control) == console_modifiers::control);
    }
  };
}
