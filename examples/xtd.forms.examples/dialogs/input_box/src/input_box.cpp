#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Input box example");
      controls().push_back_range({button1, label1});

      button1.location({10, 10});
      button1.text("Text...");
      button1.click += [&] {
        ustring value = label1.text();
        if (input_box::show(value, *this, "Message text", "Caption text") == dialog_result::ok)
          label1.text(value);
      };

      label1.location({10, 50});
      label1.auto_size(true);
      label1.text("Default value");
    }

  private:
    button button1;
    label label1;
  };
}

int main() {
  application::run(examples::form1());
}
