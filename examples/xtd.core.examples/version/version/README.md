# version

Demonstrates the [xtd::version](../../../src/xtd.core/include/xtd/version.h) constructor, and major, minor, build, revision, major_revision, and minor_revision properties.

# Sources

[src/version.cpp](src/version.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Standard version:
  major.minor.build.revision = 2.4.1128.2
Interim version:
  major.minor.build.maj_rev/min_rev = 2.4.1128.100/2
```
