| [Home](home.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Events and Callbacks

Callbacks are extensibility points that allow a framework to call back into user code through a delegate. These delegates are usually passed to the framework through a parameter of a method.

Events are a special case of callbacks that supports convenient and consistent syntax for supplying the delegate (an event handler). In addition, Visual Studio’s statement completion and designers provide help in using event-based APIs. (See [Event Design](event_design.md).)

**✔️ CONSIDER** using callbacks to allow users to provide custom code to be executed by the framework.

**✔️ CONSIDER** using events to allow users to customize the behavior of a framework without the need for understanding object-oriented design.

**✔️ DO** prefer events over plain callbacks, because they are more familiar to a broader range of developers and are integrated with Visual Studio statement completion.

**❌ AVOID** using callbacks in performance-sensitive APIs.

**✔️ DO** use the new xtd::func<...>, or xtd::action<...> types instead of custom delegates, when defining APIs with callbacks.

xtd::func<...> and xtd::action<...> represent generic delegates.

**✔️ DO** understand that by calling a delegate, you are executing arbitrary code and that could have security, correctness, and compatibility repercussions.

# See also
​
* [Design for Extensibility](design_for_extensibility.md)
* [Design Guidelines](design_guidelines.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.
