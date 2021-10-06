| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Parameter Design

This section provides broad guidelines on parameter design, including sections with guidelines for checking arguments. In addition, you should refer to the guidelines described in [Naming Parameters](naming_parameters.md).

**✔️ DO** use the least derived parameter type that provides the functionality required by the member.

For example, suppose you want to design a method that chnage the size of any control. Such a method should take xtd::forms::control as the parameter, not xtd::forms::button or xtd::forms::text_box, for example.

**❌ DO NOT** use reserved parameters.

If more input to a member is needed in some future version, a new overload can be added.

**❌ DO NOT** have publicly exposed methods that take pointers, arrays of pointers, or multidimensional arrays as parameters.

Pointers and multidimensional arrays are relatively difficult to use properly. In almost all cases, APIs can be redesigned to avoid taking these types as parameters.

**✔️ DO** place all parameters following all of the by-value, const ref and ref parameters, even if it results in an inconsistency in parameter ordering between overloads (see [Member Overloading](member-overloading.md)).

The ref parameters can be seen as extra return values, and grouping them together makes the method signature easier to understand.

**✔️ DO** be consistent in naming parameters when overriding members or implementing interface members.

This better communicates the relationship between the methods.

# Choosing Between enum and boolean Parameters

**✔️ DO** use enums if a member would otherwise have two or more boolean parameters.

**❌ DO NOT** use booleans unless you are absolutely sure there will never be a need for more than two values.

Enums give you some room for future addition of values, but you should be aware of all the implications of adding values to enums, which are described in [Enum Design](enum-design.md).

**✔️ CONSIDER** using booleans for constructor parameters that are truly two-state values and are simply used to initialize boolean properties.

# Validating Arguments

**✔️ DO** validate arguments passed to public, protected, or explicitly implemented members. Throw xtd::argument_exception, or one of its subclasses, if the validation fails.

Note that the actual validation does not necessarily have to happen in the public or protected member itself. It could happen at a lower level in some private routine. The main point is that the entire surface area that is exposed to the end users checks the arguments.

**✔️ DO** throw xtd::argument_null_exception if a nullptr argument is passed and the member does not support nullptr arguments.

**✔️ DO** validate enum parameters. Do not assume enum arguments will be in the range defined by the enum. The C++ language allows casting any integer value into an enum value even if the value is not defined in the enum.

**✔️ DO** be aware that mutable arguments might have changed after they were validated.

If the member is security sensitive, you are encouraged to make a copy and then validate and process the argument.

# Parameter Passing

From the perspective of a framework designer, there are three main groups of parameters: by-value parameters, const ref parameters, and ref parameters.

When an argument is passed through a by-value or const ref parameter, the member receives a copy of the actual argument passed in. If the argument is a value type, a copy of the argument is put on the stack. If the argument is a reference type, a copy of the reference is put on the stack. The C++ languages, default to passing parameters by value.

When an argument is passed through a ref parameter, the member receives a reference to the actual argument passed in. A reference to the argument is put on the stack. Ref parameters can be used to allow the member to modify arguments passed by the caller.

# See also
​
* [Member Design Guidelines](member_design_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
