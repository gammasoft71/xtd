#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/memory>
#undef __XTD_CORE_NATIVE_LIBRARY__

#include <unistd.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace xtd::native;

namespace {
  size_t page_size() {
    auto length = sizeof(size_t);
    auto page_size = size_t {};
    if (sysctlbyname("hw.pagesize", &page_size, &length, nullptr, 0) == -1) return 0;
    return page_size;
  }
}

size_t memory::get_total_physical_memory() {
  auto length = sizeof(size_t);
  auto total_physical_memory = size_t {};
  if (sysctlbyname("hw.physmem", &total_physical_memory, &length, nullptr, 0) == -1) return 0;
  return total_physical_memory;
}

size_t memory::get_total_process_memory() {
  auto limit = rlimit {};
  if (getrlimit(RLIMIT_AS, &limit) == 0 && limit.rlim_cur != RLIM_INFINITY) return static_cast<size_t>(limit.rlim_cur);
  return get_total_virtual_memory() - get_used_virtual_memory();
}

size_t memory::get_total_virtual_memory() {
  auto length = sizeof(size_t);
  auto total_virtual_pages = size_t {};
  if (sysctlbyname("vm.stats.vm.v_page_count", &total_virtual_pages, &length, nullptr, 0) == -1) return 0;
  return total_virtual_pages * page_size();
}

size_t memory::get_used_physical_memory() {
  auto length = sizeof(size_t);
  auto free_physical_pages = size_t {};
  if (sysctlbyname("vm.stats.vm.v_free_count", &free_physical_pages, &length, nullptr, 0) == -1) return 0;
  auto free_physical_memory = free_physical_pages * page_size();
  return get_total_physical_memory() - free_physical_memory;
}

size_t memory::get_used_process_memory() {
  auto status_file = std::ifstream {"/proc/self/status"};
  auto line = std::string {};
  auto memory_usage = size_t {};
  
  while (std::getline(status_file, line)) {
    if (line.substr(0, 6) == "VmRSS:") {
      memory_usage = std::stoul(line.substr(6)) * 1024;
      break;
    }
  }
  return memory_usage;
}

size_t memory::get_used_virtual_memory() {
  auto length = sizeof(size_t);
  auto free_virtual_pages = size_t {};
  if (sysctlbyname("vm.stats.vm.v_free_count", &free_virtual_pages, &length, nullptr, 0) == -1) return 0;
  auto free_virtual_memory = free_virtual_pages * page_size();
  return get_total_virtual_memory() - free_virtual_memory;
}
