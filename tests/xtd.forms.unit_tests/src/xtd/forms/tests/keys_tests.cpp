#include <xtd/forms/keys>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::forms;
using namespace xtd::tunit;

namespace xtd::forms::tests {
  class test_class_(keys_tests) {
    auto test_method_(none) {
      assert::are_equal(0, enum_object<>::to_int32(keys::none));
      assert::are_equal("none", enum_object<>::to_string(keys::none));
      assert::are_equal(keys::none, enum_object<>::parse<keys>("none"));
    }
    
    auto test_method_(lbutton) {
      assert::are_equal(1, enum_object<>::to_int32(keys::lbutton));
      assert::are_equal("lbutton", enum_object<>::to_string(keys::lbutton));
      assert::are_equal(keys::lbutton, enum_object<>::parse<keys>("lbutton"));
    }
    
    auto test_method_(rbutton) {
      assert::are_equal(2, enum_object<>::to_int32(keys::rbutton));
      assert::are_equal("rbutton", enum_object<>::to_string(keys::rbutton));
      assert::are_equal(keys::rbutton, enum_object<>::parse<keys>("rbutton"));
    }
    
    auto test_method_(cancel) {
      assert::are_equal(3, enum_object<>::to_int32(keys::cancel));
      assert::are_equal("cancel", enum_object<>::to_string(keys::cancel));
      assert::are_equal(keys::cancel, enum_object<>::parse<keys>("cancel"));
    }
    
    auto test_method_(mbutton) {
      assert::are_equal(4, enum_object<>::to_int32(keys::mbutton));
      assert::are_equal("mbutton", enum_object<>::to_string(keys::mbutton));
      assert::are_equal(keys::mbutton, enum_object<>::parse<keys>("mbutton"));
    }
    
    auto test_method_(xbutton1) {
      assert::are_equal(5, enum_object<>::to_int32(keys::xbutton1));
      assert::are_equal("xbutton1", enum_object<>::to_string(keys::xbutton1));
      assert::are_equal(keys::xbutton1, enum_object<>::parse<keys>("xbutton1"));
    }
    
    auto test_method_(xbutton2) {
      assert::are_equal(6, enum_object<>::to_int32(keys::xbutton2));
      assert::are_equal("xbutton2", enum_object<>::to_string(keys::xbutton2));
      assert::are_equal(keys::xbutton2, enum_object<>::parse<keys>("xbutton2"));
    }
    
    auto test_method_(back) {
      assert::are_equal(8, enum_object<>::to_int32(keys::back));
      assert::are_equal("back", enum_object<>::to_string(keys::back));
      assert::are_equal(keys::back, enum_object<>::parse<keys>("back"));
    }
    
    auto test_method_(tab) {
      assert::are_equal(9, enum_object<>::to_int32(keys::tab));
      assert::are_equal("tab", enum_object<>::to_string(keys::tab));
      assert::are_equal(keys::tab, enum_object<>::parse<keys>("tab"));
    }
    
    auto test_method_(line_feed) {
      assert::are_equal(10, enum_object<>::to_int32(keys::line_feed));
      assert::are_equal("line_feed", enum_object<>::to_string(keys::line_feed));
      assert::are_equal(keys::line_feed, enum_object<>::parse<keys>("line_feed"));
    }
    
    auto test_method_(clear) {
      assert::are_equal(12, enum_object<>::to_int32(keys::clear));
      assert::are_equal("clear", enum_object<>::to_string(keys::clear));
      assert::are_equal(keys::clear, enum_object<>::parse<keys>("clear"));
    }
    
    auto test_method_(enter) {
      assert::are_equal(13, enum_object<>::to_int32(keys::enter));
      assert::are_equal("enter", enum_object<>::to_string(keys::enter));
      assert::are_equal(keys::enter, enum_object<>::parse<keys>("enter"));
    }
    
    auto test_method_(shift_key) {
      assert::are_equal(16, enum_object<>::to_int32(keys::shift_key));
      assert::are_equal("shift_key", enum_object<>::to_string(keys::shift_key));
      assert::are_equal(keys::shift_key, enum_object<>::parse<keys>("shift_key"));
    }
    
    auto test_method_(control_key) {
      assert::are_equal(17, enum_object<>::to_int32(keys::control_key));
      assert::are_equal("control_key", enum_object<>::to_string(keys::control_key));
      assert::are_equal(keys::control_key, enum_object<>::parse<keys>("control_key"));
    }
    
    auto test_method_(menu) {
      assert::are_equal(18, enum_object<>::to_int32(keys::menu));
      assert::are_equal("menu", enum_object<>::to_string(keys::menu));
      assert::are_equal(keys::menu, enum_object<>::parse<keys>("menu"));
    }
    
    auto test_method_(pause) {
      assert::are_equal(19, enum_object<>::to_int32(keys::pause));
      assert::are_equal("pause", enum_object<>::to_string(keys::pause));
      assert::are_equal(keys::pause, enum_object<>::parse<keys>("pause"));
    }
    
    auto test_method_(caps_lock) {
      assert::are_equal(20, enum_object<>::to_int32(keys::caps_lock));
      assert::are_equal("caps_lock", enum_object<>::to_string(keys::caps_lock));
      assert::are_equal(keys::caps_lock, enum_object<>::parse<keys>("caps_lock"));
    }
    
    auto test_method_(kana_mode) {
      assert::are_equal(21, enum_object<>::to_int32(keys::kana_mode));
      assert::are_equal("kana_mode", enum_object<>::to_string(keys::kana_mode));
      assert::are_equal(keys::kana_mode, enum_object<>::parse<keys>("kana_mode"));
    }
    
    auto test_method_(junja_mode) {
      assert::are_equal(23, enum_object<>::to_int32(keys::junja_mode));
      assert::are_equal("junja_mode", enum_object<>::to_string(keys::junja_mode));
      assert::are_equal(keys::junja_mode, enum_object<>::parse<keys>("junja_mode"));
    }
    
    auto test_method_(final_mode) {
      assert::are_equal(24, enum_object<>::to_int32(keys::final_mode));
      assert::are_equal("final_mode", enum_object<>::to_string(keys::final_mode));
      assert::are_equal(keys::final_mode, enum_object<>::parse<keys>("final_mode"));
    }
    
    auto test_method_(kanji_mode) {
      assert::are_equal(25, enum_object<>::to_int32(keys::kanji_mode));
      assert::are_equal("kanji_mode", enum_object<>::to_string(keys::kanji_mode));
      assert::are_equal(keys::kanji_mode, enum_object<>::parse<keys>("kanji_mode"));
    }
    
    auto test_method_(escape) {
      assert::are_equal(27, enum_object<>::to_int32(keys::escape));
      assert::are_equal("escape", enum_object<>::to_string(keys::escape));
      assert::are_equal(keys::escape, enum_object<>::parse<keys>("escape"));
    }
    
