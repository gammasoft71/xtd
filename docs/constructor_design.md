| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Constructor Design

Constructors run when an instance of a type is created.

Constructors that don’t take any parameters are called default constructors.

Constructors are the most natural way to create instances of a type. Most developers will search and try to use a constructor before they consider alternative ways of creating instances (such as factory methods).

**✔️ CONSIDER** providing simple, ideally default, constructors.

A simple constructor has a very small number of parameters, and all parameters are primitives or enums. Such simple constructors increase usability of the framework.

**✔️ CONSIDER** using a static factory method instead of a constructor if the semantics of the desired operation do not map directly to the construction of a new instance, or if following the constructor design guidelines feels unnatural.

**✔️ DO** use constructor parameters as shortcuts for setting main properties.

**✔️ DO** minimal work in the constructor.

Constructors should not do much work other than capture the constructor parameters. The cost of any other processing should be delayed until required.

**✔️ DO** throw exceptions from instance constructors, if appropriate.

**✔️ DO** explicitly declare the public default constructor in classes, if such a constructor is required.

If you don’t explicitly declare any constructors on a type, C++ language will automatically add a public default constructor.

Adding a parameterized constructor to a class prevents the compiler from adding the default constructor. This often causes accidental breaking changes.

**❌ AVOID** calling virtual members on an object inside its constructor. Calling a virtual member will not supported by C++.

# See also
​
* [Member Design Guidelines](member_design_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
