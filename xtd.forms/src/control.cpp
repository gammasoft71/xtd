#include "../include/xtd/control.h"
#include "native/control_api.h"

const xtd::forms::control xtd::forms::control::null;


void xtd::forms::control::location(const xtd::drawing::point& location) {
  if (this->location_ != location) {
    this->location_ = location;
    this->on_location_changed(xtd::event_args::empty());
  }
}

void xtd::forms::control::parent(const xtd::forms::control& parent) {
  if (this->parent_ != &parent) {
    this->parent_ = const_cast<xtd::forms::control*>(&parent);
    this->on_parent_changed(xtd::event_args::empty());
  }
}

void xtd::forms::control::text(const std::string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    this->on_text_changed(xtd::event_args::empty());
  }
}

void xtd::forms::control::create_handle() {
  this->handle_ = native::control_api::create(this->parent_->handle());
}

void xtd::forms::control::on_location_changed(const xtd::event_args &e) {
  //native::control_api::location(this->handle_, this->location_);
  this->location_changed(*this, e);
}

void xtd::forms::control::on_parent_changed(const xtd::event_args &e) {
  this->create_control();
  //native::control_api::parent(this->handle_, this->parent_);
  //for (xtd::forms::control* control : this->controls_)
  //  control->create_control();
  this->parent_changed(*this, e);
}

void xtd::forms::control::on_text_changed(const xtd::event_args &e) {
  native::control_api::text(this->handle_, this->text_);
  this->text_changed(*this, e);
}

void xtd::forms::control::on_visible_changed(const xtd::event_args &e) {
  native::control_api::visible(this->handle_, this->visible_);
  this->visible_changed(*this, e);
}

void xtd::forms::control::show() {
  this->visible_ = true;
  this->on_visible_changed(xtd::event_args::empty());
}

