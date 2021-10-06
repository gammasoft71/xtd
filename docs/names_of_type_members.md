| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Names of Type Members

Types are made of members: methods, properties, events, constructors, and fields. The following sections describe guidelines for naming type members.

# Names of Methods

Because methods are the means of taking action, the design guidelines require that method names be verbs or verb phrases. Following this guideline also serves to distinguish method names from property and type names, which are noun or adjective phrases.

**✔️ DO** give methods names that are verbs or verb phrases.

```c++
​class ustring : public object {
public:
  int compare_to(...);
  std::vectory<ustring> split(...);
  ustring trim();
};
```

# Names of Properties

Unlike other members, properties should be given noun phrase or adjective names. That is because a property refers to data, and the name of the property reflects that. Lower case only and digits, separate words with underscores is always used for property names.

**✔️ DO** name properties using a noun, noun phrase, or adjective.

**❌ DO NOT** have properties that match the name of "get_" or "set_" methods as in the following example:

```c++
ustring text_writer() const { ... }
void textt_writer(const ustring& value) { ... }
ustring get_text_writer(int32_t value) { ... }
```

This pattern typically indicates that the property should really be a method.

**✔️ DO** name collection properties with a plural phrase describing the items in the collection instead of using a singular phrase followed by "_list" or "_collection."

**✔️ DO** name boolean properties with an affirmative phrase (can_seek instead of cant_seek). Optionally, you can also prefix boolean properties with "is_", "can_", or "has_" but only where it adds value.

**✔️ CONSIDER** giving a property the same name as its type.

For example, the following property correctly gets and sets an enum value named color, so the property is named color:

```c++
namespace forms {
  enum class color {
    ...
  };
  ​
  class control : public object {
  public:
    forms::color color() const { ... };
    void color(forms::color value) { ... };
  };
}
```

# Names of Events

Events always refer to some action, either one that is happening or one that has occurred. Therefore, as with methods, events are named with verbs, and verb tense is used to indicate the time when the event is raised.

**✔️ DO** name events with a verb or a verb phrase.

Examples include clicked, painting, dropped_down, and so on.

**✔️ DO** give events names with a concept of before and after, using the present and past tenses.

For example, a close event that is raised before a window is closed would be called closing, and one that is raised after the window is closed would be called closed.

**❌ DO NOT** use "before_" or "after_" prefixes or postfixes to indicate pre- and post-events. Use present and past tenses as just described.

**✔️ DO** name event handlers (delegates used as types of events) with the "_event_handler" suffix, as shown in the following example:

```c++
using clicked_event_handler = delegate<void(object&, const event_args&)>;
```
**✔️ DO** use two parameters named sender and e in event handlers.

The sender parameter represents the object that raised the event. The sender parameter is typically of type object, even if it is possible to employ a more specific type.

**✔️ DO** name event argument classes with the "_event_args" suffix.

# Names of Fields

The field-naming guidelines apply to static public and protected fields. Internal and private fields are not covered by guidelines, and public or protected instance fields are not allowed by the Member Design Guidelines.

**✔️ DO** use lower case only and digits, separate words with underscores in field names.

**✔️ DO** name fields using a noun, noun phrase, or adjective.

**❌ DO NOT** use a prefix for field names.

For example, do not use "g_" or "s_" to indicate static fields.

# See also
​
* [Naming Guidelines](naming_guidelines.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
