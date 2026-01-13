#include "../../../include/xtd/diagnostics/trace_listener_collection.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

trace_listener_collection::trace_listener_collection(const std::initializer_list<value_type>& il) : trace_listener_collection::base(il) {
}

trace_listener_collection::trace_listener_collection(const trace_listener_collection::base& collection) : trace_listener_collection::base(collection) {}
trace_listener_collection::trace_listener_collection(const trace_listener_collection& collection) : trace_listener_collection::base(collection) {}
trace_listener_collection& trace_listener_collection::operator =(const trace_listener_collection& collection) {
  base::operator =(collection);
  return *this;
}

auto trace_listener_collection::equals(const object& value) const noexcept -> bool {
  return is<trace_listener_collection>(value) && equals(static_cast<const trace_listener_collection&>(value));
}

auto trace_listener_collection::equals(const trace_listener_collection& value) const noexcept -> bool {
  return static_cast<const base&>(*this) == static_cast<const base&>(value);
}

auto trace_listener_collection::operator [](const string& name) const -> const_reference {
  for (auto& item : *this)
    if (item->name() == name) return item;
  return empty_;
}

auto trace_listener_collection::operator [](const string& name) -> reference {
  for (auto& item : *this)
    if (item->name() == name) return item;
  return empty_;
}
