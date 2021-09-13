#include "../../include/xtd/any.h"
#include "../../include/xtd/types.h"
#include "../../include/xtd/ustring.h"

using namespace std;
using namespace xtd;

std::unordered_map<std::type_index, std::function<std::string(std::any const&)>> __any_stringer__ {
  __to_any_stringer__<void>([]()->std::string {return "{}";}),
  __to_any_stringer__<bool>([](bool value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<byte_t>([](byte_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int16_t>([](int16_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int32_t>([](int32_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int64_t>([](int64_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<llong_t>([](llong_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<sbyte_t>([](sbyte_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint16_t>([](uint16_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint32_t>([](uint32_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint64_t>([](uint64_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<ullong_t>([](ullong_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<float>([](float value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<double>([](double value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<decimal_t>([](decimal_t value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<ustring>([](ustring value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::string>([](std::string value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::u8string>([](std::u8string value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::u16string>([](std::u16string value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::u32string>([](std::u32string value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::wstring>([](std::wstring value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<const char*>([](const char* value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<const char8_t*>([](const char8_t* value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<const char16_t*>([](const char16_t* value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<const char32_t*>([](const char32_t* value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<const wchar_t*>([](const wchar_t* value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char*>([](char* value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<char8_t*>([](char8_t* value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char16_t*>([](char16_t* value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char32_t*>([](char32_t* value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<wchar_t*>([](wchar_t* value)->std::string {return ustring::format("{}", value);}),
};
