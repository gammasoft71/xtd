#include "../../../include/xtd/drawing/bitmap.hpp"
#include "../../../include/xtd/drawing/system_colors.hpp"
#include "../../../include/xtd/drawing/system_images_base.hpp"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/system_images>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/io/directory>
#include <xtd/io/file>
#include <xtd/io/path>
#include <xtd/environment>
#include <map>

// doc : https://specifications.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html
//
// macos resources folders:
// * /System/Library/CoreServices/CoreTypes.bundle/Contents/Resources/
// * /System/Library/
// *
// * Light mode:
// *   Normal symbol : color = RGB(92, 97, 108), Opacity = 100 %
// *   shadow : color = RGB(92, 97, 108), Opacity = 30 %
// *
// * Dark mode:
// *   Normal symbol : color = RGB(241, 247, 248), Opacity = 85 %
// *   shadow : color = RGB(241, 247, 248), Opacity = 15 %
//
// * Folder with item :
// *   light folder item gradient : fg(69, 181, 232), bg(101, 197, 240)
// *   dark folder item gradient : fg(78, 139, 182), bg(94, 153, 185)

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::io;

namespace {
  static string system_images_base_resource_path() {
    return path::combine({environment::get_folder_path(environment::special_folder::xtd_resources), "system_images"});
  }
  
  drawing::size get_closed_size(const drawing::size& size) {
    static auto default_sizes = std::vector<drawing::size> {{16, 16}, {24, 24}, {32, 32}, {48, 48}, {64, 64}, {96, 96}, {128, 128}, {256, 256}, {512, 512}, {1024, 1024}};
    for (auto default_size : default_sizes)
      if (default_size.width >= size.width && default_size.height >= size.height) return default_size;
    return {1024, 1024};
  }
}

xtd::drawing::size system_images_base::default_size() noexcept {
  return {32, 32};
}

std::vector<string> system_images_base::contexts() noexcept {
  auto result = std::vector<string> {};
  for (const auto& context_name : context_names())
    result.push_back(context_name.first);
  return result;
}

