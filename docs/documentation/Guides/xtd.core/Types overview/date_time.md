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
  * [Use Parse or TryParse to convert a string to a date and time](#parse-date_time-values-from-strings)
  * [Use ParseExact or TryParseExact to convert a string in a known format](#parse-date_time-values-from-strings)
  * [Convert from the ISO 8601 string representation to a date and time](#parse-date_time-values-from-strings)
* date_time resolution
  * [Explore the resolution of date and time values](#date_time values)
  * [Comparing for equality within a tolerance](#compare-for-equality-within-tolerance)

## Quick links to Remarks topics.

This section contains topics for many common uses of the date_time struct:

* [Initializing a date_time object](#initializing-a-date-time-object)
* [date_time values and their string representations](#date_time-values-and-their-string-representations)
* [Parsing date_time values from strings](#parse-date_time-values-from-strings)
* [date_time values](#date_time-values)
* [date_time operations](#date_time-operations)
* [date_time resolution](#date_time-resolution)
* [Persisting date_time values](#Persisting-date_time-values)
* [date_time vs. time_span](#date_time-vs-time_span)
* [Comparing for equality within tolerance](#comparing-for-equality-within-tolerance)

The [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value type represents dates and times with values ranging from 00:00:00 (midnight), January 1, 0001 Anno Domini (Common Era) through 11:59:59 P.M., December 31, 9999 A.D. (C.E.) in the Gregorian calendar.

Time values are measured in 100-nanosecond units called [ticks](https://gammasoft71.github.io/xtd/reference_guides/latest/group__types.html#gaf6b556b49d28b448fc2c5af1d820f3ea). A particular date is the number of ticks since 12:00 midnight, January 1, 0001 A.D. (C.E.) in the GregorianCalendar calendar. 
The number excludes ticks that would be added by leap seconds. For example, a ticks value of 31241376000000000L represents the date Friday, January 01, 0100 12:00:00 midnight. A [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value is always expressed in the context of an explicit or default calendar.

## Note

If you are working with a `ticks` value that you want to convert to some other time interval, such as minutes or seconds, you should use the [time_span::ticks_per_day](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a5f60382ee3e9d245638ee2cdb14eca60), [time_span::ticks_per_hour](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a87871472d7a6e0cb621df7dfc7b48f59), [time_span::ticks_per_minute](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#ab31aadb6b90479ea0b1b405e1c34f3dd), [time_span::ticks_per_second](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a0cdccee1108abbaf4edc6a4bed5b6072), [time_span::ticks_per_millisecond](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#ad29c8b8563609bdf0d15badbf0ca707a) , or [time_span::ticks_per_microsecond](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html#a4d7ec607a607e24bc33dc530820957e3) constant to perform the conversion. For example, to add the number of seconds represented by a specified number of ticks to the [second](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#ae084c4d68a46500b8e64f4aec4869a15) component of a [xtd::date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value, you can use the expression 

`date_value.second() + n_ticks / time_span::ticks_per_second`.

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
auto date1 = date_time {2008, 5, 1, 8, 30, 52};
console::write_line(date1);
```

You invoke the `date_time` structure's implicit parameterless constructor when you want a `date_time` initialized to its default value.
The following example illustrates the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) implicit parameterless constructor.

```cpp
auto dat1 = date_time {};
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
auto date1 = date_time {2008, 3, 1, 7, 0, 0};
console::write_line(date1.to_string());
// For en-US culture, displays Sat Mar  1 07:00:00 2008
```

You may need to format dates in a specific culture to support web scenarios where the server may be in a different culture from the client. You specify the culture using the `std::locale` method to create the short date and long time representation in a specific culture. The following example uses the [xtd::date_time::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method to display the date and time using the short date and long time pattern for the fr-FR culture.

```cpp
auto date1 = date_time {2008, 3, 1, 7, 0, 0};
std::locale::global(std::locale("fr_FR.utf-8"));
console::write_line(date1.to_string());
// Displays Sam  1 mar 07:00:00 2008
```

Other applications may require different string representations of a date. The [date_time::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method returns the string representation defined by a standard or custom format specifier using the formatting conventions of the current culture. The following example uses the [date_rime::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method to display the full date and time pattern for the en-US culture, the current culture on the computer on which the example was run.

```cpp
auto date1 = date_time {2008, 3, 1, 7, 0, 0};
console::write_line(date1.to_string("F"));
// Displays Sat Mar  1 07:00:00 2008
```

Finally, you can specify both the culture and the format using the `std::locale` method. The following example uses the [date_rime::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa6565955947e9562c4c1e0f9c7e9a504) method to display the full date and time pattern for the fr-FR culture.

```cpp
auto date1 = date_time {2008, 3, 1, 7, 0, 0};
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

```cpp
  std::locale::global(std::locale("en_GB.utf-8"));
  
  auto date1 = date_time {2013, 6, 1, 12, 32, 30};
  auto bad_formats = vector<ustring> {};
  
  console::write_line("{,-37} {,-19}\n", "Date String", "Date");
  for (auto date_string : date1.get_date_time_formats()) {
    auto parsed_date = date_time {};
    if (date_time::try_parse(date_string, parsed_date))
      console::write_line("{,-37} {,-19}", date_string, date_time::parse(date_string));
    else
      bad_formats.push_back(date_string);
  }
  
  // Display strings that could not be parsed.
  if (bad_formats.size() > 0_sz) {
    console::write_line("\nStrings that could not be parsed: ");
    for (auto bad_format : bad_formats)
      console::write_line(bad_format);
  }
  // Press "Run" to see the output.}
```

## date_time values

Descriptions of time values in the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) type are often expressed using the Coordinated Universal Time (UTC) standard. Coordinated Universal Time is the internationally recognized name for Greenwich Mean Time (GMT). Coordinated Universal Time is the time as measured at zero degrees longitude, the UTC origin point. Daylight saving time is not applicable to UTC.

Local time is relative to a particular time zone. A time zone is associated with a time zone offset. A time zone offset is the displacement of the time zone measured in hours from the UTC origin point. In addition, local time is optionally affected by daylight saving time, which adds or subtracts a time interval adjustment. Local time is calculated by adding the time zone offset to UTC and adjusting for daylight saving time if necessary. The time zone offset at the UTC origin point is zero.

UTC time is suitable for calculations, comparisons, and storing dates and time in files. Local time is appropriate for display in user interfaces of desktop applications. Time zone-aware applications (such as many Web applications) also need to work with a number of other time zones.

If the [kind](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#ac49ab9e61e6b546f483de527819a840f) property of a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) object is [date_time_kind::unspecified](https://gammasoft71.github.io/xtd/reference_guides/latest/group__xtd__core.html#ga03b78d9831d31a0a2ea100078219f2ea), it is unspecified whether the time represented is local time, UTC time, or a time in some other time zone.

## date_time operations

A calculation using a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) structure, such as [add](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a6f0a5355543e1aed529a2a78bf6c630b) or [subtract](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aaf1f38f9b51733e38b5db3b5dfde6bb6), does not modify the value of the structure. Instead, the calculation returns a new [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) structure whose value is the result of the calculation.
Conversion operations between time zones (such as between UTC and local time, or between one time zone and another) take daylight saving time into account, but arithmetic and comparison operations do not.

The [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) structure itself offers limited support for converting from one time zone to another. You can use the [to_local_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a9678ce3d1b6da7cf005a19728bfe6e2e) method to convert UTC to local time, or you can use the [to_universal_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a60d4fa67380ada97048d0691c3143e81) method to convert from local time to UTC. However, a full set of time zone conversion methods is available in the [time_zone_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1time__zone__info.html) class. You convert the time in any one of the world's time zones to the time in any other time zone using these methods.

Calculations and comparisons of [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) objects are meaningful only if the objects represent times in the same time zone. You can use a [time_zone_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1time__zone__info.html) object to represent a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value's time zone, although the two are loosely coupled. A [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) object does not have a property that returns an object that represents that date and time value's time zone. The [kind](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#ac49ab9e61e6b546f483de527819a840f) property indicates if a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) represents UTC, local time, or is unspecified. In a time zone-aware application, you must rely on some external mechanism to determine the time zone in which a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) object was created. You could use a structure that wraps both the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value and the [time_zone_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1time__zone__info.html) object that represents the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value's time zone. For details on using UTC in calculations and comparisons with [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) values, see Performing Arithmetic Operations with Dates and Times.

Each [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) member implicitly uses the Gregorian calendar to perform its operation. Exceptions are methods that implicitly specify a calendar. 

Operations by members of the [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) type take into account details such as leap years and the number of days in a month.

## date_time vs. time_span

The [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) and [time_span](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html) value types differ in that a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) represents an instant in time whereas a [time_span](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html) represents a time interval. You can subtract one instance of [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) from another to obtain a [time_span](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html) object that represents the time interval between them. Or you could add a positive [time_span](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html) to the current [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) to obtain a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value that represents a future date.
You can add or subtract a time interval from a [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) object. Time intervals can be negative or positive, and they can be expressed in units such as ticks, seconds, or as a [time_span](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1time__span.html) object.

## Compare for equality within tolerance

Equality comparisons for [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) values are exact. That means two values must be expressed as the same number of ticks to be considered equal. That precision is often unnecessary or even incorrect for many applications. Often, you want to test if [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) objects are roughly equal.
The following example demonstrates how to compare roughly equivalent [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) values. It accepts a small margin of difference when declaring them equal.

```cpp
static bool roughly_equals(const date_time& time, const date_time& time_with_window, int window_in_seconds, int frequency_in_seconds) {
  auto delta = convert::to_int32((time_with_window - time).total_seconds_duration().count()) % frequency_in_seconds;
  delta = delta > window_in_seconds ? frequency_in_seconds - delta : delta;
  return math::abs(delta) < window_in_seconds;
}

static void test_roughly_equals() {
  auto window = 10;
  auto freq = 60 * 60 * 2; // 2 hours;
  
  auto d1 = date_time::now();
  
  auto d2 = d1.add_seconds(2 * window);
  auto d3 = d1.add_seconds(-2 * window);
  auto d4 = d1.add_seconds(window / 2);
  auto d5 = d1.add_seconds(-window / 2);
  
  auto d6 = (d1.add_hours(2)).add_seconds(2 * window);
  auto d7 = (d1.add_hours(2)).add_seconds(-2 * window);
  auto d8 = (d1.add_hours(2)).add_seconds(window / 2);
  auto d9 = (d1.add_hours(2)).add_seconds(-window / 2);
  
  console::write_line("d1 ({0}) ~= d1 ({1}): {2}", d1, d1, roughly_equals(d1, d1, window, freq));
  console::write_line("d1 ({0}) ~= d2 ({1}): {2}", d1, d2, roughly_equals(d1, d2, window, freq));
  console::write_line("d1 ({0}) ~= d3 ({1}): {2}", d1, d3, roughly_equals(d1, d3, window, freq));
  console::write_line("d1 ({0}) ~= d4 ({1}): {2}", d1, d4, roughly_equals(d1, d4, window, freq));
  console::write_line("d1 ({0}) ~= d5 ({1}): {2}", d1, d5, roughly_equals(d1, d5, window, freq));
  
  console::write_line("d1 ({0}) ~= d6 ({1}): {2}", d1, d6, roughly_equals(d1, d6, window, freq));
  console::write_line("d1 ({0}) ~= d7 ({1}): {2}", d1, d7, roughly_equals(d1, d7, window, freq));
  console::write_line("d1 ({0}) ~= d8 ({1}): {2}", d1, d8, roughly_equals(d1, d8, window, freq));
  console::write_line("d1 ({0}) ~= d9 ({1}): {2}", d1, d9, roughly_equals(d1, d9, window, freq));
}

// The example displays output similar to the following:
// d1 (Thu Dec 30 16:18:10 2021) ~= d1 (Thu Dec 30 16:18:10 2021): true
// d1 (Thu Dec 30 16:18:10 2021) ~= d2 (Thu Dec 30 16:18:30 2021): false
// d1 (Thu Dec 30 16:18:10 2021) ~= d3 (Thu Dec 30 16:17:50 2021): false
// d1 (Thu Dec 30 16:18:10 2021) ~= d4 (Thu Dec 30 16:18:15 2021): true
// d1 (Thu Dec 30 16:18:10 2021) ~= d5 (Thu Dec 30 16:18:05 2021): true
// d1 (Thu Dec 30 16:18:10 2021) ~= d6 (Thu Dec 30 18:18:30 2021): false
// d1 (Thu Dec 30 16:18:10 2021) ~= d7 (Thu Dec 30 18:17:50 2021): false
// d1 (Thu Dec 30 16:18:10 2021) ~= d8 (Thu Dec 30 18:18:15 2021): true
// d1 (Thu Dec 30 16:18:10 2021) ~= d9 (Thu Dec 30 18:18:05 2021): true
```

## See also

* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)
