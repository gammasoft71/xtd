#include "../../../include/xtd/forms/enable_debug.h"

using namespace xtd::diagnostics;
using namespace xtd::forms;

const enable_debug enable_debug::none {0};
const enable_debug enable_debug::events {0b1};
const enable_debug enable_debug::key_events {0b10};
const enable_debug enable_debug::mouse_events {0b100};
const enable_debug enable_debug::layout {0b1000};
const enable_debug enable_debug::workaround {0b10000};
const enable_debug enable_debug::all {0b1111111111111111111111111111111111111111111111111111111111111111};

trace_switch enable_debug::trace_switch_ {"trace_switch_xtd_forms", "The trace switch for xtd forms library"};
enable_debug enable_debug::values_;
