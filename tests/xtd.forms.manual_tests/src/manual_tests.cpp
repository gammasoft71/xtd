#include <xtd/xtd.forms>
#include "address_book_new_32x32.xpm"
#include "appointment_new_32x32.xpm"
#include "gammasoft_32x32.xpm"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int main() {
  bitmap bmp(128, 128);
  
  for (int y = 0; y < bmp.height(); y++)
    for (int x = 0; x < bmp.width(); x++)
      if (bmp.get_pixel(x, y) != color::from_argb(0, 0, 0, 0))
        std::cout <<format("x = {}, y = {}  color = {,-34}", x, y, bmp.get_pixel(x, y)) << std::endl;
  
  /*
  form form_main;
  form_main.text("Manual tests");

  image_list pictures;
  pictures.image_size({64, 64});
  pictures.images().push_back_range({address_book_new_32x32, appointment_new_32x32, gammasoft_32x32});
  
  button button;
  button.parent(form_main);
  button.location({10, 10});
  button.size({80, 80});
  button.image_list(pictures);
  button.image_index(2);
  //button.image(drawing::image::from_data(gammasoft_32x32));

  application::run(form_main);
   */
}
