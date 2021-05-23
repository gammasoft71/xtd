#include <cassert>
void __assert__(bool condition) {assert(condition);}

#include "../../../include/xtd/diagnostics/trace.h"
#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#include "../../../include/xtd/environment.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

trace_listener_collection __listeners__ {std::make_shared<xtd::diagnostics::default_trace_listener>()};

bool trace::auto_flush_ = false;
unsigned int trace::indent_level_ = 0;
unsigned int trace::indent_size_ = 4;
trace_listener_collection& trace::listeners_ = __listeners__;
bool trace::use_global_lock_ = true;
mutex trace::global_lock_;
string trace::source_name_ = environment::get_command_line_args().size() == 0 ? "(unknown)" : environment::get_command_line_args()[0];
