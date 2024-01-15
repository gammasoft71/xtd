#include <xtd/console_key>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(console_key_tests) {
    void test_method_(backspace) {
      assert::are_equal(8, enum_object<>::to_int32(console_key::backspace), csf_);
      assert::are_equal("backspace", enum_object<>::to_string(console_key::backspace), csf_);
      assert::are_equal(console_key::backspace, enum_object<>::parse<console_key>("backspace"), csf_);
    }
    
    void test_method_(tab) {
      assert::are_equal(9, enum_object<>::to_int32(console_key::tab), csf_);
      assert::are_equal("tab", enum_object<>::to_string(console_key::tab), csf_);
      assert::are_equal(console_key::tab, enum_object<>::parse<console_key>("tab"), csf_);
    }
    
    void test_method_(clear) {
      assert::are_equal(12, enum_object<>::to_int32(console_key::clear), csf_);
      assert::are_equal("clear", enum_object<>::to_string(console_key::clear), csf_);
      assert::are_equal(console_key::clear, enum_object<>::parse<console_key>("clear"), csf_);
    }
    
    void test_method_(enter) {
      assert::are_equal(13, enum_object<>::to_int32(console_key::enter), csf_);
      assert::are_equal("enter", enum_object<>::to_string(console_key::enter), csf_);
      assert::are_equal(console_key::enter, enum_object<>::parse<console_key>("enter"), csf_);
    }
    
    void test_method_(pause) {
      assert::are_equal(19, enum_object<>::to_int32(console_key::pause), csf_);
      assert::are_equal("pause", enum_object<>::to_string(console_key::pause), csf_);
      assert::are_equal(console_key::pause, enum_object<>::parse<console_key>("pause"), csf_);
    }
    
    void test_method_(escape) {
      assert::are_equal(27, enum_object<>::to_int32(console_key::escape), csf_);
      assert::are_equal("escape", enum_object<>::to_string(console_key::escape), csf_);
      assert::are_equal(console_key::escape, enum_object<>::parse<console_key>("escape"), csf_);
    }
    
    void test_method_(spacebar) {
      assert::are_equal(32, enum_object<>::to_int32(console_key::spacebar), csf_);
      assert::are_equal("spacebar", enum_object<>::to_string(console_key::spacebar), csf_);
      assert::are_equal(console_key::spacebar, enum_object<>::parse<console_key>("spacebar"), csf_);
    }
    
    void test_method_(page_up) {
      assert::are_equal(33, enum_object<>::to_int32(console_key::page_up), csf_);
      assert::are_equal("page_up", enum_object<>::to_string(console_key::page_up), csf_);
      assert::are_equal(console_key::page_up, enum_object<>::parse<console_key>("page_up"), csf_);
    }
    
    void test_method_(page_down) {
      assert::are_equal(34, enum_object<>::to_int32(console_key::page_down), csf_);
      assert::are_equal("page_down", enum_object<>::to_string(console_key::page_down), csf_);
      assert::are_equal(console_key::page_down, enum_object<>::parse<console_key>("page_down"), csf_);
    }
    
    void test_method_(end) {
      assert::are_equal(35, enum_object<>::to_int32(console_key::end), csf_);
      assert::are_equal("end", enum_object<>::to_string(console_key::end), csf_);
      assert::are_equal(console_key::end, enum_object<>::parse<console_key>("end"), csf_);
    }
    
    void test_method_(home) {
      assert::are_equal(36, enum_object<>::to_int32(console_key::home), csf_);
      assert::are_equal("home", enum_object<>::to_string(console_key::home), csf_);
      assert::are_equal(console_key::home, enum_object<>::parse<console_key>("home"), csf_);
    }
    
    void test_method_(left_arrow) {
      assert::are_equal(37, enum_object<>::to_int32(console_key::left_arrow), csf_);
      assert::are_equal("left_arrow", enum_object<>::to_string(console_key::left_arrow), csf_);
      assert::are_equal(console_key::left_arrow, enum_object<>::parse<console_key>("left_arrow"), csf_);
    }
    
    void test_method_(up_arrow) {
      assert::are_equal(38, enum_object<>::to_int32(console_key::up_arrow), csf_);
      assert::are_equal("up_arrow", enum_object<>::to_string(console_key::up_arrow), csf_);
      assert::are_equal(console_key::up_arrow, enum_object<>::parse<console_key>("up_arrow"), csf_);
    }
    
    void test_method_(right_arrow) {
      assert::are_equal(39, enum_object<>::to_int32(console_key::right_arrow), csf_);
      assert::are_equal("right_arrow", enum_object<>::to_string(console_key::right_arrow), csf_);
      assert::are_equal(console_key::right_arrow, enum_object<>::parse<console_key>("right_arrow"), csf_);
    }
    
    void test_method_(down_arrow) {
      assert::are_equal(40, enum_object<>::to_int32(console_key::down_arrow), csf_);
      assert::are_equal("down_arrow", enum_object<>::to_string(console_key::down_arrow), csf_);
      assert::are_equal(console_key::down_arrow, enum_object<>::parse<console_key>("down_arrow"), csf_);
    }
    
    void test_method_(select) {
      assert::are_equal(41, enum_object<>::to_int32(console_key::select), csf_);
      assert::are_equal("select", enum_object<>::to_string(console_key::select), csf_);
      assert::are_equal(console_key::select, enum_object<>::parse<console_key>("select"), csf_);
    }
    
    void test_method_(print) {
      assert::are_equal(42, enum_object<>::to_int32(console_key::print), csf_);
      assert::are_equal("print", enum_object<>::to_string(console_key::print), csf_);
      assert::are_equal(console_key::print, enum_object<>::parse<console_key>("print"), csf_);
    }
    
    void test_method_(execute) {
      assert::are_equal(43, enum_object<>::to_int32(console_key::execute), csf_);
      assert::are_equal("execute", enum_object<>::to_string(console_key::execute), csf_);
      assert::are_equal(console_key::execute, enum_object<>::parse<console_key>("execute"), csf_);
    }
    
    void test_method_(print_screen) {
      assert::are_equal(44, enum_object<>::to_int32(console_key::print_screen), csf_);
      assert::are_equal("print_screen", enum_object<>::to_string(console_key::print_screen), csf_);
      assert::are_equal(console_key::print_screen, enum_object<>::parse<console_key>("print_screen"), csf_);
    }
    
    void test_method_(insert) {
      assert::are_equal(45, enum_object<>::to_int32(console_key::insert), csf_);
      assert::are_equal("insert", enum_object<>::to_string(console_key::insert), csf_);
      assert::are_equal(console_key::insert, enum_object<>::parse<console_key>("insert"), csf_);
    }
    
    void test_method_(del) {
      assert::are_equal(46, enum_object<>::to_int32(console_key::del), csf_);
      assert::are_equal("del", enum_object<>::to_string(console_key::del), csf_);
      assert::are_equal(console_key::del, enum_object<>::parse<console_key>("del"), csf_);
    }
    
    void test_method_(help) {
      assert::are_equal(47, enum_object<>::to_int32(console_key::help), csf_);
      assert::are_equal("help", enum_object<>::to_string(console_key::help), csf_);
      assert::are_equal(console_key::help, enum_object<>::parse<console_key>("help"), csf_);
    }
    
    void test_method_(d0) {
      assert::are_equal(48, enum_object<>::to_int32(console_key::d0), csf_);
      assert::are_equal("d0", enum_object<>::to_string(console_key::d0), csf_);
      assert::are_equal(console_key::d0, enum_object<>::parse<console_key>("d0"), csf_);
    }
    
    void test_method_(d1) {
      assert::are_equal(49, enum_object<>::to_int32(console_key::d1), csf_);
      assert::are_equal("d1", enum_object<>::to_string(console_key::d1), csf_);
      assert::are_equal(console_key::d1, enum_object<>::parse<console_key>("d1"), csf_);
    }
    
    void test_method_(d2) {
      assert::are_equal(50, enum_object<>::to_int32(console_key::d2), csf_);
      assert::are_equal("d2", enum_object<>::to_string(console_key::d2), csf_);
      assert::are_equal(console_key::d2, enum_object<>::parse<console_key>("d2"), csf_);
    }
    
    void test_method_(d3) {
      assert::are_equal(51, enum_object<>::to_int32(console_key::d3), csf_);
      assert::are_equal("d3", enum_object<>::to_string(console_key::d3), csf_);
      assert::are_equal(console_key::d3, enum_object<>::parse<console_key>("d3"), csf_);
    }
    
    void test_method_(d4) {
      assert::are_equal(52, enum_object<>::to_int32(console_key::d4), csf_);
      assert::are_equal("d4", enum_object<>::to_string(console_key::d4), csf_);
      assert::are_equal(console_key::d4, enum_object<>::parse<console_key>("d4"), csf_);
    }
    
    void test_method_(d5) {
      assert::are_equal(53, enum_object<>::to_int32(console_key::d5), csf_);
      assert::are_equal("d5", enum_object<>::to_string(console_key::d5), csf_);
      assert::are_equal(console_key::d5, enum_object<>::parse<console_key>("d5"), csf_);
    }
    
    void test_method_(d6) {
      assert::are_equal(54, enum_object<>::to_int32(console_key::d6), csf_);
      assert::are_equal("d6", enum_object<>::to_string(console_key::d6), csf_);
      assert::are_equal(console_key::d6, enum_object<>::parse<console_key>("d6"), csf_);
    }
    
    void test_method_(d7) {
      assert::are_equal(55, enum_object<>::to_int32(console_key::d7), csf_);
      assert::are_equal("d7", enum_object<>::to_string(console_key::d7), csf_);
      assert::are_equal(console_key::d7, enum_object<>::parse<console_key>("d7"), csf_);
    }
    
    void test_method_(d8) {
      assert::are_equal(56, enum_object<>::to_int32(console_key::d8), csf_);
      assert::are_equal("d8", enum_object<>::to_string(console_key::d8), csf_);
      assert::are_equal(console_key::d8, enum_object<>::parse<console_key>("d8"), csf_);
    }
    
    void test_method_(d9) {
      assert::are_equal(57, enum_object<>::to_int32(console_key::d9), csf_);
      assert::are_equal("d9", enum_object<>::to_string(console_key::d9), csf_);
      assert::are_equal(console_key::d9, enum_object<>::parse<console_key>("d9"), csf_);
    }
    
    void test_method_(a) {
      assert::are_equal(65, enum_object<>::to_int32(console_key::a), csf_);
      assert::are_equal("a", enum_object<>::to_string(console_key::a), csf_);
      assert::are_equal(console_key::a, enum_object<>::parse<console_key>("a"), csf_);
    }
    
    void test_method_(b) {
      assert::are_equal(66, enum_object<>::to_int32(console_key::b), csf_);
      assert::are_equal("b", enum_object<>::to_string(console_key::b), csf_);
      assert::are_equal(console_key::b, enum_object<>::parse<console_key>("b"), csf_);
    }
    
    void test_method_(c) {
      assert::are_equal(67, enum_object<>::to_int32(console_key::c), csf_);
      assert::are_equal("c", enum_object<>::to_string(console_key::c), csf_);
      assert::are_equal(console_key::c, enum_object<>::parse<console_key>("c"), csf_);
    }
    
    void test_method_(d) {
      assert::are_equal(68, enum_object<>::to_int32(console_key::d), csf_);
      assert::are_equal("d", enum_object<>::to_string(console_key::d), csf_);
      assert::are_equal(console_key::d, enum_object<>::parse<console_key>("d"), csf_);
    }
    
    void test_method_(e) {
      assert::are_equal(69, enum_object<>::to_int32(console_key::e), csf_);
      assert::are_equal("e", enum_object<>::to_string(console_key::e), csf_);
      assert::are_equal(console_key::e, enum_object<>::parse<console_key>("e"), csf_);
    }
    
    void test_method_(f) {
      assert::are_equal(70, enum_object<>::to_int32(console_key::f), csf_);
      assert::are_equal("f", enum_object<>::to_string(console_key::f), csf_);
      assert::are_equal(console_key::f, enum_object<>::parse<console_key>("f"), csf_);
    }
    
    void test_method_(g) {
      assert::are_equal(71, enum_object<>::to_int32(console_key::g), csf_);
      assert::are_equal("g", enum_object<>::to_string(console_key::g), csf_);
      assert::are_equal(console_key::g, enum_object<>::parse<console_key>("g"), csf_);
    }
    
    void test_method_(h) {
      assert::are_equal(72, enum_object<>::to_int32(console_key::h), csf_);
      assert::are_equal("h", enum_object<>::to_string(console_key::h), csf_);
      assert::are_equal(console_key::h, enum_object<>::parse<console_key>("h"), csf_);
    }
    
    void test_method_(i) {
      assert::are_equal(73, enum_object<>::to_int32(console_key::i), csf_);
      assert::are_equal("i", enum_object<>::to_string(console_key::i), csf_);
      assert::are_equal(console_key::i, enum_object<>::parse<console_key>("i"), csf_);
    }
    
    void test_method_(j) {
      assert::are_equal(74, enum_object<>::to_int32(console_key::j), csf_);
      assert::are_equal("j", enum_object<>::to_string(console_key::j), csf_);
      assert::are_equal(console_key::j, enum_object<>::parse<console_key>("j"), csf_);
    }
    
    void test_method_(k) {
      assert::are_equal(75, enum_object<>::to_int32(console_key::k), csf_);
      assert::are_equal("k", enum_object<>::to_string(console_key::k), csf_);
      assert::are_equal(console_key::k, enum_object<>::parse<console_key>("k"), csf_);
    }
    
    void test_method_(l) {
      assert::are_equal(76, enum_object<>::to_int32(console_key::l), csf_);
      assert::are_equal("l", enum_object<>::to_string(console_key::l), csf_);
      assert::are_equal(console_key::l, enum_object<>::parse<console_key>("l"), csf_);
    }
    
    void test_method_(m) {
      assert::are_equal(77, enum_object<>::to_int32(console_key::m), csf_);
      assert::are_equal("m", enum_object<>::to_string(console_key::m), csf_);
      assert::are_equal(console_key::m, enum_object<>::parse<console_key>("m"), csf_);
    }
    
    void test_method_(n) {
      assert::are_equal(78, enum_object<>::to_int32(console_key::n), csf_);
      assert::are_equal("n", enum_object<>::to_string(console_key::n), csf_);
      assert::are_equal(console_key::n, enum_object<>::parse<console_key>("n"), csf_);
    }
    
    void test_method_(o) {
      assert::are_equal(79, enum_object<>::to_int32(console_key::o), csf_);
      assert::are_equal("o", enum_object<>::to_string(console_key::o), csf_);
      assert::are_equal(console_key::o, enum_object<>::parse<console_key>("o"), csf_);
    }
    
    void test_method_(p) {
      assert::are_equal(80, enum_object<>::to_int32(console_key::p), csf_);
      assert::are_equal("p", enum_object<>::to_string(console_key::p), csf_);
      assert::are_equal(console_key::p, enum_object<>::parse<console_key>("p"), csf_);
    }
    
    void test_method_(q) {
      assert::are_equal(81, enum_object<>::to_int32(console_key::q), csf_);
      assert::are_equal("q", enum_object<>::to_string(console_key::q), csf_);
      assert::are_equal(console_key::q, enum_object<>::parse<console_key>("q"), csf_);
    }
    
    void test_method_(r) {
      assert::are_equal(82, enum_object<>::to_int32(console_key::r), csf_);
      assert::are_equal("r", enum_object<>::to_string(console_key::r), csf_);
      assert::are_equal(console_key::r, enum_object<>::parse<console_key>("r"), csf_);
    }
    
    void test_method_(s) {
      assert::are_equal(83, enum_object<>::to_int32(console_key::s), csf_);
      assert::are_equal("s", enum_object<>::to_string(console_key::s), csf_);
      assert::are_equal(console_key::s, enum_object<>::parse<console_key>("s"), csf_);
    }
    
    void test_method_(t) {
      assert::are_equal(84, enum_object<>::to_int32(console_key::t), csf_);
      assert::are_equal("t", enum_object<>::to_string(console_key::t), csf_);
      assert::are_equal(console_key::t, enum_object<>::parse<console_key>("t"), csf_);
    }
    
    void test_method_(u) {
      assert::are_equal(85, enum_object<>::to_int32(console_key::u), csf_);
      assert::are_equal("u", enum_object<>::to_string(console_key::u), csf_);
      assert::are_equal(console_key::u, enum_object<>::parse<console_key>("u"), csf_);
    }
    
    void test_method_(v) {
      assert::are_equal(86, enum_object<>::to_int32(console_key::v), csf_);
      assert::are_equal("v", enum_object<>::to_string(console_key::v), csf_);
      assert::are_equal(console_key::v, enum_object<>::parse<console_key>("v"), csf_);
    }
    
    void test_method_(w) {
      assert::are_equal(87, enum_object<>::to_int32(console_key::w), csf_);
      assert::are_equal("w", enum_object<>::to_string(console_key::w), csf_);
      assert::are_equal(console_key::w, enum_object<>::parse<console_key>("w"), csf_);
    }
    
    void test_method_(x) {
      assert::are_equal(88, enum_object<>::to_int32(console_key::x), csf_);
      assert::are_equal("x", enum_object<>::to_string(console_key::x), csf_);
      assert::are_equal(console_key::x, enum_object<>::parse<console_key>("x"), csf_);
    }
    
    void test_method_(y) {
      assert::are_equal(89, enum_object<>::to_int32(console_key::y), csf_);
      assert::are_equal("y", enum_object<>::to_string(console_key::y), csf_);
      assert::are_equal(console_key::y, enum_object<>::parse<console_key>("y"), csf_);
    }
    
    void test_method_(z) {
      assert::are_equal(90, enum_object<>::to_int32(console_key::z), csf_);
      assert::are_equal("z", enum_object<>::to_string(console_key::z), csf_);
      assert::are_equal(console_key::z, enum_object<>::parse<console_key>("z"), csf_);
    }
    
    void test_method_(left_windows) {
      assert::are_equal(91, enum_object<>::to_int32(console_key::left_windows), csf_);
      assert::are_equal("left_windows", enum_object<>::to_string(console_key::left_windows), csf_);
      assert::are_equal(console_key::left_windows, enum_object<>::parse<console_key>("left_windows"), csf_);
    }
    
    void test_method_(right_windows) {
      assert::are_equal(92, enum_object<>::to_int32(console_key::right_windows), csf_);
      assert::are_equal("right_windows", enum_object<>::to_string(console_key::right_windows), csf_);
      assert::are_equal(console_key::right_windows, enum_object<>::parse<console_key>("right_windows"), csf_);
    }
    
    void test_method_(applications) {
      assert::are_equal(93, enum_object<>::to_int32(console_key::applications), csf_);
      assert::are_equal("applications", enum_object<>::to_string(console_key::applications), csf_);
      assert::are_equal(console_key::applications, enum_object<>::parse<console_key>("applications"), csf_);
    }
    
    void test_method_(sleep) {
      assert::are_equal(95, enum_object<>::to_int32(console_key::sleep), csf_);
      assert::are_equal("sleep", enum_object<>::to_string(console_key::sleep), csf_);
      assert::are_equal(console_key::sleep, enum_object<>::parse<console_key>("sleep"), csf_);
    }
    
    void test_method_(num_pad_0) {
      assert::are_equal(96, enum_object<>::to_int32(console_key::num_pad_0), csf_);
      assert::are_equal("num_pad_0", enum_object<>::to_string(console_key::num_pad_0), csf_);
      assert::are_equal(console_key::num_pad_0, enum_object<>::parse<console_key>("num_pad_0"), csf_);
    }
    
    void test_method_(num_pad_1) {
      assert::are_equal(97, enum_object<>::to_int32(console_key::num_pad_1), csf_);
      assert::are_equal("num_pad_1", enum_object<>::to_string(console_key::num_pad_1), csf_);
      assert::are_equal(console_key::num_pad_1, enum_object<>::parse<console_key>("num_pad_1"), csf_);
    }
    
    void test_method_(num_pad_2) {
      assert::are_equal(98, enum_object<>::to_int32(console_key::num_pad_2), csf_);
      assert::are_equal("num_pad_2", enum_object<>::to_string(console_key::num_pad_2), csf_);
      assert::are_equal(console_key::num_pad_2, enum_object<>::parse<console_key>("num_pad_2"), csf_);
    }
    
    void test_method_(num_pad_3) {
      assert::are_equal(99, enum_object<>::to_int32(console_key::num_pad_3), csf_);
      assert::are_equal("num_pad_3", enum_object<>::to_string(console_key::num_pad_3), csf_);
      assert::are_equal(console_key::num_pad_3, enum_object<>::parse<console_key>("num_pad_3"), csf_);
    }
    
    void test_method_(num_pad_4) {
      assert::are_equal(100, enum_object<>::to_int32(console_key::num_pad_4), csf_);
      assert::are_equal("num_pad_4", enum_object<>::to_string(console_key::num_pad_4), csf_);
      assert::are_equal(console_key::num_pad_4, enum_object<>::parse<console_key>("num_pad_4"), csf_);
    }
    
    void test_method_(num_pad_5) {
      assert::are_equal(101, enum_object<>::to_int32(console_key::num_pad_5), csf_);
      assert::are_equal("num_pad_5", enum_object<>::to_string(console_key::num_pad_5), csf_);
      assert::are_equal(console_key::num_pad_5, enum_object<>::parse<console_key>("num_pad_5"), csf_);
    }
    
    void test_method_(num_pad_6) {
      assert::are_equal(102, enum_object<>::to_int32(console_key::num_pad_6), csf_);
      assert::are_equal("num_pad_6", enum_object<>::to_string(console_key::num_pad_6), csf_);
      assert::are_equal(console_key::num_pad_6, enum_object<>::parse<console_key>("num_pad_6"), csf_);
    }
    
    void test_method_(num_pad_7) {
      assert::are_equal(103, enum_object<>::to_int32(console_key::num_pad_7), csf_);
      assert::are_equal("num_pad_7", enum_object<>::to_string(console_key::num_pad_7), csf_);
      assert::are_equal(console_key::num_pad_7, enum_object<>::parse<console_key>("num_pad_7"), csf_);
    }
    
    void test_method_(num_pad_8) {
      assert::are_equal(104, enum_object<>::to_int32(console_key::num_pad_8), csf_);
      assert::are_equal("num_pad_8", enum_object<>::to_string(console_key::num_pad_8), csf_);
      assert::are_equal(console_key::num_pad_8, enum_object<>::parse<console_key>("num_pad_8"), csf_);
    }
    
    void test_method_(num_pad_9) {
      assert::are_equal(105, enum_object<>::to_int32(console_key::num_pad_9), csf_);
      assert::are_equal("num_pad_9", enum_object<>::to_string(console_key::num_pad_9), csf_);
      assert::are_equal(console_key::num_pad_9, enum_object<>::parse<console_key>("num_pad_9"), csf_);
    }
    
    void test_method_(multiply) {
      assert::are_equal(106, enum_object<>::to_int32(console_key::multiply), csf_);
      assert::are_equal("multiply", enum_object<>::to_string(console_key::multiply), csf_);
      assert::are_equal(console_key::multiply, enum_object<>::parse<console_key>("multiply"), csf_);
    }
    
    void test_method_(add) {
      assert::are_equal(107, enum_object<>::to_int32(console_key::add), csf_);
      assert::are_equal("add", enum_object<>::to_string(console_key::add), csf_);
      assert::are_equal(console_key::add, enum_object<>::parse<console_key>("add"), csf_);
    }
    
    void test_method_(separator) {
      assert::are_equal(108, enum_object<>::to_int32(console_key::separator), csf_);
      assert::are_equal("separator", enum_object<>::to_string(console_key::separator), csf_);
      assert::are_equal(console_key::separator, enum_object<>::parse<console_key>("separator"), csf_);
    }
    
    void test_method_(subtract) {
      assert::are_equal(109, enum_object<>::to_int32(console_key::subtract), csf_);
      assert::are_equal("subtract", enum_object<>::to_string(console_key::subtract), csf_);
      assert::are_equal(console_key::subtract, enum_object<>::parse<console_key>("subtract"), csf_);
    }
    
    void test_method_(decimal) {
      assert::are_equal(110, enum_object<>::to_int32(console_key::decimal), csf_);
      assert::are_equal("decimal", enum_object<>::to_string(console_key::decimal), csf_);
      assert::are_equal(console_key::decimal, enum_object<>::parse<console_key>("decimal"), csf_);
    }
    
    void test_method_(divide) {
      assert::are_equal(111, enum_object<>::to_int32(console_key::divide), csf_);
      assert::are_equal("divide", enum_object<>::to_string(console_key::divide), csf_);
      assert::are_equal(console_key::divide, enum_object<>::parse<console_key>("divide"), csf_);
    }
    
    void test_method_(f1) {
      assert::are_equal(112, enum_object<>::to_int32(console_key::f1), csf_);
      assert::are_equal("f1", enum_object<>::to_string(console_key::f1), csf_);
      assert::are_equal(console_key::f1, enum_object<>::parse<console_key>("f1"), csf_);
    }
    
    void test_method_(f2) {
      assert::are_equal(113, enum_object<>::to_int32(console_key::f2), csf_);
      assert::are_equal("f2", enum_object<>::to_string(console_key::f2), csf_);
      assert::are_equal(console_key::f2, enum_object<>::parse<console_key>("f2"), csf_);
    }
    
    void test_method_(f3) {
      assert::are_equal(114, enum_object<>::to_int32(console_key::f3), csf_);
      assert::are_equal("f3", enum_object<>::to_string(console_key::f3), csf_);
      assert::are_equal(console_key::f3, enum_object<>::parse<console_key>("f3"), csf_);
    }
    
    void test_method_(f4) {
      assert::are_equal(115, enum_object<>::to_int32(console_key::f4), csf_);
      assert::are_equal("f4", enum_object<>::to_string(console_key::f4), csf_);
      assert::are_equal(console_key::f4, enum_object<>::parse<console_key>("f4"), csf_);
    }
    
    void test_method_(f5) {
      assert::are_equal(116, enum_object<>::to_int32(console_key::f5), csf_);
      assert::are_equal("f5", enum_object<>::to_string(console_key::f5), csf_);
      assert::are_equal(console_key::f5, enum_object<>::parse<console_key>("f5"), csf_);
    }
    
    void test_method_(f6) {
      assert::are_equal(117, enum_object<>::to_int32(console_key::f6), csf_);
      assert::are_equal("f6", enum_object<>::to_string(console_key::f6), csf_);
      assert::are_equal(console_key::f6, enum_object<>::parse<console_key>("f6"), csf_);
    }
    
    void test_method_(f7) {
      assert::are_equal(118, enum_object<>::to_int32(console_key::f7), csf_);
      assert::are_equal("f7", enum_object<>::to_string(console_key::f7), csf_);
      assert::are_equal(console_key::f7, enum_object<>::parse<console_key>("f7"), csf_);
    }
    
    void test_method_(f8) {
      assert::are_equal(119, enum_object<>::to_int32(console_key::f8), csf_);
      assert::are_equal("f8", enum_object<>::to_string(console_key::f8), csf_);
      assert::are_equal(console_key::f8, enum_object<>::parse<console_key>("f8"), csf_);
    }
    
    void test_method_(f9) {
      assert::are_equal(120, enum_object<>::to_int32(console_key::f9), csf_);
      assert::are_equal("f9", enum_object<>::to_string(console_key::f9), csf_);
      assert::are_equal(console_key::f9, enum_object<>::parse<console_key>("f9"), csf_);
    }
    
    void test_method_(f10) {
      assert::are_equal(121, enum_object<>::to_int32(console_key::f10), csf_);
      assert::are_equal("f10", enum_object<>::to_string(console_key::f10), csf_);
      assert::are_equal(console_key::f10, enum_object<>::parse<console_key>("f10"), csf_);
    }
    
    void test_method_(f11) {
      assert::are_equal(122, enum_object<>::to_int32(console_key::f11), csf_);
      assert::are_equal("f11", enum_object<>::to_string(console_key::f11), csf_);
      assert::are_equal(console_key::f11, enum_object<>::parse<console_key>("f11"), csf_);
    }
    
    void test_method_(f12) {
      assert::are_equal(123, enum_object<>::to_int32(console_key::f12), csf_);
      assert::are_equal("f12", enum_object<>::to_string(console_key::f12), csf_);
      assert::are_equal(console_key::f12, enum_object<>::parse<console_key>("f12"), csf_);
    }
    
    void test_method_(f13) {
      assert::are_equal(124, enum_object<>::to_int32(console_key::f13), csf_);
      assert::are_equal("f13", enum_object<>::to_string(console_key::f13), csf_);
      assert::are_equal(console_key::f13, enum_object<>::parse<console_key>("f13"), csf_);
    }
    
    void test_method_(f14) {
      assert::are_equal(125, enum_object<>::to_int32(console_key::f14), csf_);
      assert::are_equal("f14", enum_object<>::to_string(console_key::f14), csf_);
      assert::are_equal(console_key::f14, enum_object<>::parse<console_key>("f14"), csf_);
    }
    
    void test_method_(f15) {
      assert::are_equal(126, enum_object<>::to_int32(console_key::f15), csf_);
      assert::are_equal("f15", enum_object<>::to_string(console_key::f15), csf_);
      assert::are_equal(console_key::f15, enum_object<>::parse<console_key>("f15"), csf_);
    }
    
    void test_method_(f16) {
      assert::are_equal(127, enum_object<>::to_int32(console_key::f16), csf_);
      assert::are_equal("f16", enum_object<>::to_string(console_key::f16), csf_);
      assert::are_equal(console_key::f16, enum_object<>::parse<console_key>("f16"), csf_);
    }
    
    void test_method_(f17) {
      assert::are_equal(128, enum_object<>::to_int32(console_key::f17), csf_);
      assert::are_equal("f17", enum_object<>::to_string(console_key::f17), csf_);
      assert::are_equal(console_key::f17, enum_object<>::parse<console_key>("f17"), csf_);
    }
    
    void test_method_(f18) {
      assert::are_equal(129, enum_object<>::to_int32(console_key::f18), csf_);
      assert::are_equal("f18", enum_object<>::to_string(console_key::f18), csf_);
      assert::are_equal(console_key::f18, enum_object<>::parse<console_key>("f18"), csf_);
    }
    
    void test_method_(f19) {
      assert::are_equal(130, enum_object<>::to_int32(console_key::f19), csf_);
      assert::are_equal("f19", enum_object<>::to_string(console_key::f19), csf_);
      assert::are_equal(console_key::f19, enum_object<>::parse<console_key>("f19"), csf_);
    }
    
    void test_method_(f20) {
      assert::are_equal(131, enum_object<>::to_int32(console_key::f20), csf_);
      assert::are_equal("f20", enum_object<>::to_string(console_key::f20), csf_);
      assert::are_equal(console_key::f20, enum_object<>::parse<console_key>("f20"), csf_);
    }
    
    void test_method_(f21) {
      assert::are_equal(132, enum_object<>::to_int32(console_key::f21), csf_);
      assert::are_equal("f21", enum_object<>::to_string(console_key::f21), csf_);
      assert::are_equal(console_key::f21, enum_object<>::parse<console_key>("f21"), csf_);
    }
    
    void test_method_(f22) {
      assert::are_equal(133, enum_object<>::to_int32(console_key::f22), csf_);
      assert::are_equal("f22", enum_object<>::to_string(console_key::f22), csf_);
      assert::are_equal(console_key::f22, enum_object<>::parse<console_key>("f22"), csf_);
    }
    
    void test_method_(f23) {
      assert::are_equal(134, enum_object<>::to_int32(console_key::f23), csf_);
      assert::are_equal("f23", enum_object<>::to_string(console_key::f23), csf_);
      assert::are_equal(console_key::f23, enum_object<>::parse<console_key>("f23"), csf_);
    }
    
    void test_method_(f24) {
      assert::are_equal(135, enum_object<>::to_int32(console_key::f24), csf_);
      assert::are_equal("f24", enum_object<>::to_string(console_key::f24), csf_);
      assert::are_equal(console_key::f24, enum_object<>::parse<console_key>("f24"), csf_);
    }
    
    void test_method_(browser_back) {
      assert::are_equal(166, enum_object<>::to_int32(console_key::browser_back), csf_);
      assert::are_equal("browser_back", enum_object<>::to_string(console_key::browser_back), csf_);
      assert::are_equal(console_key::browser_back, enum_object<>::parse<console_key>("browser_back"), csf_);
    }
    
    void test_method_(browser_forward) {
      assert::are_equal(167, enum_object<>::to_int32(console_key::browser_forward), csf_);
      assert::are_equal("browser_forward", enum_object<>::to_string(console_key::browser_forward), csf_);
      assert::are_equal(console_key::browser_forward, enum_object<>::parse<console_key>("browser_forward"), csf_);
    }
    
    void test_method_(browser_refresh) {
      assert::are_equal(168, enum_object<>::to_int32(console_key::browser_refresh), csf_);
      assert::are_equal("browser_refresh", enum_object<>::to_string(console_key::browser_refresh), csf_);
      assert::are_equal(console_key::browser_refresh, enum_object<>::parse<console_key>("browser_refresh"), csf_);
    }
    
    void test_method_(browser_stop) {
      assert::are_equal(169, enum_object<>::to_int32(console_key::browser_stop), csf_);
      assert::are_equal("browser_stop", enum_object<>::to_string(console_key::browser_stop), csf_);
      assert::are_equal(console_key::browser_stop, enum_object<>::parse<console_key>("browser_stop"), csf_);
    }
    
    void test_method_(browser_search) {
      assert::are_equal(170, enum_object<>::to_int32(console_key::browser_search), csf_);
      assert::are_equal("browser_search", enum_object<>::to_string(console_key::browser_search), csf_);
      assert::are_equal(console_key::browser_search, enum_object<>::parse<console_key>("browser_search"), csf_);
    }
    
    void test_method_(browser_favorites) {
      assert::are_equal(171, enum_object<>::to_int32(console_key::browser_favorites), csf_);
      assert::are_equal("browser_favorites", enum_object<>::to_string(console_key::browser_favorites), csf_);
      assert::are_equal(console_key::browser_favorites, enum_object<>::parse<console_key>("browser_favorites"), csf_);
    }
    
    void test_method_(browser_home) {
      assert::are_equal(172, enum_object<>::to_int32(console_key::browser_home), csf_);
      assert::are_equal("browser_home", enum_object<>::to_string(console_key::browser_home), csf_);
      assert::are_equal(console_key::browser_home, enum_object<>::parse<console_key>("browser_home"), csf_);
    }
    
    void test_method_(volume_mute) {
      assert::are_equal(173, enum_object<>::to_int32(console_key::volume_mute), csf_);
      assert::are_equal("volume_mute", enum_object<>::to_string(console_key::volume_mute), csf_);
      assert::are_equal(console_key::volume_mute, enum_object<>::parse<console_key>("volume_mute"), csf_);
    }
    
    void test_method_(volume_down) {
      assert::are_equal(174, enum_object<>::to_int32(console_key::volume_down), csf_);
      assert::are_equal("volume_down", enum_object<>::to_string(console_key::volume_down), csf_);
      assert::are_equal(console_key::volume_down, enum_object<>::parse<console_key>("volume_down"), csf_);
    }
    
    void test_method_(volume_up) {
      assert::are_equal(175, enum_object<>::to_int32(console_key::volume_up), csf_);
      assert::are_equal("volume_up", enum_object<>::to_string(console_key::volume_up), csf_);
      assert::are_equal(console_key::volume_up, enum_object<>::parse<console_key>("volume_up"), csf_);
    }
    
    void test_method_(media_next) {
      assert::are_equal(176, enum_object<>::to_int32(console_key::media_next), csf_);
      assert::are_equal("media_next", enum_object<>::to_string(console_key::media_next), csf_);
      assert::are_equal(console_key::media_next, enum_object<>::parse<console_key>("media_next"), csf_);
    }
    
    void test_method_(media_previous) {
      assert::are_equal(177, enum_object<>::to_int32(console_key::media_previous), csf_);
      assert::are_equal("media_previous", enum_object<>::to_string(console_key::media_previous), csf_);
      assert::are_equal(console_key::media_previous, enum_object<>::parse<console_key>("media_previous"), csf_);
    }
    
    void test_method_(media_stop) {
      assert::are_equal(178, enum_object<>::to_int32(console_key::media_stop), csf_);
      assert::are_equal("media_stop", enum_object<>::to_string(console_key::media_stop), csf_);
      assert::are_equal(console_key::media_stop, enum_object<>::parse<console_key>("media_stop"), csf_);
    }
    
    void test_method_(media_play) {
      assert::are_equal(179, enum_object<>::to_int32(console_key::media_play), csf_);
      assert::are_equal("media_play", enum_object<>::to_string(console_key::media_play), csf_);
      assert::are_equal(console_key::media_play, enum_object<>::parse<console_key>("media_play"), csf_);
    }
    
    void test_method_(launch_mail) {
      assert::are_equal(180, enum_object<>::to_int32(console_key::launch_mail), csf_);
      assert::are_equal("launch_mail", enum_object<>::to_string(console_key::launch_mail), csf_);
      assert::are_equal(console_key::launch_mail, enum_object<>::parse<console_key>("launch_mail"), csf_);
    }
    
    void test_method_(launch_media_select) {
      assert::are_equal(181, enum_object<>::to_int32(console_key::launch_media_select), csf_);
      assert::are_equal("launch_media_select", enum_object<>::to_string(console_key::launch_media_select), csf_);
      assert::are_equal(console_key::launch_media_select, enum_object<>::parse<console_key>("launch_media_select"), csf_);
    }
    
    void test_method_(launch_app1) {
      assert::are_equal(182, enum_object<>::to_int32(console_key::launch_app1), csf_);
      assert::are_equal("launch_app1", enum_object<>::to_string(console_key::launch_app1), csf_);
      assert::are_equal(console_key::launch_app1, enum_object<>::parse<console_key>("launch_app1"), csf_);
    }
    
    void test_method_(launch_app2) {
      assert::are_equal(183, enum_object<>::to_int32(console_key::launch_app2), csf_);
      assert::are_equal("launch_app2", enum_object<>::to_string(console_key::launch_app2), csf_);
      assert::are_equal(console_key::launch_app2, enum_object<>::parse<console_key>("launch_app2"), csf_);
    }
    
    void test_method_(oem1) {
      assert::are_equal(186, enum_object<>::to_int32(console_key::oem1), csf_);
      assert::are_equal("oem1", enum_object<>::to_string(console_key::oem1), csf_);
      assert::are_equal(console_key::oem1, enum_object<>::parse<console_key>("oem1"), csf_);
    }
    
    void test_method_(oem_plus) {
      assert::are_equal(187, enum_object<>::to_int32(console_key::oem_plus), csf_);
      assert::are_equal("oem_plus", enum_object<>::to_string(console_key::oem_plus), csf_);
      assert::are_equal(console_key::oem_plus, enum_object<>::parse<console_key>("oem_plus"), csf_);
    }
    
    void test_method_(oem_comma) {
      assert::are_equal(188, enum_object<>::to_int32(console_key::oem_comma), csf_);
      assert::are_equal("oem_comma", enum_object<>::to_string(console_key::oem_comma), csf_);
      assert::are_equal(console_key::oem_comma, enum_object<>::parse<console_key>("oem_comma"), csf_);
    }
    
    void test_method_(oem_minus) {
      assert::are_equal(189, enum_object<>::to_int32(console_key::oem_minus), csf_);
      assert::are_equal("oem_minus", enum_object<>::to_string(console_key::oem_minus), csf_);
      assert::are_equal(console_key::oem_minus, enum_object<>::parse<console_key>("oem_minus"), csf_);
    }
    
    void test_method_(oem_period) {
      assert::are_equal(190, enum_object<>::to_int32(console_key::oem_period), csf_);
      assert::are_equal("oem_period", enum_object<>::to_string(console_key::oem_period), csf_);
      assert::are_equal(console_key::oem_period, enum_object<>::parse<console_key>("oem_period"), csf_);
    }
    
    void test_method_(oem2) {
      assert::are_equal(191, enum_object<>::to_int32(console_key::oem2), csf_);
      assert::are_equal("oem2", enum_object<>::to_string(console_key::oem2), csf_);
      assert::are_equal(console_key::oem2, enum_object<>::parse<console_key>("oem2"), csf_);
    }
    
    void test_method_(oem3) {
      assert::are_equal(192, enum_object<>::to_int32(console_key::oem3), csf_);
      assert::are_equal("oem3", enum_object<>::to_string(console_key::oem3), csf_);
      assert::are_equal(console_key::oem3, enum_object<>::parse<console_key>("oem3"), csf_);
    }
    
    void test_method_(oem4) {
      assert::are_equal(219, enum_object<>::to_int32(console_key::oem4), csf_);
      assert::are_equal("oem4", enum_object<>::to_string(console_key::oem4), csf_);
      assert::are_equal(console_key::oem4, enum_object<>::parse<console_key>("oem4"), csf_);
    }
    
    void test_method_(oem5) {
      assert::are_equal(220, enum_object<>::to_int32(console_key::oem5), csf_);
      assert::are_equal("oem5", enum_object<>::to_string(console_key::oem5), csf_);
      assert::are_equal(console_key::oem5, enum_object<>::parse<console_key>("oem5"), csf_);
    }
    
    void test_method_(oem6) {
      assert::are_equal(221, enum_object<>::to_int32(console_key::oem6), csf_);
      assert::are_equal("oem6", enum_object<>::to_string(console_key::oem6), csf_);
      assert::are_equal(console_key::oem6, enum_object<>::parse<console_key>("oem6"), csf_);
    }
    
    void test_method_(oem7) {
      assert::are_equal(222, enum_object<>::to_int32(console_key::oem7), csf_);
      assert::are_equal("oem7", enum_object<>::to_string(console_key::oem7), csf_);
      assert::are_equal(console_key::oem7, enum_object<>::parse<console_key>("oem7"), csf_);
    }
    
    void test_method_(oem8) {
      assert::are_equal(223, enum_object<>::to_int32(console_key::oem8), csf_);
      assert::are_equal("oem8", enum_object<>::to_string(console_key::oem8), csf_);
      assert::are_equal(console_key::oem8, enum_object<>::parse<console_key>("oem8"), csf_);
    }
    
    void test_method_(oem102) {
      assert::are_equal(226, enum_object<>::to_int32(console_key::oem102), csf_);
      assert::are_equal("oem102", enum_object<>::to_string(console_key::oem102), csf_);
      assert::are_equal(console_key::oem102, enum_object<>::parse<console_key>("oem102"), csf_);
    }
    
    void test_method_(process) {
      assert::are_equal(229, enum_object<>::to_int32(console_key::process), csf_);
      assert::are_equal("process", enum_object<>::to_string(console_key::process), csf_);
      assert::are_equal(console_key::process, enum_object<>::parse<console_key>("process"), csf_);
    }
    
    void test_method_(packet) {
      assert::are_equal(231, enum_object<>::to_int32(console_key::packet), csf_);
      assert::are_equal("packet", enum_object<>::to_string(console_key::packet), csf_);
      assert::are_equal(console_key::packet, enum_object<>::parse<console_key>("packet"), csf_);
    }
    
    void test_method_(attention) {
      assert::are_equal(246, enum_object<>::to_int32(console_key::attention), csf_);
      assert::are_equal("attention", enum_object<>::to_string(console_key::attention), csf_);
      assert::are_equal(console_key::attention, enum_object<>::parse<console_key>("attention"), csf_);
    }
    
    void test_method_(cr_sel) {
      assert::are_equal(247, enum_object<>::to_int32(console_key::cr_sel), csf_);
      assert::are_equal("cr_sel", enum_object<>::to_string(console_key::cr_sel), csf_);
      assert::are_equal(console_key::cr_sel, enum_object<>::parse<console_key>("cr_sel"), csf_);
    }
    
    void test_method_(ex_sel) {
      assert::are_equal(248, enum_object<>::to_int32(console_key::ex_sel), csf_);
      assert::are_equal("ex_sel", enum_object<>::to_string(console_key::ex_sel), csf_);
      assert::are_equal(console_key::ex_sel, enum_object<>::parse<console_key>("ex_sel"), csf_);
    }
    
    void test_method_(erase_end_of_file) {
      assert::are_equal(249, enum_object<>::to_int32(console_key::erase_end_of_file), csf_);
      assert::are_equal("erase_end_of_file", enum_object<>::to_string(console_key::erase_end_of_file), csf_);
      assert::are_equal(console_key::erase_end_of_file, enum_object<>::parse<console_key>("erase_end_of_file"), csf_);
    }
    
    void test_method_(play) {
      assert::are_equal(250, enum_object<>::to_int32(console_key::play), csf_);
      assert::are_equal("play", enum_object<>::to_string(console_key::play), csf_);
      assert::are_equal(console_key::play, enum_object<>::parse<console_key>("play"), csf_);
    }
    
    void test_method_(zoom) {
      assert::are_equal(251, enum_object<>::to_int32(console_key::zoom), csf_);
      assert::are_equal("zoom", enum_object<>::to_string(console_key::zoom), csf_);
      assert::are_equal(console_key::zoom, enum_object<>::parse<console_key>("zoom"), csf_);
    }
    
    void test_method_(no_name) {
      assert::are_equal(252, enum_object<>::to_int32(console_key::no_name), csf_);
      assert::are_equal("no_name", enum_object<>::to_string(console_key::no_name), csf_);
      assert::are_equal(console_key::no_name, enum_object<>::parse<console_key>("no_name"), csf_);
    }
    
    void test_method_(pa1) {
      assert::are_equal(253, enum_object<>::to_int32(console_key::pa1), csf_);
      assert::are_equal("pa1", enum_object<>::to_string(console_key::pa1), csf_);
      assert::are_equal(console_key::pa1, enum_object<>::parse<console_key>("pa1"), csf_);
    }
    
    void test_method_(oem_clear) {
      assert::are_equal(254, enum_object<>::to_int32(console_key::oem_clear), csf_);
      assert::are_equal("oem_clear", enum_object<>::to_string(console_key::oem_clear), csf_);
      assert::are_equal(console_key::oem_clear, enum_object<>::parse<console_key>("oem_clear"), csf_);
    }
  };
}

