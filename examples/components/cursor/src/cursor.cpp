#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("Cursor example");
    this->start_position(form_start_position::manual);
    this->location({200, 200});
    this->client_size({360, 240});

    this->list_box_cursors.parent(*this);
    this->list_box_cursors.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);
    this->list_box_cursors.bounds({20, 20, 150, 200});
    this->list_box_cursors.items().push_back_range({{"Application Starting", cursors::app_starting()}, {"Arrow", cursors::arrow()}, {"Close hand", cursors::close_hand()}, {"Contextual menu", cursors::contextual_menu()}, {"Cross", cursors::cross()}, {"Default cursor", cursors::default_cursor()}, {"Disappearing item", cursors::disappearing_item()}, {"Drag copy", cursors::drag_copy()}, {"Drag link", cursors::drag_link()}, {"Hand", cursors::hand()}, {"Help", cursors::help()}, {"Horizontal split", cursors::hsplit()}, {"I beam", cursors::ibeam()}, {"No", cursors::no()}, {"No move 2d", cursors::no_move_2d()}, {"No move horizontal", cursors::no_move_horiz()}, {"No move vertical", cursors::no_move_vert()}, {"Open hand", cursors::open_hand()}, {"Pan east", cursors::pan_east()}, {"Pan north east", cursors::pan_ne()}, {"Pan north", cursors::pan_north()}, {"Pan north west", cursors::pan_nw()}, {"Pan south", cursors::pan_south()}, {"Pan south west", cursors::pan_sw()}, {"Pan West", cursors::pan_west()}, {"Size all", cursors::size_all()}, {"Size north-east south-west", cursors::size_nesw()}, {"Size north south", cursors::size_ns()}, {"Size north-west south-east", cursors::size_nwse()}, {"Up arrow", cursors::up_arrow()}, {"Vertical I beam", cursors::vibeam()}, {"Vertical split", cursors::vsplit()}, {"Wait cursor", cursors::wait_cursor()}});
    this->list_box_cursors.selected_index(5);
    this->list_box_cursors.selected_index_changed += [this] {
      this->test_zone.cursor(any_cast<forms::cursor>(this->list_box_cursors.selected_item().tag()));
    };

    this->test_zone.parent(*this);
    this->test_zone.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
    this->test_zone.border_style(border_style::fixed_3d);
    this->test_zone.back_color(drawing::system_colors::window());
    this->test_zone.bounds({190, 20, 150, 200});
  }
  
private:
  list_box list_box_cursors;
  panel test_zone;
};

int main() {
  application::run(form1());
}
