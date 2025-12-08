#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(environment_special_folder_tests) {
    auto test_method_(desktop) {
      assert::are_equal(0, enum_object<>::to_int32(environment::special_folder::desktop));
      assert::are_equal("desktop", enum_object<>::to_string(environment::special_folder::desktop));
      assert::are_equal(environment::special_folder::desktop, enum_object<>::parse<environment::special_folder>("desktop"));
    }
    
    auto test_method_(programs) {
      assert::are_equal(2, enum_object<>::to_int32(environment::special_folder::programs));
      assert::are_equal("programs", enum_object<>::to_string(environment::special_folder::programs));
      assert::are_equal(environment::special_folder::programs, enum_object<>::parse<environment::special_folder>("programs"));
    }
    
    auto test_method_(my_documents) {
      assert::are_equal(5, enum_object<>::to_int32(environment::special_folder::my_documents));
      assert::are_equal("my_documents", enum_object<>::to_string(environment::special_folder::my_documents));
      assert::are_equal(environment::special_folder::my_documents, enum_object<>::parse<environment::special_folder>("my_documents"));
    }
    
    auto test_method_(favorites) {
      assert::are_equal(6, enum_object<>::to_int32(environment::special_folder::favorites));
      assert::are_equal("favorites", enum_object<>::to_string(environment::special_folder::favorites));
      assert::are_equal(environment::special_folder::favorites, enum_object<>::parse<environment::special_folder>("favorites"));
    }
    
    auto test_method_(startup) {
      assert::are_equal(7, enum_object<>::to_int32(environment::special_folder::startup));
      assert::are_equal("startup", enum_object<>::to_string(environment::special_folder::startup));
      assert::are_equal(environment::special_folder::startup, enum_object<>::parse<environment::special_folder>("startup"));
    }
    
    auto test_method_(recent) {
      assert::are_equal(8, enum_object<>::to_int32(environment::special_folder::recent));
      assert::are_equal("recent", enum_object<>::to_string(environment::special_folder::recent));
      assert::are_equal(environment::special_folder::recent, enum_object<>::parse<environment::special_folder>("recent"));
    }
    
    auto test_method_(send_to) {
      assert::are_equal(9, enum_object<>::to_int32(environment::special_folder::send_to));
      assert::are_equal("send_to", enum_object<>::to_string(environment::special_folder::send_to));
      assert::are_equal(environment::special_folder::send_to, enum_object<>::parse<environment::special_folder>("send_to"));
    }
    
    auto test_method_(start_menu) {
      assert::are_equal(11, enum_object<>::to_int32(environment::special_folder::start_menu));
      assert::are_equal("start_menu", enum_object<>::to_string(environment::special_folder::start_menu));
      assert::are_equal(environment::special_folder::start_menu, enum_object<>::parse<environment::special_folder>("start_menu"));
    }
    
    auto test_method_(my_music) {
      assert::are_equal(13, enum_object<>::to_int32(environment::special_folder::my_music));
      assert::are_equal("my_music", enum_object<>::to_string(environment::special_folder::my_music));
      assert::are_equal(environment::special_folder::my_music, enum_object<>::parse<environment::special_folder>("my_music"));
    }
    
    auto test_method_(my_videos) {
      assert::are_equal(14, enum_object<>::to_int32(environment::special_folder::my_videos));
      assert::are_equal("my_videos", enum_object<>::to_string(environment::special_folder::my_videos));
      assert::are_equal(environment::special_folder::my_videos, enum_object<>::parse<environment::special_folder>("my_videos"));
    }
    
    auto test_method_(desktop_directory) {
      assert::are_equal(16, enum_object<>::to_int32(environment::special_folder::desktop_directory));
      assert::are_equal("desktop_directory", enum_object<>::to_string(environment::special_folder::desktop_directory));
      assert::are_equal(environment::special_folder::desktop_directory, enum_object<>::parse<environment::special_folder>("desktop_directory"));
    }
    
    auto test_method_(my_computer) {
      assert::are_equal(17, enum_object<>::to_int32(environment::special_folder::my_computer));
      assert::are_equal("my_computer", enum_object<>::to_string(environment::special_folder::my_computer));
      assert::are_equal(environment::special_folder::my_computer, enum_object<>::parse<environment::special_folder>("my_computer"));
    }
    
    auto test_method_(network_shortcuts) {
      assert::are_equal(19, enum_object<>::to_int32(environment::special_folder::network_shortcuts));
      assert::are_equal("network_shortcuts", enum_object<>::to_string(environment::special_folder::network_shortcuts));
      assert::are_equal(environment::special_folder::network_shortcuts, enum_object<>::parse<environment::special_folder>("network_shortcuts"));
    }
    
    auto test_method_(fonts) {
      assert::are_equal(20, enum_object<>::to_int32(environment::special_folder::fonts));
      assert::are_equal("fonts", enum_object<>::to_string(environment::special_folder::fonts));
      assert::are_equal(environment::special_folder::fonts, enum_object<>::parse<environment::special_folder>("fonts"));
    }
    
    auto test_method_(templates) {
      assert::are_equal(21, enum_object<>::to_int32(environment::special_folder::templates));
      assert::are_equal("templates", enum_object<>::to_string(environment::special_folder::templates));
      assert::are_equal(environment::special_folder::templates, enum_object<>::parse<environment::special_folder>("templates"));
    }
    
    auto test_method_(common_start_menu) {
      assert::are_equal(22, enum_object<>::to_int32(environment::special_folder::common_start_menu));
      assert::are_equal("common_start_menu", enum_object<>::to_string(environment::special_folder::common_start_menu));
      assert::are_equal(environment::special_folder::common_start_menu, enum_object<>::parse<environment::special_folder>("common_start_menu"));
    }
    
    auto test_method_(common_programs) {
      assert::are_equal(23, enum_object<>::to_int32(environment::special_folder::common_programs));
      assert::are_equal("common_programs", enum_object<>::to_string(environment::special_folder::common_programs));
      assert::are_equal(environment::special_folder::common_programs, enum_object<>::parse<environment::special_folder>("common_programs"));
    }
    
    auto test_method_(common_startup) {
      assert::are_equal(24, enum_object<>::to_int32(environment::special_folder::common_startup));
      assert::are_equal("common_startup", enum_object<>::to_string(environment::special_folder::common_startup));
      assert::are_equal(environment::special_folder::common_startup, enum_object<>::parse<environment::special_folder>("common_startup"));
    }
    
    auto test_method_(common_desktop_directory) {
      assert::are_equal(25, enum_object<>::to_int32(environment::special_folder::common_desktop_directory));
      assert::are_equal("common_desktop_directory", enum_object<>::to_string(environment::special_folder::common_desktop_directory));
      assert::are_equal(environment::special_folder::common_desktop_directory, enum_object<>::parse<environment::special_folder>("common_desktop_directory"));
    }
    
    auto test_method_(application_data) {
      assert::are_equal(26, enum_object<>::to_int32(environment::special_folder::application_data));
      assert::are_equal("application_data", enum_object<>::to_string(environment::special_folder::application_data));
      assert::are_equal(environment::special_folder::application_data, enum_object<>::parse<environment::special_folder>("application_data"));
    }
    
    auto test_method_(printer_shortcuts) {
      assert::are_equal(27, enum_object<>::to_int32(environment::special_folder::printer_shortcuts));
      assert::are_equal("printer_shortcuts", enum_object<>::to_string(environment::special_folder::printer_shortcuts));
      assert::are_equal(environment::special_folder::printer_shortcuts, enum_object<>::parse<environment::special_folder>("printer_shortcuts"));
    }
    
    auto test_method_(local_application_data) {
      assert::are_equal(28, enum_object<>::to_int32(environment::special_folder::local_application_data));
      assert::are_equal("local_application_data", enum_object<>::to_string(environment::special_folder::local_application_data));
      assert::are_equal(environment::special_folder::local_application_data, enum_object<>::parse<environment::special_folder>("local_application_data"));
    }
    
    auto test_method_(internet_cache) {
      assert::are_equal(32, enum_object<>::to_int32(environment::special_folder::internet_cache));
      assert::are_equal("internet_cache", enum_object<>::to_string(environment::special_folder::internet_cache));
      assert::are_equal(environment::special_folder::internet_cache, enum_object<>::parse<environment::special_folder>("internet_cache"));
    }
    
    auto test_method_(cookies) {
      assert::are_equal(33, enum_object<>::to_int32(environment::special_folder::cookies));
      assert::are_equal("cookies", enum_object<>::to_string(environment::special_folder::cookies));
      assert::are_equal(environment::special_folder::cookies, enum_object<>::parse<environment::special_folder>("cookies"));
    }
    
    auto test_method_(history) {
      assert::are_equal(34, enum_object<>::to_int32(environment::special_folder::history));
      assert::are_equal("history", enum_object<>::to_string(environment::special_folder::history));
      assert::are_equal(environment::special_folder::history, enum_object<>::parse<environment::special_folder>("history"));
    }
    
    auto test_method_(common_application_data) {
      assert::are_equal(35, enum_object<>::to_int32(environment::special_folder::common_application_data));
      assert::are_equal("common_application_data", enum_object<>::to_string(environment::special_folder::common_application_data));
      assert::are_equal(environment::special_folder::common_application_data, enum_object<>::parse<environment::special_folder>("common_application_data"));
    }
    
    auto test_method_(windows) {
      assert::are_equal(36, enum_object<>::to_int32(environment::special_folder::windows));
      assert::are_equal("windows", enum_object<>::to_string(environment::special_folder::windows));
      assert::are_equal(environment::special_folder::windows, enum_object<>::parse<environment::special_folder>("windows"));
    }
    
    auto test_method_(system) {
      assert::are_equal(37, enum_object<>::to_int32(environment::special_folder::system));
      assert::are_equal("system", enum_object<>::to_string(environment::special_folder::system));
      assert::are_equal(environment::special_folder::system, enum_object<>::parse<environment::special_folder>("system"));
    }
    
    auto test_method_(program_files) {
      assert::are_equal(38, enum_object<>::to_int32(environment::special_folder::program_files));
      assert::are_equal("program_files", enum_object<>::to_string(environment::special_folder::program_files));
      assert::are_equal(environment::special_folder::program_files, enum_object<>::parse<environment::special_folder>("program_files"));
    }
    
    auto test_method_(my_pictures) {
      assert::are_equal(39, enum_object<>::to_int32(environment::special_folder::my_pictures));
      assert::are_equal("my_pictures", enum_object<>::to_string(environment::special_folder::my_pictures));
      assert::are_equal(environment::special_folder::my_pictures, enum_object<>::parse<environment::special_folder>("my_pictures"));
    }
    
    auto test_method_(user_profile) {
      assert::are_equal(40, enum_object<>::to_int32(environment::special_folder::user_profile));
      assert::are_equal("user_profile", enum_object<>::to_string(environment::special_folder::user_profile));
      assert::are_equal(environment::special_folder::user_profile, enum_object<>::parse<environment::special_folder>("user_profile"));
    }
    
    auto test_method_(system_x86) {
      assert::are_equal(41, enum_object<>::to_int32(environment::special_folder::system_x86));
      assert::are_equal("system_x86", enum_object<>::to_string(environment::special_folder::system_x86));
      assert::are_equal(environment::special_folder::system_x86, enum_object<>::parse<environment::special_folder>("system_x86"));
    }
    
    auto test_method_(program_files_x86) {
      assert::are_equal(42, enum_object<>::to_int32(environment::special_folder::program_files_x86));
      assert::are_equal("program_files_x86", enum_object<>::to_string(environment::special_folder::program_files_x86));
      assert::are_equal(environment::special_folder::program_files_x86, enum_object<>::parse<environment::special_folder>("program_files_x86"));
    }
    
    auto test_method_(common_program_files) {
      assert::are_equal(43, enum_object<>::to_int32(environment::special_folder::common_program_files));
      assert::are_equal("common_program_files", enum_object<>::to_string(environment::special_folder::common_program_files));
      assert::are_equal(environment::special_folder::common_program_files, enum_object<>::parse<environment::special_folder>("common_program_files"));
    }
    
    auto test_method_(common_program_files_x86) {
      assert::are_equal(44, enum_object<>::to_int32(environment::special_folder::common_program_files_x86));
      assert::are_equal("common_program_files_x86", enum_object<>::to_string(environment::special_folder::common_program_files_x86));
      assert::are_equal(environment::special_folder::common_program_files_x86, enum_object<>::parse<environment::special_folder>("common_program_files_x86"));
    }
    
    auto test_method_(common_templates) {
      assert::are_equal(45, enum_object<>::to_int32(environment::special_folder::common_templates));
      assert::are_equal("common_templates", enum_object<>::to_string(environment::special_folder::common_templates));
      assert::are_equal(environment::special_folder::common_templates, enum_object<>::parse<environment::special_folder>("common_templates"));
    }
    
    auto test_method_(common_documents) {
      assert::are_equal(46, enum_object<>::to_int32(environment::special_folder::common_documents));
      assert::are_equal("common_documents", enum_object<>::to_string(environment::special_folder::common_documents));
      assert::are_equal(environment::special_folder::common_documents, enum_object<>::parse<environment::special_folder>("common_documents"));
    }
    
    auto test_method_(common_admin_tools) {
      assert::are_equal(47, enum_object<>::to_int32(environment::special_folder::common_admin_tools));
      assert::are_equal("common_admin_tools", enum_object<>::to_string(environment::special_folder::common_admin_tools));
      assert::are_equal(environment::special_folder::common_admin_tools, enum_object<>::parse<environment::special_folder>("common_admin_tools"));
    }
    
    auto test_method_(admin_tools) {
      assert::are_equal(48, enum_object<>::to_int32(environment::special_folder::admin_tools));
      assert::are_equal("admin_tools", enum_object<>::to_string(environment::special_folder::admin_tools));
      assert::are_equal(environment::special_folder::admin_tools, enum_object<>::parse<environment::special_folder>("admin_tools"));
    }
    
    auto test_method_(common_music) {
      assert::are_equal(53, enum_object<>::to_int32(environment::special_folder::common_music));
      assert::are_equal("common_music", enum_object<>::to_string(environment::special_folder::common_music));
      assert::are_equal(environment::special_folder::common_music, enum_object<>::parse<environment::special_folder>("common_music"));
    }
    
    auto test_method_(common_pictures) {
      assert::are_equal(54, enum_object<>::to_int32(environment::special_folder::common_pictures));
      assert::are_equal("common_pictures", enum_object<>::to_string(environment::special_folder::common_pictures));
      assert::are_equal(environment::special_folder::common_pictures, enum_object<>::parse<environment::special_folder>("common_pictures"));
    }
    
    auto test_method_(common_videos) {
      assert::are_equal(55, enum_object<>::to_int32(environment::special_folder::common_videos));
      assert::are_equal("common_videos", enum_object<>::to_string(environment::special_folder::common_videos));
      assert::are_equal(environment::special_folder::common_videos, enum_object<>::parse<environment::special_folder>("common_videos"));
    }
    
    auto test_method_(resources) {
      assert::are_equal(56, enum_object<>::to_int32(environment::special_folder::resources));
      assert::are_equal("resources", enum_object<>::to_string(environment::special_folder::resources));
      assert::are_equal(environment::special_folder::resources, enum_object<>::parse<environment::special_folder>("resources"));
    }
    
    auto test_method_(localized_resources) {
      assert::are_equal(57, enum_object<>::to_int32(environment::special_folder::localized_resources));
      assert::are_equal("localized_resources", enum_object<>::to_string(environment::special_folder::localized_resources));
      assert::are_equal(environment::special_folder::localized_resources, enum_object<>::parse<environment::special_folder>("localized_resources"));
    }
    
    auto test_method_(common_oem_links) {
      assert::are_equal(58, enum_object<>::to_int32(environment::special_folder::common_oem_links));
      assert::are_equal("common_oem_links", enum_object<>::to_string(environment::special_folder::common_oem_links));
      assert::are_equal(environment::special_folder::common_oem_links, enum_object<>::parse<environment::special_folder>("common_oem_links"));
    }
    
    auto test_method_(cd_burning) {
      assert::are_equal(59, enum_object<>::to_int32(environment::special_folder::cd_burning));
      assert::are_equal("cd_burning", enum_object<>::to_string(environment::special_folder::cd_burning));
      assert::are_equal(environment::special_folder::cd_burning, enum_object<>::parse<environment::special_folder>("cd_burning"));
    }
    
    auto test_method_(home) {
      assert::are_equal(64, enum_object<>::to_int32(environment::special_folder::home));
      assert::are_equal("home", enum_object<>::to_string(environment::special_folder::home));
      assert::are_equal(environment::special_folder::home, enum_object<>::parse<environment::special_folder>("home"));
    }
    
    auto test_method_(application_resources) {
      assert::are_equal(999, enum_object<>::to_int32(environment::special_folder::application_resources));
      assert::are_equal("application_resources", enum_object<>::to_string(environment::special_folder::application_resources));
      assert::are_equal(environment::special_folder::application_resources, enum_object<>::parse<environment::special_folder>("application_resources"));
    }
    
    auto test_method_(xtd_install) {
      assert::are_equal(1000, enum_object<>::to_int32(environment::special_folder::xtd_install));
      assert::are_equal("xtd_install", enum_object<>::to_string(environment::special_folder::xtd_install));
      assert::are_equal(environment::special_folder::xtd_install, enum_object<>::parse<environment::special_folder>("xtd_install"));
    }
    
    auto test_method_(xtd_locale) {
      assert::are_equal(1001, enum_object<>::to_int32(environment::special_folder::xtd_locale));
      assert::are_equal("xtd_locale", enum_object<>::to_string(environment::special_folder::xtd_locale));
      assert::are_equal(environment::special_folder::xtd_locale, enum_object<>::parse<environment::special_folder>("xtd_locale"));
    }
    
    auto test_method_(xtd_reference_guide) {
      assert::are_equal(1002, enum_object<>::to_int32(environment::special_folder::xtd_reference_guide));
      assert::are_equal("xtd_reference_guide", enum_object<>::to_string(environment::special_folder::xtd_reference_guide));
      assert::are_equal(environment::special_folder::xtd_reference_guide, enum_object<>::parse<environment::special_folder>("xtd_reference_guide"));
    }
    
    auto test_method_(xtd_themes) {
      assert::are_equal(1003, enum_object<>::to_int32(environment::special_folder::xtd_themes));
      assert::are_equal("xtd_themes", enum_object<>::to_string(environment::special_folder::xtd_themes));
      assert::are_equal(environment::special_folder::xtd_themes, enum_object<>::parse<environment::special_folder>("xtd_themes"));
    }
    
    auto test_method_(xtd_include) {
      assert::are_equal(1004, enum_object<>::to_int32(environment::special_folder::xtd_include));
      assert::are_equal("xtd_include", enum_object<>::to_string(environment::special_folder::xtd_include));
      assert::are_equal(environment::special_folder::xtd_include, enum_object<>::parse<environment::special_folder>("xtd_include"));
    }
    
    auto test_method_(xtd_libraries) {
      assert::are_equal(1005, enum_object<>::to_int32(environment::special_folder::xtd_libraries));
      assert::are_equal("xtd_libraries", enum_object<>::to_string(environment::special_folder::xtd_libraries));
      assert::are_equal(environment::special_folder::xtd_libraries, enum_object<>::parse<environment::special_folder>("xtd_libraries"));
    }
    
    auto test_method_(xtd_resources) {
      assert::are_equal(1006, enum_object<>::to_int32(environment::special_folder::xtd_resources));
      assert::are_equal("xtd_resources", enum_object<>::to_string(environment::special_folder::xtd_resources));
      assert::are_equal(environment::special_folder::xtd_resources, enum_object<>::parse<environment::special_folder>("xtd_resources"));
    }
    
    auto test_method_(xtd_console_include) {
      assert::are_equal(1007, enum_object<>::to_int32(environment::special_folder::xtd_console_include));
      assert::are_equal("xtd_console_include", enum_object<>::to_string(environment::special_folder::xtd_console_include));
      assert::are_equal(environment::special_folder::xtd_console_include, enum_object<>::parse<environment::special_folder>("xtd_console_include"));
    }
    
    auto test_method_(xtd_console_libraries) {
      assert::are_equal(1008, enum_object<>::to_int32(environment::special_folder::xtd_console_libraries));
      assert::are_equal("xtd_console_libraries", enum_object<>::to_string(environment::special_folder::xtd_console_libraries));
      assert::are_equal(environment::special_folder::xtd_console_libraries, enum_object<>::parse<environment::special_folder>("xtd_console_libraries"));
    }
    
    auto test_method_(xtd_drawing_include) {
      assert::are_equal(1009, enum_object<>::to_int32(environment::special_folder::xtd_drawing_include));
      assert::are_equal("xtd_drawing_include", enum_object<>::to_string(environment::special_folder::xtd_drawing_include));
      assert::are_equal(environment::special_folder::xtd_drawing_include, enum_object<>::parse<environment::special_folder>("xtd_drawing_include"));
    }
    
    auto test_method_(xtd_drawing_libraries) {
      assert::are_equal(1010, enum_object<>::to_int32(environment::special_folder::xtd_drawing_libraries));
      assert::are_equal("xtd_drawing_libraries", enum_object<>::to_string(environment::special_folder::xtd_drawing_libraries));
      assert::are_equal(environment::special_folder::xtd_drawing_libraries, enum_object<>::parse<environment::special_folder>("xtd_drawing_libraries"));
    }
    
    auto test_method_(xtd_drawing_resources) {
      assert::are_equal(1011, enum_object<>::to_int32(environment::special_folder::xtd_drawing_resources));
      assert::are_equal("xtd_drawing_resources", enum_object<>::to_string(environment::special_folder::xtd_drawing_resources));
      assert::are_equal(environment::special_folder::xtd_drawing_resources, enum_object<>::parse<environment::special_folder>("xtd_drawing_resources"));
    }
    
    auto test_method_(xtd_forms_include) {
      assert::are_equal(1012, enum_object<>::to_int32(environment::special_folder::xtd_forms_include));
      assert::are_equal("xtd_forms_include", enum_object<>::to_string(environment::special_folder::xtd_forms_include));
      assert::are_equal(environment::special_folder::xtd_forms_include, enum_object<>::parse<environment::special_folder>("xtd_forms_include"));
    }
    
    auto test_method_(xtd_forms_libraries) {
      assert::are_equal(1013, enum_object<>::to_int32(environment::special_folder::xtd_forms_libraries));
      assert::are_equal("xtd_forms_libraries", enum_object<>::to_string(environment::special_folder::xtd_forms_libraries));
      assert::are_equal(environment::special_folder::xtd_forms_libraries, enum_object<>::parse<environment::special_folder>("xtd_forms_libraries"));
    }
    
    auto test_method_(xtd_forms_resources) {
      assert::are_equal(1014, enum_object<>::to_int32(environment::special_folder::xtd_forms_resources));
      assert::are_equal("xtd_forms_resources", enum_object<>::to_string(environment::special_folder::xtd_forms_resources));
      assert::are_equal(environment::special_folder::xtd_forms_resources, enum_object<>::parse<environment::special_folder>("xtd_forms_resources"));
    }
    
    auto test_method_(xtd_tunit_include) {
      assert::are_equal(1015, enum_object<>::to_int32(environment::special_folder::xtd_tunit_include));
      assert::are_equal("xtd_tunit_include", enum_object<>::to_string(environment::special_folder::xtd_tunit_include));
      assert::are_equal(environment::special_folder::xtd_tunit_include, enum_object<>::parse<environment::special_folder>("xtd_tunit_include"));
    }
    
    auto test_method_(xtd_tunit_libraries) {
      assert::are_equal(1016, enum_object<>::to_int32(environment::special_folder::xtd_tunit_libraries));
      assert::are_equal("xtd_tunit_libraries", enum_object<>::to_string(environment::special_folder::xtd_tunit_libraries));
      assert::are_equal(environment::special_folder::xtd_tunit_libraries, enum_object<>::parse<environment::special_folder>("xtd_tunit_libraries"));
    }
  };
}
