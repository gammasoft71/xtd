| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

This section provides guidelines for designing libraries that extend and interact with the xtd framework. 
The goal is to help library designers ensure API consistency and ease of use by providing a unified programming model for development.
We recommend that you follow these design guidelines when developing classes and components that extend the xtd Framework. 
Inconsistent library design adversely affects developer productivity and discourages adoption. 
The guidelines are organized as simple recommendations prefixed with the terms *Do*, *Consider*, *Avoid*, and *Do not*.
These guidelines are intended to help class library designers understand the trade-offs between different solutions. 
There might be situations where good library design requires that you violate these design guidelines.
Such cases should be rare, and it is important that you have a clear and compelling reason for your decision.
These guidelines are excerpted from the book Framework Design Guidelines:
Conventions, Idioms, and Patterns for Reusable .NET Libraries, 2nd Edition, by Krzysztof Cwalina and Brad Abrams.

# Notes

The guidelines are adapted to modern C++ and follow the std standard.

You can see the original source : [Framework Design Guidelines](https://docs.microsoft.com/en-us/dotnet/standard/design-guidelines).

# In this section

* [Coding Conventions Guidelines](coding_conventions_guidelines.md) provides guidelines for comments, documentation, indentations, new lines and spacing coding conventions.
* [Naming Guidelines](naming_guidelines.md) Provides guidelines for naming libraries, namespaces, types, and members in class libraries.
* [Type Design Guidelines](type_design_guidelines.md) Provides guidelines for using static and abstract classes, interfaces, enumerations, structures, and other types.
* [Member Design Guidelines](member_design_guidelines.md) Provides guidelines for designing and using properties, methods, constructors, fields, events, operators, and parameters.
* [Designing for Extensibility](designing_for_extensibility.md) Discusses extensibility mechanisms such as subclassing, using events, virtual members, and callbacks, and explains how to choose the mechanisms that best meet your framework's requirements.
* [Design Guidelines for Exception](design_guidelines_for_exception.md) Describes design guidelines for designing, throwing, and catching exceptions.
* [Common Design Patterns](common_design_patterns.md) are solutions to software design problems you find again and again in real-world application development. Patterns are about reusable designs and interactions of objects.

## See also

* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.

