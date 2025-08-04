# Final

One of the features of object-oriented frameworks is that developers can extend and customize them in ways unanticipated by the framework designers. This is both the power and danger of extensible design. When you design your framework, it is, therefore, very important to carefully design for extensibility when it is desired, and to limit extensibility when it is dangerous.

A powerful mechanism that prevents extensibility is to mark the class with "final". You can seal either the class or individual members. Marking a class with "final" prevents users from inheriting from the class. Marking a member with "final" prevents users from overriding a particular member.

**❌ DO NOT** Marking classes "final" without having a good reason to do so.

Marking a class "final" because you cannot think of an extensibility scenario is not a good reason. Framework users like to inherit from classes for various non-obvious reasons, like adding convenience members. See [Non-final Classes](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/non-final_classes) for examples of nonobvious reasons users want to inherit from a type.

Good reasons for marking a class "final" include the following:

* The class is a static class. See [Static Class Design](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines/static_class_design).
* The class stores security-sensitive secrets in inherited protected members.
* The class inherits many virtual members and the cost of marking "final" them individually would outweigh the benefits of leaving the class non-final.
* The class is an attribute that requires very fast runtime look-up. Attributes marked "final" have slightly higher performance levels than non-final ones.

**❌ DO NOT** declare protected or virtual members on "final" types.
By definition, "final" types cannot be inherited from. This means that protected members on "final" types cannot be called, and virtual methods on "final" types cannot be overridden.

**✔️ CONSIDER** Marking members "final" that you override.
Problems that can result from introducing virtual members (discussed in [Virtual Members](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/virtual_members)) apply to overrides as well, although to a slightly lesser degree. Marking an override shields "final" you from these problems starting from that point in the inheritance hierarchy.

# See also
​
* [Design for Extensibility](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility)
* [Design Guidelines](/docs/documentation/Design%20Guidelines)
* [Documentation](/docs/documentation)
