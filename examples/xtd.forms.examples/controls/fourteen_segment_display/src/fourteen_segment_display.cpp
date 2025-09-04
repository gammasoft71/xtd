#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    fourteen_segment_display1.height(250);
    fourteen_segment_display1.location({(client_size().width - fourteen_segment_display1.width()) / 2, (client_size().height - fourteen_segment_display1.height()) / 2});
    fourteen_segment_display1.parent(*this);
    fourteen_segment_display1.fore_color(color::red);
    fourteen_segment_display1.anchor(anchor_styles::top | anchor_styles::bottom);
    
    timer1.interval(300_ms);
    timer1.enabled(true);
    timer1.tick += delegate_ {
      fourteen_segment_display1.segment_style(segment_styles[(counter / chase.count()) % segment_styles.count()]);
      fourteen_segment_display1.value(chase[counter++ % chase.count()]);
    };
    
    back_color(color_converter::average(color::black, fourteen_segment_display1.fore_color(), 0.20));
    text("Fourteen segment display example");
    resize += delegate_ {
      fourteen_segment_display1.left((client_size().width - fourteen_segment_display1.width()) / 2);
    };
  }
  
private:
  int counter = 0;
  array<segments> chase = {
    segments::none,
    segments::a,
    segments::a | segments::b,
    segments::a | segments::b | segments::c,
    segments::a | segments::b | segments::c | segments::d,
    segments::a | segments::b | segments::c | segments::d | segments::e,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g1,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g1 | segments::g2,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g1 | segments::g2 | segments::h,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i | segments::j,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i | segments::j | segments::k,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i | segments::j | segments::k | segments::l,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g1 | segments::g2 | segments::h | segments::i | segments::j | segments::k | segments::l | segments::m,
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
  fourteen_segment_display fourteen_segment_display1;
  forms::timer timer1;
};

auto main() -> int {
  application::run(form1 {});
}