    auto test_method_(ime_convert) {
      assert::are_equal(28, enum_object<>::to_int32(keys::ime_convert));
      assert::are_equal("ime_convert", enum_object<>::to_string(keys::ime_convert));
      assert::are_equal(keys::ime_convert, enum_object<>::parse<keys>("ime_convert"));
    }
    
    auto test_method_(ime_nonconvert) {
      assert::are_equal(29, enum_object<>::to_int32(keys::ime_nonconvert));
      assert::are_equal("ime_nonconvert", enum_object<>::to_string(keys::ime_nonconvert));
      assert::are_equal(keys::ime_nonconvert, enum_object<>::parse<keys>("ime_nonconvert"));
    }
    
    auto test_method_(ime_accept) {
      assert::are_equal(30, enum_object<>::to_int32(keys::ime_accept));
      assert::are_equal("ime_accept", enum_object<>::to_string(keys::ime_accept));
      assert::are_equal(keys::ime_accept, enum_object<>::parse<keys>("ime_accept"));
    }
    
    auto test_method_(ime_mode_change) {
      assert::are_equal(31, enum_object<>::to_int32(keys::ime_mode_change));
      //assert::are_equal("ime_mode_change", enum_object<>::to_string(keys::ime_mode_change));
      //assert::are_equal(keys::ime_mode_change, enum_object<>::parse<keys>("ime_mode_change"));
    }
    
    auto test_method_(space) {
      assert::are_equal(32, enum_object<>::to_int32(keys::space));
      assert::are_equal("space", enum_object<>::to_string(keys::space));
      assert::are_equal(keys::space, enum_object<>::parse<keys>("space"));
    }
    
    auto test_method_(page_up) {
      assert::are_equal(33, enum_object<>::to_int32(keys::page_up));
      assert::are_equal("page_up", enum_object<>::to_string(keys::page_up));
      assert::are_equal(keys::page_up, enum_object<>::parse<keys>("page_up"));
    }
    
    auto test_method_(page_down) {
      assert::are_equal(34, enum_object<>::to_int32(keys::page_down));
      assert::are_equal("page_down", enum_object<>::to_string(keys::page_down));
      assert::are_equal(keys::page_down, enum_object<>::parse<keys>("page_down"));
    }
    
    auto test_method_(end) {
      assert::are_equal(35, enum_object<>::to_int32(keys::end));
      assert::are_equal("end", enum_object<>::to_string(keys::end));
      assert::are_equal(keys::end, enum_object<>::parse<keys>("end"));
    }
    
    auto test_method_(home) {
      assert::are_equal(36, enum_object<>::to_int32(keys::home));
      assert::are_equal("home", enum_object<>::to_string(keys::home));
      assert::are_equal(keys::home, enum_object<>::parse<keys>("home"));
    }
    
    auto test_method_(left) {
      assert::are_equal(37, enum_object<>::to_int32(keys::left));
      assert::are_equal("left", enum_object<>::to_string(keys::left));
      assert::are_equal(keys::left, enum_object<>::parse<keys>("left"));
    }
    
    auto test_method_(up) {
      assert::are_equal(38, enum_object<>::to_int32(keys::up));
      assert::are_equal("up", enum_object<>::to_string(keys::up));
      assert::are_equal(keys::up, enum_object<>::parse<keys>("up"));
    }
    
    auto test_method_(right) {
      assert::are_equal(39, enum_object<>::to_int32(keys::right));
      assert::are_equal("right", enum_object<>::to_string(keys::right));
      assert::are_equal(keys::right, enum_object<>::parse<keys>("right"));
    }
    
    auto test_method_(down) {
      assert::are_equal(40, enum_object<>::to_int32(keys::down));
      assert::are_equal("down", enum_object<>::to_string(keys::down));
      assert::are_equal(keys::down, enum_object<>::parse<keys>("down"));
    }
    
    auto test_method_(select) {
      assert::are_equal(41, enum_object<>::to_int32(keys::select));
      assert::are_equal("select", enum_object<>::to_string(keys::select));
      assert::are_equal(keys::select, enum_object<>::parse<keys>("select"));
    }
    
    auto test_method_(print) {
      assert::are_equal(42, enum_object<>::to_int32(keys::print));
      assert::are_equal("print", enum_object<>::to_string(keys::print));
      assert::are_equal(keys::print, enum_object<>::parse<keys>("print"));
    }
    
    auto test_method_(execute) {
      assert::are_equal(43, enum_object<>::to_int32(keys::execute));
      assert::are_equal("execute", enum_object<>::to_string(keys::execute));
      assert::are_equal(keys::execute, enum_object<>::parse<keys>("execute"));
    }
    
    auto test_method_(print_screen) {
      assert::are_equal(44, enum_object<>::to_int32(keys::print_screen));
      assert::are_equal("print_screen", enum_object<>::to_string(keys::print_screen));
      assert::are_equal(keys::print_screen, enum_object<>::parse<keys>("print_screen"));
    }
    
    auto test_method_(insert) {
      assert::are_equal(45, enum_object<>::to_int32(keys::insert));
      assert::are_equal("insert", enum_object<>::to_string(keys::insert));
      assert::are_equal(keys::insert, enum_object<>::parse<keys>("insert"));
    }
    
    auto test_method_(del) {
      assert::are_equal(46, enum_object<>::to_int32(keys::del));
      assert::are_equal("del", enum_object<>::to_string(keys::del));
      assert::are_equal(keys::del, enum_object<>::parse<keys>("del"));
    }
    
    auto test_method_(help) {
      assert::are_equal(47, enum_object<>::to_int32(keys::help));
      assert::are_equal("help", enum_object<>::to_string(keys::help));
      assert::are_equal(keys::help, enum_object<>::parse<keys>("help"));
    }
    
    auto test_method_(d0) {
      assert::are_equal(48, enum_object<>::to_int32(keys::d0));
      assert::are_equal("d0", enum_object<>::to_string(keys::d0));
      assert::are_equal(keys::d0, enum_object<>::parse<keys>("d0"));
    }
    
    auto test_method_(d1) {
      assert::are_equal(49, enum_object<>::to_int32(keys::d1));
      assert::are_equal("d1", enum_object<>::to_string(keys::d1));
      assert::are_equal(keys::d1, enum_object<>::parse<keys>("d1"));
    }
    
    auto test_method_(d2) {
      assert::are_equal(50, enum_object<>::to_int32(keys::d2));
      assert::are_equal("d2", enum_object<>::to_string(keys::d2));
      assert::are_equal(keys::d2, enum_object<>::parse<keys>("d2"));
    }
    
    auto test_method_(d3) {
      assert::are_equal(51, enum_object<>::to_int32(keys::d3));
      assert::are_equal("d3", enum_object<>::to_string(keys::d3));
      assert::are_equal(keys::d3, enum_object<>::parse<keys>("d3"));
    }
    
