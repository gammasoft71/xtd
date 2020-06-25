#if defined(__APPLE__)
#include <xtd/xtd.strings>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/message_box.h>
#include <xtd/forms/native/message_box_styles.h>
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
  constexpr int32_t MB_BUTTONS_MASK = 0x7;
  constexpr int32_t MB_ICON_MASK = 0x70;

  static void message_box_add_buttons_ok(NSAlert *alert) {
    [alert addButtonWithTitle:@"OK"];
  }
  
  static void message_box_add_buttons_ok_cancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"OK"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  static void message_box_add_buttons_abort_retry_ignore(NSAlert *alert) {
    [alert addButtonWithTitle:@"Abort"];
    [alert addButtonWithTitle:@"Retry"];
    [alert addButtonWithTitle:@"Ignore"];
  }
  
  static void message_box_add_buttons_yes_no_cancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"Yes"];
    [alert addButtonWithTitle:@"No"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  static void message_box_add_buttons_yes_no(NSAlert *alert) {
    [alert addButtonWithTitle:@"Yes"];
    [alert addButtonWithTitle:@"No"];
  }
  
  static void message_box_add_buttons_retry_cancel(NSAlert *alert) {
    [alert addButtonWithTitle:@"Retry"];
    [alert addButtonWithTitle:@"Cancel"];
  }
  
  static int32_t message_box_show_modal_ok(NSAlert *alert) {
    [alert runModal];
    return IDOK;
  }
  
  static int32_t message_box_show_modal_ok_cancel(NSAlert *alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? IDOK : IDCANCEL;
  }
  
  static int32_t message_box_show_modal_abort_retry_ignore(NSAlert *alert) {
    NSModalResponse result = [alert runModal];
    if (result == NSAlertFirstButtonReturn)
      return IDABORT;
    if (result == NSAlertSecondButtonReturn)
      return IDRETRY;
    return IDIGNORE;
  }
  
  static int32_t message_box_show_modal_yes_no_cancel(NSAlert *alert) {
    NSModalResponse result = [alert runModal];
    if (result == NSAlertFirstButtonReturn)
      return IDYES;
    if (result == NSAlertSecondButtonReturn)
      return IDNO;
    return IDCANCEL;
  }
  
  static int32_t message_box_show_modal_yes_no(NSAlert* alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? IDYES : IDNO;
  }
  
  static int32_t message_box_show_modal_retry_cancel(NSAlert* alert) {
    return [alert runModal] == NSAlertFirstButtonReturn ? IDRETRY : IDCANCEL;
  }

  static void add_buttons(uint32_t style, NSAlert* alert) {
    if ((style & MB_BUTTONS_MASK) == MB_RETRYCANCEL) message_box_add_buttons_retry_cancel(alert);
    else if ((style & MB_BUTTONS_MASK) == MB_YESNOCANCEL) message_box_add_buttons_yes_no_cancel(alert);
    else if ((style & MB_BUTTONS_MASK) == MB_YESNO) message_box_add_buttons_yes_no(alert);
    else if ((style & MB_BUTTONS_MASK) == MB_ABORTRETRYIGNORE) message_box_add_buttons_abort_retry_ignore(alert);
    else if ((style & MB_BUTTONS_MASK) == MB_OKCANCEL) message_box_add_buttons_ok_cancel(alert);
    else message_box_add_buttons_ok(alert);
  }
  
  static NSAlertStyle convert_to_icon(int32_t style) {
    if ((style & MB_ICON_MASK) == MB_ICONINFORMATION) return NSAlertStyleInformational;
    if ((style & MB_ICON_MASK) == MB_ICONEXCLAMATION) return NSAlertStyleCritical;
    if ((style & MB_ICON_MASK) == MB_ICONQUESTION) return NSAlertStyleInformational;
    if ((style & MB_ICON_MASK) == MB_ICONSTOP) return NSAlertStyleCritical;
    return NSAlertStyleWarning;
  }

  static int32_t show_modal(int32_t style, NSAlert* alert) {
    if ((style & MB_BUTTONS_MASK) == MB_RETRYCANCEL) return message_box_show_modal_retry_cancel(alert);
    if ((style & MB_BUTTONS_MASK) == MB_YESNOCANCEL) return message_box_show_modal_yes_no_cancel(alert);
    if ((style & MB_BUTTONS_MASK) == MB_YESNO) return message_box_show_modal_yes_no(alert);
    if ((style & MB_BUTTONS_MASK) == MB_ABORTRETRYIGNORE) return message_box_show_modal_abort_retry_ignore(alert);
    if ((style & MB_BUTTONS_MASK) == MB_OKCANCEL) return message_box_show_modal_ok_cancel(alert);
    return message_box_show_modal_ok(alert);
  }
}

int32_t message_box::show(intptr_t control, const std::string& text, const std::string& caption, uint32_t style, bool displayHelpButton) {
  @autoreleasepool {
    NSAlert *alert = [[NSAlert alloc] init];
    add_buttons(style, alert);
    [alert setMessageText:[NSString stringWithUTF8String:caption.c_str()]];
    [alert setInformativeText:[NSString stringWithUTF8String:text.c_str()]];
    [alert setAlertStyle:convert_to_icon(style)];
    if (displayHelpButton)
      [alert setShowsHelp:YES];
    
    if (NSApp == nullptr) {
      [NSApplication sharedApplication];
      [NSApp finishLaunching];
      [NSApp activateIgnoringOtherApps:YES];
    }
    
    return show_modal(style, alert);
  }
}
#endif
