---
sidebar_position: 5
---

# How to check that xtd is already installed

This article teaches you how to check which version of the xtd Framework is installed on your computer.
If any command in this article fails, you don't have the xtd Framework installed. For more information, see the [install](/docs/downloads) article.

# Check xtd versions
You can see which versions of the xtd Framework is currently installed with a terminal. Open a terminal and run the following command.

```shell
xtdc --version
```

You get output similar to the following.

```
xtdc version 0.2.0, © 2024 by Gammasoft
```

The [xtdc](https://github.com/gammasoft71/xtd/blob/master/tools/xtdc/README.md) version corresponds to the xtd version.

# More information

You can see the versions of the different libraries composing xtd with the command ```xtdc --info```.
You'll also get other environmental related information, such as the operating system version, compiler version and c++ version.

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)
