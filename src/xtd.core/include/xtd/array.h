/// @file
/// @brief Contains xtd::array class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__array_definition.h"
#undef __XTD_CORE_INTERNAL__
#include "collections/generic/enumerator.h"
#include "collections/generic/icomparer.h"
#include "collections/generic/ilist.h"
#include "core_export.h"
#include "new_ptr.h"
#include "object.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  class array_object : public xtd::object {
    template<typename type_t, typename allocator_t>
    friend class basic_array_object;
    
  public:
    array_object() = default;
  };

  template<typename type_t, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  class basic_array_object : public xtd::array_object, public xtd::collections::generic::ilist<type_t> {
    class comparer {
    public:
      comparer(const xtd::collections::generic::icomparer<type_t>* comparer) : comparer_(comparer) { }
      comparer(const comparer&) = default;
      comparer(comparer&&) = default;
      comparer& operator=(const comparer& comparer) = default;
      comparer& operator=(comparer&&) = default;
      
      bool operator()(const type_t& e1, const type_t& e2) const noexcept {return comparer_ && comparer_->compare(e1, e2) < 0;}
      
    private:
      const xtd::collections::generic::icomparer<type_t>* comparer_;
    };
    
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the list value type.
    using value_type = type_t;
    /// @brief Represents the list allocator type.
    using allocator_type = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, value_type>::value, xtd::byte, value_type>::type>;
    /// @brief Represents the list base type.
    using base_type = std::vector<typename std::conditional<std::is_same<bool, value_type>::value, xtd::byte, value_type>::type, allocator_type>;
    /// @brief Represents the list size type (usually xtd::size).
    using size_type = xtd::size;
    /// @brief Represents the list difference type (usually xtd::ptrdiff).
    using difference_type = xtd::ptrdiff;
    /// @brief Represents the reference of list value type.
    using reference = value_type&;
    /// @brief Represents the const reference of list value type.
    using const_reference = const value_type&;
    /// @brief Represents the pointer of list value type.
    using pointer = value_type*;
    /// @brief Represents the const pointer of list value type.
    using const_pointer = const value_type*;
    /// @brief Represents the iterator of list value type.
    using iterator = xtd::collections::generic::ilist<type_t>::iterator;
    /// @brief Represents the const iterator of list value type.
    using const_iterator = xtd::collections::generic::ilist<type_t>::const_iterator;
    /// @brief Represents the reverse iterator of list value type.
    using reverse_iterator = typename base_type::reverse_iterator;
    /// @brief Represents the const reverse iterator of list value type.
    using const_reverse_iterator = typename base_type::const_reverse_iterator;
    /// @}
    
    /// @name Public Fields
    
    /// @{
    /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
    inline static constexpr xtd::size npos = xtd::collections::generic::ilist<type_t>::npos;
    /// @}
    
    /// @name Public Constructors
    
    /// @{

  private:
    template<typename type_array_t, xtd::size rank_array_t, typename allocator_array_t>
    friend class array_;
    
    basic_array_object() = default;
    basic_array_object(const array_<size_type, 1>& lengths);
    
    basic_array_object(const_pointer array, xtd::size length) {
      //if (array == null) throw xtd::argument_null_exception(csf_);
      data_->array = base_type {array, length};
      data_->upper_bound[0] = length - 1;
    }
    
    struct data {
      size_type version = 0;
      base_type array;
      std::vector<size_type> lower_bound {0};
      std::vector<size_type> upper_bound {std::numeric_limits<xtd::size>::max()};
      object sync_root;
    };
    
    xtd::ptr<struct data> data_ = xtd::new_ptr<struct data>();
  };
}

#define __XTD_ARRAY_INTERNAL__
#include "array.hpp"
#undef __XTD_ARRAY_INTERNAL__
