#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/message_notifier.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/message_notifier.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/collapsible_panel.h"
#include "../../../include/xtd/forms/picture_box.h"
#include "../../../include/xtd/forms/horizontal_layout_panel.h"
#include "../../../include/xtd/forms/vertical_layout_panel.h"
#include "../../../include/xtd/forms/screen.h"

using namespace xtd;
using namespace xtd::forms;

// TODO:
//- Buttons
//- Close button
//- Notifier Icon (system icon info, warn...)
//- Timer if close timeout is enabled
//- Callbacks
//- Start position to be bottom/top right
//- Fix issue when notification message is too long, layouts intersect
//- Adapt changes to both show(hwnd) and show()
//- fix (xtd.forms.manual_tests:32885): Gtk-CRITICAL **: 14:30:31.503: gtk_window_resize: assertion 'height > 0' failed

#include <xtd/drawing/system_colors.h>
#include <xtd/diagnostics/debug.h>

namespace {
  class message_notifier_standard : public form {
  public:
    message_notifier_standard(message_notifier_buttons buttons) {
      maximize_box(false);
      minimize_box(false);
      show_icon(false);
      show_in_taskbar(false);
      opacity(0.10);
      auto_size(true);
      auto_size_mode(auto_size_mode::grow_and_shrink);
      form_border_style(forms::form_border_style::none);
      start_position(form_start_position::center_screen); // TODO: set to top right or bottom right ?
      // location({screen::primary_screen().working_area().right(), 0});
      
      h_layout_container_.parent(*this);
      h_layout_container_.auto_size(true);
      h_layout_container_.border_style(border_style::none);
      h_layout_container_.padding(forms::padding(5));
      h_layout_container_.controls().push_back_range({picture_box_icon_, v_layout_title_message_, v_layout_buttons_});
      h_layout_container_.dock(dock_style::fill);
      h_layout_container_.control_layout_style(picture_box_icon_, {.15f, size_type::percent, true});
      h_layout_container_.control_layout_style(v_layout_title_message_, {.70f, size_type::percent, true});
      h_layout_container_.control_layout_style(v_layout_buttons_, {.15f, size_type::percent, true});
      
      //      picture_box_icon_.back_color(xtd::drawing::system_colors::accent().blue);
      //      v_layout_title_message_.back_color(xtd::drawing::system_colors::accent().green);
      v_layout_buttons_.back_color(xtd::drawing::system_colors::accent().orange);
      close_button_.back_color(xtd::drawing::system_colors::accent().cyan);
      
      picture_box_icon_.height(64);
      picture_box_icon_.size_mode(picture_box_size_mode::center_image);
      picture_box_icon_.dock(dock_style::fill);
      picture_box_icon_.padding(forms::padding(5));
      
      v_layout_title_message_.auto_size(true);
      v_layout_title_message_.padding(forms::padding(5));
      v_layout_title_message_.controls().push_back_range({label_title_, label_message_});
      v_layout_title_message_.control_layout_style(label_title_, {.40f, size_type::percent, true});
      v_layout_title_message_.control_layout_style(label_message_, {.60f, size_type::percent, true});
      v_layout_title_message_.border_style(border_style::none);
      v_layout_title_message_.dock(dock_style::fill);
      
      label_title_.auto_size(true);
      label_title_.text_align(content_alignment::middle_left);
      label_title_.font({label_title_.font(), label_title_.font().size() + 4, xtd::drawing::font_style::bold});
      label_title_.margin(forms::padding(0, 10, 5, 5));
      label_title_.dock(dock_style::left);
      
      label_message_.auto_size(true);
      label_message_.dock(dock_style::left);
      label_message_.text_align(content_alignment::bottom_center);
      label_message_.margin(forms::padding(0, 5, 5, 5));
      label_message_.font({label_message_.font(), label_title_.font().size() - 4});
      
      v_layout_buttons_.auto_size(true);
      v_layout_buttons_.border_style(border_style::none);
      v_layout_buttons_.padding(forms::padding(2));
      v_layout_buttons_.dock(dock_style::fill);
      //v_layout_buttons_.anchor(anchor_styles::right);
      
      close_button_.parent(v_layout_buttons_);
      close_button_.dock(dock_style::right);
      //close_button_.anchor(anchor_styles::right);
      //close_button_.location({form::width() - 16, 0});
      //close_button_.size({16,16});
      //close_button_.anchor(anchor_styles::all);
      close_button_.auto_size(true);
      close_button_.size_mode(picture_box_size_mode::center_image);
      //close_button_.margin(forms::padding());
      close_button_.padding(forms::padding(5));
      close_button_.image(xtd::drawing::system_images::from_name("dialog-cancel", xtd::drawing::size(16, 16)));
      close_button_.click += [&] {
        on_notifier_closed_(notifier_result::none);
        form::close();
      };
      form::mouse_enter += [&] {
        //close_button_.visible(true);
      };
      form::mouse_leave += [&] {
        //close_button_.visible(false);
      };
      switch (buttons) {
        case message_notifier_buttons::ok: {
          std::unique_ptr<button> ok_btn = std::make_unique<button>();
          ok_btn->parent(v_layout_buttons_).text("ok");
          ok_btn->click += [&] {
            on_notifier_closed_(notifier_result::ok);
            form::close();
          };
          buttons_.push_back(std::move(ok_btn));
          break;
        }
        case message_notifier_buttons::ok_cancel: {
          std::unique_ptr<button> ok_btn = std::make_unique<button>();
          std::unique_ptr<button> cancel_btn = std::make_unique<button>();;
          ok_btn->parent(v_layout_buttons_).text("ok");
          ok_btn->click += [&] {
            on_notifier_closed_(notifier_result::ok);
            form::close();
          };
          cancel_btn->parent(v_layout_buttons_).text("cancel");
          cancel_btn->click += [&] {
            on_notifier_closed_(notifier_result::cancel);
            form::close();
          };
          buttons_.push_back(std::move(ok_btn));
          buttons_.push_back(std::move(cancel_btn));
          break;
        }
        case message_notifier_buttons::yes_no: {
          std::unique_ptr<button> yes_btn = std::make_unique<button>();
          std::unique_ptr<button> no_btn = std::make_unique<button>();
          yes_btn->parent(v_layout_buttons_).text("yes");
          yes_btn->click += [&] {
            on_notifier_closed_(notifier_result::yes);
            form::close();
          };
          no_btn->parent(v_layout_buttons_).text("no");
          no_btn->click += [&] {
            on_notifier_closed_(notifier_result::no);
            form::close();
          };
          buttons_.push_back(std::move(yes_btn));
          buttons_.push_back(std::move(no_btn));
          break;
        }
        case message_notifier_buttons::yes_no_cancel: {
          std::unique_ptr<button> yes_btn = std::make_unique<button>();
          std::unique_ptr<button> no_btn = std::make_unique<button>();
          std::unique_ptr<button> cancel_btn = std::make_unique<button>();
          yes_btn->parent(v_layout_buttons_).text("yes");
          yes_btn->click += [&] {
            on_notifier_closed_(notifier_result::yes);
            form::close();
          };
          no_btn->parent(v_layout_buttons_).text("no");
          no_btn->click += [&] {
            on_notifier_closed_(notifier_result::no);
            form::close();
          };
          cancel_btn->parent(v_layout_buttons_).text("cancel");
          cancel_btn->click += [&] {
            on_notifier_closed_(notifier_result::cancel);
            form::close();
          };
          buttons_.push_back(std::move(yes_btn));
          buttons_.push_back(std::move(no_btn));
          buttons_.push_back(std::move(cancel_btn));
          break;
        }
        case message_notifier_buttons::retry_cancel: {
          std::unique_ptr<button> retry_btn = std::make_unique<button>();
          std::unique_ptr<button> cancel_btn = std::make_unique<button>();
          retry_btn->parent(v_layout_buttons_).text("retry");
          retry_btn->click += [&] {
            on_notifier_closed_(notifier_result::retry);
            form::close();
          };
          cancel_btn->parent(v_layout_buttons_).text("cancel");
          cancel_btn->click += [&] {
            on_notifier_closed_(notifier_result::cancel);
            form::close();
          };
          buttons_.push_back(std::move(retry_btn));
          buttons_.push_back(std::move(cancel_btn));
          break;
        }
        case message_notifier_buttons::abort_retry_ignore: {
          std::unique_ptr<button> abort_btn = std::make_unique<button>();
          std::unique_ptr<button> retry_btn = std::make_unique<button>();
          std::unique_ptr<button> ignore_btn = std::make_unique<button>();
          abort_btn->parent(v_layout_buttons_).text("abort");
          abort_btn->click += [&] {
            on_notifier_closed_(notifier_result::abort);
            form::close();
          };
          retry_btn->parent(v_layout_buttons_).text("retry");
          retry_btn->click += [&] {
            on_notifier_closed_(notifier_result::retry);
            form::close();
          };
          ignore_btn->parent(v_layout_buttons_).text("ignore");
          ignore_btn->click += [&] {
            on_notifier_closed_(notifier_result::ignore);
            form::close();
          };
          buttons_.push_back(std::move(abort_btn));
          buttons_.push_back(std::move(retry_btn));
          buttons_.push_back(std::move(ignore_btn));
          break;
        }
        case message_notifier_buttons::none:
        default:
          break;
      }
      
      //        for(auto& btn : buttons_)
      //            btn->margin(forms::padding(2)).padding(forms::padding(0));
    }
    
