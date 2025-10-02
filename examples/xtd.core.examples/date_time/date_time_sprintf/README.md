# date_time_sprintf

Shows how to use [xtd::date_time::sprintf](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html#aa21e25167da0cf2593175b48cf1a82d0) method.

## Sources

* [src/date_time_sprintf.cpp](src/date_time_sprintf.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
%a: Sun
%A: Sunday
%b: Jun
%B: June
%c: Sun Jun 15 21:15:07 2008
%C: 20
%d: 15
%D: 06/15/08
%e: 15
%Ec: Sun Jun 15 21:15:07 2008
%EC: 20
%Ex: 06/15/08
%EX: 21:15:07
%Ey: 08
%EY: 2008
%F: 2008-06-15
%g: 08
%G: 2008
%h: Jun
%H: 21
%I: 09
%j: 168
%m: 06
%M: 15
%p: PM
%r: 09:15:07 PM
%R: 21:15
%S: 07
%T: 21:15:07
%u: 7
%U: 24
%V: 24
%w: 0
%W: 24
%x: 06/15/08
%X: 21:15:07
%y: 08
%Y: 2008
%z: +0100
%Z: CET
%Od: 15
%Oe: 15
%OH: 21
%OI: 09
%Om: 06
%OM: 15
%OS: 07
%Ou: 7
%OU: 24
%OV: 24
%Ow: 0
%OW: 24
%Oy: 08

'%I:%M:%S %p': 09:15:07 PM
'%e %b %G': 15 Jun 2008
'%H:%M:%S': 21:15:07
'%e %b %H:%M:%S': 15 Jun 21:15:07
'%%Month: %m': %Month: 06
'%H:%M:%S%z': 21:15:07+0100
```
