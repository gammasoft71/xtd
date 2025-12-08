#include <xtd/globalization/culture_info>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::globalization;
using namespace xtd::tunit;

namespace xtd::globalization::tests {
  class test_class_(culture_info_cultures_tests) {
    auto test_method_(invariant) {
      auto culture = culture_info {""};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Invariant Language (Invariant Country)", culture.display_name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.english_name());
      assert::are_equal(127_z, culture.keyboard_layout_id());
      assert::are_equal(127_z, culture.lcid());
      assert::are_equal("", culture.name());
      assert::are_equal("Invariant Language (Invariant Country)", culture.native_name());
    }
    
    auto test_method_(af) {
      auto culture = culture_info {"af"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Afrikaans", culture.display_name());
      assert::are_equal("Afrikaans", culture.english_name());
      assert::are_equal(54_z, culture.keyboard_layout_id());
      assert::are_equal(54_z, culture.lcid());
      assert::are_equal("af", culture.name());
      assert::are_equal("Afrikaans", culture.native_name());
    }
    
    auto test_method_(af_NA) {
      auto culture = culture_info {"af-NA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Afrikaans (Namibia)", culture.display_name());
      assert::are_equal("Afrikaans (Namibia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("af-NA", culture.name());
      assert::are_equal("Afrikaans (Namibië)", culture.native_name());
    }
    
    auto test_method_(af_ZA) {
      auto culture = culture_info {"af-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Afrikaans (South Africa)", culture.display_name());
      assert::are_equal("Afrikaans (South Africa)", culture.english_name());
      assert::are_equal(1078_z, culture.keyboard_layout_id());
      assert::are_equal(1078_z, culture.lcid());
      assert::are_equal("af-ZA", culture.name());
      assert::are_equal("Afrikaans (Suid-Afrika)", culture.native_name());
    }
    
    auto test_method_(agq) {
      auto culture = culture_info {"agq"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Aghem", culture.display_name());
      assert::are_equal("Aghem", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("agq", culture.name());
      assert::are_equal("Aghem", culture.native_name());
    }
    
    auto test_method_(agq_CM) {
      auto culture = culture_info {"agq-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Aghem (Cameroon)", culture.display_name());
      assert::are_equal("Aghem (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("agq-CM", culture.name());
      assert::are_equal("Aghem (Kàmàlûŋ)", culture.native_name());
    }
    
    auto test_method_(ain) {
      auto culture = culture_info {"ain"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ainu", culture.display_name());
      assert::are_equal("Ainu", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ain", culture.name());
      assert::are_equal("アイヌ・イタㇰ", culture.native_name());
    }
    
    auto test_method_(ain_JP) {
      auto culture = culture_info {"ain-JP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ainu (Japan)", culture.display_name());
      assert::are_equal("Ainu (Japan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ain-JP", culture.name());
      assert::are_equal("Ainu (Japan)", culture.native_name());
    }
    
    auto test_method_(ak) {
      auto culture = culture_info {"ak"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Akan", culture.display_name());
      assert::are_equal("Akan", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ak", culture.name());
      assert::are_equal("Akan", culture.native_name());
    }
    
    auto test_method_(ak_GH) {
      auto culture = culture_info {"ak-GH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Akan (Ghana)", culture.display_name());
      assert::are_equal("Akan (Ghana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ak-GH", culture.name());
      assert::are_equal("Akan (Gaana)", culture.native_name());
    }
    
    auto test_method_(am) {
      auto culture = culture_info {"am"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Amharic", culture.display_name());
      assert::are_equal("Amharic", culture.english_name());
      assert::are_equal(94_z, culture.keyboard_layout_id());
      assert::are_equal(94_z, culture.lcid());
      assert::are_equal("am", culture.name());
      assert::are_equal("አማርኛ", culture.native_name());
    }
    
    auto test_method_(am_ET) {
      auto culture = culture_info {"am-ET"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Amharic (Ethiopia)", culture.display_name());
      assert::are_equal("Amharic (Ethiopia)", culture.english_name());
      assert::are_equal(1118_z, culture.keyboard_layout_id());
      assert::are_equal(1118_z, culture.lcid());
      assert::are_equal("am-ET", culture.name());
      assert::are_equal("አማርኛ (ኢትዮጵያ)", culture.native_name());
    }
    
    auto test_method_(apw) {
      auto culture = culture_info {"apw"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Apache, Western", culture.display_name());
      assert::are_equal("Apache, Western", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("apw", culture.name());
      assert::are_equal("Nṉee biyátiʼ", culture.native_name());
    }
    
    auto test_method_(apw_US) {
      auto culture = culture_info {"apw-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Apache, Western (United States)", culture.display_name());
      assert::are_equal("Apache, Western (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("apw-US", culture.name());
      assert::are_equal("Apache, Western (United States)", culture.native_name());
    }
    
    auto test_method_(ar) {
      auto culture = culture_info {"ar"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Arabic", culture.display_name());
      assert::are_equal("Arabic", culture.english_name());
      assert::are_equal(1_z, culture.keyboard_layout_id());
      assert::are_equal(1_z, culture.lcid());
      assert::are_equal("ar", culture.name());
      assert::are_equal("العربية", culture.native_name());
    }
    
    auto test_method_(ar_001) {
      auto culture = culture_info {"ar-001"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (world)", culture.display_name());
      assert::are_equal("Arabic (world)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-001", culture.name());
      assert::are_equal("العربية (العالم)", culture.native_name());
    }
    
    auto test_method_(ar_AE) {
      auto culture = culture_info {"ar-AE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (United Arab Emirates)", culture.display_name());
      assert::are_equal("Arabic (United Arab Emirates)", culture.english_name());
      assert::are_equal(14337_z, culture.keyboard_layout_id());
      assert::are_equal(14337_z, culture.lcid());
      assert::are_equal("ar-AE", culture.name());
      assert::are_equal("العربية (الإمارات العربية المتحدة)", culture.native_name());
    }
    
    auto test_method_(ar_BH) {
      auto culture = culture_info {"ar-BH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Bahrain)", culture.display_name());
      assert::are_equal("Arabic (Bahrain)", culture.english_name());
      assert::are_equal(15361_z, culture.keyboard_layout_id());
      assert::are_equal(15361_z, culture.lcid());
      assert::are_equal("ar-BH", culture.name());
      assert::are_equal("العربية (البحرين)", culture.native_name());
    }
    
    auto test_method_(ar_DJ) {
      auto culture = culture_info {"ar-DJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Djibouti)", culture.display_name());
      assert::are_equal("Arabic (Djibouti)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-DJ", culture.name());
      assert::are_equal("العربية (جيبوتي)", culture.native_name());
    }
    
    auto test_method_(ar_DZ) {
      auto culture = culture_info {"ar-DZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Algeria)", culture.display_name());
      assert::are_equal("Arabic (Algeria)", culture.english_name());
      assert::are_equal(5121_z, culture.keyboard_layout_id());
      assert::are_equal(5121_z, culture.lcid());
      assert::are_equal("ar-DZ", culture.name());
      assert::are_equal("العربية (الجزائر)", culture.native_name());
    }
    
    auto test_method_(ar_EG) {
      auto culture = culture_info {"ar-EG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Egypt)", culture.display_name());
      assert::are_equal("Arabic (Egypt)", culture.english_name());
      assert::are_equal(3073_z, culture.keyboard_layout_id());
      assert::are_equal(3073_z, culture.lcid());
      assert::are_equal("ar-EG", culture.name());
      assert::are_equal("العربية (مصر)", culture.native_name());
    }
    
    auto test_method_(ar_EH) {
      auto culture = culture_info {"ar-EH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Western Sahara)", culture.display_name());
      assert::are_equal("Arabic (Western Sahara)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-EH", culture.name());
      assert::are_equal("العربية (الصحراء الغربية)", culture.native_name());
    }
    
    auto test_method_(ar_ER) {
      auto culture = culture_info {"ar-ER"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Eritrea)", culture.display_name());
      assert::are_equal("Arabic (Eritrea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-ER", culture.name());
      assert::are_equal("العربية (إريتريا)", culture.native_name());
    }
    
    auto test_method_(ar_IL) {
      auto culture = culture_info {"ar-IL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Israel)", culture.display_name());
      assert::are_equal("Arabic (Israel)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-IL", culture.name());
      assert::are_equal("العربية (إسرائيل)", culture.native_name());
    }
    
    auto test_method_(ar_IQ) {
      auto culture = culture_info {"ar-IQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Iraq)", culture.display_name());
      assert::are_equal("Arabic (Iraq)", culture.english_name());
      assert::are_equal(2049_z, culture.keyboard_layout_id());
      assert::are_equal(2049_z, culture.lcid());
      assert::are_equal("ar-IQ", culture.name());
      assert::are_equal("العربية (العراق)", culture.native_name());
    }
    
    auto test_method_(ar_JO) {
      auto culture = culture_info {"ar-JO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Jordan)", culture.display_name());
      assert::are_equal("Arabic (Jordan)", culture.english_name());
      assert::are_equal(11265_z, culture.keyboard_layout_id());
      assert::are_equal(11265_z, culture.lcid());
      assert::are_equal("ar-JO", culture.name());
      assert::are_equal("العربية (الأردن)", culture.native_name());
    }
    
    auto test_method_(ar_KM) {
      auto culture = culture_info {"ar-KM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Comoros)", culture.display_name());
      assert::are_equal("Arabic (Comoros)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-KM", culture.name());
      assert::are_equal("العربية (جزر القمر)", culture.native_name());
    }
    
    auto test_method_(ar_KW) {
      auto culture = culture_info {"ar-KW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Kuwait)", culture.display_name());
      assert::are_equal("Arabic (Kuwait)", culture.english_name());
      assert::are_equal(13313_z, culture.keyboard_layout_id());
      assert::are_equal(13313_z, culture.lcid());
      assert::are_equal("ar-KW", culture.name());
      assert::are_equal("العربية (الكويت)", culture.native_name());
    }
    
    auto test_method_(ar_LB) {
      auto culture = culture_info {"ar-LB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Lebanon)", culture.display_name());
      assert::are_equal("Arabic (Lebanon)", culture.english_name());
      assert::are_equal(12289_z, culture.keyboard_layout_id());
      assert::are_equal(12289_z, culture.lcid());
      assert::are_equal("ar-LB", culture.name());
      assert::are_equal("العربية (لبنان)", culture.native_name());
    }
    
    auto test_method_(ar_LY) {
      auto culture = culture_info {"ar-LY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Libya)", culture.display_name());
      assert::are_equal("Arabic (Libya)", culture.english_name());
      assert::are_equal(4097_z, culture.keyboard_layout_id());
      assert::are_equal(4097_z, culture.lcid());
      assert::are_equal("ar-LY", culture.name());
      assert::are_equal("العربية (ليبيا)", culture.native_name());
    }
    
    auto test_method_(ar_MA) {
      auto culture = culture_info {"ar-MA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Morocco)", culture.display_name());
      assert::are_equal("Arabic (Morocco)", culture.english_name());
      assert::are_equal(6145_z, culture.keyboard_layout_id());
      assert::are_equal(6145_z, culture.lcid());
      assert::are_equal("ar-MA", culture.name());
      assert::are_equal("العربية (المغرب)", culture.native_name());
    }
    
    auto test_method_(ar_MR) {
      auto culture = culture_info {"ar-MR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Mauritania)", culture.display_name());
      assert::are_equal("Arabic (Mauritania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-MR", culture.name());
      assert::are_equal("العربية (موريتانيا)", culture.native_name());
    }
    
    auto test_method_(ar_OM) {
      auto culture = culture_info {"ar-OM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Oman)", culture.display_name());
      assert::are_equal("Arabic (Oman)", culture.english_name());
      assert::are_equal(8193_z, culture.keyboard_layout_id());
      assert::are_equal(8193_z, culture.lcid());
      assert::are_equal("ar-OM", culture.name());
      assert::are_equal("العربية (عُمان)", culture.native_name());
    }
    
    auto test_method_(ar_PS) {
      auto culture = culture_info {"ar-PS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Palestinian Territories)", culture.display_name());
      assert::are_equal("Arabic (Palestinian Territories)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-PS", culture.name());
      assert::are_equal("العربية (الأراضي الفلسطينية)", culture.native_name());
    }
    
    auto test_method_(ar_QA) {
      auto culture = culture_info {"ar-QA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Qatar)", culture.display_name());
      assert::are_equal("Arabic (Qatar)", culture.english_name());
      assert::are_equal(16385_z, culture.keyboard_layout_id());
      assert::are_equal(16385_z, culture.lcid());
      assert::are_equal("ar-QA", culture.name());
      assert::are_equal("العربية (قطر)", culture.native_name());
    }
    
    auto test_method_(ar_SA) {
      auto culture = culture_info {"ar-SA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Saudi Arabia)", culture.display_name());
      assert::are_equal("Arabic (Saudi Arabia)", culture.english_name());
      assert::are_equal(1025_z, culture.keyboard_layout_id());
      assert::are_equal(1025_z, culture.lcid());
      assert::are_equal("ar-SA", culture.name());
      assert::are_equal("العربية (المملكة العربية السعودية)", culture.native_name());
    }
    
    auto test_method_(ar_SD) {
      auto culture = culture_info {"ar-SD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Sudan)", culture.display_name());
      assert::are_equal("Arabic (Sudan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-SD", culture.name());
      assert::are_equal("العربية (السودان)", culture.native_name());
    }
    
    auto test_method_(ar_SO) {
      auto culture = culture_info {"ar-SO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Somalia)", culture.display_name());
      assert::are_equal("Arabic (Somalia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-SO", culture.name());
      assert::are_equal("العربية (الصومال)", culture.native_name());
    }
    
    auto test_method_(ar_SS) {
      auto culture = culture_info {"ar-SS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (South Sudan)", culture.display_name());
      assert::are_equal("Arabic (South Sudan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-SS", culture.name());
      assert::are_equal("العربية (جنوب السودان)", culture.native_name());
    }
    
    auto test_method_(ar_SY) {
      auto culture = culture_info {"ar-SY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Syria)", culture.display_name());
      assert::are_equal("Arabic (Syria)", culture.english_name());
      assert::are_equal(10241_z, culture.keyboard_layout_id());
      assert::are_equal(10241_z, culture.lcid());
      assert::are_equal("ar-SY", culture.name());
      assert::are_equal("العربية (سوريا)", culture.native_name());
    }
    
    auto test_method_(ar_TD) {
      auto culture = culture_info {"ar-TD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Chad)", culture.display_name());
      assert::are_equal("Arabic (Chad)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ar-TD", culture.name());
      assert::are_equal("العربية (تشاد)", culture.native_name());
    }
    
    auto test_method_(ar_TN) {
      auto culture = culture_info {"ar-TN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Tunisia)", culture.display_name());
      assert::are_equal("Arabic (Tunisia)", culture.english_name());
      assert::are_equal(7169_z, culture.keyboard_layout_id());
      assert::are_equal(7169_z, culture.lcid());
      assert::are_equal("ar-TN", culture.name());
      assert::are_equal("العربية (تونس)", culture.native_name());
    }
    
    auto test_method_(ar_YE) {
      auto culture = culture_info {"ar-YE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Arabic (Yemen)", culture.display_name());
      assert::are_equal("Arabic (Yemen)", culture.english_name());
      assert::are_equal(9217_z, culture.keyboard_layout_id());
      assert::are_equal(9217_z, culture.lcid());
      assert::are_equal("ar-YE", culture.name());
      assert::are_equal("العربية (اليمن)", culture.native_name());
    }
    
    auto test_method_(arn) {
      auto culture = culture_info {"arn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Mapuche", culture.display_name());
      assert::are_equal("Mapuche", culture.english_name());
      assert::are_equal(122_z, culture.keyboard_layout_id());
      assert::are_equal(122_z, culture.lcid());
      assert::are_equal("arn", culture.name());
      assert::are_equal("Mapudungun", culture.native_name());
    }
    
    auto test_method_(arn_CL) {
      auto culture = culture_info {"arn-CL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Mapuche (Chile)", culture.display_name());
      assert::are_equal("Mapuche (Chile)", culture.english_name());
      assert::are_equal(1146_z, culture.keyboard_layout_id());
      assert::are_equal(1146_z, culture.lcid());
      assert::are_equal("arn-CL", culture.name());
      assert::are_equal("Mapuche (Chile)", culture.native_name());
    }
    
    auto test_method_(as) {
      auto culture = culture_info {"as"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Assamese", culture.display_name());
      assert::are_equal("Assamese", culture.english_name());
      assert::are_equal(77_z, culture.keyboard_layout_id());
      assert::are_equal(77_z, culture.lcid());
      assert::are_equal("as", culture.name());
      assert::are_equal("অসমীয়া", culture.native_name());
    }
    
    auto test_method_(as_IN) {
      auto culture = culture_info {"as-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Assamese (India)", culture.display_name());
      assert::are_equal("Assamese (India)", culture.english_name());
      assert::are_equal(1101_z, culture.keyboard_layout_id());
      assert::are_equal(1101_z, culture.lcid());
      assert::are_equal("as-IN", culture.name());
      assert::are_equal("অসমীয়া (ভাৰত)", culture.native_name());
    }
    
    auto test_method_(asa) {
      auto culture = culture_info {"asa"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Asu", culture.display_name());
      assert::are_equal("Asu", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("asa", culture.name());
      assert::are_equal("Kipare", culture.native_name());
    }
    
    auto test_method_(asa_TZ) {
      auto culture = culture_info {"asa-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Asu (Tanzania)", culture.display_name());
      assert::are_equal("Asu (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("asa-TZ", culture.name());
      assert::are_equal("Kipare (Tadhania)", culture.native_name());
    }
    
    auto test_method_(ast) {
      auto culture = culture_info {"ast"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Asturian", culture.display_name());
      assert::are_equal("Asturian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ast", culture.name());
      assert::are_equal("asturianu", culture.native_name());
    }
    
    auto test_method_(ast_ES) {
      auto culture = culture_info {"ast-ES"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Asturian (Spain)", culture.display_name());
      assert::are_equal("Asturian (Spain)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ast-ES", culture.name());
      assert::are_equal("asturianu (España)", culture.native_name());
    }
    
    auto test_method_(az) {
      auto culture = culture_info {"az"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Azerbaijani", culture.display_name());
      assert::are_equal("Azerbaijani", culture.english_name());
      assert::are_equal(44_z, culture.keyboard_layout_id());
      assert::are_equal(44_z, culture.lcid());
      assert::are_equal("az", culture.name());
      assert::are_equal("azərbaycan", culture.native_name());
    }
    
    auto test_method_(az_Cyrl) {
      auto culture = culture_info {"az-Cyrl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Azerbaijani (Cyrillic)", culture.display_name());
      assert::are_equal("Azerbaijani (Cyrillic)", culture.english_name());
      assert::are_equal(29740_z, culture.keyboard_layout_id());
      assert::are_equal(29740_z, culture.lcid());
      assert::are_equal("az-Cyrl", culture.name());
      assert::are_equal("азәрбајҹан (Кирил)", culture.native_name());
    }
    
    auto test_method_(az_Cyrl_AZ) {
      auto culture = culture_info {"az-Cyrl-AZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Azerbaijani (Cyrillic, Azerbaijan)", culture.display_name());
      assert::are_equal("Azerbaijani (Cyrillic, Azerbaijan)", culture.english_name());
      assert::are_equal(2092_z, culture.keyboard_layout_id());
      assert::are_equal(2092_z, culture.lcid());
      assert::are_equal("az-Cyrl-AZ", culture.name());
      assert::are_equal("азәрбајҹан (Кирил, Азәрбајҹан)", culture.native_name());
    }
    
    auto test_method_(az_Latn) {
      auto culture = culture_info {"az-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Azerbaijani (Latin)", culture.display_name());
      assert::are_equal("Azerbaijani (Latin)", culture.english_name());
      assert::are_equal(30764_z, culture.keyboard_layout_id());
      assert::are_equal(30764_z, culture.lcid());
      assert::are_equal("az-Latn", culture.name());
      assert::are_equal("azərbaycan (latın)", culture.native_name());
    }
    
    auto test_method_(az_Latn_AZ) {
      auto culture = culture_info {"az-Latn-AZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Azerbaijani (Latin, Azerbaijan)", culture.display_name());
      assert::are_equal("Azerbaijani (Latin, Azerbaijan)", culture.english_name());
      assert::are_equal(1068_z, culture.keyboard_layout_id());
      assert::are_equal(1068_z, culture.lcid());
      assert::are_equal("az-Latn-AZ", culture.name());
      assert::are_equal("azərbaycan (latın, Azərbaycan)", culture.native_name());
    }
    
    auto test_method_(ba) {
      auto culture = culture_info {"ba"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bashkir", culture.display_name());
      assert::are_equal("Bashkir", culture.english_name());
      assert::are_equal(109_z, culture.keyboard_layout_id());
      assert::are_equal(109_z, culture.lcid());
      assert::are_equal("ba", culture.name());
      assert::are_equal("башҡорт теле", culture.native_name());
    }
    
    auto test_method_(ba_RU) {
      auto culture = culture_info {"ba-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bashkir (Russia)", culture.display_name());
      assert::are_equal("Bashkir (Russia)", culture.english_name());
      assert::are_equal(1133_z, culture.keyboard_layout_id());
      assert::are_equal(1133_z, culture.lcid());
      assert::are_equal("ba-RU", culture.name());
      assert::are_equal("Bashkir (Russia)", culture.native_name());
    }
    
    auto test_method_(bas) {
      auto culture = culture_info {"bas"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Basaa", culture.display_name());
      assert::are_equal("Basaa", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bas", culture.name());
      assert::are_equal("Ɓàsàa", culture.native_name());
    }
    
    auto test_method_(bas_CM) {
      auto culture = culture_info {"bas-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Basaa (Cameroon)", culture.display_name());
      assert::are_equal("Basaa (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bas-CM", culture.name());
      assert::are_equal("Ɓàsàa (Kàmɛ̀rûn)", culture.native_name());
    }
    
    auto test_method_(be) {
      auto culture = culture_info {"be"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Belarusian", culture.display_name());
      assert::are_equal("Belarusian", culture.english_name());
      assert::are_equal(35_z, culture.keyboard_layout_id());
      assert::are_equal(35_z, culture.lcid());
      assert::are_equal("be", culture.name());
      assert::are_equal("беларуская", culture.native_name());
    }
    
    auto test_method_(be_BY) {
      auto culture = culture_info {"be-BY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Belarusian (Belarus)", culture.display_name());
      assert::are_equal("Belarusian (Belarus)", culture.english_name());
      assert::are_equal(1059_z, culture.keyboard_layout_id());
      assert::are_equal(1059_z, culture.lcid());
      assert::are_equal("be-BY", culture.name());
      assert::are_equal("беларуская (Беларусь)", culture.native_name());
    }
    
    auto test_method_(bem) {
      auto culture = culture_info {"bem"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bemba", culture.display_name());
      assert::are_equal("Bemba", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bem", culture.name());
      assert::are_equal("Ichibemba", culture.native_name());
    }
    
    auto test_method_(bem_ZM) {
      auto culture = culture_info {"bem-ZM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bemba (Zambia)", culture.display_name());
      assert::are_equal("Bemba (Zambia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bem-ZM", culture.name());
      assert::are_equal("Ichibemba (Zambia)", culture.native_name());
    }
    
    auto test_method_(ber) {
      auto culture = culture_info {"ber"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Amazigh", culture.display_name());
      assert::are_equal("Amazigh", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ber", culture.name());
      assert::are_equal("ⴰⵎⴰⵣⵉⵖ", culture.native_name());
    }
    
    auto test_method_(ber_Latn) {
      auto culture = culture_info {"ber-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Amazigh (Latin)", culture.display_name());
      assert::are_equal("Amazigh (Latin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ber-Latn", culture.name());
      assert::are_equal("Amaziɣ (Latin)", culture.native_name());
    }
    
    auto test_method_(ber_Latn_MA) {
      auto culture = culture_info {"ber-Latn-MA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Amazigh (Latin, Morocco)", culture.display_name());
      assert::are_equal("Amazigh (Latin, Morocco)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ber-Latn-MA", culture.name());
      assert::are_equal("Amaziɣ (Latin, Lmɣrib)", culture.native_name());
    }
    
    auto test_method_(ber_Tfng) {
      auto culture = culture_info {"ber-Tfng"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Amazigh (Tifinagh)", culture.display_name());
      assert::are_equal("Amazigh (Tifinagh)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ber-Tfng", culture.name());
      assert::are_equal("ⴰⵎⴰⵣⵉⵖ (ⵜⴼⵏⵗ)", culture.native_name());
    }
    
    auto test_method_(ber_Tfng_MA) {
      auto culture = culture_info {"ber-Tfng-MA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Amazigh (Tifinagh, Morocco)", culture.display_name());
      assert::are_equal("Amazigh (Tifinagh, Morocco)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ber-Tfng-MA", culture.name());
      assert::are_equal("Amazigh (Tifinagh, Morocco)", culture.native_name());
    }
    
    auto test_method_(bez) {
      auto culture = culture_info {"bez"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bena", culture.display_name());
      assert::are_equal("Bena", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bez", culture.name());
      assert::are_equal("Hibena", culture.native_name());
    }
    
    auto test_method_(bez_TZ) {
      auto culture = culture_info {"bez-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bena (Tanzania)", culture.display_name());
      assert::are_equal("Bena (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bez-TZ", culture.name());
      assert::are_equal("Hibena (Hutanzania)", culture.native_name());
    }
    
    auto test_method_(bg) {
      auto culture = culture_info {"bg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bulgarian", culture.display_name());
      assert::are_equal("Bulgarian", culture.english_name());
      assert::are_equal(2_z, culture.keyboard_layout_id());
      assert::are_equal(2_z, culture.lcid());
      assert::are_equal("bg", culture.name());
      assert::are_equal("български", culture.native_name());
    }
    
    auto test_method_(bg_BG) {
      auto culture = culture_info {"bg-BG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bulgarian (Bulgaria)", culture.display_name());
      assert::are_equal("Bulgarian (Bulgaria)", culture.english_name());
      assert::are_equal(1026_z, culture.keyboard_layout_id());
      assert::are_equal(1026_z, culture.lcid());
      assert::are_equal("bg-BG", culture.name());
      assert::are_equal("български (България)", culture.native_name());
    }
    
    auto test_method_(bgc) {
      auto culture = culture_info {"bgc"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Haryanvi", culture.display_name());
      assert::are_equal("Haryanvi", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bgc", culture.name());
      assert::are_equal("हरियाणवी", culture.native_name());
    }
    
    auto test_method_(bgc_IN) {
      auto culture = culture_info {"bgc-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Haryanvi (India)", culture.display_name());
      assert::are_equal("Haryanvi (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bgc-IN", culture.name());
      assert::are_equal("हरियाणवी (भारत)", culture.native_name());
    }
    
    auto test_method_(bho) {
      auto culture = culture_info {"bho"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bhojpuri", culture.display_name());
      assert::are_equal("Bhojpuri", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bho", culture.name());
      assert::are_equal("भोजपुरी", culture.native_name());
    }
    
    auto test_method_(bho_IN) {
      auto culture = culture_info {"bho-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bhojpuri (India)", culture.display_name());
      assert::are_equal("Bhojpuri (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bho-IN", culture.name());
      assert::are_equal("भोजपुरी (भारत)", culture.native_name());
    }
    
    auto test_method_(blo) {
      auto culture = culture_info {"blo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Anii", culture.display_name());
      assert::are_equal("Anii", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("blo", culture.name());
      assert::are_equal("anii kagɩja", culture.native_name());
    }
    
    auto test_method_(blo_BJ) {
      auto culture = culture_info {"blo-BJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Anii (Benin)", culture.display_name());
      assert::are_equal("Anii (Benin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("blo-BJ", culture.name());
      assert::are_equal("anii kagɩja (Benɛɛ)", culture.native_name());
    }
    
    auto test_method_(bm) {
      auto culture = culture_info {"bm"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bambara", culture.display_name());
      assert::are_equal("Bambara", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bm", culture.name());
      assert::are_equal("bamanakan", culture.native_name());
    }
    
    auto test_method_(bm_ML) {
      auto culture = culture_info {"bm-ML"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bambara (Mali)", culture.display_name());
      assert::are_equal("Bambara (Mali)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bm-ML", culture.name());
      assert::are_equal("bamanakan (Mali)", culture.native_name());
    }
    
    auto test_method_(bn) {
      auto culture = culture_info {"bn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bangla", culture.display_name());
      assert::are_equal("Bangla", culture.english_name());
      assert::are_equal(69_z, culture.keyboard_layout_id());
      assert::are_equal(69_z, culture.lcid());
      assert::are_equal("bn", culture.name());
      assert::are_equal("বাংলা", culture.native_name());
    }
    
    auto test_method_(bn_BD) {
      auto culture = culture_info {"bn-BD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bangla (Bangladesh)", culture.display_name());
      assert::are_equal("Bangla (Bangladesh)", culture.english_name());
      assert::are_equal(2117_z, culture.keyboard_layout_id());
      assert::are_equal(2117_z, culture.lcid());
      assert::are_equal("bn-BD", culture.name());
      assert::are_equal("বাংলা (বাংলাদেশ)", culture.native_name());
    }
    
    auto test_method_(bn_IN) {
      auto culture = culture_info {"bn-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bangla (India)", culture.display_name());
      assert::are_equal("Bangla (India)", culture.english_name());
      assert::are_equal(1093_z, culture.keyboard_layout_id());
      assert::are_equal(1093_z, culture.lcid());
      assert::are_equal("bn-IN", culture.name());
      assert::are_equal("বাংলা (ভারত)", culture.native_name());
    }
    
    auto test_method_(bo) {
      auto culture = culture_info {"bo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tibetan", culture.display_name());
      assert::are_equal("Tibetan", culture.english_name());
      assert::are_equal(81_z, culture.keyboard_layout_id());
      assert::are_equal(81_z, culture.lcid());
      assert::are_equal("bo", culture.name());
      assert::are_equal("བོད་སྐད་", culture.native_name());
    }
    
    auto test_method_(bo_CN) {
      auto culture = culture_info {"bo-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tibetan (China mainland)", culture.display_name());
      assert::are_equal("Tibetan (China mainland)", culture.english_name());
      assert::are_equal(1105_z, culture.keyboard_layout_id());
      assert::are_equal(1105_z, culture.lcid());
      assert::are_equal("bo-CN", culture.name());
      assert::are_equal("བོད་སྐད་ (རྒྱ་ནག)", culture.native_name());
    }
    
    auto test_method_(bo_IN) {
      auto culture = culture_info {"bo-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tibetan (India)", culture.display_name());
      assert::are_equal("Tibetan (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("bo-IN", culture.name());
      assert::are_equal("བོད་སྐད་ (རྒྱ་གར་)", culture.native_name());
    }
    
    auto test_method_(br) {
      auto culture = culture_info {"br"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Breton", culture.display_name());
      assert::are_equal("Breton", culture.english_name());
      assert::are_equal(126_z, culture.keyboard_layout_id());
      assert::are_equal(126_z, culture.lcid());
      assert::are_equal("br", culture.name());
      assert::are_equal("brezhoneg", culture.native_name());
    }
    
    auto test_method_(br_FR) {
      auto culture = culture_info {"br-FR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Breton (France)", culture.display_name());
      assert::are_equal("Breton (France)", culture.english_name());
      assert::are_equal(1150_z, culture.keyboard_layout_id());
      assert::are_equal(1150_z, culture.lcid());
      assert::are_equal("br-FR", culture.name());
      assert::are_equal("brezhoneg (Frañs)", culture.native_name());
    }
    
    auto test_method_(brx) {
      auto culture = culture_info {"brx"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bodo", culture.display_name());
      assert::are_equal("Bodo", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("brx", culture.name());
      assert::are_equal("बरʼ", culture.native_name());
    }
    
    auto test_method_(brx_IN) {
      auto culture = culture_info {"brx-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bodo (India)", culture.display_name());
      assert::are_equal("Bodo (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("brx-IN", culture.name());
      assert::are_equal("बरʼ (भारत)", culture.native_name());
    }
    
    auto test_method_(bs) {
      auto culture = culture_info {"bs"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bosnian", culture.display_name());
      assert::are_equal("Bosnian", culture.english_name());
      assert::are_equal(30746_z, culture.keyboard_layout_id());
      assert::are_equal(30746_z, culture.lcid());
      assert::are_equal("bs", culture.name());
      assert::are_equal("bosanski", culture.native_name());
    }
    
    auto test_method_(bs_Cyrl) {
      auto culture = culture_info {"bs-Cyrl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bosnian (Cyrillic)", culture.display_name());
      assert::are_equal("Bosnian (Cyrillic)", culture.english_name());
      assert::are_equal(25626_z, culture.keyboard_layout_id());
      assert::are_equal(25626_z, culture.lcid());
      assert::are_equal("bs-Cyrl", culture.name());
      assert::are_equal("босански (ћирилица)", culture.native_name());
    }
    
    auto test_method_(bs_Cyrl_BA) {
      auto culture = culture_info {"bs-Cyrl-BA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bosnian (Cyrillic, Bosnia & Herzegovina)", culture.display_name());
      assert::are_equal("Bosnian (Cyrillic, Bosnia & Herzegovina)", culture.english_name());
      assert::are_equal(8218_z, culture.keyboard_layout_id());
      assert::are_equal(8218_z, culture.lcid());
      assert::are_equal("bs-Cyrl-BA", culture.name());
      assert::are_equal("босански (ћирилица, Босна и Херцеговина)", culture.native_name());
    }
    
    auto test_method_(bs_Latn) {
      auto culture = culture_info {"bs-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bosnian (Latin)", culture.display_name());
      assert::are_equal("Bosnian (Latin)", culture.english_name());
      assert::are_equal(26650_z, culture.keyboard_layout_id());
      assert::are_equal(26650_z, culture.lcid());
      assert::are_equal("bs-Latn", culture.name());
      assert::are_equal("bosanski (latinica)", culture.native_name());
    }
    
    auto test_method_(bs_Latn_BA) {
      auto culture = culture_info {"bs-Latn-BA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bosnian (Latin, Bosnia & Herzegovina)", culture.display_name());
      assert::are_equal("Bosnian (Latin, Bosnia & Herzegovina)", culture.english_name());
      assert::are_equal(5146_z, culture.keyboard_layout_id());
      assert::are_equal(5146_z, culture.lcid());
      assert::are_equal("bs-Latn-BA", culture.name());
      assert::are_equal("bosanski (latinica, Bosna i Hercegovina)", culture.native_name());
    }
    
    auto test_method_(byn) {
      auto culture = culture_info {"byn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Blin", culture.display_name());
      assert::are_equal("Blin", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("byn", culture.name());
      assert::are_equal("ብሊን", culture.native_name());
    }
    
    auto test_method_(byn_ER) {
      auto culture = culture_info {"byn-ER"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Blin (Eritrea)", culture.display_name());
      assert::are_equal("Blin (Eritrea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("byn-ER", culture.name());
      assert::are_equal("ብሊን (ኤርትራ)", culture.native_name());
    }
    
    auto test_method_(ca) {
      auto culture = culture_info {"ca"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Catalan", culture.display_name());
      assert::are_equal("Catalan", culture.english_name());
      assert::are_equal(3_z, culture.keyboard_layout_id());
      assert::are_equal(3_z, culture.lcid());
      assert::are_equal("ca", culture.name());
      assert::are_equal("català", culture.native_name());
    }
    
    auto test_method_(ca_AD) {
      auto culture = culture_info {"ca-AD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Catalan (Andorra)", culture.display_name());
      assert::are_equal("Catalan (Andorra)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ca-AD", culture.name());
      assert::are_equal("català (Andorra)", culture.native_name());
    }
    
    auto test_method_(ca_ES) {
      auto culture = culture_info {"ca-ES"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Catalan (Spain)", culture.display_name());
      assert::are_equal("Catalan (Spain)", culture.english_name());
      assert::are_equal(1027_z, culture.keyboard_layout_id());
      assert::are_equal(1027_z, culture.lcid());
      assert::are_equal("ca-ES", culture.name());
      assert::are_equal("català (Espanya)", culture.native_name());
    }
    
    auto test_method_(ca_FR) {
      auto culture = culture_info {"ca-FR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Catalan (France)", culture.display_name());
      assert::are_equal("Catalan (France)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ca-FR", culture.name());
      assert::are_equal("català (França)", culture.native_name());
    }
    
    auto test_method_(ca_IT) {
      auto culture = culture_info {"ca-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Catalan (Italy)", culture.display_name());
      assert::are_equal("Catalan (Italy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ca-IT", culture.name());
      assert::are_equal("català (Itàlia)", culture.native_name());
    }
    
    auto test_method_(ccp) {
      auto culture = culture_info {"ccp"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Chakma", culture.display_name());
      assert::are_equal("Chakma", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ccp", culture.name());
      assert::are_equal("𑄌𑄋𑄴𑄟𑄳𑄦", culture.native_name());
    }
    
    auto test_method_(ccp_BD) {
      auto culture = culture_info {"ccp-BD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chakma (Bangladesh)", culture.display_name());
      assert::are_equal("Chakma (Bangladesh)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ccp-BD", culture.name());
      assert::are_equal("𑄌𑄋𑄴𑄟𑄳𑄦 (𑄝𑄁𑄣𑄘𑄬𑄌𑄴)", culture.native_name());
    }
    
    auto test_method_(ccp_IN) {
      auto culture = culture_info {"ccp-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chakma (India)", culture.display_name());
      assert::are_equal("Chakma (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ccp-IN", culture.name());
      assert::are_equal("𑄌𑄋𑄴𑄟𑄳𑄦 (𑄞𑄢𑄧𑄖𑄴)", culture.native_name());
    }
    
    auto test_method_(ce) {
      auto culture = culture_info {"ce"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Chechen", culture.display_name());
      assert::are_equal("Chechen", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ce", culture.name());
      assert::are_equal("нохчийн", culture.native_name());
    }
    
    auto test_method_(ce_RU) {
      auto culture = culture_info {"ce-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chechen (Russia)", culture.display_name());
      assert::are_equal("Chechen (Russia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ce-RU", culture.name());
      assert::are_equal("нохчийн (Росси)", culture.native_name());
    }
    
    auto test_method_(ceb) {
      auto culture = culture_info {"ceb"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Cebuano", culture.display_name());
      assert::are_equal("Cebuano", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ceb", culture.name());
      assert::are_equal("Cebuano", culture.native_name());
    }
    
    auto test_method_(ceb_PH) {
      auto culture = culture_info {"ceb-PH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Cebuano (Philippines)", culture.display_name());
      assert::are_equal("Cebuano (Philippines)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ceb-PH", culture.name());
      assert::are_equal("Cebuano (Pilipinas)", culture.native_name());
    }
    
    auto test_method_(cgg) {
      auto culture = culture_info {"cgg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Chiga", culture.display_name());
      assert::are_equal("Chiga", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("cgg", culture.name());
      assert::are_equal("Rukiga", culture.native_name());
    }
    
    auto test_method_(cgg_UG) {
      auto culture = culture_info {"cgg-UG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chiga (Uganda)", culture.display_name());
      assert::are_equal("Chiga (Uganda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("cgg-UG", culture.name());
      assert::are_equal("Rukiga (Uganda)", culture.native_name());
    }
    
    auto test_method_(cho) {
      auto culture = culture_info {"cho"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Choctaw", culture.display_name());
      assert::are_equal("Choctaw", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("cho", culture.name());
      assert::are_equal("Chahta", culture.native_name());
    }
    
    auto test_method_(cho_US) {
      auto culture = culture_info {"cho-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Choctaw (United States)", culture.display_name());
      assert::are_equal("Choctaw (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("cho-US", culture.name());
      assert::are_equal("Chahta (United States)", culture.native_name());
    }
    
    auto test_method_(chr) {
      auto culture = culture_info {"chr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Cherokee", culture.display_name());
      assert::are_equal("Cherokee", culture.english_name());
      assert::are_equal(92_z, culture.keyboard_layout_id());
      assert::are_equal(92_z, culture.lcid());
      assert::are_equal("chr", culture.name());
      assert::are_equal("ᏣᎳᎩ", culture.native_name());
    }
    
    auto test_method_(chr_US) {
      auto culture = culture_info {"chr-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Cherokee (United States)", culture.display_name());
      assert::are_equal("Cherokee (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("chr-US", culture.name());
      assert::are_equal("ᏣᎳᎩ (ᏌᏊ ᎢᏳᎾᎵᏍᏔᏅ ᏍᎦᏚᎩ)", culture.native_name());
    }
    
    auto test_method_(cic) {
      auto culture = culture_info {"cic"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Chickasaw", culture.display_name());
      assert::are_equal("Chickasaw", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("cic", culture.name());
      assert::are_equal("Chikashshanompaʼ", culture.native_name());
    }
    
    auto test_method_(cic_US) {
      auto culture = culture_info {"cic-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chickasaw (United States)", culture.display_name());
      assert::are_equal("Chickasaw (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("cic-US", culture.name());
      assert::are_equal("Chikashshanompaʼ (United States)", culture.native_name());
    }
    
    auto test_method_(ckb) {
      auto culture = culture_info {"ckb"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kurdish, Sorani", culture.display_name());
      assert::are_equal("Kurdish, Sorani", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ckb", culture.name());
      assert::are_equal("کوردیی ناوەندی", culture.native_name());
    }
    
    auto test_method_(ckb_IQ) {
      auto culture = culture_info {"ckb-IQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kurdish, Sorani (Iraq)", culture.display_name());
      assert::are_equal("Kurdish, Sorani (Iraq)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ckb-IQ", culture.name());
      assert::are_equal("کوردیی ناوەندی (عێراق)", culture.native_name());
    }
    
    auto test_method_(ckb_IR) {
      auto culture = culture_info {"ckb-IR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kurdish, Sorani (Iran)", culture.display_name());
      assert::are_equal("Kurdish, Sorani (Iran)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ckb-IR", culture.name());
      assert::are_equal("کوردیی ناوەندی (ئێران)", culture.native_name());
    }
    
    auto test_method_(co) {
      auto culture = culture_info {"co"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Corsican", culture.display_name());
      assert::are_equal("Corsican", culture.english_name());
      assert::are_equal(131_z, culture.keyboard_layout_id());
      assert::are_equal(131_z, culture.lcid());
      assert::are_equal("co", culture.name());
      assert::are_equal("corsu", culture.native_name());
    }
    
    auto test_method_(co_FR) {
      auto culture = culture_info {"co-FR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Corsican (France)", culture.display_name());
      assert::are_equal("Corsican (France)", culture.english_name());
      assert::are_equal(1155_z, culture.keyboard_layout_id());
      assert::are_equal(1155_z, culture.lcid());
      assert::are_equal("co-FR", culture.name());
      assert::are_equal("Corsican (France)", culture.native_name());
    }
    
    auto test_method_(cs) {
      auto culture = culture_info {"cs"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Czech", culture.display_name());
      assert::are_equal("Czech", culture.english_name());
      assert::are_equal(5_z, culture.keyboard_layout_id());
      assert::are_equal(5_z, culture.lcid());
      assert::are_equal("cs", culture.name());
      assert::are_equal("čeština", culture.native_name());
    }
    
    auto test_method_(cs_CZ) {
      auto culture = culture_info {"cs-CZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Czech (Czechia)", culture.display_name());
      assert::are_equal("Czech (Czechia)", culture.english_name());
      assert::are_equal(1029_z, culture.keyboard_layout_id());
      assert::are_equal(1029_z, culture.lcid());
      assert::are_equal("cs-CZ", culture.name());
      assert::are_equal("čeština (Česko)", culture.native_name());
    }
    
    auto test_method_(csw) {
      auto culture = culture_info {"csw"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Swampy Cree", culture.display_name());
      assert::are_equal("Swampy Cree", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("csw", culture.name());
      assert::are_equal("ᓀᐦᐃᓇᐍᐏᐣ", culture.native_name());
    }
    
    auto test_method_(csw_CA) {
      auto culture = culture_info {"csw-CA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swampy Cree (Canada)", culture.display_name());
      assert::are_equal("Swampy Cree (Canada)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("csw-CA", culture.name());
      assert::are_equal("ᓀᐦᐃᓇᐍᐏᐣ (ᑳᓇᑕ)", culture.native_name());
    }
    
    auto test_method_(cv) {
      auto culture = culture_info {"cv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Chuvash", culture.display_name());
      assert::are_equal("Chuvash", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("cv", culture.name());
      assert::are_equal("чӑваш", culture.native_name());
    }
    
    auto test_method_(cv_RU) {
      auto culture = culture_info {"cv-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chuvash (Russia)", culture.display_name());
      assert::are_equal("Chuvash (Russia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("cv-RU", culture.name());
      assert::are_equal("чӑваш (Раҫҫей)", culture.native_name());
    }
    
    auto test_method_(cy) {
      auto culture = culture_info {"cy"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Welsh", culture.display_name());
      assert::are_equal("Welsh", culture.english_name());
      assert::are_equal(82_z, culture.keyboard_layout_id());
      assert::are_equal(82_z, culture.lcid());
      assert::are_equal("cy", culture.name());
      assert::are_equal("Cymraeg", culture.native_name());
    }
    
    auto test_method_(cy_GB) {
      auto culture = culture_info {"cy-GB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Welsh (United Kingdom)", culture.display_name());
      assert::are_equal("Welsh (United Kingdom)", culture.english_name());
      assert::are_equal(1106_z, culture.keyboard_layout_id());
      assert::are_equal(1106_z, culture.lcid());
      assert::are_equal("cy-GB", culture.name());
      assert::are_equal("Cymraeg (Y Deyrnas Unedig)", culture.native_name());
    }
    
    auto test_method_(da) {
      auto culture = culture_info {"da"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Danish", culture.display_name());
      assert::are_equal("Danish", culture.english_name());
      assert::are_equal(6_z, culture.keyboard_layout_id());
      assert::are_equal(6_z, culture.lcid());
      assert::are_equal("da", culture.name());
      assert::are_equal("dansk", culture.native_name());
    }
    
    auto test_method_(da_DK) {
      auto culture = culture_info {"da-DK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Danish (Denmark)", culture.display_name());
      assert::are_equal("Danish (Denmark)", culture.english_name());
      assert::are_equal(1030_z, culture.keyboard_layout_id());
      assert::are_equal(1030_z, culture.lcid());
      assert::are_equal("da-DK", culture.name());
      assert::are_equal("dansk (Danmark)", culture.native_name());
    }
    
    auto test_method_(da_GL) {
      auto culture = culture_info {"da-GL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Danish (Greenland)", culture.display_name());
      assert::are_equal("Danish (Greenland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("da-GL", culture.name());
      assert::are_equal("dansk (Grønland)", culture.native_name());
    }
    
    auto test_method_(dav) {
      auto culture = culture_info {"dav"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Taita", culture.display_name());
      assert::are_equal("Taita", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dav", culture.name());
      assert::are_equal("Kitaita", culture.native_name());
    }
    
    auto test_method_(dav_KE) {
      auto culture = culture_info {"dav-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Taita (Kenya)", culture.display_name());
      assert::are_equal("Taita (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dav-KE", culture.name());
      assert::are_equal("Kitaita (Kenya)", culture.native_name());
    }
    
    auto test_method_(de) {
      auto culture = culture_info {"de"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("German", culture.display_name());
      assert::are_equal("German", culture.english_name());
      assert::are_equal(7_z, culture.keyboard_layout_id());
      assert::are_equal(7_z, culture.lcid());
      assert::are_equal("de", culture.name());
      assert::are_equal("Deutsch", culture.native_name());
    }
    
    auto test_method_(de_AT) {
      auto culture = culture_info {"de-AT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("German (Austria)", culture.display_name());
      assert::are_equal("German (Austria)", culture.english_name());
      assert::are_equal(3079_z, culture.keyboard_layout_id());
      assert::are_equal(3079_z, culture.lcid());
      assert::are_equal("de-AT", culture.name());
      assert::are_equal("Deutsch (Österreich)", culture.native_name());
    }
    
    auto test_method_(de_BE) {
      auto culture = culture_info {"de-BE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("German (Belgium)", culture.display_name());
      assert::are_equal("German (Belgium)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("de-BE", culture.name());
      assert::are_equal("Deutsch (Belgien)", culture.native_name());
    }
    
    auto test_method_(de_CH) {
      auto culture = culture_info {"de-CH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("German (Switzerland)", culture.display_name());
      assert::are_equal("German (Switzerland)", culture.english_name());
      assert::are_equal(2055_z, culture.keyboard_layout_id());
      assert::are_equal(2055_z, culture.lcid());
      assert::are_equal("de-CH", culture.name());
      assert::are_equal("Deutsch (Schweiz)", culture.native_name());
    }
    
    auto test_method_(de_DE) {
      auto culture = culture_info {"de-DE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("German (Germany)", culture.display_name());
      assert::are_equal("German (Germany)", culture.english_name());
      assert::are_equal(1031_z, culture.keyboard_layout_id());
      assert::are_equal(1031_z, culture.lcid());
      assert::are_equal("de-DE", culture.name());
      assert::are_equal("Deutsch (Deutschland)", culture.native_name());
    }
    
    auto test_method_(de_IT) {
      auto culture = culture_info {"de-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("German (Italy)", culture.display_name());
      assert::are_equal("German (Italy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("de-IT", culture.name());
      assert::are_equal("Deutsch (Italien)", culture.native_name());
    }
    
    auto test_method_(de_LI) {
      auto culture = culture_info {"de-LI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("German (Liechtenstein)", culture.display_name());
      assert::are_equal("German (Liechtenstein)", culture.english_name());
      assert::are_equal(5127_z, culture.keyboard_layout_id());
      assert::are_equal(5127_z, culture.lcid());
      assert::are_equal("de-LI", culture.name());
      assert::are_equal("Deutsch (Liechtenstein)", culture.native_name());
    }
    
    auto test_method_(de_LU) {
      auto culture = culture_info {"de-LU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("German (Luxembourg)", culture.display_name());
      assert::are_equal("German (Luxembourg)", culture.english_name());
      assert::are_equal(4103_z, culture.keyboard_layout_id());
      assert::are_equal(4103_z, culture.lcid());
      assert::are_equal("de-LU", culture.name());
      assert::are_equal("Deutsch (Luxemburg)", culture.native_name());
    }
    
    auto test_method_(dje) {
      auto culture = culture_info {"dje"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Zarma", culture.display_name());
      assert::are_equal("Zarma", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dje", culture.name());
      assert::are_equal("Zarmaciine", culture.native_name());
    }
    
    auto test_method_(dje_NE) {
      auto culture = culture_info {"dje-NE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Zarma (Niger)", culture.display_name());
      assert::are_equal("Zarma (Niger)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dje-NE", culture.name());
      assert::are_equal("Zarmaciine (Nižer)", culture.native_name());
    }
    
    auto test_method_(doi) {
      auto culture = culture_info {"doi"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Dogri", culture.display_name());
      assert::are_equal("Dogri", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("doi", culture.name());
      assert::are_equal("डोगरी", culture.native_name());
    }
    
    auto test_method_(doi_IN) {
      auto culture = culture_info {"doi-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dogri (India)", culture.display_name());
      assert::are_equal("Dogri (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("doi-IN", culture.name());
      assert::are_equal("डोगरी (भारत)", culture.native_name());
    }
    
    auto test_method_(dsb) {
      auto culture = culture_info {"dsb"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Lower Sorbian", culture.display_name());
      assert::are_equal("Lower Sorbian", culture.english_name());
      assert::are_equal(31790_z, culture.keyboard_layout_id());
      assert::are_equal(31790_z, culture.lcid());
      assert::are_equal("dsb", culture.name());
      assert::are_equal("dolnoserbšćina", culture.native_name());
    }
    
    auto test_method_(dsb_DE) {
      auto culture = culture_info {"dsb-DE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lower Sorbian (Germany)", culture.display_name());
      assert::are_equal("Lower Sorbian (Germany)", culture.english_name());
      assert::are_equal(2094_z, culture.keyboard_layout_id());
      assert::are_equal(2094_z, culture.lcid());
      assert::are_equal("dsb-DE", culture.name());
      assert::are_equal("dolnoserbšćina (Nimska)", culture.native_name());
    }
    
    auto test_method_(dua) {
      auto culture = culture_info {"dua"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Duala", culture.display_name());
      assert::are_equal("Duala", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dua", culture.name());
      assert::are_equal("duálá", culture.native_name());
    }
    
    auto test_method_(dua_CM) {
      auto culture = culture_info {"dua-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Duala (Cameroon)", culture.display_name());
      assert::are_equal("Duala (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dua-CM", culture.name());
      assert::are_equal("duálá (Cameroun)", culture.native_name());
    }
    
    auto test_method_(dv) {
      auto culture = culture_info {"dv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Dhivehi", culture.display_name());
      assert::are_equal("Dhivehi", culture.english_name());
      assert::are_equal(101_z, culture.keyboard_layout_id());
      assert::are_equal(101_z, culture.lcid());
      assert::are_equal("dv", culture.name());
      assert::are_equal("ދިވެހިބަސް", culture.native_name());
    }
    
    auto test_method_(dv_MV) {
      auto culture = culture_info {"dv-MV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dhivehi (Maldives)", culture.display_name());
      assert::are_equal("Dhivehi (Maldives)", culture.english_name());
      assert::are_equal(1125_z, culture.keyboard_layout_id());
      assert::are_equal(1125_z, culture.lcid());
      assert::are_equal("dv-MV", culture.name());
      assert::are_equal("ދިވެހިބަސް (ދިވެހި ރާއްޖެ)", culture.native_name());
    }
    
    auto test_method_(dyo) {
      auto culture = culture_info {"dyo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Jola-Fonyi", culture.display_name());
      assert::are_equal("Jola-Fonyi", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dyo", culture.name());
      assert::are_equal("joola", culture.native_name());
    }
    
    auto test_method_(dyo_SN) {
      auto culture = culture_info {"dyo-SN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Jola-Fonyi (Senegal)", culture.display_name());
      assert::are_equal("Jola-Fonyi (Senegal)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dyo-SN", culture.name());
      assert::are_equal("joola (Senegal)", culture.native_name());
    }
    
    auto test_method_(dz) {
      auto culture = culture_info {"dz"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Dzongkha", culture.display_name());
      assert::are_equal("Dzongkha", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("dz", culture.name());
      assert::are_equal("རྫོང་ཁ་", culture.native_name());
    }
    
    auto test_method_(dz_BT) {
      auto culture = culture_info {"dz-BT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dzongkha (Bhutan)", culture.display_name());
      assert::are_equal("Dzongkha (Bhutan)", culture.english_name());
      assert::are_equal(3153_z, culture.keyboard_layout_id());
      assert::are_equal(3153_z, culture.lcid());
      assert::are_equal("dz-BT", culture.name());
      assert::are_equal("རྫོང་ཁ་། (འབྲུག།)", culture.native_name());
    }
    
    auto test_method_(ebu) {
      auto culture = culture_info {"ebu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Embu", culture.display_name());
      assert::are_equal("Embu", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ebu", culture.name());
      assert::are_equal("Kĩembu", culture.native_name());
    }
    
    auto test_method_(ebu_KE) {
      auto culture = culture_info {"ebu-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Embu (Kenya)", culture.display_name());
      assert::are_equal("Embu (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ebu-KE", culture.name());
      assert::are_equal("Kĩembu (Kenya)", culture.native_name());
    }
    
    auto test_method_(ee) {
      auto culture = culture_info {"ee"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ewe", culture.display_name());
      assert::are_equal("Ewe", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ee", culture.name());
      assert::are_equal("eʋegbe", culture.native_name());
    }
    
    auto test_method_(ee_GH) {
      auto culture = culture_info {"ee-GH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ewe (Ghana)", culture.display_name());
      assert::are_equal("Ewe (Ghana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ee-GH", culture.name());
      assert::are_equal("eʋegbe (Ghana nutome)", culture.native_name());
    }
    
    auto test_method_(ee_TG) {
      auto culture = culture_info {"ee-TG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ewe (Togo)", culture.display_name());
      assert::are_equal("Ewe (Togo)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ee-TG", culture.name());
      assert::are_equal("eʋegbe (Togo nutome)", culture.native_name());
    }
    
    auto test_method_(el) {
      auto culture = culture_info {"el"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Greek", culture.display_name());
      assert::are_equal("Greek", culture.english_name());
      assert::are_equal(8_z, culture.keyboard_layout_id());
      assert::are_equal(8_z, culture.lcid());
      assert::are_equal("el", culture.name());
      assert::are_equal("Ελληνικά", culture.native_name());
    }
    
    auto test_method_(el_CY) {
      auto culture = culture_info {"el-CY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Greek (Cyprus)", culture.display_name());
      assert::are_equal("Greek (Cyprus)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("el-CY", culture.name());
      assert::are_equal("Ελληνικά (Κύπρος)", culture.native_name());
    }
    
    auto test_method_(el_GR) {
      auto culture = culture_info {"el-GR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Greek (Greece)", culture.display_name());
      assert::are_equal("Greek (Greece)", culture.english_name());
      assert::are_equal(1032_z, culture.keyboard_layout_id());
      assert::are_equal(1032_z, culture.lcid());
      assert::are_equal("el-GR", culture.name());
      assert::are_equal("Ελληνικά (Ελλάδα)", culture.native_name());
    }
    
    auto test_method_(en) {
      auto culture = culture_info {"en"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("English", culture.display_name());
      assert::are_equal("English", culture.english_name());
      assert::are_equal(9_z, culture.keyboard_layout_id());
      assert::are_equal(9_z, culture.lcid());
      assert::are_equal("en", culture.name());
      assert::are_equal("English", culture.native_name());
    }
    
    auto test_method_(en_001) {
      auto culture = culture_info {"en-001"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (world)", culture.display_name());
      assert::are_equal("English (world)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-001", culture.name());
      assert::are_equal("English (world)", culture.native_name());
    }
    
    auto test_method_(en_150) {
      auto culture = culture_info {"en-150"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Europe)", culture.display_name());
      assert::are_equal("English (Europe)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-150", culture.name());
      assert::are_equal("English (Europe)", culture.native_name());
    }
    
    auto test_method_(en_AE) {
      auto culture = culture_info {"en-AE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United Arab Emirates)", culture.display_name());
      assert::are_equal("English (United Arab Emirates)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-AE", culture.name());
      assert::are_equal("English (United Arab Emirates)", culture.native_name());
    }
    
    auto test_method_(en_AG) {
      auto culture = culture_info {"en-AG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Antigua & Barbuda)", culture.display_name());
      assert::are_equal("English (Antigua & Barbuda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-AG", culture.name());
      assert::are_equal("English (Antigua & Barbuda)", culture.native_name());
    }
    
    auto test_method_(en_AI) {
      auto culture = culture_info {"en-AI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Anguilla)", culture.display_name());
      assert::are_equal("English (Anguilla)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-AI", culture.name());
      assert::are_equal("English (Anguilla)", culture.native_name());
    }
    
    auto test_method_(en_AL) {
      auto culture = culture_info {"en-AL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Albania)", culture.display_name());
      assert::are_equal("English (Albania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-AL", culture.name());
      assert::are_equal("English (Albania)", culture.native_name());
    }
    
    auto test_method_(en_AR) {
      auto culture = culture_info {"en-AR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Argentina)", culture.display_name());
      assert::are_equal("English (Argentina)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-AR", culture.name());
      assert::are_equal("English (Argentina)", culture.native_name());
    }
    
    auto test_method_(en_AS) {
      auto culture = culture_info {"en-AS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (American Samoa)", culture.display_name());
      assert::are_equal("English (American Samoa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-AS", culture.name());
      assert::are_equal("English (American Samoa)", culture.native_name());
    }
    
    auto test_method_(en_AT) {
      auto culture = culture_info {"en-AT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Austria)", culture.display_name());
      assert::are_equal("English (Austria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-AT", culture.name());
      assert::are_equal("English (Austria)", culture.native_name());
    }
    
    auto test_method_(en_AU) {
      auto culture = culture_info {"en-AU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Australia)", culture.display_name());
      assert::are_equal("English (Australia)", culture.english_name());
      assert::are_equal(3081_z, culture.keyboard_layout_id());
      assert::are_equal(3081_z, culture.lcid());
      assert::are_equal("en-AU", culture.name());
      assert::are_equal("English (Australia)", culture.native_name());
    }
    
    auto test_method_(en_BB) {
      auto culture = culture_info {"en-BB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Barbados)", culture.display_name());
      assert::are_equal("English (Barbados)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BB", culture.name());
      assert::are_equal("English (Barbados)", culture.native_name());
    }
    
    auto test_method_(en_BD) {
      auto culture = culture_info {"en-BD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Bangladesh)", culture.display_name());
      assert::are_equal("English (Bangladesh)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BD", culture.name());
      assert::are_equal("English (Bangladesh)", culture.native_name());
    }
    
    auto test_method_(en_BE) {
      auto culture = culture_info {"en-BE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Belgium)", culture.display_name());
      assert::are_equal("English (Belgium)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BE", culture.name());
      assert::are_equal("English (Belgium)", culture.native_name());
    }
    
    auto test_method_(en_BG) {
      auto culture = culture_info {"en-BG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Bulgaria)", culture.display_name());
      assert::are_equal("English (Bulgaria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BG", culture.name());
      assert::are_equal("English (Bulgaria)", culture.native_name());
    }
    
    auto test_method_(en_BI) {
      auto culture = culture_info {"en-BI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Burundi)", culture.display_name());
      assert::are_equal("English (Burundi)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BI", culture.name());
      assert::are_equal("English (Burundi)", culture.native_name());
    }
    
    auto test_method_(en_BM) {
      auto culture = culture_info {"en-BM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Bermuda)", culture.display_name());
      assert::are_equal("English (Bermuda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BM", culture.name());
      assert::are_equal("English (Bermuda)", culture.native_name());
    }
    
    auto test_method_(en_BN) {
      auto culture = culture_info {"en-BN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Brunei)", culture.display_name());
      assert::are_equal("English (Brunei)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BN", culture.name());
      assert::are_equal("English (Brunei)", culture.native_name());
    }
    
    auto test_method_(en_BR) {
      auto culture = culture_info {"en-BR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Brazil)", culture.display_name());
      assert::are_equal("English (Brazil)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BR", culture.name());
      assert::are_equal("English (Brazil)", culture.native_name());
    }
    
    auto test_method_(en_BS) {
      auto culture = culture_info {"en-BS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Bahamas)", culture.display_name());
      assert::are_equal("English (Bahamas)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BS", culture.name());
      assert::are_equal("English (Bahamas)", culture.native_name());
    }
    
    auto test_method_(en_BW) {
      auto culture = culture_info {"en-BW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Botswana)", culture.display_name());
      assert::are_equal("English (Botswana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-BW", culture.name());
      assert::are_equal("English (Botswana)", culture.native_name());
    }
    
    auto test_method_(en_BZ) {
      auto culture = culture_info {"en-BZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Belize)", culture.display_name());
      assert::are_equal("English (Belize)", culture.english_name());
      assert::are_equal(10249_z, culture.keyboard_layout_id());
      assert::are_equal(10249_z, culture.lcid());
      assert::are_equal("en-BZ", culture.name());
      assert::are_equal("English (Belize)", culture.native_name());
    }
    
    auto test_method_(en_CA) {
      auto culture = culture_info {"en-CA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Canada)", culture.display_name());
      assert::are_equal("English (Canada)", culture.english_name());
      assert::are_equal(4105_z, culture.keyboard_layout_id());
      assert::are_equal(4105_z, culture.lcid());
      assert::are_equal("en-CA", culture.name());
      assert::are_equal("English (Canada)", culture.native_name());
    }
    
    auto test_method_(en_CC) {
      auto culture = culture_info {"en-CC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Cocos [Keeling] Islands)", culture.display_name());
      assert::are_equal("English (Cocos [Keeling] Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CC", culture.name());
      assert::are_equal("English (Cocos [Keeling] Islands)", culture.native_name());
    }
    
    auto test_method_(en_CH) {
      auto culture = culture_info {"en-CH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Switzerland)", culture.display_name());
      assert::are_equal("English (Switzerland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CH", culture.name());
      assert::are_equal("English (Switzerland)", culture.native_name());
    }
    
    auto test_method_(en_CK) {
      auto culture = culture_info {"en-CK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Cook Islands)", culture.display_name());
      assert::are_equal("English (Cook Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CK", culture.name());
      assert::are_equal("English (Cook Islands)", culture.native_name());
    }
    
    auto test_method_(en_CL) {
      auto culture = culture_info {"en-CL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Chile)", culture.display_name());
      assert::are_equal("English (Chile)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CL", culture.name());
      assert::are_equal("English (Chile)", culture.native_name());
    }
    
    auto test_method_(en_CM) {
      auto culture = culture_info {"en-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Cameroon)", culture.display_name());
      assert::are_equal("English (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CM", culture.name());
      assert::are_equal("English (Cameroon)", culture.native_name());
    }
    
    auto test_method_(en_CN) {
      auto culture = culture_info {"en-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (China mainland)", culture.display_name());
      assert::are_equal("English (China mainland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CN", culture.name());
      assert::are_equal("English (China mainland)", culture.native_name());
    }
    
    auto test_method_(en_CO) {
      auto culture = culture_info {"en-CO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Colombia)", culture.display_name());
      assert::are_equal("English (Colombia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CO", culture.name());
      assert::are_equal("English (Colombia)", culture.native_name());
    }
    
    auto test_method_(en_CV) {
      auto culture = culture_info {"en-CV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Cape Verde)", culture.display_name());
      assert::are_equal("English (Cape Verde)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CV", culture.name());
      assert::are_equal("English (Cape Verde)", culture.native_name());
    }
    
    auto test_method_(en_CX) {
      auto culture = culture_info {"en-CX"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Christmas Island)", culture.display_name());
      assert::are_equal("English (Christmas Island)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CX", culture.name());
      assert::are_equal("English (Christmas Island)", culture.native_name());
    }
    
    auto test_method_(en_CY) {
      auto culture = culture_info {"en-CY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Cyprus)", culture.display_name());
      assert::are_equal("English (Cyprus)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CY", culture.name());
      assert::are_equal("English (Cyprus)", culture.native_name());
    }
    
    auto test_method_(en_CZ) {
      auto culture = culture_info {"en-CZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Czechia)", culture.display_name());
      assert::are_equal("English (Czechia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-CZ", culture.name());
      assert::are_equal("English (Czechia)", culture.native_name());
    }
    
    auto test_method_(en_DE) {
      auto culture = culture_info {"en-DE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Germany)", culture.display_name());
      assert::are_equal("English (Germany)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-DE", culture.name());
      assert::are_equal("English (Germany)", culture.native_name());
    }
    
    auto test_method_(en_DG) {
      auto culture = culture_info {"en-DG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Diego Garcia)", culture.display_name());
      assert::are_equal("English (Diego Garcia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-DG", culture.name());
      assert::are_equal("English (Diego Garcia)", culture.native_name());
    }
    
    auto test_method_(en_DK) {
      auto culture = culture_info {"en-DK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Denmark)", culture.display_name());
      assert::are_equal("English (Denmark)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-DK", culture.name());
      assert::are_equal("English (Denmark)", culture.native_name());
    }
    
    auto test_method_(en_DM) {
      auto culture = culture_info {"en-DM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Dominica)", culture.display_name());
      assert::are_equal("English (Dominica)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-DM", culture.name());
      assert::are_equal("English (Dominica)", culture.native_name());
    }
    
    auto test_method_(en_EE) {
      auto culture = culture_info {"en-EE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Estonia)", culture.display_name());
      assert::are_equal("English (Estonia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-EE", culture.name());
      assert::are_equal("English (Estonia)", culture.native_name());
    }
    
    auto test_method_(en_ER) {
      auto culture = culture_info {"en-ER"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Eritrea)", culture.display_name());
      assert::are_equal("English (Eritrea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-ER", culture.name());
      assert::are_equal("English (Eritrea)", culture.native_name());
    }
    
    auto test_method_(en_FI) {
      auto culture = culture_info {"en-FI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Finland)", culture.display_name());
      assert::are_equal("English (Finland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-FI", culture.name());
      assert::are_equal("English (Finland)", culture.native_name());
    }
    
    auto test_method_(en_FJ) {
      auto culture = culture_info {"en-FJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Fiji)", culture.display_name());
      assert::are_equal("English (Fiji)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-FJ", culture.name());
      assert::are_equal("English (Fiji)", culture.native_name());
    }
    
    auto test_method_(en_FK) {
      auto culture = culture_info {"en-FK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Falkland Islands)", culture.display_name());
      assert::are_equal("English (Falkland Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-FK", culture.name());
      assert::are_equal("English (Falkland Islands)", culture.native_name());
    }
    
    auto test_method_(en_FM) {
      auto culture = culture_info {"en-FM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Micronesia)", culture.display_name());
      assert::are_equal("English (Micronesia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-FM", culture.name());
      assert::are_equal("English (Micronesia)", culture.native_name());
    }
    
    auto test_method_(en_FR) {
      auto culture = culture_info {"en-FR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (France)", culture.display_name());
      assert::are_equal("English (France)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-FR", culture.name());
      assert::are_equal("English (France)", culture.native_name());
    }
    
    auto test_method_(en_GB) {
      auto culture = culture_info {"en-GB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United Kingdom)", culture.display_name());
      assert::are_equal("English (United Kingdom)", culture.english_name());
      assert::are_equal(2057_z, culture.keyboard_layout_id());
      assert::are_equal(2057_z, culture.lcid());
      assert::are_equal("en-GB", culture.name());
      assert::are_equal("English (United Kingdom)", culture.native_name());
    }
    
    auto test_method_(en_GD) {
      auto culture = culture_info {"en-GD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Grenada)", culture.display_name());
      assert::are_equal("English (Grenada)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-GD", culture.name());
      assert::are_equal("English (Grenada)", culture.native_name());
    }
    
    auto test_method_(en_GG) {
      auto culture = culture_info {"en-GG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Guernsey)", culture.display_name());
      assert::are_equal("English (Guernsey)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-GG", culture.name());
      assert::are_equal("English (Guernsey)", culture.native_name());
    }
    
    auto test_method_(en_GH) {
      auto culture = culture_info {"en-GH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Ghana)", culture.display_name());
      assert::are_equal("English (Ghana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-GH", culture.name());
      assert::are_equal("English (Ghana)", culture.native_name());
    }
    
    auto test_method_(en_GI) {
      auto culture = culture_info {"en-GI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Gibraltar)", culture.display_name());
      assert::are_equal("English (Gibraltar)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-GI", culture.name());
      assert::are_equal("English (Gibraltar)", culture.native_name());
    }
    
    auto test_method_(en_GM) {
      auto culture = culture_info {"en-GM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Gambia)", culture.display_name());
      assert::are_equal("English (Gambia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-GM", culture.name());
      assert::are_equal("English (Gambia)", culture.native_name());
    }
    
    auto test_method_(en_GR) {
      auto culture = culture_info {"en-GR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Greece)", culture.display_name());
      assert::are_equal("English (Greece)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-GR", culture.name());
      assert::are_equal("English (Greece)", culture.native_name());
    }
    
    auto test_method_(en_GU) {
      auto culture = culture_info {"en-GU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Guam)", culture.display_name());
      assert::are_equal("English (Guam)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-GU", culture.name());
      assert::are_equal("English (Guam)", culture.native_name());
    }
    
    auto test_method_(en_GY) {
      auto culture = culture_info {"en-GY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Guyana)", culture.display_name());
      assert::are_equal("English (Guyana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-GY", culture.name());
      assert::are_equal("English (Guyana)", culture.native_name());
    }
    
    auto test_method_(en_HK) {
      auto culture = culture_info {"en-HK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Hong Kong)", culture.display_name());
      assert::are_equal("English (Hong Kong)", culture.english_name());
      assert::are_equal(15369_z, culture.keyboard_layout_id());
      assert::are_equal(15369_z, culture.lcid());
      assert::are_equal("en-HK", culture.name());
      assert::are_equal("English (Hong Kong)", culture.native_name());
    }
    
    auto test_method_(en_HU) {
      auto culture = culture_info {"en-HU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Hungary)", culture.display_name());
      assert::are_equal("English (Hungary)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-HU", culture.name());
      assert::are_equal("English (Hungary)", culture.native_name());
    }
    
    auto test_method_(en_ID) {
      auto culture = culture_info {"en-ID"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Indonesia)", culture.display_name());
      assert::are_equal("English (Indonesia)", culture.english_name());
      assert::are_equal(14345_z, culture.keyboard_layout_id());
      assert::are_equal(14345_z, culture.lcid());
      assert::are_equal("en-ID", culture.name());
      assert::are_equal("English (Indonesia)", culture.native_name());
    }
    
    auto test_method_(en_IE) {
      auto culture = culture_info {"en-IE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Ireland)", culture.display_name());
      assert::are_equal("English (Ireland)", culture.english_name());
      assert::are_equal(6153_z, culture.keyboard_layout_id());
      assert::are_equal(6153_z, culture.lcid());
      assert::are_equal("en-IE", culture.name());
      assert::are_equal("English (Ireland)", culture.native_name());
    }
    
    auto test_method_(en_IL) {
      auto culture = culture_info {"en-IL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Israel)", culture.display_name());
      assert::are_equal("English (Israel)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-IL", culture.name());
      assert::are_equal("English (Israel)", culture.native_name());
    }
    
    auto test_method_(en_IM) {
      auto culture = culture_info {"en-IM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Isle of Man)", culture.display_name());
      assert::are_equal("English (Isle of Man)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-IM", culture.name());
      assert::are_equal("English (Isle of Man)", culture.native_name());
    }
    
    auto test_method_(en_IN) {
      auto culture = culture_info {"en-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (India)", culture.display_name());
      assert::are_equal("English (India)", culture.english_name());
      assert::are_equal(16393_z, culture.keyboard_layout_id());
      assert::are_equal(16393_z, culture.lcid());
      assert::are_equal("en-IN", culture.name());
      assert::are_equal("English (India)", culture.native_name());
    }
    
    auto test_method_(en_IO) {
      auto culture = culture_info {"en-IO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Chagos Archipelago)", culture.display_name());
      assert::are_equal("English (Chagos Archipelago)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-IO", culture.name());
      assert::are_equal("English (Chagos Archipelago)", culture.native_name());
    }
    
    auto test_method_(en_JE) {
      auto culture = culture_info {"en-JE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Jersey)", culture.display_name());
      assert::are_equal("English (Jersey)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-JE", culture.name());
      assert::are_equal("English (Jersey)", culture.native_name());
    }
    
    auto test_method_(en_JM) {
      auto culture = culture_info {"en-JM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Jamaica)", culture.display_name());
      assert::are_equal("English (Jamaica)", culture.english_name());
      assert::are_equal(8201_z, culture.keyboard_layout_id());
      assert::are_equal(8201_z, culture.lcid());
      assert::are_equal("en-JM", culture.name());
      assert::are_equal("English (Jamaica)", culture.native_name());
    }
    
    auto test_method_(en_JP) {
      auto culture = culture_info {"en-JP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Japan)", culture.display_name());
      assert::are_equal("English (Japan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-JP", culture.name());
      assert::are_equal("English (Japan)", culture.native_name());
    }
    
    auto test_method_(en_KE) {
      auto culture = culture_info {"en-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Kenya)", culture.display_name());
      assert::are_equal("English (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-KE", culture.name());
      assert::are_equal("English (Kenya)", culture.native_name());
    }
    
    auto test_method_(en_KI) {
      auto culture = culture_info {"en-KI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Kiribati)", culture.display_name());
      assert::are_equal("English (Kiribati)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-KI", culture.name());
      assert::are_equal("English (Kiribati)", culture.native_name());
    }
    
    auto test_method_(en_KN) {
      auto culture = culture_info {"en-KN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (St Kitts & Nevis)", culture.display_name());
      assert::are_equal("English (St. Kitts & Nevis)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-KN", culture.name());
      assert::are_equal("English (St Kitts & Nevis)", culture.native_name());
    }
    
    auto test_method_(en_KR) {
      auto culture = culture_info {"en-KR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (South Korea)", culture.display_name());
      assert::are_equal("English (South Korea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-KR", culture.name());
      assert::are_equal("English (South Korea)", culture.native_name());
    }
    
    auto test_method_(en_KY) {
      auto culture = culture_info {"en-KY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Cayman Islands)", culture.display_name());
      assert::are_equal("English (Cayman Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-KY", culture.name());
      assert::are_equal("English (Cayman Islands)", culture.native_name());
    }
    
    auto test_method_(en_LC) {
      auto culture = culture_info {"en-LC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (St Lucia)", culture.display_name());
      assert::are_equal("English (St. Lucia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-LC", culture.name());
      assert::are_equal("English (St Lucia)", culture.native_name());
    }
    
    auto test_method_(en_LR) {
      auto culture = culture_info {"en-LR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Liberia)", culture.display_name());
      assert::are_equal("English (Liberia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-LR", culture.name());
      assert::are_equal("English (Liberia)", culture.native_name());
    }
    
    auto test_method_(en_LS) {
      auto culture = culture_info {"en-LS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Lesotho)", culture.display_name());
      assert::are_equal("English (Lesotho)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-LS", culture.name());
      assert::are_equal("English (Lesotho)", culture.native_name());
    }
    
    auto test_method_(en_LT) {
      auto culture = culture_info {"en-LT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Lithuania)", culture.display_name());
      assert::are_equal("English (Lithuania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-LT", culture.name());
      assert::are_equal("English (Lithuania)", culture.native_name());
    }
    
    auto test_method_(en_LV) {
      auto culture = culture_info {"en-LV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Latvia)", culture.display_name());
      assert::are_equal("English (Latvia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-LV", culture.name());
      assert::are_equal("English (Latvia)", culture.native_name());
    }
    
    auto test_method_(en_MG) {
      auto culture = culture_info {"en-MG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Madagascar)", culture.display_name());
      assert::are_equal("English (Madagascar)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MG", culture.name());
      assert::are_equal("English (Madagascar)", culture.native_name());
    }
    
    auto test_method_(en_MH) {
      auto culture = culture_info {"en-MH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Marshall Islands)", culture.display_name());
      assert::are_equal("English (Marshall Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MH", culture.name());
      assert::are_equal("English (Marshall Islands)", culture.native_name());
    }
    
    auto test_method_(en_MM) {
      auto culture = culture_info {"en-MM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Myanmar [Burma])", culture.display_name());
      assert::are_equal("English (Myanmar [Burma])", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MM", culture.name());
      assert::are_equal("English (Myanmar [Burma])", culture.native_name());
    }
    
    auto test_method_(en_MO) {
      auto culture = culture_info {"en-MO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Macao)", culture.display_name());
      assert::are_equal("English (Macao)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MO", culture.name());
      assert::are_equal("English (Macao)", culture.native_name());
    }
    
    auto test_method_(en_MP) {
      auto culture = culture_info {"en-MP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Northern Mariana Islands)", culture.display_name());
      assert::are_equal("English (Northern Mariana Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MP", culture.name());
      assert::are_equal("English (Northern Mariana Islands)", culture.native_name());
    }
    
    auto test_method_(en_MS) {
      auto culture = culture_info {"en-MS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Montserrat)", culture.display_name());
      assert::are_equal("English (Montserrat)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MS", culture.name());
      assert::are_equal("English (Montserrat)", culture.native_name());
    }
    
    auto test_method_(en_MT) {
      auto culture = culture_info {"en-MT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Malta)", culture.display_name());
      assert::are_equal("English (Malta)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MT", culture.name());
      assert::are_equal("English (Malta)", culture.native_name());
    }
    
    auto test_method_(en_MU) {
      auto culture = culture_info {"en-MU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Mauritius)", culture.display_name());
      assert::are_equal("English (Mauritius)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MU", culture.name());
      assert::are_equal("English (Mauritius)", culture.native_name());
    }
    
    auto test_method_(en_MV) {
      auto culture = culture_info {"en-MV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Maldives)", culture.display_name());
      assert::are_equal("English (Maldives)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MV", culture.name());
      assert::are_equal("English (Maldives)", culture.native_name());
    }
    
    auto test_method_(en_MW) {
      auto culture = culture_info {"en-MW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Malawi)", culture.display_name());
      assert::are_equal("English (Malawi)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MW", culture.name());
      assert::are_equal("English (Malawi)", culture.native_name());
    }
    
    auto test_method_(en_MX) {
      auto culture = culture_info {"en-MX"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Mexico)", culture.display_name());
      assert::are_equal("English (Mexico)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-MX", culture.name());
      assert::are_equal("English (Mexico)", culture.native_name());
    }
    
    auto test_method_(en_MY) {
      auto culture = culture_info {"en-MY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Malaysia)", culture.display_name());
      assert::are_equal("English (Malaysia)", culture.english_name());
      assert::are_equal(17417_z, culture.keyboard_layout_id());
      assert::are_equal(17417_z, culture.lcid());
      assert::are_equal("en-MY", culture.name());
      assert::are_equal("English (Malaysia)", culture.native_name());
    }
    
    auto test_method_(en_NA) {
      auto culture = culture_info {"en-NA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Namibia)", culture.display_name());
      assert::are_equal("English (Namibia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-NA", culture.name());
      assert::are_equal("English (Namibia)", culture.native_name());
    }
    
    auto test_method_(en_NF) {
      auto culture = culture_info {"en-NF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Norfolk Island)", culture.display_name());
      assert::are_equal("English (Norfolk Island)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-NF", culture.name());
      assert::are_equal("English (Norfolk Island)", culture.native_name());
    }
    
    auto test_method_(en_NG) {
      auto culture = culture_info {"en-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Nigeria)", culture.display_name());
      assert::are_equal("English (Nigeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-NG", culture.name());
      assert::are_equal("English (Nigeria)", culture.native_name());
    }
    
    auto test_method_(en_NL) {
      auto culture = culture_info {"en-NL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Netherlands)", culture.display_name());
      assert::are_equal("English (Netherlands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-NL", culture.name());
      assert::are_equal("English (Netherlands)", culture.native_name());
    }
    
    auto test_method_(en_NO) {
      auto culture = culture_info {"en-NO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Norway)", culture.display_name());
      assert::are_equal("English (Norway)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-NO", culture.name());
      assert::are_equal("English (Norway)", culture.native_name());
    }
    
    auto test_method_(en_NR) {
      auto culture = culture_info {"en-NR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Nauru)", culture.display_name());
      assert::are_equal("English (Nauru)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-NR", culture.name());
      assert::are_equal("English (Nauru)", culture.native_name());
    }
    
    auto test_method_(en_NU) {
      auto culture = culture_info {"en-NU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Niue)", culture.display_name());
      assert::are_equal("English (Niue)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-NU", culture.name());
      assert::are_equal("English (Niue)", culture.native_name());
    }
    
    auto test_method_(en_NZ) {
      auto culture = culture_info {"en-NZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (New Zealand)", culture.display_name());
      assert::are_equal("English (New Zealand)", culture.english_name());
      assert::are_equal(5129_z, culture.keyboard_layout_id());
      assert::are_equal(5129_z, culture.lcid());
      assert::are_equal("en-NZ", culture.name());
      assert::are_equal("English (New Zealand)", culture.native_name());
    }
    
    auto test_method_(en_PG) {
      auto culture = culture_info {"en-PG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Papua New Guinea)", culture.display_name());
      assert::are_equal("English (Papua New Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-PG", culture.name());
      assert::are_equal("English (Papua New Guinea)", culture.native_name());
    }
    
    auto test_method_(en_PH) {
      auto culture = culture_info {"en-PH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Philippines)", culture.display_name());
      assert::are_equal("English (Philippines)", culture.english_name());
      assert::are_equal(13321_z, culture.keyboard_layout_id());
      assert::are_equal(13321_z, culture.lcid());
      assert::are_equal("en-PH", culture.name());
      assert::are_equal("English (Philippines)", culture.native_name());
    }
    
    auto test_method_(en_PK) {
      auto culture = culture_info {"en-PK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Pakistan)", culture.display_name());
      assert::are_equal("English (Pakistan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-PK", culture.name());
      assert::are_equal("English (Pakistan)", culture.native_name());
    }
    
    auto test_method_(en_PL) {
      auto culture = culture_info {"en-PL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Poland)", culture.display_name());
      assert::are_equal("English (Poland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-PL", culture.name());
      assert::are_equal("English (Poland)", culture.native_name());
    }
    
    auto test_method_(en_PN) {
      auto culture = culture_info {"en-PN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Pitcairn Islands)", culture.display_name());
      assert::are_equal("English (Pitcairn Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-PN", culture.name());
      assert::are_equal("English (Pitcairn Islands)", culture.native_name());
    }
    
    auto test_method_(en_PR) {
      auto culture = culture_info {"en-PR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Puerto Rico)", culture.display_name());
      assert::are_equal("English (Puerto Rico)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-PR", culture.name());
      assert::are_equal("English (Puerto Rico)", culture.native_name());
    }
    
    auto test_method_(en_PT) {
      auto culture = culture_info {"en-PT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Portugal)", culture.display_name());
      assert::are_equal("English (Portugal)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-PT", culture.name());
      assert::are_equal("English (Portugal)", culture.native_name());
    }
    
    auto test_method_(en_PW) {
      auto culture = culture_info {"en-PW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Palau)", culture.display_name());
      assert::are_equal("English (Palau)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-PW", culture.name());
      assert::are_equal("English (Palau)", culture.native_name());
    }
    
    auto test_method_(en_RU) {
      auto culture = culture_info {"en-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Russia)", culture.display_name());
      assert::are_equal("English (Russia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-RU", culture.name());
      assert::are_equal("English (Russia)", culture.native_name());
    }
    
    auto test_method_(en_RW) {
      auto culture = culture_info {"en-RW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Rwanda)", culture.display_name());
      assert::are_equal("English (Rwanda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-RW", culture.name());
      assert::are_equal("English (Rwanda)", culture.native_name());
    }
    
    auto test_method_(en_SA) {
      auto culture = culture_info {"en-SA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Saudi Arabia)", culture.display_name());
      assert::are_equal("English (Saudi Arabia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SA", culture.name());
      assert::are_equal("English (Saudi Arabia)", culture.native_name());
    }
    
    auto test_method_(en_SB) {
      auto culture = culture_info {"en-SB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Solomon Islands)", culture.display_name());
      assert::are_equal("English (Solomon Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SB", culture.name());
      assert::are_equal("English (Solomon Islands)", culture.native_name());
    }
    
    auto test_method_(en_SC) {
      auto culture = culture_info {"en-SC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Seychelles)", culture.display_name());
      assert::are_equal("English (Seychelles)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SC", culture.name());
      assert::are_equal("English (Seychelles)", culture.native_name());
    }
    
    auto test_method_(en_SD) {
      auto culture = culture_info {"en-SD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Sudan)", culture.display_name());
      assert::are_equal("English (Sudan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SD", culture.name());
      assert::are_equal("English (Sudan)", culture.native_name());
    }
    
    auto test_method_(en_SE) {
      auto culture = culture_info {"en-SE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Sweden)", culture.display_name());
      assert::are_equal("English (Sweden)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SE", culture.name());
      assert::are_equal("English (Sweden)", culture.native_name());
    }
    
    auto test_method_(en_SG) {
      auto culture = culture_info {"en-SG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Singapore)", culture.display_name());
      assert::are_equal("English (Singapore)", culture.english_name());
      assert::are_equal(18441_z, culture.keyboard_layout_id());
      assert::are_equal(18441_z, culture.lcid());
      assert::are_equal("en-SG", culture.name());
      assert::are_equal("English (Singapore)", culture.native_name());
    }
    
    auto test_method_(en_SH) {
      auto culture = culture_info {"en-SH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (St Helena)", culture.display_name());
      assert::are_equal("English (St. Helena)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SH", culture.name());
      assert::are_equal("English (St Helena)", culture.native_name());
    }
    
    auto test_method_(en_SI) {
      auto culture = culture_info {"en-SI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Slovenia)", culture.display_name());
      assert::are_equal("English (Slovenia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SI", culture.name());
      assert::are_equal("English (Slovenia)", culture.native_name());
    }
    
    auto test_method_(en_SK) {
      auto culture = culture_info {"en-SK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Slovakia)", culture.display_name());
      assert::are_equal("English (Slovakia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SK", culture.name());
      assert::are_equal("English (Slovakia)", culture.native_name());
    }
    
    auto test_method_(en_SL) {
      auto culture = culture_info {"en-SL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Sierra Leone)", culture.display_name());
      assert::are_equal("English (Sierra Leone)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SL", culture.name());
      assert::are_equal("English (Sierra Leone)", culture.native_name());
    }
    
    auto test_method_(en_SS) {
      auto culture = culture_info {"en-SS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (South Sudan)", culture.display_name());
      assert::are_equal("English (South Sudan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SS", culture.name());
      assert::are_equal("English (South Sudan)", culture.native_name());
    }
    
    auto test_method_(en_SX) {
      auto culture = culture_info {"en-SX"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Sint Maarten)", culture.display_name());
      assert::are_equal("English (Sint Maarten)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SX", culture.name());
      assert::are_equal("English (Sint Maarten)", culture.native_name());
    }
    
    auto test_method_(en_SZ) {
      auto culture = culture_info {"en-SZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Eswatini)", culture.display_name());
      assert::are_equal("English (Eswatini)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-SZ", culture.name());
      assert::are_equal("English (Eswatini)", culture.native_name());
    }
    
    auto test_method_(en_TC) {
      auto culture = culture_info {"en-TC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Turks & Caicos Islands)", culture.display_name());
      assert::are_equal("English (Turks & Caicos Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-TC", culture.name());
      assert::are_equal("English (Turks & Caicos Islands)", culture.native_name());
    }
    
    auto test_method_(en_TH) {
      auto culture = culture_info {"en-TH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Thailand)", culture.display_name());
      assert::are_equal("English (Thailand)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-TH", culture.name());
      assert::are_equal("English (Thailand)", culture.native_name());
    }
    
    auto test_method_(en_TK) {
      auto culture = culture_info {"en-TK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Tokelau)", culture.display_name());
      assert::are_equal("English (Tokelau)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-TK", culture.name());
      assert::are_equal("English (Tokelau)", culture.native_name());
    }
    
    auto test_method_(en_TO) {
      auto culture = culture_info {"en-TO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Tonga)", culture.display_name());
      assert::are_equal("English (Tonga)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-TO", culture.name());
      assert::are_equal("English (Tonga)", culture.native_name());
    }
    
    auto test_method_(en_TR) {
      auto culture = culture_info {"en-TR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Türkiye)", culture.display_name());
      assert::are_equal("English (Türkiye)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-TR", culture.name());
      assert::are_equal("English (Türkiye)", culture.native_name());
    }
    
    auto test_method_(en_TT) {
      auto culture = culture_info {"en-TT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Trinidad & Tobago)", culture.display_name());
      assert::are_equal("English (Trinidad & Tobago)", culture.english_name());
      assert::are_equal(11273_z, culture.keyboard_layout_id());
      assert::are_equal(11273_z, culture.lcid());
      assert::are_equal("en-TT", culture.name());
      assert::are_equal("English (Trinidad & Tobago)", culture.native_name());
    }
    
    auto test_method_(en_TV) {
      auto culture = culture_info {"en-TV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Tuvalu)", culture.display_name());
      assert::are_equal("English (Tuvalu)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-TV", culture.name());
      assert::are_equal("English (Tuvalu)", culture.native_name());
    }
    
    auto test_method_(en_TW) {
      auto culture = culture_info {"en-TW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Taiwan)", culture.display_name());
      assert::are_equal("English (Taiwan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-TW", culture.name());
      assert::are_equal("English (Taiwan)", culture.native_name());
    }
    
    auto test_method_(en_TZ) {
      auto culture = culture_info {"en-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Tanzania)", culture.display_name());
      assert::are_equal("English (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-TZ", culture.name());
      assert::are_equal("English (Tanzania)", culture.native_name());
    }
    
    auto test_method_(en_UA) {
      auto culture = culture_info {"en-UA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Ukraine)", culture.display_name());
      assert::are_equal("English (Ukraine)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-UA", culture.name());
      assert::are_equal("English (Ukraine)", culture.native_name());
    }
    
    auto test_method_(en_UG) {
      auto culture = culture_info {"en-UG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Uganda)", culture.display_name());
      assert::are_equal("English (Uganda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-UG", culture.name());
      assert::are_equal("English (Uganda)", culture.native_name());
    }
    
    auto test_method_(en_UM) {
      auto culture = culture_info {"en-UM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (US Outlying Islands)", culture.display_name());
      assert::are_equal("English (U.S. Outlying Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-UM", culture.name());
      assert::are_equal("English (U.S. Outlying Islands)", culture.native_name());
    }
    
    auto test_method_(en_US) {
      auto culture = culture_info {"en-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States)", culture.display_name());
      assert::are_equal("English (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(1033_z, culture.lcid());
      assert::are_equal("en-US", culture.name());
      assert::are_equal("English (United States)", culture.native_name());
    }
    
    auto test_method_(en_US_POSIX) {
      auto culture = culture_info {"en-US-POSIX"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (United States, Computer)", culture.display_name());
      assert::are_equal("English (United States, Computer)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-US-POSIX", culture.name());
      assert::are_equal("English (United States, Computer)", culture.native_name());
    }
    
    auto test_method_(en_VC) {
      auto culture = culture_info {"en-VC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (St Vincent & the Grenadines)", culture.display_name());
      assert::are_equal("English (St. Vincent & Grenadines)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-VC", culture.name());
      assert::are_equal("English (St Vincent & the Grenadines)", culture.native_name());
    }
    
    auto test_method_(en_VG) {
      auto culture = culture_info {"en-VG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (British Virgin Islands)", culture.display_name());
      assert::are_equal("English (British Virgin Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-VG", culture.name());
      assert::are_equal("English (British Virgin Islands)", culture.native_name());
    }
    
    auto test_method_(en_VI) {
      auto culture = culture_info {"en-VI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (US Virgin Islands)", culture.display_name());
      assert::are_equal("English (U.S. Virgin Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-VI", culture.name());
      assert::are_equal("English (U.S. Virgin Islands)", culture.native_name());
    }
    
    auto test_method_(en_VU) {
      auto culture = culture_info {"en-VU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Vanuatu)", culture.display_name());
      assert::are_equal("English (Vanuatu)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-VU", culture.name());
      assert::are_equal("English (Vanuatu)", culture.native_name());
    }
    
    auto test_method_(en_WS) {
      auto culture = culture_info {"en-WS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Samoa)", culture.display_name());
      assert::are_equal("English (Samoa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-WS", culture.name());
      assert::are_equal("English (Samoa)", culture.native_name());
    }
    
    auto test_method_(en_ZA) {
      auto culture = culture_info {"en-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (South Africa)", culture.display_name());
      assert::are_equal("English (South Africa)", culture.english_name());
      assert::are_equal(7177_z, culture.keyboard_layout_id());
      assert::are_equal(7177_z, culture.lcid());
      assert::are_equal("en-ZA", culture.name());
      assert::are_equal("English (South Africa)", culture.native_name());
    }
    
    auto test_method_(en_ZM) {
      auto culture = culture_info {"en-ZM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Zambia)", culture.display_name());
      assert::are_equal("English (Zambia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("en-ZM", culture.name());
      assert::are_equal("English (Zambia)", culture.native_name());
    }
    
    auto test_method_(en_ZW) {
      auto culture = culture_info {"en-ZW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("English (Zimbabwe)", culture.display_name());
      assert::are_equal("English (Zimbabwe)", culture.english_name());
      assert::are_equal(12297_z, culture.keyboard_layout_id());
      assert::are_equal(12297_z, culture.lcid());
      assert::are_equal("en-ZW", culture.name());
      assert::are_equal("English (Zimbabwe)", culture.native_name());
    }
    
    auto test_method_(eo) {
      auto culture = culture_info {"eo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Esperanto", culture.display_name());
      assert::are_equal("Esperanto", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("eo", culture.name());
      assert::are_equal("Esperanto", culture.native_name());
    }
    
    auto test_method_(eo_001) {
      auto culture = culture_info {"eo-001"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Esperanto (world)", culture.display_name());
      assert::are_equal("Esperanto (world)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("eo-001", culture.name());
      assert::are_equal("Esperanto (mondo)", culture.native_name());
    }
    
    auto test_method_(es) {
      auto culture = culture_info {"es"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Spanish", culture.display_name());
      assert::are_equal("Spanish", culture.english_name());
      assert::are_equal(10_z, culture.keyboard_layout_id());
      assert::are_equal(10_z, culture.lcid());
      assert::are_equal("es", culture.name());
      assert::are_equal("español", culture.native_name());
    }
    
    auto test_method_(es_003) {
      auto culture = culture_info {"es-003"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (North America)", culture.display_name());
      assert::are_equal("Spanish (North America)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-003", culture.name());
      assert::are_equal("español (América del Norte)", culture.native_name());
    }
    
    auto test_method_(es_419) {
      auto culture = culture_info {"es-419"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Latin America)", culture.display_name());
      assert::are_equal("Spanish (Latin America)", culture.english_name());
      assert::are_equal(22538_z, culture.keyboard_layout_id());
      assert::are_equal(22538_z, culture.lcid());
      assert::are_equal("es-419", culture.name());
      assert::are_equal("español (Latinoamérica)", culture.native_name());
    }
    
    auto test_method_(es_AG) {
      auto culture = culture_info {"es-AG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Antigua & Barbuda)", culture.display_name());
      assert::are_equal("Spanish (Antigua & Barbuda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-AG", culture.name());
      assert::are_equal("español (Antigua y Barbuda)", culture.native_name());
    }
    
    auto test_method_(es_AR) {
      auto culture = culture_info {"es-AR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Argentina)", culture.display_name());
      assert::are_equal("Spanish (Argentina)", culture.english_name());
      assert::are_equal(11274_z, culture.keyboard_layout_id());
      assert::are_equal(11274_z, culture.lcid());
      assert::are_equal("es-AR", culture.name());
      assert::are_equal("español (Argentina)", culture.native_name());
    }
    
    auto test_method_(es_BB) {
      auto culture = culture_info {"es-BB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Barbados)", culture.display_name());
      assert::are_equal("Spanish (Barbados)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-BB", culture.name());
      assert::are_equal("español (Barbados)", culture.native_name());
    }
    
    auto test_method_(es_BM) {
      auto culture = culture_info {"es-BM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Bermuda)", culture.display_name());
      assert::are_equal("Spanish (Bermuda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-BM", culture.name());
      assert::are_equal("español (Bermudas)", culture.native_name());
    }
    
    auto test_method_(es_BO) {
      auto culture = culture_info {"es-BO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Bolivia)", culture.display_name());
      assert::are_equal("Spanish (Bolivia)", culture.english_name());
      assert::are_equal(16394_z, culture.keyboard_layout_id());
      assert::are_equal(16394_z, culture.lcid());
      assert::are_equal("es-BO", culture.name());
      assert::are_equal("español (Bolivia)", culture.native_name());
    }
    
    auto test_method_(es_BQ) {
      auto culture = culture_info {"es-BQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Caribbean Netherlands)", culture.display_name());
      assert::are_equal("Spanish (Caribbean Netherlands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-BQ", culture.name());
      assert::are_equal("español (Caribe neerlandés)", culture.native_name());
    }
    
    auto test_method_(es_BR) {
      auto culture = culture_info {"es-BR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Brazil)", culture.display_name());
      assert::are_equal("Spanish (Brazil)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-BR", culture.name());
      assert::are_equal("español (Brasil)", culture.native_name());
    }
    
    auto test_method_(es_BS) {
      auto culture = culture_info {"es-BS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Bahamas)", culture.display_name());
      assert::are_equal("Spanish (Bahamas)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-BS", culture.name());
      assert::are_equal("español (Bahamas)", culture.native_name());
    }
    
    auto test_method_(es_BZ) {
      auto culture = culture_info {"es-BZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Belize)", culture.display_name());
      assert::are_equal("Spanish (Belize)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-BZ", culture.name());
      assert::are_equal("español (Belice)", culture.native_name());
    }
    
    auto test_method_(es_CA) {
      auto culture = culture_info {"es-CA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Canada)", culture.display_name());
      assert::are_equal("Spanish (Canada)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-CA", culture.name());
      assert::are_equal("español (Canadá)", culture.native_name());
    }
    
    auto test_method_(es_CL) {
      auto culture = culture_info {"es-CL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Chile)", culture.display_name());
      assert::are_equal("Spanish (Chile)", culture.english_name());
      assert::are_equal(13322_z, culture.keyboard_layout_id());
      assert::are_equal(13322_z, culture.lcid());
      assert::are_equal("es-CL", culture.name());
      assert::are_equal("español (Chile)", culture.native_name());
    }
    
    auto test_method_(es_CO) {
      auto culture = culture_info {"es-CO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Colombia)", culture.display_name());
      assert::are_equal("Spanish (Colombia)", culture.english_name());
      assert::are_equal(9226_z, culture.keyboard_layout_id());
      assert::are_equal(9226_z, culture.lcid());
      assert::are_equal("es-CO", culture.name());
      assert::are_equal("español (Colombia)", culture.native_name());
    }
    
    auto test_method_(es_CR) {
      auto culture = culture_info {"es-CR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Costa Rica)", culture.display_name());
      assert::are_equal("Spanish (Costa Rica)", culture.english_name());
      assert::are_equal(5130_z, culture.keyboard_layout_id());
      assert::are_equal(5130_z, culture.lcid());
      assert::are_equal("es-CR", culture.name());
      assert::are_equal("español (Costa Rica)", culture.native_name());
    }
    
    auto test_method_(es_CU) {
      auto culture = culture_info {"es-CU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Cuba)", culture.display_name());
      assert::are_equal("Spanish (Cuba)", culture.english_name());
      assert::are_equal(23562_z, culture.keyboard_layout_id());
      assert::are_equal(23562_z, culture.lcid());
      assert::are_equal("es-CU", culture.name());
      assert::are_equal("español (Cuba)", culture.native_name());
    }
    
    auto test_method_(es_CW) {
      auto culture = culture_info {"es-CW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Curaçao)", culture.display_name());
      assert::are_equal("Spanish (Curaçao)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-CW", culture.name());
      assert::are_equal("español (Curazao)", culture.native_name());
    }
    
    auto test_method_(es_DM) {
      auto culture = culture_info {"es-DM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Dominica)", culture.display_name());
      assert::are_equal("Spanish (Dominica)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-DM", culture.name());
      assert::are_equal("español (Dominica)", culture.native_name());
    }
    
    auto test_method_(es_DO) {
      auto culture = culture_info {"es-DO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Dominican Republic)", culture.display_name());
      assert::are_equal("Spanish (Dominican Republic)", culture.english_name());
      assert::are_equal(7178_z, culture.keyboard_layout_id());
      assert::are_equal(7178_z, culture.lcid());
      assert::are_equal("es-DO", culture.name());
      assert::are_equal("español (República Dominicana)", culture.native_name());
    }
    
    auto test_method_(es_EA) {
      auto culture = culture_info {"es-EA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Ceuta & Melilla)", culture.display_name());
      assert::are_equal("Spanish (Ceuta & Melilla)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-EA", culture.name());
      assert::are_equal("español (Ceuta y Melilla)", culture.native_name());
    }
    
    auto test_method_(es_EC) {
      auto culture = culture_info {"es-EC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Ecuador)", culture.display_name());
      assert::are_equal("Spanish (Ecuador)", culture.english_name());
      assert::are_equal(12298_z, culture.keyboard_layout_id());
      assert::are_equal(12298_z, culture.lcid());
      assert::are_equal("es-EC", culture.name());
      assert::are_equal("español (Ecuador)", culture.native_name());
    }
    
    auto test_method_(es_ES) {
      auto culture = culture_info {"es-ES"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Spain)", culture.display_name());
      assert::are_equal("Spanish (Spain)", culture.english_name());
      assert::are_equal(3082_z, culture.keyboard_layout_id());
      assert::are_equal(3082_z, culture.lcid());
      assert::are_equal("es-ES", culture.name());
      assert::are_equal("español (España)", culture.native_name());
    }
    
    auto test_method_(es_GD) {
      auto culture = culture_info {"es-GD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Grenada)", culture.display_name());
      assert::are_equal("Spanish (Grenada)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-GD", culture.name());
      assert::are_equal("español (Granada)", culture.native_name());
    }
    
    auto test_method_(es_GQ) {
      auto culture = culture_info {"es-GQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Equatorial Guinea)", culture.display_name());
      assert::are_equal("Spanish (Equatorial Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-GQ", culture.name());
      assert::are_equal("español (Guinea Ecuatorial)", culture.native_name());
    }
    
    auto test_method_(es_GT) {
      auto culture = culture_info {"es-GT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Guatemala)", culture.display_name());
      assert::are_equal("Spanish (Guatemala)", culture.english_name());
      assert::are_equal(4106_z, culture.keyboard_layout_id());
      assert::are_equal(4106_z, culture.lcid());
      assert::are_equal("es-GT", culture.name());
      assert::are_equal("español (Guatemala)", culture.native_name());
    }
    
    auto test_method_(es_GY) {
      auto culture = culture_info {"es-GY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Guyana)", culture.display_name());
      assert::are_equal("Spanish (Guyana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-GY", culture.name());
      assert::are_equal("español (Guyana)", culture.native_name());
    }
    
    auto test_method_(es_HN) {
      auto culture = culture_info {"es-HN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Honduras)", culture.display_name());
      assert::are_equal("Spanish (Honduras)", culture.english_name());
      assert::are_equal(18442_z, culture.keyboard_layout_id());
      assert::are_equal(18442_z, culture.lcid());
      assert::are_equal("es-HN", culture.name());
      assert::are_equal("español (Honduras)", culture.native_name());
    }
    
    auto test_method_(es_HT) {
      auto culture = culture_info {"es-HT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Haiti)", culture.display_name());
      assert::are_equal("Spanish (Haiti)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-HT", culture.name());
      assert::are_equal("español (Haití)", culture.native_name());
    }
    
    auto test_method_(es_IC) {
      auto culture = culture_info {"es-IC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Canary Islands)", culture.display_name());
      assert::are_equal("Spanish (Canary Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-IC", culture.name());
      assert::are_equal("español (Canarias)", culture.native_name());
    }
    
    auto test_method_(es_KN) {
      auto culture = culture_info {"es-KN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (St Kitts & Nevis)", culture.display_name());
      assert::are_equal("Spanish (St. Kitts & Nevis)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-KN", culture.name());
      assert::are_equal("español (San Cristóbal y Nieves)", culture.native_name());
    }
    
    auto test_method_(es_KY) {
      auto culture = culture_info {"es-KY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Cayman Islands)", culture.display_name());
      assert::are_equal("Spanish (Cayman Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-KY", culture.name());
      assert::are_equal("español (Islas Caimán)", culture.native_name());
    }
    
    auto test_method_(es_LC) {
      auto culture = culture_info {"es-LC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (St Lucia)", culture.display_name());
      assert::are_equal("Spanish (St. Lucia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-LC", culture.name());
      assert::are_equal("español (Santa Lucía)", culture.native_name());
    }
    
    auto test_method_(es_MX) {
      auto culture = culture_info {"es-MX"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Mexico)", culture.display_name());
      assert::are_equal("Spanish (Mexico)", culture.english_name());
      assert::are_equal(2058_z, culture.keyboard_layout_id());
      assert::are_equal(2058_z, culture.lcid());
      assert::are_equal("es-MX", culture.name());
      assert::are_equal("español (México)", culture.native_name());
    }
    
    auto test_method_(es_NI) {
      auto culture = culture_info {"es-NI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Nicaragua)", culture.display_name());
      assert::are_equal("Spanish (Nicaragua)", culture.english_name());
      assert::are_equal(19466_z, culture.keyboard_layout_id());
      assert::are_equal(19466_z, culture.lcid());
      assert::are_equal("es-NI", culture.name());
      assert::are_equal("español (Nicaragua)", culture.native_name());
    }
    
    auto test_method_(es_PA) {
      auto culture = culture_info {"es-PA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Panama)", culture.display_name());
      assert::are_equal("Spanish (Panama)", culture.english_name());
      assert::are_equal(6154_z, culture.keyboard_layout_id());
      assert::are_equal(6154_z, culture.lcid());
      assert::are_equal("es-PA", culture.name());
      assert::are_equal("español (Panamá)", culture.native_name());
    }
    
    auto test_method_(es_PE) {
      auto culture = culture_info {"es-PE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Peru)", culture.display_name());
      assert::are_equal("Spanish (Peru)", culture.english_name());
      assert::are_equal(10250_z, culture.keyboard_layout_id());
      assert::are_equal(10250_z, culture.lcid());
      assert::are_equal("es-PE", culture.name());
      assert::are_equal("español (Perú)", culture.native_name());
    }
    
    auto test_method_(es_PH) {
      auto culture = culture_info {"es-PH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Philippines)", culture.display_name());
      assert::are_equal("Spanish (Philippines)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-PH", culture.name());
      assert::are_equal("español (Filipinas)", culture.native_name());
    }
    
    auto test_method_(es_PR) {
      auto culture = culture_info {"es-PR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Puerto Rico)", culture.display_name());
      assert::are_equal("Spanish (Puerto Rico)", culture.english_name());
      assert::are_equal(20490_z, culture.keyboard_layout_id());
      assert::are_equal(20490_z, culture.lcid());
      assert::are_equal("es-PR", culture.name());
      assert::are_equal("español (Puerto Rico)", culture.native_name());
    }
    
    auto test_method_(es_PY) {
      auto culture = culture_info {"es-PY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Paraguay)", culture.display_name());
      assert::are_equal("Spanish (Paraguay)", culture.english_name());
      assert::are_equal(15370_z, culture.keyboard_layout_id());
      assert::are_equal(15370_z, culture.lcid());
      assert::are_equal("es-PY", culture.name());
      assert::are_equal("español (Paraguay)", culture.native_name());
    }
    
    auto test_method_(es_SV) {
      auto culture = culture_info {"es-SV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (El Salvador)", culture.display_name());
      assert::are_equal("Spanish (El Salvador)", culture.english_name());
      assert::are_equal(17418_z, culture.keyboard_layout_id());
      assert::are_equal(17418_z, culture.lcid());
      assert::are_equal("es-SV", culture.name());
      assert::are_equal("español (El Salvador)", culture.native_name());
    }
    
    auto test_method_(es_TC) {
      auto culture = culture_info {"es-TC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Turks & Caicos Islands)", culture.display_name());
      assert::are_equal("Spanish (Turks & Caicos Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-TC", culture.name());
      assert::are_equal("español (Islas Turcas y Caicos)", culture.native_name());
    }
    
    auto test_method_(es_TT) {
      auto culture = culture_info {"es-TT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Trinidad & Tobago)", culture.display_name());
      assert::are_equal("Spanish (Trinidad & Tobago)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-TT", culture.name());
      assert::are_equal("español (Trinidad y Tobago)", culture.native_name());
    }
    
    auto test_method_(es_US) {
      auto culture = culture_info {"es-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (United States)", culture.display_name());
      assert::are_equal("Spanish (United States)", culture.english_name());
      assert::are_equal(21514_z, culture.keyboard_layout_id());
      assert::are_equal(21514_z, culture.lcid());
      assert::are_equal("es-US", culture.name());
      assert::are_equal("español (Estados Unidos)", culture.native_name());
    }
    
    auto test_method_(es_UY) {
      auto culture = culture_info {"es-UY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Uruguay)", culture.display_name());
      assert::are_equal("Spanish (Uruguay)", culture.english_name());
      assert::are_equal(14346_z, culture.keyboard_layout_id());
      assert::are_equal(14346_z, culture.lcid());
      assert::are_equal("es-UY", culture.name());
      assert::are_equal("español (Uruguay)", culture.native_name());
    }
    
    auto test_method_(es_VC) {
      auto culture = culture_info {"es-VC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (St Vincent & the Grenadines)", culture.display_name());
      assert::are_equal("Spanish (St. Vincent & Grenadines)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-VC", culture.name());
      assert::are_equal("español (San Vicente y las Granadinas)", culture.native_name());
    }
    
    auto test_method_(es_VE) {
      auto culture = culture_info {"es-VE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (Venezuela)", culture.display_name());
      assert::are_equal("Spanish (Venezuela)", culture.english_name());
      assert::are_equal(8202_z, culture.keyboard_layout_id());
      assert::are_equal(8202_z, culture.lcid());
      assert::are_equal("es-VE", culture.name());
      assert::are_equal("español (Venezuela)", culture.native_name());
    }
    
    auto test_method_(es_VG) {
      auto culture = culture_info {"es-VG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (British Virgin Islands)", culture.display_name());
      assert::are_equal("Spanish (British Virgin Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-VG", culture.name());
      assert::are_equal("español (Islas Vírgenes Británicas)", culture.native_name());
    }
    
    auto test_method_(es_VI) {
      auto culture = culture_info {"es-VI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Spanish (US Virgin Islands)", culture.display_name());
      assert::are_equal("Spanish (U.S. Virgin Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("es-VI", culture.name());
      assert::are_equal("español (Islas Vírgenes de EE. UU.)", culture.native_name());
    }
    
    auto test_method_(et) {
      auto culture = culture_info {"et"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Estonian", culture.display_name());
      assert::are_equal("Estonian", culture.english_name());
      assert::are_equal(37_z, culture.keyboard_layout_id());
      assert::are_equal(37_z, culture.lcid());
      assert::are_equal("et", culture.name());
      assert::are_equal("eesti", culture.native_name());
    }
    
    auto test_method_(et_EE) {
      auto culture = culture_info {"et-EE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Estonian (Estonia)", culture.display_name());
      assert::are_equal("Estonian (Estonia)", culture.english_name());
      assert::are_equal(1061_z, culture.keyboard_layout_id());
      assert::are_equal(1061_z, culture.lcid());
      assert::are_equal("et-EE", culture.name());
      assert::are_equal("eesti (Eesti)", culture.native_name());
    }
    
    auto test_method_(eu) {
      auto culture = culture_info {"eu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Basque", culture.display_name());
      assert::are_equal("Basque", culture.english_name());
      assert::are_equal(45_z, culture.keyboard_layout_id());
      assert::are_equal(45_z, culture.lcid());
      assert::are_equal("eu", culture.name());
      assert::are_equal("euskara", culture.native_name());
    }
    
    auto test_method_(eu_ES) {
      auto culture = culture_info {"eu-ES"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Basque (Spain)", culture.display_name());
      assert::are_equal("Basque (Spain)", culture.english_name());
      assert::are_equal(1069_z, culture.keyboard_layout_id());
      assert::are_equal(1069_z, culture.lcid());
      assert::are_equal("eu-ES", culture.name());
      assert::are_equal("euskara (Espainia)", culture.native_name());
    }
    
    auto test_method_(ewo) {
      auto culture = culture_info {"ewo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ewondo", culture.display_name());
      assert::are_equal("Ewondo", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ewo", culture.name());
      assert::are_equal("ewondo", culture.native_name());
    }
    
    auto test_method_(ewo_CM) {
      auto culture = culture_info {"ewo-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ewondo (Cameroon)", culture.display_name());
      assert::are_equal("Ewondo (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ewo-CM", culture.name());
      assert::are_equal("ewondo (Kamərún)", culture.native_name());
    }
    
    auto test_method_(fa) {
      auto culture = culture_info {"fa"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Persian", culture.display_name());
      assert::are_equal("Persian", culture.english_name());
      assert::are_equal(41_z, culture.keyboard_layout_id());
      assert::are_equal(41_z, culture.lcid());
      assert::are_equal("fa", culture.name());
      assert::are_equal("فارسی", culture.native_name());
    }
    
    auto test_method_(fa_AF) {
      auto culture = culture_info {"fa-AF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Persian (Afghanistan)", culture.display_name());
      assert::are_equal("Persian (Afghanistan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fa-AF", culture.name());
      assert::are_equal("فارسی (افغانستان)", culture.native_name());
    }
    
    auto test_method_(fa_IR) {
      auto culture = culture_info {"fa-IR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Persian (Iran)", culture.display_name());
      assert::are_equal("Persian (Iran)", culture.english_name());
      assert::are_equal(1065_z, culture.keyboard_layout_id());
      assert::are_equal(1065_z, culture.lcid());
      assert::are_equal("fa-IR", culture.name());
      assert::are_equal("فارسی (ایران)", culture.native_name());
    }
    
    auto test_method_(ff) {
      auto culture = culture_info {"ff"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Fula", culture.display_name());
      assert::are_equal("Fula", culture.english_name());
      assert::are_equal(103_z, culture.keyboard_layout_id());
      assert::are_equal(103_z, culture.lcid());
      assert::are_equal("ff", culture.name());
      assert::are_equal("Pulaar", culture.native_name());
    }
    
    auto test_method_(ff_Adlm) {
      auto culture = culture_info {"ff-Adlm"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam)", culture.display_name());
      assert::are_equal("Fula (Adlam)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_BF) {
      auto culture = culture_info {"ff-Adlm-BF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Burkina Faso)", culture.display_name());
      assert::are_equal("Fula (Adlam, Burkina Faso)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-BF", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤄𞤵𞤪𞤳𞤭𞤲𞤢 𞤊𞤢𞤧𞤮𞥅)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_CM) {
      auto culture = culture_info {"ff-Adlm-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Cameroon)", culture.display_name());
      assert::are_equal("Fula (Adlam, Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-CM", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤑𞤢𞤥𞤢𞤪𞤵𞥅𞤲)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_GH) {
      auto culture = culture_info {"ff-Adlm-GH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Ghana)", culture.display_name());
      assert::are_equal("Fula (Adlam, Ghana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-GH", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤘𞤢𞤲𞤢)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_GM) {
      auto culture = culture_info {"ff-Adlm-GM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Gambia)", culture.display_name());
      assert::are_equal("Fula (Adlam, Gambia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-GM", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤘𞤢𞤥𞤦𞤭𞤴𞤢)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_GN) {
      auto culture = culture_info {"ff-Adlm-GN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Guinea)", culture.display_name());
      assert::are_equal("Fula (Adlam, Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-GN", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤘𞤭𞤲𞤫)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_GW) {
      auto culture = culture_info {"ff-Adlm-GW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Guinea-Bissau)", culture.display_name());
      assert::are_equal("Fula (Adlam, Guinea-Bissau)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-GW", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤘𞤭𞤲𞤫-𞤄𞤭𞤧𞤢𞤱𞤮𞥅)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_LR) {
      auto culture = culture_info {"ff-Adlm-LR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Liberia)", culture.display_name());
      assert::are_equal("Fula (Adlam, Liberia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-LR", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤂𞤢𞤦𞤭𞤪𞤭𞤴𞤢𞥄)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_MR) {
      auto culture = culture_info {"ff-Adlm-MR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Mauritania)", culture.display_name());
      assert::are_equal("Fula (Adlam, Mauritania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-MR", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤃𞤮𞤪𞤼𞤢𞤲𞤭𞥅)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_NE) {
      auto culture = culture_info {"ff-Adlm-NE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Niger)", culture.display_name());
      assert::are_equal("Fula (Adlam, Niger)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-NE", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤐𞤭𞥅𞤶𞤫𞤪)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_NG) {
      auto culture = culture_info {"ff-Adlm-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Nigeria)", culture.display_name());
      assert::are_equal("Fula (Adlam, Nigeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-NG", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤐𞤢𞤶𞤫𞤪𞤭𞤴𞤢𞥄)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_SL) {
      auto culture = culture_info {"ff-Adlm-SL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Sierra Leone)", culture.display_name());
      assert::are_equal("Fula (Adlam, Sierra Leone)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-SL", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤅𞤢𞤪𞤢𞤤𞤮𞤲)", culture.native_name());
    }
    
    auto test_method_(ff_Adlm_SN) {
      auto culture = culture_info {"ff-Adlm-SN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Adlam, Senegal)", culture.display_name());
      assert::are_equal("Fula (Adlam, Senegal)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Adlm-SN", culture.name());
      assert::are_equal("𞤆𞤵𞤤𞤢𞤪 (𞤀𞤁𞤂𞤢𞤃⹁ 𞤅𞤫𞤲𞤫𞤺𞤢𞥄𞤤)", culture.native_name());
    }
    
    auto test_method_(ff_Latn) {
      auto culture = culture_info {"ff-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin)", culture.display_name());
      assert::are_equal("Fula (Latin)", culture.english_name());
      assert::are_equal(31847_z, culture.keyboard_layout_id());
      assert::are_equal(31847_z, culture.lcid());
      assert::are_equal("ff-Latn", culture.name());
      assert::are_equal("Fula (Latin)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_BF) {
      auto culture = culture_info {"ff-Latn-BF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Burkina Faso)", culture.display_name());
      assert::are_equal("Fula (Latin, Burkina Faso)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-BF", culture.name());
      assert::are_equal("Fula (Latin, Burkina Faso)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_CM) {
      auto culture = culture_info {"ff-Latn-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Cameroon)", culture.display_name());
      assert::are_equal("Fula (Latin, Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-CM", culture.name());
      assert::are_equal("Fula (Latin, Cameroon)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_GH) {
      auto culture = culture_info {"ff-Latn-GH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Ghana)", culture.display_name());
      assert::are_equal("Fula (Latin, Ghana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-GH", culture.name());
      assert::are_equal("Fula (Latin, Ghana)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_GM) {
      auto culture = culture_info {"ff-Latn-GM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Gambia)", culture.display_name());
      assert::are_equal("Fula (Latin, Gambia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-GM", culture.name());
      assert::are_equal("Fula (Latin, Gambia)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_GN) {
      auto culture = culture_info {"ff-Latn-GN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Guinea)", culture.display_name());
      assert::are_equal("Fula (Latin, Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-GN", culture.name());
      assert::are_equal("Fula (Latin, Guinea)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_GW) {
      auto culture = culture_info {"ff-Latn-GW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Guinea-Bissau)", culture.display_name());
      assert::are_equal("Fula (Latin, Guinea-Bissau)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-GW", culture.name());
      assert::are_equal("Fula (Latin, Guinea-Bissau)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_LR) {
      auto culture = culture_info {"ff-Latn-LR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Liberia)", culture.display_name());
      assert::are_equal("Fula (Latin, Liberia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-LR", culture.name());
      assert::are_equal("Fula (Latin, Liberia)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_MR) {
      auto culture = culture_info {"ff-Latn-MR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Mauritania)", culture.display_name());
      assert::are_equal("Fula (Latin, Mauritania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-MR", culture.name());
      assert::are_equal("Fula (Latin, Mauritania)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_NE) {
      auto culture = culture_info {"ff-Latn-NE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Niger)", culture.display_name());
      assert::are_equal("Fula (Latin, Niger)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-NE", culture.name());
      assert::are_equal("Fula (Latin, Niger)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_NG) {
      auto culture = culture_info {"ff-Latn-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Nigeria)", culture.display_name());
      assert::are_equal("Fula (Latin, Nigeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-NG", culture.name());
      assert::are_equal("Fula (Latin, Nigeria)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_SL) {
      auto culture = culture_info {"ff-Latn-SL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Sierra Leone)", culture.display_name());
      assert::are_equal("Fula (Latin, Sierra Leone)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ff-Latn-SL", culture.name());
      assert::are_equal("Fula (Latin, Sierra Leone)", culture.native_name());
    }
    
    auto test_method_(ff_Latn_SN) {
      auto culture = culture_info {"ff-Latn-SN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Fula (Latin, Senegal)", culture.display_name());
      assert::are_equal("Fula (Latin, Senegal)", culture.english_name());
      assert::are_equal(2151_z, culture.keyboard_layout_id());
      assert::are_equal(2151_z, culture.lcid());
      assert::are_equal("ff-Latn-SN", culture.name());
      assert::are_equal("Fula (Latin, Senegal)", culture.native_name());
    }
    
    auto test_method_(fi) {
      auto culture = culture_info {"fi"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Finnish", culture.display_name());
      assert::are_equal("Finnish", culture.english_name());
      assert::are_equal(11_z, culture.keyboard_layout_id());
      assert::are_equal(11_z, culture.lcid());
      assert::are_equal("fi", culture.name());
      assert::are_equal("suomi", culture.native_name());
    }
    
    auto test_method_(fi_FI) {
      auto culture = culture_info {"fi-FI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Finnish (Finland)", culture.display_name());
      assert::are_equal("Finnish (Finland)", culture.english_name());
      assert::are_equal(1035_z, culture.keyboard_layout_id());
      assert::are_equal(1035_z, culture.lcid());
      assert::are_equal("fi-FI", culture.name());
      assert::are_equal("suomi (Suomi)", culture.native_name());
    }
    
    auto test_method_(fil) {
      auto culture = culture_info {"fil"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Filipino", culture.display_name());
      assert::are_equal("Filipino", culture.english_name());
      assert::are_equal(100_z, culture.keyboard_layout_id());
      assert::are_equal(100_z, culture.lcid());
      assert::are_equal("fil", culture.name());
      assert::are_equal("Filipino", culture.native_name());
    }
    
    auto test_method_(fil_PH) {
      auto culture = culture_info {"fil-PH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Filipino (Philippines)", culture.display_name());
      assert::are_equal("Filipino (Philippines)", culture.english_name());
      assert::are_equal(1124_z, culture.keyboard_layout_id());
      assert::are_equal(1124_z, culture.lcid());
      assert::are_equal("fil-PH", culture.name());
      assert::are_equal("Filipino (Pilipinas)", culture.native_name());
    }
    
    auto test_method_(fo) {
      auto culture = culture_info {"fo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Faroese", culture.display_name());
      assert::are_equal("Faroese", culture.english_name());
      assert::are_equal(56_z, culture.keyboard_layout_id());
      assert::are_equal(56_z, culture.lcid());
      assert::are_equal("fo", culture.name());
      assert::are_equal("føroyskt", culture.native_name());
    }
    
    auto test_method_(fo_DK) {
      auto culture = culture_info {"fo-DK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Faroese (Denmark)", culture.display_name());
      assert::are_equal("Faroese (Denmark)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fo-DK", culture.name());
      assert::are_equal("føroyskt (Danmark)", culture.native_name());
    }
    
    auto test_method_(fo_FO) {
      auto culture = culture_info {"fo-FO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Faroese (Faroe Islands)", culture.display_name());
      assert::are_equal("Faroese (Faroe Islands)", culture.english_name());
      assert::are_equal(1080_z, culture.keyboard_layout_id());
      assert::are_equal(1080_z, culture.lcid());
      assert::are_equal("fo-FO", culture.name());
      assert::are_equal("føroyskt (Føroyar)", culture.native_name());
    }
    
    auto test_method_(fr) {
      auto culture = culture_info {"fr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("French", culture.display_name());
      assert::are_equal("French", culture.english_name());
      assert::are_equal(12_z, culture.keyboard_layout_id());
      assert::are_equal(12_z, culture.lcid());
      assert::are_equal("fr", culture.name());
      assert::are_equal("français", culture.native_name());
    }
    
    auto test_method_(fr_BE) {
      auto culture = culture_info {"fr-BE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Belgium)", culture.display_name());
      assert::are_equal("French (Belgium)", culture.english_name());
      assert::are_equal(2060_z, culture.keyboard_layout_id());
      assert::are_equal(2060_z, culture.lcid());
      assert::are_equal("fr-BE", culture.name());
      assert::are_equal("français (Belgique)", culture.native_name());
    }
    
    auto test_method_(fr_BF) {
      auto culture = culture_info {"fr-BF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Burkina Faso)", culture.display_name());
      assert::are_equal("French (Burkina Faso)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-BF", culture.name());
      assert::are_equal("français (Burkina Faso)", culture.native_name());
    }
    
    auto test_method_(fr_BI) {
      auto culture = culture_info {"fr-BI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Burundi)", culture.display_name());
      assert::are_equal("French (Burundi)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-BI", culture.name());
      assert::are_equal("français (Burundi)", culture.native_name());
    }
    
    auto test_method_(fr_BJ) {
      auto culture = culture_info {"fr-BJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Benin)", culture.display_name());
      assert::are_equal("French (Benin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-BJ", culture.name());
      assert::are_equal("français (Bénin)", culture.native_name());
    }
    
    auto test_method_(fr_BL) {
      auto culture = culture_info {"fr-BL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (St Barthélemy)", culture.display_name());
      assert::are_equal("French (St. Barthélemy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-BL", culture.name());
      assert::are_equal("français (Saint-Barthélemy)", culture.native_name());
    }
    
    auto test_method_(fr_CA) {
      auto culture = culture_info {"fr-CA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Canada)", culture.display_name());
      assert::are_equal("French (Canada)", culture.english_name());
      assert::are_equal(3084_z, culture.keyboard_layout_id());
      assert::are_equal(3084_z, culture.lcid());
      assert::are_equal("fr-CA", culture.name());
      assert::are_equal("français (Canada)", culture.native_name());
    }
    
    auto test_method_(fr_CD) {
      auto culture = culture_info {"fr-CD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Congo - Kinshasa)", culture.display_name());
      assert::are_equal("French (Congo - Kinshasa)", culture.english_name());
      assert::are_equal(9228_z, culture.keyboard_layout_id());
      assert::are_equal(9228_z, culture.lcid());
      assert::are_equal("fr-CD", culture.name());
      assert::are_equal("français (Congo-Kinshasa)", culture.native_name());
    }
    
    auto test_method_(fr_CF) {
      auto culture = culture_info {"fr-CF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Central African Republic)", culture.display_name());
      assert::are_equal("French (Central African Republic)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-CF", culture.name());
      assert::are_equal("français (République centrafricaine)", culture.native_name());
    }
    
    auto test_method_(fr_CG) {
      auto culture = culture_info {"fr-CG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Congo - Brazzaville)", culture.display_name());
      assert::are_equal("French (Congo - Brazzaville)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-CG", culture.name());
      assert::are_equal("français (Congo-Brazzaville)", culture.native_name());
    }
    
    auto test_method_(fr_CH) {
      auto culture = culture_info {"fr-CH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Switzerland)", culture.display_name());
      assert::are_equal("French (Switzerland)", culture.english_name());
      assert::are_equal(4108_z, culture.keyboard_layout_id());
      assert::are_equal(4108_z, culture.lcid());
      assert::are_equal("fr-CH", culture.name());
      assert::are_equal("français (Suisse)", culture.native_name());
    }
    
    auto test_method_(fr_CI) {
      auto culture = culture_info {"fr-CI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Côte d’Ivoire)", culture.display_name());
      assert::are_equal("French (Côte d’Ivoire)", culture.english_name());
      assert::are_equal(12300_z, culture.keyboard_layout_id());
      assert::are_equal(12300_z, culture.lcid());
      assert::are_equal("fr-CI", culture.name());
      assert::are_equal("français (Côte d’Ivoire)", culture.native_name());
    }
    
    auto test_method_(fr_CM) {
      auto culture = culture_info {"fr-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Cameroon)", culture.display_name());
      assert::are_equal("French (Cameroon)", culture.english_name());
      assert::are_equal(11276_z, culture.keyboard_layout_id());
      assert::are_equal(11276_z, culture.lcid());
      assert::are_equal("fr-CM", culture.name());
      assert::are_equal("français (Cameroun)", culture.native_name());
    }
    
    auto test_method_(fr_DJ) {
      auto culture = culture_info {"fr-DJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Djibouti)", culture.display_name());
      assert::are_equal("French (Djibouti)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-DJ", culture.name());
      assert::are_equal("français (Djibouti)", culture.native_name());
    }
    
    auto test_method_(fr_DZ) {
      auto culture = culture_info {"fr-DZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Algeria)", culture.display_name());
      assert::are_equal("French (Algeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-DZ", culture.name());
      assert::are_equal("français (Algérie)", culture.native_name());
    }
    
    auto test_method_(fr_FR) {
      auto culture = culture_info {"fr-FR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (France)", culture.display_name());
      assert::are_equal("French (France)", culture.english_name());
      assert::are_equal(1036_z, culture.keyboard_layout_id());
      assert::are_equal(1036_z, culture.lcid());
      assert::are_equal("fr-FR", culture.name());
      assert::are_equal("français (France)", culture.native_name());
    }
    
    auto test_method_(fr_GA) {
      auto culture = culture_info {"fr-GA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Gabon)", culture.display_name());
      assert::are_equal("French (Gabon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-GA", culture.name());
      assert::are_equal("français (Gabon)", culture.native_name());
    }
    
    auto test_method_(fr_GF) {
      auto culture = culture_info {"fr-GF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (French Guiana)", culture.display_name());
      assert::are_equal("French (French Guiana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-GF", culture.name());
      assert::are_equal("français (Guyane française)", culture.native_name());
    }
    
    auto test_method_(fr_GN) {
      auto culture = culture_info {"fr-GN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Guinea)", culture.display_name());
      assert::are_equal("French (Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-GN", culture.name());
      assert::are_equal("français (Guinée)", culture.native_name());
    }
    
    auto test_method_(fr_GP) {
      auto culture = culture_info {"fr-GP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Guadeloupe)", culture.display_name());
      assert::are_equal("French (Guadeloupe)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-GP", culture.name());
      assert::are_equal("français (Guadeloupe)", culture.native_name());
    }
    
    auto test_method_(fr_GQ) {
      auto culture = culture_info {"fr-GQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Equatorial Guinea)", culture.display_name());
      assert::are_equal("French (Equatorial Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-GQ", culture.name());
      assert::are_equal("français (Guinée équatoriale)", culture.native_name());
    }
    
    auto test_method_(fr_HT) {
      auto culture = culture_info {"fr-HT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Haiti)", culture.display_name());
      assert::are_equal("French (Haiti)", culture.english_name());
      assert::are_equal(15372_z, culture.keyboard_layout_id());
      assert::are_equal(15372_z, culture.lcid());
      assert::are_equal("fr-HT", culture.name());
      assert::are_equal("français (Haïti)", culture.native_name());
    }
    
    auto test_method_(fr_KM) {
      auto culture = culture_info {"fr-KM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Comoros)", culture.display_name());
      assert::are_equal("French (Comoros)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-KM", culture.name());
      assert::are_equal("français (Comores)", culture.native_name());
    }
    
    auto test_method_(fr_LU) {
      auto culture = culture_info {"fr-LU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Luxembourg)", culture.display_name());
      assert::are_equal("French (Luxembourg)", culture.english_name());
      assert::are_equal(5132_z, culture.keyboard_layout_id());
      assert::are_equal(5132_z, culture.lcid());
      assert::are_equal("fr-LU", culture.name());
      assert::are_equal("français (Luxembourg)", culture.native_name());
    }
    
    auto test_method_(fr_MA) {
      auto culture = culture_info {"fr-MA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Morocco)", culture.display_name());
      assert::are_equal("French (Morocco)", culture.english_name());
      assert::are_equal(14348_z, culture.keyboard_layout_id());
      assert::are_equal(14348_z, culture.lcid());
      assert::are_equal("fr-MA", culture.name());
      assert::are_equal("français (Maroc)", culture.native_name());
    }
    
    auto test_method_(fr_MC) {
      auto culture = culture_info {"fr-MC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Monaco)", culture.display_name());
      assert::are_equal("French (Monaco)", culture.english_name());
      assert::are_equal(6156_z, culture.keyboard_layout_id());
      assert::are_equal(6156_z, culture.lcid());
      assert::are_equal("fr-MC", culture.name());
      assert::are_equal("français (Monaco)", culture.native_name());
    }
    
    auto test_method_(fr_MF) {
      auto culture = culture_info {"fr-MF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (St Martin)", culture.display_name());
      assert::are_equal("French (St. Martin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-MF", culture.name());
      assert::are_equal("français (Saint-Martin)", culture.native_name());
    }
    
    auto test_method_(fr_MG) {
      auto culture = culture_info {"fr-MG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Madagascar)", culture.display_name());
      assert::are_equal("French (Madagascar)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-MG", culture.name());
      assert::are_equal("français (Madagascar)", culture.native_name());
    }
    
    auto test_method_(fr_ML) {
      auto culture = culture_info {"fr-ML"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Mali)", culture.display_name());
      assert::are_equal("French (Mali)", culture.english_name());
      assert::are_equal(13324_z, culture.keyboard_layout_id());
      assert::are_equal(13324_z, culture.lcid());
      assert::are_equal("fr-ML", culture.name());
      assert::are_equal("français (Mali)", culture.native_name());
    }
    
    auto test_method_(fr_MQ) {
      auto culture = culture_info {"fr-MQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Martinique)", culture.display_name());
      assert::are_equal("French (Martinique)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-MQ", culture.name());
      assert::are_equal("français (Martinique)", culture.native_name());
    }
    
    auto test_method_(fr_MR) {
      auto culture = culture_info {"fr-MR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Mauritania)", culture.display_name());
      assert::are_equal("French (Mauritania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-MR", culture.name());
      assert::are_equal("français (Mauritanie)", culture.native_name());
    }
    
    auto test_method_(fr_MU) {
      auto culture = culture_info {"fr-MU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Mauritius)", culture.display_name());
      assert::are_equal("French (Mauritius)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-MU", culture.name());
      assert::are_equal("français (Maurice)", culture.native_name());
    }
    
    auto test_method_(fr_NC) {
      auto culture = culture_info {"fr-NC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (New Caledonia)", culture.display_name());
      assert::are_equal("French (New Caledonia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-NC", culture.name());
      assert::are_equal("français (Nouvelle-Calédonie)", culture.native_name());
    }
    
    auto test_method_(fr_NE) {
      auto culture = culture_info {"fr-NE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Niger)", culture.display_name());
      assert::are_equal("French (Niger)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-NE", culture.name());
      assert::are_equal("français (Niger)", culture.native_name());
    }
    
    auto test_method_(fr_PF) {
      auto culture = culture_info {"fr-PF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (French Polynesia)", culture.display_name());
      assert::are_equal("French (French Polynesia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-PF", culture.name());
      assert::are_equal("français (Polynésie française)", culture.native_name());
    }
    
    auto test_method_(fr_PM) {
      auto culture = culture_info {"fr-PM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (St Pierre & Miquelon)", culture.display_name());
      assert::are_equal("French (St. Pierre & Miquelon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-PM", culture.name());
      assert::are_equal("français (Saint-Pierre-et-Miquelon)", culture.native_name());
    }
    
    auto test_method_(fr_RE) {
      auto culture = culture_info {"fr-RE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Réunion)", culture.display_name());
      assert::are_equal("French (Réunion)", culture.english_name());
      assert::are_equal(8204_z, culture.keyboard_layout_id());
      assert::are_equal(8204_z, culture.lcid());
      assert::are_equal("fr-RE", culture.name());
      assert::are_equal("français (La Réunion)", culture.native_name());
    }
    
    auto test_method_(fr_RW) {
      auto culture = culture_info {"fr-RW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Rwanda)", culture.display_name());
      assert::are_equal("French (Rwanda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-RW", culture.name());
      assert::are_equal("français (Rwanda)", culture.native_name());
    }
    
    auto test_method_(fr_SC) {
      auto culture = culture_info {"fr-SC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Seychelles)", culture.display_name());
      assert::are_equal("French (Seychelles)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-SC", culture.name());
      assert::are_equal("français (Seychelles)", culture.native_name());
    }
    
    auto test_method_(fr_SN) {
      auto culture = culture_info {"fr-SN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Senegal)", culture.display_name());
      assert::are_equal("French (Senegal)", culture.english_name());
      assert::are_equal(10252_z, culture.keyboard_layout_id());
      assert::are_equal(10252_z, culture.lcid());
      assert::are_equal("fr-SN", culture.name());
      assert::are_equal("français (Sénégal)", culture.native_name());
    }
    
    auto test_method_(fr_SY) {
      auto culture = culture_info {"fr-SY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Syria)", culture.display_name());
      assert::are_equal("French (Syria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-SY", culture.name());
      assert::are_equal("français (Syrie)", culture.native_name());
    }
    
    auto test_method_(fr_TD) {
      auto culture = culture_info {"fr-TD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Chad)", culture.display_name());
      assert::are_equal("French (Chad)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-TD", culture.name());
      assert::are_equal("français (Tchad)", culture.native_name());
    }
    
    auto test_method_(fr_TG) {
      auto culture = culture_info {"fr-TG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Togo)", culture.display_name());
      assert::are_equal("French (Togo)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-TG", culture.name());
      assert::are_equal("français (Togo)", culture.native_name());
    }
    
    auto test_method_(fr_TN) {
      auto culture = culture_info {"fr-TN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Tunisia)", culture.display_name());
      assert::are_equal("French (Tunisia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-TN", culture.name());
      assert::are_equal("français (Tunisie)", culture.native_name());
    }
    
    auto test_method_(fr_VU) {
      auto culture = culture_info {"fr-VU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Vanuatu)", culture.display_name());
      assert::are_equal("French (Vanuatu)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-VU", culture.name());
      assert::are_equal("français (Vanuatu)", culture.native_name());
    }
    
    auto test_method_(fr_WF) {
      auto culture = culture_info {"fr-WF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Wallis & Futuna)", culture.display_name());
      assert::are_equal("French (Wallis & Futuna)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-WF", culture.name());
      assert::are_equal("français (Wallis-et-Futuna)", culture.native_name());
    }
    
    auto test_method_(fr_YT) {
      auto culture = culture_info {"fr-YT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("French (Mayotte)", culture.display_name());
      assert::are_equal("French (Mayotte)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fr-YT", culture.name());
      assert::are_equal("français (Mayotte)", culture.native_name());
    }
    
    auto test_method_(fur) {
      auto culture = culture_info {"fur"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Friulian", culture.display_name());
      assert::are_equal("Friulian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fur", culture.name());
      assert::are_equal("furlan", culture.native_name());
    }
    
    auto test_method_(fur_IT) {
      auto culture = culture_info {"fur-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Friulian (Italy)", culture.display_name());
      assert::are_equal("Friulian (Italy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("fur-IT", culture.name());
      assert::are_equal("furlan (Italie)", culture.native_name());
    }
    
    auto test_method_(fy) {
      auto culture = culture_info {"fy"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Western Frisian", culture.display_name());
      assert::are_equal("Western Frisian", culture.english_name());
      assert::are_equal(98_z, culture.keyboard_layout_id());
      assert::are_equal(98_z, culture.lcid());
      assert::are_equal("fy", culture.name());
      assert::are_equal("Frysk", culture.native_name());
    }
    
    auto test_method_(fy_NL) {
      auto culture = culture_info {"fy-NL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Western Frisian (Netherlands)", culture.display_name());
      assert::are_equal("Western Frisian (Netherlands)", culture.english_name());
      assert::are_equal(1122_z, culture.keyboard_layout_id());
      assert::are_equal(1122_z, culture.lcid());
      assert::are_equal("fy-NL", culture.name());
      assert::are_equal("Frysk (Nederlân)", culture.native_name());
    }
    
    auto test_method_(ga) {
      auto culture = culture_info {"ga"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Irish", culture.display_name());
      assert::are_equal("Irish", culture.english_name());
      assert::are_equal(60_z, culture.keyboard_layout_id());
      assert::are_equal(60_z, culture.lcid());
      assert::are_equal("ga", culture.name());
      assert::are_equal("Gaeilge", culture.native_name());
    }
    
    auto test_method_(ga_GB) {
      auto culture = culture_info {"ga-GB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Irish (United Kingdom)", culture.display_name());
      assert::are_equal("Irish (United Kingdom)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ga-GB", culture.name());
      assert::are_equal("Gaeilge (an Ríocht Aontaithe)", culture.native_name());
    }
    
    auto test_method_(ga_IE) {
      auto culture = culture_info {"ga-IE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Irish (Ireland)", culture.display_name());
      assert::are_equal("Irish (Ireland)", culture.english_name());
      assert::are_equal(2108_z, culture.keyboard_layout_id());
      assert::are_equal(2108_z, culture.lcid());
      assert::are_equal("ga-IE", culture.name());
      assert::are_equal("Gaeilge (Éire)", culture.native_name());
    }
    
    auto test_method_(gaa) {
      auto culture = culture_info {"gaa"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ga", culture.display_name());
      assert::are_equal("Ga", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gaa", culture.name());
      assert::are_equal("Gã", culture.native_name());
    }
    
    auto test_method_(gaa_GH) {
      auto culture = culture_info {"gaa-GH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ga (Ghana)", culture.display_name());
      assert::are_equal("Ga (Ghana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gaa-GH", culture.name());
      assert::are_equal("Gã (Ghana)", culture.native_name());
    }
    
    auto test_method_(gd) {
      auto culture = culture_info {"gd"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Scottish Gaelic", culture.display_name());
      assert::are_equal("Scottish Gaelic", culture.english_name());
      assert::are_equal(145_z, culture.keyboard_layout_id());
      assert::are_equal(145_z, culture.lcid());
      assert::are_equal("gd", culture.name());
      assert::are_equal("Gàidhlig", culture.native_name());
    }
    
    auto test_method_(gd_GB) {
      auto culture = culture_info {"gd-GB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Scottish Gaelic (United Kingdom)", culture.display_name());
      assert::are_equal("Scottish Gaelic (United Kingdom)", culture.english_name());
      assert::are_equal(1169_z, culture.keyboard_layout_id());
      assert::are_equal(1169_z, culture.lcid());
      assert::are_equal("gd-GB", culture.name());
      assert::are_equal("Gàidhlig (An Rìoghachd Aonaichte)", culture.native_name());
    }
    
    auto test_method_(gez) {
      auto culture = culture_info {"gez"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Geez", culture.display_name());
      assert::are_equal("Geez", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gez", culture.name());
      assert::are_equal("ግዕዝኛ", culture.native_name());
    }
    
    auto test_method_(gez_ER) {
      auto culture = culture_info {"gez-ER"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Geez (Eritrea)", culture.display_name());
      assert::are_equal("Geez (Eritrea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gez-ER", culture.name());
      assert::are_equal("ግዕዝኛ (ኤርትራ)", culture.native_name());
    }
    
    auto test_method_(gez_ET) {
      auto culture = culture_info {"gez-ET"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Geez (Ethiopia)", culture.display_name());
      assert::are_equal("Geez (Ethiopia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gez-ET", culture.name());
      assert::are_equal("ግዕዝኛ (ኢትዮጵያ)", culture.native_name());
    }
    
    auto test_method_(gl) {
      auto culture = culture_info {"gl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Galician", culture.display_name());
      assert::are_equal("Galician", culture.english_name());
      assert::are_equal(86_z, culture.keyboard_layout_id());
      assert::are_equal(86_z, culture.lcid());
      assert::are_equal("gl", culture.name());
      assert::are_equal("galego", culture.native_name());
    }
    
    auto test_method_(gl_ES) {
      auto culture = culture_info {"gl-ES"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Galician (Spain)", culture.display_name());
      assert::are_equal("Galician (Spain)", culture.english_name());
      assert::are_equal(1110_z, culture.keyboard_layout_id());
      assert::are_equal(1110_z, culture.lcid());
      assert::are_equal("gl-ES", culture.name());
      assert::are_equal("galego (España)", culture.native_name());
    }
    
    auto test_method_(gn) {
      auto culture = culture_info {"gn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Guarani", culture.display_name());
      assert::are_equal("Guarani", culture.english_name());
      assert::are_equal(116_z, culture.keyboard_layout_id());
      assert::are_equal(116_z, culture.lcid());
      assert::are_equal("gn", culture.name());
      assert::are_equal("avañe’ẽ", culture.native_name());
    }
    
    auto test_method_(gn_PY) {
      auto culture = culture_info {"gn-PY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Guarani (Paraguay)", culture.display_name());
      assert::are_equal("Guarani (Paraguay)", culture.english_name());
      assert::are_equal(1140_z, culture.keyboard_layout_id());
      assert::are_equal(1140_z, culture.lcid());
      assert::are_equal("gn-PY", culture.name());
      assert::are_equal("Guarani (Paraguay)", culture.native_name());
    }
    
    auto test_method_(gsw) {
      auto culture = culture_info {"gsw"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Swiss German", culture.display_name());
      assert::are_equal("Swiss German", culture.english_name());
      assert::are_equal(132_z, culture.keyboard_layout_id());
      assert::are_equal(132_z, culture.lcid());
      assert::are_equal("gsw", culture.name());
      assert::are_equal("Schwiizertüütsch", culture.native_name());
    }
    
    auto test_method_(gsw_CH) {
      auto culture = culture_info {"gsw-CH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swiss German (Switzerland)", culture.display_name());
      assert::are_equal("Swiss German (Switzerland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gsw-CH", culture.name());
      assert::are_equal("Schwiizertüütsch (Schwiiz)", culture.native_name());
    }
    
    auto test_method_(gsw_FR) {
      auto culture = culture_info {"gsw-FR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swiss German (France)", culture.display_name());
      assert::are_equal("Swiss German (France)", culture.english_name());
      assert::are_equal(1156_z, culture.keyboard_layout_id());
      assert::are_equal(1156_z, culture.lcid());
      assert::are_equal("gsw-FR", culture.name());
      assert::are_equal("Schwiizertüütsch (Frankriich)", culture.native_name());
    }
    
    auto test_method_(gsw_LI) {
      auto culture = culture_info {"gsw-LI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swiss German (Liechtenstein)", culture.display_name());
      assert::are_equal("Swiss German (Liechtenstein)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gsw-LI", culture.name());
      assert::are_equal("Schwiizertüütsch (Liächteschtäi)", culture.native_name());
    }
    
    auto test_method_(gu) {
      auto culture = culture_info {"gu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Gujarati", culture.display_name());
      assert::are_equal("Gujarati", culture.english_name());
      assert::are_equal(71_z, culture.keyboard_layout_id());
      assert::are_equal(71_z, culture.lcid());
      assert::are_equal("gu", culture.name());
      assert::are_equal("ગુજરાતી", culture.native_name());
    }
    
    auto test_method_(gu_IN) {
      auto culture = culture_info {"gu-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Gujarati (India)", culture.display_name());
      assert::are_equal("Gujarati (India)", culture.english_name());
      assert::are_equal(1095_z, culture.keyboard_layout_id());
      assert::are_equal(1095_z, culture.lcid());
      assert::are_equal("gu-IN", culture.name());
      assert::are_equal("ગુજરાતી (ભારત)", culture.native_name());
    }
    
    auto test_method_(guz) {
      auto culture = culture_info {"guz"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Gusii", culture.display_name());
      assert::are_equal("Gusii", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("guz", culture.name());
      assert::are_equal("Ekegusii", culture.native_name());
    }
    
    auto test_method_(guz_KE) {
      auto culture = culture_info {"guz-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Gusii (Kenya)", culture.display_name());
      assert::are_equal("Gusii (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("guz-KE", culture.name());
      assert::are_equal("Ekegusii (Kenya)", culture.native_name());
    }
    
    auto test_method_(gv) {
      auto culture = culture_info {"gv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Manx", culture.display_name());
      assert::are_equal("Manx", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gv", culture.name());
      assert::are_equal("Gaelg", culture.native_name());
    }
    
    auto test_method_(gv_IM) {
      auto culture = culture_info {"gv-IM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Manx (Isle of Man)", culture.display_name());
      assert::are_equal("Manx (Isle of Man)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("gv-IM", culture.name());
      assert::are_equal("Gaelg (Ellan Vannin)", culture.native_name());
    }
    
    auto test_method_(ha) {
      auto culture = culture_info {"ha"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Hausa", culture.display_name());
      assert::are_equal("Hausa", culture.english_name());
      assert::are_equal(104_z, culture.keyboard_layout_id());
      assert::are_equal(104_z, culture.lcid());
      assert::are_equal("ha", culture.name());
      assert::are_equal("Hausa", culture.native_name());
    }
    
    auto test_method_(ha_GH) {
      auto culture = culture_info {"ha-GH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hausa (Ghana)", culture.display_name());
      assert::are_equal("Hausa (Ghana)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ha-GH", culture.name());
      assert::are_equal("Hausa (Gana)", culture.native_name());
    }
    
    auto test_method_(ha_NE) {
      auto culture = culture_info {"ha-NE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hausa (Niger)", culture.display_name());
      assert::are_equal("Hausa (Niger)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ha-NE", culture.name());
      assert::are_equal("Hausa (Nijar)", culture.native_name());
    }
    
    auto test_method_(ha_NG) {
      auto culture = culture_info {"ha-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hausa (Nigeria)", culture.display_name());
      assert::are_equal("Hausa (Nigeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ha-NG", culture.name());
      assert::are_equal("Hausa (Nijeriya)", culture.native_name());
    }
    
    auto test_method_(haw) {
      auto culture = culture_info {"haw"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Hawaiian", culture.display_name());
      assert::are_equal("Hawaiian", culture.english_name());
      assert::are_equal(117_z, culture.keyboard_layout_id());
      assert::are_equal(117_z, culture.lcid());
      assert::are_equal("haw", culture.name());
      assert::are_equal("ʻŌlelo Hawaiʻi", culture.native_name());
    }
    
    auto test_method_(haw_US) {
      auto culture = culture_info {"haw-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hawaiian (United States)", culture.display_name());
      assert::are_equal("Hawaiian (United States)", culture.english_name());
      assert::are_equal(1141_z, culture.keyboard_layout_id());
      assert::are_equal(1141_z, culture.lcid());
      assert::are_equal("haw-US", culture.name());
      assert::are_equal("ʻŌlelo Hawaiʻi (ʻAmelika Hui Pū ʻIa)", culture.native_name());
    }
    
    auto test_method_(he) {
      auto culture = culture_info {"he"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Hebrew", culture.display_name());
      assert::are_equal("Hebrew", culture.english_name());
      assert::are_equal(13_z, culture.keyboard_layout_id());
      assert::are_equal(13_z, culture.lcid());
      assert::are_equal("he", culture.name());
      assert::are_equal("עברית", culture.native_name());
    }
    
    auto test_method_(he_IL) {
      auto culture = culture_info {"he-IL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hebrew (Israel)", culture.display_name());
      assert::are_equal("Hebrew (Israel)", culture.english_name());
      assert::are_equal(1037_z, culture.keyboard_layout_id());
      assert::are_equal(1037_z, culture.lcid());
      assert::are_equal("he-IL", culture.name());
      assert::are_equal("עברית (ישראל)", culture.native_name());
    }
    
    auto test_method_(hi) {
      auto culture = culture_info {"hi"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Hindi", culture.display_name());
      assert::are_equal("Hindi", culture.english_name());
      assert::are_equal(57_z, culture.keyboard_layout_id());
      assert::are_equal(57_z, culture.lcid());
      assert::are_equal("hi", culture.name());
      assert::are_equal("हिन्दी", culture.native_name());
    }
    
    auto test_method_(hi_IN) {
      auto culture = culture_info {"hi-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hindi (India)", culture.display_name());
      assert::are_equal("Hindi (India)", culture.english_name());
      assert::are_equal(1081_z, culture.keyboard_layout_id());
      assert::are_equal(1081_z, culture.lcid());
      assert::are_equal("hi-IN", culture.name());
      assert::are_equal("हिन्दी (भारत)", culture.native_name());
    }
    
    auto test_method_(hi_Latn) {
      auto culture = culture_info {"hi-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Hindi (Latin)", culture.display_name());
      assert::are_equal("Hindi (Latin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("hi-Latn", culture.name());
      assert::are_equal("Hindi (Latin)", culture.native_name());
    }
    
    auto test_method_(hi_Latn_IN) {
      auto culture = culture_info {"hi-Latn-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hindi (Latin, India)", culture.display_name());
      assert::are_equal("Hindi (Latin, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("hi-Latn-IN", culture.name());
      assert::are_equal("Hindi (Latin, Bharat)", culture.native_name());
    }
    
    auto test_method_(hmn) {
      auto culture = culture_info {"hmn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Hmong", culture.display_name());
      assert::are_equal("Hmong", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("hmn", culture.name());
      assert::are_equal("𖬌𖬣𖬵", culture.native_name());
    }
    
    auto test_method_(hmn_CN) {
      auto culture = culture_info {"hmn-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hmong (China mainland)", culture.display_name());
      assert::are_equal("Hmong (China mainland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("hmn-CN", culture.name());
      assert::are_equal("𖬌𖬣𖬵 (CN)", culture.native_name());
    }
    
    auto test_method_(hr) {
      auto culture = culture_info {"hr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Croatian", culture.display_name());
      assert::are_equal("Croatian", culture.english_name());
      assert::are_equal(26_z, culture.keyboard_layout_id());
      assert::are_equal(26_z, culture.lcid());
      assert::are_equal("hr", culture.name());
      assert::are_equal("hrvatski", culture.native_name());
    }
    
    auto test_method_(hr_BA) {
      auto culture = culture_info {"hr-BA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Croatian (Bosnia & Herzegovina)", culture.display_name());
      assert::are_equal("Croatian (Bosnia & Herzegovina)", culture.english_name());
      assert::are_equal(4122_z, culture.keyboard_layout_id());
      assert::are_equal(4122_z, culture.lcid());
      assert::are_equal("hr-BA", culture.name());
      assert::are_equal("hrvatski (Bosna i Hercegovina)", culture.native_name());
    }
    
    auto test_method_(hr_HR) {
      auto culture = culture_info {"hr-HR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Croatian (Croatia)", culture.display_name());
      assert::are_equal("Croatian (Croatia)", culture.english_name());
      assert::are_equal(1050_z, culture.keyboard_layout_id());
      assert::are_equal(1050_z, culture.lcid());
      assert::are_equal("hr-HR", culture.name());
      assert::are_equal("hrvatski (Hrvatska)", culture.native_name());
    }
    
    auto test_method_(hsb) {
      auto culture = culture_info {"hsb"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Upper Sorbian", culture.display_name());
      assert::are_equal("Upper Sorbian", culture.english_name());
      assert::are_equal(46_z, culture.keyboard_layout_id());
      assert::are_equal(46_z, culture.lcid());
      assert::are_equal("hsb", culture.name());
      assert::are_equal("hornjoserbšćina", culture.native_name());
    }
    
    auto test_method_(hsb_DE) {
      auto culture = culture_info {"hsb-DE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Upper Sorbian (Germany)", culture.display_name());
      assert::are_equal("Upper Sorbian (Germany)", culture.english_name());
      assert::are_equal(1070_z, culture.keyboard_layout_id());
      assert::are_equal(1070_z, culture.lcid());
      assert::are_equal("hsb-DE", culture.name());
      assert::are_equal("hornjoserbšćina (Němska)", culture.native_name());
    }
    
    auto test_method_(hu) {
      auto culture = culture_info {"hu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Hungarian", culture.display_name());
      assert::are_equal("Hungarian", culture.english_name());
      assert::are_equal(14_z, culture.keyboard_layout_id());
      assert::are_equal(14_z, culture.lcid());
      assert::are_equal("hu", culture.name());
      assert::are_equal("magyar", culture.native_name());
    }
    
    auto test_method_(hu_HU) {
      auto culture = culture_info {"hu-HU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Hungarian (Hungary)", culture.display_name());
      assert::are_equal("Hungarian (Hungary)", culture.english_name());
      assert::are_equal(1038_z, culture.keyboard_layout_id());
      assert::are_equal(1038_z, culture.lcid());
      assert::are_equal("hu-HU", culture.name());
      assert::are_equal("magyar (Magyarország)", culture.native_name());
    }
    
    auto test_method_(hy) {
      auto culture = culture_info {"hy"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Armenian", culture.display_name());
      assert::are_equal("Armenian", culture.english_name());
      assert::are_equal(43_z, culture.keyboard_layout_id());
      assert::are_equal(43_z, culture.lcid());
      assert::are_equal("hy", culture.name());
      assert::are_equal("հայերեն", culture.native_name());
    }
    
    auto test_method_(hy_AM) {
      auto culture = culture_info {"hy-AM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Armenian (Armenia)", culture.display_name());
      assert::are_equal("Armenian (Armenia)", culture.english_name());
      assert::are_equal(1067_z, culture.keyboard_layout_id());
      assert::are_equal(1067_z, culture.lcid());
      assert::are_equal("hy-AM", culture.name());
      assert::are_equal("հայերեն (Հայաստան)", culture.native_name());
    }
    
    auto test_method_(ia) {
      auto culture = culture_info {"ia"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Interlingua", culture.display_name());
      assert::are_equal("Interlingua", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ia", culture.name());
      assert::are_equal("interlingua", culture.native_name());
    }
    
    auto test_method_(ia_001) {
      auto culture = culture_info {"ia-001"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Interlingua (world)", culture.display_name());
      assert::are_equal("Interlingua (world)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ia-001", culture.name());
      assert::are_equal("interlingua (mundo)", culture.native_name());
    }
    
    auto test_method_(id) {
      auto culture = culture_info {"id"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Indonesian", culture.display_name());
      assert::are_equal("Indonesian", culture.english_name());
      assert::are_equal(33_z, culture.keyboard_layout_id());
      assert::are_equal(33_z, culture.lcid());
      assert::are_equal("id", culture.name());
      assert::are_equal("Indonesia", culture.native_name());
    }
    
    auto test_method_(id_ID) {
      auto culture = culture_info {"id-ID"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Indonesian (Indonesia)", culture.display_name());
      assert::are_equal("Indonesian (Indonesia)", culture.english_name());
      assert::are_equal(1057_z, culture.keyboard_layout_id());
      assert::are_equal(1057_z, culture.lcid());
      assert::are_equal("id-ID", culture.name());
      assert::are_equal("Indonesia (Indonesia)", culture.native_name());
    }
    
    auto test_method_(ie) {
      auto culture = culture_info {"ie"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Interlingue", culture.display_name());
      assert::are_equal("Interlingue", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ie", culture.name());
      assert::are_equal("Interlingue", culture.native_name());
    }
    
    auto test_method_(ie_EE) {
      auto culture = culture_info {"ie-EE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Interlingue (Estonia)", culture.display_name());
      assert::are_equal("Interlingue (Estonia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ie-EE", culture.name());
      assert::are_equal("Interlingue (Estonia)", culture.native_name());
    }
    
    auto test_method_(ig) {
      auto culture = culture_info {"ig"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Igbo", culture.display_name());
      assert::are_equal("Igbo", culture.english_name());
      assert::are_equal(112_z, culture.keyboard_layout_id());
      assert::are_equal(112_z, culture.lcid());
      assert::are_equal("ig", culture.name());
      assert::are_equal("Igbo", culture.native_name());
    }
    
    auto test_method_(ig_NG) {
      auto culture = culture_info {"ig-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Igbo (Nigeria)", culture.display_name());
      assert::are_equal("Igbo (Nigeria)", culture.english_name());
      assert::are_equal(1136_z, culture.keyboard_layout_id());
      assert::are_equal(1136_z, culture.lcid());
      assert::are_equal("ig-NG", culture.name());
      assert::are_equal("Igbo (Naịjịrịa)", culture.native_name());
    }
    
    auto test_method_(ii) {
      auto culture = culture_info {"ii"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Liangshan Yi", culture.display_name());
      assert::are_equal("Liangshan Yi", culture.english_name());
      assert::are_equal(120_z, culture.keyboard_layout_id());
      assert::are_equal(120_z, culture.lcid());
      assert::are_equal("ii", culture.name());
      assert::are_equal("ꆈꌠꉙ", culture.native_name());
    }
    
    auto test_method_(ii_CN) {
      auto culture = culture_info {"ii-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Liangshan Yi (China mainland)", culture.display_name());
      assert::are_equal("Liangshan Yi (China mainland)", culture.english_name());
      assert::are_equal(1144_z, culture.keyboard_layout_id());
      assert::are_equal(1144_z, culture.lcid());
      assert::are_equal("ii-CN", culture.name());
      assert::are_equal("ꆈꌠꉙ（ꍏꇩ）", culture.native_name());
    }
    
    auto test_method_(inh) {
      auto culture = culture_info {"inh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ingush", culture.display_name());
      assert::are_equal("Ingush", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("inh", culture.name());
      assert::are_equal("ГӀалгӀай мотт", culture.native_name());
    }
    
    auto test_method_(io) {
      auto culture = culture_info {"io"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ido", culture.display_name());
      assert::are_equal("Ido", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("io", culture.name());
      assert::are_equal("Ido", culture.native_name());
    }
    
    auto test_method_(io_001) {
      auto culture = culture_info {"io-001"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ido (world)", culture.display_name());
      assert::are_equal("Ido (world)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("io-001", culture.name());
      assert::are_equal("Ido (world)", culture.native_name());
    }
    
    auto test_method_(is) {
      auto culture = culture_info {"is"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Icelandic", culture.display_name());
      assert::are_equal("Icelandic", culture.english_name());
      assert::are_equal(15_z, culture.keyboard_layout_id());
      assert::are_equal(15_z, culture.lcid());
      assert::are_equal("is", culture.name());
      assert::are_equal("íslenska", culture.native_name());
    }
    
    auto test_method_(is_IS) {
      auto culture = culture_info {"is-IS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Icelandic (Iceland)", culture.display_name());
      assert::are_equal("Icelandic (Iceland)", culture.english_name());
      assert::are_equal(1039_z, culture.keyboard_layout_id());
      assert::are_equal(1039_z, culture.lcid());
      assert::are_equal("is-IS", culture.name());
      assert::are_equal("íslenska (Ísland)", culture.native_name());
    }
    
    auto test_method_(it) {
      auto culture = culture_info {"it"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Italian", culture.display_name());
      assert::are_equal("Italian", culture.english_name());
      assert::are_equal(16_z, culture.keyboard_layout_id());
      assert::are_equal(16_z, culture.lcid());
      assert::are_equal("it", culture.name());
      assert::are_equal("italiano", culture.native_name());
    }
    
    auto test_method_(it_CH) {
      auto culture = culture_info {"it-CH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Italian (Switzerland)", culture.display_name());
      assert::are_equal("Italian (Switzerland)", culture.english_name());
      assert::are_equal(2064_z, culture.keyboard_layout_id());
      assert::are_equal(2064_z, culture.lcid());
      assert::are_equal("it-CH", culture.name());
      assert::are_equal("italiano (Svizzera)", culture.native_name());
    }
    
    auto test_method_(it_IT) {
      auto culture = culture_info {"it-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Italian (Italy)", culture.display_name());
      assert::are_equal("Italian (Italy)", culture.english_name());
      assert::are_equal(1040_z, culture.keyboard_layout_id());
      assert::are_equal(1040_z, culture.lcid());
      assert::are_equal("it-IT", culture.name());
      assert::are_equal("italiano (Italia)", culture.native_name());
    }
    
    auto test_method_(it_SM) {
      auto culture = culture_info {"it-SM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Italian (San Marino)", culture.display_name());
      assert::are_equal("Italian (San Marino)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("it-SM", culture.name());
      assert::are_equal("italiano (San Marino)", culture.native_name());
    }
    
    auto test_method_(it_VA) {
      auto culture = culture_info {"it-VA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Italian (Vatican City)", culture.display_name());
      assert::are_equal("Italian (Vatican City)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("it-VA", culture.name());
      assert::are_equal("italiano (Città del Vaticano)", culture.native_name());
    }
    
    auto test_method_(iu) {
      auto culture = culture_info {"iu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Inuktitut", culture.display_name());
      assert::are_equal("Inuktitut", culture.english_name());
      assert::are_equal(93_z, culture.keyboard_layout_id());
      assert::are_equal(93_z, culture.lcid());
      assert::are_equal("iu", culture.name());
      assert::are_equal("ᐃᓄᒃᑎᑐᑦ", culture.native_name());
    }
    
    auto test_method_(iu_CA) {
      auto culture = culture_info {"iu-CA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Inuktitut (Canada)", culture.display_name());
      assert::are_equal("Inuktitut (Canada)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("iu-CA", culture.name());
      assert::are_equal("ᐃᓄᒃᑎᑐᑦ (ᑲᓇᑕᒥ)", culture.native_name());
    }
    
    auto test_method_(ja) {
      auto culture = culture_info {"ja"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Japanese", culture.display_name());
      assert::are_equal("Japanese", culture.english_name());
      assert::are_equal(17_z, culture.keyboard_layout_id());
      assert::are_equal(17_z, culture.lcid());
      assert::are_equal("ja", culture.name());
      assert::are_equal("日本語", culture.native_name());
    }
    
    auto test_method_(ja_JP) {
      auto culture = culture_info {"ja-JP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Japanese (Japan)", culture.display_name());
      assert::are_equal("Japanese (Japan)", culture.english_name());
      assert::are_equal(1041_z, culture.keyboard_layout_id());
      assert::are_equal(1041_z, culture.lcid());
      assert::are_equal("ja-JP", culture.name());
      assert::are_equal("日本語（日本）", culture.native_name());
    }
    
    auto test_method_(jbo) {
      auto culture = culture_info {"jbo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Lojban", culture.display_name());
      assert::are_equal("Lojban", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("jbo", culture.name());
      assert::are_equal("la .lojban.", culture.native_name());
    }
    
    auto test_method_(jbo_001) {
      auto culture = culture_info {"jbo-001"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lojban (world)", culture.display_name());
      assert::are_equal("Lojban (world)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("jbo-001", culture.name());
      assert::are_equal("Lojban (world)", culture.native_name());
    }
    
    auto test_method_(jgo) {
      auto culture = culture_info {"jgo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ngomba", culture.display_name());
      assert::are_equal("Ngomba", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("jgo", culture.name());
      assert::are_equal("Ndaꞌa", culture.native_name());
    }
    
    auto test_method_(jgo_CM) {
      auto culture = culture_info {"jgo-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ngomba (Cameroon)", culture.display_name());
      assert::are_equal("Ngomba (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("jgo-CM", culture.name());
      assert::are_equal("Ndaꞌa (Kamɛlûn)", culture.native_name());
    }
    
    auto test_method_(jmc) {
      auto culture = culture_info {"jmc"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Machame", culture.display_name());
      assert::are_equal("Machame", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("jmc", culture.name());
      assert::are_equal("Kimachame", culture.native_name());
    }
    
    auto test_method_(jmc_TZ) {
      auto culture = culture_info {"jmc-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Machame (Tanzania)", culture.display_name());
      assert::are_equal("Machame (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("jmc-TZ", culture.name());
      assert::are_equal("Kimachame (Tanzania)", culture.native_name());
    }
    
    auto test_method_(jv) {
      auto culture = culture_info {"jv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Javanese", culture.display_name());
      assert::are_equal("Javanese", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("jv", culture.name());
      assert::are_equal("Jawa", culture.native_name());
    }
    
    auto test_method_(jv_ID) {
      auto culture = culture_info {"jv-ID"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Javanese (Indonesia)", culture.display_name());
      assert::are_equal("Javanese (Indonesia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("jv-ID", culture.name());
      assert::are_equal("Jawa (Indonésia)", culture.native_name());
    }
    
    auto test_method_(ka) {
      auto culture = culture_info {"ka"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Georgian", culture.display_name());
      assert::are_equal("Georgian", culture.english_name());
      assert::are_equal(55_z, culture.keyboard_layout_id());
      assert::are_equal(55_z, culture.lcid());
      assert::are_equal("ka", culture.name());
      assert::are_equal("ქართული", culture.native_name());
    }
    
    auto test_method_(ka_GE) {
      auto culture = culture_info {"ka-GE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Georgian (Georgia)", culture.display_name());
      assert::are_equal("Georgian (Georgia)", culture.english_name());
      assert::are_equal(1079_z, culture.keyboard_layout_id());
      assert::are_equal(1079_z, culture.lcid());
      assert::are_equal("ka-GE", culture.name());
      assert::are_equal("ქართული (საქართველო)", culture.native_name());
    }
    
    auto test_method_(kab) {
      auto culture = culture_info {"kab"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kabyle", culture.display_name());
      assert::are_equal("Kabyle", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kab", culture.name());
      assert::are_equal("Taqbaylit", culture.native_name());
    }
    
    auto test_method_(kab_DZ) {
      auto culture = culture_info {"kab-DZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kabyle (Algeria)", culture.display_name());
      assert::are_equal("Kabyle (Algeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kab-DZ", culture.name());
      assert::are_equal("Taqbaylit (Lezzayer)", culture.native_name());
    }
    
    auto test_method_(kaj) {
      auto culture = culture_info {"kaj"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Jju", culture.display_name());
      assert::are_equal("Jju", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kaj", culture.name());
      assert::are_equal("Kaje", culture.native_name());
    }
    
    auto test_method_(kaj_NG) {
      auto culture = culture_info {"kaj-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Jju (Nigeria)", culture.display_name());
      assert::are_equal("Jju (Nigeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kaj-NG", culture.name());
      assert::are_equal("Jju (Nigeria)", culture.native_name());
    }
    
    auto test_method_(kam) {
      auto culture = culture_info {"kam"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kamba", culture.display_name());
      assert::are_equal("Kamba", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kam", culture.name());
      assert::are_equal("Kikamba", culture.native_name());
    }
    
    auto test_method_(kam_KE) {
      auto culture = culture_info {"kam-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kamba (Kenya)", culture.display_name());
      assert::are_equal("Kamba (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kam-KE", culture.name());
      assert::are_equal("Kikamba (Kenya)", culture.native_name());
    }
    
    auto test_method_(kcg) {
      auto culture = culture_info {"kcg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tyap", culture.display_name());
      assert::are_equal("Tyap", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kcg", culture.name());
      assert::are_equal("Katab", culture.native_name());
    }
    
    auto test_method_(kcg_NG) {
      auto culture = culture_info {"kcg-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tyap (Nigeria)", culture.display_name());
      assert::are_equal("Tyap (Nigeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kcg-NG", culture.name());
      assert::are_equal("Tyap (Nigeria)", culture.native_name());
    }
    
    auto test_method_(kde) {
      auto culture = culture_info {"kde"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Makonde", culture.display_name());
      assert::are_equal("Makonde", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kde", culture.name());
      assert::are_equal("Chimakonde", culture.native_name());
    }
    
    auto test_method_(kde_TZ) {
      auto culture = culture_info {"kde-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Makonde (Tanzania)", culture.display_name());
      assert::are_equal("Makonde (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kde-TZ", culture.name());
      assert::are_equal("Chimakonde (Tanzania)", culture.native_name());
    }
    
    auto test_method_(kea) {
      auto culture = culture_info {"kea"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kabuverdianu", culture.display_name());
      assert::are_equal("Kabuverdianu", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kea", culture.name());
      assert::are_equal("kabuverdianu", culture.native_name());
    }
    
    auto test_method_(kea_CV) {
      auto culture = culture_info {"kea-CV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kabuverdianu (Cape Verde)", culture.display_name());
      assert::are_equal("Kabuverdianu (Cape Verde)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kea-CV", culture.name());
      assert::are_equal("kabuverdianu (Kabu Verdi)", culture.native_name());
    }
    
    auto test_method_(kgp) {
      auto culture = culture_info {"kgp"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kaingang", culture.display_name());
      assert::are_equal("Kaingang", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kgp", culture.name());
      assert::are_equal("kanhgág", culture.native_name());
    }
    
    auto test_method_(kgp_BR) {
      auto culture = culture_info {"kgp-BR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kaingang (Brazil)", culture.display_name());
      assert::are_equal("Kaingang (Brazil)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kgp-BR", culture.name());
      assert::are_equal("kanhgág (Mrasir)", culture.native_name());
    }
    
    auto test_method_(khq) {
      auto culture = culture_info {"khq"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Koyra Chiini", culture.display_name());
      assert::are_equal("Koyra Chiini", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("khq", culture.name());
      assert::are_equal("Koyra ciini", culture.native_name());
    }
    
    auto test_method_(khq_ML) {
      auto culture = culture_info {"khq-ML"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Koyra Chiini (Mali)", culture.display_name());
      assert::are_equal("Koyra Chiini (Mali)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("khq-ML", culture.name());
      assert::are_equal("Koyra ciini (Maali)", culture.native_name());
    }
    
    auto test_method_(ki) {
      auto culture = culture_info {"ki"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kikuyu", culture.display_name());
      assert::are_equal("Kikuyu", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ki", culture.name());
      assert::are_equal("Gikuyu", culture.native_name());
    }
    
    auto test_method_(ki_KE) {
      auto culture = culture_info {"ki-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kikuyu (Kenya)", culture.display_name());
      assert::are_equal("Kikuyu (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ki-KE", culture.name());
      assert::are_equal("Gikuyu (Kenya)", culture.native_name());
    }
    
    auto test_method_(kk) {
      auto culture = culture_info {"kk"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kazakh", culture.display_name());
      assert::are_equal("Kazakh", culture.english_name());
      assert::are_equal(63_z, culture.keyboard_layout_id());
      assert::are_equal(63_z, culture.lcid());
      assert::are_equal("kk", culture.name());
      assert::are_equal("қазақ тілі", culture.native_name());
    }
    
    auto test_method_(kk_Cyrl) {
      auto culture = culture_info {"kk-Cyrl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kazakh (Cyrillic)", culture.display_name());
      assert::are_equal("Kazakh (Cyrillic)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kk-Cyrl", culture.name());
      assert::are_equal("қазақ тілі (кирилл жазуы)", culture.native_name());
    }
    
    auto test_method_(kk_Cyrl_KZ) {
      auto culture = culture_info {"kk-Cyrl-KZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kazakh (Cyrillic, Kazakhstan)", culture.display_name());
      assert::are_equal("Kazakh (Cyrillic, Kazakhstan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kk-Cyrl-KZ", culture.name());
      assert::are_equal("қазақ тілі (кирилл жазуы, Қазақстан)", culture.native_name());
    }
    
    auto test_method_(kk_KZ) {
      auto culture = culture_info {"kk-KZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kazakh (Kazakhstan)", culture.display_name());
      assert::are_equal("Kazakh (Kazakhstan)", culture.english_name());
      assert::are_equal(1087_z, culture.keyboard_layout_id());
      assert::are_equal(1087_z, culture.lcid());
      assert::are_equal("kk-KZ", culture.name());
      assert::are_equal("қазақ тілі (Қазақстан)", culture.native_name());
    }
    
    auto test_method_(kkj) {
      auto culture = culture_info {"kkj"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kako", culture.display_name());
      assert::are_equal("Kako", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kkj", culture.name());
      assert::are_equal("kakɔ", culture.native_name());
    }
    
    auto test_method_(kkj_CM) {
      auto culture = culture_info {"kkj-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kako (Cameroon)", culture.display_name());
      assert::are_equal("Kako (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kkj-CM", culture.name());
      assert::are_equal("kakɔ (Kamɛrun)", culture.native_name());
    }
    
    auto test_method_(kl) {
      auto culture = culture_info {"kl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kalaallisut", culture.display_name());
      assert::are_equal("Kalaallisut", culture.english_name());
      assert::are_equal(111_z, culture.keyboard_layout_id());
      assert::are_equal(111_z, culture.lcid());
      assert::are_equal("kl", culture.name());
      assert::are_equal("kalaallisut", culture.native_name());
    }
    
    auto test_method_(kl_GL) {
      auto culture = culture_info {"kl-GL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kalaallisut (Greenland)", culture.display_name());
      assert::are_equal("Kalaallisut (Greenland)", culture.english_name());
      assert::are_equal(1135_z, culture.keyboard_layout_id());
      assert::are_equal(1135_z, culture.lcid());
      assert::are_equal("kl-GL", culture.name());
      assert::are_equal("kalaallisut (Kalaallit Nunaat)", culture.native_name());
    }
    
    auto test_method_(kln) {
      auto culture = culture_info {"kln"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kalenjin", culture.display_name());
      assert::are_equal("Kalenjin", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kln", culture.name());
      assert::are_equal("Kalenjin", culture.native_name());
    }
    
    auto test_method_(kln_KE) {
      auto culture = culture_info {"kln-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kalenjin (Kenya)", culture.display_name());
      assert::are_equal("Kalenjin (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kln-KE", culture.name());
      assert::are_equal("Kalenjin (Emetab Kenya)", culture.native_name());
    }
    
    auto test_method_(km) {
      auto culture = culture_info {"km"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Khmer", culture.display_name());
      assert::are_equal("Khmer", culture.english_name());
      assert::are_equal(83_z, culture.keyboard_layout_id());
      assert::are_equal(83_z, culture.lcid());
      assert::are_equal("km", culture.name());
      assert::are_equal("ខ្មែរ", culture.native_name());
    }
    
    auto test_method_(km_KH) {
      auto culture = culture_info {"km-KH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Khmer (Cambodia)", culture.display_name());
      assert::are_equal("Khmer (Cambodia)", culture.english_name());
      assert::are_equal(1107_z, culture.keyboard_layout_id());
      assert::are_equal(1107_z, culture.lcid());
      assert::are_equal("km-KH", culture.name());
      assert::are_equal("ខ្មែរ (កម្ពុជា)", culture.native_name());
    }
    
    auto test_method_(kn) {
      auto culture = culture_info {"kn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kannada", culture.display_name());
      assert::are_equal("Kannada", culture.english_name());
      assert::are_equal(75_z, culture.keyboard_layout_id());
      assert::are_equal(75_z, culture.lcid());
      assert::are_equal("kn", culture.name());
      assert::are_equal("ಕನ್ನಡ", culture.native_name());
    }
    
    auto test_method_(kn_IN) {
      auto culture = culture_info {"kn-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kannada (India)", culture.display_name());
      assert::are_equal("Kannada (India)", culture.english_name());
      assert::are_equal(1099_z, culture.keyboard_layout_id());
      assert::are_equal(1099_z, culture.lcid());
      assert::are_equal("kn-IN", culture.name());
      assert::are_equal("ಕನ್ನಡ (ಭಾರತ)", culture.native_name());
    }
    
    auto test_method_(ko) {
      auto culture = culture_info {"ko"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Korean", culture.display_name());
      assert::are_equal("Korean", culture.english_name());
      assert::are_equal(18_z, culture.keyboard_layout_id());
      assert::are_equal(18_z, culture.lcid());
      assert::are_equal("ko", culture.name());
      assert::are_equal("한국어", culture.native_name());
    }
    
    auto test_method_(ko_CN) {
      auto culture = culture_info {"ko-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Korean (China mainland)", culture.display_name());
      assert::are_equal("Korean (China mainland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ko-CN", culture.name());
      assert::are_equal("한국어(중국 본토)", culture.native_name());
    }
    
    auto test_method_(ko_KP) {
      auto culture = culture_info {"ko-KP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Korean (North Korea)", culture.display_name());
      assert::are_equal("Korean (North Korea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ko-KP", culture.name());
      assert::are_equal("한국어(조선민주주의인민공화국)", culture.native_name());
    }
    
    auto test_method_(ko_KR) {
      auto culture = culture_info {"ko-KR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Korean (South Korea)", culture.display_name());
      assert::are_equal("Korean (South Korea)", culture.english_name());
      assert::are_equal(1042_z, culture.keyboard_layout_id());
      assert::are_equal(1042_z, culture.lcid());
      assert::are_equal("ko-KR", culture.name());
      assert::are_equal("한국어(대한민국)", culture.native_name());
    }
    
    auto test_method_(kok) {
      auto culture = culture_info {"kok"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Konkani", culture.display_name());
      assert::are_equal("Konkani", culture.english_name());
      assert::are_equal(87_z, culture.keyboard_layout_id());
      assert::are_equal(87_z, culture.lcid());
      assert::are_equal("kok", culture.name());
      assert::are_equal("कोंकणी", culture.native_name());
    }
    
    auto test_method_(kok_Deva) {
      auto culture = culture_info {"kok-Deva"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Konkani (Devanagari)", culture.display_name());
      assert::are_equal("Konkani (Devanagari)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kok-Deva", culture.name());
      assert::are_equal("कोंकणी (देवनागरी)", culture.native_name());
    }
    
    auto test_method_(kok_Deva_IN) {
      auto culture = culture_info {"kok-Deva-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Konkani (Devanagari, India)", culture.display_name());
      assert::are_equal("Konkani (Devanagari, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kok-Deva-IN", culture.name());
      assert::are_equal("कोंकणी (देवनागरी, भारत)", culture.native_name());
    }
    
    auto test_method_(kok_Latn) {
      auto culture = culture_info {"kok-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Konkani (Latin)", culture.display_name());
      assert::are_equal("Konkani (Latin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kok-Latn", culture.name());
      assert::are_equal("Konknni (Romi)", culture.native_name());
    }
    
    auto test_method_(kok_Latn_IN) {
      auto culture = culture_info {"kok-Latn-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Konkani (Latin, India)", culture.display_name());
      assert::are_equal("Konkani (Latin, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kok-Latn-IN", culture.name());
      assert::are_equal("Konknni (Romi, Bharot)", culture.native_name());
    }
    
    auto test_method_(kpe) {
      auto culture = culture_info {"kpe"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kpelle", culture.display_name());
      assert::are_equal("Kpelle", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kpe", culture.name());
      assert::are_equal("Kpɛlɛɛ", culture.native_name());
    }
    
    auto test_method_(kpe_GN) {
      auto culture = culture_info {"kpe-GN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kpelle (Guinea)", culture.display_name());
      assert::are_equal("Kpelle (Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kpe-GN", culture.name());
      assert::are_equal("Kpelle (Guinea)", culture.native_name());
    }
    
    auto test_method_(kpe_LR) {
      auto culture = culture_info {"kpe-LR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kpelle (Liberia)", culture.display_name());
      assert::are_equal("Kpelle (Liberia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kpe-LR", culture.name());
      assert::are_equal("Kpelle (Liberia)", culture.native_name());
    }
    
    auto test_method_(ks) {
      auto culture = culture_info {"ks"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kashmiri", culture.display_name());
      assert::are_equal("Kashmiri", culture.english_name());
      assert::are_equal(96_z, culture.keyboard_layout_id());
      assert::are_equal(96_z, culture.lcid());
      assert::are_equal("ks", culture.name());
      assert::are_equal("کٲشُر", culture.native_name());
    }
    
    auto test_method_(ks_Arab) {
      auto culture = culture_info {"ks-Arab"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kashmiri (Naskh)", culture.display_name());
      assert::are_equal("Kashmiri (Naskh)", culture.english_name());
      assert::are_equal(1120_z, culture.keyboard_layout_id());
      assert::are_equal(1120_z, culture.lcid());
      assert::are_equal("ks-Arab", culture.name());
      assert::are_equal("کٲشُر (نسخ)", culture.native_name());
    }
    
    auto test_method_(ks_Arab_IN) {
      auto culture = culture_info {"ks-Arab-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kashmiri (Naskh, India)", culture.display_name());
      assert::are_equal("Kashmiri (Naskh, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ks-Arab-IN", culture.name());
      assert::are_equal("کٲشُر (نسخ, ہِندوستان)", culture.native_name());
    }
    
    auto test_method_(ks_Aran_IN) {
      auto culture = culture_info {"ks-Aran-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kashmiri (Nastaliq, India)", culture.display_name());
      assert::are_equal("Kashmiri (Nastaliq, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ks-Aran-IN", culture.name());
      assert::are_equal("کٲشُر (نستعلیق, ہِندوستان)", culture.native_name());
    }
    
    auto test_method_(ks_Deva) {
      auto culture = culture_info {"ks-Deva"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kashmiri (Devanagari)", culture.display_name());
      assert::are_equal("Kashmiri (Devanagari)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ks-Deva", culture.name());
      assert::are_equal("कॉशुर (देवनागरी)", culture.native_name());
    }
    
    auto test_method_(ks_Deva_IN) {
      auto culture = culture_info {"ks-Deva-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kashmiri (Devanagari, India)", culture.display_name());
      assert::are_equal("Kashmiri (Devanagari, India)", culture.english_name());
      assert::are_equal(2144_z, culture.keyboard_layout_id());
      assert::are_equal(2144_z, culture.lcid());
      assert::are_equal("ks-Deva-IN", culture.name());
      assert::are_equal("कॉशुर (देवनागरी, हिंदोस्तान)", culture.native_name());
    }
    
    auto test_method_(ksb) {
      auto culture = culture_info {"ksb"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Shambala", culture.display_name());
      assert::are_equal("Shambala", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ksb", culture.name());
      assert::are_equal("Kishambaa", culture.native_name());
    }
    
    auto test_method_(ksb_TZ) {
      auto culture = culture_info {"ksb-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Shambala (Tanzania)", culture.display_name());
      assert::are_equal("Shambala (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ksb-TZ", culture.name());
      assert::are_equal("Kishambaa (Tanzania)", culture.native_name());
    }
    
    auto test_method_(ksf) {
      auto culture = culture_info {"ksf"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Bafia", culture.display_name());
      assert::are_equal("Bafia", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ksf", culture.name());
      assert::are_equal("rikpa", culture.native_name());
    }
    
    auto test_method_(ksf_CM) {
      auto culture = culture_info {"ksf-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Bafia (Cameroon)", culture.display_name());
      assert::are_equal("Bafia (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ksf-CM", culture.name());
      assert::are_equal("rikpa (kamɛrún)", culture.native_name());
    }
    
    auto test_method_(ksh) {
      auto culture = culture_info {"ksh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Colognian", culture.display_name());
      assert::are_equal("Colognian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ksh", culture.name());
      assert::are_equal("Kölsch", culture.native_name());
    }
    
    auto test_method_(ksh_DE) {
      auto culture = culture_info {"ksh-DE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Colognian (Germany)", culture.display_name());
      assert::are_equal("Colognian (Germany)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ksh-DE", culture.name());
      assert::are_equal("Kölsch en Doütschland", culture.native_name());
    }
    
    auto test_method_(ku) {
      auto culture = culture_info {"ku"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kurdish", culture.display_name());
      assert::are_equal("Kurdish", culture.english_name());
      assert::are_equal(146_z, culture.keyboard_layout_id());
      assert::are_equal(146_z, culture.lcid());
      assert::are_equal("ku", culture.name());
      assert::are_equal("kurdî (kurmancî)", culture.native_name());
    }
    
    auto test_method_(ku_TR) {
      auto culture = culture_info {"ku-TR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kurdish (Türkiye)", culture.display_name());
      assert::are_equal("Kurdish (Türkiye)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ku-TR", culture.name());
      assert::are_equal("kurdî (kurmancî) (Tirkîye)", culture.native_name());
    }
    
    auto test_method_(kw) {
      auto culture = culture_info {"kw"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Cornish", culture.display_name());
      assert::are_equal("Cornish", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kw", culture.name());
      assert::are_equal("kernewek", culture.native_name());
    }
    
    auto test_method_(kw_GB) {
      auto culture = culture_info {"kw-GB"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Cornish (United Kingdom)", culture.display_name());
      assert::are_equal("Cornish (United Kingdom)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kw-GB", culture.name());
      assert::are_equal("kernewek (Rywvaneth Unys)", culture.native_name());
    }
    
    auto test_method_(kxv) {
      auto culture = culture_info {"kxv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kuvi", culture.display_name());
      assert::are_equal("Kuvi", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv", culture.name());
      assert::are_equal("kuvi", culture.native_name());
    }
    
    auto test_method_(kxv_Deva) {
      auto culture = culture_info {"kxv-Deva"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kuvi (Devanagari)", culture.display_name());
      assert::are_equal("Kuvi (Devanagari)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv-Deva", culture.name());
      assert::are_equal("कुवि (देवनागरी)", culture.native_name());
    }
    
    auto test_method_(kxv_Deva_IN) {
      auto culture = culture_info {"kxv-Deva-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kuvi (Devanagari, India)", culture.display_name());
      assert::are_equal("Kuvi (Devanagari, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv-Deva-IN", culture.name());
      assert::are_equal("कुवि (देवनागरी, बारत)", culture.native_name());
    }
    
    auto test_method_(kxv_Latn) {
      auto culture = culture_info {"kxv-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kuvi (Latin)", culture.display_name());
      assert::are_equal("Kuvi (Latin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv-Latn", culture.name());
      assert::are_equal("kuvi (laṭin)", culture.native_name());
    }
    
    auto test_method_(kxv_Latn_IN) {
      auto culture = culture_info {"kxv-Latn-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kuvi (Latin, India)", culture.display_name());
      assert::are_equal("Kuvi (Latin, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv-Latn-IN", culture.name());
      assert::are_equal("kuvi (laṭin, inḍiā)", culture.native_name());
    }
    
    auto test_method_(kxv_Orya) {
      auto culture = culture_info {"kxv-Orya"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kuvi (Odia)", culture.display_name());
      assert::are_equal("Kuvi (Odia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv-Orya", culture.name());
      assert::are_equal("କୁୱି (ଅଡ଼ିଆ)", culture.native_name());
    }
    
    auto test_method_(kxv_Orya_IN) {
      auto culture = culture_info {"kxv-Orya-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kuvi (Odia, India)", culture.display_name());
      assert::are_equal("Kuvi (Odia, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv-Orya-IN", culture.name());
      assert::are_equal("କୁୱି (ଅଡ଼ିଆ, ବାରତ)", culture.native_name());
    }
    
    auto test_method_(kxv_Telu) {
      auto culture = culture_info {"kxv-Telu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kuvi (Telugu)", culture.display_name());
      assert::are_equal("Kuvi (Telugu)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv-Telu", culture.name());
      assert::are_equal("కువి (తెలుగు)", culture.native_name());
    }
    
    auto test_method_(kxv_Telu_IN) {
      auto culture = culture_info {"kxv-Telu-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kuvi (Telugu, India)", culture.display_name());
      assert::are_equal("Kuvi (Telugu, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("kxv-Telu-IN", culture.name());
      assert::are_equal("కువి (తెలుగు, బారతదెసాం)", culture.native_name());
    }
    
    auto test_method_(ky) {
      auto culture = culture_info {"ky"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kyrgyz", culture.display_name());
      assert::are_equal("Kyrgyz", culture.english_name());
      assert::are_equal(64_z, culture.keyboard_layout_id());
      assert::are_equal(64_z, culture.lcid());
      assert::are_equal("ky", culture.name());
      assert::are_equal("кыргызча", culture.native_name());
    }
    
    auto test_method_(ky_KG) {
      auto culture = culture_info {"ky-KG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kyrgyz (Kyrgyzstan)", culture.display_name());
      assert::are_equal("Kyrgyz (Kyrgyzstan)", culture.english_name());
      assert::are_equal(1088_z, culture.keyboard_layout_id());
      assert::are_equal(1088_z, culture.lcid());
      assert::are_equal("ky-KG", culture.name());
      assert::are_equal("кыргызча (Кыргызстан)", culture.native_name());
    }
    
    auto test_method_(lag) {
      auto culture = culture_info {"lag"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Langi", culture.display_name());
      assert::are_equal("Langi", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lag", culture.name());
      assert::are_equal("Kɨlaangi", culture.native_name());
    }
    
    auto test_method_(lag_TZ) {
      auto culture = culture_info {"lag-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Langi (Tanzania)", culture.display_name());
      assert::are_equal("Langi (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lag-TZ", culture.name());
      assert::are_equal("Kɨlaangi (Taansanía)", culture.native_name());
    }
    
    auto test_method_(lb) {
      auto culture = culture_info {"lb"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Luxembourgish", culture.display_name());
      assert::are_equal("Luxembourgish", culture.english_name());
      assert::are_equal(110_z, culture.keyboard_layout_id());
      assert::are_equal(110_z, culture.lcid());
      assert::are_equal("lb", culture.name());
      assert::are_equal("Lëtzebuergesch", culture.native_name());
    }
    
    auto test_method_(lb_LU) {
      auto culture = culture_info {"lb-LU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Luxembourgish (Luxembourg)", culture.display_name());
      assert::are_equal("Luxembourgish (Luxembourg)", culture.english_name());
      assert::are_equal(1134_z, culture.keyboard_layout_id());
      assert::are_equal(1134_z, culture.lcid());
      assert::are_equal("lb-LU", culture.name());
      assert::are_equal("Lëtzebuergesch (Lëtzebuerg)", culture.native_name());
    }
    
    auto test_method_(lg) {
      auto culture = culture_info {"lg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ganda", culture.display_name());
      assert::are_equal("Ganda", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lg", culture.name());
      assert::are_equal("Luganda", culture.native_name());
    }
    
    auto test_method_(lg_UG) {
      auto culture = culture_info {"lg-UG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ganda (Uganda)", culture.display_name());
      assert::are_equal("Ganda (Uganda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lg-UG", culture.name());
      assert::are_equal("Luganda (Yuganda)", culture.native_name());
    }
    
    auto test_method_(lij) {
      auto culture = culture_info {"lij"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ligurian", culture.display_name());
      assert::are_equal("Ligurian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lij", culture.name());
      assert::are_equal("ligure", culture.native_name());
    }
    
    auto test_method_(lij_IT) {
      auto culture = culture_info {"lij-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ligurian (Italy)", culture.display_name());
      assert::are_equal("Ligurian (Italy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lij-IT", culture.name());
      assert::are_equal("ligure (Italia)", culture.native_name());
    }
    
    auto test_method_(lkt) {
      auto culture = culture_info {"lkt"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Lakota", culture.display_name());
      assert::are_equal("Lakota", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lkt", culture.name());
      assert::are_equal("Lakȟólʼiyapi", culture.native_name());
    }
    
    auto test_method_(lkt_US) {
      auto culture = culture_info {"lkt-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lakota (United States)", culture.display_name());
      assert::are_equal("Lakota (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lkt-US", culture.name());
      assert::are_equal("Lakȟólʼiyapi (Mílahaŋska Tȟamákȟočhe)", culture.native_name());
    }
    
    auto test_method_(lmo) {
      auto culture = culture_info {"lmo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Lombard", culture.display_name());
      assert::are_equal("Lombard", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lmo", culture.name());
      assert::are_equal("Lombard", culture.native_name());
    }
    
    auto test_method_(lmo_IT) {
      auto culture = culture_info {"lmo-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lombard (Italy)", culture.display_name());
      assert::are_equal("Lombard (Italy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lmo-IT", culture.name());
      assert::are_equal("Lombard (Italia)", culture.native_name());
    }
    
    auto test_method_(ln) {
      auto culture = culture_info {"ln"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Lingala", culture.display_name());
      assert::are_equal("Lingala", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ln", culture.name());
      assert::are_equal("lingála", culture.native_name());
    }
    
    auto test_method_(ln_AO) {
      auto culture = culture_info {"ln-AO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lingala (Angola)", culture.display_name());
      assert::are_equal("Lingala (Angola)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ln-AO", culture.name());
      assert::are_equal("lingála (Angóla)", culture.native_name());
    }
    
    auto test_method_(ln_CD) {
      auto culture = culture_info {"ln-CD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lingala (Congo - Kinshasa)", culture.display_name());
      assert::are_equal("Lingala (Congo - Kinshasa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ln-CD", culture.name());
      assert::are_equal("lingála (Republíki ya Kongó Demokratíki)", culture.native_name());
    }
    
    auto test_method_(ln_CF) {
      auto culture = culture_info {"ln-CF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lingala (Central African Republic)", culture.display_name());
      assert::are_equal("Lingala (Central African Republic)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ln-CF", culture.name());
      assert::are_equal("lingála (Repibiki ya Afríka ya Káti)", culture.native_name());
    }
    
    auto test_method_(ln_CG) {
      auto culture = culture_info {"ln-CG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lingala (Congo - Brazzaville)", culture.display_name());
      assert::are_equal("Lingala (Congo - Brazzaville)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ln-CG", culture.name());
      assert::are_equal("lingála (Kongo)", culture.native_name());
    }
    
    auto test_method_(lo) {
      auto culture = culture_info {"lo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Lao", culture.display_name());
      assert::are_equal("Lao", culture.english_name());
      assert::are_equal(84_z, culture.keyboard_layout_id());
      assert::are_equal(84_z, culture.lcid());
      assert::are_equal("lo", culture.name());
      assert::are_equal("ລາວ", culture.native_name());
    }
    
    auto test_method_(lo_LA) {
      auto culture = culture_info {"lo-LA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lao (Laos)", culture.display_name());
      assert::are_equal("Lao (Laos)", culture.english_name());
      assert::are_equal(1108_z, culture.keyboard_layout_id());
      assert::are_equal(1108_z, culture.lcid());
      assert::are_equal("lo-LA", culture.name());
      assert::are_equal("ລາວ (ລາວ)", culture.native_name());
    }
    
    auto test_method_(lrc) {
      auto culture = culture_info {"lrc"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Northern Luri", culture.display_name());
      assert::are_equal("Northern Luri", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lrc", culture.name());
      assert::are_equal("لۊری شومالی", culture.native_name());
    }
    
    auto test_method_(lrc_IQ) {
      auto culture = culture_info {"lrc-IQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Northern Luri (Iraq)", culture.display_name());
      assert::are_equal("Northern Luri (Iraq)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lrc-IQ", culture.name());
      assert::are_equal("Northern Luri (Iraq)", culture.native_name());
    }
    
    auto test_method_(lrc_IR) {
      auto culture = culture_info {"lrc-IR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Northern Luri (Iran)", culture.display_name());
      assert::are_equal("Northern Luri (Iran)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lrc-IR", culture.name());
      assert::are_equal("Northern Luri (Iran)", culture.native_name());
    }
    
    auto test_method_(lt) {
      auto culture = culture_info {"lt"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Lithuanian", culture.display_name());
      assert::are_equal("Lithuanian", culture.english_name());
      assert::are_equal(39_z, culture.keyboard_layout_id());
      assert::are_equal(39_z, culture.lcid());
      assert::are_equal("lt", culture.name());
      assert::are_equal("lietuvių", culture.native_name());
    }
    
    auto test_method_(lt_LT) {
      auto culture = culture_info {"lt-LT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Lithuanian (Lithuania)", culture.display_name());
      assert::are_equal("Lithuanian (Lithuania)", culture.english_name());
      assert::are_equal(1063_z, culture.keyboard_layout_id());
      assert::are_equal(1063_z, culture.lcid());
      assert::are_equal("lt-LT", culture.name());
      assert::are_equal("lietuvių (Lietuva)", culture.native_name());
    }
    
    auto test_method_(lu) {
      auto culture = culture_info {"lu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Luba-Katanga", culture.display_name());
      assert::are_equal("Luba-Katanga", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lu", culture.name());
      assert::are_equal("Tshiluba", culture.native_name());
    }
    
    auto test_method_(lu_CD) {
      auto culture = culture_info {"lu-CD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Luba-Katanga (Congo - Kinshasa)", culture.display_name());
      assert::are_equal("Luba-Katanga (Congo - Kinshasa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lu-CD", culture.name());
      assert::are_equal("Tshiluba (Ditunga wa Kongu)", culture.native_name());
    }
    
    auto test_method_(luo) {
      auto culture = culture_info {"luo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Luo", culture.display_name());
      assert::are_equal("Luo", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("luo", culture.name());
      assert::are_equal("Dholuo", culture.native_name());
    }
    
    auto test_method_(luo_KE) {
      auto culture = culture_info {"luo-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Luo (Kenya)", culture.display_name());
      assert::are_equal("Luo (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("luo-KE", culture.name());
      assert::are_equal("Dholuo (Kenya)", culture.native_name());
    }
    
    auto test_method_(lut) {
      auto culture = culture_info {"lut"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Lushootseed", culture.display_name());
      assert::are_equal("Lushootseed", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("lut", culture.name());
      assert::are_equal("dxʷləšucid · txʷəlšucid · xʷəlšucid", culture.native_name());
    }
    
    auto test_method_(luy) {
      auto culture = culture_info {"luy"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Luyia", culture.display_name());
      assert::are_equal("Luyia", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("luy", culture.name());
      assert::are_equal("Luluhia", culture.native_name());
    }
    
    auto test_method_(luy_KE) {
      auto culture = culture_info {"luy-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Luyia (Kenya)", culture.display_name());
      assert::are_equal("Luyia (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("luy-KE", culture.name());
      assert::are_equal("Luluhia (Kenya)", culture.native_name());
    }
    
    auto test_method_(lv) {
      auto culture = culture_info {"lv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Latvian", culture.display_name());
      assert::are_equal("Latvian", culture.english_name());
      assert::are_equal(38_z, culture.keyboard_layout_id());
      assert::are_equal(38_z, culture.lcid());
      assert::are_equal("lv", culture.name());
      assert::are_equal("latviešu", culture.native_name());
    }
    
    auto test_method_(lv_LV) {
      auto culture = culture_info {"lv-LV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Latvian (Latvia)", culture.display_name());
      assert::are_equal("Latvian (Latvia)", culture.english_name());
      assert::are_equal(1062_z, culture.keyboard_layout_id());
      assert::are_equal(1062_z, culture.lcid());
      assert::are_equal("lv-LV", culture.name());
      assert::are_equal("latviešu (Latvija)", culture.native_name());
    }
    
    auto test_method_(mai) {
      auto culture = culture_info {"mai"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Maithili", culture.display_name());
      assert::are_equal("Maithili", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mai", culture.name());
      assert::are_equal("मैथिली", culture.native_name());
    }
    
    auto test_method_(mai_IN) {
      auto culture = culture_info {"mai-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Maithili (India)", culture.display_name());
      assert::are_equal("Maithili (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mai-IN", culture.name());
      assert::are_equal("मैथिली (भारत)", culture.native_name());
    }
    
    auto test_method_(mas) {
      auto culture = culture_info {"mas"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Masai", culture.display_name());
      assert::are_equal("Masai", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mas", culture.name());
      assert::are_equal("Maa", culture.native_name());
    }
    
    auto test_method_(mas_KE) {
      auto culture = culture_info {"mas-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Masai (Kenya)", culture.display_name());
      assert::are_equal("Masai (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mas-KE", culture.name());
      assert::are_equal("Maa (Kenya)", culture.native_name());
    }
    
    auto test_method_(mas_TZ) {
      auto culture = culture_info {"mas-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Masai (Tanzania)", culture.display_name());
      assert::are_equal("Masai (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mas-TZ", culture.name());
      assert::are_equal("Maa (Tansania)", culture.native_name());
    }
    
    auto test_method_(mer) {
      auto culture = culture_info {"mer"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Meru", culture.display_name());
      assert::are_equal("Meru", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mer", culture.name());
      assert::are_equal("Kĩmĩrũ", culture.native_name());
    }
    
    auto test_method_(mer_KE) {
      auto culture = culture_info {"mer-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Meru (Kenya)", culture.display_name());
      assert::are_equal("Meru (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mer-KE", culture.name());
      assert::are_equal("Kĩmĩrũ (Kenya)", culture.native_name());
    }
    
    auto test_method_(mfe) {
      auto culture = culture_info {"mfe"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Morisyen", culture.display_name());
      assert::are_equal("Morisyen", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mfe", culture.name());
      assert::are_equal("kreol morisien", culture.native_name());
    }
    
    auto test_method_(mfe_MU) {
      auto culture = culture_info {"mfe-MU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Morisyen (Mauritius)", culture.display_name());
      assert::are_equal("Morisyen (Mauritius)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mfe-MU", culture.name());
      assert::are_equal("kreol morisien (Moris)", culture.native_name());
    }
    
    auto test_method_(mg) {
      auto culture = culture_info {"mg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Malagasy", culture.display_name());
      assert::are_equal("Malagasy", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mg", culture.name());
      assert::are_equal("Malagasy", culture.native_name());
    }
    
    auto test_method_(mg_MG) {
      auto culture = culture_info {"mg-MG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Malagasy (Madagascar)", culture.display_name());
      assert::are_equal("Malagasy (Madagascar)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mg-MG", culture.name());
      assert::are_equal("Malagasy (Madagasikara)", culture.native_name());
    }
    
    auto test_method_(mgh) {
      auto culture = culture_info {"mgh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Makhuwa-Meetto", culture.display_name());
      assert::are_equal("Makhuwa-Meetto", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mgh", culture.name());
      assert::are_equal("Makua", culture.native_name());
    }
    
    auto test_method_(mgh_MZ) {
      auto culture = culture_info {"mgh-MZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Makhuwa-Meetto (Mozambique)", culture.display_name());
      assert::are_equal("Makhuwa-Meetto (Mozambique)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mgh-MZ", culture.name());
      assert::are_equal("Makua (Umozambiki)", culture.native_name());
    }
    
    auto test_method_(mgo) {
      auto culture = culture_info {"mgo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Metaʼ", culture.display_name());
      assert::are_equal("Metaʼ", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mgo", culture.name());
      assert::are_equal("metaʼ", culture.native_name());
    }
    
    auto test_method_(mgo_CM) {
      auto culture = culture_info {"mgo-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Metaʼ (Cameroon)", culture.display_name());
      assert::are_equal("Metaʼ (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mgo-CM", culture.name());
      assert::are_equal("metaʼ (Kamalun)", culture.native_name());
    }
    
    auto test_method_(mi) {
      auto culture = culture_info {"mi"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Māori", culture.display_name());
      assert::are_equal("Māori", culture.english_name());
      assert::are_equal(129_z, culture.keyboard_layout_id());
      assert::are_equal(129_z, culture.lcid());
      assert::are_equal("mi", culture.name());
      assert::are_equal("Māori", culture.native_name());
    }
    
    auto test_method_(mi_NZ) {
      auto culture = culture_info {"mi-NZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Māori (New Zealand)", culture.display_name());
      assert::are_equal("Māori (New Zealand)", culture.english_name());
      assert::are_equal(1153_z, culture.keyboard_layout_id());
      assert::are_equal(1153_z, culture.lcid());
      assert::are_equal("mi-NZ", culture.name());
      assert::are_equal("Māori (Aotearoa)", culture.native_name());
    }
    
    auto test_method_(mic) {
      auto culture = culture_info {"mic"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Mi’kmaw", culture.display_name());
      assert::are_equal("Mi’kmaw", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mic", culture.name());
      assert::are_equal("Lʼnuiʼsuti", culture.native_name());
    }
    
    auto test_method_(mic_CA) {
      auto culture = culture_info {"mic-CA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Mi’kmaw (Canada)", culture.display_name());
      assert::are_equal("Mi’kmaw (Canada)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mic-CA", culture.name());
      assert::are_equal("Mi’kmaw (Canada)", culture.native_name());
    }
    
    auto test_method_(mid) {
      auto culture = culture_info {"mid"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Mandaic", culture.display_name());
      assert::are_equal("Mandaic", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mid", culture.name());
      assert::are_equal("ࡌࡀࡍࡃࡀࡉࡀ", culture.native_name());
    }
    
    auto test_method_(mid_IQ) {
      auto culture = culture_info {"mid-IQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Mandaic (Iraq)", culture.display_name());
      assert::are_equal("Mandaic (Iraq)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mid-IQ", culture.name());
      assert::are_equal("Mandaic (Iraq)", culture.native_name());
    }
    
    auto test_method_(mk) {
      auto culture = culture_info {"mk"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Macedonian", culture.display_name());
      assert::are_equal("Macedonian", culture.english_name());
      assert::are_equal(47_z, culture.keyboard_layout_id());
      assert::are_equal(47_z, culture.lcid());
      assert::are_equal("mk", culture.name());
      assert::are_equal("македонски", culture.native_name());
    }
    
    auto test_method_(mk_MK) {
      auto culture = culture_info {"mk-MK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Macedonian (North Macedonia)", culture.display_name());
      assert::are_equal("Macedonian (North Macedonia)", culture.english_name());
      assert::are_equal(1071_z, culture.keyboard_layout_id());
      assert::are_equal(1071_z, culture.lcid());
      assert::are_equal("mk-MK", culture.name());
      assert::are_equal("македонски (Северна Македонија)", culture.native_name());
    }
    
    auto test_method_(ml) {
      auto culture = culture_info {"ml"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Malayalam", culture.display_name());
      assert::are_equal("Malayalam", culture.english_name());
      assert::are_equal(76_z, culture.keyboard_layout_id());
      assert::are_equal(76_z, culture.lcid());
      assert::are_equal("ml", culture.name());
      assert::are_equal("മലയാളം", culture.native_name());
    }
    
    auto test_method_(ml_IN) {
      auto culture = culture_info {"ml-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Malayalam (India)", culture.display_name());
      assert::are_equal("Malayalam (India)", culture.english_name());
      assert::are_equal(1100_z, culture.keyboard_layout_id());
      assert::are_equal(1100_z, culture.lcid());
      assert::are_equal("ml-IN", culture.name());
      assert::are_equal("മലയാളം (ഇന്ത്യ)", culture.native_name());
    }
    
    auto test_method_(mn) {
      auto culture = culture_info {"mn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Mongolian", culture.display_name());
      assert::are_equal("Mongolian", culture.english_name());
      assert::are_equal(80_z, culture.keyboard_layout_id());
      assert::are_equal(80_z, culture.lcid());
      assert::are_equal("mn", culture.name());
      assert::are_equal("монгол", culture.native_name());
    }
    
    auto test_method_(mn_MN) {
      auto culture = culture_info {"mn-MN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Mongolian (Mongolia)", culture.display_name());
      assert::are_equal("Mongolian (Mongolia)", culture.english_name());
      assert::are_equal(1104_z, culture.keyboard_layout_id());
      assert::are_equal(1104_z, culture.lcid());
      assert::are_equal("mn-MN", culture.name());
      assert::are_equal("монгол (Монгол)", culture.native_name());
    }
    
    auto test_method_(mni) {
      auto culture = culture_info {"mni"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Manipuri", culture.display_name());
      assert::are_equal("Manipuri", culture.english_name());
      assert::are_equal(88_z, culture.keyboard_layout_id());
      assert::are_equal(88_z, culture.lcid());
      assert::are_equal("mni", culture.name());
      assert::are_equal("মৈতৈলোন্", culture.native_name());
    }
    
    auto test_method_(mni_Beng) {
      auto culture = culture_info {"mni-Beng"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Manipuri (Bangla)", culture.display_name());
      assert::are_equal("Manipuri (Bangla)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mni-Beng", culture.name());
      assert::are_equal("মৈতৈলোন্ (বাংলা)", culture.native_name());
    }
    
    auto test_method_(mni_Beng_IN) {
      auto culture = culture_info {"mni-Beng-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Manipuri (Bangla, India)", culture.display_name());
      assert::are_equal("Manipuri (Bangla, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mni-Beng-IN", culture.name());
      assert::are_equal("মৈতৈলোন্ (বাংলা, ইন্দিয়া)", culture.native_name());
    }
    
    auto test_method_(mni_Mtei) {
      auto culture = culture_info {"mni-Mtei"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Manipuri (Meitei Mayek)", culture.display_name());
      assert::are_equal("Manipuri (Meitei Mayek)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mni-Mtei", culture.name());
      assert::are_equal("ꯃꯤꯇꯩꯂꯣꯟ (ꯃꯤꯇꯩ ꯃꯌꯦꯛ)", culture.native_name());
    }
    
    auto test_method_(mni_Mtei_IN) {
      auto culture = culture_info {"mni-Mtei-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Manipuri (Meitei Mayek, India)", culture.display_name());
      assert::are_equal("Manipuri (Meitei Mayek, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mni-Mtei-IN", culture.name());
      assert::are_equal("Manipuri (Meitei Mayek, India)", culture.native_name());
    }
    
    auto test_method_(moh) {
      auto culture = culture_info {"moh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Mohawk", culture.display_name());
      assert::are_equal("Mohawk", culture.english_name());
      assert::are_equal(124_z, culture.keyboard_layout_id());
      assert::are_equal(124_z, culture.lcid());
      assert::are_equal("moh", culture.name());
      assert::are_equal("Kanienʼkéha", culture.native_name());
    }
    
    auto test_method_(moh_CA) {
      auto culture = culture_info {"moh-CA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Mohawk (Canada)", culture.display_name());
      assert::are_equal("Mohawk (Canada)", culture.english_name());
      assert::are_equal(1148_z, culture.keyboard_layout_id());
      assert::are_equal(1148_z, culture.lcid());
      assert::are_equal("moh-CA", culture.name());
      assert::are_equal("Mohawk (Canada)", culture.native_name());
    }
    
    auto test_method_(mr) {
      auto culture = culture_info {"mr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Marathi", culture.display_name());
      assert::are_equal("Marathi", culture.english_name());
      assert::are_equal(78_z, culture.keyboard_layout_id());
      assert::are_equal(78_z, culture.lcid());
      assert::are_equal("mr", culture.name());
      assert::are_equal("मराठी", culture.native_name());
    }
    
    auto test_method_(mr_IN) {
      auto culture = culture_info {"mr-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Marathi (India)", culture.display_name());
      assert::are_equal("Marathi (India)", culture.english_name());
      assert::are_equal(1102_z, culture.keyboard_layout_id());
      assert::are_equal(1102_z, culture.lcid());
      assert::are_equal("mr-IN", culture.name());
      assert::are_equal("मराठी (भारत)", culture.native_name());
    }
    
    auto test_method_(ms) {
      auto culture = culture_info {"ms"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Malay", culture.display_name());
      assert::are_equal("Malay", culture.english_name());
      assert::are_equal(62_z, culture.keyboard_layout_id());
      assert::are_equal(62_z, culture.lcid());
      assert::are_equal("ms", culture.name());
      assert::are_equal("Bahasa Melayu", culture.native_name());
    }
    
    auto test_method_(ms_Arab) {
      auto culture = culture_info {"ms-Arab"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Malay (Arabic)", culture.display_name());
      assert::are_equal("Malay (Arabic)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ms-Arab", culture.name());
      assert::are_equal("بهاس ملايو (عرب)", culture.native_name());
    }
    
    auto test_method_(ms_Arab_BN) {
      auto culture = culture_info {"ms-Arab-BN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Malay (Arabic, Brunei)", culture.display_name());
      assert::are_equal("Malay (Arabic, Brunei)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ms-Arab-BN", culture.name());
      assert::are_equal("بهاس ملايو (عرب، بروني)", culture.native_name());
    }
    
    auto test_method_(ms_Arab_MY) {
      auto culture = culture_info {"ms-Arab-MY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Malay (Arabic, Malaysia)", culture.display_name());
      assert::are_equal("Malay (Arabic, Malaysia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ms-Arab-MY", culture.name());
      assert::are_equal("بهاس ملايو (عرب، مليسيا)", culture.native_name());
    }
    
    auto test_method_(ms_BN) {
      auto culture = culture_info {"ms-BN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Malay (Brunei)", culture.display_name());
      assert::are_equal("Malay (Brunei)", culture.english_name());
      assert::are_equal(2110_z, culture.keyboard_layout_id());
      assert::are_equal(2110_z, culture.lcid());
      assert::are_equal("ms-BN", culture.name());
      assert::are_equal("Bahasa Melayu (Brunei)", culture.native_name());
    }
    
    auto test_method_(ms_ID) {
      auto culture = culture_info {"ms-ID"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Malay (Indonesia)", culture.display_name());
      assert::are_equal("Malay (Indonesia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ms-ID", culture.name());
      assert::are_equal("Bahasa Melayu (Indonesia)", culture.native_name());
    }
    
    auto test_method_(ms_MY) {
      auto culture = culture_info {"ms-MY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Malay (Malaysia)", culture.display_name());
      assert::are_equal("Malay (Malaysia)", culture.english_name());
      assert::are_equal(1086_z, culture.keyboard_layout_id());
      assert::are_equal(1086_z, culture.lcid());
      assert::are_equal("ms-MY", culture.name());
      assert::are_equal("Bahasa Melayu (Malaysia)", culture.native_name());
    }
    
    auto test_method_(ms_SG) {
      auto culture = culture_info {"ms-SG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Malay (Singapore)", culture.display_name());
      assert::are_equal("Malay (Singapore)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ms-SG", culture.name());
      assert::are_equal("Bahasa Melayu (Singapura)", culture.native_name());
    }
    
    auto test_method_(mt) {
      auto culture = culture_info {"mt"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Maltese", culture.display_name());
      assert::are_equal("Maltese", culture.english_name());
      assert::are_equal(58_z, culture.keyboard_layout_id());
      assert::are_equal(58_z, culture.lcid());
      assert::are_equal("mt", culture.name());
      assert::are_equal("Malti", culture.native_name());
    }
    
    auto test_method_(mt_MT) {
      auto culture = culture_info {"mt-MT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Maltese (Malta)", culture.display_name());
      assert::are_equal("Maltese (Malta)", culture.english_name());
      assert::are_equal(1082_z, culture.keyboard_layout_id());
      assert::are_equal(1082_z, culture.lcid());
      assert::are_equal("mt-MT", culture.name());
      assert::are_equal("Malti (Malta)", culture.native_name());
    }
    
    auto test_method_(mua) {
      auto culture = culture_info {"mua"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Mundang", culture.display_name());
      assert::are_equal("Mundang", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mua", culture.name());
      assert::are_equal("MUNDAŊ", culture.native_name());
    }
    
    auto test_method_(mua_CM) {
      auto culture = culture_info {"mua-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Mundang (Cameroon)", culture.display_name());
      assert::are_equal("Mundang (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mua-CM", culture.name());
      assert::are_equal("MUNDAŊ (kameruŋ)", culture.native_name());
    }
    
    auto test_method_(mus) {
      auto culture = culture_info {"mus"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Mvskoke", culture.display_name());
      assert::are_equal("Mvskoke", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mus", culture.name());
      assert::are_equal("Mvskoke", culture.native_name());
    }
    
    auto test_method_(mus_US) {
      auto culture = culture_info {"mus-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Mvskoke (United States)", culture.display_name());
      assert::are_equal("Mvskoke (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mus-US", culture.name());
      assert::are_equal("Mvskoke (United States)", culture.native_name());
    }
    
    auto test_method_(my) {
      auto culture = culture_info {"my"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Burmese", culture.display_name());
      assert::are_equal("Burmese", culture.english_name());
      assert::are_equal(85_z, culture.keyboard_layout_id());
      assert::are_equal(85_z, culture.lcid());
      assert::are_equal("my", culture.name());
      assert::are_equal("မြန်မာ", culture.native_name());
    }
    
    auto test_method_(my_MM) {
      auto culture = culture_info {"my-MM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Burmese (Myanmar [Burma])", culture.display_name());
      assert::are_equal("Burmese (Myanmar [Burma])", culture.english_name());
      assert::are_equal(1109_z, culture.keyboard_layout_id());
      assert::are_equal(1109_z, culture.lcid());
      assert::are_equal("my-MM", culture.name());
      assert::are_equal("မြန်မာ (မြန်မာ)", culture.native_name());
    }
    
    auto test_method_(myv) {
      auto culture = culture_info {"myv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Erzya", culture.display_name());
      assert::are_equal("Erzya", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("myv", culture.name());
      assert::are_equal("эрзянь кель", culture.native_name());
    }
    
    auto test_method_(myv_RU) {
      auto culture = culture_info {"myv-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Erzya (Russia)", culture.display_name());
      assert::are_equal("Erzya (Russia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("myv-RU", culture.name());
      assert::are_equal("эрзянь кель (Рузонь мастор)", culture.native_name());
    }
    
    auto test_method_(mzn) {
      auto culture = culture_info {"mzn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Mazanderani", culture.display_name());
      assert::are_equal("Mazanderani", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mzn", culture.name());
      assert::are_equal("مازرونی", culture.native_name());
    }
    
    auto test_method_(mzn_IR) {
      auto culture = culture_info {"mzn-IR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Mazanderani (Iran)", culture.display_name());
      assert::are_equal("Mazanderani (Iran)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("mzn-IR", culture.name());
      assert::are_equal("مازرونی (ایران)", culture.native_name());
    }
    
    auto test_method_(naq) {
      auto culture = culture_info {"naq"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Nama", culture.display_name());
      assert::are_equal("Nama", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("naq", culture.name());
      assert::are_equal("Khoekhoegowab", culture.native_name());
    }
    
    auto test_method_(naq_NA) {
      auto culture = culture_info {"naq-NA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nama (Namibia)", culture.display_name());
      assert::are_equal("Nama (Namibia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("naq-NA", culture.name());
      assert::are_equal("Khoekhoegowab (Namibiab)", culture.native_name());
    }
    
    auto test_method_(nb) {
      auto culture = culture_info {"nb"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Norwegian Bokmål", culture.display_name());
      assert::are_equal("Norwegian Bokmål", culture.english_name());
      assert::are_equal(31764_z, culture.keyboard_layout_id());
      assert::are_equal(31764_z, culture.lcid());
      assert::are_equal("nb", culture.name());
      assert::are_equal("norsk bokmål", culture.native_name());
    }
    
    auto test_method_(nb_NO) {
      auto culture = culture_info {"nb-NO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Norwegian Bokmål (Norway)", culture.display_name());
      assert::are_equal("Norwegian Bokmål (Norway)", culture.english_name());
      assert::are_equal(1044_z, culture.keyboard_layout_id());
      assert::are_equal(1044_z, culture.lcid());
      assert::are_equal("nb-NO", culture.name());
      assert::are_equal("norsk bokmål (Norge)", culture.native_name());
    }
    
    auto test_method_(nb_SJ) {
      auto culture = culture_info {"nb-SJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Norwegian Bokmål (Svalbard & Jan Mayen)", culture.display_name());
      assert::are_equal("Norwegian Bokmål (Svalbard & Jan Mayen)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nb-SJ", culture.name());
      assert::are_equal("norsk bokmål (Svalbard og Jan Mayen)", culture.native_name());
    }
    
    auto test_method_(nd) {
      auto culture = culture_info {"nd"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("North Ndebele", culture.display_name());
      assert::are_equal("North Ndebele", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nd", culture.name());
      assert::are_equal("isiNdebele", culture.native_name());
    }
    
    auto test_method_(nd_ZW) {
      auto culture = culture_info {"nd-ZW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("North Ndebele (Zimbabwe)", culture.display_name());
      assert::are_equal("North Ndebele (Zimbabwe)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nd-ZW", culture.name());
      assert::are_equal("isiNdebele (Zimbabwe)", culture.native_name());
    }
    
    auto test_method_(nds) {
      auto culture = culture_info {"nds"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Low German", culture.display_name());
      assert::are_equal("Low German", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nds", culture.name());
      assert::are_equal("Neddersass’sch", culture.native_name());
    }
    
    auto test_method_(nds_DE) {
      auto culture = culture_info {"nds-DE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Low German (Germany)", culture.display_name());
      assert::are_equal("Low German (Germany)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nds-DE", culture.name());
      assert::are_equal("Neddersass’sch (Düütschland)", culture.native_name());
    }
    
    auto test_method_(nds_NL) {
      auto culture = culture_info {"nds-NL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Low German (Netherlands)", culture.display_name());
      assert::are_equal("Low German (Netherlands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nds-NL", culture.name());
      assert::are_equal("Neddersass’sch (Nedderlannen)", culture.native_name());
    }
    
    auto test_method_(ne) {
      auto culture = culture_info {"ne"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Nepali", culture.display_name());
      assert::are_equal("Nepali", culture.english_name());
      assert::are_equal(97_z, culture.keyboard_layout_id());
      assert::are_equal(97_z, culture.lcid());
      assert::are_equal("ne", culture.name());
      assert::are_equal("नेपाली", culture.native_name());
    }
    
    auto test_method_(ne_IN) {
      auto culture = culture_info {"ne-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nepali (India)", culture.display_name());
      assert::are_equal("Nepali (India)", culture.english_name());
      assert::are_equal(2145_z, culture.keyboard_layout_id());
      assert::are_equal(2145_z, culture.lcid());
      assert::are_equal("ne-IN", culture.name());
      assert::are_equal("नेपाली (भारत)", culture.native_name());
    }
    
    auto test_method_(ne_NP) {
      auto culture = culture_info {"ne-NP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nepali (Nepal)", culture.display_name());
      assert::are_equal("Nepali (Nepal)", culture.english_name());
      assert::are_equal(1121_z, culture.keyboard_layout_id());
      assert::are_equal(1121_z, culture.lcid());
      assert::are_equal("ne-NP", culture.name());
      assert::are_equal("नेपाली (नेपाल)", culture.native_name());
    }
    
    auto test_method_(nl) {
      auto culture = culture_info {"nl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Dutch", culture.display_name());
      assert::are_equal("Dutch", culture.english_name());
      assert::are_equal(19_z, culture.keyboard_layout_id());
      assert::are_equal(19_z, culture.lcid());
      assert::are_equal("nl", culture.name());
      assert::are_equal("Nederlands", culture.native_name());
    }
    
    auto test_method_(nl_AW) {
      auto culture = culture_info {"nl-AW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dutch (Aruba)", culture.display_name());
      assert::are_equal("Dutch (Aruba)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nl-AW", culture.name());
      assert::are_equal("Nederlands (Aruba)", culture.native_name());
    }
    
    auto test_method_(nl_BE) {
      auto culture = culture_info {"nl-BE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dutch (Belgium)", culture.display_name());
      assert::are_equal("Dutch (Belgium)", culture.english_name());
      assert::are_equal(2067_z, culture.keyboard_layout_id());
      assert::are_equal(2067_z, culture.lcid());
      assert::are_equal("nl-BE", culture.name());
      assert::are_equal("Nederlands (België)", culture.native_name());
    }
    
    auto test_method_(nl_BQ) {
      auto culture = culture_info {"nl-BQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dutch (Caribbean Netherlands)", culture.display_name());
      assert::are_equal("Dutch (Caribbean Netherlands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nl-BQ", culture.name());
      assert::are_equal("Nederlands (Caribisch Nederland)", culture.native_name());
    }
    
    auto test_method_(nl_CW) {
      auto culture = culture_info {"nl-CW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dutch (Curaçao)", culture.display_name());
      assert::are_equal("Dutch (Curaçao)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nl-CW", culture.name());
      assert::are_equal("Nederlands (Curaçao)", culture.native_name());
    }
    
    auto test_method_(nl_NL) {
      auto culture = culture_info {"nl-NL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dutch (Netherlands)", culture.display_name());
      assert::are_equal("Dutch (Netherlands)", culture.english_name());
      assert::are_equal(1043_z, culture.keyboard_layout_id());
      assert::are_equal(1043_z, culture.lcid());
      assert::are_equal("nl-NL", culture.name());
      assert::are_equal("Nederlands (Nederland)", culture.native_name());
    }
    
    auto test_method_(nl_SR) {
      auto culture = culture_info {"nl-SR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dutch (Suriname)", culture.display_name());
      assert::are_equal("Dutch (Suriname)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nl-SR", culture.name());
      assert::are_equal("Nederlands (Suriname)", culture.native_name());
    }
    
    auto test_method_(nl_SX) {
      auto culture = culture_info {"nl-SX"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Dutch (Sint Maarten)", culture.display_name());
      assert::are_equal("Dutch (Sint Maarten)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nl-SX", culture.name());
      assert::are_equal("Nederlands (Sint-Maarten)", culture.native_name());
    }
    
    auto test_method_(nmg) {
      auto culture = culture_info {"nmg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kwasio", culture.display_name());
      assert::are_equal("Kwasio", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nmg", culture.name());
      assert::are_equal("Kwasio", culture.native_name());
    }
    
    auto test_method_(nmg_CM) {
      auto culture = culture_info {"nmg-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kwasio (Cameroon)", culture.display_name());
      assert::are_equal("Kwasio (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nmg-CM", culture.name());
      assert::are_equal("Kwasio (Cameroon)", culture.native_name());
    }
    
    auto test_method_(nn) {
      auto culture = culture_info {"nn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Norwegian Nynorsk", culture.display_name());
      assert::are_equal("Norwegian Nynorsk", culture.english_name());
      assert::are_equal(30740_z, culture.keyboard_layout_id());
      assert::are_equal(30740_z, culture.lcid());
      assert::are_equal("nn", culture.name());
      assert::are_equal("norsk nynorsk", culture.native_name());
    }
    
    auto test_method_(nn_NO) {
      auto culture = culture_info {"nn-NO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Norwegian Nynorsk (Norway)", culture.display_name());
      assert::are_equal("Norwegian Nynorsk (Norway)", culture.english_name());
      assert::are_equal(2068_z, culture.keyboard_layout_id());
      assert::are_equal(2068_z, culture.lcid());
      assert::are_equal("nn-NO", culture.name());
      assert::are_equal("norsk nynorsk (Noreg)", culture.native_name());
    }
    
    auto test_method_(nnh) {
      auto culture = culture_info {"nnh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ngiemboon", culture.display_name());
      assert::are_equal("Ngiemboon", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nnh", culture.name());
      assert::are_equal("Shwóŋò ngiembɔɔn", culture.native_name());
    }
    
    auto test_method_(nnh_CM) {
      auto culture = culture_info {"nnh-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ngiemboon (Cameroon)", culture.display_name());
      assert::are_equal("Ngiemboon (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nnh-CM", culture.name());
      assert::are_equal("Shwóŋò ngiembɔɔn (Kàmalûm)", culture.native_name());
    }
    
    auto test_method_(nnp) {
      auto culture = culture_info {"nnp"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Wancho", culture.display_name());
      assert::are_equal("Wancho", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nnp", culture.name());
      assert::are_equal("𞋒𞋀𞋉𞋃𞋕", culture.native_name());
    }
    
    auto test_method_(nnp_IN) {
      auto culture = culture_info {"nnp-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Wancho (India)", culture.display_name());
      assert::are_equal("Wancho (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nnp-IN", culture.name());
      assert::are_equal("Wancho (India)", culture.native_name());
    }
    
    auto test_method_(no) {
      auto culture = culture_info {"no"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Norwegian", culture.display_name());
      assert::are_equal("Norwegian", culture.english_name());
      assert::are_equal(20_z, culture.keyboard_layout_id());
      assert::are_equal(20_z, culture.lcid());
      assert::are_equal("no", culture.name());
      assert::are_equal("norsk", culture.native_name());
    }
    
    auto test_method_(nqo) {
      auto culture = culture_info {"nqo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("N’Ko", culture.display_name());
      assert::are_equal("N’Ko", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nqo", culture.name());
      assert::are_equal("ߒߞߏ", culture.native_name());
    }
    
    auto test_method_(nqo_GN) {
      auto culture = culture_info {"nqo-GN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("N’Ko (Guinea)", culture.display_name());
      assert::are_equal("N’Ko (Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nqo-GN", culture.name());
      assert::are_equal("ߒߞߏ (ߖߌ߬ߣߍ߫)", culture.native_name());
    }
    
    auto test_method_(nr) {
      auto culture = culture_info {"nr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("South Ndebele", culture.display_name());
      assert::are_equal("South Ndebele", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nr", culture.name());
      assert::are_equal("South Ndebele", culture.native_name());
    }
    
    auto test_method_(nr_ZA) {
      auto culture = culture_info {"nr-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("South Ndebele (South Africa)", culture.display_name());
      assert::are_equal("South Ndebele (South Africa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nr-ZA", culture.name());
      assert::are_equal("South Ndebele (South Africa)", culture.native_name());
    }
    
    auto test_method_(nso) {
      auto culture = culture_info {"nso"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Northern Sotho", culture.display_name());
      assert::are_equal("Northern Sotho", culture.english_name());
      assert::are_equal(108_z, culture.keyboard_layout_id());
      assert::are_equal(108_z, culture.lcid());
      assert::are_equal("nso", culture.name());
      assert::are_equal("Sesotho sa Leboa", culture.native_name());
    }
    
    auto test_method_(nso_ZA) {
      auto culture = culture_info {"nso-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Northern Sotho (South Africa)", culture.display_name());
      assert::are_equal("Northern Sotho (South Africa)", culture.english_name());
      assert::are_equal(1132_z, culture.keyboard_layout_id());
      assert::are_equal(1132_z, culture.lcid());
      assert::are_equal("nso-ZA", culture.name());
      assert::are_equal("Sesotho sa Leboa (Afrika Borwa)", culture.native_name());
    }
    
    auto test_method_(nus) {
      auto culture = culture_info {"nus"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Nuer", culture.display_name());
      assert::are_equal("Nuer", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nus", culture.name());
      assert::are_equal("Thok Nath", culture.native_name());
    }
    
    auto test_method_(nus_SS) {
      auto culture = culture_info {"nus-SS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nuer (South Sudan)", culture.display_name());
      assert::are_equal("Nuer (South Sudan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nus-SS", culture.name());
      assert::are_equal("Nuer (South Sudan)", culture.native_name());
    }
    
    auto test_method_(nv) {
      auto culture = culture_info {"nv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Navajo", culture.display_name());
      assert::are_equal("Navajo", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nv", culture.name());
      assert::are_equal("Diné Bizaad", culture.native_name());
    }
    
    auto test_method_(nv_US) {
      auto culture = culture_info {"nv-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Navajo (United States)", culture.display_name());
      assert::are_equal("Navajo (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nv-US", culture.name());
      assert::are_equal("Navajo (United States)", culture.native_name());
    }
    
    auto test_method_(ny) {
      auto culture = culture_info {"ny"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Nyanja", culture.display_name());
      assert::are_equal("Nyanja", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ny", culture.name());
      assert::are_equal("Nyanja", culture.native_name());
    }
    
    auto test_method_(ny_MW) {
      auto culture = culture_info {"ny-MW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nyanja (Malawi)", culture.display_name());
      assert::are_equal("Nyanja (Malawi)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ny-MW", culture.name());
      assert::are_equal("Nyanja (Malawi)", culture.native_name());
    }
    
    auto test_method_(nyn) {
      auto culture = culture_info {"nyn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Nyankole", culture.display_name());
      assert::are_equal("Nyankole", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nyn", culture.name());
      assert::are_equal("Runyankore", culture.native_name());
    }
    
    auto test_method_(nyn_UG) {
      auto culture = culture_info {"nyn-UG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nyankole (Uganda)", culture.display_name());
      assert::are_equal("Nyankole (Uganda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("nyn-UG", culture.name());
      assert::are_equal("Runyankore (Uganda)", culture.native_name());
    }
    
    auto test_method_(oc) {
      auto culture = culture_info {"oc"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Occitan", culture.display_name());
      assert::are_equal("Occitan", culture.english_name());
      assert::are_equal(130_z, culture.keyboard_layout_id());
      assert::are_equal(130_z, culture.lcid());
      assert::are_equal("oc", culture.name());
      assert::are_equal("occitan", culture.native_name());
    }
    
    auto test_method_(oc_ES) {
      auto culture = culture_info {"oc-ES"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Occitan (Spain)", culture.display_name());
      assert::are_equal("Occitan (Spain)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("oc-ES", culture.name());
      assert::are_equal("occitan (Espanha)", culture.native_name());
    }
    
    auto test_method_(oc_FR) {
      auto culture = culture_info {"oc-FR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Occitan (France)", culture.display_name());
      assert::are_equal("Occitan (France)", culture.english_name());
      assert::are_equal(1154_z, culture.keyboard_layout_id());
      assert::are_equal(1154_z, culture.lcid());
      assert::are_equal("oc-FR", culture.name());
      assert::are_equal("occitan (França)", culture.native_name());
    }
    
    auto test_method_(om) {
      auto culture = culture_info {"om"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Oromo", culture.display_name());
      assert::are_equal("Oromo", culture.english_name());
      assert::are_equal(114_z, culture.keyboard_layout_id());
      assert::are_equal(114_z, culture.lcid());
      assert::are_equal("om", culture.name());
      assert::are_equal("Oromoo", culture.native_name());
    }
    
    auto test_method_(om_ET) {
      auto culture = culture_info {"om-ET"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Oromo (Ethiopia)", culture.display_name());
      assert::are_equal("Oromo (Ethiopia)", culture.english_name());
      assert::are_equal(1138_z, culture.keyboard_layout_id());
      assert::are_equal(1138_z, culture.lcid());
      assert::are_equal("om-ET", culture.name());
      assert::are_equal("Oromoo (Itoophiyaa)", culture.native_name());
    }
    
    auto test_method_(om_KE) {
      auto culture = culture_info {"om-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Oromo (Kenya)", culture.display_name());
      assert::are_equal("Oromo (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("om-KE", culture.name());
      assert::are_equal("Oromoo (Keeniyaa)", culture.native_name());
    }
    
    auto test_method_(or_) {
      auto culture = culture_info {"or"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Odia", culture.display_name());
      assert::are_equal("Odia", culture.english_name());
      assert::are_equal(72_z, culture.keyboard_layout_id());
      assert::are_equal(72_z, culture.lcid());
      assert::are_equal("or", culture.name());
      assert::are_equal("ଓଡ଼ିଆ", culture.native_name());
    }
    
    auto test_method_(or_IN) {
      auto culture = culture_info {"or-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Odia (India)", culture.display_name());
      assert::are_equal("Odia (India)", culture.english_name());
      assert::are_equal(1096_z, culture.keyboard_layout_id());
      assert::are_equal(1096_z, culture.lcid());
      assert::are_equal("or-IN", culture.name());
      assert::are_equal("ଓଡ଼ିଆ (ଭାରତ)", culture.native_name());
    }
    
    auto test_method_(os) {
      auto culture = culture_info {"os"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ossetic", culture.display_name());
      assert::are_equal("Ossetic", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("os", culture.name());
      assert::are_equal("ирон", culture.native_name());
    }
    
    auto test_method_(os_GE) {
      auto culture = culture_info {"os-GE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ossetic (Georgia)", culture.display_name());
      assert::are_equal("Ossetic (Georgia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("os-GE", culture.name());
      assert::are_equal("ирон (Гуырдзыстон)", culture.native_name());
    }
    
    auto test_method_(os_RU) {
      auto culture = culture_info {"os-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ossetic (Russia)", culture.display_name());
      assert::are_equal("Ossetic (Russia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("os-RU", culture.name());
      assert::are_equal("ирон (Уӕрӕсе)", culture.native_name());
    }
    
    auto test_method_(osa) {
      auto culture = culture_info {"osa"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Osage", culture.display_name());
      assert::are_equal("Osage", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("osa", culture.name());
      assert::are_equal("𐓏𐓘𐓻𐓘𐓻𐓟", culture.native_name());
    }
    
    auto test_method_(osa_US) {
      auto culture = culture_info {"osa-US"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Osage (United States)", culture.display_name());
      assert::are_equal("Osage (United States)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("osa-US", culture.name());
      assert::are_equal("𐓏𐓘𐓻𐓘𐓻𐓟 (United States)", culture.native_name());
    }
    
    auto test_method_(pa) {
      auto culture = culture_info {"pa"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Punjabi", culture.display_name());
      assert::are_equal("Punjabi", culture.english_name());
      assert::are_equal(70_z, culture.keyboard_layout_id());
      assert::are_equal(70_z, culture.lcid());
      assert::are_equal("pa", culture.name());
      assert::are_equal("ਪੰਜਾਬੀ", culture.native_name());
    }
    
    auto test_method_(pa_Arab) {
      auto culture = culture_info {"pa-Arab"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Punjabi (Naskh)", culture.display_name());
      assert::are_equal("Punjabi (Naskh)", culture.english_name());
      assert::are_equal(31814_z, culture.keyboard_layout_id());
      assert::are_equal(31814_z, culture.lcid());
      assert::are_equal("pa-Arab", culture.name());
      assert::are_equal("پنجابی (نسخ)", culture.native_name());
    }
    
    auto test_method_(pa_Arab_PK) {
      auto culture = culture_info {"pa-Arab-PK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Punjabi (Naskh, Pakistan)", culture.display_name());
      assert::are_equal("Punjabi (Naskh, Pakistan)", culture.english_name());
      assert::are_equal(2118_z, culture.keyboard_layout_id());
      assert::are_equal(2118_z, culture.lcid());
      assert::are_equal("pa-Arab-PK", culture.name());
      assert::are_equal("پنجابی (نسخ, پاکستان)", culture.native_name());
    }
    
    auto test_method_(pa_Aran_PK) {
      auto culture = culture_info {"pa-Aran-PK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Punjabi (Nastaliq, Pakistan)", culture.display_name());
      assert::are_equal("Punjabi (Nastaliq, Pakistan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pa-Aran-PK", culture.name());
      assert::are_equal("پنجابی (نستعلیق, پاکستان)", culture.native_name());
    }
    
    auto test_method_(pa_Guru) {
      auto culture = culture_info {"pa-Guru"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Punjabi (Gurmukhi)", culture.display_name());
      assert::are_equal("Punjabi (Gurmukhi)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pa-Guru", culture.name());
      assert::are_equal("ਪੰਜਾਬੀ (ਗੁਰਮੁਖੀ)", culture.native_name());
    }
    
    auto test_method_(pa_Guru_IN) {
      auto culture = culture_info {"pa-Guru-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Punjabi (Gurmukhi, India)", culture.display_name());
      assert::are_equal("Punjabi (Gurmukhi, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pa-Guru-IN", culture.name());
      assert::are_equal("ਪੰਜਾਬੀ (ਗੁਰਮੁਖੀ, ਭਾਰਤ)", culture.native_name());
    }
    
    auto test_method_(pcm) {
      auto culture = culture_info {"pcm"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Nigerian Pidgin", culture.display_name());
      assert::are_equal("Nigerian Pidgin", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pcm", culture.name());
      assert::are_equal("Naijíriá Píjin", culture.native_name());
    }
    
    auto test_method_(pcm_NG) {
      auto culture = culture_info {"pcm-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nigerian Pidgin (Nigeria)", culture.display_name());
      assert::are_equal("Nigerian Pidgin (Nigeria)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pcm-NG", culture.name());
      assert::are_equal("Naijíriá Píjin (Naijíria)", culture.native_name());
    }
    
    auto test_method_(pl) {
      auto culture = culture_info {"pl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Polish", culture.display_name());
      assert::are_equal("Polish", culture.english_name());
      assert::are_equal(21_z, culture.keyboard_layout_id());
      assert::are_equal(21_z, culture.lcid());
      assert::are_equal("pl", culture.name());
      assert::are_equal("polski", culture.native_name());
    }
    
    auto test_method_(pl_PL) {
      auto culture = culture_info {"pl-PL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Polish (Poland)", culture.display_name());
      assert::are_equal("Polish (Poland)", culture.english_name());
      assert::are_equal(1045_z, culture.keyboard_layout_id());
      assert::are_equal(1045_z, culture.lcid());
      assert::are_equal("pl-PL", culture.name());
      assert::are_equal("polski (Polska)", culture.native_name());
    }
    
    auto test_method_(pqm) {
      auto culture = culture_info {"pqm"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Wolastoqey", culture.display_name());
      assert::are_equal("Wolastoqey", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pqm", culture.name());
      assert::are_equal("Wolastoqey", culture.native_name());
    }
    
    auto test_method_(pqm_CA) {
      auto culture = culture_info {"pqm-CA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Wolastoqey (Canada)", culture.display_name());
      assert::are_equal("Wolastoqey (Canada)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pqm-CA", culture.name());
      assert::are_equal("Wolastoqey (Canada)", culture.native_name());
    }
    
    auto test_method_(prg) {
      auto culture = culture_info {"prg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Prussian", culture.display_name());
      assert::are_equal("Prussian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("prg", culture.name());
      assert::are_equal("prūsiskan", culture.native_name());
    }
    
    auto test_method_(prg_PL) {
      auto culture = culture_info {"prg-PL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Prussian (Poland)", culture.display_name());
      assert::are_equal("Prussian (Poland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("prg-PL", culture.name());
      assert::are_equal("prūsiskan (Pōli)", culture.native_name());
    }
    
    auto test_method_(ps) {
      auto culture = culture_info {"ps"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Pashto", culture.display_name());
      assert::are_equal("Pashto", culture.english_name());
      assert::are_equal(99_z, culture.keyboard_layout_id());
      assert::are_equal(99_z, culture.lcid());
      assert::are_equal("ps", culture.name());
      assert::are_equal("پښتو", culture.native_name());
    }
    
    auto test_method_(ps_AF) {
      auto culture = culture_info {"ps-AF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Pashto (Afghanistan)", culture.display_name());
      assert::are_equal("Pashto (Afghanistan)", culture.english_name());
      assert::are_equal(1123_z, culture.keyboard_layout_id());
      assert::are_equal(1123_z, culture.lcid());
      assert::are_equal("ps-AF", culture.name());
      assert::are_equal("پښتو (افغانستان)", culture.native_name());
    }
    
    auto test_method_(ps_PK) {
      auto culture = culture_info {"ps-PK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Pashto (Pakistan)", culture.display_name());
      assert::are_equal("Pashto (Pakistan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ps-PK", culture.name());
      assert::are_equal("پښتو (پاکستان)", culture.native_name());
    }
    
    auto test_method_(pt) {
      auto culture = culture_info {"pt"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Portuguese", culture.display_name());
      assert::are_equal("Portuguese", culture.english_name());
      assert::are_equal(22_z, culture.keyboard_layout_id());
      assert::are_equal(22_z, culture.lcid());
      assert::are_equal("pt", culture.name());
      assert::are_equal("português", culture.native_name());
    }
    
    auto test_method_(pt_AO) {
      auto culture = culture_info {"pt-AO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Angola)", culture.display_name());
      assert::are_equal("Portuguese (Angola)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-AO", culture.name());
      assert::are_equal("português (Angola)", culture.native_name());
    }
    
    auto test_method_(pt_BR) {
      auto culture = culture_info {"pt-BR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Brazil)", culture.display_name());
      assert::are_equal("Portuguese (Brazil)", culture.english_name());
      assert::are_equal(1046_z, culture.keyboard_layout_id());
      assert::are_equal(1046_z, culture.lcid());
      assert::are_equal("pt-BR", culture.name());
      assert::are_equal("português (Brasil)", culture.native_name());
    }
    
    auto test_method_(pt_CH) {
      auto culture = culture_info {"pt-CH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Switzerland)", culture.display_name());
      assert::are_equal("Portuguese (Switzerland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-CH", culture.name());
      assert::are_equal("português (Suíça)", culture.native_name());
    }
    
    auto test_method_(pt_CV) {
      auto culture = culture_info {"pt-CV"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Cape Verde)", culture.display_name());
      assert::are_equal("Portuguese (Cape Verde)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-CV", culture.name());
      assert::are_equal("português (Cabo Verde)", culture.native_name());
    }
    
    auto test_method_(pt_FR) {
      auto culture = culture_info {"pt-FR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (France)", culture.display_name());
      assert::are_equal("Portuguese (France)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-FR", culture.name());
      assert::are_equal("português (França)", culture.native_name());
    }
    
    auto test_method_(pt_GQ) {
      auto culture = culture_info {"pt-GQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Equatorial Guinea)", culture.display_name());
      assert::are_equal("Portuguese (Equatorial Guinea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-GQ", culture.name());
      assert::are_equal("português (Guiné Equatorial)", culture.native_name());
    }
    
    auto test_method_(pt_GW) {
      auto culture = culture_info {"pt-GW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Guinea-Bissau)", culture.display_name());
      assert::are_equal("Portuguese (Guinea-Bissau)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-GW", culture.name());
      assert::are_equal("português (Guiné-Bissau)", culture.native_name());
    }
    
    auto test_method_(pt_LU) {
      auto culture = culture_info {"pt-LU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Luxembourg)", culture.display_name());
      assert::are_equal("Portuguese (Luxembourg)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-LU", culture.name());
      assert::are_equal("português (Luxemburgo)", culture.native_name());
    }
    
    auto test_method_(pt_MO) {
      auto culture = culture_info {"pt-MO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Macao)", culture.display_name());
      assert::are_equal("Portuguese (Macao)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-MO", culture.name());
      assert::are_equal("português (Macau)", culture.native_name());
    }
    
    auto test_method_(pt_MZ) {
      auto culture = culture_info {"pt-MZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Mozambique)", culture.display_name());
      assert::are_equal("Portuguese (Mozambique)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-MZ", culture.name());
      assert::are_equal("português (Moçambique)", culture.native_name());
    }
    
    auto test_method_(pt_PT) {
      auto culture = culture_info {"pt-PT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Portugal)", culture.display_name());
      assert::are_equal("Portuguese (Portugal)", culture.english_name());
      assert::are_equal(2070_z, culture.keyboard_layout_id());
      assert::are_equal(2070_z, culture.lcid());
      assert::are_equal("pt-PT", culture.name());
      assert::are_equal("português (Portugal)", culture.native_name());
    }
    
    auto test_method_(pt_ST) {
      auto culture = culture_info {"pt-ST"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (São Tomé & Príncipe)", culture.display_name());
      assert::are_equal("Portuguese (São Tomé & Príncipe)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-ST", culture.name());
      assert::are_equal("português (São Tomé e Príncipe)", culture.native_name());
    }
    
    auto test_method_(pt_TL) {
      auto culture = culture_info {"pt-TL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Portuguese (Timor-Leste)", culture.display_name());
      assert::are_equal("Portuguese (Timor-Leste)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("pt-TL", culture.name());
      assert::are_equal("português (Timor-Leste)", culture.native_name());
    }
    
    auto test_method_(qu) {
      auto culture = culture_info {"qu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Quechua", culture.display_name());
      assert::are_equal("Quechua", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("qu", culture.name());
      assert::are_equal("Runasimi", culture.native_name());
    }
    
    auto test_method_(qu_BO) {
      auto culture = culture_info {"qu-BO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Quechua (Bolivia)", culture.display_name());
      assert::are_equal("Quechua (Bolivia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("qu-BO", culture.name());
      assert::are_equal("Runasimi (Bolivia)", culture.native_name());
    }
    
    auto test_method_(qu_EC) {
      auto culture = culture_info {"qu-EC"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Quechua (Ecuador)", culture.display_name());
      assert::are_equal("Quechua (Ecuador)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("qu-EC", culture.name());
      assert::are_equal("Runasimi (Ecuador)", culture.native_name());
    }
    
    auto test_method_(qu_PE) {
      auto culture = culture_info {"qu-PE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Quechua (Peru)", culture.display_name());
      assert::are_equal("Quechua (Peru)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("qu-PE", culture.name());
      assert::are_equal("Runasimi (Perú)", culture.native_name());
    }
    
    auto test_method_(raj) {
      auto culture = culture_info {"raj"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Rajasthani", culture.display_name());
      assert::are_equal("Rajasthani", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("raj", culture.name());
      assert::are_equal("राजस्थानी", culture.native_name());
    }
    
    auto test_method_(raj_IN) {
      auto culture = culture_info {"raj-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Rajasthani (India)", culture.display_name());
      assert::are_equal("Rajasthani (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("raj-IN", culture.name());
      assert::are_equal("राजस्थानी (भारत)", culture.native_name());
    }
    
    auto test_method_(rej) {
      auto culture = culture_info {"rej"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Rejang", culture.display_name());
      assert::are_equal("Rejang", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rej", culture.name());
      assert::are_equal("Baso Hejang", culture.native_name());
    }
    
    auto test_method_(rej_ID) {
      auto culture = culture_info {"rej-ID"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Rejang (Indonesia)", culture.display_name());
      assert::are_equal("Rejang (Indonesia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rej-ID", culture.name());
      assert::are_equal("Rejang (Indonesia)", culture.native_name());
    }
    
    auto test_method_(rej_Rjng) {
      auto culture = culture_info {"rej-Rjng"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Rejang (Rejang)", culture.display_name());
      assert::are_equal("Rejang (Rejang)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rej-Rjng", culture.name());
      assert::are_equal("ꤷꤼꥋ ꤽꥍꤺꥏ (ꥆꤰ꥓ꤼꤽ ꤽꥍꤺꥏ)", culture.native_name());
    }
    
    auto test_method_(rej_Rjng_ID) {
      auto culture = culture_info {"rej-Rjng-ID"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Rejang (Rejang, Indonesia)", culture.display_name());
      assert::are_equal("Rejang (Rejang, Indonesia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rej-Rjng-ID", culture.name());
      assert::are_equal("Rejang (Rejang, Indonesia)", culture.native_name());
    }
    
    auto test_method_(rhg) {
      auto culture = culture_info {"rhg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Rohingya", culture.display_name());
      assert::are_equal("Rohingya", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rhg", culture.name());
      assert::are_equal("𐴌𐴗𐴥𐴝𐴙𐴚𐴒𐴙𐴝", culture.native_name());
    }
    
    auto test_method_(rhg_Rohg) {
      auto culture = culture_info {"rhg-Rohg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Rohingya (Hanifi)", culture.display_name());
      assert::are_equal("Rohingya (Hanifi)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rhg-Rohg", culture.name());
      assert::are_equal("Rohingya (Hanifi)", culture.native_name());
    }
    
    auto test_method_(rhg_Rohg_BD) {
      auto culture = culture_info {"rhg-Rohg-BD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Rohingya (Hanifi, Bangladesh)", culture.display_name());
      assert::are_equal("Rohingya (Hanifi, Bangladesh)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rhg-Rohg-BD", culture.name());
      assert::are_equal("Rohingya (Hanifi, Bangladesh)", culture.native_name());
    }
    
    auto test_method_(rhg_Rohg_MM) {
      auto culture = culture_info {"rhg-Rohg-MM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Rohingya (Hanifi, Myanmar [Burma])", culture.display_name());
      assert::are_equal("Rohingya (Hanifi, Myanmar [Burma])", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rhg-Rohg-MM", culture.name());
      assert::are_equal("Rohingya (Hanifi, Myanmar [Burma])", culture.native_name());
    }
    
    auto test_method_(rm) {
      auto culture = culture_info {"rm"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Romansh", culture.display_name());
      assert::are_equal("Romansh", culture.english_name());
      assert::are_equal(23_z, culture.keyboard_layout_id());
      assert::are_equal(23_z, culture.lcid());
      assert::are_equal("rm", culture.name());
      assert::are_equal("rumantsch", culture.native_name());
    }
    
    auto test_method_(rm_CH) {
      auto culture = culture_info {"rm-CH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Romansh (Switzerland)", culture.display_name());
      assert::are_equal("Romansh (Switzerland)", culture.english_name());
      assert::are_equal(1047_z, culture.keyboard_layout_id());
      assert::are_equal(1047_z, culture.lcid());
      assert::are_equal("rm-CH", culture.name());
      assert::are_equal("rumantsch (Svizra)", culture.native_name());
    }
    
    auto test_method_(rn) {
      auto culture = culture_info {"rn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Rundi", culture.display_name());
      assert::are_equal("Rundi", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rn", culture.name());
      assert::are_equal("Ikirundi", culture.native_name());
    }
    
    auto test_method_(rn_BI) {
      auto culture = culture_info {"rn-BI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Rundi (Burundi)", culture.display_name());
      assert::are_equal("Rundi (Burundi)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rn-BI", culture.name());
      assert::are_equal("Ikirundi (Uburundi)", culture.native_name());
    }
    
    auto test_method_(ro) {
      auto culture = culture_info {"ro"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Romanian", culture.display_name());
      assert::are_equal("Romanian", culture.english_name());
      assert::are_equal(24_z, culture.keyboard_layout_id());
      assert::are_equal(24_z, culture.lcid());
      assert::are_equal("ro", culture.name());
      assert::are_equal("română", culture.native_name());
    }
    
    auto test_method_(ro_MD) {
      auto culture = culture_info {"ro-MD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Romanian (Moldova)", culture.display_name());
      assert::are_equal("Romanian (Moldova)", culture.english_name());
      assert::are_equal(2072_z, culture.keyboard_layout_id());
      assert::are_equal(2072_z, culture.lcid());
      assert::are_equal("ro-MD", culture.name());
      assert::are_equal("română (Republica Moldova)", culture.native_name());
    }
    
    auto test_method_(ro_RO) {
      auto culture = culture_info {"ro-RO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Romanian (Romania)", culture.display_name());
      assert::are_equal("Romanian (Romania)", culture.english_name());
      assert::are_equal(1048_z, culture.keyboard_layout_id());
      assert::are_equal(1048_z, culture.lcid());
      assert::are_equal("ro-RO", culture.name());
      assert::are_equal("română (România)", culture.native_name());
    }
    
    auto test_method_(rof) {
      auto culture = culture_info {"rof"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Rombo", culture.display_name());
      assert::are_equal("Rombo", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rof", culture.name());
      assert::are_equal("Kihorombo", culture.native_name());
    }
    
    auto test_method_(rof_TZ) {
      auto culture = culture_info {"rof-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Rombo (Tanzania)", culture.display_name());
      assert::are_equal("Rombo (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rof-TZ", culture.name());
      assert::are_equal("Kihorombo (Tanzania)", culture.native_name());
    }
    
    auto test_method_(ru) {
      auto culture = culture_info {"ru"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Russian", culture.display_name());
      assert::are_equal("Russian", culture.english_name());
      assert::are_equal(25_z, culture.keyboard_layout_id());
      assert::are_equal(25_z, culture.lcid());
      assert::are_equal("ru", culture.name());
      assert::are_equal("русский", culture.native_name());
    }
    
    auto test_method_(ru_BY) {
      auto culture = culture_info {"ru-BY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Russian (Belarus)", culture.display_name());
      assert::are_equal("Russian (Belarus)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ru-BY", culture.name());
      assert::are_equal("русский (Беларусь)", culture.native_name());
    }
    
    auto test_method_(ru_KG) {
      auto culture = culture_info {"ru-KG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Russian (Kyrgyzstan)", culture.display_name());
      assert::are_equal("Russian (Kyrgyzstan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ru-KG", culture.name());
      assert::are_equal("русский (Киргизия)", culture.native_name());
    }
    
    auto test_method_(ru_KZ) {
      auto culture = culture_info {"ru-KZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Russian (Kazakhstan)", culture.display_name());
      assert::are_equal("Russian (Kazakhstan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ru-KZ", culture.name());
      assert::are_equal("русский (Казахстан)", culture.native_name());
    }
    
    auto test_method_(ru_MD) {
      auto culture = culture_info {"ru-MD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Russian (Moldova)", culture.display_name());
      assert::are_equal("Russian (Moldova)", culture.english_name());
      assert::are_equal(2073_z, culture.keyboard_layout_id());
      assert::are_equal(2073_z, culture.lcid());
      assert::are_equal("ru-MD", culture.name());
      assert::are_equal("русский (Молдова)", culture.native_name());
    }
    
    auto test_method_(ru_RU) {
      auto culture = culture_info {"ru-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Russian (Russia)", culture.display_name());
      assert::are_equal("Russian (Russia)", culture.english_name());
      assert::are_equal(1049_z, culture.keyboard_layout_id());
      assert::are_equal(1049_z, culture.lcid());
      assert::are_equal("ru-RU", culture.name());
      assert::are_equal("русский (Россия)", culture.native_name());
    }
    
    auto test_method_(ru_UA) {
      auto culture = culture_info {"ru-UA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Russian (Ukraine)", culture.display_name());
      assert::are_equal("Russian (Ukraine)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ru-UA", culture.name());
      assert::are_equal("русский (Украина)", culture.native_name());
    }
    
    auto test_method_(rw) {
      auto culture = culture_info {"rw"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kinyarwanda", culture.display_name());
      assert::are_equal("Kinyarwanda", culture.english_name());
      assert::are_equal(135_z, culture.keyboard_layout_id());
      assert::are_equal(135_z, culture.lcid());
      assert::are_equal("rw", culture.name());
      assert::are_equal("Ikinyarwanda", culture.native_name());
    }
    
    auto test_method_(rw_RW) {
      auto culture = culture_info {"rw-RW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kinyarwanda (Rwanda)", culture.display_name());
      assert::are_equal("Kinyarwanda (Rwanda)", culture.english_name());
      assert::are_equal(1159_z, culture.keyboard_layout_id());
      assert::are_equal(1159_z, culture.lcid());
      assert::are_equal("rw-RW", culture.name());
      assert::are_equal("Ikinyarwanda (U Rwanda)", culture.native_name());
    }
    
    auto test_method_(rwk) {
      auto culture = culture_info {"rwk"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Rwa", culture.display_name());
      assert::are_equal("Rwa", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rwk", culture.name());
      assert::are_equal("Kiruwa", culture.native_name());
    }
    
    auto test_method_(rwk_TZ) {
      auto culture = culture_info {"rwk-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Rwa (Tanzania)", culture.display_name());
      assert::are_equal("Rwa (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("rwk-TZ", culture.name());
      assert::are_equal("Kiruwa (Tanzania)", culture.native_name());
    }
    
    auto test_method_(sa) {
      auto culture = culture_info {"sa"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sanskrit", culture.display_name());
      assert::are_equal("Sanskrit", culture.english_name());
      assert::are_equal(79_z, culture.keyboard_layout_id());
      assert::are_equal(79_z, culture.lcid());
      assert::are_equal("sa", culture.name());
      assert::are_equal("संस्कृत भाषा", culture.native_name());
    }
    
    auto test_method_(sa_IN) {
      auto culture = culture_info {"sa-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sanskrit (India)", culture.display_name());
      assert::are_equal("Sanskrit (India)", culture.english_name());
      assert::are_equal(1103_z, culture.keyboard_layout_id());
      assert::are_equal(1103_z, culture.lcid());
      assert::are_equal("sa-IN", culture.name());
      assert::are_equal("संस्कृत भाषा (भारतः)", culture.native_name());
    }
    
    auto test_method_(sah) {
      auto culture = culture_info {"sah"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sakha", culture.display_name());
      assert::are_equal("Sakha", culture.english_name());
      assert::are_equal(133_z, culture.keyboard_layout_id());
      assert::are_equal(133_z, culture.lcid());
      assert::are_equal("sah", culture.name());
      assert::are_equal("саха тыла", culture.native_name());
    }
    
    auto test_method_(sah_RU) {
      auto culture = culture_info {"sah-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sakha (Russia)", culture.display_name());
      assert::are_equal("Sakha (Russia)", culture.english_name());
      assert::are_equal(1157_z, culture.keyboard_layout_id());
      assert::are_equal(1157_z, culture.lcid());
      assert::are_equal("sah-RU", culture.name());
      assert::are_equal("саха тыла (Арассыыйа)", culture.native_name());
    }
    
    auto test_method_(saq) {
      auto culture = culture_info {"saq"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Samburu", culture.display_name());
      assert::are_equal("Samburu", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("saq", culture.name());
      assert::are_equal("Kisampur", culture.native_name());
    }
    
    auto test_method_(saq_KE) {
      auto culture = culture_info {"saq-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Samburu (Kenya)", culture.display_name());
      assert::are_equal("Samburu (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("saq-KE", culture.name());
      assert::are_equal("Kisampur (Kenya)", culture.native_name());
    }
    
    auto test_method_(sat) {
      auto culture = culture_info {"sat"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Santali", culture.display_name());
      assert::are_equal("Santali", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sat", culture.name());
      assert::are_equal("ᱥᱟᱱᱛᱟᱲᱤ", culture.native_name());
    }
    
    auto test_method_(sat_Deva) {
      auto culture = culture_info {"sat-Deva"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Santali (Devanagari)", culture.display_name());
      assert::are_equal("Santali (Devanagari)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sat-Deva", culture.name());
      assert::are_equal("सानताड़ी (देवानागारी)", culture.native_name());
    }
    
    auto test_method_(sat_Deva_IN) {
      auto culture = culture_info {"sat-Deva-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Santali (Devanagari, India)", culture.display_name());
      assert::are_equal("Santali (Devanagari, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sat-Deva-IN", culture.name());
      assert::are_equal("Santali (Devanagari, India)", culture.native_name());
    }
    
    auto test_method_(sat_Olck) {
      auto culture = culture_info {"sat-Olck"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Santali (Ol Chiki)", culture.display_name());
      assert::are_equal("Santali (Ol Chiki)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sat-Olck", culture.name());
      assert::are_equal("ᱥᱟᱱᱛᱟᱲᱤ (ᱚᱞ ᱪᱤᱠᱤ)", culture.native_name());
    }
    
    auto test_method_(sat_Olck_IN) {
      auto culture = culture_info {"sat-Olck-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Santali (Ol Chiki, India)", culture.display_name());
      assert::are_equal("Santali (Ol Chiki, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sat-Olck-IN", culture.name());
      assert::are_equal("ᱥᱟᱱᱛᱟᱲᱤ (ᱚᱞ ᱪᱤᱠᱤ, ᱤᱱᱰᱤᱭᱟ)", culture.native_name());
    }
    
    auto test_method_(sbp) {
      auto culture = culture_info {"sbp"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sangu", culture.display_name());
      assert::are_equal("Sangu", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sbp", culture.name());
      assert::are_equal("Ishisangu", culture.native_name());
    }
    
    auto test_method_(sbp_TZ) {
      auto culture = culture_info {"sbp-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sangu (Tanzania)", culture.display_name());
      assert::are_equal("Sangu (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sbp-TZ", culture.name());
      assert::are_equal("Ishisangu (Tansaniya)", culture.native_name());
    }
    
    auto test_method_(sc) {
      auto culture = culture_info {"sc"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sardinian", culture.display_name());
      assert::are_equal("Sardinian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sc", culture.name());
      assert::are_equal("sardu", culture.native_name());
    }
    
    auto test_method_(sc_IT) {
      auto culture = culture_info {"sc-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sardinian (Italy)", culture.display_name());
      assert::are_equal("Sardinian (Italy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sc-IT", culture.name());
      assert::are_equal("sardu (Itàlia)", culture.native_name());
    }
    
    auto test_method_(scn) {
      auto culture = culture_info {"scn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sicilian", culture.display_name());
      assert::are_equal("Sicilian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("scn", culture.name());
      assert::are_equal("sicilianu", culture.native_name());
    }
    
    auto test_method_(scn_IT) {
      auto culture = culture_info {"scn-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sicilian (Italy)", culture.display_name());
      assert::are_equal("Sicilian (Italy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("scn-IT", culture.name());
      assert::are_equal("Sicilian (Italy)", culture.native_name());
    }
    
    auto test_method_(sd) {
      auto culture = culture_info {"sd"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sindhi", culture.display_name());
      assert::are_equal("Sindhi", culture.english_name());
      assert::are_equal(89_z, culture.keyboard_layout_id());
      assert::are_equal(89_z, culture.lcid());
      assert::are_equal("sd", culture.name());
      assert::are_equal("سنڌي", culture.native_name());
    }
    
    auto test_method_(sd_Arab) {
      auto culture = culture_info {"sd-Arab"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sindhi (Arabic)", culture.display_name());
      assert::are_equal("Sindhi (Arabic)", culture.english_name());
      assert::are_equal(31833_z, culture.keyboard_layout_id());
      assert::are_equal(31833_z, culture.lcid());
      assert::are_equal("sd-Arab", culture.name());
      assert::are_equal("سنڌي (عربي)", culture.native_name());
    }
    
    auto test_method_(sd_Arab_PK) {
      auto culture = culture_info {"sd-Arab-PK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sindhi (Arabic, Pakistan)", culture.display_name());
      assert::are_equal("Sindhi (Arabic, Pakistan)", culture.english_name());
      assert::are_equal(2137_z, culture.keyboard_layout_id());
      assert::are_equal(2137_z, culture.lcid());
      assert::are_equal("sd-Arab-PK", culture.name());
      assert::are_equal("سنڌي (عربي, پاڪستان)", culture.native_name());
    }
    
    auto test_method_(sd_Deva) {
      auto culture = culture_info {"sd-Deva"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sindhi (Devanagari)", culture.display_name());
      assert::are_equal("Sindhi (Devanagari)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sd-Deva", culture.name());
      assert::are_equal("सिन्धी (देवनागिरी)", culture.native_name());
    }
    
    auto test_method_(sd_Deva_IN) {
      auto culture = culture_info {"sd-Deva-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sindhi (Devanagari, India)", culture.display_name());
      assert::are_equal("Sindhi (Devanagari, India)", culture.english_name());
      assert::are_equal(1113_z, culture.keyboard_layout_id());
      assert::are_equal(1113_z, culture.lcid());
      assert::are_equal("sd-Deva-IN", culture.name());
      assert::are_equal("सिन्धी (देवनागिरी, भारत)", culture.native_name());
    }
    
    auto test_method_(se) {
      auto culture = culture_info {"se"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("North Sámi", culture.display_name());
      assert::are_equal("North Sámi", culture.english_name());
      assert::are_equal(59_z, culture.keyboard_layout_id());
      assert::are_equal(59_z, culture.lcid());
      assert::are_equal("se", culture.name());
      assert::are_equal("davvisámegiella", culture.native_name());
    }
    
    auto test_method_(se_FI) {
      auto culture = culture_info {"se-FI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("North Sámi (Finland)", culture.display_name());
      assert::are_equal("North Sámi (Finland)", culture.english_name());
      assert::are_equal(3131_z, culture.keyboard_layout_id());
      assert::are_equal(3131_z, culture.lcid());
      assert::are_equal("se-FI", culture.name());
      assert::are_equal("davvisámegiella (Suopma)", culture.native_name());
    }
    
    auto test_method_(se_NO) {
      auto culture = culture_info {"se-NO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("North Sámi (Norway)", culture.display_name());
      assert::are_equal("North Sámi (Norway)", culture.english_name());
      assert::are_equal(1083_z, culture.keyboard_layout_id());
      assert::are_equal(1083_z, culture.lcid());
      assert::are_equal("se-NO", culture.name());
      assert::are_equal("davvisámegiella (Norga)", culture.native_name());
    }
    
    auto test_method_(se_SE) {
      auto culture = culture_info {"se-SE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("North Sámi (Sweden)", culture.display_name());
      assert::are_equal("North Sámi (Sweden)", culture.english_name());
      assert::are_equal(2107_z, culture.keyboard_layout_id());
      assert::are_equal(2107_z, culture.lcid());
      assert::are_equal("se-SE", culture.name());
      assert::are_equal("davvisámegiella (Ruoŧŧa)", culture.native_name());
    }
    
    auto test_method_(seh) {
      auto culture = culture_info {"seh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sena", culture.display_name());
      assert::are_equal("Sena", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("seh", culture.name());
      assert::are_equal("sena", culture.native_name());
    }
    
    auto test_method_(seh_MZ) {
      auto culture = culture_info {"seh-MZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sena (Mozambique)", culture.display_name());
      assert::are_equal("Sena (Mozambique)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("seh-MZ", culture.name());
      assert::are_equal("sena (Moçambique)", culture.native_name());
    }
    
    auto test_method_(ses) {
      auto culture = culture_info {"ses"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Koyraboro Senni", culture.display_name());
      assert::are_equal("Koyraboro Senni", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ses", culture.name());
      assert::are_equal("Koyraboro senni", culture.native_name());
    }
    
    auto test_method_(ses_ML) {
      auto culture = culture_info {"ses-ML"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Koyraboro Senni (Mali)", culture.display_name());
      assert::are_equal("Koyraboro Senni (Mali)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ses-ML", culture.name());
      assert::are_equal("Koyraboro senni (Maali)", culture.native_name());
    }
    
    auto test_method_(sg) {
      auto culture = culture_info {"sg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sango", culture.display_name());
      assert::are_equal("Sango", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sg", culture.name());
      assert::are_equal("Sängö", culture.native_name());
    }
    
    auto test_method_(sg_CF) {
      auto culture = culture_info {"sg-CF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sango (Central African Republic)", culture.display_name());
      assert::are_equal("Sango (Central African Republic)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sg-CF", culture.name());
      assert::are_equal("Sängö (Ködörösêse tî Bêafrîka)", culture.native_name());
    }
    
    auto test_method_(shi) {
      auto culture = culture_info {"shi"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tachelhit", culture.display_name());
      assert::are_equal("Tachelhit", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("shi", culture.name());
      assert::are_equal("ⵜⴰⵛⵍⵃⵉⵜ", culture.native_name());
    }
    
    auto test_method_(shi_Latn) {
      auto culture = culture_info {"shi-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tachelhit (Latin)", culture.display_name());
      assert::are_equal("Tachelhit (Latin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("shi-Latn", culture.name());
      assert::are_equal("Tachelhit (Latin)", culture.native_name());
    }
    
    auto test_method_(shi_Latn_MA) {
      auto culture = culture_info {"shi-Latn-MA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tachelhit (Latin, Morocco)", culture.display_name());
      assert::are_equal("Tachelhit (Latin, Morocco)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("shi-Latn-MA", culture.name());
      assert::are_equal("Tachelhit (Latin, Morocco)", culture.native_name());
    }
    
    auto test_method_(shi_Tfng) {
      auto culture = culture_info {"shi-Tfng"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tachelhit (Tifinagh)", culture.display_name());
      assert::are_equal("Tachelhit (Tifinagh)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("shi-Tfng", culture.name());
      assert::are_equal("Tachelhit (Tifinagh)", culture.native_name());
    }
    
    auto test_method_(shi_Tfng_MA) {
      auto culture = culture_info {"shi-Tfng-MA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tachelhit (Tifinagh, Morocco)", culture.display_name());
      assert::are_equal("Tachelhit (Tifinagh, Morocco)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("shi-Tfng-MA", culture.name());
      assert::are_equal("Tachelhit (Tifinagh, Morocco)", culture.native_name());
    }
    
    auto test_method_(si) {
      auto culture = culture_info {"si"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sinhala", culture.display_name());
      assert::are_equal("Sinhala", culture.english_name());
      assert::are_equal(91_z, culture.keyboard_layout_id());
      assert::are_equal(91_z, culture.lcid());
      assert::are_equal("si", culture.name());
      assert::are_equal("සිංහල", culture.native_name());
    }
    
    auto test_method_(si_LK) {
      auto culture = culture_info {"si-LK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sinhala (Sri Lanka)", culture.display_name());
      assert::are_equal("Sinhala (Sri Lanka)", culture.english_name());
      assert::are_equal(1115_z, culture.keyboard_layout_id());
      assert::are_equal(1115_z, culture.lcid());
      assert::are_equal("si-LK", culture.name());
      assert::are_equal("සිංහල (ශ්‍රී ලංකාව)", culture.native_name());
    }
    
    auto test_method_(sjd) {
      auto culture = culture_info {"sjd"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kildin Sámi", culture.display_name());
      assert::are_equal("Kildin Sámi", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sjd", culture.name());
      assert::are_equal("Кӣллт са̄мь кӣлл", culture.native_name());
    }
    
    auto test_method_(sje) {
      auto culture = culture_info {"sje"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Pite Sámi", culture.display_name());
      assert::are_equal("Pite Sámi", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sje", culture.name());
      assert::are_equal("Bidumsámegiella", culture.native_name());
    }
    
    auto test_method_(sju) {
      auto culture = culture_info {"sju"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ume Sámi", culture.display_name());
      assert::are_equal("Ume Sámi", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sju", culture.name());
      assert::are_equal("Ubmejesámiengiälla", culture.native_name());
    }
    
    auto test_method_(sk) {
      auto culture = culture_info {"sk"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Slovak", culture.display_name());
      assert::are_equal("Slovak", culture.english_name());
      assert::are_equal(27_z, culture.keyboard_layout_id());
      assert::are_equal(27_z, culture.lcid());
      assert::are_equal("sk", culture.name());
      assert::are_equal("slovenčina", culture.native_name());
    }
    
    auto test_method_(sk_SK) {
      auto culture = culture_info {"sk-SK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Slovak (Slovakia)", culture.display_name());
      assert::are_equal("Slovak (Slovakia)", culture.english_name());
      assert::are_equal(1051_z, culture.keyboard_layout_id());
      assert::are_equal(1051_z, culture.lcid());
      assert::are_equal("sk-SK", culture.name());
      assert::are_equal("slovenčina (Slovensko)", culture.native_name());
    }
    
    auto test_method_(sl) {
      auto culture = culture_info {"sl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Slovenian", culture.display_name());
      assert::are_equal("Slovenian", culture.english_name());
      assert::are_equal(36_z, culture.keyboard_layout_id());
      assert::are_equal(36_z, culture.lcid());
      assert::are_equal("sl", culture.name());
      assert::are_equal("slovenščina", culture.native_name());
    }
    
    auto test_method_(sl_SI) {
      auto culture = culture_info {"sl-SI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Slovenian (Slovenia)", culture.display_name());
      assert::are_equal("Slovenian (Slovenia)", culture.english_name());
      assert::are_equal(1060_z, culture.keyboard_layout_id());
      assert::are_equal(1060_z, culture.lcid());
      assert::are_equal("sl-SI", culture.name());
      assert::are_equal("slovenščina (Slovenija)", culture.native_name());
    }
    
    auto test_method_(sm) {
      auto culture = culture_info {"sm"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Samoan", culture.display_name());
      assert::are_equal("Samoan", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sm", culture.name());
      assert::are_equal("Gagana faʻa Sāmoa", culture.native_name());
    }
    
    auto test_method_(sm_AS) {
      auto culture = culture_info {"sm-AS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Samoan (American Samoa)", culture.display_name());
      assert::are_equal("Samoan (American Samoa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sm-AS", culture.name());
      assert::are_equal("Samoan (American Samoa)", culture.native_name());
    }
    
    auto test_method_(sm_WS) {
      auto culture = culture_info {"sm-WS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Samoan (Samoa)", culture.display_name());
      assert::are_equal("Samoan (Samoa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sm-WS", culture.name());
      assert::are_equal("Samoan (Samoa)", culture.native_name());
    }
    
    auto test_method_(smn) {
      auto culture = culture_info {"smn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Inari Sami", culture.display_name());
      assert::are_equal("Inari Sami", culture.english_name());
      assert::are_equal(28731_z, culture.keyboard_layout_id());
      assert::are_equal(28731_z, culture.lcid());
      assert::are_equal("smn", culture.name());
      assert::are_equal("anarâškielâ", culture.native_name());
    }
    
    auto test_method_(smn_FI) {
      auto culture = culture_info {"smn-FI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Inari Sami (Finland)", culture.display_name());
      assert::are_equal("Inari Sami (Finland)", culture.english_name());
      assert::are_equal(9275_z, culture.keyboard_layout_id());
      assert::are_equal(9275_z, culture.lcid());
      assert::are_equal("smn-FI", culture.name());
      assert::are_equal("anarâškielâ (Suomâ)", culture.native_name());
    }
    
    auto test_method_(sn) {
      auto culture = culture_info {"sn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Shona", culture.display_name());
      assert::are_equal("Shona", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sn", culture.name());
      assert::are_equal("chiShona", culture.native_name());
    }
    
    auto test_method_(sn_ZW) {
      auto culture = culture_info {"sn-ZW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Shona (Zimbabwe)", culture.display_name());
      assert::are_equal("Shona (Zimbabwe)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sn-ZW", culture.name());
      assert::are_equal("chiShona (Zimbabwe)", culture.native_name());
    }
    
    auto test_method_(so) {
      auto culture = culture_info {"so"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Somali", culture.display_name());
      assert::are_equal("Somali", culture.english_name());
      assert::are_equal(119_z, culture.keyboard_layout_id());
      assert::are_equal(119_z, culture.lcid());
      assert::are_equal("so", culture.name());
      assert::are_equal("Soomaali", culture.native_name());
    }
    
    auto test_method_(so_DJ) {
      auto culture = culture_info {"so-DJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Somali (Djibouti)", culture.display_name());
      assert::are_equal("Somali (Djibouti)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("so-DJ", culture.name());
      assert::are_equal("Soomaali (Jabuuti)", culture.native_name());
    }
    
    auto test_method_(so_ET) {
      auto culture = culture_info {"so-ET"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Somali (Ethiopia)", culture.display_name());
      assert::are_equal("Somali (Ethiopia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("so-ET", culture.name());
      assert::are_equal("Soomaali (Itoobiya)", culture.native_name());
    }
    
    auto test_method_(so_KE) {
      auto culture = culture_info {"so-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Somali (Kenya)", culture.display_name());
      assert::are_equal("Somali (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("so-KE", culture.name());
      assert::are_equal("Soomaali (Kenya)", culture.native_name());
    }
    
    auto test_method_(so_SO) {
      auto culture = culture_info {"so-SO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Somali (Somalia)", culture.display_name());
      assert::are_equal("Somali (Somalia)", culture.english_name());
      assert::are_equal(1143_z, culture.keyboard_layout_id());
      assert::are_equal(1143_z, culture.lcid());
      assert::are_equal("so-SO", culture.name());
      assert::are_equal("Soomaali (Soomaaliya)", culture.native_name());
    }
    
    auto test_method_(sq) {
      auto culture = culture_info {"sq"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Albanian", culture.display_name());
      assert::are_equal("Albanian", culture.english_name());
      assert::are_equal(28_z, culture.keyboard_layout_id());
      assert::are_equal(28_z, culture.lcid());
      assert::are_equal("sq", culture.name());
      assert::are_equal("shqip", culture.native_name());
    }
    
    auto test_method_(sq_AL) {
      auto culture = culture_info {"sq-AL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Albanian (Albania)", culture.display_name());
      assert::are_equal("Albanian (Albania)", culture.english_name());
      assert::are_equal(1052_z, culture.keyboard_layout_id());
      assert::are_equal(1052_z, culture.lcid());
      assert::are_equal("sq-AL", culture.name());
      assert::are_equal("shqip (Shqipëri)", culture.native_name());
    }
    
    auto test_method_(sq_MK) {
      auto culture = culture_info {"sq-MK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Albanian (North Macedonia)", culture.display_name());
      assert::are_equal("Albanian (North Macedonia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sq-MK", culture.name());
      assert::are_equal("shqip (Maqedonia e Veriut)", culture.native_name());
    }
    
    auto test_method_(sq_XK) {
      auto culture = culture_info {"sq-XK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Albanian (Kosovo)", culture.display_name());
      assert::are_equal("Albanian (Kosovo)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sq-XK", culture.name());
      assert::are_equal("shqip (Kosovë)", culture.native_name());
    }
    
    auto test_method_(sr) {
      auto culture = culture_info {"sr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Serbian", culture.display_name());
      assert::are_equal("Serbian", culture.english_name());
      assert::are_equal(31770_z, culture.keyboard_layout_id());
      assert::are_equal(31770_z, culture.lcid());
      assert::are_equal("sr", culture.name());
      assert::are_equal("српски", culture.native_name());
    }
    
    auto test_method_(sr_Cyrl) {
      auto culture = culture_info {"sr-Cyrl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Serbian (Cyrillic)", culture.display_name());
      assert::are_equal("Serbian (Cyrillic)", culture.english_name());
      assert::are_equal(27674_z, culture.keyboard_layout_id());
      assert::are_equal(27674_z, culture.lcid());
      assert::are_equal("sr-Cyrl", culture.name());
      assert::are_equal("српски (ћирилица)", culture.native_name());
    }
    
    auto test_method_(sr_Cyrl_BA) {
      auto culture = culture_info {"sr-Cyrl-BA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Serbian (Cyrillic, Bosnia & Herzegovina)", culture.display_name());
      assert::are_equal("Serbian (Cyrillic, Bosnia & Herzegovina)", culture.english_name());
      assert::are_equal(7194_z, culture.keyboard_layout_id());
      assert::are_equal(7194_z, culture.lcid());
      assert::are_equal("sr-Cyrl-BA", culture.name());
      assert::are_equal("српски (ћирилица, Босна и Херцеговина)", culture.native_name());
    }
    
    auto test_method_(sr_Cyrl_ME) {
      auto culture = culture_info {"sr-Cyrl-ME"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Serbian (Cyrillic, Montenegro)", culture.display_name());
      assert::are_equal("Serbian (Cyrillic, Montenegro)", culture.english_name());
      assert::are_equal(12314_z, culture.keyboard_layout_id());
      assert::are_equal(12314_z, culture.lcid());
      assert::are_equal("sr-Cyrl-ME", culture.name());
      assert::are_equal("српски (ћирилица, Црна Гора)", culture.native_name());
    }
    
    auto test_method_(sr_Cyrl_RS) {
      auto culture = culture_info {"sr-Cyrl-RS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Serbian (Cyrillic, Serbia)", culture.display_name());
      assert::are_equal("Serbian (Cyrillic, Serbia)", culture.english_name());
      assert::are_equal(10266_z, culture.keyboard_layout_id());
      assert::are_equal(10266_z, culture.lcid());
      assert::are_equal("sr-Cyrl-RS", culture.name());
      assert::are_equal("српски (ћирилица, Србија)", culture.native_name());
    }
    
    auto test_method_(sr_Cyrl_XK) {
      auto culture = culture_info {"sr-Cyrl-XK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Serbian (Cyrillic, Kosovo)", culture.display_name());
      assert::are_equal("Serbian (Cyrillic, Kosovo)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sr-Cyrl-XK", culture.name());
      assert::are_equal("српски (ћирилица, Косово)", culture.native_name());
    }
    
    auto test_method_(sr_Latn) {
      auto culture = culture_info {"sr-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Serbian (Latin)", culture.display_name());
      assert::are_equal("Serbian (Latin)", culture.english_name());
      assert::are_equal(28698_z, culture.keyboard_layout_id());
      assert::are_equal(28698_z, culture.lcid());
      assert::are_equal("sr-Latn", culture.name());
      assert::are_equal("srpski (latinica)", culture.native_name());
    }
    
    auto test_method_(sr_Latn_BA) {
      auto culture = culture_info {"sr-Latn-BA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Serbian (Latin, Bosnia & Herzegovina)", culture.display_name());
      assert::are_equal("Serbian (Latin, Bosnia & Herzegovina)", culture.english_name());
      assert::are_equal(6170_z, culture.keyboard_layout_id());
      assert::are_equal(6170_z, culture.lcid());
      assert::are_equal("sr-Latn-BA", culture.name());
      assert::are_equal("srpski (latinica, Bosna i Hercegovina)", culture.native_name());
    }
    
    auto test_method_(sr_Latn_ME) {
      auto culture = culture_info {"sr-Latn-ME"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Serbian (Latin, Montenegro)", culture.display_name());
      assert::are_equal("Serbian (Latin, Montenegro)", culture.english_name());
      assert::are_equal(11290_z, culture.keyboard_layout_id());
      assert::are_equal(11290_z, culture.lcid());
      assert::are_equal("sr-Latn-ME", culture.name());
      assert::are_equal("srpski (latinica, Crna Gora)", culture.native_name());
    }
    
    auto test_method_(sr_Latn_RS) {
      auto culture = culture_info {"sr-Latn-RS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Serbian (Latin, Serbia)", culture.display_name());
      assert::are_equal("Serbian (Latin, Serbia)", culture.english_name());
      assert::are_equal(9242_z, culture.keyboard_layout_id());
      assert::are_equal(9242_z, culture.lcid());
      assert::are_equal("sr-Latn-RS", culture.name());
      assert::are_equal("srpski (latinica, Srbija)", culture.native_name());
    }
    
    auto test_method_(sr_Latn_XK) {
      auto culture = culture_info {"sr-Latn-XK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Serbian (Latin, Kosovo)", culture.display_name());
      assert::are_equal("Serbian (Latin, Kosovo)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sr-Latn-XK", culture.name());
      assert::are_equal("srpski (latinica, Kosovo)", culture.native_name());
    }
    
    auto test_method_(ss) {
      auto culture = culture_info {"ss"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Swati", culture.display_name());
      assert::are_equal("Swati", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ss", culture.name());
      assert::are_equal("siSwati", culture.native_name());
    }
    
    auto test_method_(ss_SZ) {
      auto culture = culture_info {"ss-SZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swati (Eswatini)", culture.display_name());
      assert::are_equal("Swati (Eswatini)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ss-SZ", culture.name());
      assert::are_equal("siSwati (eSwatini)", culture.native_name());
    }
    
    auto test_method_(ss_ZA) {
      auto culture = culture_info {"ss-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swati (South Africa)", culture.display_name());
      assert::are_equal("Swati (South Africa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ss-ZA", culture.name());
      assert::are_equal("Swati (South Africa)", culture.native_name());
    }
    
    auto test_method_(st) {
      auto culture = culture_info {"st"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Southern Sotho", culture.display_name());
      assert::are_equal("Southern Sotho", culture.english_name());
      assert::are_equal(48_z, culture.keyboard_layout_id());
      assert::are_equal(48_z, culture.lcid());
      assert::are_equal("st", culture.name());
      assert::are_equal("Sesotho", culture.native_name());
    }
    
    auto test_method_(st_LS) {
      auto culture = culture_info {"st-LS"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Southern Sotho (Lesotho)", culture.display_name());
      assert::are_equal("Southern Sotho (Lesotho)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("st-LS", culture.name());
      assert::are_equal("Sesotho (Lesotho)", culture.native_name());
    }
    
    auto test_method_(st_ZA) {
      auto culture = culture_info {"st-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Southern Sotho (South Africa)", culture.display_name());
      assert::are_equal("Southern Sotho (South Africa)", culture.english_name());
      assert::are_equal(1072_z, culture.keyboard_layout_id());
      assert::are_equal(1072_z, culture.lcid());
      assert::are_equal("st-ZA", culture.name());
      assert::are_equal("Sesotho (Afrika Borwa)", culture.native_name());
    }
    
    auto test_method_(su) {
      auto culture = culture_info {"su"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sundanese", culture.display_name());
      assert::are_equal("Sundanese", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("su", culture.name());
      assert::are_equal("Basa Sunda", culture.native_name());
    }
    
    auto test_method_(su_Latn) {
      auto culture = culture_info {"su-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Sundanese (Latin)", culture.display_name());
      assert::are_equal("Sundanese (Latin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("su-Latn", culture.name());
      assert::are_equal("Basa Sunda (Latin)", culture.native_name());
    }
    
    auto test_method_(su_Latn_ID) {
      auto culture = culture_info {"su-Latn-ID"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Sundanese (Latin, Indonesia)", culture.display_name());
      assert::are_equal("Sundanese (Latin, Indonesia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("su-Latn-ID", culture.name());
      assert::are_equal("Basa Sunda (Latin, Indonesia)", culture.native_name());
    }
    
    auto test_method_(sv) {
      auto culture = culture_info {"sv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Swedish", culture.display_name());
      assert::are_equal("Swedish", culture.english_name());
      assert::are_equal(29_z, culture.keyboard_layout_id());
      assert::are_equal(29_z, culture.lcid());
      assert::are_equal("sv", culture.name());
      assert::are_equal("svenska", culture.native_name());
    }
    
    auto test_method_(sv_AX) {
      auto culture = culture_info {"sv-AX"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swedish (Åland Islands)", culture.display_name());
      assert::are_equal("Swedish (Åland Islands)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sv-AX", culture.name());
      assert::are_equal("svenska (Åland)", culture.native_name());
    }
    
    auto test_method_(sv_FI) {
      auto culture = culture_info {"sv-FI"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swedish (Finland)", culture.display_name());
      assert::are_equal("Swedish (Finland)", culture.english_name());
      assert::are_equal(2077_z, culture.keyboard_layout_id());
      assert::are_equal(2077_z, culture.lcid());
      assert::are_equal("sv-FI", culture.name());
      assert::are_equal("svenska (Finland)", culture.native_name());
    }
    
    auto test_method_(sv_SE) {
      auto culture = culture_info {"sv-SE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swedish (Sweden)", culture.display_name());
      assert::are_equal("Swedish (Sweden)", culture.english_name());
      assert::are_equal(1053_z, culture.keyboard_layout_id());
      assert::are_equal(1053_z, culture.lcid());
      assert::are_equal("sv-SE", culture.name());
      assert::are_equal("svenska (Sverige)", culture.native_name());
    }
    
    auto test_method_(sw) {
      auto culture = culture_info {"sw"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Swahili", culture.display_name());
      assert::are_equal("Swahili", culture.english_name());
      assert::are_equal(65_z, culture.keyboard_layout_id());
      assert::are_equal(65_z, culture.lcid());
      assert::are_equal("sw", culture.name());
      assert::are_equal("Kiswahili", culture.native_name());
    }
    
    auto test_method_(sw_CD) {
      auto culture = culture_info {"sw-CD"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swahili (Congo - Kinshasa)", culture.display_name());
      assert::are_equal("Swahili (Congo - Kinshasa)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sw-CD", culture.name());
      assert::are_equal("Kiswahili (Jamhuri ya Kidemokrasia ya Kongo)", culture.native_name());
    }
    
    auto test_method_(sw_KE) {
      auto culture = culture_info {"sw-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swahili (Kenya)", culture.display_name());
      assert::are_equal("Swahili (Kenya)", culture.english_name());
      assert::are_equal(1089_z, culture.keyboard_layout_id());
      assert::are_equal(1089_z, culture.lcid());
      assert::are_equal("sw-KE", culture.name());
      assert::are_equal("Kiswahili (Kenya)", culture.native_name());
    }
    
    auto test_method_(sw_TZ) {
      auto culture = culture_info {"sw-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swahili (Tanzania)", culture.display_name());
      assert::are_equal("Swahili (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sw-TZ", culture.name());
      assert::are_equal("Kiswahili (Tanzania)", culture.native_name());
    }
    
    auto test_method_(sw_UG) {
      auto culture = culture_info {"sw-UG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Swahili (Uganda)", culture.display_name());
      assert::are_equal("Swahili (Uganda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("sw-UG", culture.name());
      assert::are_equal("Kiswahili (Uganda)", culture.native_name());
    }
    
    auto test_method_(syr) {
      auto culture = culture_info {"syr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Assyrian", culture.display_name());
      assert::are_equal("Assyrian", culture.english_name());
      assert::are_equal(90_z, culture.keyboard_layout_id());
      assert::are_equal(90_z, culture.lcid());
      assert::are_equal("syr", culture.name());
      assert::are_equal("ܣܘܪܝܝܐ", culture.native_name());
    }
    
    auto test_method_(syr_IQ) {
      auto culture = culture_info {"syr-IQ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Assyrian (Iraq)", culture.display_name());
      assert::are_equal("Assyrian (Iraq)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("syr-IQ", culture.name());
      assert::are_equal("ܣܘܪܝܝܐ (ܥܝܪܩ)", culture.native_name());
    }
    
    auto test_method_(syr_SY) {
      auto culture = culture_info {"syr-SY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Assyrian (Syria)", culture.display_name());
      assert::are_equal("Assyrian (Syria)", culture.english_name());
      assert::are_equal(1114_z, culture.keyboard_layout_id());
      assert::are_equal(1114_z, culture.lcid());
      assert::are_equal("syr-SY", culture.name());
      assert::are_equal("ܣܘܪܝܝܐ (ܣܘܪܝܐ)", culture.native_name());
    }
    
    auto test_method_(szl) {
      auto culture = culture_info {"szl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Silesian", culture.display_name());
      assert::are_equal("Silesian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("szl", culture.name());
      assert::are_equal("ślōnski", culture.native_name());
    }
    
    auto test_method_(szl_PL) {
      auto culture = culture_info {"szl-PL"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Silesian (Poland)", culture.display_name());
      assert::are_equal("Silesian (Poland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("szl-PL", culture.name());
      assert::are_equal("ślōnski (Polska)", culture.native_name());
    }
    
    auto test_method_(ta) {
      auto culture = culture_info {"ta"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tamil", culture.display_name());
      assert::are_equal("Tamil", culture.english_name());
      assert::are_equal(73_z, culture.keyboard_layout_id());
      assert::are_equal(73_z, culture.lcid());
      assert::are_equal("ta", culture.name());
      assert::are_equal("தமிழ்", culture.native_name());
    }
    
    auto test_method_(ta_IN) {
      auto culture = culture_info {"ta-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tamil (India)", culture.display_name());
      assert::are_equal("Tamil (India)", culture.english_name());
      assert::are_equal(1097_z, culture.keyboard_layout_id());
      assert::are_equal(1097_z, culture.lcid());
      assert::are_equal("ta-IN", culture.name());
      assert::are_equal("தமிழ் (இந்தியா)", culture.native_name());
    }
    
    auto test_method_(ta_LK) {
      auto culture = culture_info {"ta-LK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tamil (Sri Lanka)", culture.display_name());
      assert::are_equal("Tamil (Sri Lanka)", culture.english_name());
      assert::are_equal(2121_z, culture.keyboard_layout_id());
      assert::are_equal(2121_z, culture.lcid());
      assert::are_equal("ta-LK", culture.name());
      assert::are_equal("தமிழ் (இலங்கை)", culture.native_name());
    }
    
    auto test_method_(ta_MY) {
      auto culture = culture_info {"ta-MY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tamil (Malaysia)", culture.display_name());
      assert::are_equal("Tamil (Malaysia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ta-MY", culture.name());
      assert::are_equal("தமிழ் (மலேசியா)", culture.native_name());
    }
    
    auto test_method_(ta_SG) {
      auto culture = culture_info {"ta-SG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tamil (Singapore)", culture.display_name());
      assert::are_equal("Tamil (Singapore)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ta-SG", culture.name());
      assert::are_equal("தமிழ் (சிங்கப்பூர்)", culture.native_name());
    }
    
    auto test_method_(te) {
      auto culture = culture_info {"te"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Telugu", culture.display_name());
      assert::are_equal("Telugu", culture.english_name());
      assert::are_equal(74_z, culture.keyboard_layout_id());
      assert::are_equal(74_z, culture.lcid());
      assert::are_equal("te", culture.name());
      assert::are_equal("తెలుగు", culture.native_name());
    }
    
    auto test_method_(te_IN) {
      auto culture = culture_info {"te-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Telugu (India)", culture.display_name());
      assert::are_equal("Telugu (India)", culture.english_name());
      assert::are_equal(1098_z, culture.keyboard_layout_id());
      assert::are_equal(1098_z, culture.lcid());
      assert::are_equal("te-IN", culture.name());
      assert::are_equal("తెలుగు (భారతదేశం)", culture.native_name());
    }
    
    auto test_method_(teo) {
      auto culture = culture_info {"teo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Teso", culture.display_name());
      assert::are_equal("Teso", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("teo", culture.name());
      assert::are_equal("Kiteso", culture.native_name());
    }
    
    auto test_method_(teo_KE) {
      auto culture = culture_info {"teo-KE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Teso (Kenya)", culture.display_name());
      assert::are_equal("Teso (Kenya)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("teo-KE", culture.name());
      assert::are_equal("Kiteso (Kenia)", culture.native_name());
    }
    
    auto test_method_(teo_UG) {
      auto culture = culture_info {"teo-UG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Teso (Uganda)", culture.display_name());
      assert::are_equal("Teso (Uganda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("teo-UG", culture.name());
      assert::are_equal("Kiteso (Uganda)", culture.native_name());
    }
    
    auto test_method_(tg) {
      auto culture = culture_info {"tg"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tajik", culture.display_name());
      assert::are_equal("Tajik", culture.english_name());
      assert::are_equal(40_z, culture.keyboard_layout_id());
      assert::are_equal(40_z, culture.lcid());
      assert::are_equal("tg", culture.name());
      assert::are_equal("тоҷикӣ", culture.native_name());
    }
    
    auto test_method_(tg_TJ) {
      auto culture = culture_info {"tg-TJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tajik (Tajikistan)", culture.display_name());
      assert::are_equal("Tajik (Tajikistan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("tg-TJ", culture.name());
      assert::are_equal("тоҷикӣ (Тоҷикистон)", culture.native_name());
    }
    
    auto test_method_(th) {
      auto culture = culture_info {"th"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Thai", culture.display_name());
      assert::are_equal("Thai", culture.english_name());
      assert::are_equal(30_z, culture.keyboard_layout_id());
      assert::are_equal(30_z, culture.lcid());
      assert::are_equal("th", culture.name());
      assert::are_equal("ไทย", culture.native_name());
    }
    
    auto test_method_(th_TH) {
      auto culture = culture_info {"th-TH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Thai (Thailand)", culture.display_name());
      assert::are_equal("Thai (Thailand)", culture.english_name());
      assert::are_equal(1054_z, culture.keyboard_layout_id());
      assert::are_equal(1054_z, culture.lcid());
      assert::are_equal("th-TH", culture.name());
      assert::are_equal("ไทย (ไทย)", culture.native_name());
    }
    
    auto test_method_(ti) {
      auto culture = culture_info {"ti"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tigrinya", culture.display_name());
      assert::are_equal("Tigrinya", culture.english_name());
      assert::are_equal(115_z, culture.keyboard_layout_id());
      assert::are_equal(115_z, culture.lcid());
      assert::are_equal("ti", culture.name());
      assert::are_equal("ትግርኛ", culture.native_name());
    }
    
    auto test_method_(ti_ER) {
      auto culture = culture_info {"ti-ER"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tigrinya (Eritrea)", culture.display_name());
      assert::are_equal("Tigrinya (Eritrea)", culture.english_name());
      assert::are_equal(2163_z, culture.keyboard_layout_id());
      assert::are_equal(2163_z, culture.lcid());
      assert::are_equal("ti-ER", culture.name());
      assert::are_equal("ትግርኛ (ኤርትራ)", culture.native_name());
    }
    
    auto test_method_(ti_ET) {
      auto culture = culture_info {"ti-ET"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tigrinya (Ethiopia)", culture.display_name());
      assert::are_equal("Tigrinya (Ethiopia)", culture.english_name());
      assert::are_equal(1139_z, culture.keyboard_layout_id());
      assert::are_equal(1139_z, culture.lcid());
      assert::are_equal("ti-ET", culture.name());
      assert::are_equal("ትግርኛ (ኢትዮጵያ)", culture.native_name());
    }
    
    auto test_method_(tig) {
      auto culture = culture_info {"tig"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tigre", culture.display_name());
      assert::are_equal("Tigre", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("tig", culture.name());
      assert::are_equal("ትግረ", culture.native_name());
    }
    
    auto test_method_(tig_ER) {
      auto culture = culture_info {"tig-ER"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tigre (Eritrea)", culture.display_name());
      assert::are_equal("Tigre (Eritrea)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("tig-ER", culture.name());
      assert::are_equal("ትግረ (ኤርትራ)", culture.native_name());
    }
    
    auto test_method_(tk) {
      auto culture = culture_info {"tk"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Turkmen", culture.display_name());
      assert::are_equal("Turkmen", culture.english_name());
      assert::are_equal(66_z, culture.keyboard_layout_id());
      assert::are_equal(66_z, culture.lcid());
      assert::are_equal("tk", culture.name());
      assert::are_equal("türkmen dili", culture.native_name());
    }
    
    auto test_method_(tk_TM) {
      auto culture = culture_info {"tk-TM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Turkmen (Turkmenistan)", culture.display_name());
      assert::are_equal("Turkmen (Turkmenistan)", culture.english_name());
      assert::are_equal(1090_z, culture.keyboard_layout_id());
      assert::are_equal(1090_z, culture.lcid());
      assert::are_equal("tk-TM", culture.name());
      assert::are_equal("türkmen dili (Türkmenistan)", culture.native_name());
    }
    
    auto test_method_(tn) {
      auto culture = culture_info {"tn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tswana", culture.display_name());
      assert::are_equal("Tswana", culture.english_name());
      assert::are_equal(50_z, culture.keyboard_layout_id());
      assert::are_equal(50_z, culture.lcid());
      assert::are_equal("tn", culture.name());
      assert::are_equal("Setswana", culture.native_name());
    }
    
    auto test_method_(tn_BW) {
      auto culture = culture_info {"tn-BW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tswana (Botswana)", culture.display_name());
      assert::are_equal("Tswana (Botswana)", culture.english_name());
      assert::are_equal(2098_z, culture.keyboard_layout_id());
      assert::are_equal(2098_z, culture.lcid());
      assert::are_equal("tn-BW", culture.name());
      assert::are_equal("Setswana (Botswana)", culture.native_name());
    }
    
    auto test_method_(tn_ZA) {
      auto culture = culture_info {"tn-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tswana (South Africa)", culture.display_name());
      assert::are_equal("Tswana (South Africa)", culture.english_name());
      assert::are_equal(1074_z, culture.keyboard_layout_id());
      assert::are_equal(1074_z, culture.lcid());
      assert::are_equal("tn-ZA", culture.name());
      assert::are_equal("Setswana (Aforika Borwa)", culture.native_name());
    }
    
    auto test_method_(to) {
      auto culture = culture_info {"to"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tongan", culture.display_name());
      assert::are_equal("Tongan", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("to", culture.name());
      assert::are_equal("lea fakatonga", culture.native_name());
    }
    
    auto test_method_(to_TO) {
      auto culture = culture_info {"to-TO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tongan (Tonga)", culture.display_name());
      assert::are_equal("Tongan (Tonga)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("to-TO", culture.name());
      assert::are_equal("lea fakatonga (Tonga)", culture.native_name());
    }
    
    auto test_method_(tok) {
      auto culture = culture_info {"tok"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Toki Pona", culture.display_name());
      assert::are_equal("Toki Pona", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("tok", culture.name());
      assert::are_equal("toki pona", culture.native_name());
    }
    
    auto test_method_(tok_001) {
      auto culture = culture_info {"tok-001"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Toki Pona (world)", culture.display_name());
      assert::are_equal("Toki Pona (world)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("tok-001", culture.name());
      assert::are_equal("toki pona pi ma ale", culture.native_name());
    }
    
    auto test_method_(tr) {
      auto culture = culture_info {"tr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Turkish", culture.display_name());
      assert::are_equal("Turkish", culture.english_name());
      assert::are_equal(31_z, culture.keyboard_layout_id());
      assert::are_equal(31_z, culture.lcid());
      assert::are_equal("tr", culture.name());
      assert::are_equal("Türkçe", culture.native_name());
    }
    
    auto test_method_(tr_CY) {
      auto culture = culture_info {"tr-CY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Turkish (Cyprus)", culture.display_name());
      assert::are_equal("Turkish (Cyprus)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("tr-CY", culture.name());
      assert::are_equal("Türkçe (Kıbrıs)", culture.native_name());
    }
    
    auto test_method_(tr_TR) {
      auto culture = culture_info {"tr-TR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Turkish (Türkiye)", culture.display_name());
      assert::are_equal("Turkish (Türkiye)", culture.english_name());
      assert::are_equal(1055_z, culture.keyboard_layout_id());
      assert::are_equal(1055_z, culture.lcid());
      assert::are_equal("tr-TR", culture.name());
      assert::are_equal("Türkçe (Türkiye)", culture.native_name());
    }
    
    auto test_method_(trv) {
      auto culture = culture_info {"trv"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Taroko", culture.display_name());
      assert::are_equal("Taroko", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("trv", culture.name());
      assert::are_equal("patas Taroko", culture.native_name());
    }
    
    auto test_method_(trv_TW) {
      auto culture = culture_info {"trv-TW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Taroko (Taiwan)", culture.display_name());
      assert::are_equal("Taroko (Taiwan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("trv-TW", culture.name());
      assert::are_equal("patas Taroko (TW)", culture.native_name());
    }
    
    auto test_method_(ts) {
      auto culture = culture_info {"ts"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tsonga", culture.display_name());
      assert::are_equal("Tsonga", culture.english_name());
      assert::are_equal(49_z, culture.keyboard_layout_id());
      assert::are_equal(49_z, culture.lcid());
      assert::are_equal("ts", culture.name());
      assert::are_equal("Xitsonga", culture.native_name());
    }
    
    auto test_method_(ts_ZA) {
      auto culture = culture_info {"ts-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tsonga (South Africa)", culture.display_name());
      assert::are_equal("Tsonga (South Africa)", culture.english_name());
      assert::are_equal(1073_z, culture.keyboard_layout_id());
      assert::are_equal(1073_z, culture.lcid());
      assert::are_equal("ts-ZA", culture.name());
      assert::are_equal("Tsonga (South Africa)", culture.native_name());
    }
    
    auto test_method_(tt) {
      auto culture = culture_info {"tt"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tatar", culture.display_name());
      assert::are_equal("Tatar", culture.english_name());
      assert::are_equal(68_z, culture.keyboard_layout_id());
      assert::are_equal(68_z, culture.lcid());
      assert::are_equal("tt", culture.name());
      assert::are_equal("татар", culture.native_name());
    }
    
    auto test_method_(tt_RU) {
      auto culture = culture_info {"tt-RU"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tatar (Russia)", culture.display_name());
      assert::are_equal("Tatar (Russia)", culture.english_name());
      assert::are_equal(1092_z, culture.keyboard_layout_id());
      assert::are_equal(1092_z, culture.lcid());
      assert::are_equal("tt-RU", culture.name());
      assert::are_equal("татар (Россия)", culture.native_name());
    }
    
    auto test_method_(twq) {
      auto culture = culture_info {"twq"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tasawaq", culture.display_name());
      assert::are_equal("Tasawaq", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("twq", culture.name());
      assert::are_equal("Tasawaq senni", culture.native_name());
    }
    
    auto test_method_(twq_NE) {
      auto culture = culture_info {"twq-NE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tasawaq (Niger)", culture.display_name());
      assert::are_equal("Tasawaq (Niger)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("twq-NE", culture.name());
      assert::are_equal("Tasawaq senni (Nižer)", culture.native_name());
    }
    
    auto test_method_(tzm) {
      auto culture = culture_info {"tzm"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Central Atlas Tamazight", culture.display_name());
      assert::are_equal("Central Atlas Tamazight", culture.english_name());
      assert::are_equal(95_z, culture.keyboard_layout_id());
      assert::are_equal(95_z, culture.lcid());
      assert::are_equal("tzm", culture.name());
      assert::are_equal("Tamaziɣt n laṭlaṣ", culture.native_name());
    }
    
    auto test_method_(tzm_MA) {
      auto culture = culture_info {"tzm-MA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Central Atlas Tamazight (Morocco)", culture.display_name());
      assert::are_equal("Central Atlas Tamazight (Morocco)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("tzm-MA", culture.name());
      assert::are_equal("Tamaziɣt n laṭlaṣ (Meṛṛuk)", culture.native_name());
    }
    
    auto test_method_(ug) {
      auto culture = culture_info {"ug"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Uyghur", culture.display_name());
      assert::are_equal("Uyghur", culture.english_name());
      assert::are_equal(128_z, culture.keyboard_layout_id());
      assert::are_equal(128_z, culture.lcid());
      assert::are_equal("ug", culture.name());
      assert::are_equal("ئۇيغۇرچە", culture.native_name());
    }
    
    auto test_method_(ug_CN) {
      auto culture = culture_info {"ug-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Uyghur (China mainland)", culture.display_name());
      assert::are_equal("Uyghur (China mainland)", culture.english_name());
      assert::are_equal(1152_z, culture.keyboard_layout_id());
      assert::are_equal(1152_z, culture.lcid());
      assert::are_equal("ug-CN", culture.name());
      assert::are_equal("ئۇيغۇرچە (جۇڭگو)", culture.native_name());
    }
    
    auto test_method_(uk) {
      auto culture = culture_info {"uk"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Ukrainian", culture.display_name());
      assert::are_equal("Ukrainian", culture.english_name());
      assert::are_equal(34_z, culture.keyboard_layout_id());
      assert::are_equal(34_z, culture.lcid());
      assert::are_equal("uk", culture.name());
      assert::are_equal("українська", culture.native_name());
    }
    
    auto test_method_(uk_UA) {
      auto culture = culture_info {"uk-UA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Ukrainian (Ukraine)", culture.display_name());
      assert::are_equal("Ukrainian (Ukraine)", culture.english_name());
      assert::are_equal(1058_z, culture.keyboard_layout_id());
      assert::are_equal(1058_z, culture.lcid());
      assert::are_equal("uk-UA", culture.name());
      assert::are_equal("українська (Україна)", culture.native_name());
    }
    
    auto test_method_(ur) {
      auto culture = culture_info {"ur"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Urdu", culture.display_name());
      assert::are_equal("Urdu", culture.english_name());
      assert::are_equal(32_z, culture.keyboard_layout_id());
      assert::are_equal(32_z, culture.lcid());
      assert::are_equal("ur", culture.name());
      assert::are_equal("اردو", culture.native_name());
    }
    
    auto test_method_(ur_Arab) {
      auto culture = culture_info {"ur-Arab"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Urdu (Naskh)", culture.display_name());
      assert::are_equal("Urdu (Naskh)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ur-Arab", culture.name());
      assert::are_equal("اردو (نسخ)", culture.native_name());
    }
    
    auto test_method_(ur_Arab_IN) {
      auto culture = culture_info {"ur-Arab-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Urdu (Naskh, India)", culture.display_name());
      assert::are_equal("Urdu (Naskh, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ur-Arab-IN", culture.name());
      assert::are_equal("اردو (نسخ،بھارت)", culture.native_name());
    }
    
    auto test_method_(ur_Arab_PK) {
      auto culture = culture_info {"ur-Arab-PK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Urdu (Naskh, Pakistan)", culture.display_name());
      assert::are_equal("Urdu (Naskh, Pakistan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ur-Arab-PK", culture.name());
      assert::are_equal("اردو (نسخ،پاکستان)", culture.native_name());
    }
    
    auto test_method_(ur_Aran_IN) {
      auto culture = culture_info {"ur-Aran-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Urdu (Nastaliq, India)", culture.display_name());
      assert::are_equal("Urdu (Nastaliq, India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ur-Aran-IN", culture.name());
      assert::are_equal("اردو (نستعلیق،بھارت)", culture.native_name());
    }
    
    auto test_method_(ur_Aran_PK) {
      auto culture = culture_info {"ur-Aran-PK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Urdu (Nastaliq, Pakistan)", culture.display_name());
      assert::are_equal("Urdu (Nastaliq, Pakistan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("ur-Aran-PK", culture.name());
      assert::are_equal("اردو (نستعلیق،پاکستان)", culture.native_name());
    }
    
    auto test_method_(uz) {
      auto culture = culture_info {"uz"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Uzbek", culture.display_name());
      assert::are_equal("Uzbek", culture.english_name());
      assert::are_equal(67_z, culture.keyboard_layout_id());
      assert::are_equal(67_z, culture.lcid());
      assert::are_equal("uz", culture.name());
      assert::are_equal("o‘zbek", culture.native_name());
    }
    
    auto test_method_(uz_Arab) {
      auto culture = culture_info {"uz-Arab"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Uzbek (Arabic)", culture.display_name());
      assert::are_equal("Uzbek (Arabic)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("uz-Arab", culture.name());
      assert::are_equal("اوزبیک (عربی)", culture.native_name());
    }
    
    auto test_method_(uz_Arab_AF) {
      auto culture = culture_info {"uz-Arab-AF"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Uzbek (Arabic, Afghanistan)", culture.display_name());
      assert::are_equal("Uzbek (Arabic, Afghanistan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("uz-Arab-AF", culture.name());
      assert::are_equal("اوزبیک (عربی, افغانستان)", culture.native_name());
    }
    
    auto test_method_(uz_Cyrl) {
      auto culture = culture_info {"uz-Cyrl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Uzbek (Cyrillic)", culture.display_name());
      assert::are_equal("Uzbek (Cyrillic)", culture.english_name());
      assert::are_equal(30787_z, culture.keyboard_layout_id());
      assert::are_equal(30787_z, culture.lcid());
      assert::are_equal("uz-Cyrl", culture.name());
      assert::are_equal("ўзбекча (Кирил)", culture.native_name());
    }
    
    auto test_method_(uz_Cyrl_UZ) {
      auto culture = culture_info {"uz-Cyrl-UZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Uzbek (Cyrillic, Uzbekistan)", culture.display_name());
      assert::are_equal("Uzbek (Cyrillic, Uzbekistan)", culture.english_name());
      assert::are_equal(2115_z, culture.keyboard_layout_id());
      assert::are_equal(2115_z, culture.lcid());
      assert::are_equal("uz-Cyrl-UZ", culture.name());
      assert::are_equal("ўзбекча (Кирил, Ўзбекистон)", culture.native_name());
    }
    
    auto test_method_(uz_Latn) {
      auto culture = culture_info {"uz-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Uzbek (Latin)", culture.display_name());
      assert::are_equal("Uzbek (Latin)", culture.english_name());
      assert::are_equal(31811_z, culture.keyboard_layout_id());
      assert::are_equal(31811_z, culture.lcid());
      assert::are_equal("uz-Latn", culture.name());
      assert::are_equal("o‘zbek (lotin)", culture.native_name());
    }
    
    auto test_method_(uz_Latn_UZ) {
      auto culture = culture_info {"uz-Latn-UZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Uzbek (Latin, Uzbekistan)", culture.display_name());
      assert::are_equal("Uzbek (Latin, Uzbekistan)", culture.english_name());
      assert::are_equal(1091_z, culture.keyboard_layout_id());
      assert::are_equal(1091_z, culture.lcid());
      assert::are_equal("uz-Latn-UZ", culture.name());
      assert::are_equal("o‘zbek (lotin, Oʻzbekiston)", culture.native_name());
    }
    
    auto test_method_(vai) {
      auto culture = culture_info {"vai"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Vai", culture.display_name());
      assert::are_equal("Vai", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vai", culture.name());
      assert::are_equal("ꕙꔤ", culture.native_name());
    }
    
    auto test_method_(vai_Latn) {
      auto culture = culture_info {"vai-Latn"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Vai (Latin)", culture.display_name());
      assert::are_equal("Vai (Latin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vai-Latn", culture.name());
      assert::are_equal("Vai (Latin)", culture.native_name());
    }
    
    auto test_method_(vai_Latn_LR) {
      auto culture = culture_info {"vai-Latn-LR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Vai (Latin, Liberia)", culture.display_name());
      assert::are_equal("Vai (Latin, Liberia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vai-Latn-LR", culture.name());
      assert::are_equal("Vai (Latin, Liberia)", culture.native_name());
    }
    
    auto test_method_(vai_Vaii) {
      auto culture = culture_info {"vai-Vaii"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Vai (Vai)", culture.display_name());
      assert::are_equal("Vai (Vai)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vai-Vaii", culture.name());
      assert::are_equal("Vai (Vai)", culture.native_name());
    }
    
    auto test_method_(vai_Vaii_LR) {
      auto culture = culture_info {"vai-Vaii-LR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Vai (Vai, Liberia)", culture.display_name());
      assert::are_equal("Vai (Vai, Liberia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vai-Vaii-LR", culture.name());
      assert::are_equal("Vai (Vai, Liberia)", culture.native_name());
    }
    
    auto test_method_(ve) {
      auto culture = culture_info {"ve"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Venda", culture.display_name());
      assert::are_equal("Venda", culture.english_name());
      assert::are_equal(51_z, culture.keyboard_layout_id());
      assert::are_equal(51_z, culture.lcid());
      assert::are_equal("ve", culture.name());
      assert::are_equal("Tshivenḓa", culture.native_name());
    }
    
    auto test_method_(ve_ZA) {
      auto culture = culture_info {"ve-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Venda (South Africa)", culture.display_name());
      assert::are_equal("Venda (South Africa)", culture.english_name());
      assert::are_equal(1075_z, culture.keyboard_layout_id());
      assert::are_equal(1075_z, culture.lcid());
      assert::are_equal("ve-ZA", culture.name());
      assert::are_equal("Venda (South Africa)", culture.native_name());
    }
    
    auto test_method_(vec) {
      auto culture = culture_info {"vec"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Venetian", culture.display_name());
      assert::are_equal("Venetian", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vec", culture.name());
      assert::are_equal("veneto", culture.native_name());
    }
    
    auto test_method_(vec_IT) {
      auto culture = culture_info {"vec-IT"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Venetian (Italy)", culture.display_name());
      assert::are_equal("Venetian (Italy)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vec-IT", culture.name());
      assert::are_equal("veneto (Italia)", culture.native_name());
    }
    
    auto test_method_(vi) {
      auto culture = culture_info {"vi"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Vietnamese", culture.display_name());
      assert::are_equal("Vietnamese", culture.english_name());
      assert::are_equal(42_z, culture.keyboard_layout_id());
      assert::are_equal(42_z, culture.lcid());
      assert::are_equal("vi", culture.name());
      assert::are_equal("Tiếng Việt", culture.native_name());
    }
    
    auto test_method_(vi_VN) {
      auto culture = culture_info {"vi-VN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Vietnamese (Vietnam)", culture.display_name());
      assert::are_equal("Vietnamese (Vietnam)", culture.english_name());
      assert::are_equal(1066_z, culture.keyboard_layout_id());
      assert::are_equal(1066_z, culture.lcid());
      assert::are_equal("vi-VN", culture.name());
      assert::are_equal("Tiếng Việt (Việt Nam)", culture.native_name());
    }
    
    auto test_method_(vmw) {
      auto culture = culture_info {"vmw"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Makhuwa", culture.display_name());
      assert::are_equal("Makhuwa", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vmw", culture.name());
      assert::are_equal("emakhuwa", culture.native_name());
    }
    
    auto test_method_(vmw_MZ) {
      auto culture = culture_info {"vmw-MZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Makhuwa (Mozambique)", culture.display_name());
      assert::are_equal("Makhuwa (Mozambique)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vmw-MZ", culture.name());
      assert::are_equal("emakhuwa (oMosambikhi)", culture.native_name());
    }
    
    auto test_method_(vun) {
      auto culture = culture_info {"vun"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Vunjo", culture.display_name());
      assert::are_equal("Vunjo", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vun", culture.name());
      assert::are_equal("Kyivunjo", culture.native_name());
    }
    
    auto test_method_(vun_TZ) {
      auto culture = culture_info {"vun-TZ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Vunjo (Tanzania)", culture.display_name());
      assert::are_equal("Vunjo (Tanzania)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("vun-TZ", culture.name());
      assert::are_equal("Kyivunjo (Tanzania)", culture.native_name());
    }
    
    auto test_method_(wa) {
      auto culture = culture_info {"wa"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Walloon", culture.display_name());
      assert::are_equal("Walloon", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("wa", culture.name());
      assert::are_equal("walon", culture.native_name());
    }
    
    auto test_method_(wa_BE) {
      auto culture = culture_info {"wa-BE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Walloon (Belgium)", culture.display_name());
      assert::are_equal("Walloon (Belgium)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("wa-BE", culture.name());
      assert::are_equal("Walloon (Belgium)", culture.native_name());
    }
    
    auto test_method_(wae) {
      auto culture = culture_info {"wae"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Walser", culture.display_name());
      assert::are_equal("Walser", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("wae", culture.name());
      assert::are_equal("Walser", culture.native_name());
    }
    
    auto test_method_(wae_CH) {
      auto culture = culture_info {"wae-CH"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Walser (Switzerland)", culture.display_name());
      assert::are_equal("Walser (Switzerland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("wae-CH", culture.name());
      assert::are_equal("Walser (Schwiz)", culture.native_name());
    }
    
    auto test_method_(wal) {
      auto culture = culture_info {"wal"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Wolaytta", culture.display_name());
      assert::are_equal("Wolaytta", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("wal", culture.name());
      assert::are_equal("ወላይታቱ", culture.native_name());
    }
    
    auto test_method_(wal_ET) {
      auto culture = culture_info {"wal-ET"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Wolaytta (Ethiopia)", culture.display_name());
      assert::are_equal("Wolaytta (Ethiopia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("wal-ET", culture.name());
      assert::are_equal("ወላይታቱ (ኢትዮጵያ)", culture.native_name());
    }
    
    auto test_method_(wo) {
      auto culture = culture_info {"wo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Wolof", culture.display_name());
      assert::are_equal("Wolof", culture.english_name());
      assert::are_equal(136_z, culture.keyboard_layout_id());
      assert::are_equal(136_z, culture.lcid());
      assert::are_equal("wo", culture.name());
      assert::are_equal("Wolof", culture.native_name());
    }
    
    auto test_method_(wo_SN) {
      auto culture = culture_info {"wo-SN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Wolof (Senegal)", culture.display_name());
      assert::are_equal("Wolof (Senegal)", culture.english_name());
      assert::are_equal(1160_z, culture.keyboard_layout_id());
      assert::are_equal(1160_z, culture.lcid());
      assert::are_equal("wo-SN", culture.name());
      assert::are_equal("Wolof (Senegaal)", culture.native_name());
    }
    
    auto test_method_(xh) {
      auto culture = culture_info {"xh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Xhosa", culture.display_name());
      assert::are_equal("Xhosa", culture.english_name());
      assert::are_equal(52_z, culture.keyboard_layout_id());
      assert::are_equal(52_z, culture.lcid());
      assert::are_equal("xh", culture.name());
      assert::are_equal("IsiXhosa", culture.native_name());
    }
    
    auto test_method_(xh_ZA) {
      auto culture = culture_info {"xh-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Xhosa (South Africa)", culture.display_name());
      assert::are_equal("Xhosa (South Africa)", culture.english_name());
      assert::are_equal(1076_z, culture.keyboard_layout_id());
      assert::are_equal(1076_z, culture.lcid());
      assert::are_equal("xh-ZA", culture.name());
      assert::are_equal("IsiXhosa (EMzantsi Afrika)", culture.native_name());
    }
    
    auto test_method_(xnr) {
      auto culture = culture_info {"xnr"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Kangri", culture.display_name());
      assert::are_equal("Kangri", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("xnr", culture.name());
      assert::are_equal("कांगड़ी", culture.native_name());
    }
    
    auto test_method_(xnr_IN) {
      auto culture = culture_info {"xnr-IN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Kangri (India)", culture.display_name());
      assert::are_equal("Kangri (India)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("xnr-IN", culture.name());
      assert::are_equal("कांगड़ी (भारत)", culture.native_name());
    }
    
    auto test_method_(xog) {
      auto culture = culture_info {"xog"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Soga", culture.display_name());
      assert::are_equal("Soga", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("xog", culture.name());
      assert::are_equal("Olusoga", culture.native_name());
    }
    
    auto test_method_(xog_UG) {
      auto culture = culture_info {"xog-UG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Soga (Uganda)", culture.display_name());
      assert::are_equal("Soga (Uganda)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("xog-UG", culture.name());
      assert::are_equal("Olusoga (Yuganda)", culture.native_name());
    }
    
    auto test_method_(yav) {
      auto culture = culture_info {"yav"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Yangben", culture.display_name());
      assert::are_equal("Yangben", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yav", culture.name());
      assert::are_equal("nuasue", culture.native_name());
    }
    
    auto test_method_(yav_CM) {
      auto culture = culture_info {"yav-CM"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Yangben (Cameroon)", culture.display_name());
      assert::are_equal("Yangben (Cameroon)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yav-CM", culture.name());
      assert::are_equal("nuasue (Kemelún)", culture.native_name());
    }
    
    auto test_method_(yi) {
      auto culture = culture_info {"yi"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Yiddish", culture.display_name());
      assert::are_equal("Yiddish", culture.english_name());
      assert::are_equal(61_z, culture.keyboard_layout_id());
      assert::are_equal(61_z, culture.lcid());
      assert::are_equal("yi", culture.name());
      assert::are_equal("ייִדיש", culture.native_name());
    }
    
    auto test_method_(yi_UA) {
      auto culture = culture_info {"yi-UA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Yiddish (Ukraine)", culture.display_name());
      assert::are_equal("Yiddish (Ukraine)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yi-UA", culture.name());
      assert::are_equal("ייִדיש (אוקראַינע)", culture.native_name());
    }
    
    auto test_method_(yo) {
      auto culture = culture_info {"yo"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Yoruba", culture.display_name());
      assert::are_equal("Yoruba", culture.english_name());
      assert::are_equal(106_z, culture.keyboard_layout_id());
      assert::are_equal(106_z, culture.lcid());
      assert::are_equal("yo", culture.name());
      assert::are_equal("Èdè Yorùbá", culture.native_name());
    }
    
    auto test_method_(yo_BJ) {
      auto culture = culture_info {"yo-BJ"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Yoruba (Benin)", culture.display_name());
      assert::are_equal("Yoruba (Benin)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yo-BJ", culture.name());
      assert::are_equal("Èdè Yorùbá (Bɛ̀nɛ̀)", culture.native_name());
    }
    
    auto test_method_(yo_NG) {
      auto culture = culture_info {"yo-NG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Yoruba (Nigeria)", culture.display_name());
      assert::are_equal("Yoruba (Nigeria)", culture.english_name());
      assert::are_equal(1130_z, culture.keyboard_layout_id());
      assert::are_equal(1130_z, culture.lcid());
      assert::are_equal("yo-NG", culture.name());
      assert::are_equal("Èdè Yorùbá (Nàìjíríà)", culture.native_name());
    }
    
    auto test_method_(yrl) {
      auto culture = culture_info {"yrl"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Nheengatu", culture.display_name());
      assert::are_equal("Nheengatu", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yrl", culture.name());
      assert::are_equal("nheẽgatu", culture.native_name());
    }
    
    auto test_method_(yrl_BR) {
      auto culture = culture_info {"yrl-BR"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nheengatu (Brazil)", culture.display_name());
      assert::are_equal("Nheengatu (Brazil)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yrl-BR", culture.name());
      assert::are_equal("nheẽgatu (Brasiu)", culture.native_name());
    }
    
    auto test_method_(yrl_CO) {
      auto culture = culture_info {"yrl-CO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nheengatu (Colombia)", culture.display_name());
      assert::are_equal("Nheengatu (Colombia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yrl-CO", culture.name());
      assert::are_equal("ñengatú (Kurũbiya)", culture.native_name());
    }
    
    auto test_method_(yrl_VE) {
      auto culture = culture_info {"yrl-VE"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Nheengatu (Venezuela)", culture.display_name());
      assert::are_equal("Nheengatu (Venezuela)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yrl-VE", culture.name());
      assert::are_equal("ñengatú (Wenesuera)", culture.native_name());
    }
    
    auto test_method_(yue) {
      auto culture = culture_info {"yue"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Cantonese", culture.display_name());
      assert::are_equal("Cantonese", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yue", culture.name());
      assert::are_equal("廣東話", culture.native_name());
    }
    
    auto test_method_(yue_Hans) {
      auto culture = culture_info {"yue-Hans"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Cantonese, Simplified", culture.display_name());
      assert::are_equal("Cantonese, Simplified", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yue-Hans", culture.name());
      assert::are_equal("简体粤语", culture.native_name());
    }
    
    auto test_method_(yue_Hans_CN) {
      auto culture = culture_info {"yue-Hans-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Cantonese, Simplified (China mainland)", culture.display_name());
      assert::are_equal("Cantonese, Simplified (China mainland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yue-Hans-CN", culture.name());
      assert::are_equal("简体粤语（中国大陆）", culture.native_name());
    }
    
    auto test_method_(yue_Hant) {
      auto culture = culture_info {"yue-Hant"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Cantonese, Traditional", culture.display_name());
      assert::are_equal("Cantonese, Traditional", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yue-Hant", culture.name());
      assert::are_equal("繁體廣東話", culture.native_name());
    }
    
    auto test_method_(yue_Hant_CN) {
      auto culture = culture_info {"yue-Hant-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Cantonese, Traditional (China mainland)", culture.display_name());
      assert::are_equal("Cantonese, Traditional (China mainland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yue-Hant-CN", culture.name());
      assert::are_equal("繁體廣東話（中國）", culture.native_name());
    }
    
    auto test_method_(yue_Hant_HK) {
      auto culture = culture_info {"yue-Hant-HK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Cantonese, Traditional (Hong Kong)", culture.display_name());
      assert::are_equal("Cantonese, Traditional (Hong Kong)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("yue-Hant-HK", culture.name());
      assert::are_equal("繁體廣東話（香港）", culture.native_name());
    }
    
    auto test_method_(za) {
      auto culture = culture_info {"za"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Zhuang", culture.display_name());
      assert::are_equal("Zhuang", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("za", culture.name());
      assert::are_equal("Vahcuengh", culture.native_name());
    }
    
    auto test_method_(za_CN) {
      auto culture = culture_info {"za-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Zhuang (China mainland)", culture.display_name());
      assert::are_equal("Zhuang (China mainland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("za-CN", culture.name());
      assert::are_equal("Vahcuengh (Cunghgoz)", culture.native_name());
    }
    
    auto test_method_(zgh) {
      auto culture = culture_info {"zgh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Tamazight, Standard Moroccan", culture.display_name());
      assert::are_equal("Tamazight, Standard Moroccan", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zgh", culture.name());
      assert::are_equal("ⵜⴰⵎⴰⵣⵉⵖⵜ", culture.native_name());
    }
    
    auto test_method_(zgh_MA) {
      auto culture = culture_info {"zgh-MA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Tamazight, Standard Moroccan (Morocco)", culture.display_name());
      assert::are_equal("Tamazight, Standard Moroccan (Morocco)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zgh-MA", culture.name());
      assert::are_equal("ⵜⴰⵎⴰⵣⵉⵖⵜ (ⵍⵎⵖⵔⵉⴱ)", culture.native_name());
    }
    
    auto test_method_(zh) {
      auto culture = culture_info {"zh"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Chinese", culture.display_name());
      assert::are_equal("Chinese", culture.english_name());
      assert::are_equal(30724_z, culture.keyboard_layout_id());
      assert::are_equal(30724_z, culture.lcid());
      assert::are_equal("zh", culture.name());
      assert::are_equal("中文", culture.native_name());
    }
    
    auto test_method_(zh_Hans) {
      auto culture = culture_info {"zh-Hans"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Chinese, Simplified", culture.display_name());
      assert::are_equal("Chinese, Simplified", culture.english_name());
      assert::are_equal(4_z, culture.keyboard_layout_id());
      assert::are_equal(4_z, culture.lcid());
      assert::are_equal("zh-Hans", culture.name());
      assert::are_equal("简体中文", culture.native_name());
    }
    
    auto test_method_(zh_Hans_CN) {
      auto culture = culture_info {"zh-Hans-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Simplified (China mainland)", culture.display_name());
      assert::are_equal("Chinese, Simplified (China mainland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hans-CN", culture.name());
      assert::are_equal("简体中文（中国大陆）", culture.native_name());
    }
    
    auto test_method_(zh_Hans_HK) {
      auto culture = culture_info {"zh-Hans-HK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Simplified (Hong Kong)", culture.display_name());
      assert::are_equal("Chinese, Simplified (Hong Kong)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hans-HK", culture.name());
      assert::are_equal("简体中文（香港）", culture.native_name());
    }
    
    auto test_method_(zh_Hans_JP) {
      auto culture = culture_info {"zh-Hans-JP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Simplified (Japan)", culture.display_name());
      assert::are_equal("Chinese, Simplified (Japan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hans-JP", culture.name());
      assert::are_equal("简体中文（日本）", culture.native_name());
    }
    
    auto test_method_(zh_Hans_MO) {
      auto culture = culture_info {"zh-Hans-MO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Simplified (Macao)", culture.display_name());
      assert::are_equal("Chinese, Simplified (Macao)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hans-MO", culture.name());
      assert::are_equal("简体中文（澳门）", culture.native_name());
    }
    
    auto test_method_(zh_Hans_MY) {
      auto culture = culture_info {"zh-Hans-MY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Simplified (Malaysia)", culture.display_name());
      assert::are_equal("Chinese, Simplified (Malaysia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hans-MY", culture.name());
      assert::are_equal("简体中文（马来西亚）", culture.native_name());
    }
    
    auto test_method_(zh_Hans_SG) {
      auto culture = culture_info {"zh-Hans-SG"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Simplified (Singapore)", culture.display_name());
      assert::are_equal("Chinese, Simplified (Singapore)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hans-SG", culture.name());
      assert::are_equal("简体中文（新加坡）", culture.native_name());
    }
    
    auto test_method_(zh_Hant) {
      auto culture = culture_info {"zh-Hant"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Chinese, Traditional", culture.display_name());
      assert::are_equal("Chinese, Traditional", culture.english_name());
      assert::are_equal(31748_z, culture.keyboard_layout_id());
      assert::are_equal(31748_z, culture.lcid());
      assert::are_equal("zh-Hant", culture.name());
      assert::are_equal("繁體中文", culture.native_name());
    }
    
    auto test_method_(zh_Hant_CN) {
      auto culture = culture_info {"zh-Hant-CN"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Traditional (China mainland)", culture.display_name());
      assert::are_equal("Chinese, Traditional (China mainland)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hant-CN", culture.name());
      assert::are_equal("繁體中文（中國大陸）", culture.native_name());
    }
    
    auto test_method_(zh_Hant_HK) {
      auto culture = culture_info {"zh-Hant-HK"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Traditional (Hong Kong)", culture.display_name());
      assert::are_equal("Chinese, Traditional (Hong Kong)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hant-HK", culture.name());
      assert::are_equal("繁體中文（香港）", culture.native_name());
    }
    
    auto test_method_(zh_Hant_JP) {
      auto culture = culture_info {"zh-Hant-JP"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Traditional (Japan)", culture.display_name());
      assert::are_equal("Chinese, Traditional (Japan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hant-JP", culture.name());
      assert::are_equal("繁體中文（日本）", culture.native_name());
    }
    
    auto test_method_(zh_Hant_MO) {
      auto culture = culture_info {"zh-Hant-MO"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Traditional (Macao)", culture.display_name());
      assert::are_equal("Chinese, Traditional (Macao)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hant-MO", culture.name());
      assert::are_equal("繁體中文（澳門）", culture.native_name());
    }
    
    auto test_method_(zh_Hant_MY) {
      auto culture = culture_info {"zh-Hant-MY"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Traditional (Malaysia)", culture.display_name());
      assert::are_equal("Chinese, Traditional (Malaysia)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hant-MY", culture.name());
      assert::are_equal("繁體中文（馬來西亞）", culture.native_name());
    }
    
    auto test_method_(zh_Hant_TW) {
      auto culture = culture_info {"zh-Hant-TW"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Chinese, Traditional (Taiwan)", culture.display_name());
      assert::are_equal("Chinese, Traditional (Taiwan)", culture.english_name());
      assert::are_equal(1033_z, culture.keyboard_layout_id());
      assert::are_equal(4096_z, culture.lcid());
      assert::are_equal("zh-Hant-TW", culture.name());
      assert::are_equal("繁體中文（台灣）", culture.native_name());
    }
    
    auto test_method_(zu) {
      auto culture = culture_info {"zu"};
      assert::are_equal(globalization::culture_types::neutral_cultures, culture.culture_types());
      assert::are_equal("Zulu", culture.display_name());
      assert::are_equal("Zulu", culture.english_name());
      assert::are_equal(53_z, culture.keyboard_layout_id());
      assert::are_equal(53_z, culture.lcid());
      assert::are_equal("zu", culture.name());
      assert::are_equal("isiZulu", culture.native_name());
    }
    
    auto test_method_(zu_ZA) {
      auto culture = culture_info {"zu-ZA"};
      assert::are_equal(globalization::culture_types::specific_cultures, culture.culture_types());
      assert::are_equal("Zulu (South Africa)", culture.display_name());
      assert::are_equal("Zulu (South Africa)", culture.english_name());
      assert::are_equal(1077_z, culture.keyboard_layout_id());
      assert::are_equal(1077_z, culture.lcid());
      assert::are_equal("zu-ZA", culture.name());
      assert::are_equal("isiZulu (iNingizimu Afrika)", culture.native_name());
    }
  };
}
