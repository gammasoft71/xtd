/// @file
/// @brief Contains classes, structs and macros for enum introspection.
/// @remarks The enum introspection code is based on the Alecto project Irene Perez, NAV and is adapted for xtd.
/// @remarks NAV: Names and Values for Enumerations. Provides complete reflection capabilities on enums, including name lookup, value lookup, parsing functions (like charconv), and input validation
/// @copyright Copyright (c) 2022 Alecto Irene Perez. All rights reserved.
/// @see The original github project (https://github.com/codeinred/nav) for more information.
#pragma once

/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif

/// @brief The following definition activate the enum introspection.
/// @warning This code is not activated by default as long as the nav license is undefined.
/// @see https://choosealicense.com/no-permission/ for more information.
//#define __XTD_USE_ENUMERATION_INTROSPECTION__

#if !defined(__XTD_USE_ENUMERATION_INTROSPECTION__)
#define __enum_introspection__(namespace_name, enum_t, base_t, ...)
#else
#include <array>
#include <optional>
#include <string_view>
#include "../ustring.h"

namespace __enumeration_introspection {
  template <class enum_t>
  [[nodiscard]] constexpr bool name_of(enum_t value, std::string_view& destination, bool use_lowercase = false) noexcept;
  
  template <class enum_t>
  constexpr auto name_of(enum_t value, bool use_lowercase = false) noexcept -> std::optional<std::string_view>;
  
  template <class enum_t>
  [[nodiscard]] constexpr bool value_of(std::string_view name, enum_t& destination, bool ignore_case = false) noexcept;
  
  template <class enum_t>
  constexpr auto value_of(std::string_view name, bool ignore_case = false) noexcept -> std::optional<enum_t>;
  
  template <class type_t>
  constexpr std::string_view name_of_type = xtd::ustring::class_name<type_t>();

  namespace detail {
    template <class base_t>
    struct enum_maker {
      base_t value {};
      bool is_set = false;
      enum_maker() = default;
      enum_maker(enum_maker const&) = default;
      constexpr enum_maker(base_t) : enum_maker() {}
      enum_maker& operator =(enum_maker const&) = default;
      
      template <class type_t>
      constexpr enum_maker& operator =(type_t const& v) {
        value = base_t(v);
        is_set = true;
        return *this;
      }
      
      constexpr operator base_t() const {return value;}
      template <class type_t>
      constexpr explicit operator type_t() const {return type_t(value);}
    };
    
    template <class base_t>
    struct value_assigner {
      base_t value {};
      
      constexpr value_assigner& operator ,(enum_maker<base_t>& other) {
        if (other.is_set) value = other.value;
        else other = value;
        value++;
        return *this;
      }
    };
    
    constexpr std::string_view trim_whitespace(std::string_view view) {
      size_t start = view.find_first_not_of(' ');
      if (start == std::string_view::npos) return "";
      size_t end = view.find_first_of(" =", start);
      if (end == std::string_view::npos) return view.substr(start);
      return view.substr(start, end - start);
    }
    template <size_t count, size_t str_size, class function_t>
    constexpr void split_trim_apply(char const (&str)[str_size], function_t func) {
      std::string_view view(str, str_size - 1);
      
      for (size_t i = 0; i < count; i++) {
        auto new_pos = view.find(',');
        func(trim_whitespace(view.substr(0, new_pos)));
        if (new_pos != std::string_view::npos) view = view.substr(new_pos + 1);
        else break;
      }
    }
    template <size_t count, size_t str_size>
    constexpr size_t compute_name_block_size(char const (&str)[str_size]) {
      size_t total = 0;
      split_trim_apply<count>(str, [&](std::string_view sv) {total += sv.size();});
      return total;
    }
    template <size_t count, size_t str_size>
    constexpr void write_names_and_sizes(char const (&str)[str_size], char* destination, unsigned* offsets) {
      unsigned current_offset = 0;
      split_trim_apply<count>(str, [&](std::string_view sv) {
        char const* source = sv.data();
        size_t size = sv.size();
        for (size_t i = 0; i < size; i++)
          destination[i] = source[i];
        *offsets++ = current_offset;
        destination += size;
        current_offset += size;
      });
      *offsets = current_offset;
    }
    
