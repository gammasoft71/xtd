# xtd.forms (Winforms) Examples

[This folder](.) contains all examples used by [xtd::forms](../xtd.forms) docmentation and more.

## Hello World

* [hello_world_forms](hello_world/hello_world_forms/README.md) The classic first application "Hello, World!" with  [xtd::forms::label](../xtd.forms/include/xtd/forms/label.hpp) control.
* [hello_world_message_box](hello_world/hello_world_message_box/README.md) The classic first application "Hello, World!" with [xtd::forms::message_box](../xtd.forms/include/xtd/forms/message_box.hpp) control.
* [hello_world_paint](hello_world/hello_world_paint/README.md) The classic first application "Hello, Wrold!" with GDI+ drawing objects.

## Application

* [application](application/application/README.md) shows how to create an application with [xtd::forms::application](../xtd.forms/include/xtd/forms/application.hpp) class.
* [application_context](application/application_context/README.md) shows how to create an application with [xtd::forms::application](../xtd.forms/include/xtd/forms/application.hpp) class with [xtd::forms::application_context](../xtd.forms/include/xtd/forms/application_context.hpp) class.

## Controls

* [button](controls/button/README.md) represents a Windows [xtd::forms::button](../xtd.forms/include/xtd/forms/button.hpp) control.
* [check_box](controls/check_box/README.md) represents a Windows [xtd::forms::check_box](../xtd.forms/include/xtd/forms/check_box.hpp) control.
* [checked_list_box](controls/checked_list_box/README.md) represents a Windows control to display a list of check_box.
* [combo_box](controls/combo_box/README.md) represents a Windows [xtd::forms::combo_box](../xtd.forms/include/xtd/forms/combo_box.hpp)control.
* [control](controls/control/README.md) defines the base class for controls, which are components with visual representation.
* **date_time_picker** represents a Windows control that allows the user to select a date and a time and to display the date and time with a specified format.
* **domain_up_down** represents a Windows spin box (also known as an up-down control) that displays string values.
* **hscroll_bar** represents a standard Windows horizontal scroll bar.
* [label](controls/label/README.md) represents a standard Windows [xtd::forms::label](../xtd.forms/include/xtd/forms/label.hpp).
* **link_label** represents a Windows label control that can display hyperlinks.
* [list_box](controls/list_box/README.md) represents a Windows control to display a list of items.
* **list_view** represents a Windows list view control, which displays a collection of items that can be displayed using one of four different views.
* **masked_text_box** uses a mask to distinguish between proper and improper user input.
* **month_calendar** specifies values for navigating among accessible objects.
* **notify_icon** specifies a component that creates an icon in the notification area. This class cannot be inherited.
* **numeric_up_down** represents a Windows spin box (also known as an up-down control) that displays numeric values.
* **picture_box** represents a Windows picture box control for displaying an image.
* [progress_bar](controls/progress_bar/README.md) eepresents a Windows [xtd::forms::progress_bar](../xtd.forms/include/xtd/forms/progress_bar.hpp) control.
* [radio_button](controls/radio_button/README.md) enables the user to select a single option from a group of choices when paired with other [xtd::forms::radio_button](../xtd.forms/include/xtd/forms/radio_button.hpp) controls.
* **rich_text_box** represents a Windows rich text box control.
* **splitter** represents a splitter control that enables the user to resize docked controls. Splitter has been replaced by SplitContainer and is provided only for compatibility with previous versions.
* [text_box](controls/text_box/README.md) represents a Windows [xtd::forms::text_box](../xtd.forms/include/xtd/forms/text_box.hpp) control.
* **tool_tip** Represents a small rectangular pop-up window that displays a brief description of a control's purpose when the user rests the pointer on the control.
* [track_bar](controls/track_bar/README.md) represents a standard Windows [xtd::forms::track_bar](../xtd.forms/include/xtd/forms/track_bar.hpp).
* **tree_view** displays a hierarchical collection of labeled items, each represented by a TreeNode.
* [user_control](controls/user_control/README.md) defines the base class for user controls.
* **vscroll_bar** represents a standard Windows vertical scroll bar.
* **web_browser** enables the user to navigate Web pages inside your form.

## Containers

* **flow_layout_panel** represents a panel that dynamically lays out its contents horizontally or vertically.
* [form](containers/form/README.md) represents a window or dialog box that makes up an application's user interfa
* [group_box](containers/group_box/README.md) represents a Windows control that displays a frame around a group of controls with an optional caption.
* [panel](containers/panel/README.md) used to group collections of controls.
* **split_container** represents a control consisting of a movable bar that divides a container's display area into two resizable panels.
*  **tab_control** manages a related set of tab pages.
* **table_layout_panel** represents a panel that dynamically lays out its contents in a grid composed of rows and columns.

## Menus and Toolbars

* **ContextMenuStrip** represents a shortcut menu.
* **MenuStrip** provides a menu system for a form.
* **StatusStrip** represents a Windows status bar control.
* **ToolStrip** provides a container for Windows toolbar objects.
* **ToolStripContainer** provides panels on each side of the form and a central panel that can hold one or more controls.

