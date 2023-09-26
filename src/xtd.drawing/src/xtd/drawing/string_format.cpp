#include "../../../include/xtd/drawing/string_format"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/brush>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::drawing;

string_format::string_format(xtd::drawing::string_format_flags options) : format_flags_(options) {
}

xtd::drawing::string_alignment string_format::alignment() const noexcept {
  return alignment_;
}

xtd::drawing::string_format& string_format::alignment(xtd::drawing::string_alignment alignment) noexcept {
  alignment_ = alignment;
  return *this;
}

xtd::drawing::string_format_flags string_format::format_flags() const noexcept {
  return format_flags_;
}

xtd::drawing::string_format& string_format::format_flags(xtd::drawing::string_format_flags format_flag) noexcept {
  format_flags_ = format_flag;
  return *this;
}

xtd::drawing::string_format string_format::generic_default() noexcept {
  auto format = xtd::drawing::string_format {};
  format.trimming_ = xtd::drawing::string_trimming::character;
  return format;
}

xtd::drawing::string_format string_format::generic_typographic() noexcept {
  return xtd::drawing::string_format {xtd::drawing::string_format_flags::no_clip | xtd::drawing::string_format_flags::fit_black_box | xtd::drawing::string_format_flags::line_limit};
}

xtd::drawing::text::hotkey_prefix string_format::hotkey_prefix() const noexcept {
  return hotkey_prefix_;
}

xtd::drawing::string_format& string_format::hotkey_prefix(xtd::drawing::text::hotkey_prefix hotkey_prefix) noexcept {
  hotkey_prefix_ = hotkey_prefix;
  return *this;
}

xtd::drawing::string_alignment string_format::line_alignment() const noexcept {
  return line_alignment_;
}

xtd::drawing::string_format& string_format::line_alignment(xtd::drawing::string_alignment line_alignment) noexcept {
  line_alignment_ = line_alignment;
  return *this;
}

xtd::drawing::string_trimming string_format::trimming() const noexcept {
  return trimming_;
}

xtd::drawing::string_format& string_format::trimming(xtd::drawing::string_trimming trimming) noexcept {
  trimming_ = trimming;
  return *this;
}
