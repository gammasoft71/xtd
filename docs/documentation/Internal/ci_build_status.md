# Continuous Integration build status

At each commit, a build and unit tests are performed for the following configurations

| Operating system | Architecture            | Compiler      | Build Type      | Status                                                                                                                                                                                      |
| -----------------| ----------------------- | ------------- | --------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Linux (Ubuntu)   | x86 / x64               | Clang / GCC   | Debug / Release | [![Ubuntu](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/ubuntu.yml?branch=master&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/ubuntu.yml)    |
| macOS            | x64 / arm64             | Apple Clang   | Debug / Release | [![macOS](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/macos.yml?branch=master&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/macos.yml)       |
| Windows          | x86 / x64               | MSVC (VS2022) | Debug / Release | [![Windows](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/windows.yml?branch=master&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/windows.yml) |
| Windows (MSYS2)  | x64                     | Clang / GCC   | Debug / Release | [![Manually](https://img.shields.io/badge/build-manually-004080?branch=master&logo=gitHub&.svg)]()                                                                                          |
| Android _(*)_    | arm64-v8a / armeabi-v7a | Clang (NDK)   | Release         | [![Coming soon](https://img.shields.io/badge/build-coming%20soon...-808080?branch=master&logo=gitHub&.svg)]()                                                                               |
| iOS _(*)_        | arm64 / x86_64 sim      | Apple Clang   | Release         | [![Coming soon](https://img.shields.io/badge/build-coming%20soon...-808080?branch=master&logo=gitHub&.svg)]()                                                                               |
| FreeBSD          | x64                     | Clang / GCC   | Debug / Release | [![Manually](https://img.shields.io/badge/build-manually-004080?branch=master&logo=gitHub&.svg)]()                                                                                          |
| Haiku _(*)_      | x86                     | GCC           | Debug           | [![Manually](https://img.shields.io/badge/build-manually-004080?branch=master&logo=gitHub&.svg)]()                                                                                          |

 _(*) [xtd.core and xtd.tunit only](https://gammasoft71.github.io/xtd/docs/documentation/portability)._

| Deploy to GitHub Pages                   | status                                                                                                                                                                                                           |
| ---------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Deployment of the website                | [![Ubuntu Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/deploy.yml?branch=docs&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/deploy.yml)                     |
| Deployment of the latest reference guide | [![Ubuntu Debug](https://img.shields.io/github/actions/workflow/status/gammasoft71/xtd/reference_guide.yml?branch=master&logo=gitHub)](https://github.com/gammasoft71/xtd/actions/workflows/reference_guide.yml) |
