# Design for Extensibility

One important aspect of designing a framework is making sure the extensibility of the framework has been carefully considered. This requires that you understand the costs and benefits associated with various extensibility mechanisms. This chapter helps you decide which of the extensibility mechanisms—subclassing, events, virtual members, callbacks, and so on—can best meet the requirements of your framework.

There are many ways to allow extensibility in frameworks. They range from less powerful but less costly to very powerful but expensive. For any given extensibility requirement, you should choose the least costly extensibility mechanism that meets the requirements. Keep in mind that it’s usually possible to add more extensibility later, but you can never take it away without introducing breaking changes.

## In This Section

* [Non-final Classes](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/non-final_classes)
* [Protected Members](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/protected_members)
* [Events and Callbacks](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/events_and_callbacks)
* [Virtual Members](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/virtual_members)
* [Abstractions (Abstract Types and Interfaces)](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/abstractions_abstract_types_and_interfaces)
* [Base Classes for Implementing Abstractions](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/base_classes_for_implementing_abstractions)
* [Final](/docs/documentation/Design%20Guidelines/Designing%20for%20Extensibility/final)

## See also

* [Design Guidelines](/docs/documentation/Design%20Guidelines)
* [Documentation](/docs/documentation)
