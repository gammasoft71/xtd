#include <xtd/console>
#include <xtd/tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_delegate) {
  public:
    void test_method_(create_empty_console_key_info) {
      console_key_info cki;
      
      assert::are_equal(0, cki.key_char());
      assert::are_equal(static_cast<console_key>(0), cki.key());
      assert::are_equal(static_cast<console_modifiers>(0), cki.modifiers());
    }
    
    void test_method_(create_console_key_info_with_key_char_key) {
      console_key_info cki('a', console_key::a, false, false, false);

      assert::are_equal('a', cki.key_char());
      assert::are_equal(console_key::a, cki.key());
      assert::are_equal(static_cast<console_modifiers>(0), cki.modifiers());
    }
    
    void test_method_(create_console_key_info_with_key_char_key_and_shift) {
      console_key_info cki(' ', console_key::spacebar, true, false, false);
      
      assert::are_equal(' ', cki.key_char());
      assert::are_equal(console_key::spacebar, cki.key());
      assert::are_equal(static_cast<console_modifiers>(0), static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt)));
      assert::are_equal(console_modifiers::shift, static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift)));
      assert::are_equal(static_cast<console_modifiers>(0), static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control)));
    }
    
    void test_method_(create_console_key_info_with_key_char_key_and_alt) {
      console_key_info cki('\0', console_key::up_arrow, false, true, false);
      
      assert::are_equal('\0', cki.key_char());
      assert::are_equal(console_key::up_arrow, cki.key());
      assert::are_equal(console_modifiers::alt, static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt)));
      assert::are_equal(static_cast<console_modifiers>(0), static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift)));
      assert::are_equal(static_cast<console_modifiers>(0), static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control)));
    }
    
    void test_method_(create_console_key_info_with_key_char_key_and_control) {
      console_key_info cki('\t', console_key::tab, false, false, true);

      assert::are_equal('\t', cki.key_char());
      assert::are_equal(console_key::tab, cki.key());
      assert::are_equal(static_cast<console_modifiers>(0), static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt)));
      assert::are_equal(static_cast<console_modifiers>(0), static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift)));
      assert::are_equal(console_modifiers::control, static_cast<console_modifiers>(static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control)));
    }
  };
}
