#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/memory.h>
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

size_t memory::get_total_physical_memory() {
  auto mib = std::array<int32_t, 2> {CTL_HW, HW_MEMSIZE};
  auto total_physical_memory = size_t {};
  auto length = sizeof(size_t);
  sysctl(mib.data(), 2, &total_physical_memory, &length, nullptr, 0);
  return total_physical_memory;
}

size_t memory::get_total_process_memory() {
  auto limit = rlimit {};
  if (getrlimit(RLIMIT_AS, &limit) == 0 && limit.rlim_cur != RLIM_INFINITY) return static_cast<size_t>(limit.rlim_cur);
  return get_total_virtual_memory() - get_used_virtual_memory();
}

size_t memory::get_total_virtual_memory() {
  auto meminfo_file = std::ifstream {"/proc/meminfo"};
  auto line = std::string {};
  auto total_memory = size_t {};
  
  while (std::getline(meminfo_file, line)) {
    if (line.substr(0, 9) == "MemTotal:") {
      total_memory = std::stoul(line.substr(9)) * 1024;
      break;
    }
  }
  return total_memory;
}

size_t memory::get_used_physical_memory() {
  auto mib = std::array<int32_t, 2> {CTL_HW, VM_FREE_COUNT};
  auto free_physical_memory = size_t {};
  auto length = sizeof(size_t);
  sysctl(mib.data(), 2, &free_physical_memory, &length, nullptr, 0);
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
  auto meminfo_file = std::ifstream {"/proc/meminfo"};
  auto line = std::string {};
  auto total_memory = size_t {};
  auto free_memory = size_t {};
  auto buffers_memory = size_t {};
  auto cached_memory = size_t {};
  
  while (std::getline(meminfo_file, line)) {
    if (line.substr(0, 9) == "MemTotal:") total_memory = std::stoul(line.substr(9)) * 1024;
    else if (line.substr(0, 8) == "MemFree:") free_memory = std::stoul(line.substr(8)) * 1024;
    else if (line.substr(0, 8) == "Buffers:") buffers_memory = std::stoul(line.substr(8)) * 1024;
    else if (line.substr(0, 7) == "Cached:") cached_memory = std::stoul(line.substr(7)) * 1024;
  }
  return total_memory - free_memory - buffers_memory - cached_memory;
}
