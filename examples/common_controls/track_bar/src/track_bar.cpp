#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->client_size({300, 300});
    this->text("Track bar example");
    
    this->progress_bar1.location({100, 50});
    this->progress_bar1.maximum(200);
    this->progress_bar1.orientation(forms::orientation::vertical);
    this->progress_bar1.parent(*this);
    this->progress_bar1.size({23, 200});
    
    this->label1.location({150, 50});
    this->label1.parent(*this);

    this->track_bar1.location({50, 50});
    this->track_bar1.maximum(200);
    this->track_bar1.orientation(forms::orientation::vertical);
    this->track_bar1.parent(*this);
    this->track_bar1.value_changed += [&](const control& sender, const event_args& e) {
      this->progress_bar1.value(this->track_bar1.value());
      this->label1.text(strings::format("{}", this->track_bar1.value()));
    };
    this->track_bar1.value(100);
    this->track_bar1.tick_style(forms::tick_style::none);
    this->track_bar1.size({45, 200});
  }
  
private:
  track_bar track_bar1;
  progress_bar progress_bar1;
  label label1;
};

int main() {
  application::run(form1());
}
