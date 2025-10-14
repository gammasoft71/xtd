# date_time_to_string_format

Shows how to use [xtd::date_time::to_string](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#a58e9d766b5af37b77d5d8239a8320ab7) with format method.

## Sources

* [src/date_time_to_string_format.cpp](src/date_time_to_string_format.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
d: 6/15/2008
D: Sunday, June 15, 2008
f: Sunday, June 15, 2008 21:15
F: Sunday, June 15, 2008 21:15:07
g: 6/15/2008 21:15
G: 6/15/2008 21:15:07
m: June 15
o: 2008-06-15T21:15:07.0000000Z
R: Sun, 15 Jun 2008 21:15:07 GMT
s: 2008-06-15T21:15:07
t: 21:15
T: 21:15:07
u: 2008-06-15 21:15:07Z
U: Sunday, June 15, 2008 21:15:07
y: June 2008

'h:mm:ss.ff t': 9:15:07.00 P
'd MMM yyyy': 15 Jun 2008
'HH:mm:ss.f': 21:15:07.0
'dd MMM HH:mm:ss': 15 Jun 21:15:07
'\Mon\t\h\: M': Month: 6
'HH:mm:ss.ffffzzz': 21:15:07.0000+02:00

'%I:%M:%S %p': 09:15:07 PM
'%e %b %G': 15 Jun 2008
'%H:%M:%S': 21:15:07
'%e %b %H:%M:%S': 15 Jun 21:15:07
'%%Month: %m': %Month: 06
'%H:%M:%S%z': 21:15:07+0100
```
