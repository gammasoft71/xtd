| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

A library represent a unit for code programs. You can used a static link library (.lib) or dynamic link (.dll or .so). This section describes only LIB naming conventions, which then can be mapped to DLL naming conventions.

**✔️ DO** choose names for your libraries that suggest large chunks of functionality, such as xtd.drawing.

Library and DLL names don’t have to correspond to namespace names, but it is reasonable to follow the namespace name when naming library. A good rule of thumb is to name the library based on the common prefix of the libraries contained in the library. For example, a library with two namespaces, my_company::my_technology::first_feature and my_company::m_technology::second_feature, could be called my_company_my_technology.lib.

**✔️ CONSIDER** naming libraries according to the following pattern:

`<company>_<component>.lib`

where <component> contains one or more underscore-separated clauses. For example:

**xtd_drawing.lib**
​
# See also
​
* [Naming Guidelines](naming_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
