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
    /// | type                | check                                             | convert                                                        |
    /// | ------------------- | ------------------------------------------------- | -------------------------------------------------------------- |
    /// | null_type           | `xtd::is<yaml::null_type>(yaml["key"])`           | `auto value = xtd::as<yaml::null_type>(yaml["key"])`           |
    /// | boolean_type        | `xtd::is<yaml::boolean_type>(yaml["key"])`        | `auto value = xtd::as<yaml::boolean_type>(yaml["key"])`        |
    /// | integer_type        | `xtd::is<yaml::integer_type>(yaml["key"])`        | `auto value = xtd::as<yaml::integer_type>(yaml["key"])`        |
    /// | floating_point_type | `xtd::is<yaml::floating_point_type>(yaml["key"])` | `auto value = xtd::as<yaml::floating_point_type>(yaml["key"])` |
    /// | string_type         | `xtd::is<yaml::string_type>(yaml["key"])`         | `auto value = xtd::as<yaml::string_type>(yaml["key"])`         |
    /// | sequence_type       | `xtd::is<yaml::sequence_type>(yaml["key"])`       | `auto value = xtd::as<yaml::sequence_type>(yaml["key"])`       |
    /// | mapping_type        | `xtd::is<yaml::mapping_type>(yaml["key"])`        | `auto value = xtd::as<yaml::mapping_type>(yaml["key"])`        |
    /// | null                | `xtd::is<null>(yaml["key"])`                      | `auto value = xtd::as<null>(yaml["key"])`                      |
    /// | bool                | `xtd::is<bool>(yaml["key"])`                      | `auto value = xtd::as<bool>(yaml["key"])`                      |
    /// | byte                | `xtd::is<byte>(yaml["key"])`                      | `auto value = xtd::as<byte>(yaml["key"])`                      |
    /// | decimal             | `xtd::is<decimal>(yaml["key"])`                   | `auto value = xtd::as<decimal>(yaml["key"])`                   |
    /// | double              | `xtd::is<double>(yaml["key"])`                    | `auto value = xtd::as<double>(yaml["key"])`                    |
    /// | int16               | `xtd::is<int16>(yaml["key"])`                     | `auto value = xtd::as<int16>(yaml["key"])`                     |
    /// | int32               | `xtd::is<int32>(yaml["key"])`                     | `auto value = xtd::as<int32>(yaml["key"])`                     |
    /// | int64               | `xtd::is<int64>(yaml["key"])`                     | `auto value = xtd::as<int64>(yaml["key"])`                     |
    /// | sbyte               | `xtd::is<sbyte>(yaml["key"])`                     | `auto value = xtd::as<sbyte>(yaml["key"])`                     |
    /// | single              | `xtd::is<single>(yaml["key"])`                    | `auto value = xtd::as<single>(yaml["key"])`                    |
    /// | string              | `xtd::is<string>(yaml["key"])`                    | `auto value = xtd::as<string>(yaml["key"])`                    |
    /// | uint16              | `xtd::is<uint16>(yaml["key"])`                    | `auto value = xtd::as<uint16>(yaml["key"])`                    |
    /// | uint32              | `xtd::is<uint32>(yaml["key"])`                    | `auto value = xtd::as<uint32>(yaml["key"])`                    |
    /// | uint64              | `xtd::is<uint64>(yaml["key"])`                    | `auto value = xtd::as<uint64>(yaml["key"])`                    |
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
      yaml(const nodes_collection& nodes) : nodes_ {nodes} {}
      yaml(nodes_collection&& nodes) : nodes_ {std::move(nodes)} {}
      yaml(const yaml&)  = default;
      yaml(yaml&&) = default;
      yaml& operator =(const yaml&)  = default;
      yaml& operator =(yaml&&)  = default;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      auto nodes() const noexcept -> const nodes_collection& {return nodes_;}
      auto nodes() noexcept -> nodes_collection& {return nodes_;}
      auto nodes(const nodes_collection& nodes) noexcept -> void {nodes_ = nodes;}
      /// @}
      
      /// @name Public Metdods
      
      /// @{
      template<class type_t>
      auto as(const xtd::string& key) const -> type_t {
        if constexpr (std::floating_point<type_t>) return xtd::as<type_t>(as_floating_point(key));
        else if constexpr (std::integral<type_t> && !std::same_as<type_t, boolean_type>) return xtd::as<type_t>(as_integer(key));
        else if constexpr (std::same_as<type_t, null_type>) return nullptr;
        else if constexpr (std::same_as<type_t, boolean_type>) return xtd::as<boolean_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, string_type> || xtd::is_string_literal<type_t>) return xtd::as<string_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, mapping_type>) return xtd::as<mapping_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, sequence_type>) return xtd::as<sequence_type>(nodes_[key]);
        else xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
      }

      auto as_boolean(const xtd::string& key) const -> boolean_type {return xtd::as<boolean_type>(nodes_[key]);}
      auto as_byte(const xtd::string& key) const -> xtd::byte {return xtd::as<xtd::byte>(as_integer(key));}
      auto as_decimal(const xtd::string& key) const -> xtd::decimal {return xtd::as<xtd::decimal>(as_floating_point(key));}
      auto as_double(const xtd::string& key) const -> xtd::double_ {return xtd::as<double>(as_floating_point(key));}
      auto as_int16(const xtd::string& key) const -> xtd::int16 {return xtd::as<xtd::int16>(as_integer(key));}
      auto as_int32(const xtd::string& key) const -> xtd::int32 {return xtd::as<xtd::int32>(as_integer(key));}
      auto as_int64(const xtd::string& key) const -> xtd::int64 {return xtd::as<xtd::int64>(as_integer(key));}
      auto as_integer(const xtd::string& key) const -> integer_type {return xtd::as<integer_type>(nodes_[key]);}
      auto as_floating_point(const xtd::string& key) const -> floating_point_type {return xtd::as<floating_point_type>(nodes_[key]);}
      auto as_mapping(const xtd::string& key) const -> mapping_type {return xtd::as<mapping_type>(nodes_[key]);}
      auto as_null(const xtd::string& key) const -> null_type {
        if (!is<null_type>(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
        return nullptr;
      }
      auto as_sbyte(const xtd::string& key) const -> xtd::sbyte {return xtd::as<xtd::sbyte>(as_integer(key));}
      auto as_sequence(const xtd::string& key) const -> sequence_type {return xtd::as<sequence_type>(nodes_[key]);}
      auto as_single(const xtd::string& key) const -> xtd::single {return xtd::as<xtd::single>(as_floating_point(key));}
      auto as_slong(const xtd::string& key) const -> xtd::slong {return xtd::as<xtd::slong>(as_integer(key));}
      auto as_string(const xtd::string& key) const -> string_type {return xtd::as<string_type>(nodes_[key]);}
      auto as_uint16(const xtd::string& key) const -> xtd::uint16 {return xtd::as<xtd::uint16>(as_integer(key));}
      auto as_uint32(const xtd::string& key) const -> xtd::uint32 {return xtd::as<xtd::uint32>(as_integer(key));}
      auto as_uint64(const xtd::string& key) const -> xtd::uint64 {return xtd::as<xtd::uint64>(as_integer(key));}
      auto as_ulong(const xtd::string& key) const -> xtd::ulong {return xtd::as<xtd::ulong>(as_integer(key));}

      auto contains_key(const xtd::string& key) const noexcept -> bool {return nodes().contains_key(key);}
      
      template<class type_t>
      auto is(const xtd::string& key) const -> bool {
        if constexpr (std::floating_point<type_t>) return is_floating_point(key) && xtd::box_floating_point<type_t>::is_valid(as_floating_point(key));
        else if constexpr (std::integral<type_t> && !std::same_as<type_t, boolean_type>) return is_integer(key) && xtd::box_integer<type_t>::is_valid(as_integer(key));
        else if constexpr (std::same_as<type_t, null_type>) return contains_key(key) && nodes_[key] == xtd::null;
        else if constexpr (std::same_as<type_t, boolean_type>) return contains_key(key) && xtd::is<boolean_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, string_type> || xtd::is_string_literal<type_t>) return contains_key(key) && xtd::is<string_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, mapping_type>) return contains_key(key) && xtd::is<mapping_type>(nodes_[key]);
        else if constexpr (std::same_as<type_t, sequence_type>) return contains_key(key) && xtd::is<sequence_type>(nodes_[key]);
        else return false;
      }
      
      auto is_boolean(const xtd::string& key) const noexcept -> bool {return contains_key(key) && xtd::is<boolean_type>(nodes_[key]);}
      auto is_byte(const xtd::string& key) const -> bool {return is_integer(key) && xtd::byte_object::is_valid(as_integer(key));}
      auto is_decimal(const xtd::string& key) const -> bool {return is_floating_point(key) && xtd::decimal_object::is_valid(as_floating_point(key));}
      auto is_double(const xtd::string& key) const -> bool {return is_floating_point(key) && xtd::double_object::is_valid(as_floating_point(key));}
      auto is_int16(const xtd::string& key) const -> bool {return is_integer(key) && xtd::int16_object::is_valid(as_integer(key));}
      auto is_int32(const xtd::string& key) const -> bool {return is_integer(key) && xtd::int32_object::is_valid(as_integer(key));}
      auto is_int64(const xtd::string& key) const -> bool {return is_integer(key) && xtd::int64_object::is_valid(as_integer(key));}
      auto is_integer(const xtd::string& key) const noexcept -> bool {return contains_key(key) && xtd::is<integer_type>(nodes_[key]);}
      auto is_floating_point(const xtd::string& key) const noexcept -> bool {return contains_key(key) && xtd::is<floating_point_type>(nodes_[key]);}
      auto is_mapping(const xtd::string& key) const -> bool {return contains_key(key) && xtd::is<mapping_type>(nodes_[key]);}
      auto is_null(const xtd::string& key) const noexcept -> bool {return contains_key(key) && nodes_[key] == xtd::null;}
      auto is_sbyte(const xtd::string& key) const -> bool {return is_integer(key) && xtd::sbyte_object::is_valid(as_integer(key));}
      auto is_sequence(const xtd::string& key) const -> bool {return contains_key(key) && xtd::is<sequence_type>(nodes_[key]);}
      auto is_single(const xtd::string& key) const -> bool {return is_floating_point(key) && xtd::single_object::is_valid(as_floating_point(key));}
      auto is_string(const xtd::string& key) const noexcept -> bool {return contains_key(key) && xtd::is<string_type>(nodes_[key]);}
      auto is_uint16(const xtd::string& key) const -> bool {return is_integer(key) && xtd::uint16_object::is_valid(as_integer(key));}
      auto is_uint32(const xtd::string& key) const -> bool {return is_integer(key) && xtd::uint32_object::is_valid(as_integer(key));}
      auto is_uint64(const xtd::string& key) const -> bool {return is_integer(key) && xtd::uint64_object::is_valid(as_integer(key));}
      /// @}
      
      /// @name Public Operators
      
      /// @{
      auto operator[](const xtd::string& key) const -> const xtd::any_object& {return nodes_[key];}
      auto operator[](const xtd::string& key) -> xtd::any_object& {return nodes_[key];}
      /// @}

    private:
      nodes_collection nodes_;
    };
  }
}
