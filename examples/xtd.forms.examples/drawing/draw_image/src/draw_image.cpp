#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/images>
#include <xtd/math>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form_main : public form {
public:
  form_main() {
    text("Draw image example");
  }
  
protected:
  void on_paint(paint_event_args& e) override {
    form::on_paint(e);
    
    auto image_size = math::min(e.clip_rectangle().width(), e.clip_rectangle().height());
    auto image_rect = rectangle((e.clip_rectangle().width() - image_size) / 2, (e.clip_rectangle().height() - image_size) / 2, image_size, image_size);
    e.graphics().draw_image(image, image_rect);
  }
  
private:
  xtd::drawing::image image = images::from_name("system-file-manager", xtd::drawing::size {1024, 1024});
};

auto main()->int {
  application::run(form_main());
}
