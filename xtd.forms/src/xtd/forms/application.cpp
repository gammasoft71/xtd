#include <chrono>
#include <xtd/xtd.io.hpp>
#include <xtd/environment.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/window_messages.hpp>
#include "../../../include/xtd/forms/application.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

bool application::allow_quit() {
  return native::application::allow_quit();
}

string application::common_app_data_path() {
  //string common_app_data_path = io::combine(environment::get_folder_path(environment::special_folder::common_application_data), company_name(), product_name(), product_version());
  //if (!io:directory::exists(common_app_data_path))
  //  io::directory::create_directory(common_app_data_path);
  //return commonApp_data_path;
  return "";
}

/*
microsoft::win32::registry_key application::common_app_data_registry() {
  return microsoft::win32::registry::local_machine().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
}
 */

string application::company_name() {
  if (!strings::is_empty(application_informations::company_name())) return application_informations::company_name();
  return io::path::get_file_name_without_extension(executable_path());
}

string application::executable_path() {
  return environment::get_command_line_args()[0];
}

vector<reference_wrapper<form>> application::open_forms() {
  vector<reference_wrapper<form>> forms;
  
  for (intptr_t handle : native::application::open_forms()) {
    control& control = control::from_handle(handle);
    forms.push_back(static_cast<form&>(control));
  }
  return forms;
}


string application::product_name() {
  if (!strings::is_empty(application_informations::product_name())) return application_informations::product_name();
  return io::path::get_file_name_without_extension(executable_path());
}

void application::do_events() {
  native::application::do_events();
}

void application::enable_visual_styles() {
  native::application::enable_visual_style();
}

void application::exit() {
  native::application::exit();
}

void application::run() {
  native::application::run();
}

void application::run(const form& form) {
  native::application::main_form(form.__get_handle__());
  native::application::register_wnd_proc(application::wnd_proc_);
  run();
}

event<application, delegate<void(const event_args&)>> application::idle;

int application::wnd_proc_(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
  message message = forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
  wnd_proc(message);
  return message.result();
}

void application::wnd_proc(message& message) {
  switch (message.msg()) {
    case WM_ACTIVATEAPP: wm_activate_app(message); break;
    case WM_ENTERIDLE: wm_enter_idle(message); break;
    default: break;
  }
}

void application::wm_activate_app(message& message) {
  for (reference_wrapper<form>& form : open_forms())
    form.get().send_message(form.get().__get_handle__(), message.msg(), message.wparam(), message.lparam());
}

void application::wm_enter_idle(message& message) {
  static chrono::high_resolution_clock::time_point last_idle_time;
  if (chrono::high_resolution_clock::now() - last_idle_time >= chrono::milliseconds(100)) {
    last_idle_time = chrono::high_resolution_clock::now();
    application::idle(event_args::empty);
  }
  if (!application::idle.is_empty()) native::application::do_idle();
}
