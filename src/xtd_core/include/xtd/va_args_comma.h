/// @file
/// @brief Contains xtd::tunit::caller_info class.
#pragma once

#if !defined(__VA_ARGS_COMMA__)
#  define __VA_ARGS_COMMA__(...) __GET_VA_ARGS_COMMA_ARG__( , ##__VA_ARGS__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__,)
#  define __GET_VA_ARGS_COMMA_ARG__(start, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, end,...) end
#  define __COMMA__ ,
#endif


// Can be used With Visual studio 2019 16.5 :
// (add compiler options : "/Zc::preprocessor / wd5105")
// See https://docs.microsoft.com/en-us/cpp/preprocessor/preprocessor-experimental-overview?view=msvc-160
