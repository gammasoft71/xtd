#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::io;
using namespace xtd::windows::forms;

class virtual_console : public text_box {
public:
  virtual_console()  {
    environment::current_directory(environment::get_folder_path(environment::special_folder::home));
    prompt = ustring::format("[{}] $ ",  environment::current_directory());
    
    multiline(true);
    back_color(default_back_color());
    font(default_font());
    fore_color(default_fore_color());
    text(prompt);
    select(text().size() - 1, 0);
  }
  
protected:
  xtd::drawing::color default_back_color() const override {return color::black;}
  xtd::drawing::font default_font() const override {return drawing::font(font_family::generic_monospace(), 10);}
  xtd::drawing::color default_fore_color() const override {return color::lime;}
  xtd::drawing::size default_size() const override {return {300, 200};}

  void on_key_down(key_event_args& e) override {
    switch(e.key_code()) {
      case xtd::forms::keys::down: key_down_pressed(e); break;
      case xtd::forms::keys::up: key_up_pressed(e); break;
      case xtd::forms::keys::enter: key_enter_pressed(e); break;
      default: break;
    }
    text_box::on_key_down(e);
  }
  
private:
  ustring get_command() const {
    auto pos = text().last_index_of(prompt);
    if (pos != ustring::npos) {
      pos += prompt.size();
      return text().substring(pos);
    }
    return "";
  }
  
  void key_down_pressed(key_event_args& e) {
    e.handled(true);
  }
  void key_up_pressed(key_event_args& e) {
    e.handled(true);
  }
  void key_enter_pressed(key_event_args& e) {
    auto command_line = get_command();
    if (!command_line.empty()) {
      process_start_info start_info;
      try {
        auto args = command_line.split({' '});
        start_info.file_name(args[0]);
        if (args.size() > 1)
          start_info.arguments(ustring::join(" ", std::vector<ustring>(args.begin() + 1, args.end())));
        
        append_text(environment::new_line());
        start_info.use_shell_execute(false);
        start_info.redirect_standard_error(true);
        start_info.redirect_standard_output(true);

        process proc;
        proc.start_info(start_info);
        proc.start();
        istream& standard_error = proc.standard_error();
        istream& standard_output = proc.standard_output();

        stream_reader error_reader(standard_error);
        while (!error_reader.end_of_stream()) {
          append_text(error_reader.read_line());
          append_text(environment::new_line());
        }

        stream_reader output_reader(standard_output);
        while (!output_reader.end_of_stream()) {
          append_text(output_reader.read_line());
          append_text(environment::new_line());
        }
        
        if (start_info.file_name() == "cd" && !start_info.arguments().empty()) {
          environment::current_directory(start_info.arguments());
          prompt = ustring::format("[{}] $ ",  environment::current_directory());
        }
      } catch(...) {
        append_text(ustring::format("command not found: {}", start_info.file_name()));
        append_text(environment::new_line());
      }
    }
    append_text(environment::new_line());
    append_text(prompt);
    e.handled(true);
  }
  ustring prompt = ustring::format("[{}] $ ",  environment::current_directory());
  vector<ustring> commands;
};

class form_main : public form {
public:
  static void main() {
    application::run(form_main());
  }
  
  form_main() {
    text("Virtual console");
    client_size({600, 600});
    
    virtual_console.dock(dock_style::fill);
    virtual_console.parent(*this);
  }
  
private:
  class virtual_console virtual_console;
};

startup_(form_main);

