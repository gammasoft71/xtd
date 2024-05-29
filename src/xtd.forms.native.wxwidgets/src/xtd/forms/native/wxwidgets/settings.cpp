#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/settings>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <cstdio>
#include <cstdlib>
#include <map>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace std::filesystem;
using namespace xtd::native;

#if !defined(__WXOSX__)
#include <xtd/convert_string>
#include <wx/string.h>
#include <wx/config.h>
#if !defined(__WXMSW__)
#include <unistd.h>
#endif

intmax_t settings::create(const string& product_name, const string& company_name) {
  return reinterpret_cast<intmax_t>(new wxConfig(convert_string::to_wstring(product_name), convert_string::to_wstring(company_name)));
}

void settings::destroy(intmax_t config) {
  if (!config) return;
  delete reinterpret_cast<wxConfig*>(config);
}

void settings::reset(intmax_t config) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->DeleteAll();
}

string settings::read(intmax_t config, const string& key, const string& default_value) {
  if (!config) return "";
  return convert_string::to_string(reinterpret_cast<wxConfig*>(config)->Read(convert_string::to_wstring(key), convert_string::to_wstring(default_value)).c_str().AsWChar());
}

void settings::save(intmax_t config) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->Flush();
}

void settings::write(intmax_t config, const string& key, const string& value) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->Write(convert_string::to_wstring(key), wxString(convert_string::to_wstring(value)));
}
#else
class file_settings {
public:
  file_settings(const string& product_name, const string& company_name) noexcept : name_ {path {getenv("HOME")} / path {"Library"} / path {"Preferences"} / path {company_name} / path {product_name + " Preferences"}} {
    create_directory(name_.parent_path());
    reload();
  }
  
  void reset() noexcept {
    key_values_.clear();
    remove(name_.c_str());
  }
  
  string read(const string& key, const string& defeult_value) noexcept {
    reload();
    if (key_values_.find(key) == key_values_.end()) key_values_[key] = defeult_value;
    return key_values_[key];
  }
  
  void save() noexcept {
    if (!modified_) return;
    modified_ = false;
    auto stream = ofstream {name_, ios::trunc|ios::binary};
    if (!stream) return;
    for (auto [key, value] : key_values_) {
      auto line = key + "="s + value + "\n"s;
      stream.write(line.data(), line.size());
    }
    stream.close();
  }
  
  void write(const string& key, const string& value) noexcept {
    if (key_values_.find(key) != key_values_.end() && key_values_[key] == value) return;
    modified_ = true;
    key_values_[key] = value;
  }

private:
  void reload() noexcept {
    if (!modified_) return;
    modified_ = false;
    auto stream = ifstream {name_, ios::binary};
    if (!stream) return;
    std::string line;
    while (std::getline(stream, line)) {
      auto pos = line.find("=");
      key_values_[line.substr(0, pos)] = pos == line.npos || (pos + 1) > line.size() ? "" : line.substr(pos+1);
    }
    stream.close();
  }
  map<string, string> key_values_;
  path name_;
  bool modified_ = true;
};

intmax_t settings::create(const string& product_name, const string& company_name) {
  return reinterpret_cast<intmax_t>(new file_settings(product_name, company_name));
}

void settings::destroy(intmax_t config) {
  if (!config) return;
  delete reinterpret_cast<file_settings*>(config);
}

void settings::reset(intmax_t config) {
  if (!config) return;
  reinterpret_cast<file_settings*>(config)->reset();
}

string settings::read(intmax_t config, const string& key, const string& default_value) {
  if (!config) return "";
  return reinterpret_cast<file_settings*>(config)->read(key, default_value);
}

void settings::save(intmax_t config) {
  if (!config) return;
  reinterpret_cast<file_settings*>(config)->save();
}

void settings::write(intmax_t config, const string& key, const string& value) {
  if (!config) return;
  reinterpret_cast<file_settings*>(config)->write(key, value);
}
#endif
