/// @file
/// @brief Contains xtd::drawing::system_images_base factory.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "bitmap.hpp"
#include "size.hpp"
#include <xtd/static>
#include <xtd/target_id>
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class system_icons;
    /// @endcond
    
    /// @brief Represents the base for all system_images clases (xtd::drawing::system_images).
    /// ```cpp
    /// class drawing_export_ system_images_base final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::system_images_base
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ system_images_base static_ {
    protected:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;
      
      /// @brief Gets the image contexts.
      /// @return An wtd::string array that contains the image contexts.
      /// @remarks The system images are grouped by contaxt.
      /// @remarks The following table list the contexts :
      /// | Context       | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
      /// | ------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
      /// | Actions       | Icons which are generally used in menus and dialogs for interacting with the user.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
      /// | Animations    | Animated images used to represent loading web sites, or other background processing which may be less suited to more verbose progress reporting in the user interface. Animations should be a PNG with frames which are the size of the directory the animation is in, tiled in a WxH grid. Implementations should determine the number of frames by dividing the image into its frames, and iterating from left to right, wrapping to the first frame, after rendering the last.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
      /// | Applications  | Icons that describe what an application is, for use in the Programs menu, window decorations, and the task list. These may or may not be generic depending on the application and its purpose. Applications which are to be considered part of the base desktop, such as the calculator or terminal, should use the generic icons specified in this specification, while more advanced applications such as web browsers and office applications should use branded icons which still give the user an idea of what function the application provides.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
      /// | Categories    | Icons that are used for categories in the Programs menu, or the Control Center, for separating applications, preferences, and settings for display to the user.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
      /// | Devices       | Icons for hardware that is contained within or connected to the computing device. Naming for extended devices in this group, is of the form <primary function>-<manufacturer>-<model>. This allows ease of fallback to the primary function device name, or ones more targeted for a specific series of models from a manufacturer. For example, a theme author may want to provide icons for different phones. The specific model icons could be named "phone-samsung-t809", "phone-motorola-rokr", and "phone-motorola-pebl". However, the theme must provide a phone icon in the theme's style, so that devices not matching these models, will still have an appropriate icon. An exception to this rule is that the "media" icons do not need to include manufacturer names, as they are generic items, and may be available from many manufacturers. As a result, for media, the specific icons are to differentiate between different specific types of media. For exmaple, an artist may wish to provide icons for BluRay, DVD, HD-DVD, CD-ROM, and variations thereof. The specific media type icons should be named in the form, <primary function>-<specific format>. Some examples are "media-optical", "media-optical-bd" and "media-optical-dvd". |
      /// | Emblems       | Icons for tags and properties of files, that are displayed in the file manager. This context contains emblems for such things as "read-only" or "photos".                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
      /// | Emotes        | Icons for emotions that are expressed through text chat applications such as :-) or :-P in IRC or instant messengers.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
      /// | International | Icons for international denominations such as flags.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
      /// | MimeTypes     | Icons for different types of data, such as audio or image files.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
      /// | Places        | Icons used to represent locations, either on the local filesystem, or through remote connections. Folders, trash, and workgroups are some examples.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
      /// | Status        | Icons for presenting status to the user. This context contains icons for warning and error dialogs, as well as for the current weather, appointment alarms, and battery status.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
      /// | xtd           | Icons for representinf xtd libraries and products.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
      /// @remarks See (Icon Naming Specification)[https://specifications.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html) for more information.
      static xtd::array<xtd::string> contexts() noexcept;
      /// @brief Gets the image context names.
      /// @return An xtd::string, xtd::string hash table that contains the image context names.
      /// @remarks The system images are grouped by contaxt.
      /// @par The following table represents Standard Action Icons :
      /// | Name                      | Description                                                                                                                                                             |
      /// | ------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
      /// | address-book-new          | The icon used for the action to create a new address book.                                                                                                              |
      /// | application-exit          | The icon used for exiting an application. Typically this is seen in the application's menus as File->Quit.                                                              |
      /// | appointment-new           | The icon used for the action to create a new appointment in a calendaring application.                                                                                  |
      /// | call-start                | The icon used for initiating or accepting a call. Should be similar to the standard cellular call pickup icon, a green handset with ear and mouth pieces facing upward. |
      /// | call-stop                 | The icon used for stopping a current call. Should be similar to the standard cellular call hangup icon, a red handset with ear and mouth pieces facing downward.        |
      /// | contact-new               | The icon used for the action to create a new contact in an address book application.                                                                                    |
      /// | dialog-cancel             | The icon used for the action dialog cancel.                                                                                                                             |
      /// | dialog-ok                 | The icon used for the action dialog ok.                                                                                                                                 |
      /// | dialog-ok-apply           | The icon used for the action dialog apply.                                                                                                                              |
      /// | document-edit             | The icon used for the action to edit a document.                                                                                                                        |
      /// | document-new              | The icon used for the action to create a new document.                                                                                                                  |
      /// | document-open             | The icon used for the action to open a document.                                                                                                                        |
      /// | document-open-recent      | The icon used for the action to open a document that was recently opened.                                                                                               |
      /// | document-page-setup       | The icon for the page setup action of a document editor.                                                                                                                |
      /// | document-print            | The icon for the print action of an application.                                                                                                                        |
      /// | document-print-preview    | The icon for the print preview action of an application.                                                                                                                |
      /// | document-properties       | The icon for the action to view the properties of a document in an application.                                                                                         |
      /// | document-revert           | The icon for the action of reverting to a previous version of a document.                                                                                               |
      /// | document-save             | The icon for the save action. Should be an arrow pointing down and toward a hard disk.                                                                                  |
      /// | document-save-as          | The icon for the save as action.                                                                                                                                        |
      /// | document-send             | The icon for the send action. Should be an arrow pointing up and away from a hard disk.                                                                                 |
      /// | edit-clear                | The icon for the clear action.                                                                                                                                          |
      /// | edit-copy                 | The icon for the copy action.                                                                                                                                           |
      /// | edit-cut                  | The icon for the cut action.                                                                                                                                            |
      /// | edit-delete               | The icon for the delete action.                                                                                                                                         |
      /// | edit-find                 | The icon for the find action.                                                                                                                                           |
      /// | edit-find-replace         | The icon for the find and replace action.                                                                                                                               |
      /// | edit-paste                | The icon for the paste action.                                                                                                                                          |
      /// | edit-redo                 | The icon for the redo action.                                                                                                                                           |
      /// | edit-rename               | The icon for the rename action.                                                                                                                                         |
      /// | edit-select-all           | The icon for the select all action.                                                                                                                                     |
      /// | edit-undo                 | The icon for the undo action.                                                                                                                                           |
      /// | folder-new                | The icon for creating a new folder.                                                                                                                                     |
      /// | format-indent-less        | The icon for the decrease indent formatting action.                                                                                                                     |
      /// | format-indent-more        | The icon for the increase indent formatting action.                                                                                                                     |
      /// | format-justify-center     | The icon for the center justification formatting action.                                                                                                                |
      /// | format-justify-fill       | The icon for the fill justification formatting action.                                                                                                                  |
      /// | format-justify-left       | The icon for the left justification formatting action.                                                                                                                  |
      /// | format-justify-right      | The icon for the right justification action.                                                                                                                            |
      /// | format-text-direction-ltr | The icon for the left-to-right text formatting action.                                                                                                                  |
      /// | format-text-direction-rtl | The icon for the right-to-left formatting action.                                                                                                                       |
      /// | format-text-bold          | The icon for the bold text formatting action.                                                                                                                           |
      /// | format-text-italic        | The icon for the italic text formatting action.                                                                                                                         |
      /// | format-text-underline     | The icon for the underlined text formatting action.                                                                                                                     |
      /// | format-text-strikethrough | The icon for the strikethrough text formatting action.                                                                                                                  |
      /// | go-bottom                 | The icon for the go to bottom of a list action.                                                                                                                         |
      /// | go-down                   | The icon for the go down in a list action.                                                                                                                              |
      /// | go-first                  | The icon for the go to the first item in a list action.                                                                                                                 |
      /// | go-home                   | The icon for the go to home location action.                                                                                                                            |
      /// | go-jump                   | The icon for the jump to action.                                                                                                                                        |
      /// | go-last                   | The icon for the go to the last item in a list action.                                                                                                                  |
      /// | go-next                   | The icon for the go to the next item in a list action.                                                                                                                  |
      /// | go-previous               | The icon for the go to the previous item in a list action.                                                                                                              |
      /// | go-top                    | The icon for the go to the top of a list action.                                                                                                                        |
      /// | go-up                     | The icon for the go up in a list action.                                                                                                                                |
      /// | help-about                | The icon for the About item in the Help menu.                                                                                                                           |
      /// | help-contents             | The icon for Contents item in the Help menu.                                                                                                                            |
      /// | help-faq                  | The icon for the FAQ item in the Help menu.                                                                                                                             |
      /// | insert-image              | The icon for the insert image action of an application.                                                                                                                 |
      /// | insert-link               | The icon for the insert link action of an application.                                                                                                                  |
      /// | insert-object             | The icon for the insert object action of an application.                                                                                                                |
      /// | insert-table              | The icon for the insert table action of an application.                                                                                                                 |
      /// | insert-text               | The icon for the insert text action of an application.                                                                                                                  |
      /// | list-add                  | The icon for the add to list action.                                                                                                                                    |
      /// | list-remove               | The icon for the remove from list action.                                                                                                                               |
      /// | mail-forward              | The icon for the forward action of an electronic mail application.                                                                                                      |
      /// | mail-mark-important       | The icon for the mark as important action of an electronic mail application.                                                                                            |
      /// | mail-mark-junk            | The icon for the mark as junk action of an electronic mail application.                                                                                                 |
      /// | mail-mark-notjunk         | The icon for the mark as not junk action of an electronic mail application.                                                                                             |
      /// | mail-mark-read            | The icon for the mark as read action of an electronic mail application.                                                                                                 |
      /// | mail-mark-unread          | The icon for the mark as unread action of an electronic mail application.                                                                                               |
      /// | mail-message-new          | The icon for the compose new mail action of an electronic mail application.                                                                                             |
      /// | mail-reply-all            | The icon for the reply to all action of an electronic mail application.                                                                                                 |
      /// | mail-reply-sender         | The icon for the reply to sender action of an electronic mail application.                                                                                              |
      /// | mail-send                 | The icon for the send action of an electronic mail application.                                                                                                         |
      /// | mail-send-receive         | The icon for the send and receive action of an electronic mail application.                                                                                             |
      /// | media-eject               | The icon for the eject action of a media player or file manager.                                                                                                        |
      /// | media-optical-burn        | The icon for the media optical burn action of a media player or file manager.                                                                                           |
      /// | media-playback-pause      | The icon for the pause action of a media player.                                                                                                                        |
      /// | media-playback-start      | The icon for the start playback action of a media player.                                                                                                               |
      /// | media-playback-stop       | The icon for the stop action of a media player.                                                                                                                         |
      /// | media-record              | The icon for the record action of a media application.                                                                                                                  |
      /// | media-seek-backward       | The icon for the seek backward action of a media player.                                                                                                                |
      /// | media-seek-forward        | The icon for the seek forward action of a media player.                                                                                                                 |
      /// | media-skip-backward       | The icon for the skip backward action of a media player.                                                                                                                |
      /// | media-skip-forward        | The icon for the skip forward action of a media player.                                                                                                                 |
      /// | object-flip-horizontal    | The icon for the action to flip an object horizontally.                                                                                                                 |
      /// | object-flip-vertical      | The icon for the action to flip an object vertically.                                                                                                                   |
      /// | object-rotate-left        | The icon for the rotate left action performed on an object.                                                                                                             |
      /// | object-rotate-right       | The icon for the rotate rigt action performed on an object.                                                                                                             |
      /// | process-stop              | The icon used for the "Stop" action in applications with actions that may take a while to process, such as web page loading in a browser.                               |
      /// | system-lock-screen        | The icon used for the "Lock Screen" item in the desktop's panel application.                                                                                            |
      /// | system-log-out            | The icon used for the "Log Out" item in the desktop's panel application.                                                                                                |
      /// | system-run                | The icon used for the "Run Application..." item in the desktop's panel application.                                                                                     |
      /// | system-search             | The icon used for the "Search" item in the desktop's panel application.                                                                                                 |
      /// | system-reboot             | The icon used for the "Reboot" item in the desktop's panel application.                                                                                                 |
      /// | system-shutdown           | The icon used for the "Shutdown" item in the desktop's panel application.                                                                                               |
      /// | tools-check-spelling      | The icon used for the "Check Spelling" item in the application's "Tools" menu.                                                                                          |
      /// | view-fullscreen           | The icon used for the "Fullscreen" item in the application's "View" menu.                                                                                               |
      /// | view-media-equalizer      | The icon used for the view media aqualizer action.                                                                                                                      |
      /// | view-media-lyrics         | The icon used for the view media lyrics action.                                                                                                                         |
      /// | view-refresh              | The icon used for the "Refresh" item in the application's "View" menu.                                                                                                  |
      /// | view-restore              | The icon used by an application for leaving the fullscreen view, and returning to a normal windowed view.                                                               |
      /// | view-sort-ascending       | The icon used for the "Sort Ascending" item in the application's "View" menu, or in a button for changing the sort method for a list.                                   |
      /// | view-sort-descending      | The icon used for the "Sort Descending" item in the application's "View" menu, or in a button for changing the sort method for a list.                                  |
      /// | window-close              | The icon used for the window close button.                                                                                                                              |
      /// | window-close-hovered      | The icon used for the hovered window close button.                                                                                                                      |
      /// | window-fullscreen         | The icon used for the window fullscreen button.                                                                                                                         |
      /// | window-fullscreen-hovered | The icon used for the hovered window fullscreen button.                                                                                                                 |
      /// | window-maximize           | The icon used for the window maximize button.                                                                                                                           |
      /// | window-maximize-hovered   | The icon used for the hovered window maximize button.                                                                                                                   |
      /// | window-minimize           | The icon used for the window minimize button.                                                                                                                           |
      /// | window-minimize-hovered   | The icon used for the hovered window minimize button.                                                                                                                   |
      /// | window-new                | The icon used for the "New Window" item in the application's "Windows" menu.                                                                                            |
      /// | window-restore            | The icon used for the window restore button.                                                                                                                            |
      /// | window-restore-hovered    | The icon used for the hovered window restore button.                                                                                                                    |
      /// | zoom-fit-best             | The icon used for the "Best Fit" item in the application's "View" menu.                                                                                                 |
      /// | zoom-in                   | The icon used for the "Zoom in" item in the application's "View" menu.                                                                                                  |
      /// | zoom-original             | The icon used for the "Original Size" item in the application's "View" menu.                                                                                            |
      /// | zoom-out                  | The icon used for the "Zoom Out" item in the application's "View" menu.                                                                                                 |
      /// @par The following table represents Standard Animation Icons :
      /// | Name               | Description                                                                                                     |
      /// | ------------------ | --------------------------------------------------------------------------------------------------------------- |
      /// | process-working    | This is the standard spinner animation for web browsers and file managers to show that the location is loading. |
      /// @par The following table represents Standard Application Icons :
      /// | Name                              | Description                                                                                  |
      /// | --------------------------------- | -------------------------------------------------------------------------------------------- |
      /// | accessories-calculator            | The icon used for the desktop's calculator accessory program.                                |
      /// | accessories-character-map         | The icon used for the desktop's international and extended text character accessory program. |
      /// | accessories-dictionary            | The icon used for the desktop's dictionary accessory program.                                |
      /// | accessories-text-editor           | The icon used for the desktop's text editing accessory program.                              |
      /// | help-browser                      | The icon used for the desktop's help browsing application.                                   |
      /// | help                              | The icon used for the desktop's help application.                                            |
      /// | multimedia-volume-control         | The icon used for the desktop's hardware volume control application.                         |
      /// | preferences-desktop-accessibility | The icon used for the desktop's accessibility preferences.                                   |
      /// | preferences-desktop-font          | The icon used for the desktop's font preferences.                                            |
      /// | preferences-desktop-keyboard      | The icon used for the desktop's keyboard preferences.                                        |
      /// | preferences-desktop-locale.       | The icon used for the desktop's locale preferences.                                          |
      /// | preferences-desktop-screensaver   | The icon used for the desktop's screen saving preferences.                                   |
      /// | preferences-desktop-theme         | The icon used for the desktop's theme preferences.                                           |
      /// | preferences-desktop-wallpaper     | The icon used for the desktop's wallpaper preferences.                                       |
      /// | system-file-manager               | The icon used for the desktop's file management application.                                 |
      /// | system-software-install           | The icon used for the desktop's software installer application.                              |
      /// | system-software-update            | The icon used for the desktop's software updating application.                               |
      /// | utilities-system-monitor          | The icon used for the desktop's system resource monitor application.                         |
      /// | utilities-terminal                | The icon used for the desktop's terminal emulation application.                              |
      /// @par The following table represents Standard Category Icons :
      /// | Name                            | Description                                                                        |
      /// | ------------------------------- | ---------------------------------------------------------------------------------- |
      /// | applications-accessories        | The icon for the "Accessories" sub-menu of the Programs menu.                      |
      /// | applications-development        | The icon for the "Programming" sub-menu of the Programs menu.                      |
      /// | applications-engineering        | The icon for the "Engineering" sub-menu of the Programs menu.                      |
      /// | applications-games              | The icon for the "Games" sub-menu of the Programs menu.                            |
      /// | applications-graphics           | The icon for the "Graphics" sub-menu of the Programs menu.                         |
      /// | applications-internet           | The icon for the "Internet" sub-menu of the Programs menu.                         |
      /// | applications-multimedia         | The icon for the "Multimedia" sub-menu of the Programs menu.                       |
      /// | applications-office             | The icon for the "Office" sub-menu of the Programs menu.                           |
      /// | applications-other              | The icon for the "Other" sub-menu of the Programs menu.                            |
      /// | applications-science            | The icon for the "Science" sub-menu of the Programs menu.                          |
      /// | applications-system             | The icon for the "System Tools" sub-menu of the Programs menu.                     |
      /// | applications-utilities          | The icon for the "Utilities" sub-menu of the Programs menu.                        |
      /// | preferences-desktop             | The icon for the "Desktop Preferences" category.                                   |
      /// | preferences-desktop-peripherals | The icon for the "Peripherals" sub-category of the "Desktop Preferences" category. |
      /// | preferences-desktop-personal    | The icon for the "Personal" sub-category of the "Desktop Preferences" category.    |
      /// | preferences-other               | The icon for the "Other" preferences category.                                     |
      /// | preferences-system              | The icon for the "System Preferences" category.                                    |
      /// | preferences-system-network      | The icon for the "Network" sub-category of the "System Preferences" category.      |
      /// | system-help                     | The icon for the "Help" system category.                                           |
      /// @par The following table represents Standard Device Icons :
      /// | Name                                | Description                                                                                                                                                                                                                                                                 |
      /// | ----------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
      /// | audio-card                          | The icon used for the audio rendering device.                                                                                                                                                                                                                               |
      /// | audio-input-microphone              | The icon used for the microphone audio input device.                                                                                                                                                                                                                        |
      /// | battery                             | The icon used for the system battery device.                                                                                                                                                                                                                                |
      /// | camera-photo                        | The icon used for a digital still camera devices.                                                                                                                                                                                                                           |
      /// | camera-video                        | The fallback icon for video cameras.                                                                                                                                                                                                                                        |
      /// | camera-web                          | The fallback icon for web cameras.                                                                                                                                                                                                                                          |
      /// | computer                            | The icon used for the computing device as a whole.                                                                                                                                                                                                                          |
      /// | drive-harddisk                      | The icon used for hard disk drives.                                                                                                                                                                                                                                         |
      /// | drive-optical                       | The icon used for optical media drives such as CD and DVD.                                                                                                                                                                                                                  |
      /// | drive-removable-media-usb-pen-drive | The icon used for removable media usb pen drives.                                                                                                                                                                                                                           |
      /// | drive-removable-media               | The icon used for removable media drives.                                                                                                                                                                                                                                   |
      /// | input-gaming                        | The icon used for the gaming input device.                                                                                                                                                                                                                                  |
      /// | input-keyboard                      | The icon used for the keyboard input device.                                                                                                                                                                                                                                |
      /// | input-mouse                         | The icon used for the mousing input device.                                                                                                                                                                                                                                 |
      /// | input-tablet                        | The icon used for graphics tablet input devices.                                                                                                                                                                                                                            |
      /// | media-flash                         | The fallback icon used for flash media, such as memory stick and SD.                                                                                                                                                                                                        |
      /// | media-floppy                        | The icon used for physical floppy disk media.                                                                                                                                                                                                                               |
      /// | media-optical-audio                 | The icon used for physical audio optical media.                                                                                                                                                                                                                             |
      /// | media-optical-blu-ray               | The icon used for physical blu ray media.                                                                                                                                                                                                                                   |
      /// | media-optical-data                  | The icon used for physical data optical media.                                                                                                                                                                                                                              |
      /// | media-optical-dvd-video             | The icon used for physical video DVD media.                                                                                                                                                                                                                                 |
      /// | media-optical-dvd                   | The icon used for physical DVD media.                                                                                                                                                                                                                                       |
      /// | media-optical-mixed-cd              | The icon used for physical mixed CD media.                                                                                                                                                                                                                                  |
      /// | media-optical-recordeable           | The icon used for physical recordable optical media.                                                                                                                                                                                                                        |
      /// | media-optical-video                 | The icon used for physical video optical media.                                                                                                                                                                                                                             |
      /// | media-optical                       | The icon used for physical optical media such as CD and DVD.                                                                                                                                                                                                                |
      /// | media-tape                          | The icon used for generic physical tape media.                                                                                                                                                                                                                              |
      /// | modem                               | The icon used for modem devices.                                                                                                                                                                                                                                            |
      /// | multimedia-player                   | The icon used for generic multimedia playing devices.                                                                                                                                                                                                                       |
      /// | network-wired                       | The icon used for wired network connections.                                                                                                                                                                                                                                |
      /// | network-wireless                    | The icon used for wireless network connections.                                                                                                                                                                                                                             |
      /// | pda                                 | This is the fallback icon for Personal Digial Assistant devices. Primary use of this icon is for PDA devices connected to the PC. Connection medium is not an important aspect of the icon. The metaphor for this fallback icon should be a generic PDA device icon.        |
      /// | phone                               | This is the default fallback for phone devices. Primary use of this icon group is for phone devices which support connectivity to the PC. These may be VoIP, cellular, or possibly landline phones. The metaphor for this fallback should be a generic mobile phone device. |
      /// | printer                             | The icon used for a printer device.                                                                                                                                                                                                                                         |
      /// | scanner                             | The icon used for a scanner device.                                                                                                                                                                                                                                         |
      /// | video-display                       | The icon used for the monitor that video gets displayed to.                                                                                                                                                                                                                 |
      /// @par The following table represents Standard Emblem Icons :
      /// | Name                 | Description                                                                                                          |
      /// | -------------------- | -------------------------------------------------------------------------------------------------------------------- |
      /// | emblem-default       | The icon used as an emblem to specify the default selection of a printer for example.                                |
      /// | emblem-documents     | The icon used as an emblem for the directory where a user's documents are stored.                                    |
      /// | emblem-downloads     | The icon used as an emblem for the directory where a user's downloads from the internet are stored.                  |
      /// | emblem-favorite      | The icon used as an emblem for files and directories that the user marks as favorites.                               |
      /// | emblem-important     | The icon used as an emblem for files and directories that are marked as important by the user.                       |
      /// | emblem-locked        | The icon used as an emblem for files and directories that the user marks as locked.                                  |
      /// | emblem-mail          | The icon used as an emblem to specify the directory where the user's electronic mail is stored.                      |
      /// | emblem-new           | The icon used as an emblem for files and directories that the user marks as new.                                     |
      /// | emblem-photos        | The icon used as an emblem to specify the directory where the user stores photographs.                               |
      /// | emblem-readonly      | The icon used as an emblem for files and directories which can not be written to by the user.                        |
      /// | emblem-shared        | The icon used as an emblem for files and directories that are shared to other users.                                 |
      /// | emblem-symbolic-link | The icon used as an emblem for files and direcotires that are links to other files or directories on the filesystem. |
      /// | emblem-synchronized  | The icon used as an emblem for files or directories that are configured to be synchronized to another device.        |
      /// | emblem-system        | The icon used as an emblem for directories that contain system libraries, settings, and data.                        |
      /// | emblem-unlocked      | The icon used as an emblem for files and directories that the user marks as unlocked.                                |
      /// | emblem-unreadable    | The icon used as an emblem for files and directories that are inaccessible.                                          |
      /// @par The following table represents Standard Emoticon Icons :
      /// | Name             | Description                         |
      /// | ---------------- | ----------------------------------- |
      /// | face-angel       | The icon used for the 0:-) emote.   |
      /// | face-angry       | The icon used for the X-( emote.    |
      /// | face-cool        | The icon used for the B-) emote.    |
      /// | face-crying      | The icon used for the :'( emote.    |
      /// | face-devilish    | The icon used for the >:-) emote.   |
      /// | face-embarrassed | The icon used for the :-[ emote.    |
      /// | face-kiss        | The icon used for the :-* emote.    |
      /// | face-laugh       | The icon used for the :-)) emote.   |
      /// | face-monkey      | The icon used for the :-(\|) emote. |
      /// | face-plain       | The icon used for the :-\| emote.   |
      /// | face-raspberry   | The icon used for the :-P emote.    |
      /// | face-sad         | The icon used for the :-( emote.    |
      /// | face-sick        | The icon used for the :-& emote.    |
      /// | face-smile       | The icon used for the :-) emote.    |
      /// | face-smile-big   | The icon used for the :-D emote.    |
      /// | face-smirk       | The icon used for the :-! emote.    |
      /// | face-surprise    | The icon used for the :-0 emote.    |
      /// | face-tired       | The icon used for the \| ) emote.   |
      /// | face-uncertain   | The icon used for the :-/ emote.    |
      /// | face-wink        | The icon used for the ;-) emote.    |
      /// | face-worried     | The icon used for the :-S emote.    |
      /// @par The following table represents Standard MIME Type Icons :
      /// | Name    | Description                                                                                                                                                              |
      /// | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
      /// | flag-aa | The flag for the country with the ISO 3166 country code AA. All flags should use ISO 3166 two-letter country codes, in lowercase form, as the specifier for the country. |
      /// @par The following table represents Standard International Icons :
      /// | Name                     | Description                                                 |
      /// | ------------------------ | ----------------------------------------------------------- |
      /// | application-x-executable | The icon used for executable file types.                    |
      /// | audio-x-generic          | The icon used for generic audio file types.                 |
      /// | font-x-generic           | The icon used for generic font file types.                  |
      /// | image-x-generic          | The icon used for generic image file types.                 |
      /// | package-x-generic        | The icon used for generic package file types.               |
      /// | text-html                | The icon used for HTML text file types.                     |
      /// | text-x-generic           | The icon used for generic text file types.                  |
      /// | text-x-generic-template  | The icon used for generic text templates.                   |
      /// | text-x-script            | The icon used for script file types, such as shell scripts. |
      /// | video-x-generic          | The icon used for generic video file types.                 |
      /// | x-office-address-book    | The icon used for generic address book file types.          |
      /// | x-office-calendar        | The icon used for generic calendar file types.              |
      /// | x-office-contact         | The icon used for generic contact file types.               |
      /// | x-office-document        | The icon used for generic document and letter file types.   |
      /// | x-office-presentation    | The icon used for generic presentation file types.          |
      /// | x-office-spreadsheet     | The icon used for generic spreadsheet file types.           |
      /// @par The following table represents Standard Place Icons :
      /// | Name                | Description                                                                                                               |
      /// | ------------------- | ------------------------------------------------------------------------------------------------------------------------- |
      /// | folder              | The standard folder icon used to represent directories on local filesystems, mail folders, and other hierarchical groups. |
      /// | folder-activities   | The icon used for activities directory.                                                                                   |
      /// | folder-applications | The icon used for applications directory.                                                                                 |
      /// | folder-bookmark     | The icon used for bookmark directory.                                                                                     |
      /// | folder-cloud        | The icon used for cloud directory.                                                                                        |
      /// | folder-desktop      | The icon used for desktop directory.                                                                                      |
      /// | folder-development  | The icon used for develoment directory.                                                                                   |
      /// | folder-documents    | The icon used for documents directory.                                                                                    |
      /// | folder-download     | The icon used for download directory.                                                                                     |
      /// | folder-favoties     | The icon used for favorites directory.                                                                                    |
      /// | folder-games        | The icon used for games directory.                                                                                        |
      /// | folder-github       | The icon used for github directory.                                                                                       |
      /// | folder-home         | The icon used for home directory.                                                                                         |
      /// | folder-html         | The icon used for html directory.                                                                                         |
      /// | folder-images       | The icon used for images directory.                                                                                       |
      /// | folder-important    | The icon used for important directory.                                                                                    |
      /// | folder-locked       | The icon used for locked directory.                                                                                       |
      /// | folder-music        | The icon used for music directory.                                                                                        |
      /// | folder-network      | The icon used for network directory.                                                                                      |
      /// | folder-print        | The icon used for print directory.                                                                                        |
      /// | folder-public       | The icon used for public directory.                                                                                       |
      /// | folder-remote       | The icon used for normal directories on a remote filesystem.                                                              |
      /// | folder-system       | The icon used for system directory.                                                                                       |
      /// | folder-tar          | The icon used for tar directory.                                                                                          |
      /// | folder-temp         | The icon used for temp directory.                                                                                         |
      /// | folder-templates    | The icon used for templates directory.                                                                                    |
      /// | folder-text         | The icon used for text directory.                                                                                         |
      /// | folder-videos       | The icon used for videos directory.                                                                                       |
      /// | network-server      | The icon used for individual host machines under the "Network Servers" place in the file manager.                         |
      /// | network-workgroup   | The icon for the "Network Servers" place in the desktop's file manager, and workgroups within the network.                |
      /// | start-here          | The icon used by the desktop's main menu for accessing places, applications, and other features.                          |
      /// | user-bookmarks      | The icon for the user's special "Bookmarks" place.                                                                        |
      /// | user-desktop        | The icon for the special "Desktop" directory of the user.                                                                 |
      /// | user-home           | The icon for the special "Home" directory of the user.                                                                    |
      /// | user-trash          | The icon for the user's "Trash" place in the desktop's file manager.                                                      |
      /// @par The following table represents Standard Status Icons :
      /// | Name                      | Description                                                                                                                                                                                                                                                                                      |
      /// | ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
      /// | appointment-missed        | The icon used when an appointment was missed.                                                                                                                                                                                                                                                    |
      /// | appointment-soon          | The icon used when an appointment will occur soon.                                                                                                                                                                                                                                               |
      /// | audio-volume-high         | The icon used to indicate high audio volume.                                                                                                                                                                                                                                                     |
      /// | audio-volume-low          | The icon used to indicate low audio volume.                                                                                                                                                                                                                                                      |
      /// | audio-volume-medium       | The icon used to indicate medium audio volume.                                                                                                                                                                                                                                                   |
      /// | audio-volume-muted        | The icon used to indicate the muted state for audio playback.                                                                                                                                                                                                                                    |
      /// | battery-caution           | The icon used when the battery is below 40%.                                                                                                                                                                                                                                                     |
      /// | battery-low               | The icon used when the battery is below 20%.                                                                                                                                                                                                                                                     |
      /// | dialog-error              | The icon used when a dialog is opened to explain an error condition to the user.                                                                                                                                                                                                                 |
      /// | dialog-information        | The icon used when a dialog is opened to give information to the user that may be pertinent to the requested action.                                                                                                                                                                             |
      /// | dialog-password           | The icon used when a dialog requesting the authentication credentials for a user is opened.                                                                                                                                                                                                      |
      /// | dialog-question           | The icon used when a dialog is opened to ask a simple question of the user.                                                                                                                                                                                                                      |
      /// | dialog-warning            | The icon used when a dialog is opened to warn the user of impending issues with the requested action.                                                                                                                                                                                            |
      /// | folder-drag-accept        | The icon used for a folder while an object is being dragged onto it, that is of a type that the directory can contain.                                                                                                                                                                           |
      /// | folder-open               | The icon used for folders, while their contents are being displayed within the same window. This icon would normally be shown in a tree or list view, next to the main view of a folder's contents.                                                                                              |
      /// | folder-visiting           | The icon used for folders, while their contents are being displayed in another window. This icon would typically be used when using multiple windows to navigate the hierarchy, such as in Nautilus's spatial mode.                                                                              |
      /// | image-loading             | The icon used when another image is being loaded, such as thumnails for larger images in the file manager.                                                                                                                                                                                       |
      /// | image-missing             | The icon used when another image could not be loaded.                                                                                                                                                                                                                                            |
      /// | mail-attachment           | The icon used for an electronic mail that contains attachments.                                                                                                                                                                                                                                  |
      /// | mail-unread               | The icon used for an electronic mail that is unread.                                                                                                                                                                                                                                             |
      /// | mail-read                 | The icon used for an electronic mail that is read.                                                                                                                                                                                                                                               |
      /// | mail-replied              | The icon used for an electronic mail that has been replied to.                                                                                                                                                                                                                                   |
      /// | mail-signed               | The icon used for an electronic mail that contains a signature.                                                                                                                                                                                                                                  |
      /// | mail-signed-verified      | The icon used for an electronic mail that contains a signature which has also been verified by the security system.                                                                                                                                                                              |
      /// | media-playlist-repeat     | The icon for the repeat mode of a media player.                                                                                                                                                                                                                                                  |
      /// | media-playlist-shuffle    | The icon for the shuffle mode of a media player.                                                                                                                                                                                                                                                 |
      /// | network-error             | The icon used when an error occurs trying to intialize the network connection of the computing device. This icon should be two computers, one in the background, with the screens of both computers, colored black, and with the theme's style element for errors, overlayed on top of the icon. |
      /// | network-idle              | The icon used when no data is being transmitted or received, while the computing device is connected to a network. This icon should be two computers, one in the background, with the screens of both computers, colored black.                                                                  |
      /// | network-offline           | The icon used when the computing device is disconnected from the network. This icon should be a computer in the background, with a screen colored black, and the theme's icon element to show that a device is not accessible, in the foreground.                                                |
      /// | network-receive           | The icon used when data is being received, while the computing device is connected to a network. This icon should be two computers, one in the background, with its screen colored green, and the screen of the computer in the foreground, colored black.                                       |
      /// | network-transmit          | The icon used when data is being transmitted, while the computing device is connected to a network. This icon should be two computers, one in the background, with its screen colored black, and the screen of the computer in the foreground, colored green.                                    |
      /// | network-transmit-receive  | The icon used data is being both transmitted and received simultaneously, while the computing device is connected to a network. This icon should be two computers, one in the background, with the screens of both computers, colored green.                                                     |
      /// | printer-error             | The icon used when an error occurs while attempting to print. This icon should be the theme's printer device icon, with the theme's style element for errors, overlayed on top of the icon.                                                                                                      |
      /// | printer-printing          | The icon used while a print job is successfully being spooled to a printing device. This icon should be the theme's printer device icon, with a document emerging from the printing device.                                                                                                      |
      /// | security-high             | The icon used to indicate that the security level of a connection is known to be secure, using strong encryption and a valid certificate.                                                                                                                                                        |
      /// | security-medium           | The icon used to indicate that the security level of a connection is presumed to be secure, using strong encryption, and a certificate that could not be automatically verified, but which the user has chosen to trust.                                                                         |
      /// | security-low              | The icon used to indicate that the security level of a connection is presumed to be insecure, either by using weak encryption, or by using a certificate that the could not be automatically verified, and which the user has not chosent to trust.                                              |
      /// | software-update-available | The icon used when an update is available for software installed on the computing device, through the system software update program.                                                                                                                                                            |
      /// | software-update-urgent    | The icon used when an urgent update is available through the system software update program.                                                                                                                                                                                                     |
      /// | task-due                  | The icon used when a task is due soon.                                                                                                                                                                                                                                                           |
      /// | task-past-due             | The icon used when a task that was due, has been left incomplete.                                                                                                                                                                                                                                |
      /// | user-available            | The icon used when a user on a chat network is available to initiate a conversation with.                                                                                                                                                                                                        |
      /// | user-away                 | The icon used when a user on a chat network is away from their keyboard and the chat program.                                                                                                                                                                                                    |
      /// | user-idle                 | The icon used when a user on a chat network has not been an active participant in any chats on the network, for an extended period of time.                                                                                                                                                      |
      /// | user-offline              | The icon used when a user on a chat network is not available.                                                                                                                                                                                                                                    |
      /// | user-trash-full           | The icon for the user's "Trash" in the desktop's file manager, when there are items in the "Trash" waiting for disposal or recovery.                                                                                                                                                             |
      /// | weather-clear             | The icon used while the weather for a region is "clear skies".                                                                                                                                                                                                                                   |
      /// | weather-clear-night       | The icon used while the weather for a region is "clear skies" during the night.                                                                                                                                                                                                                  |
      /// | weather-few-clouds        | The icon used while the weather for a region is "partly cloudy".                                                                                                                                                                                                                                 |
      /// | weather-few-clouds-night  | The icon used while the weather for a region is "partly cloudy" during the night.                                                                                                                                                                                                                |
      /// | weather-fog               | The icon used while the weather for a region is "foggy".                                                                                                                                                                                                                                         |
      /// | weather-overcast          | The icon used while the weather for a region is "overcast".                                                                                                                                                                                                                                      |
      /// | weather-severe-alert      | The icon used while a sever weather alert is in effect for a region.                                                                                                                                                                                                                             |
      /// | weather-showers           | The icon used while rain showers are occurring in a region.                                                                                                                                                                                                                                      |
      /// | weather-showers-scattered | The icon used while scattered rain showers are occurring in a region.                                                                                                                                                                                                                            |
      /// | weather-snow              | The icon used while snow showers are occurring in a region.                                                                                                                                                                                                                                      |
      /// | weather-storm             | The icon used while storms are occurring in a region.                                                                                                                                                                                                                                            |
      /// @par The following table represents Standard xtd Icons :
      /// | Name                      | Description                        |
      /// | ------------------------- | ---------------------------------- |
      /// | gammasoft                 | The icon for Gammasoft logo.       |
      /// | xtd                       | The icon for xtd logo.             |
      /// | xtd-console               | The icon for xtd console logo.     |
      /// | xtd-forms                 | The icon for xtd forms logo.       |
      /// | xtd-console               | The icon for xtd console logo.     |
      /// | xtd-tunit                 | The icon for xtd tunit logo.       |
      /// | xtd-core                  | The icon for xtd core logo.        |
      /// | xtd-delegates             | The icon for xtd delegates logo.   |
      /// | xtd-diagnostics           | The icon for xtd diagnostics logo. |
      /// | xtd-drawing               | The icon for xtd drawing logo.     |
      /// | xtd-io                    | The icon for xtd io logo.          |
      /// | xtd-strings               | The icon for xtd strings logo.     |
      /// @remarks See [Icon Naming Specification](https://specifications.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html) for more information.
      static std::map<xtd::string, xtd::array<xtd::string>> context_names() noexcept;
      /// @brief Gets the image names.
      /// @return An xtd::string array that contains the image names.
      /// @par The following table represents Standard Action Icons :
      /// | Name                      | Description                                                                                                                                                             |
      /// | ------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
      /// | address-book-new          | The icon used for the action to create a new address book.                                                                                                              |
      /// | application-exit          | The icon used for exiting an application. Typically this is seen in the application's menus as File->Quit.                                                              |
      /// | appointment-new           | The icon used for the action to create a new appointment in a calendaring application.                                                                                  |
      /// | call-start                | The icon used for initiating or accepting a call. Should be similar to the standard cellular call pickup icon, a green handset with ear and mouth pieces facing upward. |
      /// | call-stop                 | The icon used for stopping a current call. Should be similar to the standard cellular call hangup icon, a red handset with ear and mouth pieces facing downward.        |
      /// | contact-new               | The icon used for the action to create a new contact in an address book application.                                                                                    |
      /// | dialog-cancel             | The icon used for the action dialog cancel.                                                                                                                             |
      /// | dialog-ok                 | The icon used for the action dialog ok.                                                                                                                                 |
      /// | dialog-ok-apply           | The icon used for the action dialog apply.                                                                                                                              |
      /// | document-edit             | The icon used for the action to edit a document.                                                                                                                        |
      /// | document-new              | The icon used for the action to create a new document.                                                                                                                  |
      /// | document-open             | The icon used for the action to open a document.                                                                                                                        |
      /// | document-open-recent      | The icon used for the action to open a document that was recently opened.                                                                                               |
      /// | document-page-setup       | The icon for the page setup action of a document editor.                                                                                                                |
      /// | document-print            | The icon for the print action of an application.                                                                                                                        |
      /// | document-print-preview    | The icon for the print preview action of an application.                                                                                                                |
      /// | document-properties       | The icon for the action to view the properties of a document in an application.                                                                                         |
      /// | document-revert           | The icon for the action of reverting to a previous version of a document.                                                                                               |
      /// | document-save             | The icon for the save action. Should be an arrow pointing down and toward a hard disk.                                                                                  |
      /// | document-save-as          | The icon for the save as action.                                                                                                                                        |
      /// | document-send             | The icon for the send action. Should be an arrow pointing up and away from a hard disk.                                                                                 |
      /// | edit-clear                | The icon for the clear action.                                                                                                                                          |
      /// | edit-copy                 | The icon for the copy action.                                                                                                                                           |
      /// | edit-cut                  | The icon for the cut action.                                                                                                                                            |
      /// | edit-delete               | The icon for the delete action.                                                                                                                                         |
      /// | edit-find                 | The icon for the find action.                                                                                                                                           |
      /// | edit-find-replace         | The icon for the find and replace action.                                                                                                                               |
      /// | edit-paste                | The icon for the paste action.                                                                                                                                          |
      /// | edit-redo                 | The icon for the redo action.                                                                                                                                           |
      /// | edit-rename               | The icon for the rename action.                                                                                                                                         |
      /// | edit-select-all           | The icon for the select all action.                                                                                                                                     |
      /// | edit-undo                 | The icon for the undo action.                                                                                                                                           |
      /// | folder-new                | The icon for creating a new folder.                                                                                                                                     |
      /// | format-indent-less        | The icon for the decrease indent formatting action.                                                                                                                     |
      /// | format-indent-more        | The icon for the increase indent formatting action.                                                                                                                     |
      /// | format-justify-center     | The icon for the center justification formatting action.                                                                                                                |
      /// | format-justify-fill       | The icon for the fill justification formatting action.                                                                                                                  |
      /// | format-justify-left       | The icon for the left justification formatting action.                                                                                                                  |
      /// | format-justify-right      | The icon for the right justification action.                                                                                                                            |
      /// | format-text-direction-ltr | The icon for the left-to-right text formatting action.                                                                                                                  |
      /// | format-text-direction-rtl | The icon for the right-to-left formatting action.                                                                                                                       |
      /// | format-text-bold          | The icon for the bold text formatting action.                                                                                                                           |
      /// | format-text-italic        | The icon for the italic text formatting action.                                                                                                                         |
      /// | format-text-underline     | The icon for the underlined text formatting action.                                                                                                                     |
      /// | format-text-strikethrough | The icon for the strikethrough text formatting action.                                                                                                                  |
      /// | go-bottom                 | The icon for the go to bottom of a list action.                                                                                                                         |
      /// | go-down                   | The icon for the go down in a list action.                                                                                                                              |
      /// | go-first                  | The icon for the go to the first item in a list action.                                                                                                                 |
      /// | go-home                   | The icon for the go to home location action.                                                                                                                            |
      /// | go-jump                   | The icon for the jump to action.                                                                                                                                        |
      /// | go-last                   | The icon for the go to the last item in a list action.                                                                                                                  |
      /// | go-next                   | The icon for the go to the next item in a list action.                                                                                                                  |
      /// | go-previous               | The icon for the go to the previous item in a list action.                                                                                                              |
      /// | go-top                    | The icon for the go to the top of a list action.                                                                                                                        |
      /// | go-up                     | The icon for the go up in a list action.                                                                                                                                |
      /// | help-about                | The icon for the About item in the Help menu.                                                                                                                           |
      /// | help-contents             | The icon for Contents item in the Help menu.                                                                                                                            |
      /// | help-faq                  | The icon for the FAQ item in the Help menu.                                                                                                                             |
      /// | insert-image              | The icon for the insert image action of an application.                                                                                                                 |
      /// | insert-link               | The icon for the insert link action of an application.                                                                                                                  |
      /// | insert-object             | The icon for the insert object action of an application.                                                                                                                |
      /// | insert-table              | The icon for the insert table action of an application.                                                                                                                 |
      /// | insert-text               | The icon for the insert text action of an application.                                                                                                                  |
      /// | list-add                  | The icon for the add to list action.                                                                                                                                    |
      /// | list-remove               | The icon for the remove from list action.                                                                                                                               |
      /// | mail-forward              | The icon for the forward action of an electronic mail application.                                                                                                      |
      /// | mail-mark-important       | The icon for the mark as important action of an electronic mail application.                                                                                            |
      /// | mail-mark-junk            | The icon for the mark as junk action of an electronic mail application.                                                                                                 |
      /// | mail-mark-notjunk         | The icon for the mark as not junk action of an electronic mail application.                                                                                             |
      /// | mail-mark-read            | The icon for the mark as read action of an electronic mail application.                                                                                                 |
      /// | mail-mark-unread          | The icon for the mark as unread action of an electronic mail application.                                                                                               |
      /// | mail-message-new          | The icon for the compose new mail action of an electronic mail application.                                                                                             |
      /// | mail-reply-all            | The icon for the reply to all action of an electronic mail application.                                                                                                 |
      /// | mail-reply-sender         | The icon for the reply to sender action of an electronic mail application.                                                                                              |
      /// | mail-send                 | The icon for the send action of an electronic mail application.                                                                                                         |
      /// | mail-send-receive         | The icon for the send and receive action of an electronic mail application.                                                                                             |
      /// | media-eject               | The icon for the eject action of a media player or file manager.                                                                                                        |
      /// | media-optical-burn        | The icon for the media optical burn action of a media player or file manager.                                                                                           |
      /// | media-playback-pause      | The icon for the pause action of a media player.                                                                                                                        |
      /// | media-playback-start      | The icon for the start playback action of a media player.                                                                                                               |
      /// | media-playback-stop       | The icon for the stop action of a media player.                                                                                                                         |
      /// | media-record              | The icon for the record action of a media application.                                                                                                                  |
      /// | media-seek-backward       | The icon for the seek backward action of a media player.                                                                                                                |
      /// | media-seek-forward        | The icon for the seek forward action of a media player.                                                                                                                 |
      /// | media-skip-backward       | The icon for the skip backward action of a media player.                                                                                                                |
      /// | media-skip-forward        | The icon for the skip forward action of a media player.                                                                                                                 |
      /// | object-flip-horizontal    | The icon for the action to flip an object horizontally.                                                                                                                 |
      /// | object-flip-vertical      | The icon for the action to flip an object vertically.                                                                                                                   |
      /// | object-rotate-left        | The icon for the rotate left action performed on an object.                                                                                                             |
      /// | object-rotate-right       | The icon for the rotate rigt action performed on an object.                                                                                                             |
      /// | process-stop              | The icon used for the "Stop" action in applications with actions that may take a while to process, such as web page loading in a browser.                               |
      /// | system-lock-screen        | The icon used for the "Lock Screen" item in the desktop's panel application.                                                                                            |
      /// | system-log-out            | The icon used for the "Log Out" item in the desktop's panel application.                                                                                                |
      /// | system-run                | The icon used for the "Run Application..." item in the desktop's panel application.                                                                                     |
      /// | system-search             | The icon used for the "Search" item in the desktop's panel application.                                                                                                 |
      /// | system-reboot             | The icon used for the "Reboot" item in the desktop's panel application.                                                                                                 |
      /// | system-shutdown           | The icon used for the "Shutdown" item in the desktop's panel application.                                                                                               |
      /// | tools-check-spelling      | The icon used for the "Check Spelling" item in the application's "Tools" menu.                                                                                          |
      /// | view-fullscreen           | The icon used for the "Fullscreen" item in the application's "View" menu.                                                                                               |
      /// | view-media-equalizer      | The icon used for the view media aqualizer action.                                                                                                                      |
      /// | view-media-lyrics         | The icon used for the view media lyrics action.                                                                                                                         |
      /// | view-refresh              | The icon used for the "Refresh" item in the application's "View" menu.                                                                                                  |
      /// | view-restore              | The icon used by an application for leaving the fullscreen view, and returning to a normal windowed view.                                                               |
      /// | view-sort-ascending       | The icon used for the "Sort Ascending" item in the application's "View" menu, or in a button for changing the sort method for a list.                                   |
      /// | view-sort-descending      | The icon used for the "Sort Descending" item in the application's "View" menu, or in a button for changing the sort method for a list.                                  |
      /// | window-close              | The icon used for the window close button.                                                                                                                              |
      /// | window-close-hovered      | The icon used for the hovered window close button.                                                                                                                      |
      /// | window-fullscreen         | The icon used for the window fullscreen button.                                                                                                                         |
      /// | window-fullscreen-hovered | The icon used for the hovered window fullscreen button.                                                                                                                 |
      /// | window-maximize           | The icon used for the window maximize button.                                                                                                                           |
      /// | window-maximize-hovered   | The icon used for the hovered window maximize button.                                                                                                                   |
      /// | window-minimize           | The icon used for the window minimize button.                                                                                                                           |
      /// | window-minimize-hovered   | The icon used for the hovered window minimize button.                                                                                                                   |
      /// | window-new                | The icon used for the "New Window" item in the application's "Windows" menu.                                                                                            |
      /// | window-restore            | The icon used for the window restore button.                                                                                                                            |
      /// | window-restore-hovered    | The icon used for the hovered window restore button.                                                                                                                    |
      /// | zoom-fit-best             | The icon used for the "Best Fit" item in the application's "View" menu.                                                                                                 |
      /// | zoom-in                   | The icon used for the "Zoom in" item in the application's "View" menu.                                                                                                  |
      /// | zoom-original             | The icon used for the "Original Size" item in the application's "View" menu.                                                                                            |
      /// | zoom-out                  | The icon used for the "Zoom Out" item in the application's "View" menu.                                                                                                 |
      /// @par The following table represents Standard Animation Icons :
      /// | Name               | Description                                                                                                     |
      /// | ------------------ | --------------------------------------------------------------------------------------------------------------- |
      /// | process-working    | This is the standard spinner animation for web browsers and file managers to show that the location is loading. |
      /// @par The following table represents Standard Application Icons :
      /// | Name                              | Description                                                                                  |
      /// | --------------------------------- | -------------------------------------------------------------------------------------------- |
      /// | accessories-calculator            | The icon used for the desktop's calculator accessory program.                                |
      /// | accessories-character-map         | The icon used for the desktop's international and extended text character accessory program. |
      /// | accessories-dictionary            | The icon used for the desktop's dictionary accessory program.                                |
      /// | accessories-text-editor           | The icon used for the desktop's text editing accessory program.                              |
      /// | help-browser                      | The icon used for the desktop's help browsing application.                                   |
      /// | help                              | The icon used for the desktop's help application.                                            |
      /// | multimedia-volume-control         | The icon used for the desktop's hardware volume control application.                         |
      /// | preferences-desktop-accessibility | The icon used for the desktop's accessibility preferences.                                   |
      /// | preferences-desktop-font          | The icon used for the desktop's font preferences.                                            |
      /// | preferences-desktop-keyboard      | The icon used for the desktop's keyboard preferences.                                        |
      /// | preferences-desktop-locale.       | The icon used for the desktop's locale preferences.                                          |
      /// | preferences-desktop-screensaver   | The icon used for the desktop's screen saving preferences.                                   |
      /// | preferences-desktop-theme         | The icon used for the desktop's theme preferences.                                           |
      /// | preferences-desktop-wallpaper     | The icon used for the desktop's wallpaper preferences.                                       |
      /// | system-file-manager               | The icon used for the desktop's file management application.                                 |
      /// | system-software-install           | The icon used for the desktop's software installer application.                              |
      /// | system-software-update            | The icon used for the desktop's software updating application.                               |
      /// | utilities-system-monitor          | The icon used for the desktop's system resource monitor application.                         |
      /// | utilities-terminal                | The icon used for the desktop's terminal emulation application.                              |
      /// @par The following table represents Standard Category Icons :
      /// | Name                            | Description                                                                        |
      /// | ------------------------------- | ---------------------------------------------------------------------------------- |
      /// | applications-accessories        | The icon for the "Accessories" sub-menu of the Programs menu.                      |
      /// | applications-development        | The icon for the "Programming" sub-menu of the Programs menu.                      |
      /// | applications-engineering        | The icon for the "Engineering" sub-menu of the Programs menu.                      |
      /// | applications-games              | The icon for the "Games" sub-menu of the Programs menu.                            |
      /// | applications-graphics           | The icon for the "Graphics" sub-menu of the Programs menu.                         |
      /// | applications-internet           | The icon for the "Internet" sub-menu of the Programs menu.                         |
      /// | applications-multimedia         | The icon for the "Multimedia" sub-menu of the Programs menu.                       |
      /// | applications-office             | The icon for the "Office" sub-menu of the Programs menu.                           |
      /// | applications-other              | The icon for the "Other" sub-menu of the Programs menu.                            |
      /// | applications-science            | The icon for the "Science" sub-menu of the Programs menu.                          |
      /// | applications-system             | The icon for the "System Tools" sub-menu of the Programs menu.                     |
      /// | applications-utilities          | The icon for the "Utilities" sub-menu of the Programs menu.                        |
      /// | preferences-desktop             | The icon for the "Desktop Preferences" category.                                   |
      /// | preferences-desktop-peripherals | The icon for the "Peripherals" sub-category of the "Desktop Preferences" category. |
      /// | preferences-desktop-personal    | The icon for the "Personal" sub-category of the "Desktop Preferences" category.    |
      /// | preferences-other               | The icon for the "Other" preferences category.                                     |
      /// | preferences-system              | The icon for the "System Preferences" category.                                    |
      /// | preferences-system-network      | The icon for the "Network" sub-category of the "System Preferences" category.      |
      /// | system-help                     | The icon for the "Help" system category.                                           |
      /// @par The following table represents Standard Device Icons :
      /// | Name                                | Description                                                                                                                                                                                                                                                                 |
      /// | ----------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
      /// | audio-card                          | The icon used for the audio rendering device.                                                                                                                                                                                                                               |
      /// | audio-input-microphone              | The icon used for the microphone audio input device.                                                                                                                                                                                                                        |
      /// | battery                             | The icon used for the system battery device.                                                                                                                                                                                                                                |
      /// | camera-photo                        | The icon used for a digital still camera devices.                                                                                                                                                                                                                           |
      /// | camera-video                        | The fallback icon for video cameras.                                                                                                                                                                                                                                        |
      /// | camera-web                          | The fallback icon for web cameras.                                                                                                                                                                                                                                          |
      /// | computer                            | The icon used for the computing device as a whole.                                                                                                                                                                                                                          |
      /// | drive-harddisk                      | The icon used for hard disk drives.                                                                                                                                                                                                                                         |
      /// | drive-optical                       | The icon used for optical media drives such as CD and DVD.                                                                                                                                                                                                                  |
      /// | drive-removable-media-usb-pen-drive | The icon used for removable media usb pen drives.                                                                                                                                                                                                                           |
      /// | drive-removable-media               | The icon used for removable media drives.                                                                                                                                                                                                                                   |
      /// | input-gaming                        | The icon used for the gaming input device.                                                                                                                                                                                                                                  |
      /// | input-keyboard                      | The icon used for the keyboard input device.                                                                                                                                                                                                                                |
      /// | input-mouse                         | The icon used for the mousing input device.                                                                                                                                                                                                                                 |
      /// | input-tablet                        | The icon used for graphics tablet input devices.                                                                                                                                                                                                                            |
      /// | media-flash                         | The fallback icon used for flash media, such as memory stick and SD.                                                                                                                                                                                                        |
      /// | media-floppy                        | The icon used for physical floppy disk media.                                                                                                                                                                                                                               |
      /// | media-optical-audio                 | The icon used for physical audio optical media.                                                                                                                                                                                                                             |
      /// | media-optical-blu-ray               | The icon used for physical blu ray media.                                                                                                                                                                                                                                   |
      /// | media-optical-data                  | The icon used for physical data optical media.                                                                                                                                                                                                                              |
      /// | media-optical-dvd-video             | The icon used for physical video DVD media.                                                                                                                                                                                                                                 |
      /// | media-optical-dvd                   | The icon used for physical DVD media.                                                                                                                                                                                                                                       |
      /// | media-optical-mixed-cd              | The icon used for physical mixed CD media.                                                                                                                                                                                                                                  |
      /// | media-optical-recordeable           | The icon used for physical recordable optical media.                                                                                                                                                                                                                        |
      /// | media-optical-video                 | The icon used for physical video optical media.                                                                                                                                                                                                                             |
      /// | media-optical                       | The icon used for physical optical media such as CD and DVD.                                                                                                                                                                                                                |
      /// | media-tape                          | The icon used for generic physical tape media.                                                                                                                                                                                                                              |
      /// | modem                               | The icon used for modem devices.                                                                                                                                                                                                                                            |
      /// | multimedia-player                   | The icon used for generic multimedia playing devices.                                                                                                                                                                                                                       |
      /// | network-wired                       | The icon used for wired network connections.                                                                                                                                                                                                                                |
      /// | network-wireless                    | The icon used for wireless network connections.                                                                                                                                                                                                                             |
      /// | pda                                 | This is the fallback icon for Personal Digial Assistant devices. Primary use of this icon is for PDA devices connected to the PC. Connection medium is not an important aspect of the icon. The metaphor for this fallback icon should be a generic PDA device icon.        |
      /// | phone                               | This is the default fallback for phone devices. Primary use of this icon group is for phone devices which support connectivity to the PC. These may be VoIP, cellular, or possibly landline phones. The metaphor for this fallback should be a generic mobile phone device. |
      /// | printer                             | The icon used for a printer device.                                                                                                                                                                                                                                         |
      /// | scanner                             | The icon used for a scanner device.                                                                                                                                                                                                                                         |
      /// | video-display                       | The icon used for the monitor that video gets displayed to.                                                                                                                                                                                                                 |
      /// @par The following table represents Standard Emblem Icons :
      /// | Name                 | Description                                                                                                          |
      /// | -------------------- | -------------------------------------------------------------------------------------------------------------------- |
      /// | emblem-default       | The icon used as an emblem to specify the default selection of a printer for example.                                |
      /// | emblem-documents     | The icon used as an emblem for the directory where a user's documents are stored.                                    |
      /// | emblem-downloads     | The icon used as an emblem for the directory where a user's downloads from the internet are stored.                  |
      /// | emblem-favorite      | The icon used as an emblem for files and directories that the user marks as favorites.                               |
      /// | emblem-important     | The icon used as an emblem for files and directories that are marked as important by the user.                       |
      /// | emblem-locked        | The icon used as an emblem for files and directories that the user marks as locked.                                  |
      /// | emblem-mail          | The icon used as an emblem to specify the directory where the user's electronic mail is stored.                      |
      /// | emblem-new           | The icon used as an emblem for files and directories that the user marks as new.                                     |
      /// | emblem-photos        | The icon used as an emblem to specify the directory where the user stores photographs.                               |
      /// | emblem-readonly      | The icon used as an emblem for files and directories which can not be written to by the user.                        |
      /// | emblem-shared        | The icon used as an emblem for files and directories that are shared to other users.                                 |
      /// | emblem-symbolic-link | The icon used as an emblem for files and direcotires that are links to other files or directories on the filesystem. |
      /// | emblem-synchronized  | The icon used as an emblem for files or directories that are configured to be synchronized to another device.        |
      /// | emblem-system        | The icon used as an emblem for directories that contain system libraries, settings, and data.                        |
      /// | emblem-unlocked      | The icon used as an emblem for files and directories that the user marks as unlocked.                                |
      /// | emblem-unreadable    | The icon used as an emblem for files and directories that are inaccessible.                                          |
      /// @par The following table represents Standard Emoticon Icons :
      /// | Name             | Description                         |
      /// | ---------------- | ----------------------------------- |
      /// | face-angel       | The icon used for the 0:-) emote.   |
      /// | face-angry       | The icon used for the X-( emote.    |
      /// | face-cool        | The icon used for the B-) emote.    |
      /// | face-crying      | The icon used for the :'( emote.    |
      /// | face-devilish    | The icon used for the >:-) emote.   |
      /// | face-embarrassed | The icon used for the :-[ emote.    |
      /// | face-kiss        | The icon used for the :-* emote.    |
      /// | face-laugh       | The icon used for the :-)) emote.   |
      /// | face-monkey      | The icon used for the :-(\|) emote. |
      /// | face-plain       | The icon used for the :-\| emote.   |
      /// | face-raspberry   | The icon used for the :-P emote.    |
      /// | face-sad         | The icon used for the :-( emote.    |
      /// | face-sick        | The icon used for the :-& emote.    |
      /// | face-smile       | The icon used for the :-) emote.    |
      /// | face-smile-big   | The icon used for the :-D emote.    |
      /// | face-smirk       | The icon used for the :-! emote.    |
      /// | face-surprise    | The icon used for the :-0 emote.    |
      /// | face-tired       | The icon used for the \| ) emote.   |
      /// | face-uncertain   | The icon used for the :-/ emote.    |
      /// | face-wink        | The icon used for the ;-) emote.    |
      /// | face-worried     | The icon used for the :-S emote.    |
      /// @par The following table represents Standard MIME Type Icons :
      /// | Name    | Description                                                                                                                                                              |
      /// | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
      /// | flag-aa | The flag for the country with the ISO 3166 country code AA. All flags should use ISO 3166 two-letter country codes, in lowercase form, as the specifier for the country. |
      /// @par The following table represents Standard International Icons :
      /// | Name                     | Description                                                 |
      /// | ------------------------ | ----------------------------------------------------------- |
      /// | application-x-executable | The icon used for executable file types.                    |
      /// | audio-x-generic          | The icon used for generic audio file types.                 |
      /// | font-x-generic           | The icon used for generic font file types.                  |
      /// | image-x-generic          | The icon used for generic image file types.                 |
      /// | package-x-generic        | The icon used for generic package file types.               |
      /// | text-html                | The icon used for HTML text file types.                     |
      /// | text-x-generic           | The icon used for generic text file types.                  |
      /// | text-x-generic-template  | The icon used for generic text templates.                   |
      /// | text-x-script            | The icon used for script file types, such as shell scripts. |
      /// | video-x-generic          | The icon used for generic video file types.                 |
      /// | x-office-address-book    | The icon used for generic address book file types.          |
      /// | x-office-calendar        | The icon used for generic calendar file types.              |
      /// | x-office-contact         | The icon used for generic contact file types.               |
      /// | x-office-document        | The icon used for generic document and letter file types.   |
      /// | x-office-presentation    | The icon used for generic presentation file types.          |
      /// | x-office-spreadsheet     | The icon used for generic spreadsheet file types.           |
      /// @par The following table represents Standard Place Icons :
      /// | Name                | Description                                                                                                               |
      /// | ------------------- | ------------------------------------------------------------------------------------------------------------------------- |
      /// | folder              | The standard folder icon used to represent directories on local filesystems, mail folders, and other hierarchical groups. |
      /// | folder-activities   | The icon used for activities directory.                                                                                   |
      /// | folder-applications | The icon used for applications directory.                                                                                 |
      /// | folder-bookmark     | The icon used for bookmark directory.                                                                                     |
      /// | folder-cloud        | The icon used for cloud directory.                                                                                        |
      /// | folder-desktop      | The icon used for desktop directory.                                                                                      |
      /// | folder-development  | The icon used for develoment directory.                                                                                   |
      /// | folder-documents    | The icon used for documents directory.                                                                                    |
      /// | folder-download     | The icon used for download directory.                                                                                     |
      /// | folder-favoties     | The icon used for favorites directory.                                                                                    |
      /// | folder-games        | The icon used for games directory.                                                                                        |
      /// | folder-github       | The icon used for github directory.                                                                                       |
      /// | folder-home         | The icon used for home directory.                                                                                         |
      /// | folder-html         | The icon used for html directory.                                                                                         |
      /// | folder-images       | The icon used for images directory.                                                                                       |
      /// | folder-important    | The icon used for important directory.                                                                                    |
      /// | folder-locked       | The icon used for locked directory.                                                                                       |
      /// | folder-music        | The icon used for music directory.                                                                                        |
      /// | folder-network      | The icon used for network directory.                                                                                      |
      /// | folder-print        | The icon used for print directory.                                                                                        |
      /// | folder-public       | The icon used for public directory.                                                                                       |
      /// | folder-remote       | The icon used for normal directories on a remote filesystem.                                                              |
      /// | folder-system       | The icon used for system directory.                                                                                       |
      /// | folder-tar          | The icon used for tar directory.                                                                                          |
      /// | folder-temp         | The icon used for temp directory.                                                                                         |
      /// | folder-templates    | The icon used for templates directory.                                                                                    |
      /// | folder-text         | The icon used for text directory.                                                                                         |
      /// | folder-videos       | The icon used for videos directory.                                                                                       |
      /// | network-server      | The icon used for individual host machines under the "Network Servers" place in the file manager.                         |
      /// | network-workgroup   | The icon for the "Network Servers" place in the desktop's file manager, and workgroups within the network.                |
      /// | start-here          | The icon used by the desktop's main menu for accessing places, applications, and other features.                          |
      /// | user-bookmarks      | The icon for the user's special "Bookmarks" place.                                                                        |
      /// | user-desktop        | The icon for the special "Desktop" directory of the user.                                                                 |
      /// | user-home           | The icon for the special "Home" directory of the user.                                                                    |
      /// | user-trash          | The icon for the user's "Trash" place in the desktop's file manager.                                                      |
      /// @par The following table represents Standard Status Icons :
      /// | Name                      | Description                                                                                                                                                                                                                                                                                      |
      /// | ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
      /// | appointment-missed        | The icon used when an appointment was missed.                                                                                                                                                                                                                                                    |
      /// | appointment-soon          | The icon used when an appointment will occur soon.                                                                                                                                                                                                                                               |
      /// | audio-volume-high         | The icon used to indicate high audio volume.                                                                                                                                                                                                                                                     |
      /// | audio-volume-low          | The icon used to indicate low audio volume.                                                                                                                                                                                                                                                      |
      /// | audio-volume-medium       | The icon used to indicate medium audio volume.                                                                                                                                                                                                                                                   |
      /// | audio-volume-muted        | The icon used to indicate the muted state for audio playback.                                                                                                                                                                                                                                    |
      /// | battery-caution           | The icon used when the battery is below 40%.                                                                                                                                                                                                                                                     |
      /// | battery-low               | The icon used when the battery is below 20%.                                                                                                                                                                                                                                                     |
      /// | dialog-error              | The icon used when a dialog is opened to explain an error condition to the user.                                                                                                                                                                                                                 |
      /// | dialog-information        | The icon used when a dialog is opened to give information to the user that may be pertinent to the requested action.                                                                                                                                                                             |
      /// | dialog-password           | The icon used when a dialog requesting the authentication credentials for a user is opened.                                                                                                                                                                                                      |
      /// | dialog-question           | The icon used when a dialog is opened to ask a simple question of the user.                                                                                                                                                                                                                      |
      /// | dialog-warning            | The icon used when a dialog is opened to warn the user of impending issues with the requested action.                                                                                                                                                                                            |
      /// | folder-drag-accept        | The icon used for a folder while an object is being dragged onto it, that is of a type that the directory can contain.                                                                                                                                                                           |
      /// | folder-open               | The icon used for folders, while their contents are being displayed within the same window. This icon would normally be shown in a tree or list view, next to the main view of a folder's contents.                                                                                              |
      /// | folder-visiting           | The icon used for folders, while their contents are being displayed in another window. This icon would typically be used when using multiple windows to navigate the hierarchy, such as in Nautilus's spatial mode.                                                                              |
      /// | image-loading             | The icon used when another image is being loaded, such as thumnails for larger images in the file manager.                                                                                                                                                                                       |
      /// | image-missing             | The icon used when another image could not be loaded.                                                                                                                                                                                                                                            |
      /// | mail-attachment           | The icon used for an electronic mail that contains attachments.                                                                                                                                                                                                                                  |
      /// | mail-unread               | The icon used for an electronic mail that is unread.                                                                                                                                                                                                                                             |
      /// | mail-read                 | The icon used for an electronic mail that is read.                                                                                                                                                                                                                                               |
      /// | mail-replied              | The icon used for an electronic mail that has been replied to.                                                                                                                                                                                                                                   |
      /// | mail-signed               | The icon used for an electronic mail that contains a signature.                                                                                                                                                                                                                                  |
      /// | mail-signed-verified      | The icon used for an electronic mail that contains a signature which has also been verified by the security system.                                                                                                                                                                              |
      /// | media-playlist-repeat     | The icon for the repeat mode of a media player.                                                                                                                                                                                                                                                  |
      /// | media-playlist-shuffle    | The icon for the shuffle mode of a media player.                                                                                                                                                                                                                                                 |
      /// | network-error             | The icon used when an error occurs trying to intialize the network connection of the computing device. This icon should be two computers, one in the background, with the screens of both computers, colored black, and with the theme's style element for errors, overlayed on top of the icon. |
      /// | network-idle              | The icon used when no data is being transmitted or received, while the computing device is connected to a network. This icon should be two computers, one in the background, with the screens of both computers, colored black.                                                                  |
      /// | network-offline           | The icon used when the computing device is disconnected from the network. This icon should be a computer in the background, with a screen colored black, and the theme's icon element to show that a device is not accessible, in the foreground.                                                |
      /// | network-receive           | The icon used when data is being received, while the computing device is connected to a network. This icon should be two computers, one in the background, with its screen colored green, and the screen of the computer in the foreground, colored black.                                       |
      /// | network-transmit          | The icon used when data is being transmitted, while the computing device is connected to a network. This icon should be two computers, one in the background, with its screen colored black, and the screen of the computer in the foreground, colored green.                                    |
      /// | network-transmit-receive  | The icon used data is being both transmitted and received simultaneously, while the computing device is connected to a network. This icon should be two computers, one in the background, with the screens of both computers, colored green.                                                     |
      /// | printer-error             | The icon used when an error occurs while attempting to print. This icon should be the theme's printer device icon, with the theme's style element for errors, overlayed on top of the icon.                                                                                                      |
      /// | printer-printing          | The icon used while a print job is successfully being spooled to a printing device. This icon should be the theme's printer device icon, with a document emerging from the printing device.                                                                                                      |
      /// | security-high             | The icon used to indicate that the security level of a connection is known to be secure, using strong encryption and a valid certificate.                                                                                                                                                        |
      /// | security-medium           | The icon used to indicate that the security level of a connection is presumed to be secure, using strong encryption, and a certificate that could not be automatically verified, but which the user has chosen to trust.                                                                         |
      /// | security-low              | The icon used to indicate that the security level of a connection is presumed to be insecure, either by using weak encryption, or by using a certificate that the could not be automatically verified, and which the user has not chosent to trust.                                              |
      /// | software-update-available | The icon used when an update is available for software installed on the computing device, through the system software update program.                                                                                                                                                            |
      /// | software-update-urgent    | The icon used when an urgent update is available through the system software update program.                                                                                                                                                                                                     |
      /// | task-due                  | The icon used when a task is due soon.                                                                                                                                                                                                                                                           |
      /// | task-past-due             | The icon used when a task that was due, has been left incomplete.                                                                                                                                                                                                                                |
      /// | user-available            | The icon used when a user on a chat network is available to initiate a conversation with.                                                                                                                                                                                                        |
      /// | user-away                 | The icon used when a user on a chat network is away from their keyboard and the chat program.                                                                                                                                                                                                    |
      /// | user-idle                 | The icon used when a user on a chat network has not been an active participant in any chats on the network, for an extended period of time.                                                                                                                                                      |
      /// | user-offline              | The icon used when a user on a chat network is not available.                                                                                                                                                                                                                                    |
      /// | user-trash-full           | The icon for the user's "Trash" in the desktop's file manager, when there are items in the "Trash" waiting for disposal or recovery.                                                                                                                                                             |
      /// | weather-clear             | The icon used while the weather for a region is "clear skies".                                                                                                                                                                                                                                   |
      /// | weather-clear-night       | The icon used while the weather for a region is "clear skies" during the night.                                                                                                                                                                                                                  |
      /// | weather-few-clouds        | The icon used while the weather for a region is "partly cloudy".                                                                                                                                                                                                                                 |
      /// | weather-few-clouds-night  | The icon used while the weather for a region is "partly cloudy" during the night.                                                                                                                                                                                                                |
      /// | weather-fog               | The icon used while the weather for a region is "foggy".                                                                                                                                                                                                                                         |
      /// | weather-overcast          | The icon used while the weather for a region is "overcast".                                                                                                                                                                                                                                      |
      /// | weather-severe-alert      | The icon used while a sever weather alert is in effect for a region.                                                                                                                                                                                                                             |
      /// | weather-showers           | The icon used while rain showers are occurring in a region.                                                                                                                                                                                                                                      |
      /// | weather-showers-scattered | The icon used while scattered rain showers are occurring in a region.                                                                                                                                                                                                                            |
      /// | weather-snow              | The icon used while snow showers are occurring in a region.                                                                                                                                                                                                                                      |
      /// | weather-storm             | The icon used while storms are occurring in a region.                                                                                                                                                                                                                                            |
      /// @par The following table represents Standard xtd Icons :
      /// | Name                      | Description                        |
      /// | ------------------------- | ---------------------------------- |
      /// | gammasoft                 | The icon for Gammasoft logo.       |
      /// | xtd                       | The icon for xtd logo.             |
      /// | xtd-console               | The icon for xtd console logo.     |
      /// | xtd-forms                 | The icon for xtd forms logo.       |
      /// | xtd-console               | The icon for xtd console logo.     |
      /// | xtd-tunit                 | The icon for xtd tunit logo.       |
      /// | xtd-core                  | The icon for xtd core logo.        |
      /// | xtd-delegates             | The icon for xtd delegates logo.   |
      /// | xtd-diagnostics           | The icon for xtd diagnostics logo. |
      /// | xtd-drawing               | The icon for xtd drawing logo.     |
      /// | xtd-io                    | The icon for xtd io logo.          |
      /// | xtd-strings               | The icon for xtd strings logo.     |
      /// @remarks See [Icon Naming Specification](https://specifications.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html) for more information.
      static xtd::array<xtd::string> names() noexcept;
      /// @brief Gets the image names for the specified context.
      /// @param context The context to retrieve the image names.
      /// @return An xtd::string, xtd::string hash table that contains the image names for the specified context.
      /// @remarks The system images are grouped by contaxt.
      /// @par The following table represents Standard Action Icons :
      /// | Name                      | Description                                                                                                                                                             |
      /// | ------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
      /// | address-book-new          | The icon used for the action to create a new address book.                                                                                                              |
      /// | application-exit          | The icon used for exiting an application. Typically this is seen in the application's menus as File->Quit.                                                              |
      /// | appointment-new           | The icon used for the action to create a new appointment in a calendaring application.                                                                                  |
      /// | call-start                | The icon used for initiating or accepting a call. Should be similar to the standard cellular call pickup icon, a green handset with ear and mouth pieces facing upward. |
      /// | call-stop                 | The icon used for stopping a current call. Should be similar to the standard cellular call hangup icon, a red handset with ear and mouth pieces facing downward.        |
      /// | contact-new               | The icon used for the action to create a new contact in an address book application.                                                                                    |
      /// | dialog-cancel             | The icon used for the action dialog cancel.                                                                                                                             |
      /// | dialog-ok                 | The icon used for the action dialog ok.                                                                                                                                 |
      /// | dialog-ok-apply           | The icon used for the action dialog apply.                                                                                                                              |
      /// | document-edit             | The icon used for the action to edit a document.                                                                                                                        |
      /// | document-new              | The icon used for the action to create a new document.                                                                                                                  |
      /// | document-open             | The icon used for the action to open a document.                                                                                                                        |
      /// | document-open-recent      | The icon used for the action to open a document that was recently opened.                                                                                               |
      /// | document-page-setup       | The icon for the page setup action of a document editor.                                                                                                                |
      /// | document-print            | The icon for the print action of an application.                                                                                                                        |
      /// | document-print-preview    | The icon for the print preview action of an application.                                                                                                                |
      /// | document-properties       | The icon for the action to view the properties of a document in an application.                                                                                         |
      /// | document-revert           | The icon for the action of reverting to a previous version of a document.                                                                                               |
      /// | document-save             | The icon for the save action. Should be an arrow pointing down and toward a hard disk.                                                                                  |
      /// | document-save-as          | The icon for the save as action.                                                                                                                                        |
      /// | document-send             | The icon for the send action. Should be an arrow pointing up and away from a hard disk.                                                                                 |
      /// | edit-clear                | The icon for the clear action.                                                                                                                                          |
      /// | edit-copy                 | The icon for the copy action.                                                                                                                                           |
      /// | edit-cut                  | The icon for the cut action.                                                                                                                                            |
      /// | edit-delete               | The icon for the delete action.                                                                                                                                         |
      /// | edit-find                 | The icon for the find action.                                                                                                                                           |
      /// | edit-find-replace         | The icon for the find and replace action.                                                                                                                               |
      /// | edit-paste                | The icon for the paste action.                                                                                                                                          |
      /// | edit-redo                 | The icon for the redo action.                                                                                                                                           |
      /// | edit-rename               | The icon for the rename action.                                                                                                                                         |
      /// | edit-select-all           | The icon for the select all action.                                                                                                                                     |
      /// | edit-undo                 | The icon for the undo action.                                                                                                                                           |
      /// | folder-new                | The icon for creating a new folder.                                                                                                                                     |
      /// | format-indent-less        | The icon for the decrease indent formatting action.                                                                                                                     |
      /// | format-indent-more        | The icon for the increase indent formatting action.                                                                                                                     |
      /// | format-justify-center     | The icon for the center justification formatting action.                                                                                                                |
      /// | format-justify-fill       | The icon for the fill justification formatting action.                                                                                                                  |
      /// | format-justify-left       | The icon for the left justification formatting action.                                                                                                                  |
      /// | format-justify-right      | The icon for the right justification action.                                                                                                                            |
      /// | format-text-direction-ltr | The icon for the left-to-right text formatting action.                                                                                                                  |
      /// | format-text-direction-rtl | The icon for the right-to-left formatting action.                                                                                                                       |
      /// | format-text-bold          | The icon for the bold text formatting action.                                                                                                                           |
      /// | format-text-italic        | The icon for the italic text formatting action.                                                                                                                         |
      /// | format-text-underline     | The icon for the underlined text formatting action.                                                                                                                     |
      /// | format-text-strikethrough | The icon for the strikethrough text formatting action.                                                                                                                  |
      /// | go-bottom                 | The icon for the go to bottom of a list action.                                                                                                                         |
      /// | go-down                   | The icon for the go down in a list action.                                                                                                                              |
      /// | go-first                  | The icon for the go to the first item in a list action.                                                                                                                 |
      /// | go-home                   | The icon for the go to home location action.                                                                                                                            |
      /// | go-jump                   | The icon for the jump to action.                                                                                                                                        |
      /// | go-last                   | The icon for the go to the last item in a list action.                                                                                                                  |
      /// | go-next                   | The icon for the go to the next item in a list action.                                                                                                                  |
      /// | go-previous               | The icon for the go to the previous item in a list action.                                                                                                              |
      /// | go-top                    | The icon for the go to the top of a list action.                                                                                                                        |
      /// | go-up                     | The icon for the go up in a list action.                                                                                                                                |
      /// | help-about                | The icon for the About item in the Help menu.                                                                                                                           |
      /// | help-contents             | The icon for Contents item in the Help menu.                                                                                                                            |
      /// | help-faq                  | The icon for the FAQ item in the Help menu.                                                                                                                             |
      /// | insert-image              | The icon for the insert image action of an application.                                                                                                                 |
      /// | insert-link               | The icon for the insert link action of an application.                                                                                                                  |
      /// | insert-object             | The icon for the insert object action of an application.                                                                                                                |
      /// | insert-table              | The icon for the insert table action of an application.                                                                                                                 |
      /// | insert-text               | The icon for the insert text action of an application.                                                                                                                  |
      /// | list-add                  | The icon for the add to list action.                                                                                                                                    |
      /// | list-remove               | The icon for the remove from list action.                                                                                                                               |
      /// | mail-forward              | The icon for the forward action of an electronic mail application.                                                                                                      |
      /// | mail-mark-important       | The icon for the mark as important action of an electronic mail application.                                                                                            |
      /// | mail-mark-junk            | The icon for the mark as junk action of an electronic mail application.                                                                                                 |
      /// | mail-mark-notjunk         | The icon for the mark as not junk action of an electronic mail application.                                                                                             |
      /// | mail-mark-read            | The icon for the mark as read action of an electronic mail application.                                                                                                 |
      /// | mail-mark-unread          | The icon for the mark as unread action of an electronic mail application.                                                                                               |
      /// | mail-message-new          | The icon for the compose new mail action of an electronic mail application.                                                                                             |
      /// | mail-reply-all            | The icon for the reply to all action of an electronic mail application.                                                                                                 |
      /// | mail-reply-sender         | The icon for the reply to sender action of an electronic mail application.                                                                                              |
      /// | mail-send                 | The icon for the send action of an electronic mail application.                                                                                                         |
      /// | mail-send-receive         | The icon for the send and receive action of an electronic mail application.                                                                                             |
      /// | media-eject               | The icon for the eject action of a media player or file manager.                                                                                                        |
      /// | media-optical-burn        | The icon for the media optical burn action of a media player or file manager.                                                                                           |
      /// | media-playback-pause      | The icon for the pause action of a media player.                                                                                                                        |
      /// | media-playback-start      | The icon for the start playback action of a media player.                                                                                                               |
      /// | media-playback-stop       | The icon for the stop action of a media player.                                                                                                                         |
      /// | media-record              | The icon for the record action of a media application.                                                                                                                  |
      /// | media-seek-backward       | The icon for the seek backward action of a media player.                                                                                                                |
      /// | media-seek-forward        | The icon for the seek forward action of a media player.                                                                                                                 |
      /// | media-skip-backward       | The icon for the skip backward action of a media player.                                                                                                                |
      /// | media-skip-forward        | The icon for the skip forward action of a media player.                                                                                                                 |
      /// | object-flip-horizontal    | The icon for the action to flip an object horizontally.                                                                                                                 |
      /// | object-flip-vertical      | The icon for the action to flip an object vertically.                                                                                                                   |
      /// | object-rotate-left        | The icon for the rotate left action performed on an object.                                                                                                             |
      /// | object-rotate-right       | The icon for the rotate rigt action performed on an object.                                                                                                             |
      /// | process-stop              | The icon used for the "Stop" action in applications with actions that may take a while to process, such as web page loading in a browser.                               |
      /// | system-lock-screen        | The icon used for the "Lock Screen" item in the desktop's panel application.                                                                                            |
      /// | system-log-out            | The icon used for the "Log Out" item in the desktop's panel application.                                                                                                |
      /// | system-run                | The icon used for the "Run Application..." item in the desktop's panel application.                                                                                     |
      /// | system-search             | The icon used for the "Search" item in the desktop's panel application.                                                                                                 |
      /// | system-reboot             | The icon used for the "Reboot" item in the desktop's panel application.                                                                                                 |
      /// | system-shutdown           | The icon used for the "Shutdown" item in the desktop's panel application.                                                                                               |
      /// | tools-check-spelling      | The icon used for the "Check Spelling" item in the application's "Tools" menu.                                                                                          |
      /// | view-fullscreen           | The icon used for the "Fullscreen" item in the application's "View" menu.                                                                                               |
      /// | view-media-equalizer      | The icon used for the view media aqualizer action.                                                                                                                      |
      /// | view-media-lyrics         | The icon used for the view media lyrics action.                                                                                                                         |
      /// | view-refresh              | The icon used for the "Refresh" item in the application's "View" menu.                                                                                                  |
      /// | view-restore              | The icon used by an application for leaving the fullscreen view, and returning to a normal windowed view.                                                               |
      /// | view-sort-ascending       | The icon used for the "Sort Ascending" item in the application's "View" menu, or in a button for changing the sort method for a list.                                   |
      /// | view-sort-descending      | The icon used for the "Sort Descending" item in the application's "View" menu, or in a button for changing the sort method for a list.                                  |
      /// | window-close              | The icon used for the window close button.                                                                                                                              |
      /// | window-close-hovered      | The icon used for the hovered window close button.                                                                                                                      |
      /// | window-fullscreen         | The icon used for the window fullscreen button.                                                                                                                         |
      /// | window-fullscreen-hovered | The icon used for the hovered window fullscreen button.                                                                                                                 |
      /// | window-maximize           | The icon used for the window maximize button.                                                                                                                           |
      /// | window-maximize-hovered   | The icon used for the hovered window maximize button.                                                                                                                   |
      /// | window-minimize           | The icon used for the window minimize button.                                                                                                                           |
      /// | window-minimize-hovered   | The icon used for the hovered window minimize button.                                                                                                                   |
      /// | window-new                | The icon used for the "New Window" item in the application's "Windows" menu.                                                                                            |
      /// | window-restore            | The icon used for the window restore button.                                                                                                                            |
      /// | window-restore-hovered    | The icon used for the hovered window restore button.                                                                                                                    |
      /// | zoom-fit-best             | The icon used for the "Best Fit" item in the application's "View" menu.                                                                                                 |
      /// | zoom-in                   | The icon used for the "Zoom in" item in the application's "View" menu.                                                                                                  |
      /// | zoom-original             | The icon used for the "Original Size" item in the application's "View" menu.                                                                                            |
      /// | zoom-out                  | The icon used for the "Zoom Out" item in the application's "View" menu.                                                                                                 |
      /// @par The following table represents Standard Animation Icons :
      /// | Name               | Description                                                                                                     |
      /// | ------------------ | --------------------------------------------------------------------------------------------------------------- |
      /// | process-working    | This is the standard spinner animation for web browsers and file managers to show that the location is loading. |
      /// @par The following table represents Standard Application Icons :
      /// | Name                              | Description                                                                                  |
      /// | --------------------------------- | -------------------------------------------------------------------------------------------- |
      /// | accessories-calculator            | The icon used for the desktop's calculator accessory program.                                |
      /// | accessories-character-map         | The icon used for the desktop's international and extended text character accessory program. |
      /// | accessories-dictionary            | The icon used for the desktop's dictionary accessory program.                                |
      /// | accessories-text-editor           | The icon used for the desktop's text editing accessory program.                              |
      /// | help-browser                      | The icon used for the desktop's help browsing application.                                   |
      /// | help                              | The icon used for the desktop's help application.                                            |
      /// | multimedia-volume-control         | The icon used for the desktop's hardware volume control application.                         |
      /// | preferences-desktop-accessibility | The icon used for the desktop's accessibility preferences.                                   |
      /// | preferences-desktop-font          | The icon used for the desktop's font preferences.                                            |
      /// | preferences-desktop-keyboard      | The icon used for the desktop's keyboard preferences.                                        |
      /// | preferences-desktop-locale.       | The icon used for the desktop's locale preferences.                                          |
      /// | preferences-desktop-screensaver   | The icon used for the desktop's screen saving preferences.                                   |
      /// | preferences-desktop-theme         | The icon used for the desktop's theme preferences.                                           |
      /// | preferences-desktop-wallpaper     | The icon used for the desktop's wallpaper preferences.                                       |
      /// | system-file-manager               | The icon used for the desktop's file management application.                                 |
      /// | system-software-install           | The icon used for the desktop's software installer application.                              |
      /// | system-software-update            | The icon used for the desktop's software updating application.                               |
      /// | utilities-system-monitor          | The icon used for the desktop's system resource monitor application.                         |
      /// | utilities-terminal                | The icon used for the desktop's terminal emulation application.                              |
      /// @par The following table represents Standard Category Icons :
      /// | Name                            | Description                                                                        |
      /// | ------------------------------- | ---------------------------------------------------------------------------------- |
      /// | applications-accessories        | The icon for the "Accessories" sub-menu of the Programs menu.                      |
      /// | applications-development        | The icon for the "Programming" sub-menu of the Programs menu.                      |
      /// | applications-engineering        | The icon for the "Engineering" sub-menu of the Programs menu.                      |
      /// | applications-games              | The icon for the "Games" sub-menu of the Programs menu.                            |
      /// | applications-graphics           | The icon for the "Graphics" sub-menu of the Programs menu.                         |
      /// | applications-internet           | The icon for the "Internet" sub-menu of the Programs menu.                         |
      /// | applications-multimedia         | The icon for the "Multimedia" sub-menu of the Programs menu.                       |
      /// | applications-office             | The icon for the "Office" sub-menu of the Programs menu.                           |
      /// | applications-other              | The icon for the "Other" sub-menu of the Programs menu.                            |
      /// | applications-science            | The icon for the "Science" sub-menu of the Programs menu.                          |
      /// | applications-system             | The icon for the "System Tools" sub-menu of the Programs menu.                     |
      /// | applications-utilities          | The icon for the "Utilities" sub-menu of the Programs menu.                        |
      /// | preferences-desktop             | The icon for the "Desktop Preferences" category.                                   |
      /// | preferences-desktop-peripherals | The icon for the "Peripherals" sub-category of the "Desktop Preferences" category. |
      /// | preferences-desktop-personal    | The icon for the "Personal" sub-category of the "Desktop Preferences" category.    |
      /// | preferences-other               | The icon for the "Other" preferences category.                                     |
      /// | preferences-system              | The icon for the "System Preferences" category.                                    |
      /// | preferences-system-network      | The icon for the "Network" sub-category of the "System Preferences" category.      |
      /// | system-help                     | The icon for the "Help" system category.                                           |
      /// @par The following table represents Standard Device Icons :
      /// | Name                                | Description                                                                                                                                                                                                                                                                 |
      /// | ----------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
      /// | audio-card                          | The icon used for the audio rendering device.                                                                                                                                                                                                                               |
      /// | audio-input-microphone              | The icon used for the microphone audio input device.                                                                                                                                                                                                                        |
      /// | battery                             | The icon used for the system battery device.                                                                                                                                                                                                                                |
      /// | camera-photo                        | The icon used for a digital still camera devices.                                                                                                                                                                                                                           |
      /// | camera-video                        | The fallback icon for video cameras.                                                                                                                                                                                                                                        |
      /// | camera-web                          | The fallback icon for web cameras.                                                                                                                                                                                                                                          |
      /// | computer                            | The icon used for the computing device as a whole.                                                                                                                                                                                                                          |
      /// | drive-harddisk                      | The icon used for hard disk drives.                                                                                                                                                                                                                                         |
      /// | drive-optical                       | The icon used for optical media drives such as CD and DVD.                                                                                                                                                                                                                  |
      /// | drive-removable-media-usb-pen-drive | The icon used for removable media usb pen drives.                                                                                                                                                                                                                           |
      /// | drive-removable-media               | The icon used for removable media drives.                                                                                                                                                                                                                                   |
      /// | input-gaming                        | The icon used for the gaming input device.                                                                                                                                                                                                                                  |
      /// | input-keyboard                      | The icon used for the keyboard input device.                                                                                                                                                                                                                                |
      /// | input-mouse                         | The icon used for the mousing input device.                                                                                                                                                                                                                                 |
      /// | input-tablet                        | The icon used for graphics tablet input devices.                                                                                                                                                                                                                            |
      /// | media-flash                         | The fallback icon used for flash media, such as memory stick and SD.                                                                                                                                                                                                        |
      /// | media-floppy                        | The icon used for physical floppy disk media.                                                                                                                                                                                                                               |
      /// | media-optical-audio                 | The icon used for physical audio optical media.                                                                                                                                                                                                                             |
      /// | media-optical-blu-ray               | The icon used for physical blu ray media.                                                                                                                                                                                                                                   |
      /// | media-optical-data                  | The icon used for physical data optical media.                                                                                                                                                                                                                              |
      /// | media-optical-dvd-video             | The icon used for physical video DVD media.                                                                                                                                                                                                                                 |
      /// | media-optical-dvd                   | The icon used for physical DVD media.                                                                                                                                                                                                                                       |
      /// | media-optical-mixed-cd              | The icon used for physical mixed CD media.                                                                                                                                                                                                                                  |
      /// | media-optical-recordeable           | The icon used for physical recordable optical media.                                                                                                                                                                                                                        |
      /// | media-optical-video                 | The icon used for physical video optical media.                                                                                                                                                                                                                             |
      /// | media-optical                       | The icon used for physical optical media such as CD and DVD.                                                                                                                                                                                                                |
      /// | media-tape                          | The icon used for generic physical tape media.                                                                                                                                                                                                                              |
      /// | modem                               | The icon used for modem devices.                                                                                                                                                                                                                                            |
      /// | multimedia-player                   | The icon used for generic multimedia playing devices.                                                                                                                                                                                                                       |
      /// | network-wired                       | The icon used for wired network connections.                                                                                                                                                                                                                                |
      /// | network-wireless                    | The icon used for wireless network connections.                                                                                                                                                                                                                             |
      /// | pda                                 | This is the fallback icon for Personal Digial Assistant devices. Primary use of this icon is for PDA devices connected to the PC. Connection medium is not an important aspect of the icon. The metaphor for this fallback icon should be a generic PDA device icon.        |
      /// | phone                               | This is the default fallback for phone devices. Primary use of this icon group is for phone devices which support connectivity to the PC. These may be VoIP, cellular, or possibly landline phones. The metaphor for this fallback should be a generic mobile phone device. |
      /// | printer                             | The icon used for a printer device.                                                                                                                                                                                                                                         |
      /// | scanner                             | The icon used for a scanner device.                                                                                                                                                                                                                                         |
      /// | video-display                       | The icon used for the monitor that video gets displayed to.                                                                                                                                                                                                                 |
      /// @par The following table represents Standard Emblem Icons :
      /// | Name                 | Description                                                                                                          |
      /// | -------------------- | -------------------------------------------------------------------------------------------------------------------- |
      /// | emblem-default       | The icon used as an emblem to specify the default selection of a printer for example.                                |
      /// | emblem-documents     | The icon used as an emblem for the directory where a user's documents are stored.                                    |
      /// | emblem-downloads     | The icon used as an emblem for the directory where a user's downloads from the internet are stored.                  |
      /// | emblem-favorite      | The icon used as an emblem for files and directories that the user marks as favorites.                               |
      /// | emblem-important     | The icon used as an emblem for files and directories that are marked as important by the user.                       |
      /// | emblem-locked        | The icon used as an emblem for files and directories that the user marks as locked.                                  |
      /// | emblem-mail          | The icon used as an emblem to specify the directory where the user's electronic mail is stored.                      |
      /// | emblem-new           | The icon used as an emblem for files and directories that the user marks as new.                                     |
      /// | emblem-photos        | The icon used as an emblem to specify the directory where the user stores photographs.                               |
      /// | emblem-readonly      | The icon used as an emblem for files and directories which can not be written to by the user.                        |
      /// | emblem-shared        | The icon used as an emblem for files and directories that are shared to other users.                                 |
      /// | emblem-symbolic-link | The icon used as an emblem for files and direcotires that are links to other files or directories on the filesystem. |
      /// | emblem-synchronized  | The icon used as an emblem for files or directories that are configured to be synchronized to another device.        |
      /// | emblem-system        | The icon used as an emblem for directories that contain system libraries, settings, and data.                        |
      /// | emblem-unlocked      | The icon used as an emblem for files and directories that the user marks as unlocked.                                |
      /// | emblem-unreadable    | The icon used as an emblem for files and directories that are inaccessible.                                          |
      /// @par The following table represents Standard Emoticon Icons :
      /// | Name             | Description                         |
      /// | ---------------- | ----------------------------------- |
      /// | face-angel       | The icon used for the 0:-) emote.   |
      /// | face-angry       | The icon used for the X-( emote.    |
      /// | face-cool        | The icon used for the B-) emote.    |
      /// | face-crying      | The icon used for the :'( emote.    |
      /// | face-devilish    | The icon used for the >:-) emote.   |
      /// | face-embarrassed | The icon used for the :-[ emote.    |
      /// | face-kiss        | The icon used for the :-* emote.    |
      /// | face-laugh       | The icon used for the :-)) emote.   |
      /// | face-monkey      | The icon used for the :-(\|) emote. |
      /// | face-plain       | The icon used for the :-\| emote.   |
      /// | face-raspberry   | The icon used for the :-P emote.    |
      /// | face-sad         | The icon used for the :-( emote.    |
      /// | face-sick        | The icon used for the :-& emote.    |
      /// | face-smile       | The icon used for the :-) emote.    |
      /// | face-smile-big   | The icon used for the :-D emote.    |
      /// | face-smirk       | The icon used for the :-! emote.    |
      /// | face-surprise    | The icon used for the :-0 emote.    |
      /// | face-tired       | The icon used for the \| ) emote.   |
      /// | face-uncertain   | The icon used for the :-/ emote.    |
      /// | face-wink        | The icon used for the ;-) emote.    |
      /// | face-worried     | The icon used for the :-S emote.    |
      /// @par The following table represents Standard MIME Type Icons :
      /// | Name    | Description                                                                                                                                                              |
      /// | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
      /// | flag-aa | The flag for the country with the ISO 3166 country code AA. All flags should use ISO 3166 two-letter country codes, in lowercase form, as the specifier for the country. |
      /// @par The following table represents Standard International Icons :
      /// | Name                     | Description                                                 |
      /// | ------------------------ | ----------------------------------------------------------- |
      /// | application-x-executable | The icon used for executable file types.                    |
      /// | audio-x-generic          | The icon used for generic audio file types.                 |
      /// | font-x-generic           | The icon used for generic font file types.                  |
      /// | image-x-generic          | The icon used for generic image file types.                 |
      /// | package-x-generic        | The icon used for generic package file types.               |
      /// | text-html                | The icon used for HTML text file types.                     |
      /// | text-x-generic           | The icon used for generic text file types.                  |
      /// | text-x-generic-template  | The icon used for generic text templates.                   |
      /// | text-x-script            | The icon used for script file types, such as shell scripts. |
      /// | video-x-generic          | The icon used for generic video file types.                 |
      /// | x-office-address-book    | The icon used for generic address book file types.          |
      /// | x-office-calendar        | The icon used for generic calendar file types.              |
      /// | x-office-contact         | The icon used for generic contact file types.               |
      /// | x-office-document        | The icon used for generic document and letter file types.   |
      /// | x-office-presentation    | The icon used for generic presentation file types.          |
      /// | x-office-spreadsheet     | The icon used for generic spreadsheet file types.           |
      /// @par The following table represents Standard Place Icons :
      /// | Name                | Description                                                                                                               |
      /// | ------------------- | ------------------------------------------------------------------------------------------------------------------------- |
      /// | folder              | The standard folder icon used to represent directories on local filesystems, mail folders, and other hierarchical groups. |
      /// | folder-activities   | The icon used for activities directory.                                                                                   |
      /// | folder-applications | The icon used for applications directory.                                                                                 |
      /// | folder-bookmark     | The icon used for bookmark directory.                                                                                     |
      /// | folder-cloud        | The icon used for cloud directory.                                                                                        |
      /// | folder-desktop      | The icon used for desktop directory.                                                                                      |
      /// | folder-development  | The icon used for develoment directory.                                                                                   |
      /// | folder-documents    | The icon used for documents directory.                                                                                    |
      /// | folder-download     | The icon used for download directory.                                                                                     |
      /// | folder-favoties     | The icon used for favorites directory.                                                                                    |
      /// | folder-games        | The icon used for games directory.                                                                                        |
      /// | folder-github       | The icon used for github directory.                                                                                       |
      /// | folder-home         | The icon used for home directory.                                                                                         |
      /// | folder-html         | The icon used for html directory.                                                                                         |
      /// | folder-images       | The icon used for images directory.                                                                                       |
      /// | folder-important    | The icon used for important directory.                                                                                    |
      /// | folder-locked       | The icon used for locked directory.                                                                                       |
      /// | folder-music        | The icon used for music directory.                                                                                        |
      /// | folder-network      | The icon used for network directory.                                                                                      |
      /// | folder-print        | The icon used for print directory.                                                                                        |
      /// | folder-public       | The icon used for public directory.                                                                                       |
      /// | folder-remote       | The icon used for normal directories on a remote filesystem.                                                              |
      /// | folder-system       | The icon used for system directory.                                                                                       |
      /// | folder-tar          | The icon used for tar directory.                                                                                          |
      /// | folder-temp         | The icon used for temp directory.                                                                                         |
      /// | folder-templates    | The icon used for templates directory.                                                                                    |
      /// | folder-text         | The icon used for text directory.                                                                                         |
      /// | folder-videos       | The icon used for videos directory.                                                                                       |
      /// | network-server      | The icon used for individual host machines under the "Network Servers" place in the file manager.                         |
      /// | network-workgroup   | The icon for the "Network Servers" place in the desktop's file manager, and workgroups within the network.                |
      /// | start-here          | The icon used by the desktop's main menu for accessing places, applications, and other features.                          |
      /// | user-bookmarks      | The icon for the user's special "Bookmarks" place.                                                                        |
      /// | user-desktop        | The icon for the special "Desktop" directory of the user.                                                                 |
      /// | user-home           | The icon for the special "Home" directory of the user.                                                                    |
      /// | user-trash          | The icon for the user's "Trash" place in the desktop's file manager.                                                      |
      /// @par The following table represents Standard Status Icons :
      /// | Name                      | Description                                                                                                                                                                                                                                                                                      |
      /// | ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
      /// | appointment-missed        | The icon used when an appointment was missed.                                                                                                                                                                                                                                                    |
      /// | appointment-soon          | The icon used when an appointment will occur soon.                                                                                                                                                                                                                                               |
      /// | audio-volume-high         | The icon used to indicate high audio volume.                                                                                                                                                                                                                                                     |
      /// | audio-volume-low          | The icon used to indicate low audio volume.                                                                                                                                                                                                                                                      |
      /// | audio-volume-medium       | The icon used to indicate medium audio volume.                                                                                                                                                                                                                                                   |
      /// | audio-volume-muted        | The icon used to indicate the muted state for audio playback.                                                                                                                                                                                                                                    |
      /// | battery-caution           | The icon used when the battery is below 40%.                                                                                                                                                                                                                                                     |
      /// | battery-low               | The icon used when the battery is below 20%.                                                                                                                                                                                                                                                     |
      /// | dialog-error              | The icon used when a dialog is opened to explain an error condition to the user.                                                                                                                                                                                                                 |
      /// | dialog-information        | The icon used when a dialog is opened to give information to the user that may be pertinent to the requested action.                                                                                                                                                                             |
      /// | dialog-password           | The icon used when a dialog requesting the authentication credentials for a user is opened.                                                                                                                                                                                                      |
      /// | dialog-question           | The icon used when a dialog is opened to ask a simple question of the user.                                                                                                                                                                                                                      |
      /// | dialog-warning            | The icon used when a dialog is opened to warn the user of impending issues with the requested action.                                                                                                                                                                                            |
      /// | folder-drag-accept        | The icon used for a folder while an object is being dragged onto it, that is of a type that the directory can contain.                                                                                                                                                                           |
      /// | folder-open               | The icon used for folders, while their contents are being displayed within the same window. This icon would normally be shown in a tree or list view, next to the main view of a folder's contents.                                                                                              |
      /// | folder-visiting           | The icon used for folders, while their contents are being displayed in another window. This icon would typically be used when using multiple windows to navigate the hierarchy, such as in Nautilus's spatial mode.                                                                              |
      /// | image-loading             | The icon used when another image is being loaded, such as thumnails for larger images in the file manager.                                                                                                                                                                                       |
      /// | image-missing             | The icon used when another image could not be loaded.                                                                                                                                                                                                                                            |
      /// | mail-attachment           | The icon used for an electronic mail that contains attachments.                                                                                                                                                                                                                                  |
      /// | mail-unread               | The icon used for an electronic mail that is unread.                                                                                                                                                                                                                                             |
      /// | mail-read                 | The icon used for an electronic mail that is read.                                                                                                                                                                                                                                               |
      /// | mail-replied              | The icon used for an electronic mail that has been replied to.                                                                                                                                                                                                                                   |
      /// | mail-signed               | The icon used for an electronic mail that contains a signature.                                                                                                                                                                                                                                  |
      /// | mail-signed-verified      | The icon used for an electronic mail that contains a signature which has also been verified by the security system.                                                                                                                                                                              |
      /// | media-playlist-repeat     | The icon for the repeat mode of a media player.                                                                                                                                                                                                                                                  |
      /// | media-playlist-shuffle    | The icon for the shuffle mode of a media player.                                                                                                                                                                                                                                                 |
      /// | network-error             | The icon used when an error occurs trying to intialize the network connection of the computing device. This icon should be two computers, one in the background, with the screens of both computers, colored black, and with the theme's style element for errors, overlayed on top of the icon. |
      /// | network-idle              | The icon used when no data is being transmitted or received, while the computing device is connected to a network. This icon should be two computers, one in the background, with the screens of both computers, colored black.                                                                  |
      /// | network-offline           | The icon used when the computing device is disconnected from the network. This icon should be a computer in the background, with a screen colored black, and the theme's icon element to show that a device is not accessible, in the foreground.                                                |
      /// | network-receive           | The icon used when data is being received, while the computing device is connected to a network. This icon should be two computers, one in the background, with its screen colored green, and the screen of the computer in the foreground, colored black.                                       |
      /// | network-transmit          | The icon used when data is being transmitted, while the computing device is connected to a network. This icon should be two computers, one in the background, with its screen colored black, and the screen of the computer in the foreground, colored green.                                    |
      /// | network-transmit-receive  | The icon used data is being both transmitted and received simultaneously, while the computing device is connected to a network. This icon should be two computers, one in the background, with the screens of both computers, colored green.                                                     |
      /// | printer-error             | The icon used when an error occurs while attempting to print. This icon should be the theme's printer device icon, with the theme's style element for errors, overlayed on top of the icon.                                                                                                      |
      /// | printer-printing          | The icon used while a print job is successfully being spooled to a printing device. This icon should be the theme's printer device icon, with a document emerging from the printing device.                                                                                                      |
      /// | security-high             | The icon used to indicate that the security level of a connection is known to be secure, using strong encryption and a valid certificate.                                                                                                                                                        |
      /// | security-medium           | The icon used to indicate that the security level of a connection is presumed to be secure, using strong encryption, and a certificate that could not be automatically verified, but which the user has chosen to trust.                                                                         |
      /// | security-low              | The icon used to indicate that the security level of a connection is presumed to be insecure, either by using weak encryption, or by using a certificate that the could not be automatically verified, and which the user has not chosent to trust.                                              |
      /// | software-update-available | The icon used when an update is available for software installed on the computing device, through the system software update program.                                                                                                                                                            |
      /// | software-update-urgent    | The icon used when an urgent update is available through the system software update program.                                                                                                                                                                                                     |
      /// | task-due                  | The icon used when a task is due soon.                                                                                                                                                                                                                                                           |
      /// | task-past-due             | The icon used when a task that was due, has been left incomplete.                                                                                                                                                                                                                                |
      /// | user-available            | The icon used when a user on a chat network is available to initiate a conversation with.                                                                                                                                                                                                        |
      /// | user-away                 | The icon used when a user on a chat network is away from their keyboard and the chat program.                                                                                                                                                                                                    |
      /// | user-idle                 | The icon used when a user on a chat network has not been an active participant in any chats on the network, for an extended period of time.                                                                                                                                                      |
      /// | user-offline              | The icon used when a user on a chat network is not available.                                                                                                                                                                                                                                    |
      /// | user-trash-full           | The icon for the user's "Trash" in the desktop's file manager, when there are items in the "Trash" waiting for disposal or recovery.                                                                                                                                                             |
      /// | weather-clear             | The icon used while the weather for a region is "clear skies".                                                                                                                                                                                                                                   |
      /// | weather-clear-night       | The icon used while the weather for a region is "clear skies" during the night.                                                                                                                                                                                                                  |
      /// | weather-few-clouds        | The icon used while the weather for a region is "partly cloudy".                                                                                                                                                                                                                                 |
      /// | weather-few-clouds-night  | The icon used while the weather for a region is "partly cloudy" during the night.                                                                                                                                                                                                                |
      /// | weather-fog               | The icon used while the weather for a region is "foggy".                                                                                                                                                                                                                                         |
      /// | weather-overcast          | The icon used while the weather for a region is "overcast".                                                                                                                                                                                                                                      |
      /// | weather-severe-alert      | The icon used while a sever weather alert is in effect for a region.                                                                                                                                                                                                                             |
      /// | weather-showers           | The icon used while rain showers are occurring in a region.                                                                                                                                                                                                                                      |
      /// | weather-showers-scattered | The icon used while scattered rain showers are occurring in a region.                                                                                                                                                                                                                            |
      /// | weather-snow              | The icon used while snow showers are occurring in a region.                                                                                                                                                                                                                                      |
      /// | weather-storm             | The icon used while storms are occurring in a region.                                                                                                                                                                                                                                            |
      /// @par The following table represents Standard xtd Icons :
      /// | Name                      | Description                        |
      /// | ------------------------- | ---------------------------------- |
      /// | gammasoft                 | The icon for Gammasoft logo.       |
      /// | xtd                       | The icon for xtd logo.             |
      /// | xtd-console               | The icon for xtd console logo.     |
      /// | xtd-forms                 | The icon for xtd forms logo.       |
      /// | xtd-console               | The icon for xtd console logo.     |
      /// | xtd-tunit                 | The icon for xtd tunit logo.       |
      /// | xtd-core                  | The icon for xtd core logo.        |
      /// | xtd-delegates             | The icon for xtd delegates logo.   |
      /// | xtd-diagnostics           | The icon for xtd diagnostics logo. |
      /// | xtd-drawing               | The icon for xtd drawing logo.     |
      /// | xtd-io                    | The icon for xtd io logo.          |
      /// | xtd-strings               | The icon for xtd strings logo.     |
      /// @remarks See [Icon Naming Specification](https://specifications.freedesktop.org/icon-naming-spec/icon-naming-spec-latest.html) for more information.
      static xtd::array<xtd::string> names(const xtd::string& context) noexcept;
      /// @brief Gets standard sizes for image.
      /// @return An xtd::drawing::size array that contains the default sizes for image.
      /// @remarks This method allows you to obtain the standard sizes for an image. If you choose another size, the image will be scaled.
      static xtd::array<xtd::drawing::size> sizes() noexcept;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @param name The system image name.
      /// @return An xtd::drawing::image object that contains the system image from specified name.
      /// @remarks The theme is the default system theme.
      /// @remarks The size is the default size (32 x 32).
      static xtd::drawing::image from_name(const xtd::string& name);
      /// @brief Gets system image from specified name and size.
      /// @param name The system image name.
      /// @param size The system image size in pixels.
      /// @return An xtd::drawing::image object that contains the system image from specified name.
      /// @remarks The theme is the default system theme.
      static xtd::drawing::image from_name(const xtd::string& name, const xtd::drawing::size& size);
      /// @brief Gets system image from specified them and name.
      /// @param theme The system image theme.
      /// @param name The system image name.
      /// @return An xtd::drawing::image object that contains the system image from specified name.
      /// @remarks The size is the default size in pixels (32 x 32).
      static xtd::drawing::image from_name(const xtd::string& theme, const xtd::string& name);
      /// @brief Gets system image from specified theme, name and size.
      /// @param theme The system image theme.
      /// @param name The system image name.
      /// @param size The system image size in pixels.
      /// @return An xtd::drawing::image object that contains the system image from specified name.
      static xtd::drawing::image from_name(const xtd::string& theme, const xtd::string& name, const xtd::drawing::size& size);
      /// @}
      
    private:
      // This method is only needed to disable the native::system::image::form_name function during unit testing.
      static bool native_system_images_from_name_enabled() noexcept {return __XTD_CURRENT_TARGET_ID__ != __XTD_TARGET_ID_TEST_APPLICATION__;}
      friend class system_icons;
      static xtd::string default_theme() noexcept;
      static xtd::string fallback_theme() noexcept;
      static xtd::array<xtd::string> themes() noexcept;
    };
  }
}