    auto test_method_(d4) {
      assert::are_equal(52, enum_object<>::to_int32(keys::d4));
      assert::are_equal("d4", enum_object<>::to_string(keys::d4));
      assert::are_equal(keys::d4, enum_object<>::parse<keys>("d4"));
    }
    
    auto test_method_(d5) {
      assert::are_equal(53, enum_object<>::to_int32(keys::d5));
      assert::are_equal("d5", enum_object<>::to_string(keys::d5));
      assert::are_equal(keys::d5, enum_object<>::parse<keys>("d5"));
    }
    
    auto test_method_(d6) {
      assert::are_equal(54, enum_object<>::to_int32(keys::d6));
      assert::are_equal("d6", enum_object<>::to_string(keys::d6));
      assert::are_equal(keys::d6, enum_object<>::parse<keys>("d6"));
    }
    
    auto test_method_(d7) {
      assert::are_equal(55, enum_object<>::to_int32(keys::d7));
      assert::are_equal("d7", enum_object<>::to_string(keys::d7));
      assert::are_equal(keys::d7, enum_object<>::parse<keys>("d7"));
    }
    
    auto test_method_(d8) {
      assert::are_equal(56, enum_object<>::to_int32(keys::d8));
      assert::are_equal("d8", enum_object<>::to_string(keys::d8));
      assert::are_equal(keys::d8, enum_object<>::parse<keys>("d8"));
    }
    
    auto test_method_(d9) {
      assert::are_equal(57, enum_object<>::to_int32(keys::d9));
      assert::are_equal("d9", enum_object<>::to_string(keys::d9));
      assert::are_equal(keys::d9, enum_object<>::parse<keys>("d9"));
    }
    
    auto test_method_(a) {
      assert::are_equal(65, enum_object<>::to_int32(keys::a));
      assert::are_equal("a", enum_object<>::to_string(keys::a));
      assert::are_equal(keys::a, enum_object<>::parse<keys>("a"));
    }
    
    auto test_method_(b) {
      assert::are_equal(66, enum_object<>::to_int32(keys::b));
      assert::are_equal("b", enum_object<>::to_string(keys::b));
      assert::are_equal(keys::b, enum_object<>::parse<keys>("b"));
    }
    
    auto test_method_(c) {
      assert::are_equal(67, enum_object<>::to_int32(keys::c));
      assert::are_equal("c", enum_object<>::to_string(keys::c));
      assert::are_equal(keys::c, enum_object<>::parse<keys>("c"));
    }
    
    auto test_method_(d) {
      assert::are_equal(68, enum_object<>::to_int32(keys::d));
      assert::are_equal("d", enum_object<>::to_string(keys::d));
      assert::are_equal(keys::d, enum_object<>::parse<keys>("d"));
    }
    
    auto test_method_(e) {
      assert::are_equal(69, enum_object<>::to_int32(keys::e));
      assert::are_equal("e", enum_object<>::to_string(keys::e));
      assert::are_equal(keys::e, enum_object<>::parse<keys>("e"));
    }
    
    auto test_method_(f) {
      assert::are_equal(70, enum_object<>::to_int32(keys::f));
      assert::are_equal("f", enum_object<>::to_string(keys::f));
      assert::are_equal(keys::f, enum_object<>::parse<keys>("f"));
    }
    
    auto test_method_(g) {
      assert::are_equal(71, enum_object<>::to_int32(keys::g));
      assert::are_equal("g", enum_object<>::to_string(keys::g));
      assert::are_equal(keys::g, enum_object<>::parse<keys>("g"));
    }
    
    auto test_method_(h) {
      assert::are_equal(72, enum_object<>::to_int32(keys::h));
      assert::are_equal("h", enum_object<>::to_string(keys::h));
      assert::are_equal(keys::h, enum_object<>::parse<keys>("h"));
    }
    
    auto test_method_(i) {
      assert::are_equal(73, enum_object<>::to_int32(keys::i));
      assert::are_equal("i", enum_object<>::to_string(keys::i));
      assert::are_equal(keys::i, enum_object<>::parse<keys>("i"));
    }
    
    auto test_method_(j) {
      assert::are_equal(74, enum_object<>::to_int32(keys::j));
      assert::are_equal("j", enum_object<>::to_string(keys::j));
      assert::are_equal(keys::j, enum_object<>::parse<keys>("j"));
    }
    
    auto test_method_(k) {
      assert::are_equal(75, enum_object<>::to_int32(keys::k));
      assert::are_equal("k", enum_object<>::to_string(keys::k));
      assert::are_equal(keys::k, enum_object<>::parse<keys>("k"));
    }
    
    auto test_method_(l) {
      assert::are_equal(76, enum_object<>::to_int32(keys::l));
      assert::are_equal("l", enum_object<>::to_string(keys::l));
      assert::are_equal(keys::l, enum_object<>::parse<keys>("l"));
    }
    
    auto test_method_(m) {
      assert::are_equal(77, enum_object<>::to_int32(keys::m));
      assert::are_equal("m", enum_object<>::to_string(keys::m));
      assert::are_equal(keys::m, enum_object<>::parse<keys>("m"));
    }
    
    auto test_method_(n) {
      assert::are_equal(78, enum_object<>::to_int32(keys::n));
      assert::are_equal("n", enum_object<>::to_string(keys::n));
      assert::are_equal(keys::n, enum_object<>::parse<keys>("n"));
    }
    
    auto test_method_(o) {
      assert::are_equal(79, enum_object<>::to_int32(keys::o));
      assert::are_equal("o", enum_object<>::to_string(keys::o));
      assert::are_equal(keys::o, enum_object<>::parse<keys>("o"));
    }
    
    auto test_method_(p) {
      assert::are_equal(80, enum_object<>::to_int32(keys::p));
      assert::are_equal("p", enum_object<>::to_string(keys::p));
      assert::are_equal(keys::p, enum_object<>::parse<keys>("p"));
    }
    
    auto test_method_(q) {
      assert::are_equal(81, enum_object<>::to_int32(keys::q));
      assert::are_equal("q", enum_object<>::to_string(keys::q));
      assert::are_equal(keys::q, enum_object<>::parse<keys>("q"));
    }
    
    auto test_method_(r) {
      assert::are_equal(82, enum_object<>::to_int32(keys::r));
      assert::are_equal("r", enum_object<>::to_string(keys::r));
      assert::are_equal(keys::r, enum_object<>::parse<keys>("r"));
    }
    
    auto test_method_(s) {
      assert::are_equal(83, enum_object<>::to_int32(keys::s));
      assert::are_equal("s", enum_object<>::to_string(keys::s));
      assert::are_equal(keys::s, enum_object<>::parse<keys>("s"));
    }
    
    auto test_method_(t) {
      assert::are_equal(84, enum_object<>::to_int32(keys::t));
      assert::are_equal("t", enum_object<>::to_string(keys::t));
      assert::are_equal(keys::t, enum_object<>::parse<keys>("t"));
    }
    
