#include "../../include/xtd/io/directory.hpp"
#include "../../include/xtd/io/path.hpp"
//#include "../../include/xtd/threading/thread_abort_exception"
#include "../../include/xtd/access_violation_exception.hpp"
#include "../../include/xtd/threading/thread.hpp"
#include "../../include/xtd/as.hpp"
#include "../../include/xtd/environment.hpp"
#include "../../include/xtd/argument_exception.hpp"
#include "../../include/xtd/arithmetic_exception.hpp"
#include "../../include/xtd/console.hpp"
#include "../../include/xtd/convert_string.hpp"
#include "../../include/xtd/interrupt_exception.hpp"
#include "../../include/xtd/invalid_operation_exception.hpp"
#include "../../include/xtd/software_termination_exception.hpp"
#include "../../include/xtd/unused.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <csignal>
#include <cstdlib>
#include <vector>

std::optional<xtd::toolkit> __xtd_toolkit__;

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

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::io;
using namespace xtd::threading;

namespace {
  auto __exit_code__ = 0;
}

class environment::signal_catcher {
public:
  signal_catcher() {
    std::atexit(signal_catcher::on_program_exit);
    /// Workaround std::quick_exit and std::at_quick_exit are not implemented on macOS !
    /// See https://github.com/runtimeverification/k/issues/1580 for more informtion
    native::environment::at_quick_exit(signal_catcher::on_program_quick_exit);
    std::signal(SIGABRT, signal_catcher::on_abnormal_termination_occured);
    std::signal(SIGFPE, signal_catcher::on_floating_point_exception_occured);
    std::signal(SIGILL, signal_catcher::on_illegal_instruction_occured);
    std::signal(SIGINT, signal_catcher::on_interrupt_occured);
    std::signal(SIGSEGV, signal_catcher::on_segmentation_violation_occured);
    std::signal(SIGTERM, signal_catcher::on_software_termination_occured);
  }
  
  ~signal_catcher() {
    std::signal(SIGABRT, SIG_DFL);
    std::signal(SIGFPE, SIG_DFL);
    std::signal(SIGILL, SIG_DFL);
    std::signal(SIGINT, SIG_DFL);
    std::signal(SIGSEGV, SIG_DFL);
    std::signal(SIGTERM, SIG_DFL);
  }
  
private:
  static void on_abnormal_termination_occured(int32 signal) {
    std::signal(signal, signal_catcher::on_abnormal_termination_occured);
    auto e = signal_cancel_event_args {xtd::signal::abnormal_termination};
    environment::on_cancel_signal(e);
    if (!e.cancel()) {
      console::__internal_rstc__(); // reset terminal mode
      environment::quick_exit(128 + last_signal_.value_or(signal)); //throw_helper::throws(exception_case::thread_abort);
    }
  }
  
  static void on_floating_point_exception_occured(int32 signal) {
    std::signal(signal, signal_catcher::on_floating_point_exception_occured);
    auto e = signal_cancel_event_args {xtd::signal::floating_point_exception};
    environment::on_cancel_signal(e);
    if (!e.cancel()) {
      last_signal_ = signal;
      console::__internal_rstc__(); // reset terminal mode
      throw_helper::throws(exception_case::arithmetic);
    }
  }
  
  static void on_illegal_instruction_occured(int32 signal) {
    std::signal(signal, signal_catcher::on_illegal_instruction_occured);
    auto e = signal_cancel_event_args {xtd::signal::illegal_instruction};
    environment::on_cancel_signal(e);
    if (!e.cancel()) {
      last_signal_ = signal;
      console::__internal_rstc__(); // reset terminal mode
      throw_helper::throws(exception_case::invalid_operation);
    }
  }
  
  static void on_interrupt_occured(int32 signal) {
    std::signal(signal, signal_catcher::on_interrupt_occured);
    auto se = signal_cancel_event_args {xtd::signal::interrupt};
    environment::on_cancel_signal(se);
    auto ce = console_cancel_event_args {console_special_key::control_c};
    ce.cancel(console::on_cancel_key_press(static_cast<int32>(console_special_key::control_c)));
    if (!se.cancel() && !ce.cancel()) {
      last_signal_ = signal;
      console::__internal_rstc__(); // reset terminal mode
      throw_helper::throws(exception_case::interrupt);
    }
  }
  
  static void on_program_exit() {
    environment::on_program_exit(program_exit_event_args {});
  }
  
