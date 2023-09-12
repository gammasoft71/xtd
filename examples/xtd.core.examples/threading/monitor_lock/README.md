# monitor_lock

Shows how to use [xtd::threading::monitor](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1monitor.html) class.

## Sources

[src/monitor_lock.cpp](src/monitor_lock.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Starting synchronized resource access on thread #6
Stopping synchronized resource access on thread #6
Starting synchronized resource access on thread #9
Stopping synchronized resource access on thread #9
Starting synchronized resource access on thread #2
Stopping synchronized resource access on thread #2
Starting synchronized resource access on thread #3
Stopping synchronized resource access on thread #3
Starting synchronized resource access on thread #8
Stopping synchronized resource access on thread #8
	
All synchronized operations have completed.

Starting unsynchronized resource access on Thread #9
Starting unsynchronized resource access on Thread #2
Starting unsynchronized resource access on Thread #11
Starting unsynchronized resource access on Thread #6
Starting unsynchronized resource access on Thread #4
Stopping unsynchronized resource access on thread #9
Stopping unsynchronized resource access on thread #11
Stopping unsynchronized resource access on thread #6
Stopping unsynchronized resource access on thread #2
Stopping unsynchronized resource access on thread #4
	
All unsynchronized thread operations have completed.

```
