#if defined(__APPLE__)
#include <xtd/strings.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/dialog_box_identifiers.h>
#include <xtd/forms/native/message_box.h>
#include <xtd/forms/native/message_box_styles.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
  static int convert_to_dialog_rsult(uint32_t style, NSModalResponse return_code) {
    int result = IDOK;
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) result = return_code == NSAlertFirstButtonReturn ? IDRETRY : IDCANCEL;
    else if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) result = return_code == NSAlertFirstButtonReturn ? IDYES : (return_code == NSAlertSecondButtonReturn ? IDNO : IDCANCEL);
    else if ((style & MB_YESNO) == MB_YESNO) result = return_code == NSAlertFirstButtonReturn ? IDYES : IDNO;
    else if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) result = return_code == NSAlertFirstButtonReturn ? IDABORT : (return_code == NSAlertSecondButtonReturn ? IDRETRY : IDIGNORE);
    else if ((style & MB_OKCANCEL) == MB_OKCANCEL) result = return_code == NSAlertFirstButtonReturn ? IDOK : IDCANCEL;
    return result;
  }

  static NSAlertStyle convert_to_icon(uint32_t style) {
    if ((style & MB_ICONINFORMATION) == MB_ICONINFORMATION) return NSAlertStyleInformational;
    if ((style & MB_ICONEXCLAMATION) == MB_ICONEXCLAMATION) return NSAlertStyleCritical;
    if ((style & MB_ICONQUESTION) == MB_ICONQUESTION) return NSAlertStyleInformational;
    if ((style & MB_ICONSTOP) == MB_ICONSTOP) return NSAlertStyleCritical;
    return NSAlertStyleWarning;
  }
  
  static NSAlert* create_alert(const ustring& text, const ustring& caption, uint32_t style, bool display_help_button) {
    NSAlert* alert = [[NSAlert alloc] init];
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) {
      [alert addButtonWithTitle:@"Retry"];
      [alert addButtonWithTitle:@"Cancel"];
    } else if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) {
      [alert addButtonWithTitle:@"Yes"];
      [alert addButtonWithTitle:@"No"];
      [alert addButtonWithTitle:@"Cancel"];
    } else if ((style & MB_YESNO) == MB_YESNO) {
      [alert addButtonWithTitle:@"Yes"];
      [alert addButtonWithTitle:@"No"];
    } else if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) {
      [alert addButtonWithTitle:@"Abort"];
      [alert addButtonWithTitle:@"Retry"];
      [alert addButtonWithTitle:@"Ignore"];
    } else if ((style & MB_OKCANCEL) == MB_OKCANCEL) {
      [alert addButtonWithTitle:@"OK"];
      [alert addButtonWithTitle:@"Cancel"];
    } else [alert addButtonWithTitle:@"OK"];
    [alert setMessageText:[NSString stringWithUTF8String:caption.c_str()]];
    [alert setInformativeText:[NSString stringWithUTF8String:text.c_str()]];
    [alert setAlertStyle:convert_to_icon(style)];
    if (display_help_button)
      [alert setShowsHelp:YES];
    
    if (NSApp == nullptr) {
      [NSApplication sharedApplication];
      [NSApp finishLaunching];
      [NSApp activateIgnoringOtherApps:YES];
    }
    return alert;
  }
}

int32_t message_box::show(intptr_t control, const ustring& text, const ustring& caption, uint32_t style, bool display_help_button) {
  @autoreleasepool {
    NSAlert* alert = create_alert(text, caption, style, display_help_button);
    return convert_to_dialog_rsult(style, [alert runModal]);
  }
}

void message_box::show_sheet(xtd::delegate<void(int32_t)> on_dialog_closed, intptr_t control, const ustring& text, const ustring& caption, uint32_t style, bool display_help_button) {
  @autoreleasepool {
    NSAlert *alert = create_alert(text, caption, style, display_help_button);
    [alert beginSheetModalForWindow:[reinterpret_cast<control_handler*>(control)->control()->GetHandle() window] completionHandler:^(NSModalResponse return_code) {
      on_dialog_closed(convert_to_dialog_rsult(style, return_code));
    }];
  }
}
#endif