## Datas

* **BindingNavigator** represents the navigation and manipulation user interface (UI) for controls on a form that are bound to data.
* **BindingSource** encapsulates the data source for a form.
* **Chart** 
* **DataGridView** displays data in a customizable grid.
* **DataSet** 

## Components

* **BackgroundWorker** executes an operation on a separate thread.
* **DirectoryEntry** The DirectoryEntry class encapsulates a node or object in the Active Directory Domain Services hierarchy.
* **DirectorySearcher** performs queries against Active Directory Domain Services.
* **ErrorProvider** provides a user interface for indicating that a control on a form has an error associated with it.
* **EventLog** provides interaction with Windows event logs.
* **FileSystemWatcher** listens to the file system change notifications and raises events when a directory, or file in a directory, changes.
* **HelpProvider** provides pop-up or online Help for controls.
* **ImageList** provides methods to manage a collection of Image objects. This class cannot be inherited.
* **MessageQueue** provides access to a queue on a Message Queuing server.
* **PerformanceCounter** represents a Windows NT performance counter component.
* **Process** provides access to local and remote processes and enables you to start and stop local system processes.
* **SerialPort** represents a serial port resource.
* **ServiceControler** represents a Windows service and allows you to connect to a running or stopped service, manipulate it, or get information about it.
* [Timer](components/timer/README.md) implements a timer that raises an event at user-defined intervals. This timer is optimized for use in Windows Forms applications and must be used in a window.

## Printing

* **PageSetupDialog** enables users to change page-related print settings, including margins and paper orientation. This class cannot be inherited.
* **PrintDialog** lets users select a printer and choose which sections of the document to print from a Windows Forms application.
* **PrintDocument** defines a reusable object that sends output to a printer, when printing from a Windows Forms application.
* **PrintPreviewControl** represents the raw preview part of print previewing from a Windows Forms application, without any dialog boxes or buttons. Most PrintPreviewControl objects are found on PrintPreviewDialog objects, but they do not have to be.
* **PrintPreviewDialog** represents a dialog box form that contains a PrintPreviewControl for printing from a Windows Forms application.

## Common Dialogs

* [ColorDialog](common_dialogs/color_dialog/README.md) represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
* [FolderBrowserDialog](common_dialogs/folder_browser_dialog/README.md) prompts the user to select a folder. This class cannot be inherited.
* [FontDialog](common_dialogs/font_dialog/README.md) prompts the user to choose a font from among those installed on the local computer.
* [MessageBox](common_dialogs/message_box/README.md) displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A MessageBox can contain text, buttons, and symbols that inform and instruct the user.
* [OpenFileDialog](common_dialogs/open_file_dialog/README.md) displays a standard dialog box that prompts the user to open a file.
* [SaveFileDialog](common_dialogs/save_file_dialog/README.md) prompts the user to select a location for saving a file.

## Events

* [ApplicationIdle](events/application_idle/README.md) shows how to create an Application with Application class and Idle event.
* [MouseEvent](events/mouse_event/README.md) demonstrates the use of some mouse events.
* [EnableChangedEvent](events/enable_changed_event/README.md) demonstrates the use of System::Windows::Forms::Control::EnableChaned event.
* [FontChangedEvent](events/font_changed_event/README.md) demonstrates the use of System::Windows::Forms::Control::FontChaned event.
* [FormClick](events/form_click/README.md) demonstrates the use of System::Windows::Forms::Form control and Click event.
* [WndProc](events/wnd_proc/README.md) demonstrates the use of System::Windows::Forms::Control::WndProc method.

## Others

* [Button2](others/button2/README.md) demonstrates the use of System::Windows::Forms::Button control.
* [ColoredForms](others/colored_forms/README.md) demonstrates the use of System::Windows::Forms::Form control and System::Drawing::Color class.
* [ColoredTabPages](others/colored_tab_pages/README.md) demonstrates the use of System::Windows::Forms::TabControl and colored System::Windows::Forms::TabPage controls.
* [DataFormatsGetFormat](others/data_formats_get_format/README.md) demonstrates the use of System::Windows::Forms::DataFormats::GetFormat method.
* [GroupBoxAndCheckBox](others/group_box_and_check_box/README.md) demonstrates the use of System::Windows::Forms::GroupBox and System::Windows::Forms::CheckBox controls.
* [GroupBoxAndRadioButton](others/group_box_and_radio_button/README.md) demonstrates the use of System::Windows::Forms::GroupBox and System::Windows::Forms::RadioButton controls.
* [LabelsAndUnicodeText](others/labels_and_unicode_text/README.md) demonstrates the use of System::Windows::Forms::Label control and Unicode text.
* [Lines](others/lines/README.md) demonstrates the use of System::Windows::Forms::Label control to draw simple lines.
* [SomeControls](others/some_controls/README.md) demonstrates the use of some controls.
* [StopwatchForm](others/stopwatch_form/README.md) demonstrates the use of Stopwatch class, Label and Button controls.
* [SystemSound](others/system_sound/README.md) demonstrates the use of System::Media::SystemSound component.
* [All](.) You can see all examples here. 
