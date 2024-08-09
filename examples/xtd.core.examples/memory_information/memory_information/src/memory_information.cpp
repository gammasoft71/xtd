#include <xtd/console>
#include <xtd/memory_information>

using namespace xtd;

auto main() -> int {
  console::write_line("Physical memory");
  console::write_line("  total = {,12} ({,3} GB)", memory_information::get_total_physical_memory(), memory_information::get_total_physical_memory() / 1024 / 1024 / 1024);
  console::write_line("  used  = {,12} ({,3} GB)", memory_information::get_used_physical_memory(), memory_information::get_used_physical_memory() / 1024 / 1024 / 1024);
  console::write_line("  free  = {,12} ({,3} GB)", memory_information::get_free_physical_memory(), memory_information::get_free_physical_memory() / 1024 / 1024 / 1024);
  console::write_line();
  
  console::write_line("Virtual memory");
  console::write_line("  total = {,12} ({,3} GB)", memory_information::get_total_virtual_memory(), memory_information::get_total_virtual_memory() / 1024 / 1024 / 1024);
  console::write_line("  used  = {,12} ({,3} GB)", memory_information::get_used_virtual_memory(), memory_information::get_used_virtual_memory() / 1024 / 1024 / 1024);
  console::write_line("  free  = {,12} ({,3} GB)", memory_information::get_free_virtual_memory(), memory_information::get_free_virtual_memory() / 1024 / 1024 / 1024);
  console::write_line();
  
  console::write_line("Process memory");
  console::write_line("  total = {,12} ({,3} GB)", memory_information::get_total_process_memory(), memory_information::get_total_process_memory() / 1024 / 1024 / 1024);
  console::write_line("  used  = {,12} ({,3} MB)", memory_information::get_used_process_memory(), memory_information::get_used_process_memory() / 1024 / 1024);
  console::write_line("  free  = {,12} ({,3} GB)", memory_information::get_free_process_memory(), memory_information::get_free_process_memory() / 1024 / 1024 / 1024);
}

// This code can produce the following output :
//
// Physical memory
//   total =  34359738368 ( 32 GB)
//   used  =  18914050048 ( 17 GB)
//   free  =  15445688320 ( 14 GB)
//
// Virtual memory
//   total = 600992124928 (559 GB)
//   used  = 420945264640 (392 GB)
//   free  = 180046860288 (167 GB)
//
// Process memory
//   total = 180046860288 (167 GB)
//   used  =     40550400 ( 38 MB)
//   free  = 180006309888 (167 GB)
