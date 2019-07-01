#include "../include/xtd/control.hpp"
#include "native/control_api.hpp"

const xtd::forms::control xtd::forms::control::null;

void xtd::forms::control::location(const xtd::drawing::point& location) {
  if (this->location_ != location) {
    this->location_ = location;
    this->on_location_changed(xtd::event_args::empty);
  }
}

void xtd::forms::control::parent(const xtd::forms::control& parent) {
  if (this->parent_ != &parent) {
    this->parent_ = const_cast<xtd::forms::control*>(&parent);
    this->on_parent_changed(xtd::event_args::empty);
  }
}

void xtd::forms::control::size(const xtd::drawing::size& size) {
  if (this->size_ != size) {
    this->size_ = size;
    this->on_size_changed(xtd::event_args::empty);
  }
}

void xtd::forms::control::text(const std::string& text) {
  if (this->text_ != text) {
    this->text_ = text;
    this->on_text_changed(xtd::event_args::empty);
  }
}

void xtd::forms::control::visible(bool visible) {
  if (this->visible_ != visible) {
    this->visible_ = visible;
    this->on_visible_changed(xtd::event_args::empty);
  }
}

void xtd::forms::control::create_control() {
  if (!this->handle_) {
    this->create_handle();
    this->on_create_control();
  }
}

void xtd::forms::control::create_handle() {
  this->handle_ = native::control_api::create(this->parent_->handle(), this->default_size());
}

void xtd::forms::control::on_create_control() {
  this->location_ = native::control_api::location(this->handle_);
  this->size_ = native::control_api::size(this->handle_);
  this->text_ = native::control_api::text(this->handle_);
  this->visible_ = native::control_api::visible(this->handle_);
}

void xtd::forms::control::on_handle_created(const xtd::event_args &e) {
  this->handle_created(*this, e);
}

void xtd::forms::control::on_handle_destroyed(const xtd::event_args &e) {
  this->handle_destroyed(*this, e);
}

void xtd::forms::control::on_location_changed(const xtd::event_args &e) {
  native::control_api::location(this->handle_, this->location_);
  this->location_changed(*this, e);
}

void xtd::forms::control::on_parent_changed(const xtd::event_args &e) {
  this->create_control();
  //native::control_api::parent(this->handle_, this->parent_);
  //for (xtd::forms::control* control : this->controls_)
  //  control->create_control();
  this->parent_changed(*this, e);
}

void xtd::forms::control::on_size_changed(const xtd::event_args &e) {
  native::control_api::size(this->handle_, this->size_);
  this->size_changed(*this, e);
}

void xtd::forms::control::on_text_changed(const xtd::event_args &e) {
  native::control_api::text(this->handle_, this->text_);
  this->text_changed(*this, e);
}

void xtd::forms::control::on_visible_changed(const xtd::event_args &e) {
  native::control_api::visible(this->handle_, this->visible_);
  this->visible_changed(*this, e);
}

