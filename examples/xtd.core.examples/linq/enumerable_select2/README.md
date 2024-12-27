# enumerable_select2

Shows how to use [xtd::linq::enumerable::select](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1linq_1_1enumerable.html#ae2df9541f109773859bcaaf42015b8cd) method.

## Sources

[src/enumerable_select2.cpp](src/enumerable_select2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
student_query1: select range_variable
Claire O'Donnell:112
Sven Mortensen:113
Cesar Garcia:114

student_query2: select range_variable.property
O'Donnell
Mortensen
Garcia

student_query3: select range_variable.method
ClaireO@Contoso.com,206-555-0298
SvenMort@Contoso.com,206-555-1130
CesarGar@Contoso.com,206-555-0521

student_query4: select range_variable[index]
First score = 75
First score = 88
First score = 97

student_query5: select expression
Adjusted first score = 82.5
Adjusted first score = 96.8
Adjusted first score = 106.7

student_query6: select expression2
Average = 72.25
Average = 84.5
Average = 88.25

student_query7: select tuple type
O'Donnell, Claire
Mortensen, Sven
Garcia, Cesar

student_query8: select named type
ID = 112, Average = 72.25
ID = 113, Average = 84.5
ID = 114, Average = 88.25
```
