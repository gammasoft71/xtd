#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_command_link_button.hpp"
#include <xtd/forms/native/command_link_button>
#include <xtd/forms/native/content_alignment>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>
#include <xtd/convert_string>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms::native;

void command_link_button::image(intptr control, const drawing::image& image) {
  if (!control || !wxTheApp || !image.handle()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxCommandLinkButton*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmapLabel(wxBitmap(*reinterpret_cast<wxImage*>(image.handle())));
}

void command_link_button::image_align(intptr control, uint32 align) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  switch (align) {
    case CA_TOPLEFT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_TOPCENTER: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxTOP); break;
    case CA_TOPRIGHT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
    case CA_MIDDLELEFT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_MIDDLECENTER: break;
    case CA_MIDDLERIGHT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
    case CA_BOTTOMLEFT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxLEFT); break;
    case CA_BOTTOMCENTER: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxBOTTOM); break;
    case CA_BOTTOMRIGHT: static_cast<wxCommandLinkButton*>(reinterpret_cast<wx_command_link_button*>(control)->control())->SetBitmapPosition(wxRIGHT); break;
  }
}

void command_link_button::texts(intptr control, const std::tuple<string, string>& texts) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxCommandLinkButton*>(reinterpret_cast<control_handler*>(control)->control())->SetMainLabelAndNote(convert_string::to_wstring(std::get<0>(texts)), convert_string::to_wstring(std::get<1>(texts)));
}