    auto test_method_(u) {
      assert::are_equal(85, enum_object<>::to_int32(keys::u));
      assert::are_equal("u", enum_object<>::to_string(keys::u));
      assert::are_equal(keys::u, enum_object<>::parse<keys>("u"));
    }
    
    auto test_method_(v) {
      assert::are_equal(86, enum_object<>::to_int32(keys::v));
      assert::are_equal("v", enum_object<>::to_string(keys::v));
      assert::are_equal(keys::v, enum_object<>::parse<keys>("v"));
    }
    
    auto test_method_(w) {
      assert::are_equal(87, enum_object<>::to_int32(keys::w));
      assert::are_equal("w", enum_object<>::to_string(keys::w));
      assert::are_equal(keys::w, enum_object<>::parse<keys>("w"));
    }
    
    auto test_method_(x) {
      assert::are_equal(88, enum_object<>::to_int32(keys::x));
      assert::are_equal("x", enum_object<>::to_string(keys::x));
      assert::are_equal(keys::x, enum_object<>::parse<keys>("x"));
    }
    
    auto test_method_(y) {
      assert::are_equal(89, enum_object<>::to_int32(keys::y));
      assert::are_equal("y", enum_object<>::to_string(keys::y));
      assert::are_equal(keys::y, enum_object<>::parse<keys>("y"));
    }
    
    auto test_method_(z) {
      assert::are_equal(90, enum_object<>::to_int32(keys::z));
      assert::are_equal("z", enum_object<>::to_string(keys::z));
      assert::are_equal(keys::z, enum_object<>::parse<keys>("z"));
    }
    
    auto test_method_(lwin) {
      assert::are_equal(91, enum_object<>::to_int32(keys::lwin));
      assert::are_equal("lwin", enum_object<>::to_string(keys::lwin));
      assert::are_equal(keys::lwin, enum_object<>::parse<keys>("lwin"));
    }
    
    auto test_method_(rwin) {
      assert::are_equal(92, enum_object<>::to_int32(keys::rwin));
      assert::are_equal("rwin", enum_object<>::to_string(keys::rwin));
      assert::are_equal(keys::rwin, enum_object<>::parse<keys>("rwin"));
    }
    
    auto test_method_(apps) {
      assert::are_equal(93, enum_object<>::to_int32(keys::apps));
      assert::are_equal("apps", enum_object<>::to_string(keys::apps));
      assert::are_equal(keys::apps, enum_object<>::parse<keys>("apps"));
    }
    
    auto test_method_(num_pad0) {
      assert::are_equal(96, enum_object<>::to_int32(keys::num_pad0));
      assert::are_equal("num_pad0", enum_object<>::to_string(keys::num_pad0));
      assert::are_equal(keys::num_pad0, enum_object<>::parse<keys>("num_pad0"));
    }
    
    auto test_method_(num_pad1) {
      assert::are_equal(97, enum_object<>::to_int32(keys::num_pad1));
      assert::are_equal("num_pad1", enum_object<>::to_string(keys::num_pad1));
      assert::are_equal(keys::num_pad1, enum_object<>::parse<keys>("num_pad1"));
    }
    
    auto test_method_(num_pad2) {
      assert::are_equal(98, enum_object<>::to_int32(keys::num_pad2));
      assert::are_equal("num_pad2", enum_object<>::to_string(keys::num_pad2));
      assert::are_equal(keys::num_pad2, enum_object<>::parse<keys>("num_pad2"));
    }
    
    auto test_method_(num_pad3) {
      assert::are_equal(99, enum_object<>::to_int32(keys::num_pad3));
      assert::are_equal("num_pad3", enum_object<>::to_string(keys::num_pad3));
      assert::are_equal(keys::num_pad3, enum_object<>::parse<keys>("num_pad3"));
    }
    
    auto test_method_(num_pad4) {
      assert::are_equal(100, enum_object<>::to_int32(keys::num_pad4));
      assert::are_equal("num_pad4", enum_object<>::to_string(keys::num_pad4));
      assert::are_equal(keys::num_pad4, enum_object<>::parse<keys>("num_pad4"));
    }
    
    auto test_method_(num_pad5) {
      assert::are_equal(101, enum_object<>::to_int32(keys::num_pad5));
      assert::are_equal("num_pad5", enum_object<>::to_string(keys::num_pad5));
      assert::are_equal(keys::num_pad5, enum_object<>::parse<keys>("num_pad5"));
    }
    
    auto test_method_(num_pad6) {
      assert::are_equal(102, enum_object<>::to_int32(keys::num_pad6));
      assert::are_equal("num_pad6", enum_object<>::to_string(keys::num_pad6));
      assert::are_equal(keys::num_pad6, enum_object<>::parse<keys>("num_pad6"));
    }
    
    auto test_method_(num_pad7) {
      assert::are_equal(103, enum_object<>::to_int32(keys::num_pad7));
      assert::are_equal("num_pad7", enum_object<>::to_string(keys::num_pad7));
      assert::are_equal(keys::num_pad7, enum_object<>::parse<keys>("num_pad7"));
    }
    
    auto test_method_(num_pad8) {
      assert::are_equal(104, enum_object<>::to_int32(keys::num_pad8));
      assert::are_equal("num_pad8", enum_object<>::to_string(keys::num_pad8));
      assert::are_equal(keys::num_pad8, enum_object<>::parse<keys>("num_pad8"));
    }
    
    auto test_method_(num_pad9) {
      assert::are_equal(105, enum_object<>::to_int32(keys::num_pad9));
      assert::are_equal("num_pad9", enum_object<>::to_string(keys::num_pad9));
      assert::are_equal(keys::num_pad9, enum_object<>::parse<keys>("num_pad9"));
    }
    
    auto test_method_(multiply) {
      assert::are_equal(106, enum_object<>::to_int32(keys::multiply));
      assert::are_equal("multiply", enum_object<>::to_string(keys::multiply));
      assert::are_equal(keys::multiply, enum_object<>::parse<keys>("multiply"));
    }
    
    auto test_method_(add) {
      assert::are_equal(107, enum_object<>::to_int32(keys::add));
      assert::are_equal("add", enum_object<>::to_string(keys::add));
      assert::are_equal(keys::add, enum_object<>::parse<keys>("add"));
    }
    
    auto test_method_(separator) {
      assert::are_equal(108, enum_object<>::to_int32(keys::separator));
      assert::are_equal("separator", enum_object<>::to_string(keys::separator));
      assert::are_equal(keys::separator, enum_object<>::parse<keys>("separator"));
    }
    
    auto test_method_(subtract) {
      assert::are_equal(109, enum_object<>::to_int32(keys::subtract));
      assert::are_equal("subtract", enum_object<>::to_string(keys::subtract));
      assert::are_equal(keys::subtract, enum_object<>::parse<keys>("subtract"));
    }
    
