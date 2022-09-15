| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Containers

Any control can be a container. Indeed a control can have several children.
For more information, see [Parent and children](https://github.com/gammasoft71/xtd/blob/master/docs/xtd_forms_explanations.md#parent-and-childdren).

Even if it is possible, in general we prefer to use defined containers which have properties specific to their role.

## Standard containers

### Controls
* [fixed_layout_panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1fixed__layout__panel.html)
* [group_box](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1group__box.html)
* [panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1panel.html)
* [popup_panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1popup__panel.html)
* [splitter_panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1splitter__panel.html)
* [tab_page](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1tab__page.html)

These containers use [location](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1control.html#a704049ab20aa16e25dca51911b0ba13b), [size](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1control.html#a2a9c3b512b6748c8330fe2231839c4cb), [auto_size](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1control.html#ad6dfcca7a2ecd41e2679d6b3085103fe), [anchor](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1control.html#a3908bffd315d0bfc8b2656f89e2dc42c) and [dock](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1control.html#adb3febb83c715c2f7e014b47c9cb1df7) for children controls.

For more information, see [Size and location properties](https://github.com/gammasoft71/xtd/blob/master/docs/size_and_location_properties.md).

### Remarks

* [fixed_layout_panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1fixed__layout__panel.html) is the smae as [panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1panel.html).
* [splitter_panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1splitter__panel.html) is used with [splitt_container](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1split__container.html) and is the same as [panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1panel.html).
* [tab_page](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1tab__page.html) is used with [tab_control]([tab_page](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1tab__page.html)) and is the same as [panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1panel.html).

## Layout containers

### Controls
* [flow_layout_manel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1flow__layout__panel.html)
* [horizontal_layout_panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1horizontal__layout__panel.html)
* [table_layout_panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1table__layout__panel.html)
* [vertical_layout_panel](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1vertical__layout__panel.html)

The role of the layout container is to manage the layout of child controls. 
Unlike standard panels, they define the size, position and layout of child controls and do not use user-defined child control properties

#### Remarks

Layout containers can use the dock or anchor to position themselves in the parent control (Generally we use dock(dock_style::fill)). 

On the other hand, child controls of layout panel cannot use the dock or anchor properties because it is the layout panel that decides how to display them according to the chosen options.

### Flow layout panel

Used to group collections of fixed aligned controls.

Comming soon...

### Horizontal layout panel

Used to group collections of horizontally aligned controls.

### Horizontal layout panel styles

#### styles

You must specify for each chid control the layout style to the layout container by the method vertical_layout_control_style for vertical_layout_style and horontal_layout_style for horizontal_layout_style.

#### width or height

You can specify the prefered width for horizontal_layout_panel or height for vertical_lyout__panel in pixel or percent depending the size_type.

#### Exapend 

A flag indicating if control is expanded to its containing layout container verticaly or horizontaly depend if vertical_layout_panel or horizontal_layout_panel.

#### size_type

* auto_size : The control should be automatically sized to share space with its peers.
* absolute : The control should be sized to an exact number of pixels. (Style by default)
* percent : The control should be sized as a percentage of the parent container.

#### content_alignment
* top_left : Content is vertically aligned at the top, and horizontally aligned on the left.
* top_center : Content is vertically aligned at the top, and horizontally aligned at the center.
* top_right : Content is vertically aligned at the top, and horizontally aligned on the right.
* middle_left : Content is vertically aligned in the middle, and horizontally aligned on the left.
* middle_center : Content is vertically aligned at the middle, and horizontally aligned at the center.
* middle_right : Content is vertically aligned at the middle, and horizontally aligned on the right.
* bottom_left : Content is vertically aligned in the bottom, and horizontally aligned on the left.
* bottom_center : Content is vertically aligned at the bottom, and horizontally aligned at the center.
* bottom_right : Content is vertically aligned at the bottom, and horizontally aligned on the right.

### Table layout panel

Used to group collections of fixed aligned controls.

Comming soon...

### Vertical layout panel

Used to group collections of verticaly aligned controls.

## Specific containers

### Controls
* [collapsible_panel]()
* [split_container]()
* [tab_control]()

### Collapsible panel

Used to group collections of controls in a collapsible panel.

### split_container

Represents a control consisting of a movable bar that divides a container's display area into two resizable panels.
 
### tab_control
 
Manages a related set of tab pages.

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.
