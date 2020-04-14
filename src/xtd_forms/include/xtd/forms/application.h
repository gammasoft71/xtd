#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "application_context.h"
#include "application_informations.h"
#include "imessage_filter.h"
#include "message.h"
#include "message_box.h"
#include "message_loop_callback.h"
#include <xtd/xtd.delegates>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a collection of form objects.
    /// @remarks form_collection is used by the application object to list the currently open forms in an application through the open_forms property.
    using form_collection = std::vector<std::reference_wrapper<form>>;
    
    /// @brief Provides static methods and properties to manage an application, such as methods to start and stop an application, to process Windows messages, and methods to get information about an application. This class cannot be inherited.
    /// @remarks The application class has methods to start and stop applications and threads, and to process Windows messages, as follows:
    /// * run() starts an application message loop on the current thread and, optionally, makes a form visible.
    /// * exit() or exit_thread() stops a message loop.
    /// * do_events() processes messages while your program is in a loop.
    /// * add_message_filter() adds a message filter to the application message pump to monitor Windows messages.
    /// @remarks You cannot create an instance of this class.
    /// @par Example
    /// The following code example demonstrate the use of application class.
    /// @include application.cpp
    class application {
    public:
      /// @brief Gets a value indicating whether the caller can quit this application.
      /// @return true if the caller can quit this application; otherwise, false.
      /// @remarks This method returns false if it is called from a control being hosted within a Web browser. Thus, the control cannot quit the application.
      static bool allow_quit();
      
      /// @brief Gets the path for the application data that is shared among all users.
      /// @return The path for the application data that is shared among all users.
      /// @remarks If a path does not exist, one is created in the following format: base_path\company_name\product_name\product_version
      /// @remarks product_version first looks to see if the assembly containing the main executable has the AssemblyInformationalVersion attribute on it. If this attribute exists, it is used for both product_version and common_app_data_path. If this attribute does not exist, both properties use the version of the executable file instead.
      /// @remarks The path will be different depending on whether the Windows Forms application is deployed using ClickOnce. ClickOnce applications are stored in a per-user application cache in the C:\Documents and Settings\username directory. For more information, see Accessing Local and Remote Data in ClickOnce Applications.
      static std::string common_app_data_path();
      
      /*
      /// @brief Gets the registry key for the application data that is shared among all users.
      /// @return A RegistryKey representing the registry key of the application data that is shared among all users.
      /// @remarks If the key does not exist, it is created in the following format: local_machine\software\company_name\product_name\product_version
      static microsoft::win32::registry_key common_app_data_registry();
       */

      /// @brief Gets the company name associated with the application.
      /// @return The company name.
      /// @remarks company_name is taken from the application_informations containing the current application. You can set it by setting application_informations::company_name property. For more information, see application_informations.
      /// @par Examples
      /// The following code example gets this property and displays its value in a text box. The example requires that textBox1 has been placed on a form.
      /// @code
      /// void PrintCompanyName() {
      ///   textBox1.Text(xtd;;strings::format("The company name is: {0}", application::company_name);
      /// }
      /// @endcode
      static std::string company_name();

      /// @brief Gets the executable name for the executable file that started the application, including the executable extension.
      /// @return The executable name and executable name for the executable file that started the application.<br><br>
      static std::string executable_name();
      
      /// @brief Gets the path for the executable file that started the application, including the executable name.
      /// @return The path and executable name for the executable file that started the application.<br><br>
      static std::string executable_path();
      
      /// @brief Gets a value indicating whether a message loop exists on this thread.
      /// @return true if a message loop exists; otherwise, false.
       static bool message_loop();
      
      /// @brief Gets a collection of open forms owned by the application.
      /// @return A form_collection containing all the currently open forms owned by this application.
      /// @remarks The open_forms property represents a read-only collection of forms owned by the application.
      static const form_collection open_forms();
      
      /// @brief Gets the product name associated with this application.
      /// @return The product name.
      /// @remarks product_name is taken from the application_informations containing the current application. You can set it by setting application_informations::product_name property. For more information, see application_informations.
      static std::string product_name();
      
      /// @brief Gets the product version associated with this application.
      /// @return The product version.
      /// @remarks product_version is taken from the application_informations containing the current application. You can set it by setting application_informations::product_version property. For more information, see application_informations.
      static std::string product_version();
      
      /// @brief Gets the path for the executable file that started the application, not including the executable name.
      /// @return The path for the executable file that started the application.
      static std::string startup_path();

      /// @brief Gets the path for the application data of a user.
      /// @return The path for the application data of a user.
      /// @remarks If a path does not exist, one is created in the following format: base_path\company_name\product_name\product_version
      /// @remarks Data stored in this path is part of user profile that is enabled for roaming. A roaming user works on more than one computer in a network. The user profile for a roaming user is kept on a server on the network and is loaded onto a system when the user logs on. For a user profile to be considered for roaming, the operating system must support roaming profiles and it must be enabled.
      /// @remarks A typical base path is "C:\Documents and Settings\username\Application Data".
      static std::string user_app_data_path();

      /*
       /// @brief Gets the registry key for the application data of a user.
       /// @return A registry_key representing the registry key for the application data specific to the user.
       /// @remarks If the key does not exist, it is created in the following format: current_user\software\company_name\product_name\product_version
       /// @remarks Data stored in this key is part of user profile that is enabled for roaming. A roaming user works on more than one computer in a network. The user profile for a roaming user is kept on a server on the network and is loaded onto a system when the user logs on. For a user profile to be considered for roaming, the operating system must support roaming profiles and it must be enabled.
       static microsoft::win32::registry_key user_app_data_registry();
       */
      
      /// @brief Gets a value that indicates whether visual styles are enabled for the application.
      /// @return true if visual styles are enabled; otherwise, false.
      /// @remarks The visual styles can be enabled by calling enable_visual_styles().
      static bool use_visual_styles();
      
      /// @brief Gets whether the wait cursor is used for all open forms of the application.
      /// @return true is the wait cursor is used for all open forms; otherwise, false.
      /// @remarks When this property is set to true, the use_wait_cursor property of all open forms in the application will be set to true. This call will not return until this property has been set on all forms. Use this property when you have a long-running operation, and want to indicate in all application forms that the operation is still processing.
      static bool use_wait_cursor();
      
      /// @brief Sets whether the wait cursor is used for all open forms of the application.
      /// @param use_wait_cursor true is the wait cursor is used for all open forms; otherwise, false.
      /// @remarks When this property is set to true, the use_wait_cursor property of all open forms in the application will be set to true. This call will not return until this property has been set on all forms. Use this property when you have a long-running operation, and want to indicate in all application forms that the operation is still processing.
      static void use_wait_cursor(bool use_wait_cursor);
      
      /// @brief Adds a message filter to monitor Windows messages as they are routed to their destinations.
      /// @param The implementation of the imessage_filter interface you want to install.
      /// @remarks Use a message filter to prevent specific events from being raised or to perform special operations for an event before it is passed to an event handler. Message filters are unique to a specific thread.
      static void add_message_filter(const imessage_filter& value);
      
      /// @brief Processes all Windows messages currently in the message queue.
      /// @remarks When you run a Windows form, it creates the new form, which then waits for events to handle. Each time the form handles an event, it processes all the code associated with that event. All other events wait in the queue. While your code handles the event, your application does not respond. For example, the window does not repaint if another window is dragged on top.
      /// @remarks If you call do_events in your code, your application can handle the other events. For example, if you have a form that adds data to a list_box and add do_events to your code, your form repaints when another window is dragged over it. If you remove do_events from your code, your form will not repaint until the click event handler of the button is finished executing.
      /// @remarks Typically, you use this method in a loop to process messages.
      /// @warning Calling this method causes the current thread to be suspended while all waiting window messages are processed. If a message causes an event to be triggered, then other areas of your application code may execute. This can cause your application to exhibit unexpected behaviors that are difficult to debug. If you perform operations or computations that take a long time, it is often preferable to perform those operations on a new thread.
      static void do_events();
      
      /// @brief Enables dark mode for the application.
      static void enable_dark_mode();
      
      /// @brief Enables light mode for the application.
      static void enable_light_mode();

      /// @brief Enables visual styles for the application.
      /// @remarks This method enables visual styles for the application. Visual styles are the colors, fonts, and other visual elements that form an operating system theme. Controls will draw with visual styles if the control and the operating system support it. To have an effect, nnable_visual_styles() must be called before creating any controls in the application; typically, enable_visual_styles() is the first line in the Main function. A separate manifest is not required to enable visual styles when calling enable_visual_styles().
      static void enable_visual_styles();
      
      /// @brief Informs all message pumps that they must terminate, and then closes all application windows after the messages have been processed.
      /// @remarks The exit method stops all running message loops on all threads and closes all windows of the application. This method does not necessarily force the application to exit. The exit method is typically called from within a message loop, and forces Run to return. To exit a message loop for the current thread only, call exit_thread.
      /// @remarks Exit raises the following events and performs the associated conditional actions:
      /// * A form_closing event is raised for every form represented by the open_forms property. This event can be canceled by setting the cancel property of their form_closing_event_args parameter to true.
      /// * If one of more of the handlers cancels the event, then exit returns without further action. Otherwise, a form_closed event is raised for every open form, then all running message loops and forms are closed.
      static void exit();
      
      /// @brief Informs all message pumps that they must terminate, and then closes all application windows after the messages have been processed.
      /// @param e Returns whether any Form within the application cancelled the exit.
      /// @remarks The exit method stops all running message loops on all threads and closes all windows of the application. This method does not necessarily force the application to exit. The exit method is typically called from within a message loop, and forces Run to return. To exit a message loop for the current thread only, call exit_thread.
      /// @remarks Exit raises the following events and performs the associated conditional actions:
      /// * A form_closing event is raised for every form represented by the open_forms property. This event can be canceled by setting the cancel property of their form_closing_event_args parameter to true.
      /// * If one of more of the handlers cancels the event, then exit returns without further action. Otherwise, a form_closed event is raised for every open form, then all running message loops and forms are closed.
      static void exit(cancel_event_args& e);
      
      /// @brief Exits the message loop on the current thread and closes all windows on the thread.
      /// @remarks Use this method to exit the message loop of the current thread. This method causes the call to run for the current thread to return. To exit the entire application, call exit.
      static void exit_thread();
      
      /// @brief Raises the Idle event
      /// @param e The event_args objects to pass to the idle event.
      static void raise_idle(const event_args& e);
      
      /// @cond Registers a callback for checking whether the message loop is running in hosted environments.
      /// @param callback The method to call when Windows Forms needs to check if the hosting environment is still sending messages.
      /// @remarks This method is used when hosting Windows Forms in another environment. In hosted environments, the message_loop property will always return false if Windows Forms is not processing messages. Use this callback to tell Windows Forms if the hosting environment is still processing messages.
      static void register_message_loop_callback(message_loop_callback callback);
      
      /// @cond Removes a message filter from the message pump of the application.
      /// @param value The implementation of the imessage_filter to remove from the application.
      /// @remarks You can remove a message filter when you no longer want to capture Windows messages before they are dispatched.
      static void remove_message_filter(const imessage_filter& value);

      /// @brief Shuts down the application and starts a new instance immediately.
      /// @remarks Applications are restarted in the context in which they were initially run.
      /// @remarks If your application was originally supplied command-line options when it first executed, restart will launch the application again with the same options.
      static void restart();
      
      /// @brief Begins running a standard application message loop on the current thread, without a form.
      /// @remarks In a Win32-based or Windows Forms application, a message loop is a routine in code that processes user events, such as mouse clicks and keyboard strokes. Every running Windows-based application requires an active message loop, called the main message loop. When the main message loop is closed, the application exits. In Windows Forms, this loop is closed when the exit method is called, or when the exit_thread method is called on the thread that is running the main message loop.
      /// @remarks Most Windows Forms developers will not need to use this version of the method. You should use the run(const form&) overload to start an application with a main form, so that the application terminates when the main form is closed. For all other situations, use the run(application_context&) overload, which supports supplying an application_context object for better control over the lifetime of the application.
      static void run();

      /// @brief Begins running a standard application message loop on the current thread, with an application_context.
      /// @param context An ApplicationContext in which the application is run.
      /// @remarks The message loop runs until Exit or exit_thread is called or the thread_exit event is raised on the context object.
      static void run(application_context& context);
      
      /// @brief Begins running a standard application message loop on the current thread, and makes the specified form visible.
      /// @param main_form A form that represents the form to make visible.
      /// @remarks Typically, the main function of an application calls this method and passes to it the main window of the application.
      /// @remarks This method adds an event handler to the main_form parameter for the closed event. The event handler calls exit_thread to clean up the application.
      static void run(const form& main_form);

      /*
      /// @brief Instructs the application how to respond to unhandled exceptions.
      /// @param mode An unhandled_exception_mode value describing how the application should behave if an exception is thrown without being caught.
      /// @remarks It is often not feasible to catch all of the exceptions thrown by Windows Forms. Using this method, you can instruct your application whether it should catch all unhandled exceptions thrown by Windows Forms components and continue operating, or whether it should expose them to the user and halt execution.
      /// @remarks Call set_unhandled_exception_mode before you instantiate the main form of your application using the run method.
      /// @remarks To catch exceptions that occur in threads not created and owned by Windows Forms, use the unhandled_exception event handler.
      static void set_unhandled_exception_mode (unhandled_exception_mode mode);
       */

      /*
      /// @brief Instructs the application how to respond to unhandled exceptions, optionally applying thread-specific behavior.
      /// @param mode An unhandled_exception_mode value describing how the application should behave if an exception is thrown without being caught.
      /// @param thread_scope true to set the thread exception mode; otherwise, false.
      /// @remarks It is often not feasible to catch all of the exceptions thrown by Windows Forms. Using this method, you can instruct your application whether it should catch all unhandled exceptions thrown by Windows Forms components and continue operating, or whether it should expose them to the user and halt execution.
      /// @remarks Call set_unhandled_exception_mode before you instantiate the main form of your application using the run method.
      /// @remarks When threadScope is true, the thread exception mode is set. The thread exception mode overrides the application exception mode if mode is not set to automatic.
      /// @remarks When threadScope is false, the application exception mode is set. The application exception mode is used for all threads that have the automatic mode. Setting the application exception mode does not affect the setting of the current thread.
      /// @remarks To catch exceptions that occur in threads not created and owned by Windows Forms, use the unhandled_exception event handler.
      static void set_unhandled_exception_mode (unhandled_exception_mode mode, bool thread_scope);
       */

      /// @cond
      static void cleanup();
      static void initialize();
      /// @endcond

      /// @brief Occurs when the application is about to shut down.
      /// @remarks You must attach the event handlers to the application_exit event to perform unhandled, required tasks before the application stops running. You can close files opened by this application, or dispose of objects that garbage collection did not reclaim.
      static event<application, delegate<void(const event_args&)>> application_exit;

      /// @brief Occurs when the application is about to enter a modal state.
      static event<application, delegate<void(const event_args&)>> enter_thread_modal;

      /// @brief Occurs when the application finishes processing and is about to enter the idle state.
      /// @remarks If you have tasks that you must perform before the thread becomes idle, attach them to this event.
      static event<application, delegate<void(const event_args&)>> idle;

      /// @brief Occurs when the application is about to leave a modal state.
      static event<application, delegate<void(const event_args&)>> leave_thread_modal;
      
      /*
      /// @brief Occurs when an untrapped thread exception is thrown.
      /// @remarks This event allows your Windows Forms application to handle otherwise unhandled exceptions that occur in Windows Forms threads. Attach your event handlers to the thread_exception event to deal with these exceptions, which will leave your application in an unknown state. Where possible, exceptions should be handled by a structured exception handling block.
      /// @param You can change whether this callback is used for unhandled Windows Forms thread exceptions by setting set_unhandled_exception_mode. To catch exceptions that occur in threads not created and owned by Windows Forms, use the unhandled_exception event handler.
      /// @note To guarantee that no activations of this event are missed, you must attach a handler before you call application::run.
      static event<threading::thread_exception_event_handler> thread_exception;
       */

      /// @brief Occurs when a thread is about to shut down. When the main thread for an application is about to be shut down, this event is raised first, followed by an application_exit event.
      /// @remarks You must attach the event handlers to the thread_exit event to perform any unhandled, required tasks before the thread stops running. Close files opened by this thread, or dispose of objects that the garbage collector did not reclaim.
      static event<application, delegate<void(const event_args&)>> thread_exit;

    private:
      /// @cond
      friend class form;
      friend class message_box;
      /// @endcond
      static void on_app_thread_exit(const application_context& sender, const event_args& e);
      static void raise_enter_thread_modal(const event_args& e);
      static void raise_leave_thread_modal(const event_args& e);
      static intptr_t wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle);
      static void wnd_proc(message& message);
      static void wm_activate_app(message& message);
      static void wm_enter_idle(message& message);
      static void wm_quit(message& message);

      application() = default;
      static bool use_visual_styles_;
      static bool use_wait_cursor_;
      static bool message_loop_;
    };
  }
}
