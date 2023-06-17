#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <StackWalker.h>
#include <cstddef>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using namespace xtd::native;

class stack_walker : public StackWalker {
public:
  using frame = std::tuple<std::string, size_t, size_t, std::string, size_t>;
  using frames = std::vector<frame>;

  stack_walker() : StackWalker(StackWalker::RetrieveVerbose | StackWalker::SymBuildPath) {}

  const std::vector<frame>& stack() const noexcept {return stack_;}
protected:
  void OnCallstackEntry(CallstackEntryType type, CallstackEntry& entry) override {
    StackWalker::OnCallstackEntry(type, entry);
    stack_.push_back(make_tuple(entry.lineFileName, entry.lineNumber, entry.offsetFromLine, entry.name, static_cast<size_t>(entry.offsetFromSmybol)));
  }

private:
  std::vector<frame> stack_;
};

stack_trace::frames stack_trace::get_frames(size_t skip_frames) {
  stack_walker sw;
  sw.ShowCallstack();
  stack_trace::frames frames;
  for (size_t index = skip_frames + 2; index < sw.stack().size(); ++index) {
    frames.push_back(sw.stack()[index]);
    if (get<3>(sw.stack()[index]) == "main") break;
  }

  return frames;
}
