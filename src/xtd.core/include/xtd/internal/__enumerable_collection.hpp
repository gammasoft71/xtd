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

template<class type_t, class param_t>
struct __opaque_xtd_linq_lazy_enumerable__ : xtd::collections::generic::ienumerable<type_t>, xtd::istringable {
  xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
    auto* self = const_cast<__opaque_xtd_linq_lazy_enumerable__*>(this);
    return {xtd::new_ptr<lazy_enumerator>(self->params, self->runner)};
  }
  
  xtd::string to_string() const override;
  
private:
  friend class xtd::linq::enumerable;
  using param_type = param_t;
  using runner_type = std::function<bool(param_type&)>;
  
  __opaque_xtd_linq_lazy_enumerable__() = default;
  __opaque_xtd_linq_lazy_enumerable__(__opaque_xtd_linq_lazy_enumerable__&&) = default;
  __opaque_xtd_linq_lazy_enumerable__(const __opaque_xtd_linq_lazy_enumerable__&) = default;
  __opaque_xtd_linq_lazy_enumerable__& operator =(const __opaque_xtd_linq_lazy_enumerable__&) = default;
  __opaque_xtd_linq_lazy_enumerable__(const param_type& params, runner_type runner) : params {params}, runner {runner} {}
  
  struct lazy_enumerator : xtd::collections::generic::ienumerator<type_t> {
    lazy_enumerator(const param_type& params, runner_type& runner) : original_params {params}, params {params}, runner {runner} {}
   
    const type_t& current() const override {return std::get<0>(params);}
    bool move_next() override {return runner(params);}
    void reset() override {params = original_params;}
    
    const param_type& original_params;
    param_type params;
    runner_type runner;
  };
  
  param_type params;
  runner_type runner;
};
/// @endcond
