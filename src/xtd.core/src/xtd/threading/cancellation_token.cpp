#include "../../../include/xtd/threading/cancellation_token.hpp"
#include "../../../include/xtd/threading/cancellation_token_source.hpp"
#include "../../../include/xtd/operation_canceled_exception.hpp"
#include "../../../include/xtd/threading/manual_reset_event.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::threading;

struct cancellation_token::data {
  data(bool canceled) : canceled {canceled} {}
  bool canceled = false;
  bool is_cancellation_requested = false;
  std::optional<cancellation_token_source> token_source;
  xtd::threading::manual_reset_event wait_handle {false};
};

cancellation_token cancellation_token::none;

cancellation_token::cancellation_token() : cancellation_token {false} {
}

cancellation_token::cancellation_token(bool canceled) : data_ {new_sptr<data>(canceled)} {
  if (canceled) cancel();
}

auto cancellation_token::can_be_canceled() const noexcept -> bool {
  return data_->token_source ? !is_cancellation_requested() : data_->canceled;
}

auto cancellation_token::is_cancellation_requested() const noexcept -> bool {
  return data_->token_source ? data_->is_cancellation_requested : data_->canceled;
}

auto cancellation_token::wait_handle() noexcept -> threading::wait_handle& {
  return data_->wait_handle;
}

auto cancellation_token::equals(const object& obj) const noexcept -> bool {
  return is<cancellation_token>(obj) && equals(static_cast<const cancellation_token&>(obj));
}

auto cancellation_token::equals(const cancellation_token& other) const noexcept -> bool {
  return data_ == data_;
}

auto cancellation_token::get_hash_code() const noexcept -> usize {
  return data_->token_source ? hash_code::combine(data_->canceled, data_->is_cancellation_requested, data_->token_source, data_->wait_handle) : hash_code::combine(data_->canceled, data_->is_cancellation_requested, data_->wait_handle);
}

auto cancellation_token::throw_if_cancellation_requested() const -> void {
  if (!is_cancellation_requested()) return;
  throw_helper::throws(exception_case::operation_canceled);
}

cancellation_token::cancellation_token(const cancellation_token_source& token_source) : cancellation_token {false} {
  data_->token_source = token_source;
}

auto cancellation_token::cancel() -> void {
  data_->is_cancellation_requested = true;
  data_->wait_handle.set();
}
