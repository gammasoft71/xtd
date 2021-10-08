| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Design for Extensibility

One important aspect of designing a framework is making sure the extensibility of the framework has been carefully considered. This requires that you understand the costs and benefits associated with various extensibility mechanisms. This chapter helps you decide which of the extensibility mechanisms—subclassing, events, virtual members, callbacks, and so on—can best meet the requirements of your framework.

There are many ways to allow extensibility in frameworks. They range from less powerful but less costly to very powerful but expensive. For any given extensibility requirement, you should choose the least costly extensibility mechanism that meets the requirements. Keep in mind that it’s usually possible to add more extensibility later, but you can never take it away without introducing breaking changes.

# In This Section

* [Non-final Classes](non-final_classes.md)
* [Protected Members](protected_members.md)
* [Events and Callbacks](events_and_callbacks.md)
* [Virtual Members](virtual_members.md)
* [Abstractions (Abstract Types and Interfaces)](abstractions_abstract_types_and_interfaces.md)
* [Base Classes for Implementing Abstractions](base_classes_for_implementing_abstractions.md)
* [Final](final.md)

# See also

* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
