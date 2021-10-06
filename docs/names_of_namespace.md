| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

As with other naming guidelines, the goal when naming namespaces is creating sufficient clarity for the programmer using the framework to immediately know what the content of the namespace is likely to be. The following template specifies the general rule for naming namespaces:
 
**`<company>::(<product>|<technology>)[::<feature>][::<subnamespace>]`**

The following are examples:
 
**fabrikam::math**
 
**bitware::security**
 
**✔️ DO** prefix namespace names with a company name to prevent namespaces from different companies from having the same name.
 
**✔️ DO** use a stable, version-independent product name at the second level of a namespace name.
 
**❌ DO NOT** use organisational hierarchies as the basis for names in namespace hierarchies, because group names within corporations tend to be short-lived. Organise the hierarchy of namespaces around groups of related technologies.
 
**✔️ DO** use underscore-separated, and separate namespace components with "::" (e.g., microsoft::office::power_point). If your brand employs nontraditional casing, you should follow the casing defined by your brand, even if it deviates from normal namespace casing.
 
**✔️ CONSIDER** using plural namespace names where appropriate.
 
For example, use xtd::collections instead of xtd::collection. Brand names and acronyms are exceptions to this rule, however. For example, use xtd::io instead of xtd::ios.
 
**❌ DO NOT** use the same name for a namespace and a type in that namespace.
 
For example, do not use debug as a namespace name and then also provide a class named debug in the same namespace. Several compilers require such types to be fully qualified.
 
# Namespaces and Type Name Conflicts
 
**❌ DO NOT** introduce generic type names such as element, node, log, and message.
 
There is a very high probability that doing so will lead to type name conflicts in common scenarios. You should qualify the generic type names (form_element, xml_node, event_log, soap_message).
 
There are specific guidelines for avoiding type name conflicts for different categories of namespaces.

* **Application model namespaces**
 
# See also
​
* [Naming Guidelines](naming_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
