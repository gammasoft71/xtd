# console_read

Shows how to use [xtd::console::read](https:gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#ab89501d1732741a45d43b62ed28ef7b9) method.

## Sources

[src/console_read.cpp](src/console_read.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Type a string of text then press Enter. Type '+' anywhere in the text to quit:

The quick brown fox.
Character 'T' is hexadecimal 0x0054.
Character 'h' is hexadecimal 0x0068.
Character 'e' is hexadecimal 0x0065.
Character     is hexadecimal 0x0020.
Character 'q' is hexadecimal 0x0071.
Character 'u' is hexadecimal 0x0075.
Character 'i' is hexadecimal 0x0069.
Character 'c' is hexadecimal 0x0063.
Character 'k' is hexadecimal 0x006b.
Character     is hexadecimal 0x0020.
Character 'b' is hexadecimal 0x0062.
Character 'r' is hexadecimal 0x0072.
Character 'o' is hexadecimal 0x006f.
Character 'w' is hexadecimal 0x0077.
Character 'n' is hexadecimal 0x006e.
Character     is hexadecimal 0x0020.
Character 'f' is hexadecimal 0x0066.
Character 'o' is hexadecimal 0x006f.
Character 'x' is hexadecimal 0x0078.
Character '.' is hexadecimal 0x002e.
Character     is hexadecimal 0x000d.
Character     is hexadecimal 0x000a.

Type a string of text then press Enter. Type '+' anywhere in the text to quit:

^Z
Value was either too large or too small for a character. Value read = -1.

Type a string of text then press Enter. Type '+' anywhere in the text to quit:

+
Character '+' is hexadecimal 0x002b.
```
