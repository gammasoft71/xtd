#include "../../../include/xtd/diagnostics/source_location.h"
#include "../../../include/xtd/string.h"

using namespace xtd;

struct source_location::data {
  data() = default;
  data(const xtd::string& file, xtd::size line, const xtd::string& func, xtd::size column) : file {file}, line {line}, func {func}, column {column} {}

  xtd::string file;
  xtd::size line = 0;
  xtd::string func;
  xtd::size column = 0;
};

source_location::source_location() : data_ {new_ptr<data>()} {
}

source_location::source_location(source_location&& other) : data_ {std::move(other.data_)} {
}

source_location::source_location(const source_location& other) : data_ {new_ptr<data>()} {
  *data_ = *other.data_;
}

source_location& source_location::operator =(source_location&& other) {
  data_ = std::move(other.data_);
  return *this;
}
source_location& source_location::operator =(const source_location& other) {
  *data_ = *other.data_;
  return *this;
}

source_location::source_location(const xtd::string& file, xtd::size line, const xtd::string& func, xtd::size column) : data_ {new_ptr<data>(file, line, func, column)} {
}

size source_location::column() const noexcept {
  return data_->column;
}

const string& source_location::file_name() const noexcept {
  return data_->file;
}

const string& source_location::function_name() const noexcept {
  return data_->func;
}

size source_location::line() const noexcept {
  return data_->line;
}

xtd::string source_location::to_string() const noexcept {
  return string::format("{} in file:line:column {}:{}:{}", function_name(), file_name(), line(), column());
}

source_location source_location::current(const __xtd_source_location__& value) noexcept {
  return source_location {value.file_name(), static_cast<xtd::size>(value.line()), value.function_name(), static_cast<xtd::size>(value.column())};
}
