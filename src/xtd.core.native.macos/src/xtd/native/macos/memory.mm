#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/memory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <mach/mach.h>
#include <sys/mount.h>
#include <sys/sysctl.h>
#include <array>

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
  using stats_t = struct statfs;
  auto total_virtual_memory = size_t {};
  auto stats = stats_t {};
  if (statfs("/", &stats) == 0) total_virtual_memory = static_cast<size_t>(stats.f_bsize) * stats.f_bfree;
  return total_virtual_memory;
}

size_t memory::get_used_physical_memory() {
  auto total_used_physical_memory = size_t {};
  auto page_size = vm_size_t {};
  auto vm_stats = vm_statistics_data_t {};
  auto count = static_cast<mach_msg_type_number_t>(sizeof(vm_stats) / sizeof(natural_t));
  if (host_page_size(mach_host_self(), &page_size) == KERN_SUCCESS && host_statistics(mach_host_self(), HOST_VM_INFO, reinterpret_cast<host_info_t>(&vm_stats), &count) == KERN_SUCCESS)
    total_used_physical_memory = (static_cast<size_t>(vm_stats.active_count) + static_cast<size_t>(vm_stats.inactive_count) + static_cast<size_t>(vm_stats.wire_count)) *  static_cast<size_t>(page_size);
  return total_used_physical_memory;
}

size_t memory::get_used_process_memory() {
  auto used_process_memory = size_t {};
  auto task_info = task_basic_info {};
  auto task_info_count = static_cast<mach_msg_type_number_t>(TASK_BASIC_INFO_COUNT);
  if (::task_info(mach_task_self(), TASK_BASIC_INFO, reinterpret_cast<task_info_t>(&task_info), &task_info_count) == KERN_SUCCESS)
    used_process_memory = task_info.resident_size;
  return used_process_memory;
}

size_t memory::get_used_virtual_memory() {
  auto used_virtual_memory = size_t {};
  auto task_info = task_basic_info {};
  auto task_info_count = static_cast<mach_msg_type_number_t>(TASK_BASIC_INFO_COUNT);
  if (::task_info(mach_task_self(), TASK_BASIC_INFO, reinterpret_cast<task_info_t>(&task_info), &task_info_count) == KERN_SUCCESS)
    used_virtual_memory = task_info.virtual_size;
  return used_virtual_memory;
}
