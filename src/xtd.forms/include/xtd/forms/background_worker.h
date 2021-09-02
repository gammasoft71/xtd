/// @file
/// @brief Contains xtd::forms::background_worker component.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <thread>
#include "../forms_export.h"
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
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @remarks The background_worker class allows you to run an operation on a separate, dedicated thread. Time-consuming operations like downloads and database transactions can cause your user interface (UI) to seem as though it has stopped responding while they are running. When you want a responsive UI and you are faced with long delays associated with such operations, the background_worker class provides a convenient solution.
    /// @remarks To execute a time-consuming operation in the background, create a background_worker and listen for events that report the progress of your operation and signal when your operation is finished.
    /// @remarks To set up for a background operation, add an event handler for the do_work event. Call your time-consuming operation in this event handler. To start the operation, call run_worker_async. To receive notifications of progress updates, handle the progress_changed event. To receive a notification when the operation is completed, handle the run_worker_completed event.
    /// @note You must be careful not to manipulate any user-interface objects in your do_work event handler. Instead, communicate to the user interface through the progress_changed and run_worker_completed events.
    /// @remarks If your background operation requires a parameter, call run_worker_async with your parameter. Inside the do_work event handler, you can extract the parameter from the do_work_event_args.argument property.
    /// @par Examples
    /// The following code example demonstrate the use of background_worker component.
    /// @include background_worker.cpp
    /// @par Windows
    /// @image html background_worker_w.png
    /// <br>
    /// @image html background_worker_wd.png
    /// @par macOS
    /// @image html background_worker_m.png
    /// <br>
    /// @image html background_worker_md.png
    /// @par Gnome
    /// @image html background_worker_g.png
    /// <br>
    /// @image html background_worker_gd.png
    class forms_export_ background_worker : public component {
    public:
      /// @brief Initializes a new instance of the background_worker class.
      /// @remarks This constructor initializes a background_worker.
      background_worker();
      
      /// @cond
      ~background_worker();
      /// @endcond
      
      /// @brief Gets a value indicating whether the application has requested cancellation of a background operation.
      /// @return true if the application has requested cancellation of a background operation; otherwise, false. The default is false.
      bool cancellation_pending() const {return cancellation_pending_;}
      
      /// @brief Gets a value indicating whether the background_worker is running an asynchronous operation.
      /// @return true, if the background_worker is running an asynchronous operation; otherwise, false.
      bool is_busy() const {return is_busy_;}
      
      /// @brief Gets a value indicating whether the background_worker can report progress updates.Gets or sets a value indicating whether the background_worker can report progress updates.
      /// @return true if the background_worker supports progress updates; otherwise false. The default is false.
      /// @remarks Set the worker_reports_progress property to true if you want the background_worker to support progress updates. When this property is true, user code can call the report_progress method to raise the progress_changed event.
      bool worker_reports_progress() const {return worker_reports_progress_;}
      /// @brief Sets a value indicating whether the background_worker can report progress updates.Gets or sets a value indicating whether the background_worker can report progress updates.
      /// @param value true if the background_worker supports progress updates; otherwise false. The default is false.
      /// @remarks Set the worker_reports_progress property to true if you want the background_worker to support progress updates. When this property is true, user code can call the report_progress method to raise the progress_changed event.
      void worker_reports_progress(bool value) {worker_reports_progress_ = value;}

      /// @brief Gets a value indicating whether the background_worker supports asynchronous cancellation.
      /// @return true if the background_worker supports cancellation; otherwise false. The default is false.
      /// @remarks Set the worker_supports_cancellation property to true if you want the background_worker to support cancellation. When this property is true, you can call the cancel_async method to interrupt a background operation.
      bool worker_supports_cancellation() const {return worker_supports_cancellation_;}
      /// @brief Gets a value indicating whether the background_worker supports asynchronous cancellation.
      /// @param value true if the background_worker supports cancellation; otherwise false. The default is false.
      /// @remarks Set the worker_supports_cancellation property to true if you want the background_worker to support cancellation. When this property is true, you can call the cancel_async method to interrupt a background operation.
      void worker_supports_cancellation(bool value) {worker_supports_cancellation_ = value;}

      /// @brief Requests cancellation of a pending background operation.
      /// @remarks cancel_async submits a request to terminate the pending background operation and sets the cancellation_pending property to true.
      /// @remarks When you call cancel_async, your worker method has an opportunity to stop its execution and exit. The worker code should periodically check thecancellation_pending property to see if it has been set to true.
      void cancel_async();
      
      /// @brief Raises the background_worker::do_work event.
      /// @param e An event_args that contains the event data.
      virtual void on_do_work(do_work_event_args& e) {do_work(*this, e);}
      
      /// @brief Raises the background_worker::progress_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_progres_changed(const progress_changed_event_args& e) {progress_changed(*this, e);}
      
      /// @brief Raises the background_worker::run_worker_completed event.
      /// @param e An event_args that contains the event data.
      virtual void on_run_worker_completed(const run_worker_completed_event_args& e) {run_worker_completed(*this, e);}

      /// @brief Starts execution of a background operation.
      void run_worker_async();
      
      /// @brief Starts execution of a background operation.
      /// @param argument A parameter for use by the background operation to be executed in the do_work event handler.
      template<typename argument_t>
      void run_worker_async(argument_t argument) {
        argument_ = argument;
        run_worker_async();
      }

      /// @brief Raises the ProgressChanged event.
      /// @param percent_progress The percentage, from 0 to 100, of the background operation that is complete.
      void report_progress(int32_t percent_progress);
      
      /// @brief Raises the ProgressChanged event.
      /// @param percent_progress The percentage, from 0 to 100, of the background operation that is complete.
      /// @param user_state A unique object indicating the user state. Returned as the user_state property of the progress_changed_even_args.
      void report_progress(int32_t percent_progress, std::any user_state);

      /// @brief Occurs when run_worker_async() is called.
      /// @ingroup events
      event<background_worker, do_work_event_handler> do_work;

      /// @brief Occurs when report_progress(int32_t) is called.
      /// @ingroup events
      event<background_worker, progress_changed_event_handler> progress_changed;

      /// @brief Occurs when the background operation has completed, has been canceled, or has raised an exception.
      /// @ingroup events
      event<background_worker, run_worker_completed_event_handler> run_worker_completed;
      
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
