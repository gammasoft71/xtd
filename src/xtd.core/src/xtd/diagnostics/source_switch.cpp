#include "../../../include/xtd/diagnostics/source_switch.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

source_switch::source_switch(const ustring& name) : switch_base(name, "") {
}

source_switch::source_switch(const ustring& display_name, const ustring& default_switch_value) : switch_base(display_name, "", default_switch_value) {
}


source_levels source_switch::level() const {
  return static_cast<source_levels>(switch_setting());
}

void source_switch::level(xtd::diagnostics::source_levels level) {
  switch_setting(static_cast<int32_t>(level));
}


bool source_switch::should_trace(trace_event_type event_type) {
  return (switch_setting() & static_cast<int>(event_type)) != 0;
}


void source_switch::on_value_changed() {
  switch_setting(static_cast<int32_t>(parse<source_levels>(value())));
}