    constexpr auto get_top_name(std::string_view view) {
      auto pos = view.find_last_of(':');
      if (pos == view.npos) return view;
      return view.substr(pos + 1);
    }
    template <size_t count>
    constexpr auto get_top_name(char const (&str)[count]) {return get_top_name(std::string_view(str, count - 1));}
  }

  class string_block_iterator {
    char const* data {};
    unsigned const* indices {};
    
  public:
    string_block_iterator() = default;
    string_block_iterator(string_block_iterator const&) = default;
    constexpr string_block_iterator(char const* data, unsigned const* indices) noexcept : data(data), indices(indices) {}
    
    constexpr string_block_iterator& operator ++() noexcept {
      indices++;
      return *this;
    }
    constexpr string_block_iterator operator ++(int) noexcept {
      string_block_iterator previous_state = *this;
      indices++;
      return previous_state;
    }
    constexpr intptr_t operator -(string_block_iterator const& other) const noexcept {return indices - other.indices;}
    constexpr bool operator ==(string_block_iterator const& other) const noexcept {return indices == other.indices;}
    constexpr bool operator !=(string_block_iterator const& other) const noexcept {return indices != other.indices;}
    constexpr auto operator *() const noexcept -> std::string_view {
      int off0 = indices[0];
      int off1 = indices[1];
      return std::string_view(data + off0, off1 - off0);
    }
  };
  
  template <size_t count, size_t blk_size>
  struct string_block {
    static_assert(blk_size >= count, "The size of the block must be greater than or equal to the number of strings");
    char data[blk_size] {};
    unsigned offsets[count + 1] {};
    string_block() = default;
    string_block(string_block const&) = default;
    
    template <class function_t>
    constexpr string_block(function_t&& func) : string_block() {func(*this);}
    
    template <class function_t>
    constexpr string_block(string_block const& source, function_t&& func) : string_block() {func(source, *this);}
    
    using iterator = string_block_iterator;
    using const_iterator = iterator;
    constexpr iterator begin() const noexcept {return iterator(data, offsets);}
    constexpr iterator end() const noexcept {return iterator(data, offsets + count);}
    constexpr static size_t size() noexcept {return count;}
    constexpr static size_t block_size() noexcept {return blk_size;}
    constexpr std::string_view operator [](size_t i) const noexcept {
      auto off1 = offsets[i];
      auto off2 = offsets[i + 1];
      return std::string_view(data + off1, off2 - off1);
    }
  };

  namespace detail {
    template <class enum_t>
    struct enum_type_info_base {
      constexpr static std::string_view qualified_type_name {name_of_type<enum_t>};
      constexpr static std::string_view type_name {get_top_name(name_of_type<enum_t>)};
      constexpr static size_t num_states = 0;
      constexpr static bool is_enumeration = false;
      constexpr static size_t size() noexcept {return 0;}
    };
    
    template <class enum_t>
    struct enum_value_list_base : enum_type_info_base<enum_t> {/*enum_t __enumeration_internal_values__[0] {};*/};
    
    template <class enum_t>
    struct enum_name_list_base : enum_type_info_base<enum_t> {
      using enum_type_info_base<enum_t>::num_states;
      constexpr static size_t name_block_size = 0;
      using block_type = string_block<num_states, name_block_size>;
      block_type name_block;
    };
  }

  template <class enum_t>
  struct enum_type_info : public detail::enum_type_info_base<enum_t> {
  private:
    using super = detail::enum_type_info_base<enum_t>;
    
  public:
    using super::is_enumeration;
    using super::num_states;
    using super::qualified_type_name;
    using super::size;
    using super::type_name;
  };
  