  static void on_program_quick_exit() {
    environment::on_program_exit(program_exit_event_args {xtd::exit_mode::quick});
  }
  
  static void on_segmentation_violation_occured(int32 signal) {
    std::signal(signal, signal_catcher::on_segmentation_violation_occured);
    auto e = signal_cancel_event_args {xtd::signal::segmentation_violation};
    environment::on_cancel_signal(e);
    if (!e.cancel()) {
      last_signal_ = signal;
      console::__internal_rstc__(); // reset terminal mode
      throw_helper::throws(exception_case::access_violation); //exit(128 + signal);
    }
  }
  
  static void on_software_termination_occured(int32 signal) {
    std::signal(signal, signal_catcher::on_software_termination_occured);
    auto e = signal_cancel_event_args {xtd::signal::software_termination};
    environment::on_cancel_signal(e);
    if (!e.cancel()) {
      console::__internal_rstc__(); // reset terminal mode
      throw_helper::throws(exception_case::software_termination);
    }
  }
  
  inline static std::optional<int32> last_signal_;
};

event<environment, signal_cancel_event_handler> environment::cancel_signal;

event<environment, program_exit_event_handler> environment::program_exit;

environment::signal_catcher environment::signal_catcher_;

const string& environment::xtd_library::include_path() const noexcept {
  return include_path_;
}

const string& environment::xtd_library::library_path() const noexcept {
  return library_path_;
}

const string& environment::xtd_library::name() const noexcept {
  return name_;
}

const string& environment::xtd_library::resources_path() const noexcept {
  return resources_path_;
}

const xtd::version& environment::xtd_library::version() const noexcept {
  return version_;
}

string environment::xtd_library::to_string() const noexcept {
  return xtd::string::format("{} (version {})", name_, version_);
}

environment::xtd_library::xtd_library(const string& name, const xtd::version& version, const string& include_path, const string& library_path, const string& resources_path) : name_(name), version_(version), include_path_(include_path), library_path_(library_path), resources_path_(resources_path) {
}

xtd::string environment::command_line() noexcept {
  return xtd::string::join(" ", get_command_line_args());
}

string environment::current_directory() {
  return io::directory::get_current_directory();
}

void environment::current_directory(const string& directory_name) {
  io::directory::set_current_directory(directory_name);
}

int32 environment::current_managed_thread_id() noexcept {
  return threading::thread::current_thread().managed_thread_id();
}

intptr environment::current_thread_id() noexcept {
  return threading::thread::current_thread().thread_id();
}

int32 environment::exit_code() noexcept {
  return ::__exit_code__;
}

void environment::exit_code(int32 value) noexcept {
  ::__exit_code__ = value;
}

bool environment::has_shutdown_started() {
  return native::environment::has_shutdown_started();
}

bool environment::is_64_bit_operating_system() noexcept {
  return os_version().is_64_bit();
}

bool environment::is_64_bit_process() noexcept {
  return sizeof(size_t) == 8;
}

std::locale environment::locale() noexcept {
  return std::locale();
}

string environment::machine_name() {
  return native::environment::get_machine_name();
}

string environment::new_line() noexcept {
  return native::environment::new_line();
}

xtd::operating_system environment::os_version() noexcept {
  static auto to_version = [](std::function<void(int32&, int32&, int32&, int32& method)> method) {
    auto major = 0, minor = 0, build = -1, revision = -1;
    method(major, minor, build, revision);
    return build == -1 && revision == -1 ? xtd::version {major, minor} : revision == -1 ? xtd::version {major, minor, build} : xtd::version {major, minor, build, revision};
  };
  
  static xtd::operating_system os(xtd::platform_id::unknown, xtd::version());
  if (os.platform() == xtd::platform_id::unknown) {
    auto like_ids = native::environment::get_distribution_like_ids();
    os = operating_system(static_cast<platform_id>(native::environment::get_os_platform_id()), to_version(native::environment::get_os_version), native::environment::get_service_pack(), native::environment::get_desktop_environment(), native::environment::get_desktop_theme(), native::environment::is_os_64_bit(), xtd::distribution {native::environment::get_distribution_name(), to_version(native::environment::get_distribution_version), native::environment::get_distribution_code_name(), native::environment::get_distribution_description(), native::environment::get_distribution_id(), {like_ids.begin(), like_ids.end()}, native::environment::get_distribution_version_string(), xtd::uri {native::environment::get_distribution_home()}, xtd::uri {native::environment::get_distribution_bug_report()}});
  }
  return os;
}

