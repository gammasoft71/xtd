#include "../../include/xtd/processor.hpp"

using namespace xtd;

processor::processor(xtd::architecture_id architecture, bool is_64_bit, uint32 core_count) : architecture_(architecture), is_64_bit_(is_64_bit), core_count_(core_count) {
}

xtd::architecture_id processor::architecture() const noexcept {
  return architecture_;
}

xtd::string processor::architecture_string() const noexcept {
  if (!architecture_string_.empty()) return architecture_string_;
  architecture_string_ = string::format("{}", architecture_);
  if (is_64_bit_) {
    if (architecture_ == architecture_id::x86) architecture_string_ += "_";
    architecture_string_ += "64";
  }
  return architecture_string_;
}

uint32 processor::core_count() const noexcept {
  return core_count_;
}

bool processor::is_64_bit() const noexcept {
  return is_64_bit_;
}

string processor::name() const noexcept {
  static auto processor_names = std::map<architecture_id, string> {{architecture_id::x86, "Intel or AMD"}, {architecture_id::arm, "ARM"}, {architecture_id::unknown, "<Unknown>"}};
  return processor_names[architecture_];
}

size processor::get_hash_code() const noexcept {
  return hash_code::combine(architecture_, is_64_bit_, core_count_, architecture_string_);
}

string processor::to_string() const noexcept {
  return architecture_string();
}
