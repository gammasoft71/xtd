/// @file
/// @brief Contains xtd::linq::enumerable_collection <type_t> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/helpers/allocator.hpp"
#include "../collections/generic/ienumerable.hpp"
#include "../collections/generic/extensions/enumerable.hpp"
#include "../new_ptr.hpp"
#include <limits>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
  namespace linq {
    /// @cond
    class enumerable;
    /// @endcond
    
    /// @brief Represent an enumerable collection.
    /// @par Definition
    /// ```cpp
    /// template<typename type_t>
    /// class enumerable_collection : public xtd::collections::generic::ienumerable<type_t>
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/linq/enumerable_collection
    /// ```
    /// @par Namespace
    /// xtd::linq
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core linq
    template<typename type_t, typename allocator_t>
    class enumerable_collection : public xtd::collections::generic::extensions::enumerable<enumerable_collection<type_t, allocator_t>, type_t>, public xtd::collections::generic::ienumerable<type_t> {
    public:
      xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
        struct box_enumerator : xtd::collections::generic::ienumerator<type_t> {
          explicit box_enumerator(const collection_type& items) : items {items} {}
          const type_t& current() const override {return items[index];}
          bool move_next() override {return ++index < items.size();}
          void reset() override {index = npos;}
          
        private:
          const collection_type& items;
          xtd::size index = npos;
        };
        return {new_ptr<box_enumerator>(items)};
      }

    private:
      friend class xtd::linq::enumerable;
      using collection_type = std::vector<type_t, allocator_t>;
      static constexpr xtd::size npos = std::numeric_limits<xtd::size>::max();
      collection_type items;
    };
  }
}
