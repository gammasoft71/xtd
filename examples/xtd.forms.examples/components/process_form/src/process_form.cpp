#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/button_images>
#include <xtd/forms/form>
#include <xtd/forms/vertical_layout_panel>
#include <xtd/diagnostics/process>
#include <xtd/invalid_operation_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;
using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    text("Process form example");
    controls().push_back(layout_panel);
    client_size({350, 540});
    
    layout_panel.controls().push_back_range({xtd_web_button, write_mail_button, open_home_folder_button, open_readme_txt_file_button, open_gammasoft_png_file_button, open_calculator_button});
    layout_panel.dock(dock_style::fill);
    layout_panel.control_layout_style(xtd_web_button, {size_type::auto_size, true});
    layout_panel.control_layout_style(write_mail_button, {size_type::auto_size, true});
    layout_panel.control_layout_style(open_home_folder_button, {size_type::auto_size, true});
    layout_panel.control_layout_style(open_readme_txt_file_button, {size_type::auto_size, true});
    layout_panel.control_layout_style(open_gammasoft_png_file_button, {size_type::auto_size, true});
    layout_panel.control_layout_style(open_calculator_button, {size_type::auto_size, true});
    
    xtd_web_button.image(button_images::from_name("text-html", drawing::size(64, 64)));
    xtd_web_button.image_align(content_alignment::middle_left);
    xtd_web_button.text("Open xtd website...");
    xtd_web_button.click += delegate_ {
      process::start(process_start_info {"https://gammasoft71.github.io/xtd"}.use_shell_execute(true));
    };
    
    write_mail_button.image(button_images::from_name("document-send", drawing::size(64, 64)));
    write_mail_button.image_align(content_alignment::middle_left);
    write_mail_button.text("Write mail...");
    write_mail_button.click += delegate_ {
      process::start(process_start_info {"mailto:gammasoft71@gmail.com?subject=Hi%20Gammasoft71&body=xtd%20is%20a%20great%20project.%0D%0A%20"}.use_shell_execute(true));
    };
    
    open_home_folder_button.image(button_images::from_name("folder-home", drawing::size(64, 64)));
    open_home_folder_button.image_align(content_alignment::middle_left);
    open_home_folder_button.text("Open home folder...");
    open_home_folder_button.click += delegate_ {
      process::start(process_start_info {environment::get_folder_path(environment::special_folder::home)}.use_shell_execute(true));
    };
    
    open_readme_txt_file_button.image(button_images::from_name("text-x-generic", drawing::size(64, 64)));
    open_readme_txt_file_button.image_align(content_alignment::middle_left);
    open_readme_txt_file_button.text("Open \"readme.txt\" file...");
    open_readme_txt_file_button.click += delegate_ {
      file::write_all_text(path::combine(path::get_temp_path(), "readme.txt"), "Tests open file \"readme.txt\" with xtd::diagnostics::process class.\n");
      process::start(process_start_info {path::combine(path::get_temp_path(), "readme.txt")}.use_shell_execute(true));
    };
    
    open_gammasoft_png_file_button.image(button_images::from_name("image-x-generic", drawing::size(64, 64)));
    open_gammasoft_png_file_button.image_align(content_alignment::middle_left);
    open_gammasoft_png_file_button.text("Open \"gammasoft.png\" file...");
    open_gammasoft_png_file_button.click += delegate_ {
      images::from_name("gammasoft", drawing::size(512, 512)).save(path::combine(path::get_temp_path(), "gammasoft.png"));
      process::start(process_start_info {"gammasoft.png"}.working_directory(path::get_temp_path()).use_shell_execute(true));
    };
    
    open_calculator_button.image(button_images::from_name("accessories-calculator", drawing::size(64, 64)));
    open_calculator_button.image_align(content_alignment::middle_left);
    open_calculator_button.text("Launch Calculator...");
    open_calculator_button.click += delegate_ {
      if (environment::os_version().is_windows()) process::start(process_start_info {"calc"});
      else if (environment::os_version().is_macos()) process::start(process_start_info {"Calculator"}.use_shell_execute(true));
      else if (environment::os_version().is_linux()) process::start(process_start_info {"gnome-calculator"});
      else throw invalid_operation_exception("Calculator application unknown.");
    };
  }
  
private:
  vertical_layout_panel layout_panel;
  button xtd_web_button;
  button write_mail_button;
  button open_home_folder_button;
  button open_readme_txt_file_button;
  button open_gammasoft_png_file_button;
  button open_calculator_button;
};

auto main() -> int {
  xtd::forms::application::run(main_form());
}
