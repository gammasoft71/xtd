#include <xtd/xtd>

using namespace xtd::drawing;
using namespace xtd::forms;

class form_main : public form {
public:
  form_main() {
    text("Draw image example");
  }
  
protected:
  void on_paint(paint_event_args& e) override {
    auto image_size = std::min(e.clip_rectangle().width(), e.clip_rectangle().height());
    auto image_rect = xtd::drawing::rectangle((e.clip_rectangle().width() - image_size) / 2, (e.clip_rectangle().height() - image_size) / 2, image_size, image_size);
    e.graphics().draw_image(image, image_rect);
    
    form::on_paint(e);
  }
  
private:
  xtd::drawing::image image = system_images::from_name("system-file-manager", xtd::drawing::size {1024, 1024});
};

int main() {
  application::run(form_main());
}
