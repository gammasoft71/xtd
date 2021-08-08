#include <thread>
#include <xtd/literals.h>
#include <xtd/startup.h>
#include <xtd/forms/application.h>
#include <xtd/forms/button.h>
#include <xtd/forms/choice.h>
#include <xtd/forms/label.h>
#include <xtd/forms/numeric_up_down.h>
#include <xtd/forms/text_box.h>

namespace guidgen_gui {
  class main_form : public xtd::forms::form {
  public:
    main_form() {
      using namespace std;
      using namespace xtd;
      using namespace xtd::drawing;
      using namespace xtd::forms;
      
      client_size({645, 350});
      controls().push_back_range({count_label_, count_numeric_up_down_, format_label_, format_choice_, generate_button_, result_text_box_});
      text("Guid generator"_t);
      
      count_label_.anchor(anchor_styles::top|anchor_styles::left);
      count_label_.auto_size(true);
      count_label_.location({10, 13});
      count_label_.text("Count"_t);
      
      count_numeric_up_down_.location({70, 10});
      count_numeric_up_down_.set_range(1, 2000);
      count_numeric_up_down_.value(1);
      count_numeric_up_down_.wrapped(true);
      
      format_label_.auto_size(true);
      format_label_.location({200, 13});
      format_label_.text("Format"_t);
      
      format_choice_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::right);
      format_choice_.location({260, 11});
      format_choice_.width(290);
      format_choice_.items().push_back_range({{"N : digits"_t, "N"_s}, {"D : with hyphens"_t, "D"_s}, {"B : with hyphens and braces"_t, "B"_s}, {"P : with hyphens and parentheses"_t, "P"_s}, {"X : hexadecimal with braces"_t, "X"_s}});
      format_choice_.selected_index(1);
      
      generate_button_.anchor(anchor_styles::top|anchor_styles::right);
      generate_button_.location({560, 10});
      generate_button_.text("Generate"_t);
      generate_button_.click += [&] {
        result_text_box_.text("");
        thread generate([&]{
          begin_invoke([&] {
            count_numeric_up_down_.enabled(false);
            format_choice_.enabled(false);
            generate_button_.enabled(false);
            result_text_box_.enabled(false);
            application::use_wait_cursor(true);
            application::do_events();
          });
          
          for (int count = 0; count < (count_numeric_up_down_.text() == "" ? count_numeric_up_down_.value() : parse<int>(count_numeric_up_down_.text())); count++) {
            begin_invoke([&] {
              result_text_box_.append_text(xtd::guid::new_guid().to_string(any_cast<ustring>(format_choice_.selected_item().tag())));
              result_text_box_.append_text(environment::new_line());
            });
          }
          
          begin_invoke([&] {
            count_numeric_up_down_.enabled(true);
            format_choice_.enabled(true);
            generate_button_.enabled(true);
            result_text_box_.enabled(true);
            application::use_wait_cursor(false);
            application::do_events();
          });
        });
        generate.detach();
      };
      
      result_text_box_.anchor(anchor_styles::top|anchor_styles::left|anchor_styles::bottom|anchor_styles::right);
      result_text_box_.font({font_family::generic_monospace(), result_text_box_.font().size()});
      result_text_box_.location({10, 50});
      result_text_box_.read_only(true);
      result_text_box_.size({625, 290});
      result_text_box_.multiline(true);
      result_text_box_.word_wrap(false);
    }
    
    static void main() {
      xtd::forms::application::run(main_form());
    }
    
  private:
    xtd::forms::label count_label_;
    xtd::forms::numeric_up_down count_numeric_up_down_;
    xtd::forms::label format_label_;
    xtd::forms::choice format_choice_;
    xtd::forms::button generate_button_;
    xtd::forms::text_box result_text_box_;
  };
}
