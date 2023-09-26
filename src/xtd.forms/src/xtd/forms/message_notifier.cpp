#include "../../../include/xtd/forms/collapsible_panel"
#include "../../../include/xtd/forms/form"
#include "../../../include/xtd/forms/horizontal_layout_panel"
#include "../../../include/xtd/forms/label"
#include "../../../include/xtd/forms/message_notifier"
#include "../../../include/xtd/forms/picture_box"
#include "../../../include/xtd/forms/screen"
#include "../../../include/xtd/forms/vertical_layout_panel"
#include <xtd/drawing/system_icons>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/message_notifier>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/math>

using namespace xtd;
using namespace xtd::forms;

namespace {
  class message_notifier_standard : public form {
  public:
    explicit message_notifier_standard(const message_notifier& mn) {
      maximize_box(false);
      minimize_box(false);
      show_icon(false);
      show_in_taskbar(false);
      top_most(true);
      form_border_style(forms::form_border_style::none);
      start_position(form_start_position::manual);
      client_size({350, 200});
      padding(forms::padding(5));
      
      if (environment::os_version().is_windows()) {
        // Bottom right screen location
        location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().bottom() - client_size().height() - 5});
        opacity(0.90);
        
      } else if (environment::os_version().is_macos()) {
        // Top right screen location
        location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().top() + 5});
        // Set round rectangle form
        drawing::drawing_2d::graphics_path path;
        path.add_rounded_rectangle(client_rectangle(), 7);
        region(drawing::region(path));
        // Set opacity
        opacity(0.95);
      } else { // if (environment::os_version().is_linux())
        // Top right screen location
        location({screen::primary_screen().working_area().right() - client_size().width() - 5, screen::primary_screen().working_area().top() + 5});
        // Set round rectangle form
        drawing::drawing_2d::graphics_path path;
        path.add_rounded_rectangle(client_rectangle(), 7);
        region(drawing::region(path));
        // Set opacity
        opacity(0.95);
        
      }
      
      //    back_color(drawing::color::white);
      //    h_layout_container_.back_color(drawing::color::yellow);
      //    v_layout_icon_.back_color(drawing::color::blue);
      //    v_layout_title_message_.back_color(drawing::color::orange);
      //    v_layout_buttons_.back_color(drawing::color::green);
      //    label_title_.back_color(drawing::color::pink);
      //    label_message_.back_color(drawing::color::cyan);
      
      h_layout_container_.parent(*this);
      h_layout_container_.padding(forms::padding(5));
      h_layout_container_.controls().push_back_range({v_layout_icon_, v_layout_title_message_, v_layout_buttons_});
      h_layout_container_.dock(dock_style::fill);
      h_layout_container_.control_layout_style(v_layout_icon_, {0.25f, size_type::percent, true});
      h_layout_container_.control_layout_style(v_layout_title_message_, {0.75f, size_type::percent, true});
      h_layout_container_.control_layout_style(v_layout_buttons_, {80, size_type::absolute});
      
      v_layout_icon_.controls().push_back(picture_box_icon_);
      v_layout_icon_.dock(dock_style::top);
      
      picture_box_icon_.image(xtd::drawing::system_icons::question().to_bitmap());
      picture_box_icon_.client_size({64, 64});
      picture_box_icon_.size_mode(picture_box_size_mode::center_image);
      picture_box_icon_.dock(dock_style::top);
      picture_box_icon_.padding(forms::padding(5));
      
      v_layout_title_message_.padding(forms::padding(5));
      v_layout_title_message_.controls().push_back_range({label_title_, label_message_});
      v_layout_title_message_.control_layout_style(label_title_, {0.20f, size_type::percent, true, content_alignment::top_left});
      v_layout_title_message_.control_layout_style(label_message_, {0.80f, size_type::percent, true, content_alignment::top_left});
      v_layout_title_message_.dock(dock_style::fill);
      
      label_title_.text(mn.title());
      label_title_.padding(forms::padding(5));
      label_title_.font({label_title_.font(), label_title_.font().size() + 2, xtd::drawing::font_style::bold});
      label_title_.dock(dock_style::top);
      
      label_message_.padding(forms::padding(5));
      label_message_.text(mn.message());
      label_message_.dock(dock_style::top);
      
      
      v_layout_buttons_.padding(forms::padding(5));
      v_layout_buttons_.dock(dock_style::fill);
      v_layout_buttons_.width(85);
      
      
      // Incase no button was specified, add a custom Close button
      if (mn.buttons().empty()) {
        auto btn = std::make_unique<button>();
        btn->parent(v_layout_buttons_)
        .text("&Close")
        .dock(dock_style::top)
        .margin(forms::padding(2))
        .click += [&] {
          if (timer_.enabled()) timer_.enabled(false);
          form::close();
          // TODO
          //mn.on_notifier_closed(notifier_closed_event_args(std::nullopt));
        };
        buttons_.push_back(std::move(btn));
      }
      
      // Buttons
      for (const auto& _btn : mn.buttons()) {
        auto btn = std::make_unique<button>();
        btn->parent(v_layout_buttons_)
        .text(_btn.get().text())
        .dock(dock_style::top)
        .margin(forms::padding(2))
        .click += [&] {
          if (timer_.enabled()) timer_.enabled(false);
          // TODO
          // mn.on_button_click(notifier_button_click_event_args(_btn));
          form::close();
        };
        buttons_.push_back(std::move(btn));
      }
      
      // Auto close timeout if enabled
      if (mn.close_timeout_enabled()) {
        timer_.interval(mn.close_timeout_interval());
        timer_.start();
        timer_.tick += [&] {
          form::close();
          // TODO
          //mn.on_notifier_closed(notifier_closed_event_args(.close_on_timeout_ = true));
          timer_.stop();
        };
      }
      
    }
    
    using form::show;
    static void show([[maybe_unused]] intptr hwnd, const message_notifier& mn) {
      message_notifier_.reset(new message_notifier_standard(mn));
      dynamic_cast<form&>(*message_notifier_).show();
    }
    
  private:
    inline static std::unique_ptr<message_notifier_standard> message_notifier_ = nullptr;
    picture_box picture_box_icon_;
    label label_title_;
    label label_message_;
    horizontal_layout_panel h_layout_container_;
    vertical_layout_panel v_layout_icon_;
    vertical_layout_panel v_layout_title_message_;
    vertical_layout_panel v_layout_buttons_;
    std::vector<std::unique_ptr<button>> buttons_;
    timer timer_;
    
    // TODO: spawn notifications bellow or above each other
    struct previous_message_notifier_coords {
      drawing::point location;
      drawing::size size;
    };
    inline static std::unique_ptr<previous_message_notifier_coords> previous_notifier_coords_ = nullptr;
    
    /*
            Standard Notification
    _______________________________________
    |      |                    | BUTTON1 |
    |      |   label title      | BUTTON2 |
    | icon | ------------------ | BUTTON3 |
    |      |   label message    | BUTTON4 |
    |______|____________________|_________|
    */
  };
}



void message_notifier::reset() {
  title_ = "";
  message_ = "";
  icon_ = xtd::drawing::image::empty;
  buttons_.clear();
  close_timeout_enabled_ = false;
  close_timeout_interval_ = std::chrono::milliseconds(10'000);
  notifier_closed.clear();
  notifier_style_ = xtd::forms::notifier_style::standard;
}


void message_notifier::show() {
  if (notifier_style_ == xtd::forms::notifier_style::standard)
    message_notifier_standard::show(0, *this);
  else
    throw xtd::not_implemented_exception();
}
void message_notifier::show(const iwin32_window& owner) {
  if (notifier_style_ == xtd::forms::notifier_style::standard)
    message_notifier_standard::show(owner.handle(), *this);
  else
    throw xtd::not_implemented_exception();
}
