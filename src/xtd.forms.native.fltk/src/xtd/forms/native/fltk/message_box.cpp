#include <stdexcept>
#include <string>
#include <vector>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/message_box.hpp>
#include <xtd/forms/native/message_box_styles.hpp>
#include "control_handler.hpp"
#include <FL/fl_ask.H>

using namespace std;
using namespace xtd;
using namespace xtd::forms::native;

namespace {
  int32_t result_for_ok_cancel(int32_t result) {
    switch (result) {
      case 1: return IDOK;
      case 2: return IDCANCEL;
    }
    return IDCANCEL;
  }
  
  int32_t result_for_abort_retry_ignore(int32_t result) {
    switch (result) {
      case 0: return IDABORT;
      case 1: return IDRETRY;
      case 2: return IDIGNORE;
    }
    return IDCANCEL;
  }

  int32_t result_for_yes_no_cancel(int32_t result) {
    switch (result) {
      case 0: return IDYES;
      case 1: return IDNO;
      case 2: return IDCANCEL;
    }
    return IDCANCEL;
  }

  int32_t result_for_yes_no(int32_t result) {
    switch (result) {
      case 1: return IDYES;
      case 2: return IDNO;
    }
    return IDCANCEL;
  }

  int32_t result_for_retry_cancel(int32_t result) {
    switch (result) {
      case 1: return IDRETRY;
      case 2: return IDCANCEL;
    }
    return IDCANCEL;
  }

  int32_t convert_to_dialog_result(int32_t result, uint32_t style) {
    if ((style & MB_OKCANCEL) == MB_OKCANCEL) return result_for_ok_cancel(result);
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) return result_for_abort_retry_ignore(result);
    if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) return result_for_yes_no_cancel(result);
    if ((style & MB_YESNO) == MB_YESNO) return result_for_yes_no(result);
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) return result_for_retry_cancel(result);
    return IDCANCEL;
  }
  
  vector<string> convert_to_buttons(uint32_t style) {
    if ((style & MB_OKCANCEL) == MB_OKCANCEL) return {fl_ok, fl_cancel};
    if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) return {"Abort", "Retry", "Ignore"};
    if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) return {fl_yes, fl_no, fl_cancel};
    if ((style & MB_YESNO) == MB_YESNO) return {fl_yes, fl_no};
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) return {"Retry", fl_cancel};
    return {};
  }
  
  void convert_to_colored_icon(uint32_t style) {
    if ((style & MB_ICONSTOP) == MB_ICONSTOP) fl_message_icon()->label("X");
    else if ((style & MB_ICONQUESTION) == MB_ICONQUESTION) fl_message_icon()->label("?");
    else if ((style & MB_ICONEXCLAMATION) == MB_ICONEXCLAMATION) fl_message_icon()->label("!");
    else if ((style & MB_ICONINFORMATION) == MB_ICONINFORMATION) fl_message_icon()->label("i");;
    
    if ((style & MB_ICONSTOP) == MB_ICONSTOP) {
      fl_message_icon()->color(fl_rgb_color(255, 0, 0));
      fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
    } else if ((style & MB_ICONEXCLAMATION) == MB_ICONSTOP) {
      fl_message_icon()->color(fl_rgb_color(255, 255, 0));
      fl_message_icon()->labelcolor(fl_rgb_color(0, 0, 0));
    } else {
      fl_message_icon()->color(fl_rgb_color(0, 0, 255));
      fl_message_icon()->labelcolor(fl_rgb_color(255, 255, 255));
    }
  }
}

int32_t message_box::show(intptr_t control, const ustring& text, const ustring& caption, uint32_t style, bool display_help_button) {
  native::application::initialize(); // Must be first
  fl_message_title(caption.c_str());
  convert_to_colored_icon(style);
  auto buttons = convert_to_buttons(style);
  int32_t result = fl_choice("%s", buttons.size() >= 1 ? buttons[0].c_str() : nullptr, buttons.size() >= 2 ? buttons[1].c_str() : nullptr, buttons.size() >= 3 ? buttons[2].c_str() : nullptr, text.c_str());
  fl_message_icon()->color(fl_rgb_color(255, 255, 255));
  fl_message_icon()->labelcolor(fl_rgb_color(0, 0, 255));
  return convert_to_dialog_result(result, style);
}
