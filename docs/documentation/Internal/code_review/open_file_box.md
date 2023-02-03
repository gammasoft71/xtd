# Review open_file_box (**Internal use only**)

## Implementation

* Updating [src/xtd.forms/CMakeLists.txt](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/CMakeLists.txt) to add open_file_box.h and  open_file_box_options.h.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box.h](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/open_file_box.h) to add  comments.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box.h](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/open_file_box.h) to add  comment line : /// @include open_file_box.cpp.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box.h](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/open_file_box.h) to fix some code styles.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box.h](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/open_file_box.h) to add .file_name(output) to set the specified user file name.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box_options.h](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/open_file_box_options.h) to use binary literals instead shift operators.

## Example

* Updating [examples/xtd.forms.examples/dialogs/CMakeLists.txt](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/dialogs/CMakeLists.txt) to add open_file_box project.
* Updating [examples/xtd.forms.examples/README.md](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/README.md) to add open_file_box example.
* Updating [examples/xtd.forms.examples/open_file_box/src/open_file_box.cpp](https://github.com/gammasoft71/xtd/blob/master/eexamples/xtd.forms.examples/open_file_box/src/open_file_box.cpp) to fix build warning : capture this in lambda button_open_multiple_files.click
* Updating [examples/xtd.forms.examples/open_file_box/src/open_file_box.cpp](https://github.com/gammasoft71/xtd/blob/master/eexamples/xtd.forms.examples/open_file_box/src/open_file_box.cpp) to use xtd::ustring::join :
  * using

```cpp
message_box::show(ustring::format("Selected files are:\n{}", ustring::join("\n", file_names)));
```
  * instead

```cpp
xtd::ustring txt;
for (auto& filename : file_names) txt += filename + '\n';
message_box::show(ustring::format("Selected files are:\n{}", txt));
```
* Updating [examples/xtd.forms.examples/open_file_box/src/open_file_box.cpp](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/open_file_box/src/open_file_box.cpp) to fix some code styles.

## Documentaton

* Updating [docs/roadmap.md](/docs/documentation/roadmap) to set status.
