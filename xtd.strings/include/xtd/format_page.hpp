/// @file
/// @brief Contains doygen format page.
///
/// @page FormatPage Format Documentation
///
/// @section CompositeFormatting Composite Formatting
///
/// The composite formatting feature takes a list of objects and a composite format string as input. A composite format string consists of fixed text intermixed with indexed placeholders, called format items, that correspond to the objects in the list. The formatting operation yields a result string that consists of the original fixed text intermixed with the string representation of the objects in the list.
///
/// The composite formatting feature is supported by methods such as the following:
/// * xtd::strings.format, which returns a formatted result string (xtd.strings library).
/// * Some overloads of the console::write_line method, which display a formatted result string to the console (xtd.console library).
/// * xtd::diagnostics::debug::write_line method, which outputs a formatted message to trace listeners (xtd.diagnostics library).
/// * The xtd::diagnostics::trace::trace_error, xtd::diagnostics::trace::trace_information, and xtd::diagnostics::trace::trace_warning methods, which output formatted messages to trace listeners (xtd.diagnostics library).
///
/// @subsection CompositeFormatStringSubsection Composite Format String
///
/// A composite format string and object list are used as arguments of methods that support the composite formatting feature. A composite format string consists of zero or more runs of fixed text intermixed with one or more format items. The fixed text is any string that you choose, and each format item corresponds to an object or boxed structure in the list. The composite formatting feature returns a new result string where each format item is replaced by the string representation of the corresponding object in the list.
///
/// Consider the following Format code fragment.
///
/// @code
/// string name = "Fred";
/// xtd::strings::format("Name = {0}, age = {1:D3}", name, 42);
/// @endcode
///
/// The fixed text is "Name = " and ", age = ". The format items are "{0}", whose index is 0, which corresponds to the object name, and "{1:D3}", whose index is 1, which corresponds to the integer 42.
///
/// @subsection FormatItemSyntaxSubsection Format Item Syntax
///
/// Each format item takes the following form and consists of the following components:
///
/// <H3>{[<b>index</b>][<b>,alignment</b>][<b>:format_string</b>]}</H3>
///
/// The matching braces ("{" and "}") are required.
///
/// @subsection IndexComponentSubsection Index Component
///
/// The optional index component, also called a parameter specifier, is a number starting from 0 that identifies a corresponding item in the list of objects. That is, the format item whose parameter specifier is 0 formats the first object in the list, the format item whose parameter specifier is 1 formats the second object in the list, and so on. The following example includes four parameter specifiers, numbered zero through three, to represent prime numbers less than ten:
///
/// @code
/// std::string primes;
/// primes = xtd::strings::format("Prime numbers less than 10: {0}, {1}, {2}, {3}", 2, 3, 5, 7 );
/// std::cout << primes << std::endl;
/// // The example displays the following output:
/// //
/// // Prime numbers less than 10: 2, 3, 5, 7
/// @endcode
///
/// Multiple format items can refer to the same element in the list of objects by specifying the same parameter specifier. For example, you can format the same numeric value in hexadecimal, scientific, and number format by specifying a composite format string such as : "0x{0:X} {0:E} {0:N}", as the following example shows.
///
/// @code
/// std::string multiple = xtd::strings::format("0x{0:X} {0:E} {0:N}", std::numeric_limits<long long>::max());
/// std::cout << multiple << std::endl;
/// // The example displays the following output:
/// //
/// // 0x7FFFFFFFFFFFFFFF 9.223372E+18 9,223,372,036,854,775,807.00
/// @endcode
///
/// Each format item can refer to any object in the list. For example, if there are three objects, you can format the second, first, and third object by specifying a composite format string like this: "{1} {0} {2}". An object that is not referenced by a format item is ignored. A std::argument_error is thrown at runtime if a parameter specifier designates an item outside the bounds of the list of objects.
///
/// If the index component is not specified, it will be automatically generated in the order of the argument list.
///
/// The following example shows format without specified index:
///
/// @code
/// std::cout << xtd::strings::format("{} {} {:F2}", 1, "two", 3.0) << std::endl;
/// // The example displays the following output:
/// //
/// // 1 two 3.00
/// @endcode
///
/// @subsection AlignmentComponentSubsection Alignment Component
///
/// The optional alignment component is a signed integer indicating the preferred formatted field width. If the value of alignment is less than the length of the formatted string, alignment is ignored and the length of the formatted string is used as the field width. The formatted data in the field is right-aligned if alignment is positive and left-aligned if alignment is negative. If padding is necessary, white space is used. The comma is required if alignment is specified.
///
/// The following example defines two arrays, one containing the names of employees and the other containing the hours they worked over a two-week period. The composite format string left-aligns the names in a 20-character field, and right-aligns their hours in a 5-character field. Note that the "N1" standard format string is also used to format the hours with one fractional digit.
///
/// @code
/// #include <iostream>
/// #include <vector>
/// #include <xtd/strings>
///
/// int main() {
///   std::vector names = {"Adam", "Bridgette", "Carla", "Daniel", "Ebenezer", "Francine", "George"};
///   std::vector hours = {40.0, 6.667, 40.39, 82.0, 40.333, 80.0, 16.75};
///
///   std::cout << xtd::strings::format("{0,-20} {1,5}\n", "Name", "Hours") << std::endl;
///   for (size_t ctr = 0; ctr < names.size(); ctr++)
///     std::cout << xtd::strings::format("{0,-20} {1,5:N1}", names[ctr], hours[ctr]) << std::endl;
/// }
///
/// // The example displays the following output:
/// //
/// // Name                 Hours
/// //
/// // Adam                  40.0
/// // Bridgette              6.7
/// // Carla                 40.4
/// // Daniel                82.0
/// // Ebenezer              40.3
/// // Francine              80.0
/// // George                16.8
/// @endcode
///
/// @subsection FormatStringComponentSubsection Format String Component
///
/// @subsection StringFormatSubsection String format
///
/// The optional formatString component is a format string that is appropriate for the type of object being formatted. Specify a numeric format string if the corresponding object is a numeric value, or an enumeration format string if the corresponding object is an enumeration value. If formatString is not specified, the general ("G") format specifier for a numeric or enumeration type is used. The colon is required if formatString is specified.
///
/// The following table lists types or categories of types that support a predefined set of format strings, and provides links to the topics that list the supported format strings. Note that string formatting is an extensible mechanism that makes it possible to define new format strings for all existing types as well as to define a set of format strings supported by an application-defined type. For more information, see @ref CustomFormatSubsection.
///
/// | Type or Type category                                                                                                                                            | See                              |
/// |------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------|
/// | Boolean type (bool)                                                                                                                                              | @ref BooleanFormatSection        |
/// | Enumeration types (all enum or enum class types)                                                                                                                 | @ref EnumerationFormatSection    |
/// | Numeric types (char, unsigned char, short, unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long long, float, double and long double) | @ref NumericFormatSection        |
///
/// @subsection EscapingBracesSubsection Escaping Braces
///
/// Opening and closing braces are interpreted as starting and ending a format item. Consequently, you must use an escape sequence to display a literal opening brace or closing brace. Specify two opening braces ("{{") in the fixed text to display one opening brace ("{"), or two closing braces ("}}") to display one closing brace ("}"). Braces in a format item are interpreted sequentially in the order they are encountered. Interpreting nested braces is not supported.
///
/// The way escaped braces are interpreted can lead to unexpected results. For example, consider the format item "{{{0:D}}}", which is intended to display an opening brace, a numeric value formatted as a decimal number, and a closing brace. However, the format item is actually interpreted in the following manner:
///
/// 1. The first two opening braces ("{{") are escaped and yield one opening brace.
/// 2. The next three characters ("{0:") are interpreted as the start of a format item.
/// 3. The next character ("D") would be interpreted as the Decimal standard numeric format specifier, but the next two escaped braces ("}}") yield a single brace. Because the resulting string ("D}") is not a standard numeric format specifier, the resulting string is interpreted as a custom format string that means display the literal string "D}".
/// 4. The last brace ("}") is interpreted as the end of the format item.
/// 5. he final result that is displayed is the literal string, "{D}". The numeric value that was to be formatted is not displayed.
///
/// One way to write your code to avoid misinterpreting escaped braces and format items is to format the braces and format item separately. That is, in the first format operation display a literal opening brace, in the next operation display the result of the format item, then in the final operation display a literal closing brace. The following example illustrates this approach.
///
/// @code
/// int value = 6324;
/// std::string output = xtd::strings::format("{0}{1:D}{2}", "{", value, "}");
/// std::cout << output << std::endl;
/// // The example displays the following output:
/// //
/// // {6324}
/// @endcode
///
/// @subsection CodeExamplesSubsection Code Examples
///
/// The following example shows one string created using composite formatting and another created using xtd::to_string method. Both types of formatting produce equivalent results.
///
/// @code
/// std::string format_string1 = xtd::strings::format("0:X4", std::numeric_limits<short>::max());
/// std::string format_string2 = xtd::to_strings::format(std::numeric_limits<short>::max(), "X4");
/// @endcode
///
/// @section NumericFormatSection Numeric format
///
/// Standard numeric format strings are used to format common numeric types. A standard numeric format string takes the form <b>Axx</b>, where:
/// * <b>A</b> is a single alphabetic character called the format specifier.
/// * <b>xx</b> is an optional integer called the precision specifier. The precision specifier ranges from 0 to 99 and affects the number of digits in the result. Note that the precision specifier controls the number of digits in the string representation of a number. It does not round the number itself. To perform a rounding operation, use the std::ceil, std::floor, or std::round method.
/// When precision specifier controls the number of fractional digits in the result string, the result string reflects a number that is rounded to a representable result nearest to the infinitely precise result
///
///
///
/// @remarks
/// <b>precision>/b> and <b>format>/b> are optional and can be present in the same time.
