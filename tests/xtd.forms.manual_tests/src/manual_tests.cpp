#include <xtd/drawing/drawing_2d/graphics_path>
#include <xtd/drawing/pens>
#include <xtd/drawing/region>
#include <xtd/drawing/system_icons>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/group_box>
#include <xtd/forms/horizontal_layout_panel>
#include <xtd/forms/label>
#include <xtd/forms/message_box>
#include <xtd/forms/message_notifier>
#include <xtd/forms/numeric_up_down>
#include <xtd/forms/panel>
#include <xtd/forms/picture_box>
#include <xtd/forms/progress_bar>
#include <xtd/forms/status_bar>
#include <xtd/forms/text_box>
#include <xtd/forms/timer>
#include <xtd/forms/vertical_layout_panel>
#include <xtd/startup>
#include <xtd/diagnostics/debug>
#include <xtd/chrono>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Status bar example");
      client_size({ 820, 500 });
      //status_bar(status_bar1);
      
      text_box1.multiline(true);
      text_box1.read_only(true);
      text_box1.parent(*this);
      text_box1.dock(dock_style::fill);
      
      status_bar1.parent(*this);
      status_bar1.panels().push_back_range({ status_bar_panel1, status_bar_panel2, status_bar_panel3, status_bar_panel4 });
      //status_bar1.sizing_grip(false);
      status_bar1.show_panels(true);
      status_bar1.text("Shows status information without panels...");
      
      status_bar_panel1.auto_size(xtd::forms::status_bar_panel_auto_size::contents);
      status_bar_panel1.border_style(xtd::forms::status_bar_panel_border_style::sunken);
      status_bar_panel1.tool_tip_text("Status one tool tip text");
      
      status_bar_panel2.auto_size(xtd::forms::status_bar_panel_auto_size::contents);
      status_bar_panel2.border_style(xtd::forms::status_bar_panel_border_style::sunken);
      
      status_bar_panel3.auto_size(xtd::forms::status_bar_panel_auto_size::spring);
      status_bar_panel3.border_style(xtd::forms::status_bar_panel_border_style::sunken);
      
      status_bar_panel4.auto_size(xtd::forms::status_bar_panel_auto_size::contents);
      status_bar_panel4.border_style(xtd::forms::status_bar_panel_border_style::sunken);
      
      timer1.interval_milliseconds(50);
      timer1.tick += [&] {
        progress_bar1.value(progress_bar1.value() < progress_bar1.maximum() ? progress_bar1.value() + 1 : progress_bar1.minimum());
      };
      timer1.enabled(true);
    }
    
  private:
    static image image_from_color(const color& color) {
      bitmap bitmap(16, 16);
      auto g = graphics::from_image(bitmap);
      g.fill_ellipse(solid_brush(color), 0, 0, bitmap.width(), bitmap.height());
      g.draw_ellipse(pens::black(), 0, 0, bitmap.width() - 1, bitmap.height() - 1);
      return bitmap;
    }
    
    text_box text_box1;
    forms::status_bar status_bar1;
    status_bar_panel status_bar_panel1 = status_bar_panel::create_panel("Status one", image_from_color(color::light_green));
    status_bar_panel status_bar_panel2 = status_bar_panel::create_panel("Status two");
    status_bar_panel status_bar_panel3 = status_bar_panel::create_panel("Status three");
    timer timer1;
    progress_bar progress_bar1;
    status_bar_panel status_bar_panel4 = status_bar_panel::create_control(progress_bar1);
  };
  
  using namespace std::literals;
  class form2 : public form {
  public:
    form2() {
      text("Message notifier example");
      
      button1.parent(*this);
      button1.location({ 10, 10 });
      button1.text("Notify");
      button1.click += [&] {
        message_notifier1.show();
      };
      
      message_notifier1.buttons().push_back_range({ start_message_notifier_button, cancel_message_notifier_button });
      message_notifier1.close_timeout_enabled(true);
      message_notifier1.close_timeout_interval(2s);
      message_notifier1.icon(xtd::drawing::system_icons::question());
      message_notifier1.message("Start the auto backup now. Note that once the backup is started, you can't cancel until its done.");
      message_notifier1.notifier_style(notifier_style::standard);
      message_notifier1.title("Backup");
      message_notifier1.button_click += {*this, & form2::on_message_notifier_button_click};
    }
    
  private:
  
    void on_message_notifier_button_click(object& sender, const notifier_button_click_event_args& e) {
      if (e.button() == start_message_notifier_button)
        diagnostics::debug::write_line("Start backup");
      else
        diagnostics::debug::write_line("Cancel backup");
    }
    
    button button1;
    message_notifier_button start_message_notifier_button{ "&Start" };
    message_notifier_button cancel_message_notifier_button{ "&Cancel" };
    message_notifier message_notifier1;
  };
  
  // Example of notification form with layout...
  class form3 : public form {
  public:
    form3() {
      client_size({ 300, button1.height() + button2.height() + 10 });
      form_border_style(forms::form_border_style::none);
      padding(forms::padding(5));
      start_position(xtd::forms::form_start_position::manual);
      top_most(true);
      
      /// Set round rectangle form :
      drawing::drawing_2d::graphics_path path;
      path.add_rounded_rectangle(client_rectangle(), 7);
      region(drawing::region(path));
      
      // Top right screen location :
      location({ screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().top() + 5 });
      
      // Bottom right screen location :
      //location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().bottom() - client_size().height() - 5});
      
      layout_panel1.controls().push_back_range({ panel1, layout_panel2 });
      layout_panel1.control_layout_style(panel1, { 1.0f, size_type::percent, true });
      layout_panel1.control_layout_style(layout_panel2, { 75, size_type::absolute });
      layout_panel1.dock(dock_style::fill);
      layout_panel1.parent(*this);
      
      panel1.padding(forms::padding(5));
      
      label1.parent(panel1);
      label1.dock(dock_style::fill);
      
      // The following text is wrapped in label :
      label1.text("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. Curabitur eu amet.");
      
      layout_panel2.controls().push_back_range({ button1, button2 });
      
      button1.text("Ok");
      button1.click += [&] {
        close();
      };
      
      button2.text("Cancel");
      button2.click += [&] {
        close();
      };
    };
    
  private:
    horizontal_layout_panel layout_panel1;
    panel panel1;
    label label1;
    vertical_layout_panel layout_panel2;
    button button1;
    button button2;
  };
  
  // Example of notification form with docking...
  class form4 : public form {
  public:
    form4() {
      controls().push_back_range({ panel1, panel2 });
      client_size({ 300, button1.height() + button2.height() + 10 });
      form_border_style(forms::form_border_style::none);
      start_position(xtd::forms::form_start_position::manual);
      top_most(true);
      
      /// Set round rectangle form :
      drawing::drawing_2d::graphics_path path;
      path.add_rounded_rectangle(client_rectangle(), 7);
      region(drawing::region(path));
      
      // Top right screen location :
      location({ screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().top() + 5 });
      
      // Bottom right screen location :
      //location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().bottom() - client_size().height() - 5});
      
      panel1.controls().push_back(label1);
      panel1.dock(dock_style::fill);
      panel1.parent(*this);
      panel1.padding(forms::padding(5));
      
      label1.dock(dock_style::fill);
      
      // The following text is wrapped in label :
      label1.text("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. Curabitur eu amet.");
      
      panel2.controls().push_back_range({ button2, button1 });
      panel2.dock(dock_style::right);
      panel2.width(85);
      panel2.padding(forms::padding(5));
      
      button1.text("Ok");
      button1.dock(dock_style::top);
      button1.click += [&] {
        close();
      };
      
      button2.text("Cancel");
      button2.dock(dock_style::top);
      button2.click += [&] {
        close();
      };
    };
    
  private:
    panel panel1;
    label label1;
    panel panel2;
    button button1;
    button button2;
  };
  
  class form5 : public form {
  public:
    form5() {
      maximize_box(false);
      minimize_box(false);
      show_icon(false);
      show_in_taskbar(false);
      top_most(true);
      form_border_style(forms::form_border_style::none);
      start_position(form_start_position::manual);
      client_size({ 350, 200 });
      location({ screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().top() + 5 });
      //padding(forms::padding(5));
      
      /// Set round rectangle form :
      drawing::drawing_2d::graphics_path path;
      path.add_rounded_rectangle(client_rectangle(), 10);
      region(drawing::region(path));
      
      //      back_color(drawing::color::white);
      //      h_layout_container_.back_color(drawing::color::yellow);
      //      v_layout_icon_.back_color(drawing::color::blue);
      //      v_layout_title_message_.back_color(drawing::color::orange);
      //      v_layout_buttons_.back_color(drawing::color::green);
      //      label_title_.back_color(drawing::color::pink);
      //      label_message_.back_color(drawing::color::cyan);
      
      h_layout_container_.parent(*this);
      //h_layout_container_.border_style(border_style::none);
      h_layout_container_.padding(forms::padding(5));
      h_layout_container_.controls().push_back_range({ v_layout_icon_, v_layout_title_message_, v_layout_buttons_ });
      h_layout_container_.dock(dock_style::fill);
      h_layout_container_.control_layout_style(v_layout_icon_, { 0.25f, size_type::percent, true });
      h_layout_container_.control_layout_style(v_layout_title_message_, { 0.75f, size_type::percent, true });
      h_layout_container_.control_layout_style(v_layout_buttons_, { 80, size_type::absolute });
      
      v_layout_icon_.controls().push_back(picture_box_icon_);
      v_layout_icon_.dock(dock_style::top);
      
      picture_box_icon_.image(xtd::drawing::system_icons::question().to_bitmap());
      picture_box_icon_.client_size({ 64, 64 });
      picture_box_icon_.size_mode(picture_box_size_mode::center_image);
      picture_box_icon_.dock(dock_style::top);
      picture_box_icon_.padding(forms::padding(5));
      
      v_layout_title_message_.padding(forms::padding(5));
      v_layout_title_message_.controls().push_back_range({ label_title_, label_message_ });
      v_layout_title_message_.control_layout_style(label_title_, { 0.20f, size_type::percent, true, content_alignment::top_left });
      v_layout_title_message_.control_layout_style(label_message_, { 0.80f, size_type::percent, true, content_alignment::top_left });
      v_layout_title_message_.dock(dock_style::fill);
      
      label_title_.text("Backup your files");
      label_title_.padding(forms::padding(5));
      label_title_.font({ label_title_.font(), label_title_.font().size() + 2, xtd::drawing::font_style::bold });
      label_title_.dock(dock_style::top);
      
      label_message_.padding(forms::padding(5));
      label_message_.text("Start the auto backup now.");
      label_message_.dock(dock_style::top);
      
      v_layout_buttons_.padding(forms::padding(5));
      v_layout_buttons_.dock(dock_style::fill);
      
      for (auto txt : std::vector{ ustring("Start")/*, ustring("Cancel"), ustring("Ignore"), ustring("Abort")*/ }) {
        std::unique_ptr<button> btn = std::make_unique<button>();
        btn->parent(v_layout_buttons_)
        .text(txt)
        .dock(dock_style::top)
        .click += [txt, this] {
          diagnostics::debug::write_line("button clicked -> " + txt);
          form::close();
        };
        buttons_.push_back(std::move(btn));
      }
      
    };
    
  private:
    picture_box picture_box_icon_;
    horizontal_layout_panel h_layout_container_;
    vertical_layout_panel v_layout_icon_;
    vertical_layout_panel v_layout_title_message_;
    vertical_layout_panel v_layout_buttons_;
    label label_title_;
    label label_message_;
    std::vector<std::unique_ptr<button>> buttons_;
  };
  
  class form6 : public form {
  public:
    form6() {
      mouse_down += [] {
        diagnostics::debug::write_line("form6::mouse_down");
      };
      panel_.back_color(color::navy);
      panel_.mouse_down += [] {
        diagnostics::debug::write_line("panel_::mouse_down");
      };
      panel_.parent(*this);
      panel_.size({ 250, 250 });
      
      panel2_.back_color(color::red);
      panel2_.mouse_down += [] {
        diagnostics::debug::write_line("panel2_::mouse_down");
      };
      panel2_.parent(panel_);
      panel2_.size({ 200, 200 });
      
      group_box_.parent(panel2_);
      group_box_.back_color(color::green);
      group_box_.mouse_down += [] {
        diagnostics::debug::write_line("group_box_::mouse_down");
      };
      
      button_.parent(group_box_);
      button_.flat_style(xtd::forms::flat_style::system);
      button_.mouse_down += [] {
        diagnostics::debug::write_line("button_::mouse_down");
      };
      button_.click += [] {
        diagnostics::debug::write_line("button_::click");
      };
      
      numeric_up_down_.parent(group_box_);
      numeric_up_down_.top(30);
      numeric_up_down_.value_changed += [] {
        diagnostics::debug::write_line("numeric_up_down_::value_changed");
      };
    }
  private:
    panel panel_;
    panel panel2_;
    group_box group_box_;
    button button_;
    numeric_up_down numeric_up_down_;
  };
  
  class form7 : public form {
  public:
    form7() {
      client_size({ 450, 200 });
      
      tbx_username_.parent(*this);
      tbx_username_.location({ 50, 20 });
      tbx_username_.size({ 350, 30 });
      tbx_username_.placeholder_text("Username...");
      
      tbx_password_.parent(*this);
      tbx_password_.location({ 50, 60 });
      tbx_password_.size({ 350, 30 });
      tbx_password_.use_system_password_char(true);
      tbx_password_.placeholder_text("Password must be between 6 and 20 characters...");
      
      btn_login_.parent(*this);
      btn_login_.location({ 50, 100 });
      btn_login_.size({ 350, 35 });
      btn_login_.text("Login");
      btn_login_.click += [&] {
        message_box::show(*this, "username text_box hint: " + tbx_username_.placeholder_text() + '\n' + "password text_box hint: " + tbx_password_.placeholder_text(), "placeholder");
      };
      
    }
  private:
    text_box tbx_username_;
    text_box tbx_password_;
    button btn_login_;
  };
  
}


auto main()->int {
  application::run(examples::form7());
}

