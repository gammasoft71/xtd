#include "../../../include/xtd/forms/background_worker.hpp"
#include "../../../include/xtd/forms/application.hpp"
#include <xtd/action>
#include <xtd/invalid_operation_exception>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::helpers;

struct background_worker::data {
  any_object argument;
  bool cancellation_pending = false;
  bool is_busy = false;
  bool worker_reports_progress = false;
  bool worker_supports_cancellation = false;
  progress_changed_event_args event {0, any_object {}};
  xtd::uptr<form> invoker;
  action<> worker;
  async_result worker_result;
};

background_worker::background_worker() noexcept : data_(xtd::new_sptr<data>()) {
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
  auto safe_do_work = do_work;
  if (safe_do_work.is_empty()) return;
  safe_do_work(*this, e);
}

void background_worker::on_progress_changed(const progress_changed_event_args& e) {
  auto safe_progress_changed = progress_changed;
  if (safe_progress_changed.is_empty()) return;
  safe_progress_changed(*this, e);
}

void background_worker::on_run_worker_completed(const run_worker_completed_event_args& e) {
  if (!can_raise_events()) return;
  auto safe_run_worker_completed = run_worker_completed;
  if (safe_run_worker_completed.is_empty()) return;
  safe_run_worker_completed(*this, e);
}

void background_worker::report_progress(int32 percent_progress) {
  report_progress(percent_progress, any_object {});
}

void background_worker::report_progress(int32 percent_progress, const xtd::any_object& user_state) {
  if (data_->worker_reports_progress) {
    data_->event = {percent_progress, user_state};
    data_->invoker->begin_invoke([&] {
      on_progress_changed(data_->event);
    });
  }
}

void background_worker::run_worker_async() {
  if (data_->is_busy) throw_helper::throws(exception_case::invalid_operation);
  data_->is_busy = true;
  if (data_->worker_result) data_->worker.end_invoke(data_->worker_result);
  data_->invoker = xtd::new_uptr<form>();
  data_->worker = action<> {[&] {
      auto e = do_work_event_args {data_->argument};
      on_do_work(e);
      data_->invoker->begin_invoke([&] {
        on_run_worker_completed(run_worker_completed_event_args(any_object {}, std::nullopt, data_->cancellation_pending));
        data_->invoker = nullptr;
        data_->cancellation_pending = false;
      });
      data_->is_busy = false;
    }
  };
  data_->worker_result = data_->worker.begin_invoke();
}

void background_worker::argument_(any_object&& argument) {
  data_->argument = std::move(argument);
}
