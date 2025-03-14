/// @file
/// @brief Contains __opaque_xtd_linq_enumerable_collection__ <type_t> struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../collections/generic/enumerator.hpp"
#include "../collections/generic/ienumerable.hpp"
#include "../istringable.hpp"
#include <vector>

/// @cond
namespace xtd::linq {
  class enumerable;
};

template<class type_t, class param_t>
struct __opaque_xtd_linq_lazy_enumerable__ : xtd::collections::generic::ienumerable<type_t>, xtd::istringable {
  xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
    return {xtd::new_ptr<lazy_enumerator>(data_->params, data_->move_next, data_->reset)};
  }
  
  xtd::string to_string() const override;
  
private:
  friend class xtd::linq::enumerable;
  using param_type = param_t;
  using move_next_type = std::function<bool(param_type&)>;
  using reset_type = std::function<void(param_type&)>;

  __opaque_xtd_linq_lazy_enumerable__() = default;
  __opaque_xtd_linq_lazy_enumerable__(__opaque_xtd_linq_lazy_enumerable__&&) = default;
  __opaque_xtd_linq_lazy_enumerable__(const __opaque_xtd_linq_lazy_enumerable__&) = default;
  __opaque_xtd_linq_lazy_enumerable__& operator =(const __opaque_xtd_linq_lazy_enumerable__&) = default;
  __opaque_xtd_linq_lazy_enumerable__(const param_type& params, move_next_type move_next, reset_type reset) {
    data_->params = params;
    data_->move_next = move_next;
    data_->reset = reset;
  }
  
  struct lazy_enumerator : xtd::collections::generic::ienumerator<type_t> {
    lazy_enumerator(param_type& params, move_next_type& move_next, reset_type& reset) : params_ {params}, move_next_ {move_next}, reset_ {reset} {}
    
    const type_t& current() const override {
      return std::get<0>(params_);
    }
    bool move_next() override {
      return move_next_(params_);
    }
    void reset() override {
      reset_(params_);
    }

  private:
    param_type& params_;
    move_next_type& move_next_;
    reset_type& reset_;
  };
  
  struct data {
    param_type params;
    move_next_type move_next;
    reset_type reset;
  };
  
  mutable xtd::ptr<data> data_ = xtd::new_ptr<data>();
};

template<class type_t>
struct __opaque_xtd_linq_enumerable_collection__ : xtd::collections::generic::ienumerable<type_t>, xtd::istringable {
  xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
    return xtd::collections::generic::enumerator<>::create(items);
  }
  
  xtd::string to_string() const override;
  
private:
  friend class xtd::linq::enumerable;
  __opaque_xtd_linq_enumerable_collection__() = default;
  std::vector<type_t> items;
};
/// @endcond
