#include <utility>
#include <vector>
#include <xtd/literals.h>
#include <xtd/drawing/colors.h>
#include <xtd/forms/application.h>
#include <xtd/forms/form.h>
#include <xtd/forms/label.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Labels and Unicode text example");
    client_size({400, 350});
    back_color(colors::dark_cyan());
    fore_color(colors::black());

    for (auto index = 0U; index < languages.size(); ++index) {
      items[index].first.location(point(10, 10 + index * 30)).parent(*this).text(languages[index].first).width(150);
      items[index].second.location(point(160, 10 + index * 30)).parent(*this).text(languages[index].second).width(220).font({items[index].second.font(), font_style::bold});
    }
  }

private:
  vector<pair<ustring, ustring>> languages {
    {"Arabic", u8"\u0627\u0644\u0643\u0644\u0645\u0629 \u0627\u0644\u0639\u0631\u0628\u064A\u0629"},
    {"Trad. Chinese", u8"\u4E2D\u570B\u7684\u6F22\u5B57"},
    {"Simpl. Chinese:", u8"\u6C49\u8BED"},
    {"French", u8"Langue fran\u00E7aise"},
    {"Greek", u8"\u0395\u03BB\u03BB\u03B7\u03BD\u03B9\u03BA\u03AE \u03B3\u03BB\u03CE\u03C3\u03C3\u03B1"},
    {"Hebrew", u8"\u05DB\u05EA\u05D1 \u05E2\u05D1\u05E8\u05D9\u05EA"},
    {"Hindi", u8"\u0939\u093f\u0928\u094d\u0926\u0940 \u092d\u093e\u0937\u093e"},
    {"Icelandic", u8"\u00CDslenska"},
    {"Japanese", u8"\u65E5\u672C\u8A9E\u306E\u3072\u3089\u304C\u306A, \u6F22\u5B57\u3068\u30AB\u30BF\u30AB\u30CA"},
    {"Korean", u8"\uB300\uD55C\uBBFC\uAD6D\uC758 \uD55C\uAE00"},
    {"Russian", u8"\u0420\u0443\u0441\u0441\u043A\u0438\u0439 \u044F\u0437\u044B\u043A"}};
  vector<pair<label, label>> items {languages.size()};
};

int main() {
  application::run(form1());
}
