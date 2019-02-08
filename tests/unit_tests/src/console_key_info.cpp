#include <console/console>
#include <catch2/catch.hpp>

using namespace std;
using namespace xtd;

TEST_CASE("GIVEN Create console_key_info WHEN default constructor THEN check key, key_char and modifiers") {
  console_key_info cki;

  REQUIRE(cki.key_char() == 0);
  REQUIRE(cki.key() == static_cast<console_key>(0));
  REQUIRE(cki.modifiers() == static_cast<console_modifiers>(0));
}

TEST_CASE("GIVEN Create console_key_info WHEN key_char = 'a', key = console_key::a, shift = false, alt = false and control = false THEN check key, key_char and modifiers") {
  console_key_info cki('a', console_key::a, false, false, false);
  
  REQUIRE(cki.key_char() == 'a');
  REQUIRE(cki.key() == console_key::a);
  REQUIRE(cki.modifiers() == static_cast<console_modifiers>(0));
}

TEST_CASE("GIVEN Create console_key_info WHEN key_char = ' ', key = console_key::spacebar, shift = true, alt = false and control = false THEN check key, key_char and modifiers") {
  console_key_info cki(' ', console_key::spacebar, true, false, false);
  
  REQUIRE(cki.key_char() == ' ');
  REQUIRE(cki.key() == console_key::spacebar);
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt)) == 0);
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift)) == static_cast<int>(console_modifiers::shift));
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control)) == 0);
}

TEST_CASE("GIVEN Create console_key_info WHEN key_char = '\0', key = console_key::up_arrow, shift = false, alt = true and control = false THEN check key, key_char and modifiers") {
  console_key_info cki('\0', console_key::up_arrow, false, true, false);
  
  REQUIRE(cki.key_char() == '\0');
  REQUIRE(cki.key() == console_key::up_arrow);
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt)) == static_cast<int>(console_modifiers::alt));
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift)) == 0);
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control)) == 0);
}

TEST_CASE("GIVEN Create console_key_info WHEN key_char = '\t', key = console_key::tab, shift = false, alt = false and control = true THEN check key, key_char and modifiers") {
  console_key_info cki('\t', console_key::tab, false, false, true);
  
  REQUIRE(cki.key_char() == '\t');
  REQUIRE(cki.key() == console_key::tab);
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::alt)) == 0);
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::shift)) == 0);
  REQUIRE((static_cast<int>(cki.modifiers()) & static_cast<int>(console_modifiers::control)) == static_cast<int>(console_modifiers::control));
}