    static void show(intptr_t hwnd, const xtd::ustring& title,
      const xtd::ustring& message,
      const xtd::drawing::icon& icon,
      message_notifier_icon notifier_icon,
      message_notifier_buttons buttons,
      bool close_timeout_enabled_,
      std::chrono::system_clock::duration close_timeout_interval,
      xtd::delegate<void(forms::notifier_result)> on_notifier_closed) {
      if (message_notifier != nullptr)
        delete message_notifier;
      message_notifier = new message_notifier_standard(buttons);
      
      // Icon
      if (icon != xtd::drawing::icon::empty)
        message_notifier->picture_box_icon_.image(xtd::drawing::bitmap(icon.to_bitmap(), {64, 64}));
      else if (notifier_icon != message_notifier_icon::none) {
        switch (notifier_icon) {
          case message_notifier_icon::information:
            message_notifier->picture_box_icon_.image(xtd::drawing::system_images::from_name("dialog-information", xtd::drawing::size(64, 64)));
            break;
          case message_notifier_icon::warning:
            message_notifier->picture_box_icon_.image(xtd::drawing::system_images::from_name("dialog-warning", xtd::drawing::size(64, 64)));
            break;
          case message_notifier_icon::error:
            message_notifier->picture_box_icon_.image(xtd::drawing::system_images::from_name("dialog-error", xtd::drawing::size(64, 64)));
            break;
          default:
            break;
        }
      } else
        message_notifier->picture_box_icon_.visible(false);
        
      // Title
      message_notifier->label_title_.text(title);
      
      // Message
      message_notifier->label_message_.text(message);
      
      // callbacks  (will be called in on_form_closed())
      message_notifier->on_notifier_closed_ = on_notifier_closed;
      
      // Show
      message_notifier->visible(true);
    }
    
