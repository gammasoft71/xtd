# culture_info_is_neutral_culture

Shows how to use [xtd::globalization::culture_info::is_neutral_culture](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1globalization_1_1culture__info.html) property.

## Sources

* [src/culture_info_is_neutral_culture.cpp](src/culture_info_is_neutral_culture.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
zh          Chinese                                 : neutral
zh-Hans     Chinese, Simplified                     : neutral
zh-Hans-CN  Chinese, Simplified (China mainland)    : specific
zh-Hans-HK  Chinese, Simplified (Hong Kong)         : specific
zh-Hans-JP  Chinese, Simplified (Japan)             : specific
zh-Hans-MO  Chinese, Simplified (Macao)             : specific
zh-Hans-MY  Chinese, Simplified (Malaysia)          : specific
zh-Hans-SG  Chinese, Simplified (Singapore)         : specific
zh-Hant     Chinese, Traditional                    : neutral
zh-Hant-CN  Chinese, Traditional (China mainland)   : specific
zh-Hant-HK  Chinese, Traditional (Hong Kong)        : specific
zh-Hant-JP  Chinese, Traditional (Japan)            : specific
zh-Hant-MO  Chinese, Traditional (Macao)            : specific
zh-Hant-MY  Chinese, Traditional (Malaysia)         : specific
zh-Hant-TW  Chinese, Traditional (Taiwan)           : specific
```
