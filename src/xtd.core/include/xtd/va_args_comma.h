/// @file
/// @brief Contains #__VA_ARGS_COMMA__ keyword.
#pragma once

#if !defined(__VA_ARGS_COMMA__)
#  define __VA_ARGS_COMMA__(...) __GET_VA_ARGS_COMMA_ARG__( , __VA_ARGS__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__,)
#  define __GET_VA_ARGS_COMMA_ARG__(start, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, end,...) end
#  define __COMMA__ ,
#endif

// To use with 0 argument, we need to force zero variadic macro on other compiler than gcc :
//
// clang : add_compile_options(-Wno-gnu-zero-variadic-macro-arguments) : Work
// msvc : add_compile_options(/wd5105 /Zc:preprocessor) : Not work !!!!!!
// Not working well with windows specific include... error on some macro like _VARIANT_BOOL... with bad definition...
// See https://docs.microsoft.com/en-us/cpp/preprocessor/preprocessor-experimental-overview?view=msvc-160
//
// #if !defined(__VA_ARGS_COMMA__)
//#  define __VA_ARGS_COMMA__(...) __GET_VA_ARGS_COMMA_ARG__( , ##__VA_ARGS__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__, __COMMA__,)
//#  define __GET_VA_ARGS_COMMA_ARG__(start, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, end,...) end
//#  define __COMMA__ ,
//#endif
