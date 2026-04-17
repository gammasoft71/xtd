#include "../../../include/xtd/threading/cancellation_token.hpp"
#include "../../../include/xtd/threading/cancellation_token_source.hpp"
#include "../../../include/xtd/operation_canceled_exception.hpp"
#include "../../../include/xtd/threading/manual_reset_event.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::threading;

cancellation_token cancellation_token::none;

cancellation_token::cancellation_token() {
}

cancellation_token::cancellation_token(bool canceled) {
  data_->canceled = canceled;
  if (canceled) data_->wait_handle.set();
}

auto cancellation_token::can_be_canceled() const noexcept -> bool {
  return data_->token_source ? data_->token_source->can_be_canceled() : data_->canceled;
}

auto cancellation_token::is_cancellation_requested() const noexcept -> bool {
  return data_->token_source ? data_->token_source->is_cancellation_requested() : data_->canceled;
}

auto cancellation_token::wait_handle() noexcept -> threading::wait_handle& {
  return data_->token_source ? data_->token_source->wait_handle() : data_->wait_handle;
}

auto cancellation_token::equals(const object& obj) const noexcept -> bool {
  return is<cancellation_token>(obj) && equals(static_cast<const cancellation_token&>(obj));
}

auto cancellation_token::equals(const cancellation_token& other) const noexcept -> bool {
  return data_ == data_;
}

auto cancellation_token::get_hash_code() const noexcept -> usize {
  if (!data_->token_source) return hash_code::combine(data_->canceled);
  return hash_code::combine(*data_->token_source);
}

auto cancellation_token::throw_if_cancellation_requested() const -> void {
  if (!is_cancellation_requested()) return;
  throw_helper::throws(exception_case::operation_canceled);
}

cancellation_token::cancellation_token(cancellation_token_source& token_source) {
  data_->token_source = &token_source;
}
