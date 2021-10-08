| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Member Overloading

Member overloading means creating two or more members on the same type that differ only in the number or type of parameters but have the same name. For example, in the following, the write_line method is overloaded:

```c++
class console static_ {
public:
  static void write_line();
  static void write_line(const std::string& value);
  static void write_line(bool value);
  ...
};
```

Because only methods, constructors, and indexed properties can have parameters, only those members can be overloaded.

Overloading is one of the most important techniques for improving usability, productivity, and readability of reusable libraries. Overloading on the number of parameters makes it possible to provide simpler versions of constructors and methods. Overloading on the parameter type makes it possible to use the same member name for members performing identical operations on a selected set of different types.

**✔️ DO** try to use descriptive parameter names to indicate the default used by shorter overloads.

**❌ AVOID** arbitrarily varying parameter names in overloads. If a parameter in one overload represents the same input as a parameter in another overload, the parameters should have the same name.

**❌ AVOID** being inconsistent in the ordering of parameters in overloaded members. Parameters with the same name should appear in the same position in all overloads.

**✔️ DO** make only the longest overload virtual (if extensibility is required). Shorter overloads should simply call through to a longer overload.

**❌ DO NOT** have overloads with parameters at the same position and similar types yet with different semantics.

**✔️ DO** allow nullptr to be passed for optional arguments.

**✔️ DO** use member overloading rather than defining members with default arguments.

Default arguments are not authorized.

# See also
​
* [Member Design Guidelines](member_design_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
