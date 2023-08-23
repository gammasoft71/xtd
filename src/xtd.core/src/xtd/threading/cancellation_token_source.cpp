#include "../../../include/xtd/threading/cancellation_token_source.h"
#include "../../../include/xtd/threading/manual_reset_event.h"

using namespace xtd;
using namespace xtd::threading;

struct cancellation_token_source::data {
  bool can_be_canceled = false;
  bool is_cancellation_requested = false;
  cancellation_token token {false};
  manual_reset_event wait_handle;
};

cancellation_token_source::cancellation_token_source(int32 milliseconds_delay) {
}

cancellation_token_source::cancellation_token_source() {
}

cancellation_token_source::cancellation_token_source(const cancellation_token_source& cancellation_token_source) {
}

cancellation_token_source& cancellation_token_source::operator=(const cancellation_token_source& cancellation_token_source) {
  return *this;
}

cancellation_token_source::~cancellation_token_source() {
}

bool cancellation_token_source::is_cancellation_requested() const noexcept {
  return data_->is_cancellation_requested;
}

bool cancellation_token_source::can_be_canceled() const noexcept {
  return data_->can_be_canceled;
}

threading::wait_handle& cancellation_token_source::wait_handle() noexcept {
  return data_->wait_handle;
}
