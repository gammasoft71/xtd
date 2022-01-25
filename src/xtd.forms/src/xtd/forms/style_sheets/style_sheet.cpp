#include "../../../../include/xtd/forms/style_sheets/style_sheet.h"
#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/null_pointer_exception.h>

using namespace std;
using namespace xtd;
using namespace xtd::forms::style_sheets;

namespace {
}

std::map<ustring, style_sheet> style_sheet::style_sheets_;
style_sheet* style_sheet::current_ = nullptr;
style_sheet* style_sheet::system_ = nullptr;


const button_data& style_sheet::button() const noexcept {
  return button_;
}

const control_data& style_sheet::control() const noexcept {
  return control_;
}

const style_sheet& style_sheet::current() {
  initilize();
  if (!current_) throw null_pointer_exception("uninitialized style_sheets", csf_);
  return *current_;
}

const form_data& style_sheet::form() const noexcept {
  return form_;
}

const label_data& style_sheet::label() const noexcept {
  return label_;
}

const style_sheet& style_sheet::system() {
  initilize();
  if (!system_) throw null_pointer_exception("uninitialized style_sheets", csf_);
  return *system_;
}

const map<ustring, style_sheet> style_sheet::style_sheets() noexcept {
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
  /// Read themes folder...
}
