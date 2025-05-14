# Events and Callbacks

Callbacks are extensibility points that allow a framework to call back into user code through a delegate. These delegates are usually passed to the framework through a parameter of a method.

Events are a special case of callbacks that supports convenient and consistent syntax for supplying the delegate (an event handler). In addition, Visual Studio’s statement completion and designers provide help in using event-based APIs. (See [Event Design](/docs/documentation/Design%20Guidelines/Member%20Design%20Guidelines/event_design).)

**✔️ CONSIDER** using callbacks to allow users to provide custom code to be executed by the framework.

**✔️ CONSIDER** using events to allow users to customize the behavior of a framework without the need for understanding object-oriented design.

**✔️ DO** prefer events over plain callbacks, because they are more familiar to a broader range of developers and are integrated with Visual Studio statement completion.

**❌ AVOID** using callbacks in performance-sensitive APIs.

**✔️ DO** use the new xtd::func<...>, or xtd::action<...> types instead of custom delegates, when defining APIs with callbacks.

xtd::func<...> and xtd::action<...> represent generic delegates.

**✔️ DO** understand that by calling a delegate, you are executing arbitrary code and that could have security, correctness, and compatibility repercussions.

# See also
​
* [Design for Extensibility](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility)
* [Design Guidelines](/docs/documentation/Design%20Guidelines)
* [Documentation](/docs/documentation)
