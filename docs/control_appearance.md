| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Control appearance

xtd is designed to manage controls and dialogs in pure native mode or with [CSS styles](https://github.com/gammasoft71/xtd/blob/master/docs/style_sheets_overview.md).

By default all controls are defined with CSS mode (the property [xtd::forms::control::control_appearance](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a6acf5a01e6111bd58f198aafa3e3f39e) is set to [xtd::forms::control_appearance::standard](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a6acf5a01e6111bd58f198aafa3e3f39e)).
xtd defines a [CSS theme](https://github.com/gammasoft71/xtd/tree/master/themes) for each OS so that the emulation of the controls is identical to native controls.

For any control or dialog box, you can decide to use the native version in the following way:

- Controls

```cpp
 my_control.control_appearance(xtd::forms::control_appearance::system);
```

- Buttons, group boxes and labels

  You can use [control_appearance](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a6acf5a01e6111bd58f198aafa3e3f39e) property like other controls, but [flat_style](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1button__base.html#a67a342814aa63e8a45decd3d70e36428) property adds two additional options : flat and popup.

```cpp
 my_button.flat_style(xtd::forms::flat_style::system);
```

- Dialogs

  A dialog is not a control, so to avoid confusion, this property is called dialog_style.

```cpp
 my_dialog.dialog_style(xtd::forms::dialog_style::system);
```

## Remarks

* You can create your own [CSS styles](https://github.com/gammasoft71/xtd/blob/master/docs/style_sheets_overview.md) for the whole application or for one or more specific controls according to your wishes.
* Unlike standard controls, system controls have some limitations such as: 
  * text alignment
  * background color
  * foreground colors
  * display of associated images
  * ...
* Not all standard controls are implemented yet, in this case the native control is used even if the property [xtd::forms::control::control_appearance](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a6acf5a01e6111bd58f198aafa3e3f39e) is set to [xtd::forms::control_appearance::standard](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html#a6acf5a01e6111bd58f198aafa3e3f39e).

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
