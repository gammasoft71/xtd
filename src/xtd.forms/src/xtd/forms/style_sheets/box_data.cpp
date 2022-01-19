#include <xtd/argument_exception.h>
#include "../../../../include/xtd/forms/style_sheets/box_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

box_data::box_data(const forms::padding& margin, const array<border_data, 4>& borders, const forms::padding& padding, const shared_ptr<brush>& background_color) : margin_(margin), borders_(borders), padding_(padding), background_color_(background_color) {
  if (!background_color) throw argument_exception(csf_);
}

box_data::box_data(const forms::padding& margin, const array<border_data, 4>& borders, const forms::padding& padding, const shared_ptr<brush>& background_color, optional<int32_t> width, optional<int32_t> height) : margin_(margin), borders_(borders), padding_(padding), background_color_(background_color), width_(width), height_(height) {
  if (!background_color) throw argument_exception(csf_);
}

box_data::box_data(const forms::padding& margin, const border_data& border, const forms::padding& padding, const shared_ptr<brush>& background_color) : margin_(margin), borders_({border, border, border, border}), padding_(padding), background_color_(background_color) {
  if (!background_color) throw argument_exception(csf_);
}

box_data::box_data(const forms::padding& margin, const border_data& border, const forms::padding& padding, const shared_ptr<brush>& background_color, optional<int32_t> width, optional<int32_t> height) : margin_(margin), borders_({border, border, border, border}), padding_(padding), background_color_(background_color), width_(width), height_(height) {
  if (!background_color) throw argument_exception(csf_);
}

const shared_ptr<brush>& box_data::background_color() const noexcept {
  return background_color_;
}

const array<border_data, 4>& box_data::borders() const noexcept {
  return borders_;
}

optional<int32_t> box_data::height() const noexcept {
  return height_;
}

const xtd::forms::padding& box_data::margin() const noexcept {
  return margin_;
}

const xtd::forms::padding& box_data::padding() const noexcept {
  return padding_;
}

optional<int32_t> box_data::width() const noexcept {
  return width_;
}