    auto test_method_(decimal) {
      assert::are_equal(110, enum_object<>::to_int32(keys::decimal));
      assert::are_equal("decimal", enum_object<>::to_string(keys::decimal));
      assert::are_equal(keys::decimal, enum_object<>::parse<keys>("decimal"));
    }
    
    auto test_method_(divide) {
      assert::are_equal(111, enum_object<>::to_int32(keys::divide));
      assert::are_equal("divide", enum_object<>::to_string(keys::divide));
      assert::are_equal(keys::divide, enum_object<>::parse<keys>("divide"));
    }
    
    auto test_method_(f1) {
      assert::are_equal(112, enum_object<>::to_int32(keys::f1));
      assert::are_equal("f1", enum_object<>::to_string(keys::f1));
      assert::are_equal(keys::f1, enum_object<>::parse<keys>("f1"));
    }
    
    auto test_method_(f2) {
      assert::are_equal(113, enum_object<>::to_int32(keys::f2));
      assert::are_equal("f2", enum_object<>::to_string(keys::f2));
      assert::are_equal(keys::f2, enum_object<>::parse<keys>("f2"));
    }
    
    auto test_method_(f3) {
      assert::are_equal(114, enum_object<>::to_int32(keys::f3));
      assert::are_equal("f3", enum_object<>::to_string(keys::f3));
      assert::are_equal(keys::f3, enum_object<>::parse<keys>("f3"));
    }
    
    auto test_method_(f4) {
      assert::are_equal(115, enum_object<>::to_int32(keys::f4));
      assert::are_equal("f4", enum_object<>::to_string(keys::f4));
      assert::are_equal(keys::f4, enum_object<>::parse<keys>("f4"));
    }
    
    auto test_method_(f5) {
      assert::are_equal(116, enum_object<>::to_int32(keys::f5));
      assert::are_equal("f5", enum_object<>::to_string(keys::f5));
      assert::are_equal(keys::f5, enum_object<>::parse<keys>("f5"));
    }
    
    auto test_method_(f6) {
      assert::are_equal(117, enum_object<>::to_int32(keys::f6));
      assert::are_equal("f6", enum_object<>::to_string(keys::f6));
      assert::are_equal(keys::f6, enum_object<>::parse<keys>("f6"));
    }
    
    auto test_method_(f7) {
      assert::are_equal(118, enum_object<>::to_int32(keys::f7));
      assert::are_equal("f7", enum_object<>::to_string(keys::f7));
      assert::are_equal(keys::f7, enum_object<>::parse<keys>("f7"));
    }
    
    auto test_method_(f8) {
      assert::are_equal(119, enum_object<>::to_int32(keys::f8));
      assert::are_equal("f8", enum_object<>::to_string(keys::f8));
      assert::are_equal(keys::f8, enum_object<>::parse<keys>("f8"));
    }
    
    auto test_method_(f9) {
      assert::are_equal(120, enum_object<>::to_int32(keys::f9));
      assert::are_equal("f9", enum_object<>::to_string(keys::f9));
      assert::are_equal(keys::f9, enum_object<>::parse<keys>("f9"));
    }
    
    auto test_method_(f10) {
      assert::are_equal(121, enum_object<>::to_int32(keys::f10));
      assert::are_equal("f10", enum_object<>::to_string(keys::f10));
      assert::are_equal(keys::f10, enum_object<>::parse<keys>("f10"));
    }
    
    auto test_method_(f11) {
      assert::are_equal(122, enum_object<>::to_int32(keys::f11));
      assert::are_equal("f11", enum_object<>::to_string(keys::f11));
      assert::are_equal(keys::f11, enum_object<>::parse<keys>("f11"));
    }
    
    auto test_method_(f12) {
      assert::are_equal(123, enum_object<>::to_int32(keys::f12));
      assert::are_equal("f12", enum_object<>::to_string(keys::f12));
      assert::are_equal(keys::f12, enum_object<>::parse<keys>("f12"));
    }
    
    auto test_method_(f13) {
      assert::are_equal(124, enum_object<>::to_int32(keys::f13));
      assert::are_equal("f13", enum_object<>::to_string(keys::f13));
      assert::are_equal(keys::f13, enum_object<>::parse<keys>("f13"));
    }
    
    auto test_method_(f14) {
      assert::are_equal(125, enum_object<>::to_int32(keys::f14));
      assert::are_equal("f14", enum_object<>::to_string(keys::f14));
      assert::are_equal(keys::f14, enum_object<>::parse<keys>("f14"));
    }
    
    auto test_method_(f15) {
      assert::are_equal(126, enum_object<>::to_int32(keys::f15));
      //assert::are_equal("f15", enum_object<>::to_string(keys::f15));
      //assert::are_equal(keys::f15, enum_object<>::parse<keys>("f15"));
    }
    
    auto test_method_(f16) {
      assert::are_equal(127, enum_object<>::to_int32(keys::f16));
      //assert::are_equal("f16", enum_object<>::to_string(keys::f16));
      //assert::are_equal(keys::f16, enum_object<>::parse<keys>("f16"));
    }
    
    auto test_method_(f17) {
      assert::are_equal(128, enum_object<>::to_int32(keys::f17));
      assert::are_equal("f17", enum_object<>::to_string(keys::f17));
      assert::are_equal(keys::f17, enum_object<>::parse<keys>("f17"));
    }
    
    auto test_method_(f18) {
      assert::are_equal(129, enum_object<>::to_int32(keys::f18));
      assert::are_equal("f18", enum_object<>::to_string(keys::f18));
      assert::are_equal(keys::f18, enum_object<>::parse<keys>("f18"));
    }
    
    auto test_method_(f19) {
      assert::are_equal(130, enum_object<>::to_int32(keys::f19));
      assert::are_equal("f19", enum_object<>::to_string(keys::f19));
      assert::are_equal(keys::f19, enum_object<>::parse<keys>("f19"));
    }
    
    auto test_method_(f20) {
      assert::are_equal(131, enum_object<>::to_int32(keys::f20));
      assert::are_equal("f20", enum_object<>::to_string(keys::f20));
      assert::are_equal(keys::f20, enum_object<>::parse<keys>("f20"));
    }
    
    auto test_method_(f21) {
      assert::are_equal(132, enum_object<>::to_int32(keys::f21));
      assert::are_equal("f21", enum_object<>::to_string(keys::f21));
      assert::are_equal(keys::f21, enum_object<>::parse<keys>("f21"));
    }
    
    auto test_method_(f22) {
      assert::are_equal(133, enum_object<>::to_int32(keys::f22));
      assert::are_equal("f22", enum_object<>::to_string(keys::f22));
      assert::are_equal(keys::f22, enum_object<>::parse<keys>("f22"));
    }
    
