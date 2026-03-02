#include "../../../include/xtd/serialization/yaml.hpp"

using namespace xtd;
using namespace xtd::serialization;

yaml::yaml(const nodes_collection& nodes) : nodes_ {nodes} {
}

yaml::yaml(nodes_collection&& nodes) : nodes_ {std::move(nodes)} {
}

auto yaml::nodes() const noexcept -> const nodes_collection& {
  return nodes_;
}

auto yaml::nodes() noexcept -> nodes_collection& {
  return nodes_;
}

auto yaml::nodes(const nodes_collection& nodes) noexcept -> void {
  nodes_ = nodes;
}

auto yaml::as_boolean(const xtd::string& key) const -> boolean_type {
  return xtd::as<boolean_type>(nodes_[key]);
}

auto yaml::as_integer(const xtd::string& key) const -> integer_type {
  return xtd::as<integer_type>(nodes_[key]);
}

auto yaml::as_floating_point(const xtd::string& key) const -> floating_point_type {
  return xtd::as<floating_point_type>(nodes_[key]);
}

auto yaml::as_mapping(const xtd::string& key) const -> mapping_type {
  return xtd::as<mapping_type>(nodes_[key]);
}

auto yaml::as_null(const xtd::string& key) const -> null_type {
  if (!is<null_type>(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  return nullptr;
}

auto yaml::as_sequence(const xtd::string& key) const -> sequence_type {
  return xtd::as<sequence_type>(nodes_[key]);
}

auto yaml::contains_key(const xtd::string& key) const noexcept -> bool {
  return nodes().contains_key(key);
}

auto yaml::is_boolean(const xtd::string& key) const noexcept -> bool {
  return contains_key(key) && xtd::is<boolean_type>(nodes_[key]);
}

auto yaml::is_integer(const xtd::string& key) const noexcept -> bool {
  return contains_key(key) && xtd::is<integer_type>(nodes_[key]);
}

auto yaml::is_floating_point(const xtd::string& key) const noexcept -> bool {
  return contains_key(key) && xtd::is<floating_point_type>(nodes_[key]);
}

auto yaml::is_mapping(const xtd::string& key) const -> bool {
  return contains_key(key) && xtd::is<mapping_type>(nodes_[key]);
}

auto yaml::is_null(const xtd::string& key) const noexcept -> bool {
  return contains_key(key) && nodes_[key] == xtd::null;
}

auto yaml::is_sequence(const xtd::string& key) const -> bool {
  return contains_key(key) && xtd::is<sequence_type>(nodes_[key]);
}

auto yaml::operator[](const xtd::string& key) const -> const xtd::any_object& {
  return nodes_[key];
}

auto yaml::operator[](const xtd::string& key) -> xtd::any_object& {
  return nodes_[key];
}
