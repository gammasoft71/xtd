#include <chrono>
#include <xtd/io/path.h>
#include <xtd/environment.h>
#include <xtd/xtd.diagnostics>
#include <xtd/forms/native/application.h>
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/theme.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace {
  using message_filter_ref = std::reference_wrapper<imessage_filter>;
  using message_filter_collection = std::vector<message_filter_ref>;
  
  static message_filter_collection message_filters;
  
  bool message_filter_proc(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
    bool block = false;
  
    for (message_filter_ref message_filter : message_filters) {
      block = message_filter.get().pre_filter_message(xtd::forms::message::create(hwnd, msg, wparam, lparam, 0, handle));
      if (block == true) break;
    }
    
    return block;
  }
}

bool application::use_visual_styles_ = false;
bool application::use_wait_cursor_ = false;
bool application::message_loop_ = false;

event<application, delegate<void(const event_args&)>> application::application_exit;
event<application, delegate<void(const event_args&)>> application::enter_thread_modal;
event<application, delegate<void(const event_args&)>> application::idle;
event<application, delegate<void(const event_args&)>> application::leave_thread_modal;
//event<threading::thread_exception_event_handler> application::thread_exception;
event<application, delegate<void(const event_args&)>> application::thread_exit;

bool application::allow_quit() {
  return native::application::allow_quit();
}

std::string application::common_app_data_path() {
  std::string common_app_data_path = io::path::combine({environment::get_folder_path(environment::special_folder::common_application_data), company_name(), product_name(), product_version()});
  //if (!io::directory::exists(common_app_data_path))
  //  io::directory::create_directory(common_app_data_path);
  return common_app_data_path;
}

/*
microsoft::win32::registry_key application::common_app_data_registry() {
  return microsoft::win32::registry::local_machine().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
}
 */

std::string application::company_name() {
  if (!strings::is_empty(application_informations::company_name())) return application_informations::company_name();
  return product_name();
}

std::string application::executable_name() {
  return io::path::get_file_name(application::executable_path());
}

std::string application::executable_path() {
  return environment::get_command_line_args()[0];
}

bool application::message_loop() {
  return  message_loop_;
}

const form_collection application::open_forms() {
  form_collection forms;
  for (auto control : control::top_level_controls_)
    forms.push_back(static_cast<form&>(control.get()));
  return forms;

  /*
  vector<reference_wrapper<form>> forms;
  
  for (intptr_t handle : native::application::open_forms()) {
    control& control = control::from_handle(handle);
    forms.push_back(static_cast<form&>(control));
  }
  return forms;
   */
}

std::string application::product_name() {
  if (!strings::is_empty(application_informations::product_name())) return application_informations::product_name();
  return io::path::get_file_name_without_extension(executable_path());
}

std::string application::product_version() {
  if (!strings::is_empty(application_informations::product_version())) return application_informations::product_version();
  return "0.0.0.0";
}

std::string application::startup_path() {
  return io::path::get_directory_name(environment::get_command_line_args()[0]);
}

std::string application::user_app_data_path() {
  std::string user_app_data_path = io::path::combine({environment::get_folder_path(environment::special_folder::application_data), company_name(), product_name(), product_version()});
  //if (!io::directory::exists(user_app_data_path))
  //  io::directory::create_directory(user_app_data_path);
  return user_app_data_path;
}

/*
 microsoft::win32::registry_key application::user_app_data_registry() {
   return microsoft::win32::registry::current_user().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
 }
 */

bool application::use_visual_styles() {
  return use_visual_styles_;
}

bool application::use_wait_cursor() {
  return use_wait_cursor_;
}

void application::use_wait_cursor(bool use_wait_cursor) {
  if (use_wait_cursor_ != use_wait_cursor) {
    use_wait_cursor_ = use_wait_cursor;
    native::application::use_wait_cursor(use_wait_cursor_);
  }
}

void application::add_message_filter(const imessage_filter& value) {
  message_filters.push_back(const_cast<imessage_filter&>(value));
}

void application::cleanup() {
  native::application::cleanup();
}

void application::do_events() {
  native::application::do_events();
}

bool application::dark_mode_enabled() {
  return native::application::dark_mode_enabled();
}

bool application::light_mode_enabled() {
  return !dark_mode_enabled();
}

void application::enable_dark_mode() {
  if (application::application::message_loop_ == true) throw std::runtime_error("Call applicaiton::enable_dark_mode() before application::run()");
  native::application::enable_dark_mode();
}

