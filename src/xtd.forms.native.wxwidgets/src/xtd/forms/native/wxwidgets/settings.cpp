#if !defined(_WIN32)
#include <unistd.h>
#endif
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/settings.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/config.h>

using namespace std;
using namespace xtd;
using namespace xtd::forms::native;

intptr_t settings::create(const std::string& product_name, const std::string& company_name) {
  application::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wxConfig({product_name.c_str(), wxMBConvUTF8()}, {company_name.c_str(), wxMBConvUTF8()}));
}

void settings::destroy(intptr_t config) {
  if (!config) return;
  delete reinterpret_cast<wxConfig*>(config);
}

void settings::reset(intptr_t config) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->DeleteAll();
}

std::string settings::read(intptr_t config, const std::string& key, const std::string& default_value) {
  if (!config) return "";
  return reinterpret_cast<wxConfig*>(config)->Read(key, {default_value.c_str(), wxMBConvUTF8()}).utf8_string();
}

void settings::save(intptr_t config) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->Flush();
}

void settings::write(intptr_t config, const std::string& key, const std::string& value) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->Write(key, {value.c_str(), wxMBConvUTF8()});
}
