# object_memberwise_clone

Shows hows how to use [xtd::object::memberwise_clone](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object.html#af734e36ea583a842339d7c4444fb6d86) method.

## Sources

[src/object_memberwise_clone.cpp](src/object_memberwise_clone.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Original values of p1 and p2:
   p1 instance values: 
      name: Sam, age: 42
      value: 6565
   p2 instance values:
      name: Sam, age: 42
      value: 6565

Values of p1 and p2 after changes to p1:
   p1 instance values: 
      name: Frank, age: 32
      value: 7878
   p2 instance values:
      name: Frank, age: 42
      value: 7878

Values of p1 and p3 after changes to p1:
   p1 instance values: 
      name: George, age: 39
      value: 8641
   p3 instance values:
      name: Frank, age: 32
      value: 7878
```
