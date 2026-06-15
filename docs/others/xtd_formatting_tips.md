# Xtd Formatting Tips & Tricks

This guide focuses on formatting **native, standard, and well‑known
types** using xtd's formatting system.\
It's intentionally practical and concise, giving you the essential
patterns you'll use every day.

------------------------------------------------------------------------

## 1. Basic Numeric Formatting

### **Decimal formatting**

``` cpp
println("Value = {}", 42);               // "Value = 42"
println("Padded = {:05}", 42);           // "Padded = 00042"
println("Aligned = {:>10}", 42);         // right‑aligned
println("Aligned = {:<10}", 42);         // left‑aligned
```

### **Hex, octal, binary**

``` cpp
println("Hex = {:x}", 255);              // "ff"
println("HEX = {:X}", 255);              // "FF"
println("Octal = {:o}", 255);            // "377"
println("Binary = {:b}", 255);           // "11111111"
```

### **Numeric separators**

``` cpp
println("Readable = {:n}", 1000000);     // "1,000,000" (locale‑aware)
```

------------------------------------------------------------------------

## 2. Floating‑Point Formatting

``` cpp
println("{:.2f}", 3.1415926);            // "3.14"
println("{:.6g}", 3.1415926);            // precision 6
println("{:e}", 3.1415926);              // scientific notation
println("{:E}", 3.1415926);
```

### **Alignment & padding**

``` cpp
println("{:>12.3f}", 12.34);             // right aligned
println("{:<12.3f}", 12.34);             // left aligned
println("{:^12.3f}", 12.34);             // centered
```

------------------------------------------------------------------------

## 3. Date & Time Formatting

xtd follows patterns similar to .NET:

``` cpp
auto now = date_time::now();

println("ISO: {}", now.to_string("yyyy-MM-ddTHH:mm:ss"));
println("Date: {}", now.to_string("dddd, MMM dd yyyy"));
println("Short: {}", now.to_string("d"));
println("Long: {}", now.to_string("D"));
println("Time: {}", now.to_string("HH:mm:ss"));
```

### Common Format Tokens

  Token   Meaning
  ------- ------------------
  yyyy    Year
  MM      Month
  dd      Day
  HH      Hour (24h)
  mm      Minutes
  ss      Seconds
  dddd    Day name
  MMM     Short month name

------------------------------------------------------------------------

## 4. Boolean, Char, and String Formatting

``` cpp
println("Bool: {}", true);               // "true"
println("Char: {}", 'A');                // "A"
println("Quoted: \"{}\"", "hello");      // "hello"
println("Padded: {:10}", "xtd");         // width 10
```

------------------------------------------------------------------------

## 5. Collections

Most standard containers format naturally:

``` cpp
std::vector<int> v = {1, 2, 3};
println("Vector: {}", v);                // "[1, 2, 3]"

std::map<std::string, int> m = {{"a",1},{"b",2}};
println("Map: {}", m);                   // "{a=1, b=2}"
```

------------------------------------------------------------------------

## 6. When You Need Custom Formatting

This guide keeps things simple and focuses on built‑in types.\
For **custom type formatting**, users can refer to the xtd documentation
section on user‑defined formatters.

This keeps the Tips & Tricks file clean, focused, and easy to digest.

------------------------------------------------------------------------

If you want a deeper companion guide later (including custom user
types), that can be a separate file.

Enjoy,\
Aria
