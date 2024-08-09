#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/memory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

#include <windows.h>

using namespace xtd::native;

size_t memory::get_total_physical_memory() {
  MEMORYSTATUSEX memory_status;
  memory_status.dwLength = sizeof(memory_status);
  GlobalMemoryStatusEx(&memory_status);
  return memory_status.ullTotalPhys;
}

size_t memory::get_total_process_memory() {
  return get_total_virtual_memory() - get_used_virtual_memory();
}

size_t memory::get_total_virtual_memory() {
  MEMORYSTATUSEX memory_status;
  memory_status.dwLength = sizeof(memory_status);
  GlobalMemoryStatusEx(&memory_status);
  return memory_status.ullTotalVirtual;
}

size_t memory::get_used_physical_memory() {
  MEMORYSTATUSEX memory_status;
  memory_status.dwLength = sizeof(memory_status);
  GlobalMemoryStatusEx(&memory_status);
  return memory_status.ullTotalPhys - memory_status.ullAvailPhys;
}

size_t memory::get_used_process_memory() {
  PROCESS_MEMORY_COUNTERS pmc;
  GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
  return pmc.WorkingSetSize;
}

size_t memory::get_used_virtual_memory() {
  MEMORYSTATUSEX memory_status;
  memory_status.dwLength = sizeof(memory_status);
  GlobalMemoryStatusEx(&memory_status);
  return memory_status.ullTotalVirtual - memory_status.ullAvailVirtual;
}
