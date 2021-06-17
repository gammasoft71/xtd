#include "../../../include/xtd/diagnostics/stack_frame.h"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

stack_frame::~stack_frame() {
}

size_t stack_frame::get_file_column_number() const {
  return file_column_;
}

size_t stack_frame::get_file_line_number() const {
  return file_line_;
}

const string& stack_frame::get_file_name() const {
  return file_path_;
}

const string& stack_frame::get_method() const {
  return method_name_;
}

size_t stack_frame::get_offset() const {
  return offset_;
}

string stack_frame::to_string() const {
  return strings::format("{} at {}  in file:line:column {} : {} : {}", method_name_.empty() ? "<unknown method>" : method_name_, file_path_.empty() ? "<unknown offset>" : std::to_string(offset_), file_path_.empty() ? "<filename unknown>" : file_path_, file_line_, file_column_);
}

//friend ostream& operator<<(ostream& os, const stack_frame& stack_frame) noexcept {
//  return os << stack_frame.to_string();
//}

stack_frame::stack_frame(const string& file_path, size_t file_line, size_t file_column, const string& method_name, size_t offset) : file_path_(file_path), file_line_(file_line), file_column_(file_column), method_name_(method_name), offset_(offset) {
}

stack_frame::stack_frame(const string& method_name, size_t offset) : method_name_(method_name), offset_(offset) {
}
