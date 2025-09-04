#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    sixteen_segment_display1.height(250);
    sixteen_segment_display1.location({(client_size().width - sixteen_segment_display1.width()) / 2, (client_size().height - sixteen_segment_display1.height()) / 2});
    sixteen_segment_display1.parent(*this);
    sixteen_segment_display1.fore_color(color::red);
    sixteen_segment_display1.anchor(anchor_styles::top | anchor_styles::bottom);
    
    timer1.interval(300_ms);
    timer1.enabled(true);
    timer1.tick += delegate_ {
      sixteen_segment_display1.segment_style(segment_styles[(counter / chase.count()) % segment_styles.count()]);
      sixteen_segment_display1.value(chase[counter++ % chase.count()]);
    };
    
    back_color(color_converter::average(color::black, sixteen_segment_display1.fore_color(), 0.20));
    text("Sixteen segment display example");
    resize += delegate_ {
      sixteen_segment_display1.left((client_size().width - sixteen_segment_display1.width()) / 2);
    };
  }
  
private:
  int counter = 0;
  array<segments> chase = {
    segments::none,
    segments::a1,
    segments::a1 | segments::a2,
    segments::a1 | segments::a2 | segments::b,
    segments::a1 | segments::a2 | segments::b | segments::c,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d2,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f | segments::g1,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f | segments::g1 | segments::g2,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f | segments::g1 | segments::g2 | segments::h,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i | segments::j,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i | segments::j | segments::k,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i | segments::j | segments::k | segments::l,
    segments::a1 | segments::a2 | segments::b | segments::c | segments::d1 | segments::d2 | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i | segments::j | segments::k | segments::l | segments::m,
    segments::dp,
    segments::pc
  };
  array<segment_style> segment_styles = {
    segment_style::standard,
    segment_style::modern,
    segment_style::mixed,
    segment_style::expanded,
    segment_style::design,
    segment_style::stick
  };
  sixteen_segment_display sixteen_segment_display1;
  forms::timer timer1;
};

auto main() -> int {
  application::run(form1 {});
}
