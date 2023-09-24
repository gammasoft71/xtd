#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif

#if !defined(__XTD_USE_ENUMERATION_INTROSPECTION__)
#define __enum_introspection__(namespace_name, enum_t, base_t, ...)
#else
#include <string_view>
#include "../typeof"
#include "../types"
#include "../ustring"

namespace __enumeration_introspection {
  constexpr std::string_view trim(std::string_view view) {
    size_t start = view.find_first_not_of(' ');
    if (start == std::string_view::npos) return "";
    size_t end = view.find_first_of(" =", start);
    if (end == std::string_view::npos) return view.substr(start);
    return view.substr(start, end - start);
  }
  
  template <size_t count, size_t str_size, class function_t>
  constexpr void split_trim_apply(char const(&str)[str_size], function_t func) {
    std::string_view view(str, str_size - 1);
    
    for (size_t i = 0; i < count; i++) {
      auto new_pos = view.find(',');
      func(trim(view.substr(0, new_pos)));
      if (new_pos != std::string_view::npos) view = view.substr(new_pos + 1);
      else break;
    }
  }
  
  template <size_t count, size_t str_size>
  constexpr size_t compute_name_block_size(char const(&str)[str_size]) {
    size_t total = 0;
    split_trim_apply<count>(str, [&](std::string_view sv) {total += sv.size();});
    return total;
  }
  
  template <size_t count, size_t str_size>
  constexpr void write_names_and_sizes(char const(&str)[str_size], char* destination, unsigned* offsets) {
    size_t current_offset = 0;
    split_trim_apply<count>(str, [&](std::string_view sv) {
      char const* source = sv.data();
      size_t size = sv.size();
      for (size_t i = 0; i < size; i++)
        destination[i] = source[i];
      *offsets++ = static_cast<unsigned>(current_offset);
      destination += size; // Known errors with assignment pointer parameter.
      current_offset += size;
    });
    *offsets = static_cast<unsigned>(current_offset);
  }
  
  constexpr auto get_top_name(std::string_view view) {
    auto pos = view.find_last_of(':');
    if (pos == view.npos) return view;
    return view.substr(pos + 1);
  }
  
  template <size_t count>
  constexpr auto get_top_name(char const(&str)[count]) {return get_top_name(std::string_view(str, count - 1));}
  
  template <class base_t>
  struct enumeration_maker {
    base_t value {};
    bool is_set = false;
    enumeration_maker() = default;
    enumeration_maker(enumeration_maker const&) = default;
    constexpr enumeration_maker(base_t) : enumeration_maker() {} // Can't be explicit by design.
    enumeration_maker& operator =(enumeration_maker const&) = default;
    
    template <class type_t>
    constexpr enumeration_maker& operator =(type_t const& v) {
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
    
    constexpr value_assigner& operator, (enumeration_maker<base_t>& other) {
      if (other.is_set) value = other.value;
      else other = value;
      ++value;
      return *this;
    }
  };
  
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
    constexpr xtd::intptr operator -(string_block_iterator const& other) const noexcept {return indices - other.indices;}
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
    char data[blk_size] {};
    unsigned offsets[count + 1] {};
    string_block() = default;
    string_block(string_block const&) = default;
    
    template <class function_t>
    explicit constexpr string_block(function_t&& func) : string_block() {func(*this);}
    
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
  
  template <class type_t>
  constexpr std::string_view name_of_type = typeof_<type_t>().name();
  
  template <class enum_t>
  struct enum_type_info_base {
    constexpr static std::string_view qualified_type_name {name_of_type<enum_t>};
    constexpr static std::string_view type_name {get_top_name(name_of_type<enum_t>)};
    constexpr static size_t num_states = 0;
    constexpr static size_t size() noexcept {return 0;}
  };
  
  template <class enum_t>
  struct enum_value_list_base : enum_type_info_base<enum_t> {};
  
  template <class enum_t>
  struct enum_name_list_base : enum_type_info_base<enum_t> {
    using enum_type_info_base<enum_t>::num_states;
    constexpr static size_t name_block_size = 0;
    using block_type = string_block<num_states, name_block_size>;
    block_type name_block;
  };
  
  template <class enum_t>
  struct enum_type_info : public enum_type_info_base<enum_t> {
  private:
    using super = enum_type_info_base<enum_t>;
    
  public:
    using super::num_states;
    using super::qualified_type_name;
    using super::size;
    using super::type_name;
  };
  
  template <class enum_t>
  struct enum_value_list : enum_type_info<enum_t> {
  private:
    constexpr static enum_value_list_base<enum_t> values {};
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
    constexpr static enum_name_list_base<enum_t> name_info {};
    using super = enum_type_info<enum_t>;
    
  public:
    using block_type = typename enum_name_list_base<enum_t>::block_type;
    using iterator = string_block_iterator;
    using const_iterator = iterator;
    constexpr static block_type const& get_name_block() noexcept {return name_info.name_block;}
    constexpr iterator begin() const noexcept {return name_info.name_block.begin();}
    constexpr iterator end() const noexcept {return name_info.name_block.end();}
    constexpr std::string_view operator [](size_t i) const noexcept {return name_info.name_block[i];}
  };
  
  template <class enum_t>
  constexpr size_t num_states = enum_type_info<enum_t>::num_states;
  
  template <class enum_t>
  constexpr enum_value_list<enum_t> enum_values {};
  
  template <class enum_t>
  constexpr enum_name_list<enum_t> enum_names {};
}

#define __enum_introspection_concat__(str1, str2) (#str1 "::" #str2)

#define __enum_introspection__(namespace_name, enum_t, base_t, ...) \
  namespace __enumeration_introspection { \
    template <> struct enum_type_info_base<enum_t> { \
      using base_type = base_t; \
      [[maybe_unused]] constexpr static std::string_view qualified_type_name = __enum_introspection_concat__(namespace_name, enum_t); \
      [[maybe_unused]] constexpr static std::string_view type_name = get_top_name(__enum_introspection_concat__(namespace_name, enum_t)); \
      constexpr static size_t num_states = []() -> size_t { \
        enumeration_maker<base_t> __VA_ARGS__; \
        enumeration_maker<base_t> __enum_introspection_vals[] {__VA_ARGS__}; \
        return sizeof(__enum_introspection_vals) / sizeof(enumeration_maker<base_t>); \
      }(); \
      constexpr static size_t size() noexcept {return num_states;} \
    }; \
    template <> struct enum_value_list_base<enum_t> : enum_type_info_base<enum_t> { \
      enum_t __enumeration_internal_values__[enum_type_info_base<enum_t>::num_states]; \
      constexpr enum_value_list_base() : __enumeration_internal_values__() { \
        enumeration_maker<base_t> __VA_ARGS__; \
        value_assigner<base_t> {}, __VA_ARGS__; \
        enumeration_maker<base_t> __enum_introspection_vals[] {__VA_ARGS__}; \
        for (size_t i = 0; i < enum_type_info_base<enum_t>::num_states; i++) \
          this->__enumeration_internal_values__[i] = enum_t(__enum_introspection_vals[i]); \
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
