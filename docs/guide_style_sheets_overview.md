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
  background-color: linear-gradient(system-color(button-face), system-color(button-face));
  padding: 1px 1px 1px 3px;
  color: system-color(control-text);
  text-align: middle center;
  text-decoration: none;
}
```

The following example shows part of the style sheet of a button control for pressed pseudo state :

```css
button:pressed {
  background-color: rgba(255, 255, 255, 93);
}
```

It can be noticed that only the properties that differ with the standard pseudo state are expressed.
The other properties will be the same as those of the standard preudo state.

### Remarks

we can notice that the property is written like this :

```css
  background-color: linear-gradient(system-color(button-face), system-color(button-face));
```

when we could have simply written this:

```css
  background-color: system-color(button-face);
```

The difference between the two cases is that if you change the background color of the button by programming, in the first case, the button is not impacted while in the second case the button will take the color defined by programming.
 So it's a design choice.

A solid color can be replaced on the fly while a gradient color cannot.

In the case of our example we don't want a change of color to change the appearance of the button because we can imagine that the color of the system button-face is semi-transparent.

## Style sheet usage

Comming soon...

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

# See also
​
* [Style sheets reference](guide_style_sheets_reference.md)
* [Box model](guide_style_sheets_box_model.md)
* [Guides](guides.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.
