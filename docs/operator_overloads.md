| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Operator Overloads

The principle of encapsulation is one of the most important notions in object-oriented design. This principle states that data stored inside an object should be accessible only to that object.

Operator overloads allow framework types to appear as if they were built-in language primitives.

Although allowed and useful in some situations, operator overloads should be used cautiously. There are many cases in which operator overloading has been abused, such as when framework designers started to use operators for operations that should be simple methods.

The following guidelines should help you decide when and how to use operator overloading.

**❌ AVOID** defining operator overloads, except in types that should feel like primitive (built-in) types.

**✔️ CONSIDER** defining operator overloads in a type that should feel like a primitive type.

For example, xtd:ustring has operator== and operator!= defined.

**✔️ DO** define operator overloads in structs that represent numbers.

**❌ DO NOT** be cute when defining operator overloads.

Operator overloading is useful in cases in which it is immediately obvious what the result of the operation will be. For example, it makes sense to be able to subtract one DateTime from another date_time and get a time_span. However, it is not appropriate to use the logical union operator to union two database queries, or to use the shift operator to write to a stream.

**❌ DO NOT** provide operator overloads unless at least one of the operands is of the type defining the overload.

**✔️ DO** overload operators in a symmetric fashion.

For example, if you overload the operator==, you should also overload the operator!=. Similarly, if you overload the operator<, you should also overload the operator>, and so on.

**✔️ CONSIDER** providing methods with friendly names that correspond to each overloaded operator.

# equals

The xtd::object class implement the == and != operators and used the virtual bool equals(const object&) const; method. By default this method check if the objects are the same addresses. You must just overload this method for used your own implementation.

The Point class show how to used Equals method :

```c++
class point : public object {
  ...
  
public:
  bool equals(const point& value) const {
    return x_ == value.x_ && y_ == value.y_;
  }
  ​
  bool equals(const object& obj) const override {
    return is<point>(obj) && equals(as<point>(obj));
  }
  ​
  ...
  
private:
  int x_ = 0;
  int y_ = 0;
};

...

static ustring form1::check_points(const point& p1, const point& p2) {
  if (p1 == p2) eturn "Equals";
  return "Not equals";
}
```

# ​compare_to

The xtd::icomparable interface implement the <, <=, > and >= operators. and used the virtual int32_t compare_to(const type_t&) const; method. You must just overload this method for used your own implementation.

The time_span class show how to used compare_to method:

```c++
class time_span : public object, public icomparable<time_span> {
  ...
  
public:
  int compare_to(const time_span& value) const override {
    return value_ < value.value_ ? -1 : value_ > value.value_ ? 1 : 0;
  }
  ​
  ...
  
private:
  int64 value_ = 0;
};

...

time_span test::get_max_duration(const std::vector<time_span>& durations) const {
  time_span result;
  for (const auto& duration : durations)
    if (duration > result) result = duration;
  return result;
}
```

# Operator in C++

This is a list of operators in the C++ programming languages. All the operators listed exist in C++.

When not overloaded, for the operators &&, ||, and , (the comma operator), there is a sequence point after the evaluation of the first operand.

C++ also contains the type conversion operators const_cast, static_cast, dynamic_cast, and reinterpret_cast. The formatting of these operators means that their precedence level is unimportant.

For the purposes of this tables, a, b, and c represent valid values (literals, values from variables, or return value), object names, or lvalues, as appropriate. R, S and T stand for any type(s), and K for a class type or enumerated type.

"Can overload" means that the operator can be overloaded in C++.

# Arithmetic operators

| Operator name                  | Syntax | Can overload | Prototype examples as member of K | Protype examples outside class definition |
|--------------------------------|--------|--------------|-----------------------------------|-------------------------------------------|
| Basic assignment               | a = b  | Yes          | R& K::operator =(S b);            | N/A                                       |
| Addition                       | a + b  | Yes          | R K::operator +(S b);             | R operator +(K a, S b);                   |
| Subtraction                    | a - b  | Yes          | R K::operator -(S b);             | R operator -(K a, S b);                   |
| Unary plus (integer promotion) | +a     | Yes          | R K::operator +();                | R operator +(K a);                        |
| Unary minus (additive inverse) | -a     | Yes          | R K::operator -();                | R operator -(K a);                        |
| Multiplication                 | a * b  | Yes          | R K::operator *(S b);             | R operator *(K a, S b);                   |
| Division                       | a / b  | Yes          | R K::operator /(S b);             | R operator /(K a, S b);                   |
| Modulo (integer remainder)     | a % b  | Yes          | R K::operator %(S b);             | R operator %(K a, S b);                   |
| Increment Prefix               | ++a    | Yes          | R& K::operator ++();              | R& operator ++(K& a);                     |
| Increment Postfix              | a++.   | Yes          | R K::operator ++(int);            | R operator ++(K& a, int);                 |
| Decrement Prefix               | --a    | Yes          | R& K::operator --();              | R& operator --(K& a);                     |
| Decrement Postfix              | a--    | Yes          | R K::operator --(int);            | R operator --(K& a, int);                 |

