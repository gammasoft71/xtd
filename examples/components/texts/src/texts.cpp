#include <xtd/xtd.forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Texts example");
    client_size({200, 400});
    *this << list_box_texts;

    list_box_texts.dock(dock_style::fill);
    list_box_texts.items().push_back_range({texts::abort, texts::about, texts::actual_size, texts::add, texts::align_left, texts::align_right, texts::alignment, texts::apply, texts::ascending, texts::back, texts::bold, texts::bottom, texts::cancel, texts::cdrom, texts::centered, texts::clear, texts::close, texts::color, texts::contents, texts::convert, texts::copy, texts::customize, texts::cut, texts::del, texts::descending, texts::down, texts::edit, texts::execute, texts::file, texts::find, texts::first, texts::floppy, texts::font, texts::forward, texts::harddisk, texts::help, texts::home, texts::ignore, texts::indent, texts::index, texts::info, texts::italic, texts::jump_to, texts::justified, texts::last, texts::network, texts::new_, texts::no, texts::ok, texts::open, texts::options, texts::paste, texts::preferences, texts::print, texts::print_preview, texts::properties, texts::quit, texts::redo, texts::refresh, texts::remove, texts::replace, texts::retry, texts::revert_to_saved, texts::save, texts::save_as, texts::search, texts::select_all, texts::spell_check, texts::stop, texts::strikeout, texts::tools, texts::top, texts::undelete, texts::underline, texts::undo, texts::unindent, texts::up, texts::view, texts::yes, texts::zoom_in, texts::zoom_out, texts::zoom_to_fit});
  }
  
private:
  list_box list_box_texts;
};

int main() {
  application::run(form1());
}
