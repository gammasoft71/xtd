#include <xtd/drawing/drawing_2d/hatch_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing::drawing_2d;
using namespace xtd::tunit;

namespace xtd::drawing::drawing_2d::tests {
  class test_class_(hatch_style_tests) {
    void test_method_(horizontal) {
      assert::are_equal(0, enum_object<>::to_int32(hatch_style::horizontal), csf_);
      assert::are_equal("horizontal", enum_object<>::to_string(hatch_style::horizontal), csf_);
      assert::are_equal(hatch_style::horizontal, enum_object<>::parse<hatch_style>("horizontal"), csf_);
    }
    
    void test_method_(vertical) {
      assert::are_equal(1, enum_object<>::to_int32(hatch_style::vertical), csf_);
      assert::are_equal("vertical", enum_object<>::to_string(hatch_style::vertical), csf_);
      assert::are_equal(hatch_style::vertical, enum_object<>::parse<hatch_style>("vertical"), csf_);
    }
    
    void test_method_(forward_diagonal) {
      assert::are_equal(2, enum_object<>::to_int32(hatch_style::forward_diagonal), csf_);
      assert::are_equal("forward_diagonal", enum_object<>::to_string(hatch_style::forward_diagonal), csf_);
      assert::are_equal(hatch_style::forward_diagonal, enum_object<>::parse<hatch_style>("forward_diagonal"), csf_);
    }
    
    void test_method_(backward_diagonal) {
      assert::are_equal(3, enum_object<>::to_int32(hatch_style::backward_diagonal), csf_);
      assert::are_equal("backward_diagonal", enum_object<>::to_string(hatch_style::backward_diagonal), csf_);
      assert::are_equal(hatch_style::backward_diagonal, enum_object<>::parse<hatch_style>("backward_diagonal"), csf_);
    }
    
    void test_method_(cross) {
      assert::are_equal(4, enum_object<>::to_int32(hatch_style::cross), csf_);
      assert::are_equal("cross", enum_object<>::to_string(hatch_style::cross), csf_);
      assert::are_equal(hatch_style::cross, enum_object<>::parse<hatch_style>("cross"), csf_);
    }
    
    void test_method_(diagonal_cross) {
      assert::are_equal(5, enum_object<>::to_int32(hatch_style::diagonal_cross), csf_);
      assert::are_equal("diagonal_cross", enum_object<>::to_string(hatch_style::diagonal_cross), csf_);
      assert::are_equal(hatch_style::diagonal_cross, enum_object<>::parse<hatch_style>("diagonal_cross"), csf_);
    }
    
    void test_method_(percent_05) {
      assert::are_equal(6, enum_object<>::to_int32(hatch_style::percent_05), csf_);
      assert::are_equal("percent_05", enum_object<>::to_string(hatch_style::percent_05), csf_);
      assert::are_equal(hatch_style::percent_05, enum_object<>::parse<hatch_style>("percent_05"), csf_);
    }
    
    void test_method_(percent_10) {
      assert::are_equal(7, enum_object<>::to_int32(hatch_style::percent_10), csf_);
      assert::are_equal("percent_10", enum_object<>::to_string(hatch_style::percent_10), csf_);
      assert::are_equal(hatch_style::percent_10, enum_object<>::parse<hatch_style>("percent_10"), csf_);
    }
    
    void test_method_(percent_20) {
      assert::are_equal(8, enum_object<>::to_int32(hatch_style::percent_20), csf_);
      assert::are_equal("percent_20", enum_object<>::to_string(hatch_style::percent_20), csf_);
      assert::are_equal(hatch_style::percent_20, enum_object<>::parse<hatch_style>("percent_20"), csf_);
    }
    
    void test_method_(percent_25) {
      assert::are_equal(9, enum_object<>::to_int32(hatch_style::percent_25), csf_);
      assert::are_equal("percent_25", enum_object<>::to_string(hatch_style::percent_25), csf_);
      assert::are_equal(hatch_style::percent_25, enum_object<>::parse<hatch_style>("percent_25"), csf_);
    }
    
    void test_method_(percent_30) {
      assert::are_equal(10, enum_object<>::to_int32(hatch_style::percent_30), csf_);
      assert::are_equal("percent_30", enum_object<>::to_string(hatch_style::percent_30), csf_);
      assert::are_equal(hatch_style::percent_30, enum_object<>::parse<hatch_style>("percent_30"), csf_);
    }
    
