# Benchmark collections

## Containers
 * std:       std::vector<int>
 * xtd:       xtd::array<int>
 * Qt:        QList<int>
 * wxWidgets: wxArrayInt

## Infra

* Made on MacBook Pro M1. 
* Made with containers of 1,000,000 integers.

## Results

| operation             | std         | xtd         | Qt          | wxWidgets   |
| --------------------- | ----------- | ----------- | ----------- | ----------- |
| copy                  |    366.3 µs |    335.7 µs |    327.8 µs |    363.5 µs |
| move                  |      0.0 µs |      0.0 µs |      0.0 µs |      0.0 µs |
| swap                  |      0.0 µs |      0.1 µs |      0.1 µs |      0.1 µs |
| copy to std::vector   |    366.3 µs |     69.7 µs |     73.0 µs |     67.8 µs |
| move to std::vector   |      0.0 µs |      0.0 µs |          NA |      0.0 µs |
| swap to std::vector   |      0.0 µs |      0.0 µs |          NA |      0.0 µs |
| copy from std::vector |    366.3 µs |     76.0 µs |     69.5 µs |     67.8 µs |
| move from std::vector |      0.0 µs |      1.3 µs |          NA |          NA |
| swap from std::vector |      0.0 µs |      0.0 µs |          NA |      0.2 µs |

## Code :

### std

```cpp
#include <chrono>
#include <print>
#include <vector>

using namespace std;

static inline long long now_ns() {
  return chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
}

int main(int argc, char** argv) {
  const auto count = 1'000'000z;
  
  println("std::vector :");
  {
    auto orig = vector<int>(count);
    auto t0 = now_ns();
    auto dest = vector<int>(orig);
    auto t1 = now_ns();
    println("  copy                  : {:8d} nanoseconds", (t1 - t0));
  }
  
  {
    auto orig = vector<int>(count);
    auto t0 = now_ns();
    auto dest = vector<int>(std::move(orig));
    auto t1 = now_ns();
    println("  move                  : {:8d} nanoseconds", (t1 - t0));
  }
  
  {
    auto orig = vector<int>(count);
    auto dest = vector<int>();
    auto t0 = now_ns();
    swap(orig, dest);
    auto t1 = now_ns();
    println("  swap                  : {:8d} nanoseconds", (t1 - t0));
  }
}

// This code produces the following output :
//
// std::vector :
//   copy                  :   366250 nanoseconds
//   move                  :        0 nanoseconds
//   swap                  :       42 nanoseconds
```

### xtd

```cpp
#include <xtd/xtd>

auto main() -> int {
  auto const count = 1'000'000_z;
  
  println("xtd::array :");
  using_(auto orig = xtd::array<int>(count)) {
    auto stopwatch = diagnostics::stopwatch::start_new();
    auto dest = xtd::array<int>(orig);
    stopwatch.stop();
    println("  copy                  : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }

  using_(auto orig = xtd::array<int>(count)) {
    auto stopwatch = diagnostics::stopwatch::start_new();
    auto dest = xtd::array<int>(std::move(orig));
    stopwatch.stop();
    println("  move                  : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }

  using_(auto orig = xtd::array<int>(count)) {
    auto dest = xtd::array<int> {};
    auto stopwatch = diagnostics::stopwatch::start_new();
    std::swap(orig, dest);
    stopwatch.stop();
    println("  swap                  : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }

  using_(auto orig = xtd::array<int>(count)) {
    auto stopwatch = diagnostics::stopwatch::start_new();
    auto dest = std::vector<int>(orig);
    stopwatch.stop();
    println("  copy to std::vector   : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }
  
  using_(auto orig = xtd::array<int>(count)) {
    auto stopwatch = diagnostics::stopwatch::start_new();
    auto dest = std::vector<int>(std::move(orig.items()));
    stopwatch.stop();
    println("  move to std::vector   : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }
  
  using_(auto orig = xtd::array<int>(count)) {
    auto dest = std::vector<int> {};
    auto stopwatch = diagnostics::stopwatch::start_new();
    std::swap(orig.items(), dest);
    stopwatch.stop();
    println("  swap to  std::vector  : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }

  using_(auto orig = std::vector<int>(count)) {
    auto stopwatch = diagnostics::stopwatch::start_new();
    auto dest = xtd::array<int>(orig);
    stopwatch.stop();
    println("  copy from std::vector : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }
  
  using_(auto orig = std::vector<int>(count)) {
    auto stopwatch = diagnostics::stopwatch::start_new();
    auto dest = xtd::array<int>(std::move(orig));
    stopwatch.stop();
    println("  move from std::vector : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }
  
  using_(auto orig = std::vector<int>(count)) {
    auto dest = xtd::array<int> {};
    auto stopwatch = diagnostics::stopwatch::start_new();
    std::swap(orig, dest.items());
    stopwatch.stop();
    println("  swap from std::vector : {,6} nanoseconds", stopwatch.elapsed().total_nanoseconds());
  }
}

// This code produces the following output :
//
// xtd::array :
//   copy                  : 335700 nanoseconds
//   move                  :      0 nanoseconds
//   swap                  :   1100 nanoseconds
//   copy to std::vector   :  69700 nanoseconds
//   move to std::vector   :      0 nanoseconds
//   swap to  std::vector  :      0 nanoseconds
//   copy from std::vector :  76000 nanoseconds
//   move from std::vector :   1300 nanoseconds
//   swap from std::vector :    300 nanoseconds
```


### Qt

