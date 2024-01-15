#include <xtd/drawing/international_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(international_system_images_tests) {
    void test_method_(default_size) {
      auto s = international_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(flag_af) {
      auto i = international_system_images::flag_af();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-af"), i, csf_);
    }

    void test_method_(flag_af_with_specified_size) {
      auto i = international_system_images::flag_af({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-af", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ax) {
      auto i = international_system_images::flag_ax();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ax"), i, csf_);
    }

    void test_method_(flag_ax_with_specified_size) {
      auto i = international_system_images::flag_ax({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ax", size {64, 64}), i, csf_);
    }

    void test_method_(flag_al) {
      auto i = international_system_images::flag_al();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-al"), i, csf_);
    }

    void test_method_(flag_al_with_specified_size) {
      auto i = international_system_images::flag_al({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-al", size {64, 64}), i, csf_);
    }

    void test_method_(flag_dz) {
      auto i = international_system_images::flag_dz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-dz"), i, csf_);
    }

    void test_method_(flag_dz_with_specified_size) {
      auto i = international_system_images::flag_dz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-dz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_as) {
      auto i = international_system_images::flag_as();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-as"), i, csf_);
    }

    void test_method_(flag_as_with_specified_size) {
      auto i = international_system_images::flag_as({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-as", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ad) {
      auto i = international_system_images::flag_ad();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ad"), i, csf_);
    }

    void test_method_(flag_ad_with_specified_size) {
      auto i = international_system_images::flag_ad({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ad", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ao) {
      auto i = international_system_images::flag_ao();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ao"), i, csf_);
    }

    void test_method_(flag_ao_with_specified_size) {
      auto i = international_system_images::flag_ao({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ao", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ai) {
      auto i = international_system_images::flag_ai();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ai"), i, csf_);
    }

    void test_method_(flag_ai_with_specified_size) {
      auto i = international_system_images::flag_ai({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ai", size {64, 64}), i, csf_);
    }

    void test_method_(flag_aq) {
      auto i = international_system_images::flag_aq();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-aq"), i, csf_);
    }

    void test_method_(flag_aq_with_specified_size) {
      auto i = international_system_images::flag_aq({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-aq", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ag) {
      auto i = international_system_images::flag_ag();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ag"), i, csf_);
    }

    void test_method_(flag_ag_with_specified_size) {
      auto i = international_system_images::flag_ag({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ag", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ar) {
      auto i = international_system_images::flag_ar();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ar"), i, csf_);
    }

    void test_method_(flag_ar_with_specified_size) {
      auto i = international_system_images::flag_ar({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ar", size {64, 64}), i, csf_);
    }

    void test_method_(flag_am) {
      auto i = international_system_images::flag_am();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-am"), i, csf_);
    }

    void test_method_(flag_am_with_specified_size) {
      auto i = international_system_images::flag_am({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-am", size {64, 64}), i, csf_);
    }

    void test_method_(flag_aw) {
      auto i = international_system_images::flag_aw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-aw"), i, csf_);
    }

    void test_method_(flag_aw_with_specified_size) {
      auto i = international_system_images::flag_aw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-aw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_au) {
      auto i = international_system_images::flag_au();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-au"), i, csf_);
    }

    void test_method_(flag_au_with_specified_size) {
      auto i = international_system_images::flag_au({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-au", size {64, 64}), i, csf_);
    }

    void test_method_(flag_at) {
      auto i = international_system_images::flag_at();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-at"), i, csf_);
    }

    void test_method_(flag_at_with_specified_size) {
      auto i = international_system_images::flag_at({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-at", size {64, 64}), i, csf_);
    }

    void test_method_(flag_az) {
      auto i = international_system_images::flag_az();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-az"), i, csf_);
    }

    void test_method_(flag_az_with_specified_size) {
      auto i = international_system_images::flag_az({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-az", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bs) {
      auto i = international_system_images::flag_bs();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bs"), i, csf_);
    }

    void test_method_(flag_bs_with_specified_size) {
      auto i = international_system_images::flag_bs({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bs", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bh) {
      auto i = international_system_images::flag_bh();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bh"), i, csf_);
    }

    void test_method_(flag_bh_with_specified_size) {
      auto i = international_system_images::flag_bh({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bh", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bd) {
      auto i = international_system_images::flag_bd();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bd"), i, csf_);
    }

    void test_method_(flag_bd_with_specified_size) {
      auto i = international_system_images::flag_bd({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bd", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bb) {
      auto i = international_system_images::flag_bb();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bb"), i, csf_);
    }

    void test_method_(flag_bb_with_specified_size) {
      auto i = international_system_images::flag_bb({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bb", size {64, 64}), i, csf_);
    }

    void test_method_(flag_by) {
      auto i = international_system_images::flag_by();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-by"), i, csf_);
    }

    void test_method_(flag_by_with_specified_size) {
      auto i = international_system_images::flag_by({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-by", size {64, 64}), i, csf_);
    }

    void test_method_(flag_be) {
      auto i = international_system_images::flag_be();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-be"), i, csf_);
    }

    void test_method_(flag_be_with_specified_size) {
      auto i = international_system_images::flag_be({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-be", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bz) {
      auto i = international_system_images::flag_bz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bz"), i, csf_);
    }

    void test_method_(flag_bz_with_specified_size) {
      auto i = international_system_images::flag_bz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bj) {
      auto i = international_system_images::flag_bj();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bj"), i, csf_);
    }

    void test_method_(flag_bj_with_specified_size) {
      auto i = international_system_images::flag_bj({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bj", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bm) {
      auto i = international_system_images::flag_bm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bm"), i, csf_);
    }

    void test_method_(flag_bm_with_specified_size) {
      auto i = international_system_images::flag_bm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bt) {
      auto i = international_system_images::flag_bt();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bt"), i, csf_);
    }

    void test_method_(flag_bt_with_specified_size) {
      auto i = international_system_images::flag_bt({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bt", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bo) {
      auto i = international_system_images::flag_bo();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bo"), i, csf_);
    }

    void test_method_(flag_bo_with_specified_size) {
      auto i = international_system_images::flag_bo({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bo", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bq) {
      auto i = international_system_images::flag_bq();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bq"), i, csf_);
    }

    void test_method_(flag_bq_with_specified_size) {
      auto i = international_system_images::flag_bq({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bq", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ba) {
      auto i = international_system_images::flag_ba();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ba"), i, csf_);
    }

    void test_method_(flag_ba_with_specified_size) {
      auto i = international_system_images::flag_ba({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ba", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bw) {
      auto i = international_system_images::flag_bw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bw"), i, csf_);
    }

    void test_method_(flag_bw_with_specified_size) {
      auto i = international_system_images::flag_bw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bv) {
      auto i = international_system_images::flag_bv();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bv"), i, csf_);
    }

    void test_method_(flag_bv_with_specified_size) {
      auto i = international_system_images::flag_bv({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bv", size {64, 64}), i, csf_);
    }

    void test_method_(flag_br) {
      auto i = international_system_images::flag_br();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-br"), i, csf_);
    }

    void test_method_(flag_br_with_specified_size) {
      auto i = international_system_images::flag_br({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-br", size {64, 64}), i, csf_);
    }

    void test_method_(flag_io) {
      auto i = international_system_images::flag_io();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-io"), i, csf_);
    }

    void test_method_(flag_io_with_specified_size) {
      auto i = international_system_images::flag_io({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-io", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bn) {
      auto i = international_system_images::flag_bn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bn"), i, csf_);
    }

    void test_method_(flag_bn_with_specified_size) {
      auto i = international_system_images::flag_bn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bg) {
      auto i = international_system_images::flag_bg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bg"), i, csf_);
    }

    void test_method_(flag_bg_with_specified_size) {
      auto i = international_system_images::flag_bg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bf) {
      auto i = international_system_images::flag_bf();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bf"), i, csf_);
    }

    void test_method_(flag_bf_with_specified_size) {
      auto i = international_system_images::flag_bf({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bf", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bi) {
      auto i = international_system_images::flag_bi();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bi"), i, csf_);
    }

    void test_method_(flag_bi_with_specified_size) {
      auto i = international_system_images::flag_bi({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bi", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cv) {
      auto i = international_system_images::flag_cv();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cv"), i, csf_);
    }

    void test_method_(flag_cv_with_specified_size) {
      auto i = international_system_images::flag_cv({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cv", size {64, 64}), i, csf_);
    }

    void test_method_(flag_kh) {
      auto i = international_system_images::flag_kh();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kh"), i, csf_);
    }

    void test_method_(flag_kh_with_specified_size) {
      auto i = international_system_images::flag_kh({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kh", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cm) {
      auto i = international_system_images::flag_cm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cm"), i, csf_);
    }

    void test_method_(flag_cm_with_specified_size) {
      auto i = international_system_images::flag_cm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ca) {
      auto i = international_system_images::flag_ca();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ca"), i, csf_);
    }

    void test_method_(flag_ca_with_specified_size) {
      auto i = international_system_images::flag_ca({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ca", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ky) {
      auto i = international_system_images::flag_ky();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ky"), i, csf_);
    }

    void test_method_(flag_ky_with_specified_size) {
      auto i = international_system_images::flag_ky({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ky", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cf) {
      auto i = international_system_images::flag_cf();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cf"), i, csf_);
    }

    void test_method_(flag_cf_with_specified_size) {
      auto i = international_system_images::flag_cf({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cf", size {64, 64}), i, csf_);
    }

    void test_method_(flag_td) {
      auto i = international_system_images::flag_td();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-td"), i, csf_);
    }

    void test_method_(flag_td_with_specified_size) {
      auto i = international_system_images::flag_td({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-td", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cl) {
      auto i = international_system_images::flag_cl();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cl"), i, csf_);
    }

    void test_method_(flag_cl_with_specified_size) {
      auto i = international_system_images::flag_cl({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cl", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cn) {
      auto i = international_system_images::flag_cn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cn"), i, csf_);
    }

    void test_method_(flag_cn_with_specified_size) {
      auto i = international_system_images::flag_cn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cx) {
      auto i = international_system_images::flag_cx();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cx"), i, csf_);
    }

    void test_method_(flag_cx_with_specified_size) {
      auto i = international_system_images::flag_cx({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cx", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cc) {
      auto i = international_system_images::flag_cc();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cc"), i, csf_);
    }

    void test_method_(flag_cc_with_specified_size) {
      auto i = international_system_images::flag_cc({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cc", size {64, 64}), i, csf_);
    }

    void test_method_(flag_co) {
      auto i = international_system_images::flag_co();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-co"), i, csf_);
    }

    void test_method_(flag_co_with_specified_size) {
      auto i = international_system_images::flag_co({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-co", size {64, 64}), i, csf_);
    }

    void test_method_(flag_km) {
      auto i = international_system_images::flag_km();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-km"), i, csf_);
    }

    void test_method_(flag_km_with_specified_size) {
      auto i = international_system_images::flag_km({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-km", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cg) {
      auto i = international_system_images::flag_cg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cg"), i, csf_);
    }

    void test_method_(flag_cg_with_specified_size) {
      auto i = international_system_images::flag_cg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cd) {
      auto i = international_system_images::flag_cd();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cd"), i, csf_);
    }

    void test_method_(flag_cd_with_specified_size) {
      auto i = international_system_images::flag_cd({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cd", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ck) {
      auto i = international_system_images::flag_ck();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ck"), i, csf_);
    }

    void test_method_(flag_ck_with_specified_size) {
      auto i = international_system_images::flag_ck({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ck", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cr) {
      auto i = international_system_images::flag_cr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cr"), i, csf_);
    }

    void test_method_(flag_cr_with_specified_size) {
      auto i = international_system_images::flag_cr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ci) {
      auto i = international_system_images::flag_ci();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ci"), i, csf_);
    }

    void test_method_(flag_ci_with_specified_size) {
      auto i = international_system_images::flag_ci({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ci", size {64, 64}), i, csf_);
    }

    void test_method_(flag_hr) {
      auto i = international_system_images::flag_hr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hr"), i, csf_);
    }

    void test_method_(flag_hr_with_specified_size) {
      auto i = international_system_images::flag_hr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cu) {
      auto i = international_system_images::flag_cu();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cu"), i, csf_);
    }

    void test_method_(flag_cu_with_specified_size) {
      auto i = international_system_images::flag_cu({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cu", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cw) {
      auto i = international_system_images::flag_cw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cw"), i, csf_);
    }

    void test_method_(flag_cw_with_specified_size) {
      auto i = international_system_images::flag_cw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cy) {
      auto i = international_system_images::flag_cy();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cy"), i, csf_);
    }

    void test_method_(flag_cy_with_specified_size) {
      auto i = international_system_images::flag_cy({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cy", size {64, 64}), i, csf_);
    }

    void test_method_(flag_cz) {
      auto i = international_system_images::flag_cz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cz"), i, csf_);
    }

    void test_method_(flag_cz_with_specified_size) {
      auto i = international_system_images::flag_cz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-cz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_dk) {
      auto i = international_system_images::flag_dk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-dk"), i, csf_);
    }

    void test_method_(flag_dk_with_specified_size) {
      auto i = international_system_images::flag_dk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-dk", size {64, 64}), i, csf_);
    }

    void test_method_(flag_dj) {
      auto i = international_system_images::flag_dj();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-dj"), i, csf_);
    }

    void test_method_(flag_dj_with_specified_size) {
      auto i = international_system_images::flag_dj({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-dj", size {64, 64}), i, csf_);
    }

    void test_method_(flag_dm) {
      auto i = international_system_images::flag_dm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-dm"), i, csf_);
    }

    void test_method_(flag_dm_with_specified_size) {
      auto i = international_system_images::flag_dm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-dm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_do) {
      auto i = international_system_images::flag_do();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-do"), i, csf_);
    }

    void test_method_(flag_do_with_specified_size) {
      auto i = international_system_images::flag_do({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-do", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ec) {
      auto i = international_system_images::flag_ec();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ec"), i, csf_);
    }

    void test_method_(flag_ec_with_specified_size) {
      auto i = international_system_images::flag_ec({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ec", size {64, 64}), i, csf_);
    }

    void test_method_(flag_eg) {
      auto i = international_system_images::flag_eg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-eg"), i, csf_);
    }

    void test_method_(flag_eg_with_specified_size) {
      auto i = international_system_images::flag_eg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-eg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sv) {
      auto i = international_system_images::flag_sv();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sv"), i, csf_);
    }

    void test_method_(flag_sv_with_specified_size) {
      auto i = international_system_images::flag_sv({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sv", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gq) {
      auto i = international_system_images::flag_gq();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gq"), i, csf_);
    }

    void test_method_(flag_gq_with_specified_size) {
      auto i = international_system_images::flag_gq({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gq", size {64, 64}), i, csf_);
    }

    void test_method_(flag_er) {
      auto i = international_system_images::flag_er();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-er"), i, csf_);
    }

    void test_method_(flag_er_with_specified_size) {
      auto i = international_system_images::flag_er({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-er", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ee) {
      auto i = international_system_images::flag_ee();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ee"), i, csf_);
    }

    void test_method_(flag_ee_with_specified_size) {
      auto i = international_system_images::flag_ee({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ee", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sz) {
      auto i = international_system_images::flag_sz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sz"), i, csf_);
    }

    void test_method_(flag_sz_with_specified_size) {
      auto i = international_system_images::flag_sz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_et) {
      auto i = international_system_images::flag_et();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-et"), i, csf_);
    }

    void test_method_(flag_et_with_specified_size) {
      auto i = international_system_images::flag_et({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-et", size {64, 64}), i, csf_);
    }

    void test_method_(flag_fk) {
      auto i = international_system_images::flag_fk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fk"), i, csf_);
    }

    void test_method_(flag_fk_with_specified_size) {
      auto i = international_system_images::flag_fk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fk", size {64, 64}), i, csf_);
    }

    void test_method_(flag_fo) {
      auto i = international_system_images::flag_fo();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fo"), i, csf_);
    }

    void test_method_(flag_fo_with_specified_size) {
      auto i = international_system_images::flag_fo({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fo", size {64, 64}), i, csf_);
    }

    void test_method_(flag_fj) {
      auto i = international_system_images::flag_fj();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fj"), i, csf_);
    }

    void test_method_(flag_fj_with_specified_size) {
      auto i = international_system_images::flag_fj({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fj", size {64, 64}), i, csf_);
    }

    void test_method_(flag_fi) {
      auto i = international_system_images::flag_fi();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fi"), i, csf_);
    }

    void test_method_(flag_fi_with_specified_size) {
      auto i = international_system_images::flag_fi({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fi", size {64, 64}), i, csf_);
    }

    void test_method_(flag_fr) {
      auto i = international_system_images::flag_fr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fr"), i, csf_);
    }

    void test_method_(flag_fr_with_specified_size) {
      auto i = international_system_images::flag_fr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gf) {
      auto i = international_system_images::flag_gf();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gf"), i, csf_);
    }

    void test_method_(flag_gf_with_specified_size) {
      auto i = international_system_images::flag_gf({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gf", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pf) {
      auto i = international_system_images::flag_pf();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pf"), i, csf_);
    }

    void test_method_(flag_pf_with_specified_size) {
      auto i = international_system_images::flag_pf({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pf", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tf) {
      auto i = international_system_images::flag_tf();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tf"), i, csf_);
    }

    void test_method_(flag_tf_with_specified_size) {
      auto i = international_system_images::flag_tf({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tf", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ga) {
      auto i = international_system_images::flag_ga();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ga"), i, csf_);
    }

    void test_method_(flag_ga_with_specified_size) {
      auto i = international_system_images::flag_ga({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ga", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gm) {
      auto i = international_system_images::flag_gm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gm"), i, csf_);
    }

    void test_method_(flag_gm_with_specified_size) {
      auto i = international_system_images::flag_gm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ge) {
      auto i = international_system_images::flag_ge();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ge"), i, csf_);
    }

    void test_method_(flag_ge_with_specified_size) {
      auto i = international_system_images::flag_ge({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ge", size {64, 64}), i, csf_);
    }

    void test_method_(flag_de) {
      auto i = international_system_images::flag_de();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-de"), i, csf_);
    }

    void test_method_(flag_de_with_specified_size) {
      auto i = international_system_images::flag_de({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-de", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gh) {
      auto i = international_system_images::flag_gh();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gh"), i, csf_);
    }

    void test_method_(flag_gh_with_specified_size) {
      auto i = international_system_images::flag_gh({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gh", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gi) {
      auto i = international_system_images::flag_gi();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gi"), i, csf_);
    }

    void test_method_(flag_gi_with_specified_size) {
      auto i = international_system_images::flag_gi({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gi", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gr) {
      auto i = international_system_images::flag_gr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gr"), i, csf_);
    }

    void test_method_(flag_gr_with_specified_size) {
      auto i = international_system_images::flag_gr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gl) {
      auto i = international_system_images::flag_gl();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gl"), i, csf_);
    }

    void test_method_(flag_gl_with_specified_size) {
      auto i = international_system_images::flag_gl({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gl", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gd) {
      auto i = international_system_images::flag_gd();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gd"), i, csf_);
    }

    void test_method_(flag_gd_with_specified_size) {
      auto i = international_system_images::flag_gd({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gd", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gp) {
      auto i = international_system_images::flag_gp();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gp"), i, csf_);
    }

    void test_method_(flag_gp_with_specified_size) {
      auto i = international_system_images::flag_gp({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gp", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gu) {
      auto i = international_system_images::flag_gu();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gu"), i, csf_);
    }

    void test_method_(flag_gu_with_specified_size) {
      auto i = international_system_images::flag_gu({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gu", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gt) {
      auto i = international_system_images::flag_gt();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gt"), i, csf_);
    }

    void test_method_(flag_gt_with_specified_size) {
      auto i = international_system_images::flag_gt({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gt", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gg) {
      auto i = international_system_images::flag_gg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gg"), i, csf_);
    }

    void test_method_(flag_gg_with_specified_size) {
      auto i = international_system_images::flag_gg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gn) {
      auto i = international_system_images::flag_gn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gn"), i, csf_);
    }

    void test_method_(flag_gn_with_specified_size) {
      auto i = international_system_images::flag_gn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gw) {
      auto i = international_system_images::flag_gw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gw"), i, csf_);
    }

    void test_method_(flag_gw_with_specified_size) {
      auto i = international_system_images::flag_gw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gy) {
      auto i = international_system_images::flag_gy();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gy"), i, csf_);
    }

    void test_method_(flag_gy_with_specified_size) {
      auto i = international_system_images::flag_gy({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gy", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ht) {
      auto i = international_system_images::flag_ht();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ht"), i, csf_);
    }

    void test_method_(flag_ht_with_specified_size) {
      auto i = international_system_images::flag_ht({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ht", size {64, 64}), i, csf_);
    }

    void test_method_(flag_hm) {
      auto i = international_system_images::flag_hm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hm"), i, csf_);
    }

    void test_method_(flag_hm_with_specified_size) {
      auto i = international_system_images::flag_hm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_va) {
      auto i = international_system_images::flag_va();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-va"), i, csf_);
    }

    void test_method_(flag_va_with_specified_size) {
      auto i = international_system_images::flag_va({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-va", size {64, 64}), i, csf_);
    }

    void test_method_(flag_hn) {
      auto i = international_system_images::flag_hn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hn"), i, csf_);
    }

    void test_method_(flag_hn_with_specified_size) {
      auto i = international_system_images::flag_hn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_hk) {
      auto i = international_system_images::flag_hk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hk"), i, csf_);
    }

    void test_method_(flag_hk_with_specified_size) {
      auto i = international_system_images::flag_hk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hk", size {64, 64}), i, csf_);
    }

    void test_method_(flag_hu) {
      auto i = international_system_images::flag_hu();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hu"), i, csf_);
    }

    void test_method_(flag_hu_with_specified_size) {
      auto i = international_system_images::flag_hu({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-hu", size {64, 64}), i, csf_);
    }

    void test_method_(flag_is) {
      auto i = international_system_images::flag_is();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-is"), i, csf_);
    }

    void test_method_(flag_is_with_specified_size) {
      auto i = international_system_images::flag_is({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-is", size {64, 64}), i, csf_);
    }

    void test_method_(flag_in) {
      auto i = international_system_images::flag_in();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-in"), i, csf_);
    }

    void test_method_(flag_in_with_specified_size) {
      auto i = international_system_images::flag_in({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-in", size {64, 64}), i, csf_);
    }

    void test_method_(flag_id) {
      auto i = international_system_images::flag_id();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-id"), i, csf_);
    }

    void test_method_(flag_id_with_specified_size) {
      auto i = international_system_images::flag_id({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-id", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ir) {
      auto i = international_system_images::flag_ir();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ir"), i, csf_);
    }

    void test_method_(flag_ir_with_specified_size) {
      auto i = international_system_images::flag_ir({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ir", size {64, 64}), i, csf_);
    }

    void test_method_(flag_iq) {
      auto i = international_system_images::flag_iq();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-iq"), i, csf_);
    }

    void test_method_(flag_iq_with_specified_size) {
      auto i = international_system_images::flag_iq({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-iq", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ie) {
      auto i = international_system_images::flag_ie();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ie"), i, csf_);
    }

    void test_method_(flag_ie_with_specified_size) {
      auto i = international_system_images::flag_ie({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ie", size {64, 64}), i, csf_);
    }

    void test_method_(flag_im) {
      auto i = international_system_images::flag_im();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-im"), i, csf_);
    }

    void test_method_(flag_im_with_specified_size) {
      auto i = international_system_images::flag_im({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-im", size {64, 64}), i, csf_);
    }

    void test_method_(flag_il) {
      auto i = international_system_images::flag_il();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-il"), i, csf_);
    }

    void test_method_(flag_il_with_specified_size) {
      auto i = international_system_images::flag_il({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-il", size {64, 64}), i, csf_);
    }

    void test_method_(flag_it) {
      auto i = international_system_images::flag_it();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-it"), i, csf_);
    }

    void test_method_(flag_it_with_specified_size) {
      auto i = international_system_images::flag_it({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-it", size {64, 64}), i, csf_);
    }

    void test_method_(flag_jm) {
      auto i = international_system_images::flag_jm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-jm"), i, csf_);
    }

    void test_method_(flag_jm_with_specified_size) {
      auto i = international_system_images::flag_jm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-jm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_jp) {
      auto i = international_system_images::flag_jp();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-jp"), i, csf_);
    }

    void test_method_(flag_jp_with_specified_size) {
      auto i = international_system_images::flag_jp({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-jp", size {64, 64}), i, csf_);
    }

    void test_method_(flag_je) {
      auto i = international_system_images::flag_je();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-je"), i, csf_);
    }

    void test_method_(flag_je_with_specified_size) {
      auto i = international_system_images::flag_je({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-je", size {64, 64}), i, csf_);
    }

    void test_method_(flag_jo) {
      auto i = international_system_images::flag_jo();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-jo"), i, csf_);
    }

    void test_method_(flag_jo_with_specified_size) {
      auto i = international_system_images::flag_jo({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-jo", size {64, 64}), i, csf_);
    }

    void test_method_(flag_kz) {
      auto i = international_system_images::flag_kz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kz"), i, csf_);
    }

    void test_method_(flag_kz_with_specified_size) {
      auto i = international_system_images::flag_kz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ke) {
      auto i = international_system_images::flag_ke();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ke"), i, csf_);
    }

    void test_method_(flag_ke_with_specified_size) {
      auto i = international_system_images::flag_ke({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ke", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ki) {
      auto i = international_system_images::flag_ki();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ki"), i, csf_);
    }

    void test_method_(flag_ki_with_specified_size) {
      auto i = international_system_images::flag_ki({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ki", size {64, 64}), i, csf_);
    }

    void test_method_(flag_kp) {
      auto i = international_system_images::flag_kp();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kp"), i, csf_);
    }

    void test_method_(flag_kp_with_specified_size) {
      auto i = international_system_images::flag_kp({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kp", size {64, 64}), i, csf_);
    }

    void test_method_(flag_kr) {
      auto i = international_system_images::flag_kr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kr"), i, csf_);
    }

    void test_method_(flag_kr_with_specified_size) {
      auto i = international_system_images::flag_kr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_kw) {
      auto i = international_system_images::flag_kw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kw"), i, csf_);
    }

    void test_method_(flag_kw_with_specified_size) {
      auto i = international_system_images::flag_kw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_kg) {
      auto i = international_system_images::flag_kg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kg"), i, csf_);
    }

    void test_method_(flag_kg_with_specified_size) {
      auto i = international_system_images::flag_kg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_la) {
      auto i = international_system_images::flag_la();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-la"), i, csf_);
    }

    void test_method_(flag_la_with_specified_size) {
      auto i = international_system_images::flag_la({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-la", size {64, 64}), i, csf_);
    }

    void test_method_(flag_lv) {
      auto i = international_system_images::flag_lv();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lv"), i, csf_);
    }

    void test_method_(flag_lv_with_specified_size) {
      auto i = international_system_images::flag_lv({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lv", size {64, 64}), i, csf_);
    }

    void test_method_(flag_lb) {
      auto i = international_system_images::flag_lb();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lb"), i, csf_);
    }

    void test_method_(flag_lb_with_specified_size) {
      auto i = international_system_images::flag_lb({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lb", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ls) {
      auto i = international_system_images::flag_ls();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ls"), i, csf_);
    }

    void test_method_(flag_ls_with_specified_size) {
      auto i = international_system_images::flag_ls({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ls", size {64, 64}), i, csf_);
    }

    void test_method_(flag_lr) {
      auto i = international_system_images::flag_lr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lr"), i, csf_);
    }

    void test_method_(flag_lr_with_specified_size) {
      auto i = international_system_images::flag_lr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ly) {
      auto i = international_system_images::flag_ly();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ly"), i, csf_);
    }

    void test_method_(flag_ly_with_specified_size) {
      auto i = international_system_images::flag_ly({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ly", size {64, 64}), i, csf_);
    }

    void test_method_(flag_li) {
      auto i = international_system_images::flag_li();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-li"), i, csf_);
    }

    void test_method_(flag_li_with_specified_size) {
      auto i = international_system_images::flag_li({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-li", size {64, 64}), i, csf_);
    }

    void test_method_(flag_lt) {
      auto i = international_system_images::flag_lt();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lt"), i, csf_);
    }

    void test_method_(flag_lt_with_specified_size) {
      auto i = international_system_images::flag_lt({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lt", size {64, 64}), i, csf_);
    }

    void test_method_(flag_lu) {
      auto i = international_system_images::flag_lu();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lu"), i, csf_);
    }

    void test_method_(flag_lu_with_specified_size) {
      auto i = international_system_images::flag_lu({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lu", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mo) {
      auto i = international_system_images::flag_mo();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mo"), i, csf_);
    }

    void test_method_(flag_mo_with_specified_size) {
      auto i = international_system_images::flag_mo({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mo", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mg) {
      auto i = international_system_images::flag_mg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mg"), i, csf_);
    }

    void test_method_(flag_mg_with_specified_size) {
      auto i = international_system_images::flag_mg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mw) {
      auto i = international_system_images::flag_mw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mw"), i, csf_);
    }

    void test_method_(flag_mw_with_specified_size) {
      auto i = international_system_images::flag_mw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_my) {
      auto i = international_system_images::flag_my();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-my"), i, csf_);
    }

    void test_method_(flag_my_with_specified_size) {
      auto i = international_system_images::flag_my({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-my", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mv) {
      auto i = international_system_images::flag_mv();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mv"), i, csf_);
    }

    void test_method_(flag_mv_with_specified_size) {
      auto i = international_system_images::flag_mv({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mv", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ml) {
      auto i = international_system_images::flag_ml();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ml"), i, csf_);
    }

    void test_method_(flag_ml_with_specified_size) {
      auto i = international_system_images::flag_ml({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ml", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mt) {
      auto i = international_system_images::flag_mt();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mt"), i, csf_);
    }

    void test_method_(flag_mt_with_specified_size) {
      auto i = international_system_images::flag_mt({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mt", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mh) {
      auto i = international_system_images::flag_mh();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mh"), i, csf_);
    }

    void test_method_(flag_mh_with_specified_size) {
      auto i = international_system_images::flag_mh({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mh", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mq) {
      auto i = international_system_images::flag_mq();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mq"), i, csf_);
    }

    void test_method_(flag_mq_with_specified_size) {
      auto i = international_system_images::flag_mq({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mq", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mr) {
      auto i = international_system_images::flag_mr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mr"), i, csf_);
    }

    void test_method_(flag_mr_with_specified_size) {
      auto i = international_system_images::flag_mr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mu) {
      auto i = international_system_images::flag_mu();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mu"), i, csf_);
    }

    void test_method_(flag_mu_with_specified_size) {
      auto i = international_system_images::flag_mu({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mu", size {64, 64}), i, csf_);
    }

    void test_method_(flag_yt) {
      auto i = international_system_images::flag_yt();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-yt"), i, csf_);
    }

    void test_method_(flag_yt_with_specified_size) {
      auto i = international_system_images::flag_yt({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-yt", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mx) {
      auto i = international_system_images::flag_mx();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mx"), i, csf_);
    }

    void test_method_(flag_mx_with_specified_size) {
      auto i = international_system_images::flag_mx({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mx", size {64, 64}), i, csf_);
    }

    void test_method_(flag_fm) {
      auto i = international_system_images::flag_fm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fm"), i, csf_);
    }

    void test_method_(flag_fm_with_specified_size) {
      auto i = international_system_images::flag_fm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-fm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_md) {
      auto i = international_system_images::flag_md();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-md"), i, csf_);
    }

    void test_method_(flag_md_with_specified_size) {
      auto i = international_system_images::flag_md({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-md", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mc) {
      auto i = international_system_images::flag_mc();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mc"), i, csf_);
    }

    void test_method_(flag_mc_with_specified_size) {
      auto i = international_system_images::flag_mc({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mc", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mn) {
      auto i = international_system_images::flag_mn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mn"), i, csf_);
    }

    void test_method_(flag_mn_with_specified_size) {
      auto i = international_system_images::flag_mn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_me) {
      auto i = international_system_images::flag_me();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-me"), i, csf_);
    }

    void test_method_(flag_me_with_specified_size) {
      auto i = international_system_images::flag_me({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-me", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ms) {
      auto i = international_system_images::flag_ms();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ms"), i, csf_);
    }

    void test_method_(flag_ms_with_specified_size) {
      auto i = international_system_images::flag_ms({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ms", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ma) {
      auto i = international_system_images::flag_ma();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ma"), i, csf_);
    }

    void test_method_(flag_ma_with_specified_size) {
      auto i = international_system_images::flag_ma({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ma", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mz) {
      auto i = international_system_images::flag_mz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mz"), i, csf_);
    }

    void test_method_(flag_mz_with_specified_size) {
      auto i = international_system_images::flag_mz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mm) {
      auto i = international_system_images::flag_mm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mm"), i, csf_);
    }

    void test_method_(flag_mm_with_specified_size) {
      auto i = international_system_images::flag_mm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_na) {
      auto i = international_system_images::flag_na();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-na"), i, csf_);
    }

    void test_method_(flag_na_with_specified_size) {
      auto i = international_system_images::flag_na({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-na", size {64, 64}), i, csf_);
    }

    void test_method_(flag_nr) {
      auto i = international_system_images::flag_nr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nr"), i, csf_);
    }

    void test_method_(flag_nr_with_specified_size) {
      auto i = international_system_images::flag_nr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_np) {
      auto i = international_system_images::flag_np();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-np"), i, csf_);
    }

    void test_method_(flag_np_with_specified_size) {
      auto i = international_system_images::flag_np({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-np", size {64, 64}), i, csf_);
    }

    void test_method_(flag_nl) {
      auto i = international_system_images::flag_nl();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nl"), i, csf_);
    }

    void test_method_(flag_nl_with_specified_size) {
      auto i = international_system_images::flag_nl({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nl", size {64, 64}), i, csf_);
    }

    void test_method_(flag_nc) {
      auto i = international_system_images::flag_nc();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nc"), i, csf_);
    }

    void test_method_(flag_nc_with_specified_size) {
      auto i = international_system_images::flag_nc({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nc", size {64, 64}), i, csf_);
    }

    void test_method_(flag_nz) {
      auto i = international_system_images::flag_nz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nz"), i, csf_);
    }

    void test_method_(flag_nz_with_specified_size) {
      auto i = international_system_images::flag_nz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ni) {
      auto i = international_system_images::flag_ni();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ni"), i, csf_);
    }

    void test_method_(flag_ni_with_specified_size) {
      auto i = international_system_images::flag_ni({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ni", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ne) {
      auto i = international_system_images::flag_ne();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ne"), i, csf_);
    }

    void test_method_(flag_ne_with_specified_size) {
      auto i = international_system_images::flag_ne({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ne", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ng) {
      auto i = international_system_images::flag_ng();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ng"), i, csf_);
    }

    void test_method_(flag_ng_with_specified_size) {
      auto i = international_system_images::flag_ng({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ng", size {64, 64}), i, csf_);
    }

    void test_method_(flag_nu) {
      auto i = international_system_images::flag_nu();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nu"), i, csf_);
    }

    void test_method_(flag_nu_with_specified_size) {
      auto i = international_system_images::flag_nu({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nu", size {64, 64}), i, csf_);
    }

    void test_method_(flag_nf) {
      auto i = international_system_images::flag_nf();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nf"), i, csf_);
    }

    void test_method_(flag_nf_with_specified_size) {
      auto i = international_system_images::flag_nf({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-nf", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mk) {
      auto i = international_system_images::flag_mk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mk"), i, csf_);
    }

    void test_method_(flag_mk_with_specified_size) {
      auto i = international_system_images::flag_mk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mk", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mp) {
      auto i = international_system_images::flag_mp();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mp"), i, csf_);
    }

    void test_method_(flag_mp_with_specified_size) {
      auto i = international_system_images::flag_mp({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mp", size {64, 64}), i, csf_);
    }

    void test_method_(flag_no) {
      auto i = international_system_images::flag_no();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-no"), i, csf_);
    }

    void test_method_(flag_no_with_specified_size) {
      auto i = international_system_images::flag_no({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-no", size {64, 64}), i, csf_);
    }

    void test_method_(flag_om) {
      auto i = international_system_images::flag_om();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-om"), i, csf_);
    }

    void test_method_(flag_om_with_specified_size) {
      auto i = international_system_images::flag_om({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-om", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pk) {
      auto i = international_system_images::flag_pk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pk"), i, csf_);
    }

    void test_method_(flag_pk_with_specified_size) {
      auto i = international_system_images::flag_pk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pk", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pw) {
      auto i = international_system_images::flag_pw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pw"), i, csf_);
    }

    void test_method_(flag_pw_with_specified_size) {
      auto i = international_system_images::flag_pw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ps) {
      auto i = international_system_images::flag_ps();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ps"), i, csf_);
    }

    void test_method_(flag_ps_with_specified_size) {
      auto i = international_system_images::flag_ps({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ps", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pa) {
      auto i = international_system_images::flag_pa();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pa"), i, csf_);
    }

    void test_method_(flag_pa_with_specified_size) {
      auto i = international_system_images::flag_pa({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pa", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pg) {
      auto i = international_system_images::flag_pg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pg"), i, csf_);
    }

    void test_method_(flag_pg_with_specified_size) {
      auto i = international_system_images::flag_pg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_py) {
      auto i = international_system_images::flag_py();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-py"), i, csf_);
    }

    void test_method_(flag_py_with_specified_size) {
      auto i = international_system_images::flag_py({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-py", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pe) {
      auto i = international_system_images::flag_pe();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pe"), i, csf_);
    }

    void test_method_(flag_pe_with_specified_size) {
      auto i = international_system_images::flag_pe({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pe", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ph) {
      auto i = international_system_images::flag_ph();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ph"), i, csf_);
    }

    void test_method_(flag_ph_with_specified_size) {
      auto i = international_system_images::flag_ph({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ph", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pn) {
      auto i = international_system_images::flag_pn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pn"), i, csf_);
    }

    void test_method_(flag_pn_with_specified_size) {
      auto i = international_system_images::flag_pn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pl) {
      auto i = international_system_images::flag_pl();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pl"), i, csf_);
    }

    void test_method_(flag_pl_with_specified_size) {
      auto i = international_system_images::flag_pl({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pl", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pt) {
      auto i = international_system_images::flag_pt();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pt"), i, csf_);
    }

    void test_method_(flag_pt_with_specified_size) {
      auto i = international_system_images::flag_pt({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pt", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pr) {
      auto i = international_system_images::flag_pr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pr"), i, csf_);
    }

    void test_method_(flag_pr_with_specified_size) {
      auto i = international_system_images::flag_pr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_qa) {
      auto i = international_system_images::flag_qa();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-qa"), i, csf_);
    }

    void test_method_(flag_qa_with_specified_size) {
      auto i = international_system_images::flag_qa({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-qa", size {64, 64}), i, csf_);
    }

    void test_method_(flag_re) {
      auto i = international_system_images::flag_re();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-re"), i, csf_);
    }

    void test_method_(flag_re_with_specified_size) {
      auto i = international_system_images::flag_re({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-re", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ro) {
      auto i = international_system_images::flag_ro();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ro"), i, csf_);
    }

    void test_method_(flag_ro_with_specified_size) {
      auto i = international_system_images::flag_ro({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ro", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ru) {
      auto i = international_system_images::flag_ru();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ru"), i, csf_);
    }

    void test_method_(flag_ru_with_specified_size) {
      auto i = international_system_images::flag_ru({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ru", size {64, 64}), i, csf_);
    }

    void test_method_(flag_rw) {
      auto i = international_system_images::flag_rw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-rw"), i, csf_);
    }

    void test_method_(flag_rw_with_specified_size) {
      auto i = international_system_images::flag_rw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-rw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_bl) {
      auto i = international_system_images::flag_bl();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bl"), i, csf_);
    }

    void test_method_(flag_bl_with_specified_size) {
      auto i = international_system_images::flag_bl({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-bl", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sh) {
      auto i = international_system_images::flag_sh();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sh"), i, csf_);
    }

    void test_method_(flag_sh_with_specified_size) {
      auto i = international_system_images::flag_sh({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sh", size {64, 64}), i, csf_);
    }

    void test_method_(flag_kn) {
      auto i = international_system_images::flag_kn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kn"), i, csf_);
    }

    void test_method_(flag_kn_with_specified_size) {
      auto i = international_system_images::flag_kn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-kn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_lc) {
      auto i = international_system_images::flag_lc();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lc"), i, csf_);
    }

    void test_method_(flag_lc_with_specified_size) {
      auto i = international_system_images::flag_lc({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lc", size {64, 64}), i, csf_);
    }

    void test_method_(flag_mf) {
      auto i = international_system_images::flag_mf();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mf"), i, csf_);
    }

    void test_method_(flag_mf_with_specified_size) {
      auto i = international_system_images::flag_mf({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-mf", size {64, 64}), i, csf_);
    }

    void test_method_(flag_pm) {
      auto i = international_system_images::flag_pm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pm"), i, csf_);
    }

    void test_method_(flag_pm_with_specified_size) {
      auto i = international_system_images::flag_pm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-pm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_vc) {
      auto i = international_system_images::flag_vc();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vc"), i, csf_);
    }

    void test_method_(flag_vc_with_specified_size) {
      auto i = international_system_images::flag_vc({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vc", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ws) {
      auto i = international_system_images::flag_ws();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ws"), i, csf_);
    }

    void test_method_(flag_ws_with_specified_size) {
      auto i = international_system_images::flag_ws({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ws", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sm) {
      auto i = international_system_images::flag_sm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sm"), i, csf_);
    }

    void test_method_(flag_sm_with_specified_size) {
      auto i = international_system_images::flag_sm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_st) {
      auto i = international_system_images::flag_st();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-st"), i, csf_);
    }

    void test_method_(flag_st_with_specified_size) {
      auto i = international_system_images::flag_st({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-st", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sa) {
      auto i = international_system_images::flag_sa();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sa"), i, csf_);
    }

    void test_method_(flag_sa_with_specified_size) {
      auto i = international_system_images::flag_sa({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sa", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sn) {
      auto i = international_system_images::flag_sn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sn"), i, csf_);
    }

    void test_method_(flag_sn_with_specified_size) {
      auto i = international_system_images::flag_sn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_rs) {
      auto i = international_system_images::flag_rs();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-rs"), i, csf_);
    }

    void test_method_(flag_rs_with_specified_size) {
      auto i = international_system_images::flag_rs({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-rs", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sc) {
      auto i = international_system_images::flag_sc();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sc"), i, csf_);
    }

    void test_method_(flag_sc_with_specified_size) {
      auto i = international_system_images::flag_sc({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sc", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sl) {
      auto i = international_system_images::flag_sl();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sl"), i, csf_);
    }

    void test_method_(flag_sl_with_specified_size) {
      auto i = international_system_images::flag_sl({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sl", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sg) {
      auto i = international_system_images::flag_sg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sg"), i, csf_);
    }

    void test_method_(flag_sg_with_specified_size) {
      auto i = international_system_images::flag_sg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sx) {
      auto i = international_system_images::flag_sx();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sx"), i, csf_);
    }

    void test_method_(flag_sx_with_specified_size) {
      auto i = international_system_images::flag_sx({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sx", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sk) {
      auto i = international_system_images::flag_sk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sk"), i, csf_);
    }

    void test_method_(flag_sk_with_specified_size) {
      auto i = international_system_images::flag_sk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sk", size {64, 64}), i, csf_);
    }

    void test_method_(flag_si) {
      auto i = international_system_images::flag_si();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-si"), i, csf_);
    }

    void test_method_(flag_si_with_specified_size) {
      auto i = international_system_images::flag_si({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-si", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sb) {
      auto i = international_system_images::flag_sb();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sb"), i, csf_);
    }

    void test_method_(flag_sb_with_specified_size) {
      auto i = international_system_images::flag_sb({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sb", size {64, 64}), i, csf_);
    }

    void test_method_(flag_so) {
      auto i = international_system_images::flag_so();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-so"), i, csf_);
    }

    void test_method_(flag_so_with_specified_size) {
      auto i = international_system_images::flag_so({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-so", size {64, 64}), i, csf_);
    }

    void test_method_(flag_za) {
      auto i = international_system_images::flag_za();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-za"), i, csf_);
    }

    void test_method_(flag_za_with_specified_size) {
      auto i = international_system_images::flag_za({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-za", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gs) {
      auto i = international_system_images::flag_gs();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gs"), i, csf_);
    }

    void test_method_(flag_gs_with_specified_size) {
      auto i = international_system_images::flag_gs({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gs", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ss) {
      auto i = international_system_images::flag_ss();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ss"), i, csf_);
    }

    void test_method_(flag_ss_with_specified_size) {
      auto i = international_system_images::flag_ss({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ss", size {64, 64}), i, csf_);
    }

    void test_method_(flag_es) {
      auto i = international_system_images::flag_es();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-es"), i, csf_);
    }

    void test_method_(flag_es_with_specified_size) {
      auto i = international_system_images::flag_es({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-es", size {64, 64}), i, csf_);
    }

    void test_method_(flag_lk) {
      auto i = international_system_images::flag_lk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lk"), i, csf_);
    }

    void test_method_(flag_lk_with_specified_size) {
      auto i = international_system_images::flag_lk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-lk", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sd) {
      auto i = international_system_images::flag_sd();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sd"), i, csf_);
    }

    void test_method_(flag_sd_with_specified_size) {
      auto i = international_system_images::flag_sd({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sd", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sr) {
      auto i = international_system_images::flag_sr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sr"), i, csf_);
    }

    void test_method_(flag_sr_with_specified_size) {
      auto i = international_system_images::flag_sr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sj) {
      auto i = international_system_images::flag_sj();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sj"), i, csf_);
    }

    void test_method_(flag_sj_with_specified_size) {
      auto i = international_system_images::flag_sj({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sj", size {64, 64}), i, csf_);
    }

    void test_method_(flag_se) {
      auto i = international_system_images::flag_se();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-se"), i, csf_);
    }

    void test_method_(flag_se_with_specified_size) {
      auto i = international_system_images::flag_se({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-se", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ch) {
      auto i = international_system_images::flag_ch();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ch"), i, csf_);
    }

    void test_method_(flag_ch_with_specified_size) {
      auto i = international_system_images::flag_ch({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ch", size {64, 64}), i, csf_);
    }

    void test_method_(flag_sy) {
      auto i = international_system_images::flag_sy();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sy"), i, csf_);
    }

    void test_method_(flag_sy_with_specified_size) {
      auto i = international_system_images::flag_sy({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-sy", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tw) {
      auto i = international_system_images::flag_tw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tw"), i, csf_);
    }

    void test_method_(flag_tw_with_specified_size) {
      auto i = international_system_images::flag_tw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tw", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tj) {
      auto i = international_system_images::flag_tj();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tj"), i, csf_);
    }

    void test_method_(flag_tj_with_specified_size) {
      auto i = international_system_images::flag_tj({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tj", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tz) {
      auto i = international_system_images::flag_tz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tz"), i, csf_);
    }

    void test_method_(flag_tz_with_specified_size) {
      auto i = international_system_images::flag_tz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_th) {
      auto i = international_system_images::flag_th();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-th"), i, csf_);
    }

    void test_method_(flag_th_with_specified_size) {
      auto i = international_system_images::flag_th({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-th", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tl) {
      auto i = international_system_images::flag_tl();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tl"), i, csf_);
    }

    void test_method_(flag_tl_with_specified_size) {
      auto i = international_system_images::flag_tl({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tl", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tg) {
      auto i = international_system_images::flag_tg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tg"), i, csf_);
    }

    void test_method_(flag_tg_with_specified_size) {
      auto i = international_system_images::flag_tg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tk) {
      auto i = international_system_images::flag_tk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tk"), i, csf_);
    }

    void test_method_(flag_tk_with_specified_size) {
      auto i = international_system_images::flag_tk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tk", size {64, 64}), i, csf_);
    }

    void test_method_(flag_to) {
      auto i = international_system_images::flag_to();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-to"), i, csf_);
    }

    void test_method_(flag_to_with_specified_size) {
      auto i = international_system_images::flag_to({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-to", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tt) {
      auto i = international_system_images::flag_tt();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tt"), i, csf_);
    }

    void test_method_(flag_tt_with_specified_size) {
      auto i = international_system_images::flag_tt({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tt", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tn) {
      auto i = international_system_images::flag_tn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tn"), i, csf_);
    }

    void test_method_(flag_tn_with_specified_size) {
      auto i = international_system_images::flag_tn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tr) {
      auto i = international_system_images::flag_tr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tr"), i, csf_);
    }

    void test_method_(flag_tr_with_specified_size) {
      auto i = international_system_images::flag_tr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tr", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tm) {
      auto i = international_system_images::flag_tm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tm"), i, csf_);
    }

    void test_method_(flag_tm_with_specified_size) {
      auto i = international_system_images::flag_tm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tc) {
      auto i = international_system_images::flag_tc();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tc"), i, csf_);
    }

    void test_method_(flag_tc_with_specified_size) {
      auto i = international_system_images::flag_tc({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tc", size {64, 64}), i, csf_);
    }

    void test_method_(flag_tv) {
      auto i = international_system_images::flag_tv();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tv"), i, csf_);
    }

    void test_method_(flag_tv_with_specified_size) {
      auto i = international_system_images::flag_tv({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-tv", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ug) {
      auto i = international_system_images::flag_ug();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ug"), i, csf_);
    }

    void test_method_(flag_ug_with_specified_size) {
      auto i = international_system_images::flag_ug({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ug", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ua) {
      auto i = international_system_images::flag_ua();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ua"), i, csf_);
    }

    void test_method_(flag_ua_with_specified_size) {
      auto i = international_system_images::flag_ua({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ua", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ae) {
      auto i = international_system_images::flag_ae();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ae"), i, csf_);
    }

    void test_method_(flag_ae_with_specified_size) {
      auto i = international_system_images::flag_ae({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ae", size {64, 64}), i, csf_);
    }

    void test_method_(flag_gb) {
      auto i = international_system_images::flag_gb();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gb"), i, csf_);
    }

    void test_method_(flag_gb_with_specified_size) {
      auto i = international_system_images::flag_gb({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-gb", size {64, 64}), i, csf_);
    }

    void test_method_(flag_us) {
      auto i = international_system_images::flag_us();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-us"), i, csf_);
    }

    void test_method_(flag_us_with_specified_size) {
      auto i = international_system_images::flag_us({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-us", size {64, 64}), i, csf_);
    }

    void test_method_(flag_um) {
      auto i = international_system_images::flag_um();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-um"), i, csf_);
    }

    void test_method_(flag_um_with_specified_size) {
      auto i = international_system_images::flag_um({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-um", size {64, 64}), i, csf_);
    }

    void test_method_(flag_uy) {
      auto i = international_system_images::flag_uy();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-uy"), i, csf_);
    }

    void test_method_(flag_uy_with_specified_size) {
      auto i = international_system_images::flag_uy({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-uy", size {64, 64}), i, csf_);
    }

    void test_method_(flag_uz) {
      auto i = international_system_images::flag_uz();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-uz"), i, csf_);
    }

    void test_method_(flag_uz_with_specified_size) {
      auto i = international_system_images::flag_uz({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-uz", size {64, 64}), i, csf_);
    }

    void test_method_(flag_vu) {
      auto i = international_system_images::flag_vu();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vu"), i, csf_);
    }

    void test_method_(flag_vu_with_specified_size) {
      auto i = international_system_images::flag_vu({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vu", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ve) {
      auto i = international_system_images::flag_ve();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ve"), i, csf_);
    }

    void test_method_(flag_ve_with_specified_size) {
      auto i = international_system_images::flag_ve({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ve", size {64, 64}), i, csf_);
    }

    void test_method_(flag_vn) {
      auto i = international_system_images::flag_vn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vn"), i, csf_);
    }

    void test_method_(flag_vn_with_specified_size) {
      auto i = international_system_images::flag_vn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vn", size {64, 64}), i, csf_);
    }

    void test_method_(flag_vg) {
      auto i = international_system_images::flag_vg();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vg"), i, csf_);
    }

    void test_method_(flag_vg_with_specified_size) {
      auto i = international_system_images::flag_vg({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vg", size {64, 64}), i, csf_);
    }

    void test_method_(flag_vi) {
      auto i = international_system_images::flag_vi();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vi"), i, csf_);
    }

    void test_method_(flag_vi_with_specified_size) {
      auto i = international_system_images::flag_vi({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-vi", size {64, 64}), i, csf_);
    }

    void test_method_(flag_wf) {
      auto i = international_system_images::flag_wf();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-wf"), i, csf_);
    }

    void test_method_(flag_wf_with_specified_size) {
      auto i = international_system_images::flag_wf({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-wf", size {64, 64}), i, csf_);
    }

    void test_method_(flag_eh) {
      auto i = international_system_images::flag_eh();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-eh"), i, csf_);
    }

    void test_method_(flag_eh_with_specified_size) {
      auto i = international_system_images::flag_eh({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-eh", size {64, 64}), i, csf_);
    }

    void test_method_(flag_ye) {
      auto i = international_system_images::flag_ye();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ye"), i, csf_);
    }

    void test_method_(flag_ye_with_specified_size) {
      auto i = international_system_images::flag_ye({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-ye", size {64, 64}), i, csf_);
    }

    void test_method_(flag_zm) {
      auto i = international_system_images::flag_zm();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-zm"), i, csf_);
    }

    void test_method_(flag_zm_with_specified_size) {
      auto i = international_system_images::flag_zm({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-zm", size {64, 64}), i, csf_);
    }

    void test_method_(flag_zw) {
      auto i = international_system_images::flag_zw();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-zw"), i, csf_);
    }

    void test_method_(flag_zw_with_specified_size) {
      auto i = international_system_images::flag_zw({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("flag-zw", size {64, 64}), i, csf_);
    }
  };
}
