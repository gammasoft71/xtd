#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/memory>
#undef __XTD_CORE_NATIVE_LIBRARY__

#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>


using namespace xtd::native;

size_t memory::get_total_physical_memory() {
  return sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
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
  FILE* fp = popen("memstat", "r");
  if (!fp)
    return 0;
  size_t physical_pages_in_use = 0;
  size_t page_size = sysconf(_SC_PAGE_SIZE);
  while (!feof(fp)) {
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp)) {
      if (sscanf(buffer, "Physical pages (in use) count: %zu", &physical_pages_in_use) == 1)
        break;
    }
  }
  pclose(fp);
  if (page_size == (size_t) -1)
    page_size = 4096;
  return physical_pages_in_use * page_size;
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
