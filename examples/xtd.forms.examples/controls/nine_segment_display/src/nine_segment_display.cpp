#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    nine_segment_display1.height(250);
    nine_segment_display1.location({(client_size().width - nine_segment_display1.width()) / 2, (client_size().height - nine_segment_display1.height()) / 2});
    nine_segment_display1.parent(*this);
    nine_segment_display1.fore_color(color::red);
    nine_segment_display1.anchor(anchor_styles::top | anchor_styles::bottom);
    
    timer1.interval(300_ms);
    timer1.enabled(true);
    timer1.tick += delegate_ {
      nine_segment_display1.segment_style(segment_styles[(counter / chase.count()) % segment_styles.count()]);
      nine_segment_display1.value(chase[counter++ % chase.count()]);
    };
    
    back_color(color_converter::average(color::black, nine_segment_display1.fore_color(), 0.20));
    text("Nine segment display example");
    resize += delegate_ {
      nine_segment_display1.left((client_size().width - nine_segment_display1.width()) / 2);
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
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g | segments::h,
    segments::a | segments::b | segments::c | segments::d | segments::e | segments::f | segments::g | segments::h | segments::i,
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
  nine_segment_display nine_segment_display1;
  forms::timer timer1;
};

auto main() -> int {
  application::run(form1 {});
}
