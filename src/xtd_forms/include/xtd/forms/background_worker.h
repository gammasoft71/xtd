#pragma once
#include <thread>
#include "component.h"
#include "form.h"
#include "do_work_event_handler.h"
#include "progress_changed_event_handler.h"
#include "run_worker_completed_event_handler.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Executes an operation on a separate thread.
    /// @remarks The background_worker class allows you to run an operation on a separate, dedicated thread. Time-consuming operations like downloads and database transactions can cause your user interface (UI) to seem as though it has stopped responding while they are running. When you want a responsive UI and you are faced with long delays associated with such operations, the background_worker class provides a convenient solution.
    /// @remarks To execute a time-consuming operation in the background, create a background_worker and listen for events that report the progress of your operation and signal when your operation is finished.
    /// @remarks To set up for a background operation, add an event handler for the do_work event. Call your time-consuming operation in this event handler. To start the operation, call run_worker_async. To receive notifications of progress updates, handle the progress_changed event. To receive a notification when the operation is completed, handle the run_worker_completed event.
    /// @note You must be careful not to manipulate any user-interface objects in your do_work event handler. Instead, communicate to the user interface through the progress_changed and run_worker_completed events.
    /// @remarks If your background operation requires a parameter, call run_worker_async with your parameter. Inside the do_work event handler, you can extract the parameter from the do_work_event_args.argument property.
    class background_worker : public component {
    public:
      /// @brief Initializes a new instance of the background_worker class.
      /// @remarks This constructor initializes a background_worker.
      background_worker();
      
      /// @cond
      ~background_worker();
      /// @endcond
      
      bool cancellation_pending() const {return cancellation_pending_;}
      
      bool is_busy() const {return is_busy_;}
      
      bool worker_reports_progress() const {return worker_reports_progress_;}
      void worker_reports_progress(bool value) {worker_reports_progress_ = value;}

      bool worker_supports_cancellation() const {return worker_supports_cancellation_;}
      void worker_supports_cancellation(bool value) {worker_supports_cancellation_ = value;}

      void on_do_work(do_work_event_args& e) {do_work(*this, e);}
      
      void on_progres_changed(const progress_changed_event_args& e) {progress_changed(*this, e);}
      
      void on_run_worker_completed(const run_worker_completed_event_args& e) {run_worker_completed(*this, e);}

      void cancel_async();
      
      /// @brief Starts execution of a background operation.
      void run_worker_async();

      void report_progress(int32_t percent_progress);
      
      void report_progress(int32_t percent_progress, std::any user_state);
      
      /// @brief Starts execution of a background operation.
      template<typename argument_t>
      void run_worker_async(argument_t argument) {
        argument_ = argument;
        run_worker_async();
      }

      event<background_worker, do_work_event_handler<component&>> do_work;
      
      event<background_worker, progress_changed_event_handler<component&>> progress_changed;
      
      event<background_worker, run_worker_completed_event_handler<component&>> run_worker_completed;
      
    private:
      std::any argument_;
      bool cancellation_pending_ = false;
      bool is_busy_ = false;
      bool worker_reports_progress_ = false;
      bool worker_supports_cancellation_ = false;
      progress_changed_event_args e_ {0, std::any()};
      std::unique_ptr<form> invoker_;
      std::thread thread_;
    };
  }
}
