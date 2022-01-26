#include "../../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/null_pointer_exception.h>

using namespace std;
using namespace xtd;
using namespace xtd::forms::style_sheets;

std::map<ustring, style_sheet> style_sheet::style_sheets_;

const button_data& style_sheet::button() const noexcept {
  return button_;
}

const control_data& style_sheet::control() const noexcept {
  return control_;
}

const form_data& style_sheet::form() const noexcept {
  return form_;
}

const label_data& style_sheet::label() const noexcept {
  return label_;
}

const system_colors_data& style_sheet::system_colors()const noexcept {
  return system_colors_;
}

const map<ustring, style_sheet> style_sheet::style_sheets() noexcept {
  initilize();
  return style_sheets_;
}

const theme_data& style_sheet::theme() const noexcept {
  return theme_;
}

bool style_sheet::equals(const object& other) const noexcept {
  return is<style_sheet>(other) ? equals(static_cast<const style_sheet&>(other)) : false;
}

bool style_sheet::equals(const style_sheet& other) const noexcept {
  return theme_ == theme_;
}

void style_sheet::initilize() {
  if (!style_sheets_.empty()) return;
  
}