std::map<string, std::vector<string>> system_images_base::context_names() noexcept {
  static std::map<string, std::vector<string>> context_names {
    {"Actions", {"address-book-new", "application-exit", "appointment-new", "call-start", "call-stop", "contact-new", "dialog-cancel", "dialog-ok", "dialog-ok-apply", "document-edit", "document-new", "document-open", "document-open-recent", "document-page-setup", "document-print", "document-print-preview", "document-properties", "document-revert", "document-save", "document-save-as", "document-send", "edit-clear", "edit-copy", "edit-cut", "edit-delete", "edit-find", "edit-find-replace", "edit-paste", "edit-redo", "edit-rename", "edit-select-all", "edit-undo", "folder-new", "format-indent-less", "format-indent-more", "format-justify-center", "format-justify-fill", "format-justify-left", "format-justify-right", "format-text-direction-ltr", "format-text-direction-rtl", "format-text-bold", "format-text-italic", "format-text-underline", "format-text-strikethrough", "go-bottom", "go-down", "go-first", "go-home", "go-jump", "go-last", "go-next", "go-previous", "go-top", "go-up", "help-about", "help-contents", "help-faq", "insert-image", "insert-link", "insert-object", "insert-table", "insert-text", "list-add", "list-remove", "mail-forward", "mail-mark-important", "mail-mark-junk", "mail-mark-notjunk", "mail-mark-read", "mail-mark-unread", "mail-message-new", "mail-reply-all", "mail-reply-sender", "mail-send", "mail-send-receive", "media-eject", "media-optical-burn", "media-playback-pause", "media-playback-start", "media-playback-stop", "media-record", "media-seek-backward", "media-seek-forward", "media-skip-backward", "media-skip-forward", "object-flip-horizontal", "object-flip-vertical", "object-rotate-left", "object-rotate-right", "process-stop", "system-lock-screen", "system-log-out", "system-run", "system-search", "system-reboot", "system-shutdown", "tools-check-spelling", "view-fullscreen", "view-media-equalizer", "view-media-lyrics", "view-refresh", "view-restore", "view-sort-ascending", "view-sort-descending", "window-close", "window-close-hovered", "window-fullscreen", "window-fullscreen-hovered", "window-maximize", "window-maximize-hovered", "window-minimize", "window-minimize-hovered", "window-new", "window-restore", "window-restore-hovered", "zoom-fit-best", "zoom-in", "zoom-original", "zoom-out"}},
    {"Animations", {"process-working"}},
    {"Applications", {"accessories-calculator", "accessories-character-map", "accessories-dictionary", "accessories-text-editor", "help-browser", "help", "multimedia-volume-control", "preferences-desktop-accessibility", "preferences-desktop-font", "preferences-desktop-keyboard", "preferences-desktop-locale", "preferences-desktop-screensaver", "preferences-desktop-theme", "preferences-desktop-wallpaper", "system-file-manager", "system-software-install", "system-software-update", "utilities-system-monitor", "utilities-terminal"}},
    {"Categories", {"applications-accessories", "applications-development", "applications-engineering", "applications-games", "applications-graphics", "applications-internet", "applications-multimedia", "applications-office", "applications-other", "applications-science", "applications-system", "applications-utilities", "preferences-desktop", "preferences-desktop-peripherals", "preferences-desktop-personal", "preferences-other", "preferences-system", "preferences-system-network", "system-help"}},
    {"Devices", {"audio-card", "audio-input-microphone", "battery", "camera-photo", "camera-video", "camera-web", "computer", "drive-harddisk", "drive-optical", "drive-removable-media-usb-pendrive", "drive-removable-media", "input-gaming", "input-keyboard", "input-mouse", "input-tablet", "media-flash", "media-floppy", "media-optical-audio", "media-optical-blu-ray", "media-optical-data", "media-optical-dvd-video", "media-optical-dvd", "media-optical-mixed-cd", "media-optical-recordable", "media-optical-video", "media-optical", "media-tape", "modem", "multimedia-player", "network-wired", "network-wireless", "pda", "phone", "printer", "scanner", "video-display"}},
    {"Emblems", {"emblem-default", "emblem-documents", "emblem-downloads", "emblem-favorite", "emblem-important", "emblem-locked", "emblem-mail", "emblem-new", "emblem-photos", "emblem-readonly", "emblem-shared", "emblem-symbolic-link", "emblem-synchronizing", "emblem-system", "emblem-unlocked", "emblem-unreadable"}},
    {"Emotes", {"face-angel", "face-angry", "face-cool", "face-crying", "face-devilish", "face-embarrassed", "face-kiss", "face-laugh", "face-monkey", "face-plain", "face-raspberry", "face-sad", "face-sick", "face-smile", "face-smile-big", "face-smirk", "face-surprise", "face-tired", "face-uncertain", "face-wink", "face-worried"}},
    {"International", {"flag-af", "flag-ax", "flag-al", "flag-dz", "flag-as", "flag-ad", "flag-ao", "flag-ai", "flag-aq", "flag-ag", "flag-ar", "flag-am", "flag-aw", "flag-au", "flag-at", "flag-az", "flag-bs", "flag-bh", "flag-bd", "flag-bb", "flag-by", "flag-be", "flag-bz", "flag-bj", "flag-bm", "flag-bt", "flag-bo", "flag-bq", "flag-ba", "flag-bw", "flag-bv", "flag-br", "flag-io", "flag-bn", "flag-bg", "flag-bf", "flag-bi", "flag-cv", "flag-kh", "flag-cm", "flag-ca", "flag-ky", "flag-cf", "flag-td", "flag-cl", "flag-cn", "flag-cx", "flag-cc", "flag-co", "flag-km", "flag-cg", "flag-cd", "flag-ck", "flag-cr", "flag-ci", "flag-hr", "flag-cu", "flag-cw", "flag-cy", "flag-cz", "flag-dk", "flag-dj", "flag-dm", "flag-do", "flag-ec", "flag-eg", "flag-sv", "flag-gq", "flag-er", "flag-ee", "flag-sz", "flag-et", "flag-fk", "flag-fo", "flag-fj", "flag-fi", "flag-fr", "flag-gf", "flag-pf", "flag-tf", "flag-ga", "flag-gm", "flag-ge", "flag-de", "flag-gh", "flag-gi", "flag-gr", "flag-gl", "flag-gd", "flag-gp", "flag-gu", "flag-gt", "flag-gg", "flag-gn", "flag-gw", "flag-gy", "flag-ht", "flag-hm", "flag-va", "flag-hn", "flag-hk", "flag-hu", "flag-is", "flag-in", "flag-id", "flag-ir", "flag-iq", "flag-ie", "flag-im", "flag-il", "flag-it", "flag-jm", "flag-jp", "flag-je", "flag-jo", "flag-kz", "flag-ke", "flag-ki", "flag-kp", "flag-kr", "flag-kw", "flag-kg", "flag-la", "flag-lv", "flag-lb", "flag-ls", "flag-lr", "flag-ly", "flag-li", "flag-lt", "flag-lu", "flag-mo", "flag-mg", "flag-mw", "flag-my", "flag-mv", "flag-ml", "flag-mt", "flag-mh", "flag-mq", "flag-mr", "flag-mu", "flag-yt", "flag-mx", "flag-fm", "flag-md", "flag-mc", "flag-mn", "flag-me", "flag-ms", "flag-ma", "flag-mz", "flag-mm", "flag-na", "flag-nr", "flag-np", "flag-nl", "flag-nc", "flag-nz", "flag-ni", "flag-ne", "flag-ng", "flag-nu", "flag-nf", "flag-mk", "flag-mp", "flag-no", "flag-om", "flag-pk", "flag-pw", "flag-ps", "flag-pa", "flag-pg", "flag-py", "flag-pe", "flag-ph", "flag-pn", "flag-pl", "flag-pt", "flag-pr", "flag-qa", "flag-re", "flag-ro", "flag-ru", "flag-rw", "flag-bl", "flag-sh", "flag-kn", "flag-lc", "flag-mf", "flag-pm", "flag-vc", "flag-ws", "flag-sm", "flag-st", "flag-sa", "flag-sn", "flag-rs", "flag-sc", "flag-sl", "flag-sg", "flag-sx", "flag-sk", "flag-si", "flag-sb", "flag-so", "flag-za", "flag-gs", "flag-ss", "flag-es", "flag-lk", "flag-sd", "flag-sr", "flag-sj", "flag-se", "flag-ch", "flag-sy", "flag-tw", "flag-tj", "flag-tz", "flag-th", "flag-tl", "flag-tg", "flag-tk", "flag-to", "flag-tt", "flag-tn", "flag-tr", "flag-tm", "flag-tc", "flag-tv", "flag-ug", "flag-ua", "flag-ae", "flag-gb", "flag-us", "flag-um", "flag-uy", "flag-uz", "flag-vu", "flag-ve", "flag-vn", "flag-vg", "flag-vi", "flag-wf", "flag-eh", "flag-ye", "flag-zm", "flag-zw"}},
    {"MimeTypes", {"application-x-executable", "audio-x-generic", "font-x-generic", "image-x-generic", "package-x-generic", "text-html", "text-x-generic", "text-x-generic-template", "text-x-script", "video-x-generic", "x-office-address-book", "x-office-calendar", "x-office-contact", "x-office-document", "x-office-presentation", "x-office-spreadsheet"}},
    {"Places", {"folder", "folder-activities", "folder-applications", "folder-bookmark", "folder-cloud", "folder-desktop", "folder-development", "folder-documents", "folder-download", "folder-favorites", "folder-games", "folder-github", "folder-home", "folder-html", "folder-images", "folder-important", "folder-locked", "folder-music", "folder-network", "folder-print", "folder-public", "folder-remote", "folder-system", "folder-tar", "folder-temp", "folder-templates", "folder-text", "folder-videos", "network-server", "network-workgroup", "start-here", "user-bookmarks", "user-desktop", "user-home", "user-trash"}},
    {"Status", {"appointment-missed", "appointment-soon", "audio-volume-high", "audio-volume-low", "audio-volume-medium", "audio-volume-muted", "battery-caution", "battery-low", "dialog-error", "dialog-information", "dialog-password", "dialog-question", "dialog-warning", "folder-drag-accept", "folder-open", "folder-visiting", "image-loading", "image-missing", "mail-attachment", "mail-unread", "mail-read", "mail-replied", "mail-signed", "mail-signed-verified", "media-playlist-repeat", "media-playlist-shuffle", "network-error", "network-idle", "network-offline", "network-receive", "network-transmit", "network-transmit-receive", "printer-error", "printer-printing", "security-high", "security-medium", "security-low", "software-update-available", "software-update-urgent", "task-due", "task-past-due", "user-available", "user-away", "user-idle", "user-offline", "user-trash-full", "weather-clear", "weather-clear-night", "weather-few-clouds", "weather-few-clouds-night", "weather-fog", "weather-overcast", "weather-severe-alert", "weather-showers", "weather-showers-scattered", "weather-snow", "weather-storm"}},
    {"xtd", {"gammasoft", "xtd", "xtd-console", "xtd-forms", "xtd-tunit", "xtd-core", "xtd-delegates", "xtd-diagnostics", "xtd-drawing", "xtd-io", "xtd-strings", "xtd-cmake"}},
  };
  return context_names;
}

