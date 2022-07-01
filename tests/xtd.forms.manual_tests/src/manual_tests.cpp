#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Status bar example");
      client_size({820, 500});
      //status_bar(status_bar1);
      
      status_bar1.parent(*this);
      status_bar1.panels().push_back_range({status_bar_panel1, status_bar_panel2, status_bar_panel3, status_bar_panel4});
      //status_bar1.sizing_grip(false);
      //status_bar1.show_panels(true);
      
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
    
    forms::status_bar status_bar1;
    status_bar_panel status_bar_panel1 = status_bar_panel::create_panel("Status one", image_from_color(color::light_green));
    status_bar_panel status_bar_panel2 = status_bar_panel::create_panel("Status two");
    status_bar_panel status_bar_panel3 = status_bar_panel::create_panel("Status three");
    timer timer1;
    progress_bar progress_bar1;
    status_bar_panel status_bar_panel4 = status_bar_panel::create_control(progress_bar1);
  };
  
  class form2 : public form {
  public:
    form2() {
      text("Message notifier example");
      client_size({350, 200});
      start_position(form_start_position::center_screen);
      btn.parent(*this)
      .text("notify")
      .size({200, 35})
      .click += [&] {
        notifier.reset();
        notifier.notifier_style(notifier_style::standard);
        notifier.title("This is a notification title");
        notifier.message("Where this is the notification message");
        notifier.icon(xtd::drawing::system_icons::xtd_logo());
        //notifier.notifier_icon(message_notifier_icon::information);
        notifier.buttons(message_notifier_buttons::yes_no_cancel);
        notifier.close_timeout_enabled(true);
        notifier.close_timeout_interval(std::chrono::seconds(2) + std::chrono::milliseconds(1000));
        
        notifier.notifier_closed += [&](object&, const notifier_closed_event_args & e) {
          diagnostics::debug::write_line("notifier closed => {}", e.notifier_result());
          //if (e.notifier_result() == notifier_result::ok) // or: if (notifier.notifier_result() == notifier_result::ok)
        };
        notifier.show();
      };
      
    }
    
  private:
    button btn;
    message_notifier notifier;
  };
  
  // Example of notification form with layout...
  class form3 : public form {
  public:
    form3() {
      client_size({300, button1.height() + button2.height() + 10});
      form_border_style(forms::form_border_style::none);
      padding(forms::padding(5));
      start_position(xtd::forms::form_start_position::manual);
      top_most(true);
      
      /// Set round rectangle form :
      drawing::drawing2d::graphics_path path;
      path.add_rounded_rectangle(client_rectangle(), 7);
      region(drawing::region(path));
      
      // Top right screen location :
      location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().top() + 5});
      
      // Bottom right screen location :
      //location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().bottom() - client_size().height() - 5});
      
      layout_panel1.controls().push_back_range({panel1, layout_panel2});
      layout_panel1.control_layout_style(panel1, {1.0f, size_type::percent, true});
      layout_panel1.control_layout_style(layout_panel2, {75, size_type::absolute});
      layout_panel1.dock(dock_style::fill);
      layout_panel1.parent(*this);
      
      panel1.padding(forms::padding(5));
      
      label1.parent(panel1);
      label1.dock(dock_style::fill);
      
      // The following text is wrapped in label :
      label1.text("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. Curabitur eu amet.");
      
      layout_panel2.controls().push_back_range({button1, button2});
      
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
      controls().push_back_range({panel1, panel2});
      client_size({300, button1.height() + button2.height() + 10});
      form_border_style(forms::form_border_style::none);
      start_position(xtd::forms::form_start_position::manual);
      top_most(true);
      
      /// Set round rectangle form :
      drawing::drawing2d::graphics_path path;
      path.add_rounded_rectangle(client_rectangle(), 7);
      region(drawing::region(path));
      
      // Top right screen location :
      location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().top() + 5});
      
      // Bottom right screen location :
      //location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().bottom() - client_size().height() - 5});
      
      panel1.controls().push_back(label1);
      panel1.dock(dock_style::fill);
      panel1.parent(*this);
      panel1.padding(forms::padding(5));
      
      label1.dock(dock_style::fill);
      
      // The following text is wrapped in label :
      label1.text("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. Curabitur eu amet.");
      
      panel2.controls().push_back_range({button2, button1});
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
}

int main() {
  application::run(examples::form1());
}
