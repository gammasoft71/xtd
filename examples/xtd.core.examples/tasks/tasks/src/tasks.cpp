#include <xtd/xtd>

class example {
public:
  static auto main() async_ {
    console::write_line("main {}, thread {} -> start", task<>::current_id(), thread::current_thread().managed_thread_id());
    
    auto task_proc = [] {console::write_line("  task {}, thread {} -> running", task<>::current_id(), thread::current_thread().managed_thread_id());};
    auto task1 = task<>::run(task_proc);
    auto task2 = task<>::factory().start_new(task_proc);
    auto task3 = task_factory {}.start_new(task_proc);
    task<>::wait_all(task1, task2, task3);
    
    task<> {task_proc}.run_synchronously();
    
    auto par_proc = [] {console::write_line("  parallel {} running", task<>::current_id());};
    parallel::invoke(par_proc, par_proc, par_proc, par_proc, par_proc, par_proc, par_proc, par_proc, par_proc, par_proc);
    
    auto task_string_proc = [] {return string::format("task<string> {}, thread {} -> running", task<>::current_id(), thread::current_thread().managed_thread_id());};
    auto task5 = task<string>::run(task_string_proc);
    task5.wait();
    console::write_line("main {}, thread {} -> task5.result = {}", task<>::current_id(), thread::current_thread().managed_thread_id(), task5.result());
    console::write_line("main {}, thread {} -> result co_await = {}", task<>::current_id(), thread::current_thread().managed_thread_id(), co_await task<string>::run(task_string_proc));
    
    console::write_line("main {}, thread {} -> end", task<>::current_id(), thread::current_thread().managed_thread_id());
    co_return;
  }
};

startup_(example::main);

// This code produces the following output :
//
// main 0, thread 1 -> start
//   task 2, thread 5 -> running
//   task 3, thread 2 -> running
//   task 4, thread 3 -> running
//   task 5, thread 1 -> running
//   parallel (6) running
//   parallel (7) running
//   parallel (8) running
//   parallel (9) running
//   parallel (10) running
//   parallel (12) running
//   parallel (13) running
//   parallel (14) running
//   parallel (11) running
//   parallel (15) running
// main 0, thread 1 -> task5.result = task<string> 16, thread 7 -> running
// main 0, thread 1 -> result co_await = task<string> 17, thread 7 -> running
// main 0, thread 7 -> end
