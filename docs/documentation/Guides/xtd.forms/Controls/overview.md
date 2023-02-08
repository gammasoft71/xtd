# Overview of using controls (xtd)

[xtd.forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) controls are reusable components that encapsulate user interface functionality and are used in client-side, Windows-based applications. 
Not only does [xtd::forms](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html) provide many ready-to-use controls, it also provides the infrastructure for developing your own controls. 
You can combine existing controls, extend existing controls, or author your own custom controls.
For more information, see [Types of custom controls](/docs/documentation/Guides/xtd.forms/Controls/custom_controls).

# Adding controls

Controls are added through code. For more information, see Add a control (Windows Forms).
In the future controls can be added through xtd.code. 
With the xtd.code designer, you will be able to place, size, align and move controls. 

# Layout options

The position a control appears on a parent is determined by the value of the [location](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a53e5a75ad180a2efadc129e5a3c18cbd) property relative to the top-left of the parent surface.
The top-left position coordinate in the parent is (x0,y0). The size of the control is determined by the [size](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#ad6b15530ad92e3df1996d4fd3c0c862e) property and represents the width and height of the control.

Besides manual positioning and sizing, various container controls are provided that help with automatic placement of controls.

For more information, see [Position and layout of controls](/docs/documentation/Guides/xtd.forms/Controls/position_and_layout_of_controls) and [How to dock and anchor controls](/docs/documentation/Guides/xtd.forms/Controls/Common%20tasks/dock_and_anchor_controls).

# Control events

Controls provide a set of common events through the base class: [Control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html). Not every control responds to every event. 
For example, the [label](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1label.html) control doesn't respond to keyboard input, so the [control::preview_key_down](#) event isn't raised. 
Most shared events fall under these categories:

* Mouse events
* Keyboard events
* Property changed events
* Other events

For more information, see [Control events](/docs/documentation/Guides/xtd.forms/Controls/Events) and [How to handle a control event](/docs/documentation/Guides/xtd.forms/Controls/Common%20tasks/add_or_remove_event_handlers).

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/desktop/winforms/controls/overview?view=netdesktop-6.0)
