# process_with_standard_output_redirection

Shows how to use [xtd::process](../../../../src/xtd.core/include/xtd/diagnostics/process.h) class with standard output redirection.

## Sources

[src/process_with_standard_output_redirection.cpp](src/process_with_standard_output_redirection.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
xtdc version 1.0.0, © 2021 by Gammasoft

Usage: xtdc [<options> | command [<command-argument>] [<command-options>]]

options:
  -i, --info       Display information.
  -v, --version    Display version in use.
  -h, --help       Display help.

command:
  new              Initializes project.
  add              Adds new project to project.
  update           Regenerates a project.
  run              Compiles and immediately executes a project.
  build            Builds a project.
  install          Install a project.
  clean            Clean build output(s).
  open             Open a project in default ide.
  targets          List project targets.
  test             Runs unit tests using the test runner specified in the project.
  uninstall        Uninstall a project.
  documentation    Open xtd documentation.
  examples         Open xtd examples.
  guide            Open xtd reference guide.
  web              Open Gammasoft website.
  help             Show help.

Run 'xtdc command --help' for more information on a command.
```
