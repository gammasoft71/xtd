#include "../../../include/xtd/threading/cancellation_token"
#include "../../../include/xtd/threading/cancellation_token_source"
#include "../../../include/xtd/threading/manual_reset_event"

using namespace xtd;
using namespace xtd::threading;

cancellation_token cancellation_token::none;

cancellation_token::cancellation_token() {
}

cancellation_token::cancellation_token(bool canceled) : canceled_(canceled) {
}

cancellation_token::~cancellation_token() {
}

bool cancellation_token::can_be_canceled() const noexcept {
  return token_source_ ? token_source_->can_be_canceled() : canceled_;
}

bool cancellation_token::is_cancellation_requested() const noexcept {
  return token_source_ ? token_source_->is_cancellation_requested() : canceled_;
}

threading::wait_handle& cancellation_token::wait_handle() noexcept {
  if (token_source_) return token_source_->wait_handle();
  if (!wait_handle_) wait_handle_ = std::make_shared<manual_reset_event>();
  return *wait_handle_;
}

bool cancellation_token::equals(const cancellation_token& other) const noexcept {
  return token_source_ == other.token_source_;
}

cancellation_token::cancellation_token(cancellation_token_source& token_source) {
  token_source_ = &token_source;
}
