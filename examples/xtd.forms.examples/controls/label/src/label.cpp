#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/label>

using namespace xtd::forms;

namespace label_example {
  class form1 : public form {
  public:
    form1() {
      text("Label example");
      client_size({390, 360});
      
      label1.parent(*this);
      label1.text("Lorem ipsum");
      label1.location({10, 50});
      
      label2.parent(*this);
      label2.auto_size(true);
      label2.text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
      label2.location({10, 100});
      
      label3.parent(*this);
      label3.auto_ellipsis(true);
      label3.text("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
      label3.location({10, 150});
      
      label4.parent(*this);
      label4.text("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus.Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor.Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim.Pellentesque congue. Ut in risus volutpat libero pharetra tempor.Cras vestibulum bibendum augue. Praesent egestas leo in pede.Praesent blandit odio eu enim.Pellentesque sed dui ut augue blandit sodales.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum.Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar.Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula.Pellentesque rhoncus nunc et augue.Integer id felis.Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas.Lorem ipsum dolor sit amet, consectetuer adipiscing elit.Morbi vel erat non mauris convallis vehicula.Nulla et sapien.Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat.Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus.Fusce vulputate sem at sapien.Vivamus leo. Aliquam euismod libero eu enim.Nulla nec felis sed leo placerat imperdiet.Aenean suscipit nulla in justo.Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus.Curabitur eu amet.\n");
      label4.location({10, 200});
      label4.size({350, 150});
      label4.anchor(anchor_styles::all);
      label4.text_align(xtd::forms::content_alignment::top_center);
    }
    
  private:
    label label1;
    label label2;
    label label3;
    label label4;
  };
}

auto main() -> int {
  application::run(label_example::form1 {});
}
