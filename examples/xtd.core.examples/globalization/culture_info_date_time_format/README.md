# culture_info_date_time_format

Shows how to use [xtd::globalization::culture_info::date_time_format](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1globalization_1_1culture__info.html) property.

## Sources

* [src/culture_info_date_time_format.cpp](src/culture_info_date_time_format.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
dtfi/nfi PROPERTY           ORIGINAL         LOCAL            MODIFIED COPY    MODIFIED CLONE
dtfi.am_designator          AM               A.M.             A.M.             a.m.            
dtfi.date_separator         /                -                -                .               
nfi.currency_symbol         $                USD              USD              usd             
nfi.number_decimal_digits   2                4                4                3               
```
