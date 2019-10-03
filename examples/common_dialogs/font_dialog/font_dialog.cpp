#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Font dialog test");
    client_size({400, 400});
    controls().push_back_range({button1, label1});

    button1.location({10, 10});
    button1.text("Font...");
    button1.click += [this] {
      font_dialog font_dialog;
      font_dialog.color(this->label1.fore_color());
      font_dialog.font(this->label1.font());
      if (font_dialog.show_dialog() == forms::dialog_result::ok) {
        label1.fore_color(font_dialog.color());
        label1.font(font_dialog.font());
      }
    };

    label1.location({10, 50});
    label1.size({380, 340});
    label1.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
    label1.text(L"The quick brown fox jumps over the lazy dog.\n"
    L"THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
    L"0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
    L"àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
    L"\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
    L"\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
    L"\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
    L"\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
    L"\U0001F428");
  }
  
private:
  button button1;
  label label1;
};

int main() {
  application::run(form1());
}
