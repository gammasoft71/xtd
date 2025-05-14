# Struct Design

The general-purpose value type is most often referred to as a struct, its C++ keyword. This section provides guidelines for general struct design.

**❌ DO NOT** provide a default constructor for a struct.

Following this guideline allows arrays of structs to be created without having to run the constructor on each item of the array.

**❌ DO NOT** define mutable value types.

Mutable value types have several problems. For example, when a property getter returns a value type, the caller receives a copy. Because the copy is created implicitly, developers might not be aware that they are mutating the copy, and not the original value. Also, some languages (dynamic languages, in particular) have problems using mutable value types because even local variables, when dereference, cause a copy to be made.

**✔️ DO** ensure that a state where all instance data is set to zero, false, or null (as appropriate) is valid.

This prevents accidental creation of invalid instances when an array of the structs is created.

The xtd::object::equals method on value types causes boxing, and its default implementation is not very efficient, because it uses reflection. Equals can have much better performance and can be implemented so that it will not cause boxing.

**❌ DO** explicitly extend xtd::value_type.

In general, structs can be very useful but should only be used for small, single, immutable values that will not be boxed frequently.

# See also
​
* [Type Design Guidelines](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines)
* [Design Guidelines](/docs/documentation/Design%20Guidelines)
* [Documentation](/docs/documentation)
