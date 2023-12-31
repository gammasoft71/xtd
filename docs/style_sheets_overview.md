| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Style sheets overview

We will now see a few examples to get started with using xtd style sheets.

## CSS usage

Follow the [css tutorial](https://www.w3schools.com/css/default.asp) to read or write CSS style sheets.

CSS is used to define styles for xtd controls.

### xtd css example

The following example shows part of the style sheet of a button control for standard pseudo state :

```css
button {
  margin: 0px 1px 0px 1px;
  border-style: outset;
  border-color: system-color(control-dark);
  border-width: 1px;
  border-radius: 5px;
  background-image: linear-gradient(system-color(button-face), system-color(button-face));
  padding: 1px 1px 1px 3px;
  color: system-color(control-text);
  text-align: middle center;
  text-decoration: none;
}
```

The following example shows part of the style sheet of a button control for pressed pseudo state :

```css
button:pressed {
  background-image: linear-gradient(rgba(255, 255, 255, 93), rgba(255, 255, 255, 93));
}
```

It can be noticed that only the properties that differ with the standard pseudo state are expressed.
The other properties will be the same as those of the standard preudo state.

### Remarks

we can notice that the property is written like this :

```css
  background-image: linear-gradient(system-color(button-face), system-color(button-face));
```

when we could have simply written this:

```css
  background-color: system-color(button-face);
```

The difference between the two cases is that if you change the background color of the button by programming, in the first case, the button is not impacted while in the second case the button will take the color defined by programming.
 So it's a design choice.

A background color can be replaced on the fly while ab ackground image cannot.

In the case of our example we don't want a change of color to change the appearance of the button because we can imagine that the color of the system button-face is semi-transparent.

## Style sheet usage

coming soon...

## Themes

xtd has predifined themes for major operating system and desktop environment and also some specific themes.

Feel free to browse these themes for inspiration.

## Current Operating System / Desktop Environment

* [gnome_dark](https://github.com/gammasoft71/xtd/tree/master/themes/gnome_dark) contains GNOME dark theme.
* [gnome_light](https://github.com/gammasoft71/xtd/tree/master/themes/gnome_light) contains GNOME dark theme.
* [kde_dark](https://github.com/gammasoft71/xtd/tree/master/themes/kde_dark) contains KDE dark theme.
* [kde_light](https://github.com/gammasoft71/xtd/tree/master/themes/kde_light) contains KDE dark theme.
* [macos_dark](https://github.com/gammasoft71/xtd/tree/master/themes/macos_dark) contains macOS dark theme.
* [macos_light](https://github.com/gammasoft71/xtd/tree/master/themes/macos_dark) contains macOS light theme.
* [windows_dark](https://github.com/gammasoft71/xtd/tree/master/themes/windows_dark) contains Windows dark theme.
* [windows_light](https://github.com/gammasoft71/xtd/tree/master/themes/windows_light) contains Windows light theme.

## Generic

* [symbolic_dark](https://github.com/gammasoft71/xtd/tree/master/themes/symbolic_dark) contains Symbolic dark theme.
* [symbolic_light](https://github.com/gammasoft71/xtd/tree/master/themes/symbolic_light) contains Symbolic light theme.
* [xtd_dark](https://github.com/gammasoft71/xtd/tree/master/themes/xtd_dark) contains xtd dark theme.
* [xtd_light](https://github.com/gammasoft71/xtd/tree/master/themes/xtd_light) contains xtd light theme.

## Colors only

* [black](https://github.com/gammasoft71/xtd/tree/master/themes/black) contains black color theme.
* [blue](https://github.com/gammasoft71/xtd/tree/master/themes/blue) contains blue color theme.
* [dark](https://github.com/gammasoft71/xtd/tree/master/themes/dark) contains dark color theme.
* [green](https://github.com/gammasoft71/xtd/tree/master/themes/green) contains green color theme.
* [light](https://github.com/gammasoft71/xtd/tree/master/themes/light) contains light color theme.
* [red](https://github.com/gammasoft71/xtd/tree/master/themes/red) contains red color theme.
* [white](https://github.com/gammasoft71/xtd/tree/master/themes/white) contains white color theme.

## Remarks

The style sheet for each control has been split in several files for more clarity. But we could have put them in one file.
xtd browses the whole folder and reads all files with the .css extension.

# See also
​
* [Style sheets reference](style_sheets_reference.md)
* [Box model](style_sheets_box_model.md)
* [Guides](guides.md)
* [Documentation](documentation.md)


______________________________________________________________________________________________

© 2024 Gammasoft.
