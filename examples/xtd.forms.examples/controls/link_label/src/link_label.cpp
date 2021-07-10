#include <filesystem>
#include <xtd/xtd>

using namespace std;
using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Link label example");
      client_size({400, 200});

      link_label1.location({10, 10});
      link_label1.auto_size(true);
      link_label1.parent(*this);
      link_label1.text("xtd sources on github");
      link_label1.link_clicked += [](control& sender, link_label_clicked_event_args& e) {
        e.visited(true);
        process::start("https://github.com/gammasoft71/xtd");
      };

      link_label2.location({10, 40});
      link_label2.auto_size(true);
      link_label2.parent(*this);
      link_label2.text("Gammasoft presents xtd framework");
      link_label2.links().push_back({0, 9, "https://gammasoft71.wixsite.com/gammasoft"_s});
      link_label2.links().push_back({19, 3, "https://gammasoft71.wixsite.com/xtdpro"_s});
      link_label2.link_clicked += [](control& sender, link_label_clicked_event_args& e) {
        e.visited(true);
        process::start(as<string>(e.link().link_data()));
      };

      link_label3.location({10, 70});
      link_label3.auto_size(true);
      link_label3.parent(*this);
      link_label3.text("Put your temporary files in the temp directory");
      link_label3.links().push_back({32, 4, temp_directory_path()});
      link_label3.link_clicked += [](control& sender, link_label_clicked_event_args& e) {
        process::start(as<path>(e.link().link_data()).string());
      };
    }
    
  private:
    link_label link_label1;
    link_label link_label2;
    link_label link_label3;
  };
}

int main() {
  application::run(examples::form1());
}
