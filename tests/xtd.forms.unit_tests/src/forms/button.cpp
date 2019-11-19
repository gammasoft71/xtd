#include <xtd/xtd.forms>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd::forms;
using namespace xtd::tunit;

namespace unit_tests {
  class test_class_(test_button) {
  public:
    void test_method_(perform_click_form_button) {
      form form;
      button button;
      button.parent(form);
      int click_control_check = 0;
      button.click += [&] {
        click_control_check += 1;
      };
      button.perform_click();
      assert::are_equal_(1, click_control_check);
    }

    void test_method_(send_message_button_click_form_panel_button) {
      form form;
      panel panel;
      panel.parent(form);
      button button;
      button.parent(panel);
      int click_control_check = 0;
      button.click += [&] {
        click_control_check += 1;
      };
      send_message(button.handle(), WM_COMMAND, BN_CLICKED, button.handle());
      assert::are_equal_(1, click_control_check);
    }
  };
}
