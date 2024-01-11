# font

Shows how to use [xtd::drawing::font](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1drawing_1_1font.html) class.

## Sources

[src/font.cpp](src/font.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

## Output

```
font1 = [font: name=Courier New, size=42, units=3, gdi_char_set=0, gdi_vertical_font=false]
font2 = [font: name=Times New Roman, size=24, units=3, gdi_char_set=0, gdi_vertical_font=false]
font3 = [font: name=Times New Roman, size=24, units=3, gdi_char_set=0, gdi_vertical_font=false]
font1 != font2
font2 == font3
```
