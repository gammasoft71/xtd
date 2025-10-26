/// @todo Remove following includes when xtd::diagnostics::process will used for restart see below..
#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/exception_box.hpp"
#include "../../../include/xtd/forms/message_box.hpp"
#include "../../../include/xtd/forms/trace_form_base.hpp"
#include <xtd/diagnostics/assert>
#include <xtd/diagnostics/debugger>
#include <xtd/diagnostics/process>
#include <xtd/diagnostics/stopwatch>
#include <xtd/io/directory>
#include <xtd/io/path>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application>
#include <xtd/forms/native/toolkit>
#include <xtd/forms/native/window_definitions>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/threading/thread>
#include <xtd/reflection/assembly>
#include <xtd/environment>
#include <xtd/invalid_operation_exception>
#include <xtd/globalization/translator>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;
using namespace xtd::helpers;
using namespace xtd::reflection;
using namespace xtd::threading;

extern std::optional<xtd::toolkit> __xtd_toolkit__;

auto application::__opaque_crt_prv_msg__(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr result, intptr handle) noexcept {
  return xtd::forms::message(hwnd, msg, wparam, lparam, result, handle);
}

// Initialize xtd::diagnostics::process::message_box_message_ delegate th show message_box dialog.
// This operation can be done only if xtd.forms lib is present.
struct __init_process_message_box_message__ {
  __init_process_message_box_message__() {
    xtd::diagnostics::process::message_box_message_ = {*this, &__init_process_message_box_message__::__show_message_box__};
  }
  
  void __show_message_box__(const string& file_name) {
    xtd::forms::message_box::show(string::format("{} cannot find '{}'. Make sure you typed the name correctly, and try again.", xtd::environment::os_version().name(), file_name), file_name, xtd::forms::message_box_buttons::ok, xtd::forms::message_box_icon::error);
  }
  
  void __force_compiler_optimizer_to_create_object__() {
  }
};

__init_process_message_box_message__ __init_process_message_box_message_value__;

struct __init_toolkit__ {
  __init_toolkit__() {
    __xtd_toolkit__ = toolkit {native::toolkit::name(), native::toolkit::version(), native::toolkit::description()};
  }
};

__init_toolkit__ __init_toolkit_value__;

namespace {
  using message_filter_ref = ref<imessage_filter>;
  using message_filter_collection = std::vector<message_filter_ref>;
  
  static message_filter_collection message_filters;
  
  bool message_filter_proc(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr handle) {
    auto current_control = control::from_handle(hwnd);
    if (current_control.has_value() && (current_control.value().get().name() == __xtd_forms_trace_form_base_default_form_name__() || current_control.value().get().name() == __xtd_forms_trace_form_base_default_text_box_name__())) return false;
    
    for (auto message_filter : message_filters)
      if (message_filter.get().pre_filter_message(application::__opaque_crt_prv_msg__(hwnd, msg, wparam, lparam, 0, handle))) return true;
      
    for (auto open_form : application::open_forms())
      if (open_form.get().pre_process_message(application::__opaque_crt_prv_msg__(hwnd, msg, wparam, lparam, 0, handle))) return true;
      
    return false;
  }
}

xtd::forms::application_context application::internal_context_;
xtd::forms::application_context* application::context_ = &application::internal_context_;
bool application::button_images_ = true;
#if defined(__XTD_KEEP_CLONED_CONTROLS__)
bool application::keep_cloned_controls_ = true;
#else
bool application::keep_cloned_controls_ = false;
#endif
bool application::font_size_correction_ = true;
bool application::light_mode_ = false;
bool application::menu_images_ = true;
bool application::message_loop_ = false;
bool application::raise_idle_ = false;
#if defined(__XTD_USE_SYSTEM_CONTROLS__)
bool application::system_controls_ = true;
#else
bool application::system_controls_ = false;
#endif
bool application::system_font_size_ = false;
bool application::use_wait_cursor_ = false;
bool application::visual_styles_ = false;

event<application, event_handler> application::application_exit;
event<application, event_handler> application::enter_thread_modal;
event<application, event_handler> application::idle;
event<application, event_handler> application::leave_thread_modal;
event<application, threading::thread_exception_event_handler> application::thread_exception;
event<application, event_handler> application::thread_exit;

