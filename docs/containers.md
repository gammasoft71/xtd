| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Containers

# Table of content

* [Controls](#controls)
* [Standard containers](#standard-containers)
  * [Fixed layout panel](#fixed-layout-panel)
  * [Group box](#group-box)
  * [Panel](#panel)
  * [Popup panel](#popup-panel)
  * [Splitter panel](#splitter-panel)
  * [Tab page](#tab-page)
* [Layout containers](#layout-containers)
  * [Flow layout panel](#flow-layout-panel)
  * [Horizontal layout panel](#horizontal-layout-panel)
  * [Table layout panel](#table-layout-panel)
  * [Vertical layout panel](#vertical-layout-panel)
* [Specific containers](#specific-containers)
  * [Collapsible panel](#collapsible-panel)
  * [Split container](#split-container)
  * [Tab control](#tab-control)
* [User container](#user-container)
  * [Own horizontal stack panel](#own-horizontal-stack-panel)
  * [Own vertical stack panel](#own-vertical-stack-panel)

## Controls

Any control can be a container. Indeed a control can have several children.
For more information, see [Parent and children](https://github.com/gammasoft71/xtd/blob/master/docs/xtd_forms_explanations.md#parent-and-children).

While this is possible, we generally prefer to use defined containers that have specific properties to handle child controls.

## Standard containers

These containers use [location](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a704049ab20aa16e25dca51911b0ba13b), [size](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a2a9c3b512b6748c8330fe2231839c4cb), [auto_size](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#ad6dfcca7a2ecd41e2679d6b3085103fe), [anchor](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a3908bffd315d0bfc8b2656f89e2dc42c) and [dock](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#adb3febb83c715c2f7e014b47c9cb1df7) for children controls.

For more information, see [Size and location properties](https://github.com/gammasoft71/xtd/blob/master/docs/size_and_location_properties.md) and [Position and layout of controls](https://github.com/gammasoft71/xtd/blob/master/docs/position_and_layout_of_controls.md).

### Fixed layout panel

The [fixed_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1fixed__layout__panel.html) is used to group collections of fixed aligned controls.

#### Example

The following example demonstrates the use of [fixed_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1fixed__layout__panel.html) container.

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({400, 200});
    
    panel1.parent(*this).dock(dock_style::fill);
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    button1.location({10, 10});
    button1.text("button 1");

    button2.location({10, 55});
    button2.text("button 2");

    button3.location({10, 100});
    button3.text("button 3");

    button4.location({10, 145});
    button4.text("button 4");
  }
  
private:
  fixed_layout_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

### Group box

[group_box](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1group__box.html) represents a Windows control that displays a frame around a group of controls with an optional caption.

#### Example

The following example demonstrates the use of [group_box](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1group__box.html) container.

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({400, 200});
    
    group_box1.parent(*this).dock(dock_style::fill);
    group_box1.controls().push_back_range({button1, button2, button3, button4});
    
    button1.location({10, 10});
    button1.text("button 1");

    button2.location({10, 55});
    button2.text("button 2");

    button3.location({10, 100});
    button3.text("button 3");

    button4.location({10, 145});
    button4.text("button 4");
  }
  
private:
  group_box group_box1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

### Panel

[panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1panel.html) is used to group collections of controls.

The following example demonstrates the use of [panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1panel.html) container.

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({400, 200});
    
    panel1.parent(*this).dock(dock_style::fill);
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    button1.location({10, 10});
    button1.text("button 1");

    button2.location({10, 55});
    button2.text("button 2");

    button3.location({10, 100});
    button3.text("button 3");

    button4.location({10, 145});
    button4.text("button 4");
  }
  
private:
  fixed_layout_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

### Popup panel

[popup_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1popup__panel.html) represents a special type of panel container that can be used for [context_menu](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1context__menu.html), [combo_box](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1combo__box.html) popups and more.

#### Example

The following example demonstrates the use of [popup_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1popup__panel.html) container.

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Popup panel example");
    client_size({300, 100});
    controls().push_back_range({button1, popup_panel1});
    
    list_box1.parent(popup_panel1);
    list_box1.dock(dock_style::fill);
    list_box1.items().push_back_range({{"clear", button_images::from_name("weather-clear")}, {"clear night", button_images::from_name("weather-clear-night")}, {"few clouds", button_images::from_name("weather-few-clouds")}, {"few clouds night", button_images::from_name("weather-few-clouds-night")}, {"fog", button_images::from_name("weather-fog")}, {"overcast", button_images::from_name("weather-overcast")}, {"severe alert", button_images::from_name("weather-severe-alert")}, {"showers", button_images::from_name("weather-showers")}, {"showers scattered", button_images::from_name("weather-showers-scattered")}, {"snow", button_images::from_name("weather-snow")}, {"storm", button_images::from_name("weather-storm")}});
    list_box1.selected_index(0);
    list_box1.click += [&] {
      button1.text(list_box1.selected_item().value());
      button1.image(as<image>(list_box1.selected_item().tag()));
      popup_panel1.hide();
    };
    
    button1.location({10, 10});
    button1.size({160, 50});
    button1.image_align(content_alignment::top_center);
    button1.text_align(content_alignment::bottom_center);
    button1.text(list_box1.selected_item().value());
    button1.image(as<image>(list_box1.selected_item().tag()));
    button1.click += [&] {
      popup_panel1.show();
    };

    popup_panel1.location(button1.location());
    popup_panel1.width(button1.width());
  }
  
private:
  button button1;
  list_box list_box1;
  popup_panel popup_panel1;
};

auto main() -> int {
  application::run(form1 {});
}
```

### Splitter panel

[splitter_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1splitter__panel.html) represents a panel that is associated with a split_container.

*Coming soon...*

### Tab page

[tab_page](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__page.html) represents a single tab page in a tab_control.

#### Example

The following example demonstrates the use of [tab_page](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__page.html) container.

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Tab control example");
    controls().push_back(tab_control1);
    client_size({390, 270});
    
    tab_control1.location({10, 10});
    tab_control1.size({370, 250});
    tab_control1.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);

    tab_page1.parent(tab_control1);
    tab_page1.text("Tab page 1");
    
    label1.dock(dock_style::fill);
    label1.parent(tab_page1);
    label1.text("label1");
    label1.text_align(xtd::forms::content_alignment::top_left);
    
    tab_page2.parent(tab_control1);
    tab_page2.text("Tab page 2");
    
    label2.dock(dock_style::fill);
    label2.parent(tab_page2);
    label2.text_align(xtd::forms::content_alignment::middle_center);
    label2.text("label2");
    
    tab_page3.parent(tab_control1);
    tab_page3.text("Tab page 3");
    
    label3.dock(dock_style::fill);
    label3.parent(tab_page3);
    label3.text_align(xtd::forms::content_alignment::bottom_right);
    label3.text("label3");
  }
  
private:
  tab_control tab_control1;
  tab_page tab_page1;
  tab_page tab_page2;
  tab_page tab_page3;
  
  label label1;
  label label2;
  label label3;
};

auto main() -> int {
  application::run(form1 {});
}
```

### Remarks

* [fixed_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1fixed__layout__panel.html) is the same as [panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1panel.html).
* [splitter_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1splitter__panel.html) is used with [splitt_container](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1split__container.html) and is the same as [panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1panel.html).
* [tab_page](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__page.html) is used with [tab_control]([tab_page](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__page.html)) and is the same as [panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1panel.html).

## Layout containers

The layout containers manage the layout of child controls. 
Unlike standard containers, they manage the size, position and layout of child controls and do not use user-defined child control properties.

#### Remarks

Layout containers can use the dock or anchor to position themselves in the parent control (Usually we use ```dock(dock_style::fill))```. 

On the other hand, child controls of layout panel cannot use the dock or anchor properties because it is the layout panel that decides how to display them according to the chosen options.

### Flow layout panel

[flow_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1flow__layout__panel.html) is used to group collections of fixed aligned controls.

*Coming soon...*

### Horizontal layout panel

[horizontal_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__layout__panel.html) is used to group collections of horizontally aligned controls.

### Horizontal layout panel styles

For each child control of [horizontal_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__layout__panel.html) an [horizontal_layout_style](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__control__layout__style.html) style is associate.
You can specify for each chid control the layout style to the layout container by the method [control_layout_style](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__layout__panel.html#a6e1ad8fe72ee251ca0c35e7316cc29fa).
If you don't specify the layout style, it use the style by default.

An [horizontal_layout_style](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__control__layout__style.html) is composed of :
* content_alignment :	One of the [content_alignment](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) values. The default is middle_center.
  * [top_left](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the top, and horizontally aligned on the left.
  * [top_center](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the top, and horizontally aligned at the center.
  * [top_right](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the top, and horizontally aligned on the right.
  * [middle_left](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned in the middle, and horizontally aligned on the left.
  * [middle_center](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the middle, and horizontally aligned at the center.
  * [middle_right](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the middle, and horizontally aligned on the right.
  * [bottom_left](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned in the bottom, and horizontally aligned on the left.
  * [bottom_center](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the bottom, and horizontally aligned at the center.
  * [bottom_right](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the bottom, and horizontally aligned on the right.
* exapend : A flag indicating if control is expanded to its containing layout container. The default is false.
* size_type : One of the [size_type](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gab29b04bbaf914660d81ba98475d8a100) values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is auto_size.
  * [auto_size](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gab29b04bbaf914660d81ba98475d8a100) : The control should be automatically sized to share space with its peers.
  * [absolute](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gab29b04bbaf914660d81ba98475d8a100) : The control should be sized to an exact number of pixels. (Style by default)
  * [percent](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gab29b04bbaf914660d81ba98475d8a100) : The control should be sized as a percentage of the parent container.
* width : The prefered width in pixel or percent depending the size_type. The default is std::nullopt.

#### Remarks

If you don't set expand to true and you set the height of the control. the [horizontal_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__layout__panel.html) will take this into account.
But not the width.

#### Examples

The following example shows how to create a [horizontal_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__layout__panel.html) with children that have a default style.

```cpp
#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({400, 200});
    
    panel1.parent(*this).dock(dock_style::fill);
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    button1.flat_style(xtd::forms::flat_style::popup).text("button 1");
    button2.flat_style(xtd::forms::flat_style::popup).text("button 2");
    button3.flat_style(xtd::forms::flat_style::popup).text("button 3");
    button4.flat_style(xtd::forms::flat_style::popup).text("button 4");
  }
  
private:
  horizontal_layout_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

The following example shows how to create a [horizontal_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__layout__panel.html) whose children must have a size corresponding to a percentage of the parent container.

```cpp
#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({400, 200});
    
    panel1.parent(*this).dock(dock_style::fill);
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    panel1.control_layout_style(button1, horizontal_control_layout_style{.15f, size_type::percent});
    panel1.control_layout_style(button2, horizontal_control_layout_style{.35f, size_type::percent});
    panel1.control_layout_style(button3, horizontal_control_layout_style{.35f, size_type::percent});
    panel1.control_layout_style(button4, horizontal_control_layout_style{.15f, size_type::percent});

    button1.flat_style(xtd::forms::flat_style::popup).text("button 1");
    button2.flat_style(xtd::forms::flat_style::popup).text("button 2");
    button3.flat_style(xtd::forms::flat_style::popup).text("button 3");
    button4.flat_style(xtd::forms::flat_style::popup).text("button 4");
  }
  
private:
  horizontal_layout_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

The following example shows how to create a [horizontal_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1horizontal__layout__panel.html) whose children must have a size corresponding to a abosulte value in pixels and set expand to true.

```cpp
#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({400, 200});
    
    panel1.parent(*this).dock(dock_style::fill);
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    panel1.control_layout_style(button1, horizontal_control_layout_style{75, size_type::absolute, true});
    panel1.control_layout_style(button2, horizontal_control_layout_style{125, size_type::absolute, true});
    panel1.control_layout_style(button3, horizontal_control_layout_style{125, size_type::absolute, true});
    panel1.control_layout_style(button4, horizontal_control_layout_style{75, size_type::absolute, true});

    button1.flat_style(xtd::forms::flat_style::popup).text("button 1");
    button2.flat_style(xtd::forms::flat_style::popup).text("button 2");
    button3.flat_style(xtd::forms::flat_style::popup).text("button 3");
    button4.flat_style(xtd::forms::flat_style::popup).text("button 4");
  }
  
private:
  horizontal_layout_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

### Table layout panel

[table_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1table__layout__panel.html) is used to group collections of fixed aligned controls.

*Coming soon...*

### Vertical layout panel

[vertical_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__layout__panel.html) is used to group collections of verticaly aligned controls.

### Vertical layout panel styles

For each child control of [vertical_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__layout__panel.html) an [vertical_layout_style](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__control__layout__style.html) style is associate.
You can specify for each chid control the layout style to the layout container by the method [control_layout_style](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__layout__panel.html#a059dccea939682c556eac63a4288b0ca).
If you don't specify the layout style, it use the style by default.

An [vertical_layout_style](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__control__layout__style.html) is composed of :
* content_alignment :	One of the [content_alignment](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) values. The default is middle_center.
  * [top_left](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the top, and horizontally aligned on the left.
  * [top_center](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the top, and horizontally aligned at the center.
  * [top_right](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the top, and horizontally aligned on the right.
  * [middle_left](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned in the middle, and horizontally aligned on the left.
  * [middle_center](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the middle, and horizontally aligned at the center.
  * [middle_right](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the middle, and horizontally aligned on the right.
  * [bottom_left](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned in the bottom, and horizontally aligned on the left.
  * [bottom_center](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the bottom, and horizontally aligned at the center.
  * [bottom_right](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gad8fe8984e9f4652c13654b2c4d7288f0) : Content is vertically aligned at the bottom, and horizontally aligned on the right.
* exapend : A flag indicating if control is expanded to its containing layout container. The default is false.
* size_type : One of the [size_type](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gab29b04bbaf914660d81ba98475d8a100) values that specifies how layout container of user interface (UI) elements should be sized relative to their container. The default is auto_size.
  * [auto_size](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gab29b04bbaf914660d81ba98475d8a100) : The control should be automatically sized to share space with its peers.
  * [absolute](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gab29b04bbaf914660d81ba98475d8a100) : The control should be sized to an exact number of pixels. (Style by default)
  * [percent](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__forms.html#gab29b04bbaf914660d81ba98475d8a100) : The control should be sized as a percentage of the parent container.
* width : The prefered width in pixel or percent depending the size_type. The default is std::nullopt.

#### Remarks

If you don't set expand to true and you set the width of the control. the [vertical_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__layout__panel.html) will take this into account.
But not the height.


#### Examples

The following example shows how to create a [vertical_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__layout__panel.html) with children that have a default style.

```cpp
#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({200, 400});
    
    panel1.parent(*this).dock(dock_style::fill);
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    button1.flat_style(xtd::forms::flat_style::popup).text("button 1");
    button2.flat_style(xtd::forms::flat_style::popup).text("button 2");
    button3.flat_style(xtd::forms::flat_style::popup).text("button 3");
    button4.flat_style(xtd::forms::flat_style::popup).text("button 4");
  }
  
private:
  vertical_layout_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

The following example shows how to create a [vertical_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__layout__panel.html) whose children must have a size corresponding to a percentage of the parent container.

```cpp
#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({200, 400});
    
    panel1.parent(*this).dock(dock_style::fill);
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    panel1.control_layout_style(button1, vertical_control_layout_style{.15f, size_type::percent});
    panel1.control_layout_style(button2, vertical_control_layout_style{.35f, size_type::percent});
    panel1.control_layout_style(button3, vertical_control_layout_style{.35f, size_type::percent});
    panel1.control_layout_style(button4, vertical_control_layout_style{.15f, size_type::percent});

    button1.flat_style(xtd::forms::flat_style::popup).text("button 1");
    button2.flat_style(xtd::forms::flat_style::popup).text("button 2");
    button3.flat_style(xtd::forms::flat_style::popup).text("button 3");
    button4.flat_style(xtd::forms::flat_style::popup).text("button 4");
  }
  
private:
  vertical_layout_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

The following example shows how to create a [vertical_layout_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1vertical__layout__panel.html) whose children must have a size corresponding to a abosulte value in pixels and set expand to true.

```cpp
#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({200, 400});
    
    panel1.parent(*this).dock(dock_style::fill);
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    panel1.control_layout_style(button1, vertical_control_layout_style{75, size_type::absolute, true});
    panel1.control_layout_style(button2, vertical_control_layout_style{125, size_type::absolute, true});
    panel1.control_layout_style(button3, vertical_control_layout_style{125, size_type::absolute, true});
    panel1.control_layout_style(button4, vertical_control_layout_style{75, size_type::absolute, true});

    button1.flat_style(xtd::forms::flat_style::popup).text("button 1");
    button2.flat_style(xtd::forms::flat_style::popup).text("button 2");
    button3.flat_style(xtd::forms::flat_style::popup).text("button 3");
    button4.flat_style(xtd::forms::flat_style::popup).text("button 4");
  }
  
private:
  vertical_layout_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

## Specific containers

### Collapsible panel

[collapsible_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1collapsible__panel.html) is used to group collections of controls in a collapsible panel.

*coming soon...*

### Split container

[split_container](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1split__container.html) represents a control consisting of a movable bar that divides a container's display area into two resizable panels.

#### Remarks

The child control for the [split_container](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1split__container.html) are [splitter_panel](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1splitter__panel.html).

*coming soon...*
 
### Tab control
 
[tab_control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__control.html) manages a related set of tab pages.

#### Remarks

The child controls for the [tab_control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__control.html) are [tab_page](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__page.html).

#### Example

The following example demonstrates the use of [tab_control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__control.html) container.

```cpp
#include <xtd/xtd>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Tab control example");
    controls().push_back(tab_control1);
    client_size({390, 270});
    
    tab_control1.location({10, 10});
    tab_control1.size({370, 250});
    tab_control1.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);

    tab_page1.parent(tab_control1);
    tab_page1.text("Tab page 1");
    
    label1.dock(dock_style::fill);
    label1.parent(tab_page1);
    label1.text("label1");
    label1.text_align(xtd::forms::content_alignment::top_left);
    
    tab_page2.parent(tab_control1);
    tab_page2.text("Tab page 2");
    
    label2.dock(dock_style::fill);
    label2.parent(tab_page2);
    label2.text_align(xtd::forms::content_alignment::middle_center);
    label2.text("label2");
    
    tab_page3.parent(tab_control1);
    tab_page3.text("Tab page 3");
    
    label3.dock(dock_style::fill);
    label3.parent(tab_page3);
    label3.text_align(xtd::forms::content_alignment::bottom_right);
    label3.text("label3");
  }
  
private:
  tab_control tab_control1;
  tab_page tab_page1;
  tab_page tab_page2;
  tab_page tab_page3;
  
  label label1;
  label label2;
  label label3;
};

auto main() -> int {
  application::run(form1 {});
}
```

## User container

xtd is flexible and complete enough to create your own container without much effort.

### Own horizontal stack panel

The following example show how to make your own horizontal stack panel esasily with overloading [on_layout](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga277d5f851e0d49163d9fdecaace4d7bd) method.

```cpp
#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class horizontal_stack_panel : public panel {
protected:
  void on_layout(const event_args& e) override {
    panel::on_layout(e);
    auto left = 0;
    for (auto control : controls()) {
      control.get().left(left).height(client_size().height());
      left += control.get().width();
    }
  }
};

class form1 : public form {
public:
  form1() {
    client_size({400, 200});
    
    panel1.parent(*this).size({300, 35});
    panel1.controls().push_back_range({button1, button2, button3, button4});
    
    button1.flat_style(xtd::forms::flat_style::popup).text("button 1");
    button2.flat_style(xtd::forms::flat_style::popup).text("button 2");
    button3.flat_style(xtd::forms::flat_style::popup).text("button 3");
    button4.flat_style(xtd::forms::flat_style::popup).text("button 4");
  }
  
private:
  horizontal_stack_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

### Own vertical stack panel

The following example show how to make your own vertical stack panel esasily with [dock](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#adb3febb83c715c2f7e014b47c9cb1df7) and overloading [on_control_added](https://gammasoft71.github.io/xtd/reference_guides/latest/group__events.html#ga76d3b55915e43555fe652aa4d71ae2f0) method.

```cpp
#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

class vertical_stack_panel : public panel {
protected:
  void on_control_added(const control_event_args& e) override {
    panel::on_control_added(e);
    e.control().dock(dock_style::top);
  }
};

class form1 : public form {
public:
  form1() {
    client_size({400, 200});
    
    panel1.parent(*this).size({100, 150});
    panel1.controls().push_back_range({button4, button3, button2, button1});
    
    button1.flat_style(xtd::forms::flat_style::popup).text("button 1");
    button2.flat_style(xtd::forms::flat_style::popup).text("button 2");
    button3.flat_style(xtd::forms::flat_style::popup).text("button 3");
    button4.flat_style(xtd::forms::flat_style::popup).text("button 4");
  }
  
private:
  vertical_stack_panel panel1;
  button button1;
  button button2;
  button button3;
  button button4;
};

auto main() -> int {
  application::run(form1());
}
```

# See also
​
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
