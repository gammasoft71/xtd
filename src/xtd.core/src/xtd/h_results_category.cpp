#include "../../include/xtd/h_results_category.h"
#include "../../include/xtd/h_results.h"
#include "../../include/xtd/literals.h"
#include "../../include/xtd/uint32.h"

using namespace xtd;

const std::error_category& xtd::h_results_category() noexcept {
  class h_results_category : public std::error_category {
  public:
    const char* name() const noexcept override{return "h_results_category";}
    
    std::string message(int h_result) const override {
      switch (h_result) {
        case h_results::S_OK: return "Operation successful.";
        case h_results::S_FALSE: return "Operation successful but returned no results.";
        case h_results::COR_E_ABANDONEDMUTEX: return "The wait completed due to an abandoned mutex.";
        case h_results::COR_E_AMBIGUOUSIMPLEMENTATION: return "Ambiguous implementation found.";
        case h_results::COR_E_AMBIGUOUSMATCH: return "Ambiguous match found.";
        case h_results::COR_E_APPDOMAINUNLOADED: return "Attempted to access an unloaded AppDomain.";
        case h_results::COR_E_APPLICATION: return "Error in the application.";
        case h_results::COR_E_ARGUMENT: return "Value does not fall within the expected range.";
        case h_results::COR_E_ARGUMENTOUTOFRANGE: return "Specified argument was out of the range of valid values.";
        case h_results::COR_E_ARITHMETIC : return "Overflow or underflow in the arithmetic operation.";
        case h_results::COR_E_ARRAYTYPEMISMATCH : return "Attempted to access an element as a type incompatible with the array.";
        case h_results::COR_E_BADEXEFORMAT: return "Format of the executable (.exe) cannot be run."_t;
        case h_results::COR_E_BADIMAGEFORMAT: return "Format of the executable (.exe) or library (.dll) is invalid."_t;
        case h_results::COR_E_CANNOTUNLOADAPPDOMAIN: return "Attempt to unload the AppDomain failed."_t;
        case h_results::COR_E_EXCEPTION: return "Exception of type 'xtd::exception' was thrown."_t;
        case h_results::COR_E_RANK: return "Attempted to operate on an array with the incorrect number of dimensions."_t;
        case h_results::COR_E_SYSTEM: return "System error."_t;
        case h_results::E_POINTER: return "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."_t;
        default: return string::format("Exception error 0x{0:X8} ({0})", static_cast<uint32>(h_result));
      }
    }
  };

  static auto result = h_results_category {};
  return result;
}
