#include "../../../include/xtd/drawing/bitmap.h"
#include "../../../include/xtd/drawing/system_images.h"
#include <filesystem>
#include <map>
#include <xtd/environment.h>
//#include <xtd/drawing/native/system_images.h>

// macos resources folders:
// * /System/Library/CoreServices/CoreTypes.bundle/Contents/Resources/
// * /System/Library/

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::drawing;

namespace {
  static path system_images_resource_path() {
  #if defined(__XTD_DRAWING_RESOURCES_PATH__)
    return path(__XTD_DRAWING_RESOURCES_PATH__)/"share"/"xtd"/"resources"/"system_images";
  #else
    return {};
  #endif
  }
}

image system_images::from_name(const string& theme, const string& name, const size& size) {
  static vector<drawing::size> default_sizes = {{16, 16}, {24, 24}, {32, 32}, {48, 48}, {64, 64}, {96, 96}, {128, 128}, {256, 256}, {512, 512}, {1024, 1024}};
  static vector<string> default_size_names = {"16x16", "24x24", "32x32", "48x48", "64x64", "96x96", "128x128", "256x256", "512x512", "1024x1024"};

  auto theme_path = exists(system_images_resource_path()/theme) ? system_images_resource_path()/theme : system_images_resource_path()/default_theme();
  /// @todo find closed user size
  auto it_sizes = find(default_sizes.begin(), default_sizes.end(), size);
  auto index_sizes = it_sizes != default_sizes.end() ? it_sizes - default_sizes.begin() : 2;
  
  if (exists(theme_path/default_size_names[index_sizes]/(name + ".png"))) return bitmap((theme_path/default_size_names[index_sizes]/(name + ".png")).string());
  if (exists(system_images_resource_path()/"xtd"/default_size_names[index_sizes]/(name + ".png"))) return bitmap((system_images_resource_path()/"xtd"/default_size_names[index_sizes]/(name + ".png")).string());
  if (exists(theme_path/default_size_names[index_sizes]/"image-missing.png")) return bitmap((theme_path/default_size_names[index_sizes]/"image-missing.png").string());
  if (exists(system_images_resource_path()/"xtd"/default_size_names[index_sizes]/"image-missing.png")) return bitmap((system_images_resource_path()/"xtd"/default_size_names[index_sizes]/"image-missing.png").string());
  return image::empty;
}

vector<string> system_images::contexts() {
  vector<string> result;
  for (const auto& context_name : context_names())
    result.push_back(context_name.first);
  return result;
}

