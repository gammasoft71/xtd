#include <xtd/xtd>

auto create_circle_texture(const color& fore_color, const color& back_color)->image {
  auto texture = bitmap {16, 16};
  auto graphics = texture.create_graphics();
  graphics.fill_ellipse(solid_brush {back_color}, 1, 1, texture.width() - 2, texture.height() - 2);
  graphics.draw_ellipse(pen {fore_color, 2}, 1, 1, texture.width() - 2, texture.height() - 2);
  return texture;
}

auto main() -> int {
  auto form1 = form::create("form1");
  form1.paint += delegate_(object& sender, paint_event_args& e) {
    auto g = e.graphics();

    //g.fill_closed_curve(solid_brush {color::red}, array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});
    //g.fill_closed_curve(drawing_2d::hatch_brush(drawing_2d::hatch_style::wide_checker_board, color::white, color::blue), array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});
    //g.fill_closed_curve(texture_brush {create_circle_texture(color::white, color::blue)}, array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});
    //g.fill_closed_curve(drawing_2d::linear_gradient_brush {e.clip_rectangle(), color::white, color::blue, 45}, array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});
    g.fill_closed_curve(drawing_2d::conical_gradient_brush {point {e.clip_rectangle().width / 2, e.clip_rectangle().height / 2}, color::blue, color::white, 0}, array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});

    //g.fill_ellipse(solid_brush {color::blue},  30, 50, 200, 200);
    //g.fill_ellipse(drawing_2d::hatch_brush(drawing_2d::hatch_style::wide_checker_board, color::white, color::blue),  30, 50, 200, 200);
    //g.fill_ellipse(texture_brush {create_circle_texture(color::white, color::blue)},  30, 50, 200, 200);
    //g.fill_ellipse(drawing_2d::linear_gradient_brush {e.clip_rectangle(), color::white, color::blue, 45},  30, 50, 200, 200);
    //g.fill_ellipse(drawing_2d::conical_gradient_brush {point {e.clip_rectangle().width / 2, e.clip_rectangle().height / 2}, color::blue, color::white, 0}, 30, 50, 200, 200);

    //g.fill_pie(solid_brush {color::blue}, 30, 50, 200, 200, 45, 270);
    //g.fill_pie(drawing_2d::hatch_brush(drawing_2d::hatch_style::wide_checker_board, color::white, color::blue), 30, 50, 200, 200 45, 270);
    //g.fill_pie(texture_brush {create_circle_texture(color::white, color::blue)}, 30, 50, 200, 200, 45, 270);
    //g.fill_pie(drawing_2d::linear_gradient_brush {e.clip_rectangle(), color::white, color::blue, 45}, 30, 50, 200, 200, 45, 270);
    //g.fill_pie(drawing_2d::conical_gradient_brush {point {e.clip_rectangle().width / 2, e.clip_rectangle().height / 2}, color::blue, color::white, 0},  30, 50, 200, 200, 45, 270);

    //auto path = drawing_2d::graphics_path {};
    //path.add_rectangle(30, 50, 200, 200);
    //g.fill_path(solid_brush {color::blue}, path);
    
    //g.fill_polygon(solid_brush {color::blue}, array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});
    //g.fill_polygon(drawing_2d::hatch_brush(drawing_2d::hatch_style::wide_checker_board, color::white, color::blue), array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});
    //g.fill_polygon(texture_brush {create_circle_texture(color::white, color::blue)}, array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});
    //g.fill_polygon(drawing_2d::linear_gradient_brush {e.clip_rectangle(), color::white, color::blue, 45}, array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});
    //g.fill_polygon(drawing_2d::conical_gradient_brush {point {e.clip_rectangle().width / 2, e.clip_rectangle().height / 2}, color::blue, color::white, 0}, array<point> {{50, 50}, {250, 100}, {200, 250}, {100, 200}});

    //g.fill_rectangle(solid_brush {color::blue}, 30, 50, 200, 200);
    //g.fill_rectangle(drawing_2d::hatch_brush(drawing_2d::hatch_style::wide_checker_board, color::white, color::blue), 30, 50, 200, 200);
    //g.fill_rectangle(texture_brush {create_circle_texture(color::white, color::blue)}, 30, 50, 200, 200);
    //g.fill_rectangle(drawing_2d::linear_gradient_brush {e.clip_rectangle(), color::white, color::blue, 45}, 30, 50, 200, 200);
    //g.fill_rectangle(drawing_2d::conical_gradient_brush {point {e.clip_rectangle().width / 2, e.clip_rectangle().height / 2}, color::blue, color::white, 0},  30, 50, 200, 200);

    //g.fill_rounded_rectangle(solid_brush {color::blue}, 30, 50, 200, 200, 10);
    //g.fill_rounded_rectangle(drawing_2d::hatch_brush(drawing_2d::hatch_style::wide_checker_board, color::white, color::blue), 30, 50, 200, 200, 10);
    //g.fill_rounded_rectangle(texture_brush {create_circle_texture(color::white, color::blue)}, 30, 50, 200, 200, 10);
    //g.fill_rounded_rectangle(drawing_2d::linear_gradient_brush {e.clip_rectangle(), color::white, color::blue, 45}, 30, 50, 200, 200, 10);
    //g.fill_rounded_rectangle(drawing_2d::conical_gradient_brush {point {e.clip_rectangle().width / 2, e.clip_rectangle().height / 2}, color::blue, color::white, 0},  30, 50, 200, 200, 10);
  };
  application::run(form1);
}
