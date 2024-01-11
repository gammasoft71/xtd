# time_span_from_days

Demonstrates the [xtd::time_span::from_days](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a8417d7db7bed884f491005bccf2bb786) method.

## Sources

[src/time_span_from_days.cpp](src/time_span_from_days.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
This example of time_span::from_days(double)
generates the following output.

            from_days          time_span
            ---------          ---------
                6E-09          00:00:00.0010000
              1.7E-08          00:00:00.0010000
          0.000123456          00:00:10.6670000
          1.234567898        1.05:37:46.6660000
      12345.678987654    12345.16:17:44.5330000
           1.1574E-05          00:00:01        
          0.000694444          00:01:00        
          0.041666666          01:00:00        
                    1        1.00:00:00        
          20.84745602       20.20:20:20.2000000
```
