#if !defined(__APPLE__)
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#include <xtd/native/assert_dialog_results.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <iostream>
#include <syslog.h>
#include <gtk/gtk.h>

using namespace xtd::native;

int32_t debug::show_assert_dialog(const std::string& text, const std::string& caption) {
  gtk_init_check(0, nullptr);
  auto dialog = gtk_message_dialog_new(nullptr, GtkDialogFlags::GTK_DIALOG_MODAL, GtkMessageType::GTK_MESSAGE_ERROR, GtkButtonsType::GTK_BUTTONS_NONE, "%s", text.c_str());
  gtk_window_set_title(GTK_WINDOW(dialog), caption.c_str());
  gtk_dialog_add_button(GTK_DIALOG(dialog), "&Abort", GTK_RESPONSE_YES);
  gtk_dialog_add_button(GTK_DIALOG(dialog), "&Retry", GTK_RESPONSE_NO);
  gtk_dialog_add_button(GTK_DIALOG(dialog), "&Ignore", GTK_RESPONSE_CANCEL);
  auto return_code = gtk_dialog_run(GTK_DIALOG(dialog));
  return return_code == GTK_RESPONSE_YES ? ADR_ABORT : (return_code == GTK_RESPONSE_NO ? ADR_RETRY : ADR_IGNORE);
}

void debug::write_to_output(const std::string& message) {
  syslog(LOG_EMERG | LOG_USER, "%s", message.c_str());
  std::cerr << message << std::flush;
}
#endif
