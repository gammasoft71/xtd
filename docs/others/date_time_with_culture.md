# Display date and time according to culture (🟡 Medium)

## C++ moderne

```cpp
#include <chrono>
#include <iomanip>
#include <iostream>
#include <locale>
#include <format>
#include <print>
#include <sstream>

using namespace std;
using namespace std::chrono;

auto main() -> int {
  for (auto loc : {locale {"ar_MA.UTF-8"}, locale {"en_US.UTF-8"}, locale {"fr_BE.UTF-8"}, locale {"it_IT.UTF-8"}, locale {"ja_JP.UTF-8"}, locale {"ru_RU.UTF-8"}, locale {"zh_CN.UTF-8"}})
    println("{:>12}: {} -> {}", loc.name(), "%c",  format(loc, "{:%c}", system_clock::now()));
}

// ar_MA.UTF-8 : %c -> Tue Oct 21 15:32:59 2025
// en_US.UTF-8 : %c -> Tue Oct 21 15:32:59 2025
// fr_BE.UTF-8 : %c -> Tue Oct 21 15:32:59 2025
// it_IT.UTF-8 : %c -> Tue Oct 21 15:32:59 2025
// ja_JP.UTF-8 : %c -> Tue Oct 21 15:32:59 2025
// ru_RU.UTF-8 : %c -> Tue Oct 21 15:32:59 2025
// zh_CN.UTF-8 : %c -> Tue Oct 21 15:32:59 2025
```

### Remarks

* Modern version to display the date and time according to the local.
* But unfortunately, there are still some implementation bugs on some libc.

## C++ moderne with corrections

```cpp
#include <chrono>
#include <iomanip>
#include <iostream>
#include <locale>
#include <format>
#include <print>
#include <sstream>

using namespace std;
using namespace std::chrono;

inline struct tm to_tm(time_t time) noexcept {
  auto result = tm {};
  localtime_r(&time, &result);
  return result;
}

string to_string(const string& format, time_t value, const locale& loc) {
  auto result = stringstream {};
  result.imbue(loc);
  auto tm_value = to_tm(value);
  result << std::put_time(&tm_value, format.c_str());
  return result.str();
}

auto main() -> int {
  for (auto loc : {locale {"ar_MA.UTF-8"}, locale {"en_US.UTF-8"}, locale {"fr_BE.UTF-8"}, locale {"it_IT.UTF-8"}, locale {"ja_JP.UTF-8"}, locale {"ru_RU.UTF-8"}, locale {"zh_CN.UTF-8"}})
    println("{:>12}: {} -> {}", loc.name(), "%c",  to_string( "%c", system_clock::to_time_t(system_clock::now()),loc));
}

// ar_MA.UTF-8: %c -> الثلاثاء أكتوبر 21 15:32:59 2025
// en_US.UTF-8: %c -> Tue Oct 21 15:32:59 2025
// fr_BE.UTF-8: %c -> mar. 21 oct. 15:32:59 2025
// it_IT.UTF-8: %c -> mar 21 ott 15:32:59 2025
// ja_JP.UTF-8: %c -> 火 10/21 15:32:59 2025
// ru_RU.UTF-8: %c -> вторник, 21 октября 2025 г. 15:32:59
// zh_CN.UTF-8: %c -> 二 10月/21 15:32:59 2025
```

### Remarks

* std::put_time is limited in the number of formats and in its possibilities.

## wxWidgets

```cpp
#include <wx/wx.h>
#include <wx/intl.h>
#include <wx/datetime.h>
#include <wx/string.h>

class MyApp : public wxApp {
public:
  bool OnInit() override {
    wxDateTime now = wxDateTime::Now();

    for (auto name : {"ar_MA", "en_US", "fr_BE", "it_IT", "ja_JP", "ru_RU", "zh_CN"}) {
      auto locale = wxLocale {};
      if (!locale.Init(name)) wxPrintf("Locale %s not available on this system.\n", name);

      wxString formatted = now.Format(wxLocale::GetInfo(wxLOCALE_DATE_TIME_FMT));
      wxPrintf("%-8s: %-35s -> %s\n", name, wxLocale::GetInfo(wxLOCALE_DATE_TIME_FMT), formatted);
    }

    return false;
  }
};

wxIMPLEMENT_APP_NO_MAIN(MyApp);

auto main(int argc, char** argv) -> int {
  return wxEntry(argc, argv);
}

// This code produces the following outputs :
//
// ar_MA   : %A %e %B %Y %H:%M:%S         -> الثلاثاء 21 أكتوبر 2025
// en_US   : %A, %B %e, %Y %H:%M:%S       -> Tuesday, October 21, 2025 15:42:17
// fr_BE   : %A %e %B %Y %H:%M:%S         -> mardi 21 octobre 2025 15:42:17
// it_IT   : %A %e %B %Y %H:%M:%S         -> martedì 21 ottobre 2025 15:42:17
// ja_JP   : %Y年%m月%d日 %A %H:%M:%S         -> 2025年10月21日 火曜日 15:42:17
// ru_RU   : %A, %e %B %Y %H:%M:%S        -> вторник, 21 октября 2025 15:42:17
// zh_CN   : %Y年%m月%d日 %A %H:%M:%S         -> 2025年10月21日 星期二 15:42:17
```