bool application::allow_quit() noexcept {
  try {
    return native::application::allow_quit();
  } catch (...) {
    return true;
  }
}

xtd::forms::application_context& application::application_context() {
  return *context_;
}

bool application::button_images() noexcept {
  return button_images_;
}

void application::button_images(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call xtd::application::button_images() before application::run()");
  if (button_images_ == value) return;
  button_images_ = value;
  native::application::enable_button_images(value);
}

xtd::string application::common_app_data_path() noexcept {
  auto common_app_data_path = io::path::combine({environment::get_folder_path(environment::special_folder::common_application_data), company_name(), product_name(), product_version()});
  try {
    if (!io::directory::exists(common_app_data_path))
      io::directory::create_directory(common_app_data_path);
  } catch (...) {
    assert_(io::directory::exists(common_app_data_path), string::format("The {} path does not exist.", common_app_data_path));
  }
  return common_app_data_path;
}

/*
microsoft::win32::registry_key application::common_app_data_registry() {
  return microsoft::win32::registry::local_machine().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
}
 */

xtd::string application::company_name() noexcept {
  try {
    if (assembly::get_executing_assembly().company() == "") return xtd::io::path::get_file_name_without_extension(executable_path());
    return assembly::get_executing_assembly().company();
  } catch (...) {
    return assembly::get_executing_assembly().company();
  }
}

bool application::dark_mode() noexcept {
  try {
    return native::application::dark_mode_enabled();
  } catch (...) {
    return false;
  }
}

void application::dark_mode(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call xtd::application::light_mode() before application::run()");
  if (dark_mode() == value) return;
  native::application::enable_dark_mode(value);
}

xtd::string application::executable_name() noexcept {
  return io::path::get_file_name(application::executable_path());
}

xtd::string application::executable_path() noexcept {
  return assembly::get_executing_assembly().location();
}

bool application::font_size_correction() {
  return font_size_correction_;
}

void application::font_size_correction(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call application::font_size_correction() before application::run()");
  if (font_size_correction_ == value) return;
  font_size_correction_ = value;
  native::application::enable_font_size_correction(value);
}

bool application::keep_cloned_controls() noexcept {
  return keep_cloned_controls_;
}

void application::keep_cloned_controls(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call xtd::keep_cloned_controls::button_images() before application::run()");
  keep_cloned_controls_ = value;
}

bool application::light_mode() noexcept {
  return !dark_mode();
}

void application::light_mode(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call xtd::application::light_mode() before application::run()");
  if (light_mode() == value) return;
  native::application::enable_light_mode(value);
}

bool application::dark_mode_enabled() noexcept {
  return dark_mode();
}

bool application::light_mode_enabled() noexcept {
  return light_mode();
}

std::optional<form_ref> application::main_form() {
  if (application_context().main_form().has_value()) return application_context().main_form();
  return {};
}

bool application::menu_images() noexcept {
  return menu_images_;
}

void application::menu_images(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call xtd::application::menu_images() before application::run()");
  if (menu_images_ == value) return;
  menu_images_ = value;
  native::application::enable_menu_images(value);
}

bool application::message_loop() noexcept {
  return  message_loop_;
}

const form_collection application::open_forms() noexcept {
  auto forms = form_collection {};
  for (auto control : control::top_level_controls_)
    forms.push_back(dynamic_cast<form&>(control.get()));
  return forms;
  
  /*
  auto forms = form_collection {};
  for (intptr handle : native::application::open_forms()) {
    control& control = control::from_handle(handle);
    forms.push_back(static_cast<form&>(control));
  }
  return forms;
   */
}

xtd::string application::product_name() noexcept {
  if (assembly::get_executing_assembly().product() == "") return xtd::io::path::get_file_name_without_extension(executable_path());
  return assembly::get_executing_assembly().product();
}

xtd::string application::product_version() noexcept {
  if (assembly::get_executing_assembly().version() == "") return string("0.0.0");
  return assembly::get_executing_assembly().version();
}

