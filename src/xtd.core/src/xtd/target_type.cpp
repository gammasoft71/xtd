#include "../../include/xtd/as.h"
#include "../../include/xtd/target_type.h"

using namespace xtd;

bool target_type::is_console_application() const noexcept {
  return target_id_ == xtd::target_id::console_application;
}

bool target_type::is_guid_application() const noexcept {
  return target_id_ == xtd::target_id::gui_application;
}

bool target_type::is_test_application() const noexcept {
  return target_id_ == xtd::target_id::test_application;
}

bool target_type::is_shared_library() const noexcept {
  return target_id_ == xtd::target_id::shared_library;
}

bool target_type::is_static_library() const noexcept {
  return target_id_ == xtd::target_id::static_library;
}

target_id target_type::target_id() const noexcept {
  return target_id_;
}

ustring target_type::name() const noexcept {
  return enum_object<xtd::target_id>(target_id_).to_string().replace("_", " ");
}

ustring target_type::to_string() const noexcept {
  return name();
}

target_type::target_type(xtd::target_id target_id) : target_id_(target_id) {
}
