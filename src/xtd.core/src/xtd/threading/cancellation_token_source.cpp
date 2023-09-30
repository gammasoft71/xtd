#include "../../../include/xtd/threading/cancellation_token_source.h"
#include "../../../include/xtd/threading/manual_reset_event.h"
#include "../../../include/xtd/as.h"

using namespace xtd;
using namespace xtd::threading;

struct cancellation_token_source::data {
  bool can_be_canceled = false;
  bool is_cancellation_requested = false;
  cancellation_token token {false};
  manual_reset_event wait_handle;
  int32 milliseconds_delay;
};

cancellation_token_source::cancellation_token_source() : cancellation_token_source(0) {
}

cancellation_token_source::cancellation_token_source(int32 milliseconds_delay) : data_(std::make_shared<data>()) {
  data_->token = cancellation_token {*this};
  data_->milliseconds_delay = milliseconds_delay;
}

cancellation_token_source::cancellation_token_source(const time_span& delay) : cancellation_token_source(as<int32>(delay.total_milliseconds())) {
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

const cancellation_token& cancellation_token_source::token() const noexcept {
  return data_->token;
}

bool cancellation_token_source::can_be_canceled() const noexcept {
  return data_->can_be_canceled;
}

threading::wait_handle& cancellation_token_source::wait_handle() noexcept {
  return data_->wait_handle;
}
