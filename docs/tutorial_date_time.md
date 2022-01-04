| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Date and time

## In This Section

This article includes several examples that use the DateTime type:

* Initialization Examples
  * Invoke a constructor
  * Invoke the implicit parameterless constructor
  * Assignment from return value
  * Parsing a string that represents a date and time
  * Visual Basic syntax to initialize a date and time
* Formatting DateTime objects as strings
  * Use the default date time format
  * Format a date and time using a specific culture
  * Format a date time using a standard or custom format string
  * Specify both a format string and a specific culture
  * Format a date time using the ISO 8601 standard for web services
* Parsing strings as DateTime objects
  * Use Parse or TryParse to convert a string to a date and time
  * Use ParseExact or TryParseExact to convert a string in a known format
  * Convert from the ISO 8601 string representation to a date and time
* DateTime resolution
  * Explore the resolution of date and time values
  * Comparing for equality within a tolerance
  * Culture and calendars
  * Display date and time values using culture specific calendars
  * Parse strings according to a culture specific calendar
  * Initialize a date and time from a specific culture's calendar
  * Accessing date and time properties using a specific culture's calendar
  * Retrieving the week of the year using culture specific calendars
* Persistence
  * Persisting date and time values as strings in the local time zone
  * Persisting date and time values as strings in a culture and time invariant format
  * Persisting date and time values as integers
  * Persisting date and time values using the XmlSerializer
  * Persisting date and time values using the BinaryFormatter
  * Persisting date and time values with time zone data

## Quick links to Remarks topics.

This section contains topics for many common uses of the DateTime struct:

* Initializing a DateTime object
* DateTime values and their string representations
* Parsing DateTime values from strings
* DateTime values
* DateTime operations
* DateTime resolution
* DateTime values and calendars
* Persisting DateTime values
* DateTime vs. TimeSpan
* Comparing for equality within tolerance
* COM interop considerations

The [xtd::date_time](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1date__time.html) value type represents dates and times with values ranging from 00:00:00 (midnight), January 1, 0001 Anno Domini (Common Era) through 11:59:59 P.M., December 31, 9999 A.D. (C.E.) in the Gregorian calendar.

Time values are measured in 100-nanosecond units called [ticks](https://codedocs.xyz/gammasoft71/xtd/group__types.html#ga8fd3ccd5f25e401dc28a28ba352aa966). A particular date is the number of ticks since 12:00 midnight, January 1, 0001 A.D. (C.E.) in the GregorianCalendar calendar. 
The number excludes ticks that would be added by leap seconds. For example, a ticks value of 31241376000000000L represents the date Friday, January 01, 0100 12:00:00 midnight. A [xtd::date_time](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1date__time.html) value is always expressed in the context of an explicit or default calendar.

## See also

* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2022 Gammasoft.
