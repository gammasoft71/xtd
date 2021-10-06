| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Static Class Design

A static class is defined as a class that contains only static members (of course besides the instance members inherited from System.Object and possibly a private constructor). C++ languages do not provide built-in support for static classes.

Static classes are a compromise between pure object-oriented design and simplicity. They are commonly used to provide shortcuts to other operations (such as xtd::io::file), holders of extension methods, or functionality for which a full object-oriented wrapper is unwarranted (such as xtd::environment).

**✔️ DO** use static classes sparingly.

Static classes should be used only as supporting classes for the object-oriented core of the framework.

**❌ DO NOT** treat static classes as a miscellaneous bucket.

**❌ DO NOT** declare or override instance members in static classes.

**✔️ DO** declare static classes as abstract, and add a private instance constructor or add xtd keyword static_ because C++ language does not have built-in support for static classes.

```c++
namespace xtd {
  class environment static_ {
  public:
    static void exit(int exit_code) {
      ...
    }
    ...
  };
}
```

# See also
​
* [Type Design Guidelines](type_design_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
