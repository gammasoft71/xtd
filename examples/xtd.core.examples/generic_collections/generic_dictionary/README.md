# generic_dictionary

Shows how to use [xtd::collections::generic::dictionary](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1dictionary.html) class.

## Sources

* [src/generic_dictionary.cpp](src/generic_dictionary.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
An element with key = "txt" already exists.
For key = "rtf", value = wordpad.exe.
For key = "rtf", value = winword.exe.
key = "tif" is not found.
key = "tif" is not found.
value added for key = "ht": hypertrm.exe

key = doc, value = winword.exe
key = rtf, value = winword.exe
key = bmp, value = paint.exe
key = ht, value = hypertrm.exe
key = dib, value = paint.exe
key = txt, value = notepad.exe

value = winword.exe
value = winword.exe
value = paint.exe
value = hypertrm.exe
value = paint.exe
value = notepad.exe

key = doc
key = rtf
key = bmp
key = ht
key = dib
key = txt

Remove("doc")
key "doc" is not found.
```