map<string, vector<string>> system_images::context_names() {
  static map<string, vector<string>> context_names {
    {"Actions", {"address-book-new", "application-exit", "appointment-new", "burn-disk", "call-start", "call-stop", "contact-new", "dialog-cancel", "dialog-ok", "dialog-ok-apply", "document-new", "document-open", "document-open-recent", "document-page-setup", "document-print", "document-print-preview", "document-properties", "document-revert", "document-save", "document-save-as", "document-send", "drive-download", "drive-upload", "edit", "edit-clear", "edit-copy", "edit-cut", "edit-delete", "edit-find", "edit-find-replace", "edit-paste", "edit-redo", "edit-rename", "edit-select-all", "edit-undo", "folder-new", "format-indent-less", "format-indent-more", "format-justify-center", "format-justify-fill", "format-justify-left", "format-justify-right", "format-text-direction-ltr", "format-text-direction-rtl", "format-text-bold", "format-text-italic", "format-text-underline", "format-text-strikethrough", "go-bottom", "go-down", "go-first", "go-home", "go-jump", "go-last", "go-next", "go-previous", "go-top", "go-up", "help-about", "help-contents", "help-faq", "insert-image", "insert-link", "insert-object", "insert-table", "insert-text", "list-add", "list-remove", "mail-forward", "mail-mark-important", "mail-mark-junk", "mail-mark-notjunk", "mail-mark-read", "mail-mark-unread", "mail-message-new", "mail-reply-all", "mail-reply-sender", "mail-send", "mail-send-receive", "media-eject", "media-playback-pause", "media-playback-start", "media-playback-stop", "media-record", "media-seek-backward", "media-seek-forward", "media-skip-backward", "media-skip-forward", "object-flip-horizontal", "object-flip-vertical", "object-rotate-left", "object-rotate-right", "process-stop", "system-lock-screen", "system-log-out", "system-run", "system-search", "system-reboot", "system-shutdown", "tools-check-spelling", "view-fullscreen", "view-media-equalizer", "view-media-lyrics", "view-refresh", "view-restore", "view-sort-ascending", "view-sort-descending", "window-close", "window-new", "zoom-fit-best", "zoom-in", "zoom-original", "zoom-out"}},
    {"Animations", {"process-working"}},
    {"Applications", {"accessories-calculator", "accessories-character-map", "accessories-dictionary", "accessories-text-editor", "help-browser", "multimedia-volume-control", "preferences-desktop-accessibility", "preferences-desktop-font", "preferences-desktop-keyboard", "preferences-desktop-locale", "preferences-desktop-screensaver", "preferences-desktop-theme", "preferences-desktop-wallpaper", "system-file-manager", "system-software-install", "system-software-update", "utilities-system-monitor", "utilities-terminal"}},
    {"Categories", {"applications-accessories", "applications-development", "applications-engineering", "applications-games", "applications-graphics", "applications-internet", "applications-multimedia", "applications-office", "applications-other", "applications-science", "applications-system", "applications-utilities", "preferences-desktop", "preferences-desktop-peripherals", "preferences-desktop-personal", "preferences-other", "preferences-system", "preferences-system-network", "system-help"}},
    {"Devices", {"audio-card", "audio-input-microphone", "battery", "camera-photo", "camera-video", "camera-web", "computer", "drive-harddisk", "drive-optical", "drive-removable-flash", "drive-removable-media", "input-gaming", "input-keyboard", "input-mouse", "input-tablet", "media-flash", "media-floppy", "media-optical", "media-optical-audio", "media-optical-dvd", "media-tape", "modem", "multimedia-player", "network-wired", "network-wireless", "pda", "phone", "printer", "scanner", "video-display"}},
    {"Emblems", {"emblem-default", "emblem-documents", "emblem-downloads", "emblem-favorite", "emblem-important", "emblem-mail", "emblem-photos", "emblem-readonly", "emblem-shared", "emblem-symbolic-link", "emblem-synchronized", "emblem-system", "emblem-user", "emblem-unreadable"}},
    {"Emotes", {"face-angel", "face-angry", "face-cool", "face-crying", "face-devilish", "face-embarrassed", "face-kiss", "face-laugh", "face-monkey", "face-plain", "face-raspberry", "face-sad", "face-sick", "face-smile", "face-smile-big", "face-smirk", "face-surprise", "face-tired", "face-uncertain", "face-wink", "face-worried"}},
    {"International", {"flag-af", "flag-ax", "flag-al", "flag-dz", "flag-as", "flag-ad", "flag-ao", "flag-ai", "flag-aq", "flag-ag", "flag-ar", "flag-am", "flag-aw", "flag-au", "flag-at", "flag-az", "flag-bs", "flag-bh", "flag-bd", "flag-bb", "flag-by", "flag-be", "flag-bz", "flag-bj", "flag-bm", "flag-bt", "flag-bo", "flag-bq", "flag-ba", "flag-bw", "flag-bv", "flag-br", "flag-io", "flag-bn", "flag-bg", "flag-bf", "flag-bi", "flag-cv", "flag-kh", "flag-cm", "flag-ca", "flag-ky", "flag-cf", "flag-td", "flag-cl", "flag-cn", "flag-cx", "flag-cc", "flag-co", "flag-km", "flag-cg", "flag-cd", "flag-ck", "flag-cr", "flag-ci", "flag-hr", "flag-cu", "flag-cw", "flag-cy", "flag-cz", "flag-dk", "flag-dj", "flag-dm", "flag-do", "flag-ec", "flag-eg", "flag-sv", "flag-gq", "flag-er", "flag-ee", "flag-sz", "flag-et", "flag-fk", "flag-fo", "flag-fj", "flag-fi", "flag-fr", "flag-gf", "flag-pf", "flag-tf", "flag-ga", "flag-gm", "flag-ge", "flag-de", "flag-gh", "flag-gi", "flag-gr", "flag-gl", "flag-gd", "flag-gp", "flag-gu", "flag-gt", "flag-gg", "flag-gn", "flag-gw", "flag-gy", "flag-ht", "flag-hm", "flag-va", "flag-hn", "flag-hk", "flag-hu", "flag-is", "flag-in", "flag-id", "flag-ir", "flag-iq", "flag-ie", "flag-im", "flag-il", "flag-it", "flag-jm", "flag-jp", "flag-je", "flag-jo", "flag-kz", "flag-ke", "flag-ki", "flag-kp", "flag-kr", "flag-kw", "flag-kg", "flag-la", "flag-lv", "flag-lb", "flag-ls", "flag-lr", "flag-ly", "flag-li", "flag-lt", "flag-lu", "flag-mo", "flag-mg", "flag-mw", "flag-my", "flag-mv", "flag-ml", "flag-mt", "flag-mh", "flag-mq", "flag-mr", "flag-mu", "flag-yt", "flag-mx", "flag-fm", "flag-md", "flag-mc", "flag-mn", "flag-me", "flag-ms", "flag-ma", "flag-mz", "flag-mm", "flag-na", "flag-nr", "flag-np", "flag-nl", "flag-nc", "flag-nz", "flag-ni", "flag-ne", "flag-ng", "flag-nu", "flag-nf", "flag-mk", "flag-mp", "flag-no", "flag-om", "flag-pk", "flag-pw", "flag-ps", "flag-pa", "flag-pg", "flag-py", "flag-pe", "flag-ph", "flag-pn", "flag-pl", "flag-pt", "flag-pr", "flag-qa", "flag-re", "flag-ro", "flag-ru", "flag-rw", "flag-bl", "flag-sh", "flag-kn", "flag-lc", "flag-mf", "flag-pm", "flag-vc", "flag-ws", "flag-sm", "flag-st", "flag-sa", "flag-sn", "flag-rs", "flag-sc", "flag-sl", "flag-sg", "flag-sx", "flag-sk", "flag-si", "flag-sb", "flag-so", "flag-za", "flag-gs", "flag-ss", "flag-es", "flag-lk", "flag-sd", "flag-sr", "flag-sj", "flag-se", "flag-ch", "flag-sy", "flag-tw", "flag-tj", "flag-tz", "flag-th", "flag-tl", "flag-tg", "flag-tk", "flag-to", "flag-tt", "flag-tn", "flag-tr", "flag-tm", "flag-tc", "flag-tv", "flag-ug", "flag-ua", "flag-ae", "flag-gb", "flag-us", "flag-um", "flag-uy", "flag-uz", "flag-vu", "flag-ve", "flag-vn", "flag-vg", "flag-vi", "flag-wf", "flag-eh", "flag-ye", "flag-zm", "flag-zw"}},
    {"MimeTypes", {"application-x-executable", "audio-x-generic", "font-x-generic", "image-x-generic", "package-x-generic", "text-html", "text-x-generic", "text-x-generic-template", "text-x-script", "video-x-generic", "x-office-address-book", "x-office-calendar", "x-office-document", "x-office-presentation", "x-office-spreadsheet"}},
    {"Places", {"folder", "folder-remote", "network-server", "network-workgroup", "start-here", "user-bookmarks", "user-desktop", "user-home", "user-trash"}},
    {"Status", {"appointment-missed", "appointment-soon", "audio-volume-high", "audio-volume-low", "audio-volume-medium", "audio-volume-muted", "battery-caution", "battery-low", "dialog-error", "dialog-information", "dialog-password", "dialog-question", "dialog-warning", "folder-drag-accept", "folder-open", "folder-visiting", "image-loading", "image-missing", "mail-attachment", "mail-unread", "mail-read", "mail-replied", "mail-signed", "mail-signed-verified", "media-playlist-repeat", "media-playlist-shuffle", "network-error", "network-idle", "network-offline", "network-receive", "network-transmit", "network-transmit-receive", "printer-error", "printer-printing", "security-high", "security-medium", "security-low", "software-update-available", "software-update-urgent", "sync-error", "sync-synchronizing", "task-due", "task-past-due", "user-available", "user-away", "user-idle", "user-offline", "user-trash-full", "weather-clear", "weather-clear-night", "weather-few-clouds", "weather-few-clouds-night", "weather-fog", "weather-overcast", "weather-severe-alert", "weather-showers", "weather-showers-scattered", "weather-snow", "weather-storm"}},
    {"xtd", {"gammasoft", "xtd", "xtd-console", "xtd-forms"}},
  };
  return context_names;
}

string system_images::default_theme() {
  if (environment::os_version().is_windows_platform()) return "windows";
  if (environment::os_version().is_osx_platform()) return "macos";
  if (environment::os_version().is_linux_platform()) return "gnome";
  return "xtd";
}

std::vector<string> system_images::names() {
  vector<string> result;
  for (const auto& context_name : context_names())
    for (const auto& name : context_name.second)
      result.push_back(name);
  return result;
}

std::vector<xtd::drawing::size> system_images::sizes() {
  return {{16, 16}, {24, 24}, {32, 32}, {48, 48}, {64, 64}, {96, 96}, {128, 128}, {256, 256}, {512, 512}, {1024, 1024}};
}

vector<string> system_images::themes() {
  return {"windows", "macos", "gnome", "xtd"};
}