### Remarks

* On POSIX systems, wxLocale::Init often fails if the locale is not installed system-wide (e.g. sudo locale-gen fr_BE.UTF-8).
* This is a common source of confusion for cross-platform developers.

## Qt

```cpp
#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>
#include <QLocale>

auto main(int argc, char *argv[]) -> int {
  QCoreApplication a(argc, argv);
  for (auto locale : {QLocale {"ar-MA"}, QLocale {"en-US"}, QLocale {"fr-BE"}, QLocale {"it-IT"}, QLocale {"ja-JP"}, QLocale {"ru-RU"}, QLocale {"zh-Hans-CN"}})
    qDebug() << qPrintable(QString("%1: %2 -> %3").arg(locale.name(), -6).arg(locale.dateTimeFormat(QLocale::LongFormat), -43).arg(locale.toString(QDateTime::currentDateTime(), QLocale::LongFormat)));
}

// This code produces the following outputs :
//
// ar_MA : dddd، d MMMM yyyy HH:mm:ss tttt             -> الثلاثاء، 21 أكتوبر 2025 14:59:11 توقيت وسط أوروبا الصيفي
// en_US : dddd, MMMM d, yyyy h:mm:ss Ap tttt          -> Tuesday, October 21, 2025 2:59:11 PM Central European Summer Time
// fr_BE : dddd d MMMM yyyy H 'h' mm 'min' ss 's' tttt -> mardi 21 octobre 2025 14 h 59 min 11 s heure d’été d’Europe centrale
// it_IT : dddd d MMMM yyyy HH:mm:ss tttt              -> martedì 21 ottobre 2025 14:59:11 Ora legale dell’Europa centrale
// ja_JP : yyyy年M月d日dddd H時mm分ss秒 tttt                 -> 2025年10月21日火曜日 14時59分11秒 中央ヨーロッパ夏時間
// ru_RU : dddd, d MMMM yyyy 'г'. HH:mm:ss tttt        -> вторник, 21 октября 2025 г. 14:59:11 Центральная Европа, летнее время
// zh_CN : yyyy年M月d日dddd tttt HH:mm:ss                 -> 2025年10月21日星期二 中欧夏令时间 14:59:11
```

### Remarks

* Does what is necessary but only works with its own structures. Cannot interact with the std.

## xtd

```cpp
#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  for (auto culture : {culture_info {"ar-MA"}, culture_info {"en-US"}, culture_info {"fr-BE"}, culture_info {"it-IT"}, culture_info {"ja-JP"}, culture_info {"ru-RU"}, culture_info {"zh-Hans-CN"}})
    println("{,-11}: {,-30} -> {}", culture.name(), culture.date_time_format().full_date_time_pattern(), date_time::now().to_string("F", culture));
}

// This code produces the following outputs :
//
// ar-MA      : dddd، d MMMM yyyy HH:mm:ss     -> الثلاثاء، 21 أكتوبر 2025 14:31:23
// en-US      : dddd, MMMM d, yyyy h:mm:ss tt  -> Tuesday, October 21, 2025 2:31:23 PM
// fr-BE      : dddd d MMMM yyyy HH:mm:ss      -> mardi 21 octobre 2025 14:31:23
// it-IT      : dddd d MMMM yyyy HH:mm:ss      -> martedì 21 ottobre 2025 14:31:23
// ja-JP      : yyyy年M月d日 dddd H:mm:ss         -> 2025年10月21日 火曜日 14:31:23
// ru-RU      : dddd, d MMMM yyyy 'г'. HH:mm:ss -> вторник, 21 октября 2025 г. 14:31:23
// zh-Hans-CN : yyyy年M月d日 dddd HH:mm:ss        -> 2025年10月21日 星期二 14:31:23
```

## Remarks
* Not only does xtd do the job, but in addition it manages the standard formats ("d", "D", "F", ...), the custom formats ("dd/MM/yy HH:mm", ...), but also the std::put_tim formats ("%c", "%Ex", ...).
* xtd integrates completely with the std, changing the current culture affects the local and vice versa.
* xtd also formats the types of std (std::time_t, std::tm, std::chrono::system_clock::time_point, ...).

## To go further

```cpp
#include <xtd/xtd>

using namespace xtd::globalization;

auto main() -> int {
  std::locale::global(std::locale("ja_JP.UTF-8"));

  println("{,-11}: {,-30} -> {}", culture_info::current_culture().name(), culture_info::current_culture().date_time_format().full_date_time_pattern(), std::chrono::system_clock::now());
}

// This code produces the following outputs :
//
// ja-JP      : yyyy年M月d日 dddd H:mm:ss         -> 2025年10月21日 火曜日 14:31:23
```

With xtd, culture-aware formatting finally feels natural in modern C++.

## See also

* [Tips & Tricks](/docs/documentation/tips_and_tricks)
* [Documentation](/docs/documentation)
