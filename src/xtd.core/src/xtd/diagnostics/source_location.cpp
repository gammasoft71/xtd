#include "../../../include/xtd/diagnostics/source_location.hpp"
#include "../../../include/xtd/string.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

struct source_location::data {
  data() = default;
  data(const xtd::string& file, xtd::usize line, const xtd::string& func, xtd::usize column) : file {file}, line {line}, func {func}, column {column} {}
  
  xtd::string file;
  xtd::usize line = 0;
  xtd::string func;
  xtd::usize column = 0;
};

source_location::source_location() : data_ {new_ptr<data>()} {
}

source_location::source_location(source_location&& other) : data_ {std::move(other.data_)} {
}

source_location::source_location(const source_location& other) : data_ {new_ptr<data>()} {
  *data_ = *other.data_;
}

auto source_location::operator =(source_location&& other) -> source_location& {
  data_ = std::move(other.data_);
  return *this;
}

auto source_location::operator =(const source_location& other) -> source_location& {
  *data_ = *other.data_;
  return *this;
}

source_location::source_location(const xtd::string& file, xtd::usize line, const xtd::string& func, xtd::usize column) : data_ {new_ptr<data>(file, line, func, column)} {
}

auto source_location::column() const noexcept -> size {
  return data_->column;
}

auto source_location::file_name() const noexcept -> const string& {
  return data_->file;
}

auto source_location::function_name() const noexcept -> const string& {
  return data_->func;
}

auto source_location::line() const noexcept -> size {
  return data_->line;
}

auto source_location::to_string() const noexcept -> xtd::string {
  return string::format("{} in file:line:column {}:{}:{}", function_name(), file_name(), line(), column());
}

auto source_location::current(const __xtd_source_location__& value) noexcept -> source_location {
  return source_location {value.file_name(), static_cast<xtd::usize>(value.line()), value.function_name() == xtd::string {} ? "<unknown>" : value.function_name(), static_cast<xtd::usize>(value.column())};
}
