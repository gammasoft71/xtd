# xtd.forms (Winforms) Examples

[This folder](.) contains all examples used by [xtd::forms](../xtd.forms)Docmentation and more.

## Hello World

* [Hello World](hello_world/hello_world_forms/README.md) The classic first application "Hello, World!" with  [xtd::forms::label](../xtd.forms/include/xtd/forms/label.hpp) control.
* [Hello World with message_box](hello_world/hello_world_message_box/README.md) The classic first application "Hello, World!" with [xtd::forms::message_box](../xtd.forms/include/xtd/forms/message_box.hpp) control.
* [Hello World with paint event](hello_world/hello_world_paint/README.md) The classic first application "Hello, Wrold!" with GDI+ drawing objects.

## Application

* [Application](application/application/README.md) shows how to create an application with [xtd::forms::application](../xtd.forms/include/xtd/forms/application.hpp) class.
* [Application context](application/application_context/README.md) shows how to create an application with [xtd::forms::application](../xtd.forms/include/xtd/forms/application.hpp) class with [xtd::forms::application_context](../xtd.forms/include/xtd/forms/application_context.hpp) class.

## Common Controls

* [Button](common_controls/button/README.md) represents a Windows button control.
* [Check box](common_controls/check_box/README.md) represents a Windows check box control.
* [Checked list box](common_control/check_list_box/README) represents a Windows control to display a list of check box items.
* [Combo box](common_control/combo_box/README) represents a Windows combo box control.
* [Control](./Control/README.md) refines the base class for controls, which are components with visual representation.
* **DateTimePicker** represents a Windows control that allows the user to select a date and a time and to display the date and time with a specified format.
* **DomainUpDown** represents a Windows spin box (also known as an up-down control) that displays string values.
* **HScroolBar** represents a standard Windows horizontal scroll bar.
* [Label](./Label/README.md) represents a standard Windows label.
* **LinkLabel** represents a Windows label control that can display hyperlinks.
* **ListBox** represents a Windows control to display a list of items.
* **ListView** represents a Windows list view control, which displays a collection of items that can be displayed using one of four different views.
* **MaskedTextBox** uses a mask to distinguish between proper and improper user input.
* **MonthCalendar** specifies values for navigating among accessible objects.
* **NotifyIcon** specifies a component that creates an icon in the notification area. This class cannot be inherited.
* **NumericUpDown** represents a Windows spin box (also known as an up-down control) that displays numeric values.
* **PictureBox** represents a Windows picture box control for displaying an image.
* [ProgressBar](./ProgressBar/README.md) eepresents a Windows progress bar control.
* [RadioButton](./RadioButton/README.md) enables the user to select a single option from a group of choices when paired with other RadioButton controls.
* [RichTextBox](./RichTextBox/README.md) represents a Windows rich text box control.
* **Splitter** represents a splitter control that enables the user to resize docked controls. Splitter has been replaced by SplitContainer and is provided only for compatibility with previous versions.
* [TextBox](./TextBox/README.md) represents a Windows text box control.
* **ToolTip** Represents a small rectangular pop-up window that displays a brief description of a control's purpose when the user rests the pointer on the control.
* [TrackBar](./TrackBar/README.md) represents a standard Windows track bar.
* **TreeView** displays a hierarchical collection of labeled items, each represented by a TreeNode.
* **VScroolBar** represents a standard Windows vertical scroll bar.
* **WebBrowser** enables the user to navigate Web pages inside your form.

## Containers

* **FlowLayoutPanel** represents a panel that dynamically lays out its contents horizontally or vertically.
* [Form](./Form/README.md) represents a window or dialog box that makes up an application's user interfa
* [GroupBox](./GroupBox/README.md) represents a Windows control that displays a frame around a group of controls with an optional caption.
* [Panel](./Panel/README.md) used to group collections of controls.
* **SplitContainer** represents a control consisting of a movable bar that divides a container's display area into two resizable panels.
* [TabControl](./TabControl/README.md) manages a related set of tab pages.
* **TableLayoutPanel** represents a panel that dynamically lays out its contents in a grid composed of rows and columns.

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
* [Timer](./TimerForm/README.md) implements a timer that raises an event at user-defined intervals. This timer is optimized for use in Windows Forms applications and must be used in a window.

