#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    sixteen_segment_display1.height(250);
    sixteen_segment_display1.location({(client_size().width() - sixteen_segment_display1.width()) / 2, (client_size().height() - sixteen_segment_display1.height()) / 2});
    sixteen_segment_display1.parent(*this);
    sixteen_segment_display1.fore_color(color::red);
    sixteen_segment_display1.anchor(anchor_styles::top|anchor_styles::bottom);
    
    timer1.interval(300);
    timer1.enabled(true);
    timer1.tick += [&] {
      sixteen_segment_display1.segment_style(segment_styles[(counter / chaser.size()) % segment_styles.size()]);
      sixteen_segment_display1.value(chaser[counter++ % chaser.size()]);
    };
    
    back_color(color::average(color::black, sixteen_segment_display1.fore_color(), 0.20));
    text("Sixteen segment display example");
    resize += [&] {
      sixteen_segment_display1.left((client_size().width() - sixteen_segment_display1.width()) / 2);
    };
  }
  
private:
  int counter = 0;
  std::vector<segments> chaser = {
    segments::a1|segments::a2|segments::b|segments::c|segments::d1|segments::d2|segments::e|segments::f|segments::g1|segments::g2|segments::h|segments::i|segments::j|segments::k|segments::l|segments::m,
    segments::none,
    segments::a1|segments::a2|segments::b|segments::c|segments::d1|segments::d2|segments::e|segments::f|segments::g1|segments::g2|segments::h|segments::i|segments::j|segments::k|segments::l|segments::m,
    segments::none,
    segments::a1|segments::a2|segments::b|segments::c|segments::d1|segments::d2|segments::e|segments::f|segments::g1|segments::g2|segments::h|segments::i|segments::j|segments::k|segments::l|segments::m,
    segments::a1,segments::a2, segments::b, segments::c, segments::d2, segments::d1, segments::e, segments::f, segments::a1, segments::a2, segments::b, segments::c, segments::d2, segments::d1, segments::e, segments::f,
    segments::i|segments::l, segments::j|segments::k, segments::g1|segments::g2, segments::h|segments::m, segments::i|segments::l, segments::j|segments::k, segments::g1|segments::g2, segments::h|segments::m, segments::i|segments::l, segments::dp, segments::pc};
  std::vector<segment_style> segment_styles = {segment_style::standard, segment_style::modern, segment_style::mixed, segment_style::expanded, segment_style::design, segment_style::stick};
  sixteen_segment_display sixteen_segment_display1;
  timer timer1;
};

int main() {
  application::run(form1());
}