void application::enable_button_images() {
  if (application::application::message_loop_ == true) throw std::runtime_error("Call applicaiton::enable_button_images() before application::run()");
  native::application::enable_button_images();
}

void application::enable_light_mode() {
  if (application::application::message_loop_ == true) throw std::runtime_error("Call applicaiton::enable_light_mode() before application::run()");
  native::application::enable_light_mode();
}

void application::enable_menu_images() {
  if (application::application::message_loop_ == true) throw std::runtime_error("Call applicaiton::enable_menu_images() before application::run()");
  native::application::enable_menu_images();
}

void application::enable_visual_styles() {
  if (application::application::message_loop_ == true) throw std::runtime_error("Call applicaiton::enable_visual_styles() before application::run()");
  application::use_visual_styles_ = true;
  native::application::enable_visual_style();
}

void application::exit() {
  cancel_event_args e;
  application::exit(e);
}

void application::exit(cancel_event_args& e) {
  bool cancel_exit = false;
  for (auto f : application::open_forms()) {
    form_closing_event_args e;
    f.get().on_form_closing(e);
    if (e.cancel()) {
      cancel_exit = true;
      break;
    }
  }
  
  e.cancel(cancel_exit);
  if (!cancel_exit) {
    for (auto f : application::open_forms()) {
      form_closed_event_args e;
      f.get().on_form_closed(e);
    }
    native::application::exit();
  }
}

void application::exit_thread() {
  native::application::exit();
}

void application::initialize() {
  native::application::initialize();
}

void application::raise_idle(const event_args &e) {
  application::idle(e);
}

void application::register_message_loop_callback(message_loop_callback callback) {
}

void application::remove_message_filter(const imessage_filter& value) {
  for(message_filter_collection::iterator iterator = message_filters.begin(); iterator != message_filters.end(); ++iterator) {
    if (&iterator->get() == &value) {
      message_filters.erase(iterator);
      break;
    }
  }
}

void application::restart() {
  cancel_event_args e;
  application::exit(e);
  if (!e.cancel())
    native::application::restart();
}

void application::run() {
  application_context context;
  application::run(context);
}

void application::run(application_context& context) {
  if (application::application::message_loop_ == true) throw std::runtime_error("Application already running");
  cursor::current(cursors::default_cursor());
  try {
    context.thread_exit += application::on_app_thread_exit;
    native::application::register_message_filter(delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>(message_filter_proc));
    native::application::register_wnd_proc(delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>(application::wnd_proc_));
    application::message_loop_ = true;
    if (context.main_form_ != nullptr) context.main_form().show();
    native::application::run();
    application::message_loop_ = false;
  } catch(std::exception& exception) {
    /// @todo add exception message...
    cdebug << format("exception ({}) throws : {}", strings::full_class_name(exception), exception.what()) << endl;
  } catch(...) {
    /// @todo add exception message...
    cdebug << "exception (unknown) throws : ..." << endl;
  }
}

void application::run(const form& form) {
  application_context context(form);
  application::run(context);
}

void application::theme(const std::string& theme) {
  theme::current_theme(theme);
}

std::string application::theme() {
  return theme::current_theme().name();
}

std::vector<std::string> application::themes() {
  return theme::theme_names();
}

void application::yield() {
  native::application::yield();
}

void application::on_app_thread_exit(const application_context& sender, const event_args& e) {
  application::exit_thread();
}

void application::raise_enter_thread_modal(const event_args &e) {
  application::enter_thread_modal(e);
}

void application::raise_leave_thread_modal(const event_args &e) {
  application::leave_thread_modal(e);
}

intptr_t application::wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
  message message = forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
  wnd_proc(message);
  return message.result();
}

void application::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_ACTIVATEAPP: wm_activate_app(message); break;
    case WM_ENTERIDLE: wm_enter_idle(message); break;
    case WM_QUIT: wm_quit(message); break;
    default: break;
  }
}

void application::wm_activate_app(message& message) {
  for (const reference_wrapper<form>& form : open_forms())
    form.get().send_message(form.get().handle(), message.msg(), message.wparam(), message.lparam());
}

void application::wm_enter_idle(message& message) {
  static chrono::high_resolution_clock::time_point last_idle_time;
  if (chrono::high_resolution_clock::now() - last_idle_time >= chrono::milliseconds(100)) {
    last_idle_time = chrono::high_resolution_clock::now();
    application::idle(event_args::empty);
  }
  if (!application::idle.is_empty()) native::application::do_idle();
}

void application::wm_quit(message& message) {
  application::thread_exit(event_args::empty);
  application::application_exit(event_args::empty);
}
