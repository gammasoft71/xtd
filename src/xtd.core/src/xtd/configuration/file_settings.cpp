#include "../../../include/xtd/configuration/file_settings.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/environment.hpp"

using namespace xtd;
using namespace xtd::configuration;
using namespace xtd::helpers;
using namespace xtd::io;

namespace {
  static constexpr char alt_comment_delimiter = ';';
  static constexpr char alt_string_delimiter = '\'';
  static constexpr char comment_delimiter = '#';
  static constexpr char key_value_separator = '=';
  static constexpr char section_end_delimiter = ']';
  static constexpr char section_start_delimiter = '[';
  static constexpr char string_delimiter = '"';
}

file_settings::file_settings(const string& file_path) : file_path_ {file_path != string::empty_string ? path::get_full_path(file_path) : string::empty_string} {
  if (string::is_empty(file_path_) || !file::exists(file_path_)) return;
  load(file_path_);
}

file_settings::file_settings(std::iostream& stream) : stream_ {&stream} {
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

xtd::string file_settings::bottom_file_comment() const noexcept {
  return convert_comment_to_text(bottom_file_comment_);
}

file_settings& file_settings::bottom_file_comment(const xtd::string& value) noexcept {
  bottom_file_comment_ = convert_text_to_comment(value);
  return *this;
}

const xtd::string& file_settings::file_path() const noexcept {
  return file_path_;
}

file_settings::string_dictionary file_settings::key_values() const noexcept {
  return key_values(string::empty_string);
}

file_settings::string_dictionary file_settings::key_values(const string& section) const noexcept {
  if (section_key_values_.find(section) == section_key_values_.end()) return {};
  return section_key_values_.at(section);
}

file_settings::string_collection file_settings::keys() const noexcept {
  return keys(string::empty_string);
}

file_settings::string_collection file_settings::keys(const string& section) const noexcept {
  if (section_key_values_.find(section) == section_key_values_.end()) return {};
  auto keys = string_collection {};
  for (auto [key, value] : section_key_values_.at(section))
    keys.add(key);
  return keys;
}

file_settings::string_collection file_settings::sections() const noexcept {
  auto sections = string_collection {};
  for (auto [section, key_value] : section_key_values_)
    sections.add(section);
  return sections;
}

std::optional<ref<std::iostream>> file_settings::stream() const noexcept {
  return stream_ ? std::optional<ref<std::iostream>> {*stream_} : std::nullopt;
}

xtd::string file_settings::top_file_comment() const noexcept {
  return convert_comment_to_text(top_file_comment_);
}

file_settings& file_settings::top_file_comment(const xtd::string& value) noexcept {
  top_file_comment_ = convert_text_to_comment(value);
  return *this;
}

bool file_settings::equals(const object& obj) const noexcept {
  return is<file_settings>(obj) && equals(static_cast<const file_settings&>(obj));
}

bool file_settings::equals(const file_settings& other) const noexcept {
  return section_key_values_ == other.section_key_values_;
}

void file_settings::from_string(const xtd::string& text) {
  auto unescaping = [](const string & line) {return line.replace("\\\\", "\\").replace("\\\'", "\'").replace("\\\"", "\"").replace("\\0", "\0").replace("\\a", "\a").replace("\\t", "\t").replace("\\r", "\r").replace("\\n", "\n").replace("\\;", ";").replace("\\#", "#").replace("\\=", "=").replace("\\:", ":").replace("\\ ", " ");};
  auto separate_comment = [](const string & line, string & comment) {
    auto result = line.trim();
    auto start_with_section = result.starts_with(section_start_delimiter);
    
    auto last_index = result.last_index_of(start_with_section ? section_end_delimiter : string_delimiter);
    if (last_index == result.npos) last_index = 0;
    if (result.index_of_any({comment_delimiter, alt_comment_delimiter}, last_index) != result.npos) {
      comment = result.substring(result.index_of_any({comment_delimiter, alt_comment_delimiter}, last_index));
      result = result.remove(result.index_of_any({comment_delimiter, alt_comment_delimiter}, last_index));
    }
    return result.trim();
  };
  section_key_values_.clear();
  auto comment = string::empty_string;
  auto section = string::empty_string;
  auto comment_break = false;
  for (auto line : text.split({10, 13})) {
    line = line.trim();
    if (string::is_empty(line))
      comment_break = true;
    else if (line.starts_with(comment_delimiter) || line.starts_with(alt_comment_delimiter)) {
      if (section_key_values_.empty() && !comment_break) top_file_comment_ += line + environment::new_line();
      else comment += line + environment::new_line();
    } else {
      comment_break = false;
      if (line.starts_with(section_start_delimiter)) {
        auto section_comment = string::empty_string;
        line = separate_comment(line, section_comment);
        if (!line.ends_with(section_end_delimiter)) throw_helper::throws(exception_case::format, string::format("Section start with '{}' but not end with '{}'", section_start_delimiter, section_end_delimiter).chars().c_str());
        section = unescaping(line.substring(1, line.length() - 2));
        if (!string::is_empty(section_comment)) section_comment_[section] = section_comment;
        section_key_values_[section] = {};
        if (!string::is_empty(comment)) before_section_comment_[section] = comment;
        comment = string::empty_string;
      } else {
        //if (!string::is_empty(comment)) after_section_comment_[section] = comment;
        //comment = string::empty_string;
        auto key_value = line.split(key_value_separator);
        if (key_value.length() == 1) {
          if (!string::is_empty(comment)) before_key_value_comment_[section][unescaping(key_value[0].trim().trim(string_delimiter))] = comment;
          section_key_values_[section][unescaping(key_value[0].trim().trim(string_delimiter))] = "";
        } else {
          auto key_comment = string::empty_string;
          auto value = separate_comment(string::join(string::format("{}", key_value_separator), key_value, 1), key_comment);
          if (value.starts_with(string_delimiter) && value.ends_with(string_delimiter)) value = value.trim(string_delimiter);
          if (value.starts_with(alt_string_delimiter) && value.ends_with(alt_string_delimiter)) value = value.trim(alt_string_delimiter);
          if (!string::is_empty(key_comment)) key_value_comment_[section][unescaping(key_value[0].trim().trim(string_delimiter))] = key_comment;
          section_key_values_[section][unescaping(key_value[0].trim().trim(string_delimiter))] = unescaping(value);
          if (!string::is_empty(comment)) before_key_value_comment_[section][unescaping(key_value[0].trim().trim(string_delimiter))] = comment;
        }
        comment = string::empty_string;
      }
    }
  }
  
  if (!string::is_empty(comment)) bottom_file_comment_ += comment;
}

void file_settings::load(const xtd::string& file_path) {
  file_path_ = path::get_full_path(file_path);
  from_string(stream_reader {file_path_}.read_to_end());
}

void file_settings::load(std::istream& stream) {
  if (!stream.good()) throw_helper::throws(exception_case::io);
  from_string(stream_reader {stream}.read_to_end());
}

string file_settings::read(const string& key, const string& default_value) noexcept {
  return read_string(string::empty_string, key, default_value);
}

string file_settings::read(const string& section, const string& key, const string& default_value) noexcept {
  return read_string(section, key, default_value);
}

void file_settings::remove(const string& key) noexcept {
  remove(string::empty_string, key);
}

void file_settings::remove(const string& section, const string& key) noexcept {
  if (section_key_values_.find(section) == section_key_values_.end() || section_key_values_[section].find(key) == section_key_values_[section].end()) return;
  section_key_values_[section].erase(key);
}

void file_settings::remove_all_keys() noexcept {
  remove_all_keys(string::empty_string);
}

void file_settings::remove_all_keys(const string& section) noexcept {
  if (section_key_values_.find(section) == section_key_values_.end()) return;
  section_key_values_[section].clear();
}

void file_settings::reset() {
  section_key_values_.clear();
  if (!string::is_empty(file_path_) && file::exists(file_path_)) file::remove(file_path_);
  if (stream_) stream_writer(*stream_).write("");
}

void file_settings::save() {
  if (!string::is_empty(file_path_)) save_as(file_path_);
  if (stream_) save_as(*stream_);
}

void file_settings::save_as(const xtd::string& file_path) {
  directory::create_directory(path::get_directory_name(path::get_full_path(file_path)));
  auto sw = stream_writer {file_path};
  sw.write(to_string());
}

void file_settings::save_as(std::ostream& stream) {
  auto sw = stream_writer {stream};
  sw.write(to_string());
}

string file_settings::to_string() const noexcept {
  auto split_comment = [](const string & comments) {
    auto result = string::empty_string;
    for (auto comment : comments.split({10, 13}))
      result += string::format("{}\n", comment);
    return result;
  };
  auto text = string::empty_string;
  if (!string::is_empty(top_file_comment_))
    text += split_comment(top_file_comment_);
  for (auto [section, key_value] : section_key_values_) {
    text += text.length() == 0 ? "" : environment::new_line();
    auto bs_it = before_section_comment_.find(section);
    if (bs_it != before_section_comment_.end() && !string::is_empty(bs_it->second)) text += split_comment(bs_it->second);
    auto s_it = section_comment_.find(section);
    if (!string::is_empty(section)) text += string::format("{}{}{}{}\n", section_start_delimiter, section, section_end_delimiter, s_it != section_comment_.end() && !string::is_empty(s_it->second) ? string::format(" {}", s_it->second) : "");
    auto as_it = after_section_comment_.find(section);
    if (as_it != after_section_comment_.end() && !string::is_empty(as_it->second)) text += split_comment(as_it->second);
    for (auto [key, value] : key_value) {
      if (before_key_value_comment_.find(section) != before_key_value_comment_.end()) {
        auto bk_it = before_key_value_comment_.at(section).find(key);
        if (bk_it != before_key_value_comment_.at(section).end() && !string::is_empty(bk_it->second)) text += split_comment(bk_it->second);
      }
      if (key_value_comment_.find(section) == key_value_comment_.end())
        text += string::format("{} {} {}\n", key, key_value_separator, value.starts_with(' ') || value.starts_with('\t') || value.ends_with(' ') || value.ends_with('\t') || value.contains(comment_delimiter) || value.contains(alt_comment_delimiter) || value.contains(key_value_separator) ? string::format("\"{}\"", value) : value);
      else {
        auto k_it = key_value_comment_.at(section).find(key);
        text += string::format("{} {} {}{}\n", key, key_value_separator, value.starts_with(' ') || value.starts_with('\t') || value.ends_with(' ') || value.ends_with('\t') || value.contains(comment_delimiter) || value.contains(alt_comment_delimiter) || value.contains(key_value_separator) ? string::format("\"{}\"", value) : value, k_it != key_value_comment_.at(section).end() && !string::is_empty(k_it->second) ? string::format(" {}", k_it->second) : "");
      }
      
      if (after_key_value_comment_.find(section) != after_key_value_comment_.end()) {
        auto ak_it = after_key_value_comment_.at(section).find(key);
        if (ak_it != after_key_value_comment_.at(section).end() && !string::is_empty(ak_it->second)) text += split_comment(ak_it->second);
      }
    }
  }
  if (!string::is_empty(bottom_file_comment_)) text += environment::new_line() + split_comment(bottom_file_comment_);
  return text;
}

void file_settings::write(const string& key, const string& value) noexcept {
  write_string(string::empty_string, key, value);
}

void file_settings::write(const string& section, const string& key, const string& value) noexcept {
  write_string(section, key, value);
}

const file_settings::string_dictionary& file_settings::operator [](const string& section) const noexcept {
  return section_key_values_.at(section);
}

file_settings::string_dictionary& file_settings::operator [](const string& section) noexcept {
  return section_key_values_[section];
}

xtd::string file_settings::convert_comment_to_text(const xtd::string& text) const noexcept {
  auto lines = text.split({10, 13});
  for (auto& line : lines)
    if (line.starts_with(comment_delimiter) || line.starts_with(alt_comment_delimiter)) line = line.remove(0, 1).trim();
  return string::join(environment::new_line(), lines);
}

xtd::string file_settings::convert_text_to_comment(const xtd::string& text) const noexcept {
  auto lines = text.split({10, 13});
  for (auto& line : lines)
    if (!line.starts_with(comment_delimiter) && !line.starts_with(alt_comment_delimiter))
      line = string::format("{} {}", comment_delimiter, line);
  return string::join(environment::new_line(), lines);
}

xtd::string file_settings::read_string(const xtd::string& section, const xtd::string& key, const xtd::string& default_value) noexcept {
  if (section_key_values_.find(section) == section_key_values_.end() || section_key_values_[section].find(key) == section_key_values_[section].end()) section_key_values_[section][key] = default_value;
  return section_key_values_[section][key];
}

void file_settings::write_string(const xtd::string& section, const xtd::string& key, const xtd::string& value) noexcept {
  if (section_key_values_.find(section) != section_key_values_.end() && section_key_values_[section].find(key) != section_key_values_[section].end() && section_key_values_[section][key] == value) return;
  section_key_values_[section][key] = value;
}
