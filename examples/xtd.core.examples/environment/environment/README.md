# environment

Shows how to use [xtd::environment](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1environment.html) class.

## Sources

[src/environment.cpp](src/environment.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
>environment ARBITRARY TEXT

-- environment members --
command_line: !---OMITTED---!/environment ARBITRARY TEXT
get_command_line_args: !---OMITTED---!/environment, ARBITRARY, TEXT
current_directory: !---OMITTED---!/environment/environment/Debug
exit_code: 0
has_shutdown_started: false
machine_name: !---OMITTED---!
new_line:
first line
second line
third line
os_version: macOS 12.6.0
stack_trace: '   at xtd::environment::stack_trace()
   at environment_example::program::main()
   at main::startup::run(void (*)(), int, char**)'
system_directory: /System
tick_count: 3.01:15:01:827000000
user_domain_name: !---OMITTED---!
user_interactive: true
user_name: !---OMITTED---!
version: 0.2.0
working_set: 0
expand_environment_variables:
My home folder is /Users/!---OMITTED---! and user is !---OMITTED---!
get_environment_variable:
My temporary directory is /var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T/.
get_environment_variables:
...
!---OMITTED---!
get_folder_path: /System
GetLogicalDrives: /, /dev, /System/Volumes/Hardware, /System/Volumes/Update, /System/Volumes/Preboot, /System/Volumes/xarts, /System/Volumes/VM, /System/Volumes/Data, /System/Volumes/iSCPreboot, /System/Volumes/Data/home, /Volumes/Data
```
