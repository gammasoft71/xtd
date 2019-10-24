#if !defined(_WIN32)
#include <unistd.h>
#endif
#include <xtd/environment.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/window_messages.hpp>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Icon.H>

using namespace std;
using namespace xtd;
using namespace xtd::forms::native;

namespace {
  bool restart_asked = false;
  bool initialized = false;

  int fltk_handler(int event) {
    return event == FL_SHORTCUT && Fl::event_key() == FL_Escape;
  }
}

bool application::allow_quit() {
  initialize(); // Must be first
  return true;
}

void application::cleanup() {
  if (initialized == true) {
    Fl::remove_handler(&fltk_handler);
    initialized = false;
  }
}

void application::do_events() {
  initialize(); // Must be first
  Fl::wait();
}

void application::do_idle() {
}

void application::enable_visual_style() {
  initialize(); // Must be first
  if (Fl::scheme() == nullptr) Fl::scheme("gtk+");
}

void application::exit() {
  _exit(0);
}

void application::initialize() {
  if (initialized == false) {
    FL_NORMAL_SIZE = 12;
    Fl::get_system_colors();
    Fl_File_Icon::load_system_icons();
    Fl::add_handler(&fltk_handler);
    Fl::scheme(nullptr);

    // This hack is used to to prevent run method to exit when last form is closed...
    //static Fl_Window form_hidden(1000, 10000, 0, 0, nullptr);
    //form_hidden.show();

    initialized = true;
  }
}

void application::register_message_filter(const delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& message_filter_proc) {
  initialize(); // Must be first
}

void application::register_wnd_proc(const delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>& wnd_proc) {
  initialize(); // Must be first
}

void application::restart() {
  restart_asked = true;
}

void application::run() {
  initialize(); // Must be first
  
  Fl::run();
  
  if (restart_asked) {
    std::vector<string> command_line_args = environment::get_command_line_args();
    char** argv = new char*[command_line_args.size() + 1];
    for(int index = 0; index <command_line_args.size(); index++)
      argv[index] = command_line_args[index].data();
    argv[command_line_args.size()] = 0;
    execv(argv[0], argv);
    delete [] argv;
    _Exit(0);
  }
}
