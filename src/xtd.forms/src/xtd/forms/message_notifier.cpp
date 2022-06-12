#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/message_notifier.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_icons.h>
#include "../../../include/xtd/forms/message_notifier.h"
#include "../../../include/xtd/forms/form.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/panel.h"
#include "../../../include/xtd/forms/picture_box.h"
#include "../../../include/xtd/forms/horizontal_layout_panel.h"
#include "../../../include/xtd/forms/vertical_layout_panel.h"

using namespace xtd;
using namespace xtd::forms;

namespace {
  class message_notifier_standard : public form {
  public:
    message_notifier_standard() {
        maximize_box(false);
        minimize_box(false);
        show_icon(false);
        show_in_taskbar(false);
        opacity(0.10);
        auto_size(true);

        auto_size_mode(auto_size_mode::grow_and_shrink);
        form_border_style(forms::form_border_style::none);
        start_position(form_start_position::center_screen); // TODO: top right in linux, bottom right windows ?

        h_layout_container_.parent(*this);
        h_layout_container_.auto_size(true);
        h_layout_container_.border_style(border_style::none);
        h_layout_container_.padding(forms::padding(5));
        h_layout_container_.controls().push_back_range({v_layout_icon_, v_layout_title_message_, v_layout_buttons_});
        h_layout_container_.dock(dock_style::fill);
        h_layout_container_.control_layout_style(v_layout_icon_, {.20f, size_type::percent, true}); // 20% icon
        h_layout_container_.control_layout_style(v_layout_title_message_, {.60f, size_type::percent, true}); // 60 % title & message
        h_layout_container_.control_layout_style(v_layout_buttons_, {.20f, size_type::percent, true}); // 20% buttons

        v_layout_icon_.height(64);
        v_layout_icon_.border_style(border_style::none);
        v_layout_icon_.controls().push_back_range({picture_box_icon_});
        v_layout_icon_.dock(dock_style::fill);

        picture_box_icon_.height(64);
        picture_box_icon_.size_mode(picture_box_size_mode::center_image);
        picture_box_icon_.margin(20);
//        picture_box_icon_.dock(dock_style::fill);


        v_layout_title_message_.border_style(border_style::none);
        label_title_.parent(v_layout_title_message_);
        label_title_.auto_size(true);
        label_title_.text_align(content_alignment::middle_left);
        label_title_.font({label_title_.font(), label_title_.font().size() + 2, xtd::drawing::font_style::bold});
        label_title_.padding(forms::padding(5));

        label_message_.parent(v_layout_title_message_);
        label_message_.auto_size(true);
        label_message_.width(350);
        label_message_.text_align(content_alignment::middle_left);



    }



    static void show(intptr_t hwnd,const xtd::ustring& title,
                                      const xtd::ustring& message,
                                      const xtd::drawing::icon& icon,
                                      uint32_t style,
                                      bool close_timeout_enabled_,
                                      std::chrono::system_clock::duration close_timeout_interval,
                                      xtd::delegate<void()> on_notifier_closed)
    {
        if (message_notifier != nullptr) {
          message_notifier->activate();
          return;
        }
        message_notifier = new message_notifier_standard();

        // Icon
        if (icon != xtd::drawing::icon::empty)
          message_notifier->picture_box_icon_.image(xtd::drawing::bitmap(icon.to_bitmap(), {64, 64}));
        else
            // TODO: use system icon info warning with help of xtd::drawing::system_icons::
           message_notifier->picture_box_icon_.image(xtd::drawing::system_images::from_name("dialog-warning", xtd::drawing::size(64, 64)));

        // Title
        message_notifier->label_title_.text(title);

        // Message
        message_notifier->label_message_.text(message);

        // callbacks  (will be called in on_form_closed())
        message_notifier->on_notifier_closed_ = on_notifier_closed;

         // TODO:
            //- Buttons
            //- Notifier Icon (system ico info, warn...)
            //- Timer if close timeout is enabled

         // Show
         message_notifier->visible(true);

    }

  private:
    void on_form_closed(const form_closed_event_args& e) override {
      form::on_form_closed(e);
      message_notifier->on_notifier_closed_();
      delete message_notifier;
    }
    inline static message_notifier_standard* message_notifier = nullptr;
    xtd::delegate<void()> on_notifier_closed_;
    picture_box picture_box_icon_;
    label label_title_;
    label label_message_;
    horizontal_layout_panel h_layout_container_;
    vertical_layout_panel v_layout_icon_;
    vertical_layout_panel v_layout_title_message_;
    vertical_layout_panel v_layout_buttons_;
    std::vector<button> buttons;
  };
}


void message_notifier::reset()
{
    title_ = "";
    message_ = "";
    icon_ = xtd::drawing::image::empty;
    notifier_icon_ = xtd::forms::message_notifier_icon::none;
    buttons_ = xtd::forms::message_notifier_buttons::none;
    close_timeout_enabled_ = false;
    close_timeout_interval_ = std::chrono::seconds(10);
    result_ = xtd::forms::notifier_result::none;
    notifier_style_ = xtd::forms::notifier_style::standard;
    notifier_closed.clear(); // Should we clear deleagate callbacks as well?
}


void message_notifier::show() {
    auto notifier_closed_callback = xtd::delegate<void()>([this]()
    {
      this->on_notifier_closed(notifier_closed_event_args{});
    });

    if (notifier_style_ == xtd::forms::notifier_style::system)
      native::message_notifier::show(0,
                                   title_,
                                   message_,
                                   xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)),
                                   static_cast<uint32_t>(notifier_icon_) + static_cast<uint32_t>(buttons_),
                                   close_timeout_enabled_, close_timeout_interval_, notifier_closed_callback);
    else
        message_notifier_standard::show(0,
                                        title_,
                                        message_,
                                        xtd::drawing::icon::from_bitmap(xtd::drawing::bitmap(icon_)),
                                        static_cast<uint32_t>(notifier_icon_) + static_cast<uint32_t>(buttons_),
                                        close_timeout_enabled_, close_timeout_interval_, notifier_closed_callback);
}



void message_notifier::show(const iwin32_window& owner) {
  auto notifier_closed_callback = xtd::delegate<void()>([this]()
  {
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
                                      static_cast<uint32_t>(notifier_icon_) + static_cast<uint32_t>(buttons_),
                                      close_timeout_enabled_, close_timeout_interval_, notifier_closed_callback);
}
