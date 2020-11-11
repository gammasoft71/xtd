#pragma once
#include "form.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class application;
    /// @endcond
    
    /// @brief Specifies the contextual information about an application thread.
    /// @remarks You can use the application_context class to redefine the circumstances that cause a message loop to exit. By default, the application_context listens to the closed event on the application's main form, then exits the thread's message loop.
    /// @par Example
    /// The following code example demonstrate the use of application and application_context classes.
    /// @include application_context.cpp
    class application_context {
    public:
      /// @brief Initializes a new instance of the application_context class with no context.
      application_context() = default;
      /// @brief Initializes a new instance of the application_context class with the specified Form.
      /// @param main_form The main form of the application to use for context.
      /// @remarks If on_main_form_closed is not overridden, the message loop of the thread terminates when main_form is closed.
      explicit application_context(const form& main_form) {this->main_form(main_form);}

      /// @cond
      virtual ~application_context() {
        if (this->main_form_ != nullptr) this->main_form_->handle_destroyed -= {*this, &application_context::on_main_form_closed};
      }
      /// @endcond
      
      /// @brief Gets the form to use as context.
      /// @return The form to use as context.
      /// @remarks This property determines the main form for this context. This property can change at any time. If on_main_form_closed is not overridden, the message loop of the thread terminates when the main_form parameter closes.
      const form& main_form() const {return *this->main_form_;}
      /// @brief Gets or sets the Form to use as context.
      /// @return The form to use as context.
      /// @remarks This property determines the main form for this context. This property can change at any time. If on_main_form_closed is not overridden, the message loop of the thread terminates when the main_form parameter closes.
      form& main_form() {return *this->main_form_;}
      /// @brief Sets the Form to use as context.
      /// @param main_form The form to use as context.
      /// @remarks This property determines the main form for this context. This property can change at any time. If on_main_form_closed is not overridden, the message loop of the thread terminates when the main_form parameter closes.
      void main_form(const form& main_form) {
        if (this->main_form_ != nullptr) this->main_form_->handle_destroyed -= {*this, &application_context::on_main_form_closed};
        this->main_form_ = const_cast<form*>(&main_form);
        this->main_form_->visible_changed += {*this, &application_context::on_main_form_closed};
      }

      /// @brief Gets an object that contains data about the control.
      /// @return A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      std::any tag() const {return this->tag_;}
      /// @brief Sets an object that contains data about the control.
      /// @param tag A std::any that contains data about the control. The default is empty.
      /// @remarks Any type of class can be assigned to this property.
      /// @remarks A common use for the tag property is to store data that is closely associated with the control. For example, if you have a control that displays information about a customer, you might store a data_set that contains the customer's order history in that control's tag property so the data can be accessed quickly.
      void tag(std::any tag) {this->tag_ = tag;}

      /// @brief Occurs when the message loop of the thread should be terminated, by calling exit_thread().
      event<application_context, event_handler<const application_context&>> thread_exit;
      
      /// @brief Terminates the message loop of the thread.
      /// @remarks This method calls exit_thread_core.
      /// @note exit_thread and exit_thread_core do not actually cause the thread to terminate. These methods raise the thread_exit event to which the Application object listens. The Application object then terminates the thread.
      void exit_thread() {this->exit_thread_core();}
      
    protected:
      /// @brief Terminates the message loop of the thread.
      /// @remarks This method is called from exit_thread.
      /// @note exit_thread and exit_thread_core do not actually cause the thread to terminate. These methods raise the thread_exit event to which the Application object listens. The Application object then terminates the thread.
      virtual void exit_thread_core() {this->thread_exit(*this, event_args::empty);}
      
      /// @brief Calls ExitThreadCore(), which raises the ThreadExit event.
      /// @param sender The object that raised the event.
      /// @param e The event_args that contains the event data.
      /// @remarks The default implementation of this method calls exit_thread_core.
      virtual void on_main_form_closed(const control& sender, const event_args& e) {
        if (!this->main_form_->visible()) {
          if (!this->main_form_->can_close_) this->main_form_->close();
          if (this->main_form_->can_close_) {
            this->main_form_->handle_destroyed -= {*this, &application_context::on_main_form_closed};
            this->exit_thread_core();
          }
        }
      }
      
    private:
      /// @cond
      friend class application;
      /// @endcond
      form* main_form_ = nullptr;
      std::any tag_;
    };
  }
}
