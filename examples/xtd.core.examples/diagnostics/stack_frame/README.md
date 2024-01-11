# stack_frame

Shows how to use [xtd::diagnostics::stack_frame](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1diagnostics_1_1stack__frame.html) class.

## Sources

[src/stack_frame.cpp](src/stack_frame.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
This code produces the following output :

 Stack trace for Method2:    at main [0x000030B0] in /!---OMITTED---!/stack_frame:line 0
   at method2(int)
   at method1()
   at main
 Stack trace for Method1:    at method1() [0x00002D20] in /!---OMITTED---!/stack_frame:line 0
   at method1()
   at main
 Stack trace for next level frame:    at main [0x000030B0] in /!---OMITTED---!/stack_frame:line 0
 Stack trace for Main:    at main [0x000030B0] in /!---OMITTED---!/stack_frame:line 0
   at main
Press Enter to exit.
```
