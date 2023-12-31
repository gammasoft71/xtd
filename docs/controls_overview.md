| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Overview of using controls (xtd)

[xtd.forms]() controls are reusable components that encapsulate user interface functionality and are used in client-side, Windows-based applications. 
Not only does [xtd::forms]() provide many ready-to-use controls, it also provides the infrastructure for developing your own controls. 
You can combine existing controls, extend existing controls, or author your own custom controls.
For more information, see [Types of custom controls](custom_controls.md).

# Adding controls

Controls are added through code. For more information, see Add a control (Windows Forms).
In the future controls can be added through xtd.code. 
With the xtd.code designer, you will be able to place, size, align and move controls. 

# Layout options

The position a control appears on a parent is determined by the value of the [location]() property relative to the top-left of the parent surface.
The top-left position coordinate in the parent is (x0,y0). The size of the control is determined by the [size]() property and represents the width and height of the control.

Besides manual positioning and sizing, various container controls are provided that help with automatic placement of controls.

For more information, see [Position and layout of controls](position_and_layout_of_controls.md) and [How to dock and anchor controls](dock_and_anchor_controls).

# Control events

Controls provide a set of common events through the base class: [Control](). Not every control responds to every event. 
For example, the [label]() control doesn't respond to keyboard input, so the [control::preview_key_down]() event isn't raised. 
Most shared events fall under these categories:

* Mouse events
* Keyboard events
* Property changed events
* Other events

For more information, see [Control events]() and [How to handle a control event]().

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.

[//]: # (https://learn.microsoft.com/en-us/dotnet/desktop/winforms/controls/overview?view=netdesktop-6.0)
