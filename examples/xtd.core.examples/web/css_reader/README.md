# css_reader

Shows how to use [xtd::web::css:css_reader](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1web_1_1css_1_1css__reader.html) class.

## Sources

[src/css_reader.cpp](src/css_reader.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Write all selectors and all properties :
----------------------------------------
.user_box {
  background: #4080FA;
  display: none;
  filter: alpha(opacity=40);
  height: 100%;
  left: 300;
  opacity: 0.4;
  position: fixed;
  top: 200;
  width: 100%;
  z-index: 100;
}

Get specific properties :
-------------------------
filter = alpha(opacity=40)
opacity = 0.4
z-index = 100
```
