/// @file
/// @brief Contains xtd::linq::enumerable_collection <type_t> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../collections/generic/ienumerable.hpp"
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
    template<typename type_t>
    class enumerable_collection : public xtd::collections::generic::ienumerable<type_t> {
    public:
      xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
        class box_enumerator : public xtd::collections::generic::ienumerator<type_t> {
        public:
          explicit box_enumerator(const std::vector<type_t>& items) : items_(items) {}
          const type_t& current() const override {return items_[index_];}
          bool move_next() override {return ++index_ < items_.size();}
          void reset() override {index_ = std::numeric_limits<size>::max();}
          
        protected:
          const std::vector<type_t>& items_;
          size index_ = std::numeric_limits<size>::max();
        };
        return {new_ptr<box_enumerator>(enumerable_collection_)};
      }

    private:
      friend class xtd::linq::enumerable;
      
      void append(const type_t& item) noexcept {
        enumerable_collection_.push_back(item);
      }
      
      std::vector<type_t> enumerable_collection_;
    };
  }
}