```cpp
#include <vector>
#include <QCoreApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QList>

auto main(int argc, char* argv[]) -> int {
 auto app =  QCoreApplication {argc, argv};

  const size_t count = 1'000'000;

  qDebug() << QString("QList :") << Qt::endl;

  {
    auto orig = QList<int>(count);
    auto timer = QElapsedTimer {};
    timer.start();
    auto dest = QList<int>(orig.begin(), orig.end());
    auto elapsed = timer.nsecsElapsed();
    qDebug() << QString("  copy                  : %1 nanoseconds").arg(elapsed) << Qt::endl;
  }

  {
    auto orig = QList<int>(count);
    auto timer = QElapsedTimer {};
    timer.start();
    auto dest = QList(std::move(orig));
    auto elapsed = timer.nsecsElapsed();
    qDebug() << QString("  move                  : %1 nanoseconds").arg(elapsed) << Qt::endl;
  }

  {
    auto orig = QList<int>(count);
    auto timer = QElapsedTimer {};
    auto dest = QList<int> {};
    timer.start();
    std::swap(orig, dest);
    auto elapsed = timer.nsecsElapsed();
    qDebug() << QString("  swap                  : %1 nanoseconds").arg(elapsed) << Qt::endl;
  }

  {
    auto orig = QList<int>(count);
    auto timer = QElapsedTimer {};
    timer.start();
    auto dest = std::vector<int>(orig.begin(), orig.end());
    auto elapsed = timer.nsecsElapsed();
    qDebug() << QString("  copy to std::vector   : %1 nanoseconds").arg(elapsed) << Qt::endl;
  }

  qDebug() << QString("  move to std::vector   :     NA") << Qt::endl;
  qDebug() << QString("  swap to std::vector   :     NA") << Qt::endl;

  {
    auto orig = std::vector<int>(count);
    auto timer = QElapsedTimer {};
    timer.start();
    auto dest = QList<int>(orig.begin(), orig.end());
    auto elapsed = timer.nsecsElapsed();
    qDebug() << QString("  copy from std::vector : %1 nanoseconds").arg(elapsed) << Qt::endl;
  }

  qDebug() << QString("  move from std::vector :     NA") << Qt::endl;
  qDebug() << QString("  swap from std::vector :     NA") << Qt::endl;
}

// This code produces the following output :
//
// QList :
//   copy                  : 327792 nanoseconds
//   move                  :      0 nanoseconds
//   swap                  :     83 nanoseconds
//   copy to std::vector   :  73000 nanoseconds
//   move to std::vector   :     NA
//   swap to std::vector   :     NA
//   copy from std::vector :  69459 nanoseconds
//   move from std::vector :     NA
//   swap from  std::vector:     NA
```

### wxWidgets

```cpp
#include <wx/wx.h>
#include <chrono>
#include <print>
#include <vector>

using namespace std;

static inline long long now_ns() {
  return chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
}

int main(int argc, char** argv) {
  auto initializer = wxInitializer {};
  const auto count = 1'000'000z;
  
  println("wxArrayInt :");
  {
    auto orig = wxArrayInt(count);
    auto t0 = now_ns();
    auto dest = wxArrayInt(orig);
    auto t1 = now_ns();
    println("  copy                  : {:8d} nanoseconds", (t1 - t0));
  }
  
  {
    auto orig = wxArrayInt(count);
    auto t0 = now_ns();
    auto dest = wxArrayInt(std::move(orig));
    auto t1 = now_ns();
    println("  move                  : {:8d} nanoseconds", (t1 - t0));
  }
  
  {
    auto orig = wxArrayInt(count);
    auto dest = wxArrayInt();
    auto t0 = now_ns();
    swap(orig, dest);
    auto t1 = now_ns();
    println("  swap                  : {:8d} nanoseconds", (t1 - t0));
  }
  
  {
    auto orig = wxArrayInt(count);
    auto t0 = now_ns();
    auto dest = vector<int> {orig};
    auto t1 = now_ns();
    println("  copy to std::vector   : {:8d} nanoseconds", (t1 - t0));
  }
  
  {
    auto orig = wxArrayInt(count);
    auto t0 = now_ns();
    auto dest = vector<int> {std::move(orig)};
    auto t1 = now_ns();
    println("  move to std::vector   : {:8d} nanoseconds", (t1 - t0));
  }
  
  {
    auto orig = wxArrayInt(count);
    auto dest = vector<int> {};
    auto t0 = now_ns();
    std::swap(orig, dest);
    auto t1 = now_ns();
    println("  swap to std::vector   : {:8d} nanoseconds", (t1 - t0));
  }
  
  {
    auto orig = vector<int>(count);
    auto t0 = now_ns();
    auto dest = wxArrayInt(orig.begin(), orig.end());
    auto t1 = now_ns();
    println("  copy from std::vector : {:8d} nanoseconds", (t1 - t0));
  }

  println("  move to std::vector   :       NA");

  {
    auto orig = vector<int>(count);
    auto dest = wxArrayInt {};
    auto t0 = now_ns();
    std::swap(orig, dest);
    auto t1 = now_ns();
    println("  swap from std::vector : {:8d} nanoseconds", (t1 - t0));
  }
}

// This code produces the following output :
//
// wxArrayInt :
//   copy                  :   363500 nanoseconds
//   move                  :       42 nanoseconds
//   swap                  :      125 nanoseconds
//   copy to std::vector   :    67792 nanoseconds
//   move to std::vector   :        0 nanoseconds
//   swap to std::vector   :       42 nanoseconds
//   copy from std::vector :    67792 nanoseconds
//   move to std::vector   :       NA
//   swap from std::vector :      167 nanoseconds
```
