#include "../include/xtd/diagnostics/stack_trace.h"
#include <call_stack.h>

using namespace xtd::diagnostics;

stack_trace::stack_trace(size_t skip_frames) : handle_(reinterpret_cast<intptr_t>(new stacktrace::call_stack(2))) {
  get_frames(skip_frames);
}


stack_trace::~stack_trace() {
  delete reinterpret_cast<stacktrace::call_stack*>(handle_);
}

void stack_trace::get_frames(size_t skip_frames) {
  for (auto index = 0U; index < reinterpret_cast<stacktrace::call_stack*>(handle_)->stack.size(); ++index)
   if (index >= skip_frames)
      frames_.push_back({reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].file, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].line, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].column, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].function, reinterpret_cast<stacktrace::call_stack*>(handle_)->stack[index].offset});
}
