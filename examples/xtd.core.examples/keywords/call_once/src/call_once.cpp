#include <xtd/xtd>

using namespace xtd;
using namespace xtd::threading;

auto main() -> int {
  console::write_line("(main) begin");
  
  auto mre = manual_reset_event {};
  
  auto thread_proc = [&] {
    static auto cpt = 0;
    call_once_ {
      console::write_line("  (thread_proc) call once {} times", cpt + 1);
    };
    console::write_line("  (thread_proc) running {} times", ++cpt);
    if (cpt == 3) mre.set();
  };
  
  thread_pool::register_wait_for_single_object(mre, thread_proc, {}, 100, false);
  
  mre.wait_one();
  
  thread::join_all();
  console::write_line("(main) end");
}

// This code produces the following output :
//
// (main) begin
//   (thread_proc) call once 1 times
//   (thread_proc) running 1 times
//   (thread_proc) running 2 times
//   (thread_proc) running 3 times
// (main) end