    void test_method_(percent_40) {
      assert::are_equal(11, enum_object<>::to_int32(hatch_style::percent_40), csf_);
      assert::are_equal("percent_40", enum_object<>::to_string(hatch_style::percent_40), csf_);
      assert::are_equal(hatch_style::percent_40, enum_object<>::parse<hatch_style>("percent_40"), csf_);
    }
    
    void test_method_(percent_50) {
      assert::are_equal(12, enum_object<>::to_int32(hatch_style::percent_50), csf_);
      assert::are_equal("percent_50", enum_object<>::to_string(hatch_style::percent_50), csf_);
      assert::are_equal(hatch_style::percent_50, enum_object<>::parse<hatch_style>("percent_50"), csf_);
    }
    
    void test_method_(percent_60) {
      assert::are_equal(13, enum_object<>::to_int32(hatch_style::percent_60), csf_);
      assert::are_equal("percent_60", enum_object<>::to_string(hatch_style::percent_60), csf_);
      assert::are_equal(hatch_style::percent_60, enum_object<>::parse<hatch_style>("percent_60"), csf_);
    }
    
    void test_method_(percent_70) {
      assert::are_equal(14, enum_object<>::to_int32(hatch_style::percent_70), csf_);
      assert::are_equal("percent_70", enum_object<>::to_string(hatch_style::percent_70), csf_);
      assert::are_equal(hatch_style::percent_70, enum_object<>::parse<hatch_style>("percent_70"), csf_);
    }
    
    void test_method_(percent_75) {
      assert::are_equal(15, enum_object<>::to_int32(hatch_style::percent_75), csf_);
      assert::are_equal("percent_75", enum_object<>::to_string(hatch_style::percent_75), csf_);
      assert::are_equal(hatch_style::percent_75, enum_object<>::parse<hatch_style>("percent_75"), csf_);
    }
    
    void test_method_(percent_80) {
      assert::are_equal(16, enum_object<>::to_int32(hatch_style::percent_80), csf_);
      assert::are_equal("percent_80", enum_object<>::to_string(hatch_style::percent_80), csf_);
      assert::are_equal(hatch_style::percent_80, enum_object<>::parse<hatch_style>("percent_80"), csf_);
    }
    
    void test_method_(percent_90) {
      assert::are_equal(17, enum_object<>::to_int32(hatch_style::percent_90), csf_);
      assert::are_equal("percent_90", enum_object<>::to_string(hatch_style::percent_90), csf_);
      assert::are_equal(hatch_style::percent_90, enum_object<>::parse<hatch_style>("percent_90"), csf_);
    }
    
    void test_method_(light_downward_diagonal) {
      assert::are_equal(18, enum_object<>::to_int32(hatch_style::light_downward_diagonal), csf_);
      assert::are_equal("light_downward_diagonal", enum_object<>::to_string(hatch_style::light_downward_diagonal), csf_);
      assert::are_equal(hatch_style::light_downward_diagonal, enum_object<>::parse<hatch_style>("light_downward_diagonal"), csf_);
    }
    
    void test_method_(light_upward_diagonal) {
      assert::are_equal(19, enum_object<>::to_int32(hatch_style::light_upward_diagonal), csf_);
      assert::are_equal("light_upward_diagonal", enum_object<>::to_string(hatch_style::light_upward_diagonal), csf_);
      assert::are_equal(hatch_style::light_upward_diagonal, enum_object<>::parse<hatch_style>("light_upward_diagonal"), csf_);
    }
    
    void test_method_(dark_downward_diagonal) {
      assert::are_equal(20, enum_object<>::to_int32(hatch_style::dark_downward_diagonal), csf_);
      assert::are_equal("dark_downward_diagonal", enum_object<>::to_string(hatch_style::dark_downward_diagonal), csf_);
      assert::are_equal(hatch_style::dark_downward_diagonal, enum_object<>::parse<hatch_style>("dark_downward_diagonal"), csf_);
    }
    
    void test_method_(dark_upward_diagonal) {
      assert::are_equal(21, enum_object<>::to_int32(hatch_style::dark_upward_diagonal), csf_);
      assert::are_equal("dark_upward_diagonal", enum_object<>::to_string(hatch_style::dark_upward_diagonal), csf_);
      assert::are_equal(hatch_style::dark_upward_diagonal, enum_object<>::parse<hatch_style>("dark_upward_diagonal"), csf_);
    }
    