uint32 environment::processor_count() {
  return processor_information().core_count();
}

xtd::processor environment::processor_information() {
  static auto processor = xtd::processor {xtd::architecture_id::unknown, false, 1};
  if (processor.architecture() == xtd::architecture_id::unknown)
    processor = xtd::processor(native::environment::is_processor_arm() ? architecture_id::arm : architecture_id::x86, native::environment::is_os_64_bit(), native::environment::get_processor_count());
  return processor;
}

xtd::string environment::stack_trace() {
  return xtd::diagnostics::stack_trace(true).to_string();
}

xtd::string environment::system_directory() {
  return get_folder_path(environment::special_folder::system);
}

size_t environment::system_page_size() {
  return native::environment::get_system_page_size();
}

std::chrono::milliseconds environment::tick_count() {
  return std::chrono::milliseconds(native::environment::get_tick_count());
}

toolkit environment::toolkit_version() {
  //return toolkit {drawing::native::toolkit::name(), drawing::native::toolkit::version()};
  return __xtd_toolkit__.value_or(toolkit {});
}

bool environment::user_administrator() {
  return native::environment::get_user_administrator();
}

string environment::user_domain_name() {
  return native::environment::get_user_domain_name();
}

bool environment::user_interactive() {
  return true;
}

string environment::user_name() {
  return native::environment::get_user_name();
}

int64 environment::working_set() {
  return native::environment::working_set();
}

const xtd::environment::xtd_library_collection& environment::xtd_libraries() noexcept {
  static auto libraries = xtd_library_collection {{"xtd.core", environment::version(), xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "include"), xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "lib"), environment::get_folder_path(environment::special_folder::xtd_resources)}, {"xtd.drawing", environment::version(), xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "include"), xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "lib"), environment::get_folder_path(environment::special_folder::xtd_resources)}, {"xtd.forms", environment::version(), xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "include"), xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "lib"), environment::get_folder_path(environment::special_folder::xtd_resources)}, {"xtd.tunit", environment::version(), xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "include"), xtd::io::path::combine(environment::get_folder_path(environment::special_folder::xtd_install), "lib"), environment::get_folder_path(environment::special_folder::xtd_resources)},};
  return libraries;
}

void environment::abort() {
  raise(xtd::signal::abnormal_termination);
}

void environment::exit() {
  exit(exit_code());
}

void environment::exit(int32 exit_code) {
  std::exit(exit_code);
}

void environment::exit(xtd::exit_status exit_status) {
  exit(enum_object<>::to_int32(exit_status));
}

xtd::string environment::expand_environment_variables(const xtd::string& name) {
  auto buffer = name;
  auto result = xtd::string::empty_string;
  
  auto index = buffer.index_of('%');
  while (index != xtd::string::npos && buffer.index_of('%', index + 1) != xtd::string::npos) {
    result += buffer.substring(0, index);
    buffer = buffer.remove(0, index + 1);
    index = buffer.index_of('%');
    if (get_environment_variable(buffer.substring(0, index)) != "") result += get_environment_variable(buffer.substring(0, index));
    else result += xtd::string::format("%{0}%", buffer.substring(0, index));
    buffer = buffer.remove(0, index + 1);
    index = buffer.index_of('%');
  }
  result += buffer;
  return result;
}

xtd::argument_collection environment::get_command_line_args() {
  auto args = native::environment::get_command_line_args();
  return {args.begin(), args.end()};
}

xtd::string environment::get_environment_variable(const xtd::string& variable) {
  return get_environment_variable(variable, environment_variable_target::process);
}

string environment::get_environment_variable(const string& variable, environment_variable_target target) {
  if (!enum_object<>::is_defined<environment_variable_target>(target)) throw_helper::throws(exception_case::argument, "Invalid environment variable target value");
  return native::environment::get_environment_variable(variable, as<int32>(target));
}

std::map<std::string, std::string>& environment::get_environment_variables() {
  return get_environment_variables(environment_variable_target::process);
}

std::map<std::string, std::string>& environment::get_environment_variables(environment_variable_target target) {
  if (!enum_object<>::is_defined<environment_variable_target>(target)) throw_helper::throws(exception_case::argument, "Invalid environment variable target value");
  return native::environment::get_environment_variables(as<int32>(target));
}

