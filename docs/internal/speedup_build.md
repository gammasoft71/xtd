# Investigations to speed up the build of xtd (**Internal use only**)

## Muultiple proocess build flags

### Windows

Visuall Studio has a **"/MP"** flag that allows you to run builds in parallel on different processes.

A new option **XTD_SET_COMPILER_OPTION_BUILD_ON_MULTIPLE_PROCESSES ** is added in xtd and number of precessorrs are dettected by CMake and addded to MSVC comile flags.

#### Conclusions

Currently, the flag is doing the job, but in full build, Windows freeze completely ...

We contunue the investigation for more information. (Bader)

### macOS

Xcode build in multi processes natively.

Remarks : For command line tools see [Linux](#linux)

The build seems optimized. (Gammasof)

### Linux 

* To build multi porcess add specific flag **"-j N"** to make command (N : number of precesses).
* To build multi porcess add specific flag **"-- -j N"** to cmake command (N : number of precesses).
* Generally we can use **"nproc"** command to know the number roof proocessosrs.

#### example make

```shell
make -j 8
```

or with nproc

```shell
make -j $(naproc)
```

#### example cmake

```shell
cmake -- -j 8
```

or with nproc

```shell
cmake-- -j $(naproc)
```

#### Conclusions

The build seems optimized. (Gammasof)

## Cotire

[Cotire](https://github.com/sakra/cotire) (compile time reducer) is a CMake module that speeds up the build process of CMake based build 

We investigate to add cotire to build of xtd.

### xtd install script

* git clone wxWidgets 3.1.5
* build and install wxWidgets in Debug and Release.
* build and install xtd (without unit tests) in Debug and Release.

### TTime to install xtd on linux Unbuntu (4 cores and 8 Gb memory)

```
real	34m30,458s
user	109m8,613s
sys	8m32,720s
```

### Time to install xtd on linux Unbuntu (4 cores and 8 Gb memory) with cotire

```
real	34m52,459s
user	102m18,172s
sys	9m31,467s
```

Exactly the same time for both builds.
We can see the log lines of the cotire and that it is doing its job... but it doesn't speed up the time.

### Conclusions

The result is not convincing.

We stop the investigation (Gammasoft)
