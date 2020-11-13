#include <map>
#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/drawing/system_fonts.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/control.hpp>
#include "fl_button.hpp"
#include "fl_check_box.hpp"
#include "fl_checked_list_box.hpp"
#include "fl_combo_box.hpp"
#include "fl_control.hpp"
#include "fl_form.hpp"
#include "fl_group_box.hpp"
#include "fl_label.hpp"
#include "fl_list_box.hpp"
#include "fl_panel.hpp"
#include "fl_progress_bar.hpp"
#include "fl_radio_button.hpp"
#include "fl_tab_control.hpp"
#include "fl_tab_page.hpp"
#include "fl_text_box.hpp"
#include "fl_track_bar.hpp"
#include "fl_user_control.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

extern int32_t __mainloop_runnning__;

color control::back_color(intptr_t control) {
  if (control == 0) return color::empty;
  
  return color::from_argb(0xFF000000 + (reinterpret_cast<control_handler*>(control)->control()->color() >> 8));
}

void control::back_color(intptr_t control, const color& color) {
  if (control == 0) return;
  
  reinterpret_cast<control_handler*>(control)->control()->color(fl_rgb_color(color.r(), color.g(), color.b()));
}

intptr_t control::create(const forms::create_params& create_params) {
  application::initialize(); // Must be first
  if (create_params.class_name() == "button") return reinterpret_cast<intptr_t>(new fl_button(create_params));
  if (create_params.class_name() == "checkbox") return reinterpret_cast<intptr_t>(new fl_check_box(create_params));
  if (create_params.class_name() == "checkedlistbox") return reinterpret_cast<intptr_t>(new fl_checked_list_box(create_params));
  if (create_params.class_name() == "combobox") return reinterpret_cast<intptr_t>(new fl_combo_box(create_params));
  if (create_params.class_name() == "form") return reinterpret_cast<intptr_t>(new fl_form(create_params));
  if (create_params.class_name() == "groupbox") return reinterpret_cast<intptr_t>(new fl_group_box(create_params));
  if (create_params.class_name() == "label") return reinterpret_cast<intptr_t>(new fl_label(create_params));
  if (create_params.class_name() == "listbox") return reinterpret_cast<intptr_t>(new fl_list_box(create_params));
  if (create_params.class_name() == "panel") return reinterpret_cast<intptr_t>(new fl_panel(create_params));
  if (create_params.class_name() == "progressbar") return reinterpret_cast<intptr_t>(new fl_progress_bar(create_params));
  if (create_params.class_name() == "radiobutton") return reinterpret_cast<intptr_t>(new fl_radio_button(create_params));
  if (create_params.class_name() == "tabcontrol") return reinterpret_cast<intptr_t>(new fl_tab_control(create_params));
  if (create_params.class_name() == "tabpage") return reinterpret_cast<intptr_t>(new fl_tab_page(create_params));
  if (create_params.class_name() == "textbox") return reinterpret_cast<intptr_t>(new fl_text_box(create_params));
  if (create_params.class_name() == "trackbar") return reinterpret_cast<intptr_t>(new fl_track_bar(create_params));
  if (create_params.class_name() == "usercontrol") return reinterpret_cast<intptr_t>(new fl_user_control(create_params));
  return reinterpret_cast<intptr_t>(new fl_control(create_params));
}

intptr_t control::create_paint_graphics(intptr_t control) {
  return control;
}

intptr_t control::create_double_buffered_paint_graphics(intptr_t control) {
  return control;
}

intptr_t control::create_graphics(intptr_t control) {
  return control;
}

intptr_t control::def_wnd_proc(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t presult, intptr_t handle) {
  if (!control || handle == 0) return 0;
  return reinterpret_cast<control_handler*>(control)->call_def_wnd_proc(hwnd, msg, wparam, lparam, presult, handle);
}

font control::default_font() {
  return system_fonts::default_font();
}

void control::destroy(intptr_t control) {
  if (control == 0) return;
  if (reinterpret_cast<control_handler*>(control)->control() == 0) return;
  reinterpret_cast<control_handler*>(control)->destroy();
  delete reinterpret_cast<class control_handler*>(control);
}

void control::init() {
  application::initialize(); // Must be first
}

drawing::rectangle control::client_rectangle(intptr_t control) {
  if (control == 0) return {};
  return {reinterpret_cast<control_handler*>(control)->control()->x(), reinterpret_cast<control_handler*>(control)->control()->y(), reinterpret_cast<control_handler*>(control)->control()->w() - Fl::box_dw(reinterpret_cast<control_handler*>(control)->control()->box()), reinterpret_cast<control_handler*>(control)->control()->h() - Fl::box_dh(reinterpret_cast<control_handler*>(control)->control()->box())};
}

