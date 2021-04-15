#include <xtd/xtd>

using namespace std::literals;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    fourteen_segment_display1.height(250);
    fourteen_segment_display1.location({(client_size().width() - fourteen_segment_display1.width()) / 2, (client_size().height() - fourteen_segment_display1.height()) / 2});
    fourteen_segment_display1.parent(*this);
    fourteen_segment_display1.fore_color(color::red);
    fourteen_segment_display1.anchor(anchor_styles::top|anchor_styles::bottom);
    
    timer1.interval(300ms);
    timer1.enabled(true);
    timer1.tick += [&] {
      fourteen_segment_display1.segment_style(segment_styles[(counter / chaser.size()) % segment_styles.size()]);
      fourteen_segment_display1.value(chaser[counter++ % chaser.size()]);
    };
    
    back_color(color::average(color::black, fourteen_segment_display1.fore_color(), 0.20));
    text("Fourteen segment display example");
    resize += [&] {
      fourteen_segment_display1.left((client_size().width() - fourteen_segment_display1.width()) / 2);
    };
  }
  
private:
  int counter = 0;
  std::vector<segments> chaser = {
    segments::none,
    segments::a,
    segments::a|segments::b,
    segments::a|segments::b|segments::c,
    segments::a|segments::b|segments::c|segments::d,
    segments::a|segments::b|segments::c|segments::d|segments::e,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g1,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g1|segments::g2,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g1|segments::g2|segments::h,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g1|segments::g2|segments::h|segments::i,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g1|segments::g2|segments::h|segments::i|segments::j,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g1|segments::g2|segments::h|segments::i|segments::j|segments::k,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g1|segments::g2|segments::h|segments::i|segments::j|segments::k|segments::l,
    segments::a|segments::b|segments::c|segments::d|segments::e|segments::f|segments::g1|segments::g2|segments::h|segments::i|segments::j|segments::k|segments::l|segments::m,
    segments::dp,
    segments::pc
  };
  std::vector<segment_style> segment_styles = {
    segment_style::standard,
    segment_style::modern,
    segment_style::mixed,
    segment_style::expanded,
    segment_style::design,
    segment_style::stick
  };
  fourteen_segment_display fourteen_segment_display1;
  timer timer1;
};

int main() {
  application::run(form1());
}
