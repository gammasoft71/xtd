#if !defined(_WIN32)
#include <unistd.h>
#endif
#include <xtd/convert_string.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/settings.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/string.h>
#include <wx/config.h>

using namespace std;
using namespace xtd;
using namespace xtd::forms::native;

intptr_t settings::create(const ustring& product_name, const ustring& company_name) {
  application::initialize(); // Must be first
  return reinterpret_cast<intptr_t>(new wxConfig(convert_string::to_wstring(product_name), convert_string::to_wstring(company_name)));
}

void settings::destroy(intptr_t config) {
  if (!config) return;
  delete reinterpret_cast<wxConfig*>(config);
}

void settings::reset(intptr_t config) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->DeleteAll();
}

ustring settings::read(intptr_t config, const ustring& key, const ustring& default_value) {
  if (!config) return "";
  return reinterpret_cast<wxConfig*>(config)->Read(convert_string::to_wstring(key), convert_string::to_wstring(default_value)).c_str().AsWChar();
}

void settings::save(intptr_t config) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->Flush();
}

void settings::write(intptr_t config, const ustring& key, const ustring& value) {
  if (!config) return;
  reinterpret_cast<wxConfig*>(config)->Write(convert_string::to_wstring(key), wxString(convert_string::to_wstring(value)));
}