std::vector<string> system_images_base::names() noexcept {
  auto result = std::vector<string> {};
  for (const auto& context_name : context_names())
    for (const auto& name : context_name.second)
      result.push_back(name);
  return result;
}

std::vector<xtd::string> system_images_base::names(const xtd::string& context) noexcept {
  return context_names()[context];
}

std::vector<xtd::drawing::size> system_images_base::sizes() noexcept {
  return {{16, 16}, {24, 24}, {32, 32}, {48, 48}, {64, 64}, {96, 96}, {128, 128}, {256, 256}, {512, 512}, {1024, 1024}};
}

image system_images_base::from_name(const xtd::string& name) {
  return from_name(default_theme(), name, default_size());
}

image system_images_base::from_name(const xtd::string& name, const xtd::drawing::size& size) {
  return from_name(default_theme(), name, size);
}

image system_images_base::from_name(const xtd::string& theme, const xtd::string& name) {
  return from_name(theme, name, default_size());
}

image system_images_base::from_name(const string& theme, const string& name, const size& size) {
  static auto default_sizes = std::vector<drawing::size> {{1024, 1024}, {512, 512}, {256, 256}, {128, 128}, {96, 96}, {64, 64}, {48, 48}, {32, 32}, {24, 24}, {16, 16}};
  static auto default_size_names = std::vector<string> {"1024x1024", "512x512", "256x256", "128x128", "96x96", "64x64", "48x48", "32x32", "24x24", "16x16"};
  auto dark_mode = (system_colors::window().get_lightness() < 0.5 && !theme.ends_with(" (light)")) || theme.ends_with(" (dark)");
  auto theme_name = theme.replace(" (dark)", string::empty_string).replace(" (light)", string::empty_string);
  
  auto theme_path = directory::exists(path::combine(system_images_base_resource_path(), theme_name)) ? path::combine(system_images_base_resource_path(), theme_name) : path::combine(system_images_base_resource_path(), default_theme());
  auto it_sizes = find(default_sizes.begin(), default_sizes.end(), get_closed_size(size));
  
  if (theme == default_theme()) {
    auto hbitmap = native_system_images_from_name_enabled() ? native::system_images::from_name(name, size.width, size.height) : intptr {0};
    if (hbitmap) return image::from_hbitmap(hbitmap);
  }
  
  if (dark_mode) {
    if (file::exists(path::combine(theme_path, default_size_names[it_sizes - default_sizes.begin()], name + "-dark.png"))) return bitmap(path::combine(theme_path, default_size_names[it_sizes - default_sizes.begin()], name + "-dark.png"));
    for (auto it = default_sizes.begin(); it != default_sizes.end(); ++it)
      if (file::exists(path::combine(theme_path, default_size_names[it - default_sizes.begin()], name + "-dark.png"))) return bitmap(bitmap(path::combine(theme_path, default_size_names[it - default_sizes.begin()], name + "-dark.png")), *it_sizes);
  }
  
  if (file::exists(path::combine(theme_path, default_size_names[it_sizes - default_sizes.begin()], name + ".png"))) return bitmap(path::combine(theme_path, default_size_names[it_sizes - default_sizes.begin()], name + ".png"));
  for (auto it = default_sizes.begin(); it != default_sizes.end(); ++it)
    if (file::exists(path::combine(theme_path, default_size_names[it - default_sizes.begin()], name + ".png"))) return bitmap(bitmap(path::combine(theme_path, default_size_names[it - default_sizes.begin()], name + ".png")), *it_sizes);
    
  if (dark_mode) {
    if (file::exists(path::combine(system_images_base_resource_path(), fallback_theme(), default_size_names[it_sizes - default_sizes.begin()], name + "-dark.png"))) return bitmap(path::combine(system_images_base_resource_path(), fallback_theme(), default_size_names[it_sizes - default_sizes.begin()], name + "-dark.png"));
    for (auto it = default_sizes.begin(); it != default_sizes.end(); ++it)
      if (file::exists(path::combine(system_images_base_resource_path(), fallback_theme(), default_size_names[it - default_sizes.begin()], name + "-dark.png"))) return bitmap(bitmap(path::combine(system_images_base_resource_path(), fallback_theme(), default_size_names[it - default_sizes.begin()], name + "-dark.png")), *it_sizes);
  }
  
  if (file::exists(path::combine(system_images_base_resource_path(), fallback_theme(), default_size_names[it_sizes - default_sizes.begin()], name + ".png"))) return bitmap(path::combine(system_images_base_resource_path(), fallback_theme(), default_size_names[it_sizes - default_sizes.begin()], name + ".png"));
  for (auto it = default_sizes.begin(); it != default_sizes.end(); ++it)
    if (file::exists(path::combine(system_images_base_resource_path(), fallback_theme(), default_size_names[it - default_sizes.begin()], name + ".png"))) return bitmap(bitmap(path::combine(system_images_base_resource_path(), fallback_theme(), default_size_names[it - default_sizes.begin()], name + ".png")), *it_sizes);
    
  return image::empty;
}

string system_images_base::default_theme() noexcept {
  static auto default_theme = xtd::environment::os_version().desktop_environment() == "" ? "symbolic" :  xtd::environment::os_version().desktop_environment();
  return default_theme;
}

string system_images_base::fallback_theme() noexcept {
  return "symbolic";
}

std::vector<string> system_images_base::themes() noexcept {
  return {"gnome", "gnome (dark)", "gnome (light)", "kde", "kde (dark)", "kde (light)", "macos", "macos (dark)", "macos (light)", "symbolic", "symbolic (dark)", "symbolic (light)", "windows", "windows (dark)", "windows (light)", "xtd", "xtd (dark)", "xtd (light)"};
}
