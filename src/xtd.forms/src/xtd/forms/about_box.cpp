#include "../../../include/xtd/forms/about_box.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

void about_box::show(const iwin32_window& owner) {
  show_about_dialog<icon>(&owner);
}

void about_box::show(const iwin32_window& owner, const string& text) {
  show_about_dialog<icon>(&owner, text);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption) {
  show_about_dialog<icon>(&owner, text, caption);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon) {
  show_about_dialog(&owner, text, caption, icon);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version) {
  show_about_dialog(&owner, text, caption, icon, version);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version) {
  show_about_dialog(&owner, text, caption, icon, version, long_version);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists);
}

void about_box::show(const iwin32_window& owner, const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists, const string& license) {
  show_about_dialog(&owner, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists, license);
}

void about_box::show() {
  show_about_dialog<icon>(nullptr);
}

void about_box::show(const string& text) {
  show_about_dialog<icon>(nullptr, text);
}

void about_box::show(const string& text, const string& caption) {
  show_about_dialog<icon>(nullptr, text, caption);
}

void about_box::show(const string& text, const string& caption, const icon& icon) {
  show_about_dialog(nullptr, text, caption, icon);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version) {
  show_about_dialog(nullptr, text, caption, icon, version);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists);
}

void about_box::show(const string& text, const string& caption, const icon& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists, const string& license) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists, license);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon) {
  show_about_dialog(nullptr, text, caption, icon);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version) {
  show_about_dialog(nullptr, text, caption, icon, version);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version, const string& copyright) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version, const string& copyright, const string& website) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists);
}

void about_box::show(const string& text, const string& caption, const bitmap& icon, const string& version, const string& long_version, const string& copyright, const string& website, const string& website_label, const author_collection& authors, const documenter_collection& documenters, const translator_collection& translators, const artist_collection& artists, const string& license) {
  show_about_dialog(nullptr, text, caption, icon, version, long_version, copyright, website, website_label, authors, documenters, translators, artists, license);
}
