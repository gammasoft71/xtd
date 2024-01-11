# console_cursor_visible

Shows how to use [xtd::console::cursor_visible](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a415a3993f5a358a3c90a52ad78ccdbf5) property.

## Sources

[src/console_cursor_visible.cpp](src/console_cursor_visible.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
The cursor is VISIBLE.
Type any text then press Enter. Type '+' in the first column to show
the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
The quick brown fox

The cursor is VISIBLE.
Type any text then press Enter. Type '+' in the first column to show
the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
-

The cursor is HIDDEN.
Type any text then press Enter. Type '+' in the first column to show
the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
jumps over

The cursor is HIDDEN.
Type any text then press Enter. Type '+' in the first column to show
the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
+

The cursor is VISIBLE.
Type any text then press Enter. Type '+' in the first column to show
the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
the lazy dog.

The cursor is VISIBLE.
Type any text then press Enter. Type '+' in the first column to show
the cursor, '-' to hide the cursor, or lowercase 'x' to quit:
x
```
