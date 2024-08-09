#include "../../include/xtd/memory_information.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/memory.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;

size memory_information::get_free_physical_memory() noexcept {
  return get_total_physical_memory() - get_used_physical_memory();
}

size memory_information::get_free_process_memory() noexcept {
  return get_total_process_memory() - get_used_process_memory();
}

size memory_information::get_free_virtual_memory() noexcept {
  return get_total_virtual_memory() - get_used_virtual_memory();
}

size memory_information::get_total_physical_memory() noexcept {
  return native::memory::get_total_physical_memory();
}

size memory_information::get_total_process_memory() noexcept {
  return native::memory::get_total_process_memory();
}

size memory_information::get_total_virtual_memory() noexcept {
  return native::memory::get_total_virtual_memory();
}

size memory_information::get_used_physical_memory() noexcept {
  return native::memory::get_used_physical_memory();
}

size memory_information::get_used_process_memory() noexcept {
  return native::memory::get_used_process_memory();
}

size memory_information::get_used_virtual_memory() noexcept {
  return native::memory::get_used_virtual_memory();
}