# Comparison operators / relational operators

| Operator name            | Syntax                 | Can overload | Prototype example as member of K       | Prototype examples outside class definition |
|--------------------------|------------------------|--------------|----------------------------------------|---------------------------------------------|
| Equal to.                | a == b                 | Yes          | bool K::operator ==(S const& b) const; | bool operator ==(K const& a, S const& b);   |
| Not equal to             | a != b -or- a not_eq b | Yes          | bool K::operator !=(S const& b) const; | bool operator !=(K const& a, S const& b);   |
| Greater than             | a > b                  | Yes          | bool K::operator >(S const& b) const;  | bool operator >(K const& a, S const& b);    |
| Less than                | a > b                  | Yes          | bool K::operator <(S const& b) const;  | bool operator <(K const& a, S const& b);    |
| Greater than or equal to | a >= b                 | Yes          | bool K::operator >=(S const& b) const; | bool operator >=(K const& a, S const& b);   |
| Less than or equal to    | a <= b                 | Yes          | bool K::operator <=(S const& b) const; | bool operator <=(K const& a, S const& b);   |

# Logical operators

| Operator name          | Syntax              | Can overload | Protype examples as member of K | Protype examples outside class definitions |
|------------------------|---------------------|--------------|---------------------------------|--------------------------------------------|
| Logical negation (NOT) | !a -or- not a       | Yes          | bool K::operator !() const;     | bool operator !(K a);                      |
| Logical AND            | a && b -or- a and b | Yes          | bool K::operator &&(S b) const; | bool operator &&(K a, S b);                |
| Logical OR             | a || b -or- a or b  | Yes          | bool K::operator ||(S b) const; | bool operator ||(K a, S b);                |

# Bitwise operators

| Operator name       | Syntax                | Can overload | Protype examples as member of K | Protype examples outside class definitions |
|---------------------|-----------------------|--------------|---------------------------------|--------------------------------------------|
| Bitwise NOT         | ~a -or- compl a       | Yes          | R K::operator ~();              | R operator ~(K a);                         |
| Bitwise AND         | a & b -or- a bitand b | Yes          | R K::operator &(S b);           | R operator &(K a, S b);                    |
| Bitwise OR          | a | n -or- a bitor b  | Yes          | R K::operator |(S b);           | R operator |(K a, S b);                    |
| Bitwise XOR         | a ^ b -r- a xor b     | Yes          | R K::operator ^(S b);           | R operator ^(K a, S b);                    |
| Bitwise left shift  | a << b                | Yes          | R K::operator <<(S b);          | R operator <<(K a, S b);                   |
| Bitwise right shift | a >> b                | Yes          | R K::operator >>(S b);          | R operator >>(K a, S b);                   |

# Compound assignment operators

| Operator name                  | Syntax                 | Meaning.   | Can overload | Protype examples as member of K | Protype examples outside class definitions |
|--------------------------------|------------------------|------------|--------------|---------------------------------|--------------------------------------------|
| Addition assignment            | a += b                 | a = a + b  | Yes          | R& K::operator +=(S b);         | R& operator +=(K& a, S b);                 |
| Subtraction assignment         | a -= b                 | a = a - b  | Yes          | R& K::operator -=(S b);         | R& operator -=(K& a, S b);                 |
| Multiplication assignment      | a *= b                 | a = a * b  | Yes          | R& K::operator *=(S b);         | R& operator *=(K& a, S b);                 |
| Division assignment            | a /= b                 | a = a / b  | Yes          | R& K::operator /=(S b);         | R& operator /=(K& a, S b);                 |
| Modulo assignment              | a %= b                 | a = a % b  | Yes          | R& K::operator %=(S b);         | R& operator %=(K& a, S b);                 |
| Bitwise AND assignment         | a &= b -or- a end_eq b | a = a & b  | Yes          | R& K::operator &=(S b);         | R& operator &=(K& a, S b);                 |
| Bitwise OR assignment          | a \|= b -or- a or_eq b | a = a \| b | Yes          | R& K::operator \|=(S b);        | R& operator \|=(K& a, S b);                |
| Bitwise XOR assignment         | a ^= b -or- a xor_eq b | a = a^b    | Yes          | R& K::operator ^=(S b);         | R& operator ^=(K& a, S b);                 |
| Bitwise left shift assignment  | a <<= b                | a = a << b | Yes          | R& K::operator <<=(S b);        | R& operator <<=(K& a, S b);                |
| Bitwise right shift assignment | a >>= b                | a = a >> b | Yes          | R& K::operator >>=(S b);        | R& operator <<=(K& a, S b);                |

