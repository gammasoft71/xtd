#include "../../include/xtd/as.h"
#include "../../include/xtd/environment.h"
#include "../../include/xtd/argument_exception.h"
#include "../../include/xtd/convert_string.h"
#include "../../include/xtd/io/directory.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <vector>

// Workaround : Add "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin" to PATH if needed on macOS when debugging on Xcode...
struct __update__macos_path__ {
  __update__macos_path__() {
    if (!xtd::environment::os_version().is_macos_platform()) return;
    /// @todo fix PATH with foreach...
    //for (auto path : {"/usr/local/bin", "/usr/bin", "/bin", "/usr/sbin", "/sbin", "/Library/Apple/usr/bin"})
    //  if (!xtd::environment::get_environment_variable("PATH"), path).contains() xtd::environment::set_environment_variable("PATH", path+xtd::environment::get_environment_variable("PATH"));
    xtd::environment::set_environment_variable("PATH", "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin" + xtd::environment::get_environment_variable("PATH"));
  }
} __updmacpath__;

using namespace std;
using namespace xtd;
using namespace xtd::io;

namespace {
  int32_t exit_code = 0;
}

xtd::ustring environment::command_line() noexcept {
  return xtd::ustring::join(" ", get_command_line_args());
}

ustring environment::current_directory() {
  return io::directory::get_current_directory();
}

void environment::current_directory(const ustring& directory_name) {
  io::directory::set_current_directory(directory_name);
}

std::thread::id environment::current_thread_id() noexcept {
  return std::this_thread::get_id();
}

int32_t environment::exit_code() noexcept {
  return ::exit_code;
}

void environment::exit_code(int32_t value) noexcept {
  ::exit_code = value;
}

bool environment::has_shutdown_started() {
  return native::environment::has_shutdown_started();
}

xtd::collections::specialized::string_vector environment::get_command_line_args() {
  auto args = native::environment::get_command_line_args();
  return {args.begin(), args.end()};
}

ustring environment::get_environment_variable(const ustring& variable, environment_variable_target target) {
  if (!enum_object<>::is_defined<environment_variable_target>(target)) throw xtd::argument_exception("Invalid environment variable target value"_t, csf_);
  return native::environment::get_environment_variable(variable, as<int32_t>(target));
}

map<string, string>& environment::get_environment_variables(environment_variable_target target) {
  if (!enum_object<>::is_defined<environment_variable_target>(target)) throw xtd::argument_exception("Invalid environment variable target value"_t, csf_);
  return native::environment::get_environment_variables(as<int32_t>(target));
}

ustring environment::get_folder_path(environment::special_folder folder, environment::special_folder_option option) {
  switch (folder) {
    case environment::special_folder::xtd_install: return __XTD_INSTALL_PATH__;
    case environment::special_folder::xtd_locale: return __XTD_LOCALE_PATH__; break;
    case environment::special_folder::xtd_reference_guide: return __XTD_REFERENCE_GUIDE_PATH__;
    case environment::special_folder::xtd_themes: return __XTD_THEMES_PATH__;
    case environment::special_folder::xtd_include: return environment::xtd_include_path;
    case environment::special_folder::xtd_libraries: return environment::xtd_libraries_path;
    case environment::special_folder::xtd_resources: return environment::xtd_resources_path;
    case environment::special_folder::xtd_console_include: return environment::xtd_console_include_path;
    case environment::special_folder::xtd_console_libraries: return environment::xtd_console_libraries_path;
    case environment::special_folder::xtd_drawing_include: return environment::xtd_drawing_include_path;
    case environment::special_folder::xtd_drawing_libraries: return environment::xtd_drawing_libraries_path;
    case environment::special_folder::xtd_drawing_resources: return environment::xtd_drawing_resources_path;
    case environment::special_folder::xtd_forms_include: return environment::xtd_forms_include_path;
    case environment::special_folder::xtd_forms_libraries: return environment::xtd_forms_libraries_path;
    case environment::special_folder::xtd_forms_resources: return environment::xtd_forms_resources_path;
    case environment::special_folder::xtd_tunit_include: return environment::xtd_tunit_include_path;
    case environment::special_folder::xtd_tunit_libraries: return environment::xtd_tunit_libraries_path;
    default: break;
  }
    
  ustring path = native::environment::get_know_folder_path(static_cast<int32_t>(folder));
  if (path.empty()) return path;
  if (option == environment::special_folder_option::none) return !xtd::io::directory::exists(path) ? "" :  path;
  if (!xtd::io::directory::exists(path)) xtd::io::directory::create_directory(path);
  return path;
}

