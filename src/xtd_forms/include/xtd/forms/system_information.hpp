#pragma once
#include <xtd/drawing/font.h>
#include <xtd/drawing/size.h>
#include "arrange_direction.hpp"
#include "arrange_starting_position.hpp"
#include "boot_mode.hpp"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides information about the current system environment.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The system_information class provides static properties that can be used to get information about the current system environment. The class provides access to information such as Windows display element sizes, operating system settings, network availability, and the capabilities of hardware installed on the system. This class cannot be instantiated.
    /// @remarks For more information about system-wide parameters, see "SystemParametersInfo" in the Platform SDK documentation at http://msdn.microsoft.com.
    class system_information static_ {
    public:
      /// @cond
      /// @endcond

      /// @brief Gets the active window tracking delay.
      /// @return The active window tracking delay, in milliseconds.
      static int32_t active_window_tracking_delay();
      
      /// @brief Gets a value that indicates the direction in which the operating system arranges minimized windows.
      /// @return One of the ArrangeDirection values that indicates the direction in which the operating system arranges minimized windows.
      /// @remarks The arrange_direction property indicates the direction in which minimized windows are arranged on the desktop or in a Multiple Document Interface (MDI) container.
      static xtd::forms::arrange_direction arrange_direction();

      /// @brief Gets an ArrangeStartingPosition value that indicates the starting position from which the operating system arranges minimized windows.
      /// @return One of the ArrangeStartingPosition values that indicates the starting position from which the operating system arranges minimized windows.
      /// @remarks The ArrangeStartingPosition property indicates the corner of a screen or window in which the operating system begins to arrange minimized windows.
      static xtd::forms::arrange_starting_position arrange_starting_position();

      /// @brief Gets a BootMode value that indicates the boot mode the system was started in.
      /// @return One of the boot_mode values that indicates the boot mode the system was started in.
      /// @remarks The boot_mode property indicates whether the operating system was started in a normal or safe boot mode.
      static xtd::forms::boot_mode boot_mode();

      /// @brief Gets the thickness, in pixels, of a three-dimensional (3-D) style window or system control border.
      /// @return A size that indicates the width, in pixels, of a 3-D style vertical border, and the height, in pixels, of a 3-D style horizontal border.
      /// @remarks The border_3d_size property indicates the thickness, in pixels, of a three-dimensional (3-D) style system control border.
      /// @remarks The Width property of the border_3d_size property indicates the width of a vertical 3-D border. The Height property of the border_3d_size property indicates the height of a horizontal 3-D border.
      /// @remarks The border_size property indicates the thickness of a window or system control border that is not a 3-D style border.
      static xtd::drawing::size border_3d_size();

      /// @brief Gets the border multiplier factor that is used when determining the thickness of a window's sizing border.
      /// @return The multiplier used to determine the thickness of a window's sizing border.
      static int32_t border_multiplier_factor();

      /// @brief Gets the thickness, in pixels, of a flat-style window or system control border.
      /// @return A size that indicates the width, in pixels, of a vertical border, and the height, in pixels, of a horizontal border.
      /// @remarks The border_size property indicates the thickness of a flat-style system control border in pixels.
      /// @remarks The Width property of the border_size property indicates the width of a vertical flat-style border. The Height property of the border_size property indicates the height of a horizontal flat-style border.
      /// @remarks The border_3d_size property of the SystemInformation class indicates the thickness of a three-dimensional (3-D) style window or system control border.
      static xtd::drawing::size border_size();

      /// @brief Gets the standard size, in pixels, of a button in a window's title bar.
      /// @return A size that indicates the standard dimensions, in pixels, of a button in a window's title bar.
      /// @remarks The caption_button_size property indicates the standard dimensions of a button in the title bar of a window.
      /// @remarks The value of this property can be used to ensure that a button is properly sized to fit within the title bar of a window. Window caption buttons should be sized less than or equal to the standard dimensions for window caption buttons to ensure that they can be displayed in view correctly.
      static xtd::drawing::size caption_button_size();

      /// @brief Gets the height, in pixels, of the standard title bar area of a window.
      /// @return The height, in pixels, of the standard title bar area of a window.
      /// @remarks The caption_height property indicates the height of the standard window title bar area, in pixels.
      static int32_t caption_height();

      /// @brief Gets the caret blink time
      /// @return The caret blink time.
      static int32_t caret_blink_time();

      /// @brief Gets the width, in pixels, of the caret in edit controls.
      /// @return The width, in pixels, of the caret in edit controls.
      static int32_t caret_width();

      /// @brief Gets the NetBIOS computer name of the local computer.
      /// @return The name of this computer.
      /// @remarks The ComputerName property retrieves the NetBIOS name of the local computer. This is accomplished with a call into the native System Information function GetComputerName. This name is established at system startup_, when the system reads it from the registry. If the local computer is a node in a cluster, ComputerName returns the name of the cluster virtual server.
      /// @remarks You can use the computer_name method to determine the name of the computer that is displayed to other users on a network.
      static std::string computer_name();

      /// @brief Gets the maximum size, in pixels, that a cursor can occupy.
      /// @return A size that indicates the maximum dimensions of a cursor in pixels.
      /// @remarks The system cannot create cursors of other sizes.
      static xtd::drawing::size cursor_size();

      /// @brief Gets a value indicating whether the operating system is capable of handling double-byte character set (DBCS) characters.
      /// @return true if the operating system supports DBCS; otherwise, false.
      /// @remarks The dbcs_enabled property indicates whether the current operating system supports DBCS.
      static bool dbcs_enabled();

      /// @brief Gets a value indicating whether the debug version of USER.EXE is installed.
      /// @return true if the debugging version of USER.EXE is installed; otherwise, false.
      static bool debug_os();

      /// @brief Gets the dimensions, in pixels, of the area within which the user must click twice for the operating system to consider the two clicks a double-click.
      /// @return A size that indicates the dimensions, in pixels, of the area within which the user must click twice for the operating system to consider the two clicks a double-click.
      /// @remarks The double_click_size property indicates the size of a rectangular area centered around the point at which the last click occurred. To cause a double-click, a second click must occur within the area of the rectangle before the double-click time elapses.
      static xtd::drawing::size double_click_size();

      /// @brief Gets the maximum number of milliseconds that can elapse between a first click and a second click for the OS to consider the mouse action a double-click.
      /// @return The maximum amount of time, in milliseconds, that can elapse between a first click and a second click for the OS to consider the mouse action a double-click.
      /// @remarks A double-click is a series of two clicks of the mouse button, the second occurring within a specified length of time after, and within a specified distance from, the first. The double-click time is the maximum number of milliseconds that can elapse between the first and second click of a double-click.
      /// @remarks The double_click_time property indicates the maximum number of milliseconds that can elapse before a second click for the second click to cause a double-click.
      static int32_t double_click_time();

      /// @brief Gets a value indicating whether the user has enabled full window drag.
      /// @return true if the user has enabled full window drag; otherwise, false.
      /// @remarks When this property is true, the content of a window is refreshed during a window move or resize drag, using the current position and size as they are updated.
      static bool drag_full_windows();

      /// @brief Gets the width and height of a rectangle centered on the point the mouse button was pressed, within which a drag operation will not begin.
      /// @return A size that specifies the area of a rectangle, in pixels, centered on the point the mouse button was pressed, within which a drag operation will not begin.
      /// @remarks The drag_size property indicates the size, in pixels, of a rectangle centered around the point at which the mouse button was pressed. Windows uses the rectangle as a boundary within which it does not start a drag operation.
      /// @remarks A user can hold a mouse button down and move the mouse within this area before a drag operation begins, which enables the user to click and release the mouse button easily without unintentionally starting a drag operation.
      static xtd::drawing::size drag_size();

      /// @brief Gets the thickness, in pixels, of the frame border of a window that has a caption and is not resizable.
      /// @return A size that specifies the thickness, in pixels, of a fixed sized window border.
      /// @remarks The fixed_frame_border_size property indicates the thickness of the frame, in pixels, around the perimeter of a window that has a caption but is not sizable.
      /// @remarks The Width property of fixed_frame_border_size is the height of the horizontal border and the Height property of fixed_frame_border_size is the width of the vertical border.
      static xtd::drawing::size fixed_frame_border_size();

      /// @brief Gets the font smoothing contrast value used in ClearType smoothing.
      /// @return The ClearType font smoothing contrast value.
      static int32_t font_smoothing_contrast();

      /// @brief Gets the current type of font smoothing.
      /// @return A value that indicates the current type of font smoothing.
      static int32_t font_smoothing_type();

      /// @brief Gets the thickness, in pixels, of the resizing border that is drawn around the perimeter of a window that is being drag resized.
      /// @return A size that indicates the thickness, in pixels, of the width of a vertical resizing border and the height of a horizontal resizing border.
      /// @remarks The frame_border_size property indicates the width and height of the resizing border for a window.
      /// @remarks The Width value of this property is the width of a vertical resizing border. The Height value of this property is the height of a horizontal resizing border.
      static xtd::drawing::size frame_border_size();

      /// @brief Gets a value indicating whether the user has enabled the high-contrast mode accessibility feature.
      /// @return true if the user has enabled high-contrast mode; otherwise, false.
      /// @remarks The high-contrast accessibility feature can make the screen easier for some users to view by enabling a color scheme that can heighten screen contrast with alternative color combinations. Some of the schemes also change font sizes for easier reading.
      /// @remarks The high-contrast mode feature can be enabled or disabled through the Accessibility Options control panel.
      static bool high_contrast();

      /// @brief Gets the thickness of the left and right edges of the system focus rectangle, in pixels.
      /// @return The thickness of the left and right edges of the system focus rectangle, in pixels.
      /// @remarks The HorizontalFocusThickness property indicates the width of the left and right edges of the system focus rectangle, in pixels. The system focus rectangle is used to draw user's attention to a window or area by displaying a rectangular highlighted outline.
      static int32_t horizontal_focus_thickness();

      /// @brief Gets the thickness of the left and right edges of the sizing border around the perimeter of a window being resized, in pixels.
      /// @return The width of the left and right edges of the sizing border around the perimeter of a window being resized, in pixels.
      /// @remarks The HorizontalResizeBorderThickness property indicates the width of the vertical sizing border around the perimeter of a window being resized.
      static int32_t horizontal_resize_border_thickness();

      /// @brief Gets the width, in pixels, of the arrow bitmap on the horizontal scroll bar.
      /// @return The width, in pixels, of the arrow bitmap on the horizontal scroll bar.
      static int32_t horizontal_scroll_bar_arrow_width();

      /// @brief Gets the default height, in pixels, of the horizontal scroll bar.
      /// @return The default height, in pixels, of the horizontal scroll bar.
      static int32_t horizontal_scroll_bar_height();

      /// @brief Gets the width, in pixels, of the scroll box in a horizontal scroll bar.
      /// @return The width, in pixels, of the scroll box in a horizontal scroll bar.
      static int32_t horizontal_scroll_bar_bhumb_width();

      /// @brief Gets the width, in pixels, of an icon arrangement cell in large icon view.
      /// @return The width, in pixels, of an icon arrangement cell in large icon view.
      /// @remarks The IconHorizontalSpacing property indicates the width of the space for an icon in large icon view. The system uses this distance to arrange icons in large icon view.
      static int32_t icon_horizontal_spacing;

      /// @brief Gets the dimensions, in pixels, of the Windows default program icon size.
      /// @return A size that indicates the default dimensions, in pixels, for a program icon.
      static xtd::drawing::size icon_size();

      /// @brief Gets the size, in pixels, of the grid square used to arrange icons in a large-icon view.
      /// @return A size that specifies the dimensions, in pixels, of the grid square used to arrange icons in a large-icon view.
      /// @remarks The icon_spacing_size property indicates the size of the grid rectangle that each icon fits into when the system arranges them in a large-icon view. This value is always greater than or equal to icon_size.
      static xtd::drawing::size icon_spacing_size();

      /// @brief Gets the height, in pixels, of an icon arrangement cell in large icon view.
      /// @return The height, in pixels, of an icon arrangement cell in large icon view.
      /// @remarks The icon_vertical_spacing property indicates the width of the space for an icon in large icon view. The system uses this distance to arrange icons in large icon view.
      static int32_t icon_vertical_spacing();

      /// @brief Gets a value indicating whether active window tracking is enabled.
      /// @return true if active window tracking is enabled; otherwise, false.
      /// @remarks The is_active_window_tracking_enabled property indicates whether active window tracking is enabled. Active window tracking causes any window the mouse is directly over to become the active window.
      static bool is_active_window_tracking_enabled();

      /// @brief Gets a value indicating whether the slide-open effect for combo boxes is enabled.
      /// @return true if the slide-open effect for combo boxes is enabled; otherwise, false.
      /// @remarks The is_combo_box_animation_enabled property indicates whether the slide-open effect for system control combo boxes is enabled.
      /// @remarks When the slide-open effect for system control combo boxes is enabled, the drop down menu of a combo box slides into view when it is displayed, instead of being immediately fully drawn in view.
      static bool is_combo_box_animation_enabled();

      /// @brief Gets a value indicating whether the drop shadow effect is enabled.
      /// @return true if the drop shadow effect is enabled; otherwise, false.
      static bool is_drop_shadow_enabled();

      /// @brief Gets a value indicating whether native user menus have a flat menu appearance.
      /// @return true if native user menus have a flat menu appearance; otherwise, false.
      static bool is_flat_menu_enabled();

      /// @brief Gets a value indicating whether font smoothing is enabled.
      /// @return bool true if the font smoothing feature is enabled; otherwise, false.
      /// @remarks This font smoothing feature uses font antialiasing to make font curves appear smoother by painting pixels at different gray levels.
      static bool is_font_smoothing_enabled();

      /// @brief Gets a value indicating whether hot tracking of user-interface elements, such as menu names on menu bars, is enabled.
      /// @return bool true if hot tracking of user-interface elements is enabled; otherwise, false.
      /// @remarks The IsHotTrackingEnabled property indicates whether hot tracking of user-interface elements is enabled. Hot tracking means that when the cursor moves over an item, it is highlighted but not selected.
      static bool is_hot_tracking_enabled();

      /// @brief Gets a value indicating whether icon-title wrapping is enabled.
      /// @return bool true if the icon-title wrapping feature is enabled; otherwise, false.
      static bool is_icon_title_wrapping_enabled();

      /// @brief Gets a value indicating whether the user relies on the keyboard instead of the mouse, and prefers applications to display keyboard interfaces that would otherwise be hidden.
      /// @return bool true if keyboard preferred mode is enabled; otherwise, false.
      /// @remarks The IsKeyboardPreferred property indicates whether the user has indicated a preference for keyboard-based input interfaces.
      static bool is_keyboard_preferred();

      /// @brief Gets a value indicating whether the smooth-scrolling effect for list boxes is enabled.
      /// @return true if smooth-scrolling is enabled; otherwise, false.
      /// @remarks The is_list_box_smooth_scrolling_enabled property indicates whether the smooth-scrolling effect for system control list boxes is enabled.
      static bool is_list_box_smooth_scrolling_enabled();

      /// @brief Gets a value indicating whether menu fade or slide animation features are enabled.
      /// @return true if menu fade or slide animation is enabled; otherwise, false.
      /// @remarks The is_menu_animation_enabled property indicates whether either of the fade or slide animation features of system control menus is enabled.
      /// @remarks If the value of this property is true, the IsMenuFadeEnabled property indicates whether menus use fade or slide animation.
      static bool is_menu_animation_enabled();

      /// @brief Gets a value indicating whether menu fade animation is enabled.
      /// @return true if fade animation is enabled; false if it is disabled.
      /// @remarks The is_menu_fade_enabled property indicates whether a menu uses fade animation, if menu animation is enabled. The IsMenuAnimationEnabled property indicates whether menu animation is enabled.
      /// @remarks If menu animation is enabled and the value of this property is true, menus use fade animation. If menu animation is enabled and the value of this property is false, menus use slide animation. If menu animation is disabled, the value of this property is meaningless.
      static bool is_menu_fade_enabled();

      /// @brief Gets a value indicating whether window minimize and restore animation is enabled.
      /// @return true if window minimize and restore animation is enabled; otherwise, false.
      /// @remarks The is_minimize_restore_animation_enabled property indicates whether the window minimize and restore sequence is animated.
      static bool is_minimize_restore_animation_enabled();

      /// @brief Gets a value indicating whether the selection fade effect is enabled.
      /// @return true if the selection fade effect is enabled; otherwise, false.
      /// @remarks The is_selection_fade_enabled property indicates whether the selection fade effect is enabled. The selection fade effect causes a menu item selected by the user to remain on the screen briefly while fading out after the menu is dismissed.
      static bool is_selection_fade_enabled();

      /// @brief Gets a value indicating whether the snap-to-default-button feature is enabled.
      /// @return true if the snap-to-default-button feature is enabled; otherwise, false.
      /// @remarks The is_snap_to_default_enabled property indicates whether the snap-to-default-button feature is enabled. If the feature is enabled, the mouse cursor automatically moves to the default button, such as OK or Apply, of a dialog box.
      static bool is_snap_to_default_enabled();

      /// @brief Gets a value indicating whether the gradient effect for window title bars is enabled.
      /// @return true if the gradient effect for window title bars is enabled; otherwise, false.
      /// @remarks The is_title_bar_gradient_enabled property indicates whether the background of window title bars are drawn using a gradient fill effect.
      /// @note This property is supported only on Windows 98, Windows Millennium Edition, Windows 2000, Windows XP, and the Windows Server 2003 family.
      static bool is_title_bar_gradient_enabled();

      /// @brief Gets a value indicating whether tool_tip animation is enabled.
      /// @return true if tool_tip animation is enabled; otherwise, false.
      /// @remarks The is_tool_tip_animation_enabled property indicates whether tool_tips can fade or slide into view.
      /// @note This property is supported only on Windows 2000, Windows XP, and the Windows Server 2003 family. On other platforms, this property returns false.
      static bool is_tool_tip_animation_enabled();

      /// @brief Gets the height, in pixels, of the Kanji window at the bottom of the screen for double-byte character set (DBCS) versions of Windows.
      /// @return The height, in pixels, of the Kanji window.
      /// @remarks The kanji_window_height property indicates the height of the Kanji window on operating systems that support DBCS. The DbcsEnabled property indicates whether the operating system supports DBCS.
      static int32_t kanji_window_height();

      /// @brief Gets the keyboard repeat-delay setting.
      /// @return The keyboard repeat-delay setting, from 0 (approximately 250 millisecond delay) through 3 (approximately 1 second delay).
      /// @remarks This property indicates the amount of time that elapses after a key is pressed and held down until keystroke repeat messages are sent by the operating system. This value is in the range from 0 (approximately 250 millisecond delay) through 3 (approximately 1 second delay). The actual delay associated with each value may vary depending on the hardware.
      /// @remarks The keyboard_speed property indicates the repeat speed setting that determines the length of time between each keystroke repeat message sent by the operating system.
      static int32_t keyboard_delay();

      /// @brief Gets the keyboard repeat-speed setting.
      /// @return The keyboard repeat-speed setting, from 0 (approximately 2.5 repetitions per second) through 31 (approximately 30 repetitions per second).
      /// @remarks This property indicates the time between each keystroke repeat message that is sent when a user presses and holds a key down. This is a value in the range from 0 (approximately 2.5 repetitions per second) through 31 (approximately 30 repetitions per second). The actual repeat rates are hardware-dependent and may vary from a linear scale by as much as 20%.
      /// @remarks The keyboard_delay property indicates the length of time after a key is pressed and held down before keystroke repeat messages are sent by the operating system.
      static int32_t keyboard_speed();

      /// @brief Gets the default maximum dimensions, in pixels, of a window that has a caption and sizing borders.
      /// @return A size that specifies the maximum dimensions, in pixels, to which a window can be sized.
      /// @remarks The max_window_track_size property indicates the maximum dimensions to which a user can drag resize a window. The value returned by max_>indow_track_size refers to the dimensions of the entire desktop.
      static xtd::drawing::size max_window_track_size();

      /// @brief Gets a value indicating whether menu access keys are always underlined.
      /// @return true if menu access keys are always underlined; false if they are underlined only when the menu is activated or receives focus.
      /// @remarks The menu_access_keys_underlined property indicates whether the menu shortcut keys are underlined in menu text even when the menu has not been activated or received focus.
      static bool menu_access_keys_underlined();

      /// @brief Gets the default width, in pixels, for menu-bar buttons and the height, in pixels, of a menu bar.
      /// @return A size that indicates the default width for menu-bar buttons, in pixels, and the height of a menu bar, in pixels.
      /// @remarks The size.width() value of this property indicates the default width for a button on a menu-bar, in pixels. The size.height() value of this property indicates the height of a menu bar, in pixels.
      static xtd::drawing::size menu_bar_button_size();

      /// @brief Gets the default dimensions, in pixels, of menu-bar buttons.
      /// @return A size that indicates the default dimensions, in pixels, of menu-bar buttons.
      /// @remarks This property indicates the default dimensions, in pixels, for menu-bar buttons, such as the child window close button used in the multiple document interface.
      static xtd::drawing::size menu_button_size();

      /// @brief Gets the dimensions, in pixels, of the default size of a menu check mark area.
      /// @return A size that indicates the default size, in pixels, of a menu check mark area.
      /// @remarks The menu_check_size property indicates the size of the image used by Windows to display a check mark area next to a selected menu item.
      static xtd::drawing::size menu_check_size();

      /// @brief Gets the font used to display text on menus.
      /// @return The Font used to display text on menus.
      /// @remarks The menu_font property indicates the font used to display text on menus.
      static xtd::drawing::font menu_font();
      
      /// @brief Gets the height, in pixels, of one line of a menu.
      /// @return The height, in pixels, of one line of a menu.
      /// @remarks The menu_height property indicates the height that is currently defined by Windows for a menu bar.
      static int32_t menu_height();
      
      /// @brief Gets the time, in milliseconds, that the system waits before displaying a cascaded shortcut menu when the mouse cursor is over a submenu item.
      /// @return The time, in milliseconds, that the system waits before displaying a cascaded shortcut menu when the mouse cursor is over a submenu item.
      /// @remarks The menu_show_delay property indicates the time, in milliseconds, that the system waits before displaying a cascaded shortcut menu when the mouse cursor is over a submenu item.
      static int32_t menu_show_delay();
      
      /// @brief Gets a value indicating whether the operating system is enabled for the Hebrew and Arabic languages.
      /// @return true if the operating system is enabled for Hebrew or Arabic; otherwise, false.
      /// @remarks The mid_east_enabled property indicates whether the operating system is enabled for the Hebrew and Arabic languages.
      static bool mid_east_enabled();
      
      /// @brief Gets the dimensions, in pixels, of a normal minimized window.
      /// @return A size that indicates the dimensions, in pixels, of a normal minimized window.
      /// @remarks The minimized_window_size property indicates the size of the area occupied by a normal minimized window.
      static xtd::drawing::size minimized_window_size();
      
      /// @brief Gets the dimensions, in pixels, of the area each minimized window is allocated when arranged.
      /// @return A size that indicates the area each minimized window is allocated when arranged.
      /// @remarks The minimized_window_spacing_size property indicates the size, in pixels, of an arrangement grid cell for a minimized window. Each minimized window fits into a rectangle this size when arranged.
      /// @remarks The value of this property is always greater than or equal to the value of the minimum_window_size property.
      static xtd::drawing::size minimized_window_spacing_size();
      
      /// @brief Gets the minimum width and height for a window, in pixels.
      /// @return A size that specifies the minimum allowable dimensions of a window, in pixels.
      /// @remarks The minimum_window_size property indicates the dimensions specified by Windows as the minimum size for a window. You can use this property to limit the resizing of windows to dimensions not exceeding either dimension returned by this property.
      /// @note Developers of applications capable of resizing windows may want to use the value of this property to ensure that the application does not attempt to resize the window to a lesser width or height, since the dimensions of the window would be limited by the system.
      static xtd::drawing::size minimum_window_size();
      
      /// @brief Gets the default minimum dimensions, in pixels, that a window may occupy during a drag resize.
      /// @return A size that indicates the default minimum width and height of a window during resize, in pixels.
      /// @remarks The min_window_track_size property indicates the default smallest window size that can be produced by using the borders to size the window.
      /// @remarks The user cannot drag the window frame to a size smaller than these dimensions. A form can override these values by setting the minimum_size property.
      static xtd::drawing::size min_window_track_size();
      
      /// @brief Gets the number of display monitors on the desktop.
      /// @return The number of monitors that make up the desktop.
      /// @remarks The monitor_count property indicates the number of monitors currently recognized by the operating system. This property returns a value greater than one only if multiple monitors are currently recognized by the operating system.
      /// @note This property is supported only on Windows 98, Windows Millennium Edition, Windows 2000, Windows XP, and the Windows Server 2003 family.
      static int32_t monitor_count();
      
      /// @brief Gets a value indicating whether all the display monitors are using the same pixel color format.
      /// @return true if all monitors are using the same pixel color format; otherwise, false.
      /// @remarks The monitors_same_display_format indicates whether all monitors currently recognized by the operating system are using the same pixel color format.
      /// @remarks Pixel formats define the data structure used to encode pixel color and luminosity information. The pixel_format enumeration indicates a set of standard pixel color formats. Pixel values can be encoded in a variety of formats, with differing color value ranges and bit precisions, and differing positions of bits in a pixel data format structure.
      /// @note Two displays can have the same bit depth but different color formats.
      /// @note This property is supported only on Windows 98, Windows Millennium Edition, Windows 2000, Windows XP, and the Windows Server 2003 family.
      static bool monitors_same_display_format();
      
      /// @brief Gets the number of buttons on the mouse.
      /// @return The number of buttons on the mouse, or zero if no mouse is installed.
      /// @remarks The mouse_buttons property indicates the number of mouse buttons recognized on the currently installed mouse.
      /// @remarks You can use mouse_buttons property to toggle additional functionality for users with more or less than the standard number of mouse buttons supported by your application.
      static int32_t mouse_buttons();
      
      /// @brief Gets a value indicating whether the functions of the left and right mouse buttons have been swapped.
      /// @return true if the functions of the left and right mouse buttons are swapped; otherwise, false.
      static bool mouse_buttons_swapped();
      
      /// @brief Gets the dimensions, in pixels, of the rectangle within which the mouse pointer has to stay for the mouse hover time before a mouse hover message is generated.
      /// @return A size that indicates the dimensions, in pixels, of the rectangle within which the mouse pointer has to stay for the mouse hover time before a mouse hover message is generated.
      /// @remarks The mouse_hover_size property indicates the size of the rectangle within which the mouse pointer has to stay for the mouse hover time before a mouse hover message is generated.
      /// @remarks The mouse_hover_time property indicates the time, in milliseconds, that a mouse pointer must remain within an area the size of the MouseHoverSize property in order to generate a mouse hover message.
      static xtd::drawing::size mouse_hover_size();
      
      /// @brief Gets the time, in milliseconds, that the mouse pointer has to stay in the hover rectangle before a mouse hover message is generated.
      /// @return The time, in milliseconds, that the mouse pointer has to stay in the hover rectangle before a mouse hover message is generated.
      /// @remarks The mouse_hover_time property indicates the time, in milliseconds, that a mouse pointer must remain within an area the size of the MouseHoverSize property in order to generate a mouse hover message.
      /// @remarks The mouse_hover_size property indicates the size of the rectangle within which the mouse pointer has to stay for the mouse hover time before a mouse hover message is generated.
      static int32_t mouse_hover_time();
      
      /// @brief Gets a value indicating whether the functions of the left and right mouse buttons have been swapped.
      /// @return true if a mouse is installed; otherwise, false.
      /// @remarks The mouse_present property indicates whether a pointing device is present or installed on the system. This is usually the case, so mouse_present almost always returns true.
      static bool mouse_present();
      
      /// @brief Gets the current mouse speed.
      /// @return A mouse speed value between 1 (slowest) and 20 (fastest).
      /// @remarks The mouse speed determines how far the pointer will move based on the distance the mouse moves. The value of this property ranges between 1 (slowest) and 20 (fastest). A value of 10 is the default. The value can be set by an end user using the mouse control panel application or by an application using the SystemParametersInfo function of the Platform SDK.
      static int32_t mouse_speed();
      
      /// @brief Gets a value indicating whether a mouse with a mouse wheel is installed.
      /// @return true if a mouse with a mouse wheel is installed; otherwise, false.
      /// @remarks The Mouse_wheel_present property indicates whether the system recognizes a mouse wheel on an installed mouse.
      /// @note This property is equivalent to native_mouse_wheel_support.
      static bool Mouse_wheel_present();
      
      /// @brief Gets the amount of the delta value of a single mouse wheel rotation increment.
      /// @return The amount of the delta value of a single mouse wheel rotation increment.
      /// @remarks The delta value is an integer value that represents a single mouse wheel rotation increment. A downward mouse wheel rotation produces a negative delta value.
      static int32_t mouse_wheel_scroll_delta();
      
      /// @brief Gets the number of lines to scroll when the mouse wheel is rotated.
      /// @return The number of lines to scroll on a mouse wheel rotation, or -1 if the "One screen at a time" mouse option is selected.
      /// @remarks The mouse_wheel_scroll_lines property indicates how many lines to scroll, by default, in a multi-line control that has a scroll bar. The corresponding Platform SDK system-wide parameters are SPI_GETWHEELSCROLLLINES and SPI_SETWHEELSCROLLLINES. For more information about system-wide parameters, see "SystemParametersInfo" in the Platform SDK documentation at https://msdn.microsoft.com.
      /// @note Be sure to handle the special case that occurs if the "One screen at a time" mouse option is selected. In this case, the mouse_wheel_scroll_lines property has a value of -1.
      static int32_t mouse_wheel_scroll_lines();
      
      /// @brief Gets a value indicating whether a mouse with a mouse wheel is installed.
      /// @return true if a mouse with a mouse wheel is installed; otherwise, false.
      /// @remarks The native_mouse_wheel_support property indicates whether the system recognizes a mouse wheel on an installed mouse.
      /// @note This property is equivalent to mouse_wheel_present.
      static bool native_mouse_wheel_support();
      
      /// @brief Gets a value indicating whether a network connection is present.
      /// @return true if a network connection is present; otherwise, false.
      /// @remarks The network property indicates whether the system has a currently established network connection.
      /// @note This property always returns true on all platforms.
      static bool network();
      
      static int32_t vertical_scroll_bar_width();

    };
  }
}