  private:
    // we dont need this if we're closing the window witha dialog-cancel icon
    //  void on_form_closed(const form_closed_event_args& e) override {
    //    form::on_form_closed(e);
    //    message_notifier->on_notifier_closed_(notifier_result::none);
    //    delete message_notifier;
    //  }
    inline static message_notifier_standard* message_notifier = nullptr;
    xtd::delegate<void(notifier_result)> on_notifier_closed_;
    picture_box picture_box_icon_;
    label label_title_;
    label label_message_;
    horizontal_layout_panel h_layout_container_;
    //vertical_layout_panel v_layout_icon_;
    vertical_layout_panel v_layout_title_message_;
    //split_container splitter_;
    vertical_layout_panel v_layout_buttons_;
    std::vector<std::unique_ptr<button>> buttons_;
    picture_box close_button_;
    /*
            Standard Notification
     ________________________________________
    |          |                    | BUTTON1 |
    |          |   label title      | BUTTON2 |
    |   icon   | ------------------ | BUTTON3 |
    |          |   label message    | BUTTON4 |
    |__________|____________________|_________|
    */
  };
}

void message_notifier::reset() {
  title_ = "";
  message_ = "";
  icon_ = xtd::drawing::image::empty;
  notifier_icon_ = xtd::forms::message_notifier_icon::none;
  buttons_ = xtd::forms::message_notifier_buttons::none;
  close_timeout_enabled_ = false;
  close_timeout_interval_ = std::chrono::seconds(10);
  result_ = xtd::forms::notifier_result::none;
  notifier_style_ = xtd::forms::notifier_style::standard;
  notifier_closed.clear();
}

void message_notifier::show() {
  if (notifier_style_ == xtd::forms::notifier_style::system) {
    auto notifier_closed_callback = xtd::delegate<void()>([this]() {
      this->on_notifier_closed(notifier_closed_event_args{});
    });
    native::message_notifier::show(0,
      title_,
      message_,
      xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)),
      static_cast<uint32_t>(notifier_icon_) + static_cast<uint32_t>(buttons_),
      close_timeout_enabled_,
      close_timeout_interval_,
      notifier_closed_callback);
      
  } else {
    message_notifier_standard::show(0,
      title_,
      message_,
      xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)),
      notifier_icon_,
      buttons_,
      close_timeout_enabled_,
      close_timeout_interval_,
    xtd::delegate<void(forms::notifier_result)>([this](forms::notifier_result res) {
      on_notifier_closed(notifier_closed_event_args{ res });
    }));
  }
}

void message_notifier::show(const iwin32_window& owner) {
  auto notifier_closed_callback = xtd::delegate<void()>([this]() {
    this->on_notifier_closed(notifier_closed_event_args{});
  });
  
  if (notifier_style_ == xtd::forms::notifier_style::system)
    native::message_notifier::show(owner.handle(),
      title_,
      message_,
      xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)),
      static_cast<uint32_t>(notifier_icon_) + static_cast<uint32_t>(buttons_),
      close_timeout_enabled_, close_timeout_interval_, notifier_closed_callback);
  else
    message_notifier_standard::show(owner.handle(),
      title_,
      message_,
      xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)),
      notifier_icon_,
      buttons_,
      close_timeout_enabled_, close_timeout_interval_, notifier_closed_callback);
}
