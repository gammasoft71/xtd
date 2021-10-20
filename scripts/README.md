# scripts

Contains cmake, CI, install and tests scrips.

## Continuous Integration

* [appveyor](appveyor) contains Windows build and unit tests scripts for Appveyor.
* [circleci](circleci) contains linux and unit tests build scripts for CircleCI.
* [travis](travis) contains macOS build and unit tests scripts for TravisCI.
* [github](github) contains Windows, macOS and linux build and unit tests scripts for GitHub Actions.

## Installation

* [install](install) contains install scrips for OS. Read [installation](../docs/downloads.md) for more information.

## Tests

* [run_tests.cmd](run_tests.cmd) for running xtd unit tests on Windows. Run it from xtd root folder.
* [run_tests.sh](run_tests.sh) for running xtd unit tests on macOS or linux. Run it from xtd root folder.
