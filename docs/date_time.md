| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# Date and time

## In This Section

This article includes several examples that use the DateTime type:

* Initialization Examples
  * [Invoke a constructor](#invoke-a-constructor)
  * [Invoke the implicit parameterless constructor](#)
  * [Assignment from return value](#)
  * [Parsing a string that represents a date and time](#)
  * [Visual Basic syntax to initialize a date and time](#)
* Formatting DateTime objects as strings
  * [Use the default date time format](#)
  * [Format a date and time using a specific culture](#)
  * [Format a date time using a standard or custom format string](#)
  * [Specify both a format string and a specific culture](#)
  * [Format a date time using the ISO 8601 standard for web services](#)
* Parsing strings as DateTime objects
  * [Use Parse or TryParse to convert a string to a date and time](#)
  * [Use ParseExact or TryParseExact to convert a string in a known format](#)
  * [Convert from the ISO 8601 string representation to a date and time](#)
* DateTime resolution
  * [Explore the resolution of date and time values](#)
  * [Comparing for equality within a tolerance](#)
  * [Culture and calendars](#)
  * [Display date and time values using culture specific calendars](#)
  * [Parse strings according to a culture specific calendar](#)
  * [Initialize a date and time from a specific culture's calendar](#)
  * [Accessing date and time properties using a specific culture's calendar](#)
  * [Retrieving the week of the year using culture specific calendars](#)
* Persistence
  * [Persisting date and time values as strings in the local time zone](#)
  * [Persisting date and time values as strings in a culture and time invariant format](#)
  * [Persisting date and time values as integers](#)
  * [Persisting date and time values using the XmlSerializer](#)
  * [Persisting date and time values using the BinaryFormatter](#)
  * [Persisting date and time values with time zone data](#)

## Quick links to Remarks topics.

This section contains topics for many common uses of the DateTime struct:

* [Initializing a date_time object](#initializing-a-date-time-object)
* [DateTime values and their string representations](#)
* [Parsing DateTime values from strings](#)
* [DateTime values](#)
* [DateTime operations](#)
* [DateTime resolution](#)
* [DateTime values and calendars](#)
* [Persisting DateTime values](#)
* [DateTime vs. TimeSpan](#)
* [Comparing for equality within tolerance](#)
* [COM interop considerations](#)

The [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value type represents dates and times with values ranging from 00:00:00 (midnight), January 1, 0001 Anno Domini (Common Era) through 11:59:59 P.M., December 31, 9999 A.D. (C.E.) in the Gregorian calendar.

Time values are measured in 100-nanosecond units called [ticks](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#ga8fd3ccd5f25e401dc28a28ba352aa966). A particular date is the number of ticks since 12:00 midnight, January 1, 0001 A.D. (C.E.) in the GregorianCalendar calendar. 
The number excludes ticks that would be added by leap seconds. For example, a ticks value of 31241376000000000L represents the date Friday, January 01, 0100 12:00:00 midnight. A [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value is always expressed in the context of an explicit or default calendar.

## Note

  If you are working with a ticks value that you want to convert to some other time interval, such as minutes or seconds, you should use the [std::chono::duretion_cast<>](https://en.cppreference.com/w/cpp/chrono/duration/duration_cast) converter to perform the conversion or use [std::chrono::nanoseconds](https://en.cppreference.com/w/cpp/chrono/duration), [std::chrono::microseconds](https://en.cppreference.com/w/cpp/chrono/duration), [std::chrono::milliseonds](https://en.cppreference.com/w/cpp/chrono/duration), [std::chrono::seconds](https://en.cppreference.com/w/cpp/chrono/duration), [std::chrono::minutes](https://en.cppreference.com/w/cpp/chrono/duration) and [std::chrono::hours](https://en.cppreference.com/w/cpp/chrono/duration) durations. 
  For example, to add the number of seconds represented by a specified number of ticks to the [second](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#ae084c4d68a46500b8e64f4aec4869a15) component of a [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value, you can use the expression 'dateValue.second() + std::duration_cast<std::chrono::second>(n_ticks).count()'.

You can view the source for the entire set of examples from this article from the [examples](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.core.examples/date_time/README.md) repository on GitHub.

## Initializing a date_time object

You can assign an initial value to a new `date_time` value in many different ways:
* Calling a constructor, either one where you specify arguments for values, or use the implicit parameterless constructor.
* Assigning a `date_time` to the return value of a property or method.
* Parsing a `date_time` value from its string representation.

The following code snippets show examples of each:

### Invoke Constructors

You call any of the overloads of the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) constructor that specify elements of the date and time value (such as the year, month, and day, or the number of ticks). 
The following code creates a specific date using the DateTime constructor specifying the year, month, day, hour, minute, and second.

```cpp
auto date1 = date_time(2008, 5, 1, 8, 30, 52);
console::write_line(date1);
```

You invoke the `date_time` structure's implicit parameterless constructor when you want a `date_time` initialized to its default value.
The following example illustrates the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) implicit parameterless constructor.

```cpp
auto dat1 = date_time();
// The following method call displays 1/1/0001 12:00:00 AM.
console::write_line(dat1.to_string());
// The following method call displays true.
console::write_line(dat1 == date_time::min_value);
```

### Assigning a computed value

You can assign the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) object a date and time value returned by a property or method. 
The following example assigns the current date and time, the current Coordinated Universal Time (UTC) date and time, and the current date to three new [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) variables.

```cpp
date_time date1 = date_time::now();
date_time date2 = date_time::utc_now();
date_time date3 = date_time.today();
```
### Parsing a string that represents a DateTime

The [xtd::parse<xtd::data_time>](), [xtd::date_time::parse](), [xtd::date_time::parse_exact](), [xtd::try_parse<xtd::date_time>](), [xtd::date_time::try_parse](), and [xtd::date_time::try_parse_exact]() methods all convert a string to its equivalent date and time value.
The following examples use the [xtd::date_time::parse]() and [xtd::date_time::parse_exact]() methods to parse a string and convert it to a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value. 
The second format uses a form supported by the ISO 8601 standard for a representing date and time in string format. This standard representation is often used to transfer date information in web services.

```cpp
auto date_string = "5/1/2008 8:30:52 AM";
date_time date1 = date_time::parse(date_string, std::locale());
auto iso8601_string = "20080501T08:30:52Z";
date_time date_iso8602 = date_time::parse_exact(iso8601_string, "yyyyMMddTHH:mm:ssZ", std::locale());
```

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.
