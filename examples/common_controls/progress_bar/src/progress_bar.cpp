#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Progress bar example");
      this->client_size({300, 300});

      this->progress_bar1.parent(*this);
      this->progress_bar1.location({50, 50});
      this->progress_bar1.width(200);

      this->progress_bar2.parent(*this);
      this->progress_bar2.location({50, 80});
      this->progress_bar2.value(50);
      this->progress_bar2.width(200);

      this->progress_bar3.parent(*this);
      this->progress_bar3.location({50, 110});
      this->progress_bar3.maximum(300);
      this->progress_bar3.increment(300);
      this->progress_bar3.width(200);

      this->progress_bar4.parent(*this);
      this->progress_bar4.location({50, 140});
      this->progress_bar4.step(1);
      this->progress_bar4.width(200);

      this->progress_bar5.parent(*this);
      this->progress_bar5.location({50, 170});
      this->progress_bar5.maximum(200);
      this->progress_bar5.minimum(100);
      this->progress_bar5.style(progress_bar_style::marquee);
      this->progress_bar5.width(200);
      
      this->timer1.interval(50);
      this->timer1.tick += [&] {
        if (this->progress_bar4.value() == this->progress_bar4.maximum())
          this->progress_bar4.value(this->progress_bar4.minimum());
        else
          progress_bar4.perform_step();
      };
      this->timer1.enabled(true);
    }
    
  private:
    progress_bar progress_bar1;
    progress_bar progress_bar2;
    progress_bar progress_bar3;
    progress_bar progress_bar4;
    progress_bar progress_bar5;
    timer timer1;
  };
}

int main() {
  application::run(examples::form1());
}
