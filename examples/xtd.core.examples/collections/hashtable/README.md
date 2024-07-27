# hashtable

Shows how to use [hashtable](https://gammasoft71.github.io/xtd/reference_guides/latest/group__collections.html#gaf18249e78122f5f0f0f09003cf6abc5c) alias.

## Sources

[src/hashtable.cpp](src/hashtable.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
For key = "rtf", value = wordpad.exe.
For key = "rtf", value = winword.exe.
Value added for key = "ht": hypertrm.exe

Key = ht, Value = hypertrm.exe
Key = doc, Value = winword.exe
Key = bmp, Value = paint.exe
Key = rtf, Value = winword.exe
Key = dib, Value = paint.exe
Key = txt, Value = notepad.exe

erase("doc")
Key "doc" is not found.
```
