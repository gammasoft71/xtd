#include "../../../include/xtd/forms/background_worker.h"
#include "../../../include/xtd/forms/application.h"

using namespace xtd;
using namespace xtd::forms;

background_worker::background_worker() {
}

background_worker::~background_worker() {
  if (thread_.joinable()) thread_.join();
}

void background_worker::cancel_async() {
  if (worker_supports_cancellation_)
    cancellation_pending_ = true;
}

void background_worker::report_progress(int32_t percent_progress) {
  report_progress(percent_progress, std::any());
}

void background_worker::report_progress(int32_t percent_progress, std::any user_state) {
  if (worker_reports_progress_) {
    e_ = {percent_progress, user_state};
    invoker_->begin_invoke([&] {
      on_progress_changed(e_);
    });
  }
}

void background_worker::run_worker_async() {
  is_busy_ = true;
  if (thread_.joinable()) thread_.join();
  invoker_ = std::make_unique<form>();
  thread_ = std::thread([&] {
    do_work_event_args e(argument_);
    on_do_work(e);
    is_busy_ = false;
    invoker_->begin_invoke([&] {
      on_run_worker_completed(run_worker_completed_event_args(std::any(), std::optional<std::reference_wrapper<std::exception>>(), cancellation_pending_));
      invoker_ = nullptr;
      cancellation_pending_ = false;
    });
  });
}
