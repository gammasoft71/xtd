#include "../../../include/xtd/threading/cancellation_token_source.hpp"
#include "../../../include/xtd/threading/manual_reset_event.hpp"
#include "../../../include/xtd/threading/timer.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;
using namespace xtd::threading;

struct cancellation_token_source::data {
  cancellation_token token;
  int32 milliseconds_delay;
  timer cancel_timer {[]{}};
};

cancellation_token_source::cancellation_token_source() : cancellation_token_source(0) {
}

cancellation_token_source::cancellation_token_source(int32 milliseconds_delay) : data_(xtd::new_sptr<data>()) {
  data_->token = cancellation_token {*this};
  data_->milliseconds_delay = milliseconds_delay;
}

cancellation_token_source::cancellation_token_source(const time_span& delay) : cancellation_token_source(as<int32>(delay.total_milliseconds())) {
}

auto cancellation_token_source::is_cancellation_requested() const noexcept -> bool {
  return data_->token.is_cancellation_requested();
}

auto cancellation_token_source::token() const noexcept -> const cancellation_token& {
  return data_->token;
}

auto cancellation_token_source::token() noexcept -> cancellation_token& {
  return data_->token;
}

auto cancellation_token_source::can_be_canceled() const noexcept -> bool {
  return data_->token.can_be_canceled();
}

auto cancellation_token_source::wait_handle() noexcept -> threading::wait_handle& {
  return data_->token.wait_handle();
}

auto cancellation_token_source::cancel() -> void {
  data_->cancel_timer = timer {[token = data_->token] mutable {token.cancel();}, data_->milliseconds_delay, timeout::infinite};
}
