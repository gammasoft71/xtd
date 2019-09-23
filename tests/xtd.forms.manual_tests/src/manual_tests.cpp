#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
  class cursor_name_pair {
  public:
    cursor_name_pair() {}
    cursor_name_pair(const forms::cursor& cursor, const string& name) : cursor_(cursor), name_(name)  {}
    
    forms::cursor cursor() const {return this->cursor_;}
    string name() const {return this->name_;}
    
    friend std::ostream& operator<<(std::ostream& os, const cursor_name_pair& value) noexcept {return os << value.name();}

  private:
    forms::cursor cursor_ = cursors::default_cursor();
    string name_ = "Default";
  };

public:
  form1() {
    this->text("Cursor example");
    this->client_size({400, 240});

    this->list_box_cursors.parent(*this);
    this->list_box_cursors.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);
    this->list_box_cursors.bounds({20, 20, 150, 200});
    for(auto cursor_name_pair : this->cursor_name_pairs)
      this->list_box_cursors.items().push_back(cursor_name_pair.name());
    this->list_box_cursors.selected_index(5);
    this->list_box_cursors.click += [this] {
      this->panel_test_zone.cursor(this->cursor_name_pairs[this->list_box_cursors.selected_index()].cursor());
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
       forms::cursor::visible(false);
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
  std::vector<cursor_name_pair> cursor_name_pairs = {{cursors::app_starting(), "Application Starting"}, {cursors::arrow(), "Arrow"}, {cursors::close_hand(), "Close hand"}, {cursors::contextual_menu(), "Contextual menu"}, {cursors::cross(), "Cross"}, {cursors::default_cursor(), "Default cursor"}, {cursors::disappearing_item(), "Disappearing item"}, {cursors::drag_copy(), "Drag copy"}, {cursors::drag_link(), "Drag link"}, {cursors::hand(), "Hand"}, {cursors::help(), "Help"}, {cursors::hsplit(), "Horizontal split"}, {cursors::ibeam(), "I beam"}, {cursors::no(), "No"}, {cursors::no_move_2d(), "No move 2d"}, {cursors::no_move_horiz(), "No move horizontal"}, {cursors::no_move_vert(), "No move vertical"}, {cursors::open_hand(), "Open hand"}, {cursors::pan_east(), "Pan east"}, {cursors::pan_ne(), "Pan north east"}, {cursors::pan_north(), "Pan north"}, {cursors::pan_nw(), "Pan north west"}, {cursors::pan_south(), "Pan south"}, {cursors::pan_sw(), "Pan south west"}, {cursors::pan_west(), "Pan West"}, {cursors::size_all(), "Size all"}, {cursors::size_nesw(), "Size north-east south-west"}, {cursors::size_ns(), "Size north south"}, {cursors::size_nwse(), "Size north-west south-east"}, {cursors::up_arrow(), "Up arrow"}, {cursors::vibeam(), "Vertical I beam"}, {cursors::vsplit(), "Vertical split"}, {cursors::wait_cursor(), "Wait cursor"}};
  list_box list_box_cursors;
  panel panel_test_zone;
  button button_show_hide;
  button button_move_up_left;
  timer timer_show_cursor;
  const int cursor_hidden_duration = 3;
};

int main() {
  application::run(form1());
}


