# date_time_format_info

Shows how to use [xtd::globalization::date_time_format](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1globalization_1_1date__time__format__info.html) class.

## Sources

* [src/date_time_format_info.cpp](src/date_time_format_info.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
full_date_time_pattern                dddd, MMMM d, yyyy h:mm:ss tt 
                                         Example: Monday, May 28, 2012 11:35:00 AM

long_date_pattern                     dddd, MMMM d, yyyy 
                                         Example: Monday, May 28, 2012

long_time_pattern                     h:mm:ss tt 
                                         Example: 11:35:00 AM

month_day_pattern                     MMMM d 
                                         Example: May 28

rfc_1123_pattern                      ddd, dd MMM yyyy HH':'mm':'ss 'GMT' 
                                         Example: Mon, 28 May 2012 11:35:00 GMT

short_date_pattern                    M/d/yyyy 
                                         Example: 5/28/2012

short_time_pattern                    h:mm tt 
                                         Example: 11:35 AM

sortable_date_time_pattern            yyyy'-'MM'-'dd'T'HH':'mm':'ss 
                                         Example: 2012-05-28T11:35:00

universal_sortable_date_time_pattern  yyyy'-'MM'-'dd HH':'mm':'ss'Z' 
                                         Example: 2012-05-28 11:35:00Z

year_month_pattern                    MMMM yyyy 
                                         Example: May 2012

```
