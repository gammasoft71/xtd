#include "../../../include/xtd/forms/background_worker.h"
#include "../../../include/xtd/forms/application.h"
#include <xtd/action>
#include <xtd/invalid_operation_exception>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

struct background_worker::data {
  any argument;
  bool cancellation_pending = false;
  bool is_busy = false;
  bool worker_reports_progress = false;
  bool worker_supports_cancellation = false;
  progress_changed_event_args event {0, any()};
  unique_ptr<form> invoker;
  action<> worker;
  iasync_result_ptr worker_result;
};

background_worker::background_worker() noexcept : data_(make_shared<data>()) {
}

background_worker::~background_worker() noexcept {
  if (data_->worker_result) data_->worker.end_invoke(data_->worker_result);
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

void background_worker::report_progress(int32 percent_progress) {
  report_progress(percent_progress, any());
}

void background_worker::report_progress(int32 percent_progress, any user_state) {
  if (data_->worker_reports_progress) {
    data_->event = {percent_progress, user_state};
    data_->invoker->begin_invoke([&] {
      on_progress_changed(data_->event);
    });
  }
}

void background_worker::run_worker_async() {
  if (data_->is_busy) throw invalid_operation_exception {csf_};
  data_->is_busy = true;
  if (data_->worker_result) data_->worker.end_invoke(data_->worker_result);
  data_->invoker = make_unique<form>();
  data_->worker = action<> {[&] {
    auto e = do_work_event_args {data_->argument};
    on_do_work(e);
    data_->invoker->begin_invoke([&] {
      on_run_worker_completed(run_worker_completed_event_args(any(), optional<reference_wrapper<exception>>(), data_->cancellation_pending));
      data_->invoker = nullptr;
      data_->cancellation_pending = false;
    });
    data_->is_busy = false;
  }};
  data_->worker_result = data_->worker.begin_invoke();
}

void background_worker::argument_(any&& argument) {
  data_->argument = std::move(argument);
}
