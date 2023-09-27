#include "../../include/xtd/ustring"
#include "../../include/xtd/register_any_stringer"
#include "../../include/xtd/types"
#include "../../include/xtd/date_time"
#include "../../include/xtd/time_span"

using namespace std;
using namespace xtd;

std::unordered_map<std::type_index, std::function<std::string(std::any const&)>> __any_stringer__ {
  __to_any_stringer__<void>([]()->std::string {return "{}";}),
  __to_any_stringer__<bool>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char>([](auto value)->std::string {return ustring::format("{}", value);}),
#if defined(__cpp_lib_char8_t)
  //__to_any_stringer__<char8>([](auto value)->std::string {return ustring::format("{}", value);}),
#endif
  __to_any_stringer__<char16>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char32>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<wchar>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<xtd::byte>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int16>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int32>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<int64>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<slong>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<sbyte>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint16>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint32>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<uint64>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<xtd::ulong>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<float>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<double>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<decimal>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<ustring>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::string>([](auto value)->std::string {return ustring::format("{}", value);}),
#if defined(__cpp_lib_char8_t)
  __to_any_stringer__<std::u8string>([](auto value)->std::string {return ustring::format("{}", value);}),
#endif
  __to_any_stringer__<std::u16string>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::u32string>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<std::wstring>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<const char*>([](auto value)->std::string {return ustring::format("{}", value);}),
#if defined(__cpp_lib_char8_t)
  //__to_any_stringer__<const char8*>([](auto value)->std::string {return ustring::format("{}", value);}),
#endif
  //__to_any_stringer__<const char16*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<const char32*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<const wchar*>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<char*>([](auto value)->std::string {return ustring::format("{}", value);}),
#if defined(__cpp_lib_char8_t)
  //__to_any_stringer__<char8*>([](auto value)->std::string {return ustring::format("{}", value);}),
#endif
  //__to_any_stringer__<char16*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<char32*>([](auto value)->std::string {return ustring::format("{}", value);}),
  //__to_any_stringer__<wchar*>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<date_time>([](auto value)->std::string {return ustring::format("{}", value);}),
  __to_any_stringer__<time_span>([](auto value)->std::string {return ustring::format("{}", value);}),
};
