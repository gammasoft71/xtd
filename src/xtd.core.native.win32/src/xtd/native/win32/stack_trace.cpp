#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <StackWalker.h>
#include <cstddef>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using namespace xtd::native;

namespace {
  constexpr size_t native_offset = 3;
  
  class stack_walker final : public StackWalker {
  public:
    using frame = std::tuple<std::string, size_t, size_t, std::string, size_t>;
    using frames = std::vector<frame>;
    
    explicit stack_walker(bool need_file_info) : StackWalker(StackWalker::RetrieveVerbose | StackWalker::SymBuildPath), need_file_info_ {need_file_info} {}
    
    const frames& get_frames() const noexcept {return frames_;}
    
  private:
    void OnCallstackEntry(CallstackEntryType type, CallstackEntry& entry) override {
      StackWalker::OnCallstackEntry(type, entry);
      if (!need_file_info_) frames_.push_back(make_tuple("", 0, 0, entry.name, 0));
      else frames_.push_back(make_tuple(entry.lineFileName, entry.lineNumber, entry.offsetFromLine, entry.name, static_cast<size_t>(entry.offsetFromSmybol)));
    }
    
  private:
    frames frames_;
    bool need_file_info_ = false;
  };
}

size_t stack_trace::get_native_offset() {
  return native_offset;
}

stack_trace::frames stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  auto sw = stack_walker {need_file_info};
  if (!sw.ShowCallstack()) return {};
  
  auto result = stack_trace::frames {};
  auto frames = sw.get_frames();
  for (auto index = skip_frames + native_offset; index < frames.size(); ++index) {
    if (get<3>(frames[index]) == "invoke_main") break;
    if (get<3>(frames[index]) == "start") break;
    result.push_back(frames[index]);
  }
  return result;
}