# Member and pointer operators

| Operator name                                                | Syntax | Can overload | Protype examples as member of K | Protype examples outside class definitions |
|--------------------------------------------------------------|--------|--------------|---------------------------------|--------------------------------------------|
| Array subsript                                               | a[b]   | Yes          | R& K::operator [](S b);         | N/A                                        |
| Indirection ("object pointed to by a")                       | a      | Yes          | R& K::operator *();             | R& operator *(K a);                        |
| Address ("address of a")                                     | &a     | Yes          | R* K::operator &();             | R* operator &(K a);                        |
| Structure dereference ("member b of object pointed to by a") | a->b   | Yes          | R* K::operator ->();            | N/A                                        |
| Structure reference ("member b of object a")                 | a.b    | No           | N/A                             | N/A                                        |
| Member pointed to by b of object pointed to by a             | a->*b  | Yes          | R& K::operator ->*(S b);        | R& operator ->*(K a, S b);                 |
| Member pointed to by b of object a                           | a.*b   | No           | N/A                             | N/A                                        |

# Other operators

| Operator name               | Syntax                            | Can overload | Protype examples as member of K     | Protype examples outside class definitions |
|-----------------------------|-----------------------------------|--------------|-------------------------------------|--------------------------------------------|
| Function call               | a(a1, a2)                         | Yes          | R K::operator ()(S a, T b, ...);    | N/A                                        |
| Comma                       | a, b                              | Yes          | R K::operator ,(S b);               | R operator ,(K a, S b);                    |
| Ternary conditional         | a ? b : c                         | No           | N/A                                 | N/A                                        |
| Scope resolution            | a::b                              | No           | N/A                                 | N/A                                        |
| User-defined literals       | "a"_b                             | Yes          | N/A                                 | R operator "" _b(T a);                     |
| Size-of                     | sizeof(a) -or- sizeof(type)       | No           | N/A                                 | N/A                                        |
| Size of parameter pack      | sizeof...(args)                   | No           | N/A                                 | N/A                                        |
| Align-of                    | alignof(type) -or- _Alignof(type) | No           | N/A                                 | N/A                                        |
| Type identification         | typeid(a) -or- typeid(type)       | No           | N/A                                 | N/A                                        |
| Conversion (C-style cast)   | (type)a -or- type(a)              | Yes          | K::operator R();                    | N/A                                        |
| static_cast conversion      | static_cast<type>(a)              | No           | N/A                                 | N/A                                        |
| dynamic_cast conversion     | dynamic_cast<type>(a)             | No           | N/A                                 | N/A                                        |
| const_cast conversion       | const_cast<type>(a)               | No           | N/A                                 | N/A                                        |
| reinterpret_cast conversion | reinterpret_cast<type>(a)         | No           | N/A                                 | N/A                                        |
| Allocate storage            | new type                          | Yes          | void* K::operator new(size_t x);    | void* operator new(size_t x);              |
| Allocate storage (array)    | new type[n]                       | Yes          | void* K::operator new[](size_t a);  | void* operator new[](size_t x);            |
| Deallocate storage          | delete a                          | Yes          | void K::operator delete(void* a);   | void operator delete(void* a);             |
| Deallocate storage (array)  | delete[] a                        | Yes          | void K::operator delete[](void* a); | void operator delete[](void* a);           |
| Exception check             | noexcept(a)                       | No           | N/A                                 | N/A                                        |

# See also
​
* [Member Design Guidelines](member_design_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
