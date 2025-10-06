#include "../../../include/xtd/collections/specialized/string_dictionary.hpp"
#include "../../../include/xtd/configuration/file_settings.hpp"
#include "../../../include/xtd/diagnostics/console_trace_listener.hpp"
#include "../../../include/xtd/diagnostics/default_trace_listener.hpp"
#include "../../../include/xtd/diagnostics/ostream_trace_listener.hpp"
#include "../../../include/xtd/diagnostics/trace_listener_collection.hpp"
#include "../../../include/xtd/helpers/throw_helper.hpp"
#include "../../../include/xtd/reflection/assembly.hpp"
#include "../../../include/xtd/call_once.hpp"
#include "../../../include/xtd/environment.hpp"

using namespace xtd;
using namespace xtd::collections::specialized;
using namespace xtd::diagnostics;
using namespace xtd::helpers;
using namespace xtd::io;
using namespace xtd::reflection;

namespace {
  static const auto empty_diagnostics_content = {
    "# ============================================================================",
    "#  xtd::diagnostics configuration file",
    "#  Define and customize diagnostic listeners and switches",
    "# ============================================================================",
    "",
    "",
    "# --------------------------------------------------------------------------",
    "# Listeners",
    "# --------------------------------------------------------------------------",
    "# Define trace listeners.",
    "# Each entry has the form:",
    "#   name = \"key1=value1;key2=value2;...\"",
    "#",
    "# Available listener types:",
    "#   - type=default   : writes to system debugger/log (default)",
    "#   - type=console   : writes to console output/error",
    "#   - type=file      : writes to a log file",
    "#",
    "# Common options:",
    "#   indent_size=N            : number of spaces for indentation (default=4)",
    "#   trace_option=options     : A combination of : none, logical_operation_stack,",
    "#                              date_time, timestamp, process_id, thread_id,",
    "#                              callstack. ",
    "#                              Options must be separated by a comma (,).",
    "#",
    "# default listener specific options:",
    "#   log=file_path            : add log file path",
    "#",
    "# console listener specific options:",
    "#   error_stream=true/false  : use stderr instead of stdout",
    "#",
    "# file listener specific options:",
    "#   append=true/false        : append to file (default=true)",
    "#   path=file_path           : add log file path",
    "#",
    "# Examples:",
    "# [listeners]",
    "# console_listener = \"type=console;error_stream=true\"",
    "# file_listener = \"type=file;path=app.log;append=true;\"",
    "# default = \"type=default;log=default.log\"",
    "# --------------------------------------------------------------------------",
    "",
    "[listeners]",
    "",
    "# --------------------------------------------------------------------------",
    "# Switches",
    "# --------------------------------------------------------------------------",
    "# Define diagnostics switches.",
    "# Each switch is simply \"name = value\".",
    "#",
    "# Available xtd switch types:",
    "#   BooleanSwitch : true/false",
    "#   SourceSwitch  : off, critical, error, warning, information, verbose,",
    "#                   activity_tracing, all (or numeric levels)",
    "#   TraceSwitch   : off, error, warning, info, verbose (or numeric levels)",
    "#",
    "# Notes: User switch types can also be used.",
    "#",
    "# Examples:",
    "# [switches]",
    "# network_switch = warning",
    "# ui_switch = verbose",
    "# feature_x = true",
    "# --------------------------------------------------------------------------",
    "",
    "[switches]"
  };
}

const std::tuple<const trace_listener_collection&, const string_dictionary&>& __xtd___read_diagnostics_config__() {
  static auto listeners = trace_listener_collection {};
  static auto switches = string_dictionary {};
  call_once_ {
    auto product_name = assembly::get_executing_assembly().product() != string::empty_string ? assembly::get_executing_assembly().product() : path::get_file_name_without_extension(assembly::get_executing_assembly().location());
    auto company_name = assembly::get_executing_assembly().company() != string::empty_string ? assembly::get_executing_assembly().company() : product_name;
    auto file_path = path::combine(environment::get_folder_path(environment::special_folder::application_data), company_name);
    if (!directory::exists(file_path)) directory::create_directory(file_path);
    auto file_name = path::combine(file_path, product_name + ".diagnostics.config");
    if (!file::exists(file_name)) file::write_all_lines(file_name, empty_diagnostics_content);
    else {
      auto file_settings = configuration::file_settings(file_name);
      // listeners
      for (const auto& [key, value] : file_settings.key_values("listeners")) {
        auto key_values = value.split(';', string_split_options::remove_empty_entries);
        auto sub_key_values = string_dictionary {};
        for (const auto& key_value : key_values) {
          auto parts = key_value.split('=');
          if (parts.length() != 2) throw_helper::throws(xtd::helpers::exception_case::format);
          sub_key_values[parts[0].trim()] = parts[1].trim();
        }
        if (!sub_key_values.contains_key("type")) throw_helper::throws(xtd::helpers::exception_case::format);
        auto listener = ptr<trace_listener> {};
        if (sub_key_values["type"] == "default")
          listener = new_ptr<default_trace_listener>(sub_key_values.contains_key("log") ? sub_key_values["log"] : "");
        else if (sub_key_values["type"] == "console")
          listener = new_ptr<console_trace_listener>(sub_key_values.contains_key("error_stream") ? as<bool>(sub_key_values["error_stream"]) : false);
        else if (sub_key_values["type"] == "file" && sub_key_values.contains_key("path"))
          listener = new_ptr<ostream_trace_listener>((sub_key_values.contains_key("append") ? as<bool>(sub_key_values["append"]) : false) ? file::append_text(sub_key_values["path"]) : file::write_text(sub_key_values["path"]));
        else throw_helper::throws(xtd::helpers::exception_case::format);
        listener->name(key);
        listeners.add(listener);
      }
      
      // switches
      for (const auto& [key, value] : file_settings.key_values("switches"))
        switches[key] = value;
    }
    
    if (!listeners.count()) listeners.add(xtd::new_sptr<default_trace_listener>());
  };
  static auto result = std::tuple<const trace_listener_collection&, const string_dictionary&> {listeners, switches};
  return result;
}
