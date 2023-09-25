#include "../../../include/xtd/io/drive_info"
#include "../../../include/xtd/io/io_exception"
#include "../../../include/xtd/argument_exception"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/drive>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace io;

const drive_info drive_info::empty;

drive_info::drive_info(const ustring& drive_name) : drive_name_(drive_name) {
  if (drive_name.empty()) throw argument_exception {csf_};
  auto drives = native::drive::get_drives();
  if (find(drives.begin(), drives.end(), drive_name) == drives.end()) throw argument_exception {csf_};
}

size_t drive_info::available_free_space() const {
  auto free_bytes = 0_sz, total_number_of_bytes =  0_sz, total_number_of_free_bytes = 0_sz;
  if (!native::drive::get_available_free_space(drive_name_, free_bytes, total_number_of_bytes, total_number_of_free_bytes)) throw io_exception {csf_};
  return free_bytes;
}

ustring drive_info::drive_format() const {
  auto volume_name = string {}, file_system_name = string {};
  if (!native::drive::get_volume_information(drive_name_, volume_name, file_system_name)) throw io_exception {csf_};
  return file_system_name;
}

drive_type drive_info::drive_type() const {
  auto drive_type = native::drive::get_drive_type(drive_name_);
  return static_cast<xtd::io::drive_type>(drive_type);
}

bool drive_info::is_ready() const noexcept {
  auto volume_name = string {}, file_system_name = string {};
  return native::drive::get_volume_information(drive_name_, volume_name, file_system_name);
}

ustring drive_info::name() const noexcept {
  return drive_name_;
}

directory_info drive_info::root_directory() const noexcept {
  return directory_info(drive_name_);
}

size_t drive_info::total_free_space() const {
  auto free_bytes = 0_sz, total_number_of_bytes = 0_sz, total_number_of_free_bytes = 0_sz;
  if (!native::drive::get_available_free_space(drive_name_, free_bytes, total_number_of_bytes, total_number_of_free_bytes)) throw io_exception {csf_};
  return total_number_of_free_bytes;
}

size_t drive_info::total_size() const {
  auto free_bytes = 0_sz, total_number_of_bytes =  0_sz, total_number_of_free_bytes = 0_sz;
  if (!native::drive::get_available_free_space(drive_name_, free_bytes, total_number_of_bytes, total_number_of_free_bytes)) throw io_exception {csf_};
  return total_number_of_bytes;
}

ustring drive_info::volume_label() const {
  auto volume_name = string {}, file_system_name = string {};
  if (!native::drive::get_volume_information(drive_name_, volume_name, file_system_name)) throw io_exception {csf_};
  return volume_name;
}

vector<drive_info> drive_info::get_drives() noexcept {
  auto drives = vector<drive_info> {};
  auto native_drives = native::drive::get_drives();
  for_each(native_drives.begin(), native_drives.end(), [&](auto drive) {drives.emplace_back(drive_info(drive));});
  return drives;
}

xtd::ustring drive_info::to_string() const noexcept {
  return drive_name_;
}
