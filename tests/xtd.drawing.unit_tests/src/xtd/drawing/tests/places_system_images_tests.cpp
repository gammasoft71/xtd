#include <xtd/drawing/places_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(places_system_images_tests) {
    void test_method_(default_size) {
      auto s = places_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(folder) {
      auto i = places_system_images::folder();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder"), i, csf_);
    }

    void test_method_(folder_with_specified_size) {
      auto i = places_system_images::folder({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder", size {64, 64}), i, csf_);
    }

    void test_method_(folder_activities) {
      auto i = places_system_images::folder_activities();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-activities"), i, csf_);
    }

    void test_method_(folder_activities_with_specified_size) {
      auto i = places_system_images::folder_activities({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-activities", size {64, 64}), i, csf_);
    }

    void test_method_(folder_applications) {
      auto i = places_system_images::folder_applications();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-applications"), i, csf_);
    }

    void test_method_(folder_applications_with_specified_size) {
      auto i = places_system_images::folder_applications({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-applications", size {64, 64}), i, csf_);
    }

    void test_method_(folder_bookmark) {
      auto i = places_system_images::folder_bookmark();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-bookmark"), i, csf_);
    }

    void test_method_(folder_bookmark_with_specified_size) {
      auto i = places_system_images::folder_bookmark({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-bookmark", size {64, 64}), i, csf_);
    }

    void test_method_(folder_cloud) {
      auto i = places_system_images::folder_cloud();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-cloud"), i, csf_);
    }

    void test_method_(folder_cloud_with_specified_size) {
      auto i = places_system_images::folder_cloud({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-cloud", size {64, 64}), i, csf_);
    }

    void test_method_(folder_desktop) {
      auto i = places_system_images::folder_desktop();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-desktop"), i, csf_);
    }

    void test_method_(folder_desktop_with_specified_size) {
      auto i = places_system_images::folder_desktop({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-desktop", size {64, 64}), i, csf_);
    }

    void test_method_(folder_development) {
      auto i = places_system_images::folder_development();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-development"), i, csf_);
    }

    void test_method_(folder_development_with_specified_size) {
      auto i = places_system_images::folder_development({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-development", size {64, 64}), i, csf_);
    }

    void test_method_(folder_documents) {
      auto i = places_system_images::folder_documents();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-documents"), i, csf_);
    }

    void test_method_(folder_documents_with_specified_size) {
      auto i = places_system_images::folder_documents({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-documents", size {64, 64}), i, csf_);
    }

    void test_method_(folder_download) {
      auto i = places_system_images::folder_download();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-download"), i, csf_);
    }

    void test_method_(folder_download_with_specified_size) {
      auto i = places_system_images::folder_download({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-download", size {64, 64}), i, csf_);
    }

    void test_method_(folder_favorites) {
      auto i = places_system_images::folder_favorites();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-favorites"), i, csf_);
    }

    void test_method_(folder_favorites_with_specified_size) {
      auto i = places_system_images::folder_favorites({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-favorites", size {64, 64}), i, csf_);
    }

    void test_method_(folder_games) {
      auto i = places_system_images::folder_games();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-games"), i, csf_);
    }

    void test_method_(folder_games_with_specified_size) {
      auto i = places_system_images::folder_games({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-games", size {64, 64}), i, csf_);
    }

    void test_method_(folder_github) {
      auto i = places_system_images::folder_github();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-github"), i, csf_);
    }

    void test_method_(folder_github_with_specified_size) {
      auto i = places_system_images::folder_github({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-github", size {64, 64}), i, csf_);
    }

    void test_method_(folder_home) {
      auto i = places_system_images::folder_home();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-home"), i, csf_);
    }

    void test_method_(folder_home_with_specified_size) {
      auto i = places_system_images::folder_home({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-home", size {64, 64}), i, csf_);
    }

    void test_method_(folder_html) {
      auto i = places_system_images::folder_html();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-html"), i, csf_);
    }

    void test_method_(folder_html_with_specified_size) {
      auto i = places_system_images::folder_html({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-html", size {64, 64}), i, csf_);
    }

    void test_method_(folder_images) {
      auto i = places_system_images::folder_images();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-images"), i, csf_);
    }

    void test_method_(folder_images_with_specified_size) {
      auto i = places_system_images::folder_images({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-images", size {64, 64}), i, csf_);
    }

    void test_method_(folder_important) {
      auto i = places_system_images::folder_important();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-important"), i, csf_);
    }

    void test_method_(folder_important_with_specified_size) {
      auto i = places_system_images::folder_important({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-important", size {64, 64}), i, csf_);
    }

    void test_method_(folder_locked) {
      auto i = places_system_images::folder_locked();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-locked"), i, csf_);
    }

    void test_method_(folder_locked_with_specified_size) {
      auto i = places_system_images::folder_locked({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-locked", size {64, 64}), i, csf_);
    }

    void test_method_(folder_music) {
      auto i = places_system_images::folder_music();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-music"), i, csf_);
    }

    void test_method_(folder_music_with_specified_size) {
      auto i = places_system_images::folder_music({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-music", size {64, 64}), i, csf_);
    }

    void test_method_(folder_network) {
      auto i = places_system_images::folder_network();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-network"), i, csf_);
    }

    void test_method_(folder_network_with_specified_size) {
      auto i = places_system_images::folder_network({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-network", size {64, 64}), i, csf_);
    }

    void test_method_(folder_print) {
      auto i = places_system_images::folder_print();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-print"), i, csf_);
    }

    void test_method_(folder_print_with_specified_size) {
      auto i = places_system_images::folder_print({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-print", size {64, 64}), i, csf_);
    }

    void test_method_(folder_public) {
      auto i = places_system_images::folder_public();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-public"), i, csf_);
    }

    void test_method_(folder_public_with_specified_size) {
      auto i = places_system_images::folder_public({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-public", size {64, 64}), i, csf_);
    }

    void test_method_(folder_remote) {
      auto i = places_system_images::folder_remote();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-remote"), i, csf_);
    }

    void test_method_(folder_remote_with_specified_size) {
      auto i = places_system_images::folder_remote({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-remote", size {64, 64}), i, csf_);
    }

    void test_method_(folder_system) {
      auto i = places_system_images::folder_system();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-system"), i, csf_);
    }

    void test_method_(folder_system_with_specified_size) {
      auto i = places_system_images::folder_system({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-system", size {64, 64}), i, csf_);
    }

    void test_method_(folder_tar) {
      auto i = places_system_images::folder_tar();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-tar"), i, csf_);
    }

    void test_method_(folder_tar_with_specified_size) {
      auto i = places_system_images::folder_tar({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-tar", size {64, 64}), i, csf_);
    }

    void test_method_(folder_temp) {
      auto i = places_system_images::folder_temp();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-temp"), i, csf_);
    }

    void test_method_(folder_temp_with_specified_size) {
      auto i = places_system_images::folder_temp({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-temp", size {64, 64}), i, csf_);
    }

    void test_method_(folder_templates) {
      auto i = places_system_images::folder_templates();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-templates"), i, csf_);
    }

    void test_method_(folder_templates_with_specified_size) {
      auto i = places_system_images::folder_templates({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-templates", size {64, 64}), i, csf_);
    }

    void test_method_(folder_text) {
      auto i = places_system_images::folder_text();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-text"), i, csf_);
    }

    void test_method_(folder_text_with_specified_size) {
      auto i = places_system_images::folder_text({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-text", size {64, 64}), i, csf_);
    }

    void test_method_(folder_videos) {
      auto i = places_system_images::folder_videos();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-videos"), i, csf_);
    }

    void test_method_(folder_videos_with_specified_size) {
      auto i = places_system_images::folder_videos({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-videos", size {64, 64}), i, csf_);
    }

    void test_method_(network_server) {
      auto i = places_system_images::network_server();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-server"), i, csf_);
    }

    void test_method_(network_server_with_specified_size) {
      auto i = places_system_images::network_server({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-server", size {64, 64}), i, csf_);
    }

    void test_method_(network_workgroup) {
      auto i = places_system_images::network_workgroup();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-workgroup"), i, csf_);
    }

    void test_method_(network_workgroup_with_specified_size) {
      auto i = places_system_images::network_workgroup({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("network-workgroup", size {64, 64}), i, csf_);
    }

    void test_method_(start_here) {
      auto i = places_system_images::start_here();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("start-here"), i, csf_);
    }

    void test_method_(start_here_with_specified_size) {
      auto i = places_system_images::start_here({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("start-here", size {64, 64}), i, csf_);
    }

    void test_method_(user_bookmarks) {
      auto i = places_system_images::user_bookmarks();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-bookmarks"), i, csf_);
    }

    void test_method_(user_bookmarks_with_specified_size) {
      auto i = places_system_images::user_bookmarks({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-bookmarks", size {64, 64}), i, csf_);
    }

    void test_method_(user_desktop) {
      auto i = places_system_images::user_desktop();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-desktop"), i, csf_);
    }

    void test_method_(user_desktop_with_specified_size) {
      auto i = places_system_images::user_desktop({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-desktop", size {64, 64}), i, csf_);
    }

    void test_method_(user_home) {
      auto i = places_system_images::user_home();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-home"), i, csf_);
    }

    void test_method_(user_home_with_specified_size) {
      auto i = places_system_images::user_home({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-home", size {64, 64}), i, csf_);
    }

    void test_method_(user_trash) {
      auto i = places_system_images::user_trash();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-trash"), i, csf_);
    }

    void test_method_(user_trash_with_specified_size) {
      auto i = places_system_images::user_trash({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("user-trash", size {64, 64}), i, csf_);
    }
  };
}
