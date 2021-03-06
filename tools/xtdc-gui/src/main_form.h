/// @file
/// @brief Contains main_form class.
#pragma once
#include "project_type_item_control.h"
#include "project_type_items_control.h"
#include "xtd_example_item.h"
#include <limits>
#include <memory>
#include <vector>
#include <xtd/forms/background_worker.h>
#include <xtd/forms/button.h>
#include <xtd/forms/check_box.h>
#include <xtd/forms/choice.h>
#include <xtd/forms/form.h>
#include <xtd/forms/label.h>
#include <xtd/forms/list_box.h>
#include <xtd/forms/panel.h>
#include <xtd/forms/picture_box.h>
#include <xtd/forms/progress_dialog.h>
#include <xtd/forms/tab_control.h>
#include <xtd/forms/tab_page.h>
#include <xtd/forms/text_box.h>

namespace xtdc_gui {
  /// @brief Represents the main form
  class main_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the main_form class.
    main_form();

    // The main entry point for the application.
    static void main();
    
  private:
    void add_to_create_recent_projects(size_t create_project_items_index);
    void add_to_open_recent_projects(const std::string& project_path);
    void delete_from_create_recent_projects(size_t create_project_items_index);
    void delete_from_open_recent_projects(const std::string& project_path);
    void init();
    void init_create_create_recent_projects_list_box();
    void init_startup_open_recent_projects_list_box();
    void new_project(const std::string& project_path, size_t project_type_items_index);
    void new_project(const std::string& project_path, project_type type, project_language language, project_sdk sdk);
    void open_project(const std::string& project_path);
    void run_project(const std::string& project_path);

    std::unique_ptr<xtd::forms::background_worker> background_worker_;
    std::unique_ptr<xtd::forms::progress_dialog> progress_dialog_;
    xtd::forms::panel startup_panel_;
    xtd::forms::label startup_title_label_;
    xtd::forms::label startup_open_recent_project_title_label_;
    xtd::forms::list_box startup_open_recent_projects_list_box_;
    xtd::forms::label startup_get_started_title_label_;
    xtd::forms::button startup_open_project_button_;
    xtd::forms::button startup_run_project_button_;
    xtd::forms::button startup_new_project_button_;
    xtd::forms::button startup_open_xtd_examples_button_;

    xtd::forms::panel open_xtd_examples_panel_;
    xtd::forms::label open_xtd_examples_title_label_;
    xtd::forms::tab_control open_xtd_example_tab_control_;
    xtd::forms::tab_page open_xtd_example_console_tab_page_;
    xtd::forms::tab_page open_xtd_example_forms_tab_page_;
    xtd::forms::tab_page open_xtd_example_tunit_tab_page_;
    xtd::forms::picture_box open_xtd_example_console_picture_box_;
    xtd::forms::picture_box open_xtd_example_forms_picture_box_;
    xtd::forms::picture_box open_xtd_example_tunit_picture_box_;
    xtd::forms::label open_xtd_example_console_title_label_;
    xtd::forms::label open_xtd_example_forms_title_label_;
    xtd::forms::label open_xtd_example_tunit_title_label_;
    xtd::forms::list_box open_xtd_example_console_list_box_;
    xtd::forms::list_box open_xtd_example_forms_list_box_;
    xtd::forms::list_box open_xtd_example_tunit_list_box_;
    xtd::forms::text_box open_xtd_examples_information_text_box_;
    xtd::forms::picture_box open_xtd_examples_information_picture_box_;

    xtd::forms::panel create_panel_;
    xtd::forms::label create_title_label_;
    xtd::forms::label create_recent_project_title_label_;
    xtd::forms::list_box create_create_recent_projects_list_box_;
    xtd::forms::choice create_language_choice_;
    xtd::forms::choice create_platform_choice_;
    xtd::forms::choice create_type_choice_;
    project_type_items_control create_project_type_items_control_;