drawing::size control::client_size(intptr_t control) {
  if (control == 0) return {};
  return {reinterpret_cast<control_handler*>(control)->control()->w() - Fl::box_dw(reinterpret_cast<control_handler*>(control)->control()->box()), reinterpret_cast<control_handler*>(control)->control()->h() - Fl::box_dh(reinterpret_cast<control_handler*>(control)->control()->box())};
}

void control::client_size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->size(size.width() + Fl::box_dw(reinterpret_cast<control_handler*>(control)->control()->box()), size.height() + Fl::box_dh(reinterpret_cast<control_handler*>(control)->control()->box()));
}

void control::cursor(intptr_t control, intptr_t cursor) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->cursor(static_cast<Fl_Cursor>(cursor));
}

bool control::enabled(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->active();
}

void control::enabled(intptr_t control, bool enabled) {
  if (control == 0) return;
  if (enabled)
    reinterpret_cast<control_handler*>(control)->control()->activate();
  else
  reinterpret_cast<control_handler*>(control)->control()->deactivate();
}

void control ::focus(intptr_t control) {
  if (control == 0) return;
  Fl::focus(reinterpret_cast<control_handler*>(control)->control());
}

color control::fore_color(intptr_t control) {
  if (control == 0) return color::empty;
  return color::from_argb(0xFF000000 + (reinterpret_cast<control_handler*>(control)->control()->labelcolor() >> 8));
}

void control::fore_color(intptr_t control, const color& color) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->labelcolor(fl_rgb_color(color.r(), color.g(), color.b()));
}

drawing::font control::font(intptr_t control) {
  return drawing::font::from_hfont(static_cast<intptr_t>(reinterpret_cast<control_handler*>(control)->control()->labelfont()));
}

void control::font(intptr_t control, const drawing::font& font) {
  if (control == 0) return;
  //reinterpret_cast<control_handler*>(control)->control()->labelfont(static_cast<Fl_Font>(font.handle()));
}

point control::location(intptr_t control) {
  if (control == 0) return {};
  return {reinterpret_cast<control_handler*>(control)->control()->x(), reinterpret_cast<control_handler*>(control)->control()->y()};
}

void control::location(intptr_t control, const point& location) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->position(location.x(), location.y());
}

drawing::point control::point_to_screen(intptr_t control, const drawing::point& p) {
  if (control == 0) return p;
  drawing::point screen = p + drawing::size(reinterpret_cast<control_handler*>(control)->control()->x(), reinterpret_cast<control_handler*>(control)->control()->y());
  Fl_Widget* parent = reinterpret_cast<control_handler*>(control)->control()->parent();
  while(parent) {
    screen = screen + drawing::size(parent->x(), parent->y());
    parent = parent->parent();
  }
  return screen;
}

drawing::point control::point_to_client(intptr_t control, const drawing::point& p) {
  if (control == 0) return p;
  drawing::point client = p - drawing::size(reinterpret_cast<control_handler*>(control)->control()->x(), reinterpret_cast<control_handler*>(control)->control()->y());
  Fl_Widget* parent = reinterpret_cast<control_handler*>(control)->control()->parent();
  while(parent) {
    client = client - drawing::size(parent->x(), parent->y());
    parent = parent->parent();
  }
  return client;
}

drawing::size control::size(intptr_t control) {
  if (control == 0) return {};
  return {reinterpret_cast<control_handler*>(control)->control()->w(), reinterpret_cast<control_handler*>(control)->control()->h()};
}

void control::size(intptr_t control, const drawing::size& size) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->size(size.width(), size.height());
}

ustring control::text(intptr_t control) {
  if (control == 0) return {};
  return reinterpret_cast<control_handler*>(control)->control()->label();
}

void control::text(intptr_t control, const ustring& text) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->copy_label(text.c_str());
}

bool control::visible(intptr_t control) {
  if (control == 0) return false;
  return reinterpret_cast<control_handler*>(control)->control()->visible();
}

void control::visible(intptr_t control, bool visible) {
  if (control == 0) return;
  if (visible)
    reinterpret_cast<control_handler*>(control)->control()->show();
  else
    reinterpret_cast<control_handler*>(control)->control()->hide();
}

void control::invalidate(intptr_t control, const drawing::rectangle& rect, bool invalidate_children) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->control()->damage(255, rect.x(), rect.y(), rect.width(), rect.height());
}

void control::refresh(intptr_t control) {
  if (control == 0) return;

  reinterpret_cast<control_handler*>(control)->control()->redraw();
}

void control::update(intptr_t control) {
  if (control == 0) return;

  reinterpret_cast<control_handler*>(control)->control()->redraw();
}

void control::register_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->wnd_proc += wnd_proc;
}

void control::unregister_wnd_proc(intptr_t control, const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  if (control == 0) return;
  reinterpret_cast<control_handler*>(control)->wnd_proc -= wnd_proc;
}

intptr_t control::send_message(intptr_t control, intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam) {
  if (hwnd == 0) return -1;
  return reinterpret_cast<control_handler*>(control)->send_message(hwnd, msg, wparam, lparam, 0);
}
