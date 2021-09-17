#include "../../../include/xtd/diagnostics/trace_listener_collection.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

trace_listener_collection::trace_listener_collection(const trace_listener_collection::allocator_type& allocator) : trace_listener_collection::base(allocator) {
}

trace_listener_collection::trace_listener_collection(const std::initializer_list<value_type>& il) : trace_listener_collection::base(il) {
}

trace_listener_collection::trace_listener_collection(const trace_listener_collection::base& collection) : trace_listener_collection::base(collection) {}
trace_listener_collection::trace_listener_collection(const trace_listener_collection& collection) : trace_listener_collection::base(collection) {}
trace_listener_collection& trace_listener_collection::operator=(const trace_listener_collection& collection) {
  base::operator=(collection);
  return *this;
}

bool trace_listener_collection::operator==(const trace_listener_collection& value) const {
  return reinterpret_cast<const base&>(*this) == reinterpret_cast<const base&>(value);
}
bool trace_listener_collection::operator!=(const trace_listener_collection& value) const {
  return !operator==(value);
}

trace_listener_collection::const_reference trace_listener_collection::operator[](const ustring& name) const {
  for(auto& item : *this)
    if(item->name() == name) return item;
  return empty_;
}

trace_listener_collection::reference trace_listener_collection::operator[](const ustring& name) {
  for(auto& item : *this)
    if(item->name() == name) return item;
  return empty_;
}
