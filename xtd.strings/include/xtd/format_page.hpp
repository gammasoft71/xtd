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
/// ach format item takes the following form and consists of the following components:
///
/// <H2>{[<b>index</b>][<b>,alignment</b>][<b>:format</b>]}</H2>
///
/// @section IdSection index
///
/// Represent argument identifier, it optional
///
/// If not pecified, the argument identifiers are automaicaly generated.
///
/// @par Examples:
///
/// Example with specifying argument identifier :
/// @code
/// cout << strings::format("{0}, {1}, {3}", 42, 'c', "word") << endl;
/// cout << strings::format("The {0} we {1} {1} {2} {1}.", "man", "saw", 'a') << endl; // repeated identifier
/// @endcode
///
/// Output :
/// @code
/// 42, c, word
/// The man saw saw a saw.
/// @endcode
///
/// Example without specifying argument identifier :
/// @code
/// cout << strings::format("{} {} {}", 1, "two", 3.0) << endl;
/// cout << strings::format("{}, {}!", "Hello", "World") << endl;
/// @endcode
///
/// Output :
/// @code
/// 1 two 3
/// Hello, World!
/// @endcode
///
/// @section PrecisionSection precision
///
/// Precision must begin with <b>,</b> character and contains a positive or negative integer value :
///   * positivie value : pad left.
///   * negative value : pad rigth.
///
/// @par Examples
///
/// Example with precision :
/// @code
/// cout << strings::format("{0,4} items", 10) << endl;
/// cout << strings::format("{0,-4} items", 10) << endl;
/// @endcode
///
/// Output :
/// @code
/// 10   items
///   10 items
/// @endcode
///
/// @section FormatSection format
/// Format is optional.
///
/// @subsection StringFormatSubsection String format
///
/// No need format specification for string
///
/// @subsection NumericFormatSubsection Numeric format
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

