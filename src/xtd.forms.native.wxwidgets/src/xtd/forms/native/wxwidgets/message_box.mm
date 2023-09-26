#if defined(__WXOSX__)
#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler"
#include <xtd/forms/native/application>
#include <xtd/forms/native/dialog_box_identifiers>
#include <xtd/forms/native/message_box>
#include <xtd/forms/native/message_box_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

using namespace xtd;
using namespace xtd::forms::native;

namespace {
  static int32 convert_to_dialog_rsult(uint32 style, NSModalResponse return_code) {
    int32 result = IDOK;
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) result = return_code == NSAlertFirstButtonReturn ? IDRETRY : IDCANCEL;
    else if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) result = return_code == NSAlertFirstButtonReturn ? IDYES : (return_code == NSAlertSecondButtonReturn ? IDNO : IDCANCEL);
    else if ((style & MB_YESNO) == MB_YESNO) result = return_code == NSAlertFirstButtonReturn ? IDYES : IDNO;
    else if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) result = return_code == NSAlertFirstButtonReturn ? IDABORT : (return_code == NSAlertSecondButtonReturn ? IDRETRY : IDIGNORE);
    else if ((style & MB_OKCANCEL) == MB_OKCANCEL) result = return_code == NSAlertFirstButtonReturn ? IDOK : IDCANCEL;
    return result;
  }
  
  static NSAlertStyle convert_to_icon(uint32 style) {
    if ((style & MB_ICONINFORMATION) == MB_ICONINFORMATION) return NSAlertStyleInformational;
    if ((style & MB_ICONEXCLAMATION) == MB_ICONEXCLAMATION) return NSAlertStyleCritical;
    if ((style & MB_ICONQUESTION) == MB_ICONQUESTION) return NSAlertStyleInformational;
    if ((style & MB_ICONSTOP) == MB_ICONSTOP) return NSAlertStyleCritical;
    return NSAlertStyleWarning;
  }
  
  static NSAlert* create_alert(const ustring& text, const ustring& caption, uint32 style, bool display_help_button) {
    NSAlert* alert = [[NSAlert alloc] init];
    if ((style & MB_RETRYCANCEL) == MB_RETRYCANCEL) {
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Retry"_t]];
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Cancel"_t]];
    } else if ((style & MB_YESNOCANCEL) == MB_YESNOCANCEL) {
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Yes"_t]];
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"No"_t]];
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Cancel"_t]];
    } else if ((style & MB_YESNO) == MB_YESNO) {
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Yes"_t]];
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"No"_t]];
    } else if ((style & MB_ABORTRETRYIGNORE) == MB_ABORTRETRYIGNORE) {
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Abort"_t]];
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Retry"_t]];
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Ignore"_t]];
    } else if ((style & MB_OKCANCEL) == MB_OKCANCEL) {
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"OK"_t]];
      [alert addButtonWithTitle:[NSString stringWithUTF8String:"Cancel"_t]];
    } else [alert addButtonWithTitle:[NSString stringWithUTF8String:"OK"_t]];
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

int32 message_box::show(intptr control, const ustring& text, const ustring& caption, uint32 style, bool display_help_button) {
  @autoreleasepool {
    NSAlert* alert = create_alert(text, caption, style, display_help_button);
    return convert_to_dialog_rsult(style, [alert runModal]);
  }
}

void message_box::show_sheet(xtd::delegate<void(int32)> on_dialog_closed, intptr control, const ustring& text, const ustring& caption, uint32 style, bool display_help_button) {
  @autoreleasepool {
    NSAlert* alert = create_alert(text, caption, style, display_help_button);
    [alert beginSheetModalForWindow:[reinterpret_cast<control_handler*>(control)->control()->GetHandle() window] completionHandler: ^ (NSModalResponse return_code) {
            on_dialog_closed(convert_to_dialog_rsult(style, return_code));
          }];
  }
}
#endif
