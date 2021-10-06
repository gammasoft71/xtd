| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Choosing Between Class and Struct

One of the basic design decisions every framework designer faces is whether to design a type as a class or as a struct. Good understanding of the differences in the behavior of reference types and value types is crucial in making this choice.

The only difference between a class and a struct in C++ is that structs have default public members and bases and classes have default private members and bases. Both classes and structs can have a mixture of public and private members, can use inheritance, and can have member functions.

**√ CONSIDER** defining a struct instead of a class if instances of the type are small and commonly short-lived or are commonly embedded in other objects.

**X AVOID** defining a struct unless the type has all of the following characteristics:

* It logically represents a single value, similar to primitive types (int, double, etc.).
* It is immutable.

In all other cases, you should define your types as classes.

# See also
​
* [Type Design Guidelines](type_design_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
