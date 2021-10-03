#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Texts example");
    client_size({200, 400});
    *this << list_box_texts;

    list_box_texts.dock(dock_style::fill);
    list_box_texts.items().push_back_range({system_texts::abort(), system_texts::about(), system_texts::actual_size(), system_texts::add(), system_texts::align_left(), system_texts::align_right(), system_texts::alignment(), system_texts::apply(), system_texts::ascending(), system_texts::back(), system_texts::bold(), system_texts::bottom(), system_texts::cancel(), system_texts::cdrom(), system_texts::centered(), system_texts::clear(), system_texts::close(), system_texts::color(), system_texts::contents(), system_texts::convert(), system_texts::copy(), system_texts::customize(), system_texts::cut(), system_texts::del(), system_texts::descending(), system_texts::down(), system_texts::edit(), system_texts::execute(), system_texts::file(), system_texts::find(), system_texts::first(), system_texts::floppy(), system_texts::font(), system_texts::forward(), system_texts::harddisk(), system_texts::help(), system_texts::home(), system_texts::ignore(), system_texts::indent(), system_texts::index(), system_texts::info(), system_texts::italic(), system_texts::jump_to(), system_texts::justified(), system_texts::last(), system_texts::network(), system_texts::new_(), system_texts::no(), system_texts::ok(), system_texts::open(), system_texts::options(), system_texts::paste(), system_texts::preferences(), system_texts::print(), system_texts::print_preview(), system_texts::properties(), system_texts::quit(), system_texts::redo(), system_texts::refresh(), system_texts::remove(), system_texts::replace(), system_texts::retry(), system_texts::revert_to_saved(), system_texts::save(), system_texts::save_as(), system_texts::search(), system_texts::select_all(), system_texts::spell_check(), system_texts::stop(), system_texts::strikeout(), system_texts::tools(), system_texts::top(), system_texts::undelete(), system_texts::underline(), system_texts::undo(), system_texts::unindent(), system_texts::up(), system_texts::view(), system_texts::yes(), system_texts::zoom_in(), system_texts::zoom_out(), system_texts::zoom_to_fit()});
  }
  
private:
  list_box list_box_texts;
};

int main() {
  application::run(form1());
}
