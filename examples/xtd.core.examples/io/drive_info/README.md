# drive_info

Show how to use [xtd::io::drive_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1drive__info.html) class.

## Sources

[src/drive_info.cpp](src/drive_info.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
This code produces the following output :

Drive A:\
  Drive type: Removable
Drive C:\
  Drive type: Fixed
  Volume label:
  File system: FAT32
  Available space to current user:     4770430976 bytes
  Total available space:               4770430976 bytes
  Total size of drive:                10731683840 bytes
Drive D:\
  Drive type: Fixed
  Volume label:
  File system: NTFS
  Available space to current user:    15114977280 bytes
  Total available space:              15114977280 bytes
  Total size of drive:                25958948864 bytes
Drive E:\
  Drive type: CDRom

The actual output of this code will vary based on machine and the permissions
granted to the user executing it.
```