    auto test_method_(f23) {
      assert::are_equal(134, enum_object<>::to_int32(keys::f23));
      assert::are_equal("f23", enum_object<>::to_string(keys::f23));
      assert::are_equal(keys::f23, enum_object<>::parse<keys>("f23"));
    }
    
    auto test_method_(f24) {
      assert::are_equal(135, enum_object<>::to_int32(keys::f24));
      assert::are_equal("f24", enum_object<>::to_string(keys::f24));
      assert::are_equal(keys::f24, enum_object<>::parse<keys>("f24"));
    }
    
    auto test_method_(num_lock) {
      assert::are_equal(144, enum_object<>::to_int32(keys::num_lock));
      assert::are_equal("num_lock", enum_object<>::to_string(keys::num_lock));
      assert::are_equal(keys::num_lock, enum_object<>::parse<keys>("num_lock"));
    }
    
    auto test_method_(scroll) {
      assert::are_equal(145, enum_object<>::to_int32(keys::scroll));
      assert::are_equal("scroll", enum_object<>::to_string(keys::scroll));
      assert::are_equal(keys::scroll, enum_object<>::parse<keys>("scroll"));
    }
    
    auto test_method_(lshift_key) {
      assert::are_equal(160, enum_object<>::to_int32(keys::lshift_key));
      assert::are_equal("lshift_key", enum_object<>::to_string(keys::lshift_key));
      assert::are_equal(keys::lshift_key, enum_object<>::parse<keys>("lshift_key"));
    }
    
    auto test_method_(rshift_key) {
      assert::are_equal(161, enum_object<>::to_int32(keys::rshift_key));
      assert::are_equal("rshift_key", enum_object<>::to_string(keys::rshift_key));
      assert::are_equal(keys::rshift_key, enum_object<>::parse<keys>("rshift_key"));
    }
    
    auto test_method_(lcontrol_key) {
      assert::are_equal(162, enum_object<>::to_int32(keys::lcontrol_key));
      assert::are_equal("lcontrol_key", enum_object<>::to_string(keys::lcontrol_key));
      assert::are_equal(keys::lcontrol_key, enum_object<>::parse<keys>("lcontrol_key"));
    }
    
    auto test_method_(rcontrol_key) {
      assert::are_equal(163, enum_object<>::to_int32(keys::rcontrol_key));
      assert::are_equal("rcontrol_key", enum_object<>::to_string(keys::rcontrol_key));
      assert::are_equal(keys::rcontrol_key, enum_object<>::parse<keys>("rcontrol_key"));
    }
    
    auto test_method_(lmenu) {
      assert::are_equal(164, enum_object<>::to_int32(keys::lmenu));
      assert::are_equal("lmenu", enum_object<>::to_string(keys::lmenu));
      assert::are_equal(keys::lmenu, enum_object<>::parse<keys>("lmenu"));
    }
    
    auto test_method_(rmenu) {
      assert::are_equal(165, enum_object<>::to_int32(keys::rmenu));
      assert::are_equal("rmenu", enum_object<>::to_string(keys::rmenu));
      assert::are_equal(keys::rmenu, enum_object<>::parse<keys>("rmenu"));
    }
    
    auto test_method_(browser_back) {
      assert::are_equal(166, enum_object<>::to_int32(keys::browser_back));
      assert::are_equal("browser_back", enum_object<>::to_string(keys::browser_back));
      assert::are_equal(keys::browser_back, enum_object<>::parse<keys>("browser_back"));
    }
    
    auto test_method_(browser_forward) {
      assert::are_equal(167, enum_object<>::to_int32(keys::browser_forward));
      assert::are_equal("browser_forward", enum_object<>::to_string(keys::browser_forward));
      assert::are_equal(keys::browser_forward, enum_object<>::parse<keys>("browser_forward"));
    }
    
    auto test_method_(browser_refresh) {
      assert::are_equal(168, enum_object<>::to_int32(keys::browser_refresh));
      assert::are_equal("browser_refresh", enum_object<>::to_string(keys::browser_refresh));
      assert::are_equal(keys::browser_refresh, enum_object<>::parse<keys>("browser_refresh"));
    }
    
    auto test_method_(browser_stop) {
      assert::are_equal(169, enum_object<>::to_int32(keys::browser_stop));
      assert::are_equal("browser_stop", enum_object<>::to_string(keys::browser_stop));
      assert::are_equal(keys::browser_stop, enum_object<>::parse<keys>("browser_stop"));
    }
    
    auto test_method_(browser_search) {
      assert::are_equal(170, enum_object<>::to_int32(keys::browser_search));
      assert::are_equal("browser_search", enum_object<>::to_string(keys::browser_search));
      assert::are_equal(keys::browser_search, enum_object<>::parse<keys>("browser_search"));
    }
    
    auto test_method_(browser_favorites) {
      assert::are_equal(171, enum_object<>::to_int32(keys::browser_favorites));
      //assert::are_equal("browser_favorites", enum_object<>::to_string(keys::browser_favorites));
      //assert::are_equal(keys::browser_favorites, enum_object<>::parse<keys>("browser_favorites"));
    }
    
    auto test_method_(browser_home) {
      assert::are_equal(172, enum_object<>::to_int32(keys::browser_home));
      assert::are_equal("browser_home", enum_object<>::to_string(keys::browser_home));
      assert::are_equal(keys::browser_home, enum_object<>::parse<keys>("browser_home"));
    }
    
    auto test_method_(volume_mute) {
      assert::are_equal(173, enum_object<>::to_int32(keys::volume_mute));
      assert::are_equal("volume_mute", enum_object<>::to_string(keys::volume_mute));
      assert::are_equal(keys::volume_mute, enum_object<>::parse<keys>("volume_mute"));
    }
    
    auto test_method_(volume_down) {
      assert::are_equal(174, enum_object<>::to_int32(keys::volume_down));
      assert::are_equal("volume_down", enum_object<>::to_string(keys::volume_down));
      assert::are_equal(keys::volume_down, enum_object<>::parse<keys>("volume_down"));
    }
    
    auto test_method_(volume_up) {
      assert::are_equal(175, enum_object<>::to_int32(keys::volume_up));
      assert::are_equal("volume_up", enum_object<>::to_string(keys::volume_up));
      assert::are_equal(keys::volume_up, enum_object<>::parse<keys>("volume_up"));
    }
    
    auto test_method_(media_next_track) {
      assert::are_equal(176, enum_object<>::to_int32(keys::media_next_track));
      assert::are_equal("media_next_track", enum_object<>::to_string(keys::media_next_track));
      assert::are_equal(keys::media_next_track, enum_object<>::parse<keys>("media_next_track"));
    }
    
    auto test_method_(media_previous_track) {
      assert::are_equal(177, enum_object<>::to_int32(keys::media_previous_track));
      assert::are_equal("media_previous_track", enum_object<>::to_string(keys::media_previous_track));
      assert::are_equal(keys::media_previous_track, enum_object<>::parse<keys>("media_previous_track"));
    }
    