## Printing

* **PageSetupDialog** enables users to change page-related print settings, including margins and paper orientation. This class cannot be inherited.
* **PrintDialog** lets users select a printer and choose which sections of the document to print from a Windows Forms application.
* **PrintDocument** defines a reusable object that sends output to a printer, when printing from a Windows Forms application.
* **PrintPreviewControl** represents the raw preview part of print previewing from a Windows Forms application, without any dialog boxes or buttons. Most PrintPreviewControl objects are found on PrintPreviewDialog objects, but they do not have to be.
* **PrintPreviewDialog** represents a dialog box form that contains a PrintPreviewControl for printing from a Windows Forms application.

## Dialogs

* [ColorDialog](./ColorDialog/README.md) represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.
* [FolderBrowserDialog](./FolderBrowserDialog/README.md) prompts the user to select a folder. This class cannot be inherited.
* [FontDialog](./FontDialog/README.md) prompts the user to choose a font from among those installed on the local computer.
* [MessageBox](./MessageBox/README.md) displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A MessageBox can contain text, buttons, and symbols that inform and instruct the user.
* [OpenFileDialog](./OpenFileDialog/README.md) displays a standard dialog box that prompts the user to open a file.
* [SaveFileDialog](./SaveFileDialog/README.md) prompts the user to select a location for saving a file.

## Events

* [ApplicationIdle](./ApplicationIdle/README.md) shows how to create an Application with Application class and Idle event.
* [MouseEvent](./MouseEvent/README.md) demonstrates the use of some mouse events.
* [EnableChangedEvent](./EnableChangedEvent/README.md) demonstrates the use of System::Windows::Forms::Control::EnableChaned event.
* [FontChangedEvent](./FontChangedEvent/README.md) demonstrates the use of System::Windows::Forms::Control::FontChaned event.
* [FormClick](./FormClick/README.md) demonstrates the use of System::Windows::Forms::Form control and Click event.
* [WndProc](./WndProc/README.md) demonstrates the use of System::Windows::Forms::Control::WndProc method.

## Other

* [Button2](./Button2/README.md) demonstrates the use of System::Windows::Forms::Button control.
* [ColoredForms](./ColoredForms/README.md) demonstrates the use of System::Windows::Forms::Form control and System::Drawing::Color class.
* [ColoredTabPages](./ColoredTabPages/README.md) demonstrates the use of System::Windows::Forms::TabControl and colored System::Windows::Forms::TabPage controls.
* [DataFormatsGetFormat](./DataFormatsGetFormat/README.md) demonstrates the use of System::Windows::Forms::DataFormats::GetFormat method.
* [GroupBoxAndCheckBox](./GroupBoxAndCheckBox/README.md) demonstrates the use of System::Windows::Forms::GroupBox and System::Windows::Forms::CheckBox controls.
* [GroupBoxAndRadioButton](./GroupBoxAndRadioButton/README.md) demonstrates the use of System::Windows::Forms::GroupBox and System::Windows::Forms::RadioButton controls.
* [LabelsAndUnicodeText](./LabelsAndUnicodeText/README.md) demonstrates the use of System::Windows::Forms::Label control and Unicode text.
* [Lines](./Lines/README.md) demonstrates the use of System::Windows::Forms::Label control to draw simple lines.
* [SomeControls](./SomeControls/README.md) demonstrates the use of some controls.
* [StopwatchForm](./StopwatchForm/README.md) demonstrates the use of Stopwatch class, Label and Button controls.
* [SystemSound](./SystemSound/README.md) demonstrates the use of System::Media::SystemSound component.
* [All](.) You can see all examples here. 
