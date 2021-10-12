| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Final

One of the features of object-oriented frameworks is that developers can extend and customize them in ways unanticipated by the framework designers. This is both the power and danger of extensible design. When you design your framework, it is, therefore, very important to carefully design for extensibility when it is desired, and to limit extensibility when it is dangerous.

A powerful mechanism that prevents extensibility is to mark the class with "final". You can seal either the class or individual members. Marking a class with "final" prevents users from inheriting from the class. Marking a member with "final" prevents users from overriding a particular member.

**❌ DO NOT** Marking classes "final" without having a good reason to do so.

Marking a class "final" because you cannot think of an extensibility scenario is not a good reason. Framework users like to inherit from classes for various non-obvious reasons, like adding convenience members. See [Non-final Classes](non-final_classes.md) for examples of nonobvious reasons users want to inherit from a type.

Good reasons for marking a class "final" include the following:

* The class is a static class. See [Static Class Design](static_class_design.md).
* The class stores security-sensitive secrets in inherited protected members.
* The class inherits many virtual members and the cost of marking "final" them individually would outweigh the benefits of leaving the class non-final.
* The class is an attribute that requires very fast runtime look-up. Attributes marked "final" have slightly higher performance levels than non-final ones. See [Attributes](attributes.md).

**❌ DO NOT** declare protected or virtual members on "final" types.
By definition, "final" types cannot be inherited from. This means that protected members on "final" types cannot be called, and virtual methods on "final" types cannot be overridden.

**✔️ CONSIDER** Marking members "final" that you override.
Problems that can result from introducing virtual members (discussed in [Virtual Members](virtual_members.md)) apply to overrides as well, although to a slightly lesser degree. Marking an override shields "final" you from these problems starting from that point in the inheritance hierarchy.

# See also
​
* [Design for Extensibility](design_for_extensibility.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
