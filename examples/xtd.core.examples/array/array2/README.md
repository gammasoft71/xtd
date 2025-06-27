# array2

Shows how to use [xtd::array](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1array.html) class.

## Sources

[src/array2.cpp](src/array2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Initially,
integer array:	1	2	3	4	5
Object array: 	26	27	28	29	30

After copying the first two elements of the integer array to the Object array,
integer array:	1	2	3	4	5
Object array: 	1	2	28	29	30

After copying the last two elements of the Object array to the integer array,
integer array:	1	2	3	29	30
Object array: 	1	2	28	29	30
```
