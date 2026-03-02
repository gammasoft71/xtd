/// @file
/// @brief Contains xtd::serialization::yaml alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/dictionary.hpp"
#include "../collections/array_list.hpp"
#include "../helpers/throw_helper.hpp"
#include "../any_object.hpp"
#include "../is_string_literal.hpp"
#include "../string.hpp"
#include <type_traits>
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains classes that can be used for serializing and deserializing objects. Serialization is the process of converting an object or a graph of objects into a linear sequence of bytes for either storage or transmission to another location. Deserialization is the process of taking in stored information and recreating objects from it.
  namespace serialization {
    /// @brief Represents a YAML content. Typically a xtd::collections::generic::dictionary of xtd::string and xtd::any_object as key value.
    /// @remarks The xtd::any_object value can be of different type :
    /// | type                | check                                       | convert                                                  |
    /// | ------------------- | ------------------------------------------- | -------------------------------------------------------- |
    /// | null_type           | `node.is<yaml::null_type>("key")`           | `auto value = node.as<yaml::null_type>("key")`           |
    /// | boolean_type        | `node.is<yaml::boolean_type>("key")`        | `auto value = node.as<yaml::boolean_type>("key")`        |
    /// | integer_type        | `node.is<yaml::integer_type>("key")`        | `auto value = node.as<yaml::integer_type>("key")`        |
    /// | floating_point_type | `node.is<yaml::floating_point_type>("key")` | `auto value = node.as<yaml::floating_point_type>("key")` |
    /// | string_type         | `node.is<yaml::string_type>("key")`         | `auto value = node.as<yaml::string_type>("key")`         |
    /// | sequence_type       | `node.is<yaml::sequence_type>("key")`       | `auto value = node.as<yaml::sequence_type>("key")`       |
    /// | mapping_type        | `node.is<yaml::mapping_type>("key")`        | `auto value = node.as<yaml::mapping_type>("key")`        |
    /// | null                | `node.is<null>("key")`                      | `auto value = node.as<null>("key")`                      |
    /// | bool                | `node.is<bool>("key")`                      | `auto value = node.as<bool>("key")`                      |
    /// | byte                | `node.is<byte>("key")`                      | `auto value = node.as<byte>("key")`                      |
    /// | decimal             | `node.is<decimal>("key")`                   | `auto value = node.as<decimal>("key")`                   |
    /// | double              | `node.is<double>("key")`                    | `auto value = node.as<double>("key")`                    |
    /// | int16               | `node.is<int16>("key")`                     | `auto value = node.as<int16>("key")`                     |
    /// | int32               | `node.is<int32>("key")`                     | `auto value = node.as<int32>("key")`                     |
    /// | int64               | `node.is<int64>("key")`                     | `auto value = node.as<int64>("key")`                     |
    /// | sbyte               | `node.is<sbyte>("key")`                     | `auto value = node.as<sbyte>("key")`                     |
    /// | single              | `node.is<single>("key")`                    | `auto value = node.as<single>("key")`                    |
    /// | string              | `node.is<string>("key")`                    | `auto value = node.as<string>("key")`                    |
    /// | uint16              | `node.is<uint16>("key")`                    | `auto value = node.as<uint16>("key")`                    |
    /// | uint32              | `node.is<uint32>("key")`                    | `auto value = node.as<uint32>("key")`                    |
    /// | uint64              | `node.is<uint64>("key")`                    | `auto value = node.as<uint64>("key")`                    |
    class yaml : public object {
    public:
      /// @name Public Aliases
      
      /// @{
      using boolean_type = xtd::boolean;
      using floating_point_type = xtd::decimal;
      using integer_type = xtd::int64;
      using mapping_type = yaml;
      using nodes_collection = xtd::collections::generic::dictionary<xtd::string, xtd::any_object>;
      using null_type = xtd::null_ptr;
      using sequence_type = xtd::collections::array_list;
      using string_type = xtd::string;
      /// @}

      /// @name Public Constructors
      
      /// @{
      yaml() = default;
      yaml(const nodes_collection& nodes);
      yaml(nodes_collection&& nodes);
      yaml(const yaml&)  = default;
      yaml(yaml&&) = default;
      yaml& operator =(const yaml&)  = default;
      yaml& operator =(yaml&&)  = default;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      auto nodes() const noexcept -> const nodes_collection&;
      auto nodes() noexcept -> nodes_collection&;
      auto nodes(const nodes_collection& nodes) noexcept -> void;
      /// @}
      
      /// @name Public Metdods
      
      /// @{
      template<class type_t>
      auto as(const xtd::string& key) const -> type_t {
        if constexpr (std::floating_point<type_t>) return xtd::as<type_t>(as_floating_point(key));
        else if constexpr (std::integral<type_t> && !std::same_as<type_t, boolean_type>) return xtd::as<type_t>(xtd::is<integer_type>(nodes_[key]) ? xtd::as<int64>(nodes_[key]) : xtd::as<uint64>(nodes_[key]));
        else if constexpr (std::same_as<type_t, null_type>) return nullptr;
        else if constexpr (std::same_as<type_t, boolean_type>) return xtd::as<boolean_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, string_type> || xtd::is_string_literal<type_t>) return xtd::as<string_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, mapping_type>) return xtd::as<mapping_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, sequence_type>) return xtd::as<sequence_type>(nodes_[key]);
        else xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }

      auto as_boolean(const xtd::string& key) const -> boolean_type;
      auto as_integer(const xtd::string& key) const {return xtd::is<integer_type>(nodes_[key]) ? xtd::as<integer_type>(nodes_[key]) : xtd::as<uint64>(nodes_[key]);}
      auto as_floating_point(const xtd::string& key) const -> floating_point_type;
      auto as_mapping(const xtd::string& key) const -> mapping_type;
      auto as_null(const xtd::string& key) const -> null_type;
      auto as_sequence(const xtd::string& key) const -> sequence_type;
      auto as_string(const xtd::string& key) const -> string_type;

      auto contains_key(const xtd::string& key) const noexcept -> bool;
      
      template<class type_t>
      auto is(const xtd::string& key) const -> bool {
        if (!contains_key(key)) return false;
        if constexpr (std::floating_point<type_t>) return is_floating_point(key) && xtd::box_floating_point<type_t>::is_valid(as_floating_point(key));
        else if constexpr (std::integral<type_t> && !std::same_as<type_t, boolean_type>) return is_integer(key) && xtd::box_integer<type_t>::is_valid(xtd::is<integer_type>(nodes_[key]) ? xtd::as<int64>(nodes_[key]) : xtd::as<uint64>(nodes_[key]));
        else if constexpr (std::same_as<type_t, null_type>) return contains_key(key) && xtd::is<xtd::null_ptr>(nodes_[key]);
        else if constexpr (std::same_as<type_t, boolean_type>) return contains_key(key) && xtd::is<boolean_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, string_type> || xtd::is_string_literal<type_t>) return contains_key(key) && xtd::is<string_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, mapping_type>) return contains_key(key) && xtd::is<mapping_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, sequence_type>) return contains_key(key) && xtd::is<sequence_type>(nodes_[key]);
        else return false;
      }
      
      auto is_boolean(const xtd::string& key) const noexcept -> bool;
      auto is_integer(const xtd::string& key) const noexcept -> bool;
      auto is_floating_point(const xtd::string& key) const noexcept -> bool;
      auto is_mapping(const xtd::string& key) const -> bool;
      auto is_null(const xtd::string& key) const noexcept -> bool;
      auto is_sequence(const xtd::string& key) const -> bool;
      auto is_string(const xtd::string& key) const noexcept -> bool;
      /// @}
      
      /// @name Public Operators
      
      /// @{
      auto operator[](const xtd::string& key) const -> const xtd::any_object&;
      auto operator[](const xtd::string& key) -> xtd::any_object&;
      /// @}

    private:
      nodes_collection nodes_;
    };
  }
}
