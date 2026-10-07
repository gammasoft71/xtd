# basic_colors

Demonstrates how to use [xtd::drawing::basic_colors](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1drawing_1_1basic__colors.html) class.

## Sources

* [src/basic_colors.cpp](src/basic_colors.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

## Output

```
| -------------------------- | ------- | ---------------------------- | --------------------------- | --------------------------- | ------------------------ | ------------------ | -------- |
| Name                       | Hex     | CMYK                         | HSL                         | HSV                         | HTML                     | RGB                | Win32    |
| -------------------------- | ------- | ---------------------------- | --------------------------- | --------------------------- | ------------------------ | ------------------ | -------- |
| white                      | #ffffff | cmyk(0%, 0%, 0%, 0%)         | hsl(0, 0%, 100%)            | hsv(0, 0%, 0%)              | White                    | rgb(255, 255, 255) | 0xffffff |
| silver                     | #c0c0c0 | cmyk(0%, 0%, 0%, 25%)        | hsl(0, 0%, 75%)             | hsv(0, 0%, 0%)              | Silver                   | rgb(192, 192, 192) | 0xc0c0c0 |
| gray                       | #808080 | cmyk(0%, 0%, 0%, 50%)        | hsl(0, 0%, 50%)             | hsv(0, 0%, 0%)              | Gray                     | rgb(128, 128, 128) | 0x808080 |
| black                      | #000000 | cmyk(0%, 0%, 0%, 100%)       | hsl(0, 0%, 0%)              | hsv(0, 0%, 0%)              | Black                    | rgb(0, 0, 0)       | 0x000000 |
| red                        | #ff0000 | cmyk(0%, 100%, 100%, 0%)     | hsl(0, 100%, 50%)           | hsv(0, 100%, 100%)          | Red                      | rgb(255, 0, 0)     | 0x0000ff |
| maroon                     | #800000 | cmyk(0%, 100%, 100%, 50%)    | hsl(0, 100%, 25%)           | hsv(0, 100%, 100%)          | Maroon                   | rgb(128, 0, 0)     | 0x000080 |
| yellow                     | #ffff00 | cmyk(0%, 0%, 100%, 0%)       | hsl(60, 100%, 50%)          | hsv(60, 100%, 100%)         | Yellow                   | rgb(255, 255, 0)   | 0x00ffff |
| olive                      | #808000 | cmyk(0%, 0%, 100%, 50%)      | hsl(60, 100%, 25%)          | hsv(60, 100%, 100%)         | Olive                    | rgb(128, 128, 0)   | 0x008080 |
| lime                       | #00ff00 | cmyk(100%, 0%, 100%, 0%)     | hsl(120, 100%, 50%)         | hsv(120, 100%, 100%)        | Lime                     | rgb(0, 255, 0)     | 0x00ff00 |
| green                      | #008000 | cmyk(100%, 0%, 100%, 50%)    | hsl(120, 100%, 25%)         | hsv(120, 100%, 100%)        | Green                    | rgb(0, 128, 0)     | 0x008000 |
| aqua                       | #00ffff | cmyk(100%, 0%, 0%, 0%)       | hsl(180, 100%, 50%)         | hsv(180, 100%, 100%)        | Aqua                     | rgb(0, 255, 255)   | 0xffff00 |
| teal                       | #008080 | cmyk(100%, 0%, 0%, 50%)      | hsl(180, 100%, 25%)         | hsv(180, 100%, 100%)        | Teal                     | rgb(0, 128, 128)   | 0x808000 |
| blue                       | #0000ff | cmyk(100%, 100%, 0%, 0%)     | hsl(240, 100%, 50%)         | hsv(240, 100%, 100%)        | Blue                     | rgb(0, 0, 255)     | 0xff0000 |
| navy                       | #000080 | cmyk(100%, 100%, 0%, 50%)    | hsl(240, 100%, 25%)         | hsv(240, 100%, 100%)        | Navy                     | rgb(0, 0, 128)     | 0x800000 |
| fuchsia                    | #ff00ff | cmyk(0%, 100%, 0%, 0%)       | hsl(300, 100%, 50%)         | hsv(300, 100%, 100%)        | Fuchsia                  | rgb(255, 0, 255)   | 0xff00ff |
| purple                     | #800080 | cmyk(0%, 100%, 0%, 50%)      | hsl(300, 100%, 25%)         | hsv(300, 100%, 100%)        | Purple                   | rgb(128, 0, 128)   | 0x800080 |
| -------------------------- | ------- | ---------------------------- | --------------------------- | --------------------------- | ------------------------ | ------------------ | -------- |
```
