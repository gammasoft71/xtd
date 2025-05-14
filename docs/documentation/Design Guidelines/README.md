---
sidebar_position: 4
---

# Design Guidelines

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

## Notes

The guidelines are adapted to modern C++ and follow the std standard.

You can see the original source : [Framework Design Guidelines](https://docs.microsoft.com/en-us/dotnet/standard/design-guidelines).

## In this section

* [Coding Conventions Guidelines](/docs/documentation/Design%20Guidelines/coding_conventions_guidelines) provides guidelines for comments, documentation, indentations, new lines and spacing coding conventions.
* [Naming Guidelines](/docs/documentation/Design%20Guidelines/Naming%20Guidelines) Provides guidelines for naming libraries, namespaces, types, and members in class libraries.
* [Type Design Guidelines](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines) Provides guidelines for using static and abstract classes, interfaces, enumerations, structures, and other types.
* [Member Design Guidelines](/docs/documentation/Design%20Guidelines/Member%20Design%20Guidelines) Provides guidelines for designing and using properties, methods, constructors, fields, events, operators, and parameters.
* [Designing for Extensibility](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility) Discusses extensibility mechanisms such as subclassing, using events, virtual members, and callbacks, and explains how to choose the mechanisms that best meet your framework's requirements.
* [Design Guidelines for Exception](/docs/documentation/Design%20Guidelines/Design%20Guidelines%20for%20Exception) Describes design guidelines for designing, throwing, and catching exceptions.
* [Common Design Patterns](/docs/documentation/Design%20Guidelines/Common%20Design%20Patterns) are solutions to software design problems you find again and again in real-world application development. Patterns are about reusable designs and interactions of objects.

## See also

* [Documentation](/docs/documentation)
