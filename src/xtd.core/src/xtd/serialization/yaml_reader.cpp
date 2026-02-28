#include "../../../include/xtd/collections/generic/list.hpp"
#include "../../../include/xtd/serialization/yaml_reader.hpp"
#include "../../../include/xtd/helpers/throw_helper.hpp"
#include "fkYAML/node.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::io;
using namespace xtd::helpers;
using namespace xtd::serialization;

namespace xtd::internal {
  auto parse_node(const fkyaml::node& node) -> any_object {
    if (node.is_mapping()) {
      auto result = yaml::mapping_type {};
      for (auto&& [key, value] : node.as_map())
        result.nodes().add(key.as_str(), parse_node(value));
      return result;
    }
    
    if (node.is_sequence()) {
      auto result = yaml::sequence_type {};
      for (auto&& value : node.as_seq())
        result.add(parse_node(value));
      return result;
    }
    
    if (node.is_null()) return null;
    if (node.is_boolean()) return xtd::as<yaml::boolean_type>(node.as_bool());
    if (node.is_integer()) return xtd::as<yaml::integer_type>(node.as_int());
    if (node.is_float_number()) return xtd::as<yaml::floating_point_type>(node.as_float());
    if (node.is_string()) return xtd::as<yaml::string_type>(node.as_str());
    
    throw_helper::throws(exception_case::format, "Unsupported YAML node type");
  }
  
  auto parse_yaml(const string& value) -> yaml {
    return as<yaml>(parse_node(fkyaml::node::deserialize(value)));
  }
}

yaml_reader::yaml_reader(std::istream& stream) {
  parse_text(stream_reader {stream}.read_to_end());
}

yaml_reader::yaml_reader(text_reader& text_reader) {
  parse_text(text_reader.read_to_end());
}

yaml_reader::yaml_reader(const string& text) {
  parse_text(text);
}

auto yaml_reader::yaml() const noexcept -> const xtd::serialization::yaml& {
  return yaml_;
}

auto yaml_reader::parse_text(const string& text) -> void {
  yaml_ = internal::parse_yaml(text);
}
