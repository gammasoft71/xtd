#include <xtd/console_key>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_key_tests) {
    auto test_method_(backspace) {
      assert::are_equal(8, enum_object<>::to_int32(console_key::backspace));
      assert::are_equal("backspace", enum_object<>::to_string(console_key::backspace));
      assert::are_equal(console_key::backspace, enum_object<>::parse<console_key>("backspace"));
    }
    
    auto test_method_(tab) {
      assert::are_equal(9, enum_object<>::to_int32(console_key::tab));
      assert::are_equal("tab", enum_object<>::to_string(console_key::tab));
      assert::are_equal(console_key::tab, enum_object<>::parse<console_key>("tab"));
    }
    
    auto test_method_(clear) {
      assert::are_equal(12, enum_object<>::to_int32(console_key::clear));
      assert::are_equal("clear", enum_object<>::to_string(console_key::clear));
      assert::are_equal(console_key::clear, enum_object<>::parse<console_key>("clear"));
    }
    
    auto test_method_(enter) {
      assert::are_equal(13, enum_object<>::to_int32(console_key::enter));
      assert::are_equal("enter", enum_object<>::to_string(console_key::enter));
      assert::are_equal(console_key::enter, enum_object<>::parse<console_key>("enter"));
    }
    
    auto test_method_(pause) {
      assert::are_equal(19, enum_object<>::to_int32(console_key::pause));
      assert::are_equal("pause", enum_object<>::to_string(console_key::pause));
      assert::are_equal(console_key::pause, enum_object<>::parse<console_key>("pause"));
    }
    
    auto test_method_(escape) {
      assert::are_equal(27, enum_object<>::to_int32(console_key::escape));
      assert::are_equal("escape", enum_object<>::to_string(console_key::escape));
      assert::are_equal(console_key::escape, enum_object<>::parse<console_key>("escape"));
    }
    
    auto test_method_(spacebar) {
      assert::are_equal(32, enum_object<>::to_int32(console_key::spacebar));
      assert::are_equal("spacebar", enum_object<>::to_string(console_key::spacebar));
      assert::are_equal(console_key::spacebar, enum_object<>::parse<console_key>("spacebar"));
    }
    
    auto test_method_(page_up) {
      assert::are_equal(33, enum_object<>::to_int32(console_key::page_up));
      assert::are_equal("page_up", enum_object<>::to_string(console_key::page_up));
      assert::are_equal(console_key::page_up, enum_object<>::parse<console_key>("page_up"));
    }
    
    auto test_method_(page_down) {
      assert::are_equal(34, enum_object<>::to_int32(console_key::page_down));
      assert::are_equal("page_down", enum_object<>::to_string(console_key::page_down));
      assert::are_equal(console_key::page_down, enum_object<>::parse<console_key>("page_down"));
    }
    
    auto test_method_(end) {
      assert::are_equal(35, enum_object<>::to_int32(console_key::end));
      assert::are_equal("end", enum_object<>::to_string(console_key::end));
      assert::are_equal(console_key::end, enum_object<>::parse<console_key>("end"));
    }
    
    auto test_method_(home) {
      assert::are_equal(36, enum_object<>::to_int32(console_key::home));
      assert::are_equal("home", enum_object<>::to_string(console_key::home));
      assert::are_equal(console_key::home, enum_object<>::parse<console_key>("home"));
    }
    
    auto test_method_(left_arrow) {
      assert::are_equal(37, enum_object<>::to_int32(console_key::left_arrow));
      assert::are_equal("left_arrow", enum_object<>::to_string(console_key::left_arrow));
      assert::are_equal(console_key::left_arrow, enum_object<>::parse<console_key>("left_arrow"));
    }
    
    auto test_method_(up_arrow) {
      assert::are_equal(38, enum_object<>::to_int32(console_key::up_arrow));
      assert::are_equal("up_arrow", enum_object<>::to_string(console_key::up_arrow));
      assert::are_equal(console_key::up_arrow, enum_object<>::parse<console_key>("up_arrow"));
    }
    
    auto test_method_(right_arrow) {
      assert::are_equal(39, enum_object<>::to_int32(console_key::right_arrow));
      assert::are_equal("right_arrow", enum_object<>::to_string(console_key::right_arrow));
      assert::are_equal(console_key::right_arrow, enum_object<>::parse<console_key>("right_arrow"));
    }
    
    auto test_method_(down_arrow) {
      assert::are_equal(40, enum_object<>::to_int32(console_key::down_arrow));
      assert::are_equal("down_arrow", enum_object<>::to_string(console_key::down_arrow));
      assert::are_equal(console_key::down_arrow, enum_object<>::parse<console_key>("down_arrow"));
    }
    
    auto test_method_(select) {
      assert::are_equal(41, enum_object<>::to_int32(console_key::select));
      assert::are_equal("select", enum_object<>::to_string(console_key::select));
      assert::are_equal(console_key::select, enum_object<>::parse<console_key>("select"));
    }
    
    auto test_method_(print) {
      assert::are_equal(42, enum_object<>::to_int32(console_key::print));
      assert::are_equal("print", enum_object<>::to_string(console_key::print));
      assert::are_equal(console_key::print, enum_object<>::parse<console_key>("print"));
    }
    
    auto test_method_(execute) {
      assert::are_equal(43, enum_object<>::to_int32(console_key::execute));
      assert::are_equal("execute", enum_object<>::to_string(console_key::execute));
      assert::are_equal(console_key::execute, enum_object<>::parse<console_key>("execute"));
    }
    
    auto test_method_(print_screen) {
      assert::are_equal(44, enum_object<>::to_int32(console_key::print_screen));
      assert::are_equal("print_screen", enum_object<>::to_string(console_key::print_screen));
      assert::are_equal(console_key::print_screen, enum_object<>::parse<console_key>("print_screen"));
    }
    
    auto test_method_(insert) {
      assert::are_equal(45, enum_object<>::to_int32(console_key::insert));
      assert::are_equal("insert", enum_object<>::to_string(console_key::insert));
      assert::are_equal(console_key::insert, enum_object<>::parse<console_key>("insert"));
    }
    
    auto test_method_(del) {
      assert::are_equal(46, enum_object<>::to_int32(console_key::del));
      assert::are_equal("del", enum_object<>::to_string(console_key::del));
      assert::are_equal(console_key::del, enum_object<>::parse<console_key>("del"));
    }
    
    auto test_method_(help) {
      assert::are_equal(47, enum_object<>::to_int32(console_key::help));
      assert::are_equal("help", enum_object<>::to_string(console_key::help));
      assert::are_equal(console_key::help, enum_object<>::parse<console_key>("help"));
    }
    
    auto test_method_(d0) {
      assert::are_equal(48, enum_object<>::to_int32(console_key::d0));
      assert::are_equal("d0", enum_object<>::to_string(console_key::d0));
      assert::are_equal(console_key::d0, enum_object<>::parse<console_key>("d0"));
    }
    
    auto test_method_(d1) {
      assert::are_equal(49, enum_object<>::to_int32(console_key::d1));
      assert::are_equal("d1", enum_object<>::to_string(console_key::d1));
      assert::are_equal(console_key::d1, enum_object<>::parse<console_key>("d1"));
    }
    
    auto test_method_(d2) {
      assert::are_equal(50, enum_object<>::to_int32(console_key::d2));
      assert::are_equal("d2", enum_object<>::to_string(console_key::d2));
      assert::are_equal(console_key::d2, enum_object<>::parse<console_key>("d2"));
    }
    
    auto test_method_(d3) {
      assert::are_equal(51, enum_object<>::to_int32(console_key::d3));
      assert::are_equal("d3", enum_object<>::to_string(console_key::d3));
      assert::are_equal(console_key::d3, enum_object<>::parse<console_key>("d3"));
    }
    
    auto test_method_(d4) {
      assert::are_equal(52, enum_object<>::to_int32(console_key::d4));
      assert::are_equal("d4", enum_object<>::to_string(console_key::d4));
      assert::are_equal(console_key::d4, enum_object<>::parse<console_key>("d4"));
    }
    
    auto test_method_(d5) {
      assert::are_equal(53, enum_object<>::to_int32(console_key::d5));
      assert::are_equal("d5", enum_object<>::to_string(console_key::d5));
      assert::are_equal(console_key::d5, enum_object<>::parse<console_key>("d5"));
    }
    
    auto test_method_(d6) {
      assert::are_equal(54, enum_object<>::to_int32(console_key::d6));
      assert::are_equal("d6", enum_object<>::to_string(console_key::d6));
      assert::are_equal(console_key::d6, enum_object<>::parse<console_key>("d6"));
    }
    
    auto test_method_(d7) {
      assert::are_equal(55, enum_object<>::to_int32(console_key::d7));
      assert::are_equal("d7", enum_object<>::to_string(console_key::d7));
      assert::are_equal(console_key::d7, enum_object<>::parse<console_key>("d7"));
    }
    
    auto test_method_(d8) {
      assert::are_equal(56, enum_object<>::to_int32(console_key::d8));
      assert::are_equal("d8", enum_object<>::to_string(console_key::d8));
      assert::are_equal(console_key::d8, enum_object<>::parse<console_key>("d8"));
    }
    
    auto test_method_(d9) {
      assert::are_equal(57, enum_object<>::to_int32(console_key::d9));
      assert::are_equal("d9", enum_object<>::to_string(console_key::d9));
      assert::are_equal(console_key::d9, enum_object<>::parse<console_key>("d9"));
    }
    
    auto test_method_(a) {
      assert::are_equal(65, enum_object<>::to_int32(console_key::a));
      assert::are_equal("a", enum_object<>::to_string(console_key::a));
      assert::are_equal(console_key::a, enum_object<>::parse<console_key>("a"));
    }
    
    auto test_method_(b) {
      assert::are_equal(66, enum_object<>::to_int32(console_key::b));
      assert::are_equal("b", enum_object<>::to_string(console_key::b));
      assert::are_equal(console_key::b, enum_object<>::parse<console_key>("b"));
    }
    
    auto test_method_(c) {
      assert::are_equal(67, enum_object<>::to_int32(console_key::c));
      assert::are_equal("c", enum_object<>::to_string(console_key::c));
      assert::are_equal(console_key::c, enum_object<>::parse<console_key>("c"));
    }
    
    auto test_method_(d) {
      assert::are_equal(68, enum_object<>::to_int32(console_key::d));
      assert::are_equal("d", enum_object<>::to_string(console_key::d));
      assert::are_equal(console_key::d, enum_object<>::parse<console_key>("d"));
    }
    
    auto test_method_(e) {
      assert::are_equal(69, enum_object<>::to_int32(console_key::e));
      assert::are_equal("e", enum_object<>::to_string(console_key::e));
      assert::are_equal(console_key::e, enum_object<>::parse<console_key>("e"));
    }
    
    auto test_method_(f) {
      assert::are_equal(70, enum_object<>::to_int32(console_key::f));
      assert::are_equal("f", enum_object<>::to_string(console_key::f));
      assert::are_equal(console_key::f, enum_object<>::parse<console_key>("f"));
    }
    
    auto test_method_(g) {
      assert::are_equal(71, enum_object<>::to_int32(console_key::g));
      assert::are_equal("g", enum_object<>::to_string(console_key::g));
      assert::are_equal(console_key::g, enum_object<>::parse<console_key>("g"));
    }
    
    auto test_method_(h) {
      assert::are_equal(72, enum_object<>::to_int32(console_key::h));
      assert::are_equal("h", enum_object<>::to_string(console_key::h));
      assert::are_equal(console_key::h, enum_object<>::parse<console_key>("h"));
    }
    
    auto test_method_(i) {
      assert::are_equal(73, enum_object<>::to_int32(console_key::i));
      assert::are_equal("i", enum_object<>::to_string(console_key::i));
      assert::are_equal(console_key::i, enum_object<>::parse<console_key>("i"));
    }
    
    auto test_method_(j) {
      assert::are_equal(74, enum_object<>::to_int32(console_key::j));
      assert::are_equal("j", enum_object<>::to_string(console_key::j));
      assert::are_equal(console_key::j, enum_object<>::parse<console_key>("j"));
    }
    
    auto test_method_(k) {
      assert::are_equal(75, enum_object<>::to_int32(console_key::k));
      assert::are_equal("k", enum_object<>::to_string(console_key::k));
      assert::are_equal(console_key::k, enum_object<>::parse<console_key>("k"));
    }
    
    auto test_method_(l) {
      assert::are_equal(76, enum_object<>::to_int32(console_key::l));
      assert::are_equal("l", enum_object<>::to_string(console_key::l));
      assert::are_equal(console_key::l, enum_object<>::parse<console_key>("l"));
    }
    
    auto test_method_(m) {
      assert::are_equal(77, enum_object<>::to_int32(console_key::m));
      assert::are_equal("m", enum_object<>::to_string(console_key::m));
      assert::are_equal(console_key::m, enum_object<>::parse<console_key>("m"));
    }
    
    auto test_method_(n) {
      assert::are_equal(78, enum_object<>::to_int32(console_key::n));
      assert::are_equal("n", enum_object<>::to_string(console_key::n));
      assert::are_equal(console_key::n, enum_object<>::parse<console_key>("n"));
    }
    
    auto test_method_(o) {
      assert::are_equal(79, enum_object<>::to_int32(console_key::o));
      assert::are_equal("o", enum_object<>::to_string(console_key::o));
      assert::are_equal(console_key::o, enum_object<>::parse<console_key>("o"));
    }
    
    auto test_method_(p) {
      assert::are_equal(80, enum_object<>::to_int32(console_key::p));
      assert::are_equal("p", enum_object<>::to_string(console_key::p));
      assert::are_equal(console_key::p, enum_object<>::parse<console_key>("p"));
    }
    
    auto test_method_(q) {
      assert::are_equal(81, enum_object<>::to_int32(console_key::q));
      assert::are_equal("q", enum_object<>::to_string(console_key::q));
      assert::are_equal(console_key::q, enum_object<>::parse<console_key>("q"));
    }
    
    auto test_method_(r) {
      assert::are_equal(82, enum_object<>::to_int32(console_key::r));
      assert::are_equal("r", enum_object<>::to_string(console_key::r));
      assert::are_equal(console_key::r, enum_object<>::parse<console_key>("r"));
    }
    
    auto test_method_(s) {
      assert::are_equal(83, enum_object<>::to_int32(console_key::s));
      assert::are_equal("s", enum_object<>::to_string(console_key::s));
      assert::are_equal(console_key::s, enum_object<>::parse<console_key>("s"));
    }
    
    auto test_method_(t) {
      assert::are_equal(84, enum_object<>::to_int32(console_key::t));
      assert::are_equal("t", enum_object<>::to_string(console_key::t));
      assert::are_equal(console_key::t, enum_object<>::parse<console_key>("t"));
    }
    
    auto test_method_(u) {
      assert::are_equal(85, enum_object<>::to_int32(console_key::u));
      assert::are_equal("u", enum_object<>::to_string(console_key::u));
      assert::are_equal(console_key::u, enum_object<>::parse<console_key>("u"));
    }
    
    auto test_method_(v) {
      assert::are_equal(86, enum_object<>::to_int32(console_key::v));
      assert::are_equal("v", enum_object<>::to_string(console_key::v));
      assert::are_equal(console_key::v, enum_object<>::parse<console_key>("v"));
    }
    
    auto test_method_(w) {
      assert::are_equal(87, enum_object<>::to_int32(console_key::w));
      assert::are_equal("w", enum_object<>::to_string(console_key::w));
      assert::are_equal(console_key::w, enum_object<>::parse<console_key>("w"));
    }
    
    auto test_method_(x) {
      assert::are_equal(88, enum_object<>::to_int32(console_key::x));
      assert::are_equal("x", enum_object<>::to_string(console_key::x));
      assert::are_equal(console_key::x, enum_object<>::parse<console_key>("x"));
    }
    
    auto test_method_(y) {
      assert::are_equal(89, enum_object<>::to_int32(console_key::y));
      assert::are_equal("y", enum_object<>::to_string(console_key::y));
      assert::are_equal(console_key::y, enum_object<>::parse<console_key>("y"));
    }
    
    auto test_method_(z) {
      assert::are_equal(90, enum_object<>::to_int32(console_key::z));
      assert::are_equal("z", enum_object<>::to_string(console_key::z));
      assert::are_equal(console_key::z, enum_object<>::parse<console_key>("z"));
    }
    
    auto test_method_(left_windows) {
      assert::are_equal(91, enum_object<>::to_int32(console_key::left_windows));
      assert::are_equal("left_windows", enum_object<>::to_string(console_key::left_windows));
      assert::are_equal(console_key::left_windows, enum_object<>::parse<console_key>("left_windows"));
    }
    
    auto test_method_(right_windows) {
      assert::are_equal(92, enum_object<>::to_int32(console_key::right_windows));
      assert::are_equal("right_windows", enum_object<>::to_string(console_key::right_windows));
      assert::are_equal(console_key::right_windows, enum_object<>::parse<console_key>("right_windows"));
    }
    
    auto test_method_(applications) {
      assert::are_equal(93, enum_object<>::to_int32(console_key::applications));
      assert::are_equal("applications", enum_object<>::to_string(console_key::applications));
      assert::are_equal(console_key::applications, enum_object<>::parse<console_key>("applications"));
    }
    
    auto test_method_(sleep) {
      assert::are_equal(95, enum_object<>::to_int32(console_key::sleep));
      assert::are_equal("sleep", enum_object<>::to_string(console_key::sleep));
      assert::are_equal(console_key::sleep, enum_object<>::parse<console_key>("sleep"));
    }
    
    auto test_method_(num_pad_0) {
      assert::are_equal(96, enum_object<>::to_int32(console_key::num_pad_0));
      assert::are_equal("num_pad_0", enum_object<>::to_string(console_key::num_pad_0));
      assert::are_equal(console_key::num_pad_0, enum_object<>::parse<console_key>("num_pad_0"));
    }
    
    auto test_method_(num_pad_1) {
      assert::are_equal(97, enum_object<>::to_int32(console_key::num_pad_1));
      assert::are_equal("num_pad_1", enum_object<>::to_string(console_key::num_pad_1));
      assert::are_equal(console_key::num_pad_1, enum_object<>::parse<console_key>("num_pad_1"));
    }
    
    auto test_method_(num_pad_2) {
      assert::are_equal(98, enum_object<>::to_int32(console_key::num_pad_2));
      assert::are_equal("num_pad_2", enum_object<>::to_string(console_key::num_pad_2));
      assert::are_equal(console_key::num_pad_2, enum_object<>::parse<console_key>("num_pad_2"));
    }
    
    auto test_method_(num_pad_3) {
      assert::are_equal(99, enum_object<>::to_int32(console_key::num_pad_3));
      assert::are_equal("num_pad_3", enum_object<>::to_string(console_key::num_pad_3));
      assert::are_equal(console_key::num_pad_3, enum_object<>::parse<console_key>("num_pad_3"));
    }
    
    auto test_method_(num_pad_4) {
      assert::are_equal(100, enum_object<>::to_int32(console_key::num_pad_4));
      assert::are_equal("num_pad_4", enum_object<>::to_string(console_key::num_pad_4));
      assert::are_equal(console_key::num_pad_4, enum_object<>::parse<console_key>("num_pad_4"));
    }
    
    auto test_method_(num_pad_5) {
      assert::are_equal(101, enum_object<>::to_int32(console_key::num_pad_5));
      assert::are_equal("num_pad_5", enum_object<>::to_string(console_key::num_pad_5));
      assert::are_equal(console_key::num_pad_5, enum_object<>::parse<console_key>("num_pad_5"));
    }
    
    auto test_method_(num_pad_6) {
      assert::are_equal(102, enum_object<>::to_int32(console_key::num_pad_6));
      assert::are_equal("num_pad_6", enum_object<>::to_string(console_key::num_pad_6));
      assert::are_equal(console_key::num_pad_6, enum_object<>::parse<console_key>("num_pad_6"));
    }
    
    auto test_method_(num_pad_7) {
      assert::are_equal(103, enum_object<>::to_int32(console_key::num_pad_7));
      assert::are_equal("num_pad_7", enum_object<>::to_string(console_key::num_pad_7));
      assert::are_equal(console_key::num_pad_7, enum_object<>::parse<console_key>("num_pad_7"));
    }
    
    auto test_method_(num_pad_8) {
      assert::are_equal(104, enum_object<>::to_int32(console_key::num_pad_8));
      assert::are_equal("num_pad_8", enum_object<>::to_string(console_key::num_pad_8));
      assert::are_equal(console_key::num_pad_8, enum_object<>::parse<console_key>("num_pad_8"));
    }
    
    auto test_method_(num_pad_9) {
      assert::are_equal(105, enum_object<>::to_int32(console_key::num_pad_9));
      assert::are_equal("num_pad_9", enum_object<>::to_string(console_key::num_pad_9));
      assert::are_equal(console_key::num_pad_9, enum_object<>::parse<console_key>("num_pad_9"));
    }
    
    auto test_method_(multiply) {
      assert::are_equal(106, enum_object<>::to_int32(console_key::multiply));
      assert::are_equal("multiply", enum_object<>::to_string(console_key::multiply));
      assert::are_equal(console_key::multiply, enum_object<>::parse<console_key>("multiply"));
    }
    
    auto test_method_(add) {
      assert::are_equal(107, enum_object<>::to_int32(console_key::add));
      assert::are_equal("add", enum_object<>::to_string(console_key::add));
      assert::are_equal(console_key::add, enum_object<>::parse<console_key>("add"));
    }
    
    auto test_method_(separator) {
      assert::are_equal(108, enum_object<>::to_int32(console_key::separator));
      assert::are_equal("separator", enum_object<>::to_string(console_key::separator));
      assert::are_equal(console_key::separator, enum_object<>::parse<console_key>("separator"));
    }
    
    auto test_method_(subtract) {
      assert::are_equal(109, enum_object<>::to_int32(console_key::subtract));
      assert::are_equal("subtract", enum_object<>::to_string(console_key::subtract));
      assert::are_equal(console_key::subtract, enum_object<>::parse<console_key>("subtract"));
    }
    
    auto test_method_(decimal) {
      assert::are_equal(110, enum_object<>::to_int32(console_key::decimal));
      assert::are_equal("decimal", enum_object<>::to_string(console_key::decimal));
      assert::are_equal(console_key::decimal, enum_object<>::parse<console_key>("decimal"));
    }
    
    auto test_method_(divide) {
      assert::are_equal(111, enum_object<>::to_int32(console_key::divide));
      assert::are_equal("divide", enum_object<>::to_string(console_key::divide));
      assert::are_equal(console_key::divide, enum_object<>::parse<console_key>("divide"));
    }
    
    auto test_method_(f1) {
      assert::are_equal(112, enum_object<>::to_int32(console_key::f1));
      assert::are_equal("f1", enum_object<>::to_string(console_key::f1));
      assert::are_equal(console_key::f1, enum_object<>::parse<console_key>("f1"));
    }
    
    auto test_method_(f2) {
      assert::are_equal(113, enum_object<>::to_int32(console_key::f2));
      assert::are_equal("f2", enum_object<>::to_string(console_key::f2));
      assert::are_equal(console_key::f2, enum_object<>::parse<console_key>("f2"));
    }
    
    auto test_method_(f3) {
      assert::are_equal(114, enum_object<>::to_int32(console_key::f3));
      assert::are_equal("f3", enum_object<>::to_string(console_key::f3));
      assert::are_equal(console_key::f3, enum_object<>::parse<console_key>("f3"));
    }
    
    auto test_method_(f4) {
      assert::are_equal(115, enum_object<>::to_int32(console_key::f4));
      assert::are_equal("f4", enum_object<>::to_string(console_key::f4));
      assert::are_equal(console_key::f4, enum_object<>::parse<console_key>("f4"));
    }
    
    auto test_method_(f5) {
      assert::are_equal(116, enum_object<>::to_int32(console_key::f5));
      assert::are_equal("f5", enum_object<>::to_string(console_key::f5));
      assert::are_equal(console_key::f5, enum_object<>::parse<console_key>("f5"));
    }
    
    auto test_method_(f6) {
      assert::are_equal(117, enum_object<>::to_int32(console_key::f6));
      assert::are_equal("f6", enum_object<>::to_string(console_key::f6));
      assert::are_equal(console_key::f6, enum_object<>::parse<console_key>("f6"));
    }
    
    auto test_method_(f7) {
      assert::are_equal(118, enum_object<>::to_int32(console_key::f7));
      assert::are_equal("f7", enum_object<>::to_string(console_key::f7));
      assert::are_equal(console_key::f7, enum_object<>::parse<console_key>("f7"));
    }
    
    auto test_method_(f8) {
      assert::are_equal(119, enum_object<>::to_int32(console_key::f8));
      assert::are_equal("f8", enum_object<>::to_string(console_key::f8));
      assert::are_equal(console_key::f8, enum_object<>::parse<console_key>("f8"));
    }
    
    auto test_method_(f9) {
      assert::are_equal(120, enum_object<>::to_int32(console_key::f9));
      assert::are_equal("f9", enum_object<>::to_string(console_key::f9));
      assert::are_equal(console_key::f9, enum_object<>::parse<console_key>("f9"));
    }
    
    auto test_method_(f10) {
      assert::are_equal(121, enum_object<>::to_int32(console_key::f10));
      assert::are_equal("f10", enum_object<>::to_string(console_key::f10));
      assert::are_equal(console_key::f10, enum_object<>::parse<console_key>("f10"));
    }
    
    auto test_method_(f11) {
      assert::are_equal(122, enum_object<>::to_int32(console_key::f11));
      assert::are_equal("f11", enum_object<>::to_string(console_key::f11));
      assert::are_equal(console_key::f11, enum_object<>::parse<console_key>("f11"));
    }
    
    auto test_method_(f12) {
      assert::are_equal(123, enum_object<>::to_int32(console_key::f12));
      assert::are_equal("f12", enum_object<>::to_string(console_key::f12));
      assert::are_equal(console_key::f12, enum_object<>::parse<console_key>("f12"));
    }
    
    auto test_method_(f13) {
      assert::are_equal(124, enum_object<>::to_int32(console_key::f13));
      assert::are_equal("f13", enum_object<>::to_string(console_key::f13));
      assert::are_equal(console_key::f13, enum_object<>::parse<console_key>("f13"));
    }
    
    auto test_method_(f14) {
      assert::are_equal(125, enum_object<>::to_int32(console_key::f14));
      assert::are_equal("f14", enum_object<>::to_string(console_key::f14));
      assert::are_equal(console_key::f14, enum_object<>::parse<console_key>("f14"));
    }
    
    auto test_method_(f15) {
      assert::are_equal(126, enum_object<>::to_int32(console_key::f15));
      assert::are_equal("f15", enum_object<>::to_string(console_key::f15));
      assert::are_equal(console_key::f15, enum_object<>::parse<console_key>("f15"));
    }
    
    auto test_method_(f16) {
      assert::are_equal(127, enum_object<>::to_int32(console_key::f16));
      assert::are_equal("f16", enum_object<>::to_string(console_key::f16));
      assert::are_equal(console_key::f16, enum_object<>::parse<console_key>("f16"));
    }
    
    auto test_method_(f17) {
      assert::are_equal(128, enum_object<>::to_int32(console_key::f17));
      assert::are_equal("f17", enum_object<>::to_string(console_key::f17));
      assert::are_equal(console_key::f17, enum_object<>::parse<console_key>("f17"));
    }
    
    auto test_method_(f18) {
      assert::are_equal(129, enum_object<>::to_int32(console_key::f18));
      assert::are_equal("f18", enum_object<>::to_string(console_key::f18));
      assert::are_equal(console_key::f18, enum_object<>::parse<console_key>("f18"));
    }
    
    auto test_method_(f19) {
      assert::are_equal(130, enum_object<>::to_int32(console_key::f19));
      assert::are_equal("f19", enum_object<>::to_string(console_key::f19));
      assert::are_equal(console_key::f19, enum_object<>::parse<console_key>("f19"));
    }
    
    auto test_method_(f20) {
      assert::are_equal(131, enum_object<>::to_int32(console_key::f20));
      assert::are_equal("f20", enum_object<>::to_string(console_key::f20));
      assert::are_equal(console_key::f20, enum_object<>::parse<console_key>("f20"));
    }
    
    auto test_method_(f21) {
      assert::are_equal(132, enum_object<>::to_int32(console_key::f21));
      assert::are_equal("f21", enum_object<>::to_string(console_key::f21));
      assert::are_equal(console_key::f21, enum_object<>::parse<console_key>("f21"));
    }
    
    auto test_method_(f22) {
      assert::are_equal(133, enum_object<>::to_int32(console_key::f22));
      assert::are_equal("f22", enum_object<>::to_string(console_key::f22));
      assert::are_equal(console_key::f22, enum_object<>::parse<console_key>("f22"));
    }
    
    auto test_method_(f23) {
      assert::are_equal(134, enum_object<>::to_int32(console_key::f23));
      assert::are_equal("f23", enum_object<>::to_string(console_key::f23));
      assert::are_equal(console_key::f23, enum_object<>::parse<console_key>("f23"));
    }
    
    auto test_method_(f24) {
      assert::are_equal(135, enum_object<>::to_int32(console_key::f24));
      assert::are_equal("f24", enum_object<>::to_string(console_key::f24));
      assert::are_equal(console_key::f24, enum_object<>::parse<console_key>("f24"));
    }
    
    auto test_method_(browser_back) {
      assert::are_equal(166, enum_object<>::to_int32(console_key::browser_back));
      assert::are_equal("browser_back", enum_object<>::to_string(console_key::browser_back));
      assert::are_equal(console_key::browser_back, enum_object<>::parse<console_key>("browser_back"));
    }
    
    auto test_method_(browser_forward) {
      assert::are_equal(167, enum_object<>::to_int32(console_key::browser_forward));
      assert::are_equal("browser_forward", enum_object<>::to_string(console_key::browser_forward));
      assert::are_equal(console_key::browser_forward, enum_object<>::parse<console_key>("browser_forward"));
    }
    
    auto test_method_(browser_refresh) {
      assert::are_equal(168, enum_object<>::to_int32(console_key::browser_refresh));
      assert::are_equal("browser_refresh", enum_object<>::to_string(console_key::browser_refresh));
      assert::are_equal(console_key::browser_refresh, enum_object<>::parse<console_key>("browser_refresh"));
    }
    
    auto test_method_(browser_stop) {
      assert::are_equal(169, enum_object<>::to_int32(console_key::browser_stop));
      assert::are_equal("browser_stop", enum_object<>::to_string(console_key::browser_stop));
      assert::are_equal(console_key::browser_stop, enum_object<>::parse<console_key>("browser_stop"));
    }
    
    auto test_method_(browser_search) {
      assert::are_equal(170, enum_object<>::to_int32(console_key::browser_search));
      assert::are_equal("browser_search", enum_object<>::to_string(console_key::browser_search));
      assert::are_equal(console_key::browser_search, enum_object<>::parse<console_key>("browser_search"));
    }
    
    auto test_method_(browser_favorites) {
      assert::are_equal(171, enum_object<>::to_int32(console_key::browser_favorites));
      assert::are_equal("browser_favorites", enum_object<>::to_string(console_key::browser_favorites));
      assert::are_equal(console_key::browser_favorites, enum_object<>::parse<console_key>("browser_favorites"));
    }
    
    auto test_method_(browser_home) {
      assert::are_equal(172, enum_object<>::to_int32(console_key::browser_home));
      assert::are_equal("browser_home", enum_object<>::to_string(console_key::browser_home));
      assert::are_equal(console_key::browser_home, enum_object<>::parse<console_key>("browser_home"));
    }
    
    auto test_method_(volume_mute) {
      assert::are_equal(173, enum_object<>::to_int32(console_key::volume_mute));
      assert::are_equal("volume_mute", enum_object<>::to_string(console_key::volume_mute));
      assert::are_equal(console_key::volume_mute, enum_object<>::parse<console_key>("volume_mute"));
    }
    
    auto test_method_(volume_down) {
      assert::are_equal(174, enum_object<>::to_int32(console_key::volume_down));
      assert::are_equal("volume_down", enum_object<>::to_string(console_key::volume_down));
      assert::are_equal(console_key::volume_down, enum_object<>::parse<console_key>("volume_down"));
    }
    
    auto test_method_(volume_up) {
      assert::are_equal(175, enum_object<>::to_int32(console_key::volume_up));
      assert::are_equal("volume_up", enum_object<>::to_string(console_key::volume_up));
      assert::are_equal(console_key::volume_up, enum_object<>::parse<console_key>("volume_up"));
    }
    
    auto test_method_(media_next) {
      assert::are_equal(176, enum_object<>::to_int32(console_key::media_next));
      assert::are_equal("media_next", enum_object<>::to_string(console_key::media_next));
      assert::are_equal(console_key::media_next, enum_object<>::parse<console_key>("media_next"));
    }
    
    auto test_method_(media_previous) {
      assert::are_equal(177, enum_object<>::to_int32(console_key::media_previous));
      assert::are_equal("media_previous", enum_object<>::to_string(console_key::media_previous));
      assert::are_equal(console_key::media_previous, enum_object<>::parse<console_key>("media_previous"));
    }
    
    auto test_method_(media_stop) {
      assert::are_equal(178, enum_object<>::to_int32(console_key::media_stop));
      assert::are_equal("media_stop", enum_object<>::to_string(console_key::media_stop));
      assert::are_equal(console_key::media_stop, enum_object<>::parse<console_key>("media_stop"));
    }
    
    auto test_method_(media_play) {
      assert::are_equal(179, enum_object<>::to_int32(console_key::media_play));
      assert::are_equal("media_play", enum_object<>::to_string(console_key::media_play));
      assert::are_equal(console_key::media_play, enum_object<>::parse<console_key>("media_play"));
    }
    
    auto test_method_(launch_mail) {
      assert::are_equal(180, enum_object<>::to_int32(console_key::launch_mail));
      assert::are_equal("launch_mail", enum_object<>::to_string(console_key::launch_mail));
      assert::are_equal(console_key::launch_mail, enum_object<>::parse<console_key>("launch_mail"));
    }
    
    auto test_method_(launch_media_select) {
      assert::are_equal(181, enum_object<>::to_int32(console_key::launch_media_select));
      assert::are_equal("launch_media_select", enum_object<>::to_string(console_key::launch_media_select));
      assert::are_equal(console_key::launch_media_select, enum_object<>::parse<console_key>("launch_media_select"));
    }
    
    auto test_method_(launch_app1) {
      assert::are_equal(182, enum_object<>::to_int32(console_key::launch_app1));
      assert::are_equal("launch_app1", enum_object<>::to_string(console_key::launch_app1));
      assert::are_equal(console_key::launch_app1, enum_object<>::parse<console_key>("launch_app1"));
    }
    
    auto test_method_(launch_app2) {
      assert::are_equal(183, enum_object<>::to_int32(console_key::launch_app2));
      assert::are_equal("launch_app2", enum_object<>::to_string(console_key::launch_app2));
      assert::are_equal(console_key::launch_app2, enum_object<>::parse<console_key>("launch_app2"));
    }
    
    auto test_method_(oem1) {
      assert::are_equal(186, enum_object<>::to_int32(console_key::oem1));
      assert::are_equal("oem1", enum_object<>::to_string(console_key::oem1));
      assert::are_equal(console_key::oem1, enum_object<>::parse<console_key>("oem1"));
    }
    
    auto test_method_(oem_plus) {
      assert::are_equal(187, enum_object<>::to_int32(console_key::oem_plus));
      assert::are_equal("oem_plus", enum_object<>::to_string(console_key::oem_plus));
      assert::are_equal(console_key::oem_plus, enum_object<>::parse<console_key>("oem_plus"));
    }
    
    auto test_method_(oem_comma) {
      assert::are_equal(188, enum_object<>::to_int32(console_key::oem_comma));
      assert::are_equal("oem_comma", enum_object<>::to_string(console_key::oem_comma));
      assert::are_equal(console_key::oem_comma, enum_object<>::parse<console_key>("oem_comma"));
    }
    
    auto test_method_(oem_minus) {
      assert::are_equal(189, enum_object<>::to_int32(console_key::oem_minus));
      assert::are_equal("oem_minus", enum_object<>::to_string(console_key::oem_minus));
      assert::are_equal(console_key::oem_minus, enum_object<>::parse<console_key>("oem_minus"));
    }
    
    auto test_method_(oem_period) {
      assert::are_equal(190, enum_object<>::to_int32(console_key::oem_period));
      assert::are_equal("oem_period", enum_object<>::to_string(console_key::oem_period));
      assert::are_equal(console_key::oem_period, enum_object<>::parse<console_key>("oem_period"));
    }
    
    auto test_method_(oem2) {
      assert::are_equal(191, enum_object<>::to_int32(console_key::oem2));
      assert::are_equal("oem2", enum_object<>::to_string(console_key::oem2));
      assert::are_equal(console_key::oem2, enum_object<>::parse<console_key>("oem2"));
    }
    
    auto test_method_(oem3) {
      assert::are_equal(192, enum_object<>::to_int32(console_key::oem3));
      assert::are_equal("oem3", enum_object<>::to_string(console_key::oem3));
      assert::are_equal(console_key::oem3, enum_object<>::parse<console_key>("oem3"));
    }
    
    auto test_method_(oem4) {
      assert::are_equal(219, enum_object<>::to_int32(console_key::oem4));
      assert::are_equal("oem4", enum_object<>::to_string(console_key::oem4));
      assert::are_equal(console_key::oem4, enum_object<>::parse<console_key>("oem4"));
    }
    
    auto test_method_(oem5) {
      assert::are_equal(220, enum_object<>::to_int32(console_key::oem5));
      assert::are_equal("oem5", enum_object<>::to_string(console_key::oem5));
      assert::are_equal(console_key::oem5, enum_object<>::parse<console_key>("oem5"));
    }
    
    auto test_method_(oem6) {
      assert::are_equal(221, enum_object<>::to_int32(console_key::oem6));
      assert::are_equal("oem6", enum_object<>::to_string(console_key::oem6));
      assert::are_equal(console_key::oem6, enum_object<>::parse<console_key>("oem6"));
    }
    
    auto test_method_(oem7) {
      assert::are_equal(222, enum_object<>::to_int32(console_key::oem7));
      assert::are_equal("oem7", enum_object<>::to_string(console_key::oem7));
      assert::are_equal(console_key::oem7, enum_object<>::parse<console_key>("oem7"));
    }
    
    auto test_method_(oem8) {
      assert::are_equal(223, enum_object<>::to_int32(console_key::oem8));
      assert::are_equal("oem8", enum_object<>::to_string(console_key::oem8));
      assert::are_equal(console_key::oem8, enum_object<>::parse<console_key>("oem8"));
    }
    
    auto test_method_(oem102) {
      assert::are_equal(226, enum_object<>::to_int32(console_key::oem102));
      assert::are_equal("oem102", enum_object<>::to_string(console_key::oem102));
      assert::are_equal(console_key::oem102, enum_object<>::parse<console_key>("oem102"));
    }
    
    auto test_method_(process) {
      assert::are_equal(229, enum_object<>::to_int32(console_key::process));
      assert::are_equal("process", enum_object<>::to_string(console_key::process));
      assert::are_equal(console_key::process, enum_object<>::parse<console_key>("process"));
    }
    
    auto test_method_(packet) {
      assert::are_equal(231, enum_object<>::to_int32(console_key::packet));
      assert::are_equal("packet", enum_object<>::to_string(console_key::packet));
      assert::are_equal(console_key::packet, enum_object<>::parse<console_key>("packet"));
    }
    
    auto test_method_(attention) {
      assert::are_equal(246, enum_object<>::to_int32(console_key::attention));
      assert::are_equal("attention", enum_object<>::to_string(console_key::attention));
      assert::are_equal(console_key::attention, enum_object<>::parse<console_key>("attention"));
    }
    
    auto test_method_(cr_sel) {
      assert::are_equal(247, enum_object<>::to_int32(console_key::cr_sel));
      assert::are_equal("cr_sel", enum_object<>::to_string(console_key::cr_sel));
      assert::are_equal(console_key::cr_sel, enum_object<>::parse<console_key>("cr_sel"));
    }
    
    auto test_method_(ex_sel) {
      assert::are_equal(248, enum_object<>::to_int32(console_key::ex_sel));
      assert::are_equal("ex_sel", enum_object<>::to_string(console_key::ex_sel));
      assert::are_equal(console_key::ex_sel, enum_object<>::parse<console_key>("ex_sel"));
    }
    
    auto test_method_(erase_end_of_file) {
      assert::are_equal(249, enum_object<>::to_int32(console_key::erase_end_of_file));
      assert::are_equal("erase_end_of_file", enum_object<>::to_string(console_key::erase_end_of_file));
      assert::are_equal(console_key::erase_end_of_file, enum_object<>::parse<console_key>("erase_end_of_file"));
    }
    
    auto test_method_(play) {
      assert::are_equal(250, enum_object<>::to_int32(console_key::play));
      assert::are_equal("play", enum_object<>::to_string(console_key::play));
      assert::are_equal(console_key::play, enum_object<>::parse<console_key>("play"));
    }
    
    auto test_method_(zoom) {
      assert::are_equal(251, enum_object<>::to_int32(console_key::zoom));
      assert::are_equal("zoom", enum_object<>::to_string(console_key::zoom));
      assert::are_equal(console_key::zoom, enum_object<>::parse<console_key>("zoom"));
    }
    
    auto test_method_(no_name) {
      assert::are_equal(252, enum_object<>::to_int32(console_key::no_name));
      assert::are_equal("no_name", enum_object<>::to_string(console_key::no_name));
      assert::are_equal(console_key::no_name, enum_object<>::parse<console_key>("no_name"));
    }
    
    auto test_method_(pa1) {
      assert::are_equal(253, enum_object<>::to_int32(console_key::pa1));
      assert::are_equal("pa1", enum_object<>::to_string(console_key::pa1));
      assert::are_equal(console_key::pa1, enum_object<>::parse<console_key>("pa1"));
    }
    
    auto test_method_(oem_clear) {
      assert::are_equal(254, enum_object<>::to_int32(console_key::oem_clear));
      assert::are_equal("oem_clear", enum_object<>::to_string(console_key::oem_clear));
      assert::are_equal(console_key::oem_clear, enum_object<>::parse<console_key>("oem_clear"));
    }
  };
}

