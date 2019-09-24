#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("Cursor example");
    this->client_size({420, 240});

    this->list_box_cursors.parent(*this);
    this->list_box_cursors.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);
    this->list_box_cursors.bounds({20, 20, 170, 200});
    this->list_box_cursors.items().push_back_range({cursors::app_starting(), cursors::arrow(), cursors::close_hand(), cursors::contextual_menu(), cursors::cross(), cursors::default_cursor(), cursors::disappearing_item(), cursors::drag_copy(), cursors::drag_link(), cursors::hand(), cursors::help(), cursors::hsplit(), cursors::ibeam(), cursors::no(), cursors::no_move_2d(), cursors::no_move_horiz(), cursors::no_move_vert(), cursors::open_hand(), cursors::pan_east(), cursors::pan_ne(), cursors::pan_north(), cursors::pan_nw(), cursors::pan_south(), cursors::pan_sw(), cursors::pan_west(), cursors::size_all(), cursors::size_nesw(), cursors::size_ns(), cursors::size_nwse(), cursors::up_arrow(), cursors::vibeam(), cursors::vsplit(), cursors::wait_cursor()});
    this->list_box_cursors.selected_index(5);
    this->list_box_cursors.selected_index_changed += [this] {
      this->panel_test_zone.cursor(any_cast<forms::cursor>(this->list_box_cursors.selected_item().tag()));
      cdebug << format("cursor = {}", this->panel_test_zone.cursor()) << endl;
    };

    this->panel_test_zone.parent(*this);
    this->panel_test_zone.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
    this->panel_test_zone.border_style(border_style::fixed_3d);
    this->panel_test_zone.back_color(drawing::system_colors::window());
    this->panel_test_zone.bounds({210, 20, 190, 160});

    this->button_move_up_left.parent(*this);
    this->button_move_up_left.anchor(anchor_styles::right | anchor_styles::bottom);
    this->button_move_up_left.location({210, 200});
    this->button_move_up_left.text("To Up/Left");
    this->button_move_up_left.click += [&] {
      forms::cursor::position({0, 0});
    };
      
     this->button_show_hide.parent(*this);
     this->button_show_hide.anchor(anchor_styles::right | anchor_styles::bottom);
     this->button_show_hide.location({325, 200});
     this->button_show_hide.text("Hide");
     this->button_show_hide.click += [&] {
       forms::cursor::hide();
       this->button_show_hide.enabled(false);
       this->button_show_hide.text(strings::format("Show in {}s", this->cursor_hidden_duration));
       this->timer_show_cursor.enabled(true);
     };

    this->timer_show_cursor.interval(1000);
    this->timer_show_cursor.tick += [&] {
      static int duration = 0;
      if (++duration < this->cursor_hidden_duration)
        this->button_show_hide.text(strings::format("Show in {}s", this->cursor_hidden_duration - duration));
      else {
        forms::cursor::show();
        this->button_show_hide.enabled(true);
        this->button_show_hide.text("Hide");
        this->timer_show_cursor.enabled(false);
        duration = 0;
      }
    };
  }
  
private:
  timer timer_show_cursor;
  list_box list_box_cursors;
  panel panel_test_zone;
  button button_show_hide;
  button button_move_up_left;
  const int cursor_hidden_duration = 3;
};

int main() {
  application::run(form1());
}