  template <class enum_t>
  struct enum_value_list : enum_type_info<enum_t> {
  private:
    constexpr static detail::enum_value_list_base<enum_t> values {};
    using super = enum_type_info<enum_t>;
    
  public:
    using iterator = enum_t const*;
    using const_iterator = enum_t const*;
    constexpr enum_t const* begin() const noexcept {return values.__enumeration_internal_values__;}
    constexpr enum_t const* end() const noexcept {return values.__enumeration_internal_values__ + super::num_states;}
    constexpr enum_t const& operator [](size_t i) const noexcept {return values.__enumeration_internal_values__[i];}
  };
  
  template <class enum_t>
  struct enum_name_list : enum_type_info<enum_t> {
  private:
    constexpr static detail::enum_name_list_base<enum_t> name_info {};
    using super = enum_type_info<enum_t>;
    
  public:
    using block_type = typename detail::enum_name_list_base<enum_t>::block_type;
    using iterator = string_block_iterator;
    using const_iterator = iterator;
    constexpr static block_type const& get_name_block() noexcept {return name_info.name_block;}
    constexpr iterator begin() const noexcept {return name_info.name_block.begin();}
    constexpr iterator end() const noexcept {return name_info.name_block.end();}
    constexpr std::string_view operator [](size_t i) const noexcept {return name_info.name_block[i];}
  };
  
  template <class enum_t>
  constexpr bool is_enumeration = enum_type_info<enum_t>::is_enumeration;
  
  template <class enum_t>
  constexpr size_t num_states = enum_type_info<enum_t>::num_states;
  
  template <class enum_t>
  constexpr enum_value_list<enum_t> enum_values {};
  
  template <class enum_t>
  constexpr enum_name_list<enum_t> enum_names {};
}

#define __enumeration_concat__(str1, str2) (#str1 "::" #str2)

#define __enum_introspection__(namespace_name, enum_t, base_t, ...) \
  namespace __enumeration_introspection::detail { \
    template <> struct enum_type_info_base<enum_t> { \
      using base_type = base_t; \
      constexpr static std::string_view qualified_type_name = __enumeration_concat__(namespace_name, enum_t); \
      constexpr static std::string_view type_name = get_top_name(__enumeration_concat__(namespace_name, enum_t)); \
      constexpr static bool is_enumeration = true; \
      constexpr static size_t num_states = []() -> size_t { \
        enum_maker<base_t> __VA_ARGS__; \
        enum_maker<base_t> NAV_DECLARE_ENUM_vals[] {__VA_ARGS__}; \
        return sizeof(NAV_DECLARE_ENUM_vals) / sizeof(enum_maker<base_t>); \
      }(); \
      constexpr static size_t size() noexcept {return num_states;} \
    }; \
    template <> struct enum_value_list_base<enum_t> : enum_type_info_base<enum_t> { \
      enum_t __enumeration_internal_values__[enum_type_info_base<enum_t>::num_states]; \
      constexpr enum_value_list_base() : __enumeration_internal_values__() { \
        enum_maker<base_t> __VA_ARGS__; \
        value_assigner<base_t> {}, __VA_ARGS__; \
        enum_maker<base_t> NAV_DECLARE_ENUM_vals[] {__VA_ARGS__}; \
        for (size_t i = 0; i < enum_type_info_base<enum_t>::num_states; i++) \
          this->__enumeration_internal_values__[i] = enum_t(NAV_DECLARE_ENUM_vals[i]); \
      } \
    }; \
    template <> struct enum_name_list_base<enum_t> : enum_type_info_base<enum_t> { \
      using enum_type_info_base<enum_t>::num_states; \
      constexpr static size_t name_block_size = compute_name_block_size<num_states>(#__VA_ARGS__); \
      using block_type = string_block<num_states, name_block_size>; \
      block_type name_block; \
      constexpr enum_name_list_base() : name_block([](auto& block) { \
        write_names_and_sizes<num_states>(#__VA_ARGS__, block.data, block.offsets); \
      }) {} \
    }; \
  }

#endif
/// @endcond
