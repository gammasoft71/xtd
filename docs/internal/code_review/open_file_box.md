# Review open_file_box

## Implementation

* Updating [src/xtd.forms/CMakeLists.txt](../../../src/xtd.forms/CMakeLists.txt) to add open_file_box.h and  open_file_box_options.h.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box.h](../../../src/xtd.forms/include/xtd/forms/open_file_box.h) to add  comments.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box.h](../../../src/xtd.forms/include/xtd/forms/open_file_box.h) to add  comment line : /// @include open_file_box.cpp.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box.h](../../../src/xtd.forms/include/xtd/forms/open_file_box.h) to fix some code styles.
* Updating [src/xtd.forms/include/xtd/forms/open_file_box_options.h](../../../src/xtd.forms/include/xtd/forms/open_file_box_options.h) to use binary literals instead shift operators.

## Example

* Updating [examples/xtd.forms.examples/dialogs/CMakeLists.txt](../../../examples/xtd.forms.examples/dialogs/CMakeLists.txt) to add open_file_box project.
* Updating [examples/xtd.forms.examples/README.md](../../../examples/xtd.forms.examples/README.md) to add open_file_box example.
* Updating [examples/xtd.forms.examples/open_file_box/src/open_file_box.cpp](../../../eexamples/xtd.forms.examples/open_file_box/src/open_file_box.cpp) to fix build warning : capture this in lambda button_open_multiple_files.click
* Updating [examples/xtd.forms.examples/open_file_box/src/open_file_box.cpp](../../../eexamples/xtd.forms.examples/open_file_box/src/open_file_box.cpp) to use xtd::ustring::join :
  * using
```c++
message_box::show(ustring::format("Selected files are:\n{}", ustring::join("\n", file_names)));
```
  * instead
```c++
xtd::ustring txt;
for (auto& filename : file_names) txt += filename + '\n';
message_box::show(ustring::format("Selected files are:\n{}", txt));
```
* Updating [examples/xtd.forms.examples/open_file_box/src/open_file_box.cpp](../../../examples/xtd.forms.examples/open_file_box/src/open_file_box.cpp) to fix some code styles.

## Documentaton

* Updating [docs/roadmap.md](../../../docs/roadmap.md) to set status.
