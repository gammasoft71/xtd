#include <xtd/xtd>

class example {
public:
  static auto main() -> void {
    auto lpf = list<drawing::point_f> {};
    
    lpf.add(drawing::point_f {27.8f, 32.62f});
    lpf.add(drawing::point_f {99.3f, 147.273f});
    lpf.add(drawing::point_f {7.5f, 1412.2f});
    
    console::write_line();
    for (const auto& p : lpf)
      console::write_line(p);
    
    list<drawing::point> lp = lpf.convert_all(converter<drawing::point, const drawing::point_f&> {point_f_to_point});
    
    console::write_line();
    for (const auto& p : lp)
      console::write_line(p);
  }

  static drawing::point point_f_to_point(const drawing::point_f& pf) {
    return {as<int>(pf.x), as<int>(pf.y)};
  }
};

startup_(example::main);

// This code produces the following output :
//
//
// {x=27.8, y=32.62}
// {x=99.3, y=147.273}
// {x=7.5, y=1412.2}
//
// {x=28, y=33}
// {x=99, y=147}
// {x=8, y=1412}
