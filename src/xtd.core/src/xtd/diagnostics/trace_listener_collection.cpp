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

bool trace_listener_collection::equals(const object& value) const noexcept {
  return is<trace_listener_collection>(value) && equals(static_cast<const trace_listener_collection&>(value));
}

bool trace_listener_collection::equals(const trace_listener_collection& value) const noexcept {
  return static_cast<const base&>(*this) == static_cast<const base&>(value);
}

trace_listener_collection::const_reference trace_listener_collection::operator [](const string& name) const {
  for (auto& item : *this)
    if (item->name() == name) return item;
  return empty_;
}

trace_listener_collection::reference trace_listener_collection::operator [](const string& name) {
  for (auto& item : *this)
    if (item->name() == name) return item;
  return empty_;
}
