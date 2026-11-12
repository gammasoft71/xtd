#include <xtd/xtd>
#include <thread>

auto print_thread(const thread& thread) -> void {
  println("{}.handle = {}", thread.name(), thread.handle());
  println("{}.managed_thread_id = {}", thread.name(), thread.managed_thread_id());
  println("{}.name = {}", thread.name(), thread.name());
  println("{}.priority = {}", thread.name(), thread.priority());
  println("{}.thread_state = {}", thread.name(), thread.thread_state());
  println("{}.thread_id = {}", thread.name(), thread.thread_id());
  println();
}

auto main() -> int {
  thread::current_thread().name("main_thread");
  print_thread(thread::current_thread());
  
  using_(auto thread1 = thread {[] {
    thread::sleep(10_ms);
    print_thread(thread::current_thread());
  }}) {
    thread1.name("xtd_thread");
    thread1.priority(thread_priority::highest);
    thread1.start();
    thread1.join();
  }
  
  using_(auto thread1 = jthread {[] {
    thread::sleep(10_ms);
    print_thread(thread::current_thread());
  }}) {
    thread1.name("xtd_jthread");
    thread1.priority(thread_priority::highest);
    thread1.start();
  }
  
  using_(auto thread1 = thread {[] {
    thread::sleep(10_ms);
    print_thread(thread::current_thread());
  }}) {
    thread1.is_background(true);
    thread1.name("background_thread");
    thread1.start();
    thread::sleep(200_ms);
  }
  
  using_(auto thread1 = std::thread {[] {
    thread::sleep(10_ms);
    thread::current_thread().name("std_thread");
    thread::current_thread().priority(thread_priority::below_normal);
    print_thread(thread::current_thread());
  }}) {
    thread1.join();
  }
  
  using_(auto thread1 = std::jthread {[] {
    thread::sleep(10_ms);
    thread::current_thread().name("std_jthread");
    thread::current_thread().priority(thread_priority::below_normal);
    print_thread(thread::current_thread());
  }}) {
  }
  
  using_(auto thread1 = std::thread {[] {
    thread::sleep(10_ms);
    thread::current_thread().name("detached_thread");
    print_thread(thread::current_thread());
  }}) {
    thread1.detach();
    thread::sleep(200_ms);
  }
}

// This code produces the following output :
//
// main_thread.handle = 8555549440
// main_thread.managed_thread_id = 1
// main_thread.name = main_thread
// main_thread.priority = normal
// main_thread.thread_state = running
// main_thread.thread_id = 8555549440
//
// xtd_thread.handle = 6173618176
// xtd_thread.managed_thread_id = 2
// xtd_thread.name = xtd_thread
// xtd_thread.priority = highest
// xtd_thread.thread_state = running
// xtd_thread.thread_id = 6173618176
//
// xtd_jthread.handle = 6173618176
// xtd_jthread.managed_thread_id = 3
// xtd_jthread.name = xtd_jthread
// xtd_jthread.priority = highest
// xtd_jthread.thread_state = running
// xtd_jthread.thread_id = 6173618176
//
// background_thread.handle = 6173618176
// background_thread.managed_thread_id = 4
// background_thread.name = background_thread
// background_thread.priority = normal
// background_thread.thread_state = background
// background_thread.thread_id = 6173618176
//
// std_thread.handle = 6174191616
// std_thread.managed_thread_id = 0
// std_thread.name = std_thread
// std_thread.priority = below_normal
// std_thread.thread_state = background
// std_thread.thread_id = 6174191616
//
// std_jthread.handle = 6174732288
// std_jthread.managed_thread_id = 0
// std_jthread.name = std_jthread
// std_jthread.priority = below_normal
// std_jthread.thread_state = background
// std_jthread.thread_id = 6174732288
//
// detached_thread.handle = 6174191616
// detached_thread.managed_thread_id = 0
// detached_thread.name = detached_thread
// detached_thread.priority = normal
// detached_thread.thread_state = background
// detached_thread.thread_id = 6174191616
//
