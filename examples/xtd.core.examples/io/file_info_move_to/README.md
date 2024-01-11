# file_info_move_to

Show how to use [xtd::io::file_info::move_to](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__info.html#a518d205507601c6de179fab492750dbc) method.

## Sources

[src/file_info_move_to.cpp](src/file_info_move_to.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Welcome.
This application demonstrates the file_info.move_to method.
Press any key to start.

    Checking whether C:\Documents and Settings\MyComputer\My Documents\file_infoTestDirectory\MoveFrom\FromFile.xml exists.
Creating file C:\Documents and Settings\MyComputer\My Documents\file_infoTestDirectory\MoveFrom\FromFile.xml.
Adding data to the file.
Successfully created the file.
The file_info instance shows these property values.
FullName: C:\Documents and Settings\MyComputer\My Documents\file_infoTestDirectory\MoveFrom\FromFile.xml
CreationTime: 4/18/2006 1:24:19 PM
LastWriteTime: 4/18/2006 1:24:19 PM

File contents:

<?xml version="1.0" standalone="yes"?>
<MyElement Index="0">
MyElement at position 0.
<MyElement Index="1">
MyElement at position 1.
<MyElement Index="2">
MyElement at position 2.
<MyElement Index="3">
MyElement at position 3.
<MyElement Index="4">
MyElement at position 4.
<MyElement Index="5">
MyElement at position 5.
<MyElement Index="6">
MyElement at position 6.
<MyElement Index="7">
MyElement at position 7.
<MyElement Index="8">
MyElement at position 8.
<MyElement Index="9">
MyElement at position 9.

Preparing to move the file to
C:\Documents and Settings\MYComputer\My Documents\file_infoTestDirectory\DestFile.xml.
File moved to
C:\Documents and Settings\MYComputer\My Documents\file_infoTestDirectory\DestFile.xml
The file_info instance shows these property values.
FullName: C:\Documents and Settings\MYComputer\My Documents\file_infoTestDirectory\DestFile.xml
CreationTime: 4/18/2006 1:24:19 PM
LastWriteTime: 4/18/2006 1:24:19 PM

File contents:

<?xml version="1.0" standalone="yes"?>
<MyElement Index="0">
MyElement at position 0.
<MyElement Index="1">
MyElement at position 1.
<MyElement Index="2">
MyElement at position 2.
<MyElement Index="3">
MyElement at position 3.
<MyElement Index="4">
MyElement at position 4.
<MyElement Index="5">
MyElement at position 5.
<MyElement Index="6">
MyElement at position 6.
<MyElement Index="7">
MyElement at position 7.
<MyElement Index="8">
MyElement at position 8.
<MyElement Index="9">
MyElement at position 9.

Preparing to delete directories.
Successfully deleted directories and files.
Press the ENTER key to close this application.
```