    void test_method_(wide_downward_diagonal) {
      assert::are_equal(22, enum_object<>::to_int32(hatch_style::wide_downward_diagonal), csf_);
      assert::are_equal("wide_downward_diagonal", enum_object<>::to_string(hatch_style::wide_downward_diagonal), csf_);
      assert::are_equal(hatch_style::wide_downward_diagonal, enum_object<>::parse<hatch_style>("wide_downward_diagonal"), csf_);
    }
    
    void test_method_(wide_upward_diagonal) {
      assert::are_equal(23, enum_object<>::to_int32(hatch_style::wide_upward_diagonal), csf_);
      assert::are_equal("wide_upward_diagonal", enum_object<>::to_string(hatch_style::wide_upward_diagonal), csf_);
      assert::are_equal(hatch_style::wide_upward_diagonal, enum_object<>::parse<hatch_style>("wide_upward_diagonal"), csf_);
    }
    
    void test_method_(light_vertical) {
      assert::are_equal(24, enum_object<>::to_int32(hatch_style::light_vertical), csf_);
      assert::are_equal("light_vertical", enum_object<>::to_string(hatch_style::light_vertical), csf_);
      assert::are_equal(hatch_style::light_vertical, enum_object<>::parse<hatch_style>("light_vertical"), csf_);
    }
    
    void test_method_(light_horizontal) {
      assert::are_equal(25, enum_object<>::to_int32(hatch_style::light_horizontal), csf_);
      assert::are_equal("light_horizontal", enum_object<>::to_string(hatch_style::light_horizontal), csf_);
      assert::are_equal(hatch_style::light_horizontal, enum_object<>::parse<hatch_style>("light_horizontal"), csf_);
    }
    
    void test_method_(narrow_vertical) {
      assert::are_equal(26, enum_object<>::to_int32(hatch_style::narrow_vertical), csf_);
      assert::are_equal("narrow_vertical", enum_object<>::to_string(hatch_style::narrow_vertical), csf_);
      assert::are_equal(hatch_style::narrow_vertical, enum_object<>::parse<hatch_style>("narrow_vertical"), csf_);
    }
    
    void test_method_(narrow_horizontal) {
      assert::are_equal(27, enum_object<>::to_int32(hatch_style::narrow_horizontal), csf_);
      assert::are_equal("narrow_horizontal", enum_object<>::to_string(hatch_style::narrow_horizontal), csf_);
      assert::are_equal(hatch_style::narrow_horizontal, enum_object<>::parse<hatch_style>("narrow_horizontal"), csf_);
    }
    
    void test_method_(dark_vertical) {
      assert::are_equal(28, enum_object<>::to_int32(hatch_style::dark_vertical), csf_);
      assert::are_equal("dark_vertical", enum_object<>::to_string(hatch_style::dark_vertical), csf_);
      assert::are_equal(hatch_style::dark_vertical, enum_object<>::parse<hatch_style>("dark_vertical"), csf_);
    }
    
    void test_method_(dark_horizontal) {
      assert::are_equal(29, enum_object<>::to_int32(hatch_style::dark_horizontal), csf_);
      assert::are_equal("dark_horizontal", enum_object<>::to_string(hatch_style::dark_horizontal), csf_);
      assert::are_equal(hatch_style::dark_horizontal, enum_object<>::parse<hatch_style>("dark_horizontal"), csf_);
    }
    
    void test_method_(dashed_downward_diagonal) {
      assert::are_equal(30, enum_object<>::to_int32(hatch_style::dashed_downward_diagonal), csf_);
      assert::are_equal("dashed_downward_diagonal", enum_object<>::to_string(hatch_style::dashed_downward_diagonal), csf_);
      assert::are_equal(hatch_style::dashed_downward_diagonal, enum_object<>::parse<hatch_style>("dashed_downward_diagonal"), csf_);
    }
    
    void test_method_(dashed_upward_diagonal) {
      assert::are_equal(31, enum_object<>::to_int32(hatch_style::dashed_upward_diagonal), csf_);
      assert::are_equal("dashed_upward_diagonal", enum_object<>::to_string(hatch_style::dashed_upward_diagonal), csf_);
      assert::are_equal(hatch_style::dashed_upward_diagonal, enum_object<>::parse<hatch_style>("dashed_upward_diagonal"), csf_);
    }
    
