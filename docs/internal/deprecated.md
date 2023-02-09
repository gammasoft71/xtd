| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Deprecated (**Internal use only**)

Do not remove an old method immediately. but :

* Set this method deprecated in N version to N + 1 version of xtd. 
* It will be removed in N + 2 version of xtd.

## How to set method deprecated

To set a method deprecated add the deprecated attribute before method and add doxygen comment.

## For example

In version 1.2.1 of xtd, we want to remove the *void xtd::old_function_name(int32_t old_param)* method.

* Version 1.2.1 update code as :

```c++
/// @deprecated Replaced by xtd::new_function_name(const xtd::ustring& new_param) - Will be removed in version 1.2.3
[[deprecated("Replaced by xtd::new_function_name(xtd::ustring new_param) - Will be removed in version 1.2.3")]]
void xtd::old_function_name(int32_t old_param) {
  // ...
}

/// @bref The new function do something.
/// @param new_param The new specifie parameter.
void xtd::new_function_name(const std::ustring& new_param) {
  // ...
}
```

* Version 1.2.2 : Do nothing

* Version 1.2.3 remove code as :

```c++
/// @bref The new function do something.
/// @param new_param The new specifie parameter.
void xtd::new_function_name(const std::ustring& new_param) {
  // ...
}
```
