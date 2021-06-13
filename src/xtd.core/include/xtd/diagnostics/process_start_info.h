/// @file
/// @brief Contains xtd::diagnostics::process_start_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <filesystem>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "../core_export.h"
#include "../security/secure_string.h"
#include "process_window_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies a set of values that are used when you start a process.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks xtd::diagnostics::process_start_info is used together with the xtd::diagnostics::process component. When you start a process using the xtd::diagnostics::process class, you have access to process information in addition to that available when attaching to a running process.
    /// @remarks You can use the xtd::diagnostics::process_start_info class for better control over the process you start. You must at least set the xtd::diagnostics::process_start_info::file_name property, either manually or using the constructor. The file name is any application or document. Here a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
    /// @remarks In addition, you can set other properties that define actions to take with that file. You can specify a value specific to the type of the xtd::diagnostics::process_start_info::file_name property for the xtd::diagnostics::process_start_info::verb property. For example, you can specify "print" for a document type. Additionally, you can specify xtd::diagnostics::process_start_info::arguments property values to be command-line arguments to pass to the file's open procedure. For example, if you specify a text editor application in the xtd::diagnostics::process_start_info::file_name property, you can use the xtd::diagnostics::process_start_info::arguments property to specify a text file to be opened by the editor.
    /// @remarks Standard input is usually the keyboard, and standard output and standard error are usually the monitor screen. However, you can use the xtd::diagnostics::process_start_info::redirect_standard_input, xtd::diagnostics::process_start_info::redirect_standard_output, and xtd::diagnostics::process_start_info::redirect_standard_error properties to cause the process to get input from or return output to a file or other device. If you use the xtd::diagnostics::process::standard_input, xtd::diagnostics::process::standard_output, or xtd::diagnostics::process::standard_error properties on the xtd::diagnostics::process component, you must first set the corresponding value on the xtd::diagnostics::process_start_info property. Otherwise, the system throws an exception when you read or write to the stream.
    /// @remarks Set xtd::diagnostics::process_start_info::use_shell_execute to specify whether to start the process by using the operating system shell.
    /// @remarks You can change the value of any process_start_info property up to the time that the process starts. After you start the process, changing these values has no effect.
    class core_export_ process_start_info final {
    public:
      /// @brief Initializes a new instance of the xtd::diagnostics::process_start_info class without specifying a file name with which to start the process.
      /// @remarks You must set at least the xtd::diagnostics::process_start_info::file_name property before you start the process. The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
      /// @remarks Optionally, you can also set other properties before you start the process. The xtd::diagnostics::process_start_info::verb property supplies actions to take, such as "print", with the file indicated in the xtd::diagnostics::process_start_info::file_name property. The xtd::diagnostics::process_start_info::arguments property supplies a way to pass command-line arguments_ to the file when the system opens it.
      process_start_info() = default;
      
      /// @brief Initializes a new instance of the xtd::diagnostics::process_start_info class and specifies a file name such as an application or document with which to start the process.
      /// @param file_name_ An application or document with which to start a process.
      /// @remarks The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
      /// @remarks You can change the xtd::diagnostics::process_start_info::file_name property after you call this constructor, up to the time that the process starts. After you start the process, changing these values has no effect.
      explicit process_start_info(const std::string& file_name);
      
      /// @brief Initializes a new instance of the xtd::diagnostics::process_start_info class, specifies an application file name with which to start the process, and specifies a set of command-line arguments_ to pass to the application.
      /// @param file_name  An application with which to start a process.
      /// @param arguments Command-line arguments to pass to the application when the process starts.
      /// @remarks The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
      /// @remarks You can change the xtd::diagnostics::process_start_info::file_name or xtd::diagnostics::process_start_info::arguments properties after you call this constructor, up to the time that the process starts. After you start the process, changing these values has no effect.
      process_start_info(const std::string& file_name, const std::string& arguments);
      
      /// @cond
      process_start_info(const process_start_info& process_start_info) = default;
      process_start_info& operator=(const process_start_info&) = default;
      /// @endcond
      
      /// @brief Gets the set of command-line arguments to use when starting the application.
      /// @return File type–specific arguments that the system can associate with the application specified in the xtd::diagnostics::process_start_info::file_name property. The default is an empty string ("").
      const std::string& arguments() const;
      /// @brief Sets the set of command-line arguments to use when starting the application.
      /// @param value File type–specific arguments that the system can associate with the application specified in the xtd::diagnostics::process_start_info::file_name property. The default is an empty string ("").
      /// @return The current instance of process_start_info.
      process_start_info& arguments(const std::string& value);
      
      /// @brief Gets a value indicating whether to start the process in a new window.
      /// @return true if the process should be started without creating a new window to contain it; otherwise, false. The default is false.
      /// @remarks If the xtd::diagnostics::process_start_info::use_shell_execute property is true or the xtd::diagnostics::process_start_info::user_name and xtd::diagnostics::process_start_info::password properties are not empty, the xtd::diagnostics::process_start_info::create_no_window property value is ignored and a new window is created.
      bool create_no_window() const;
      /// @brief Sets a value indicating whether to start the process in a new window.
      /// @param value true if the process should be started without creating a new window to contain it; otherwise, false. The default is false.
      /// @return The current instance of process_start_info.
      /// @remarks If the xtd::diagnostics::process_start_info::use_shell_execute property is true or the xtd::diagnostics::process_start_info::user_name and xtd::diagnostics::process_start_info::password properties are not empty, the xtd::diagnostics::process_start_info::create_no_window property value is ignored and a new window is created.
      process_start_info& create_no_window(bool value);
      
      /// @brief Gets a value that identifies the domain to use when starting the process.
      /// @return string The Active Directory Domain to use when starting the process. The xtd::diagnostics::process_start_info::domain property is primarily of interest to users within enterprise environments that use Active Directory.
      const std::string& domain() const;
      /// @brief Sets a value that identifies the domain to use when starting the process.
      /// @param value string The Active Directory Domain to use when starting the process. The xtd::diagnostics::process_start_info::domain property is primarily of interest to users within enterprise environments that use Active Directory.
      /// @return The current instance of process_start_info.
      process_start_info& domain(const std::string& value);
      
      /// @brief Gets the environment variables that apply to this process and its child processes.
      /// @return std::map<std::string, std::string> A generic dictionary containing the environment variables that apply to this process and its child processes.
      /// @remarks The environment variables contain search paths for files, directories for temporary files, application-specific options, and other similar information. Although you cannot directly set the xtd::diagnostics::process_start_info::environment property, you can modify the generic dictionary returned by the property. For example, the following code adds a TempPath environment variable: @verbatim my_process.start_info().environment().insert({"TempPath", "C:\\Temp"}); @endverbatim. You must set the xtd::diagnostics::process_start_info::use_shell_execute property to false to start the process after changing the xtd::diagnostics::process_start_info::environment property. If xtd::diagnostics::process_start_info:use_shell_execute is true, an xtd::invalid_operation_exception is thrown when the xtd::diagnostics::process::start method is called.
      /// @remarks An applications, using the xtd::diagnostics::process_start_info::environment property is the same as using the xtd::diagnostics::process_start_info::environment_variables property.
      const std::map<std::string, std::string>& environment() const;
      /// @brief Gets the environment variables that apply to this process and its child processes.
      /// @return std::map<std::string, std::string> A generic dictionary containing the environment variables that apply to this process and its child processes.
      /// @remarks The environment variables contain search paths for files, directories for temporary files, application-specific options, and other similar information. Although you cannot directly set the xtd::diagnostics::process_start_info::environment property, you can modify the generic dictionary returned by the property. For example, the following code adds a TempPath environment variable: @verbatim my_process.start_info().environment().insert({"TempPath", "C:\\Temp"}); @endverbatim. You must set the xtd::diagnostics::process_start_info::use_shell_execute property to false to start the process after changing the xtd::diagnostics::process_start_info::environment property. If xtd::diagnostics::process_start_info:use_shell_execute is true, an xtd::invalid_operation_exception is thrown when the xtd::diagnostics::process::start method is called.
      /// @remarks An applications, using the xtd::diagnostics::process_start_info::environment property is the same as using the xtd::diagnostics::process_start_info::environment_variables property.
      std::map<std::string, std::string>& environment();

      /// @brief Gets search paths for files, directories for temporary files, application-specific options, and other similar information.
      /// @return std::map<std::string, std::string> A string dictionary that provides environment variables that apply to this process and child processes. The default is empty.
      /// @remarks Although you cannot set the xtd::diagnostics::process_start_info::environment_variables property, you can modify the generic disctionary returned by the property. For example, the following code adds a TempPath environment variable: @verbatim my_process.startInfo().environment_variables().insert({"TempPath", "C:\\Temp"}); @endverbatim. You must set the xtd::diagnostics::process_start_info::use_shell_execute property to false to start the process after changing the xtd::diagnostics::process_start_info::environment_variables property. If xtd::diagnostics::process_start_info::use_shell_execute is true, an xtd::invalid_operation_exception is thrown when the xtd::diagnostics::process::start method is called.
      const std::map<std::string, std::string>& environment_variables() const;
      /// @brief Gets search paths for files, directories for temporary files, application-specific options, and other similar information.
      /// @return std::map<std::string, std::string> A string dictionary that provides environment variables that apply to this process and child processes. The default is empty.
      /// @remarks Although you cannot set the xtd::diagnostics::process_start_info::environment_variables property, you can modify the generic disctionary returned by the property. For example, the following code adds a TempPath environment variable: @verbatim my_process.startInfo().environment_variables().insert({"TempPath", "C:\\Temp"}); @endverbatim. You must set the xtd::diagnostics::process_start_info::use_shell_execute property to false to start the process after changing the xtd::diagnostics::process_start_info::environment_variables property. If xtd::diagnostics::process_start_info::use_shell_execute is true, an xtd::invalid_operation_exception is thrown when the xtd::diagnostics::process::start method is called.
      std::map<std::string, std::string>& environment_variables();

      /// @brief Gets a value indicating whether an error dialog box is displayed to the user if the process cannot be started.
      /// @return true if an error dialog box should be displayed on the screen if the process cannot be started; otherwise, false. The default is false.
      /// @note xtd::diagnostics::process_start_info::use_shell_execute must be true if you want to set xtd::diagnostics::process_start_info::error_dialog to true.
      bool error_dialog() const;
      /// @brief Sets a value indicating whether an error dialog box is displayed to the user if the process cannot be started.
      /// @param value true if an error dialog box should be displayed on the screen if the process cannot be started; otherwise, false. The default is false.
      /// @return The current instance of process_start_info.
      /// @note xtd::diagnostics::process_start_info::use_shell_execute must be true if you want to set xtd::diagnostics::process_start_info::error_dialog to true.
      process_start_info& error_dialog(bool value);
      
      /// @brief Gets the window handle to use when an error dialog box is shown for a process that cannot be started.
      /// @return A pointer to the handle of the error dialog box that results from a process start failure.
      /// @remarks If xtd::diagnostics::process_start_info::error_dialog is true, the xtd::diagnostics::process_start_info::error_dialog_parent_handle property specifies the parent window for the dialog box that is shown. It is useful to specify a parent to keep the dialog box in front of the application.
      intptr_t error_dialog_parent_handle() const;
      /// @brief Sets the window handle to use when an error dialog box is shown for a process that cannot be started.
      /// @param value A pointer to the handle of the error dialog box that results from a process start failure.
      /// @return The current instance of process_start_info.
      /// @remarks If xtd::diagnostics::process_start_info::error_dialog is true, the xtd::diagnostics::process_start_info::error_dialog_parent_handle property specifies the parent window for the dialog box that is shown. It is useful to specify a parent to keep the dialog box in front of the application.
      process_start_info& error_dialog_parent_handle(intptr_t value);
      
      /// @brief Gets the application or document to start.
      /// @return The name of the application to start, or the name of a document of a file type that is associated with an application and that has a default open action available to it. The default is an empty string ("").
      /// @remarks You must set at least the xtd::diagnostics::process_start_info::file_name property before you start the process. The file name is any application or document. A document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
      /// @remarks The set of file types available to you depends in part on the value of the xtd::diagnostics::process_start_info::use_shell_execute property. If xtd::diagnostics::process_start_info::use_shell_execute is true, you can start any document and perform operations on the file, such as printing, with the xtd::diagnostics::process component. When xtd::diagnostics::process_start_info::use_shell_execute is false, you can start only executables with the xtd::diagnostics::process component.
      const std::string& file_name() const;
      /// @brief Sets the application or document to start.
      /// @param value string The name of the application to start, or the name of a document of a file type that is associated with an application and that has a default open action available to it. The default is an empty string ("").
      /// @return The current instance of process_start_info.
      /// @remarks You must set at least the xtd::diagnostics::process_start_info::file_name property before you start the process. The file name is any application or document. A document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
      /// @remarks The set of file types available to you depends in part on the value of the xtd::diagnostics::process_start_info::use_shell_execute property. If xtd::diagnostics::process_start_info::use_shell_execute is true, you can start any document and perform operations on the file, such as printing, with the xtd::diagnostics::process component. When xtd::diagnostics::process_start_info::use_shell_execute is false, you can start only executables with the xtd::diagnostics::process component.
      process_start_info& file_name(const std::string& value);
      /// @brief Sets the application or document to start.
      /// @param value string The name of the application to start, or the name of a document of a file type that is associated with an application and that has a default open action available to it. The default is an empty string ("").
      /// @return The current instance of process_start_info.
      /// @remarks You must set at least the xtd::diagnostics::process_start_info::file_name property before you start the process. The file name is any application or document. A document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
      /// @remarks The set of file types available to you depends in part on the value of the xtd::diagnostics::process_start_info::use_shell_execute property. If xtd::diagnostics::process_start_info::use_shell_execute is true, you can start any document and perform operations on the file, such as printing, with the xtd::diagnostics::process component. When xtd::diagnostics::process_start_info::use_shell_execute is false, you can start only executables with the xtd::diagnostics::process component.
      process_start_info& file_name(const std::filesystem::path& value);
      /// @cond
      process_start_info& file_name(const char* value);
      /// @endcond

      /// @brief Gets a value that indicates whether the Windows user profile is to be loaded from the registry.
      /// @return true if the Windows user profile should be loaded; otherwise, false. The default is false.
      /// @remarks This property is referenced if the process is being started by using the user name, password, and domain.
      /// @remarks If the value is true, the user's profile in the HKEY_USERS registry key is loaded. Loading the profile can be time-consuming. Therefore, it is best to use this value only if you must access the information in the HKEY_CURRENT_USER registry key.
      bool load_user_profile() const;
      /// @brief Sets a value that indicates whether the Windows user profile is to be loaded from the registry.
      /// @param value true if the Windows user profile should be loaded; otherwise, false. The default is false.
      /// @return The current instance of process_start_info.
      /// @remarks This property is referenced if the process is being started by using the user name, password, and domain.
      /// @remarks If the value is true, the user's profile in the HKEY_USERS registry key is loaded. Loading the profile can be time-consuming. Therefore, it is best to use this value only if you must access the information in the HKEY_CURRENT_USER registry key.
      process_start_info& load_user_profile(bool value);
      
      /// @brief Gets a secure string that contains the user password to use when starting the process.
      /// @return The user password to use when starting the process.
      /// @par Important
      /// The xtd::diagnostics::process_start_info::working_directory property must be set if xtd::diagnostics::process_start_info::user_name and xtd::diagnostics::process_start_info::password are provided. If the property is not set, the default working directory is %SYSTEMROOT%\system32.
      /// @note Setting the xtd::diagnostics::process_start_info::domain, xtd::diagnostics::process_start_info::user_name, and the xtd::diagnostics::process_start_info::password properties in a xtd::diagnostics::process_start_info object is the recommended practice for starting a process with user credentials.
      /// @remarks A xtd::security::secure_string object is like a std::string object in that it has a text value. However, the value of a xtd::security::secure_string object is automatically encrypted, it can be modified until your application marks it as read-only, and it can be deleted from computer memory by either your application.
      /// @note If you provide a value for the xtd::diagnostics::process_start_info::password property, the xtd::diagnostics::process_start_info::use_shell_execute property must be false, o an xtd::invalid_operation_exception will be thrown when the xtd::diagnostics::process::start(process_start_info) method is called.
      const xtd::security::secure_string& pasword() const;
      /// @brief Sets a secure string that contains the user password to use when starting the process.
      /// @param value The user password to use when starting the process.
      /// @return The current instance of process_start_info.
      /// @par Important
      /// The xtd::diagnostics::process_start_info::working_directory property must be set if xtd::diagnostics::process_start_info::user_name and xtd::diagnostics::process_start_info::password are provided. If the property is not set, the default working directory is %SYSTEMROOT%\system32.
      /// @note Setting the xtd::diagnostics::process_start_info::domain, xtd::diagnostics::process_start_info::user_name, and the xtd::diagnostics::process_start_info::password properties in a xtd::diagnostics::process_start_info object is the recommended practice for starting a process with user credentials.
      /// @remarks A xtd::security::secure_string object is like a std::string object in that it has a text value. However, the value of a xtd::security::secure_string object is automatically encrypted, it can be modified until your application marks it as read-only, and it can be deleted from computer memory by either your application.
      /// @note If you provide a value for the xtd::diagnostics::process_start_info::password property, the xtd::diagnostics::process_start_info::use_shell_execute property must be false, o an xtd::invalid_operation_exception will be thrown when the xtd::diagnostics::process::start(process_start_info) method is called.
      process_start_info& pasword(const xtd::security::secure_string& value);

      /// @brief Gets the user password in clear text to use when starting the process.
      /// @return The user password in clear text.
      std::string password_in_clear_text() const;
      /// @brief Sets the user password in clear text to use when starting the process.
      /// @param value string The user password in clear text.
      process_start_info& password_in_clear_text(const std::string& value);
      
      /// @brief Gets a value that indicates whether the error output of an application is written to the xtd::diagnostics::process::standard_error stream.
      /// @return true if error output should be written to xtd::diagnostics::process::standard_error; otherwise, false. The default is false.
      /// @remarks When a xtd::diagnostics::process writes text to its standard error stream, that text is typically displayed on the console. By redirecting the xtd::diagnostics::process::standard_error stream, you can manipulate or suppress the error output of a process. For example, you can filter the text, format it differently, or write the output to both the console and a designated log file.
      /// @note You must set xtd::diagnostics::process_start_info::use_shell_execute to false if you want to set xtd::diagnostics::process_start_info::redirect_standard_error to true. Otherwise, reading from the xtd::diagnostics::process::standard_error stream throws an exception.
      /// @remarks The redirected xtd::diagnostics::process::standard_error stream can be read synchronously or asynchronously. Methods such as xtd::io::sream_reader::read, xtd::io::sream_reader::read_ine and xtd::io::sream_reader::read_to_end perform synchronous read operations on the error output stream of the process. These synchronous read operations do not complete until the associated xtd::diagnostics::process writes to its xtd::diagnostics::process::standard_error stream, or closes the stream.
      /// @remarks In contrast, xtd::diagnostics::process::begin_error_read_line starts asynchronous read operations on the xtd::diagnostics::process::standard_error stream. This method enables a designated event handler for the stream output and immediately returns to the caller, which can perform other work while the stream output is directed to the event handler.
      /// @note The application that is processing the asynchronous output should call the xtd::diagnostics::process::wait_for_exit method to ensure that the output buffer has been flushed.
      /// @remarks Synchronous read operations introduce a dependency between the caller reading from the xtd::diagnostics::process::standard_eror stream and the child process writing to that stream. These dependencies can cause deadlock conditions. When the caller reads from the redirected stream of a child process, it is dependent on the child. The caller waits for the read operation until the child writes to the stream or closes the stream. When the child process writes enough data_ to fill its redirected stream, it is dependent on the parent. The child process waits for the next write operation until the parent reads from the full stream or closes the stream. The deadlock condition results when the caller and child process wait for each other to complete an operation, and neither can continue. You can avoid deadlocks by evaluating dependencies between the caller and child process.
      /// For example, the following code shows how to read from a redirected stream and wait for the child process to exit.
      /// @code
      /// // Start the child process.
      /// process p;
      /// Redirect the error stream of the child process.
      /// p.start_info().use_shell_execute(false);
      /// p.start_info().redirect_standard_error(true);
      /// p.start_info().file_name("write_500_lines");
      /// p.start();
      /// // Do not wait for the child process to exit before
      /// // reading to the end of its redirected error stream.
      /// // p.wait_for_exit();
      /// // Read the error stream first and then wait.
      /// string error = stream_reader(p.standard_error()).read_ro_end();
      /// p.wait_for_exit();
      /// @endcode
      /// @remarks The code example avoids a deadlock condition by calling read_stream(p.standard_error()).read_to_end before p.wait_for_exit. A deadlock condition can result if the parent process calls p.wait_for_exit before stream_reader(p.standard_error()).read_to_end and the child process writes enough text to fill the redirected stream. The parent process would wait indefinitely for the child process to exit. The child process would wait indefinitely for the parent to read from the full xtd::diagnostics::process::standardE_error stream.
      /// @remarks There is a similar issue when you read all text from both the standard output and standard error streams. For example, the following code performs a read operation on both streams.
      /// @code
      /// // Do not perform a synchronous read to the end of both
      /// // redirected streams.
      /// // string output = stream_reader(p.standard_output()).read_to_end();
      /// // string error = stream_reader(p.standard_error()).read_to_end();
      /// // p.wait_for_exit();
      /// // Use asynchronous read operations on at least one of the streams.
      /// p.begin_output_read_line();
      /// string error = stream_reader(p.standard_error()).read_to_rnd();
      /// p.wait_for_exit();
      /// @endcode
      /// @remarks The code example avoids the deadlock condition by performing asynchronous read operations on the StandardOutput stream. A deadlock condition results if the parent process calls p.StandardOutput.ReadToEnd followed by p.StandardError.ReadToEnd and the child process writes enough text to fill its error stream. The parent process would wait indefinitely for the child process to close its StandardOutput stream. The child process would wait indefinitely for the parent to read from the full StandardError stream.
      /// @remarks You can use asynchronous read operations to avoid these dependencies and their deadlock potential. Alternately, you can avoid the deadlock condition by creating two threads and reading the output of each stream on a separate thread.
      bool redirect_standard_error() const;
      process_start_info& redirect_standard_error(bool value);
      
      /// @biref Gets or sets a value indicating whether the input for an application is read from the Process.StandardInput stream.
      /// @return bool true if input should be read from Process.StandardInput; otherwise, false. The default is false.
      /// @remarks A Process can read input text from its standard input stream, typically the keyboard. By redirecting the StandardInput stream, you can programmatically specify the input of a process. For example, instead of using keyboard input, you can provide text from the contents of a designated file or output from another application.
      /// @note You must set UseShellExecute to false if you want to set RedirectStandardInput to true. Otherwise, writing to the StandardInput stream throws an exception.
      bool redirect_standard_input() const;
      process_start_info& redirect_standard_input(bool value);
      
      /// @brief Gets or sets a value that indicates whether the textual output of an application is written to the Process.StandardOutput stream.
      /// @return bool true if output should be written to Process.StandardOutput; otherwise, false. The default is false.
      /// @remarks When a Process writes text to its standard stream, that text is typically displayed on the console. By setting RedirectStandardOutput to true to redirect the StandardOutput stream, you can manipulate or suppress the output of a process. For example, you can filter the text, format it differently, or write the output to both the console and a designated log file.
      /// @note You must set UseShellExecute to false if you want to set RedirectStandardOutput to true. Otherwise, reading from the StandardOutput stream throws an exception.
      /// @remarks The redirected StandardOutput stream can be read synchronously or asynchronously. Methods such as Read, ReadLine, and ReadToEnd perform synchronous read operations on the output stream of the process. These synchronous read operations do not complete until the associated Process writes to its StandardOutput stream, or closes the stream.
      /// @remarks In contrast, BeginOutputReadLine starts asynchronous read operations on the StandardOutput stream. This method enables a designated event handler (see OutputDataReceived) for the stream output and immediately returns to the caller, which can perform other work while the stream output is directed to the event handler.
      /// @note The application that is processing the asynchronous output should call the WaitForExit method to ensure that the output buffer has been flushed.
      /// @remarks Synchronous read operations introduce a dependency between the caller reading from the StandardOutput stream and the child process writing to that stream. These dependencies can cause deadlock conditions. When the caller reads from the redirected stream of a child process, it is dependent on the child. The caller waits for the read operation until the child writes to the stream or closes the stream. When the child process writes enough data_ to fill its redirected stream, it is dependent on the parent. The child process waits for the next write operation until the parent reads from the full stream or closes the stream. The deadlock condition results when the caller and child process wait for each other to complete an operation, and neither can continue. You can avoid deadlocks by evaluating dependencies between the caller and child process.
      /// @remarks For example, the following code shows how to read from a redirected stream and wait for the child process to exit.
      /// @code
      /// Process p;
      /// p.StartInfo().UseShellExecute = false;
      /// p.StartInfo().RedirectStandardOutput = true;
      /// p.StartInfo().FileName = "Write500Lines.exe";
      /// p.Start();
      ///
      /// // To avoid deadlocks, always read the output stream first and then wait.
      /// string output = p.StandardOutput.ReadToEnd();
      /// p.WaitForExit();
      /// @endcode
      /// @remarks The code example avoids a deadlock condition by calling p.StandardOutput.ReadToEnd before p.WaitForExit. A deadlock condition can result if the parent process calls p.WaitForExit before p.StandardOutput.ReadToEnd and the child process writes enough text to fill the redirected stream. The parent process would wait indefinitely for the child process to exit. The child process would wait indefinitely for the parent to read from the full StandardOutput stream.
      /// @remarks There is a similar issue when you read all text from both the standard output and standard error streams. For example, the following C# code performs a read operation on both streams.
      /// @code
      /// // To avoid deadlocks, use asynchronous read operations on at least one of the streams.
      /// // Do not perform a synchronous read to the end of both redirected streams.
      /// p.BeginOutputReadLine();
      /// string error = p.StandardError().ReadToEnd();
      /// p.WaitForExit();
      /// @endcode
      /// @remarks The code example avoids the deadlock condition by performing asynchronous read operations on the StandardOutput stream. A deadlock condition results if the parent process calls p.StandardOutput.ReadToEnd followed by p.StandardError.ReadToEnd and the child process writes enough text to fill its error stream. The parent process would wait indefinitely for the child process to close its StandardOutput stream. The child process would wait indefinitely for the parent to read from the full StandardError stream.
      /// @remarks You can use asynchronous read operations to avoid these dependencies and their deadlock potential. Alternately, you can avoid the deadlock condition by creating two threads and reading the output of each stream on a separate thread.
      bool redirect_standard_output() const;
      process_start_info& redirect_standard_output(bool value);
      
      /// @brief Gets or sets the user name to be used when starting the process.
      /// @return string The user name to use when starting the process.
      /// @par Important
      /// The WorkingDirectory property must be set if UserName and Password are provided. If the property is not set, the default working directory is %SYSTEMROOT%\system32.
      /// @remarks If the UserName property is not an empty string, the UseShellExecute property must be false, or an InvalidOperationException will be thrown when the Process.Start(process_start_info) method is called.
      const std::string& user_name() const;
      process_start_info& user_name(const std::string& value);
      
      /// @brief Gets or sets a value indicating whether to use the operating system shell to start the process.
      /// @return true if the shell should be used when starting the process; false if the process should be created directly from the executable file. The default is true.
      /// @remarks Setting this property to false enables you to redirect input, output, and error streams.
      /// @note UseShellExecute must be false if the UserName property is not null or an empty string, or an InvalidOperationException will be thrown when the Process.Start(process_start_info) method is called.
      /// @remarks When you use the operating system shell to start processes, you can start any document (which is any registered file type associated with an executable that has a default open action) and perform operations on the file, such as printing, by using the Process object. When UseShellExecute is false, you can start only executables by using the Process object.
      /// @note UseShellExecute must be true if you set the ErrorDialog property to true.
      /// @remarks The WorkingDirectory property behaves differently depending on the value of the UseShellExecute property. When UseShellExecute is true, the WorkingDirectory property specifies the location of the executable. If WorkingDirectory is an empty string, it is assumed that the current directory contains the executable.
      /// @remarks When UseShellExecute is false, the WorkingDirectory property is not used to find the executable. Instead, it is used only by the process that is started and has meaning only within the context of the new process. When UseShellExecute is false, the FileName property can be either a fully qualified path to the executable, or a simple executable name that the system will attempt to find within folders specified by the PATH environment variable.
      bool use_shell_execute() const;
      process_start_info& use_shell_execute(bool value);
      
      /// @brief Gets or sets the verb to use when opening the application or document specified by the FileName property.
      /// @return string The action to take with the file that the process opens. The default is an empty string (""), which signifies no action.
      /// @remarks Each file name extension has its own set of verbs, which can be obtained by using the Verbs property. For example, the "print" verb will print a document specified by using FileName. The default verb can be specified by using an empty string (""). Examples of verbs are "Edit", "Open", "OpenAsReadOnly", "Print", and "Printto". You should use only verbs that appear in the set of verbs returned by the Verbs property.
      /// @remarks When you use the Verb property, you must include the file name extension when you set the value of the FileName property. The file name does not need to have an extension if you manually enter a value for the Verb property.
      std::string verb() const;
      process_start_info& verb(const std::string& value);
      
      /// @brief Gets the set of verbs associated with the type of file specified by the FileName property.
      /// @return Array<string> The actions that the system can apply to the file indicated by the FileName property.
      /// @remarks The Verbs property enables you to determine the verbs that can be used with the file specified by the FileName property. You can set the Verb property to the value of any verb in the set. Examples of verbs are "Edit", "Open", "OpenAsReadOnly", "Print", and "Printto".
      /// @remarks When you use the Verbs property, you must include the file name extension when you set the value of the FileName property. The file name extension determines the set of possible verbs.
      std::vector<std::string> verbs() const;
      
      /// @brief Gets or sets the window state to use when the process is started.
      /// @return ProcessWindowStyle One of the enumeration values that indicates whether the process is started in a window that is maximized, minimized, normal (neither maximized nor minimized), or not visible. The default is Normal.
      /// @exception InvalidEnumArgumentException The window style is not one of the ProcessWindowStyle enumeration members.
      process_window_style window_style() const;
      process_start_info& window_style(process_window_style value);
      
      /// When the UseShellExecute property is false, gets or sets the working directory for the process to be started. When UseShellExecute is true, gets or sets the directory that contains the process to be started.
      /// @return string When UseShellExecute is true, the fully qualified name of the directory that contains the process to be started. When the UseShellExecute property is false, the working directory for the process to be started. The default is an empty string ("").
      /// @par Important
      /// The WorkingDirectory property must be set if UserName and Password are provided. If the property is not set, the default working directory is %SYSTEMROOT%\system32.
      /// @remarks If the directory is already part of the system path variable, you do not have to repeat the directory's location in this property.
      /// @remarks The WorkingDirectory property behaves differently when UseShellExecute is true than when UseShellExecute is false. When UseShellExecute is true, the WorkingDirectory property specifies the location of the executable. If WorkingDirectory is an empty string, the current directory is understood to contain the executable.
      /// @note When UseShellExecute is true, the working directory of the application that starts the executable is also the working directory of the executable.
      /// @remarks When UseShellExecute is false, the WorkingDirectory property is not used to find the executable. Instead, its value applies to the process that is started and only has meaning within the context of the new process.
      const std::string& working_directory() const;
      process_start_info& working_directory(const std::string& value);
      
    private:
      std::string file_name_;
      std::string arguments_;
      bool create_no_window_ = false;
      std::string domain_;
      bool error_dialog_ = false;
      intptr_t error_dialog_parent_handle_ = 0;
      std::map<std::string, std::string> environment_variables_;
      bool load_user_profile_ = false;
      xtd::security::secure_string password_;
      bool redirect_standard_error_ = false;
      bool redirect_standard_input_ = false;
      bool redirect_standard_output_ = false;
      std::string user_name_;
      bool use_shell_execute_ = true;
      std::string verb_;
      process_window_style window_style_ = process_window_style::normal;
      std::string working_directory_;
    };
  }
}
