#if __cpp_lib_stacktrace >= 202011l

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <stacktrace>

using namespace std;
using namespace xtd::native;

size_t stack_trace::get_native_offset() {
  return 3;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  auto frames = frame_collection {};
  for (auto& entry : std::stacktrace::current(skip_frames + get_native_offset())) {
    frames.push_back({need_file_info ? entry.source_file() : "", need_file_info ? static_cast<size_t>(entry.source_line()) : 0, 0, entry.description(), 0});
    if (std::get<3>(frames.back()) == "main") break;
  }
  return frames;
}

#else

#define NOMINMAX
#define UNICODE
#include <windows.h>
#include <dbghelp.h>
#include <string>
#include <vector>
#include <tuple>
#undef interface
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd::native;

namespace {
  using address = void*;
  using address_collection = std::vector<address>;
  using file_info = std::tuple<std::string, size_t, size_t>;
  using frame = std::tuple<std::string, size_t, size_t, std::string, size_t>;
  using frame_collection = std::vector<frame>;
  
  address_collection backtrace(size_t skip = 0, size_t maxFrames = 64) {
    auto stack = address_collection(maxFrames);
    auto frames = CaptureStackBackTrace(static_cast<DWORD>(skip), static_cast<DWORD>(maxFrames), stack.data(), nullptr);
    stack.resize(frames);
    return stack;
  }
  
  std::string addr_to_symbol(void* addr) {
    auto process = GetCurrentProcess();
    static auto initialized = false;
    if (!initialized) {
      SymInitialize(process, nullptr, TRUE);
      SymSetOptions(SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);
      initialized = true;
    }
    
    char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME];
    auto symbol = reinterpret_cast<PSYMBOL_INFO>(buffer);
    symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
    symbol->MaxNameLen = MAX_SYM_NAME;
    
    auto displacement = DWORD64 {0};
    return SymFromAddr(process, reinterpret_cast<DWORD64>(addr), &displacement, symbol) ? std::string(symbol->Name) : "???";
  }
  
  frame_collection get_frames_without_file_info(const address_collection& addresses) {
    auto frames = frame_collection {};
    for (auto address : addresses) {
      frames.push_back(std::make_tuple("", size_t {0}, size_t {0}, addr_to_symbol(address), size_t {0}));
      if (std::get<3>(frames.back()) == "main") break;
    }
    return frames;
  }
  
  file_info addresse_to_file_line(address addr) {
    auto line = IMAGEHLP_LINE64 {};
    auto displacement = DWORD {0};
    memset(&line, 0, sizeof(line));
    line.SizeOfStruct = sizeof(line);
    
    if (!SymGetLineFromAddr64(GetCurrentProcess(), reinterpret_cast<DWORD64>(addr), &displacement, &line)) return {};
    return {line.FileName ? line.FileName : "", static_cast<size_t>(line.LineNumber), size_t {0}};
  }
  
  frame_collection get_frames(const address_collection& addresses) {
    auto frames = frame_collection {};
    for (auto address : addresses) {
      auto file_info = addresse_to_file_line(address);
      frames.push_back(std::make_tuple(std::get<0>(file_info), std::get<1>(file_info), size_t {0}, addr_to_symbol(address), size_t {0}));
      if (std::get<3>(frames.back()) == "main") break;
    }
    return frames;
  }
}

size_t stack_trace::get_native_offset() {
  return 3;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  if (!need_file_info) return get_frames_without_file_info(backtrace(skip_frames + get_native_offset()));
  
  // Workaround: first native frame never has file info. Skip one more and drop the first to keep alignment.
  auto frames = ::get_frames(backtrace(skip_frames + get_native_offset() - 1));
  return frames.size() > 1 ? frame_collection {frames.begin() + 1, frames.end()} : frame_collection {};
}
#endif