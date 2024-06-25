#include "../../../include/xtd/threading/jthread.h"

using namespace xtd;
using namespace xtd::threading;

jthread::jthread(const xtd::threading::parameterized_thread_start& start) : thread {start} {
  auto_join(true);
}

jthread::jthread(const xtd::threading::parameterized_thread_start& start, int32 max_stack_size) : thread {start, max_stack_size} {
  auto_join(true);
}

jthread::jthread(const xtd::threading::thread_start& start) : thread {start} {
  auto_join(true);
}

jthread::jthread(const xtd::threading::thread_start& start, int32 max_stack_size) : thread {start, max_stack_size} {
  auto_join(true);
}

jthread::jthread() {
  auto_join(true);
}

jthread jthread::start_new(const xtd::threading::thread_start& start) {
  auto thread = threading::jthread {start};
  thread.start();
  return thread;
}

jthread jthread::start_new(const xtd::threading::parameterized_thread_start& start, std::any obj) {
  auto thread = threading::jthread {start};
  thread.start(obj);
  return thread;
}
