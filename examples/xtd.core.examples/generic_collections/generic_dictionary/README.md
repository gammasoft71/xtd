# generic_dictionary

Shows how to use [xtd::collections::generic::dictionary](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1dictionary.html) class.

## Sources

[src/generic_dictionary.cpp](src/generic_dictionary.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
An element with Key = "txt" already exists.
For key = "rtf", value = wordpad.exe.
For key = "rtf", value = winword.exe.
Key = "tif" is not found.
Key = "tif" is not found.
Value added for key = "ht": hypertrm.exe

Key = doc, Value = winword.exe
Key = rtf, Value = winword.exe
Key = bmp, Value = paint.exe
Key = ht, Value = hypertrm.exe
Key = dib, Value = paint.exe
Key = txt, Value = notepad.exe

Value = winword.exe
Value = winword.exe
Value = paint.exe
Value = hypertrm.exe
Value = paint.exe
Value = notepad.exe

Key = doc
Key = rtf
Key = bmp
Key = ht
Key = dib
Key = txt

Remove("doc")
Key "doc" is not found.
```
