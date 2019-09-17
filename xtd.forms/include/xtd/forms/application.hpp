#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "application_informations.hpp"
#include "form.hpp"
#include "message.hpp"
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
    /// The following code example demonstrate the use of Application class.
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

      /// @brief Gets the path for the executable file that started the application, including the executable name.
      /// @return The path and executable name for the executable file that started the application.<br><br>
      /// This path will be different depending on whether the Windows Forms application is deployed using ClickOnce. ClickOnce applications are stored in a per-user application cache in the C:\Documents and Settings\username directory. For more information, see Accessing Local and Remote Data in ClickOnce Applications.
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

      /// @brief Processes all Windows messages currently in the message queue.
      /// @remarks When you run a Windows form, it creates the new form, which then waits for events to handle. Each time the form handles an event, it processes all the code associated with that event. All other events wait in the queue. While your code handles the event, your application does not respond. For example, the window does not repaint if another window is dragged on top.
      /// @remarks If you call do_events in your code, your application can handle the other events. For example, if you have a form that adds data to a list_box and add do_events to your code, your form repaints when another window is dragged over it. If you remove do_events from your code, your form will not repaint until the click event handler of the button is finished executing.
      /// @remarks Typically, you use this method in a loop to process messages.
      /// @warning Calling this method causes the current thread to be suspended while all waiting window messages are processed. If a message causes an event to be triggered, then other areas of your application code may execute. This can cause your application to exhibit unexpected behaviors that are difficult to debug. If you perform operations or computations that take a long time, it is often preferable to perform those operations on a new thread.
      static void do_events();
      
      /// @brief Enables visual styles for the application.
      /// @remarks This method enables visual styles for the application. Visual styles are the colors, fonts, and other visual elements that form an operating system theme. Controls will draw with visual styles if the control and the operating system support it. To have an effect, nnable_visual_styles() must be called before creating any controls in the application; typically, enable_visual_styles() is the first line in the Main function. A separate manifest is not required to enable visual styles when calling enable_visual_styles().
      static void enable_visual_styles();

      static void end();

      static void exit();

      static void run();

      static void run(const form& form);
      
      /// @cond
      static void run(form& form);
      /// @endcond
      
      static void start();

      static event<application, delegate<void(const event_args&)>> idle;
      
    private:
      //static void wnd_proc(message& message);
      static intptr_t wnd_proc_(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle);
      static void wnd_proc(message& message);
      static void wm_activate_app(message& message);
      static void wm_enter_idle(message& message);

      application() = default;
      static const form* main_form;
      static bool use_visual_styles_;
      static bool message_loop_;
    };
  }
}
