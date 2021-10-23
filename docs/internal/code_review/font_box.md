# Review font_box

## Implementation

* Updating [src/xtd.forms/include/xtd/forms/font_box_options.h](../../../src/xtd.forms/include/xtd/forms/font_box_options.h) to remove alignment spacing. Because if it always looks good when you write the class, it quickly becomes ugly as the development lives. For example, there might be refactorings that will damage the alignment without the developer realizing it. Then later when he opens the file he realizes that everything is out of alignment. So he realigns everything. To refactor again, everything is again misaligned, so we realign, in short it quickly becomes a hell (situation experienced at the office by a colleague who absolutely wanted to keep his alignments, he ended up being convinced lol).
* Updating [src/xtd.forms/include/xtd/forms/font_box.h](../../../src/xtd.forms/include/xtd/forms/font_box.h) to add dialog.color(*color) dialoog.font(font) to set the specified user color and font at opening font box.

## Example

* Updating [examples/xtd.forms.examples/font_box/src/font_box.cpp](../../../eexamples/xtd.forms.examples/font_box/src/font_box.cpp) replace "Arial" by drawing::font_family::generic_sans_serif(), because "Arial" is not a portable font.