    void test_method_(dashed_horizontal) {
      assert::are_equal(32, enum_object<>::to_int32(hatch_style::dashed_horizontal), csf_);
      assert::are_equal("dashed_horizontal", enum_object<>::to_string(hatch_style::dashed_horizontal), csf_);
      assert::are_equal(hatch_style::dashed_horizontal, enum_object<>::parse<hatch_style>("dashed_horizontal"), csf_);
    }
    
    void test_method_(dashed_vertical) {
      assert::are_equal(33, enum_object<>::to_int32(hatch_style::dashed_vertical), csf_);
      assert::are_equal("dashed_vertical", enum_object<>::to_string(hatch_style::dashed_vertical), csf_);
      assert::are_equal(hatch_style::dashed_vertical, enum_object<>::parse<hatch_style>("dashed_vertical"), csf_);
    }
    
    void test_method_(small_confetti) {
      assert::are_equal(34, enum_object<>::to_int32(hatch_style::small_confetti), csf_);
      assert::are_equal("small_confetti", enum_object<>::to_string(hatch_style::small_confetti), csf_);
      assert::are_equal(hatch_style::small_confetti, enum_object<>::parse<hatch_style>("small_confetti"), csf_);
    }
    
    void test_method_(large_confetti) {
      assert::are_equal(35, enum_object<>::to_int32(hatch_style::large_confetti), csf_);
      assert::are_equal("large_confetti", enum_object<>::to_string(hatch_style::large_confetti), csf_);
      assert::are_equal(hatch_style::large_confetti, enum_object<>::parse<hatch_style>("large_confetti"), csf_);
    }
    
    void test_method_(zig_zag) {
      assert::are_equal(36, enum_object<>::to_int32(hatch_style::zig_zag), csf_);
      assert::are_equal("zig_zag", enum_object<>::to_string(hatch_style::zig_zag), csf_);
      assert::are_equal(hatch_style::zig_zag, enum_object<>::parse<hatch_style>("zig_zag"), csf_);
    }
    
    void test_method_(wave) {
      assert::are_equal(37, enum_object<>::to_int32(hatch_style::wave), csf_);
      assert::are_equal("wave", enum_object<>::to_string(hatch_style::wave), csf_);
      assert::are_equal(hatch_style::wave, enum_object<>::parse<hatch_style>("wave"), csf_);
    }
    
    void test_method_(diagonal_brick) {
      assert::are_equal(38, enum_object<>::to_int32(hatch_style::diagonal_brick), csf_);
      assert::are_equal("diagonal_brick", enum_object<>::to_string(hatch_style::diagonal_brick), csf_);
      assert::are_equal(hatch_style::diagonal_brick, enum_object<>::parse<hatch_style>("diagonal_brick"), csf_);
    }
    
    void test_method_(horizontal_brick) {
      assert::are_equal(39, enum_object<>::to_int32(hatch_style::horizontal_brick), csf_);
      assert::are_equal("horizontal_brick", enum_object<>::to_string(hatch_style::horizontal_brick), csf_);
      assert::are_equal(hatch_style::horizontal_brick, enum_object<>::parse<hatch_style>("horizontal_brick"), csf_);
    }
    
    void test_method_(weave) {
      assert::are_equal(40, enum_object<>::to_int32(hatch_style::weave), csf_);
      assert::are_equal("weave", enum_object<>::to_string(hatch_style::weave), csf_);
      assert::are_equal(hatch_style::weave, enum_object<>::parse<hatch_style>("weave"), csf_);
    }
    
    void test_method_(plaid) {
      assert::are_equal(41, enum_object<>::to_int32(hatch_style::plaid), csf_);
      assert::are_equal("plaid", enum_object<>::to_string(hatch_style::plaid), csf_);
      assert::are_equal(hatch_style::plaid, enum_object<>::parse<hatch_style>("plaid"), csf_);
    }
    
    void test_method_(divot) {
      assert::are_equal(42, enum_object<>::to_int32(hatch_style::divot), csf_);
      assert::are_equal("divot", enum_object<>::to_string(hatch_style::divot), csf_);
      assert::are_equal(hatch_style::divot, enum_object<>::parse<hatch_style>("divot"), csf_);
    }
    
