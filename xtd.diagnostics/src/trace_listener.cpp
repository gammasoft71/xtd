#include "../include/xtd/diagnostics/trace_listener.hpp"
#include <xtd/xtd.strings>

xtd::diagnostics::trace_listener::trace_listener(const std::string& name) {
  this->data_->name_ = name;
}

void xtd::diagnostics::trace_listener::trace_listener::close() {
  this->flush();
}

void xtd::diagnostics::trace_listener::fail(const std::string& message) {
  write_line(xtd::strings::format("Fail: {}", message));
}

void xtd::diagnostics::trace_listener::fail(const std::string& message, const std::string& detail_message) {
  write_line(xtd::strings::format("Fail: {} {}", message, detail_message));
}

void xtd::diagnostics::trace_listener::trace_listener::flush() {
}

void xtd::diagnostics::trace_listener::trace_listener::trace_event(const xtd::diagnostics::trace_event_cache& event_cache, const std::string& source, const xtd::diagnostics::trace_event_type& event_type, int id) {
  this->write_line(xtd::strings::format("{} {}: {}", source, event_type, id));
  this->write_event_cache(event_cache);
}

void xtd::diagnostics::trace_listener::trace_listener::trace_event(const xtd::diagnostics::trace_event_cache& event_cache, const std::string& source, const xtd::diagnostics::trace_event_type& event_type, int id, const std::string& message) {
  this->write_line(xtd::strings::format("{} {}: {} : {}", source, event_type, id, message));
  this->write_event_cache(event_cache);
}

void xtd::diagnostics::trace_listener::trace_listener::trace_transfert(const xtd::diagnostics::trace_event_cache& event_cache, const std::string& source, int id, const std::string& message, const xtd::guid& related_activity_id) {
  this->write_line(xtd::strings::format("{} Transfert: {} : {}, related_activity_id={}", source, id, message, related_activity_id));
  this->write_event_cache(event_cache);
}

void xtd::diagnostics::trace_listener::trace_listener::write_indent() {
  this->data_->need_indent_ = false;
  for (int i = 0; i < this->data_->indent_level_; ++i)
    this->write(std::string(this->data_->indent_size_, ' '));
}

void xtd::diagnostics::trace_listener::trace_listener::write_event_cache(const xtd::diagnostics::trace_event_cache& event_cache) {
  if (((int)this->data_->trace_output_options_ & (int)xtd::diagnostics::trace_options::process_id) == (int)xtd::diagnostics::trace_options::process_id)
    this->write_line(xtd::strings::format("{0}ProcessId={1}", std::string(this->data_->indent_size_, ' '), event_cache.process_id()));
  if (((int)this->data_->trace_output_options_ & (int)xtd::diagnostics::trace_options::logical_operation_stack) == (int)xtd::diagnostics::trace_options::logical_operation_stack)
    this->write_line(xtd::strings::format("{0}LogicalOperationStack={1}", std::string(this->data_->indent_size_, ' '), xtd::strings::join(", ", event_cache.logical_operation_stack())));
  if (((int)this->data_->trace_output_options_ & (int)xtd::diagnostics::trace_options::thread_id) == (int)xtd::diagnostics::trace_options::thread_id)
    this->write_line(xtd::strings::format("{0}ThreadId={1}", std::string(this->data_->indent_size_, ' '), event_cache.thread_id()));
  /*
  if (((int)this->data_->trace_output_options_ & (int)xtd::diagnostics::trace_options::date_time) == (int)xtd::diagnostics::trace_options::date_time)
    this->write_line(xtd::strings::format("{0}DateTime={1:D}T{1:T}", std::string(this->data_->indent_size_, ' '), event_cache.date_time()));
   */
  if (((int)this->data_->trace_output_options_ & (int)xtd::diagnostics::trace_options::timestamp) == (int)xtd::diagnostics::trace_options::timestamp)
    this->write_line(xtd::strings::format("{0}Timestamp={1}", std::string(this->data_->indent_size_, ' '), event_cache.timestamp()));
  if (((int)this->data_->trace_output_options_ & (int)xtd::diagnostics::trace_options::callstack) == (int)xtd::diagnostics::trace_options::callstack)
    this->write_line(xtd::strings::format("{0}Callstack={1}", std::string(this->data_->indent_size_, ' '), event_cache.call_stack()));
}
