#include <xtd/diagnostics/process>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/link_label>
#include <filesystem>

using namespace std::filesystem;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

namespace link_label_example {
  class form1 : public form {
  public:
    form1() {
      text("Link label example");
      client_size({400, 200});
      
      link_label1.location({10, 10});
      link_label1.auto_size(true);
      link_label1.parent(*this);
      link_label1.text("xtd Reference Guide");
      link_label1.link_clicked += [](object & sender, link_label_clicked_event_args & e) {
        e.visited(true);
        process::start("https://gammasoft71.github.io/xtd/reference_guides/latest/index.html");
      };
      
      link_label2.location({10, 40});
      link_label2.auto_size(true);
      link_label2.parent(*this);
      link_label2.text("Gammasoft presents xtd framework");
      link_label2.links().push_back({0, 9, "https://gammasoft71.wixsite.com/gammasoft"});
      link_label2.links().push_back({19, 3, "https://gammasoft71.github.io/xtd"});
      link_label2.link_clicked += [](object & sender, link_label_clicked_event_args & e) {
        e.visited(true);
        process::start(as<ustring>(e.link().link_data()));
      };
      
      link_label3.location({10, 70});
      link_label3.auto_size(true);
      link_label3.parent(*this);
      link_label3.text("Put your temporary files in the temp directory");
      link_label3.links().push_back({32, 4, temp_directory_path()});
      link_label3.link_clicked += [](object & sender, link_label_clicked_event_args & e) {
        process::start(as<path>(e.link().link_data()).string());
      };
    }
    
  private:
    link_label link_label1;
    link_label link_label2;
    link_label link_label3;
  };
}

auto main() -> int {
  application::run(link_label_example::form1 {});
}