xtd::string application::startup_path() noexcept {
  return assembly::get_executing_assembly().location_path();
}

const xtd::forms::style_sheets::style_sheet& application::style_sheet() noexcept {
  return style_sheets::style_sheet::current_style_sheet();
}

void application::style_sheet(const xtd::forms::style_sheets::style_sheet& value) {
  style_sheets::style_sheet::current_style_sheet(value);
}

const xtd::forms::style_sheets::style_sheet::style_sheets_t& application::style_sheets() noexcept {
  return xtd::forms::style_sheets::style_sheet::style_sheets();
}

const xtd::forms::style_sheets::style_sheet::style_sheet_names_t& application::style_sheet_names() noexcept {
  return xtd::forms::style_sheets::style_sheet::style_sheet_names();
}

bool application::system_controls() noexcept {
  return system_controls_;
}

void application::system_controls(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call application::system_controls() before application::run()");
  system_controls_ = value;
}

bool application::system_font_size() noexcept {
  return system_font_size_;
}

void application::system_font_size(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call application::system_font_size() before application::run()");
  if (system_font_size_ == value) return;
  system_font_size_ = value;
  native::application::enable_system_font_size(value);
}

const xtd::forms::style_sheets::style_sheet& application::system_style_sheet() noexcept {
  return xtd::forms::style_sheets::style_sheet::system_style_sheet();
}

xtd::string application::user_app_data_path() noexcept {
  auto user_app_data_path = io::path::combine({environment::get_folder_path(environment::special_folder::application_data), company_name(), product_name(), product_version()});
  try {
    if (!io::directory::exists(user_app_data_path))
      io::directory::create_directory(user_app_data_path);
  } catch (...) {
    assert_(io::directory::exists(user_app_data_path), string::format("The {} path does not exist.", user_app_data_path));
  }
  return user_app_data_path;
}

/*
 microsoft::win32::registry_key application::user_app_data_registry() {
   return microsoft::win32::registry::current_user().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
 }
 */

bool application::use_visual_styles() noexcept {
  return visual_styles();
}

bool application::use_wait_cursor() noexcept {
  return use_wait_cursor_;
}

void application::use_wait_cursor(bool use_wait_cursor) {
  if (use_wait_cursor_ == use_wait_cursor) return;
  use_wait_cursor_ = use_wait_cursor;
  native::application::use_wait_cursor(use_wait_cursor_);
}

bool application::visual_styles() noexcept {
  return visual_styles_;
}

void application::visual_styles(bool value) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Call application::visual_styles() before application::run()");
  if (visual_styles_ == value) return;
  visual_styles_ = true;
  native::application::enable_visual_style(value);
}

void application::add_message_filter(const imessage_filter& value) {
  message_filters.push_back(const_cast<imessage_filter&>(value));
}

void application::do_events() {
  native::application::do_events();
}

void application::enable_button_images() {
  button_images(true);
}

void application::enable_dark_mode() {
  dark_mode(true);
}

void application::enable_light_mode() {
  light_mode(true);
}

void application::enable_menu_images() {
  menu_images(true);
}

void application::enable_visual_styles() {
  visual_styles(true);
}

void application::exit() {
  auto e = cancel_event_args {};
  application::exit(e);
}

void application::exit(cancel_event_args& e) {
  e.cancel(!close_open_forms());
  if (!e.cancel()) native::application::exit();
}

void application::exit_thread() {
  native::application::exit();
}

xtd::forms::style_sheets::style_sheet application::get_style_sheet_from_name(const xtd::string& name) {
  return xtd::forms::style_sheets::style_sheet::get_style_sheet_from_name(name);
}

void application::raise_idle(const event_args& e) {
  raise_idle_ = true;
  auto message = forms::message::create(0, WM_APPIDLE, 0, 0);
  wm_app_idle(message);
}

void application::register_message_loop_callback(message_loop_callback callback) {
}

void application::remove_message_filter(const imessage_filter& value) {
  for (auto iterator = message_filters.begin(); iterator != message_filters.end(); ++iterator) {
    if (&iterator->get() == &value) {
      message_filters.erase(iterator);
      break;
    }
  }
}

