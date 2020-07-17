#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({400, 100});
    controls().push_back_range({track_bar1, button1});
    text("Track bar 2 example");
    
    track_bar1.auto_size(false);
    track_bar1.bounds({40, 10, 200, 80});
    track_bar1.set_range(0, 100);
    track_bar1.value_changed += [&] {
      if (muted && track_bar1.value()) muted = false;
      if (!muted || track_bar1.value()) volume = track_bar1.value();

      if (track_bar1.value() == 0) button1.image(button_images::from_name("audio-volume-muted", drawing::size {64, 64}));
      else if (track_bar1.value() < 30) button1.image(button_images::from_name("audio-volume-low", drawing::size {64, 64}));
      else if (track_bar1.value() < 80) button1.image(button_images::from_name("audio-volume-medium", drawing::size {64, 64}));
      else button1.image(button_images::from_name("audio-volume-high", drawing::size {64, 64}));
     };
    track_bar1.value(60);

    button1.bounds({280, 10, 80, 80});
    button1.click += [&] {
      muted = !muted;
      track_bar1.value(muted ?  0 : volume);
    };
  }
  
  static void main() {
    application::run(form1());
  }

private:
  bool muted = false;
  int volume = 0;
  track_bar track_bar1;
  button button1;
};

startup_(form1);
