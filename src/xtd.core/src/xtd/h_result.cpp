#include "../../include/xtd/array.h"
#include "../../include/xtd/call_once.h"
#include "../../include/xtd/h_result.h"
#include "../../include/xtd/literals.h"
#include "../../include/xtd/string.h"
#include "../../include/xtd/uint32.h"

using namespace xtd;

const std::map<int32, string>& h_result::get_h_result_names() noexcept {
  static auto h_result_names = std::map<int32, string> {
    {S_OK, "Operation successful."_t},
    {S_FALSE, "Operation successful but returned no results."_t},
    {COR_E_ABANDONEDMUTEX, "The wait completed due to an abandoned mutex."_t},
    {COR_E_AMBIGUOUSIMPLEMENTATION, "Ambiguous implementation found."_t},
    {COR_E_AMBIGUOUSMATCH, "Ambiguous match found."_t},
    {COR_E_APPDOMAINUNLOADED, "Attempted to access an unloaded AppDomain."_t},
    {COR_E_APPLICATION, "Error in the application."_t},
    {COR_E_ARGUMENT, "Value does not fall within the expected range."_t},
    {COR_E_ARGUMENTOUTOFRANGE, "Specified argument was out of the range of valid values."_t},
    {COR_E_ARITHMETIC , "Overflow or underflow in the arithmetic operation."},
    {COR_E_ARRAYTYPEMISMATCH , "Attempted to access an element as a type incompatible with the array."_t},
    {COR_E_BADEXEFORMAT, "Format of the executable (.exe) cannot be run."_t},
    {COR_E_BADIMAGEFORMAT, "Format of the executable (.exe) or library (.dll) is invalid."_t},
    {COR_E_CANNOTUNLOADAPPDOMAIN, "Attempt to unload the AppDomain failed."_t},
    {COR_E_EXCEPTION, "Exception of type 'xtd::exception' was thrown."_t},
    {COR_E_RANK, "Attempted to operate on an array with the incorrect number of dimensions."_t},
    {COR_E_SYSTEM, "System error."_t},
    {E_POINTER, "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."_t},
  };
  return h_result_names;
}

const xtd::array<int32>& h_result::get_h_results() noexcept {
  static auto h_results = xtd::array<int32> {};
  call_once_ {
    for (auto item : get_h_result_names())
      h_results.push_back(item.first);
  };
  return h_results;
}

string h_result::get_name(int32 h_result) noexcept {
  auto iterator = get_h_result_names().find(h_result);
  if (iterator == get_h_result_names().end()) return string::format("Unknown h_result 0x{0:X8} ({0})", static_cast<uint32>(h_result));
  return iterator->second;
}

const std::error_category& h_result::h_result_category() noexcept {
  struct h_result_category : public std::error_category {
    std::string message(int h_result) const override {return  xtd::h_result::get_name(h_result);}
    const char* name() const noexcept override{return "h_result_category";}
  };

  static auto result = h_result_category {};
  return result;
}

std::error_code h_result::make_error_code(int h_result) noexcept {
  return std::error_code {h_result, h_result_category()};
}
