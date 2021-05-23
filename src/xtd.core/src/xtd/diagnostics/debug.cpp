#include <cassert>

#include "../../../include/xtd/diagnostics/debug.h"
#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#include "../../../include/xtd/environment.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

extern trace_listener_collection __listeners__;
extern char** __diagnostics_argv;

bool debug::auto_flush_ = false;
unsigned int debug::indent_level_ = 0;
unsigned int debug::indent_size_ = 4;
trace_listener_collection& debug::listeners_ = __listeners__;
bool debug::use_global_lock_ = true;
mutex debug::global_lock_;
string debug::source_name_ = environment::get_command_line_args().size() == 0 ? "(unknown)" : environment::get_command_line_args()[0];