bool environment::is_64_bit_operating_system() noexcept {
  return os_version().is_64_bit();
}

bool environment::is_64_bit_process() noexcept {
  return sizeof(size_t) == 8;
}

ustring environment::machine_name() {
  return native::environment::get_machine_name();
}

ustring environment::new_line() noexcept {
  return native::environment::new_line();
}

xtd::operating_system environment::os_version() noexcept {
  static xtd::operating_system os(xtd::platform_id::unknown, xtd::version());
  if (os.platform() == xtd::platform_id::unknown) {
    int32_t major, minor, build, revision;
    native::environment::get_os_version(major, minor, build, revision);
    xtd::version version;
    version = xtd::version(major, minor, build, revision);
    os = operating_system(static_cast<platform_id>(native::environment::get_os_platform_id()), version, native::environment::get_service_pack(), native::environment::get_desktop_environment(), native::environment::get_desktop_theme(), native::environment::is_os_64_bit());
  }
  return os;
}

uint32_t environment::processor_count() {
  return processor_information().core_count();
}

xtd::processor environment::processor_information() {
  static xtd::processor proc(xtd::architecture_id::unknown, false, 1);
  if (proc.architecture() == xtd::architecture_id::unknown)
    proc = xtd::processor(native::environment::is_processor_arm() ? architecture_id::arm : architecture_id::x86, native::environment::is_os_64_bit(), native::environment::get_processor_count());
  return proc;
}

void environment::set_environment_variable(const ustring& variable, const ustring& value, environment_variable_target target) {
  if (ustring::is_empty(variable)) throw xtd::argument_exception("Environment variable name is empty"_t, csf_);

  if (!enum_object<>::is_defined<environment_variable_target>(target)) throw xtd::argument_exception("Invalid environment variable target value"_t, csf_);
  
  if (ustring::is_empty(value)) {
    native::environment::get_environment_variables(as<int32_t>(target)).erase(variable);
    native::environment::unset_environment_variable(variable, as<int32_t>(target));
  } else {
    native::environment::get_environment_variables(as<int32_t>(target))[variable] = value;
    native::environment::set_environment_variable(variable, value, as<int32_t>(target));
  }
}

xtd::ustring environment::stack_trace() {
  return xtd::diagnostics::stack_trace().to_string();
}

xtd::ustring environment::system_directory() {
  return get_folder_path(environment::special_folder::system);
}

size_t environment::system_page_size() {
  return native::environment::get_system_page_size();
}

std::chrono::milliseconds environment::tick_count() {
  return std::chrono::milliseconds(native::environment::get_tick_count());
}

bool environment::user_administrator() {
  return native::environment::get_user_administrator();
}

ustring environment::user_domain_name() {
  return native::environment::get_user_domain_name();
}

bool environment::user_interactive() {
  return true;
}

ustring environment::user_name() {
  return native::environment::get_user_name();
}

int64_t environment::working_set() {
  return native::environment::working_set();
}

void environment::exit(int32_t exit_code) {
  _Exit(exit_code);
}

xtd::ustring environment::expand_environment_variables(const xtd::ustring& name) {
  xtd::ustring buffer = name;
  xtd::ustring result;
  
  size_t index = buffer.index_of('%');
  while (index != xtd::ustring::npos && buffer.index_of('%', index + 1) != xtd::ustring::npos) {
    result += buffer.substring(0, index);
    buffer = buffer.remove(0, index + 1);
    index = buffer.index_of('%');
    if (get_environment_variable(buffer.substring(0, index)) != "")
      result += get_environment_variable(buffer.substring(0, index));
    else
      result += xtd::ustring::format("%{0}%", buffer.substring(0, index));
    buffer = buffer.remove(0, index + 1);
    index = buffer.index_of('%');
  }
  result += buffer;
  return result;
}

xtd::ustring environment::get_environment_variable(const xtd::ustring& variable) {
  return get_environment_variable(variable, environment_variable_target::process);
}

std::map<std::string, std::string>& environment::get_environment_variables() {
  return get_environment_variables(environment_variable_target::process);
}

xtd::ustring environment::get_folder_path(environment::special_folder folder) {
  return get_folder_path(folder, environment::special_folder_option::none);
}

xtd::collections::specialized::string_vector environment::get_logical_drives() {
  return io::directory::get_logical_drives();
}

void environment::set_environment_variable(const xtd::ustring& variable, const xtd::ustring& value) {
  set_environment_variable(variable, value, environment_variable_target::process);
}
