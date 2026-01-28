#include <xtd/xtd>

auto job2() -> task<> {
  println("(job2) task {}, thread {} -> start", task<>::current_id(), thread::current_thread().managed_thread_id());
  co_await task<>::yield();
  println("(job2) task {}, thread {} -> end", task<>::current_id(), thread::current_thread().managed_thread_id());
  co_return;
}

auto job1() -> task<> {
  println("(job1) task {}, thread {} -> start", task<>::current_id(), thread::current_thread().managed_thread_id());
  co_await task<>::yield();
  job2().wait();
  println("(job1) task {}, thread {} -> end", task<>::current_id(), thread::current_thread().managed_thread_id());
  co_return;
}

auto main_async() async_ {
  println("(main) task {}, thread {} -> start", task<>::current_id(), thread::current_thread().managed_thread_id());
  job1().wait();
  println("(main) task {}, thread {} -> start", task<>::current_id(), thread::current_thread().managed_thread_id());
  co_return;
}

startup_(main_async);

// This code produces the following output :
//
// (main) task 0, thread 1 -> start
// (job1) task 0, thread 1 -> start
// (job2) task 0, thread 8 -> start
// (job2) task 0, thread 5 -> end
// (job1) task 0, thread 8 -> end
// (main) task 0, thread 1 -> start
