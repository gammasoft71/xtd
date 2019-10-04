#include <utility>
#include <vector>
#include <xtd/ustring.hpp>
#include <xtd/forms/application.hpp>
#include <xtd/forms/form.hpp>
#include <xtd/forms/label.hpp>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Labels and Unicode text example");
    client_size({400, 350});

    for (int index = 0; index < languages.size(); ++index) {
      items[index].first.location(point(10, 10 + index * 30)).parent(*this).text(languages[index].first).width(150);
      items[index].second.location(point(160, 10 + index * 30)).parent(*this).text(languages[index].second).width(220);
    }
  }

private:
  vector<pair<ustring, ustring>> languages {{"Arabic", L"\u0627\u0644\u0643\u0644\u0645\u0629 \u0627\u0644\u0639\u0631\u0628\u064A\u0629"}, {"Trad. Chinese", L"\u4E2D\u570B\u7684\u6F22\u5B57"}, {"Simpl. Chinese:", L"\u6C49\u8BED"}, {"French", L"Langue fran\u00E7aise"}, {"Greek", L"\u0395\u03BB\u03BB\u03B7\u03BD\u03B9\u03BA\u03AE \u03B3\u03BB\u03CE\u03C3\u03C3\u03B1"}, {"Hebrew", L"\u05DB\u05EA\u05D1 \u05E2\u05D1\u05E8\u05D9\u05EA"}, {"Hindi", L"\u0939\u093f\u0928\u094d\u0926\u0940 \u092d\u093e\u0937\u093e"}, {"Icelandic", L"\u00CDslenska"}, {"Japanese", L"\u65E5\u672C\u8A9E\u306E\u3072\u3089\u304C\u306A, \u6F22\u5B57\u3068\u30AB\u30BF\u30AB\u30CA"}, {"Korean", L"\uB300\uD55C\uBBFC\uAD6D\uC758 \uD55C\uAE00"}, {"Russian", L"\u0420\u0443\u0441\u0441\u043A\u0438\u0439 \u044F\u0437\u044B\u043A"}};
  vector<pair<label, label>> items {languages.size()};
};

int main() {
  application::run(form1());
}
