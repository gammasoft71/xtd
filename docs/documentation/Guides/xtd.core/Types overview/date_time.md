# Date and time

## In This Section

This article includes several examples that use the date_time type:

* Initialization Examples
  * [Invoke a constructor](#invoke-constructor)
  * [Invoke the implicit parameterless constructor](#invoke-constructor)
  * [Assignment from return value](#assigning-a-computed-value)
  * [Parsing a string that represents a date and time](#parsing-a-string-that-represents-a-date_time)
* Formatting date_time objects as strings
  * [Use the default date time format](#date_time-values-and-their-string-representations)
  * [Format a date and time using a specific culture](##date_time-values-and-their-string-representations)
  * [Format a date time using a standard or custom format string](##date_time-values-and-their-string-representations)
  * [Specify both a format string and a specific culture](##date_time-values-and-their-string-representations)
  * [Format a date time using the ISO 8601 standard for web services](#date_time-values-and-their-string-representations)
* Parsing strings as date_time objects
  * [Use Parse or TryParse to convert a string to a date and time](#)
  * [Use ParseExact or TryParseExact to convert a string in a known format](#)
  * [Convert from the ISO 8601 string representation to a date and time](#)
* date_time resolution
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

This section contains topics for many common uses of the date_time struct:

* [Initializing a date_time object](#initializing-a-date-time-object)
* [date_time values and their string representations](#)
* [Parsing date_time values from strings](#)
* [date_time values](#)
* [date_time operations](#)
* [date_time resolution](#)
* [date_time values and calendars](#)
* [Persisting date_time values](#)
* [date_time vs. TimeSpan](#)
* [Comparing for equality within tolerance](#)
* [COM interop considerations](#)

The [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value type represents dates and times with values ranging from 00:00:00 (midnight), January 1, 0001 Anno Domini (Common Era) through 11:59:59 P.M., December 31, 9999 A.D. (C.E.) in the Gregorian calendar.

Time values are measured in 100-nanosecond units called [ticks](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gaf6b556b49d28b448fc2c5af1d820f3ea). A particular date is the number of ticks since 12:00 midnight, January 1, 0001 A.D. (C.E.) in the GregorianCalendar calendar. 
The number excludes ticks that would be added by leap seconds. For example, a ticks value of 31241376000000000L represents the date Friday, January 01, 0100 12:00:00 midnight. A [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value is always expressed in the context of an explicit or default calendar.

## Note

If you are working with a `ticks` value that you want to convert to some other time interval, such as minutes or seconds, you should use the [time_span::ticks_per_day](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a5f60382ee3e9d245638ee2cdb14eca60), [time_span::ticks_per_hour](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a87871472d7a6e0cb621df7dfc7b48f59), [time_span::ticks_per_minute](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#ab31aadb6b90479ea0b1b405e1c34f3dd), [time_span::ticks_per_second](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a0cdccee1108abbaf4edc6a4bed5b6072), [time_span::ticks_per_millisecond](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#ad29c8b8563609bdf0d15badbf0ca707a) , or [time_span::ticks_per_microsecond](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a4d7ec607a607e24bc33dc530820957e3) constant to perform the conversion. For example, to add the number of seconds represented by a specified number of ticks to the [second](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#ae084c4d68a46500b8e64f4aec4869a15) component of a [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value, you can use the expression <br>`date_value.second() + n_ticks / time_span::ticks_per_second`.

You can view the source for the entire set of examples from this article from the [examples](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.core.examples/date_time/README.md) repository on GitHub.

## Initializing a date_time object

You can assign an initial value to a new `date_time` value in many different ways:
* Calling a constructor, either one where you specify arguments for values, or use the implicit parameterless constructor.
* Assigning a `date_time` to the return value of a property or method.
* Parsing a `date_time` value from its string representation.

The following code snippets show examples of each:

### Invoke constructors

You call any of the overloads of the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) constructor that specify elements of the date and time value (such as the year, month, and day, or the number of ticks). 
The following code creates a specific date using the date_time constructor specifying the year, month, day, hour, minute, and second.

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
### Parsing a string that represents a date_time

The [xtd::date_time::parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a546b0f90e2a358dd2c61a44d9ac7d740), and [xtd::date_time::try_parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aed2927509532db28cee470cf231dc16d) methods all convert a string to its equivalent date and time value.
The following examples use the [xtd::date_time::parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a546b0f90e2a358dd2c61a44d9ac7d740) method to parse a string and convert it to a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value. 
The second format uses a form supported by the ISO 8601 standard for a representing date and time in string format. This standard representation is often used to transfer date information in web services.

```cpp
auto date_string = "5/1/2008 8:30:52 AM";
date_time date1 = date_time::parse(date_string, std::locale());
auto iso8601_string = "20080501T08:30:52Z";
date_time date_iso8602 = date_time::parse_exact(iso8601_string, "yyyyMMddTHH:mm:ssZ", std::locale());
```
The [try_parse](#) method indicates whether a string is a valid representation of a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value and, if it is, performs the conversion.

## date_time values and their string representations

Internally, all  [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) values are represented as the number of ticks (the number of 100-nanosecond intervals) that have elapsed since 12:00:00 midnight, January 1, 0001. The actual  [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value is independent of the way in which that value appears when displayed. The appearance of a  [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value is the result of a formatting operation that converts a value to its string representation.

The appearance of date and time values is dependent on culture, international standards, application requirements, and personal preference. The  [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) structure offers flexibility in formatting date and time values through overloads of [to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504). The default [xtd::date_time::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method returns the string representation of a date and time value using the current culture's short date and long time pattern. The following example uses the default [xtd::date_time::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method. It displays the date and time using the short date and long time pattern for the current culture. The en-US culture is the current culture on the computer on which the example was run.

```cpp
auto date1 = date_time(2008, 3, 1, 7, 0, 0);
console::write_line(date1.to_string());
// For en-US culture, displays Sat Mar  1 07:00:00 2008
```

You may need to format dates in a specific culture to support web scenarios where the server may be in a different culture from the client. You specify the culture using the `std::locale` method to create the short date and long time representation in a specific culture. The following example uses the [xtd::date_time::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method to display the date and time using the short date and long time pattern for the fr-FR culture.

```cpp
auto date1 = date_time(2008, 3, 1, 7, 0, 0);
std::locale::global(std::locale("fr_FR.utf-8"));
console::write_line(date1.to_string());
// Displays Sam  1 mar 07:00:00 2008
```

Other applications may require different string representations of a date. The [date_time::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method returns the string representation defined by a standard or custom format specifier using the formatting conventions of the current culture. The following example uses the [date_rime::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method to display the full date and time pattern for the en-US culture, the current culture on the computer on which the example was run.

```cpp
auto date1 = date_time(2008, 3, 1, 7, 0, 0);
console::write_line(date1.to_string("F"));
// Displays Sat Mar  1 07:00:00 2008
```

Finally, you can specify both the culture and the format using the `std::locale` method. The following example uses the [date_rime::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method to display the full date and time pattern for the fr-FR culture.

```cpp
auto date1 = date_time(2008, 3, 1, 7, 0, 0);
std::locale::global(std::locale("fr_FR.utf-8"));
console::write_line(date1.to_string("F"));
// Displays Sam  1 mar 07:00:00 2008
```

For more information about formatting [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) values, see [Standard Date and Time Format Strings](/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/standard_date_and_time_format_strings) and [Custom Date and Time Format Strings](/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/custom_date_and_time_format_strings).

## Parse date_time values from strings

Parsing converts the string representation of a date and time to a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value. Typically, date and time strings have two different usages in applications:
* A date and time takes a variety of forms and reflects the conventions of either the current culture or a specific culture. For example, an application allows a user whose current culture is en-US to input a date value as "12/15/2013" or "December 15, 2013". It allows a user whose current culture is en-gb to input a date value as "15/12/2013" or "15 December 2013."
* A date and time is represented in a predefined format. For example, an application serializes a date as "20130103" independently of the culture on which the app is running. An application may require dates be input in the current culture's short date format.

You use the [parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a546b0f90e2a358dd2c61a44d9ac7d740) or [try_parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aed2927509532db28cee470cf231dc16d) method to convert a string from one of the common date and time formats used by a culture to a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value. The following example shows how you can use  [try_parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aed2927509532db28cee470cf231dc16d) to convert date strings in different culture-specific formats to a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value. It changes the current culture to English (United Kingdom) and calls the [get_date_time_formats](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a986723d16d20808a9dbdc1f3dd6f4c1a) method to generate an array of date and time strings. It then passes each element in the array to the  [try_parse](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aed2927509532db28cee470cf231dc16d) method. The output from the example shows the parsing method was able to successfully convert each of the culture-specific date and time strings.


## See also

* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)
