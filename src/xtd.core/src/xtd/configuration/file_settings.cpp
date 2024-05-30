#include "../../../include/xtd/configuration/file_settings.h"

using namespace xtd;
using namespace configuration;
using namespace io;

file_settings::file_settings(const ustring& file_path) {
  this->load(file_path);
}

file_settings::string_map file_settings::key_values() const noexcept {
  return key_values(ustring::empty_string);
}

file_settings::string_map file_settings::key_values(const ustring& section) const noexcept {
  if (section_key_values_.find(section) == section_key_values_.end()) return {};
  return section_key_values_.at(section);
}

file_settings::string_vector file_settings::keys() const noexcept {
  return keys(ustring::empty_string);
}

file_settings::string_vector file_settings::keys(const ustring& section) const noexcept {
  if (section_key_values_.find(section) == section_key_values_.end()) return {};
  auto keys = string_vector {};
  for (auto [key, value] : section_key_values_.at(section))
    keys.push_back(key);
  return keys;
}

file_settings::string_vector file_settings::sections() const noexcept {
  auto sections = string_vector {};
  for (auto [section, key_value] : section_key_values_)
    sections.push_back(section);
  return sections;
}

bool file_settings::equals(const file_settings& rhs) const noexcept {
  return section_key_values_ == rhs.section_key_values_;
}

void file_settings::load(const xtd::ustring& file_path) {
  file_path_ = path::get_full_path(file_path);
  if (ustring::is_empty(file_path_) || !file::exists(file_path_)) return;
  auto stream = stream_reader {file_path_};
  auto section = ustring::empty_string;
  while (!stream.end_of_stream()) {
    auto line = stream.read_line().trim();
    if (ustring::is_empty(line) || line.starts_with(';') || line.starts_with('#')) continue;
    if (line.starts_with('[') && line.ends_with(']')) section = line.substring(1, line.size() - 2);
    else {
      auto key_value = line.split({'='});
      section_key_values_[section][key_value[0]] = key_value.size() == 1 ? "" : ustring::join("=", key_value, 1);
    }
  }
}

ustring file_settings::read(const ustring& key, const ustring& default_value) noexcept {
  return read(ustring::empty_string, key, default_value);
}

ustring file_settings::read(const ustring& section, const ustring& key, const ustring& default_value) noexcept {
  if (section_key_values_.find(section) == section_key_values_.end() || section_key_values_[section].find(key) == section_key_values_[section].end()) section_key_values_[section][key] = default_value;
  return section_key_values_[section][key];
}

void file_settings::remove(const ustring& key) noexcept {
  remove(ustring::empty_string, key);
}

void file_settings::remove(const ustring& section, const ustring& key) noexcept {
  if (section_key_values_.find(section) == section_key_values_.end() || section_key_values_[section].find(key) == section_key_values_[section].end()) return;
  section_key_values_[section].erase(key);
}

void file_settings::remove_all_keys() noexcept {
  remove_all_keys(ustring::empty_string);
}

void file_settings::remove_all_keys(const ustring& section) noexcept {
  if (section_key_values_.find(section) == section_key_values_.end()) return;
  section_key_values_[section].clear();
}

void file_settings::reset() {
  section_key_values_.clear();
  if (ustring::is_empty(file_path_) || !file::exists(file_path_)) return;
  file::remove(file_path_);
}

void file_settings::save() {
  save_as(file_path_);
}

void file_settings::save_as(const xtd::ustring& file_path) {
  if (ustring::is_empty(file_path)) return;
  if (!directory::exists(path::get_directory_name(file_path))) directory::create_directory(path::get_directory_name(file_path));
  auto stream = stream_writer {file_path};
  stream.write(to_string());
}

ustring file_settings::to_string() const noexcept {
  auto text = ustring::empty_string;
  for (auto [section, key_value] : section_key_values_) {
    if (!ustring::is_empty(section)) text += ustring::format("{}[{}]\n", text.size() == 0 ? "" : "\n", section);
    for (auto [key, value] : key_value)
      text += ustring::format("{}={}\n", key, value);
  }
  return text;
}

void file_settings::write(const ustring& key, const ustring& value) noexcept {
  write(ustring::empty_string, key, value);
}

void file_settings::write(const ustring& section, const ustring& key, const ustring& value) noexcept {
  if (section_key_values_.find(section) != section_key_values_.end() && section_key_values_[section].find(key) != section_key_values_[section].end() && section_key_values_[section][key] == value) return;
  section_key_values_[section][key] = value;
}

const file_settings::string_map& file_settings::operator [](const ustring& section) const noexcept {
  return section_key_values_.at(section);
}

file_settings::string_map& file_settings::operator [](const ustring& section) noexcept {
  return section_key_values_[section];
}
