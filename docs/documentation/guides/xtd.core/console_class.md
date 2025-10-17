# Console applications (xtd.core)

xtd applications can use the [xtd::console](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html) class to read characters from and write characters to the console. 
Data from the console is read from the standard input stream, data to the console is written to the standard output stream, and error data to the console is written to the standard error output stream. 
These streams are automatically associated with the console when the application starts and are presented as the [in](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a7c103233b3e74cb63538b48616b7fd02), [out](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a923837ac84baf01726703e0474ca4888), and [error](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a07c2c9e615422f0ab7321b3331e83c73) properties, respectively.


The value of the [console::in](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a7c103233b3e74cb63538b48616b7fd02) property is a [std::istream](https://en.cppreference.com/w/cpp/io/basic_istream.html) object, whereas the values of the [console::out](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a923837ac84baf01726703e0474ca4888) and [console::error](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a07c2c9e615422f0ab7321b3331e83c73) properties are [std::ostream](https://en.cppreference.com/w/cpp/io/basic_ostream.html) objects. 
You can associate these properties with streams that do not represent the console, making it possible for you to point the stream to a different location for input or output. 
For example, you can redirect the output to a file by setting the [console::out](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a923837ac84baf01726703e0474ca4888) property to a [std::ostream](https://en.cppreference.com/w/cpp/io/basic_ostream.html), which encapsulates a [std::ofstream](https://en.cppreference.com/w/cpp/io/basic_ofstream.html) by means of the [console::set_out](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a87d167b8caea4c48a34906a6d5aa86c2) method. 
The [console::in](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a7c103233b3e74cb63538b48616b7fd02) and [console::out](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html#a923837ac84baf01726703e0474ca4888) properties do not need to refer to the same stream.

> **Note**
> For more information about building console applications, including examples, see the documentation for the [console](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html) class. 

If the console does not exist, for example, in a xtd.forms application, output written to the standard output stream will not be visible, because there is no console to write the information to. 
Writing information to an inaccessible console does not cause an exception to be raised. (You can always change the application type to **Console Application**, for example, in the CMakeLists.txt file).

The [xtd::console](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1console.html) class has methods that can read individual characters or entire lines from the console. 
Other methods convert data and format strings, and then write the formatted strings to the console. 
For more information on formatting strings, see [Formatting types](/docs/documentation/guides/xtd.core/format_number_dates_other_types/overview).

> **Tips**
> Console applications lack a message pump that starts by default.

## See also
* [Formatting types](/docs/documentation/guides/xtd.core/format_number_dates_other_types/overview)
* [Guides](/docs/documentation/guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/building-console-apps)
