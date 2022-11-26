#include "../../../include/xtd/forms/background_worker.h"
#include "../../../include/xtd/forms/application.h"

using namespace xtd;
using namespace xtd::forms;

background_worker::background_worker() noexcept {
}

background_worker::~background_worker() noexcept {
  if (data_->thread.joinable()) {
    if (data_->cancellation_pending) data_->thread.detach();
    else data_->thread.join();
  }
}

bool background_worker::cancellation_pending() const noexcept {
  return data_->cancellation_pending;
}

bool background_worker::is_busy() const noexcept {
  return data_->is_busy;
}

bool background_worker::worker_reports_progress() const noexcept {
  return data_->worker_reports_progress;
}

void background_worker::worker_reports_progress(bool value) {
  data_->worker_reports_progress = value;
}

bool background_worker::worker_supports_cancellation() const noexcept {
  return data_->worker_supports_cancellation;
}

void background_worker::worker_supports_cancellation(bool value) {
  data_->worker_supports_cancellation = value;
}

void background_worker::cancel_async() {
  if (data_->worker_supports_cancellation)
    data_->cancellation_pending = true;
}

void background_worker::on_do_work(do_work_event_args& e) {
  do_work(*this, e);
}

void background_worker::on_progress_changed(const progress_changed_event_args& e) {
  progress_changed(*this, e);
}

void background_worker::on_run_worker_completed(const run_worker_completed_event_args& e) {
  run_worker_completed(*this, e);
}

void background_worker::report_progress(int32_t percent_progress) {
  report_progress(percent_progress, std::any());
}

void background_worker::report_progress(int32_t percent_progress, std::any user_state) {
  if (data_->worker_reports_progress) {
    data_->event = {percent_progress, user_state};
    data_->invoker->begin_invoke([&] {
      on_progress_changed(data_->event);
    });
  }
}

void background_worker::run_worker_async() {
  data_->is_busy = true;
  if (data_->thread.joinable()) data_->thread.join();
  data_->invoker = std::make_unique<form>();
  data_->thread = std::thread([&] {
    do_work_event_args e(data_->argument);
    on_do_work(e);
    data_->is_busy = false;
    data_->invoker->begin_invoke([&] {
      on_run_worker_completed(run_worker_completed_event_args(std::any(), std::optional<std::reference_wrapper<std::exception>>(), data_->cancellation_pending));
      data_->invoker = nullptr;
      data_->cancellation_pending = false;
    });
  });
}