void application::restart() {
  native::application::restart(close_open_forms());
}

void application::run() {
  __init_process_message_box_message_value__.__force_compiler_optimizer_to_create_object__();
  application::run(internal_context_);
}

void application::run(xtd::forms::application_context& context) {
  if (application::application::message_loop_ == true) throw_helper::throws(exception_case::invalid_operation, "Application already running");
  if (control::check_for_illegal_cross_thread_calls() && !thread::current_thread().is_main_thread()) throw_helper::throws(exception_case::invalid_operation, xtd::string::format("Cross-thread operation not valid: {}", typeof_<application>().full_name()).chars().c_str());
  
  context_ = &context;
  context.thread_exit += application::on_app_thread_exit;
  native::application::register_message_filter(delegate<bool(intptr, int32, intptr, intptr, intptr)>(message_filter_proc));
  native::application::register_thread_exception(delegate<bool()>(on_app_thread_exception));
  native::application::register_wnd_proc(delegate<intptr(intptr, int32, intptr, intptr, intptr)>(application::wnd_proc_));
  
  application::message_loop_ = true;
  if (context.main_form().has_value()) context.main_form().value().get().show();
  native::application::run();
  context.thread_exit -= application::on_app_thread_exit;
  application::message_loop_ = false;
  internal_context_.main_form(nullptr);
  native::application::cleanup();
}

void application::run(const form& form) {
  internal_context_.main_form(form);
  application::run(internal_context_);
}

bool application::close_open_forms() {
  for (auto open_form : application::open_forms()) {
    auto closing_args = form_closing_event_args {};
    open_form.get().on_form_closing(closing_args);
    if (closing_args.cancel()) return false;
  }
  
  for (auto open_form : application::open_forms())
    open_form.get().on_form_closed(form_closed_event_args {});
    
  return true;
}

void application::on_app_thread_exit(object& sender, const event_args& e) {
  application::exit_thread();
}

bool application::on_app_thread_exception() {
  try {
    throw;
  } catch (const std::exception& e) {
    return on_thread_exception({e});
  } catch (...) {
    return on_thread_exception({invalid_operation_exception {}});
  }
}

bool application::on_thread_exception(const threading::thread_exception_event_args& e) {
  auto safe_thread_exception = thread_exception;
  if (safe_thread_exception.is_empty()) return (main_form().has_value() ? exception_box::show(main_form().value().get(), e.exception(), product_name()) : exception_box::show(e.exception(), product_name())) == dialog_result::ok;
  auto obj = object {};
  safe_thread_exception(obj, e);
  return true;
}

void application::raise_enter_thread_modal(const event_args& e) {
  auto obj = object {};
  application::enter_thread_modal(obj, e);
}

void application::raise_leave_thread_modal(const event_args& e) {
  auto obj = object {};
  application::leave_thread_modal(obj, e);
}

intptr application::wnd_proc_(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr handle) {
  auto message = forms::message {hwnd, msg, wparam, lparam, 0, handle};
  wnd_proc(message);
  return message.result;
}

void application::wnd_proc(message& message) {
  switch (message.msg) {
    case WM_ACTIVATEAPP: wm_activate_app(message); break;
    case WM_APPIDLE: wm_app_idle(message); break;
    case WM_QUIT: wm_quit(message); break;
    default: break;
  }
}

void application::wm_activate_app(message& message) {
  for (auto form : open_forms())
    form.get().send_message(form.get().handle(), message.msg, message.wparam, message.lparam);
}

void application::wm_app_idle(message& message) {
  static auto sw = stopwatch::start_new();
  static auto obj = object {};
  if (raise_idle_ || sw.elapsed_milliseconds() >= 100) {
    sw = stopwatch::start_new();
    idle(obj, event_args::empty);
    raise_idle_ = false;
  }
  if (!idle.is_empty()) native::application::do_idle();
  
  for (auto form : open_forms())
    form.get().wnd_proc(message);
}

void application::wm_quit(message& message) {
  auto obj = object {};
  thread_exit(obj, event_args::empty);
  application_exit(obj, event_args::empty);
}
