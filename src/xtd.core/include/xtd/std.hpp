/// @file
/// @brief Contains c++ std library headers.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#ifdef _MSC_VER
#  include "intrin.h"
#endif
#include <algorithm>
#include <any>
#include <array>
#include <atomic>
#ifdef __cpp_lib_barrier
#  include <barrier>
#endif
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <charconv>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <codecvt>
#include <compare>
#include <complex>
#include <concepts>
#include <condition_variable>
#ifdef __cpp_lib_coroutine
#  include <coroutine>
#endif
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __has_include(<cuchar>)
#  include <cuchar>
#endif
#include <cwchar>
#include <cwctype>
#  ifdef __cpp_lib_debugging
#include <debugging>
#endif
#include <deque>
#include <exception>
// libstdc++ currently has a dependency on linking TBB if <execution> is
// included, and TBB seems to be not automatically installed and linkable
// on some GCC installations, so let's not pull in that little-used header
// in our -pure-cpp2 "import std;" simulation mode... if you need this,
// use mixed mode (not -pure-cpp2) and #include all the headers you need
// including this one
//
// #include <execution>
#ifdef __cpp_lib_expected
#  include <expected>
#endif
#include <filesystem>
#if defined(__cpp_lib_format) || (defined(_MSC_VER) && _MSC_VER >= 1929)
#  include <format>
#endif
#ifdef __cpp_lib_flat_map
#  include <flat_map>
#endif
#ifdef __cpp_lib_flat_set
#  include <flat_set>
#endif
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#ifdef __cpp_lib_generator
#  include <generator>
#endif
#ifdef __cpp_lib_hazard_pointer
#  include <hazard_pointer>
#endif
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iso646.h>
#include <istream>
#include <iterator>
#ifdef __cpp_lib_latch
#  include <latch>
#endif
#include <limits>
#ifdef __cpp_lib_linalg
#  include <linalg>
#endif
#include <list>
#include <locale>
#include <map>
#ifdef __cpp_lib_mdspan
#  include <mdspan>
#endif
#include <memory>
#ifdef __cpp_lib_memory_resource
#  include <memory_resource>
#endif
#include <mutex>
#include <new>
#include <numbers>
#include <numeric>
#include <optional>
#include <ostream>
#ifdef __cpp_lib_print
#  include <print>
#endif
#include <queue>
#include <random>
#include <ranges>
#include <ratio>
#ifdef __cpp_lib_rcu
#  include <rcu>
#endif
#include <regex>
#include <scoped_allocator>
#ifdef __cpp_lib_semaphore
#  include <semaphore>
#endif
#include <set>
#include <shared_mutex>
#ifdef __cpp_lib_source_location
#  include <source_location>
#endif
#include <span>
#ifdef __cpp_lib_spanstream
#  include <spanstream>
#endif
#include <sstream>
#include <stack>
#ifdef __cpp_lib_stacktrace
#  include <stacktrace>
#endif
#ifdef __cpp_lib_stdatomic_h
#  include <stdatomic.h>
#endif
#include <stdexcept>
#if __has_include(<stdfloat>)
#  if !defined(_MSC_VER) || _HAS_CXX23
#    include <stdfloat>
#  endif
#endif
#ifdef __cpp_lib_jthread
#  include <stop_token>
#endif
#include <streambuf>
#include <string>
#include <string_view>
#ifdef __cpp_lib_syncbuf
#  include <syncstream>
#endif
#include <system_error>
#ifdef __cpp_lib_text_encoding
#  include <text_encoding>
#endif
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>
