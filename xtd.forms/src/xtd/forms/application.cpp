#include <chrono>
#include <xtd/xtd.io.hpp>
#include <xtd/environment.hpp>
#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"
#include "../../native/application_api.hpp"

bool xtd::forms::application::allow_quit() {
  return native::application_api::allow_quit();
}

std::string xtd::forms::application::common_app_data_path() {
  //std::string common_app_data_path = xtd::io::combine(xtd::environment::get_folder_path(xtd::environment::special_folder::common_application_data), company_name(), product_name(), product_version());
  //if (!xtd::io:directory::exists(common_app_data_path))
  //  xtd::io::directory::create_directory(common_app_data_path);
  //return commonApp_data_path;
  return "";
}

/*
xtd::microsoft::win32::registry_key xtd::forms::application::common_app_data_registry() {
  return xtd::microsoft::win32::registry::local_machine().create_sub_key("Software").create_sub_key(company_name()).create_sub_key(product_name()).create_sub_key(product_version());
}
 */

std::string xtd::forms::application::company_name() {
  if (!xtd::strings::is_empty(xtd::forms::application_informations::company_name())) return xtd::forms::application_informations::company_name();
  return xtd::io::path::get_file_name_without_extension(executable_path());
}

std::string xtd::forms::application::executable_path() {
  return xtd::environment::get_command_line_args()[0];
}

std::vector<std::reference_wrapper<xtd::forms::form>> xtd::forms::application::open_forms() {
  std::vector<std::reference_wrapper<xtd::forms::form>> forms;
  
  for (intptr_t handle : native::application_api::open_forms()) {
    xtd::forms::control& control = xtd::forms::control::from_handle(handle);
    forms.push_back(static_cast<xtd::forms::form&>(control));
  }
  return forms;
}


std::string xtd::forms::application::product_name() {
  if (!xtd::strings::is_empty(xtd::forms::application_informations::product_name())) return xtd::forms::application_informations::product_name();
  return xtd::io::path::get_file_name_without_extension(executable_path());
}

void xtd::forms::application::do_events() {
  native::application_api::do_events();
}

void xtd::forms::application::enable_visual_styles() {
  native::application_api::enable_visual_style();
}

void xtd::forms::application::exit() {
  native::application_api::exit();
}

void xtd::forms::application::run() {
  native::application_api::run();
}

void xtd::forms::application::run(const form& form) {
  native::application_api::main_form(form.__get_handle__());
  native::application_api::register_wnd_proc(application::wnd_proc);
  run();
  native::application_api::unregister_wnd_proc();
}

xtd::event<xtd::forms::application, xtd::delegate<void(const xtd::event_args&)>> xtd::forms::application::idle;

void xtd::forms::application::wnd_proc(xtd::forms::message& message) {
  switch (message.msg()) {
    case WM_ACTIVATEAPP: wm_activate_app(message); break;
    case WM_ENTERIDLE: wm_enter_idle(message); break;
    default: break;
  }
}

void xtd::forms::application::wm_activate_app(xtd::forms::message& message) {
  for (std::reference_wrapper<xtd::forms::form>& form : open_forms())
    form.get().send_message(form.get().__get_handle__(), message.msg(), message.wparam(), message.lparam());
}

void xtd::forms::application::wm_enter_idle(xtd::forms::message& message) {
  static std::chrono::high_resolution_clock::time_point last_idle_time;
  if (std::chrono::high_resolution_clock::now() - last_idle_time >= std::chrono::milliseconds(100)) {
    last_idle_time = std::chrono::high_resolution_clock::now();
    xtd::forms::application::idle(xtd::event_args::empty);
  }
  if (!xtd::forms::application::idle.is_empty()) native::application_api::do_idle();
}