xtd::collections::specialized::string_collection environment::get_logical_drives() {
  return io::directory::get_logical_drives();
}

void environment::quick_exit() noexcept {
  quick_exit(exit_code());
}

void environment::quick_exit(int32 exit_code) noexcept {
  /// Workaround std::quick_exit and std::at_quick_exit are not implemented on macOS !
  /// See https://github.com/runtimeverification/k/issues/1580 for more informtion
  native::environment::quick_exit(exit_code);
}

void environment::quick_exit(xtd::exit_status exit_status) noexcept {
  quick_exit(enum_object<>::to_int32(exit_status));
}

void environment::raise(xtd::signal signal) {
  std::raise(enum_object<>::to_int32(signal));
}

void environment::set_environment_variable(const xtd::string& variable, const xtd::string& value) {
  set_environment_variable(variable, value, environment_variable_target::process);
}

void environment::set_environment_variable(const string& variable, const string& value, environment_variable_target target) {
  if (string::is_empty(variable)) throw_helper::throws(exception_case::argument, "Environment variable name is empty");
  
  if (!enum_object<>::is_defined<environment_variable_target>(target)) throw_helper::throws(exception_case::argument, "Invalid environment variable target value");
  
  if (string::is_empty(value)) {
    native::environment::get_environment_variables(as<int32>(target)).erase(variable);
    native::environment::unset_environment_variable(variable, as<int32>(target));
  } else {
    native::environment::get_environment_variables(as<int32>(target))[variable] = value;
    native::environment::set_environment_variable(variable, value, as<int32>(target));
  }
}

void environment::__signal_catcher_check__() {
  unused_(signal_catcher_);
}

void environment::on_cancel_signal(signal_cancel_event_args& e) {
  auto safe_cancel_signal = cancel_signal;
  if (!safe_cancel_signal.is_empty()) safe_cancel_signal(e);
}

void environment::on_program_exit(const program_exit_event_args& e) {
  auto safe_program_exit = program_exit;
  if (!safe_program_exit.is_empty()) safe_program_exit(e);
}

string environment::get_folder_path_(environment::special_folder folder, environment::special_folder_option option, bool is_gui_application) {
  switch (folder) {
    case environment::special_folder::application_resources: return path::get_full_path(native::environment::get_resources_path(is_gui_application));
    case environment::special_folder::xtd_install: return xtd_root_path();
    case environment::special_folder::xtd_locale: return path::combine(xtd_root_path(), "share", "xtd", "locale");
    case environment::special_folder::xtd_reference_guide: return path::combine(xtd_root_path(), "share", "xtd", "reference_guide");
    case environment::special_folder::xtd_themes: return path::combine(xtd_root_path(), "share", "xtd", "themes");
    case environment::special_folder::xtd_include: return path::combine(xtd_root_path(), "include");
    case environment::special_folder::xtd_libraries: return path::combine(xtd_root_path(), "lib");
    case environment::special_folder::xtd_resources: return path::combine(xtd_root_path(), "share", "xtd", "resources");
    case environment::special_folder::xtd_console_include: return path::combine(xtd_root_path(), "include");
    case environment::special_folder::xtd_console_libraries: return path::combine(xtd_root_path(), "lib");
    case environment::special_folder::xtd_drawing_include: return path::combine(xtd_root_path(), "include");
    case environment::special_folder::xtd_drawing_libraries: return path::combine(xtd_root_path(), "lib");
    case environment::special_folder::xtd_drawing_resources: return path::combine(xtd_root_path(), "share", "xtd", "resources");
    case environment::special_folder::xtd_forms_include: return path::combine(xtd_root_path(), "include");
    case environment::special_folder::xtd_forms_libraries: return path::combine(xtd_root_path(), "lib");
    case environment::special_folder::xtd_forms_resources: return path::combine(xtd_root_path(), "share", "xtd", "resources");
    case environment::special_folder::xtd_tunit_include: return path::combine(xtd_root_path(), "include");
    case environment::special_folder::xtd_tunit_libraries: return path::combine(xtd_root_path(), "lib");
    default: break;
  }
  
  auto path = native::environment::get_know_folder_path(static_cast<int32>(folder));
  if (xtd::string::is_empty(path)) return path;
  if (option == environment::special_folder_option::none) return !xtd::io::directory::exists(path) ? "" :  path;
  if (option == environment::special_folder_option::create && !xtd::io::directory::exists(path)) xtd::io::directory::create_directory(path);
  return path;
}
