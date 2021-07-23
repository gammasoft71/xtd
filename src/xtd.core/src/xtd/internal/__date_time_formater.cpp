#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__date_time_formater.h"
#undef __XTD_CORE_INTERNAL__

std::string __date_time_formater(std::string fmt, const std::tm& time, const std::locale& loc) {
  if (fmt.empty()) fmt =  "G";
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'd': return xtd::strings::format("{:D2}/{:D2}/{}", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900);
    case 'D': return xtd::strings::format("{}/{:D2}/{}", time.tm_mon+1, time.tm_mday, time.tm_year + 1900);
    case 'f': return __tm_formater("%Ec", time, loc);
    case 'F': return __tm_formater("%c", time, loc);
    case 'g': return __tm_formater("%Ec", time, loc);
    case 'G': return __tm_formater("%c", time, loc);
    case 'h': return xtd::strings::format("{}", __get_brief_weekday_name<char>(time, loc));
    case 'H': return xtd::strings::format("{}", __get_weekday_name<char>(time, loc));
    case 'i': return xtd::strings::format("{:D2}", time.tm_mday);
    case 'I': return xtd::strings::format("{}", time.tm_mday);
    case 'j': return xtd::strings::format("{}", __get_brief_month_name<char>(time, loc));
    case 'J': return xtd::strings::format("{}", __get_month_name<char>(time, loc));
    case 'k': return xtd::strings::format("{:D2}", time.tm_mon + 1);
    case 'K': return xtd::strings::format("{}", time.tm_mon + 1);
    case 'l': return xtd::strings::format("{:D2}", time.tm_year % 100);
    case 'L': return xtd::strings::format("{}", time.tm_year + 1900);
    case 'm':
    case 'M': return xtd::strings::format("{} {}", __get_month_name<char>(time, loc), time.tm_mday);
    case 'n': return xtd::strings::format("{}, {} {} {}", __get_weekday_name<char>(time, loc), time.tm_mday, __get_month_name<char>(time, loc), time.tm_year + 1900);
    case 'N': return xtd::strings::format("{}, {} {} {} {}:{:D2}:{:D2}", __get_weekday_name<char>(time, loc), time.tm_mday, __get_month_name<char>(time, loc), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'o':
    case 'O': return xtd::strings::format("{} {} {}", time.tm_mday, __get_month_name<char>(time, loc), time.tm_year + 1900);
    case 's': return xtd::strings::format("{}-{:D2}-{:D2}T{:D2}:{:D2}:{:D2}", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 't': return xtd::strings::format("{:D2}:{:D2}:{:D2}", time.tm_hour, time.tm_min, time.tm_sec);
    case 'T': return xtd::strings::format("{}:{:D2}:{:D2}", time.tm_hour, time.tm_min, time.tm_sec);
    case 'u': return xtd::strings::format("{}-{:D2}-{:D2} {:D2}:{:D2}:{:D2}", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 'U': return xtd::strings::format("{}, {} {} {} {}:{:D2}:{:D2}", __get_weekday_name<char>(time, loc), time.tm_mday, __get_month_name<char>(time, loc), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'v': return xtd::strings::format("{:D2}:{:D2}", time.tm_hour, time.tm_min);
    case 'V': return xtd::strings::format("{}:{:D2}", time.tm_hour, time.tm_min);
    case 'y': return xtd::strings::format("{} {}", __get_month_name<char>(time, loc), time.tm_year % 100);
    case 'Y': return xtd::strings::format("{} {}", __get_month_name<char>(time, loc), time.tm_year + 1900);
    case 'z':
    case 'Z': return __tm_formater("%Z", time, loc);
    default: __format_exception("Invalid format"); return {};
  }
}

std::wstring __date_time_formater(std::wstring fmt, const std::tm& time, const std::locale& loc) {
  if (fmt.empty()) fmt =  L"G";
  if (fmt.size() > 1) __format_exception("Invalid format");
  
  switch (fmt[0]) {
    case 'd': return xtd::strings::format(L"{:D2}/{:D2}/{}", time.tm_mon + 1, time.tm_mday, time.tm_year + 1900);
    case 'D': return xtd::strings::format(L"{}/{:D2}/{}", time.tm_mon+1, time.tm_mday, time.tm_year + 1900);
    case 'f': return __tm_formater(L"%Ec", time, loc);
    case 'F': return __tm_formater(L"%c", time, loc);
    case 'g': return __tm_formater(L"%Ec", time, loc);
    case 'G': return __tm_formater(L"%c", time, loc);
    case 'h': return xtd::strings::format(L"{}", __get_brief_weekday_name<wchar_t>(time, loc));
    case 'H': return xtd::strings::format(L"{}", __get_weekday_name<wchar_t>(time, loc));
    case 'i': return xtd::strings::format(L"{:D2}", time.tm_mday);
    case 'I': return xtd::strings::format(L"{}", time.tm_mday);
    case 'j': return xtd::strings::format(L"{}", __get_brief_month_name<wchar_t>(time, loc));
    case 'J': return xtd::strings::format(L"{}", __get_month_name<wchar_t>(time, loc));
    case 'k': return xtd::strings::format(L"{:D2}", time.tm_mon + 1);
    case 'K': return xtd::strings::format(L"{}", time.tm_mon + 1);
    case 'l': return xtd::strings::format(L"{:D2}", time.tm_year % 100);
    case 'L': return xtd::strings::format(L"{}", time.tm_year + 1900);
    case 'm':
    case 'M': return xtd::strings::format(L"{} {}", __get_month_name<wchar_t>(time, loc), time.tm_mday);
    case 'n': return xtd::strings::format(L"{}, {} {} {}", __get_weekday_name<wchar_t>(time, loc), time.tm_mday, __get_month_name<wchar_t>(time, loc), time.tm_year + 1900);
    case 'N': return xtd::strings::format(L"{}, {} {} {} {}:{:D2}:{:D2}", __get_weekday_name<wchar_t>(time, loc), time.tm_mday, __get_month_name<wchar_t>(time, loc), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'o':
    case 'O': return xtd::strings::format(L"{} {} {}", time.tm_mday, __get_month_name<wchar_t>(time, loc), time.tm_year + 1900);
    case 's': return xtd::strings::format(L"{}-{:D2}-{:D2}T{:D2}:{:D2}:{:D2}", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 't': return xtd::strings::format(L"{:D2}:{:D2}:{:D2}", time.tm_hour, time.tm_min, time.tm_sec);
    case 'T': return xtd::strings::format(L"{}:{:D2}:{:D2}", time.tm_hour, time.tm_min, time.tm_sec);
    case 'u': return xtd::strings::format(L"{}-{:D2}-{:D2} {:D2}:{:D2}:{:D2}", time.tm_year + 1900, time.tm_mon+1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
    case 'U': return xtd::strings::format(L"{}, {} {} {} {}:{:D2}:{:D2}", __get_weekday_name<wchar_t>(time, loc), time.tm_mday, __get_month_name<wchar_t>(time, loc), time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
    case 'v': return xtd::strings::format(L"{:D2}:{:D2}", time.tm_hour, time.tm_min);
    case 'V': return xtd::strings::format(L"{}:{:D2}", time.tm_hour, time.tm_min);
    case 'y': return xtd::strings::format(L"{} {}", __get_month_name<wchar_t>(time, loc), time.tm_year % 100);
    case 'Y': return xtd::strings::format(L"{} {}", __get_month_name<wchar_t>(time, loc), time.tm_year + 1900);
    case 'z':
    case 'Z': return __tm_formater(L"%Z", time, loc);
    default: __format_exception("Invalid format"); return {};
  }
}

std::string __date_time_formater(std::string fmt, time_t time, const std::locale& loc) {
  return __date_time_formater(fmt, *std::localtime(&time), loc);
}

std::wstring __date_time_formater(std::wstring fmt, time_t time, const std::locale& loc) {
  return __date_time_formater(fmt, *std::localtime(&time), loc);
}
