# color

Shows how to use [xtd::drawing::color](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1drawing_1_1color.html) class.

## Sources

[src/color.cpp](src/color.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```shell
xtdc run
```

## Output

```
color::black = color [black]
color::withe = color [white]
color::blue = color [blue]
Color::light_green = color [light_green]
Color::from_argb(255, 253, 2, 0) = color [a=255, r=253, g=2, b=0]
color::from_name("dodger_blue") = color [dodger_blue]
color::from_name("dodger blue") = color [dodger_blue]
color::from_name("dodgerblue") = color [dodger_blue]
```