    void test_method_(dotted_grid) {
      assert::are_equal(43, enum_object<>::to_int32(hatch_style::dotted_grid), csf_);
      assert::are_equal("dotted_grid", enum_object<>::to_string(hatch_style::dotted_grid), csf_);
      assert::are_equal(hatch_style::dotted_grid, enum_object<>::parse<hatch_style>("dotted_grid"), csf_);
    }
    
    void test_method_(dotted_diamond) {
      assert::are_equal(44, enum_object<>::to_int32(hatch_style::dotted_diamond), csf_);
      assert::are_equal("dotted_diamond", enum_object<>::to_string(hatch_style::dotted_diamond), csf_);
      assert::are_equal(hatch_style::dotted_diamond, enum_object<>::parse<hatch_style>("dotted_diamond"), csf_);
    }
    
    void test_method_(shingle) {
      assert::are_equal(45, enum_object<>::to_int32(hatch_style::shingle), csf_);
      assert::are_equal("shingle", enum_object<>::to_string(hatch_style::shingle), csf_);
      assert::are_equal(hatch_style::shingle, enum_object<>::parse<hatch_style>("shingle"), csf_);
    }
    
    void test_method_(trellis) {
      assert::are_equal(46, enum_object<>::to_int32(hatch_style::trellis), csf_);
      assert::are_equal("trellis", enum_object<>::to_string(hatch_style::trellis), csf_);
      assert::are_equal(hatch_style::trellis, enum_object<>::parse<hatch_style>("trellis"), csf_);
    }
    
    void test_method_(sphere) {
      assert::are_equal(47, enum_object<>::to_int32(hatch_style::sphere), csf_);
      assert::are_equal("sphere", enum_object<>::to_string(hatch_style::sphere), csf_);
      assert::are_equal(hatch_style::sphere, enum_object<>::parse<hatch_style>("sphere"), csf_);
    }
    
    void test_method_(small_grid) {
      assert::are_equal(48, enum_object<>::to_int32(hatch_style::small_grid), csf_);
      assert::are_equal("small_grid", enum_object<>::to_string(hatch_style::small_grid), csf_);
      assert::are_equal(hatch_style::small_grid, enum_object<>::parse<hatch_style>("small_grid"), csf_);
    }
    
    void test_method_(small_checker_board) {
      assert::are_equal(49, enum_object<>::to_int32(hatch_style::small_checker_board), csf_);
      assert::are_equal("small_checker_board", enum_object<>::to_string(hatch_style::small_checker_board), csf_);
      assert::are_equal(hatch_style::small_checker_board, enum_object<>::parse<hatch_style>("small_checker_board"), csf_);
    }
    
    void test_method_(large_checker_board) {
      assert::are_equal(50, enum_object<>::to_int32(hatch_style::large_checker_board), csf_);
      assert::are_equal("large_checker_board", enum_object<>::to_string(hatch_style::large_checker_board), csf_);
      assert::are_equal(hatch_style::large_checker_board, enum_object<>::parse<hatch_style>("large_checker_board"), csf_);
    }
    
    void test_method_(outlined_diamond) {
      assert::are_equal(51, enum_object<>::to_int32(hatch_style::outlined_diamond), csf_);
      assert::are_equal("outlined_diamond", enum_object<>::to_string(hatch_style::outlined_diamond), csf_);
      assert::are_equal(hatch_style::outlined_diamond, enum_object<>::parse<hatch_style>("outlined_diamond"), csf_);
    }
    
    void test_method_(solid_diamond) {
      assert::are_equal(52, enum_object<>::to_int32(hatch_style::solid_diamond), csf_);
      assert::are_equal("solid_diamond", enum_object<>::to_string(hatch_style::solid_diamond), csf_);
      assert::are_equal(hatch_style::solid_diamond, enum_object<>::parse<hatch_style>("solid_diamond"), csf_);
    }
    
    void test_method_(wide_checker_board) {
      assert::are_equal(53, enum_object<>::to_int32(hatch_style::wide_checker_board), csf_);
      assert::are_equal("wide_checker_board", enum_object<>::to_string(hatch_style::wide_checker_board), csf_);
      assert::are_equal(hatch_style::wide_checker_board, enum_object<>::parse<hatch_style>("wide_checker_board"), csf_);
    }
  };
}
