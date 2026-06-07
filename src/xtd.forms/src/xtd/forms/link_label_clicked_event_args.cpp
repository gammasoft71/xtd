#include "../../../include/xtd/forms/link_label_clicked_event_args.hpp"

using namespace xtd;
using namespace xtd::forms;

link_label_clicked_event_args::link_label_clicked_event_args(const xtd::forms::link& link, xtd::forms::mouse_buttons button) : link_(link), button_(button) {
}

auto link_label_clicked_event_args::link() const noexcept -> const xtd::forms::link& {
  return link_;
}

auto link_label_clicked_event_args::button() const noexcept -> xtd::forms::mouse_buttons {
  return button_;
}

auto link_label_clicked_event_args::visited() const noexcept -> bool {
  return visited_;
}

auto link_label_clicked_event_args::visited(bool value) -> link_label_clicked_event_args& {
  visited_ = value;
  return *this;
}
