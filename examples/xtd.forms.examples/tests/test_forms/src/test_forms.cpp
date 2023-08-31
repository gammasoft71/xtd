#include <xtd/diagnostics/process>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/text_box>
#include <xtd/environment>
#include <xtd/startup>

class virtual_console : public xtd::forms::text_box {
public:
  virtual_console()  {
    xtd::environment::current_directory(xtd::environment::get_folder_path(xtd::environment::special_folder::home));
    prompt = xtd::ustring::format("[{}] $ ", xtd::environment::current_directory());
    
    multiline(true);
    back_color(default_back_color());
    font(default_font());
    fore_color(default_fore_color());
    text(prompt);
    select(text().size() - 1, 0);
  }
  
protected:
  xtd::drawing::color default_back_color() const noexcept override {return xtd::drawing::color::black;}
  xtd::drawing::font default_font() const noexcept override {return xtd::drawing::font(xtd::drawing::font_family::generic_monospace(), 10);}
  xtd::drawing::color default_fore_color() const noexcept override {return xtd::drawing::color::lime;}
  xtd::drawing::size default_size() const noexcept override {return {300, 200};}
  
  void on_key_down(xtd::forms::key_event_args& e) override {
    switch (e.key_code()) {
      case xtd::forms::keys::down: key_down_pressed(e); break;
      case xtd::forms::keys::up: key_up_pressed(e); break;
      case xtd::forms::keys::enter: key_enter_pressed(e); break;
      default: break;
    }
    text_box::on_key_down(e);
  }
  
private:
  xtd::ustring get_command() const {
    auto pos = text().last_index_of(prompt);
    if (pos != xtd::ustring::npos) {
      pos += prompt.size();
      return text().substring(pos);
    }
    return "";
  }
  
  void key_down_pressed(xtd::forms::key_event_args& e) {
    e.handled(true);
  }
  void key_up_pressed(xtd::forms::key_event_args& e) {
    e.handled(true);
  }
  void key_enter_pressed(xtd::forms::key_event_args& e) {
    auto command_line = get_command();
    if (!command_line.empty()) {
      xtd::diagnostics::process_start_info start_info;
      try {
        auto args = command_line.split({' '});
        start_info.file_name(args[0]);
        if (args.size() > 1)
          start_info.arguments(xtd::ustring::join(" ", std::vector<xtd::ustring>(args.begin() + 1, args.end())));
          
        append_text(xtd::environment::new_line());
        start_info.use_shell_execute(false);
        start_info.redirect_standard_error(true);
        start_info.redirect_standard_output(true);
        
        if (start_info.file_name() == "cd" && !start_info.arguments().empty()) {
          if (xtd::io::directory::exists(start_info.arguments())) {
            xtd::environment::current_directory(start_info.arguments());
            prompt = xtd::ustring::format("[{}] $ ",  xtd::environment::current_directory());
          } else {
            append_text(xtd::ustring::format("cd: no such file or directory: {}", start_info.arguments()));
            append_text(xtd::environment::new_line());
          }
        } else {
          xtd::diagnostics::process process;
          process.start_info(start_info);
          process.start();
          std::istream& standard_error = process.standard_error();
          std::istream& standard_output = process.standard_output();
          
          xtd::io::stream_reader error_reader(standard_error);
          while (!error_reader.end_of_stream()) {
            append_text(error_reader.read_line());
            append_text(xtd::environment::new_line());
          }
          
          xtd::io::stream_reader output_reader(standard_output);
          while (!output_reader.end_of_stream()) {
            append_text(output_reader.read_line());
            append_text(xtd::environment::new_line());
          }
        }
      } catch (...) {
        append_text(xtd::ustring::format("command not found: {}", start_info.file_name()));
        append_text(xtd::environment::new_line());
      }
    }
    append_text(xtd::environment::new_line());
    append_text(prompt);
    e.handled(true);
  }
  xtd::ustring prompt = xtd::ustring::format("[{}] $ ",  xtd::environment::current_directory());
  std::vector<xtd::ustring> commands;
};

using namespace xtd;
using namespace xtd::windows::forms;

class form_main : public form {
public:
  static auto main() {
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

startup_(form_main::main);
