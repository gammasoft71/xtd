# time_span_from_hours

Demonstrates the [xtd::time_span::from_days](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a788f3085fe6068614f25c53e6bcfdbc3) method.

## Sources

[src/time_span_from_hours.cpp](src/time_span_from_hours.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
This example of time_span::from_hours(double)
generates the following output.

           from_hours          time_span
           ----------          ---------
                2E-07          00:00:00.0007200
                3E-07          00:00:00.0010800
            0.0012345          00:00:04.4442000
           12.3456789          12:20:44.4440400
       123456.7898765     5144.00:47:23.5554000
            0.0002777          00:00:00.9997199
            0.0166666          00:00:59.9997600
                    1                  01:00:00
                   24                1.00:00:00
          500.3389445       20.20:20:20.2002000
```
