#include "../../../include/xtd/forms/about_box"

using namespace xtd;
using namespace xtd::forms;

void about_box::show(const iwin32_window& owner) {
  show_about_dialog<xtd::drawing::icon>(&owner);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text) {
  show_about_dialog<xtd::drawing::icon>(&owner, text);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption) {
  show_about_dialog<xtd::drawing::icon>(&owner, text, caption);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon) {
  show_about_dialog(&owner, text, caption, icon);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version) {
  show_about_dialog(&owner, text, caption, icon, version);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version) {
  show_about_dialog(&owner, text, caption, icon, version, long_version);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators, const artist_collection& artists) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists);
}

void about_box::show(const iwin32_window& owner, const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators, const artist_collection& artists, const xtd::ustring& license) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists, license);
}

void about_box::show() {
  show_about_dialog<xtd::drawing::icon>(nullptr);
}

void about_box::show(const xtd::ustring& text) {
  show_about_dialog<xtd::drawing::icon>(nullptr, text);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption) {
  show_about_dialog<xtd::drawing::icon>(nullptr, text, caption);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon) {
  show_about_dialog(nullptr, text, caption, icon);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version) {
  show_about_dialog(nullptr, text, caption, icon, version);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators, const artist_collection& artists) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::icon& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators, const artist_collection& artists, const xtd::ustring& license) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists, license);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon) {
  show_about_dialog(nullptr, text, caption, icon);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version) {
  show_about_dialog(nullptr, text, caption, icon, version);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators, const artist_collection& artists) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists);
}

void about_box::show(const xtd::ustring& text, const xtd::ustring& caption, const xtd::drawing::bitmap& icon, const xtd::ustring& version, const xtd::ustring& long_version, const xtd::ustring& copyright, const xtd::ustring& website, const xtd::ustring& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection translators, const artist_collection& artists, const xtd::ustring& license) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists, license);
}
