| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Enum Design

Enums are a special kind of value type. There are two kinds of enums: simple enums and flag enums.

Simple enums represent small closed sets of choices. A common example of the simple enum is a set of colors.

Flag enums are designed to support bitwise operations on the enum values. A common example of the flags enum is a list of options.

**✔️ DO** use an enum to strongly type parameters, properties, and return values that represent sets of values.

**✔️ DO** favor using an enum instead of static constants.

**❌ DO NOT** use an enum for open sets (such as the operating system version, names of your friends, etc.).

**❌ DO NOT** provide reserved enum values that are intended for future use.

You can always simply add values to the existing enum at a later stage. See [Adding Values](#adding-values) to Enums for more details on adding values to enums. Reserved values just pollute the set of real values and tend to lead to user errors.

**❌ AVOID** publicly exposing enums with only one value.

A common practice for ensuring future extensibility of C APIs is to add reserved parameters to method signatures. Such reserved parameters can be expressed as enums with a single default value. This should not be done in managed APIs. Method overloading allows adding parameters in future releases.

**❌ DO NOT** include sentinel values in enums.

Although they are sometimes helpful to framework developers, sentinel values are confusing to users of the framework. They are used to track the state of the enum rather than being one of the values from the set represented by the enum.

**✔️ DO** provide a value of zero on simple enums.

Consider calling the value something like "none". If such a value is not appropriate for this particular enum, the most common default value for the enum should be assigned the underlying value of zero.

**✔️ CONSIDER** using int32_t (the default in C++ language) as the underlying type of an enum unless any of the following is true:

* The enum is a flags enum and you have more than 32 flags, or expect to have more in the future.
* The underlying type needs to be different than int32 for easier interoperability with unmanaged code expecting different-size enums.
* A smaller underlying type would result in substantial savings in space. If you expect the enum to be used mainly as an argument for flow of control, the size makes little difference. The size savings might be significant if:
* You expect the enum to be used as a field in a very frequently instantiated structure or class.
* You expect users to create large arrays or collections of the enum instances.
* You expect a large number of instances of the enum to be serialized. For in-memory usage, be aware that managed objects are always DWORD-aligned, so you effectively need multiple enums or other small structures in an instance to pack a smaller enum with in order to make a difference, because the total instance size is always going to be rounded up to a DWORD.

**✔️ DO** name flag enums with plural nouns or noun phrases and simple enums with singular nouns or noun phrases.

# Designing Flag Enums

**✔️ DO** use powers of two for the flag enum values so they can be freely combined using the bitwise OR operation.

**✔️ CONSIDER** providing special enum values for commonly used combinations of flags.

Bitwise operations are an advanced concept and should not be required for simple tasks. ReadWrite is an example of such a special value.

**❌ AVOID** creating flag enums where certain combinations of values are invalid.

**❌ AVOID** using flag enum values of zero unless the value represents "all flags are cleared" and is named appropriately, as prescribed by the next guideline.

**✔️ DO** name the zero value of flag enums "none". For a flag enum, the value must always mean "all flags are cleared."

# Adding Value to Enums

It is very common to discover that you need to add values to an enum after you have already shipped it. There is a potential application compatibility problem when the newly added value is returned from an existing API, because poorly written applications might not handle the new value correctly.

**✔️ CONSIDER** adding values to enums, despite a small compatibility risk.

If you have real data about application incompatibilities caused by additions to an enum, consider adding a new API that returns the new and old values, and deprecate the old API, which should continue returning just the old values. This will ensure that your existing applications remain compatible.

# See also
​
* [Type Design Guidelines](type_design_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