    xtd::forms::panel configure_panel_;
    xtd::forms::label configure_title_label_;
    xtd::forms::label configure_project_type_title_label_;
    xtd::forms::label configure_project_name_label_;
    xtd::forms::text_box configure_project_name_text_box_;
    xtd::forms::label configure_project_location_label_;
    xtd::forms::text_box configure_project_location_text_box_;
    xtd::forms::button configure_project_location_button_;

    xtd::forms::check_box auto_close_check_box_;
    xtd::forms::button previous_button_;
    xtd::forms::button next_button_;
    
    size_t current_project_type_index_ = std::numeric_limits<size_t>::max();
    size_t current_open_xtd_example_console_list_box_index_ = 0;
    size_t current_open_xtd_example_forms_list_box_index_ = 0;
    size_t current_open_xtd_example_tunit_list_box_index_ = 0;
    std::vector<xtd_example_item> xtd_console_examples_ {
      {"Console - background color", "shows how to set console background color.", {"xtd.core.examples/console_background_color"}},
      {"Console - beep", "shows how to use console beep.", {"xtd.core.examples/console_beep"}},
      {"Console - buffer", "shows how to use console buffer.\n\nThis code produces the following output:\n\nThe current buffer height is 300 rows.\nThe current buffer width is 85 columns.", {"xtd.core.examples/console_buffer"}},
      {"Console - color", "shows how to set background and foreground color.", {"xtd.core.examples/console_color"}},
      {"Console - cursor", "shows how to use console cursor position.\n\nThis code produces the following output:\n\n+---+\n|   |\n|   |\n|   |\n+---+\n\nAll done!", {"xtd.core.examples/console_cursor"}},
      {"Console - in out", "shows how to use in and out stream properties.", {"xtd.core.examples/console_in_out"}},
      {"Console - read line", "shows how to use read line.", {"xtd.core.examples/console_read_line"}},
      {"Hello world - hello world (console)", "The classic first \"Hello, World!\" console application.\n\nThis code produces the following output with colors :\n\nHello, World!", {"xtd.core.examples/hello_world_console"}},
      {"other - song", "Show how to play song with beep.", {"xtd.core.examples/console_song"}},
    };
    std::vector<xtd_example_item> xtd_forms_examples_ {
      {"Hello world - hello world (emoticons)", "The classic first \"Hello, World!\" with xtd::forms::emoticons component.", {"xtd.forms.examples/hello_worlds/hello_world_emoticons"}},
      {"Hello world - hello world (label)", "The classic first \"Hello, World!\" with xtd::forms::label control.", {"xtd.forms.examples/hello_worlds/hello_world_label"}},
      {"Hello world - hello world (message box)", "The classic first \"Hello, World!\" with xtd::forms::message_box dialog.", {"xtd.forms.examples/hello_worlds/hello_world_message_box"}},
      {"Hello world - hello world (message box) 2", "The classic first \"Hello, World!\" with xtd::forms::message_box dialog.", {"xtd.forms.examples/hello_worlds/hello_world_message_box2"}},
      {"Hello world - hello world (paint)", "The classic first \"Hello, World!\" with GDI+ drawing objects.", {"xtd.forms.examples/hello_worlds/hello_world_paint"}},
      {"Hello world - hello world (say)", "The classic first application \"Hello, World!\" with say.", {"xtd.forms.examples/hello_worlds/hello_world_say"}},
      
      {"Application - application", "shows how to create an application with xtd::forms::application class.", {"xtd.forms.examples/applications/application"}},
      {"Application - exception", "shows how to create an application with xtd::forms::application and how to manage exception.", {"xtd.forms.examples/applications/application_and_exception"}},
      {"Application - application context", "shows how to create an application with xtd::forms::application and xtd::forms::application_context classes.", {"xtd.forms.examples/applications/application_context"}},
      {"Application - enable dark mode", "shows how to enbale dark mode with xtd::forms::application class.", {"xtd.forms.examples/applications/application_enable_dark_mode"}},
      {"Application - enable light mode", "shows how to enbale light mode with xtd::forms::application class.", {"xtd.forms.examples/applications/application_enable_light_mode"}},
      {"Application - restart", "shows how to restart application with xtd::forms::application::restart method.", {"xtd.forms.examples/applications/application_restart"}},
      {"Application - use wait cursor", "shows how to show and hide wait cursor application with xtd::forms::application::use_wait_cursor method.", {"xtd.forms.examples/applications/application_use_wait_cursor"}},

      {"Common controls - button", "represents a xtd::forms::button control.", {"xtd.forms.examples/common_controls/button"}},
      {"Common controls - buttons", "shows how to create a button with xtd::froms::buttons factory class.", {"xtd.forms.examples/common_controls/buttons"}},
      {"Common controls - check box", "represents a Windows xtd::forms::check_box control.", {"xtd.forms.examples/common_controls/check_box"}},
      {"Common controls - check boxes", "shows how to create a check box with xtd::froms::check_boxes factory class", {"xtd.forms.examples/common_controls/check_boxes"}},
      {"Common controls - checked list box", "represents a Windows control to display a list of check box.", {"xtd.forms.examples/common_controls/checked_list_box"}},
      {"Common controls - choice", "represents a Windows xtd::forms::choice control.", {"xtd.forms.examples/common_controls/choice"}},
      {"Common controls - combo box", "represents a Windows xtd::forms::combo_box control.", {"xtd.forms.examples/common_controls/combo_box"}},
      {"Common controls - command link button", "represents a Windows xtd::forms::command_link_button control.", {"xtd.forms.examples/common_controls/command_link_button"}},
      {"Common controls - control", "defines the base class for controls, which are components with visual representation.", {"xtd.forms.examples/common_controls/control"}},
      {"Common controls - domain up down", "represents a Windows spin box (also known as an up-down control) that displays string values.", {"xtd.forms.examples/common_controls/domain_up_down"}},
      {"Common controls - label", " represents a standard Windows xtd::forms::label.", {"xtd.forms.examples/common_controls/label"}},
      {"Common controls - list box", "represents a Windows control to display a list of items.", {"xtd.forms.examples/common_controls/list_box"}},
      {"Common controls - nunmeric up down", "represents a Windows spin box (also known as an up-down control) that displays numeric values.", {"xtd.forms.examples/common_controls/numeric_up_down"}},
      {"Common controls - picture box", "represents a Windows picture box control for displaying an image.", {"xtd.forms.examples/common_controls/picture_box"}},
      {"Common controls - progress bar", "represents a Windows xtd::forms::progress_bar control.", {"xtd.forms.examples/common_controls/progress_bar"}},
      {"Common controls - radio button", "enables the user to select a single option from a group of choices when paired with other xtd::forms::radio_button controls.", {"xtd.forms.examples/common_controls/radio_button"}},
      {"Common controls - radio buttons", "shows how to create a radio button with xtd::froms::radio_buttons factory class", {"xtd.forms.examples/common_controls/radio_buttons"}},
      {"Common controls - splitter", "represents a Windows xtd::forms::splitter control.", {"xtd.forms.examples/common_controls/splitter"}},
      {"Common controls - switch button", "represents a Windows xtd::forms::switch_button control.", {"xtd.forms.examples/common_controls/switch_button"}},
      {"Common controls - text box", "represents a Windows xtd::forms::text_box control.", {"xtd.forms.examples/common_controls/text_box"}},
      {"Common controls - toggle button", "represents a Windows xtd::forms::toggle_button control.", {"xtd.forms.examples/common_controls/toggle_button"}},
      {"Common controls - track bar", "represents a standard Windows xtd::forms::track_bar.", {"xtd.forms.examples/common_controls/track_bar"}},
      {"Common controls - up down button", "represents a Windows spin button.", {"xtd.forms.examples/common_controls/up_down_button"}},
      {"Common controls - user control", "defines the base class for user controls.", {"xtd.forms.examples/common_controls/user_control"}},
      
      {"Picker controls - color picker", "represents a Windows control that allows the user to select and display a color.", {"xtd.forms.examples/picker_controls/color_picker"}},
      {"Picker controls - date time_picker", "represents a Windows control that allows the user to select a date and a time and to display the date and time with a specified format.", {"xtd.forms.examples/picker_controls/date_time_picker"}},
      {"Picker controls - font picker", "represents a Windows control that allows the user to select and display a font.", {"xtd.forms.examples/picker_controls/font_picker"}},

      {"Control containers - form", "represents a window or dialog box that makes up an application's user interface.", {"xtd.forms.examples/conttrtol_containers/form"}},
      {"Control containers - group box", "represents a Windows control that displays a frame around a group of controls with an optional caption.", {"xtd.forms.examples/conttrtol_containers/group_box"}},
      {"Control containers - panel", "used to group collections of controls.", {"xtd.forms.examples/conttrtol_containers/panel"}},
      {"Control containers - split container", "represents a control consisting of a movable bar that divides a container's display area into two resizable panels.", {"xtd.forms.examples/conttrtol_containers/split_container"}},
      {"Control containers - tab control", "manages a related set of tab pages.", {"xtd.forms.examples/conttrtol_containers/tab_control"}},
 
      {"Controls - dot matrix display", "represents a xtd::forms::fourteen_segment_display control.", {"xtd.forms.examples/controls/dot_matrix_display"}},
      {"Controls - fourteen segment display", "represents a xtd::forms::fourteen_segment_display control.", {"xtd.forms.examples/controls/fourteen_segment_display"}},
      {"Controls - lcd label", "represents a xtd::forms::lcd_label control.", {"xtd.forms.examples/controls/lcd_label"}},
      {"Controls - nine segment display", "represents a xtd::forms::nine_segment_display control.", {"xtd.forms.examples/controls/fourteen_nine_display"}},
      {"Controls - seven segment display", "represents a xtd::forms::seven_segment_display control.", {"xtd.forms.examples/controls/seven_segment_display"}},
      {"Controls - sixteen segment display", "represents a xtd::forms::sixteen_segment_display control.", {"xtd.forms.examples/controls/sixteen_segment_display"}},
      
      {"Custom controls - line", "demonstrates the use of xtd::forms::user_controlcontrol to draw simple lines.", {"xtd.forms.examples/custom_controls/line"}},
      {"Custom controls - numeric text box", "demonstrates how to customize xtd::forms::text_box control.", {"xtd.forms.examples/custom_controls/numeric_text_box"}},
      
      {"Menus and toolbars - menu", "provides a menu system for a form.", {"xtd.forms.examples/menus_and_toolbars/menu"}},

      {"Components - background worker", "executes an operation on a separate thread.", {"xtd.forms.examples/components/background_worker"}},
      {"Components - button images", "shows how to create a bitmap button with xtd::froms::button_images factory class.", {"xtd.forms.examples/components/button_images"}},
      {"Components - button renderer", "shows how to draw button with xtd::froms::button_renderer class.", {"xtd.forms.examples/components/button_renderer"}},
      {"Components - check box renderer", "shows how to draw check box with xtd::froms::check_box_renderer class.", {"xtd.forms.examples/components/check_box_renderer"}},
      {"Components - countries", "demonstrates the use of xtd::forms::countries class.", {"xtd.forms.examples/components/countries"}},
      {"Components - cursor", "represents the image used to paint the mouse pointer.", {"xtd.forms.examples/components/cursor"}},
      {"Components - emoticons", "demonstrates the use of xtd::forms::emoticons class.", {"xtd.forms.examples/components/emoticons"}},
      {"Components - image list", "provides methods to manage a collection of image objects.", {"xtd.forms.examples/components/image_list"}},
      {"Components - radio button renderer", "shows how to draw radio button with xtd::froms::radio_button_renderer class.", {"xtd.forms.examples/components/radio_button_renderer"}},
      {"Components - screen", "represents a display device or multiple display devices on a single system.", {"xtd.forms.examples/components/screen"}},
      {"Components - settings", "represents settings application.", {"xtd.forms.examples/components/settings_example"}},
      {"Components - settings2", "represents settings application.", {"xtd.forms.examples/components/settings_example2"}},
      {"Components - system images", "demonstrates the use of xtd::drawing::system_images class.", {"xtd.forms.examples/components/system_images"}},
      {"Components - texts", "demonstrates the use of xtd::forms::texts class.", {"xtd.forms.examples/components/texts"}},
      {"Components - timer", "implements a timer that raises an event at user-defined intervals.", {"xtd.forms.examples/components/timer"}},
      {"Components - translator", "demonstrates the use of xtd::forms::translator strings for internationalization.", {"xtd.forms.examples/components/translattor"}},
      {"Components - use wait cursor", "shows how to use xtd::forms::use_wait_cursor component.", {"xtd.forms.examples/components/use_wait_cursor"}},

      {"Common dialogs - color dialog", "represents a common dialog box that displays available colors along with controls that enable the user to define custom colors.", {"xtd.forms.examples/common_dialogs/color_dialog"}},
      {"Common dialogs - folder browser dialog", "prompts the user to select a folder.", {"xtd.forms.examples/common_dialogs/folder_browser_dialog"}},
      {"Common dialogs - font dialog", "prompts the user to choose a font from among those installed on the local computer.", {"xtd.forms.examples/common_dialogs/font_dialog"}},
      {"Common dialogs - input dialog", "prompts the user to input text.", {"xtd.forms.examples/common_dialogs/input_dialog"}},
      {"Common dialogs - open file dialog", "displays a standard dialog box that prompts the user to open a file.", {"xtd.forms.examples/common_dialogs/open_file_dialog"}},
      {"Common dialogs - save file dialog", "prompts the user to select a location for saving a file.", {"xtd.forms.examples/common_dialogs/save_file_dialog"}},

      {"Dialogs - about dialog", "represents a common dialog box that displays about dialog.", {"xtd.forms.examples/dialogs/about_dialog"}},
      {"Dialogs - about dialog (system)", "represents a common dialog box that displays system about dlialog.", {"xtd.forms.examples/dialogs/about_dialog_system"}},
      {"Dialogs - message box", "displays a message window, also known as a dialog box, which presents a message to the user. It is a modal window, blocking other actions in the application until the user closes it. A MessageBox can contain text, buttons, and symbols that inform and instruct the user.", {"xtd.forms.examples/dialogs/message_box"}},

      {"Custom dialogs - user dialog", "demonstrates the use of xtd::forms::form as dialog.", {"xtd.forms.examples/custom_dialogs/user_dialog"}},

      {"Event - application idle", "shows how to create an application with xtd::forms::application class and idle event.", {"xtd.forms.examples/events/application_idle"}},
      {"Event - enable changed event", "demonstrates the use of enable_changed event.", {"xtd.forms.examples/events/enable_changed_event"}},
      {"Event - font changed event", "demonstrates the use of font_changed event.", {"xtd.forms.examples/events/font_changed_event"}},
      {"Event - form click", "demonstrates the use of xtd::forms::form control and click event.", {"xtd.forms.examples/events/form_click"}},
      {"Event - form and messages", "demonstrates some events received by xtd::forms::form.", {"xtd.forms.examples/events/form_and_messages"}},
      {"Event - form paint", "demonstrates paint event with xtd::forms::form.", {"xtd.forms.examples/events/form_paint"}},
      {"Event - key events", "demonstrates the use of mouse events.", {"xtd.forms.examples/events/key_events"}},
      {"Event - mouse events", "demonstrates the use of mouse events.", {"xtd.forms.examples/events/mouse_events"}},
      {"Event - move form", "demonstrates the use of mouse events.", {"xtd.forms.examples/events/move_form"}},
      {"Event - send message", "demonstrates how to send message to xtd::forms::form.", {"xtd.forms.examples/events/send_message_to_form"}},
      {"Event - wnd proc", "demonstrates the xtd::control::wnd_proc method.", {"xtd.forms.examples/events/wnd_proc"}},
      
      {"Others - auto scroll", "demonstrates the use of xtd::forms::panel container with xtd::forms::scrollable_control::auto_scroll.", {"xtd.forms.examples/others/auto_scroll"}},
      {"Others - bitmap button", "demonstrates the use of xtd::forms::button control with image.", {"xtd.forms.examples/others/bitmap_button"}},
      {"Others - button 2", "represents a xtd::forms::button control.", {"xtd.forms.examples/others/button2"}},
      {"Others - button 3", "represents a xtd::forms::button control.", {"xtd.forms.examples/others/button3"}},
      {"Others - button 4", "represents a xtd::forms::button control.", {"xtd.forms.examples/others/button4"}},
      {"Others - calculator", "demonstrates the use of xtd::forms::label and  xtd::forms::button controls.", {"xtd.forms.examples/others/calculator"}},
      {"Others - clock", "demonstrates the use of xtd::forms::lcd_label control.", {"xtd.forms.examples/others/clock"}},
      {"Others - colored forms", "demonstrates the use of xtd::foxms::form container with colored background.", {"xtd.forms.examples/others/colored_forms"}},
      {"Others - colored tab pages", "demonstrates the use of xtd::foxms::tab_page container with colored background.", {"xtd.forms.examples/others/colored_tab_pages"}},
      {"Others - colors", "demonstrates the use of xtd::forms::user_control control with xtd::drawing::color.", {"xtd.forms.examples/others/colors"}},
      {"Others - docked panels", "demonstrates the use of xtd::forms::panel container with xtd::forms::control::dock style.", {"xtd.forms.examples/others/docked_panels"}},
      {"Others - font families", "demonstrates the use of xtd::drawing::font_families class.", {"xtd.forms.examples/others/font_families"}},
      {"Others - form and main", "demonstrates how to use startup_ keyword.", {"xtd.forms.examples/others/form_and_main"}},
      {"Others - form and thread", "demonstrates how a thread can update ui with xtd::forms::control::invoke method.", {"xtd.forms.examples/others/form_and_thread"}},
      {"Others - form show", "demontrate how to launch form as normal window, modeless window and modal window.", {"xtd.forms.examples/others/form_show"}},
      {"Others - form window state", "demonstrates the use of xtd::forms::form window state.", {"xtd.forms.examples/others/form_window_state"}},
      {"Others - form 2", "represents a window or dialog box that makes up an application's user interface.", {"xtd.forms.examples/others/form2"}},
      {"Others - group box and check box", "demonstrates the use of xtd::forms::group_box container and  xtd::forms::check_box control.", {"xtd.forms.examples/others/group_box_and_check_box"}},
      {"Others - group box and radio button", "demonstrates the use of xtd::forms::group_box container and  xtd::forms::check_box control.", {"xtd.forms.examples/others/group_box_and_radio_button"}},
      {"Others - input dialog multiline", "demonstrates the use of xtd::forms::input_dialog dialog.", {"xtd.forms.examples/others/input_dialog_multiline"}},
      {"Others - input dialog password", "demonstrates the use of xtd::forms::input_dialog dialog.", {"xtd.forms.examples/others/input_dialog_password"}},
      {"Others - labels and unicode text", "demonstrates the use of xtd::forms::label control with unicode text.", {"xtd.forms.examples/others/labels_and_unicode_text"}},
      {"Others - lcd label with dot matrix", "demonstrates the use of xtd::forms::lcd_label control with dot matrix.", {"xtd.forms.examples/others/lcd_label_with dot matrix"}},
      {"Others - lcd label with fourteen segment", "demonstrates the use of xtd::forms::lcd_label control with fourteen segment.", {"xtd.forms.examples/others/lcd_label_with_fourteen_segment"}},
      {"Others - lcd label with nine segment", "demonstrates the use of xtd::forms::lcd_label control with nine segment.", {"xtd.forms.examples/others/lcd_label_with_nine_segment"}},
      {"Others - lcd label with seven segment", "demonstrates the use of xtd::forms::lcd_label control with seven segment.", {"xtd.forms.examples/others/lcd_label_with_seven_segment"}},
      {"Others - lcd label with sixteen segment", "demonstrates the use of xtd::forms::lcd_label control with sixteen segment.", {"xtd.forms.examples/others/lcd_label_with_sixteen_segment"}},
      {"Others - lcd label 2", "represents a xtd::forms::lcd_label control.", {"xtd.forms.examples/others/lcd_label2"}},
      {"Others - painting", "demonstrates the use of xtd::forms::form, xtd::forms::panel, xtd::forms::track_bar and  xtd::forms::button controls with mouse_down, mouse_move and paint events.", {"xtd.forms.examples/others/painting"}},
      {"Others - smileys", "demonstrates the use of xtd::forms::label control.", {"xtd.forms.examples/others/smileys"}},
      {"Others - stop watch", "demonstrates the use of xtd::forms::button, xtd::forms::label controls and xtd::forms::timer component..", {"xtd.forms.examples/others/stop_watch"}},
      {"Others - system images 2", "demonstrates the use of xtd::drawing::system_images class.", {"xtd.forms.examples/others/system_images2"}},
      {"Others - system images 3", "demonstrates the use of xtd::drawing::system_images class.", {"xtd.forms.examples/others/system_images3"}},
      {"Others - system report", "shows system_repoort with xtd::forms::text_box control.", {"xtd.forms.examples/others/system_report"}},
      {"Others - text box multiline", "represents a Windows xtd::forms::text_box control.", {"xtd.forms.examples/others/text_box_multiline"}},
      {"Others - text box password", "represents a Windows xtd::forms::text_box control.", {"xtd.forms.examples/others/text_box_password"}},
      {"Others - toggle button 2", "represents a Windows xtd::forms::toggle_button control.", {"xtd.forms.examples/others/toggle_button2"}},
      {"Others - track bar 2", "represents a standard Windows xtd::forms::track_bar.", {"xtd.forms.examples/others/track_bar2"}},
      {"Others - wiggly", "shows how to animate a user control using timer and timer::event. In addition, the example demonstrates how to use graphics::measure_string to determine the size of text on screen.", {"xtd.forms.examples/others/wiggly"}},
      
      {"Games - game of life", "The Game of Life is not your typical computer game. It is a 'cellular automaton', and was invented by Cambridge mathematician John Conway.", {"xtd.forms.examples/games/game_of_life"}},
      {"Games - minesweeper", "The goal of the game is to uncover all the squares that do not contain mines.", {"xtd.forms.examples/games/minesweeper"}},
      
      {"Demo - button appearance", "demonstrates the different appearance of xtd::forms::button control.", {"xtd.forms.examples/custom_dialogs/button_appearance"}},
      {"Demo - check box appearance", "demonstrates the different appearance of xtd::forms::check_box control.", {"xtd.forms.examples/custom_dialogs/check_box_appearance"}},
      {"Demo - lcd label appearance", "demonstrates the different appearance of xtd::forms::lcd_label control.", {"xtd.forms.examples/custom_dialogs/lcd_label_appearance"}},
      {"Demo - message box appearance", "demonstrates the different appearance of xtd::forms::message_box dialog.", {"xtd.forms.examples/custom_dialogs/message_box_appearance"}},
    };
    std::vector<xtd_example_item> xtd_tunit_examples_ {
      {"assert - abort", "Tshows how to use assert abort.", "xtd.tunit.examples/assert_abort"},
      {"assert - abort", "Tshows how to use assert abort.", "xtd.tunit.examples/assert_abort"},
      {"Hello world - hello world (assert)", "The classic first \"Hello, World!\" unit tests application.", "xtd.tunit.examples/hello_world_tunit"},
    };
  };
}
