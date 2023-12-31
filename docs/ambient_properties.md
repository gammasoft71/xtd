| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Ambient properties

## In This Section

* [Overview](#overview)

## Overview

An ambient property is a property on a control that, if not set, is retrieved from the parent control. 

If the control does not have a parent and the property is not set, the control sets the ambient property with its own default value.

Some objects derived from the [xtd::forms::control](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/control.h) class might set the property even if you do not. 

For example, the [xtd::forms::form](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/form.h) class always sets the [xtd::forms::control::fore_color](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/control.h) and [xtd::forms::control::back_color](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/control.h) properties.

List of ambient properties :

* [xtd::forms::control::back_color](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/control.h)
* [xtd::forms::control::cursor](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/control.h)
* [xtd::forms::control::font](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/control.h)
* [xtd::forms::control::fore_color](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/control.h)

### Example

The following example shows the back_color and fore_color ambient properties in action :

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class main_form : public form {
public:
  main_form() {
    controls().push_back_range({change_color_button, label1, label2});
    client_size({400, 200});
  
    change_color_button.auto_size(true);
    change_color_button.location({10, 10});
    change_color_button.text("Change color");
    change_color_button.click += [&] {
      back_color(color::from_argb(rand.next<uint8>(), rand.next<uint8>(), rand.next<uint8>()));
      fore_color(color::from_argb(rand.next<uint8>(), rand.next<uint8>(), rand.next<uint8>()));
      label1.text(ustring::format("back_color = {}\nfore_color = {}", label1.back_color(), label1.fore_color()));
      label2.text(ustring::format("back_color = {}\nfore_color = {}", label2.back_color(), label2.fore_color()));
    };
    
    label1.auto_size(true);
    label1.location({10, 50});
    label1.text(ustring::format("back_color = {}\nfore_color = {}", label1.back_color(), label1.fore_color()));
    
    label2.auto_size(true);
    label2.back_color(color::dark_cyan);
    label2.fore_color(color::black);
    label2.location({10, 110});
    label2.text(ustring::format("back_color = {}\nfore_color = {}", label2.back_color(), label2.fore_color()));
  }
  
private:
  xtd::random rand;
  button change_color_button;
  label label1;
  label label2;
};

auto main()->int {
  application::run(main_form());
}
```

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