    auto test_method_(media_stop) {
      assert::are_equal(178, enum_object<>::to_int32(keys::media_stop));
      assert::are_equal("media_stop", enum_object<>::to_string(keys::media_stop));
      assert::are_equal(keys::media_stop, enum_object<>::parse<keys>("media_stop"));
    }
    
    auto test_method_(media_play_pause) {
      assert::are_equal(179, enum_object<>::to_int32(keys::media_play_pause));
      //assert::are_equal("media_play_pause", enum_object<>::to_string(keys::media_play_pause));
      //assert::are_equal(keys::media_play_pause, enum_object<>::parse<keys>("media_play_pause"));
    }
    
    auto test_method_(launch_mail) {
      assert::are_equal(180, enum_object<>::to_int32(keys::launch_mail));
      assert::are_equal("launch_mail", enum_object<>::to_string(keys::launch_mail));
      assert::are_equal(keys::launch_mail, enum_object<>::parse<keys>("launch_mail"));
    }
    
    auto test_method_(select_media) {
      assert::are_equal(181, enum_object<>::to_int32(keys::select_media));
      assert::are_equal("select_media", enum_object<>::to_string(keys::select_media));
      assert::are_equal(keys::select_media, enum_object<>::parse<keys>("select_media"));
    }
    
    auto test_method_(launch_application1) {
      assert::are_equal(182, enum_object<>::to_int32(keys::launch_application1));
      assert::are_equal("launch_application1", enum_object<>::to_string(keys::launch_application1));
      assert::are_equal(keys::launch_application1, enum_object<>::parse<keys>("launch_application1"));
    }
    
    auto test_method_(launch_application2) {
      assert::are_equal(183, enum_object<>::to_int32(keys::launch_application2));
      assert::are_equal("launch_application2", enum_object<>::to_string(keys::launch_application2));
      assert::are_equal(keys::launch_application2, enum_object<>::parse<keys>("launch_application2"));
    }
    
    auto test_method_(oem_semicolon) {
      assert::are_equal(186, enum_object<>::to_int32(keys::oem_semicolon));
      //assert::are_equal("oem_semicolon", enum_object<>::to_string(keys::oem_semicolon));
      //assert::are_equal(keys::oem_semicolon, enum_object<>::parse<keys>("oem_semicolon"));
    }
    
    auto test_method_(oem_plus) {
      assert::are_equal(187, enum_object<>::to_int32(keys::oem_plus));
      //assert::are_equal("oem_plus", enum_object<>::to_string(keys::oem_plus));
      //assert::are_equal(keys::oem_plus, enum_object<>::parse<keys>("oem_plus"));
    }
    
    auto test_method_(oem_comma) {
      assert::are_equal(188, enum_object<>::to_int32(keys::oem_comma));
      assert::are_equal("oem_comma", enum_object<>::to_string(keys::oem_comma));
      assert::are_equal(keys::oem_comma, enum_object<>::parse<keys>("oem_comma"));
    }
    
    auto test_method_(oem_minus) {
      assert::are_equal(189, enum_object<>::to_int32(keys::oem_minus));
      assert::are_equal("oem_minus", enum_object<>::to_string(keys::oem_minus));
      assert::are_equal(keys::oem_minus, enum_object<>::parse<keys>("oem_minus"));
    }
    
    auto test_method_(oem_period) {
      assert::are_equal(190, enum_object<>::to_int32(keys::oem_period));
      //assert::are_equal("oem_period", enum_object<>::to_string(keys::oem_period));
      //assert::are_equal(keys::oem_period, enum_object<>::parse<keys>("v"));
    }
    
    auto test_method_(oem_question) {
      assert::are_equal(191, enum_object<>::to_int32(keys::oem_question));
      //assert::are_equal("oem_question", enum_object<>::to_string(keys::oem_question));
      //assert::are_equal(keys::oem_question, enum_object<>::parse<keys>("oem_question"));
    }
    
    auto test_method_(oem_tilde) {
      assert::are_equal(192, enum_object<>::to_int32(keys::oem_tilde));
      assert::are_equal("oem_tilde", enum_object<>::to_string(keys::oem_tilde));
      assert::are_equal(keys::oem_tilde, enum_object<>::parse<keys>("oem_tilde"));
    }
    
    auto test_method_(oem_open_brackets) {
      assert::are_equal(219, enum_object<>::to_int32(keys::oem_open_brackets));
      assert::are_equal("oem_open_brackets", enum_object<>::to_string(keys::oem_open_brackets));
      assert::are_equal(keys::oem_open_brackets, enum_object<>::parse<keys>("oem_open_brackets"));
    }
    
    auto test_method_(oem_pipe) {
      assert::are_equal(220, enum_object<>::to_int32(keys::oem_pipe));
      assert::are_equal("oem_pipe", enum_object<>::to_string(keys::oem_pipe));
      assert::are_equal(keys::oem_pipe, enum_object<>::parse<keys>("oem_pipe"));
    }
    
    auto test_method_(oem_close_brackets) {
      assert::are_equal(221, enum_object<>::to_int32(keys::oem_close_brackets));
      assert::are_equal("oem_close_brackets", enum_object<>::to_string(keys::oem_close_brackets));
      assert::are_equal(keys::oem_close_brackets, enum_object<>::parse<keys>("oem_close_brackets"));
    }
    
    auto test_method_(oem_quotes) {
      assert::are_equal(222, enum_object<>::to_int32(keys::oem_quotes));
      //assert::are_equal("oem_quotes", enum_object<>::to_string(keys::oem_quotes));
      //assert::are_equal(keys::oem_quotes, enum_object<>::parse<keys>("oem_quotes"));
    }
    
    auto test_method_(oem8) {
      assert::are_equal(223, enum_object<>::to_int32(keys::oem8));
      //assert::are_equal("oem8", enum_object<>::to_string(keys::oem8));
      //assert::are_equal(keys::oem8, enum_object<>::parse<keys>("oem8"));
    }
    
    auto test_method_(oem_backslash) {
      assert::are_equal(226, enum_object<>::to_int32(keys::oem_backslash));
      assert::are_equal("oem_backslash", enum_object<>::to_string(keys::oem_backslash));
      assert::are_equal(keys::oem_backslash, enum_object<>::parse<keys>("oem_backslash"));
    }
    
    auto test_method_(process_key) {
      assert::are_equal(229, enum_object<>::to_int32(keys::process_key));
      assert::are_equal("process_key", enum_object<>::to_string(keys::process_key));
      assert::are_equal(keys::process_key, enum_object<>::parse<keys>("process_key"));
    }
    
    auto test_method_(attn) {
      assert::are_equal(246, enum_object<>::to_int32(keys::attn));
      assert::are_equal("attn", enum_object<>::to_string(keys::attn));
      assert::are_equal(keys::attn, enum_object<>::parse<keys>("attn"));
    }
    
