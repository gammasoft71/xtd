#include "../../../include/xtd/forms/application"
#include "../../../include/xtd/forms/busy_dialog"
#include <xtd/drawing/system_icons>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/busy_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <memory>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct busy_dialog::data {
  xtd::drawing::color back_color = application::style_sheet().system_colors().control();
  xtd::forms::dialog_appearance dialog_appearance = xtd::forms::dialog_appearance::system;
  xtd::drawing::color fore_color = application::style_sheet().system_colors().control_text();
  xtd::drawing::image icon;
  xtd::ustring text;
  xtd::ustring description;
  double opacity = 1.0;
  bool native = false;
  intptr handle = 0;
};

busy_dialog::busy_dialog() : data_(std::make_shared<data>()) {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
}

busy_dialog::~busy_dialog() {hide();}

xtd::drawing::color busy_dialog::back_color() const noexcept {
  return data_->back_color;
}

busy_dialog& busy_dialog::back_color(const xtd::drawing::color& color) {
  data_->back_color = color;
  return *this;
}

xtd::forms::dialog_appearance busy_dialog::dialog_appearance() const noexcept {
  return data_->dialog_appearance;
}

busy_dialog& busy_dialog::dialog_appearance(xtd::forms::dialog_appearance dialog_appearance) {
  data_->dialog_appearance = dialog_appearance;
  return *this;
}

const xtd::ustring& busy_dialog::description() const noexcept {
  return data_->description;
}

busy_dialog& busy_dialog::description(const xtd::ustring& description) {
  data_->description = description;
  return *this;
}

/// @brief Gets the foreground color for the dialog.
/// @return A xtd::drawing::color that represents the foreground color of the dialog.
xtd::drawing::color busy_dialog::fore_color() const noexcept {
  return data_->fore_color;
}

busy_dialog& busy_dialog::fore_color(const xtd::drawing::color& color) {
  data_->fore_color = color;
  return *this;
}

xtd::drawing::icon busy_dialog::icon() const noexcept {
  return xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon));
}

busy_dialog& busy_dialog::icon(const xtd::drawing::icon& icon) {
  data_->icon = icon.to_bitmap();
  return *this;
}

busy_dialog& busy_dialog::icon(const xtd::drawing::image& image) {
  data_->icon = image;
  return *this;
}

busy_dialog& busy_dialog::icon(const xtd::drawing::bitmap& bitmap) {
  data_->icon = bitmap;
  return *this;
}

double busy_dialog::opacity() const noexcept {
  return data_->opacity;
}

busy_dialog& busy_dialog::opacity(double opacity) {
  data_->opacity = opacity;
  return *this;
}

/// @brief Gets the dialog title.
/// @return The dialog title.
const xtd::ustring& busy_dialog::text() const noexcept {
  return data_->text;
}

busy_dialog& busy_dialog::text(const xtd::ustring& text) {
  data_->text = text;
  return *this;
}

void busy_dialog::reset() {
  data_->dialog_appearance = application::use_system_controls() ? forms::dialog_appearance::system : forms::dialog_appearance::standard;
  data_->icon = xtd::drawing::image::empty;
  data_->text = "";
  data_->description = "";
}

void busy_dialog::show() {
  /// @todo Delete the following comment when the standard dialog is ready.
  data_->native = true; //data_->dialog_appearance == xtd::forms::dialog_appearance::system;
  if (data_->native) data_->handle = native::busy_dialog::create(0, xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->text, data_->description, data_->back_color, data_->fore_color, data_->opacity);
  application::do_events();
}

void busy_dialog::show(const iwin32_window& owner) {
  /// @todo Delete the following comment when the standard dialog is ready.
  data_->native = true; //data_->dialog_appearance == xtd::forms::dialog_appearance::system;
  if (data_->native) data_->handle = native::busy_dialog::create(owner.handle(), xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(data_->icon)), data_->text, data_->description, data_->back_color, data_->fore_color, data_->opacity);
  application::do_events();
}

void busy_dialog::hide() {
  if (!data_->handle) return;
  if (data_->native) native::busy_dialog::destroy(data_->handle);
  data_->native = false;
  data_->handle = 0;
}
