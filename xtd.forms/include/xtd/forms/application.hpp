#pragma once
#include <vector>
#include "application_informations.hpp"
#include "form.hpp"
#include "message.hpp"
#include <xtd/xtd.delegates>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
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
      /// @remarks If a path does not exist, one is created in the following format:
      /// @remarks Base Path\company_name\product_name\product_version
      /// @remarks product_version first looks to see if the assembly containing the main executable has the AssemblyInformationalVersion attribute on it. If this attribute exists, it is used for both product_version and common_app_data_path. If this attribute does not exist, both properties use the version of the executable file instead.
      /// @remarks The path will be different depending on whether the Windows Forms application is deployed using ClickOnce. ClickOnce applications are stored in a per-user application cache in the C:\Documents and Settings\username directory. For more information, see Accessing Local and Remote Data in ClickOnce Applications.
      static std::string common_app_data_path();
      
      /*
      /// @brief Gets the registry key for the application data that is shared among all users.
      /// @return A RegistryKey representing the registry key of the application data that is shared among all users.
      /// @remarks If the key does not exist, it is created in the following format:
      /// @remarks LocalMachine\Software\CompanyName\ProductName\ProductVersion
      static xtd::microsoft::win32::registry_key common_app_data_registry();
       */

      /// @brief Gets the company name associated with the application.
      /// @return The company name.
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

      static std::vector<std::reference_wrapper<xtd::forms::form>> open_forms();
      
      static std::string product_name();

      static void do_events();
      
      static void enable_visual_styles();

      static void exit();
      
      static void run();

      static void run(const form& form);
      
      static xtd::delegate<void(const xtd::event_args&)> idle;
      
    private:
      static void wnd_proc(xtd::forms::message& message);
      static void wm_activate_app(xtd::forms::message& message);
      static void wm_enter_idle(xtd::forms::message& message);
      static void wm_quit(xtd::forms::message& message);

      application() = default;
      static const form* main_form;
    };
  }
}
