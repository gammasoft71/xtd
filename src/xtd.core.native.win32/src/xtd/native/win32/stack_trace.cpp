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

class stack_walker final : public StackWalker {
public:
  using frame = std::tuple<std::string, size_t, size_t, std::string, size_t>;
  using frames = std::vector<frame>;
  
  stack_walker() : StackWalker(StackWalker::RetrieveVerbose | StackWalker::SymBuildPath) {}
  
  const frames& get_frames() const noexcept {return frames_;}
  
private:
  void OnCallstackEntry(CallstackEntryType type, CallstackEntry& entry) override {
    StackWalker::OnCallstackEntry(type, entry);
    frames_.push_back(make_tuple(entry.lineFileName, entry.lineNumber, entry.offsetFromLine, entry.name, static_cast<size_t>(entry.offsetFromSmybol)));
  }
  
private:
  frames frames_;
};

stack_trace::frames stack_trace::get_frames(size_t skip_frames) {
  auto sw = stack_walker {};
  if (!sw.ShowCallstack()) return {};
  
  auto result = stack_trace::frames {};
  auto frames = sw.get_frames();
  for (auto index = skip_frames + 1; index < frames.size(); ++index) {
    result.push_back(frames[index]);
    if (get<3>(frames[index]) == "main") break;
  }
  return result;
}
