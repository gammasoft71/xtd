| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Form

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

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
