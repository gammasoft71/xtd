#if !defined(__APPLE__)
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#include <xtd/native/assert_dialog_results>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <syslog.h>
#include <unistd.h>
#include <gtk/gtk.h>

using namespace xtd::native;

namespace {
  std::string get_process_name(pid_t pid) {
    std::ifstream stat_file("/proc/" + std::to_string(pid) + "/status");
    if (!stat_file) return "Unknown";
    
    std::string line;
    getline(stat_file, line);
    size_t start = line.find("Name:\t") + 1;
    
    if (start == std::string::npos) return "Unknown";
    start += std::string {"Name:\t"}.size() - 1;
    return line.substr(start, line.size() - start);
  }
}

void debugger::debug_break() {
  std::abort();
}

bool debugger::is_attached() {
  auto parent_process_name = get_process_name(getppid());
  return parent_process_name == "gdb" || parent_process_name == "lldb";
}

bool debugger::is_logging() {
  return true;
}

bool debugger::launch() {
  return true;
}

int_least32_t debugger::show_assert_dialog(const std::string& text, const std::string& caption) {
  gtk_init_check(0, nullptr);
  auto dialog = gtk_message_dialog_new(nullptr, GtkDialogFlags::GTK_DIALOG_MODAL, GtkMessageType::GTK_MESSAGE_ERROR, GtkButtonsType::GTK_BUTTONS_NONE, "%s", text.c_str());
  gtk_window_set_title(GTK_WINDOW(dialog), caption.c_str());
  gtk_dialog_add_button(GTK_DIALOG(dialog), "Abort", GTK_RESPONSE_YES);
  gtk_dialog_add_button(GTK_DIALOG(dialog), "Retry", GTK_RESPONSE_NO);
  gtk_dialog_add_button(GTK_DIALOG(dialog), "Ignore", GTK_RESPONSE_CANCEL);
  auto return_code = gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_hide(dialog);
  return return_code == GTK_RESPONSE_YES ? ADR_ABORT : (return_code == GTK_RESPONSE_NO ? ADR_RETRY : ADR_IGNORE);
}

void debugger::log(int_least32_t level, const std::string& category, const std::string& message) {
  syslog(LOG_EMERG | LOG_USER, "%s", message.c_str());
  std::cerr << message << std::flush;
}
#endif
