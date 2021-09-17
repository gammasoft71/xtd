#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({300, 300});
    text("Track bar example");
    
    progress_bar1.location({80, 50});
    progress_bar1.maximum(200);
    progress_bar1.orientation(forms::orientation::vertical);
    progress_bar1.parent(*this);
    progress_bar1.size({23, 200});
    
    label1.location({150, 50});
    label1.parent(*this);

    track_bar1.location({50, 50});
    track_bar1.maximum(200);
    track_bar1.auto_size(false);
    track_bar1.orientation(forms::orientation::vertical);
    track_bar1.parent(*this);
    track_bar1.value_changed += [&] {
      progress_bar1.value(track_bar1.value());
      label1.text(ustring::format("{}", track_bar1.value()));
    };
    track_bar1.value(100);
    track_bar1.tick_style(forms::tick_style::none);
    track_bar1.size({25, 200});
  }
  
private:
  track_bar track_bar1;
  progress_bar progress_bar1;
  label label1;
};

int main() {
  application::run(form1());
}
