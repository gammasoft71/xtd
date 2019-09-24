#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("Cursor example");
    this->client_size({400, 240});

    this->list_box_cursors.parent(*this);
    this->list_box_cursors.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);
    this->list_box_cursors.bounds({20, 20, 150, 200});
    this->list_box_cursors.items().push_back_range({{"Application Starting", cursors::app_starting()}, {"Arrow", cursors::arrow()}, {"Close hand", cursors::close_hand()}, {"Contextual menu", cursors::contextual_menu()}, {"Cross", cursors::cross()}, {"Default cursor", cursors::default_cursor()}, {"Disappearing item", cursors::disappearing_item()}, {"Drag copy", cursors::drag_copy()}, {"Drag link", cursors::drag_link()}, {"Hand", cursors::hand()}, {"Help", cursors::help()}, {"Horizontal split", cursors::hsplit()}, {"I beam", cursors::ibeam()}, {"No", cursors::no()}, {"No move 2d", cursors::no_move_2d()}, {"No move horizontal", cursors::no_move_horiz()}, {"No move vertical", cursors::no_move_vert()}, {"Open hand", cursors::open_hand()}, {"Pan east", cursors::pan_east()}, {"Pan north east", cursors::pan_ne()}, {"Pan north", cursors::pan_north()}, {"Pan north west", cursors::pan_nw()}, {"Pan south", cursors::pan_south()}, {"Pan south west", cursors::pan_sw()}, {"Pan West", cursors::pan_west()}, {"Size all", cursors::size_all()}, {"Size north-east south-west", cursors::size_nesw()}, {"Size north south", cursors::size_ns()}, {"Size north-west south-east", cursors::size_nwse()}, {"Up arrow", cursors::up_arrow()}, {"Vertical I beam", cursors::vibeam()}, {"Vertical split", cursors::vsplit()}, {"Wait cursor", cursors::wait_cursor()}});
    this->list_box_cursors.selected_index_changed += [this] {
      this->panel_test_zone.cursor(any_cast<forms::cursor>(this->list_box_cursors.selected_item().tag()));
      cdebug << format("cursor = {}", this->panel_test_zone.cursor()) << endl;
    };

    this->panel_test_zone.parent(*this);
    this->panel_test_zone.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
    this->panel_test_zone.border_style(border_style::fixed_3d);
    this->panel_test_zone.back_color(drawing::system_colors::window());
    this->panel_test_zone.bounds({190, 20, 190, 160});

    this->button_move_up_left.parent(*this);
    this->button_move_up_left.anchor(anchor_styles::right | anchor_styles::bottom);
    this->button_move_up_left.location({190, 200});
    this->button_move_up_left.text("To Up/Left");
    this->button_move_up_left.click += [&] {
      forms::cursor::position({0, 0});
    };
      
     this->button_show_hide.parent(*this);
     this->button_show_hide.anchor(anchor_styles::right | anchor_styles::bottom);
     this->button_show_hide.location({305, 200});
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