    auto test_method_(crsel) {
      assert::are_equal(247, enum_object<>::to_int32(keys::crsel));
      //assert::are_equal("crsel", enum_object<>::to_string(keys::crsel));
      //assert::are_equal(keys::crsel, enum_object<>::parse<keys>("crsel"));
    }
    
    auto test_method_(exsel) {
      assert::are_equal(248, enum_object<>::to_int32(keys::exsel));
      assert::are_equal("exsel", enum_object<>::to_string(keys::exsel));
      assert::are_equal(keys::exsel, enum_object<>::parse<keys>("exsel"));
    }
    
    auto test_method_(erase_eof) {
      assert::are_equal(249, enum_object<>::to_int32(keys::erase_eof));
      assert::are_equal("erase_eof", enum_object<>::to_string(keys::erase_eof));
      assert::are_equal(keys::erase_eof, enum_object<>::parse<keys>("erase_eof"));
    }
    
    auto test_method_(play) {
      assert::are_equal(250, enum_object<>::to_int32(keys::play));
      //assert::are_equal("play", enum_object<>::to_string(keys::play));
      //assert::are_equal(keys::play, enum_object<>::parse<keys>("play"));
    }
    
    auto test_method_(zoom) {
      assert::are_equal(251, enum_object<>::to_int32(keys::zoom));
      //assert::are_equal("zoom", enum_object<>::to_string(keys::zoom));
      //assert::are_equal(keys::zoom, enum_object<>::parse<keys>("zoomzoom"));
    }
    
    auto test_method_(no_name) {
      assert::are_equal(252, enum_object<>::to_int32(keys::no_name));
      assert::are_equal("no_name", enum_object<>::to_string(keys::no_name));
      assert::are_equal(keys::no_name, enum_object<>::parse<keys>("no_name"));
    }
    
    auto test_method_(pa1) {
      assert::are_equal(253, enum_object<>::to_int32(keys::pa1));
      assert::are_equal("pa1", enum_object<>::to_string(keys::pa1));
      assert::are_equal(keys::pa1, enum_object<>::parse<keys>("pa1"));
    }
    
    auto test_method_(oem_clear) {
      assert::are_equal(254, enum_object<>::to_int32(keys::oem_clear));
      //assert::are_equal("oem_clear", enum_object<>::to_string(keys::oem_clear));
      //assert::are_equal(keys::oem_clear, enum_object<>::parse<keys>("oem_clear"));
    }
    
    auto test_method_(key_code) {
      assert::are_equal(65535, enum_object<>::to_int32(keys::key_code));
      //assert::are_equal("key_code", enum_object<>::to_string(keys::key_code));
      //assert::are_equal(keys::key_code, enum_object<>::parse<keys>("key_code"));
    }
    
    auto test_method_(shift) {
      assert::are_equal(65536, enum_object<>::to_int32(keys::shift));
      assert::are_equal("shift", enum_object<>::to_string(keys::shift));
      assert::are_equal(keys::shift, enum_object<>::parse<keys>("shift"));
    }
    
    auto test_method_(control) {
      assert::are_equal(131072, enum_object<>::to_int32(keys::control));
      assert::are_equal("control", enum_object<>::to_string(keys::control));
      assert::are_equal(keys::control, enum_object<>::parse<keys>("control"));
    }
    
    auto test_method_(alt) {
      assert::are_equal(262144, enum_object<>::to_int32(keys::alt));
      assert::are_equal("alt", enum_object<>::to_string(keys::alt));
      assert::are_equal(keys::alt, enum_object<>::parse<keys>("alt"));
    }
    
    auto test_method_(command) {
      assert::are_equal(131072, enum_object<>::to_int32(keys::command));
      assert::are_equal("control", enum_object<>::to_string(keys::command));
      assert::are_equal(keys::command, enum_object<>::parse<keys>("control"));
    }
    
    auto test_method_(meta) {
      assert::are_equal(524288, enum_object<>::to_int32(keys::meta));
      assert::are_equal("meta", enum_object<>::to_string(keys::meta));
      assert::are_equal(keys::meta, enum_object<>::parse<keys>("meta"));
    }
    
    auto test_method_(function) {
      assert::are_equal(1048576, enum_object<>::to_int32(keys::function));
      assert::are_equal("function", enum_object<>::to_string(keys::function));
      assert::are_equal(keys::function, enum_object<>::parse<keys>("function"));
    }
    
    auto test_method_(modifiers) {
      assert::are_equal(-65536, enum_object<>::to_int32(keys::modifiers));
      assert::are_equal("modifiers", enum_object<>::to_string(keys::modifiers));
      assert::are_equal(keys::modifiers, enum_object<>::parse<keys>("modifiers"));
    }
    
    auto test_method_(oem1) {
      assert::are_equal(186, enum_object<>::to_int32(keys::oem1));
      assert::are_equal("oem1", enum_object<>::to_string(keys::oem1));
      assert::are_equal(keys::oem1, enum_object<>::parse<keys>("oem1"));
    }
    
    auto test_method_(packet) {
      assert::are_equal(231, enum_object<>::to_int32(keys::packet));
      assert::are_equal("packet", enum_object<>::to_string(keys::packet));
      assert::are_equal(keys::packet, enum_object<>::parse<keys>("packet"));
    }
    
    auto test_method_(sleep) {
      assert::are_equal(95, enum_object<>::to_int32(keys::sleep));
      assert::are_equal("sleep", enum_object<>::to_string(keys::sleep));
      assert::are_equal(keys::sleep, enum_object<>::parse<keys>("sleep"));
    }
    
    auto test_method_(command_key) {
      assert::are_equal(256, enum_object<>::to_int32(keys::command_key));
      assert::are_equal("command_key", enum_object<>::to_string(keys::command_key));
      assert::are_equal(keys::command_key, enum_object<>::parse<keys>("command_key"));
    }
    
    auto test_method_(lcommand_key) {
      assert::are_equal(257, enum_object<>::to_int32(keys::lcommand_key));
      assert::are_equal("lcommand_key", enum_object<>::to_string(keys::lcommand_key));
      assert::are_equal(keys::lcommand_key, enum_object<>::parse<keys>("lcommand_key"));
    }
    
    auto test_method_(rcommand_key) {
      assert::are_equal(258, enum_object<>::to_int32(keys::rcommand_key));
      assert::are_equal("rcommand_key", enum_object<>::to_string(keys::rcommand_key));
      assert::are_equal(keys::rcommand_key, enum_object<>::parse<keys>("rcommand_key"));
    }
    
    auto test_method_(function_key) {
      assert::are_equal(260, enum_object<>::to_int32(keys::function_key));
      assert::are_equal("function_key", enum_object<>::to_string(keys::function_key));
      assert::are_equal(keys::function_key, enum_object<>::parse<keys>("function_key"));
    }
  };
}
