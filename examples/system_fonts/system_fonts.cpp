#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  cout << format("caption_font       : {}", system_fonts::caption_font()) << endl;
  cout << format("default_font       : {}", system_fonts::default_font()) << endl;
  cout << format("dialog_font        : {}", system_fonts::dialog_font()) << endl;
  cout << format("icon_title_font    : {}", system_fonts::icon_title_font()) << endl;
  cout << format("menu_font          : {}", system_fonts::menu_font()) << endl;
  cout << format("message_box_font   : {}", system_fonts::message_box_font()) << endl;
  cout << format("small_caption_font : {}", system_fonts::small_caption_font()) << endl;
  cout << format("status_font        : {}", system_fonts::status_font()) << endl;
}
