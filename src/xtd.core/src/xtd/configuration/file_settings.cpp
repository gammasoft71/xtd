#include "../../../include/xtd/configuration/file_settings.h"
#include "../../../include/xtd/io/io_exception.h"

using namespace std;
using namespace xtd;
using namespace xtd::configuration;
using namespace xtd::io;

file_settings::file_settings(const ustring& file_path) : file_path_ {file_path != ustring::empty_string ? path::get_full_path(file_path) : ustring::empty_string} {
  if (ustring::is_empty(file_path_) || !file::exists(file_path_)) return;
  load(file_path_);
}

file_settings::file_settings(iostream& stream) : stream_ {&stream} {
  if (!stream.good() || stream_->peek() == EOF) return;
  load(*stream_);
}

file_settings::~file_settings() {
  if (auto_save_) save();
}

bool file_settings::auto_save() const noexcept {
  return auto_save_;
}
void file_settings::auto_save(bool value) noexcept {
  auto_save_ = value;
}

const xtd::ustring& file_settings::file_path() const noexcept {
  return file_path_;
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

optional<reference_wrapper<iostream>> file_settings::stream() const noexcept {
  return stream_ ? optional<reference_wrapper<iostream>> {*stream_} : optional<reference_wrapper<iostream>> {};
}

bool file_settings::equals(const file_settings& obj) const noexcept {
  return section_key_values_ == obj.section_key_values_;
}

void file_settings::from_string(const xtd::ustring& text) {
  auto unescaping = [](const ustring& line) {return line.replace("\\\\", "\\").replace("\\\'", "\'").replace("\\\"", "\"").replace("\\0", "\0").replace("\\a", "\a").replace("\\t", "\t").replace("\\r", "\r").replace("\\n", "\n").replace("\\;", ";").replace("\\#", "#").replace("\\=", "=").replace("\\:", ":").replace("\\ ", " ");};
  auto separate_comment = [](const ustring& line, ustring& comment) {
    auto result = line.trim();
    auto start_with_section = result.starts_with('[');

    auto last_index = result.last_index_of(start_with_section ? ']' : '"');
    if (last_index == result.npos) last_index = 0;
    if (result.index_of_any({'#', ';'}, last_index) != result.npos) {
      comment = result.substring(result.index_of_any({'#', ';'}, last_index));
      result = result.remove(result.index_of_any({'#', ';'}, last_index));
    }
    return result.trim();
  };
  section_key_values_.clear();
  auto comment = ustring::empty_string;
  auto section = ustring::empty_string;
  auto comment_break = false;
  for (auto line : text.split({10, 13})) {
    line = line.trim();
    if (ustring::is_empty(line)) {
      comment_break = true;
    } else if (line.starts_with(';') || line.starts_with('#')) {
      if (section_key_values_.empty() && !comment_break) before_all_comment_ += line + "\n";
      else comment += line + "\n";
    } else {
      comment_break = false;
      if (line.starts_with('[')) {
        auto section_comment = ustring::empty_string;
        line = separate_comment(line, section_comment);
        if (!line.ends_with(']')) throw format_exception {"Section start with '[' but not end with ']'", csf_};
        section = unescaping(line.substring(1, line.size() - 2));
        if (!ustring::is_empty(section_comment)) section_comment_[section] = section_comment;
        section_key_values_[section] = {};
        if (!ustring::is_empty(comment)) before_section_comment_[section] = comment;
        comment = ustring::empty_string;
      } else {
        //if (!ustring::is_empty(comment)) after_section_comment_[section] = comment;
        //comment = ustring::empty_string;
        auto key_value = line.split({'='});
        if (key_value.size() == 1 ) {
          if (!ustring::is_empty(comment)) before_key_comment_[unescaping(key_value[0].trim().trim('"'))] = comment;
          section_key_values_[section][unescaping(key_value[0].trim().trim('"'))] = "";
        } else {
          auto key_comment = ustring::empty_string;
          auto value = separate_comment(ustring::join("=", key_value, 1), key_comment);
          if (value.starts_with('"') && value.ends_with('"')) value = value.trim('"');
          if (value.starts_with('\'') && value.ends_with('\'')) value = value.trim('\'');
          if (!ustring::is_empty(key_comment)) key_comment_[unescaping(key_value[0].trim().trim('"'))] = key_comment;
          section_key_values_[section][unescaping(key_value[0].trim().trim('"'))] = unescaping(value);
          if (!ustring::is_empty(comment)) before_key_comment_[unescaping(key_value[0].trim().trim('"'))] = comment;
        }
        comment = ustring::empty_string;
      }
    }
  }
  
  if (!ustring::is_empty(comment)) after_all_comment_ += comment;
}

void file_settings::load(const xtd::ustring& file_path) {
  file_path_ = path::get_full_path(file_path);
  from_string(stream_reader {file_path_}.read_to_end());
}

void file_settings::load(istream& stream) {
  if (!stream.good()) throw io_exception {csf_};
  from_string(stream_reader {stream}.read_to_end());
}

ustring file_settings::read(const ustring& key, const ustring& default_value) noexcept {
  return read_string(ustring::empty_string, key, default_value);
}

ustring file_settings::read(const ustring& section, const ustring& key, const ustring& default_value) noexcept {
  return read_string(section, key, default_value);
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
  if (!ustring::is_empty(file_path_) && file::exists(file_path_)) file::remove(file_path_);
  if (stream_) stream_writer(*stream_).write("");
}

void file_settings::save() {
  if (!ustring::is_empty(file_path_)) save_as(file_path_);
  if (stream_) save_as(*stream_);
}

void file_settings::save_as(const xtd::ustring& file_path) {
  directory::create_directory(path::get_directory_name(path::get_full_path(file_path)));
  auto sw = stream_writer {file_path};
  sw.write(to_string());
}

void file_settings::save_as(ostream& stream) {
  auto sw = stream_writer {stream};
  sw.write(to_string());
}

ustring file_settings::to_string() const noexcept {
  auto split_comment = [](const ustring& comments) {
    auto result = ustring::empty_string;
    for (auto comment : comments.split({10, 13}))
      result += ustring::format("{}\n", comment);
    return result;
  };
  auto text = ustring::empty_string;
  if (!ustring::is_empty(before_all_comment_)) 
    text += split_comment(before_all_comment_);
  for (auto [section, key_value] : section_key_values_) {
    text += text.size() == 0 ? "" : "\n";
    auto bs_it = before_section_comment_.find(section);
    if (bs_it != before_section_comment_.end() && !ustring::is_empty(bs_it->second)) text += split_comment(bs_it->second);
    auto s_it = section_comment_.find(section);
    if (!ustring::is_empty(section)) text += ustring::format("[{}]{}\n", section, s_it != section_comment_.end() && !ustring::is_empty(s_it->second) ? ustring::format(" {}", s_it->second) : "");
    auto as_it = after_section_comment_.find(section);
    if (as_it != after_section_comment_.end() && !ustring::is_empty(as_it->second)) text += split_comment(as_it->second);
    for (auto [key, value] : key_value) {
      auto bk_it = before_key_comment_.find(key);
      if (bk_it != before_key_comment_.end() && !ustring::is_empty(bk_it->second)) text += split_comment(bk_it->second);
      auto k_it = key_comment_.find(key);
      text += ustring::format("{}={}{}\n", key, value.starts_with(' ') || value.starts_with('\t') || value.ends_with(' ') || value.ends_with('\t') || value.contains("#") || value.contains(";") || value.contains("=") ? ustring::format("\"{}\"", value) : value, k_it != key_comment_.end() && !ustring::is_empty(k_it->second) ? ustring::format(" {}", k_it->second) : "");
      auto ak_it = after_key_comment_.find(key);
      if (ak_it != after_key_comment_.end() && !ustring::is_empty(ak_it->second)) text += split_comment(ak_it->second);
    }
  }
  if (!ustring::is_empty(after_all_comment_)) text += "\n" + split_comment(after_all_comment_);
  return text;
}

void file_settings::write(const ustring& key, const ustring& value) noexcept {
  write_string(ustring::empty_string, key, value);
}

void file_settings::write(const ustring& section, const ustring& key, const ustring& value) noexcept {
  write_string(section, key, value);
}

const file_settings::string_map& file_settings::operator [](const ustring& section) const noexcept {
  return section_key_values_.at(section);
}

file_settings::string_map& file_settings::operator [](const ustring& section) noexcept {
  return section_key_values_[section];
}

xtd::ustring file_settings::read_string(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& default_value) noexcept {
  if (section_key_values_.find(section) == section_key_values_.end() || section_key_values_[section].find(key) == section_key_values_[section].end()) section_key_values_[section][key] = default_value;
  return section_key_values_[section][key];
}

void file_settings::write_string(const xtd::ustring& section, const xtd::ustring& key, const xtd::ustring& value) noexcept {
  if (section_key_values_.find(section) != section_key_values_.end() && section_key_values_[section].find(key) != section_key_values_[section].end() && section_key_values_[section][key] == value) return;
  section_key_values_[section][key] = value;
}
